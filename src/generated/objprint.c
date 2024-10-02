
/* Library Function - Single Match
    objFrameFn_80094b10
   
   Library: KioskDefault 0 0 */

void objRenderCurrentModel
               (ObjInstance *obj,Gfx **param2,undefined4 *param3,undefined4 *param4,
               undefined4 *param5) { //80094B10
  bool bVar1;
  undefined4 unaff_r23;
  undefined4 uVar2;
  undefined4 uVar3;
  AnimInstance *anim;
  
  bVar1 = areModelsEnabled();
  if ((bVar1) && (obj->objId != 1)) {
    return;
  }
  bVar1 = isMainCharacterEnabled();
  if ((!bVar1) || (obj->objId != 1)) {
    uVar3 = *param3;
    uVar2 = *param4;
    if (param5 != (undefined4 *)0x0) {
      unaff_r23 = *param5;
    }
    if (obj->modelInstances == (ModelInstance *)0x0) {
                    
      OSPanic("objprint.c",599,s_Failed_assertion_obj_>frames_802ee3c4);
    }
    anim = (AnimInstance *)obj->modelInstances->mtxs[(char)obj->curModel + -3];
    if (anim != (AnimInstance *)0x0) {
      if ((anim->model->flags & CopyVtxsOnLoad) == 0) {
        *param2 = *param2;
        *param3 = uVar3;
        *param4 = uVar2;
        if (param5 != (undefined4 *)0x0) {
          *param5 = unaff_r23;
        }
      }
      else {
        RSP_sync(param2);
        if ((obj->shadow != (Shadow *)0x0) && (obj->shadow->field6_0xc != 0)) {
          modelAnimFn_800b2af4(obj,0);
        }
        objprintDrawGCModel(obj);
        if (obj->field25_0x74 != (vec3f *)0x0) {
          renderGCModel(obj);
        }
      }
    }
  }
  return;
}


/* Library Function - Single Match
    objPrintModelFn_80094cbc
   
   Library: KioskDefault 0 0 */

ModelInstance *
objPrintModelFn_80094cbc
          (undefined4 *param_1,Mtx44 **param_2,undefined4 param_3,undefined4 param_4,int param_5,
          int param_6,AnimInstance *param_7,undefined4 param_8,ObjInstance *obj,int param_10) { //80094CBC
  char cVar1;
  AnimInstance *pAVar2;
  Model *model;
  int iVar3;
  AnimInstance *anim;
  ObjPos local_50;
  
  PTR_80398ad8 = (AnimInstance *)0x0;
  anim = (AnimInstance *)obj->modelInstances->mtxs[(char)obj->curModel + -3];
  if ((anim != (AnimInstance *)0x0) && ((*(ushort *)(param_6 + 0x18) & 8) == 0)) {
    model = anim->model;
    if (*(char *)(*(int *)(param_5 + 0x50) + 0x70) != '\0') {
      if ('\x05' < *(char *)(param_5 + 0xad)) {
        printf("2: objprint.c: modelno overflow");
      }
      cVar1 = *(char *)(*(int *)(*(int *)(param_5 + 0x50) + 0x2c) +
                       param_10 * 0x18 + (int)*(char *)(param_5 + 0xad) + 0x12);
      local_50.pos.x = *(float *)(*(int *)(*(int *)(param_5 + 0x50) + 0x2c) + param_10 * 0x18);
      local_50.pos.y = *(float *)(*(int *)(*(int *)(param_5 + 0x50) + 0x2c) + param_10 * 0x18 + 4);
      local_50.pos.z = *(float *)(*(int *)(*(int *)(param_5 + 0x50) + 0x2c) + param_10 * 0x18 + 8);
      local_50.scale = 1.0;
      local_50.rotation.x =
           *(short *)(*(int *)(*(int *)(param_5 + 0x50) + 0x2c) + param_10 * 0x18 + 0xc);
      local_50.rotation.y =
           *(short *)(*(int *)(*(int *)(param_5 + 0x50) + 0x2c) + param_10 * 0x18 + 0xe);
      local_50.rotation.z =
           *(short *)(*(int *)(*(int *)(param_5 + 0x50) + 0x2c) + param_10 * 0x18 + 0x10);
      mtxSetFromObjPos((Mtx44 *)param_7,&local_50);
      Mtx44VecMult((float *)param_7,
                   (float *)(*(int *)(param_6 + (*(ushort *)(param_6 + 0x18) & 1) * 4 + 0xc) +
                            cVar1 * 0x40),(float *)param_7);
    }
    if (model->animBufSize == 0) {
      *(ushort *)&anim->mtxSize = *(ushort *)&anim->mtxSize ^ 1;
      pAVar2 = (AnimInstance *)(&anim->field3_0xc)[*(ushort *)&anim->mtxSize & 1];
      for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
        (&pAVar2->model)[iVar3] = (&param_7->model)[iVar3];
      }
      objPrintModelFn_80095044((undefined2 *)obj,param_5,(ModelInstance *)anim);
      PTR_80398ad8 = pAVar2;
    }
    else {
      PTR_80398ad8 = param_7;
      modelAnimFn_8007e974((ModelInstance *)anim,(int)model,(int)obj,(float *)param_7);
      objPrintModelFn_80095044((undefined2 *)obj,param_5,(ModelInstance *)anim);
    }
    *(ushort *)&anim->mtxSize = *(ushort *)&anim->mtxSize ^ 2;
    if ((((obj->data->flags & DifferentLightColor) != 0) || (model->bCopyVtxsToModelInst != 0)) &&
       (model->bCopyVtxsToModelInst != 0)) {
      FUN_80080d04((int *)anim);
    }
    (obj->pos).pos.x = (float)PTR_80398ad8->x;
    (obj->pos).pos.y = (float)PTR_80398ad8->y;
    (obj->pos).pos.z = (float)PTR_80398ad8->z;
    if (obj->pMatrix == (ObjInstance *)0x0) {
      (obj->pos).pos.x = (obj->pos).pos.x + playerMapOffsetX;
      (obj->pos).pos.z = (obj->pos).pos.z + playerMapOffsetZ;
      (obj->prevPos).x = (obj->pos).pos.x;
      (obj->prevPos).y = (obj->pos).pos.y;
      (obj->prevPos).z = (obj->pos).pos.z;
    }
    else {
      multVectorByObjMtx((double)(obj->pos).pos.x,(double)(obj->pos).pos.y,(double)(obj->pos).pos.z,
                         &(obj->prevPos).x,&(obj->prevPos).y,&(obj->prevPos).z,obj->pMatrix);
    }
    if ((1 < obj->data->noplacements) && (obj->objId == 0x2f)) {
      if (obj->pMatrix != (ObjInstance *)0x0) {
        FUN_8006b318(param_1);
      }
      (*(code *)obj->dll->ptrs2->render2C)(obj,param_1,param_2,param_3,param_4);
      if (obj->pMatrix != (ObjInstance *)0x0) {
        FUN_8006b184(param_1,param_2,&obj->pMatrix->pos);
      }
    }
  }
  return (ModelInstance *)anim;
}


/* Library Function - Single Match
    objPrintModelFn_80095044
   
   Library: KioskDefault 0 0 */

void objPrintModelFn_80095044(undefined2 *param1,undefined4 param2,ModelInstance *param3) { //80095044
  int iVar1;
  Mtx43 *m;
  int iVar2;
  int iVar3;
  int iVar4;
  vec3f local_38;
  vec3f local_2c;
  
  if ((1 < *(byte *)(*(int *)(param1 + 0x28) + 0x70)) && (param1[0x22] == 0x2f)) {
    iVar4 = *(int *)(param1 + 0x5c);
    for (iVar2 = 0; iVar2 < *(short *)(iVar4 + 0x86); iVar2 = iVar2 + 1) {
      iVar1 = iVar2 * 2;
      iVar3 = iVar1 + 1;
      if (iVar3 < (int)(uint)*(byte *)(*(int *)(param1 + 0x28) + 0x70)) {
        if ('\x05' < *(char *)((int)param1 + 0xad)) {
          printf("3: objprint.c: modelno overflow");
        }
        m = (Mtx43 *)modelInstGetjMtx(param3,(int)*(char *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c)
                                                           + (iVar1 + 2) * 0x18 +
                                                             (int)*(char *)((int)param1 + 0xad) +
                                                             0x12));
        if (m == (Mtx43 *)0x0) {
                    
          OSPanic("objprint.c",0x4d1,"Failed assertion jointmtx");
        }
        local_2c.x = *(float *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c) + (iVar1 + 2) * 0x18);
        local_2c.y = *(float *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c) + (iVar1 + 2) * 0x18 + 4);
        local_2c.z = *(float *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c) + (iVar1 + 2) * 0x18 + 8);
        MTXMultVec(m,&local_2c,&local_2c);
        local_2c.x = local_2c.x + playerMapOffsetX;
        local_2c.z = local_2c.z + playerMapOffsetZ;
        *(float *)(iVar4 + iVar2 * 4 + 0x30) = local_2c.x;
        *(float *)(iVar4 + iVar2 * 4 + 0x38) = local_2c.y;
        *(float *)(iVar4 + iVar2 * 4 + 0x40) = local_2c.z;
      }
      if (iVar3 < (int)(uint)*(byte *)(*(int *)(param1 + 0x28) + 0x70)) {
        if ('\x05' < *(char *)((int)param1 + 0xad)) {
          printf("4: objprint.c: modelno overflow");
        }
        local_38.x = *(float *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c) + iVar3 * 0x18);
        local_38.y = *(float *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c) + iVar3 * 0x18 + 4);
        local_38.z = *(float *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c) + iVar3 * 0x18 + 8);
        MTXMultVec((Mtx43 *)(param3->mtxs[param3->flags & 1] +
                            *(char *)(*(int *)(*(int *)(param1 + 0x28) + 0x2c) +
                                     iVar3 * 0x18 + (int)*(char *)((int)param1 + 0xad) + 0x12)),
                   &local_38,&local_38);
        local_38.x = local_38.x + playerMapOffsetX;
        local_38.z = local_38.z + playerMapOffsetZ;
        *(float *)(iVar4 + iVar2 * 4 + 0x18) = local_38.x;
        *(float *)(iVar4 + iVar2 * 4 + 0x20) = local_38.y;
        *(float *)(iVar4 + iVar2 * 4 + 0x28) = local_38.z;
      }
    }
    if (*(short *)(iVar4 + 0x86) != 0) {
      local_2c.x = *(float *)(iVar4 + *(short *)(iVar4 + 0x88) * 4 + 0x30);
      local_2c.y = *(float *)(iVar4 + *(short *)(iVar4 + 0x88) * 4 + 0x38);
      local_2c.z = *(float *)(iVar4 + *(short *)(iVar4 + 0x88) * 4 + 0x40);
      if (bDisableSky == '\0') {
        (**(code **)(**(int **)(param1 + 0x34) + 0x28))(param1,param2,&local_38);
      }
      local_2c.x = local_2c.x - local_38.x;
      local_2c.y = local_2c.y - local_38.y;
      local_2c.z = local_2c.z - local_38.z;
      iVar2 = getAngle();
      *param1 = (short)iVar2;
      sqrt((double)(local_2c.x * local_2c.x + local_2c.z * local_2c.z));
      iVar2 = getAngle();
      param1[1] = 0x4000 - (short)iVar2;
      param1[2] = 0;
    }
  }
  return;
}


/* Library Function - Single Match
    objPrintFn_80095cd4
   
   Library: KioskDefault 0 0 */

void objPrintFn_80095cd4(Gfx *param1,Mtx44 **param2,undefined4 param_3,undefined4 param_4,int param5
                        ,ModelInstance *param6) { //80095CD4
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  Mtx44 *pMVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 auStack_4f0 [2];
  undefined4 local_4e8 [28];
  undefined4 auStack_478 [2];
  uint local_470 [118];
  undefined4 auStack_298 [2];
  uint local_290 [120];
  ObjPos local_b0;
  Mtx44 MStack_98;
  float local_58;
  float local_54;
  float local_50;
  
  pfVar8 = param6->field7_0x14;
  iVar11 = 0x3c;
  puVar7 = null_ARRAY_802cf018 + 2;
  puVar6 = auStack_298;
  do {
    uVar2 = puVar7[3];
    puVar6[2] = puVar7[2];
    puVar6[3] = uVar2;
    iVar11 = iVar11 + -1;
    puVar7 = puVar7 + 2;
    puVar6 = puVar6 + 2;
  } while (iVar11 != 0);
  iVar11 = 0x3c;
  puVar7 = null_ARRAY_802cf028 + 0x76;
  puVar6 = auStack_478;
  do {
    uVar2 = puVar7[3];
    puVar6[2] = puVar7[2];
    puVar6[3] = uVar2;
    iVar11 = iVar11 + -1;
    puVar7 = puVar7 + 2;
    puVar6 = puVar6 + 2;
  } while (iVar11 != 0);
  iVar11 = 0xf;
  puVar7 = null_ARRAY_802cf028 + 0xee;
  puVar6 = auStack_4f0;
  do {
    uVar2 = puVar7[3];
    puVar6[2] = puVar7[2];
    puVar6[3] = uVar2;
    iVar11 = iVar11 + -1;
    puVar7 = puVar7 + 2;
    puVar6 = puVar6 + 2;
  } while (iVar11 != 0);
  for (iVar11 = 1; iVar11 < (int)(uint)*(byte *)(param5 + 0xb7); iVar11 = iVar11 + 1) {
    sqrt((double)(*(float *)(*(int *)(param5 + 0x3c) + iVar11 * 0x1c + 4) *
                  *(float *)(*(int *)(param5 + 0x3c) + iVar11 * 0x1c + 4) +
                 *(float *)(*(int *)(param5 + 0x3c) + iVar11 * 0x1c + 0xc) *
                 *(float *)(*(int *)(param5 + 0x3c) + iVar11 * 0x1c + 0xc)));
    uVar3 = getAngle();
    local_290[iVar11] = uVar3 & 0xffff;
    uVar3 = getAngle();
    local_470[iVar11] = uVar3 & 0xffff;
  }
  iVar11 = 1;
  do {
    if ((int)(uint)*(byte *)(param5 + 0xb7) <= iVar11) {
      return;
    }
    FUN_800a4fa4((Gfx **)param1,(undefined4 *)0x0,(undefined4 *)0x0,0x80000002,0,0,1);
    for (iVar9 = 0; iVar9 < 2; iVar9 = iVar9 + 1) {
      iVar10 = iVar11;
      if (iVar9 == 0) {
        iVar10 = (int)*(char *)(*(int *)(param5 + 0x3c) + iVar11 * 0x1c);
      }
      iVar4 = modelInstGetjMtx(param6,iVar11);
      if (iVar4 == 0) {
                    
        OSPanic("objprint.c",0x7c6,"Failed assertion jMtx");
      }
      local_b0.pos.x = *(float *)(iVar4 + 0xc);
      local_58 = local_b0.pos.x;
      local_b0.pos.y = *(float *)(iVar4 + 0x1c);
      local_54 = local_b0.pos.y;
      local_b0.pos.z = *(float *)(iVar4 + 0x2c);
      local_50 = local_b0.pos.z;
      local_b0.rotation.z = 0;
      local_b0.rotation.y = (short)local_290[iVar10];
      local_b0.rotation.x = (short)local_470[iVar10];
      local_b0.scale = *(float *)((int)pfVar8[1] + iVar10 * 4) * 0.0625;
      if (1.0 < *(float *)(*(int *)(param5 + 0x1c) + iVar10 * 4)) {
        iVar4 = modelInstGetjMtx(param6,(int)*(char *)(*(int *)(param5 + 0x3c) + iVar11 * 0x1c));
        if (iVar4 == 0) {
                    
          OSPanic("objprint.c",0x7de,"Failed assertion jMtx");
        }
        local_58 = *(float *)(iVar4 + 0xc);
        local_54 = *(float *)(iVar4 + 0x1c);
        local_50 = *(float *)(iVar4 + 0x2c);
        local_b0.pos.x =
             (local_b0.pos.x - local_58) * (*(float *)(*(int *)(param5 + 0x1c) + iVar11 * 4) - 1.0)
             + local_b0.pos.x;
        local_b0.pos.y =
             (local_b0.pos.y - local_54) * (*(float *)(*(int *)(param5 + 0x1c) + iVar11 * 4) - 1.0)
             + local_b0.pos.y;
        local_b0.pos.z =
             (local_b0.pos.z - local_50) * (*(float *)(*(int *)(param5 + 0x1c) + iVar11 * 4) - 1.0)
             + local_b0.pos.z;
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      mtxSetFromObjPos(&MStack_98,&local_b0);
      MTXCopy(&MStack_98,*param2);
      puVar7 = (undefined4 *)param1->cmd;
      param1->cmd = (F3DEXcommand)(puVar7 + 2);
      *puVar7 = 0xda380002;
      pMVar5 = *param2;
      *param2 = pMVar5 + 1;
      puVar7[1] = pMVar5;
      if (*(char *)((int)pfVar8[6] + iVar10) == '\0') {
        RSP_setTevColor2(param1,0xff,0xff,0xff,0xff);
      }
      else {
        RSP_setTevColor2(param1,0,0,0,0xff);
      }
      if (iVar9 == 0) {
        puVar7 = (undefined4 *)param1->cmd;
        param1->cmd = (F3DEXcommand)(puVar7 + 2);
        *puVar7 = &DAT_01004008;
        puVar7[1] = &PTR_DAT_802edf10;
      }
      else {
        puVar7 = (undefined4 *)param1->cmd;
        param1->cmd = (F3DEXcommand)(puVar7 + 2);
        *puVar7 = 0x1004010;
        puVar7[1] = &PTR_DAT_802edf10;
        if (bVar1) {
          FUN_800a6d88((uint **)param1,&astruct_4_802edf50,10);
        }
        else {
          FUN_800a6d88((uint **)param1,&astruct_4_802edff0,8);
        }
      }
      puVar7 = (undefined4 *)param1->cmd;
      param1->cmd = (F3DEXcommand)(puVar7 + 2);
      *puVar7 = 0xd8380002;
      puVar7[1] = 0x40;
    }
    iVar11 = iVar11 + 1;
  } while( true );
}


/* Library Function - Single Match
    objModelFn_800971c4
   
   Library: KioskDefault 0 0 */

void renderGCModel(ObjInstance *this) { //800971C4
  Model *modelInstance;
  Mtx43 *param1;
  vec3f *pvVar1;
  AButtonInteraction *interact;
  int iVar2;
  
  interact = this->data->aButtonInteraction;
  pvVar1 = this->field25_0x74;
  if ((this->flags_0xaf & (ModelDisableFlag08|ModelDisableFlag20)) == 0) {
    modelInstance = objGetModelInstance(this);
    for (iVar2 = 0; iVar2 < (int)(uint)this->data->field74_count; iVar2 = iVar2 + 1) {
      if ('\x05' < (char)this->curModel) {
        printf("1: objprint.c: modelno overflow");
      }
      if ((char)(&interact->field_0x11)[iVar2 * 0x18 + (int)(char)this->curModel] < 0) {
        param1 = (Mtx43 *)0x0;
      }
      else {
        param1 = (Mtx43 *)modelInstGetjMtx((ModelInstance *)modelInstance,
                                           (int)(char)(&interact->field_0x11)
                                                      [iVar2 * 0x18 + (int)(char)this->curModel]);
      }
      lockPositionFn_80096e94
                (param1,&pvVar1[iVar2 * 2 + 1].x,(short *)(&interact->field_0x6 + iVar2 * 0x18),
                 interact->field13_0x10 & 0x10,this);
      lockPositionFn_80096e94
                (param1,&pvVar1[iVar2 * 2].x,&interact->field0_0x0 + iVar2 * 0xc,
                 interact->field13_0x10 & 0x10,this);
    }
  }
  return;
}

