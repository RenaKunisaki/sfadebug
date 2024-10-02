
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFPrisonGuard_initialise(undefined4 param) { //80207984
  return;
}


/* @description Called when DLL is unloaded */

void CFPrisonGuard_release(void) { //80207988
  return;
}


/* Library Function - Single Match
    CFPrisonGuard_func03
   
   Library: KioskDefault 0 0 */

void CFPrisonGuard_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8020798C
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  puVar2[8] = 1;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->fptr_0xbc = FUN_80207d40;
  objAllocMsgQueue(this,4);
  puVar2[6] = 1;
  uVar1 = mainGetBit(0x4d);
  if (uVar1 != 0) {
    puVar2[8] = puVar2[8] | 4;
  }
  this->flags_0xaf = this->flags_0xaf & ~PlayerIsDisguised;
  puVar2[9] = puVar2[9] & 0x7f | 0x80;
  return;
}


/* Library Function - Single Match
    CFPrisonGuard_func04
   
   Library: KioskDefault 0 0 */

void CFPrisonGuard_update(ObjInstance *this) { //80207A34
  short sVar1;
  ObjInstance *param2;
  uint uVar2;
  int iVar3;
  ObjDef *pOVar4;
  undefined *puVar5;
  double in_f1;
  
  puVar5 = this->state;
  param2 = Object_objGetMain();
  pOVar4 = this->def;
  if ((char)puVar5[9] < '\0') {
    FUN_800d5708(1);
    FUN_800d5730(-0.1000000014901161,-0.1000000014901161,1.0);
    in_f1 = (double)FUN_800d5710(0x8c,0x96,0xb4,0x82,0x6e);
    puVar5[9] = puVar5[9] & 0x7f;
  }
  if (puVar5[7] == '\x05') {
    printf(" Removing Guard ");
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    (this->pos).flags = (this->pos).flags | Invisible;
    in_f1 = (double)objFreeFn_80083b54(this);
  }
  uVar2 = mainGetBit(0x44);
  objDistObj2Obj(this,param2);
  if (uVar2 == 0) {
    sVar1._0_1_ = pOVar4[1].allocatedSize;
    sVar1._1_1_ = pOVar4[1].mapStates1;
    if ((in_f1 < (double)(float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                                4503601774854144.0)) &&
       (iVar3 = FUN_801a7998((int)param2), iVar3 != 0x40)) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
    }
  }
  if (puVar5[8] == '\x01') {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
    puVar5[8] = 2;
  }
  return;
}


/* Library Function - Single Match
    CFPrisonGuard_func05
   
   Library: KioskDefault 0 0 */

void CFPrisonGuard_hitDetect(ObjInstance *param1) { //80207BAC
  int iVar1;
  undefined *puVar2;
  
  puVar2 = param1->state;
  iVar1 = FUN_800883e4((int)param1,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if (iVar1 == 0x13) {
    printf(" Hit By Projectile My Friend");
    puVar2[7] = 7;
  }
  return;
}


/* Library Function - Single Match
    CFPrisonGuard_func06
   
   Library: KioskDefault 0 0 */

void CFPrisonGuard_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80207C10
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar1;
  
  pfVar1 = (float *)this->state;
  if ((shouldRender) &&
     (objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5)), 0.0 < *pfVar1)) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,(uint)framesThisStep) - 4503599627370496.0) * 0.01
              + *pfVar1;
    if (1.5 <= *pfVar1) {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,pfVar1);
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,pfVar1);
    }
    else {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x32f,pfVar1);
    }
  }
  return;
}


/* @description Free object instance */

void CFPrisonGuard_free(ObjInstance *this,int param2) { //80207D2C
  return;
}


undefined4 CFPrisonGuard_func08(ObjInstance *this) { //80207D30
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int CFPrisonGuard_getExtraSize(void) { //80207D38
  return 0xc;
}

