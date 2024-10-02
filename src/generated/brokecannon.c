
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void brokecannon_initialise(undefined4 param) { //80267254
  return;
}


/* @description Called when DLL is unloaded */

void brokecannon_release(void) { //80267258
  return;
}


/* @description Set up object instance */

void brokecannon_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8026725C
  return;
}


/* Library Function - Single Match
    dll_239_func04
   
   Library: KioskDefault 0 0 */

void brokecannon_update(ObjInstance *this) { //80267260
  short sVar1;
  uint uVar2;
  
  sVar1._0_1_ = this->def[1].bound;
  sVar1._1_1_ = this->def[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    audioTryStartSfx((int *)this,0x81,0x6e,0x7f,"brokecannon.c",0x8a);
  }
  return;
}


/* @description Override hit detection */

void brokecannon_hitDetect(ObjInstance *this) { //802672C8
  return;
}


/* Library Function - Single Match
    dll_239_func06
   
   Library: KioskDefault 0 0 */

void brokecannon_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802672CC
  short sVar1;
  uint uVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  sVar1._0_1_ = this->def[1].bound;
  sVar1._1_1_ = this->def[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void brokecannon_free(ObjInstance *this,int param2) { //80267334
  return;
}


undefined4 brokecannon_func08(ObjInstance *this) { //80267338
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int brokecannon_getExtraSize(void) { //80267340
  return 1;
}

