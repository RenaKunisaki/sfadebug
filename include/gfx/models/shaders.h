#ifndef _GFX_MODELS_SHADERS_H_
#define _GFX_MODELS_SHADERS_H_
#include "gfx/textures.h"

typedef enum {
    GCShaderAttribute_HasFog = 2,
    GCShaderAttribute_BackfaceCulling = 4,
    GCShaderAttribute_BlendModeFlag10 = 16,
    GCShaderAttribute_BlendModeFlag20 = 32,
    GCShaderAttribute_BlendModeFlag40 = 64,
    GCShaderAttribute_IsWater = 128,
} GCShaderAttributes;

typedef struct {
    /* 0x0 */ Texture *texture; //actual texture
    /* 0x4 */ UNKTYPE *lighting; //material/lighting - setting texture AND lighting to null causes glitches
} ShaderDef;

typedef struct {
    /* 0x0 */ Texture *texture;
    /* 0x4 */ s8 unk04;
    /* 0x5 */ s8 unk05;
    /* 0x6 */ s8 texScrollIdx;
    /* 0x7 */ s8 unk07;
} ShaderLayer;

typedef struct {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ s8 unk03;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ s8 unk06;
    /* 0x07 */ s8 unk07;
    /* 0x08 */ s32 unk08;
    /* 0x0c */ s8 unk0c;
    /* 0x0d */ s8 unk0d;
    /* 0x0e */ s8 unk0e;
    /* 0x0f */ s8 unk0f;
    /* 0x10 */ s8 unk10;
    /* 0x11 */ s8 unk11;
    /* 0x12 */ s8 unk12;
    /* 0x13 */ s8 unk13;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ Texture *tex18;
    /* 0x1c */ Texture *tex1C;
    /* 0x20 */ s8 unk20;
    /* 0x21 */ s8 unk21;
    /* 0x22 */ s8 unk22;
    /* 0x23 */ s8 unk23;
    /* 0x24 */ ShaderLayer layer[2];
    /* 0x34 */ Texture *tex34;
    /* 0x38 */ u16 attributes; //GCShaderAttributes
    /* 0x3a */ s8 unk3a;
    /* 0x3b */ s8 numLayers;
    /* 0x3c */ s8 unk3c;
    /* 0x3d */ s8 unk3d;
    /* 0x3e */ s8 unk3e;
    /* 0x3f */ s8 unk3f;
} Shader;

#endif //_GFX_MODELS_SHADERS_H_
