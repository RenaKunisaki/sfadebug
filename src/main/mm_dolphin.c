#include "dolphin.h"
#include "macros.h"
#include "types.h"
#include "debug/debug.h"
#include "sys/alloc.h"
#include "sys/n64.h"

//.data
/* clang-format off */
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
/* clang-format on */

//.bss
/* 803555F8 */ Heap heaps[MAX_HEAPS];
/* 80355698 */ FreeListEntry freeList[MAX_FREELIST_SIZE];

//.sbss
/* 80398A08 */ u8 numHeaps;
/* 80398A0A */ s16 freeListEntries;
/* 80398A0C */ int mmDelay;
/* 80398A10 */ int heapUsed0, heapUsed1, heapUsed2;
/* 80398A1C */ int memUsedPct;

/* 80398B70 */ void *pFrameBuffer_80398b70;
/* 80398B74 */ void *pFrameBuffer_80398b74;
/* 80398B78 */ extern TVParams *curTvParams; // probably doesn't belong here


void _mmHeapFree(void *ptr);
void _mmAddToFreeList(void *ptr);
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
	iVar1 = (curTvParams->width + 0xf & 0xfff0) *
        (ushort)curTvParams->height2 * 2;
	pFrameBuffer_80398b74 = (void *)OSRoundUp32B(pvVar2);
	pFrameBuffer_80398b70
	    = (void *)OSRoundUp32B((u32)pFrameBuffer_80398b74 + iVar1);
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

    size = 0x500000;
	pvVar2 = OSAllocFromHeap(__OSCurrHeap, size);
	memset_(pvVar2, 0, size);
	DCFlushRange(pvVar2, size);
	heapInit((HeapEntry *)pvVar2, size, 0x5aa);

    size = 0x9ffa0;
	pvVar2 = OSAllocFromHeap(__OSCurrHeap, size);
	if(!pvVar2) {
		OSPanic(__FILE__, 0x142, "Memory region setup is too big");
	}
	memset_(pvVar2, 0, size);
	DCFlushRange(pvVar2, size);
	heapInit((HeapEntry *)pvVar2, size, 0x76c);
	mmSetDelay(2);
	freeListEntries = 0;
	return;
}

void* heapInit(HeapEntry *addr, int size, int nSlots) { // 8007B580
	int ii;
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

	for(ii = 0; ii < heaps[iHeap].avail; ii++) {
		entry->stack = ii;
		entry++;
	}
	entry = heaps[iHeap].data;
	addr = (HeapEntry *)((int)addr + size2);
	if((uint)addr & 0x1f) {
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

void *mmAlloc(volatile int size, volatile u32 tag, volatile u32 name) { // 8007B690
	void *result;
	u32 *tags;
	void *crash;
	volatile u32 crash2;

	tags = allocTagColorTbl;
	if(!size) {
		crash = NULL;
		crash2 = *(volatile u32 *)((u32)crash + 0x14);
		return NULL;
	}

	if(tag <= ALLOC_TAG_TEST_COL) tag = tags[tag];
	if(size >= 0x3000 || n64RamSize != 0x800000) {
		result = heapAlloc(0, size, tag, (const char *)name);
		if(!result) result = heapAlloc(1, size, tag, (const char *)name);
	} else if(size >= 0x400) {
		result = heapAlloc(1, size, tag, (const char *)name);
		if(!result) result = heapAlloc(2, size, tag, (const char *)name);
	} else {
		result = heapAlloc(2, size, tag, (const char *)name);
		if(!result) result = heapAlloc(0, size, tag, (const char *)name);
	}

	if(!result) {
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

	if(size <= 0) {
		crash = NULL;
		crash2 = *(volatile u32 *)((u32)crash + 0x14);
		return NULL;
	}

	if(size & 0x1f) size = (size & ~0x1f) + 0x20;

	iHeap = _mmGetHeapIdx(offset);
	if(iHeap == -1) return NULL;

	entry = heaps[iHeap].data;
	iEntry = 0;
	do {
		if(entry[iEntry].entry.loc == offset) break;
		iEntry = entry[iEntry].next;
	} while(iEntry != -1);

	if(iEntry != -1) {
		heaps[iHeap].used2 -= entry[iEntry].entry.size;
		heaps[iHeap].used2 += size;
	}

	if((int)size < (int)entry[iEntry].entry.size) {
		if(heaps[iHeap].used + 1 == heaps[iHeap].avail) { return NULL; }

		heapSetEntry(iHeap, iEntry, size, 1, 0, entry[iEntry].tag, name);
	} else if((int)size > (int)entry[iEntry].entry.size) {
		iVar7 = entry[iEntry].next;
		uVar5 = entry[iEntry].entry.size;
		uVar4 = 0;

		while(iVar7 != -1) {
			if(entry[iVar7].type != 0) break;
			uVar4 = uVar5;
			uVar5 += entry[iVar7].entry.size;
			if((int)uVar5 >= (int)size) break;

			iVar7 = entry[iVar7].next;
		}

		if((int)uVar5 < size) return NULL;

		if((int)uVar5 > size) {
			heapSetEntry(
			    iHeap, iVar7, size - uVar4, 1, 0, entry[iEntry].tag, name);
		}

		iVar7 = (int)entry[iEntry].next;
		uVar5 = entry[iEntry].entry.size;
		while((int)uVar5 < size) {
			uVar5 += entry[iVar7].entry.size;
			uVar4 = entry[iVar7].next;
			entry[iEntry].next = uVar4;
			if(uVar4 != -1) { entry[uVar4].prev = iEntry; }
			entry[--heaps[iHeap].used].stack = (s16)iVar7;
			iVar7 = uVar4;
		}

		entry[iEntry].entry.size = size;
	}
	return offset;
}

void *mmAlloc2(volatile int size, u32 tag, const char *name) { // 8007BADC
	u32 *tags;
	u32 *crash;
	volatile u32 crash2;
	void *result;

	tags = allocTagColorTbl;
	STUBBED_OP(tags);
	if(tag <= ALLOC_TAG_TEST_COL) tag = tags[tag];
	if(!size) {
		crash = NULL;
		crash2 = ((u32*)crash)[5];
		return NULL;
	}

	result = heapAlloc(1, size, tag, name);
	if(!result) {
		crash = NULL;
		crash2 = ((u32*)crash)[5];
	}
	return result;
}

void *heapAlloc(volatile int iHeap, volatile int size,
u32 tag, const char *name) { //8007BB74
	void *result;
	HeapEntry *data;
	int largest; //sp18
	int smallest; //r26
	int idx;
	int iEntry;
	u32 irq;

	largest = 0;
    irq = n64DisableInterrupts();

	heaps[iHeap].used2 += size;
    if(size) STUBBED_OP(tag); //could be wrong var
	if(heaps[iHeap].used + 1 == heaps[iHeap].avail) {
        n64EnableInterrupts(irq);
		return NULL;
	}

    if(size & 0x1f) size = (size & ~0x1F) + 0x20; //align
    iEntry = -1;
    smallest = 0x7fffffff;
	data = heaps[iHeap].data;
	idx  = 0;
    do {
		data = &data[idx];
        if(data->type != 0) continue;
		if((int)data->entry.size >= size) {
			if((int)data->entry.size >= smallest) continue;
			smallest = data->entry.size;
			iEntry = idx;
		} else if((int)data->entry.size > largest) {
			largest = data->entry.size;
		}
    } while((idx = data->next) != -1);

	//force these to be allocated on the stack
	//STUBBED_OP(&smallest);
	STUBBED_OP(&largest);
	STUBBED_OP(&tag);

    if(iEntry != -1) {
        heapSetEntry(iHeap, iEntry, size, 1, 0, tag, name);
        result = &data[iEntry].entry.loc;
        n64EnableInterrupts(irq);
        return *(void**)result;
    }
	//failure case
	//@bug interrupts aren't re-enabled
    if((iHeap == 2 && size > 0x3000) || (iHeap != 3 && iHeap == 1)) {
        STUBBED_OP(result);
    }
    return NULL;
}

void mmSetDelay(int delay) { // 8007BD28
	u32 irq;

	irq = n64DisableInterrupts();
	mmDelay = delay;
	if(delay == 0) {
		while(0 < freeListEntries) {
			_mmHeapFree(freeList[--freeListEntries].ptr);
		}
	}
	n64EnableInterrupts(irq);
	return;
}

void mmFree(void *__ptr) { // 8007BDA4
	u32 irq;
	irq = n64DisableInterrupts();
	if(mmDelay == 0) _mmHeapFree(__ptr);
	else _mmAddToFreeList(__ptr);
	n64EnableInterrupts(irq);
}

inline void countHeap(int idx, int *out) {
    int iVar3;
	HeapEntry *entry;
    entry = heaps[idx].data;
	do {
		if(entry->type) {
			*out += entry->entry.size;
		}
		iVar3 = entry->next;
		if(iVar3 == -1) break;
        entry = heaps[idx].data + iVar3;
	} while(iVar3 != -1);
}

inline void handleFreeLists() {
    u32 irq;
    int iVar3;

    irq = n64DisableInterrupts();
	iVar3 = 0;
	while(iVar3 < freeListEntries) {
		freeList[iVar3].delay--;
		if(freeList[iVar3].delay == 0) {
			_mmHeapFree(freeList[iVar3].ptr);
			freeList[iVar3].ptr = freeList[freeListEntries + -1].ptr;
			freeList[iVar3].delay = freeList[freeListEntries + -1].delay;
			freeListEntries--;
		} else {
			iVar3++;
		}
	}
	n64EnableInterrupts(irq);
}

void checkHeaps(void) { // 8007BDFC
	int pct;
	int iVar3;

	handleFreeLists();
	heapUsed0 = 0;
	heapUsed2 = 0; //out of order
	heapUsed1 = 0;
    countHeap(0, &heapUsed0);
    countHeap(1, &heapUsed1);
    countHeap(2, &heapUsed2);

	pct = memUsedPct++;
    iVar3 = 500;
	if(!(pct - ((pct / iVar3) * iVar3))) {
        getTotalHeapUsed(0);
    }
}

void _mmHeapFree(void *ptr) { // 8007BFD8
	int idx;
	HeapEntry *ent;
	int ii;

    idx = _mmGetHeapIdx(ptr);
	if(idx == -1) return;
    ent = heaps[idx].data;
	STUBBED_OP(ent);
    ii = 0;
    do {
        if(ent[ii].entry.loc == ptr) {
            if((ent[ii].type == 1) || (ent[ii].type == 4)) {
                if(idx) STUBBED_OP(&ptr);
                _mmActuallyFree(idx, ii);
            }
            return;
        }
        ii = (int)ent[ii].next;
    } while(ii != -1);
}

void _mmAddToFreeList(void *ptr) { // 8007C090
    if(freeListEntries >= 0x400) STUBBED_OP(ptr);
	freeList[freeListEntries].ptr = ptr;
	freeList[freeListEntries].delay = mmDelay;
	freeListEntries = freeListEntries + 1;
	return;
}

int _mmGetHeapIdx(void *offset) { // 8007C0DC
	int iHeap;

	iHeap = 0;
	while(iHeap < numHeaps) {
		if((offset > heaps[iHeap].data)
		&& (offset < (void *)((int)&((heaps[iHeap].data)->entry).loc
		    + heaps[iHeap].size))) {
			return iHeap;
        }
		iHeap = iHeap + 1;
	}
	return -1;
}

void _mmActuallyFree(int iHeap, int iEntry) { // 8007C154 regswap
	int next;
	int prev;
	int tmp;
	HeapEntry *entry;

	entry = heaps[iHeap].data;
	next  = entry[iEntry].next;
	prev  = entry[iEntry].prev;
	entry[iEntry].type = 0;
	fn_8018F9F0(entry[iEntry].entry.loc);
	heaps[iHeap].used2 -= entry[iEntry].entry.size;
	if((next != -1) && (entry[next].type == 0)) {
		entry[iEntry].entry.size += entry[next].entry.size;
		tmp = entry[next].next;
		entry[iEntry].next = tmp;
		if(tmp != -1) {
            entry[tmp].prev = (s16)iEntry;
        }
		entry[--heaps[iHeap].used].stack = next;
	}
	if((prev != -1) && (entry[prev].type == 0)) {
		entry[prev].entry.size += entry[iEntry].entry.size;
		next = entry[iEntry].next;
		entry[prev].next = next;
		if(next != -1) {
            entry[next].prev = prev;
        }
		entry[--heaps[iHeap].used].stack = (s16)iEntry;
	}
	return;
}

void *mmGetSlotPtr(int iHeap) { // 8007C310
	return (void *)heaps[iHeap].data;
}

int heapSetEntry(int iHeap, int iEntry, int size, int type,
int type2, u32 tag, const char *name) { // 8007C328
	int oldSize;
	int idx;
	HeapEntry *entry;

	entry = heaps[iHeap].data;
	entry[iEntry].type = type;
	oldSize = entry[iEntry].entry.size;
	entry[iEntry].entry.size = size;
	entry[iEntry].tag = tag;
	if(oldSize > size) {
		idx = entry[iEntry].next;
		if(((idx != -1) && (entry[idx].type == 0)) && (type2 == 0)) {
			//merge with next block
			entry[idx].entry.loc = &((u8*)entry[iEntry].entry.loc)[size];
			entry[idx].entry.size += oldSize - size;
            return idx;
		} else {
            idx = entry[heaps[iHeap].used++].stack;
			entry[idx].entry.loc = &((u8*)entry[iEntry].entry.loc)[size];
			entry[idx].entry.size = oldSize - size;
			entry[idx].type = type2;
			oldSize = entry[iEntry].next;
			entry[idx].next = oldSize;
			entry[idx].prev = iEntry;
			entry[iEntry].next = idx;
			if(oldSize != -1) entry[oldSize].prev = idx;
            return idx;
		}
	}
	return iEntry;
}

/**
 * @brief Returns the passed in address aligned to
 *  the next 16-byte boundary.
 *
 *  @param ptr The address.
 *  @return void* The aligned address.
 */
void* mmAlign16(void *ptr) { //8007C4AC
	int pad = (uint)ptr & 15;
	if(pad > 0) ptr = (void*)(((uint)ptr)+(16 - pad));
	return ptr;
}

/**
 * @brief Returns the passed in address aligned to
 *  the next 8-byte boundary.
 *
 *  @param ptr The address.
 *  @return void* The aligned address.
 */
void* mmAlign8(void *ptr) { //8007C4D4
	int pad = (uint)ptr & 7;
	if(pad > 0) ptr = (void*)(((uint)ptr)+(8 - pad));
	return ptr;
}

/**
 * @brief Returns the passed in address aligned to
 *  the next 4-byte boundary.
 *
 *  @param ptr The address.
 *  @return void* The aligned address.
 */
void* mmAlign4(void *ptr) { //8007C4FC
	int pad = (uint)ptr & 3;
	if(pad > 0) ptr = (void*)(((uint)ptr)+(4 - pad));
	return ptr;
}

/**
 * @brief Returns the passed in address aligned to
 *  the next 2-byte boundary.
 *
 *  @param ptr The address.
 *  @return void* The aligned address.
 */
void* mmAlign2(void *ptr) { //8007C524
	int pad = (uint)ptr & 1;
	if(pad > 0) ptr = (void*)(((uint)ptr)+(2 - pad));
	return ptr;
}

#ifdef __MWERKS__
#pragma peephole off
#endif
int getTotalHeapUsed(int unused) { //8007C54C
	register Heap *dummy = heaps;
	return heapUsed0 + heapUsed1 + heapUsed2;
}
