
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMbossspit_initialise(undefined4 param) { //8023403C
  return;
}


/* @description Called when DLL is unloaded */

void DIMbossspit_release(void) { //80234040
  return;
}


/* Library Function - Single Match
    dll_225_func03
   
   Library: KioskDefault 0 0 */

void DIMbossspit_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80234044
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  FUN_80234238(this);
  this->field76_0xf4 = 0xb4;
  objHitFn_80089074(this,0,0,0);
  objHitFn_80089354(this,0);
  *puVar1 = 0;
  puVar1[1] = 0;
  FUN_80088d3c((int)this);
  return;
}


/* Library Function - Single Match
    dll_225_func04
   
   Library: KioskDefault 0 0 */

void DIMbossspit_update(ObjInstance *this) { //802340B8
  short *psVar1;
  
  psVar1 = (short *)this->state;
  if (*psVar1 == 0) {
    this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
    if ((int)this->field76_0xf4 < 0) {
      Object_objFreeObject(this);
    }
    else {
      FUN_802342b8(this);
      if (this->hitstate->field54_0x9d != 0) {
        (this->pos).pos.x = this->hitstate->minSizeY;
        (this->pos).pos.y = this->hitstate->sizeY - 10.0;
        (this->pos).pos.z = (this->hitstate->field12_0x3c).x;
        *psVar1 = 1;
      }
    }
  }
  else {
    FUN_80234478(this);
  }
  return;
}


/* @description Override hit detection */

void DIMbossspit_hitDetect(ObjInstance *this) { //80234170
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIMbossspit_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80234174
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
    dll_225_func07
   
   Library: KioskDefault 0 0 */

void DIMbossspit_free(ObjInstance *this,int param2) { //802341D0
  if (*(int *)(this->state + 4) != 0) {
    lightFreeAndRemove(*(Light **)(this->state + 4));
  }
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 DIMbossspit_func08(ObjInstance *this) { //80234228
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIMbossspit_getExtraSize(void) { //80234230
  return 8;
}

