#ifndef _SYS_SPARSEARRAY_H_
#define _SYS_SPARSEARRAY_H_
#include "dolphin/types.h"

typedef struct {
    short key;
    u8 data[0];
} SparseArrayItem;

typedef struct {
    /* 0x00 */ SparseArrayItem *items;
    /* 0x04 */ SparseArrayItem *highPtr;
    /* 0x08 */ SparseArrayItem *endPtr;
    /* 0x0c */ u8 keySize;
    /* 0x0d */ u8 elemSize;
    //2 bytes padding
} SparseArray;

SparseArray* SparseArray_create(int capacity,int itemSize);
BOOL SparseArray_get(SparseArray *sparseArray,int id,void *element);
void SparseArray_set(SparseArray *sparseArray,short key,void *newElement);
BOOL SparseArray_find(SparseArray *sparseArray,void *element,int *key);
void SparseArray_remove(SparseArray *sparseArray,int key);

#endif //_SYS_SPARSEARRAY_H_
