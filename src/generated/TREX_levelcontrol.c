
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void TREX_levelcontrol_initialise(undefined4 param) { //802AB914
  return;
}


/* @description Called when DLL is unloaded */

void TREX_levelcontrol_release(void) { //802AB918
  return;
}


/* Library Function - Single Match
    dll_298_func03
   
   Library: KioskDefault 0 0 */

void TREX_levelcontrol_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802AB91C
  float *pfVar1;
  
  pfVar1 = (float *)this->state;
  loadEnvfxAction(this,this,0x18e,0);
  loadEnvfxAction(this,this,399,0);
  loadLfxAction(this,this,0x1fd);
  loadLfxAction(this,this,0x1fe);
                    /* {@symbol 8011bc64} */
  (**(code **)(*(int *)pDll05_2 + 4))
            (this,0xd5,"TREX_levelcontrol.c",0xa8,"AMMUSICACTION_TREX_MainTune");
  mainSetBits(0x572,0);
  mainSetBits(0x56e,1);
  mainSetBits(0x566,1);
  mainSetBits(0x569,1);
  *pfVar1 = 600.0;
  mainSetBits(0x55a,1);
  mainSetBits(0x54a,2);
  mainSetBits(0x54e,2);
  mainSetBits(0x552,1);
  mainSetBits(0x556,1);
  this->field76_0xf4 = 0;
  return;
}


/* Library Function - Single Match
    dll_298_func04
   
   Library: KioskDefault 0 0 */

void TREX_levelcontrol_update(ObjInstance *this) { //802ABA54
  uint uVar1;
  uint uVar2;
  
  if (this->field76_0xf4 == 0) {
    mainSetBits(0x55e,1);
    this->field76_0xf4 = 1;
  }
  uVar1 = mainGetBit(0x572);
  if (DAT_8039a130 != uVar1) {
    if ((uVar1 & 1) == 0) {
      mainSetBits(0x55c,1);
      audioStartSfx((int **)0x0,0x59,0x7f,0x40,"TREX_levelcontrol.c",0xef);
    }
    else {
      mainSetBits(0x54a,0);
      mainSetBits(0x54e,0);
      mainSetBits(0x552,0);
      mainSetBits(0x556,0);
    }
  }
  uVar2 = mainGetBit(0x55c);
  if (uVar2 != 0) {
    uVar2 = mainGetBit(0x55a);
    if (uVar2 == 0) {
      uVar2 = mainGetBit(0x55b);
      if (uVar2 != 0) {
        mainSetBits(0x54a,1);
        mainSetBits(0x54e,1);
        mainSetBits(0x552,2);
        mainSetBits(0x556,2);
      }
    }
    else {
      mainSetBits(0x54a,2);
      mainSetBits(0x54e,2);
      mainSetBits(0x552,1);
      mainSetBits(0x556,1);
    }
    mainSetBits(0x55c,0);
  }
  DAT_8039a130 = uVar1;
  return;
}


/* @description Override hit detection */

void TREX_levelcontrol_hitDetect(ObjInstance *this) { //802ABBC4
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void TREX_levelcontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802ABBC8
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
    dll_298_func07
   
   Library: KioskDefault 0 0 */

void TREX_levelcontrol_free(ObjInstance *this,int param2) { //802ABC24
                    /* {@symbol 8011bc64} */
  (**(code **)(*(int *)pDll05_2 + 4))
            (this,0xd6,"TREX_levelcontrol.c",0x13e,
             "AMMUSICACTION_TREX_MainTuneKill");
                    /* {@symbol 8011bc6c} */
  (**(code **)(*(int *)pDll05_2 + 8))
            (this,0xd5,"TREX_levelcontrol.c",0x13f,"AMMUSICACTION_TREX_MainTune");
  return;
}


undefined4 TREX_levelcontrol_func08(ObjInstance *this) { //802ABCA4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int TREX_levelcontrol_getExtraSize(void) { //802ABCAC
  return 4;
}

