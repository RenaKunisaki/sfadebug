
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFtoggleswitch_initialise(undefined4 param) { //8020B3C8
  return;
}


/* @description Called when DLL is unloaded */

void CFtoggleswitch_release(void) { //8020B3CC
  return;
}


/* Library Function - Single Match
    dll_16D_func03
   
   Library: KioskDefault 0 0 */

void CFtoggleswitch_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8020B3D0
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->fptr_0xbc = FUN_8020b684;
  puVar3 = this->state;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  puVar3[2] = (char)uVar2;
  uVar2 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  puVar3[1] = (char)uVar2;
  *puVar3 = 2;
  return;
}


/* Library Function - Single Match
    dll_16D_func04
   
   Library: KioskDefault 0 0 */

void CFtoggleswitch_update(ObjInstance *this) { //8020B440
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  ObjDef *pOVar6;
  byte *pbVar7;
  
  iVar5 = 0;
  pbVar7 = this->state;
  pOVar6 = this->def;
  if ((*pbVar7 & 1) == 0) {
    uVar4 = mainGetBit((int)*(short *)&pOVar6[1].pos.x);
    if (pbVar7[1] != uVar4) {
      pbVar7[1] = pbVar7[1] ^ 1;
      sVar1._0_1_ = pOVar6[1].bound;
      sVar1._1_1_ = pOVar6[1].cullDist;
      uVar4 = mainGetBit((int)sVar1);
      if (uVar4 != 0) {
        sVar2._0_1_ = pOVar6[1].allocatedSize;
        sVar2._1_1_ = pOVar6[1].mapStates1;
                    /* {@symbol 800d0a70} */
        (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,(int)sVar2);
      }
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(pbVar7[1],this,1);
      *pbVar7 = *pbVar7 | 1;
    }
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    if ((this->flags_0xaf & PlayerIsDisguised) == 0) {
      iVar5 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    }
    if ((iVar5 == 0xe) || ((this->flags_0xaf & CanPressAToTalk) != 0)) {
      pbVar7[1] = pbVar7[1] ^ 1;
      if (iVar5 == 0) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(pbVar7[1],this,0xffffffff);
      }
      else {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(pbVar7[1],this,1);
      }
      *pbVar7 = *pbVar7 | 1;
      disableButtons(0,PAD_BUTTON_A);
    }
    if ((*pbVar7 & 2) != 0) {
      sVar3._0_1_ = pOVar6[1].allocatedSize;
      sVar3._1_1_ = pOVar6[1].mapStates1;
                    /* {@symbol 800d0a70} */
      (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,(int)sVar3);
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(pbVar7[1],this,1);
      *pbVar7 = *pbVar7 & 0xfd;
    }
  }
  else {
    *pbVar7 = *pbVar7 & 0xfe;
  }
  return;
}


/* @description Override hit detection */

void CFtoggleswitch_hitDetect(ObjInstance *this) { //8020B610
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void CFtoggleswitch_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8020B614
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

void CFtoggleswitch_free(ObjInstance *this,int param2) { //8020B670
  return;
}


undefined4 CFtoggleswitch_func08(ObjInstance *this) { //8020B674
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int CFtoggleswitch_getExtraSize(void) { //8020B67C
  return 3;
}

