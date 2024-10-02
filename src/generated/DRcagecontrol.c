
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRcagecontrol_initialise(undefined4 param) { //802B65EC
  return;
}


/* @description Called when DLL is unloaded */

void DRcagecontrol_release(void) { //802B65F0
  return;
}


/* Library Function - Single Match
    dll_2B1_func03
   
   Library: KioskDefault 0 0 */

void DRcagecontrol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //802B65F4
  short sVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)this->state;
  this->fptr_0xbc = DR_CageControl_seqFn;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 == 0) {
    *puVar3 = 0;
  }
  else {
    *puVar3 = 1;
  }
  return;
}


/* Library Function - Single Match
    dll_2B1_func04
   
   Library: KioskDefault 0 0 */

void DRcagecontrol_update(ObjInstance *this) { //802B6658
  short sVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)this->state;
  if ((*piVar3 == 0) &&
     (sVar1._0_1_ = this->def[1].bound, sVar1._1_1_ = this->def[1].cullDist,
     uVar2 = mainGetBit((int)sVar1), uVar2 != 0)) {
    *piVar3 = 1;
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(2,this,0xffffffff);
  }
  else {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(*piVar3,this,0xffffffff);
  }
  return;
}


/* @description Override hit detection */

void DRcagecontrol_hitDetect(ObjInstance *this) { //802B66F0
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DRcagecontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802B66F4
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

void DRcagecontrol_free(ObjInstance *this,int param2) { //802B6750
  return;
}


undefined4 DRcagecontrol_func08(ObjInstance *this) { //802B6754
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRcagecontrol_getExtraSize(void) { //802B675C
  return 4;
}

