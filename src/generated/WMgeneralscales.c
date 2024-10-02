
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WMgeneralscales_initialise(undefined4 param) { //802850D0
  return;
}


/* @description Called when DLL is unloaded */

void WMgeneralscales_release(void) { //802850D4
  return;
}


/* Library Function - Single Match
    dll_24C_func03
   
   Library: KioskDefault 0 0 */

void WMgeneralscales_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802850D8
  float *pfVar1;
  
  pfVar1 = (float *)this->state;
  this->fptr_0xbc = FUN_80285210;
  *pfVar1 = 0.0;
  *(undefined *)(pfVar1 + 1) = 1;
  this->child[0] = (ObjInstance *)0x0;
  return;
}


/* @description Update object instance */

void WMgeneralscales_update(ObjInstance *this) { //80285114
  return;
}


/* @description Override hit detection */

void WMgeneralscales_hitDetect(ObjInstance *this) { //80285118
  return;
}


/* Library Function - Single Match
    dll_24C_func06
   
   Library: KioskDefault 0 0 */

void WMgeneralscales_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8028511C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if (puVar1[4] != '\x01') {
    if ((puVar1[4] == '\x02') || (puVar1[4] == '\x03')) {
      FUN_80285464((short *)this,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),
                   (undefined4 *)CONCAT31(in_register_00000018,param4));
    }
    if (shouldRender) {
      objRenderCurrentModel
                (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    return;
  }
  return;
}


/* Library Function - Single Match
    dll_24C_func07
   
   Library: KioskDefault 0 0 */

void WMgeneralscales_free(ObjInstance *this,int param2) { //802851C0
  if (this->child[0] != (ObjInstance *)0x0) {
    Object_objRemoveChild(this,this->child[0]);
  }
  return;
}


undefined4 WMgeneralscales_func08(ObjInstance *this) { //80285200
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int WMgeneralscales_getExtraSize(void) { //80285208
  return 8;
}

