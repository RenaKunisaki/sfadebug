#include "dolphin.h"
#include "types.h"
#include "debug.h"
#include "alloc.h"
#include "n64.h"

/* 802eb0e0 */ u32 allocTagColorTbl[] = {
    ALLOC_TAG_ZERO,   ALLOC_TAG_LISTS,    ALLOC_TAG_SCREEN,
    ALLOC_TAG_CODE,   ALLOC_TAG_DLL,      ALLOC_TAG_TRACK,
    ALLOC_TAG_TEX,    ALLOC_TAG_TRACKTEX, ALLOC_TAG_SPRITETEX,
    ALLOC_TAG_MODELS, ALLOC_TAG_ANIMS,    ALLOC_TAG_AUDIO,
    ALLOC_TAG_SEQ,    ALLOC_TAG_SFX,      ALLOC_TAG_OBJECTS,
    ALLOC_TAG_CAM,    ALLOC_TAG_VOX,      ALLOC_TAG_ANIMSEQ,
    ALLOC_TAG_LFX,    ALLOC_TAG_GFX,      ALLOC_TAG_EXPGFX,
    ALLOC_TAG_MODGFX, ALLOC_TAG_PROJGFX,  ALLOC_TAG_SKY,
    ALLOC_TAG_SHAD,   ALLOC_TAG_GAME,     ALLOC_TAG_TEST,
    0x000000FF,       0xFF0000FF,         0x00FF00FF,
    0x0000FFFF,       0x00FFFFFF,         0xFF00FFFF,
    0xFFFF00FF,       0xFFFFFFFF,
};

/* 803555F8 */ Heap heaps[MAX_HEAPS];
/* 80355698 */ FreeListEntry freeList[MAX_FREELIST_SIZE];
/* 80398B70 */ void *pFrameBuffer_80398b70;
/* 80398B74 */ void *pFrameBuffer_80398b74;
/* 80398A08 */ u8 numHeaps;
/* 80398A0A */ s16 freeListEntries;
/* 80398A0C */ int mmDelay;
/* 80398A10 */ int DAT_80398a10;
/* 80398A14 */ int INT_80398a14;
/* 80398A18 */ int INT_80398a18;
/* 80398A1C */ int memUsedPct;

/* 80398B78 */ TVParams *curTvParams; // probably doesn't belong here

void *heapInit(HeapEntry *addr, int size, int nSlots);
void *heapAlloc(int heap, uint size, u32 tag, const char *name);
void mmSetDelay(int param1);
void _mmAddToFreeList(void *ptr);
void _mmHeapFree(void *ptr);
int heapSetEntry(int iHeap, int iEntry, u32 size, s16 type, int type2, u32 tag,
                 const char *name);
void _mmActuallyFree(int iHeap, int iEntry);

void initHeaps(void) { // 8007B3A4
    int iVar1;
    size_t size;
    void *pvVar2;
    void *arenaEnd;
    OSHeapHandle heap;
    u32 *tags;

    tags = allocTagColorTbl; // probably fake for string reloc

    numHeaps = 0;
    pvVar2 = OSGetArenaLo();
    iVar1 =
        (curTvParams->width + 0xf & 0xfff0) * (ushort)curTvParams->height2 * 2;
    pFrameBuffer_80398b74 = (void *)OSRoundUp32B(pvVar2);
    pFrameBuffer_80398b70 =
        (void *)OSRoundUp32B((u32)pFrameBuffer_80398b74 + iVar1);
    pvVar2 = (void *)OSRoundUp32B((u32)pFrameBuffer_80398b70 + iVar1);
    OSSetArenaLo(pvVar2);

    arenaEnd = OSGetArenaHi();
    pvVar2 = OSInitAlloc(pvVar2, arenaEnd, 1);
    OSSetArenaLo(pvVar2);

    pvVar2 = (void *)OSRoundUp32B(pvVar2);
    arenaEnd = (void *)((uint)arenaEnd & ~0x1f);
    heap = OSCreateHeap(pvVar2, arenaEnd);
    OSSetCurrentHeap(heap);

    size = (uint)arenaEnd - (uint)pvVar2 - 0x5a0000;
    pvVar2 = OSAllocFromHeap(__OSCurrHeap, size);
    memset_(pvVar2, 0, size);
    DCFlushRange(pvVar2, size);
    heapInit((HeapEntry *)pvVar2, size, 0x2ee);

    pvVar2 = OSAllocFromHeap(__OSCurrHeap, 0x500000);
    memset_(pvVar2, 0, 0x500000);
    DCFlushRange(pvVar2, 0x500000);
    heapInit((HeapEntry *)pvVar2, 0x500000, 0x5aa);

    pvVar2 = OSAllocFromHeap(__OSCurrHeap, 0x9ffa0);
    if (!pvVar2) {
        OSPanic("mm_dolphin.c", 0x142, "Memory region setup is too big");
    }
    memset_(pvVar2, 0, 0x9ffa0);
    DCFlushRange(pvVar2, 0x9ffa0);
    heapInit((HeapEntry *)pvVar2, 0x9ffa0, 0x76c);
    mmSetDelay(2);
    freeListEntries = 0;
    return;
}

void *heapInit(HeapEntry *addr, int size, int nSlots) { // 8007B580
    int iVar2;
    HeapEntry *entry;
    uint iHeap;
    uint size2;
    uint size3;

    iHeap = numHeaps;
    numHeaps++;
    size2 = nSlots * sizeof(HeapEntry);
    size3 = size - size2;

    heaps[iHeap].avail = nSlots;
    heaps[iHeap].used = 0;
    heaps[iHeap].data = addr;
    heaps[iHeap].size = size;
    heaps[iHeap].used2 = 0;
    entry = heaps[iHeap].data;

    for (iVar2 = 0; iVar2 < (int)heaps[iHeap].avail; iVar2++) {
        (entry++)->stack = iVar2;
    }
    entry = heaps[iHeap].data;
    addr = (HeapEntry *)((int)addr + size2);
    if ((uint)addr & 0x1f) {
        entry->entry.loc = (void *)(((u32)addr & ~0x1F) + 0x20);
    } else {
        entry->entry.loc = addr;
    }
    entry->entry.size = size3;
    entry->type = 0;
    entry->prev = -1;
    entry->next = -1;
    heaps[iHeap].used++;
    return heaps[iHeap].data;
}

void *mmAlloc(volatile int size, volatile u32 tag,
              volatile u32 name) { // 8007B690
    void *result;
    u32 *tags;
    void *crash;
    volatile u32 crash2;

    tags = allocTagColorTbl;
    if (!size) {
        crash = NULL;
        crash2 = *(volatile u32 *)((u32)crash + 0x14);
        return NULL;
    }

    if (tag <= ALLOC_TAG_TEST_COL)
        tag = tags[tag];
    if (size >= 0x3000 || n64RamSize != 0x800000) {
        result = heapAlloc(0, size, tag, (const char *)name);
        if (!result)
            result = heapAlloc(1, size, tag, (const char *)name);
    } else if (size >= 0x400) {
        result = heapAlloc(1, size, tag, (const char *)name);
        if (!result)
            result = heapAlloc(2, size, tag, (const char *)name);
    } else {
        result = heapAlloc(2, size, tag, (const char *)name);
        if (!result)
            result = heapAlloc(0, size, tag, (const char *)name);
    }

    if (!result) {
        crash = NULL;
        crash2 = *(volatile u32 *)((u32)crash + 0x14);
    }

    return result;
}

void *realloc(void *volatile offset, volatile int size,
              const char *name) { // 8007B7F4
    int iHeap;
    int uVar4;
    u32 uVar5;
    int iVar7;
    int iEntry;
    HeapEntry *entry;
    void *crash;
    volatile u32 crash2;

    if (size <= 0) {
        crash = NULL;
        crash2 = *(volatile u32 *)((u32)crash + 0x14);
        return NULL;
    }

    if (size & 0x1f)
        size = (size & ~0x1f) + 0x20;

    iHeap = _mmGetHeapIdx(offset);
    if (iHeap == -1)
        return NULL;

    entry = heaps[iHeap].data;
    iEntry = 0;
    do {
        if (entry[iEntry].entry.loc == offset)
            break;
        iEntry = entry[iEntry].next;
    } while (iEntry != -1);

    if (iEntry != -1) {
        heaps[iHeap].used2 -= entry[iEntry].entry.size;
        heaps[iHeap].used2 += size;
    }

    if ((int)size < (int)entry[iEntry].entry.size) {
        if (heaps[iHeap].used + 1 == heaps[iHeap].avail) {
            return NULL;
        }

        heapSetEntry(iHeap, iEntry, size, 1, 0, entry[iEntry].tag, name);
    } else if ((int)size > (int)entry[iEntry].entry.size) {
        iVar7 = entry[iEntry].next;
        uVar5 = entry[iEntry].entry.size;
        uVar4 = 0;

        while (iVar7 != -1) {
            if (entry[iVar7].type != 0)
                break;
            uVar4 = uVar5;
            uVar5 += entry[iVar7].entry.size;
            if ((int)uVar5 >= (int)size)
                break;

            iVar7 = entry[iVar7].next;
        }

        if ((int)uVar5 < size)
            return NULL;

        if ((int)uVar5 > size) {
            heapSetEntry(iHeap, iVar7, size - uVar4, 1, 0, entry[iEntry].tag,
                         name);
        }

        iVar7 = (int)entry[iEntry].next;
        uVar5 = entry[iEntry].entry.size;
        while ((int)uVar5 < size) {
            uVar5 += entry[iVar7].entry.size;
            uVar4 = entry[iVar7].next;
            entry[iEntry].next = uVar4;
            if (uVar4 != -1) {
                entry[uVar4].prev = iEntry;
            }
            entry[--heaps[iHeap].used].stack = (s16)iVar7;
            iVar7 = uVar4;
        }

        entry[iEntry].entry.size = size;
    }
    return offset;
}

void *mmAlloc2(volatile int size, u32 tag, const char *name) { // 8007BADC
    //eq except regswap
    void *result;
    u32 *tags;
    void *crash;
    volatile u32 crash2;

    tags = allocTagColorTbl;
    if (tag <= ALLOC_TAG_TEST_COL)
        tag = tags[tag];
    if (size == 0) {
        crash = NULL;
        crash2 = *(volatile u32 *)((u32)crash + 0x14);
        return NULL;
    }

    result = heapAlloc(1, size, tag, name);
    if(!result) {
        crash = NULL;
        crash2 = *(volatile u32 *)((u32)crash + 0x14);
    }
    return result;
}

void *heapAlloc(int heap, uint size, u32 tag, const char *name) { // 8007BB74
    u32 param1;
    void *pvVar1;
    HeapEntry *data;
    u32 uVar2;
    int iVar3;
    int iEntry;
    uint local_34;
    u32 local_28;

    local_28 = 0;
    param1 = n64DisableInterrupts();
    heaps[heap].used2 = heaps[heap].used2 + size;
    if (heaps[heap].used + 1 == heaps[heap].avail) {
        n64EnableInterrupts(param1);
        pvVar1 = (void *)0x0;
    } else {
        local_34 = size;
        if ((size & 0x1f) != 0) {
            local_34 = (size & 0xffffffe0) + 0x20;
        }
        iEntry = -1;
        uVar2 = 0x7fffffff;
        data = heaps[heap].data;
        iVar3 = 0;
        do {
            if (data[iVar3].type == 0) {
                if ((int)data[iVar3].entry.size < (int)local_34) {
                    if ((int)local_28 < (int)data[iVar3].entry.size) {
                        local_28 = data[iVar3].entry.size;
                    }
                } else if ((int)data[iVar3].entry.size < (int)uVar2) {
                    uVar2 = data[iVar3].entry.size;
                    iEntry = iVar3;
                }
            }
            iVar3 = (int)data[iVar3].next;
        } while (iVar3 != -1);
        if (iEntry == -1) {
            pvVar1 = (void *)0x0;
        } else {
            heapSetEntry(heap, iEntry, local_34, 1, 0, tag, name);
            n64EnableInterrupts(param1);
            pvVar1 = data[iEntry].entry.loc;
        }
    }
    return pvVar1;
}

void mmSetDelay(int delay) { // 8007BD28
    u32 param1;

    param1 = n64DisableInterrupts();
    mmDelay = delay;
    if (delay == 0) {
        while (0 < freeListEntries) {
            freeListEntries = freeListEntries + -1;
            _mmHeapFree(freeList[freeListEntries].ptr);
        }
    }
    n64EnableInterrupts(param1);
    return;
}

void mmFree(void *__ptr) { // 8007BDA4
    u32 param1;

    param1 = n64DisableInterrupts();
    if (mmDelay == 0) {
        _mmHeapFree(__ptr);
    } else {
        _mmAddToFreeList(__ptr);
    }
    n64EnableInterrupts(param1);
    return;
}

void checkHeaps(void) { // 8007BDFC
    bool bVar1;
    int dVar2;
    u32 param1;
    int iVar3;
    HeapEntry *pHVar4;
    HeapEntry *pHVar5;

    param1 = n64DisableInterrupts();
    iVar3 = 0;
    while (iVar3 < freeListEntries) {
        freeList[iVar3].delay = freeList[iVar3].delay - 1;
        if (freeList[iVar3].delay == 0) {
            _mmHeapFree(freeList[iVar3].ptr);
            freeList[iVar3].ptr = freeList[freeListEntries + -1].ptr;
            freeList[iVar3].delay = freeList[freeListEntries + -1].delay;
            freeListEntries = freeListEntries + -1;
        } else {
            iVar3 = iVar3 + 1;
        }
    }
    n64EnableInterrupts(param1);
    DAT_80398a10 = 0;
    INT_80398a18 = 0;
    INT_80398a14 = 0;
    pHVar5 = heaps[0].data;
    while (true) {
        if (pHVar5->type != 0) {
            DAT_80398a10 = DAT_80398a10 + (pHVar5->entry).size;
        }
        pHVar4 = heaps[1].data;
        if (pHVar5->next == -1)
            break;
        pHVar5 = heaps[0].data + pHVar5->next;
    }
    while (true) {
        if (pHVar4->type != 0) {
            INT_80398a14 = INT_80398a14 + (pHVar4->entry).size;
        }
        pHVar5 = heaps[2].data;
        if (pHVar4->next == -1)
            break;
        pHVar4 = heaps[1].data + pHVar4->next;
    }
    while (true) {
        if (pHVar5->type != 0) {
            INT_80398a18 = INT_80398a18 + (pHVar5->entry).size;
        }
        if (pHVar5->next == -1)
            break;
        pHVar5 = heaps[2].data + pHVar5->next;
    }
    dVar2 = memUsedPct + 1;
    bVar1 = memUsedPct == ((int)memUsedPct / 500) * 500;
    memUsedPct = dVar2;
    if (bVar1) {
        fn_8007C54C();
    }
    return;
}

void _mmHeapFree(void *ptr) { // 8007BFD8
    int idx;
    HeapEntry *ent;
    int ii;

    idx = _mmGetHeapIdx(ptr);
    if (idx != -1) {
        ent = heaps[idx].data;
        ii = 0;
        do {
            if (ent[ii].entry.loc == ptr) {
                if ((ent[ii].type != 1) && (ent[ii].type != 4)) {
                    return;
                }
                _mmActuallyFree(idx, ii);
                return;
            }
            ii = (int)ent[ii].next;
        } while (ii != -1);
    }
    return;
}

void _mmAddToFreeList(void *ptr) { // 8007C090
    freeList[freeListEntries].ptr = ptr;
    freeList[freeListEntries].delay = mmDelay;
    freeListEntries = freeListEntries + 1;
    return;
}

int _mmGetHeapIdx(void *offset) { // 8007C0DC
    int iHeap;

    iHeap = 0;
    while (true) {
        if ((int)(uint)numHeaps <= iHeap) {
            return -1;
        }
        if ((heaps[iHeap].data < offset) &&
            (offset < (void *)((int)&((heaps[iHeap].data)->entry).loc +
                               heaps[iHeap].size)))
            break;
        iHeap = iHeap + 1;
    }
    return iHeap;
}

void _mmActuallyFree(int iHeap, int iEntry) { // 8007C154
    short sVar1;
    short sVar2;
    short sVar3;
    uint uVar4;
    int iVar5;
    int iVar6;
    HeapEntry *entry;

    entry = heaps[iHeap].data;
    sVar1 = entry[iEntry].next;
    iVar6 = (int)sVar1;
    sVar2 = entry[iEntry].prev;
    iVar5 = (int)sVar2;
    entry[iEntry].type = 0;
    LAB_8018fa40(entry[iEntry].entry.loc);
    heaps[iHeap].used2 = heaps[iHeap].used2 - entry[iEntry].entry.size;
    if ((iVar6 != -1) && (entry[iVar6].type == 0)) {
        entry[iEntry].entry.size =
            entry[iEntry].entry.size + entry[iVar6].entry.size;
        sVar3 = entry[iVar6].next;
        entry[iEntry].next = sVar3;
        if (sVar3 != -1) {
            entry[sVar3].prev = (s16)iEntry;
        }
        uVar4 = heaps[iHeap].used - 1;
        heaps[iHeap].used = uVar4;
        entry[uVar4].stack = sVar1;
    }
    if ((iVar5 != -1) && (entry[iVar5].type == 0)) {
        entry[iVar5].entry.size =
            entry[iVar5].entry.size + entry[iEntry].entry.size;
        sVar1 = entry[iEntry].next;
        entry[iVar5].next = sVar1;
        if (sVar1 != -1) {
            entry[sVar1].prev = sVar2;
        }
        uVar4 = heaps[iHeap].used - 1;
        heaps[iHeap].used = uVar4;
        entry[uVar4].stack = (s16)iEntry;
    }
    return;
}

void *getHeapData(int iHeap) { // 8007C310
    return (void *)heaps[iHeap].data;
}

int heapSetEntry(int iHeap, int iEntry, u32 size, s16 type, int type2, u32 tag,
                 const char *name) { // 8007C328
    short sVar1;
    short sVar2;
    uint uVar3;
    u32 uVar4;
    int idx;
    HeapEntry *entry;

    entry = heaps[iHeap].data;
    entry[iEntry].type = type;
    uVar4 = entry[iEntry].entry.size;
    entry[iEntry].entry.size = size;
    entry[iEntry].tag = tag;
    idx = iEntry;
    if ((int)size < (int)uVar4) {
        idx = (int)entry[iEntry].next;
        if (((idx == -1) || (entry[idx].type != 0)) || (type2 != 0)) {
            uVar3 = heaps[iHeap].used;
            heaps[iHeap].used = uVar3 + 1;
            sVar1 = entry[uVar3].stack;
            idx = (int)sVar1;
            entry[idx].entry.loc =
                (void *)((int)entry[iEntry].entry.loc + size);
            entry[idx].entry.size = uVar4 - size;
            entry[idx].type = (s16)type2;
            sVar2 = entry[iEntry].next;
            entry[idx].next = sVar2;
            entry[idx].prev = (s16)iEntry;
            entry[iEntry].next = sVar1;
            if (sVar2 != -1) {
                entry[sVar2].prev = sVar1;
            }
        } else {
            entry[idx].entry.loc =
                (void *)((int)entry[iEntry].entry.loc + size);
            entry[idx].entry.size = entry[idx].entry.size + (uVar4 - size);
        }
    }
    return idx;
}
