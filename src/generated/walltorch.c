
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void walltorch248_initialise(undefined4 param) { //802830D4
  return;
}


/* @description Called when DLL is unloaded */

void walltorch248_release(void) { //802830D8
  return;
}


/* Library Function - Single Match
    dll_248_func03
   
   Library: KioskDefault 0 0 */

void walltorch248_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //802830DC
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  bool bVar7;
  LoadedDll *dll;
  undefined4 uVar8;
  undefined *puVar9;
  undefined auStack_3c [16];
  float local_2c;
  undefined4 local_20;
  uint uStack_1c;
  
  puVar9 = this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 10);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  if (sVar1 < 1) {
    (this->pos).scale = 0.1;
  }
  else {
    sVar2._0_1_ = objDef[1].allocatedSize;
    sVar2._1_1_ = objDef[1].mapStates1;
    uStack_1c = (int)sVar2 ^ 0x80000000;
    local_20 = 0x43300000;
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0) / 8192.0;
  }
  puVar9[6] = *(undefined *)((int)&objDef[1].objType + 1);
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  *(int *)(puVar9 + 0xc) = (int)sVar3;
  sVar4._0_1_ = objDef[1].loadFlags;
  sVar4._1_1_ = objDef[1].mapStates2;
  this->curModel = (byte)((uint)(int)sVar4 >> 1) & 1;
  bVar7 = checkSomeDebugFlags_8017c4f8();
  if ((!bVar7) && (local_2c = -2.0, puVar9[6] == '\0')) {
    puVar9[7] = 1;
    dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
    uVar5._0_1_ = objDef[1].loadFlags;
    uVar5._1_1_ = objDef[1].mapStates2;
    if ((uVar5 & 4) == 0) {
      uVar6._0_1_ = objDef[1].loadFlags;
      uVar6._1_1_ = objDef[1].mapStates2;
      if ((uVar6 & 1) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 1;
      }
    }
    else {
      uVar8 = 2;
    }
    (**(code **)(dll->id + 4))(this,uVar8,auStack_3c,&DAT_00010004,0xffffffff,0);
    DLL_free(dll);
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_248_func04
   
   Library: KioskDefault 0 0 */

void walltorch248_update(ObjInstance *this) { //8028322C
  ObjInstance *pOVar1;
  ObjDef *pOVar2;
  int iVar3;
  LoadedDll *dll;
  uint uVar4;
  ObjInstance **ppOVar5;
  double in_f1;
  undefined auStack_3c [16];
  float local_2c;
  
  ppOVar5 = (ObjInstance **)this->state;
  pOVar1 = Object_objGetMain();
  objDistObj2Obj(pOVar1,this);
  if ((*ppOVar5 != (ObjInstance *)0x0) && (((*ppOVar5)->flags_0xb0 & IsFreed) != 0)) {
    *ppOVar5 = (ObjInstance *)0x0;
  }
  if (*(char *)((int)ppOVar5 + 6) == '\x01') {
    local_2c = -2.0;
    *(undefined *)((int)ppOVar5 + 9) = *(undefined *)((int)ppOVar5 + 7);
    iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if (iVar3 != 0) {
      *(char *)((int)ppOVar5 + 7) = '\x01' - *(char *)((int)ppOVar5 + 7);
    }
    if (((*(char *)((int)ppOVar5 + 7) != '\0') && (*(short *)(ppOVar5 + 1) < 1)) &&
       (*(char *)(ppOVar5 + 2) != '\0')) {
      *(undefined *)(ppOVar5 + 2) = 0;
      audioTryStartSfx((int *)this,1,0x37,0x7f,"walltorch.c",0xca);
    }
    if (*(char *)((int)ppOVar5 + 7) != *(char *)((int)ppOVar5 + 9)) {
      if (*(char *)((int)ppOVar5 + 7) == '\0') {
        FUN_80068a9c((uint)this,0x40);
                    /* {@symbol 800e2b88} */
        (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc1d4} */
        (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        if ((ppOVar5[3] != (ObjInstance *)0xffffffff) &&
           (uVar4 = mainGetBit((int)ppOVar5[3]), uVar4 != 0)) {
          mainSetBits((int)ppOVar5[3],0);
        }
        if (*ppOVar5 != (ObjInstance *)0x0) {
          Object_objFreeObject(*ppOVar5);
          *ppOVar5 = (ObjInstance *)0x0;
        }
      }
      else {
        dll = (LoadedDll *)runlinkDownloadCode(0x1011,1);
        (**(code **)(dll->id + 4))(this,1,auStack_3c,&DAT_00010004,0xffffffff,0);
        DLL_free(dll);
        for (iVar3 = 0; iVar3 < 100; iVar3 = iVar3 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1a3,0,0,0xffffffff,0);
        }
        if ((ppOVar5[3] != (ObjInstance *)0xffffffff) &&
           (uVar4 = mainGetBit((int)ppOVar5[3]), uVar4 == 0)) {
          mainSetBits((int)ppOVar5[3],1);
        }
        *(undefined *)(ppOVar5 + 2) = 1;
        *(undefined2 *)(ppOVar5 + 1) = 1;
        if (*ppOVar5 == (ObjInstance *)0x0) {
          pOVar2 = objAlloc(0x28,LFXEmitter);
          pOVar2->loadFlags = isManualLoad;
          (pOVar2->pos).x = (this->pos).pos.x;
          (pOVar2->pos).y = (this->pos).pos.y;
          (pOVar2->pos).z = (this->pos).pos.z;
          pOVar2[1].bound = 1;
          pOVar2[1].cullDist = 0x2a;
          *(undefined2 *)((int)&pOVar2[1].pos.x + 2) = 0xffff;
          pOVar1 = objInstantiateCharacter(pOVar2,5,(int)(char)this->mapId,-1,this->pMatrix);
          *ppOVar5 = pOVar1;
        }
      }
    }
  }
  else if ((*(char *)((int)ppOVar5 + 6) == '\0') && (true)) {
    if ((75.0 <= in_f1) || (*ppOVar5 != (ObjInstance *)0x0)) {
      if ((95.0 <= in_f1) && (*ppOVar5 != (ObjInstance *)0x0)) {
        Object_objFreeObject(*ppOVar5);
        *ppOVar5 = (ObjInstance *)0x0;
      }
    }
    else {
      pOVar2 = objAlloc(0x28,LFXEmitter);
      pOVar2->loadFlags = isManualLoad;
      (pOVar2->pos).x = (this->pos).pos.x;
      (pOVar2->pos).y = (this->pos).pos.y;
      (pOVar2->pos).z = (this->pos).pos.z;
      pOVar2[1].bound = 0;
      pOVar2[1].cullDist = 0x8c;
      *(undefined2 *)((int)&pOVar2[1].pos.x + 2) = 0xffff;
      pOVar1 = objInstantiateCharacter(pOVar2,5,(int)(char)this->mapId,-1,this->pMatrix);
      *ppOVar5 = pOVar1;
    }
  }
  return;
}


/* @description Override hit detection */

void walltorch248_hitDetect(ObjInstance *this) { //802835BC
  return;
}


/* Library Function - Single Match
    dll_248_func06
   
   Library: KioskDefault 0 0 */

void walltorch248_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802835C0
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
  else {
    *(undefined2 *)(this->state + 4) = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_248_func07
   
   Library: KioskDefault 0 0 */

void walltorch248_free(ObjInstance *this,int param2) { //80283634
  ObjInstance **ppOVar1;
  
  ppOVar1 = (ObjInstance **)this->state;
  if ((param2 == 0) && (*ppOVar1 != (ObjInstance *)0x0)) {
    Object_objFreeObject(*ppOVar1);
  }
  if (*(char *)((int)ppOVar1 + 6) == '\0') {
                    /* {@symbol 800e2b88} */
    (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  }
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


/* Library Function - Single Match
    dll_248_func08
   
   Library: KioskDefault 0 0 */

uint walltorch248_func08(ObjInstance *this) { //802836C0
  short sVar1;
  
  sVar1._0_1_ = this->def[1].loadFlags;
  sVar1._1_1_ = this->def[1].mapStates2;
  return ((int)sVar1 & 2U) << 10 | 0x401;
}


/* @description Get extra size for object (size of State struct) */

int walltorch248_getExtraSize(void) { //802836E4
  return 0x10;
}

