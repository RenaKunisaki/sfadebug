
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void NWsfx_initialise(undefined4 param) { //8024B7B0
  return;
}


/* @description Called when DLL is unloaded */

void NWsfx_release(void) { //8024B7B4
  return;
}


/* Library Function - Single Match
    dll_1DA_func03
   
   Library: KioskDefault 0 0 */

void NWsfx_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //8024B7B8
  ObjDefEnum OVar1;
  ObjDefEnum *pOVar2;
  
  pOVar2 = (ObjDefEnum *)this->state;
  *pOVar2 = objDef[1].objType;
  OVar1 = (ushort)objDef[1].mapStates1 * 0x3c;
  pOVar2[2] = OVar1;
  pOVar2[1] = OVar1;
  if (objDef[1].allocatedSize == 0) {
    *(undefined *)(pOVar2 + 3) = 1;
  }
  else {
    *(undefined *)(pOVar2 + 3) = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_1DA_func04
   
   Library: KioskDefault 0 0 */

void NWsfx_update(ObjInstance *this) { //8024B808
  int iVar1;
  uint uVar2;
  short *psVar3;
  
  psVar3 = (short *)this->state;
  if ((*(char *)(psVar3 + 3) != '\0') &&
     (psVar3[2] = psVar3[2] - (ushort)framesThisStep, psVar3[2] < 0)) {
    psVar3[2] = psVar3[1];
    iVar1 = randInt(0,(int)psVar3[1]);
    psVar3[2] = psVar3[2] + (short)iVar1;
    if ((*psVar3 == -1) || (uVar2 = mainGetBit((int)*psVar3), uVar2 == 0)) {
      iVar1 = randInt(0,3);
      audioTryStartSfx((int *)this,1,*(ushort *)((int)&PTR_DAT_80397e00 + iVar1 * 2),0x7f,
                       "NWsfx.c",0x61);
    }
  }
  return;
}


/* @description Override hit detection */

void NWsfx_hitDetect(ObjInstance *this) { //8024B8CC
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void NWsfx_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //8024B8D0
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

void NWsfx_free(ObjInstance *this,int param2) { //8024B92C
  return;
}


undefined4 NWsfx_func08(ObjInstance *this) { //8024B930
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int NWsfx_getExtraSize(void) { //8024B938
  return 8;
}

