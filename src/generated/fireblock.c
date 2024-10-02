
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void fireblock_initialise(undefined4 param) { //8028DDEC
  return;
}


/* @description Called when DLL is unloaded */

void fireblock_release(void) { //8028DDF0
  return;
}


/* @description Set up object instance */

void fireblock_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8028DDF4
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *puVar1 = *(undefined2 *)&objDef[1].bound;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    dll_25F_func04
   
   Library: KioskDefault 0 0 */

void fireblock_update(ObjInstance *this) { //8028DE34
  uint uVar1;
  int iVar2;
  ObjInstance *param1;
  bool bVar3;
  short *psVar4;
  double dVar5;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  
  psVar4 = (short *)this->state;
  local_1c = 0;
  uVar1 = mainGetBit((int)*psVar4);
  if (uVar1 == 0) {
    iVar2 = FUN_800883e4((int)this,&local_1c,(int *)0x0,(uint *)0x0);
    if (((iVar2 != 0) && (local_1c != 0)) && (*(short *)(local_1c + 0x46) == 0x14b)) {
      mainSetBits((int)*psVar4,1);
      audioTryStartSfx((int *)this,1,0x37,0x7f,(char *)&PTR_DAT_8031e438,0x47);
    }
  }
  else {
    local_20 = 0.0;
    local_24 = 8.0;
    local_28 = 20.0;
    local_2c = 1.0;
    local_34 = 0;
    local_32 = 0;
    local_30 = 0;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3a5,&local_34,4,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    dVar5 = (double)(**(code **)(*(int *)pDll_objfsa + 8))(this,0x3a6,&local_34,4,0xffffffff,0);
    param1 = Object_objGetMain();
    objDistObj2Obj(param1,this);
    bVar3 = FUN_80068b20((int)this,0x40);
    if (bVar3) {
      if (dVar5 < 90.0) {
        audioTryStartSfx((int *)this,0x40,300,0x7f,(char *)&PTR_DAT_8031e438,0x5a);
      }
    }
    else if (90.0 <= dVar5) {
      FUN_80068a9c((uint)this,0x40);
    }
  }
  return;
}


/* @description Override hit detection */

void fireblock_hitDetect(ObjInstance *this) { //8028DFFC
  return;
}


/* @description Override render */

void fireblock_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8028E000
  return;
}


/* @description Free object instance */

void fireblock_free(ObjInstance *this,int param2) { //8028E004
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 fireblock_func08(ObjInstance *this) { //8028E03C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int fireblock_getExtraSize(void) { //8028E044
  return 2;
}

