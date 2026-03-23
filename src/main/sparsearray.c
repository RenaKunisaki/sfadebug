#include "dolphin.h"
#include "macros.h"
#include "sys/alloc.h"
#include "sys/SparseArray.h"

SparseArray *SparseArray_create(int capacity, int itemSize) {
	SparseArray *sparseArray;
    int size;

    size = capacity * (itemSize + sizeof(SparseArrayItem)) + sizeof(SparseArray);
	sparseArray = (SparseArray *)mmAlloc(size,
	    ALLOC_TAG_TEST_COL, "dtype:sparseArray");
    ASSERTLINE(43, sparseArray);
	sparseArray->items = (SparseArrayItem *)((int)sparseArray + sizeof(SparseArray));
	sparseArray->keySize = itemSize;
	sparseArray->elemSize = (itemSize + 2U) >> 1;
	sparseArray->lastElem = (SparseArrayItem*)&sparseArray->items->key;
	sparseArray->endPtr = (SparseArrayItem*)&sparseArray->items[
        capacity * sparseArray->elemSize].key;
	memset_(sparseArray->items, -1,
        sparseArray->elemSize * 2 * capacity);
	return sparseArray;
}

void SparseArray_set(SparseArray *sparseArray, short key, void *newElement) {
	SparseArrayItem *keyPtr;

    ASSERTLINE(95, sparseArray);
    ASSERTLINE(96, newElement);
	for(keyPtr = sparseArray->items;
	    keyPtr < (SparseArrayItem *)sparseArray->lastElem;
	    keyPtr += sparseArray->elemSize) {
            if(keyPtr->key == -1) break;
        }
    ASSERTLINE(110, keyPtr<sparseArray->endPtr);
	keyPtr->key = key;
	memcpy(keyPtr + 1, newElement, (uint)sparseArray->keySize);
	if(keyPtr == (SparseArrayItem *)sparseArray->lastElem) {
		sparseArray->lastElem = sparseArray->lastElem + sparseArray->elemSize;
	}
}
