
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void VFlevcontrol_initialise(undefined4 param) { //8028AF98
  return;
}


/* @description Called when DLL is unloaded */

void VFlevcontrol_release(void) { //8028AF9C
  return;
}


/* Library Function - Single Match
    VFlevcontrol_func03
   
   Library: KioskDefault 0 0 */

void VFlevcontrol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8028AFA0
  byte bVar1;
  
  Object_objAddObjectType(this,10);
                    /* {@symbol 8012decc} */
  (**(code **)(*(int *)pDll_SaveGame + 0x44))((int)(char)this->mapId,1);
                    /* {@symbol 8012dfa8} */
  bVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  if (bVar1 == 3) {
    loadEnvfxAction(this,this,0x105,0);
    loadEnvfxAction(this,this,0x106,0);
    loadEnvfxAction(this,this,0x107,0);
    loadLfxAction(this,this,0x166);
    loadLfxAction(this,this,0x167);
    loadLfxAction(this,this,0x168);
    loadLfxAction(this,this,0x169);
    loadLfxAction(this,this,0x174);
  }
  else if ((bVar1 < 3) && (bVar1 == 0)) {
    loadEnvfxAction(this,this,0x105,0);
    loadEnvfxAction(this,this,0x106,0);
    loadEnvfxAction(this,this,0x107,0);
  }
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    VFlevcontrol_func04
   
   Library: KioskDefault 0 0 */

void VFlevcontrol_update(ObjInstance *this) { //8028B140
  ObjInstance *pOVar1;
  uint uVar2;
  byte bVar3;
  
  pOVar1 = Object_objGetMain();
  mapCoordsToId(SUB84((double)(pOVar1->pos).pos.x,0),SUB84((double)(pOVar1->pos).pos.z,0));
                    /* {@symbol 8012dfa8} */
  uVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  diPrintf("ACT %d ",uVar2 & 0xff);
                    /* {@symbol 8012dfa8} */
  bVar3 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  if (bVar3 == 2) {
    if ((DAT_80398008 != 0) &&
       (DAT_80398008 = DAT_80398008 - (short)(int)timeDelta, DAT_80398008 < 1)) {
      DAT_80398008 = 0;
      mainSetBits(0x4e9,1);
      loadEnvfxAction(this,this,0x105,0);
      loadEnvfxAction(this,this,0x106,0);
      loadEnvfxAction(this,this,0x107,0);
      loadLfxAction(this,this,0x166);
      loadLfxAction(this,this,0x167);
      loadLfxAction(this,this,0x168);
      loadLfxAction(this,this,0x169);
      loadLfxAction(this,this,0x174);
      loadLfxAction(this,this,0x178);
      mainSetBits(0x83b,1);
      mainSetBits(0x22b,1);
      printf("TRACE: '%s' {Line %d}","VFlevcontrol.c",0xb2);
    }
    FUN_8028b6b8();
  }
  else if (bVar3 < 2) {
    if ((bVar3 != 0) && (true)) {
      if ((DAT_80398008 != 0) &&
         (DAT_80398008 = DAT_80398008 - (short)(int)timeDelta, DAT_80398008 < 1)) {
        DAT_80398008 = 0;
        loadEnvfxAction(this,this,0x105,0);
        loadEnvfxAction(this,this,0x106,0);
        loadEnvfxAction(this,this,0x107,0);
        loadLfxAction(this,this,0x166);
        loadLfxAction(this,this,0x167);
        loadLfxAction(this,this,0x168);
        loadLfxAction(this,this,0x169);
        loadLfxAction(this,this,0x174);
        loadLfxAction(this,this,0x178);
        mainSetBits(0x123,1);
      }
      FUN_8028b608();
    }
  }
  else if (bVar3 < 4) {
    if ((DAT_80398008 != 0) &&
       (DAT_80398008 = DAT_80398008 - (short)(int)timeDelta, DAT_80398008 < 1)) {
      DAT_80398008 = 0;
      mainSetBits(0x4e9,1);
      mainSetBits(0x63c,1);
      loadEnvfxAction(this,this,0x105,0);
      loadEnvfxAction(this,this,0x106,0);
      loadEnvfxAction(this,this,0x107,0);
      loadLfxAction(this,this,0x166);
      loadLfxAction(this,this,0x167);
      loadLfxAction(this,this,0x168);
      loadLfxAction(this,this,0x169);
      loadLfxAction(this,this,0x174);
      mainSetBits(0x83c,1);
    }
    FUN_8028b71c();
  }
  return;
}


/* @description Override hit detection */

void VFlevcontrol_hitDetect(ObjInstance *this) { //8028B5C4
  return;
}


/* @description Override render */

void VFlevcontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8028B5C8
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    VFlevcontrol_func07
    dll_2CC_func07
    dll_2E7_func07
    sunMoonBlockPuzzle_func07
   
   Library: KioskDefault 0 0 */

void VFlevcontrol_free(ObjInstance *this,int param2) { //8028B5CC
  Object_removePlayerObj(this,10);
  return;
}


undefined4 VFlevcontrol_func08(ObjInstance *this) { //8028B5F8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int VFlevcontrol_getExtraSize(void) { //8028B600
  return 3;
}

