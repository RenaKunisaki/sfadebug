#ifndef _GFX_MODELS_ANIMATION_H_
#define _GFX_MODELS_ANIMATION_H_
//#include "gfx/models/models.h"

typedef struct { //XXX populate
    /* 0x00 */ s8 usage; //reference count
    //...more...
} Animation;

typedef struct {
    /* 0x00 */ struct Model *model;
    /* 0x04 */ float hitboxSize;
    /* 0x08 */ float unk08;
    /* 0x0c */ undefined4 unk0c;
    /* 0x10 */ undefined4 unk10;
    /* 0x14 */ float unk14;
    /* 0x18 */ uint mtxSize;
    /* 0x1c */ float *unk1c;
    /* 0x20 */ void *unk20;
    /* 0x24 */ void *unk24;
    /* 0x28 */ void *unk28;
    /* 0x2c */ s8 unk2c;
    /* 0x2d */ s8 unk2d;
    /* 0x2e */ s8 unk2e;
    /* 0x2f */ s8 unk2f;
    /* 0x30 */ int x;
    /* 0x34 */ int y;
    /* 0x38 */ int z;
    /* 0x3c */ undefined4 unk3c;
    /* 0x40 */ undefined4 unk40;
    /* 0x44 */ ushort unk44;
    /* 0x46 */ ushort unk46;
    /* 0x48 */ undefined2 unk48;
    /* 0x4a */ undefined2 unk4a;
    /* 0x4c */ s8 unk4c;
    /* 0x4d */ s8 unk4d;
    /* 0x4e */ s8 unk4e;
    /* 0x4f */ s8 unk4f;
    /* 0x50 */ s8 unk50;
    /* 0x51 */ s8 unk51;
    /* 0x52 */ s8 unk52;
    /* 0x53 */ s8 unk53;
    /* 0x54 */ s8 unk54;
    /* 0x55 */ s8 unk55;
    /* 0x56 */ s8 unk56;
    /* 0x57 */ s8 unk57;
    /* 0x58 */ short unk58;
    /* 0x5a */ short unk5a;
    /* 0x5c */ short unk5c;
    /* 0x5e */ short unk5e;
    /* 0x60 */ s8 unk60;
    /* 0x61 */ s8 unk61;
    /* 0x62 */ char unk62;
    /* 0x63 */ s8 unk63;
    /* 0x64 */ undefined2 unk64;
    /* 0x66 */ s8 unk66;
    /* 0x67 */ s8 unk67;
} AnimInstance;

#endif //_GFX_MODELS_ANIMATION_H_
