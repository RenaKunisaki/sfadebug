#ifndef _SYS_DLL_H_
#define _SYS_DLL_H_
//XXX file here is DLL*
#include "obj/ObjInstance.h"
typedef int (*DLL_func)(void *file);

//this is a bit gross. eventually it should be replaced
//with some kind of build system that puts each DLL
//in its own file.
typedef struct {
    /* 0x0 */ union {
        //possibly the onLoad signature is only newer game versions?
        int (*onLoad)(void *thisdll);
        void (*func0)(void);
    } _0;
    /* 0x4 */ union {
        //many of the following need their args and return types
        //filled in, and may have more functions.

        int (*onUnload)(void *thisdll);
        void (*func1)(void);
        void(*Object_onLoad)(struct ObjInstance *object, void *param2, void *param3);
        struct {
            void (*func03)(struct ObjInstance *obj,float x,float y,float z);
            void (*func04)(int);
            void (*func05)();
            void (*func06)();
            void (*func07)();
            void (*func08)();
            void (*func09)(int param1,s8 param2,s8 param3,uint len,ObjDef *odef,int param6,u8 param7);
        } camcontrol;

        struct {
            void(*func03)();
            void(*func04)();
            void(*func05)();
            void(*func06)();
            void(*func07)();
            void(*func08)();
            void(*func09)();
            void(*func0A)();
            void(*func0B)();
            void(*func0C)();
            void(*func0D)();
            void(*func0E)();
            void(*func0F)();
            void(*func10)();
            void(*func11)();
            void(*func12)();
            void(*func13)();
            void(*endObjSequence)(int slot);
        } Checkpoint; //XXX must be wrong name

        struct {
            void(*func03)();
            void(*func04)();
            void(*func05)();
            void(*func06)();
            void(*func07)();
            void(*func08)();
            void(*func09)();
            void(*func0A)();
            void(*func0B)();
            void(*func0C)();
            void(*func0D)();
            void(*func0E)();
            void(*func0F)();
            void(*func10)();
            void(*func11)();
            void(*func12)();
            void(*func13_nop)(struct ObjInstance *obj);
        } Dll05;

        struct {
            void(*func03)();
            void(*func04)();
            void(*func05)();
            void (*func06_nop)(struct ObjInstance *obj);
        } Dummy04;

        struct {
            void(*func03_nop)();
            void(*newgame)();
            void(*func05)();
            void(*func06_nop)();
            void(*func07)();
            void(*func08)();
            void(*savePoint)();
            void(*gotoSavegame)();
            void(*restartPoint)();
            void(*gotoRestartPoint)();
            void(*clearRestartPoint)();
            void(*haveRestartPoint)();
            void(*func0F)();
            void(*loadOptions)();
            void(*func11)();
            void(*getAct)();
            void(*gplaySetAct)();
            void(*setMapAct)();
            void(*getObjGroups)();
            void(*setObjGroups)();
            void(*getMapObjGroups)();
            void(*setMapObjGroups)();
            void(*getMapObjGroups_19)();
            void(*resetMapState)();
            void(*gplayAddTime)();
            void(*shouldNotSaveTime)();
            void(*func1D)();
            void(*updateTime)();
            void(*func1F)();
            void(*setPlayerNo)();
            void(*getSavedObjPositions)();
            void(*getNumSavedObjPositions)();
            void(*func23)();
            void(*func24)();
            void(*getCurCharState)();
            struct CharPos* (*getCurCharPos)();
            void(*func27)();
            void(*gplayGetCurrentPlayerLactions)();
            void(*gplayGetCurrentPlayerEnvactions)();
            void(*func2A)();
            void(*func2B)();
            void(*func2C)();
            void(*func2D)();
            void(*isCheatUnlocked)();
            void(*unlockCheat)();
            void(*isCheatUnlockedAndEnabled)();
            void(*toggleCheatEnabled)();
            void(*isCinemaUnlocked)();
            void(*unlockCinema)();
        } gplay;

        struct {
            void(*func04)();
            void(*func05)();
            void(*func06)();
            void(*func07)();
            void(*func08)();
            void(*func09)();
            void(*func0A)();
            void(*func0B)();
            void(*func0C)(struct ObjInstance *obj);
        } ModGfx;

        struct {
            /* 0x08 */ void(*update)(struct ObjInstance *object);
            /* 0x0c */ void(*hitDetect)(struct ObjInstance *object);
            /* 0x10 */ void(*render)(struct ObjInstance *object, undefined4 param2, undefined4 param3, undefined4 param4, undefined4 param5, BOOL shouldRender);
            /* 0x14 */ void(*onFreeObjDef)(struct ObjInstance *object, undefined4);
            /* 0x18 */ u32 (*getModelFlags)(struct ObjInstance *object); //in final, this is done inline
            /* 0x1c */ int (*getExtraSize)(struct ObjInstance *object, void *state); //returns sizeof(this obj's State)
            /* 0x20 */ UNKTYPE *setScale;
            /* 0x24 */ UNKTYPE *unk24;
            /* 0x28 */ void (*modelMtxFn_0x28)(struct ObjInstance *object, undefined4, Vec * );
            /* 0x2c */ UNKTYPE *render2C; //called for child of player object with ID 0x2d
        } Object;
    };

} DLL_funcs;

typedef struct DLL {
    /* 0x0 */ struct DLL *prev;
    /* 0x4 */ struct DLL *next;
    /* 0x8 */ int (*_08)(void *thisdll);
    /* 0xc */ ushort nFuncs; //includes onUnload but not onLoad
    /* 0xe */ ushort _0E;
    /* 0x10 */ DLL_funcs funcs;
} DLL;

typedef struct {
    /* 0x0 */ DLL_funcs *funcs;
    /* 0x4 */ UNKTYPE *_0C; //maybe rodata? seems to be set by uninitialized var
    /* 0x8 */ int id;
    /* 0xc */ int refCount;
} LoadedDLL;

BOOL DLL_free(LoadedDLL *dll);
LoadedDLL* runlinkDownloadCode(ushort id, ushort param);

#endif //_SYS_DLL_H_
