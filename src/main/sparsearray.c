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
	sparseArray->lastElem = &sparseArray->items->key;
	sparseArray->highPtr = &sparseArray->items[
        capacity * sparseArray->elemSize].key;
	memset_(sparseArray->items, -1,
        sparseArray->elemSize * 2 * capacity);
	return sparseArray;
}
