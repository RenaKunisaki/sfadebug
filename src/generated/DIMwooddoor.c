
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMwooddoor_initialise(undefined4 param) { //8022A080
  return;
}


/* @description Called when DLL is unloaded */

void DIMwooddoor_release(void) { //8022A084
  return;
}


/* Library Function - Single Match
    dll_20D_func03
   
   Library: KioskDefault 0 0 */

void DIMwooddoor_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8022A088
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  puVar3 = this->state;
  *puVar3 = 3;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    *puVar3 = 0;
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    this->newOpacity = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_20D_func04
   
   Library: KioskDefault 0 0 */

void DIMwooddoor_update(ObjInstance *this) { //8022A110
  char cVar1;
  short sVar2;
  bool bVar3;
  ObjDef *pOVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  pOVar4 = this->def;
  pcVar7 = this->state;
  if (*pcVar7 < '\x01') {
    iVar6 = (uint)this->newOpacity + (uint)framesThisStep * -0x10;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    this->newOpacity = (u8)iVar6;
  }
  else {
    bVar3 = false;
    for (iVar6 = 0; iVar6 < (char)this->field18_0x58->field144_0x10f; iVar6 = iVar6 + 1) {
      iVar5 = *(int *)((int)(this->field18_0x58->mtx + 2) + iVar6 * 4);
      if ((*(short *)(iVar5 + 0x46) == 399) || (*(short *)(iVar5 + 0x46) == 0x1d6)) {
        bVar3 = true;
        break;
      }
    }
    if (bVar3) {
      cVar1 = *pcVar7;
      *pcVar7 = cVar1 + -1;
      if ((char)(cVar1 + -1) < '\x01') {
        sVar2._0_1_ = pOVar4[1].bound;
        sVar2._1_1_ = pOVar4[1].cullDist;
        mainSetBits((int)sVar2,1);
        audioTryStartSfx((int *)this,1,500,0x7f,"DIMwooddoor.c",0x76);
      }
      else {
        audioTryStartSfx((int *)this,1,0x22d,0x7f,"DIMwooddoor.c",0x78);
      }
      iVar6 = 3 - *pcVar7;
      if (2 < iVar6) {
        iVar6 = 2;
      }
      if ((char)this->curModel != iVar6) {
        objSetModelNo(this,iVar6);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void DIMwooddoor_hitDetect(ObjInstance *this) { //8022A27C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIMwooddoor_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //8022A280
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

void DIMwooddoor_free(ObjInstance *this,int param2) { //8022A2DC
  return;
}


undefined4 DIMwooddoor_func08(ObjInstance *this) { //8022A2E0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIMwooddoor_getExtraSize(void) { //8022A2E8
  return 1;
}

