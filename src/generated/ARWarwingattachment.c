
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void ARWarwingattachment_initialise(undefined4 param) { //802C6ECC
  return;
}


/* @description Called when DLL is unloaded */

void ARWarwingattachment_release(void) { //802C6ED0
  return;
}


/* @description Set up object instance */

void ARWarwingattachment_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802C6ED4
  return;
}


/* Library Function - Single Match
    laserBomb02E9_func04
   
   Library: KioskDefault 0 0 */

void ARWarwingattachment_update(ObjInstance *this) { //802C6ED8
  uint uVar1;
  ObjState_laerBomb02E9 *state;
  
  state = (ObjState_laerBomb02E9 *)this->state;
  uVar1 = countLeadingZeros((uint)(byte)state->field_0x14c);
  if ((uVar1 >> 5 & 1) == 0) {
    laserDebugFn_802c88d4(this,state);
    FUN_802c7d60((int)state);
    FUN_802c7e18(this,(int)state);
    laserFireFn_802c7828(this,(int)state);
    bombFn_802c7b00(this,(int)state);
    FUN_802c7360(this,(int)state);
    FUN_802c77f4(this,(int)state);
                    /* {@symbol 80153b18} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x60))(&state->field_0x24,0xc);
  }
  else {
    FUN_802c7004(this,(ObjInstance **)state);
  }
  return;
}


/* @description Override hit detection */

void ARWarwingattachment_hitDetect(ObjInstance *this) { //802C6F90
  return;
}


/* Library Function - Single Match
    laserBomb02E9_func06
   
   Library: KioskDefault 0 0 */

void ARWarwingattachment_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802C6F94
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

void ARWarwingattachment_free(ObjInstance *this,int param2) { //802C6FF0
  return;
}


undefined4 ARWarwingattachment_func08(ObjInstance *this) { //802C6FF4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int ARWarwingattachment_getExtraSize(void) { //802C6FFC
  return 0x150;
}


/* Library Function - Single Match
    ARWarwingattachmentFn_802ca4f0
   
   Library: KioskDefault 0 0 */

void ARWarwingattachmentFn_802ca4f0(int param1,undefined4 param2) { //802CA4F0
  if (*(short *)(param1 + 0x46) != 0x606) {
                    
    OSPanic("ARWarwingattachment.c",0x185,s_Failed_assertion_object_>romdefn_80325618);
  }
  *(undefined4 *)(*(int *)(param1 + 0xb8) + 4) = param2;
  return;
}


void FUN_802ca550(int param_1,char param_2) { //802CA550
  if ((*(short *)(param_1 + 0x46) != 0x610) && (*(short *)(param_1 + 0x46) != 0x615)) {
                    
    OSPanic("ARWarwingattachment.c",0x19c,s_Failed_assertion_object_>romdefn_80325650);
  }
  if (param_2 == '\0') {
    *(undefined *)(param_1 + 0x36) = 0;
  }
  else {
    *(undefined *)(param_1 + 0x36) = 0xff;
    **(float **)(param_1 + 0xb8) = 5.0;
  }
  return;
}


void FUN_802ca5dc(int param_1,char param_2) { //802CA5DC
  if (*(short *)(param_1 + 0x46) != 0x611) {
                    
    OSPanic("ARWarwingattachment.c",0x1bb,s_Failed_assertion_object_>romdefn_803256c0);
  }
  if (param_2 == '\0') {
    **(undefined **)(param_1 + 0xb8) = 0;
  }
  else {
    **(undefined **)(param_1 + 0xb8) = 1;
  }
  return;
}

