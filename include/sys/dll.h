#ifndef _SYS_DLL_H_
#define _SYS_DLL_H_
#include "gfx/gametext.h"
#include "gfx/render.h"
#include "obj/ObjInstance.h"
#include "obj/Curve.h"
#include "types.h"

//XXX file here is DLL*
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
            void (*func18)(Gfx_ **gfx,Mtx44 **mtx,undefined4 *param3,undefined4 *param4);
            void (*func19)(int param1,BOOL param2);
            void (*func1A)(undefined4 param1,undefined4 param2);
            int (*func1B)(void);
            void (*func1C)(s8 param1);
            void (*func1D)(int param1);
            void (*func1E)(int param1,s8 param2);
        } camcontrol;

        struct {
            void (*reset)(void);
            void (*Add)(ObjDef *def);
            void (*Remove)(ObjDef *def);
            void (*calcPosition)(ObjPos *obj,struct CheckpointStruct10 *param2,int param3);
            void (*racePostion)(ObjInstance *param_1,undefined *param_2,undefined4 param_3,int param_4);
            void (*func08)(double param_1_00,short *param_2,int param_3,int param4,uint param5,char param6);
            undefined4 (*func09_ret1)(void);
            void (*func0A)(int param1,float *param2,char *param3);
            struct CheckpointStruct2* (*find)(int id,int *outIdx);
            void (*func0C)(Gfx_ **gfx,N64Vertex **vtx,Pol **pol);
            void (*func0D)(undefined4 param1);
            undefined* (*func0E)(int *param1);
            int (*func0F)(undefined *param1);
            int (*func10)(int param1);
            void (*func11)(void);
            void (*func12)(Gfx_ **gfx,N64Vertex **vtx,Pol **pol);
        } Checkpoint;

        struct {
            void (*clear)(void);
            void (*addCurveDef)(ObjDef_RomCurve *curve);
            void (*remove)(ObjDef_RomCurve *curve);
            ObjDef_RomCurve** (*getCurves)(int *outNum);
            int (*find)(double x,double y,double z,int *types,int nTypes,int action);
            void (*findNearObj)(ObjInstance *obj,undefined *param_2,int param3,int param4,s8 param5);
            ObjDef_RomCurve* (*getById)(uint id);
            void (*func0A)(double param_1,double param2,double param3,int type,int action,float *outX,float *outY,float *outZ);
            float (*distFn0B)(Vec *param1,uint id);
            float (*distXZ)(float x,float z,uint id);
            void (*func0D)(undefined4 *param1,int *param2);
            BOOL (*isPoint)(ObjDef_RomCurve *curve);
            BOOL (*isNotPoint)(ObjDef_RomCurve *curve);
            int (*findFn10)(ObjDef_RomCurve *curve,undefined *param2,int param3,int *outId);
            void (*func11)(ObjDef_RomCurve *curve,int type,int action,int *outId);
            int (*findByAction)(int action);
            void (*func13)(uint param_1,int type,uint param3,int *param4);
            int (*distanceToNearestOfType16)(float x,float y,float z,int mapId);
            void (*distFn15)(double x,double y,double z,uint id,float *dist);
            uint (*func16)(float x,float y,float z);
            int (*getRandomPoint)(ObjDef_RomCurve *curve,int exceptThis);
            int (*getIds_18)(ObjDef_RomCurve *curve,int id,undefined *param3);
            void (*func19)(ObjDef_RomCurve *curve,int param_2,float x,float y,float z);
            int (*getRandomPoint1A)(ObjDef_RomCurve *curve,int exceptThis);
            void (*func1B)(ObjDef_RomCurve *curve,int param_2,float x,float y,float z);
            void (*search)(ObjDef_RomCurve *curve,undefined4 param_2,undefined4 param_3,int *outId);
            void (*getIds_1D)(ObjDef_RomCurve *curve,int *outIds);
            undefined4 (*func1E)(undefined *param1,float *outX,float *outY,float *outZ);
            int (*countRandomPoints)(ObjDef_RomCurve *curve);
            int (*func20)(ObjDef_RomCurve *curve,float *outX,float *outY,float *outZ,u8 *outType);
            void (*func21)(undefined *param_1,float x,float y,float z,float *outX,float *outY,float *outZ);
            ObjDef_RomCurve* (*func22)(ObjDef_RomCurve *curve,float *out,float x,float y,float z);
            void (*getPos)(double scale,ObjDef_RomCurve *curve,float *outX,float *outY,float *outZ);
            float (*func24)(ObjDef_RomCurve *curve1,ObjDef_RomCurve *curve2,Vec *pos2,Vec *pos1,float param_5,float param_6);
            void (*func25)(double param_1_00,Curve *curve,ObjInstance *obj,int param4,int param5);
            undefined4 (*func26)(Curve *param1);
            undefined4 (*setClosed)(Curve *curve,float param2);
            void (*setA4)(Curve *param1,int param2);
            undefined4 (*func29)(Curve *curve,int param2);
            int (*func2A)(undefined *param1,int param2,int idx);
            int (*func2B)(ObjDef_RomCurve *curve,int id,int branch);
            undefined4 (*func2C)(Curve *curve,undefined4 param_2,uint id);
            void (*func2D)(Gfx_ **gfx,N64Vertex **param_3,Pol **param3);
        } curve; //aka RomCurve

        struct {
            void(*free)(int);
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
            void(*func04)(Gfx_**, Mtx44**, N64Vertex **vtx);
            void(*func05)(uint, u8);
            void(*func06)(uint, u8);
            void(*func07)(float, uint, u8);
            u8(*func08)(void);
            float(*func09)(void);
        } Dll1A;

        struct {
            int (*set_retM1)(void *param_1,undefined param_2,char *file,int line,char *code);
            void (*free_nop)(ObjInstance *param_1,undefined param_2,char *file,int line,char *code);
            undefined4 (*func05_ret0)(void);
            void (*func06_nop)(ObjInstance *param_1);
            void (*func07_nop)(void);
            void (*func08_nop)(int param_1,int param_2,int param_3,int param_4,int param_5);
            void (*func09_nop)(int param_1);
            undefined4 (*func0A_ret0)(void);
            undefined4 (*func0B_ret0)(void);
            void (*func0C_nop)(void);
            undefined4 (*func0D_ret0)(void);
            void (*func0E_nop)(void);
            undefined4 (*func0F_ret0)(void);
            void (*func10_nop)(int param_1,s8 param_2);
            undefined4 (*func11_ret0)(void);
            void (*func12_nop)(void);
            void (*func13_nop)(void);
            void (*func14_nop)(ObjInstance *param_1);
            void (*func15_nop)(void);
            void (*func16_nop)(void);
            void (*func17_nop)(void);
            void (*func18_nop)(void);
            void (*func19_nop)(void);
            void (*func1A_nop)(void);
            void (*func1B_nop)(void);
            void (*func1C_nop)(void);
            undefined4 (*func1D_ret0)(void);
            void (*func1E_nop)(void);
            void (*func1F_nop)(void);
            void (*func20_nop)(void);
            undefined4 (*func21_ret0)(void);
            undefined4 (*func22_ret0x7F)(void);
            void (*func23_nop)(void);
            undefined4 (*func24_ret0)(void);
            void (*func25_nop)(void);
        } Dummy04;

        struct {
            void(*free_nop)(void);
            void(*func04_nop)(void);
            void(*func05_nop)(void);
            int(*func06_ret0)(void);
            void(*func07_nop)(void);
            void(*func08_nop)(void);
            void(*func09)(void*);
            void(*func0A_nop)(void);
        } Dummy15;

        struct {
            int (*getNumLanguages)(void);
            int (*getNumTexts)(void);
            void (*gametextLoadLanguage)(s8 lang);
            s8 (*getCurLanguage)(void);
            GameTextGroup* (*loadTextGroup)(uint id);
            char* (*loadTextGroupString)(ushort textId,ushort param2);
            void (*func09)(s8 *param1,int param2);
        } gametext;
        struct {
            void(*func03_nop)(Gfx_**, Mtx44**, N64Vertex **vtx);
            void(*newgame)(int);
            void(*func05)();
            void(*func06_nop)();
            void(*func07)();
            void(*setPos)(Vec*, int, int, int);
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
            struct SaveGame* (*func1D)();
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
            void(*func07)(Gfx_**, Mtx**, int*);
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
            void (*func03)(s8 hintTextIdx);
            void (*func04)(s8 param1);
            int (*func05)(void);
            undefined4 (*tasktextGetTaskName)(s8 task);
            void (*func07)(void);
            int (*func08)(void);
        } SaveGame;

        struct {
            void (*func03)(int);
            void (*func04)(float param_1_00,undefined2 *param_2,uint param_3,undefined *param4,int param5);
            void (*func05)(Gfx_ **gfx,float **param2);
            void (*func06)(float x,float y,float z,float param_4);
            void (*func07)(float param1,float param2,float param3,float param4,undefined2 param5,undefined2 param6);
            void (*func08)(double param1,double param2,double param3,double param4,undefined2 param5);
            void (*func09)(void);
            void (*func0A)(float param1,int param2);
        } waterfx;
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
