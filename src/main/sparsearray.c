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
	sparseArray->highPtr = (SparseArrayItem*)&sparseArray->items->key;
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
	    keyPtr < (SparseArrayItem *)sparseArray->highPtr;
	    keyPtr += sparseArray->elemSize) {
            if(keyPtr->key == -1) break;
        }
    ASSERTLINE(110, keyPtr<sparseArray->endPtr);
	keyPtr->key = key;
	memcpy(keyPtr + 1, newElement, (uint)sparseArray->keySize);
	if(keyPtr == (SparseArrayItem *)sparseArray->highPtr) {
		sparseArray->highPtr = sparseArray->highPtr + sparseArray->elemSize;
	}
}

void SparseArray_remove(SparseArray *sparseArray, int key) {
	SparseArrayItem *keyPtr;

    ASSERTLINE(144, sparseArray);
	for(keyPtr = sparseArray->items;
    keyPtr < sparseArray->highPtr;
    keyPtr += sparseArray->elemSize) {
		if(keyPtr->key == key) {
            keyPtr->key = -1;
            break;
        }
	}

    ASSERTLINE(157, keyPtr!=sparseArray->highPtr);
    while((sparseArray->highPtr > sparseArray->items
    &&    (sparseArray->highPtr[-1].key == -1))) {
        sparseArray->highPtr -= sparseArray->elemSize;
    }
}

BOOL SparseArray_get(SparseArray *sparseArray, int id, void *element) {
	SparseArrayItem *keyPtr;

    ASSERTLINE(188, sparseArray);
    ASSERTLINE(189, element);
	keyPtr = sparseArray->items;
	while(keyPtr < sparseArray->highPtr) {
		if(keyPtr->key == id) {
            memcpy(element, keyPtr + 1,
                sparseArray->keySize);
	        return TRUE;
        }
		keyPtr += sparseArray->elemSize;
	}
    return FALSE;
}
