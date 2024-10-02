
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRlaserturret_initialise(undefined4 param) { //802B0104
  return;
}


/* @description Called when DLL is unloaded */

void DRlaserturret_release(void) { //802B0108
  return;
}


/* Library Function - Single Match
    DRlaserturret_func03
   
   Library: KioskDefault 0 0 */

void DRlaserturret_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //802B010C
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  puVar5[0x78] = 5;
  FUN_80088d3c((int)this);
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    (this->pos).flags = (this->pos).flags | Invisible;
    objFreeFn_80083b54(this);
    FUN_80088da4((int)this);
  }
  Object_objAddObjectType(this,4);
  if (this->romdefno != DR_LaserCan) {
    Object_ObjAnimSetMove(1.0,this,3,0);
  }
  if (obj2 == (ObjInstance *)0x0) {
    for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
      uVar3 = FUN_802b0d0c((int)this);
      *(undefined4 *)(puVar5 + iVar4 * 4) = uVar3;
    }
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *(undefined4 *)(puVar5 + 0x24) = 600;
  return;
}


/* Library Function - Single Match
    DRlaserturret_func04
   
   Library: KioskDefault 0 0 */

void DRlaserturret_update(ObjInstance *this) { //802B01F4
  short sVar1;
  short sVar2;
  short sVar3;
  ObjInstance *pOVar4;
  ObjInstance *pOVar5;
  short sVar7;
  int iVar6;
  ObjDef *pOVar8;
  undefined *puVar9;
  double dVar10;
  
  puVar9 = this->state;
  pOVar8 = this->def;
  if ((char)puVar9[0x28] < '\0') {
    (this->pos).flags = (this->pos).flags | Invisible;
    objFreeFn_80083b54(this);
    FUN_80088da4((int)this);
    return;
  }
  pOVar4 = dTimeFn_802b0854(this,(int *)(puVar9 + 0x24));
  if (pOVar4 == (ObjInstance *)0x0) goto LAB_802b0554;
  dVar10 = (double)objDistObj2ObjXZ(pOVar4,this);
  *(uint *)(puVar9 + 0x2c) = *(int *)(puVar9 + 0x2c) + (uint)framesThisStep;
  sVar7._0_1_ = pOVar8[1].allocatedSize;
  sVar7._1_1_ = pOVar8[1].mapStates1;
  if ((double)(float)((double)CONCAT44(0x43300000,(int)sVar7 ^ 0x80000000) - 4503601774854144.0) <=
      dVar10) {
    if (((byte)puVar9[0x28] >> 6 & 1) != 0) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(2,this,0xffffffff);
      puVar9[0x28] = puVar9[0x28] & 0xbf;
    }
    goto LAB_802b0554;
  }
  pOVar5 = Object_getSidekicksLoaded();
  if ((pOVar4 != pOVar5) && (this->romdefno == DR_LaserCan)) {
    if ((((byte)puVar9[0x79] >> 6 & 1) == 0) && (dVar10 < 150.0)) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(4,this,0xffffffff);
      puVar9[0x79] = puVar9[0x79] & 0xbf | 0x40;
      return;
    }
    if ((((byte)puVar9[0x79] >> 6 & 1) != 0) && (170.0 < dVar10)) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(3,this,0xffffffff);
      puVar9[0x79] = puVar9[0x79] & 0xbf;
      return;
    }
  }
  if (((byte)puVar9[0x79] >> 6 & 1) != 0) goto LAB_802b0554;
  if (this->romdefno == DR_LaserCan) {
    FUN_802b0db0((int)this,0);
  }
  if (((byte)puVar9[0x28] >> 6 & 1) == 0) {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
    puVar9[0x28] = puVar9[0x28] & 0xbf | 0x40;
    return;
  }
  if ((uint)((int)*(char *)((int)&pOVar8[1].objType + 1) << 2) < *(uint *)(puVar9 + 0x2c)) {
    sVar1._0_1_ = pOVar8[1].loadFlags;
    sVar1._1_1_ = pOVar8[1].mapStates2;
    if (sVar1 != 0x168) {
      sVar7 = objDistFn_80091a84((int)this,(int)pOVar4,(float *)0x0);
      if (sVar7 < 0) {
        sVar7 = objDistFn_80091a84((int)this,(int)pOVar4,(float *)0x0);
        iVar6 = -(int)sVar7;
      }
      else {
        sVar7 = objDistFn_80091a84((int)this,(int)pOVar4,(float *)0x0);
        iVar6 = (int)sVar7;
      }
      sVar2._0_1_ = pOVar8[1].loadFlags;
      sVar2._1_1_ = pOVar8[1].mapStates2;
      if ((short)(int)((float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) -
                              4503601774854144.0) * 182.04) <= iVar6) goto LAB_802b04d8;
    }
    audioTryStartSfx((int *)this,0x20,0x1f0,0x7f,"DRlaserturret.c",0xc6);
    FUN_802b0c18(6.0,(int)this,(int)pOVar4,(undefined4 *)(puVar9 + 0x18));
    Object_ObjAnimSetMove(0.0,this,0,0);
    audioTryStartSfx((int *)this,1,0x1ef,0x7f,"DRlaserturret.c",0xc9);
    *(undefined4 *)(puVar9 + 0x2c) = 0;
  }
LAB_802b04d8:
  sVar3._0_1_ = pOVar8[1].loadFlags;
  sVar3._1_1_ = pOVar8[1].mapStates2;
  iVar6 = FUN_802b0958((short *)this,(int)pOVar4,(int)(puVar9 + 0x30),(int)sVar3);
  if (iVar6 != 0) {
    audioTryStartSfx((int *)this,0x88,0x210,100,"DRlaserturret.c",0xd0);
  }
LAB_802b0554:
  diPrintf(" Turret Timer %i ",*(undefined4 *)(puVar9 + 0x2c));
  pOVar4 = Object_getSidekicksLoaded();
  if (pOVar4 != (ObjInstance *)0x0) {
    (*pOVar4->dll->ptrs2[1].hitDetect)(pOVar4);
  }
  objRunAnimation(0.01799999922513962,(double)timeDelta,(int)this,(float *)0x0);
  return;
}


/* Library Function - Single Match
    DRlaserturret_func05
   
   Library: KioskDefault 0 0 */

void DRlaserturret_hitDetect(ObjInstance *param1) { //802B05C0
  short sVar1;
  ObjInstance *this;
  int param1_00;
  LoadedDll *dll;
  ObjDef *pOVar2;
  undefined *puVar3;
  undefined auStack_3c [24];
  int local_24;
  undefined *local_20;
  uint local_1c;
  
  puVar3 = param1->state;
  local_20 = &DAT_000f0014;
  this = Object_getSidekicksLoaded();
  pOVar2 = param1->def;
  memclr(auStack_3c,0x18);
  if (-1 < (char)puVar3[0x28]) {
    param1_00 = FUN_800883e4((int)param1,&local_24,(int *)0x0,&local_1c);
    if (param1_00 != 0) {
      printf(" HHITS %i %i ",param1_00,local_1c);
    }
    if (param1_00 == 5) {
      if (*(int *)(puVar3 + 0x14) != local_24) {
        *(int *)(puVar3 + 0x14) = local_24;
        puVar3[0x78] = puVar3[0x78] - (char)local_1c;
        if ((char)puVar3[0x78] < '\x01') {
          puVar3[0x28] = puVar3[0x28] & 0x7f | 0x80;
          sVar1._0_1_ = pOVar2[1].bound;
          sVar1._1_1_ = pOVar2[1].cullDist;
          mainSetBits((int)sVar1,1);
          if (this != (ObjInstance *)0x0) {
            (*this->dll->ptrs2[1].modelMtxFn_0x28)(this,0,(vec3f *)0x0);
          }
          dll = (LoadedDll *)runlinkDownloadCode(0x104c,1);
          (**(code **)(dll->id + 4))(param1,0,auStack_3c,2,0xffffffff,&local_20);
          DLL_free(dll);
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,param1,0xffffffff);
        }
      }
    }
    if (param1_00 == 0) {
      *(undefined4 *)(puVar3 + 0x14) = 0;
    }
  }
  return;
}


/* Library Function - Single Match
    DRlaserturret_func06
   
   Library: KioskDefault 0 0 */

void DRlaserturret_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802B0740
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    objGetAttachPointWorldPos
              (this,0,(float *)(puVar1 + 0x18),(float *)(puVar1 + 0x1c),(float *)(puVar1 + 0x20),
               FALSE);
  }
  return;
}


/* Library Function - Single Match
    DRlaserturret_func07
   
   Library: KioskDefault 0 0 */

void DRlaserturret_free(ObjInstance *this,int param2) { //802B07C4
  undefined *puVar1;
  int iVar2;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
  if (param2 == 0) {
    for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
      (**(code **)(**(int **)(*(int *)(puVar1 + iVar2 * 4) + 0x68) + 0x28))
                (*(undefined4 *)(puVar1 + iVar2 * 4));
    }
  }
  return;
}


undefined4 DRlaserturret_func08(ObjInstance *this) { //802B0844
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRlaserturret_getExtraSize(void) { //802B084C
  return 0x7c;
}

