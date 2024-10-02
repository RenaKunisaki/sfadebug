
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRvines_initialise(undefined4 param) { //802B7984
  return;
}


/* @description Called when DLL is unloaded */

void DRvines_release(void) { //802B7988
  return;
}


/* Library Function - Single Match
    dll_2B6_func03
   
   Library: KioskDefault 0 0 */

void DRvines_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //802B798C
  short sVar1;
  uint uVar2;
  
  Object_objAddObjectType(this,0x33);
  FUN_80088d3c((int)this);
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    (this->pos).flags = (this->pos).flags | Invisible;
    objFreeFn_80083b54(this);
    FUN_80088da4((int)this);
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  DLL_createTempDll(0x33);
  return;
}


/* Library Function - Single Match
    dll_2B6_func04
   
   Library: KioskDefault 0 0 */

void DRvines_update(ObjInstance *this) { //802B7A38
  short sVar1;
  short sVar2;
  ObjInstance *this_00;
  ObjInstance *param2;
  ObjInstance **ppOVar3;
  ObjDef *pOVar4;
  double dVar5;
  
  pOVar4 = this->def;
  ppOVar3 = (ObjInstance **)this->state;
  this_00 = Object_getSidekicksLoaded();
  if (this_00 != (ObjInstance *)0x0) {
    param2 = Object_objGetMain();
    dVar5 = (double)objDistSqObj2Obj(this,param2);
    sVar1._0_1_ = pOVar4[1].loadFlags;
    sVar1._1_1_ = pOVar4[1].mapStates2;
    sVar2._0_1_ = pOVar4[1].loadFlags;
    sVar2._1_1_ = pOVar4[1].mapStates2;
    if (dVar5 <= (double)(float)((double)CONCAT44(0x43300000,(int)sVar1 * (int)sVar2 ^ 0x80000000) -
                                4503601774854144.0)) {
      (*this_00->dll->ptrs2[1].hitDetect)(this_00);
    }
  }
  if (this->newOpacity != 0xff) {
    if (this->newOpacity < framesThisStep) {
      FUN_80068a9c((uint)this,1);
      objFreeFn_80083b54(this);
      FUN_80088da4((int)this);
      this->newOpacity = 0;
      (this->pos).flags = (this->pos).flags | Invisible;
      if (*ppOVar3 != (ObjInstance *)0x0) {
        Object_objFreeObject(*ppOVar3);
      }
    }
    else {
      this->newOpacity = this->newOpacity - framesThisStep;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2B6_func05
   
   Library: KioskDefault 0 0 */

void DRvines_hitDetect(ObjInstance *this) { //802B7B60
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ObjDef *pOVar5;
  uint uStack_14;
  
  pOVar5 = this->def;
  puVar4 = (undefined4 *)this->state;
  iVar2 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,&uStack_14);
  if ((iVar2 == 0x1a) && (this->newOpacity == 0xff)) {
    sVar1._0_1_ = pOVar5[1].bound;
    sVar1._1_1_ = pOVar5[1].cullDist;
    mainSetBits((int)sVar1,1);
    audioTryStartSfx((int *)this,1,300,0x7f,(char *)&PTR_DAT_80323ca8,0x97);
    this->newOpacity = 0xfd;
    objHitFn_80089074(this,0xb,1,0);
    uVar3 = FUN_802b7dc0((int)this,0x25c);
    *puVar4 = uVar3;
  }
  return;
}


/* Library Function - Single Match
    dll_2B6_func06
   
   Library: KioskDefault 0 0 */

void DRvines_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //802B7C18
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  int iVar3;
  undefined auStack_28 [8];
  float local_20;
  undefined auStack_1c [16];
  
  puVar2 = this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (this->newOpacity != 0xff) {
      local_20 = this->cullDistance * 0.03;
      for (iVar3 = 0; iVar3 < (int)(uint)framesThisStep; iVar3 = iVar3 + 1) {
        iVar1 = randInt(0,*(int *)(puVar2 + 4) + -1);
        (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x34))
                  (this,iVar1,auStack_1c);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x672,auStack_28,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x673,auStack_28,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x674,auStack_28,&DAT_00200001,0xffffffff,0);
      }
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_2B6_func07
    dll_EE_func07
   
   Library: KioskDefault 0 0 */

void DRvines_free(ObjInstance *this,int param2) { //802B7D7C
  Object_removePlayerObj(this,0x33);
  DLL_removeTempDll(0x33);
  return;
}


undefined4 DRvines_func08(ObjInstance *this) { //802B7DB0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRvines_getExtraSize(void) { //802B7DB8
  return 8;
}

