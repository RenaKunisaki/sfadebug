#ifndef _GFX_MODELS_HIT_H_
#define _GFX_MODELS_HIT_H_
#include "types.h"
#include "dolphin/mtx.h"

typedef struct {
    /* 0x00 */ int firstPolygon;
    /* 0x04 */ S16Vec *vtxs;
    /* 0x08 */ ushort nTris;
    /* 0x0a */ short unk0a;
    /* 0x0c */ ushort unk0c;
    /* 0x0e */ s8 unk0e;
    /* 0x0f */ s8 unk0f;
    /* 0x10 */ uint	flags;
} PolygonGroup;

typedef struct {
    /* 0x0 */ float radius;
    /* 0x4 */ Vec pos;
} HitSpherePos;

typedef struct {
    /* 0x00 */ float radius;
    /* 0x04 */ Vec pos;
} RamHitSphere; //hitbox in memory

typedef struct {
    /* 0x00 */ s16 bone; //bone idx
    /* 0x02 */ s16 unk02; //always 0?
    /* 0x04 */ float radius;
    /* 0x08 */ Vec pos; //offset from bone
    /* 0x14 */ u8 unk14; //always 0?
    /* 0x15 */ u8 unk15; //always 0?
    /* 0x16 */ u8 unk16; //increments
    /* 0x17 */ u8 unk17; //same as 0x16?
} HitSphere; //hitbox in model file

#endif //_GFX_MODELS_HIT_H_
