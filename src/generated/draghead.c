
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void draghead_initialise(undefined4 param) { //8028F1B4
  return;
}


/* @description Called when DLL is unloaded */

void draghead_release(void) { //8028F1B8
  return;
}


/* Library Function - Single Match
    dll_263_func03
   
   Library: KioskDefault 0 0 */

void draghead_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8028F1BC
  undefined2 uVar1;
  bool bVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)this->state;
  if (this->romdefno == CAMERAnewse) {
    puVar3[3] = 0x78;
    (this->pos).scale = this->data->scale * 0.5;
    objHitFn_80089074(this,0xe,1,0);
  }
  else {
    (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  }
  *puVar3 = *(undefined2 *)&objDef[1].bound;
  puVar3[1] = *(undefined2 *)&objDef[1].pos.x;
  puVar3[2] = 100;
  uVar1._0_1_ = objDef[1].allocatedSize;
  uVar1._1_1_ = objDef[1].mapStates1;
  *(char *)((int)puVar3 + 0xb) = (char)uVar1;
  if ((*(char *)((int)&objDef[1].objType + 1) == '\x01') &&
     (bVar2 = checkSomeDebugFlags_8017c4f8(), !bVar2)) {
    (this->pos).scale = this->data->scale * 0.5;
  }
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  DAT_8039a0a8 = runlinkDownloadCode(0x104d,1);
  return;
}


/* Library Function - Single Match
    dll_263_func04
   
   Library: KioskDefault 0 0 */

void draghead_update(ObjInstance *this) { //8028F2A8
  ObjDef *pOVar1;
  
  pOVar1 = this->def;
  if (*(char *)((int)&pOVar1[1].objType + 1) == '\x02') {
    FUN_8028f7e0((int *)this);
  }
  else if (this->romdefno == CAMERAnewse) {
    FUN_8028f748(this);
  }
  else if (*(char *)((int)&pOVar1[1].objType + 1) == '\0') {
    FUN_8028f3bc((int *)this);
  }
  else if (*(char *)((int)&pOVar1[1].objType + 1) == '\x01') {
    FUN_8028f640((int)this);
  }
  return;
}


/* @description Override hit detection */

void draghead_hitDetect(ObjInstance *this) { //8028F330
  return;
}


/* @description Override render */

void draghead_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8028F334
  return;
}


/* Library Function - Single Match
    dll_263_func07
   
   Library: KioskDefault 0 0 */

void draghead_free(ObjInstance *this,int param2) { //8028F338
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
                    /* {@symbol 800e29b8} */
  (**(code **)(*(int *)pDll_projgfx + 0x14))(this);
  if (DAT_8039a0a8 != (LoadedDll *)0x0) {
    DLL_free(DAT_8039a0a8);
  }
  DAT_8039a0a8 = (LoadedDll *)0x0;
  return;
}


undefined4 draghead_func08(ObjInstance *this) { //8028F3AC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int draghead_getExtraSize(void) { //8028F3B4
  return 0xc;
}

