
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void waterfallControl_initialise(undefined4 param) { //801EC194
  return;
}


/* @description Called when DLL is unloaded */

void waterfallControl_release(void) { //801EC198
  return;
}


/* @description Set up object instance */

void waterfallControl_init
               (ObjInstance *param1,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801EC19C
  param1->flags_0xb0 = param1->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    waterfallControl_func04
   
   Library: KioskDefault 0 0 */

void waterfallControl_update(ObjInstance *this) { //801EC1AC
  bool bVar1;
  
  bVar1 = FUN_80068b20((int)this,0x40);
  if (bVar1) {
    printf("no play");
  }
  else {
    printf("play");
    audioTryStartSfx((int *)this,0x40,0x7b,0x7f,"waterfallcontrol.c",0x2e);
  }
  return;
}


/* @description Override hit detection */

void waterfallControl_hitDetect(ObjInstance *this) { //801EC22C
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void waterfallControl_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801EC230
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void waterfallControl_free(ObjInstance *this,int param2) { //801EC27C
  return;
}


undefined4 waterfallControl_func08(ObjInstance *this) { //801EC280
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int waterfallControl_getExtraSize(void) { //801EC288
  return 0;
}

