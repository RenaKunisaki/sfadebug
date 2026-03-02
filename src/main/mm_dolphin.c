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

const char *allocTagNames[] = {
	"LISTS_COL",
	"SCREEN_COL",
	"CODE_COL",
	"TRACK_COL",
	"TRACKTEX_COL",
	"SPRITETEX_COL",
	"MODELS_COL",
	"ANIMS_COL",
	"AUDIO_COL",
	"OBJECTS_COL",
	"ANIMSEQ_COL",
	"EXPGFX_COL",
	"MODGFX_COL",
	"PROJGFX_COL",
	"SHAD_COL",
	"GAME_COL",
	"TEST_COL"};

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


//debug strings that need to be put in appropriate places
// * marks those that have been placed
// * "LISTS_COL"
// * "SCREEN_COL"
// * "CODE_COL"
// * "TRACK_COL"
// * "TRACKTEX_COL"
// * "SPRITETEX_COL"
// * "MODELS_COL"
// * "ANIMS_COL"
// * "AUDIO_COL"
// * "OBJECTS_COL"
// * "ANIMSEQ_COL"
// * "EXPGFX_COL"
// * "MODGFX_COL"
// * "PROJGFX_COL"
// * "SHAD_COL"
// * "GAME_COL"
// * "TEST_COL"
// * "####### MEM large %d  overall %d\n"
// * "####### MEM medium %d\n"
// * "mm_dolphin.c""Memory region setup is too big"
// * "####### MEM small %d\n"
// * "1:mmAlloc(%d,%d): Size==0 : RA:0x%08x\n"
// * "4:mmAlloc(%s,%d): failed : RA:0x%08x\n"
//   "mmRealloc(0x%08x,%d), RA:0x%08x\n"
//   "mmAllocDi(%s,%d): Size==0 : RA:0x%08x\n"
//   "mmAllocDi(%s,%d): failed : RA:0x%08x\n"
//   "*** mmAlloc: size = 0 ***\n"
//   "1: *** mm Error *** ---> '%s' No more slots available.\n"
//   "\n2: *** mm Error *** --->  '%s' region=%d col=%x wantsize=%d largestsize=%d...No suitble block found for allocation.\n"
//   "*** mmAllocAtAddr: '%s' size = 0 ***\n"
//   "\n3: *** mm Error *** ---> No more slots available.\n"
//   "\n4: *** mm Error *** ---> Can't allocate memory '%s' at desired address.\n"
//   "\n5: *** mm Error *** ---> Can't free ram at this location: %x\n"
//   "\n6: *** mm Error *** ---> No match found for mmFree, %08x.\n"
//   "\n7: *** mm Error *** ---> stbf stack too deep!\n"
//   "mem %dk/%dk %dk/%dk %dk/%dk\n\tslot %d/%d %d/%d %d/%d\t\n"
//   "mm:audioheap"


void _mmHeapFree(void *ptr);
void _mmAddToFreeList(void *ptr);
void _mmActuallyFree(int iHeap, int iEntry);

void initHeaps(void) { // 8007B3A4
	int frameBufSize;
	int size;
	void *ptr;
	void *arenaEnd;
	OSHeapHandle heap;

	numHeaps = 0;
	ptr = OSGetArenaLo();
	frameBufSize = (curTvParams->width + 0xf & 0xfff0) * curTvParams->height2 * 2;
	pFrameBuffer_80398b74 = (void *)OSRoundUp32B(ptr);
	pFrameBuffer_80398b70 = (void *)OSRoundUp32B((u32)pFrameBuffer_80398b74 + frameBufSize);
	ptr = (void *)OSRoundUp32B((u32)pFrameBuffer_80398b70 + frameBufSize);
	OSSetArenaLo(ptr);

	arenaEnd = OSGetArenaHi();
	ptr = OSInitAlloc(ptr, arenaEnd, 1);
	OSSetArenaLo(ptr);

	ptr = (void *)OSRoundUp32B(ptr);
	arenaEnd = (void *)((uint)arenaEnd & ~0x1f);
	heap = OSCreateHeap(ptr, arenaEnd);
	OSSetCurrentHeap(heap);

	size = (uint)arenaEnd - (uint)ptr - 0x5a0000;
	ptr = OSAllocFromHeap(__OSCurrHeap, size);
	//missing parameter here, no way to know what
	STUBBED_PRINTF("####### MEM large %d  overall %d\n", size);
	memset_(ptr, 0, size);
	DCFlushRange(ptr, size);
	heapInit((HeapEntry *)ptr, size, 750);

    size = 0x500000;
	ptr = OSAllocFromHeap(__OSCurrHeap, size);
	STUBBED_PRINTF("####### MEM medium %d\n", size);
	memset_(ptr, 0, size);
	DCFlushRange(ptr, size);
	heapInit((HeapEntry *)ptr, size, 1450);

    size = 0x5a0000 - (0x500000 + 0x60); //0x9ffa0
	ptr = OSAllocFromHeap(__OSCurrHeap, size);
	if(!ptr) {
		OSPanic(__FILE__, 322, "Memory region setup is too big");
	}
	STUBBED_PRINTF("####### MEM small %d\n", size);
	memset_(ptr, 0, size);
	DCFlushRange(ptr, size);
	heapInit((HeapEntry *)ptr, size, 1900);
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
	void *crash;
	volatile u32 crash2;

	if(!size) {
		STUBBED_PRINTF("1:mmAlloc(%d,%d): Size==0 : RA:0x%08x\n");
		crash = NULL;
		crash2 = *(volatile u32 *)((u32)crash + 0x14);
		return NULL;
	}

	if(tag <= ALLOC_TAG_TEST_COL) tag = allocTagColorTbl[tag];
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
		STUBBED_PRINTF("4:mmAlloc(%s,%d): failed : RA:0x%08x\n");
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
	u32 irq; //r24

	largest = 0;
    irq = n64DisableInterrupts();

	heaps[iHeap].used2 += size;
    if(size) STUBBED_OP(tag); //could be wrong var
	if(heaps[iHeap].used + 1 == heaps[iHeap].avail) {
		//out of slots
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
	//STUBBED_OP(&tag);

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
