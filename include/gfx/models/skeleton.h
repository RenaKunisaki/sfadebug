#ifndef _GFX_MODELS_SKELETON_H_
#define _GFX_MODELS_SKELETON_H_
#include "../types.h"
#include "dolphin/mtx.h"

#define MAX_JOINTS 150
typedef struct {
    /* 0x00 */ s8 parent; //high bit is a flag?
    /* 0x01 */ s8 idx[3]; //idx to write to?
    /* 0x04 */ Vec translation;
    /* 0x10 */ Vec bindTranslation;
} Bone;

typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ float *unk04; //radi * scale
    /* 0x08 */ float *unk08; //previous value squared
    /* 0x0c */ float *jointDist; //xlate distance from centre
    /* 0x10 */ float *totalDist; //distance + ancestor distances
} ModelSkeletonStruct;

#endif //_GFX_MODELS_SKELETON_H_
