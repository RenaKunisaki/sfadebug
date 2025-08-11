#ifndef _SYS_DLL_H_
#define _SYS_DLL_H_
#include "dolphin/mtx.h"
#include "gfx/gametext.h"
#include "gfx/render.h"
#include "obj/ObjInstance.h"
#include "obj/Curve.h"
#include "types.h"

//XXX file here is DLL*
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
            void (*init)(void);
            void (*activate)(Gfx_ **gfx, Mtx44 **mtx, N64Vertex **vtx); //or render?
            void (*setFlag)(int iFlag,s8 val);
            int (*getFlag)(int iFlag);
            void (*camCtrl)(double param_1,ObjInstance *param_2,uint param_3);
            void (*func08)(void);
            void (*func09)(undefined *param1,ObjDef *objDef);
            void (*func0A)(undefined *param1);
            void (*func0B)(undefined *param1);
            void (*func0C)(double param_1);
            void (*func0D)(ObjInstance *obj);
            undefined4 (*func0E_ret0)(void);
            BOOL (*isEnabled)(void);
            int (*func10)(void);
            void (*func11)(int param1);
            undefined4 (*func12_ret0)(void);
            void (*func13_nop)(void);
            void (*startObjSequence)(int seqNo,ObjInstance *obj,uint flags);
            void (*endObjSequence)(int seqNo);
            void (*func16)(undefined4 param1,int param2,int param3,int param4);
            void (*preemptSequenceTime)(ObjInstance *obj,int time);
            void (*func18)(undefined *param1,undefined4 param2);
            s8 (*func19)(void);
            void (*func1A)(s8 param1);
            s16 (*func1B)(void);
            void (*func1C)(int param1);
            s16 (*func1D)(void);
            void (*func1E)(int param1);
            void (*func1F)(int param1,int param2);
            void (*func20)(ObjInstance *obj,undefined *param_2,short param3,short param4,short param5,short param6,short param7);
            undefined4 (*func21)(int param1,ObjInstance *override,s8 param3);
            BOOL (*func22)(float x,float y,float z);
            undefined4 (*func23)(undefined4 param_1,int param2);
            char* (*func24)(ObjInstance *obj); //not present in final version
        } anim; //aka ObjSeq

        struct {
            void (*func03)(ObjInstance *obj,float x,float y,float z);
            void (*func04)(int param_1);
            struct Camera* (* getCurCamera)(void);
            int (*func06)(void);
            int (*func07)(void);
            struct CamControlAttention* (* getAttentionCam)(void);
            void (*setupCamControl1)(int param1,s8 param2,s8 param3,uint len,ObjDef *odef,int param6,u8 param7);
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
            void (*func13)(Gfx_ **gfx,N64Vertex **vtx,Pol **pol, Mtx44 **mtx);
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
            void(*func03)(u8,uint);
            void(*func04)(Gfx_**, Mtx44**, N64Vertex **vtx);
            void(*func05)(uint, u8);
            void(*func06)(uint, u8);
            void(*func07)(float, uint, u8);
            u8(*func08)(void);
            float(*func09)(void);
        } Dll1A;

        struct {
            void (*func03)(void);
            undefined4 (*func04)(int);
            //something screwy. this DLL only has these
            //two functions, and pDll_36 is only ever
            //set to this, but, the game seems to treat
            //it as if it points to gplay.
            //need to double check symbol addrs.
        } Dll36;

        struct {
            undefined4 (*func03_ret0)(void);
            void (*func04_nop)(void);
            void (*func05)(Gfx_ **gfx,undefined4 param2,undefined4 param3);
        } Dll48;

        struct {
            int (*set_retM1)(void *param_1,undefined param_2,char *file,int line,char *code);
            void (*free_nop)(ObjInstance *param_1,undefined param_2,char *file,int line,char *code);
            undefined4 (*func05_ret0)(Gfx_**);
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
            void (*func03)(void);
            void (*func04)(int *param_1,int param_2);
            void (*func05)(s8 param_1,uint param_2);
            void (*func06)(void);
            void (*ownerFree)(ObjInstance *obj);
            void (*ownerFree2)(ObjInstance *obj);
            void (*draw)(ObjInstance *obj,Gfx_ **gfx,undefined4 param_3,undefined4 param_4,s8 param_5);
            void (*func0A_nop)(void);
            void (*func0B_nop)(void);
            void (*ownerFree3)(ObjInstance *obj);
            s8 (*func0D)(ObjInstance *obj);
        } expgfx;

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
            void(*savePoint)();
            void(*setPos)(Vec*, int, int, int);
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
            struct SaveGame* (*func24)();
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
            void (*func03)(void);
            int (*func04)(struct ModGfxStruct0F *param1,undefined4 param_2,int param3,int param4,int param5,int param6,int textureId,Texture *tex);
            void (*func05)(void);
            void (*free)(void);
            void (*func07)(int param1);
            void (*func08)(int param1);
            undefined4 (*func09)(Gfx_ **gfx,Mtx44 **mtx,N64Vertex **vtx,bool param4,int param5);
            void (*func0A)(short *param1);
            void (*func0B)(void);
            void (*func0C)(ObjInstance *obj,undefined param2);
            void (*func0D)(int param1);
            void (*func0E)(undefined *param1);
            void (*func0F)(int param1,s8 param2,s8 param3,int param4,int param5);
            void (*func10)(void);
            void (*func11)(undefined4 param4,undefined2 param5,undefined4 param6,float x,float y,float z);
            void (*func12)(void);
            void (*func13)(s16 param1);
            void (*func14)(u16 param1);
            void (*func15)(u16 *param1);
            void (*func16)(ObjInstance *obj,int param2,int param3,int param4,int param5,int param6,Texture *tex);
            void (*setFlags54)(uint flags);
            int (*func18)(void);
        } ModGfx;

        struct {
            void(*update)(struct ObjInstance *object);
            void(*render)(struct ObjInstance *object, Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx, bool shouldRender);
            //void(*func04)(struct ObjInstance *object);
            void(*hitDetect)(struct ObjInstance *object);
            void(*func06)(struct ObjInstance *object, Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx, bool shouldRender);
            void(*onFreeObjDef)(struct ObjInstance *object, undefined4);
            u32 (*getModelFlags)(struct ObjInstance *object); //in final, this is done inline
            int (*getExtraSize)(struct ObjInstance *object, void *state); //returns sizeof(this obj's State)
            UNKTYPE *setScale;
            UNKTYPE *unk24;
            void (*modelMtxFn_0x28)(struct ObjInstance *object, undefined4, Vec * );
            void (*render2C)(struct ObjInstance *object, Gfx_ **gfx, Mtx44 **mtx, Pol **pol, N64Vertex **vtx); //called for child of player object with ID 0x2d, 0x2f
        } Object;

        struct {
            void (*func03)(void);
            void (*func04)(s8 param1);
            int (*func05)(void);
            undefined4 (*tasktextGetTaskName)(s8 task);
            void (*func07)(void);
            int (*func08)(void);
        } SaveGame;

        struct {
            int (*func03)(int param1);
            undefined4 (*func04)(void);
            void (*func05)(uint param1,s8 param2);
            void (*func06)(uint group);
            void (*free)(void);
            void (*func08)(void);
            void (*func09)(Gfx_ **gfx,int delayMin);
            int (*func0A)(int param1);
            bool (*func0B)(int param1,int param2);
            undefined4 (*func0C)(s8 param1);
        } subtitles;

        struct {
            void (*walkGroupFn03)(double param_1,double param2,double param3);
            uint (*func04)(float *param1,undefined *param2);
            undefined4 (*func05)(int param1);
            undefined2 (*func06)(float *param1,int groupNo);
            undefined4 (*isPointWithinPatchGroup)(float *param1,int param2,uint param3);
            void (*func08)(float *param_1,uint param_2,int param3);
            void (*func09)(float *param_1,uint param_2,int param3);
            void (*func0A)(Vec *param_1,Vec *param_2,short param3);
            bool (*func0B)(int param1,float *param2,float *param3);
            undefined4 (*getPatchEndPoint)(int groupNo,int param2,float *outA,float *outB);
            bool (*func0D)(Curve *param1,float param2,float param3,undefined4 param4);
            undefined4 (*func0E)(Curve *param1,float param2);
            undefined4 (*func0F)(undefined *param1,undefined *param2);
            void (*func10)(float *param1);
            void (*func11)(ObjInstance *obj,uint param_2);
            void (*func12)(ObjInstance *obj,uint param_2);
            void (*func13)(ObjInstance *obj,int param_2);
        } TrickyWalk;

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

/* 80398934 */ extern LoadedDLL *pDll_1A;
/* 80398938 */ extern LoadedDLL *pDll_camcontrol;
/* 8039893C */ extern LoadedDLL *pDll_anim;
/* 80398940 */ extern LoadedDLL *pDll_newday;
/* 80398944 */ extern LoadedDLL *pDll_newfog;
/* 80398948 */ extern LoadedDLL *pDll_newclouds;
/* 8039894C */ extern LoadedDLL *pDll_newstars;
/* 80398950 */ extern LoadedDLL *pDll_0A;
/* 80398954 */ extern LoadedDLL *pDll_GameUI;
/* 80398958 */ extern LoadedDLL *pDll_checkpoint;
/* 8039895C */ extern LoadedDLL *pDll_Dummy04;
/* 80398960 */ extern LoadedDLL *pDll_Dummy04_2;
/* 80398964 */ extern LoadedDLL *pDll_expgfx;
/* 80398968 */ extern LoadedDLL *pDll_modgfx;
/* 8039896C */ extern LoadedDLL *pDll_projgfx;
/* 80398970 */ extern LoadedDLL *pDll_0E;
/* 80398974 */ extern LoadedDLL *pDll_partfx;
/* 80398978 */ extern LoadedDLL *pDll_objfsa;
/* 8039897C */ extern LoadedDLL *pDll_screens;
/* 80398980 */ extern LoadedDLL *pDll_gametext;
/* 80398984 */ extern LoadedDLL *pDll_subtitles;
/* 80398988 */ extern LoadedDLL *pDll_Dummy15;
/* 8039898C */ extern LoadedDLL *pDll_waterfx;
/* 80398990 */ extern LoadedDLL *pDll_TrickyWalk;
/* 80398994 */ extern LoadedDLL *pDll_curve;
/* 80398998 */ extern LoadedDLL *pDll_picmenu;
/* 8039899C */ extern LoadedDLL *pDll_47;
/* 803989A0 */ extern LoadedDLL *pDll_19;
/* 803989A4 */ extern LoadedDLL *pDll_gplay;
/* 803989A8 */ extern LoadedDLL *pDll_foodbag;
/* 803989AC */ extern LoadedDLL *pDll_savegame;
/* 803989B0 */ extern LoadedDLL *pDll_48;
/* 803989B4 */ extern LoadedDLL *pDll_modelfx;
/* 803989B8 */ extern LoadedDLL *pDll_baddieControl;
/* 803989BC */ extern LoadedDLL *pDll_36;
/* 803989C0 */ extern LoadedDLL *pDll_pickup;

#endif //_SYS_DLL_H_
