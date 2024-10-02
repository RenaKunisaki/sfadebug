typedef struct {
    /* 0x0 */ S16Vec rotation;
    /* 0x6 */ u16 flags; //ObjInstance_Flags06
    /* 0x8 */ float	scale;
    /* 0xc */ Vec pos;
} ObjPos;

struct ObjInstance;

#define ObjInstance_FlagsB0_WhichParentHitbox	7
#define ObjInstance_FlagsB0_ScalingFlag08	8
#define ObjInstance_FlagsB0_IsInGlobalObjList	16
#define ObjInstance_FlagsB0_FallThruFloor	32
#define ObjInstance_FlagsB0_IsFreed	64
#define ObjInstance_FlagsB0_LockAnimsAndControls	128
#define ObjInstance_FlagsB0_Invisible	1024
#define ObjInstance_FlagsB0_IsRendered	2048
#define ObjInstance_FlagsB0_SeqActive	4096
#define ObjInstance_FlagsB0_DontMove	8192
#define ObjInstance_FlagsB0_DontUseRenderCallback	16384
#define ObjInstance_FlagsB0_DontUpdate	32768

typedef int (*ObjSeqFunc)(struct ObjInstance *this,
    struct ObjInstance *that, void *state);

typedef struct {
    int TODO;
} Model;

typedef struct {
    int TODO;
} ObjDef;

typedef struct {
    int TODO;
} ObjData;

typedef struct {
    int TODO;
} HitState;

typedef struct {
    int TODO;
} ObjInstanceField58;

typedef struct {
    int TODO;
} ObjEventData;

typedef struct {
    int TODO;
} Shadow;

typedef struct {
    int TODO;
} astruct_53;

typedef struct {
    int TODO;
} ModelInstance;

typedef struct {
    /* 0x0 */ ObjPos pos;
    /* 0x18 */ Vec prevPos; //maybe "viewPos"
    /* 0x24 */ Vec vel;
    /* 0x30 */ struct ObjInstance *pMatrix; //can be null
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
    /* 0x54 */ HitState *hitstate;
    /* 0x58 */ ObjInstanceField58 *_58;
    /* 0x5c */ Model *models;
    /* 0x60 */ ObjEventData *pEventName;
    /* 0x64 */ Shadow *shadow;
    /* 0x68 */ DLL *dll; //can be NULL; XXX is it LoadedDLL?
    /* 0x6c */ UNKTYPE *pVecs;
    /* 0x70 */ astruct_53 **pTextures; //count = file->count59
    /* 0x74 */ Vec *_74; //maybe matrix*; count = file->count72
    /* 0x78 */ UNKTYPE *_78;
    /* 0x7c */ ModelInstance *modelInstances; //one per model
    /* 0x80 */ Vec oldPos;
    /* 0x8c */ Vec pos_0x8c;
    /* 0x98 */ float animTimer; //controls idle animation
    /* 0x9c */ float animVal_9c;
    /* 0xa0 */ s16 animId; //which animation is playing
    /* 0xa2 */ s16 animVal_a2;
    /* 0xa4 */ float depth; //for render sorting
    /* 0xa8 */ float cullDistance; //affects brightness and opacity; multiplied by scale; fuzz?
    /* 0xac */ u8 mapId; //MapId8 crashes if < 0x80; passed to loadCharacter but not used?
    /* 0xad */ s8 curModel; //which model index to use
    /* 0xae */ u8 priority; //0x50 for most
    /* 0xaf */ u8 flags_0xaf; //ObjInstance_FlagsAF 28=don't render something (no models?)
    /* 0xb0 */ u16 flags_0xb0; //ObjInstance_FlagsB0
    /* 0xb2 */ s16 romDefNo;
    /* 0xb4 */ s16 curSeq;
    /* 0xb6 */ s8 _B6; //padding?
    /* 0xb7 */ s8 _B7;
    /* 0xb8 */ void	*state; //type depends on object
    /* 0xbc */ ObjSeqFunc *seqFn;
    /* 0xc0 */ struct ObjInstance *pObj_0xc0;
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
    /* 0xea */ s8 lockedFreeTick;
    /* 0xeb */ u8 nChildren;
    /* 0xec */ u32 colorEC;
    /* 0xf0 */ s8 _F0;
    /* 0xf1 */ u8 brightness;
    /* 0xf2 */ u8 colorIdx;
    /* 0xf3 */ s8 _F3;
    /* 0xf4 */ s32 _F4;
    /* 0xf8 */ u32 flags_0xf8; //prevents picking up - also an ObjDefEnum
    /* 0xfc */ Vec oldVel;
    /* 0x108 */ float f128; //maybe start of another object/subclass
} ObjInstance;
