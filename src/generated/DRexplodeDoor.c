
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRexplodeDoor_initialise(undefined4 param) { //802B5E34
  return;
}


/* @description Called when DLL is unloaded */

void DRexplodeDoor_release(void) { //802B5E38
  return;
}


/* Library Function - Single Match
    dll_2B2_func03
   
   Library: KioskDefault 0 0 */

void DRexplodeDoor_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //802B5E3C
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  
  FUN_80088d3c((int)this);
  if (*(char *)((int)&objDef[1].objType + 1) != '\0') {
    (this->pos).flags = (this->pos).flags | Invisible;
  }
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar6 = mainGetBit((int)sVar1);
  if (uVar6 != 0) {
    (this->pos).flags = (this->pos).flags | Invisible;
    this->flags_0xb0 = this->flags_0xb0 | DontMove;
    objFreeFn_80083b54(this);
  }
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  if (sVar2 != 0) {
    sVar3._0_1_ = objDef[1].allocatedSize;
    sVar3._1_1_ = objDef[1].mapStates1;
    if (sVar3 < 0) {
      sVar5._0_1_ = objDef[1].allocatedSize;
      sVar5._1_1_ = objDef[1].mapStates1;
      uVar6 = -(int)sVar5;
    }
    else {
      sVar4._0_1_ = objDef[1].allocatedSize;
      sVar4._1_1_ = objDef[1].mapStates1;
      uVar6 = (uint)sVar4;
    }
    objHitFn_80089354(this,(short)(int)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                                       4503601774854144.0));
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  return;
}


/* Library Function - Single Match
    dll_2B2_func04
   
   Library: KioskDefault 0 0 */

void DRexplodeDoor_update(ObjInstance *this) { //802B5F24
  short sVar1;
  uint uVar2;
  LoadedDll *dll;
  ObjDef *pOVar3;
  undefined *local_1c;
  undefined2 local_18;
  
  pOVar3 = this->def;
  local_1c = &DAT_000a0014;
  local_18 = 0;
  if ((*(char *)((int)&pOVar3[1].objType + 1) == '\x02') &&
     (sVar1._0_1_ = pOVar3[1].bound, sVar1._1_1_ = pOVar3[1].cullDist,
     uVar2 = mainGetBit((int)sVar1), uVar2 != 0)) {
    dll = (LoadedDll *)runlinkDownloadCode(0x1003,1);
    (**(code **)(dll->id + 4))(this,0x10,0,2,0xffffffff,&local_1c);
    DLL_free(dll);
    audioTryStartSfx((int *)this,1,0xb8,0x7f,"DRexplodeDoor.c",0x72);
    objFreeFn_80083b54(this);
  }
  return;
}


/* Library Function - Single Match
    dll_2B2_func05
   
   Library: KioskDefault 0 0 */

void DRexplodeDoor_hitDetect(ObjInstance *this) { //802B5FE8
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  LoadedDll *dll;
  ObjDef *pOVar7;
  undefined auStack_3c [8];
  float local_34;
  undefined *local_24;
  undefined2 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  pOVar7 = this->def;
  local_24 = &DAT_000a000f;
  local_20 = 0;
  iVar5 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,&uStack_1c);
  if ((iVar5 == 5) ||
     (sVar1._0_1_ = pOVar7[1].bound, sVar1._1_1_ = pOVar7[1].cullDist,
     uVar6 = mainGetBit((int)sVar1), uVar6 != 0)) {
    memclr(auStack_3c,0x18);
    sVar2._0_1_ = pOVar7[1].allocatedSize;
    sVar2._1_1_ = pOVar7[1].mapStates1;
    uStack_14 = (int)sVar2 ^ 0x80000000;
    local_18 = 0x43300000;
    local_34 = (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) * 0.03125;
    dll = (LoadedDll *)runlinkDownloadCode(0x104c,1);
    sVar3._0_1_ = pOVar7[1].loadFlags;
    sVar3._1_1_ = pOVar7[1].mapStates2;
    (**(code **)(dll->id + 4))(this,(int)sVar3,auStack_3c,2,0xffffffff,&local_24);
    DLL_free(dll);
    audioTryStartSfx((int *)this,1,0x28,0x7f,"DRexplodeDoor.c",0x94);
    this->flags_0xb0 = this->flags_0xb0 | DontMove;
    (this->pos).flags = (this->pos).flags | Invisible;
    sVar4._0_1_ = pOVar7[1].bound;
    sVar4._1_1_ = pOVar7[1].cullDist;
    mainSetBits((int)sVar4,1);
    FUN_80088da4((int)this);
  }
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DRexplodeDoor_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802B611C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DRexplodeDoor_free(ObjInstance *this,int param2) { //802B6178
  return;
}


undefined4 DRexplodeDoor_func08(ObjInstance *this) { //802B617C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRexplodeDoor_getExtraSize(void) { //802B6184
  return 4;
}

