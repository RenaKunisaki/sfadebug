
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void BOSSdrakor_laser_initialise(undefined4 param) { //802A742C
  return;
}


/* @description Called when DLL is unloaded */

void BOSSdrakor_laser_release(void) { //802A7430
  return;
}


/* @description Set up object instance */

void BOSSdrakor_laser_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802A7434
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  this->newOpacity = 0;
  return;
}


/* Library Function - Single Match
    dll_295_func04
   
   Library: KioskDefault 0 0 */

void BOSSdrakor_laser_update(ObjInstance *this) { //802A744C
  undefined2 *puVar1;
  float local_5c;
  float local_58;
  float local_54;
  Mtx44 MStack_50;
  longlong local_10;
  
  puVar1 = (undefined2 *)this->state;
  if ((puVar1[1] != 0) || (puVar1[2] != 0)) {
    mtxSetFromObjPos(&MStack_50,&this->pos);
    local_5c = 0.0;
    local_58 = 0.0;
    local_54 = 1000.0;
    multVectorByMatrix(0.0,0.0,1000.0,&MStack_50,&local_5c,&local_58,&local_54);
    FUN_802a7774(this,&local_5c);
    if (puVar1[2] != 0) {
      local_10 = (longlong)(int)timeDelta;
      puVar1[2] = puVar1[2] - (short)(int)timeDelta;
      if ((short)puVar1[2] < 1) {
        puVar1[2] = 0;
                    /* {@symbol 800e3c34} */
        (**(code **)(*(int *)pDll_projgfx + 0x2c))(this);
        FUN_80068a9c((uint)this,3);
        audioTryStartSfx((int *)this,4,0x1f5,0x7f,(char *)&PTR_DAT_80322e78,0x72);
      }
    }
    if (puVar1[1] != 0) {
      local_10 = (longlong)(int)timeDelta;
      puVar1[1] = puVar1[1] - (short)(int)timeDelta;
      if ((short)puVar1[1] < 1) {
        puVar1[1] = 0;
        puVar1[2] = *puVar1;
                    /* {@symbol 800e3c34} */
        (**(code **)(*(int *)pDll_projgfx + 0x2c))(this);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void BOSSdrakor_laser_hitDetect(ObjInstance *this) { //802A75CC
  return;
}


/* @description Override render */

void BOSSdrakor_laser_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802A75D0
  return;
}


/* @description Free object instance */

void BOSSdrakor_laser_free(ObjInstance *this,int param2) { //802A75D4
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
                    /* {@symbol 800e29b8} */
  (**(code **)(*(int *)pDll_projgfx + 0x14))(this);
  return;
}


undefined4 BOSSdrakor_laser_func08(ObjInstance *this) { //802A762C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int BOSSdrakor_laser_getExtraSize(void) { //802A7634
  return 10;
}


/* Library Function - Single Match
    dll_295_func0A
   
   Library: KioskDefault 0 0 */

void BOSSdrakor_laser_setScale(ObjInstance *this,float scale) { //802A763C
  LoadedDll *dll;
  int in_r4;
  int in_r5;
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  if ((in_r4 < 1) || (in_r5 < 1)) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  else {
    *puVar1 = (short)in_r5;
    puVar1[1] = (short)in_r4;
    puVar1[2] = 0;
    dll = (LoadedDll *)runlinkDownloadCode(0x1049,1);
    (**(code **)(dll->id + 4))(this,0,0,4,0xffffffff,0);
    DLL_free(dll);
    puVar1[3] = 1;
    puVar1[4] = 1;
    audioTryStartSfx((int *)this,1,0x230,(byte)puVar1[3],(char *)&PTR_DAT_80322e78,0xf6);
    audioTryStartSfx((int *)this,2,0x230,(byte)puVar1[4],(char *)&PTR_DAT_80322e78,0xf7);
    audioTryStartSfx((int *)this,4,0x1f6,0x7f,(char *)&PTR_DAT_80322e78,0xf8);
  }
  return;
}

