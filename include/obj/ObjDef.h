#ifndef _OBJ_OBJDEF_H_
#define _OBJ_OBJDEF_H_

#include "obj/ObjDefNo.h"
#include "obj/ObjCats.h"

typedef enum {
	RomListLoadFlag_isLevelObject        = 0x01,
	RomListLoadFlag_isManualLoad         = 0x02,
	RomListLoadFlag_OnlyLoadIfNearPlayer = 0x04,
	RomListLoadFlag_AllocatedByCode      = 0x08,
	RomListLoadFlag_loadForOtherMap      = 0x10,
	RomListLoadFlag_isBlockObject        = 0x20,
} RomListObjLoadFlags;

typedef enum {
    objSetupObjectActual_SkipObjInd = 0x02
} objSetupObjectActual_flags;

typedef enum {
    ObjSpawnFlags_KeepLoaded         = 0x01,
    ObjSpawnFlags_DontUseObjIndexBin = 0x02,
} ObjSpawnFlags;

typedef struct {
    //this is the common header for all ObjDef structs
    /* 0x00 */ s16 objType; //ObjDefEnum (ObjDefNo_*)
    /* 0x02 */ s8 allocatedSize; //size of this entry in words
    /* 0x03 */ u8 mapStates1; //whether to NOT load in states 1-8
    /* 0x04 */ u8 loadFlags; //RomListObjLoadFlags
    /* 0x05 */ u8 mapStates2; //whether to NOT load in states 15-9 (low bit unused?)
    /* 0x06 */ u8 bound; //load if in range (bound<<3) of player
    /* 0x07 */ u8 cullDist;
    /* 0x08 */ Vec pos;
    /* 0x14 */ s32 id; //unique ID
} ObjDef;

//XXX move
typedef struct { //object with ID 9
    /* 0x00 */ ObjDef odef;
    /* 0x18 */ u8 size[2]; //x, y
    /* 0x1A */ u8 scale[3]; //x, y, z
    /* 0x1D */ u8 iColor;
    //probably more...
} ObjDef_Id9;

#endif //_OBJ_OBJDEF_H_
