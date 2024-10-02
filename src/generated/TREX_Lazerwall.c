
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void TREX_Lazerwall_initialise(undefined4 param) { //802AF85C
  return;
}


/* @description Called when DLL is unloaded */

void TREX_Lazerwall_release(void) { //802AF860
  return;
}


/* Library Function - Single Match
    dll_29B_func03
   
   Library: KioskDefault 0 0 */

void TREX_Lazerwall_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802AF864
  undefined *puVar1;
  
  puVar1 = this->state;
  DAT_8039a148 = runlinkDownloadCode(0x1042,1);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *(float *)(puVar1 + 8) = 0.0;
  return;
}


/* Library Function - Single Match
    dll_29B_func04
   
   Library: KioskDefault 0 0 */

void TREX_Lazerwall_update(ObjInstance *this) { //802AF8C4
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ObjDef *pOVar10;
  byte *pbVar11;
  undefined4 local_24;
  undefined4 local_20;
  uint uStack_1c;
  
  pOVar10 = this->def;
  pbVar11 = this->state;
  pbVar11[1] = *pbVar11;
  *pbVar11 = *pbVar11 & 0xfc;
  sVar1._0_1_ = pOVar10[1].allocatedSize;
  sVar1._1_1_ = pOVar10[1].mapStates1;
  uVar7 = mainGetBit((int)sVar1);
  sVar2._0_1_ = pOVar10[1].loadFlags;
  sVar2._1_1_ = pOVar10[1].mapStates2;
  if ((short)uVar7 < sVar2) {
    *pbVar11 = *pbVar11 & 0xfb;
    sVar3._0_1_ = pOVar10[1].bound;
    sVar3._1_1_ = pOVar10[1].cullDist;
    uVar8 = mainGetBit((int)sVar3);
    if (uVar8 == 0) {
      return;
    }
  }
  else {
    *pbVar11 = *pbVar11 | 4;
  }
  (this->pos).rotation.z = (this->pos).rotation.z + 0x38e;
  if (0xe < (short)uVar7) {
    if (*(float *)(pbVar11 + 4) <= 0.0) {
      sVar4._0_1_ = pOVar10[1].bound;
      sVar4._1_1_ = pOVar10[1].cullDist;
      mainSetBits((int)sVar4,1);
      *pbVar11 = *pbVar11 | 9;
    }
    *(float *)(pbVar11 + 4) = 120.0;
  }
  if ((0.0 < *(float *)(pbVar11 + 4)) &&
     (*(float *)(pbVar11 + 4) = *(float *)(pbVar11 + 4) - timeDelta, *(float *)(pbVar11 + 4) <= 0.0)
     ) {
    sVar5._0_1_ = pOVar10[1].bound;
    sVar5._1_1_ = pOVar10[1].cullDist;
    mainSetBits((int)sVar5,0);
    *pbVar11 = *pbVar11 & 0xf7;
  }
  if ((*pbVar11 & 1) != 0) {
    if (DAT_8039a148 != (int *)0x0) {
      (**(code **)(*DAT_8039a148 + 4))(this,0,0,4,0xffffffff,0);
      (**(code **)(*DAT_8039a148 + 4))(this,0,0,4,0xffffffff,0);
      (**(code **)(*DAT_8039a148 + 4))(this,0,0,4,0xffffffff,0);
      (**(code **)(*DAT_8039a148 + 4))(this,0,0,4,0xffffffff,0);
    }
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x47e,0,2,0xffffffff,0);
    for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
      local_24 = 2;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x48c,0,2,0xffffffff,&local_24);
    }
    uStack_1c = randInt(1,0x3c);
    uStack_1c = uStack_1c ^ 0x80000000;
    local_20 = 0x43300000;
    *(float *)(pbVar11 + 8) = (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0);
  }
  if ((*pbVar11 & 4) != 0) {
    local_24 = 0;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x48c,0,2,0xffffffff,&local_24);
    local_24 = 1;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x48c,0,2,0xffffffff,&local_24);
    if ((pbVar11[1] & 4) == 0) {
      sVar6._0_1_ = pOVar10[1].loadFlags;
      sVar6._1_1_ = pOVar10[1].mapStates2;
      uStack_1c = (int)sVar6 ^ 0x80000000;
      local_20 = 0x43300000;
      audioTryStartSfx((int *)this,0x20,0x1eb,0x7f,"TREX_Lazerwall.c",0xc3);
    }
  }
  if ((*pbVar11 & 8) != 0) {
    local_24 = 0;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x48c,0,2,0xffffffff,&local_24);
    local_24 = 2;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x48c,0,2,0xffffffff,&local_24);
  }
  if (((*pbVar11 & 8) == 0) && ((pbVar11[1] & 8) != 0)) {
    audioTryStartSfx((int *)this,2,0x1ea,0x7f,"TREX_Lazerwall.c",0xd0);
  }
  if ((0.0 < *(float *)(pbVar11 + 8)) &&
     (*(float *)(pbVar11 + 8) = *(float *)(pbVar11 + 8) - timeDelta, *(float *)(pbVar11 + 8) <= 0.0)
     ) {
    audioTryStartSfx((int *)this,0x20,0x1ec,0x7f,"TREX_Lazerwall.c",0xd7);
    *(float *)(pbVar11 + 8) = 0.0;
  }
  return;
}


/* @description Override hit detection */

void TREX_Lazerwall_hitDetect(ObjInstance *this) { //802AFD30
  return;
}


/* @description Override render */

void TREX_Lazerwall_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802AFD34
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (bVar1 = checkSomeDebugFlags_8017c4f8(), bVar1)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_29B_func07
   
   Library: KioskDefault 0 0 */

void TREX_Lazerwall_free(ObjInstance *this,int param2) { //802AFD9C
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_8039a148);
  DAT_8039a148 = (LoadedDll *)0x0;
  return;
}


undefined4 TREX_Lazerwall_func08(ObjInstance *this) { //802AFDE4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int TREX_Lazerwall_getExtraSize(void) { //802AFDEC
  return 0xc;
}

