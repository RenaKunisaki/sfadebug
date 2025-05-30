#ifndef _GFX_MODELS_MODELS_H_
#define _GFX_MODELS_MODELS_H_
#include "gfx/textures.h"
#include "gfx/models/skeleton.h"
#include "gfx/models/bitstream.h"
#include "gfx/models/hit.h"
#include "gfx/models/shaders.h"
#include "gfx/models/animation.h"

typedef enum {
    ModelDataFlags2_NoAnimations       =     2,
    ModelDataFlags2_CopyVtxsOnLoad     =    16,
    ModelDataFlags2_BoneRelated        =    32,
    ModelDataFlags2_UseLocalModAnimTab =    64,
    ModelDataFlags2_FogRelated         =   256,
    ModelDataFlags2_NoDepthTest        =  1024,
    ModelDataFlags2_ModelField14Valid  =  4096,
    ModelDataFlags2_AlphaZUpdateEnable =  8192,
    ModelDataFlags2_AltRenderInstrs    = 32768,
} ModelDataFlags2;

typedef enum {
    ModelFlags18_UseOtherMtxs     =  1,
    ModelFlags18_UseOtherVtxs     =  2,
    ModelFlags18_UseOtherHitboxes =  4,
    ModelFlags18_MtxsLoaded       =  8,
    ModelFlags18_ShadersLoaded    = 64,
} ModelFlags18;

typedef struct {
    /* 0x00 */ void *displayList; //to raw GX commands
    /* 0x04 */ u16 length;
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

typedef struct {
    /* 0x00 */ s8 usage; //ref count
    /* 0x01 */
    /* 0x02 */ u16 flags; //ModelDataFlags2
    /* 0x04 */ short cacheModNo; //model ID, set on load
    /* 0x06 */
    /* 0x07 */
    /* 0x08 */ int headerCksum;
    /* 0x0c */ int dataSize; //size of this file
    /* 0x10 */ s8 unk10;
    /* 0x11 */ s8 unk11;
    /* 0x12 */ s8 unk12;
    /* 0x13 */ s8 unk13;
    /* 0x14 */ float *skeleton;
    /* 0x18 */ float *radi;
    /* 0x1c */ u32 *exT; //extraAmapSize (dlInfoSize?)
    /* 0x20 */ Texture **GCtextures; //-> texture IDs that get turned into pointers
    /* 0x24 */ Vec *normals; //either 1 or 3 vecs per (presumably) face
    /* 0x28 */ S16Vec *vertexPositions;
    /* 0x2c */ Vec *vertexNormals;
    /* 0x30 */ u16 *vertexColours;
    /* 0x34 */ Vec *vertexTexCoords;
    /* 0x38 */ Shader *shaders;
    /* 0x3c */ Bone *joints;
    /* 0x40 */ void *sphereHits;
    /* 0x44 */ UNKTYPE *GCpolygons;
    /* 0x48 */ PolygonGroup *polygonGroups;
    /* 0x4c */ UNKTYPE **anims;
    /* 0x50 */ HitSpherePos *curHitSpherePos; //=hitSpherePositions[n] for current frame
    /* 0x54 */ s16 *animIds;
    /* 0x58 */ UNKTYPE *unk58;
    /* 0x5c */ s8 unk5c;
    /* 0x5d */ s8 unk5d;
    /* 0x5e */ s8 unk5e;
    /* 0x5f */ s8 unk5f;
    /* 0x60 */ s8 unk60;
    /* 0x61 */ s8 unk61;
    /* 0x62 */ s8 unk62;
    /* 0x63 */ s8 unk63;
    /* 0x64 */ s8 unk64;
    /* 0x65 */ s8 unk65;
    /* 0x66 */ s8 unk66;
    /* 0x67 */ s8 unk67;
    /* 0x68 */ u32 animOffset;
    /* 0x6c */ short animCacheSize;
    /* 0x6e */ s8 unk6e;
    /* 0x6f */ s8 unk6f;
    /* 0x70 */ s8 unk70;
    /* 0x71 */ s8 unk71;
    /* 0x72 */ ushort unk72;
    /* 0x74 */ s8 unk74;
    /* 0x75 */ s8 unk75;
    /* 0x76 */ s8 unk76;
    /* 0x77 */ s8 unk77;
    /* 0x78 */ s8 unk78;
    /* 0x79 */ s8 unk79;
    /* 0x7a */ s8 unk7a;
    /* 0x7b */ s8 unk7b;
    /* 0x7c */ int unk7c;
    /* 0x80 */ s8 unk80;
    /* 0x81 */ s8 unk81;
    /* 0x82 */ s8 unk82;
    /* 0x83 */ s8 unk83;
    /* 0x84 */ s8 unk84;
    /* 0x85 */ s8 unk85;
    /* 0x86 */ s8 unk86;
    /* 0x87 */ s8 unk87;
    /* 0x88 */ s8 unk88;
    /* 0x89 */ s8 unk89;
    /* 0x8a */ s8 unk8a;
    /* 0x8b */ s8 unk8b;
    /* 0x8c */ void *skin2Matrices;
    /* 0x90 */ UNKTYPE *skinWeights;
    /* 0x94 */ DisplayList *displayLists;
    /* 0x98 */ BitStream *renderStream;
    /* 0x9c */ s8 unk9c;
    /* 0x9d */ s8 unk9d;
    /* 0x9e */ s8 unk9e;
    /* 0x9f */ s8 unk9f;
    /* 0xa0 */ UNKTYPE *vertexAnims;
    /* 0xa4 */ s16 unka4;
    /* 0xa6 */ u16 flagsA6;
    /* 0xa8 */ ushort numPositions;
    /* 0xaa */ s8 unkaa;
    /* 0xab */ s8 unkab;
    /* 0xac */ s8 unkac;
    /* 0xad */ s8 unkad;
    /* 0xae */ s8 unkae;
    /* 0xaf */ s8 unkaf;
    /* 0xb0 */ u16 numAnims;
    /* 0xb2 */ s16 numGcPolygons;
    /* 0xb4 */ s16 numPolyGroups;
    /* 0xb6 */ u8 numTextures;
    /* 0xb7 */ u8 animLength;
    /* 0xb8 */ s8 unkb8;
    /* 0xb9 */ u8 nHitSpheres;
    /* 0xba */ u8 nShaders;
    /* 0xbb */ u8 bCopyVtxsToModelInst;
} Model;

typedef struct {
    Mtx44 *mtx[2];
    S16Vec unk;
} ModelInstanceField54;

typedef struct {
    /* 0x00 */ Model *model;
    /* 0x04 */ S16Vec *vertexPositions2;
    /* 0x08 */ s8 unk08;
    /* 0x09 */ s8 unk09;
    /* 0x0a */ s8 unk0a;
    /* 0x0b */ s8 unk0b;
    /* 0x0c */ Mtx44 *mtxs[2];
    /* 0x14 */ float **unk14;
    /* 0x18 */ u16 flags; //ModelFlags18 40:shaders loaded
    /* 0x1a */ s8 unk1a;
    /* 0x1b */ s8 unk1b;
    /* 0x1c */ S16Vec *vertexPositions[2];
    /* 0x24 */ AnimInstance *animInstances[2];
    /* 0x2c */ ShaderDef *shaderDefs;
    /* 0x30 */ UNKTYPE *texFuncPtr;
    /* 0x34 */ uint unk34;
    /* 0x38 */ uint unk38;
    /* 0x3c */ int unk3c;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ uint unk44;
    /* 0x48 */ void *unk48;
    /* 0x4c */ Mtx44 *unk4c;
    /* 0x50 */ s8 unk50;
    /* 0x51 */ s8 unk51;
    /* 0x52 */ s8 unk52;
    /* 0x53 */ s8 unk53;
    /* 0x54 */ ModelInstanceField54 *field54;
} ModelInstance;

#endif //_GFX_MODELS_MODELS_H_
