
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void IMspacecraft_initialise(undefined4 param) { //802249B0
  return;
}


/* @description Called when DLL is unloaded */

void IMspacecraft_release(void) { //802249B4
  return;
}


/* Library Function - Single Match
    dll_188_func03
   
   Library: KioskDefault 0 0 */

void IMspacecraft_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //802249B8
  int iVar1;
  uint uVar2;
  
  this->fptr_0xbc = IMAnimSpaceCraft_SeqFn;
  DAT_80395d6c = 0.0;
  DAT_80395d70 = 0.0;
  DAT_80395d74 = 0.0;
  for (uVar2 = 2; (int)uVar2 < 7; uVar2 = uVar2 + 1) {
    iVar1 = FUN_80094400((int)this,uVar2);
    *(undefined *)(iVar1 + 0xc) = 1;
    *(undefined *)(iVar1 + 0xd) = 1;
    *(undefined *)(iVar1 + 0xe) = 1;
  }
  return;
}


/* @description Update object instance */

void IMspacecraft_update(ObjInstance *this) { //80224A4C
  if (this->field76_0xf4 != 0) {
    return;
  }
  this->field76_0xf4 = 1;
  return;
}


/* @description Override hit detection */

void IMspacecraft_hitDetect(ObjInstance *this) { //80224A64
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void IMspacecraft_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80224A68
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


/* @description Free object instance */

void IMspacecraft_free(ObjInstance *this,int param2) { //80224AC4
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 IMspacecraft_func08(ObjInstance *this) { //80224AFC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int IMspacecraft_getExtraSize(void) { //80224B04
  return 4;
}


/* Library Function - Single Match
    dll_188_func0A
   
   Library: KioskDefault 0 0 */

void IMspacecraft_setScale(ObjInstance *this,float scale) { //80224D2C
  return;
}


byte IMspacecraft_func0B(int param1) { //80224D64
  return *(byte *)(*(int *)(param1 + 0xb8) + 3) & 4;
}


/* Library Function - Single Match
    dll_188_func0C
   
   Library: KioskDefault 0 0 */

void IMspacecraft_modelMtxFn(ObjInstance *this,int param2,vec3f *param3) { //80224D84
  int iVar1;
  double in_f1;
  double dVar2;
  
  dVar2 = (double)(float)(in_f1 * 255.0);
  if (dVar2 < 1.0) {
    dVar2 = 1.0;
  }
  iVar1 = FUN_80094400((int)this,param2 + 2);
  *(char *)(iVar1 + 0xc) = (char)(int)dVar2;
  if (*(char *)(iVar1 + 0xc) == '\0') {
    *(undefined *)(iVar1 + 0xc) = 1;
  }
  *(char *)(iVar1 + 0xd) = (char)(int)dVar2;
  if (*(char *)(iVar1 + 0xd) == '\0') {
    *(undefined *)(iVar1 + 0xd) = 1;
  }
  *(char *)(iVar1 + 0xe) = (char)(int)dVar2;
  if (*(char *)(iVar1 + 0xe) == '\0') {
    *(undefined *)(iVar1 + 0xe) = 1;
  }
  return;
}

