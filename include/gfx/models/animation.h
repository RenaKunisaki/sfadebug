#ifndef _GFX_MODELS_ANIMATION_H_
#define _GFX_MODELS_ANIMATION_H_

#include "gfx/models/skeleton.h"
#include "types.h"

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
    /* 0x60 */ u32 vertSrc;
    /* 0x64 */ UNKTYPE *weightsSrc;
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
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 numPieces;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u8 posNrmShift; //aka quantizeScale
    /* 0x07 */ u8 unk07;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0a */ u8 unk0a;
    /* 0x0b */ u8 unk0b;
    /* 0x0c */ FineSkinningPiece *sk2ListArray;
} FineSkinningConfig;

typedef struct {
    /* 0x00 */ u8 totalBones;
    /* 0x01 */ u8 totalKeyframes;
    /* 0x02 */ u8 keyframeStride;
    /* 0x03 */ u8 unk_0x9;
    /** Encodes info about each bone component (SRT):
    base value throughout animation,
    the number of bits used in adding a delta to the
    base per keyframe,
    and whether TS components are also animated (bones
    always have rotation component) */
    /* 0x04 */ u16 animatedComponents; //array
} AnimationHeader;

typedef struct {
    /* 0x00 */ s8 usage; //reference count
    /* 0x01 */ u8 flags01;
    /* 0x02 */ s16 keyframeOffset;
    /** keyframes for the root translation of the model
(used to map the anim playback progress based on character speed, e.g. during walk cycles) */
    /* 0x04 */ s16 rootMotionOffset;
    /* 0x06 */ AnimationHeader animHeader;
    //size is likely 0xC
} Animation;

#define ANIMMAP_SIZE 0x80
typedef struct {
    u8 animMap[ANIMMAP_SIZE]; //at index 6 is (sometimes?) a Bone
    Animation animData[0]; //unknown size
} AnimCache;

typedef struct {
    /* 0x00 */ undefined4 unk00; //model->numPositions * 2 * 6 + 0x20
    /* 0x04 */ int hitSphereDataSize;
    /* 0x08 */ int unk08;
    /* 0x0c */ int nAnims;
    /* 0x10 */ int size10; //sizeof(AnimInstance), sometimes + mtxs
    /* 0x14 */ int animCacheSize;
    /* 0x18 */ int mtxSize;
} AnimUnk;

#define AnimInstance_MAX_ANIMS 4
#define AnimInstance_MAX_JOINTS 4
typedef struct {
    /* 0x00 */ struct Model *model;
    /* 0x04 */ float hitboxSize[3][2]; //related to joints, might not be size
    /* 0x1c */ AnimCache *cache0[2];
    /* 0x24 */ AnimCache *cache1[2];
    /* 0x2c */ UNKTYPE *unk2c;
    /* 0x30 */ int unk30;
    /* 0x34 */ Bone *joints[AnimInstance_MAX_JOINTS];
    /* 0x44 */ ushort iJoint[AnimInstance_MAX_JOINTS];
    /* 0x4c */ ushort sizeVar4c[AnimInstance_MAX_JOINTS];
    /* 0x54 */ undefined unk54;
    /* 0x55 */ undefined unk55;
    /* 0x56 */ undefined unk56;
    /* 0x57 */ undefined unk57;
    /* 0x58 */ ushort unk58;
    /* 0x5a */ ushort unk5a;
    /* 0x5c */ ushort unk5c;
    /* 0x5e */ ushort unk5e;
    /* 0x60 */ s8 unk60[2]; //related to joints
    /* 0x62 */ undefined unk62; //possibly part of unk60
    /* 0x63 */ s8 flags63;
    /* 0x64 */ undefined unk64;
    /* 0x65 */ undefined unk65;
    /* 0x66 */ undefined unk66;
    /* 0x67 */ undefined unk67;
} AnimInstance;

#endif //_GFX_MODELS_ANIMATION_H_
