
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFlevelControl_initialise(undefined4 param) { //80212368
  return;
}


/* @description Called when DLL is unloaded */

void CFlevelControl_release(void) { //8021236C
  return;
}


/* Library Function - Single Match
    dll_17B_func03
   
   Library: KioskDefault 0 0 */

void CFlevelControl_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //80212370
  short *param1;
  
  param1 = (short *)this->state;
  *(undefined *)((int)param1 + 3) = 1;
  DAT_80399e30 = mainGetBit(0x575);
  resetGroupLoadFn_80212974((int)this,-0x7fcea5d0,DAT_80397cec);
  DAT_80399e34 = runlinkDownloadCode(0x2004,1);
  DLL_createTempDll(0x33);
  timerReset(param1);
  timerSet(param1,0x1e0);
                    /* {@symbol 8012e228} */
  (**(code **)(*(int *)pDll_SaveGame + 0x50))(0xc,2,1);
  return;
}


/* Library Function - Single Match
    dll_17B_func04
   
   Library: KioskDefault 0 0 */

void CFlevelControl_update(ObjInstance *this) { //80212410
  ObjInstance *pOVar1;
  uint uVar2;
  uint uVar3;
  ObjInstance *pOVar4;
  int iVar5;
  BOOL BVar6;
  short *param1;
  
  param1 = (short *)this->state;
  pOVar1 = Object_objGetMain();
  loadGroupFn_80212744((int)this,-0x7fcea5d0,DAT_80397cec);
  FUN_80212acc(0x4dd,(short *)&DAT_80397cd8,2);
  freeBabyFn_80212b78((int *)&PTR_DAT_803159b4,3);
  uVar2 = mainGetBit(0x526);
  if (uVar2 == 0) {
    FUN_80212c40((short *)&DAT_80397cf0,1);
  }
  FUN_80212cd4();
  for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
    uVar3 = mainGetBit((&DAT_80315ab8)[uVar2]);
    if (uVar3 != 0) {
      FUN_8016eb28((&DAT_80315a98)[uVar2],'\0');
      pOVar4 = Object_objGetMain();
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0xf,pOVar4,0xffffffff);
      mainSetBits((&DAT_80315ab8)[uVar2],0);
    }
  }
  uVar2 = mainGetBit(0x94f);
  if (uVar2 != 0) {
    mainSetBits(0x94e,0);
  }
  uVar2 = mainGetBit(0x94e);
  if (((uVar2 == 0) || (iVar5 = FUN_801a8904(), iVar5 == 0)) ||
     (BVar6 = krystalIsClaw(pOVar1), BVar6 != FALSE)) {
    if (((uVar2 == 0) && (iVar5 = FUN_801a8904(), iVar5 == 0)) &&
       (BVar6 = krystalIsClaw(pOVar1), BVar6 == FALSE)) {
      pOVar1 = Object_objGetMain();
      foxWeaponFn_801a87b4((int)pOVar1,1);
    }
  }
  else {
    pOVar1 = Object_objGetMain();
    foxWeaponFn_801a87b4((int)pOVar1,0);
  }
  uVar2 = mainGetBit(0x212);
  if ((uVar2 != 0) && (iVar5 = timerTickDown(param1), iVar5 != 0)) {
    audioPlaySong(0x16,4);
  }
  uVar2 = mainGetBit(0x983);
  if (uVar2 != 0) {
    audioPlaySong(0x18,4);
    mainSetBits(0x983,0);
  }
  uVar2 = mainGetBit(0x985);
  if (uVar2 != 0) {
    audioPlaySong(0x17,4);
    mainSetBits(0x985,0);
  }
  uVar2 = mainGetBit(0x984);
  if (uVar2 != 0) {
    audioPlaySong(0x15,4);
    mainSetBits(0x984,0);
  }
  nop_80212D44();
  return;
}


/* @description Override hit detection */

void CFlevelControl_hitDetect(ObjInstance *this) { //8021265C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void CFlevelControl_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80212660
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
    dll_17B_func07
   
   Library: KioskDefault 0 0 */

void CFlevelControl_free(ObjInstance *this,int param2) { //802126BC
  DLL_removeTempDll(0x33);
  if (DAT_80399e34 != (LoadedDll *)0x0) {
    DLL_free(DAT_80399e34);
  }
  DAT_80399e34 = (LoadedDll *)0x0;
  return;
}


undefined4 CFlevelControl_func08(ObjInstance *this) { //802126FC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int CFlevelControl_getExtraSize(void) { //80212704
  return 6;
}

