#ifndef _OBJ_OBJINSTANCE_H_
#define _OBJ_OBJINSTANCE_H_
#include "gfx/models/models.h"

#define MAX_OBJECTS 350

typedef struct {
    /* 0x0 */ S16Vec rotation;
    /* 0x6 */ s16 flags; //ObjInstance_Flags06
    /* 0x8 */ float scale;
    /* 0xc */ Vec pos;
} ObjPos;

struct ObjInstance;

#define ObjInstance_FlagsB0_WhichParentHitbox 7
#define ObjInstance_FlagsB0_ScalingFlag08 8
#define ObjInstance_FlagsB0_IsInGlobalObjList 16
#define ObjInstance_FlagsB0_FallThruFloor 32
#define ObjInstance_FlagsB0_IsFreed 64
#define ObjInstance_FlagsB0_LockAnimsAndControls 128
#define ObjInstance_FlagsB0_Invisible 1024
#define ObjInstance_FlagsB0_IsRendered 2048
#define ObjInstance_FlagsB0_SeqActive 4096
#define ObjInstance_FlagsB0_DontMove 8192
#define ObjInstance_FlagsB0_DontUseRenderCallback 16384
#define ObjInstance_FlagsB0_DontUpdate 32768

#define ObjFileStructFlags44_HaveModels	1
#define ObjFileStructFlags44_DifferentLightColor	16
#define ObjFileStructFlags44_ModelRelated	32
#define ObjFileStructFlags44_IsWorldObj	64
#define ObjFileStructFlags44_EnableCulling	1024
#define ObjFileStructFlags44_UseDifferentModelLoading	2048
#define ObjFileStructFlags44_LockAnimsAndControls	262144
#define ObjFileStructFlags44_FixedDepth	524288	//o->data->depth is the Z depth for sorting
#define ObjFileStructFlags44_OpacityDrawGroupFlag_0x100000	1048576	//affects whether opacity is used to calc draw group
#define ObjFileStructFlags44_KeepHitboxWhenInvisible	2097152
#define ObjFileStructFlags44_HasEvent	4194304
#define ObjFileStructFlags44_DidLoadModels	8388608

#define ObjData_Flag_FixedDepth 0x80000

#define RomLockData_Flag_Rotate 0x10

typedef int (*ObjSeqFunc)(struct ObjInstance *this,
    struct ObjInstance *that, void *state);

typedef struct {
    /* 0x00 */ short unk00;
    /* 0x02 */ short unk02;
    /* 0x04 */ short unk04;
    /* 0x06 */ S16Vec unk08;
    /* 0x0c */ u8 unk0C;
    /* 0x0d */ u8 combatCamDist; //deactivate combat mode when further away than (this << 2)
    /* 0x0e */ u8 maxDist;
    /* 0x0f */ u8 unk0F;
    /* 0x10 */ u8 flags; //RomLockData_Flag_*
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
} RomLockData;

typedef struct {
    /* 0x00 */ u8 fieldC;
    /* 0x01 */ u8 combatCamDist;
    /* 0x02 */ u8 maxDist;
    /* 0x03 */ u8 fieldF;
    /* 0x04 */ u8 flags;
} RamLockData;

typedef struct {
    int TODO;
} ModLine;

typedef struct {
    int TODO;
} ObjSeqCmd;

typedef struct {
    int TODO;
} ObjWeaponData;

typedef struct {
    int TODO;
} AttachPoint;

typedef struct {
    /* 0x00 */ S16Vec unk00;
    /* 0x06 */ s32 unk06;
    /* 0x08 */ s32 unk08;
    /* 0x0a */ s32 unk0a;
    /* 0x0c */ s32 unk0c;
    /* 0x0e */ s32 unk0e;
    /* 0x10 */ s32 unk10;
} Joint;

typedef uint ObjFileStructFlags44;
typedef s16 ObjFileStruct_ShadowType;
typedef u16 HitboxFlags60;
typedef u16 HitboxFlags62;

typedef struct {
    /* 0x00 */ float unk00; //copied to shadow field 0
    /* 0x04 */ float scale;
    /* 0x08 */ u32 *pModelList; //-> list of model IDs
    /* 0x0c */ void *textures;
    /* 0x10 */ void *jointRelated10;
    /* 0x14 */ void *unk14;
    /* 0x18 */ ObjSeqCmd *offset_0x18; //[OPTIONAL] a file containing functions
    /* 0x1c */ u16 *pSeq; //[OPTIONAL] -> seq IDs
    /* 0x20 */ s16 *pEvent; //[OPTIONAL] -> event IDs, ends with -1
        //triples of [animId, offset, size, animId, offset...]
        //but is not a struct
    /* 0x24 */ void *pHits; //[OPTIONAL]
    /* 0x28 */ ObjWeaponData *pWeaponDa; //[OPTIONAL]
    /* 0x2c */ AttachPoint *pAttachPoints;
    /* 0x30 */ ModLine *pModLines; //ignored in file (zeroed on load)
    /* 0x34 */ void *wObjList; //ignored in file (zeroed on load)
    /* 0x38 */ void *nextIntersectPoint;
    /* 0x3c */ void *nextIntersectLine;
    /* 0x40 */ RomLockData *lockdata; //A-button interaction
    /* 0x44 */ ObjFileStructFlags44 flags;
    /* 0x48 */ ObjFileStruct_ShadowType shadowType;
    /* 0x4a */ s16 shadowTexture;
    /* 0x4c */ s8 unk4c;
    /* 0x4d */ s8 unk4d;
    /* 0x4e */ HitboxFlags60 hitbox_flags60;
    /* 0x50 */ s8 unk50;
    /* 0x51 */ s8 unk51;
    /* 0x52 */ s8 unk52;
    /* 0x53 */ s8 unk53;
    /* 0x54 */ s8 unk54;
    /* 0x55 */ s8 unk55;
    /* 0x56 */ s8 numPlayerObjs; //if > 0, objAddObjectType(obj, 8)
    /* 0x57 */ u8 unk57; //never read?
    /* 0x58 */ u16 dll_id;
    /* 0x5a */ u16 objId;
    /* 0x5c */ s8 modLinesSize; //ignored in file
    /* 0x5d */ s8 nModels;
    /* 0x5e */ u8 numSeqs;
    /* 0x5f */ char name[15];
    /* 0x6e */ s8 unk6e;
    /* 0x6f */ s8 unk6f;
    /* 0x70 */ s8 noplacements; //related to hitbox (height?)
    /* 0x71 */ u8 nTextures;
    /* 0x72 */ u8 nJoints;
    /* 0x73 */ s8 stateVar73; //1=translucent; 3=invincible - not flags
    /* 0x74 */ bool bDisableHits;
    /* 0x75 */ s8 unk75;
    /* 0x76 */ s16 modLineCount;
    /* 0x78 */ s16 modLineNo;
    /* 0x7a */ s16 nSeqs;
    /* 0x7c */ s8 unk7c;
    /* 0x7d */ s8 unk7d;
    /* 0x7e */ s8 unk7e;
    /* 0x7f */ s8 unk7f;
    /* 0x80 */ s8 unk80;
    /* 0x81 */ s8 unk81;
    /* 0x82 */ s8 unk82;
    /* 0x83 */ s8 cend; //relates to lighting
    /* 0x84 */ s8 csize;
    /* 0x85 */ s8 ambient;
    /* 0x86 */ s8 intensity;
    /* 0x87 */ s8 lightFlags;
    /* 0x88 */ float lagVar88; //causes lag at ~65536.0; GPU hang at much more; related to shadow; maybe causing excessive map loads?
    /* 0x8c */ s8 nLights;
    /* 0x8d */ s8 lightIdx;
    /* 0x8e */ s8 unk8e; //related to textures; 1=dark, 2=default, 3+=corrupt, 77=crash, 0=normal
    /* 0x8f */ u8 maybeNumHits; //related to hitbox
    /* 0x90 */ HitboxFlags62 hitbox_flagsB6; // < 0xE = invincible
    /* 0x92 */ s8 unk92;
    /* 0x93 */ u8 flags93;
    /* 0x94 */ s8 unk94;
    /* 0x95 */ s8 unk95;
    /* 0x96 */ s8 unk96;
    /* 0x97 */ s8 unk97;
    /* 0x98 */ s8 unk98;
    /* 0x99 */ s8 unk99;
    /* 0x9a */ s8 unk9a;
    /* 0x9b */ u8 numLockData;
    /* 0x9c */ u8 unk9c;
    /* 0x9d */ u8 fixedDepth; //mult by 100, used if flags & FIxedDepth
    /* 0x9e */ s8 unk9e;
    /* 0x9f */ s8 unk9f;
    /* 0xa0 */ s16 unka0;
} ObjData;

typedef struct {
    /* 0x00 */ short animId; //-1 = end of list
    /* 0x02 */ short offset; //into OBJHITS.bin
    /* 0x04 */ short length;
} ObjHitsEntry_final;

typedef struct {
    u32 frame;
} ObjHitsEntry;

#define MAX_HITS 3
typedef struct {
    /* 0x00 */ struct ObjInstance *curTouchedObject;
    /* 0x04 */ short objHitsSize; //this >> 2 = #ptrs at field 8
    /* 0x06 */ short maxHitsSize;
    /* 0x08 */ ObjHitsEntry *objHits; //from OBJHITS.bin
    //s32 objHits;
    /* 0x0c */ float sizeXY_0C;
    /* 0x10 */ Vec pos;
    /* 0x1c */ Vec prevPos;
    /* 0x28 */ float size;
    /* 0x2c */ float cullDist;
    /* 0x30 */ float cullDist2;
    /* 0x34 */ float minSizeY;
    /* 0x38 */ float sizeY;
    /* 0x3c */ s8 unk3c;
    /* 0x3d */ s8 unk3d;
    /* 0x3e */ s8 unk3e;
    /* 0x3f */ s8 unk3f;
    /* 0x40 */ int frame;
    /* 0x44 */ int prevFrame;
    /* 0x48 */ undefined4 unk48;
    /* 0x4c */ s32 unk4c;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ ushort unk52;
    /* 0x54 */ short unk54;
    /* 0x56 */ short unk56;
    /* 0x58 */ u16 flags; //800:no Y rotation; 1000:no Z rotation
    /* 0x5a */ u8 flags5A; //(final at 0x62) 20:have skeleton
    /* 0x5b */ s8 unk5b;
    /* 0x5c */ s8 sizeX1;
    /* 0x5d */ s8 unk5d;
    /* 0x5e */ s8 unk5e;
    /* 0x5f */ s8 unk5f;
    /* 0x60 */ u16 flags_0x60; //HitboxFlags60
    /* 0x62 */ u8 nSpheres; //HitboxFlags62?
    /* 0x63 */ s8 unk63;
    /* 0x64 */ short sizeZ;
    /* 0x66 */ short sizeZ1;
    /* 0x68 */ short sizeZ2;
    /* 0x6a */ s8 unk6a;
    /* 0x6b */ s8 unk6b;
    /* 0x6c */ s8 damage;
    /* 0x6d */ s8 unk6d;
    /* 0x6e */ s8 unk6e;
    /* 0x6f */ s8 unk6f;
    /* 0x70 */ s8 unk70;
    /* 0x71 */ s8 nHits; //max 3; only used for damage?
    /* 0x72 */ s8 sphereIdxs[MAX_HITS];
    /* 0x75 */ s8 objField6C[MAX_HITS];
    /* 0x78 */ s8 recordedDamage[MAX_HITS];
    /* 0x7b */ s8 unk7b;
    /* 0x7c */ struct ObjInstance *objs[MAX_HITS];
    /* 0x88 */ float objX[MAX_HITS];
    /* 0x94 */ s8 unk94;
    /* 0x95 */ s8 unk95;
    /* 0x96 */ s8 unk96;
    /* 0x97 */ s8 unk97;
    /* 0x98 */ s8 unk98;
    /* 0x99 */ s8 unk99;
    /* 0x9a */ s8 unk9a;
    /* 0x9b */ s8 unk9b;
    /* 0x9c */ s8 unk9c;
    /* 0x9d */ s8 unk9d;
    /* 0x9e */ s8 disable2;
    /* 0x9f */ s8 state2;
    /* 0xa0 */ s8 objZ;
    /* 0xa1 */ s8 unka1;
    /* 0xa2 */ s8 unka2;
    /* 0xa3 */ s8 unka3;
    /* 0xa4 */ s8 unka4;
    /* 0xa5 */ s8 unka5;
    /* 0xa6 */ s8 unka6;
    /* 0xa7 */ s8 unka7;
    /* 0xa8 */ s8 unka8;
    /* 0xa9 */ s8 unka9;
    /* 0xaa */ s8 unkaa;
    /* 0xab */ s8 unkab;
    /* 0xac */ s8 typeOfPolyHit; //PolygonType
    /* 0xad */ s8 unkad;
    /* 0xae */ s8 disable;
    /* 0xaf */ s8 state;
    /* 0xb0 */ s8 unkb0;
    /* 0xb1 */ s8 unkb1;
    /* 0xb2 */ short unkb2;
    /* 0xb4 */ s8 unkb4;
    /* 0xb5 */ s8 unkb5;
    /* 0xb6 */ u8 flagsB6; //HitboxFlags62
} HitState;

typedef struct {
    int TODO;
} ObjInstanceField58;

typedef struct {
    u8 unk[0x50];
} ObjEventData2;

typedef struct {
    int size;
    ObjEventData2 *data;
} ObjEventData;

typedef struct {
    /* 0x00 */ float unk00; //copied from ObjectFileStruct field 0
    /* 0x04 */ Texture *texture;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ int unk0c;
    /* 0x10 */ int unk10;
    /* 0x14 */ Vec unk14; //size?
    /* 0x20 */ Vec pos;
    /* 0x2c */ float unk2c;
    /* 0x30 */ uint flags; //8=initialized?
    /* 0x34 */ u8 unk34;
    /* 0x35 */ u8 unk35;
    /* 0x36 */ short opacityChange;
    /* 0x38 */ u32 color; //Color4b
    /* 0x3c */ u8 unk3c;
    /* 0x3d */ u8 unk3d;
    /* 0x3e */ u8 unk3e;
    /* 0x3f */ u8 unk3f;
    /* 0x40 */ u8 opacity;
} Shadow;

typedef struct {
    int TODO;
} astruct_53;

typedef struct ObjInstance {
    /* 0x00 */ ObjPos pos;
    /* 0x18 */ Vec prevPos; //maybe "viewPos"
    /* 0x24 */ Vec vel;
    /* 0x30 */ struct ObjInstance *heldBy; //can be null
    /* 0x34 */ u8 map; //MapId8 related to children and/or player objects
    /* 0x35 */ u8 mtxIdx;
    /* 0x36 */ u8 newOpacity;
    /* 0x37 */ u8 opacity; //is set to newOpacity each frame
    /* 0x38 */ struct ObjInstance *next; //list is not necessarily in order
    /* 0x3c */ float camDistVar3C; //same value as 0x40
    /* 0x40 */ float camDistVar40; //2040=100% opacity, 128=~50% - camera distance?
    /* 0x44 */ s16 objId; //same for multiple objs
    /* 0x46 */ s16 romdefno; //ObjDefEnum
    /* 0x48 */ s16 realType;
    /* 0x4a */ s16 _4A;
    /* 0x4c */ ObjDef *def;
    /* 0x50 */ ObjData *data;
    /* 0x54 */ HitState *hits;
    /* 0x58 */ ObjInstanceField58 *_58;
    /* 0x5c */ Model *models;
    /* 0x60 */ ObjEventData *pEventName;
    /* 0x64 */ Shadow *shadow;
    /* 0x68 */ LoadedDLL *dll; //can be NULL
    /* 0x6c */ Joint *joints;
    /* 0x70 */ astruct_53 **pTextures; //count = file->count59
    /* 0x74 */ RomLockData *romLockdata;
    /* 0x78 */ RamLockData *lockdata;
    /* 0x7c */ ModelInstance **modelInstances; //one per model
    /* 0x80 */ Vec oldPos;
    /* 0x8c */ Vec pos_0x8c;
    /* 0x98 */ float animTimer; //controls idle animation
    /* 0x9c */ float frame;
    /* 0xa0 */ s16 animId; //which animation is playing
    /* 0xa2 */ s16 animVal_a2;
    /* 0xa4 */ float depth; //for render sorting
    /* 0xa8 */ float cullDistance; //affects brightness and opacity; multiplied by scale; fuzz?
    /* 0xac */ u8 mapId; //MapId8 crashes if < 0x80; passed to loadCharacter but not used?
    /* 0xad */ s8 curModel; //which model index to use
    /* 0xae */ s8 priority; //0x50 for most
    /* 0xaf */ u8 flags_0xaf; //ObjInstance_FlagsAF 28=don't render something (no models?)
    /* 0xb0 */ u16 flags_0xb0; //ObjInstance_FlagsB0
    /* 0xb2 */ s16 romDefNo;
    /* 0xb4 */ s16 curSeq;
    /* 0xb6 */ s8 _B6; //padding?
    /* 0xb7 */ s8 _B7;
    /* 0xb8 */ void *state; //type depends on object
    /* 0xbc */ ObjSeqFunc *seqFn;
    /* 0xc0 */ struct ObjInstance *pObj_0xc0; //related to being held
    /* 0xc4 */ struct ObjInstance *parent;
    /* 0xc8 */ struct ObjInstance *child[3];
    /* 0xd4 */ s8 *_D4;
    /* 0xd8 */ s16 _D8;
    /* 0xda */ s8 _DA;
    /* 0xdb */ s8 _DB;
    /* 0xdc */ void *msgQueue;
    /* 0xe0 */ s8 _E0;
    /* 0xe1 */ s8 _E1;
    /* 0xe2 */ s8 _E2;
    /* 0xe3 */ u8 flags_e3;
    /* 0xe4 */ u8 _E4; //related to field_0x74
    /* 0xe5 */ u8 stateFlags; //ObjStateFlags
    /* 0xe6 */ s16 _E6;
    /* 0xe8 */ s8 hintTextIdx;
    /* 0xe9 */ s8 nTouchCallbacks;
    /* 0xea */ u8 lockedFreeTick;
    /* 0xeb */ u8 nChildren;
    /* 0xec */ u32 colorEC;
    /* 0xf0 */ s8 _F0;
    /* 0xf1 */ u8 brightness;
    /* 0xf2 */ u8 colorIdx;
    /* 0xf3 */ s8 _F3;
    /* 0xf4 */ s32 _F4;
    /* 0xf8 */ u32 flags_0xf8; //prevents picking up - also an ObjDefEnum
} ObjInstance;

typedef struct {
    short usage;
    short objSize;
    ObjInstance *obj;
} ObjListStruct;

#endif //_OBJ_OBJINSTANCE_H_
