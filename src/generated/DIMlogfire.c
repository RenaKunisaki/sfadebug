
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMlogfire_initialise(undefined4 param) { //802266B8
  return;
}


/* @description Called when DLL is unloaded */

void DIMlogfire_release(void) { //802266BC
  return;
}


/* Library Function - Single Match
    dll_202_func03
   
   Library: KioskDefault 0 0 */

void DIMlogfire_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //802266C0
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  undefined *puVar5;
  
  this->fptr_0xbc = DIMLogFire_SeqFn;
  Object_objAddObjectType(this,0x33);
  puVar5 = this->state;
  puVar5[0x14] = 0;
  uVar1._0_1_ = objDef[1].allocatedSize;
  uVar1._1_1_ = objDef[1].mapStates1;
  puVar5[0xc] = (char)uVar1;
  uVar2._0_1_ = objDef[1].loadFlags;
  uVar2._1_1_ = objDef[1].mapStates2;
  puVar5[0x10] = (char)uVar2;
  puVar5[0x12] = puVar5[0x10];
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  uVar4 = mainGetBit((int)sVar3);
  if (uVar4 != 0) {
    puVar5[0xe] = 1;
    puVar5[0x11] = 1;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_202_func04
   
   Library: KioskDefault 0 0 */

void DIMlogfire_update(ObjInstance *this) { //80226758
  byte bVar1;
  short sVar2;
  ObjInstance *this_00;
  ObjInstance *param2;
  bool bVar4;
  LoadedDll *pLVar3;
  ObjDef *pOVar5;
  undefined *puVar6;
  double dVar7;
  
  puVar6 = this->state;
  pOVar5 = this->def;
  bVar1 = puVar6[0xe];
  if (bVar1 != 3) {
    if (bVar1 < 3) {
      if (bVar1 == 1) {
        audioTryStartSfx((int *)this,0x40,300,0x7f,"DIMlogfire.c",0x8b);
        goto LAB_80226874;
      }
      if (bVar1 != 0) {
        if ((char)puVar6[0x10] < '\x01') {
          FUN_80088da4((int)this);
          puVar6[0xe] = 1;
          puVar6[0x11] = 1;
          sVar2._0_1_ = pOVar5[1].bound;
          sVar2._1_1_ = pOVar5[1].cullDist;
          mainSetBits((int)sVar2,1);
        }
        this_00 = Object_getSidekicksLoaded();
        if (this_00 != (ObjInstance *)0x0) {
          param2 = Object_objGetMain();
          dVar7 = (double)objDistSqObj2Obj(this,param2);
          if (dVar7 <= 10000.0) {
            (*this_00->dll->ptrs2[1].hitDetect)(this_00);
          }
        }
        goto LAB_80226874;
      }
    }
    else if (bVar1 < 5) goto LAB_80226874;
  }
  if (puVar6[0xc] == '\0') {
    puVar6[0xe] = 1;
    puVar6[0x11] = 1;
  }
  else {
    puVar6[0xe] = 2;
  }
LAB_80226874:
  if ((puVar6[0x11] != '\0') && (bVar4 = checkSomeDebugFlags_8017c4f8(), !bVar4)) {
                    /* {@symbol 800e3c34} */
    (**(code **)(*(int *)pDll_projgfx + 0x2c))(this);
    pLVar3 = (LoadedDll *)runlinkDownloadCode(0x100c,1);
    (**(code **)(pLVar3->id + 4))(this,0,0,&DAT_00010004,0xffffffff,0);
    DLL_free(pLVar3);
    pLVar3 = (LoadedDll *)runlinkDownloadCode(0x100b,1);
    (**(code **)(pLVar3->id + 4))(this,0,0,&DAT_00010004,0xffffffff,0);
    DLL_free(pLVar3);
    pLVar3 = (LoadedDll *)runlinkDownloadCode(0x100a,1);
    (**(code **)(pLVar3->id + 4))(this,0,0,&DAT_00010004,0xffffffff,0);
    DLL_free(pLVar3);
    puVar6[0x11] = 0;
  }
  return;
}


/* @description Override hit detection */

void DIMlogfire_hitDetect(ObjInstance *this) { //8022698C
  return;
}


/* Library Function - Single Match
    dll_202_func06
   
   Library: KioskDefault 0 0 */

void DIMlogfire_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80226990
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  Mtx44 *pMVar1;
  ObjInstance **ppOVar2;
  
  if (shouldRender) {
    ppOVar2 = (ObjInstance **)this->state;
    if (*ppOVar2 != (ObjInstance *)0x0) {
      pMVar1 = (*ppOVar2)->modelInstances->mtxs[(char)(*ppOVar2)->curModel + -3];
      *(ushort *)&pMVar1->m23 = *(ushort *)&pMVar1->m23 & 0xfff7;
      (*ppOVar2)->opacity = this->opacity;
      objRenderCurrentModel
                (*ppOVar2,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_202_func07
   
   Library: KioskDefault 0 0 */

void DIMlogfire_free(ObjInstance *this,int param2) { //80226A54
  ObjInstance **ppOVar1;
  
  ppOVar1 = (ObjInstance **)this->state;
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  if ((*ppOVar1 != (ObjInstance *)0x0) && (param2 == 0)) {
    Object_objFreeObject(*ppOVar1);
  }
  Object_removePlayerObj(this,0x33);
  return;
}


undefined4 DIMlogfire_func08(ObjInstance *this) { //80226AE0
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int DIMlogfire_getExtraSize(void) { //80226AE8
  return 0x18;
}


/* Library Function - Single Match
    dll_202_func0A
   
   Library: KioskDefault 0 0 */

void DIMlogfire_setScale(ObjInstance *this,float scale) { //80226AF0
  char in_r4;
  
  this->state[0x10] = this->state[0x10] - in_r4;
  return;
}

