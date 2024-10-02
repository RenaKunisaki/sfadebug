
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void tesla_initialise(undefined4 param) { //801CDB90
  return;
}


/* @description Called when DLL is unloaded */

void tesla_release(void) { //801CDB94
  return;
}


/* Library Function - Single Match
    dll_EB_func03
   
   Library: KioskDefault 0 0 */

void tesla_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //801CDB98
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)this->state;
  if (obj2 == (ObjInstance *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined *)(puVar1 + 2) = 2;
    *(undefined *)((int)puVar1 + 9) = 0;
    puVar1[4] = 0.0;
    (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].pos.x << 8;
    (this->pos).pos.y =
         (objDef->pos).y -
         (float)((double)CONCAT44(0x43300000,(uint)objDef[1].bound) - 4503599627370496.0);
    Object_objAddObjectType(this,3);
  }
  else {
    (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].pos.x << 8;
  }
  return;
}


/* Library Function - Single Match
    dll_EB_baddieStrikeFn04
   
   Library: KioskDefault 0 0 */

void tesla_baddieStrikeFn04(ObjInstance *this) { //801CDC58
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  DLL_func **ppDVar10;
  ObjInstance *param1;
  uint uVar11;
  ObjInstance **ppOVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ObjInstance *pOVar16;
  ObjDef *pOVar17;
  int **ppiVar18;
  double dVar19;
  int local_6c;
  float local_68 [2];
  undefined4 local_60;
  uint uStack_5c;
  double local_58;
  double local_50;
  undefined4 local_48;
  uint uStack_44;
  double local_40;
  
  _savefpr_29();
  ppiVar18 = (int **)this->state;
  pOVar17 = this->def;
  pOVar16 = (ObjInstance *)0x0;
  if (*ppiVar18 == (int *)0x0) {
    ppDVar10 = runlinkDownloadCode(0x2013,1);
    *ppiVar18 = (int *)ppDVar10;
    if (*ppiVar18 == (int *)0x0) goto LAB_801ce6c4;
  }
  if (ppiVar18[1] == (int *)0x0) {
    ppDVar10 = runlinkDownloadCode(0x1035,1);
    ppiVar18[1] = (int *)ppDVar10;
    if (ppiVar18[1] == (int *)0x0) goto LAB_801ce6c4;
  }
  param1 = Object_objGetMain();
  dVar19 = (double)objDistObj2ObjXZ(param1,this);
  bVar1 = *(byte *)(ppiVar18 + 2);
  if (bVar1 == 2) {
    uStack_44 = (uint)*(byte *)&pOVar17[1].objType;
    local_48 = 0x43300000;
    if ((dVar19 < (double)(float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0)) &&
       ((sVar6._0_1_ = pOVar17[1].loadFlags, sVar6._1_1_ = pOVar17[1].mapStates2, sVar6 == -1 ||
        (sVar7._0_1_ = pOVar17[1].loadFlags, sVar7._1_1_ = pOVar17[1].mapStates2,
        uVar11 = mainGetBit((int)sVar7), uVar11 != 0)))) {
      *(undefined *)(ppiVar18 + 2) = 0;
      audioTryStartSfx((int *)this,0x40,0x1e2,0x7f,"tesla.c",0x99);
    }
    goto LAB_801ce6c4;
  }
  if (bVar1 < 2) {
    if (bVar1 == 0) {
      local_40 = (double)CONCAT44(0x43300000,(uint)pOVar17[1].cullDist);
      ppiVar18[4] = (int *)((float)(local_40 - 4503599627370496.0) * timeDelta * 0.01 +
                           (float)ppiVar18[4]);
      (this->pos).pos.y = (float)ppiVar18[4] * timeDelta + (this->pos).pos.y;
      FUN_801ce8e4((int)this,(int)pOVar17);
      uStack_44 = (uint)*(byte *)&pOVar17[1].objType;
      local_48 = 0x43300000;
      if (((double)(float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0) < dVar19) ||
         ((sVar2._0_1_ = pOVar17[1].loadFlags, sVar2._1_1_ = pOVar17[1].mapStates2, sVar2 != -1 &&
          (sVar3._0_1_ = pOVar17[1].loadFlags, sVar3._1_1_ = pOVar17[1].mapStates2,
          uVar11 = mainGetBit((int)sVar3), uVar11 == 0)))) {
        *(undefined *)(ppiVar18 + 2) = 1;
        audioTryStartSfx((int *)this,0x40,0x1e2,0x7f,"tesla.c",0x7a);
      }
      else if ((this->pos).pos.y == (pOVar17->pos).y) {
        *(undefined *)(ppiVar18 + 2) = 3;
        *(undefined2 *)(ppiVar18 + 3) = 0;
        audioTryStartSfx((int *)this,0x40,0x231,0x7f,"tesla.c",0x7f);
      }
    }
    else if (true) {
      uStack_44 = (uint)pOVar17[1].cullDist;
      local_48 = 0x43300000;
      ppiVar18[4] = (int *)-((float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0) *
                             timeDelta * 0.01 - (float)ppiVar18[4]);
      (this->pos).pos.y = (float)ppiVar18[4] * timeDelta + (this->pos).pos.y;
      FUN_801ce8e4((int)this,(int)pOVar17);
      local_40 = (double)CONCAT44(0x43300000,(uint)*(byte *)&pOVar17[1].objType);
      if (((double)(float)(local_40 - 4503599627370496.0) <= dVar19) ||
         ((sVar4._0_1_ = pOVar17[1].loadFlags, sVar4._1_1_ = pOVar17[1].mapStates2, sVar4 != -1 &&
          (sVar5._0_1_ = pOVar17[1].loadFlags, sVar5._1_1_ = pOVar17[1].mapStates2,
          uVar11 = mainGetBit((int)sVar5), uVar11 == 0)))) {
        uStack_44 = (uint)pOVar17[1].bound;
        local_48 = 0x43300000;
        if ((this->pos).pos.y ==
            (pOVar17->pos).y - (float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0))
        {
          *(undefined *)(ppiVar18 + 2) = 2;
          FUN_80068a9c((uint)this,0x40);
        }
      }
      else {
        *(undefined *)(ppiVar18 + 2) = 0;
        audioTryStartSfx((int *)this,0x40,0x1e2,0x7f,"tesla.c",0x8c);
      }
    }
    goto LAB_801ce6c4;
  }
  if (bVar1 == 4) {
    iVar15 = (int)((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(ppiVar18 + 3)) -
                          4503599627370496.0) + timeDelta);
    local_58 = (double)(longlong)iVar15;
    *(short *)(ppiVar18 + 3) = (short)iVar15;
    local_50 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(ppiVar18 + 3));
    if (10.0 < (float)(local_50 - 4503599627370496.0)) {
      uStack_5c = (uint)*(ushort *)(ppiVar18 + 3);
      local_60 = 0x43300000;
      iVar15 = (int)((float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0) - 10.0);
      local_58 = (double)(longlong)iVar15;
      *(short *)(ppiVar18 + 3) = (short)iVar15;
      FUN_80088818((int)param1,(int)this,'\x01',0,0);
      (**(code **)(**ppiVar18 + 4))(this,0,0,1,0xffffffff,0x13,param1);
      audioTryStartSfx((int *)this,0x20,0x1f9,0x7f,"tesla.c",0xf3);
    }
    uStack_5c = (uint)pOVar17[1].allocatedSize;
    local_60 = 0x43300000;
    if ((double)(float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0) < dVar19) {
      *(undefined *)(ppiVar18 + 2) = 3;
    }
    goto LAB_801ce6c4;
  }
  if (3 < bVar1) goto LAB_801ce6c4;
  uStack_44 = (uint)*(ushort *)(ppiVar18 + 3);
  local_48 = 0x43300000;
  iVar15 = (int)((float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0) + timeDelta);
  local_40 = (double)(longlong)iVar15;
  *(short *)(ppiVar18 + 3) = (short)iVar15;
  local_50 = (double)CONCAT44(0x43300000,(uint)pOVar17[1].mapStates1 << 1 ^ 0x80000000);
  local_58 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(ppiVar18 + 3));
  if (120.0 < (float)(local_50 - 4503601774854144.0) - (float)(local_58 - 4503599627370496.0)) {
    local_58 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(ppiVar18 + 3));
    local_50 = (double)CONCAT44(0x43300000,(uint)pOVar17[1].mapStates1 << 1 ^ 0x80000000);
    uStack_44 = (uint)*(byte *)((int)ppiVar18 + 9);
    local_48 = 0x43300000;
    iVar15 = (int)((float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0) + timeDelta)
    ;
    local_40 = (double)(longlong)iVar15;
    *(char *)((int)ppiVar18 + 9) = (char)iVar15;
    uStack_5c = (uint)*(byte *)((int)ppiVar18 + 9);
    local_60 = 0x43300000;
    if ((1.0 - (float)(local_58 - 4503599627370496.0) / (float)(local_50 - 4503601774854144.0)) *
        60.0 <= (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
      *(undefined *)((int)ppiVar18 + 9) = 0;
      (**(code **)(*ppiVar18[1] + 4))(this,0,0,&DAT_00010001,0xffffffff,0);
    }
  }
  uStack_5c = (uint)pOVar17[1].allocatedSize;
  local_60 = 0x43300000;
  if (dVar19 < (double)(float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
    *(undefined2 *)(ppiVar18 + 3) = 0;
    FUN_80088818((int)param1,(int)this,'\x01',0,0);
    *(undefined *)((int)ppiVar18 + 10) = 1;
    *(undefined *)(ppiVar18 + 2) = 4;
    goto LAB_801ce6c4;
  }
  uStack_5c = (uint)*(ushort *)(ppiVar18 + 3);
  local_60 = 0x43300000;
  local_58 = (double)CONCAT44(0x43300000,(uint)pOVar17[1].mapStates1 << 1 ^ 0x80000000);
  if ((float)(local_58 - 4503601774854144.0) <
      (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
    uStack_5c = (uint)*(ushort *)(ppiVar18 + 3);
    local_60 = 0x43300000;
    local_58 = (double)CONCAT44(0x43300000,(uint)pOVar17[1].mapStates1 << 1 ^ 0x80000000);
    iVar15 = (int)((float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0) -
                  (float)(local_58 - 4503601774854144.0));
    local_50 = (double)(longlong)iVar15;
    *(short *)(ppiVar18 + 3) = (short)iVar15;
    *(undefined *)((int)ppiVar18 + 10) = 2;
    audioTryStartSfx((int *)this,0x20,0x1f9,0x7f,"tesla.c",0xb8);
    uStack_44 = (uint)*(byte *)((int)&pOVar17[1].objType + 1);
    local_48 = 0x43300000;
    local_68[0] = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0);
    pOVar16 = getSeqObj(4,this,local_68);
    if ((pOVar16 == (ObjInstance *)0x0) || (dVar19 <= (double)local_68[0])) {
      uStack_5c = (uint)*(byte *)((int)&pOVar17[1].objType + 1);
      local_60 = 0x43300000;
      if (dVar19 < (double)(float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
        FUN_80088818((int)param1,(int)this,'\v',*(undefined *)((int)&pOVar17[1].pos.x + 1),0);
      }
    }
    else {
      uStack_5c = (uint)*(byte *)((int)&pOVar17[1].objType + 1);
      local_60 = 0x43300000;
      if (local_68[0] < (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
        printf("Trying to strike baddie, but it doesn't work! Would someone please fix this.");
        FUN_80088818((int)pOVar16,(int)this,'\x0e',*(undefined *)((int)&pOVar17[1].pos.x + 1),0);
      }
    }
  }
  if (*(char *)((int)ppiVar18 + 10) != '\0') {
    if (pOVar16 == (ObjInstance *)0x0) {
      uStack_5c = (uint)*(byte *)((int)&pOVar17[1].objType + 1);
      local_60 = 0x43300000;
      local_68[0] = (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0);
      pOVar16 = getSeqObj(4,this,local_68);
    }
    *(char *)((int)ppiVar18 + 10) = *(char *)((int)ppiVar18 + 10) + -1;
    if ((pOVar16 == (ObjInstance *)0x0) || (dVar19 <= (double)local_68[0])) {
      uStack_5c = (uint)*(byte *)((int)&pOVar17[1].objType + 1);
      local_60 = 0x43300000;
      if (dVar19 < (double)(float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
        (**(code **)(**ppiVar18 + 4))(this,0,0,1,0xffffffff,0x13,param1);
        (**(code **)(**ppiVar18 + 4))(this,0,0,1,0xffffffff,0x13,param1);
        goto LAB_801ce534;
      }
    }
    if (pOVar16 != (ObjInstance *)0x0) {
      uStack_5c = (uint)*(byte *)((int)&pOVar17[1].objType + 1);
      local_60 = 0x43300000;
      if (local_68[0] < (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0)) {
        (**(code **)(**ppiVar18 + 4))(this,0,0,1,0xffffffff,0x13,pOVar16);
        (**(code **)(**ppiVar18 + 4))(this,0,0,1,0xffffffff,0x13,pOVar16);
        goto LAB_801ce534;
      }
    }
    ppOVar12 = Object_playerGetObject(3,&local_6c);
    for (iVar15 = 0; iVar15 < 2; iVar15 = iVar15 + 1) {
      do {
        iVar13 = randInt(0,local_6c + -1);
        if (this->realType == ppOVar12[iVar13]->realType) break;
        iVar14 = (*(code *)ppOVar12[iVar13]->dll->ptrs2->setScale)(ppOVar12[iVar13]);
      } while (iVar14 == 0);
      (**(code **)(**ppiVar18 + 4))(this,0,0,1,0xffffffff,0x13,ppOVar12[iVar13]);
    }
  }
LAB_801ce534:
  uStack_5c = (uint)*(byte *)&pOVar17[1].objType;
  local_60 = 0x43300000;
  if (((double)(float)((double)CONCAT44(0x43300000,uStack_5c) - 4503599627370496.0) < dVar19) ||
     ((sVar8._0_1_ = pOVar17[1].loadFlags, sVar8._1_1_ = pOVar17[1].mapStates2, sVar8 != -1 &&
      (sVar9._0_1_ = pOVar17[1].loadFlags, sVar9._1_1_ = pOVar17[1].mapStates2,
      uVar11 = mainGetBit((int)sVar9), uVar11 == 0)))) {
    *(undefined *)(ppiVar18 + 2) = 1;
    audioTryStartSfx((int *)this,0x40,0x1e2,0x7f,"tesla.c",0xe8);
  }
LAB_801ce6c4:
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void tesla_hitDetect(ObjInstance *this) { //801CE6E0
  return;
}


/* Library Function - Single Match
    dll_EB_func06
   
   Library: KioskDefault 0 0 */

void tesla_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //801CE6E4
  bool bVar1;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  ObjDef *pOVar3;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  pOVar3 = this->def;
  puVar2 = this->state;
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if (bVar1) {
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)&pOVar3[1].objType) -
                                  4503599627370496.0),32.0,param2_00,param3_00,0,0xc0,0x20);
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,
                                                    (uint)*(byte *)((int)&pOVar3[1].objType + 1)) -
                                  4503599627370496.0),32.0,param2_00,param3_00,0xc0,0,0x20);
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)pOVar3[1].allocatedSize) -
                                  4503599627370496.0),32.0,param2_00,param3_00,0xc0,0xc0,0x20);
    }
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  else if ((shouldRender) && (puVar2[8] != '\x02')) {
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_EB_func07
   
   Library: KioskDefault 0 0 */

void tesla_free(ObjInstance *this,int param2) { //801CE864
  LoadedDll **ppLVar1;
  
  ppLVar1 = (LoadedDll **)this->state;
  if (*ppLVar1 != (LoadedDll *)0x0) {
    DLL_free(*ppLVar1);
  }
  if (ppLVar1[1] != (LoadedDll *)0x0) {
    DLL_free(ppLVar1[1]);
  }
  ppLVar1[1] = (LoadedDll *)0x0;
  *ppLVar1 = (LoadedDll *)0x0;
  Object_removePlayerObj(this,3);
  return;
}


undefined4 tesla_func08(ObjInstance *this) { //801CE8D4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int tesla_getExtraSize(void) { //801CE8DC
  return 0x14;
}


/* Library Function - Single Match
    dll_EB_func0A
   
   Library: KioskDefault 0 0 */

void tesla_setScale(ObjInstance *this,float scale) { //801CE97C
  countLeadingZeros(3 - (uint)(byte)this->state[8]);
  return;
}

