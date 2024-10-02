
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void doorswitch261_initialise(undefined4 param) { //8028E9DC
  return;
}


/* @description Called when DLL is unloaded */

void doorswitch261_release(void) { //8028E9E0
  return;
}


/* Library Function - Single Match
    dll_261_func03
   
   Library: KioskDefault 0 0 */

void doorswitch261_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8028E9E4
  uint uVar1;
  short *psVar2;
  
  psVar2 = (short *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  (this->pos).rotation.z = (short)((int)*(char *)((int)&objDef[1].objType + 1) << 8);
  (this->pos).rotation.y = *(short *)&objDef[1].loadFlags;
  *psVar2 = *(short *)&objDef[1].bound;
  psVar2[1] = *(short *)&objDef[1].allocatedSize;
  uVar1 = mainGetBit((int)*psVar2);
  if (uVar1 != 0) {
    *(undefined *)(psVar2 + 2) = 1;
  }
  if ((this->romdefno == VFP_LiftInd) && (*(char *)(psVar2 + 2) != '\0')) {
    this->curModel = 1;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_261_func04
   
   Library: KioskDefault 0 0 */

void doorswitch261_update(ObjInstance *this) { //8028EA98
  if (this->romdefno == VFP_LiftInd) {
    FUN_8028ecd8(this);
  }
  else {
    FUN_8028ebb4((int *)this);
  }
  return;
}


/* @description Override hit detection */

void doorswitch261_hitDetect(ObjInstance *this) { //8028EAE0
  return;
}


/* Library Function - Single Match
    dll_261_func06
   
   Library: KioskDefault 0 0 */

void doorswitch261_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8028EAE4
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (this->romdefno == VFP_LiftInd) {
    if (!shouldRender) {
      return;
    }
  }
  else {
    if (!shouldRender) {
      return;
    }
    if (this->state[4] != '\0') {
      return;
    }
  }
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void doorswitch261_free(ObjInstance *this,int param2) { //8028EB6C
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 doorswitch261_func08(ObjInstance *this) { //8028EBA4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int doorswitch261_getExtraSize(void) { //8028EBAC
  return 6;
}

