#ifndef _GFX_MODELS_HIT_H_
#define _GFX_MODELS_HIT_H_

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

#endif //_GFX_MODELS_HIT_H_
