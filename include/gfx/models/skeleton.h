#ifndef _GFX_MODELS_SKELETON_H_
#define _GFX_MODELS_SKELETON_H_
#include "../types.h"
#include "dolphin/mtx.h"

#define MAX_JOINTS 150
typedef struct {
    //these are sometimes s8, sometimes u8?
    /* 0x00 */ s8 idx[2]; //idx to write to? high bit is a flag?; first idx is parent
    /* 0x02 */ u8 idx2[2]; //weird
    /* 0x04 */ Vec translation;
    /* 0x10 */ Vec bindTranslation;
} Bone;

typedef struct {
    /* 0x00 */ Vec *joints;
    /* 0x04 */ float *scale; //radi * scale, per joint
    /* 0x08 */ float *unk08; //previous value squared, per joint
    /* 0x0c */ float *jointDist; //xlate distance from centre, per joint
    /* 0x10 */ float *totalDist; //distance + ancestor distances, per joint
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 *unk18; //something renders as white if *this is 0, else black, per joint
    /* 0x1c */ //s8 *unk1C;
} ModelSkeletonStruct;

#endif //_GFX_MODELS_SKELETON_H_
