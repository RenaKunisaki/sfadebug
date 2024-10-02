
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void mmp_levelcontrol_initialise(undefined4 param) { //8021A63C
  return;
}


/* @description Called when DLL is unloaded */

void mmp_levelcontrol_release(void) { //8021A640
  return;
}


/* @description Set up object instance */

void mmp_levelcontrol_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8021A644
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  this->field76_0xf4 = 1;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8021a824;
  return;
}


/* Library Function - Single Match
    dll_1A4_func04
   
   Library: KioskDefault 0 0 */

void mmp_levelcontrol_update(ObjInstance *this) { //8021A668
  ObjInstance *param2;
  
  if (this->field76_0xf4 != 0) {
    param2 = Object_objGetMain();
    loadEnvfxAction(this,param2,0x13a,0);
    loadEnvfxAction(this,param2,0x138,0);
    loadEnvfxAction(this,param2,0x139,0);
    loadLfxAction(this,param2,0x1dc);
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))
              (this,0xf,"MMP_levelcontrol.c",0x5d,"AMMUSICACTION_MMP_Ambience");
    this->field76_0xf4 = 0;
  }
  return;
}


/* @description Override hit detection */

void mmp_levelcontrol_hitDetect(ObjInstance *this) { //8021A734
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void mmp_levelcontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8021A738
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
    dll_1A4_func07
   
   Library: KioskDefault 0 0 */

void mmp_levelcontrol_free(ObjInstance *this,int param2) { //8021A794
                    /* {@symbol 8011bc6c} */
  (**(code **)(*(int *)pDll05_2 + 8))
            (this,0xf,"MMP_levelcontrol.c",0x7d,"AMMUSICACTION_MMP_Ambience");
                    /* {@symbol 8011bc64} */
  (**(code **)(*(int *)pDll05_2 + 4))
            (this,0x107,"MMP_levelcontrol.c",0x7e,"AMMUSICACTION_MMP_AmbienceKill"
            );
  return;
}


undefined4 mmp_levelcontrol_func08(ObjInstance *this) { //8021A814
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int mmp_levelcontrol_getExtraSize(void) { //8021A81C
  return 0;
}

