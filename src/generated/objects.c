
ObjInstance *
Object_objSetupObjectActual
          (ObjDef *objDef,objSetupObjectActual_flags flags,MapId8 mapId,s32 romDefNo,
          ObjInstance *pMatrix,undefined param6) { //80082B88
  ObjData *objData;
  ObjInstance *obj;
  u32 uVar1;
  uint size;
  ModelInstance *minst;
  vec3f *pvVar2;
  undefined *puVar3;
  astruct_53 **ppaVar4;
  void *ptr;
  int nModels;
  int realType;
  uint modelFlags;
  int iModel;
  uint modelNo;
  double dVar5;
  ObjInstance objTmp;
  bool fail;
  ObjDefEnum objType;
  
  objType = objDef->objType;
  realType = (int)(short)objType;
  if ((flags & SkipObjInd) == 0) {
    if (maxObjType < realType) {
      printf("objSetupObjectActual objtype out of range %d/%d",realType,maxObjType);
      return (ObjInstance *)0x0;
    }
    realType = (int)objindex_bin[realType];
  }
  memclr(&objTmp,0xfc);
  objData = objLoadData(realType);
  objTmp.data = objData;
  if ((objData == (ObjData *)0x0) || (objData == (ObjData *)0xffffffff)) {
    debugPrint("Warning: Unknown object type '%d/%d romdefno %d', using DummyObject (128)",realType,(int)(short)objDef->objType,
               (int)(short)objTmp.romdefno);
    if (objData == (ObjData *)0xffffffff) {
      debugPrint("Warning: Object romdefno is -1, check the object is in objects.spec");
    }
    obj = (ObjInstance *)0x0;
  }
  else {
    objTmp.objId = objData->objId;
    objTmp.pos.scale = objData->scale;
    if (objTmp.pos.scale == 0.0) {
      objTmp.pos.scale = 1.0;
    }
    objTmp.pos.flags = 2;
    if ((objData->flags & 0x80) != 0) {
      objTmp.pos.flags = 0x82;
    }
    if ((objData->flags & 0x40000) != 0) {
      objTmp.flags_0xb0 = objTmp.flags_0xb0 | LockAnimsAndControls;
    }
    if ((flags & 4) != 0) {
      objTmp.pos.flags = objTmp.pos.flags | DontSave;
    }
    objTmp.pos.pos.x = (objDef->pos).x;
    objTmp.pos.pos.y = (objDef->pos).y;
    objTmp.pos.pos.z = (objDef->pos).z;
    objTmp.realType = (s16)realType;
    objTmp.romDefNo = (s16)romDefNo;
    objTmp.animVal_a2 = -1;
    objTmp.curSeq = -1;
    objTmp.newOpacity = 0xff;
    objTmp.msgQueue = (undefined *)0x0;
    objTmp.f128 = 176.0;
    objTmp.camDistVar3C =
         (float)((double)CONCAT44(0x43300000,(uint)objDef->bound << 3 ^ 0x80000000) -
                4503601774854144.0);
    objTmp.oldVel.z = (float)((uint)objDef->cullDist << 3 ^ 0x80000000);
    objTmp.oldVel.y = 176.0;
    objTmp.camDistVar40 = (float)((double)CONCAT44(0x43300000,objTmp.oldVel.z) - 4503601774854144.0)
    ;
    objTmp.dll = (ObjectFuncPtrs *)0x0;
    objTmp.romdefno = objType;
    objTmp.def = objDef;
    objTmp.mapId = mapId;
    if ((objData->dll_id != 0) &&
       (objTmp.dll = (ObjectFuncPtrs *)DLL_setup((uint)objData->dll_id,6,TRUE),
       objTmp.dll == (ObjectFuncPtrs *)0x0)) {
      printf("OBJECTS: warning DLL load failed");
    }
    uVar1 = getModelFlags(&objTmp);
    if ((objData->flags & ModelRelated) == 0) {
      modelFlags = uVar1 | 1;
    }
    else {
      modelFlags = uVar1 & 0xfffffffe;
    }
    if (objData->shadowType == NoShadow) {
      modelFlags = modelFlags & 0xfffffffd;
    }
    else {
      modelFlags = modelFlags | 2;
    }
    if (objData->shadowType == Crash) {
      modelFlags = modelFlags | 0x8000;
    }
    size = objGetTotalDataSize(&objTmp,objData,objDef,modelFlags);
    obj = (ObjInstance *)mmAlloc(size,OBJECTS_COL,"obj");
    if (obj == (ObjInstance *)0x0) {
      printf("ObjSetupObject(3) Memory fail!!");
      objFreeObjdef(realType);
      obj = (ObjInstance *)0x0;
    }
    else {
      memcpy_src_dst_len(&objTmp,obj,0xfc);
      memclr(&obj->oldVel,size - 0xfc);
      nModels = (int)objData->nModels;
      obj->modelInstances = (ModelInstance *)&obj->oldVel;
      iModel = 0;
      fail = false;
      if ((modelFlags & 0x200) == 0) {
        if ((modelFlags & 0x400) == 0) {
          for (; iModel < nModels; iModel = iModel + 1) {
            minst = loadModelInstance(-objData->pModelList[iModel],modelFlags);
            obj->modelInstances->mtxs[iModel + -3] = (Mtx44 *)minst;
            if (obj->modelInstances->mtxs[iModel + -3] == (Mtx44 *)0x0) {
              fail = true;
            }
            else {
              ModelInstance_loadShaders
                        ((ModelInstance *)obj->modelInstances->mtxs[iModel + -3],obj);
              modelInitSkeleton((double)(obj->pos).scale,
                                (ModelInstance *)obj->modelInstances->mtxs[iModel + -3]);
              if ((obj->data->flags & UseDifferentModelLoading) != 0) {
                ModelInstance_setField30
                          ((ModelInstance *)obj->modelInstances->mtxs[iModel + -3],
                           modelLoadCb_800c5b80);
              }
            }
          }
        }
        else {
          modelNo = modelFlags >> 0xb & 0xf;
          if ((int)modelNo < nModels) {
            minst = loadModelInstance(-objData->pModelList[modelNo],modelFlags);
            obj->modelInstances->mtxs[modelNo - 3] = (Mtx44 *)minst;
            if (obj->modelInstances->mtxs[modelNo - 3] == (Mtx44 *)0x0) {
              fail = true;
            }
            else {
              ModelInstance_loadShaders
                        ((ModelInstance *)obj->modelInstances->mtxs[modelNo - 3],obj);
              modelInitSkeleton((double)(obj->pos).scale,
                                (ModelInstance *)obj->modelInstances->mtxs[modelNo - 3]);
              if ((obj->data->flags & UseDifferentModelLoading) != 0) {
                ModelInstance_setField30
                          ((ModelInstance *)obj->modelInstances->mtxs[modelNo - 3],
                           modelLoadCb_800c5b80);
              }
            }
          }
        }
      }
      if (fail) {
        freeModels(obj,nModels);
        objFreeObjdef(realType);
        obj = (ObjInstance *)0x0;
      }
      else {
        pvVar2 = (vec3f *)objInitState(obj,obj->modelInstances->mtxs + objData->nModels + -3);
        if ((modelFlags & 0x40) != 0) {
          pvVar2 = (vec3f *)objSetupEvents((int)(short)obj->romdefno,obj,pvVar2);
        }
        if ((modelFlags & 0x100) != 0) {
          pvVar2 = (vec3f *)objSetupModels((int)(short)obj->romdefno,obj->modelInstances->model,obj,
                                           pvVar2);
        }
        if (((modelFlags & 2) != 0) && (objData->shadowType != NoShadow)) {
          pvVar2 = (vec3f *)objLoadShadow(obj,pvVar2);
        }
        dVar5 = objModelFn_800839d4(obj);
        obj->cullDistance = (float)((double)(obj->pos).scale * dVar5);
        if ((objData->maybeNumHits != 0) &&
           (pvVar2 = (vec3f *)objSetupHitState(obj,pvVar2), (objData->flags93 & 8) != 0)) {
          pvVar2 = (vec3f *)objSetupField58(obj,pvVar2);
        }
        if (objData->nVecs != 0) {
          puVar3 = (undefined *)alignTo4((uint)pvVar2);
          obj->pVecs = puVar3;
          pvVar2 = (vec3f *)(puVar3 + (uint)objData->nVecs * 0x12);
        }
        if (objData->nTextures != 0) {
          ppaVar4 = (astruct_53 **)alignTo4((uint)pvVar2);
          obj->pTextures = ppaVar4;
          pvVar2 = (vec3f *)(ppaVar4 + (uint)objData->nTextures * 4);
        }
        if (objData->field74_count != 0) {
          pvVar2 = (vec3f *)alignTo4((uint)pvVar2);
          obj->field25_0x74 = pvVar2;
          pvVar2 = pvVar2 + (uint)objData->field74_count * 2;
        }
        if ((objData->maybeNumHits != 0) && (objData->bDisableHits != false)) {
          ptr = (void *)alignTo4((uint)pvVar2);
          pvVar2 = (vec3f *)objSetupHits((int)(short)obj->romdefno,
                                         (ModelInstance *)obj->modelInstances->model,obj->hitstate,
                                         ptr,obj);
        }
        if (objData->field74_count != 0) {
          puVar3 = (undefined *)alignTo4((uint)pvVar2);
          obj->field26_0x78 = puVar3;
          for (realType = 0; realType < (int)(uint)objData->field74_count; realType = realType + 1)
          {
            obj->field26_0x78[realType * 5 + 4] =
                 (&objData->aButtonInteraction->field13_0x10)[realType * 0x18];
            obj->field26_0x78[realType * 5] =
                 (&objData->aButtonInteraction->field_0xc)[realType * 0x18];
            obj->field26_0x78[realType * 5 + 3] =
                 (&objData->aButtonInteraction->field_0xf)[realType * 0x18];
            obj->field26_0x78[realType * 5 + 1] =
                 (&objData->aButtonInteraction->field_0xd)[realType * 0x18];
            obj->field26_0x78[realType * 5 + 2] =
                 (&objData->aButtonInteraction->field_0xe)[realType * 0x18];
          }
          pvVar2 = (vec3f *)(puVar3 + (uint)objData->field74_count * 5);
        }
        if (size != (int)pvVar2 - (int)obj) {
          printf("objects.c: objSetupObject: sizes do not match");
        }
        obj->pMatrix = pMatrix;
        streamFn_8018fa50(obj,(int)(short)obj->romdefno);
      }
    }
  }
  return obj;
}


/* Library Function - Single Match
    objFn_800832c8
   
   Library: KioskDefault 0 0 */

void objSetup(ObjInstance *this,uint bAddToLoadedObjs) { //800832C8
  ObjInstance **ppOVar1;
  
  if (this->pMatrix == (ObjInstance *)0x0) {
    (this->prevPos).x = (this->pos).pos.x;
    (this->prevPos).y = (this->pos).pos.y;
    (this->prevPos).z = (this->pos).pos.z;
  }
  else {
    multVectorByObjMtx((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z
                       ,&(this->prevPos).x,&(this->prevPos).y,&(this->prevPos).z,this->pMatrix);
  }
  (this->pos_0x8c).x = (this->prevPos).x;
  (this->pos_0x8c).y = (this->prevPos).y;
  (this->pos_0x8c).z = (this->prevPos).z;
  (this->oldPos).x = (this->pos).pos.x;
  (this->oldPos).y = (this->pos).pos.y;
  (this->oldPos).z = (this->pos).pos.z;
  Object_setup(this,this->def,0);
  if (this->hitstate != (HitState *)0x0) {
    (this->hitstate->pos).x = (this->pos).pos.x;
    (this->hitstate->pos).y = (this->pos).pos.y;
    (this->hitstate->pos).z = (this->pos).pos.z;
    (this->hitstate->prevPos).y = (this->pos).pos.x;
    (this->hitstate->prevPos).z = (this->pos).pos.y;
    this->hitstate->size = (this->pos).pos.z;
  }
  if (-1 < *(short *)&this->data->field_0xa0) {
    worldMapListFn_800aac60((int)*(short *)&this->data->field_0xa0,(int)this);
  }
  if ((this->data->flags & IsWorldObj) == 0) {
    if (this->priority == 0) {
      Object_setPriority(this,0x50);
    }
  }
  else {
    Object_objAddObjectType(this,7);
    if (this->priority != 0x5a) {
      Object_setPriority(this,0x5a);
    }
  }
  if ((bAddToLoadedObjs & 1) != 0) {
    this->flags_0xb0 = this->flags_0xb0 | IsInGlobalObjList;
    ppOVar1 = loadedObjs + numLoadedObjs;
    numLoadedObjs = numLoadedObjs + 1;
    *ppOVar1 = this;
    if (0x15d < numLoadedObjs) {
                    
      OSPanic("objects.c",0x4b2,s_Failed_assertion_ObjListSize<MAX_802eccf0);
    }
    FUN_80083b94(this);
  }
  if ('\0' < (char)this->data->numSeqs) {
    Object_objAddObjectType(this,9);
  }
  if ((this->data->flags & HaveModels) != 0) {
    clearNVisibleObjs();
  }
  if ((this->data->flags & DifferentLightColor) != 0) {
    Object_objAddObjectType(this,0x38);
  }
  return;
}


/* Library Function - Single Match
    objFreeTick
   
   Library: KioskDefault 0 0 */

void Object_objFreeObject(ObjInstance *obj) { //80083C34
  uint uVar1;
  int iVar2;
  
  if (obj == (ObjInstance *)0x0) {
                    
    OSPanic("objects.c",0x5bb,"Failed assertion obj");
  }
  if ((obj->flags_0xb0 & IsFreed) == 0) {
    FUN_80068a9c((uint)obj,0x7f);
    if ((obj->flags_0xb0 & IsInGlobalObjList) != 0) {
      for (iVar2 = 0; (iVar2 < numLoadedObjs && (loadedObjs[iVar2] != obj)); iVar2 = iVar2 + 1) {
      }
      if (iVar2 < numLoadedObjs) {
        numLoadedObjs = numLoadedObjs + -1;
        for (; iVar2 < numLoadedObjs; iVar2 = iVar2 + 1) {
          loadedObjs[iVar2] = loadedObjs[iVar2 + 1];
        }
      }
      objFreeFn_80083b54(obj);
      clearNVisibleObjs();
    }
    obj->flags_0xb0 = obj->flags_0xb0 | IsFreed;
    FUN_8018fac0(obj,(int)(short)obj->romdefno);
    if (obj->lockedFreeTick == 0) {
      if (var_80396D08 == 2) {
        iVar2 = objDelListCount;
        if (objDelListCount != 0) {
          for (iVar2 = 0; (iVar2 < objDelListCount && (delList[iVar2] != obj)); iVar2 = iVar2 + 1) {
          }
        }
        if (iVar2 == objDelListCount) {
          delList[objDelListCount] = obj;
          objDelListCount = objDelListCount + 1;
          if (objDelListCount == 200) {
            printf("objFreeObject: delete list size overrun");
            objDelListCount = objDelListCount + -1;
          }
        }
      }
      else {
        uVar1 = countLeadingZeros(-var_80396D08);
        worldProcessObjFreeList(obj,uVar1 >> 5);
      }
    }
    else {
      for (iVar2 = 0; (iVar2 < lockListLen && (lockList[iVar2] != obj)); iVar2 = iVar2 + 1) {
      }
      if (iVar2 == lockListLen) {
        lockList[lockListLen] = obj;
        lockListLen = lockListLen + 1;
      }
      else {
        printf("objFreeTick %08x locked %d,already on list",(uint)obj,(uint)obj->lockedFreeTick);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    objLoadEventData
   
   Library: KioskDefault 0 0 */

void Object_objLoadEventData
               (ObjInstance *this,int romdefno,ObjEventData *event,int animId,bool bImmediate) { //800843FC
  short sVar1;
  s16 *evtIds;
  int iVar2;
  
  evtIds = (s16 *)this->data->pEvent;
  event->size = 0;
  if (evtIds != (s16 *)0x0) {
    for (iVar2 = 0; evtIds[iVar2] != -1; iVar2 = iVar2 + 3) {
      if (animId == evtIds[iVar2]) {
        sVar1 = evtIds[iVar2 + 1];
        event->size = (int)evtIds[iVar2 + 2];
        if (0x50 < (int)event->size) {
          printf("objects.c: event data size overflow");
          event->size = 0x50;
        }
        if (!bImmediate) {
          loadAsset_fileWithOffsetLength(event->data,OBJEVENT.bin,(int)sVar1,event->size);
          return;
        }
        loadDataFileWithLength(OBJEVENT.bin,event->data,(int)sVar1,event->size);
        return;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    worldFreeObjList_80084c24
   
   Library: KioskDefault 0 0 */

void Object_worldProcessObjFreeList(ObjInstance *obj,int param2) { //80084C24
  s8 sVar1;
  int iVar2;
  ObjInstance **ppOVar3;
  ObjInstance *pOVar4;
  int iVar5;
  ObjInstance *local_f0 [51];
  
  if (obj == (ObjInstance *)0x0) {
                    
    OSPanic("objects.c",0x8e3,"Failed assertion obj");
  }
  if (obj->data == (ObjData *)0x0) {
                    
    OSPanic("objects.c",0x8e4,s_Failed_assertion_obj_>objdata_802ecf78);
  }
  if (obj->nTouchCallbacks != 0) {
    freeFn_80092460(obj);
  }
  if (obj->romdefno == Krystal) {
    krystalFree(obj);
  }
  else if (obj->dll != (ObjectFuncPtrs *)0x0) {
    if (obj->dll->ptrs2->onFreeObjDef != (objOnFreeDefFn *)0x0) {
      (*obj->dll->ptrs2->onFreeObjDef)(obj,param2);
    }
    DLL_free((LoadedDll *)obj->dll);
    obj->dll = (ObjectFuncPtrs *)0x0;
  }
                    /* {@symbol 8011bd1c} */
  (**(code **)(*pDll05 + 0x48))(obj);
                    /* {@symbol 800dd3f8} */
  (**(code **)(*(int *)pDll_modgfx + 0x28))(obj);
  if ((obj->data != (ObjData *)0x0) && ((obj->data->flags & DifferentLightColor) != 0)) {
    removePlayerObj(obj,0x38);
  }
  if (((obj->data->flags & IsWorldObj) != 0) && (removePlayerObj(obj,7), param2 == 0)) {
    iVar2 = 0;
    for (iVar5 = 0; iVar5 < numLoadedObjs; iVar5 = iVar5 + 1) {
      pOVar4 = loadedObjs[iVar5];
      if ((pOVar4->pMatrix == obj) &&
         (pOVar4->pMatrix = (ObjInstance *)0x0, pOVar4->def != (ObjDef *)0x0)) {
        local_f0[iVar2] = pOVar4;
        iVar2 = iVar2 + 1;
        if (0x27 < iVar2) {
          printf("world free obj list overflow");
        }
      }
    }
    for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
      objFreeObject(local_f0[iVar5]);
    }
    trackFreeMap((uint)obj->map);
  }
  if ((param2 == 0) && (obj->objId == 0x10)) {
    for (iVar2 = 0; iVar2 < numLoadedObjs; iVar2 = iVar2 + 1) {
      if (loadedObjs[iVar2]->pObj_0xc0 == obj) {
        loadedObjs[iVar2]->pObj_0xc0 = (ObjInstance *)0x0;
      }
    }
  }
  iVar2 = 0;
  while( true ) {
    if (numLoadedObjs <= iVar2) break;
    if ((loadedObjs[iVar2]->objId == 0x10) &&
       (ppOVar3 = (ObjInstance **)loadedObjs[iVar2]->state, *ppOVar3 == obj)) {
      *ppOVar3 = (ObjInstance *)0x0;
      *(undefined *)(ppOVar3 + 0x22) = 1;
    }
    iVar2 = iVar2 + 1;
  }
  if ('\0' < (char)obj->data->numSeqs) {
    removePlayerObj(obj,9);
  }
  if (obj->shadow != (Shadow *)0x0) {
    if (obj->data->shadowType == BigBoxShadow) {
      setShadowFlag_803db658(1);
    }
    if (obj->shadow->texture != (undefined *)0x0) {
      texFreeTexture((Texture *)obj->shadow->texture);
    }
    if (*(int *)&obj->shadow->field_0x8 != 0) {
      texFreeTexture(*(Texture **)&obj->shadow->field_0x8);
    }
    if ((obj->shadow->field7_0x10 != 0) && (obj->shadow->field7_0x10 != -1)) {
      mm_free((void *)obj->shadow->field7_0x10);
    }
  }
  if (obj->msgQueue != (undefined *)0x0) {
    mm_free(obj->msgQueue);
    obj->msgQueue = (undefined *)0x0;
  }
  sVar1 = obj->data->nModels;
  iVar2 = 0;
  while( true ) {
    if (sVar1 <= iVar2) break;
    if (obj->modelInstances->mtxs[iVar2 + -3] != (Mtx44 *)0x0) {
      modelInstanceFree((ModelInstance *)obj->modelInstances->mtxs[iVar2 + -3]);
    }
    iVar2 = iVar2 + 1;
  }
  if ((obj->stateFlags & 1) != 0) {
    FUN_80085ddc(obj);
  }
  if ((obj->stateFlags & 2) != 0) {
    FUN_8008607c((int)obj);
  }
  objFreeObjdef((int)obj->realType);
  if ((-1 < obj->curSeq) && (param2 == 0)) {
                    /* {@symbol 800d0958} */
    (**(code **)(*(int *)pDll_checkpoint + 0x4c))((int)obj->curSeq);
    obj->curSeq = -1;
  }
  if ((((obj->pos).flags & DontSave) != 0) && (obj->def != (ObjDef *)0x0)) {
    mm_free(obj->def);
  }
  memclr(obj,0xfc);
  mm_free(obj);
  return;
}


/* Library Function - Single Match
    objGetModelInstance
   
   Library: KioskDefault 0 0 */

Model * objGetModelInstance(ObjInstance *obj) { //80085968
  if ((-1 < (char)obj->curModel) && ((char)obj->curModel < obj->data->nModels)) {
    return (Model *)obj->modelInstances->mtxs[(char)obj->curModel + -3];
  }
                    
  OSPanic("objects.c",0xc6a,s_Failed_assertion_object_>modelno_802ed150);
}


/* Library Function - Single Match
    objModelMtxFn_800859e8
   
   Library: KioskDefault 0 0 */

void objModelMtxFn_800859e8(ObjInstance *object,Mtx43 *modelMatrix) { //800859E8
  if (object == (ObjInstance *)0x0) {
                    
    OSPanic("objects.c",0xc98,"Failed assertion object");
  }
  if (modelMatrix == (Mtx43 *)0x0) {
                    
    OSPanic("objects.c",0xc99,"Failed assertion modelMatrix");
  }
  if (object->pMatrix == (ObjInstance *)0x0) {
    (object->pos).pos.x = (object->pos).pos.x - playerMapOffsetX;
    (object->pos).pos.z = (object->pos).pos.z - playerMapOffsetZ;
  }
  objModelMtxFn_8007b0c0(object,modelMatrix);
  if (object->pMatrix == (ObjInstance *)0x0) {
    (object->pos).pos.x = (object->pos).pos.x + playerMapOffsetX;
    (object->pos).pos.z = (object->pos).pos.z + playerMapOffsetZ;
  }
  return;
}


/* Library Function - Single Match
    objModelMtxFn_80085ab8
   
   Library: KioskDefault 0 0 */

void objModelMtxFn_80085ab8(ObjInstance *object,Mtx43 *modelMatrix) { //80085AB8
  vec3s local_70;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  Mtx44 MStack_58;
  
  if (object == (ObjInstance *)0x0) {
                    
    OSPanic("objects.c",0xcc4,"Failed assertion object");
  }
  if (modelMatrix == (Mtx43 *)0x0) {
                    
    OSPanic("objects.c",0xcc5,"Failed assertion modelMatrix");
  }
  if (object->pMatrix == (ObjInstance *)0x0) {
    (object->pos).pos.x = (object->pos).pos.x - playerMapOffsetX;
    (object->pos).pos.z = (object->pos).pos.z - playerMapOffsetZ;
  }
  local_64 = -(object->pos).pos.x;
  local_60 = -(object->pos).pos.y;
  local_5c = -(object->pos).pos.z;
  local_70.x = -(object->pos).rotation.x;
  local_70.y = -(object->pos).rotation.y;
  local_70.z = -(object->pos).rotation.z;
  local_68 = 1.0;
  mtxRotateByVec3s(&MStack_58,&local_70);
  mtx44Transpose(&MStack_58,(Mtx44 *)modelMatrix);
  if (object->pMatrix == (ObjInstance *)0x0) {
    (object->pos).pos.x = (object->pos).pos.x + playerMapOffsetX;
    (object->pos).pos.z = (object->pos).pos.z + playerMapOffsetZ;
  }
  return;
}


/* Library Function - Single Match
    objFn_80085e2c
   
   Library: KioskDefault 0 0 */

void objFreezeFn_80085e2c
               (ObjInstance *object,undefined4 fieldE6,undefined4 r,undefined4 g,undefined4 b,uint a
               ) { //80085E2C
  int iVar1;
  
  if ((object->stateFlags & 1) != 0) {
                    
    OSPanic("objects.c",0xd9f,s_Failed_assertion___object_>state_802ed228);
  }
  object->field66_0xe6 = (short)fieldE6;
  object->stateFlags = object->stateFlags & 0xfb;
  object->stateFlags = object->stateFlags | 2;
  (object->colorEC).r = (u8)r;
  (object->colorEC).g = (u8)g;
  (object->colorEC).b = (u8)b;
  if ((a & 0xff) == 0) {
    (object->colorEC).a = 0;
  }
  else {
    (object->colorEC).a = 0xb4;
  }
  for (iVar1 = 0; iVar1 < (int)(uint)object->nChildren; iVar1 = iVar1 + 1) {
    objFreezeFn_80085e2c(object->child[iVar1],fieldE6,r,g,b,a);
  }
  return;
}

