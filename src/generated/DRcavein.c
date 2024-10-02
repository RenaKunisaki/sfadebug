
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRcavein_initialise(undefined4 param) { //802BD69C
  return;
}


/* @description Called when DLL is unloaded */

void DRcavein_release(void) { //802BD6A0
  return;
}


/* Library Function - Single Match
    dll_2C3_func03
   
   Library: KioskDefault 0 0 */

void DRcavein_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802BD6A4
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined *puVar4;
  undefined4 local_1c;
  undefined4 local_18;
  uint uStack_14;
  
  puVar4 = this->state;
  local_1c = 1;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802bdd28;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
                    /* {@symbol 80128bb8} */
  (**(code **)(*(int *)pDll_RomCurve + 0x8c))(0x4072c00000000000,puVar4,this,&local_1c,0xffffffff);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  uStack_14 = (int)sVar1 ^ 0x80000000;
  local_18 = 0x43300000;
  *(float *)(puVar4 + 0x108) =
       (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) / 10.0;
  sVar2._0_1_ = objDef[1].bound;
  sVar2._1_1_ = objDef[1].cullDist;
  uVar3 = mainGetBit((int)sVar2);
  if (uVar3 == 0) {
    (this->pos).flags = (this->pos).flags | Invisible;
    FUN_80088da4((int)this);
    puVar4[0x10c] = 0;
  }
  else {
    puVar4[0x10c] = 1;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_2C3_func04
   
   Library: KioskDefault 0 0 */

void DRcavein_update(ObjInstance *this) { //802BD794
  byte bVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  ObjDef *pOVar5;
  float *pfVar6;
  
  pfVar6 = (float *)this->state;
  pOVar5 = this->def;
  bVar1 = *(byte *)(pfVar6 + 0x43);
  if (bVar1 != 1) {
    if (bVar1 == 0) {
      if ((true) && (uVar2 = mainGetBit((int)*(short *)&pOVar5[1].pos.x), uVar2 != 0)) {
        *(undefined *)(pfVar6 + 0x43) = 2;
        (this->pos).flags = (this->pos).flags & ~Invisible;
        FUN_80088d3c((int)this);
        audioTryStartSfx((int *)this,1,0x74,0x7f,(char *)&PTR_DAT_80324160,0x92);
        audioTryStartSfx((int *)this,2,0x66,0x7f,(char *)&PTR_DAT_80324160,0x93);
      }
    }
    else if (bVar1 < 3) {
      objHitFn_80089074(this,0xb,1,0);
      iVar3 = getAngle();
      (this->pos).rotation.x = (short)iVar3;
      if (*(char *)((int)&pOVar5[1].objType + 1) == '\x01') {
        FUN_80088d3c((int)this);
        (this->pos).rotation.x = -0x8000;
        objHitFn_80089074(this,1,1,0);
      }
      (this->pos).pos.x = pfVar6[0x1a];
      (this->pos).pos.y = pfVar6[0x1b];
      (this->pos).pos.z = pfVar6[0x1c];
      iVar3 = FUN_8006c2c8((double)pfVar6[0x42],pfVar6);
                    /* {@symbol 801290d4} */
      if (((iVar3 != 0) || (pfVar6[4] != 0.0)) &&
         ((*(char *)((int)pfVar6[0x28] + 0x18) == '\x7f' ||
          (cVar4 = (**(code **)(*(int *)pDll_RomCurve + 0x90))(pfVar6), cVar4 != '\0')))) {
        FUN_802bde08(this);
      }
      FUN_802bd9e4((double)pfVar6[0x42],(int)this);
      FUN_802bdb8c((int)this,pfVar6 + 0x1a,0);
      FUN_802bdadc(this);
    }
  }
  return;
}


/* @description Override hit detection */

void DRcavein_hitDetect(ObjInstance *this) { //802BD950
  return;
}


/* Library Function - Single Match
    dll_2C3_func06
   
   Library: KioskDefault 0 0 */

void DRcavein_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802BD954
  u8 uVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    uVar1 = this->newOpacity;
    this->newOpacity = 0xff;
    this->opacity = 0xff;
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    this->newOpacity = uVar1;
  }
  return;
}


/* @description Free object instance */

void DRcavein_free(ObjInstance *this,int param2) { //802BD9D0
  return;
}


undefined4 DRcavein_func08(ObjInstance *this) { //802BD9D4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRcavein_getExtraSize(void) { //802BD9DC
  return 0x110;
}

