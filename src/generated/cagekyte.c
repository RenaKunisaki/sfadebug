
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SBcagedkyte_initialise(undefined4 param) { //8026555C
  return;
}


/* @description Called when DLL is unloaded */

void SBcagedkyte_release(void) { //80265560
  return;
}


/* @description Set up object instance */

void SBcagedkyte_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80265564
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80265764;
  return;
}


/* Library Function - Single Match
    dll_233_func04
   
   Library: KioskDefault 0 0 */

void SBcagedkyte_update(ObjInstance *this) { //80265574
  ObjInstance *param2;
  bool bVar1;
  int iVar2;
  short *psVar3;
  double in_f1;
  
  psVar3 = (short *)this->state;
  if (0 < (int)this->field76_0xf4) {
    this->field76_0xf4 = this->field76_0xf4 + -1;
  }
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  iVar2 = this->pMatrix->field76_0xf4;
  if (iVar2 == 7) {
    *psVar3 = *psVar3 - (ushort)framesThisStep;
    param2 = Object_objGetMain();
    objDistObj2Obj(this,param2);
    if ((in_f1 < 280.0) && (*psVar3 < 1)) {
      iVar2 = randInt(0,10);
      audioTryStartSfx((int *)this,1,(&DAT_80397ef0)[7 < iVar2],0x7f,(char *)&PTR_DAT_8031bf48,0x66)
      ;
      iVar2 = randInt(400,600);
      *psVar3 = (short)iVar2;
    }
  }
  else if (8 < iVar2) {
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    bVar1 = FUN_80068b20((int)this,1);
    if (bVar1) {
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      FUN_80068a9c((uint)this,1);
    }
  }
  return;
}


/* @description Override hit detection */

void SBcagedkyte_hitDetect(ObjInstance *this) { //802656CC
  return;
}


/* Library Function - Single Match
    dll_233_func06
   
   Library: KioskDefault 0 0 */

void SBcagedkyte_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802656D0
  uint uVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (((shouldRender) && (uVar1 = mainGetBit(0xd0), uVar1 == 0)) && (this->field76_0xf4 == 0)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void SBcagedkyte_free(ObjInstance *this,int param2) { //80265750
  return;
}


undefined4 SBcagedkyte_func08(ObjInstance *this) { //80265754
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int SBcagedkyte_getExtraSize(void) { //8026575C
  return 2;
}

