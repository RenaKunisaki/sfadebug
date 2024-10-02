
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void MMP_gyservent_initialise(undefined4 param) { //8021C424
  return;
}


/* @description Called when DLL is unloaded */

void MMP_gyservent_release(void) { //8021C428
  return;
}


/* Library Function - Single Match
    dll_1A9_func03
   
   Library: KioskDefault 0 0 */

void MMP_gyservent_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8021C42C
  int iVar1;
  
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  this->newOpacity = 0;
  iVar1 = randInt(10,200);
  this->field76_0xf4 = iVar1;
  return;
}


/* Library Function - Single Match
    dll_1A9_func04
   
   Library: KioskDefault 0 0 */

void MMP_gyservent_update(ObjInstance *this) { //8021C478
  short sVar1;
  uint uVar2;
  int iVar3;
  dword dVar4;
  
  sVar1._0_1_ = this->def[1].bound;
  sVar1._1_1_ = this->def[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 == 0) {
    this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
    if ((int)this->field76_0xf4 < 0) {
      iVar3 = randInt(0x46,0xf0);
      this->field76_0xf4 = iVar3;
      dVar4 = randInt(0x1e,0x3c);
      this->flags_0xf8 = dVar4;
      iVar3 = randInt(0,1);
      audioTryStartSfx((int *)this,1,*(ushort *)((int)&PTR_DAT_80397d10 + iVar3 * 2),0x7f,
                       "MMP_gyservent.c",0x41);
    }
    if (this->flags_0xf8 != 0) {
      this->flags_0xf8 = this->flags_0xf8 - (uint)framesThisStep;
      if ((int)this->flags_0xf8 < 1) {
        this->flags_0xf8 = 0;
      }
      else {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x724,0,2,0xffffffff,0);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void MMP_gyservent_hitDetect(ObjInstance *this) { //8021C588
  return;
}


/* @description Override render */

void MMP_gyservent_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8021C58C
  return;
}


/* @description Free object instance */

void MMP_gyservent_free(ObjInstance *this,int param2) { //8021C590
  return;
}


undefined4 MMP_gyservent_func08(ObjInstance *this) { //8021C594
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int MMP_gyservent_getExtraSize(void) { //8021C59C
  return 0;
}

