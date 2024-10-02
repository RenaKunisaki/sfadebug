
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void gasvent_initialise(undefined4 param) { //80221DB8
  return;
}


/* @description Called when DLL is unloaded */

void gasvent_release(void) { //80221DBC
  return;
}


/* Library Function - Single Match
    dll_1BA_func03
   
   Library: KioskDefault 0 0 */

void gasvent_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //80221DC0
  Object_objAddObjectType(this,0x41);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_1BA_func04
   
   Library: KioskDefault 0 0 */

void gasvent_update(ObjInstance *this) { //80221E00
  float local_c [2];
  
  local_c[0] = 3.402823e+38;
  getSeqObj(6,this,local_c);
  if (10.0 <= local_c[0]) {
    audioTryStartSfx((int *)this,1,0x71,0x7f,"gasvent.c",0x41);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3df,0,0,0xffffffff,0);
  }
  else {
    audioTryStartSfx((int *)this,0x40,0x3e,0x7f,"gasvent.c",0x3f);
  }
  return;
}


/* @description Override hit detection */

void gasvent_hitDetect(ObjInstance *this) { //80221EC8
  return;
}


/* @description Override render */

void gasvent_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //80221ECC
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if ((bVar1) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_1BA_func07
   
   Library: KioskDefault 0 0 */

void gasvent_free(ObjInstance *this,int param2) { //80221F34
  Object_removePlayerObj(this,0x41);
  return;
}


undefined4 gasvent_func08(ObjInstance *this) { //80221F60
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int gasvent_getExtraSize(void) { //80221F68
  return 0;
}

