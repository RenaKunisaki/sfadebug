
/* Library Function - Single Match
    objGetDistance
   
   Library: KioskDefault 0 0 */

void objDistObj2Obj(ObjInstance *param1,ObjInstance *param2) { //80091264
  float fVar1;
  float fVar2;
  float fVar3;
  
  _savefpr_29();
  if ((param1 != (ObjInstance *)0x0) && (param2 != (ObjInstance *)0x0)) {
    fVar1 = (param1->prevPos).x - (param2->prevPos).x;
    fVar2 = (param1->prevPos).y - (param2->prevPos).y;
    fVar3 = (param1->prevPos).z - (param2->prevPos).z;
    sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
    _restfpr_29();
    return;
  }
                    
  OSPanic("objlib.c",0x2b,"Failed assertion 0");
}


/* Library Function - Single Match
    objGetDistanceSquared
   
   Library: KioskDefault 0 0 */

void objDistSqObj2Obj(ObjInstance *param1,ObjInstance *param2) { //80091314
  _savefpr_29();
  if ((param1 != (ObjInstance *)0x0) && (param2 != (ObjInstance *)0x0)) {
    _restfpr_29();
    return;
  }
                    
  OSPanic("objlib.c",0x39,"Failed assertion 0");
}


/* Library Function - Single Match
    objGetXZDistance
   
   Library: KioskDefault 0 0 */

void objDistObj2ObjXZ(ObjInstance *param1,ObjInstance *param2) { //800913C0
  float fVar1;
  float fVar2;
  
  _savefpr_30();
  if ((param1 != (ObjInstance *)0x0) && (param2 != (ObjInstance *)0x0)) {
    fVar1 = (param1->prevPos).x - (param2->prevPos).x;
    fVar2 = (param1->prevPos).z - (param2->prevPos).z;
    sqrt((double)(fVar1 * fVar1 + fVar2 * fVar2));
    _restfpr_30();
    return;
  }
                    
  OSPanic("objlib.c",0x49,"Failed assertion 0");
}


/* Library Function - Single Match
    objGetXZDistanceSquared
   
   Library: KioskDefault 0 0 */

void objDistSqObj2ObjXZ(ObjInstance *param1,ObjInstance *param2) { //80091460
  _savefpr_30();
  if ((param1 != (ObjInstance *)0x0) && (param2 != (ObjInstance *)0x0)) {
    _restfpr_30();
    return;
  }
                    
  OSPanic("objlib.c",0x57,"Failed assertion 0");
}


/* Library Function - Single Match
    objDistFn_800914fc
   
   Library: KioskDefault 0 0 */

void objDistObj2Def(ObjInstance *param1,ObjDef *param2) { //800914FC
  _savefpr_30();
  if ((param1 != (ObjInstance *)0x0) && (param2 != (ObjDef *)0x0)) {
    _restfpr_30();
    return;
  }
                    
  OSPanic("objlib.c",0x75,"Failed assertion 0");
}


/* Library Function - Single Match
    objDistFn_800915f0
   
   Library: KioskDefault 0 0 */

void objDistSqObj2DefXZ(ObjInstance *param1,ObjDef *param2) { //800915F0
  _savefpr_29();
  if ((param1 != (ObjInstance *)0x0) && (param2 != (ObjDef *)0x0)) {
    _restfpr_29();
    return;
  }
                    
  OSPanic("objlib.c",0x88,"Failed assertion 0");
}


/* Library Function - Single Match
    objDistFn_8009169c
   
   Library: KioskDefault 0 0 */

void objDistSqObj2Def(ObjInstance *param1,ObjDef *param2) { //8009169C
  float fVar1;
  float fVar2;
  
  _savefpr_30();
  if ((param1 != (ObjInstance *)0x0) && (param2 != (ObjDef *)0x0)) {
    fVar1 = (param1->prevPos).x - (param2->pos).x;
    fVar2 = (param1->prevPos).z - (param2->pos).z;
    sqrt((double)(fVar1 * fVar1 + fVar2 * fVar2));
    _restfpr_30();
    return;
  }
                    
  OSPanic("objlib.c",0x96,"Failed assertion 0");
}


/* Library Function - Single Match
    objDistFn_80091a84
   
   Library: KioskDefault 0 0 */

void objDistFn_80091a84(int param1,int param2,float *param3) { //80091A84
  double dVar1;
  double dVar2;
  
  _savefpr_30();
  if ((param1 != 0) && (param2 != 0)) {
    dVar2 = (double)(*(float *)(param1 + 0xc) - *(float *)(param2 + 0xc));
    dVar1 = (double)(*(float *)(param1 + 0x14) - *(float *)(param2 + 0x14));
    getAngle();
    if (param3 != (float *)0x0) {
      dVar1 = sqrt((double)(float)(dVar2 * dVar2 + (double)(float)(dVar1 * dVar1)));
      *param3 = (float)dVar1;
    }
    _restfpr_30();
    return;
  }
                    
  OSPanic("objlib.c",0xe9,"Failed assertion obj1 && obj2");
}


/* Library Function - Single Match
    objJointFn_80091b6c
   
   Library: KioskDefault 0 0 */

void objGetAttachPointWorldPos
               (ObjInstance *obj,int idx,float *outX,float *outY,float *outZ,BOOL noRotate) { //80091B6C
  Model *modelInstance;
  Mtx43 *a;
  int param2;
  Mtx44 MStack_e0;
  vec3s local_a0 [2];
  float local_94;
  float local_90;
  float local_8c;
  Mtx43 MStack_88;
  Mtx43 MStack_58;
  
  if ((idx < 0) || ((int)(uint)obj->data->noplacements <= idx)) {
                    
    OSPanic("objlib.c",0x123,s_Failed_assertion_placeNum>_0____p_802ed8f8);
  }
  modelInstance = objGetModelInstance(obj);
  param2 = (int)(&obj->data->pAttachPoints[idx].bone)[(char)obj->curModel];
  if ((-1 < param2) && (param2 < (int)(uint)*(byte *)(*(int *)modelInstance + 0xb7))) {
    if ((param2 < 0) || ((int)(uint)*(byte *)(*(int *)modelInstance + 0xb7) <= param2)) {
      *outX = (obj->pos).pos.x;
      *outY = (obj->pos).pos.y;
      *outZ = (obj->pos).pos.z;
    }
    else {
      a = (Mtx43 *)modelInstGetjMtx((ModelInstance *)modelInstance,param2);
      if (noRotate == FALSE) {
        local_94 = obj->data->pAttachPoints[idx].pos.x;
        local_90 = obj->data->pAttachPoints[idx].pos.y;
        local_8c = obj->data->pAttachPoints[idx].pos.z;
        local_a0[0].x = obj->data->pAttachPoints[idx].rot.x;
        local_a0[0].y = obj->data->pAttachPoints[idx].rot.y;
        local_a0[0].z = obj->data->pAttachPoints[idx].rot.z;
      }
      else {
        local_94 = *outX;
        local_90 = *outY;
        local_8c = *outZ;
        local_a0[0].x = 0;
        local_a0[0].y = 0;
        local_a0[0].z = 0;
      }
      mtxRotateByVec3s(&MStack_e0,local_a0);
      mtx44Transpose(&MStack_e0,(Mtx44 *)&MStack_58);
      MTXConcat(a,&MStack_58,&MStack_88);
      *outX = MStack_88.m14;
      *outY = MStack_88.m24;
      *outZ = MStack_88.m34;
      if (obj->pMatrix == (ObjInstance *)0x0) {
        *outX = *outX + playerMapOffsetX;
        *outZ = *outZ + playerMapOffsetZ;
      }
    }
    return;
  }
                    
  OSPanic("objlib.c",0x131,s_Failed_assertion_jointNum_>__0___802ed940);
}


/* Library Function - Single Match
    objJointFn_80091db4
   
   Library: KioskDefault 0 0 */

void objJointFn_80091db4(ObjInstance *param1,int param2) { //80091DB4
  Model *modelInstance;
  int param2_00;
  
  if ((param2 < 0) || ((int)(uint)param1->data->noplacements <= param2)) {
                    
    OSPanic("objlib.c",0x17b,s_Failed_assertion_placeNum>_0____p_802ed98c);
  }
  modelInstance = objGetModelInstance(param1);
  param2_00 = (int)(&param1->data->pAttachPoints[param2].bone)[(char)param1->curModel];
  if ((-1 < param2_00) && (param2_00 < (int)(uint)*(byte *)(*(int *)modelInstance + 0xb7))) {
    modelInstGetjMtx((ModelInstance *)modelInstance,param2_00);
    return;
  }
                    
  OSPanic("objlib.c",0x184,s_Failed_assertion_jointNum_>__0___802ed9d4);
}


/* Library Function - Single Match
    objFootFn_80091ec4
   
   Library: KioskDefault 0 0 */

void objFootFn_80091ec4(int param1,int param2,int param3,int param4) { //80091EC4
  int iVar1;
  ModelInstance *modelInstance;
  int iVar2;
  int iVar3;
  
  if ((0 < param3) && (param3 < 0x10)) {
    if ((int)(uint)*(byte *)(*(int *)(param1 + 0x50) + 0x70) <= param2 + param3) {
                    
      OSPanic("objlib.c",0x1a3,s_Failed_assertion_obj_>objdata_>n_802eda48);
    }
    iVar2 = *(int *)(param1 + 0x50);
    modelInstance = *(ModelInstance **)(*(int *)(param1 + 0x7c) + *(char *)(param1 + 0xad) * 4);
    for (iVar3 = 0; iVar3 < param3; iVar3 = iVar3 + 1) {
      iVar1 = modelInstGetjMtx(modelInstance,
                               (int)*(char *)(*(int *)(iVar2 + 0x2c) +
                                             (param2 + iVar3) * 0x18 + (int)*(char *)(param1 + 0xad)
                                             + 0x12));
      *(undefined4 *)(param4 + iVar3 * 0xc) = *(undefined4 *)(iVar1 + 0xc);
      *(undefined4 *)(param4 + iVar3 * 0xc + 4) = *(undefined4 *)(iVar1 + 0x1c);
      *(undefined4 *)(param4 + iVar3 * 0xc + 8) = *(undefined4 *)(iVar1 + 0x2c);
      if (*(int *)(param1 + 0x30) == 0) {
        *(float *)(param4 + iVar3 * 0xc) = *(float *)(param4 + iVar3 * 0xc) + playerMapOffsetX;
        iVar1 = iVar3 * 0xc + 8;
        *(float *)(param4 + iVar1) = *(float *)(param4 + iVar1) + playerMapOffsetZ;
      }
    }
    return;
  }
                    
  OSPanic("objlib.c",0x1a2,s_Failed_assertion_nofeet_>_0____n_802eda1c);
}


/* Library Function - Single Match
    objFn_80092010
   
   Library: KioskDefault 0 0 */

undefined4 objFn_80092010(ObjInstance *param1) { //80092010
  ObjInstance **ppOVar1;
  int local_14;
  int local_10 [2];
  float *local_8;
  
  local_8 = &FLOAT_80395a20;
  if (param1 == (ObjInstance *)0x0) {
                    
    OSPanic("objlib.c",0x1d9,"Failed assertion obj");
  }
  ppOVar1 = Object_getObjects(local_10,&local_14);
  local_10[0] = 0;
  while( true ) {
    if (local_14 <= local_10[0]) {
      return 0;
    }
    if (ppOVar1[local_10[0]] == param1) break;
    local_10[0] = local_10[0] + 1;
  }
  return 1;
}


/* Library Function - Single Match
    objDistFn_800920b4
   
   Library: KioskDefault 0 0 */

ObjInstance * objDistFn_800920b4(ObjInstance *param1,int param2,float *param3) { //800920B4
  ObjInstance **ppOVar1;
  ObjInstance *pOVar2;
  int iVar3;
  double dVar4;
  int local_34;
  int local_30 [3];
  
  if (param1 == (ObjInstance *)0x0) {
                    
    OSPanic("objlib.c",0x1f1,"Failed assertion obj");
  }
  if (param3 == (float *)0x0) {
                    
    OSPanic("objlib.c",0x1f2,"Failed assertion mdist");
  }
  if (*param3 <= 0.0) {
                    
    OSPanic("objlib.c",499,s_Failed_assertion__mdist_>_0_0F_802edab8);
  }
  ppOVar1 = Object_getObjects(local_30,&local_34);
  if (ppOVar1 != (ObjInstance **)0x0) {
    pOVar2 = (ObjInstance *)0x0;
    *param3 = *param3 * *param3;
    iVar3 = local_30[0];
    if (param2 == -1) {
      for (; iVar3 < local_34; iVar3 = iVar3 + 1) {
        dVar4 = (double)objDistSqObj2Obj(param1,ppOVar1[iVar3]);
        if ((dVar4 != 0.0) && (dVar4 < (double)*param3)) {
          *param3 = (float)dVar4;
          pOVar2 = ppOVar1[iVar3];
        }
      }
    }
    else {
      for (; iVar3 < local_34; iVar3 = iVar3 + 1) {
        if (((param2 == (short)ppOVar1[iVar3]->romdefno) && (param1 != ppOVar1[iVar3])) &&
           (dVar4 = (double)objDistSqObj2Obj(param1,ppOVar1[iVar3]), dVar4 < (double)*param3)) {
          *param3 = (float)dVar4;
          pOVar2 = ppOVar1[iVar3];
        }
      }
    }
    return pOVar2;
  }
                    
  OSPanic("objlib.c",0x1f7,"Failed assertion ObjList");
}


/* Library Function - Single Match
    objLockFn_80092258
   
   Library: KioskDefault 0 0 */

undefined4 objLockFn_80092258(int param1) { //80092258
  int iVar1;
  ObjInstance *pOVar2;
  
  if (param1 == 0) {
                    
    OSPanic("objlib.c",0x21c,"Failed assertion obj");
  }
  if (*(int *)(param1 + 0x50) != 0) {
    if (*(int *)(*(int *)(param1 + 0x50) + 0x40) == 0) {
                    
      OSPanic("objlib.c",0x21e,s_Failed_assertion_obj_>objdata_>l_802edb14);
    }
                    /* {@symbol 8016db64} */
    if (((*(byte *)(param1 + 0xaf) & 1) != 0) &&
       (iVar1 = (**(code **)(*pdll_camcontrol + 0x1c))(), iVar1 == 0)) {
      pOVar2 = Object_objGetMain();
      iVar1 = FUN_801a7998((int)pOVar2);
      if (iVar1 == -1) {
        disableButtons(0,PAD_BUTTON_A);
        return 1;
      }
    }
    return 0;
  }
                    
  OSPanic("objlib.c",0x21d,s_Failed_assertion_obj_>objdata_802edaf4);
}


/* Library Function - Single Match
    objAddChild
   
   Library: KioskDefault 0 0 */

void objAddChild(ObjInstance *param1,ObjInstance *param2,int param3) { //800925E4
  byte bVar1;
  
  if ((param3 < 0) || ((int)(uint)param1->data->noplacements <= param3)) {
                    
    OSPanic("objlib.c",0x314,s_Failed_assertion_childPosition>__802edbd0);
  }
  if (4 < param1->nChildren) {
                    
    OSPanic("objlib.c",0x315,s_Failed_assertion_parentObject_>n_802edc28);
  }
  if (param2->parent != (ObjInstance *)0x0) {
                    
    OSPanic("objlib.c",0x316,s_Failed_assertion_childObject_>pa_802edc60);
  }
  if (3 < param3) {
                    
    OSPanic("objlib.c",0x317,s_Failed_assertion_childPosition<__802edc90);
  }
  bVar1 = param1->nChildren;
  param1->nChildren = bVar1 + 1;
  param1->child[bVar1] = param2;
  param2->parent = param1;
  param2->flags_0xb0 = param2->flags_0xb0 & 0xfffc;
  param2->flags_0xb0 = param2->flags_0xb0 | (ObjInstance_FlagsB0)param3;
  return;
}


/* Library Function - Single Match
    objRemoveChild
   
   Library: KioskDefault 0 0 */

void Object_objRemoveChild(ObjInstance *parentObject,ObjInstance *child) { //800926D8
  int iVar1;
  
  if (parentObject->nChildren == 0) {
                    
    OSPanic("objlib.c",0x335,s_Failed_assertion_parentObject_>n_802edcc0);
  }
  for (iVar1 = 0;
      (iVar1 < (int)(uint)parentObject->nChildren && (parentObject->child[iVar1] != child));
      iVar1 = iVar1 + 1) {
  }
  if ((int)(uint)parentObject->nChildren <= iVar1) {
                    
    OSPanic("objlib.c",0x341,s_Failed_assertion_i<parentObject__802edcec);
  }
  for (; iVar1 < (int)(parentObject->nChildren - 1); iVar1 = iVar1 + 1) {
    parentObject->child[iVar1] = parentObject->child[iVar1 + 1];
  }
  parentObject->nChildren = parentObject->nChildren - 1;
  parentObject->child[parentObject->nChildren] = (ObjInstance *)0x0;
  child->parent = (ObjInstance *)0x0;
  return;
}

