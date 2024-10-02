
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void pushpullObj_initialise(undefined4 param) { //801D4F3C
  return;
}


/* @description Called when DLL is unloaded */

void pushpullObj_release(void) { //801D4F40
  return;
}


/* Library Function - Single Match
    pushpullObj_func03
   
   Library: KioskDefault 0 0 */

void pushpullObj_func03(ObjInstance *param1,int param2) { //801D4F44
  byte bVar1;
  ObjDefEnum OVar2;
  bool bVar3;
  int iVar4;
  ushort uVar5;
  ObjInstanceField58 *pOVar6;
  Mtx44 *pMVar7;
  Model *model;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  double dVar11;
  vec3f local_4c;
  double local_40;
  double local_38;
  
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0x22) << 8;
  Object_objAddObjectType(param1,6);
  Object_setPriority(param1,0x5a);
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801d61cc;
  puVar10 = param1->state;
  pMVar7 = param1->modelInstances->mtxs[(char)param1->curModel + -3];
  model = (Model *)pMVar7->m11;
  *(undefined4 *)(puVar10 + 0x80) = *(undefined4 *)(param2 + 0x1c);
  local_38 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + 0x20));
  *(float *)(puVar10 + 0x10) = (float)(local_38 - 4503599627370496.0) / 65535.0;
  *(float *)(puVar10 + 0x10) = *(float *)(puVar10 + 0x10) * param1->data->scale;
  uVar5 = modelGetFieldA4((Model *)pMVar7->m11);
  local_40 = (double)CONCAT44(0x43300000,(uint)uVar5);
  *(float *)(puVar10 + 0xc) =
       *(float *)(puVar10 + 0x10) * (float)(local_40 - 4503599627370496.0) + 10.0;
  *(float *)(puVar10 + 0x14) = 0.0;
  *(undefined2 *)(puVar10 + 0x7c) = *(undefined2 *)(param2 + 0x18);
  Object_ObjAnimSetMove(0.0,param1,0,0);
  objAllocMsgQueue(param1,4);
  dVar11 = 10000.0;
  for (iVar8 = 0; iVar8 < (int)(uint)model->numPositions; iVar8 = iVar8 + 1) {
    modelGetVtxPosFloat(model,iVar8,&local_4c);
    if ((double)local_4c.y < dVar11) {
      dVar11 = (double)local_4c.y;
    }
  }
  for (iVar8 = 0; iVar8 < (int)(uint)model->numPositions; iVar8 = iVar8 + 1) {
    modelGetVtxPosFloat(model,iVar8,&local_4c);
    if ((double)local_4c.y == dVar11) {
      bVar3 = false;
      for (iVar4 = 0; iVar4 < (char)puVar10[0x84]; iVar4 = iVar4 + 1) {
        if ((local_4c.x == *(float *)(puVar10 + iVar4 * 0xc + 0x18)) &&
           (local_4c.z == *(float *)(puVar10 + iVar4 * 0xc + 0x20))) {
          bVar3 = true;
          iVar4 = (int)(char)puVar10[0x84];
        }
      }
      if (!bVar3) {
        *(float *)(puVar10 + (char)puVar10[0x84] * 0xc + 0x18) = local_4c.x;
        *(float *)(puVar10 + (char)puVar10[0x84] * 0xc + 0x1c) = local_4c.y;
        *(float *)(puVar10 + (char)puVar10[0x84] * 0xc + 0x20) = local_4c.z;
        puVar10[0x84] = puVar10[0x84] + '\x01';
      }
    }
  }
  if ('\x04' < (char)puVar10[0x84]) {
    puVar10[0x84] = 4;
    debugPrint("PUSHPULL OBJECT: hitpoint overflow");
  }
  pOVar6 = param1->field18_0x58;
  bVar1 = param1->field18_0x58->mtxIdx;
  for (iVar8 = 0; iVar8 < (char)puVar10[0x84]; iVar8 = iVar8 + 1) {
    if (0.0 <= *(float *)(puVar10 + iVar8 * 0xc + 0x18)) {
      iVar4 = iVar8 * 0xc + 0x18;
      *(float *)(puVar10 + iVar4) = *(float *)(puVar10 + iVar4) - 0.5;
      puVar10[0xd4] = (char)iVar8;
    }
    else {
      iVar4 = iVar8 * 0xc + 0x18;
      *(float *)(puVar10 + iVar4) = *(float *)(puVar10 + iVar4) + 0.5;
    }
    if (0.0 <= *(float *)(puVar10 + iVar8 * 0xc + 0x20)) {
      iVar4 = iVar8 * 0xc + 0x20;
      *(float *)(puVar10 + iVar4) = *(float *)(puVar10 + iVar4) - 0.5;
      puVar10[0xd2] = (char)iVar8;
    }
    else {
      iVar4 = iVar8 * 0xc + 0x20;
      *(float *)(puVar10 + iVar4) = *(float *)(puVar10 + iVar4) + 0.5;
    }
    multVectorByMatrix((double)*(float *)(puVar10 + iVar8 * 0xc + 0x18),
                       (double)*(float *)(puVar10 + iVar8 * 0xc + 0x1c),
                       (double)*(float *)(puVar10 + iVar8 * 0xc + 0x20),pOVar6->mtx + bVar1,
                       (float *)(puVar10 + iVar8 * 0xc + 0x48),
                       (float *)(puVar10 + iVar8 * 0xc + 0x4c),
                       (float *)(puVar10 + iVar8 * 0xc + 0x50));
  }
  for (uVar9 = 0; (int)uVar9 < (int)(char)puVar10[0x84]; uVar9 = uVar9 + 1) {
    if ((uVar9 != (byte)puVar10[0xd4]) && (*(float *)(puVar10 + uVar9 * 0xc + 0x18) < 0.0)) {
      local_40 = (double)(longlong)(int)*(float *)(puVar10 + uVar9 * 0xc + 0x20);
      local_38 = (double)(longlong)(int)*(float *)(puVar10 + (uint)(byte)puVar10[0xd4] * 0xc + 0x20)
      ;
      if ((int)*(float *)(puVar10 + uVar9 * 0xc + 0x20) ==
          (int)*(float *)(puVar10 + (uint)(byte)puVar10[0xd4] * 0xc + 0x20)) {
        puVar10[0xd5] = (char)uVar9;
      }
    }
    if ((uVar9 != (byte)puVar10[0xd2]) && (*(float *)(puVar10 + uVar9 * 0xc + 0x20) < 0.0)) {
      local_40 = (double)(longlong)(int)*(float *)(puVar10 + uVar9 * 0xc + 0x18);
      local_38 = (double)(longlong)(int)*(float *)(puVar10 + (uint)(byte)puVar10[0xd2] * 0xc + 0x18)
      ;
      if ((int)*(float *)(puVar10 + uVar9 * 0xc + 0x18) ==
          (int)*(float *)(puVar10 + (uint)(byte)puVar10[0xd2] * 0xc + 0x18)) {
        puVar10[0xd3] = (char)uVar9;
      }
    }
  }
  OVar2 = param1->romdefno;
  if (OVar2 == 0x411) {
    FUN_801d67cc((int)param1,(int)puVar10);
  }
  else if (((short)OVar2 < 0x411) && (OVar2 == 0x21e)) {
    FUN_801d67cc((int)param1,(int)puVar10);
  }
  else if ((-1 < *(short *)(param2 + 0x18)) &&
          (uVar9 = mainGetBit((int)*(short *)(param2 + 0x18)), uVar9 != 0)) {
    *(ushort *)(puVar10 + 0xd0) = *(ushort *)(puVar10 + 0xd0) | 1;
  }
  if (param1->shadow != (Shadow *)0x0) {
    param1->shadow->flags = param1->shadow->flags | 0xa10;
    (param1->shadow->color).b = 0x60;
    (param1->shadow->color).a = 0x40;
  }
  *(ushort *)(puVar10 + 0xd0) = *(ushort *)(puVar10 + 0xd0) | 0x40;
  if ((param1->romdefno == VFP_Block2) &&
     (uVar9 = mainGetBit((int)*(short *)(puVar10 + 0x7c)), uVar9 != 0)) {
    (param1->pos).pos.x = -15876.0;
    (param1->pos).pos.y = -1218.0;
    (param1->pos).pos.z = -7664.0;
    (param1->pos).rotation.z = 0;
    (param1->pos).rotation.y = 0;
    *(ushort *)(puVar10 + 0xd0) = *(ushort *)(puVar10 + 0xd0) & 0xfffb;
    *(ushort *)(puVar10 + 0xd0) = *(ushort *)(puVar10 + 0xd0) | 0x80;
  }
  return;
}


/* Library Function - Single Match
    pushpullObj_func04
   
   Library: KioskDefault 0 0 */

void pushpullObj_func04(int param1) { //801D54C8
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *(ushort *)(iVar1 + 0xd0) = *(ushort *)(iVar1 + 0xd0) & 0xfffd;
  if (*(float *)(param1 + 0x28) != 0.0) {
    *(ushort *)(iVar1 + 0xd0) = *(ushort *)(iVar1 + 0xd0) | 2;
  }
  return;
}


/* Library Function - Single Match
    pushpullObj_func05
   
   Library: KioskDefault 0 0 */

void pushpullObj_func05(ObjInstance *param1) { //801D5508
  ObjDefEnum OVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  double dVar9;
  double in_f30;
  double dVar10;
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  uint auStack_bc [6];
  float local_a4 [12];
  float local_74 [4];
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  int local_4c;
  undefined4 local_48;
  uint uStack_44;
  
  _savefpr_29();
  local_cc = 0.0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = 0;
  puVar8 = param1->state;
  OVar1 = param1->romdefno;
  if (OVar1 == 0x411) {
    uVar4 = mainGetBit((int)*(short *)(puVar8 + 0x7c));
joined_r0x801d5598:
    if (uVar4 != 0) goto LAB_801d59e0;
  }
  else if (((short)OVar1 < 0x411) && (OVar1 == 0x21e)) {
    uVar4 = mainGetBit((int)*(short *)(puVar8 + 0x7c));
    goto joined_r0x801d5598;
  }
  if ((*(ushort *)(puVar8 + 0xd0) & 4) != 0) {
    (param1->vel).y = -(timeDelta * 0.1 - (param1->vel).y);
    (param1->pos).pos.y = (param1->vel).y * timeDelta + (param1->pos).pos.y;
  }
  FUN_8006b3d4(&param1->pos);
  for (iVar7 = 0; iVar7 < (char)puVar8[0x84]; iVar7 = iVar7 + 1) {
    multVectorByObjMtx((double)*(float *)(puVar8 + iVar7 * 0xc + 0x18),
                       (double)*(float *)(puVar8 + iVar7 * 0xc + 0x1c),
                       (double)*(float *)(puVar8 + iVar7 * 0xc + 0x20),local_a4 + iVar7 * 3,
                       local_a4 + iVar7 * 3 + 1,local_a4 + iVar7 * 3 + 2,param1);
  }
  if ((*(ushort *)(puVar8 + 0xd0) & 2) != 0) {
    mathFn_8006961c(auStack_bc,(float *)(puVar8 + 0x48),local_a4,&local_cc,4);
    pListFn_800b50cc((int)param1,(int *)auStack_bc,0);
    dVar10 = 0.0;
    uVar5 = 0;
    uVar4 = 0;
    for (iVar7 = 0; iVar7 < (char)puVar8[0x84]; iVar7 = iVar7 + 1) {
      local_74[iVar7] = local_a4[iVar7 * 3 + 1];
      in_f30 = 0.0;
      cVar3 = FUN_800b9dcc((double)local_a4[iVar7 * 3],(double)local_a4[iVar7 * 3 + 1],
                           (double)local_a4[iVar7 * 3 + 2],(int)param1,&local_4c,-1,0);
      bVar2 = false;
      if (cVar3 != '\0') {
        for (iVar6 = 0; iVar6 < cVar3; iVar6 = iVar6 + 1) {
          if (*(char *)(*(int *)(local_4c + iVar6 * 4) + 0x14) == '\x0e') {
            dVar9 = (double)(**(float **)(local_4c + iVar6 * 4) - (param1->pos).pos.y);
            if (0.0 < dVar9) {
              in_f30 = (double)(float)(in_f30 + dVar9);
              uVar4 = uVar4 + 1;
            }
          }
          else if ((!bVar2) && (**(float **)(local_4c + iVar6 * 4) < local_a4[iVar7 * 3 + 1] + 10.0)
                  ) {
            local_74[iVar7] = **(float **)(local_4c + iVar6 * 4);
            dVar10 = (double)(float)(dVar10 + (double)**(float **)(local_4c + iVar6 * 4));
            uVar5 = uVar5 + 1;
            bVar2 = true;
          }
        }
      }
    }
    *(undefined4 *)(puVar8 + 200) = *(undefined4 *)(puVar8 + 0xc4);
    if (uVar4 == 0) {
      *(float *)(puVar8 + 0xc4) = 0.0;
    }
    else {
      uStack_44 = uVar4 ^ 0x80000000;
      local_48 = 0x43300000;
      *(float *)(puVar8 + 0xc4) =
           (float)(in_f30 / (double)(float)((double)CONCAT44(0x43300000,uStack_44) -
                                           4503601774854144.0));
    }
    if (uVar5 == 0) {
      *(ushort *)(puVar8 + 0xd0) = *(ushort *)(puVar8 + 0xd0) | 0xc;
    }
    else {
      (param1->vel).y = 0.0;
      uStack_44 = uVar5 ^ 0x80000000;
      local_48 = 0x43300000;
      (param1->pos).pos.y =
           (float)(dVar10 / (double)(float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) -
                                           4503601774854144.0));
      local_5c = local_74[(byte)puVar8[0xd2]];
      local_64 = *(float *)(puVar8 + (uint)(byte)puVar8[0xd2] * 0xc + 0x20);
      local_58 = local_74[(byte)puVar8[0xd3]];
      local_60 = *(float *)(puVar8 + (uint)(byte)puVar8[0xd3] * 0xc + 0x20);
      local_64 = *(float *)(puVar8 + (uint)(byte)puVar8[0xd2] * 0xc + 0x20) - local_60;
      local_5c = local_74[(byte)puVar8[0xd2]] - local_58;
      iVar7 = getAngle();
      (param1->pos).rotation.y = -(short)iVar7;
      local_5c = local_74[(byte)puVar8[0xd4]];
      local_54 = *(float *)(puVar8 + (uint)(byte)puVar8[0xd4] * 0xc + 0x18);
      local_58 = local_74[(byte)puVar8[0xd5]];
      local_50 = *(float *)(puVar8 + (uint)(byte)puVar8[0xd5] * 0xc + 0x18);
      local_54 = *(float *)(puVar8 + (uint)(byte)puVar8[0xd4] * 0xc + 0x18) - local_50;
      local_5c = local_74[(byte)puVar8[0xd4]] - local_58;
      iVar7 = getAngle();
      (param1->pos).rotation.z = (short)iVar7;
      *(ushort *)(puVar8 + 0xd0) = *(ushort *)(puVar8 + 0xd0) & 0xfff3;
    }
  }
  FUN_8006b3d4(&param1->pos);
  for (iVar7 = 0; iVar7 < (char)puVar8[0x84]; iVar7 = iVar7 + 1) {
    multVectorByObjMtx((double)*(float *)(puVar8 + iVar7 * 0xc + 0x18),
                       (double)*(float *)(puVar8 + iVar7 * 0xc + 0x1c),
                       (double)*(float *)(puVar8 + iVar7 * 0xc + 0x20),
                       (float *)(puVar8 + iVar7 * 0xc + 0x48),(float *)(puVar8 + iVar7 * 0xc + 0x4c)
                       ,(float *)(puVar8 + iVar7 * 0xc + 0x50),param1);
  }
LAB_801d59e0:
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    pushpullObj_func06
   
   Library: KioskDefault 0 0 */

void pushpullObj_func06(ObjInstance *param1,Gfx **param2,undefined4 *param3,undefined4 *param4,
                        undefined4 *param5,char param6) { //801D59FC
  ObjDefEnum OVar1;
  uint uVar2;
  float fVar3;
  undefined *puVar4;
  
  if (param6 == '\0') {
    return;
  }
  puVar4 = param1->state;
  OVar1 = param1->romdefno;
  if (OVar1 == 0x411) {
    uVar2 = mainGetBit((int)*(short *)(puVar4 + 0x7c));
  }
  else {
    if (0x410 < (short)OVar1) {
      if ((OVar1 == VFP_Block2) && (0.0 < *(float *)(puVar4 + 0x14))) {
        *(float *)(puVar4 + 0x14) = *(float *)(puVar4 + 0x14) - timeDelta;
        if (0.0 < *(float *)(puVar4 + 0x14)) {
          FUN_80096b14(200,0,0,0xff);
        }
        else {
          *(float *)(puVar4 + 0x14) = 0.0;
        }
      }
      goto LAB_801d5ad8;
    }
    if (OVar1 != 0x21e) goto LAB_801d5ad8;
    uVar2 = mainGetBit((int)*(short *)(puVar4 + 0x7c));
  }
  if (uVar2 != 0) {
    return;
  }
LAB_801d5ad8:
  fVar3 = param1->modelInstances->mtxs[(char)param1->curModel + -3]->m11;
  *(ushort *)((int)fVar3 + 2) = *(ushort *)((int)fVar3 + 2) | 2;
  objRenderCurrentModel(param1,param2,param3,param4,param5);
  return;
}


/* Library Function - Single Match
    pushpullObj_func07
   
   Library: KioskDefault 0 0 */

void pushpullObj_func07(ObjInstance *param1) { //801D5B2C
  ObjDefEnum OVar1;
  
  OVar1 = param1->romdefno;
  if (OVar1 == 0x411) {
    mainSetBits((int)*(short *)(param1->state + 0x7c),0);
  }
  else if (((short)OVar1 < 0x411) && (OVar1 == 0x21e)) {
    mainSetBits((int)*(short *)(param1->state + 0x7c),0);
  }
  Object_removePlayerObj(param1,6);
  return;
}


undefined4 pushpullObj_func08(void) { //801D5B9C
  return 0x48;
}


undefined4 pushpullObj_func09(void) { //801D5BA4
  return 0xd8;
}


/* Library Function - Single Match
    pushpullObj_func0A
   
   Library: KioskDefault 0 0 */

undefined pushpullObj_func0A(ObjInstance *param1,short *param2,int param3,float *param4,
                             float *param5) { //801D5BAC
  byte bVar1;
  ObjDefEnum OVar2;
  ObjInstance *pOVar3;
  ObjInstanceField58 *pOVar4;
  undefined uVar5;
  ObjDef *pOVar6;
  undefined **ppuVar7;
  int iVar8;
  undefined *puVar9;
  float local_fc [12];
  float local_cc [12];
  ObjPos local_9c;
  Mtx44 MStack_84;
  float local_44;
  float local_40 [2];
  undefined4 local_38;
  uint uStack_34;
  
  ppuVar7 = &PTR_80311448;
  pOVar6 = param1->def;
  pOVar3 = Object_objGetMain();
  puVar9 = param1->state;
  uVar5 = 0;
  if (((param3 < 2) && (-2 < param3)) || ((*(ushort *)(puVar9 + 0xd0) & 8) != 0)) {
    pOVar4 = param1->field18_0x58;
    bVar1 = param1->field18_0x58->mtxIdx;
    for (iVar8 = 0; iVar8 < (char)puVar9[0x84]; iVar8 = iVar8 + 1) {
      multVectorByMatrix((double)*(float *)(puVar9 + iVar8 * 0xc + 0x18),
                         (double)*(float *)(puVar9 + iVar8 * 0xc + 0x1c),
                         (double)*(float *)(puVar9 + iVar8 * 0xc + 0x20),pOVar4->mtx + bVar1,
                         (float *)(puVar9 + iVar8 * 0xc + 0x48),
                         (float *)(puVar9 + iVar8 * 0xc + 0x4c),
                         (float *)(puVar9 + iVar8 * 0xc + 0x50));
    }
    Object_ObjAnimSetMove(0.0,param1,0,0);
    objRunAnimation(0.0,1.0,(int)param1,(float *)0x0);
  }
  else {
    *(ushort *)(puVar9 + 0xd0) = *(ushort *)(puVar9 + 0xd0) | 2;
    if (param3 < 0) {
      ppuVar7 = (undefined **)&DAT_80311458;
      param3 = -param3;
    }
    if ((undefined *)(int)(short)param1->animId == ppuVar7[param3]) {
      if (*(float *)(param2 + 0x4c) < param1->animTimer) {
        local_40[0] = 1.0;
      }
      else {
        local_40[0] = *(float *)(param2 + 0x4c) - param1->animTimer;
      }
    }
    else {
      Object_ObjAnimSetMove(0.0,param1,(uint)ppuVar7[param3],0);
      local_40[0] = *(float *)(param2 + 0x4c);
      *(ushort *)(puVar9 + 0xd0) = *(ushort *)(puVar9 + 0xd0) | 0x20;
    }
    if ((0.1 < param1->animTimer) && ((*(ushort *)(puVar9 + 0xd0) & 0x20) != 0)) {
      uStack_34 = randInt(-0x32,0x32);
      uStack_34 = uStack_34 ^ 0x80000000;
      local_38 = 0x43300000;
      audioTryStartSfx((int *)param1,8,0x2c,0x7f,"pushpull.c",0x29e);
      *(ushort *)(puVar9 + 0xd0) = *(ushort *)(puVar9 + 0xd0) & 0xffdf;
    }
    (param1->pos).scale = *(float *)(param2 + 4);
    FUN_801d6158((double)local_40[0],(int)param1,puVar9,&local_44);
    if ((*(ushort *)(puVar9 + 0xd0) & 0x80) != 0) {
      local_44 = 0.0;
    }
    (param1->pos).scale = param1->data->scale;
    local_9c.rotation.x = *param2;
    local_9c.rotation.y = 0;
    local_9c.rotation.z = 0;
    local_9c.scale = 1.0;
    local_9c.pos.x = 0.0;
    local_9c.pos.y = 0.0;
    local_9c.pos.z = 0.0;
    mtxSetFromObjPos(&MStack_84,&local_9c);
    multVectorByMatrix(0.0,0.0,(double)local_44,&MStack_84,&(param1->vel).x,local_40,
                       &(param1->vel).z);
    objMove((double)(param1->vel).x,0.0,(double)(param1->vel).z,param1);
    *param4 = *(float *)(param2 + 6) - (param1->pos).pos.x;
    *param5 = *(float *)(param2 + 10) - (param1->pos).pos.z;
    FUN_8006b3d4(&param1->pos);
    for (iVar8 = 0; iVar8 < (char)puVar9[0x84]; iVar8 = iVar8 + 1) {
      multVectorByObjMtx((double)*(float *)(puVar9 + iVar8 * 0xc + 0x18),
                         (double)*(float *)(puVar9 + iVar8 * 0xc + 0x1c),
                         (double)*(float *)(puVar9 + iVar8 * 0xc + 0x20),local_cc + iVar8 * 3,
                         local_cc + iVar8 * 3 + 1,local_cc + iVar8 * 3 + 2,param1);
      local_fc[iVar8 * 3] = (param1->pos).pos.x - local_cc[iVar8 * 3];
      local_fc[iVar8 * 3 + 1] = (param1->pos).pos.y - local_cc[iVar8 * 3 + 1];
      local_fc[iVar8 * 3 + 2] = (param1->pos).pos.z - local_cc[iVar8 * 3 + 2];
    }
    FUN_801d64d0(param1,(int)puVar9);
    FUN_8006b3d4(&param1->pos);
    if (((ppuVar7 == (undefined **)&DAT_80311458) && ((*(ushort *)(puVar9 + 0xd0) & 1) != 0)) &&
       (*(ushort *)(puVar9 + 0xd0) = *(ushort *)(puVar9 + 0xd0) & 0xfffe,
       -1 < (short)pOVar6[1].objType)) {
      OVar2 = param1->romdefno;
      if ((OVar2 != 0x411) && ((0x410 < (short)OVar2 || (OVar2 != 0x21e)))) {
        mainSetBits((int)(short)pOVar6[1].objType,0);
      }
    }
  }
  if (((param1->romdefno == VFP_Block2) && (0.0 < *(float *)(puVar9 + 0x14))) &&
     (iVar8 = FUN_801a7998((int)pOVar3), iVar8 != 0x1d7)) {
    pOVar3 = Object_objGetMain();
    objSendMsg((int)pOVar3,0x60004,(uint)param1,1);
  }
  if ((*(ushort *)(puVar9 + 0xd0) & 8) != 0) {
    uVar5 = 2;
  }
  return uVar5;
}


/* Library Function - Single Match
    pushpullObj_func0B
   
   Library: KioskDefault 0 0 */

uint pushpullObj_func0B(int param1,int param2) { //801D6068
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  double dVar5;
  
  iVar4 = *(int *)(param1 + 0xb8);
  fVar1 = *(float *)(param2 + 0xc) - *(float *)(param1 + 0xc);
  fVar2 = *(float *)(param2 + 0x10) - *(float *)(param1 + 0x10);
  fVar3 = *(float *)(param2 + 0x14) - *(float *)(param1 + 0x14);
  dVar5 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
  return ((uint)(byte)((dVar5 < (double)*(float *)(iVar4 + 0xc)) << 3) << 0x1c) >> 0x1f;
}


/* Library Function - Single Match
    pushpullObj_func0C
   
   Library: KioskDefault 0 0 */

void pushpullObj_func0C(int param1,int param2) { //801D610C
  *(uint *)(*(int *)(param1 + 0xb8) + 0x78) =
       *(uint *)(*(int *)(param1 + 0xb8) + 0x78) | 1 << param2;
  return;
}


ushort pushpullObj_func0D(int param1) { //801D6138
  return *(ushort *)(*(int *)(param1 + 0xb8) + 0xd0) & 1;
}

