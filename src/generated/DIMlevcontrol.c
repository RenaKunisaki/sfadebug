
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMlevcontrol_initialise(undefined4 param) { //8022B100
  return;
}


/* @description Called when DLL is unloaded */

void DIMlevcontrol_release(void) { //8022B104
  return;
}


/* Library Function - Single Match
    dll_20F_func03
   
   Library: KioskDefault 0 0 */

void DIMlevcontrol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8022B108
  uint uVar1;
  
  uVar1 = randInt(0,0xb);
  *this->state = 0;
  mainSetBits(0x46d,uVar1 & 0xff);
  uVar1 = mainGetBit(0x42c);
  if (uVar1 == 0) {
                    /* {@symbol 8012decc} */
    (**(code **)(*(int *)pDll_SaveGame + 0x44))((int)(char)this->mapId,1);
  }
  else {
                    /* {@symbol 8012decc} */
    (**(code **)(*(int *)pDll_SaveGame + 0x44))((int)(char)this->mapId,2);
  }
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    dll_20F_func04
   
   Library: KioskDefault 0 0 */

void DIMlevcontrol_update(ObjInstance *this) { //8022B1B8
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = this->state;
  uVar1 = mainGetBit(0x3e2);
  uVar2 = mainGetBit(0x3e3);
  uVar2 = countLeadingZeros(uVar2);
  uVar1 = uVar2 >> 5 & uVar1;
  if ((uVar1 & 0xff) != (uint)*pbVar3) {
    mainSetBits(1000,uVar1 & 0xff);
    *pbVar3 = (byte)uVar1;
  }
  uVar2 = mainGetBit(0x8a4);
  if (((((uVar2 & 0xff) == 0) && (uVar2 = mainGetBit(0x89d), uVar2 != 0)) &&
      (uVar2 = mainGetBit(0x89e), uVar2 != 0)) && (uVar2 = mainGetBit(0x89f), uVar2 != 0)) {
    audioStartSfx((int **)0x0,0x161,0x7f,0x40,"DIMlevcontrol.c",0x5e);
    mainSetBits(0x8a4,1);
  }
  return;
}


/* @description Override hit detection */

void DIMlevcontrol_hitDetect(ObjInstance *this) { //8022B29C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIMlevcontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8022B2A0
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

void DIMlevcontrol_free(ObjInstance *this,int param2) { //8022B2FC
  return;
}


undefined4 DIMlevcontrol_func08(ObjInstance *this) { //8022B300
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIMlevcontrol_getExtraSize(void) { //8022B308
  return 1;
}

