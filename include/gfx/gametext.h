#ifndef _GFX_GAMETEXT_H_
#define _GFX_GAMETEXT_H_
#include "types.h"

typedef struct {
    /* 0x0 */ s8 unk00;
    /* 0x1 */ s8 unk01;
    /* 0x2 */ s8 unk02;
    /* 0x3 */ s8 unk03;
    /* 0x4 */ void *unk04;
    /* 0x8 */ s8 *data;
} GameTextGroup;

#endif //_GFX_GAMETEXT_H_
