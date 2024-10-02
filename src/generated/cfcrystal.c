
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFcrystal_initialise(undefined4 param) { //802057FC
  return;
}


/* @description Called when DLL is unloaded */

void CFcrystal_release(void) { //80205800
  return;
}


/* Library Function - Single Match
    dll_15F_func03
   
   Library: KioskDefault 0 0 */

void CFcrystal_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //80205804
  undefined *puVar1;
  
  puVar1 = this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  if (*(char *)((int)&objDef[1].objType + 1) == '\0') {
    puVar1[0x15c] = 0x28;
    puVar1[0x15d] = 0;
    puVar1[0x15e] = 0;
    puVar1[0x15f] = 0x46;
    this->curModel = 1;
    *(undefined4 *)(puVar1 + 0x158) = 0;
  }
  DAT_80399e04 = runlinkDownloadCode(0x2003,1);
  objAllocMsgQueue(this,2);
  return;
}


/* Library Function - Single Match
    dll_15F_func04
   
   Library: KioskDefault 0 0 */

void CFcrystal_update(ObjInstance *this) { //802058A0
  char cVar1;
  double in_f1;
  
  cVar1 = *(char *)((int)&this->def[1].objType + 1);
  if (cVar1 == '\x01') {
    FUN_802065d0((short *)this);
  }
  else if ((cVar1 < '\x01') && (-1 < cVar1)) {
    cryActionFn_802059c0(in_f1,this);
  }
  return;
}


/* @description Override hit detection */

void CFcrystal_hitDetect(ObjInstance *this) { //80205900
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void CFcrystal_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //80205904
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


/* Library Function - Single Match
    dll_15F_func07
   
   Library: KioskDefault 0 0 */

void CFcrystal_free(ObjInstance *this,int param2) { //80205960
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  DLL_free(DAT_80399e04);
  DAT_80399e04 = (LoadedDll *)0x0;
  DAT_80399e08 = 0;
  return;
}


undefined4 CFcrystal_func08(ObjInstance *this) { //802059B0
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int CFcrystal_getExtraSize(void) { //802059B8
  return 0x160;
}

