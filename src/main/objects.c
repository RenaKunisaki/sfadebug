#include "dolphin.h"
#include "dolphin/mtx.h"
#include "types.h"
#include "global.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/dll.h"
#include "obj/ObjDef.h"
#include "obj/ObjInstance.h"
#include "gfx/models/models.h"

typedef int DataFileId32;
typedef int mapId32;
typedef uint DataFileLoadedFlags;
typedef int ObjDefEnum;
typedef u32 AllocTag;
typedef u32 ModelFlags_loadCharacter;

s8 Camera_addWorldMtx(void *);                      /* extern */
void Camera_setPlayerNo(int);                       /* extern */
DLL_func** DLL_setup(uint dllId, ushort exportCount, BOOL bDontCallInit); /* extern */
void ModelInstance_loadShaders(ModelInstance *minst,ObjInstance *obj);              /* extern */
void Modelnstance_setTexFuncPtrsetTexFuncPtr(ModelInstance *modelInstance,undefined *cb);               /* extern */
void ModelInstance_unloadShaders(ModelInstance *modelInstance);                 /* extern */
void Object_freeFn_80092460(ObjInstance *obj);                    /* extern */
void Object_objAddObjectType(ObjInstance *this,int type);             /* extern */
void* Object_objLoadShadow(ObjInstance *this,void *ptr);              /* extern */
void* Object_objSetupField58(ObjInstance *this,void *ptr);               /* extern */
void* Object_objSetupHitState(ObjInstance *this,void *ptr);              /* extern */
void* Object_objSetupHits(int romdefno,ModelInstance *minst,HitState *hitState,void *buf,ObjInstance *obj); /* extern */
ObjInstance** Object_playerGetObject(int typ,int *outNumObjs);               /* extern */
void Object_objRemoveObjectType(ObjInstance *obj,int playerObjIdx);               /* extern */
void Object_streamFn_8018fa50(ObjInstance *obj,int romDefNo);               /* extern */
u32 alignTo4(u64);                                  /* extern */
s32 alignTo64(u64);                                 /* extern */
void debugPrint(char *fmt,...);                   /* extern */
void dll_26F_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,/* DllInitFlags*/ uint flags,float x,float y,float z);                  /* extern */
void objStopSounds(ObjInstance *this,u8 flags);                 /* extern */
void fn_8007FCF8();                                    /* extern */
void fn_8008607C(s16 *);                               /* extern */
mapId32 mapCoordsToId(float x,float z);                           /* extern */
f32 fn_8018FAC0(s16 *, s16);                        /* extern */
void fn_801921E8(ObjInstance *);                               /* extern */
void fn_80192660(ObjInstance *);                               /* extern */
void freezeModelFn_8007f184(ModelInstance *param_1,Mtx *param_2,char param3);                 /* extern */
f32 getCameraDepth(f32, f32, f32);                  /* extern */
void *getCurCamera();                               /* extern */
s32 getCurMapType(void);                             /* extern */
int getLoadedDataFileSize(DataFileId32 param1);                       /* extern */
DataFileLoadedFlags getPiLockedFlags(void);                               /* extern */
void intersectModLineBuild(ObjData *data);                       /* extern */
BOOL isModelAnimDisabled(void);                     /* extern */
void krystalFree(ObjInstance *obj);                          /* extern */
void loadAsset_Character(ObjInstance **result,ObjDef *def,uint flags,int mapId,int objNo,float *pMatrix,undefined4 param7); /* extern */
void loadAsset_fileWithOffsetLength(void *dest,DataFileId32 file,int offset,int length); /* extern */
void * loadDataFileWithLength(DataFileId32 file,void *dest,uint offset,u32 len);     /* extern */
ModelInstance * loadModelInstance(int id,uint flags);                    /* extern */
ObjDefEnum mapGetPlayerObjType(int *outWhichObjs);                       /* extern */
f32 mathFn_80294204(f32, f32);                      /* extern */
void memclr(void *param1,size_t param2);                               /* extern */
void memcpy_src_dst_len(void *param1,void *param2,size_t param3);                /* extern */
void * mmAlloc(uint size,AllocTag tag,char *name);                           /* extern */
void mmFree(void *__ptr);                                    /* extern */
undefined2 modelGetFieldA4(Model *model);                      /* extern */
void modelInstanceFree(ModelInstance *modelInstance);                           /* extern */
void mtx44Transpose(Mtx44 *src,Mtx44 *dst);                         /* extern */
void mtxRotateByVec3s(Mtx44 *mtx,S16Vec *rot);                     /* extern */
void multVectorByObjMtx(double x,double y,double z,float *outX,float *outY,float *outZ,ObjInstance *obj); /* extern */
void objFn_8002aac8(s16 *);                            /* extern */
void objFreeAll(void);                                     /* extern */
void objListAdd(ObjInstance **param_1,ObjInstance *obj1,ObjInstance *obj2);                  /* extern */
void objModelMtxFn_8007b0c0(ObjInstance *obj, f32 (*)[4]);        /* extern */
void objMultPosByMtx(ObjInstance *obj,float *x,float *y,float *z);      /* extern */
void objRemoveFromList(ObjListStruct *entry,ObjInstance *obj);                    /* extern */
void playerOnLoad(ObjInstance *this);                   /* extern */
void playerUpdateFn_800ae404(void);                        /* extern */
void setShadowFlag_803db658(s8 param_1);                        /* extern */
double sqrt(double __x);        /* extern */
void texFreeTexture(Texture *tex);                              /* extern */
void trackFreeMap(mapId32 mapNo);                                 /* extern */
void worldMapListFn_800aac60(double param_1,double param_2,double param_3,mapId32 mapNo,int param2);           /* extern */
void Object_freeModels(ObjInstance *this,int count);     /* static */
ModelFlags_loadCharacter Object_getModelFlags(ObjInstance *obj);                /* static */
void * Object_objInitState(ObjInstance *this,void *ptr);        /* static */
ObjData * Object_objLoadData(int objType);                 /* static */
void Object_objLoadEventData (ObjInstance *this,int romdefno,ObjEventData *event,int animId,bool bImmediate); /* static */
void * Object_objSetupEvents(int romdefno,ObjInstance *obj,void *ptr); /* static */
void * Object_objSetupModels(int romdefno,Model *model,ObjInstance *obj,void *ptr); /* static */
void Object_setPriority(ObjInstance *obj,s8 priority);        /* static */
void Object_setup(ObjInstance *this,ObjDef *def,undefined4 param_3);   /* static */
void Object_worldProcessObjFreeList(ObjInstance *obj,int param2); /* static */
void fn_80083B94(ObjInstance *outNumObjs);                       /* static */
void fn_80085D68(ObjInstance *outNumObjs);                        /* static */
void fn_80085DDC(ObjInstance *outNumObjs);                        /* static */
ModLine * loadModLine(int lineNo,u16 *outCount);              /* static */
void modelInitSkeleton(double scale,ModelInstance *model);       /* static */
void objFreeObjdef(int defNo);                       /* static */
void objFreezeFn_80085e2c(ObjInstance *object,undefined4 fieldE6,undefined4 r,undefined4 g,undefined4 b,uint a); /* static */
uint objGetTotalDataSize(ObjInstance *obj,ObjData *objData,ObjDef *objDef,uint flags); /* static */
double objModelFn_800839d4(ObjInstance *this);        /* static */
void objSetup(double param_1,double param_2,double param_3,ObjInstance *this,uint bAddToLoadedObjs);                /* static */
extern u8 BYTE_802eca98;
extern u8 BYTE_80398a91;
extern f64 DOUBLE_8039a990;
extern f64 DOUBLE_8039a9b8;
extern int DWORD_80396d10;
extern int DWORD_80398a88;
extern void *DWORD_80398a94;
extern s16 *Object_contNoBuf;
extern s32 Object_delList;
extern ObjInstance **Object_loadedObjs;
extern s32 Object_lockList;
extern s32 Object_lockListLen;
extern s32 Object_maxObjId;
extern s32 Object_maxObjType;
extern s32 Object_numLoadedObjs;
extern s32 Object_objDelListCount;
extern s32 Object_objTypes;
extern s32 Object_pObjIndex;
extern s32 Object_pObjectsTab;
extern s32 defList;
extern s32 defNo;
extern s8 effectBoxes;
extern s8 lbl_802ECCE4;
extern s8 lbl_802ECCF0;
extern s8 lbl_802ECDE4;
extern s8 lbl_802ECE0C;
extern s8 lbl_802ECE30;
extern s8 lbl_802ECE44;
extern s8 lbl_802ECEA0;
extern s8 lbl_802ECECC;
extern s8 lbl_802ECEF8;
extern s8 lbl_802ED02C;
extern s8 lbl_802ED05C;
extern s8 lbl_802ED090;
extern s8 lbl_802ED0D4;
extern s8 lbl_802ED100;
extern s8 lbl_802ED150;
extern s8 lbl_802ED228;
extern f32 lbl_8039A998;
extern f32 lbl_8039A99C;
extern f32 lbl_8039A9A0;
extern f32 lbl_8039A9A4;
extern f32 lbl_8039A9A8;
extern f32 lbl_8039A9AC;
extern f32 lbl_8039A9B0;
extern f32 lbl_8039A9C0;
extern f32 lbl_8039A9C4;
extern f32 lbl_8039A9C8;
extern f32 lbl_8039A9CC;
void modelLoadCb_800c5b80(int param_1,ModelInstance *param_2);
extern s32 nTablesTab;
extern s16 nVisibleObjs;
extern u8 numEffectBoxes;
extern void **pDll05;
extern void **pDll_ObjSeq;
extern void **pDll_SaveGame;
extern void **pDll_checkpoint;
extern void **pDll_modgfx;
extern f32 playerMapOffsetX;
extern f32 playerMapOffsetZ;
extern s16 playerObjIds[2];
extern s32 tables_bin;
extern s32 tables_tab;
extern f32 timeDelta;
extern s32 var_80396D08;

void clearNVisibleObjs(void) {
    nVisibleObjs = 0;
}

int getNumVisibleObjects(s32 *outNumObjs) {
    int result; //r31
    s32 nObjs; //r30
    s32 stop; //r29
    s32 nObjsStart; //r28
    s32 nObjsStart2; //r27
    ObjInstance *obj; //r26

    *outNumObjs = Object_numLoadedObjs;
    if(isModelAnimDisabled()) {
        nVisibleObjs = 0;
        return 0;
    }
    if(nVisibleObjs) return nVisibleObjs;
    result = 0;
    nObjs = Object_numLoadedObjs - 1;
    nObjsStart = result;
    nObjsStart2 = nObjs;

    while(result <= nObjs) {
        stop = 0;
        while(result <= nObjsStart2 && !stop) {
            if(Object_loadedObjs[result]->data->flags & 1) {
                result++;
            } else stop = -1;
        }

        stop = 0;
        while(nObjs >= nObjsStart && !stop) {
            if(!(Object_loadedObjs[nObjs]->data->flags & 1)) {
                nObjs--;
            } else stop = -1;
        }

        if(result < nObjs) { //swap
            obj = Object_loadedObjs[result];
            Object_loadedObjs[result] = Object_loadedObjs[nObjs];
            Object_loadedObjs[nObjs] = obj;
            result++;
            nObjs--;
        }
    }

    nVisibleObjs = result;
    return result;
}
