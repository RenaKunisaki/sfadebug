
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void collectable_initialise(undefined4 param) { //801D2998
  return;
}


/* @description Called when DLL is unloaded */

void collectable_release(void) { //801D299C
  return;
}


/* Library Function - Single Match
    dll_F6_func03
   
   Library: KioskDefault 0 0 */

void collectable_func03(ObjInstance *param1,int param2,int param3) { //801D29A0
  short sVar1;
  uint uVar2;
  AButtonInteraction *pAVar3;
  int iVar4;
  ObjSeqCmd *pOVar5;
  undefined *param1_00;
  
  param1_00 = param1->state;
  Object_objAddObjectType(param1,5);
  objAllocMsgQueue(param1,2);
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0x1b) << 8;
  (param1->pos).rotation.y = (ushort)*(byte *)(param2 + 0x22) << 8;
  (param1->pos).rotation.z = (ushort)*(byte *)(param2 + 0x23) << 8;
  (param1->pos).scale = param1->data->scale;
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801d3248;
  param1->curModel = *(byte *)(param2 + 0x26);
  param1->flags_0xb0 = param1->flags_0xb0 | DontMove;
  memclr(param1_00,0x48);
  param1_00[0xc] = *(undefined *)(param2 + 0x19);
  param1_00[0xd] = *(undefined *)(param2 + 0x1a);
  param1_00[0xf] = 0;
  *(undefined4 *)(param1_00 + 0x18) = 0xfffffffe;
  param1_00[0x1d] = 0;
  param1_00[0x1c] = 0x3c;
  *(undefined2 *)(param1_00 + 0x14) = *(undefined2 *)(param2 + 0x24);
  *(undefined4 *)(param1_00 + 0x20) = *(undefined4 *)(param2 + 0x14);
  *(float *)(param1_00 + 0x24) = (param1->pos).pos.x;
  *(float *)(param1_00 + 0x28) = (param1->pos).pos.y;
  *(float *)(param1_00 + 0x2c) = (param1->pos).pos.z;
  param1_00[0x36] = *(undefined *)(param2 + 0x27);
  if (*(short *)(param1_00 + 0x14) != -1) {
    uVar2 = mainGetBit((int)*(short *)(param1_00 + 0x14));
    uVar2 = countLeadingZeros(uVar2);
    param1_00[0x1e] = (char)(uVar2 >> 5);
  }
  *(undefined2 *)(param1_00 + 0x10) = *(undefined2 *)(param2 + 0x1c);
  if (*(short *)(param1_00 + 0x10) == -1) {
    param1->field76_0xf4 = 0;
  }
  else {
    uVar2 = mainGetBit((int)*(short *)(param1_00 + 0x10));
    param1->field76_0xf4 = uVar2;
  }
  if (param1->field76_0xf4 == 0) {
    pOVar5 = param1->data->offset_0x18;
    if ((pOVar5 != (ObjSeqCmd *)0x0) &&
       (sVar1._0_1_ = pOVar5->param1, sVar1._1_1_ = pOVar5->param2, sVar1 == 0x40)) {
      if (param3 == 0) {
        audioTryStartSfx((int *)param1,0x81,0x15f,0x7f,"collectable.c",0xc6);
      }
      for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x42,0,4,0xffffffff,0);
      }
      (param1->vel).y = -1.2;
    }
    if (pOVar5 == (ObjSeqCmd *)0x0) {
      *(float *)(param1_00 + 4) = 15.0;
    }
    else {
      *(float *)(param1_00 + 4) =
           (float)((double)CONCAT44(0x43300000,(int)(char)pOVar5[2].flags ^ 0x80000000) -
                  4503601774854144.0);
    }
    pAVar3 = param1->data->aButtonInteraction;
    if (pAVar3 != (AButtonInteraction *)0x0) {
      *(float *)(param1_00 + 4) =
           (float)((double)CONCAT44(0x43300000,(uint)(byte)pAVar3->field_0xc << 2 ^ 0x80000000) -
                  4503601774854144.0);
    }
    if ((param1->shadow != (Shadow *)0x0) &&
       ((param1->shadow->flags = 0x810, param1->romdefno == 0x49 ||
        (param1->romdefno == WM_PureMagi)))) {
      param1->shadow->flags = param1->shadow->flags | 0x400;
    }
    if (((param1->data->flags & 0x10000) != 0) && (param1_00[0x36] != '\0')) {
      param1_00[0x38] = *(undefined *)(param2 + 0x28);
      param1_00[0x39] = *(undefined *)(param2 + 0x29);
      param1_00[0x3a] = *(undefined *)(param2 + 0x2a);
    }
    return;
  }
  return;
}


/* Library Function - Single Match
    dll_F6_func04
   
   Library: KioskDefault 0 0 */

void collectable_func04(ObjInstance *param1) { //801D2C88
  ObjDefEnum OVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  ObjInstance *param2;
  ObjSeqCmd *pOVar6;
  ObjDef *pOVar7;
  float *pfVar8;
  double dVar9;
  float local_34;
  undefined *local_30;
  uint uStack_2c;
  longlong local_28;
  
  pfVar8 = (float *)param1->state;
  pOVar7 = param1->def;
  pOVar6 = param1->data->offset_0x18;
  local_34 = 1.0;
  if (pfVar8[2] != 0.0) {
    pfVar8[2] = pfVar8[2] - timeDelta;
    if (0.0 < pfVar8[2]) {
      return;
    }
    if (pOVar7->id == -1) {
      Object_objFreeObject(param1);
    }
    else {
      objFreeFn_80083b54(param1);
    }
    pfVar8[2] = 0.0;
    return;
  }
                    /* {@symbol 800d24d8} */
  (**(code **)(*(int *)pDll_newfog + 0x18))(&local_34);
  param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
  if (*(short *)(pfVar8 + 5) != -1) {
    uVar4 = mainGetBit((int)*(short *)(pfVar8 + 5));
    uVar4 = countLeadingZeros(uVar4);
    *(char *)((int)pfVar8 + 0x1e) = (char)(uVar4 >> 5);
  }
  if (*(char *)((int)pfVar8 + 0x1e) != '\0') {
    return;
  }
  if (*(char *)((int)pfVar8 + 0xf) != '\0') {
    return;
  }
  if (param1->flags_0xf8 != 0) {
    local_28 = (longlong)(int)(timeDelta * 3.0);
    param1->flags_0xf8 = param1->flags_0xf8 - (int)(short)(int)(timeDelta * 3.0);
    if ((int)param1->flags_0xf8 < 1) {
      if (pOVar7->id == -1) {
        Object_objFreeObject(param1);
      }
      else {
        objFreeFn_80083b54(param1);
      }
    }
  }
  *(u8 *)(pfVar8 + 7) = *(char *)(pfVar8 + 7) - framesThisStep;
  if (*(char *)(pfVar8 + 7) < '\0') {
    *(undefined *)(pfVar8 + 7) = 0;
  }
  while (iVar5 = FUN_80091100((int)param1,(uint *)&local_30,&uStack_2c,(uint *)0x0), iVar5 != 0) {
    if (local_30 == &DAT_0007000b) {
      pfVar8[2] = 180.0;
      FUN_801d38d8(param1);
    }
  }
  if (((param1->romdefno == DIMAlpineRo_0319) && (*(short *)(pfVar8 + 0xf) != 0)) &&
     (*(ushort *)(pfVar8 + 0xf) = *(short *)(pfVar8 + 0xf) - (ushort)framesThisStep,
     *(short *)(pfVar8 + 0xf) < 1)) {
    *(undefined2 *)(pfVar8 + 0xf) = 0;
    param1->newOpacity = 0xff;
    param1->field76_0xf4 = 0;
  }
  if (((param1->pos).flags & Invisible) != 0) {
    return;
  }
  if (param1->field76_0xf4 != 0) {
    if (param1->hitstate != (HitState *)0x0) {
      param1->hitstate->flags = param1->hitstate->flags | 0x100;
    }
    if (*(short *)(pfVar8 + 4) == -1) {
      return;
    }
    uVar4 = mainGetBit((int)*(short *)(pfVar8 + 4));
    if (uVar4 != 0) {
      return;
    }
    param1->field76_0xf4 = 0;
    return;
  }
  param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
  FUN_801d32e0((int *)param1);
  if (*(char *)((int)pfVar8 + 0x1d) != '\0') {
    FUN_801d36bc(param1);
  }
  param2 = Object_objGetMain();
  if (param2 == (ObjInstance *)0x0) {
    return;
  }
  if ((*(byte *)((int)pfVar8 + 0x37) & 1) != 0) {
    return;
  }
  if (param1->data->offset_0x18 == (ObjSeqCmd *)0x0) {
    return;
  }
  dVar9 = (double)objDistObj2ObjXZ(param1,param2);
  if (((double)pfVar8[1] <= dVar9) || (*(char *)(pfVar8 + 7) != '\0')) goto LAB_801d3114;
  OVar1 = param1->romdefno;
  if (OVar1 != 0x2da) {
    if ((short)OVar1 < 0x2da) {
      if (OVar1 != 0x49) {
        if ((short)OVar1 < 0x49) {
          if (OVar1 == EnergyEgg) {
            *(byte *)((int)pfVar8 + 0x37) = *(byte *)((int)pfVar8 + 0x37) | 1;
                    /* {@symbol 800dc2d8} */
            (**(code **)(*(int *)pDll_modgfx + 0x18))(param1);
            for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x549,0,1,0xffffffff,0);
            }
            uVar4 = mainGetBit(0x90e);
            if (uVar4 == 0) {
              sVar2._0_1_ = pOVar6[1].param1;
              sVar2._1_1_ = pOVar6[1].param2;
                    /* {@symbol 800d1668} */
              (**(code **)(*(int *)pDll_checkpoint + 0x7c))((int)sVar2,0,0);
              *(undefined2 *)(pfVar8 + 0x10) = 0xffff;
              *(undefined2 *)((int)pfVar8 + 0x42) = 0;
              pfVar8[0x11] = 1.0;
              objSendMsg((int)param2,0x7000a,(uint)param1,(uint)(pfVar8 + 0x10));
              mainSetBits(0x90e,1);
            }
            else {
              pfVar8[2] = 180.0;
              FUN_801d38d8(param1);
            }
            goto LAB_801d3114;
          }
        }
        else if (OVar1 == WM_PureMagi) goto LAB_801d30a0;
LAB_801d30b8:
        if ((param1->flags_0xaf & CanPressAToTalk) != 0) {
          sVar3._0_1_ = pOVar6[1].param1;
          sVar3._1_1_ = pOVar6[1].param2;
                    /* {@symbol 800d1668} */
          (**(code **)(*(int *)pDll_checkpoint + 0x7c))((int)sVar3,0,0);
          *(undefined2 *)(pfVar8 + 0x10) = 0xffff;
          *(undefined2 *)((int)pfVar8 + 0x42) = 0;
          pfVar8[0x11] = 1.0;
          objSendMsg((int)param2,0x7000a,(uint)param1,(uint)(pfVar8 + 0x10));
        }
        goto LAB_801d3114;
      }
    }
    else if ((OVar1 != Apple) && ((0x3cc < (short)OVar1 || (OVar1 != DIMAlpineRo_0319))))
    goto LAB_801d30b8;
  }
LAB_801d30a0:
  *(byte *)((int)pfVar8 + 0x37) = *(byte *)((int)pfVar8 + 0x37) | 1;
  FUN_801d38d8(param1);
LAB_801d3114:
  *pfVar8 = (float)dVar9;
  return;
}


void collectable_func05(void) { //801D3130
  return;
}


/* Library Function - Single Match
    dll_F6_func06
   
   Library: KioskDefault 0 0 */

void collectable_func06(ObjInstance *param1,Gfx **param2,undefined4 *param3,undefined4 *param4,
                        undefined4 *param5,char param6) { //801D3134
  bool bVar1;
  undefined *puVar2;
  
  puVar2 = param1->state;
  if ((param6 != '\0') && (*(float *)(puVar2 + 8) == 0.0)) {
    if (param1->field76_0xf4 == 0) {
      bVar1 = checkSomeDebugFlags_8017c4f8();
      if ((bVar1) || (puVar2[0x1e] == '\0')) {
        if (((param1->data->flags & 0x10000) != 0) && (puVar2[0x36] != '\0')) {
          FUN_80096afc((ushort)(byte)puVar2[0x38],(ushort)(byte)puVar2[0x39],
                       (ushort)(byte)puVar2[0x3a]);
        }
        objRenderCurrentModel(param1,param2,param3,param4,param5);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_F6_func07
   
   Library: KioskDefault 0 0 */

void collectable_func07(ObjInstance *param1) { //801D31FC
  Object_removePlayerObj(param1,5);
  return;
}


undefined4 collectable_func08(void) { //801D3238
  return 0x13;
}


undefined4 collectable_func09(void) { //801D3240
  return 0x48;
}


undefined4 collectable_func0A(int param1) { //801D3B90
  return *(undefined4 *)(param1 + 0xf4);
}


void collectable_func0B(int param1,undefined param2) { //801D3B98
  *(undefined *)(*(int *)(param1 + 0xb8) + 0xf) = param2;
  return;
}


/* Library Function - Single Match
    dll_F6_func0C
   
   Library: KioskDefault 0 0 */

undefined4 collectable_func0C(int param1) { //801D3BB4
  ObjDefEnum OVar1;
  int iVar2;
  
  iVar2 = *(int *)(param1 + 0xb8);
  if (*(int *)(iVar2 + 0x18) == -2) {
    OVar1 = FUN_800918d0((double)*(float *)(param1 + 0x18),(double)*(float *)(param1 + 0x1c),
                         (double)*(float *)(param1 + 0x20));
    *(uint *)(iVar2 + 0x18) = (uint)OVar1;
  }
  return *(undefined4 *)(iVar2 + 0x18);
}


void collectable_func0E(int param1,undefined param2) { //801D3C08
  *(undefined *)(*(int *)(param1 + 0xb8) + 0x1e) = param2;
  return;
}


undefined collectable_func0F(int param1) { //801D3C24
  return *(undefined *)(*(int *)(param1 + 0xb8) + 0x1e);
}


/* Library Function - Single Match
    dll_F6_func0D
   
   Library: KioskDefault 0 0 */

void collectable_func0D(double param1,double param2,double param3,int param4) { //801D3C40
  *(undefined *)(*(int *)(param4 + 0xb8) + 0x1d) = 8;
  *(float *)(param4 + 0x24) = (float)param1;
  *(float *)(param4 + 0x28) = (float)param2;
  *(float *)(param4 + 0x2c) = (float)param3;
  return;
}


/* Library Function - Single Match
    dll_F6_func10
   
   Library: KioskDefault 0 0 */

void collectable_func10(double param1,double param2,double param3,int param4) { //801D3C6C
  int iVar1;
  
  iVar1 = *(int *)(param4 + 0xb8);
  if (*(int *)(param4 + 0x4c) != 0) {
    *(float *)(param4 + 0xc) = (float)param1;
    *(float *)(iVar1 + 0x24) = (float)param1;
    *(float *)(param4 + 0x10) = (float)param2;
    *(float *)(iVar1 + 0x28) = (float)param2;
    *(float *)(param4 + 0x14) = (float)param3;
    *(float *)(iVar1 + 0x2c) = (float)param3;
    objRomDefMove_800af9d8
              ((double)*(float *)(param4 + 0xc),(double)*(float *)(param4 + 0x10),
               (double)*(float *)(param4 + 0x14),*(ObjDef **)(param4 + 0x4c),
               (short)*(char *)(param4 + 0xac));
  }
  return;
}

