
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void spellStonePlace_initialise(undefined4 param) { //80290A18
  return;
}


/* @description Called when DLL is unloaded */

void spellStonePlace_release(void) { //80290A1C
  return;
}


/* Library Function - Single Match
    spellStonePlace_func03
   
   Library: KioskDefault 0 0 */

void spellStonePlace_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //80290A20
  uint uVar1;
  short *psVar2;
  
  psVar2 = (short *)this->state;
  *psVar2 = *(short *)&objDef[1].bound;
  psVar2[1] = *(short *)&objDef[1].pos.x;
  uVar1 = mainGetBit((int)psVar2[1]);
  if ((uVar1 == 0) && (uVar1 = mainGetBit((int)*psVar2), uVar1 == 0)) {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  }
  else {
    *(undefined *)(psVar2 + 2) = 1;
  }
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    spellStonePlace_func04
   
   Library: KioskDefault 0 0 */

void spellStonePlace_update(ObjInstance *this) { //80290AA4
  ObjInstance *param2;
  byte bVar1;
  double in_f1;
  
  param2 = Object_objGetMain();
  if ((param2 != (ObjInstance *)0x0) && (objDistObj2Obj(this,param2), in_f1 <= 100.0)) {
                    /* {@symbol 8012dfa8} */
    bVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
    if (bVar1 == 2) {
      spellPlaceFn_80290c24((int)this);
    }
    else if ((bVar1 < 2) && (bVar1 != 0)) {
      spellPlaceFn_80290b5c((int)this);
    }
  }
  return;
}


/* @description Override hit detection */

void spellStonePlace_hitDetect(ObjInstance *this) { //80290B40
  return;
}


/* @description Override render */

void spellStonePlace_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80290B44
  return;
}


/* @description Free object instance */

void spellStonePlace_free(ObjInstance *this,int param2) { //80290B48
  return;
}


undefined4 spellStonePlace_func08(ObjInstance *this) { //80290B4C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int spellStonePlace_getExtraSize(void) { //80290B54
  return 6;
}

