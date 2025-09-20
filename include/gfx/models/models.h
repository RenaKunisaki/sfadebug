#ifndef _GFX_MODELS_MODELS_H_
#define _GFX_MODELS_MODELS_H_
#include "dolphin/mtx.h"
#include "gfx/textures.h"
#include "gfx/displaylist.h"
#include "gfx/models/skeleton.h"
#include "gfx/models/bitstream.h"
#include "gfx/models/hit.h"
#include "gfx/models/shaders.h"
#include "gfx/models/animation.h"
#include "sys/SparseArray.h"
#include "types.h"

typedef u32 ModelFlags_loadCharacter;

typedef enum {
    ObjShadowType_None,
    ObjShadowType_BigBoxShadow,
    ObjShadowType_GeomShadow,
    ObjShadowType_Textured,
    ObjShadowType_BlueGlowingRect,
} ObjShadowType;

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
    ModelFlags18_UseOtherMtxs     =  1, //which index into jMtxs to use for double buffering
    ModelFlags18_UseOtherVtxs     =  2, //which vtxs
    ModelFlags18_UseOtherHitboxes =  4, //which hit spheres
    ModelFlags18_MtxsLoaded       =  8,
    ModelFlags18_ShadersLoaded    = 64,
} ModelFlags18;

typedef enum {
    CreateModelInstanceFlags_DoubleBufferAnims = 0x0080,
    CreateModelInstanceFlags_TexturedShadow    = 0x8000,
} CreateModelInstanceFlags;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 unk;
} VertexPosition;

typedef struct {
    u8 unknown[8];
    //might just be VertexPosition
} GCPolygon;

typedef struct Model {
    /* 0x00 */ u8 usage; //ref count
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u16 flags; //ModelDataFlags2
    /* 0x04 */ ushort cacheModNo; //model ID, set on load
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
    /* 0x1c */ float *exT; //extraAmapSize (dlInfoSize?)
    /* 0x20 */ Texture **GCtextures; // -> texture IDs that get turned into pointers
    /* 0x24 */ u8 normalFlags; //ModelNormalFlags
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 unk27;
    /* 0x28 */ S16Vec *vertexPositions;
    /* 0x2c */ S16Vec *vertexNormals;
    /* 0x30 */ u16 *vertexColours;
    /* 0x34 */ S16Vec *vertexTexCoords;
    /* 0x38 */ Shader *shaders;
    /* 0x3c */ Bone *joints;
    /* 0x40 */ HitSphere *sphereHits;
    /* 0x44 */ GCPolygon *GCpolygons;
    /* 0x48 */ PolygonGroup *polygonGroups;
    /* 0x4c */ struct Animation **anims;
    /* 0x50 */ //HitSpherePos *curHitSpherePos; //=hitSpherePositions[n] for current frame
    //The kiosk AMAP.BIN file looks like
    //it's just u8 unk[0x28]
    //but this seems to be something else,
    //maybe not AMAP.BIN at all.
    //see setupAnimInstance which allocates
    //either 0x80 or (numJoints << 7) bytes.
    /* 0x50 */ s8 **amap; //related to joint anims
    /* 0x54 */ s16 *animIds;
    /* 0x58 */ s16 animBank[8];
    /* 0x68 */ u32 animOffset;
    /* 0x6c */ s16 animCacheSize;
    /* 0x6e */ u8 unk6e;
    /* 0x6f */ u8 unk6f;
    /* 0x70 */ FineSkinningConfig skin;
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
    /* 0x8c */ FineSkinningPiece *skin2Matrices; //aka posFineSkinningConfig; //aka skin2Matrices
    /* 0x90 */ UNKTYPE *skinWeights;
    /* 0x94 */ DisplayList *displayLists;
    /* 0x98 */ BitStream *renderStream;
    /* 0x9c */ u16 renderStreamLen;
    /* 0x9e */ u8 unk9e;
    /* 0x9f */ u8 unk9f;
    /* 0xa0 */ UNKTYPE **vertexAnims; //likely points to some struct, using UNKTYPE** to satisfy checks for now
    /* 0xa4 */ u16 unka4;
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

typedef struct {
    /* 0x00 */ float pos;
    /* 0x04 */ float prevPos;
    /* 0x08 */ float speed; //guessed
    /* 0x0c */ s8 animsIdx1;
    /* 0x0d */ s8 animsIdx2;
    /* 0x0e */ u8 flags;
} ModelInstanceField20; //size: 0x10
#define ModelInstanceField20_MAX_NUM 3 //most instances of this a ModelInstance can have

//this struct is actually just what was being
//stored after the ModelInstance.
typedef struct {
    Mtx44 *jMtxs[2];
    VertexPosition unk;
} ModelInstanceField54;

typedef void(*TexFuncPtr)(struct ObjInstance *obj, struct ModelInstance *mInst, int shaderNum);

typedef struct {
    S16Vec pos[4]; //vertices
    s8 state; //0:not calculated, 1:OK, -1:invalid
    s8 unk19; //padding?
} TexturedShadow;

typedef struct {
    /* 0x00 */ Model *mod;
    /* 0x04 */ S16Vec *vertexPositions2;
    /* 0x08 */ s32 unk08; //vertexPositions2[1]?
    /* 0x0c */ Mtx44 *jMtxs[2]; //joint matrices
        //obj->frames->jMtxs[(char)obj->modelno + -3]
        //is actually:
        //obj->frames[obj->modelno]
    /* 0x14 */ ModelSkeletonStruct *skeleton;
    /* 0x18 */ u16 flags; //ModelFlags18
    /* 0x1a */ s8 unk1a;
    /* 0x1b */ s8 unk1b;
    /* 0x1c */ S16Vec *vertexPositions;
    /* 0x20 */ ModelInstanceField20 *unk20; //-> ModelInstanceField20[ModelInstanceField20_MAX_NUM]
    /* 0x24 */ AnimInstance *animInstances[2]; //only one in final?
    /* 0x2c */ ShaderDef *shaderDefs;
    /* 0x30 */ TexFuncPtr texFuncPtr;
    /* 0x34 */ VertexPosition **skinVtxs;
    /* 0x38 */ RamHitSphere *hitSpheres[2];
    /* 0x40 */ RamHitSphere *activeHitSphere;
    /* 0x44 */ TexturedShadow *shadow;
    /* 0x48 */ void *unk48;
    /* 0x4c */ Mtx44 *jMtxs4C;
    /* 0x50 */ s8 bUseVertexPositions1C;
    /* 0x51 */ s8 unk51;
    /* 0x52 */ s8 unk52;
    /* 0x53 */ s8 unk53;
} ModelInstance;

#endif //_GFX_MODELS_MODELS_H_
