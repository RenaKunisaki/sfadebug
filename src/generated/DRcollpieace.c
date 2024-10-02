
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRcollpieace_initialise(undefined4 param) { //802BC854
  return;
}


/* @description Called when DLL is unloaded */

void DRcollpieace_release(void) { //802BC858
  return;
}


/* Library Function - Single Match
    dll_2C0_func03
   
   Library: KioskDefault 0 0 */

void DRcollpieace_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //802BC85C
  short sVar1;
  uint uVar2;
  float *pfVar3;
  
  pfVar3 = (float *)this->state;
  FUN_802bcf0c((undefined2 *)this,pfVar3,(int)objDef);
  uVar2 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  if (uVar2 == 0) {
    *(undefined *)((int)pfVar3 + 0x21) = 0;
  }
  else {
    *(undefined *)((int)pfVar3 + 0x21) = 3;
  }
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa30;
    this->shadow->flags = this->shadow->flags | 0x8000;
  }
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  if (sVar1 != 0) {
    (this->pos).flags = (this->pos).flags | Invisible;
    FUN_80088da4((int)this);
  }
  return;
}


/* Library Function - Single Match
    dll_2C0_func04
   
   Library: KioskDefault 0 0 */

void DRcollpieace_update(ObjInstance *this) { //802BC90C
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ObjDef *pOVar8;
  float *pfVar9;
  
  pfVar9 = (float *)this->state;
  pOVar8 = this->def;
  bVar1 = *(byte *)((int)pfVar9 + 0x21);
  if (bVar1 == 2) {
    objHitFn_80089114(this);
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      if ((*(short *)&pOVar8[1].pos.x == -1) ||
         (uVar6 = mainGetBit((int)*(short *)&pOVar8[1].pos.x), uVar6 != 0)) {
        *(undefined *)((int)pfVar9 + 0x21) = 3;
        FUN_80088d3c((int)this);
        sVar2._0_1_ = pOVar8[1].loadFlags;
        sVar2._1_1_ = pOVar8[1].mapStates2;
        if (sVar2 != 0) {
          (this->pos).flags = (this->pos).flags & ~Invisible;
        }
      }
    }
    else if ((true) && (((this->pos).flags & DontSave) != 0)) {
      Object_objFreeObject(this);
    }
  }
  else if (bVar1 < 4) {
    objHitFn_80089074(this,0xb,1,0);
    iVar7 = FUN_802bcb34((int *)this,pfVar9);
    if (iVar7 != 0) {
      *(undefined *)((int)pfVar9 + 0x21) = 2;
      sVar3._0_1_ = pOVar8[1].bound;
      sVar3._1_1_ = pOVar8[1].cullDist;
      if (sVar3 != -1) {
        sVar4._0_1_ = pOVar8[1].bound;
        sVar4._1_1_ = pOVar8[1].cullDist;
        mainSetBits((int)sVar4,1);
      }
      sVar5._0_1_ = pOVar8[1].loadFlags;
      sVar5._1_1_ = pOVar8[1].mapStates2;
      if (sVar5 == 0) {
        pfVar9[4] = (float)((int)pfVar9[5] + -0x7f);
      }
    }
  }
  iVar7 = FUN_802bca94((int)this,(int)pfVar9);
  if (iVar7 != 0) {
    (this->pos).flags = (this->pos).flags | Invisible;
    *(undefined *)((int)pfVar9 + 0x21) = 1;
  }
  FUN_802bca68((double)pfVar9[3],(int)this);
  return;
}


/* @description Override hit detection */

void DRcollpieace_hitDetect(ObjInstance *this) { //802BCE44
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DRcollpieace_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802BCE48
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

void DRcollpieace_free(ObjInstance *this,int param2) { //802BCEA4
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 DRcollpieace_func08(ObjInstance *this) { //802BCEFC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRcollpieace_getExtraSize(void) { //802BCF04
  return 0x24;
}

