#ifndef _GFX_DISPLAYLIST_H_
#define _GFX_DISPLAYLIST_H_

#include "types.h"

typedef struct {
    /* 0x00 */ void *displayList; //to raw GX commands
    /* 0x04 */ u16 displayListSize;
    /* 0x06 */ s8 unk06;
    /* 0x07 */ s8 unk07;
    /* 0x08 */ s8 unk08;
    /* 0x09 */ s8 unk09;
    /* 0x0a */ s8 unk0a;
    /* 0x0b */ s8 unk0b;
    /* 0x0c */ s8 unk0c;
    /* 0x0d */ s8 unk0d;
    /* 0x0e */ s8 unk0e;
    /* 0x0f */ s8 unk0f;
    /* 0x10 */ s8 unk10;
    /* 0x11 */ s8 unk11;
    /* 0x12 */ s8 unk12;
    /* 0x13 */ s8 unk13;
    /* 0x14 */ s8 unk14;
    /* 0x15 */ s8 unk15;
    /* 0x16 */ s8 unk16;
    /* 0x17 */ s8 unk17;
    /* 0x18 */ s8 unk18;
    /* 0x19 */ s8 unk19;
    /* 0x1a */ s8 unk1a;
    /* 0x1b */ s8 unk1b;
    /* 0x1c */ s8 unk1c;
    /* 0x1d */ s8 unk1d;
    /* 0x1e */ s8 unk1e;
    /* 0x1f */ s8 unk1f;
    /* 0x20 */ s8 unk20;
    /* 0x21 */ s8 unk21;
    /* 0x22 */ s8 unk22;
    /* 0x23 */ s8 unk23;
    /* 0x24 */ s8 unk24;
    /* 0x25 */ s8 unk25;
    /* 0x26 */ s8 unk26;
    /* 0x27 */ s8 unk27;
    /* 0x28 */ s8 unk28;
    /* 0x29 */ s8 unk29;
    /* 0x2a */ s8 unk2a;
    /* 0x2b */ s8 unk2b;
    /* 0x2c */ s8 unk2c;
    /* 0x2d */ s8 unk2d;
    /* 0x2e */ s8 unk2e;
    /* 0x2f */ s8 unk2f;
    /* 0x30 */ s8 unk30;
    /* 0x31 */ s8 unk31;
    /* 0x32 */ s8 unk32;
    /* 0x33 */ s8 unk33;
} DisplayList;

#endif //_GFX_DISPLAYLIST_H_
