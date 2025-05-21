#include "dolphin.h"
#include "dolphin/mtx.h"
#include "types.h"
#include "global.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "sys/alloc.h"
#include "sys/dll.h"
#include "obj/ObjDef.h"
#include "obj/ObjInstance.h"
#include "gfx/models/models.h"

typedef int DataFileId32;
typedef int mapId32;
typedef uint DataFileLoadedFlags;
typedef int ObjDefEnum;
typedef u32 ModelFlags_loadCharacter;

s8 Camera_addWorldMtx(void *);                      /* extern */
void Camera_setPlayerNo(int);                       /* extern */
DLL_func** DLL_setup(uint dllId, ushort exportCount, BOOL bDontCallInit); /* extern */
void ModelInstance_loadShaders(ModelInstance *minst,ObjInstance *obj);              /* extern */
void Modelnstance_setTexFuncPtrsetTexFuncPtr(ModelInstance *modelInstance,undefined *cb);               /* extern */
void ModelInstance_unloadShaders(ModelInstance *modelInstance);                 /* extern */
void Object_freeFn_80092460(ObjInstance *obj);                    /* extern */
void Object_objAddObjectType(ObjInstance *this,int type);             /* extern */
void* Object_objLoadShadow(ObjInstance *this,void *ptr,s32);              /* extern */
void* Object_objSetupField58(ObjInstance *this,void *ptr);               /* extern */
void* Object_objSetupHitState(ObjInstance *this,void *ptr);              /* extern */
void* Object_objSetupHits(int romdefno,ModelInstance *minst,HitState *hitState,void *buf,ObjInstance *obj); /* extern */
ObjInstance** Object_playerGetObject(int typ,int *outNumObjs);               /* extern */
void Object_objRemoveObjectType(ObjInstance *obj,int playerObjIdx);               /* extern */
void Object_streamFn_8018fa50(ObjInstance *obj,int romDefNo);               /* extern */
void *alignTo4(void*);                                  /* extern */
void *alignTo64(void*);                                 /* extern */
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
void Object_freeModels(ObjInstance *this,int count, int);     /* static */
ModelFlags_loadCharacter Object_getModelFlags(ObjInstance *obj);                /* static */
void * Object_objInitState(ObjInstance *this,void *ptr);        /* static */
ObjData * Object_objLoadData(int objType);                 /* static */
void Object_objLoadEventData (ObjInstance *this,int romdefno,ObjEventData *event,int animId,bool bImmediate); /* static */
void * Object_objSetupEvents(int romdefno,ObjInstance *obj,void *ptr); /* static */
void * Object_objSetupModels(int romdefno,ModelInstance *modelInstances,ObjInstance *obj,void *ptr); /* static */
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
float objModelFn_800839d4(ObjInstance *this);        /* static */
void objSetup(ObjInstance *this,uint bAddToLoadedObjs);                /* static */
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
extern s16 *Object_pObjIndex;
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
extern s32 *tables_bin;
extern s32 *tables_tab;
extern f32 timeDelta;
extern s32 var_80396D08;

/**
 * @brief Reset nVisibleObjs.
 */
void clearNVisibleObjs(void) {
    nVisibleObjs = 0;
}

/**
 * @brief Get the number of visible objects.
 *
 *  @param outNumObjs Receives number of loaded objects.
 *  @return int Number of visible objects.
 *  @note Caches the result.
 */
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

void depthSortObjects_doSort(s32 arg0, s32 arg1) {
    ObjInstance *obj;
    BOOL done;
    s32 ii;

    if(arg0 > arg1) return;

    for(ii = arg0; ii <= arg1; ii++) {
        obj = Object_loadedObjs[ii];
        if(obj->data->flags & ObjData_Flag_FixedDepth) {
            obj->depth = obj->data->fixedDepth * 100;
        } else {
            obj->depth = -getCameraDepth(obj->prevPos.x,
                obj->prevPos.y, obj->prevPos.z);
        }
    }

    done = false;
    while(!done) {
        done = true;
        for(ii = arg0; ii < arg1; ii++) {
            if (Object_loadedObjs[ii+1]->depth < Object_loadedObjs[ii]->depth) {
                obj = Object_loadedObjs[ii];
                Object_loadedObjs[ii] = Object_loadedObjs[ii+1];
                Object_loadedObjs[ii+1] = obj;
                done = false;
            }
        }
    }
}

//maybe better name is "objUpdateHolders"
void updateObjMtxs(void) {
    ObjInstance *obj1;
    ObjInstance *obj2;
    s32 ii;

    for(ii = 0; ii < Object_numLoadedObjs; ii++) {
        obj1 = Object_loadedObjs[ii];
        if(obj1->pObj_0xc0) {
            obj2 = obj1->pObj_0xc0;
            if (!obj1->heldBy && obj2->heldBy) {
                obj1->heldBy = obj2->heldBy;
            }
            obj1->pObj_0xc0 = NULL;
        }
    }
}

/**
 * @brief Get the global object list.
 *
 *  @param outFirstObj (optional) Receives index of first object (always 0).
 *  @param outNumObjs (optional) Receives number of objects.
 *  @return ObjInstance** The object list.
 */
ObjInstance **Object_getObjects(s32 *outFirstObj, s32 *outNumObjs) {
    if(outFirstObj) *outFirstObj = 0;
    if(outNumObjs) *outNumObjs = Object_numLoadedObjs;
    return Object_loadedObjs;
}

/**
 * @brief Get the specified object from the global object list.
 *
 *  @param idx Object index.
 *  @return ObjInstance* The object, or NULL if idx is invalid.
 */
ObjInstance *Object_getObject(s32 idx) {
    if((idx < 0) || (idx >= Object_numLoadedObjs)) {
        return NULL;
    }
    return Object_loadedObjs[idx];
}

/**
 * @brief Find an object by its unique ID.
 *
 *  @param id The ID.
 *  @return ObjInstance* The object, or NULL if not found.
 */
ObjInstance *Object_findByUniqueId(u32 id) {
    s32 ii;
    s32 nObjs;
    ObjInstance *obj;

    ii = 0;
    nObjs = Object_numLoadedObjs;
    while(ii < nObjs) {
        obj = Object_loadedObjs[ii];
        if(obj->def && obj->def->id == id) {
            return obj;
        }
        ii++;
    }
    return NULL;
}

s32 Object_getNumLoadedObjs(void) {
    return Object_numLoadedObjs;
}

s32 Object_getFirstLoadedObj(void) {
    return 0;
}

s32 *getTablesBinEntry(s32 idx) {
    //why is this here?
    if((idx < 0) || (idx >= nTablesTab)) {
        return tables_bin;
    }
    return (s32*)((u32)tables_bin + tables_tab[idx] * 4);
}

ObjInstance *objInstantiateCharacter(
ObjDef *def, uint flags, int mapId, int objNo, float *pMatrix) {
    ObjInstance *obj;

    obj = NULL;
    if(getPiLockedFlags() & 1) { obj; }

    loadAsset_Character(&obj, def, flags, mapId, objNo, pMatrix, 0);
    if(obj) objSetup(obj, flags);

    if(getPiLockedFlags() & 1) { obj; }
    return obj;
}

ObjInstance *Object_objSetupObjectActual(ObjDef *def, s32 flags,
s32 mapId, s32 romDefNo, struct ObjInstance *heldBy) {
    //should be down to regswap and string offsets
    ObjInstance objTmp;
    ObjData *objData;
    ObjInstance *result;
    s32 oType;
    s32 realType;
    s32 iModelInst;
    s32 iLock;
    s32 ii;
    s8 bModelFailed;
    u32 totalSize;
    u32 modelFlags; //ModelFlags_loadCharacter
    int nModels;
    void *next;

    oType = def->objType;
    if(flags & 2) realType = oType;
    else {
        if(oType > Object_maxObjType) {
            printf("objSetupObjectActual objtype out of range %d/%d\n",
                oType,Object_maxObjType);
            return NULL;
        }
        realType = Object_pObjIndex[oType];
    }

    memclr(&objTmp, sizeof(ObjInstance));
    result = &objTmp;
    objData = Object_objLoadData(realType);
    result->data = objData;
    if((!objData) || ((s32)objData == -1)) {
            debugPrint("Warning: Unknown object type '%d/%d romdefno %d', using DummyObject (128)\n",
               oType, def->objType, result->romdefno);
        if((s32)objData == -1) {
            //@bug missing newline
            debugPrint("Warning: Object romdefno is -1, check the object is in objects.spec");
        }
        return NULL;
    }

    result->objId = objData->objId;
    result->pos.scale = objData->scale;
    if(0.0f == result->pos.scale) result->pos.scale = 1.0f;
    result->pos.flags = 2;
    if(objData->flags & 0x80) result->pos.flags |= 0x80;
    if(objData->flags & 0x40000) result->flags_0xb0 |= 0x80; //LockAnimsAndControls
    if(flags & 4) result->pos.flags |= 0x2000; //DontSave

    result->pos.pos.x = def->pos.x;
    result->pos.pos.y = def->pos.y;
    result->pos.pos.z = def->pos.z;
    result->realType = realType;
    result->def = def;
    result->romdefno = oType;
    result->romDefNo = romDefNo;
    result->mapId = (s8)mapId;
    result->animVal_a2 = -1;
    result->curSeq = -1;
    result->newOpacity = 0xFF;
    result->msgQueue = NULL;
    result->camDistVar3C = ((u8) def->bound * 8);
    result->camDistVar40 = ((u8) def->cullDist * 8);

    result->dll = NULL;
    if(objData->dll_id) {
        //probably wrong return type here
        result->dll = (DLL*)DLL_setup((u32) objData->dll_id, 6U, 1);
        if(!result->dll) printf("OBJECTS: warning DLL load failed\n");
    }

    if(result->romdefno == 0xF7) { result; }
    modelFlags = Object_getModelFlags(result);
    if(objData->flags & 0x20) modelFlags &= ~1;
    else modelFlags |= 1;
    if (objData->shadowType != 0) modelFlags |= 2;
    else modelFlags &= ~2;
    if (objData->shadowType == 3) modelFlags |= 0x8000; //HasShadow

    totalSize = objGetTotalDataSize(result, objData, def, modelFlags);
    result = (ObjInstance*)mmAlloc(totalSize, ALLOC_TAG_OBJECTS_COL,
        (volatile u32)"obj");
    if(!result) {
        printf("ObjSetupObject(3) Memory fail!!\n");
        objFreeObjdef(realType);
        return NULL;
    }
    memcpy_src_dst_len(&objTmp, result, sizeof(ObjInstance));
    memclr(result + 1, totalSize - sizeof(ObjInstance));
    nModels = objData->nModels;
    result->modelInstances = (ModelInstance**)&result[1];

    ii = 0;
    bModelFailed = false;
    if (!(modelFlags & 0x200)) { //objFileHasModels
        if(modelFlags & 0x400) { //OnlyLoadOneModel
            iModelInst = (modelFlags >> 0xBU) & 0xF;
            if (iModelInst < nModels) {
                result->modelInstances[iModelInst] = loadModelInstance(
                    -objData->pModelList[iModelInst], modelFlags);
                if(!(s32)result->modelInstances[iModelInst]) {
                    bModelFailed = true;
                } else {
                    ModelInstance_loadShaders(
                        result->modelInstances[iModelInst], result);
                    modelInitSkeleton(result->pos.scale,
                        result->modelInstances[iModelInst]);
                    if (result->data->flags & 0x800) {
                        Modelnstance_setTexFuncPtr(
                            result->modelInstances[iModelInst],
                            modelLoadCb_800c5b80);
                    }
                }
            }
        } else {
            while (ii < nModels) {
                result->modelInstances[ii] = loadModelInstance(-(s32) objData->pModelList[ii], modelFlags);
                if ((s32) result->modelInstances[ii] == 0) {
                    bModelFailed = true;
                } else {
                    ModelInstance_loadShaders(result->modelInstances[ii], result);
                    modelInitSkeleton((f64) result->pos.scale, result->modelInstances[ii]);
                    if (result->data->flags & 0x800) {
                        Modelnstance_setTexFuncPtr(result->modelInstances[ii], modelLoadCb_800c5b80);
                    }
                }
                ii += 1;
            }
        }
    }
    if(bModelFailed) {
        Object_freeModels(result, nModels, realType); //unsure of last arg
        objFreeObjdef(realType);
        return NULL;
    }
    next = &result->modelInstances[objData->nModels];
    next = Object_objInitState(result, next);
    if(modelFlags & 0x40) {
        next = Object_objSetupEvents((s32) result->romdefno,
            result, next);
    }
    if(modelFlags & 0x100) {
        next = Object_objSetupModels(result->romdefno,
            result->modelInstances[0], result, next);
    }
    if((modelFlags & 2) && ((s16) objData->shadowType != 0)) {
        next = Object_objLoadShadow(result, next, 0);
    }
    result->cullDistance = result->pos.scale * objModelFn_800839d4(result);
    if((u8)objData->maybeNumHits != 0) {
        next = (void*)Object_objSetupHitState(result, next);
        if ((u8) objData->flags93 & 8) {
            next = (void*)Object_objSetupField58(result, next);
        }
    }
    if((u8)objData->nJoints != 0) {
        next = alignTo4(next);
        result->joints = next;
        next = (void*)((s32)next + ((u8)objData->nJoints * sizeof(Joint)));
    }
    if((u8)objData->nTextures != 0) {
        next = alignTo4(next);
        result->pTextures = next;
        next = (void*)((s32)next + ((u8) objData->nTextures * 0x10));
    }
    if((u8) objData->numLockData != 0) {
        next = alignTo4(next);
        result->romLockdata = next;
        next = (void*)((s32)next + ((u8) objData->numLockData * sizeof(RomLockData)));
    }
    if(((u8) objData->maybeNumHits != 0) && ((u8) objData->bDisableHits != 0)) {
        next = alignTo4(next);
        next = Object_objSetupHits((s32)result->romdefno,
            (ModelInstance *)result->modelInstances[0],
            result->hitstate, next, result);
    }
    if(objData->numLockData != 0) {
        next = alignTo4(next);
        result->lockdata = next;
        for(iLock = 0; iLock < objData->numLockData; iLock++) {
            result->lockdata[iLock].flags         = objData->lockdata[iLock].flags;
            result->lockdata[iLock].fieldC        = objData->lockdata[iLock].unk0C;
            result->lockdata[iLock].fieldF        = objData->lockdata[iLock].unk0F;
            result->lockdata[iLock].combatCamDist = objData->lockdata[iLock].combatCamDist;
            result->lockdata[iLock].maxDist       = objData->lockdata[iLock].maxDist;
        }
        next = (void*)((u32)next + (u32)(objData->numLockData * sizeof(RamLockData)));
    }
    if ((s32) totalSize != ((s32)next - (s32)result)) {
        printf("objects.c: objSetupObject: sizes do not match\n");
    }
    result->heldBy = heldBy;
    Object_streamFn_8018fa50(result, (s32) result->romdefno);
    return result;
}
