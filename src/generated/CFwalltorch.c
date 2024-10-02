
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFwalltorch_initialise(undefined4 param) { //802149B4
  return;
}


/* @description Called when DLL is unloaded */

void CFwalltorch_release(void) { //802149B8
  return;
}


/* Library Function - Single Match
    dll_17E_func03
   
   Library: KioskDefault 0 0 */

void CFwalltorch_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802149BC
  short sVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  LoadedDll *dll;
  undefined4 *puVar5;
  undefined auStack_34 [16];
  float local_24;
  undefined4 local_18;
  uint uStack_14;
  
  puVar5 = (undefined4 *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 10);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 < 1) {
    (this->pos).scale = 0.1;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    uStack_14 = (int)sVar2 ^ 0x80000000;
    local_18 = 0x43300000;
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) / 8192.0;
  }
  *puVar5 = DAT_80399e40;
  *(undefined *)((int)puVar5 + 6) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined *)((int)puVar5 + 7) = 0;
  *(undefined *)((int)puVar5 + 10) = 0;
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  puVar5[3] = (int)sVar3;
  bVar4 = checkSomeDebugFlags_8017c4f8();
  if (!bVar4) {
    local_24 = -2.0;
    *(undefined *)((int)puVar5 + 7) = 1;
    dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
    (**(code **)(dll->id + 4))(this,0,auStack_34,&DAT_00010004,0xffffffff,0);
    DLL_free(dll);
  }
  *(undefined2 *)(puVar5 + 1) = 0;
  Object_objAddObjectType(this,0x2f);
  return;
}


/* Library Function - Single Match
    dll_17E_func04
   
   Library: KioskDefault 0 0 */

void CFwalltorch_update(ObjInstance *this) { //80214AE0
  ObjInstance *param1;
  bool bVar1;
  int *piVar2;
  double in_f1;
  
  piVar2 = (int *)this->state;
  param1 = Object_objGetMain();
  objDistObj2Obj(param1,this);
  bVar1 = FUN_80068b20((int)this,0x40);
  if (bVar1) {
    if ((90.0 <= in_f1) && (*(char *)((int)piVar2 + 7) != '\0')) {
      FUN_80068a9c((uint)this,0x40);
    }
  }
  else if ((in_f1 < 90.0) && (*(char *)((int)piVar2 + 7) != '\0')) {
    audioTryStartSfx((int *)this,0x40,300,0x7f,"CFwalltorch.c",0x8a);
  }
  if ((in_f1 < 75.0) && (*piVar2 != 0)) {
    *(float *)(DAT_80399e40 + 0xc) = (this->pos).pos.x;
    *(float *)(DAT_80399e40 + 0x10) = (this->pos).pos.y;
    *(float *)(DAT_80399e40 + 0x14) = (this->pos).pos.z;
  }
  return;
}


/* @description Override hit detection */

void CFwalltorch_hitDetect(ObjInstance *this) { //80214C10
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void CFwalltorch_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80214C14
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
    dll_17E_func07
   
   Library: KioskDefault 0 0 */

void CFwalltorch_free(ObjInstance *this,int param2) { //80214C70
  ObjInstance **ppOVar1;
  int local_10 [2];
  
  ppOVar1 = (ObjInstance **)this->state;
  Object_removePlayerObj(this,0x2f);
  if ((param2 == 0) && (*ppOVar1 != (ObjInstance *)0x0)) {
    Object_playerGetObject(0x2f,local_10);
    if (local_10[0] == 0) {
      Object_objFreeObject(*ppOVar1);
      DAT_80399e40 = 0;
    }
    *ppOVar1 = (ObjInstance *)0x0;
  }
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 CFwalltorch_func08(ObjInstance *this) { //80214D24
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int CFwalltorch_getExtraSize(void) { //80214D2C
  return 0x14;
}

