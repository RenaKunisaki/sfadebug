#ifndef _OBJ_CURVE_H_
#define _OBJ_CURVE_H_

#include "../types.h"
#include "obj/ObjDef.h"

typedef struct {
    /* 0x0 */ s16 objDefEnum; //ObjDefEnum
    /* 0x2 */ s8 unk02;
    /* 0x3 */ s8 unk03;
} RomCurveParamsUnk;

typedef struct {
    /* 0x0 */ s16 bit0; //GameBit16
    /* 0x2 */ s16 bit2; //GameBit16
} RomCurveParams24;

typedef union {
   RomCurveParamsUnk unk;
   RomCurveParams24 type24;
} ObjDef_RomCurve_Params;

typedef struct {
    /* 0x00 */ ObjDef def;
    /* 0x18 */ s8 action;
    /* 0x19 */ s8 type;
    /* 0x1a */ s8 unk1a;
    /* 0x1b */ u8 flags; //1:no Prev; 2: no Next; 4: no id24; 8: no id28
    /* 0x1c */ int idPrev;
    /* 0x20 */ int idNext;
    /* 0x24 */ int id24;
    /* 0x28 */ int id28;
    /* 0x2c */ s8 rotZ;
    /* 0x2d */ s8 rotY;
    /* 0x2e */ s8 rotX;
    /* 0x2f */ s8 unk2f;
    /* 0x30 */ ObjDef_RomCurve_Params params;
} ObjDef_RomCurve;

typedef struct {
    /* 0x00 */ float unk00;
    /* 0x04 */ float unk04;
    /* 0x08 */ float unk08;
    /* 0x0c */ float unk0c;
    /* 0x10 */ int unk10;
    /* 0x14 */ float maybeLength;
    /* 0x18 */ float unk18[20];
    /* 0x68 */ float unk68;
    /* 0x6c */ float unk6c;
    /* 0x70 */ float unk70;
    /* 0x74 */ float unk74;
    /* 0x78 */ float unk78;
    /* 0x7c */ float unk7c;
    /* 0x80 */ float unk80;
    /* 0x84 */ int unk84;
    /* 0x88 */ int unk88;
    /* 0x8c */ int unk8c;
    /* 0x90 */ int nControlPoints;
    /* 0x94 */ UNKTYPE *func;
    /* 0x98 */ UNKTYPE *callback98;
} Curve;

#endif //_OBJ_CURVE_H_
