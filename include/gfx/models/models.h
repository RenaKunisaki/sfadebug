#ifndef _GFX_MODELS_MODELS_H_
#define _GFX_MODELS_MODELS_H_
#include "gfx/textures.h"
#include "gfx/models/skeleton.h"
#include "gfx/models/bitstream.h"
#include "gfx/models/hit.h"
#include "gfx/models/shaders.h"
#include "sys/SparseArray.h"

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
    ModelFlags18_UseOtherMtxs     =  1, //which index into jMtxs to use
    ModelFlags18_UseOtherVtxs     =  2,
    ModelFlags18_UseOtherHitboxes =  4,
    ModelFlags18_MtxsLoaded       =  8,
    ModelFlags18_ShadersLoaded    = 64,
} ModelFlags18;

typedef struct {
    u8 unknown[8];
} GCPolygon;

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
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ u8 unk0c;
    /* 0x0d */ u8 unk0d;
    /* 0x0e */ u8 unk0e;
    /* 0x0f */ u8 unk0f;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1a */ u8 unk1a;
    /* 0x1b */ u8 unk1b;
    /* 0x1c */ u8 unk1c;
    /* 0x1d */ u8 unk1d;
    /* 0x1e */ u8 unk1e;
    /* 0x1f */ u8 unk1f;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2a */ u8 unk2a;
    /* 0x2b */ u8 unk2b;
    /* 0x2c */ u8 unk2c;
    /* 0x2d */ u8 unk2d;
    /* 0x2e */ u8 unk2e;
    /* 0x2f */ u8 unk2f;
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 unk31;
    /* 0x32 */ u8 unk32;
    /* 0x33 */ u8 unk33;
    /* 0x34 */ u8 unk34;
    /* 0x35 */ u8 unk35;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 unk37;
    /* 0x38 */ u8 unk38;
    /* 0x39 */ u8 unk39;
    /* 0x3a */ u8 unk3a;
    /* 0x3b */ u8 unk3b;
    /* 0x3c */ u8 unk3c;
    /* 0x3d */ u8 unk3d;
    /* 0x3e */ u8 unk3e;
    /* 0x3f */ u8 unk3f;
    /* 0x40 */ u8 unk40;
    /* 0x41 */ u8 unk41;
    /* 0x42 */ u8 unk42;
    /* 0x43 */ u8 unk43;
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 unk45;
    /* 0x46 */ u8 unk46;
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 unk48;
    /* 0x49 */ u8 unk49;
    /* 0x4a */ u8 unk4a;
    /* 0x4b */ u8 unk4b;
    /* 0x4c */ u8 unk4c;
    /* 0x4d */ u8 unk4d;
    /* 0x4e */ u8 unk4e;
    /* 0x4f */ u8 unk4f;
    /* 0x50 */ u8 unk50;
    /* 0x51 */ u8 unk51;
    /* 0x52 */ u8 unk52;
    /* 0x53 */ u8 unk53;
    /* 0x54 */ u8 unk54;
    /* 0x55 */ u8 unk55;
    /* 0x56 */ u8 unk56;
    /* 0x57 */ u8 unk57;
    /* 0x58 */ u8 unk58;
    /* 0x59 */ u8 unk59;
    /* 0x5a */ u8 unk5a;
    /* 0x5b */ u8 unk5b;
    /* 0x5c */ u8 unk5c;
    /* 0x5d */ u8 unk5d;
    /* 0x5e */ u8 unk5e;
    /* 0x5f */ u8 unk5f;
    /* 0x60 */ u32 skinDataSrcOffs;
    /* 0x64 */ u32 weightsSrc;
    /* 0x68 */ u8 unk68;
    /* 0x69 */ u8 unk69;
    /* 0x6a */ u8 unk6a;
    /* 0x6b */ u8 unk6b;
    /* 0x6c */ u8 bone0;
    /* 0x6d */ u8 bone1;
    /* 0x6e */ u8 unk6e;
    /* 0x6f */ u8 weightsBlockCount;
    /* 0x70 */ u16 nVtxs;
    /* 0x72 */ u8 skinMeOffs;
    /* 0x73 */ u8 skinSrcBlockCount;
} FineSkinningPiece;

typedef struct {
    /* 0x00 */ u8 usage; //ref count
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u16 flags; //ModelDataFlags2
    /* 0x04 */ short cacheModNo; //model ID, set on load
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ int headerCksum;
    /* 0x0c */ int size; //size of this file
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ float *skeleton;
    /* 0x18 */ float *radi;
    /* 0x1c */ u32 *exT; //extraAmapSize (dlInfoSize?)
    /* 0x20 */ Texture **GCtextures; // -> texture IDs that get turned into pointers
    /* 0x24 */ Vec *normals; //either 1 or 3 vecs per (presumably) face
    /* 0x28 */ S16Vec *vertexPositions;
    /* 0x2c */ S16Vec *vertexNormals;
    /* 0x30 */ u16 *vertexColours;
    /* 0x34 */ S16Vec *vertexTexCoords;
    /* 0x38 */ Shader *shaders;
    /* 0x3c */ Bone *joints;
    /* 0x40 */ void *sphereHits;
    /* 0x44 */ GCPolygon *GCpolygons;
    /* 0x48 */ PolygonGroup *polygonGroups;
    /* 0x4c */ struct Animation **anims;
    /* 0x50 */ HitSpherePos *curHitSpherePos; //=hitSpherePositions[n] for current frame
    /* 0x54 */ s16 *animIds;
    /* 0x58 */ s16 animBank[8];
    /* 0x68 */ u32 animOffset;
    /* 0x6c */ s16 animCacheSize;
    /* 0x6e */ u8 unk6e;
    /* 0x6f */ u8 unk6f;
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 unk71;
    /* 0x72 */ ushort numSkinMtxs;
    /* 0x74 */ u8 unk74;
    /* 0x75 */ u8 unk75;
    /* 0x76 */ u8 unk76;
    /* 0x77 */ u8 unk77;
    /* 0x78 */ u8 unk78;
    /* 0x79 */ u8 unk79;
    /* 0x7a */ u8 unk7a;
    /* 0x7b */ u8 unk7b;
    /* 0x7c */ FineSkinningPiece *posFineSkinningPieces;
    /* 0x80 */ u8 unk80;
    /* 0x81 */ u8 unk81;
    /* 0x82 */ u8 unk82;
    /* 0x83 */ u8 unk83;
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 unk85;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
    /* 0x8a */ u8 unk8a;
    /* 0x8b */ u8 unk8b;
    /* 0x8c */ FineSkinningPiece *posFineSkinningConfig;
    /* 0x90 */ UNKTYPE *skinWeights;
    /* 0x94 */ DisplayList *displayLists;
    /* 0x98 */ BitStream *renderStream;
    /* 0x9c */ u8 unk9c;
    /* 0x9d */ u8 unk9d;
    /* 0x9e */ u8 unk9e;
    /* 0x9f */ u8 unk9f;
    /* 0xa0 */ undefined4 *vertexAnims;
    /* 0xa4 */ undefined2 unka4;
    /* 0xa6 */ u16 shaderFlags; //ModelShaderFlags
    /* 0xa8 */ ushort numPositions;
    /* 0xaa */ s8 numNormals;
    /* 0xab */ s8 numColours;
    /* 0xac */ s8 numTexCoords;
    /* 0xad */ s8 unkad;
    /* 0xae */ s8 unkae;
    /* 0xaf */ s8 unkaf;
    /* 0xb0 */ u16 numAnims;
    /* 0xb2 */ u16 numPolygons;
    /* 0xb4 */ u16 numGroups;
    /* 0xb6 */ u8 numTextures;
    /* 0xb7 */ u8 numJoints;
    /* 0xb8 */ u8 numDisplayLists;
    /* 0xb9 */ u8 numHitSpheres;
    /* 0xba */ u8 numShaders;
    /* 0xbb */ u8 bCopyVtxsToModelInst;
    /* 0xbc */ u8 maxLights;
} Model;

typedef struct { //XXX populate
    /* 0x00 */ s8 usage; //reference count
    /* 0x01 */ u8 flags01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    //...more...
} Animation;

typedef struct {
    /* 0x00 */ undefined4 unk00;
    /* 0x04 */ uint hitSphereDataSize;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0a */ u8 unk0A;
    /* 0x0b */ u8 unk0B;
    /* 0x0c */ int nAnims;
    /* 0x10 */ int unk10;
    /* 0x14 */ uint animCacheSize;
    /* 0x18 */ uint mtxSize;
} AnimUnk;

typedef struct {
    /* 0x00 */ Model *model;
    /* 0x04 */ float hitboxSize04;
    /* 0x08 */ float hitboxSize08;
    /* 0x0c */ float unk0c;
    /* 0x10 */ float unk10;
    /* 0x14 */ float unk14;
    /* 0x18 */ float unk18;
    /* 0x1c */ UNKTYPE *animData[4];
    /* 0x2c */ undefined unk2c;
    /* 0x2d */ undefined unk2d;
    /* 0x2e */ undefined unk2e;
    /* 0x2f */ undefined unk2f;
    /* 0x30 */ int unk30;
    /* 0x34 */ Animation *anim[4];
    /* 0x44 */ ushort iAnim;
    /* 0x46 */ ushort unk46;
    /* 0x48 */ ushort unk48;
    /* 0x4a */ ushort unk4a;
    /* 0x4c */ undefined unk4c;
    /* 0x4d */ undefined unk4d;
    /* 0x4e */ undefined unk4e;
    /* 0x4f */ undefined unk4f;
    /* 0x50 */ undefined unk50;
    /* 0x51 */ undefined unk51;
    /* 0x52 */ undefined unk52;
    /* 0x53 */ undefined unk53;
    /* 0x54 */ undefined unk54;
    /* 0x55 */ undefined unk55;
    /* 0x56 */ undefined unk56;
    /* 0x57 */ undefined unk57;
    /* 0x58 */ short unk58;
    /* 0x5a */ short unk5a;
    /* 0x5c */ short unk5c;
    /* 0x5e */ short unk5e;
    /* 0x60 */ s8 unk60;
    /* 0x61 */ undefined unk61;
    /* 0x62 */ undefined unk62;
    /* 0x63 */ u8 flags63;
    /* 0x64 */ undefined unk64;
    /* 0x65 */ undefined unk65;
    /* 0x66 */ undefined unk66;
    /* 0x67 */ undefined unk67;
} AnimInstance;

#define ANIMMAP_SIZE 0x80
typedef struct {
    u8 animMap[ANIMMAP_SIZE];
    Animation animData[];
} AnimCache;

typedef struct {
    /* 0x00 */ Vec vec;
    /* 0x0c */ s8 unk0c;
    /* 0x0d */ s8 unk0d;
    /* 0x0e */ u8 flags;
} ModelInstanceField20; //size: 0x10

typedef struct {
    Mtx *jMtxs[2];
    S16Vec unk;
} ModelInstanceField54;

typedef struct {
    /* 0x00 */ Model *mod;
    /* 0x04 */ S16Vec *vertexPositions2;
    /* 0x08 */ s8 unk08;
    /* 0x09 */ s8 unk09;
    /* 0x0a */ s8 unk0a;
    /* 0x0b */ s8 unk0b;
    /* 0x0c */ Mtx *jMtxs[2]; //joint matrices
    /* 0x14 */ float **unk14;
    /* 0x18 */ u16 flags; //ModelFlags18 40:shaders loaded
    /* 0x1a */ s8 unk1a;
    /* 0x1b */ s8 unk1b;
    /* 0x1c */ S16Vec *vertexPositions;
    /* 0x20 */ ModelInstanceField20 *unk20;
    /* 0x24 */ AnimInstance *animInstances[2];
    /* 0x2c */ ShaderDef *shaderDefs;
    /* 0x30 */ UNKTYPE *texFuncPtr;
    /* 0x34 */ UNKTYPE *skinVtxs;
    /* 0x38 */ uint unk38;
    /* 0x3c */ int unk3c;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ uint unk44;
    /* 0x48 */ void *unk48;
    /* 0x4c */ Mtx *jMtxs4C;
    /* 0x50 */ s8 unk50;
    /* 0x51 */ s8 unk51;
    /* 0x52 */ s8 unk52;
    /* 0x53 */ s8 unk53;
    /* 0x54 */ ModelInstanceField54 *field54;
} ModelInstance;

#endif //_GFX_MODELS_MODELS_H_
