
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void MMP_critterspit_initialise(undefined4 param) { //801C84DC
  return;
}


/* @description Called when DLL is unloaded */

void MMP_critterspit_release(void) { //801C84E0
  return;
}


/* Library Function - Single Match
    dll_E1_func03
   
   Library: KioskDefault 0 0 */

void MMP_critterspit_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801C84E4
  this->field76_0xf4 = 300;
  FUN_80088da4((int)this);
  this->newOpacity = 0xff;
  audioTryStartSfx((int *)this,0x40,0x234,0x7f,(char *)&PTR_DAT_80310b38,0x44);
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    dll_E1_func04
   
   Library: KioskDefault 0 0 */

void MMP_critterspit_update(ObjInstance *this) { //801C8554
  int iVar1;
  ObjInstance *pOVar2;
  double z;
  double x;
  double local_30;
  double local_28;
  
  _savefpr_29();
  local_28 = (double)CONCAT44(0x43300000,this->field76_0xf4 ^ 0x80000000);
  this->field76_0xf4 = (int)((float)(local_28 - 4503601774854144.0) - timeDelta);
  if ((int)this->field76_0xf4 < 0) {
    Object_objFreeObject(this);
    goto LAB_801c87e0;
  }
  if (this->newOpacity == 0) goto LAB_801c87e0;
  if ((int)this->field76_0xf4 < 0xb7) {
    (this->vel).y = -(timeDelta * 0.07 - (this->vel).y);
    local_30 = (double)CONCAT44(0x43300000,(uint)this->newOpacity);
    if (-(timeDelta * 4.0 - (float)(local_30 - 4503599627370496.0)) <= 0.0) {
      FUN_80068a9c((uint)this,0x7f);
      this->newOpacity = 0;
    }
    else {
      local_30 = (double)CONCAT44(0x43300000,(uint)this->newOpacity);
      this->newOpacity = (u8)(int)-(timeDelta * 4.0 - (float)(local_30 - 4503599627370496.0));
    }
    FUN_800689dc(127.0,(int)this,1,(byte)((int)(uint)this->newOpacity >> 1));
  }
  x = (double)((this->vel).x * timeDelta);
  z = (double)((this->vel).z * timeDelta);
  objMove(x,(double)((this->vel).y * timeDelta),z,this);
  iVar1 = getAngle();
  (this->pos).rotation.x = (short)iVar1 + -0x8000;
  sqrt((double)(float)(x * x + (double)(float)(z * z)));
  iVar1 = getAngle();
  (this->pos).rotation.y = 0x4000 - (short)iVar1;
  objHitFn_80089074(this,10,1,0);
  FUN_80088d3c((int)this);
  if (this->hitstate->field13_0x48 == 0) {
LAB_801c876c:
    if (this->hitstate->field54_0x9d == 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x714,0,2,0xffffffff,&this->newOpacity);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x715,0,1,0xffffffff,0);
    }
    else {
      FUN_801c8818((int *)this);
    }
  }
  else {
    pOVar2 = Object_objGetMain();
    if ((ObjInstance *)this->hitstate->field13_0x48 != pOVar2) {
      pOVar2 = Object_getSidekicksLoaded();
      if ((ObjInstance *)this->hitstate->field13_0x48 != pOVar2) goto LAB_801c876c;
    }
    FUN_801c8818((int *)this);
  }
LAB_801c87e0:
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void MMP_critterspit_hitDetect(ObjInstance *this) { //801C87FC
  return;
}


/* @description Override render */

void MMP_critterspit_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801C8800
  return;
}


/* @description Free object instance */

void MMP_critterspit_free(ObjInstance *this,int param2) { //801C8804
  return;
}


undefined4 MMP_critterspit_func08(ObjInstance *this) { //801C8808
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int MMP_critterspit_getExtraSize(void) { //801C8810
  return 0;
}

