
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBshooter_initialise(undefined4 param) { //8029D358
  return;
}


/* @description Called when DLL is unloaded */

void DBshooter_release(void) { //8029D35C
  return;
}


/* Library Function - Single Match
    dll_281_func03
   
   Library: KioskDefault 0 0 */

void DBshooter_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8029D360
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined uVar5;
  undefined4 uVar4;
  int iVar6;
  undefined *puVar7;
  
  puVar7 = this->state;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar3 = mainGetBit((int)sVar1);
  if (uVar3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
  puVar7[0x1c] = uVar5;
  puVar7[0x1e] = *(undefined *)((int)&objDef[1].objType + 1);
  if (6 < (byte)puVar7[0x1e]) {
    puVar7[0x1e] = 6;
  }
  sVar2._0_1_ = objDef[1].loadFlags;
  sVar2._1_1_ = objDef[1].mapStates2;
  *(float *)(puVar7 + 0x14) =
       (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0) / 100.0;
  if (obj2 == (ObjInstance *)0x0) {
    for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
      uVar4 = FUN_8029dbc4((int)this);
      *(undefined4 *)(puVar7 + iVar6 * 4) = uVar4;
    }
  }
  this->hitstate->flags = this->hitstate->flags | 1;
  Object_ObjAnimSetMove(0.0,this,0,0);
  Object_objAddObjectType(this,0x2b);
  puVar7[0x1d] = 0;
  return;
}


/* Library Function - Single Match
    dll_281_func04
   
   Library: KioskDefault 0 0 */

void DBshooter_update(ObjInstance *this) { //8029D464
  undefined2 uVar1;
  short sVar2;
  ObjInstance *pOVar3;
  bool bVar5;
  int iVar4;
  ObjDef *pOVar6;
  int iVar7;
  undefined *puVar8;
  
  pOVar3 = Object_objGetMain();
  pOVar6 = this->def;
  puVar8 = this->state;
  if (puVar8[0x1c] == '\x01') {
    *(uint *)(puVar8 + 0x18) = *(int *)(puVar8 + 0x18) - (uint)framesThisStep;
    if (*(int *)(puVar8 + 0x18) < 0) {
      puVar8[0x1c] = 0;
      puVar8[0x20] = puVar8[0x20] & 0xbf | 0x40;
      puVar8[0x20] = puVar8[0x20] & 0x7f;
      for (iVar7 = 0; iVar7 < (int)((byte)puVar8[0x1e] - 1); iVar7 = iVar7 + 1) {
        FUN_8029dcd4((int)this,iVar7 + 1,8);
      }
    }
  }
  else if ((puVar8[0x1c] == '\0') && (true)) {
    iVar7 = randInt(0,0x40);
    if (iVar7 == 0) {
      audioTryStartSfx((int *)this,0x40,0x1f8,0x7f,(char *)&PTR_DAT_80321ee8,0x97);
    }
    if ((puVar8[0x1d] & 1) != 0) {
      puVar8[0x1f] = 1;
      puVar8[0x20] = puVar8[0x20] & 0xbf | 0x40;
      puVar8[0x20] = puVar8[0x20] & 0x7f | 0x80;
      for (iVar7 = 0; iVar7 < (int)((byte)puVar8[0x1e] - 1); iVar7 = iVar7 + 1) {
        FUN_8029dcd4((int)this,iVar7 + 1,6);
      }
      bVar5 = FUN_8029da60((double)*(float *)(puVar8 + 0x14),(short *)this,(int)pOVar3);
      if (bVar5) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3c7,0,2,0xffffffff,0);
        uVar1._0_1_ = pOVar6[1].allocatedSize;
        uVar1._1_1_ = pOVar6[1].mapStates1;
        FUN_8029de24((int)this,0x25d,uVar1);
        audioTryStartSfx((int *)this,0x20,0x215,0x7f,(char *)&PTR_DAT_80321ee8,0xa3);
      }
      puVar8[0x1d] = puVar8[0x1d] & 0xfe;
      puVar8[0x1c] = 1;
      sVar2._0_1_ = pOVar6[1].allocatedSize;
      sVar2._1_1_ = pOVar6[1].mapStates1;
      *(int *)(puVar8 + 0x18) = (int)sVar2;
    }
  }
  if (puVar8[0x1e] != '\0') {
    FUN_8029dc58((int)this,0,3,0);
    if (((byte)puVar8[0x20] >> 6 & 1) == 0) {
      if (-1 < (char)puVar8[0x20]) {
        for (iVar7 = 0; iVar7 < (int)((byte)puVar8[0x1e] - 1); iVar7 = iVar7 + 1) {
          FUN_8029dc58((int)this,iVar7 + 1,5,1);
        }
      }
    }
    else {
      for (iVar7 = 0; iVar7 < (int)((byte)puVar8[0x1e] - 1); iVar7 = iVar7 + 1) {
        iVar4 = FUN_8029dd2c((int)this,iVar7 + 1,8,0,puVar8 + 0x1f);
        if (iVar4 != 0) {
          puVar8[0x20] = puVar8[0x20] & 0xbf;
        }
      }
    }
  }
  objRunAnimation(0.01666666753590107,(double)timeDelta,(int)this,(float *)0x0);
  return;
}


/* Library Function - Single Match
    dll_281_func05
   
   Library: KioskDefault 0 0 */

void DBshooter_hitDetect(ObjInstance *this) { //8029D728
  short sVar1;
  int iVar2;
  N64Button32 NVar3;
  LoadedDll *dll;
  ObjDef *pOVar4;
  undefined *puVar5;
  undefined auStack_3c [8];
  float local_34;
  undefined *local_24;
  undefined2 local_20;
  
  puVar5 = this->state;
  local_24 = &DAT_000a000f;
  local_20 = 0;
  pOVar4 = this->def;
  iVar2 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  NVar3 = n64GetEnabledButtonsPressed(0);
  if ((NVar3 & N64_BUTTON_DOWN) != 0) {
    iVar2 = 0xe;
  }
  if (iVar2 == 0xe) {
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x1ea,0x7f,(char *)&PTR_DAT_80321ee8,(int *)0xe5);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3c7,0,2,0xffffffff,0);
    puVar5[0x1e] = puVar5[0x1e] + -1;
    FUN_8029dcd4((int)this,(uint)(byte)puVar5[0x1e],0);
    if (puVar5[0x1e] == '\0') {
      FUN_80088da4((int)this);
      local_34 = 2.0;
      dll = (LoadedDll *)runlinkDownloadCode(0x104c,1);
      (**(code **)(dll->id + 4))(this,0,auStack_3c,2,0xffffffff,&local_24);
      DLL_free(dll);
      FUN_8029de24((int)this,0x25e,200);
      if (*(int *)(puVar5 + 0x10) != 0) {
        Object_objFreeObject(*(ObjInstance **)(puVar5 + 0x10));
        *(undefined4 *)(puVar5 + 0x10) = 0;
      }
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x28,0x7f,(char *)&PTR_DAT_80321ee8,(int *)0xf8)
      ;
      puVar5[0x1c] = 2;
      sVar1._0_1_ = pOVar4[1].bound;
      sVar1._1_1_ = pOVar4[1].cullDist;
      mainSetBits((int)sVar1,1);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_281_func06
   
   Library: KioskDefault 0 0 */

void DBshooter_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8029D8D0
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->state[0x1c] != '\x02')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_281_func07
   
   Library: KioskDefault 0 0 */

void DBshooter_free(ObjInstance *this,int param2) { //8029D944
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  Object_removePlayerObj(this,0x2b);
  if ((param2 == 0) && (*(int *)(puVar2 + 0x10) != 0)) {
    Object_objFreeObject(*(ObjInstance **)(puVar2 + 0x10));
    *(undefined4 *)(puVar2 + 0x10) = 0;
  }
  if (param2 == 0) {
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      (**(code **)(**(int **)(*(int *)(puVar2 + iVar1 * 4) + 0x68) + 0x28))
                (*(undefined4 *)(puVar2 + iVar1 * 4));
    }
  }
  return;
}


undefined4 DBshooter_func08(ObjInstance *this) { //8029D9E4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBshooter_getExtraSize(void) { //8029D9EC
  return 0x24;
}


/* Library Function - Single Match
    dll_281_func0A
   
   Library: KioskDefault 0 0 */

void DBshooter_setScale(ObjInstance *this,float scale) { //8029D9F4
  this->state[0x1d] = this->state[0x1d] | 1;
  return;
}


/* Library Function - Single Match
    dll_281_func0B
   
   Library: KioskDefault 0 0 */

uint DBshooter_func0B(int param1) { //8029DA30
  uint uVar1;
  
  uVar1 = countLeadingZeros(2 - (uint)*(byte *)(*(int *)(param1 + 0xb8) + 0x1c));
  return uVar1 >> 5;
}

