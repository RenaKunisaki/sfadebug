#ifndef _GFX_TEXTURES_H_
#define _GFX_TEXTURES_H_
#include "../types.h"
#include "dolphin/gx/GXStruct.h"
typedef struct Texture {
    // /* 0x00 */ struct Texture *next;
    /* 0x00 */ float unk00;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ s8 unk06;
    /* 0x07 */ s8 unk07;
    /* 0x08 */ s8 unk08;
    /* 0x09 */ s8 unk09;
    /* 0x0a */ ushort width;
    /* 0x0c */ ushort height;
    /* 0x0e */ u8 flags;
    /* 0x0f */ u8 unk0F;
    /* 0x10 */ short unk10;
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
    /* 0x1e */ char unk1e;
    /* 0x1f */ s8 unk1f;
    /* 0x20 */ uint unk20;
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
    /* 0x30 */ struct Texture **self;
    /* 0x34 */ s8 unk34;
    /* 0x35 */ s8 unk35;
    /* 0x36 */ s8 unk36;
    /* 0x37 */ s8 unk37;
    /* 0x38 */ s8 unk38;
    /* 0x39 */ s8 unk39;
    /* 0x3a */ s8 unk3a;
    /* 0x3b */ s8 unk3b;
    /* 0x3c */ s8 unk3c;
    /* 0x3d */ s8 unk3d;
    /* 0x3e */ s8 unk3e;
    /* 0x3f */ s8 unk3f;
    /* 0x40 */ UNKTYPE *unk40;
    /* 0x44 */ int unk44;
    /* 0x48 */ s8 unk48;
    /* 0x49 */ s8 unk49;
    /* 0x4a */ s8 unk4a;
    /* 0x4b */ s8 unk4b;
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
    /* 0x58 */ s8 unk58;
    /* 0x59 */ s8 unk59;
    /* 0x5a */ s8 unk5a;
    /* 0x5b */ s8 unk5b;
    /* 0x5c */ s8 unk5c;
    /* 0x5d */ s8 unk5d;
    /* 0x5e */ s8 unk5e;
    /* 0x5f */ s8 unk5f;
} Texture;

typedef struct TextureStruct4 {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ s8 unk03;
    /* 0x04 */ undefined4 unk04;
    /* 0x08 */ uint unk08;
    /* 0x0c */ Texture *pTexture2C;
    /* 0x10 */ Texture *pTexture30;
    /* 0x14 */ uint format;
    /* 0x18 */ Texture *pTexture18;
    /* 0x1c */ ushort blockSize;
    /* 0x1e */ u8 pixelFmt; //0=CMPR 1=4bpp 2=8bpp 3=32bpp
    /* 0x1f */ u8 flags_0x1f;
} TextureStruct4;

typedef struct Texture2 {
    /* 0x00 */ struct Texture2 *next; //next mipmap/frame
    /* 0x04 */ uint flags;
    /* 0x08 */ short xOffset;
    /* 0x0a */ ushort width;
    /* 0x0c */ ushort height;
    /* 0x0e */ short refCount;
    /* 0x10 */ short nFrames;
    /* 0x12 */ s8 unk12;
    /* 0x13 */ s8 unk13;
    /* 0x14 */ ushort unk14;
    /* 0x16 */ u8 format; //TextureFormat
    /* 0x17 */ GXColor unk17;
    /* 0x1b */ s8 unk1b;
    /* 0x1c */ s8 unk1c;
    /* 0x1d */ s8 unk1d;
    /* 0x1e */ s8 unk1e;
    /* 0x1f */ s8 unk1f;
    /* 0x20 */ TextureStruct4 unk20;
    /* 0x40 */ undefined4 unk40;
    /* 0x44 */ int dataSize;
    /* 0x48 */ s8 unk48;
    /* 0x49 */ s8 unk49;
    /* 0x4a */ s8 unk4a;
    /* 0x4b */ s8 unk4b;
    /* 0x4c */ uint size;
    /* 0x50 */ u32 unk50;
    /* 0x54 */ s8 unk54;
    /* 0x55 */ s8 unk55;
    /* 0x56 */ s8 unk56;
    /* 0x57 */ s8 unk57;
    /* 0x58 */ s8 unk58;
    /* 0x59 */ s8 unk59;
    /* 0x5a */ s8 unk5a;
    /* 0x5b */ s8 unk5b;
    /* 0x5c */ s8 unk5c;
    /* 0x5d */ s8 unk5d;
    /* 0x5e */ s8 unk5e;
    /* 0x5f */ s8 unk5f;
    /* 0x60 */ u8 data[];
} Texture2;

typedef union {
    Texture *ptr;
    int id;
} TexturePtr;

#endif //_GFX_TEXTURES_H_
