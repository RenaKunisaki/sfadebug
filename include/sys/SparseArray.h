#ifndef _SYS_SPARSEARRAY_H_
#define _SYS_SPARSEARRAY_H_

typedef struct {
    short key;
    u8 data[0];
} SparseArrayItem;

typedef struct {
    /* 0x00 */ SparseArrayItem *items;
    /* 0x04 */ short *lastElem;
    /* 0x08 */ short *highPtr;
    /* 0x0c */ u8 keySize;
    /* 0x0d */ u8 elemSize;
} SparseArray;

#endif //_SYS_SPARSEARRAY_H_
