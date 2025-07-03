#ifndef _SYS_DLL_H_
#define _SYS_DLL_H_
//XXX file here is DLL*
#include "obj/ObjInstance.h"
#include "types.h"
typedef int (*DLL_func)(void *file);

enum {
    /*  0 */ MAINDLL_gplay,
    /*  1 */ MAINDLL_ObjSeq,
    /*  2 */ MAINDLL_checkpoint,
    /*  3 */ MAINDLL_newfog,
    /*  4 */ MAINDLL_08,
    /*  5 */ MAINDLL_newstars,
    /*  6 */ MAINDLL_0A,
    /*  7 */ MAINDLL_expgfx,
    /*  8 */ MAINDLL_camcontrol,
    /*  9 */ MAINDLL_Dummy04,
    /* 10 */ MAINDLL_05,
    /* 11 */ MAINDLL_05_2,
    /* 12 */ MAINDLL_modgfx,
    /* 13 */ MAINDLL_projgfx,
    /* 14 */ MAINDLL_0E,
    /* 15 */ MAINDLL_partfx,
    /* 16 */ MAINDLL_objfsa,
    /* 17 */ MAINDLL_11,
    /* 18 */ MAINDLL_gametext,
    /* 19 */ MAINDLL_subtitles,
    /* 20 */ MAINDLL_Dummy15,
    /* 21 */ MAINDLL_waterfx,
    /* 22 */ MAINDLL_TrickyWalk,
    /* 23 */ MAINDLL_curve,
    /* 24 */ MAINDLL_RomCurve,
    /* 25 */ MAINDLL_frontend_control,
    /* 26 */ MAINDLL_47,
    /* 27 */ MAINDLL_1A,
    /* 28 */ MAINDLL_SaveGame,
    /* 29 */ MAINDLL_36,
    /* 30 */ MAINDLL_modelfx,
    /* 31 */ MAINDLL_48,
    /* 32 */ MAINDLL_baddieControl,
    /* 33 */ MAINDLL_partfx1F,
    /* 34 */ MAINDLL_n_POST,
    /* 35 */ MAINDLL_projLib,
    /* 36 */ NUM_MAIN_DLLS
} MainDllIdx; //index into mainDlls[]

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
            void (*func03)(ObjInstance *obj,float x,float y,float z);
            void (*func04)(int param_1);
            struct Camera* (* getCurCamera)(void);
            int (*func06)(void);
            int (*func07)(void);
            struct CamControlAttention* (* getAttentionCam)(void);
            void (*setupCamControl1)(int param1,s8 param2,s8 param3,uint len,ObjDef *odef,int param6,s8 param7);
            void (*getCamAction)(int actNo);
            void (*func0B)(int param1,uint param2);
            void (*setObjA0)(ObjInstance *param1);
            void (*setPosCC)(float x,float y,float z);
            void (*moveBy)(float x,float y,float z);
            void (*func0F)(float param1,float param2,float param3,float param4,float param5,float *param6);
            void (*func10)(float param1,ObjInstance *param2,float *param3,float *param4,float *param5,float *param6);
            struct CameraLock* (*getLock)(void);
            struct CameraLock* (*getLock114)(void);
            void (*func13)(BOOL param1);
            void (*setLock)(struct CameraLock *lock);
            void (*setField110)(undefined4 param1);
            uint (*isFieldE4Negative)(void);
            void (*func17)(void);
            void (*func18)(struct Gfx **gfx,Mtx44 **mtx,undefined4 *param3,undefined4 *param4);
            void (*func19)(int param1,BOOL param2);
            void (*func1A)(undefined4 param1,undefined4 param2);
            int (*func1B)(void);
            void (*func1C)(s8 param1);
            void (*func1D)(int param1);
            void (*func1E)(int param1,s8 param2);
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
            void(*func03)(u8,uint);
            void(*func04)(struct Gfx**, Mtx44**, UNKTYPE **vtx);
            void(*func05)(uint, u8);
            void(*func06)(uint, u8);
            void(*func07)(float, uint, u8);
            u8(*func08)(void);
            float(*func09)(void);
        } Dll1A;

        struct {
            void(*func03)();
            void(*func04)();
            void(*func05)();
            void (*func06_nop)(struct ObjInstance *obj);
        } Dummy04;

        struct {
            void(*func03_nop)(void);
            void(*func04_nop)(void);
            void(*func05_nop)(void);
            int(*func06_ret0)(void);
            void(*func07_nop)(void);
            void(*func08_nop)(void);
            void(*func09)(void*);
            void(*func0A_nop)(void);
        } Dummy15;

        struct {
            void(*func03_nop)(struct Gfx**, Mtx44**, UNKTYPE **vtx);
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
            void(*updateTimes)();
            u8(*func1F)();
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
            void(*func03_nop)();
            void(*func04_nop)();
            void(*func05)(ObjInstance*, undefined4, float*);
            void(*func06_nop)();
            void(*func07)(struct Gfx*, float**, int*);
            void(*func08_nop)();
        } modelfx;

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

        struct {
            /*  0 */ void (*init)(void);
            /*  1 */ void (*activate)(int idx,undefined2 param2,undefined2 len);
            /*  2 */ void (*setFlag)(int iFlag,s8 val);
            /*  3 */ int (*getFlag)(int iFlag);
            /*  4 */ void (*camCtrl)(float param_1,ObjInstance *param_2,uint param_3);
            /*  5 */ void (*func08)(void);
            /*  6 */ void (*func09)(UNKTYPE *param1,ObjDef *objDef);
            /*  7 */ void (*func0A)(UNKTYPE *param1);
            /*  8 */ void (*func0B)(UNKTYPE *param1);
            /*  9 */ void (*func0C)(float param_1);
            /* 10 */ void (*func0D)(UNKTYPE *param_1);
            /* 11 */ undefined4 (*func0E_ret0)(void);
            /* 12 */ BOOL (*func0F)(void);
            /* 13 */ undefined4 (*func10)(void);
            /* 14 */ void (*func11)(undefined4 param1);
            /* 15 */ undefined4 (*func12_ret0)(void);
            /* 16 */ void (*func13_nop)(void);
            /* 17 */ void (*startObjSequence)(int seqNo,ObjInstance *obj,uint flags);
            /* 18 */ void (*endObjSequence)(int seqNo);
            /* 19 */ void (*func16)(undefined4 param1,undefined4 param2,undefined4 param3,undefined4 param4);
            /* 20 */ void (*preemptSequenceTime)(ObjInstance *obj,int time);
            /* 21 */ void (*func18)(UNKTYPE *param1,undefined4 param2);
            /* 22 */ s8 (*func19)(void);
            /* 23 */ void (*func1A)(s8 param1);
            /* 24 */ s16 (*func1B)(void);
            /* 25 */ void (*func1C)(s16 param1);
            /* 26 */ s16 (*func1D)(void);
            /* 27 */ void (*func1E)(s16 param1);
            /* 28 */ void (*func1F)(int param1,s16 param2);
            /* 29 */ void (*func20)(ObjInstance *param_1,int param_2,short param3,short param4,short param5, short param6,short param7);
            /* 30 */ undefined4 (*func21)(int param1,ObjInstance *override,s8 param3);
            /* 31 */ BOOL (*func22)(float x,float y,float z);
            /* 32 */ undefined4 (*func23)(undefined4 param_1,int param2);
            /* 33 */ char* (*func24)(ObjInstance *obj);
        } ObjSeq;

        struct {
            void (*func03)(void);
            void (*func04)(s8 param1);
            int (*func05)(void);
            undefined4 (*tasktextGetTaskName)(s8 task);
            void (*func07)(void);
            int (*func08)(void);
        } SaveGame;
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
