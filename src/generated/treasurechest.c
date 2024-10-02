
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void treasurechest_initialise(undefined4 param) { //801EE420
  return;
}


/* @description Called when DLL is unloaded */

void treasurechest_release(void) { //801EE424
  return;
}


/* Library Function - Single Match
    dll_12E_func03
   
   Library: KioskDefault 0 0 */

void treasurechest_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //801EE428
  short sVar1;
  short sVar2;
  uint uVar3;
  ObjDef *pOVar4;
  char *pcVar5;
  
  pcVar5 = this->state;
  pOVar4 = this->def;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801ee71c;
  sVar1._0_1_ = pOVar4[1].bound;
  sVar1._1_1_ = pOVar4[1].cullDist;
  if (sVar1 == -1) {
    *pcVar5 = '\0';
  }
  else {
    sVar2._0_1_ = pOVar4[1].bound;
    sVar2._1_1_ = pOVar4[1].cullDist;
    uVar3 = mainGetBit((int)sVar2);
    *pcVar5 = (char)uVar3;
  }
  if (*pcVar5 != '\0') {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    Object_ObjAnimSetMove(1.0,this,0,0);
  }
  DAT_80399d88 = DLL_setup(0x1002,1,FALSE);
  return;
}


/* Library Function - Single Match
    dll_12E_func04
   
   Library: KioskDefault 0 0 */

void treasurechest_update(ObjInstance *this) { //801EE4C8
  short sVar1;
  short sVar2;
  ObjInstance *pOVar3;
  ObjDef *pOVar4;
  char *pcVar5;
  
  pcVar5 = this->state;
  pOVar4 = this->def;
  if ((*pcVar5 == '\0') && ((this->flags_0xaf & CanPressAToTalk) != 0)) {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    pOVar3 = Object_objGetMain();
    FUN_801a7dc8((int)pOVar3,1);
    sVar1._0_1_ = pOVar4[1].allocatedSize;
    sVar1._1_1_ = pOVar4[1].mapStates1;
                    /* {@symbol 800d1668} */
    (**(code **)(*(int *)pDll_checkpoint + 0x7c))((int)sVar1,0,0);
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
    sVar2._0_1_ = pOVar4[1].bound;
    sVar2._1_1_ = pOVar4[1].cullDist;
    mainSetBits((int)sVar2,1);
    *pcVar5 = '\x01';
  }
  FUN_801ee608((int)this);
  return;
}


/* @description Override hit detection */

void treasurechest_hitDetect(ObjInstance *this) { //801EE584
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void treasurechest_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801EE588
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void treasurechest_free(ObjInstance *this,int param2) { //801EE5D4
  DLL_free(DAT_80399d88);
  return;
}


undefined4 treasurechest_func08(ObjInstance *this) { //801EE5F8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int treasurechest_getExtraSize(void) { //801EE600
  return 1;
}

