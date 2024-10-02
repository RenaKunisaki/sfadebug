
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void TREX_trex_initialise(undefined4 param) { //802ABCB4
  trexInitFuncPtrs_802aef2c();
  return;
}


/* @description Called when DLL is unloaded */

void TREX_trex_release(void) { //802ABCD4
  return;
}


/* Library Function - Single Match
    dll_299_func03
   
   Library: KioskDefault 0 0 */

void TREX_trex_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802ABCD8
  short sVar1;
  DtypeStack *pDVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  DtypeStack **ppDVar7;
  ObjDef *local_2c;
  ObjInstance *local_28;
  
  puVar5 = this->state;
  uVar4 = 0x10;
  if (obj2 != (ObjInstance *)0x0) {
    uVar4 = 0x11;
  }
  local_2c = objDef;
  local_28 = obj2;
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))
            (0x4034000000000000,this,&local_2c,puVar5,9,0xc,0x100,uVar4);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802aca68;
                    /* {@symbol 8011c3c0} */
  (**(code **)(*(int *)pDll11 + 0x14))(this,puVar5,0);
  *(undefined2 *)(puVar5 + 0x268) = 2;
  *(undefined4 *)(puVar5 + 0x2c8) = 0;
  puVar5[0x25b] = 0;
  puVar5[0x33d] = 0;
  this->flags_0xaf = this->flags_0xaf | 0x88;
  FUN_80088d3c((int)this);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
  }
  ppDVar7 = *(DtypeStack ***)(puVar5 + 0x3f0);
  pDVar2 = stackCreate(4,4);
  *ppDVar7 = pDVar2;
  sVar1 = (short)((int)*(char *)((int)&local_2c[1].pos.z + 2) << 8);
  (this->pos).rotation.x = sVar1;
  *(short *)(ppDVar7 + 0x3e) = sVar1;
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
                    /* {@symbol 8012464c} */
    iVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))((&PTR_DAT_803233bc)[iVar6]);
    if (iVar3 != 0) {
      ppDVar7[iVar6 + 4] = *(DtypeStack **)(iVar3 + 8);
      ppDVar7[iVar6 + 8] = *(DtypeStack **)(iVar3 + 0xc);
      ppDVar7[iVar6 + 0xc] = *(DtypeStack **)(iVar3 + 0x10);
                    /* {@symbol 8012464c} */
      iVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))((&PTR_DAT_803233ac)[iVar6]);
      ppDVar7[iVar6 + 0x10] = *(DtypeStack **)(iVar3 + 8);
      ppDVar7[iVar6 + 0x14] = *(DtypeStack **)(iVar3 + 0xc);
      ppDVar7[iVar6 + 0x18] = *(DtypeStack **)(iVar3 + 0x10);
                    /* {@symbol 8012464c} */
      iVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))((&PTR_DAT_803233dc)[iVar6]);
      ppDVar7[iVar6 + 0x1c] = *(DtypeStack **)(iVar3 + 8);
      ppDVar7[iVar6 + 0x20] = *(DtypeStack **)(iVar3 + 0xc);
      ppDVar7[iVar6 + 0x24] = *(DtypeStack **)(iVar3 + 0x10);
                    /* {@symbol 8012464c} */
      iVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))((&PTR_DAT_803233cc)[iVar6]);
      ppDVar7[iVar6 + 0x28] = *(DtypeStack **)(iVar3 + 8);
      ppDVar7[iVar6 + 0x2c] = *(DtypeStack **)(iVar3 + 0xc);
      ppDVar7[iVar6 + 0x30] = *(DtypeStack **)(iVar3 + 0x10);
    }
  }
  ppDVar7[0x34] = (DtypeStack *)(ppDVar7 + 4);
  ppDVar7[0x35] = (DtypeStack *)(ppDVar7 + 8);
  ppDVar7[0x36] = (DtypeStack *)(ppDVar7 + 0xc);
  ppDVar7[0x37] = (DtypeStack *)(ppDVar7 + 0x10);
  ppDVar7[0x38] = (DtypeStack *)(ppDVar7 + 0x14);
  ppDVar7[0x39] = (DtypeStack *)(ppDVar7 + 0x18);
  *(undefined *)((int)ppDVar7 + 0x102) = 4;
  DAT_8039a140 = runlinkDownloadCode(0x1002,1);
  return;
}


/* Library Function - Single Match
    dll_299_func04
   
   Library: KioskDefault 0 0 */

void TREX_trex_update(ObjInstance *this) { //802ABFC0
  float fVar1;
  float fVar2;
  float fVar3;
  undefined *puVar4;
  ObjInstance *pOVar5;
  uint uVar6;
  undefined uVar7;
  double dVar8;
  
  if (this->field76_0xf4 == 0) {
    puVar4 = this->state;
    DAT_8039a13c = *(int *)(puVar4 + 0x3f0);
    DAT_8039a138 = puVar4;
    FUN_8008b5f8((undefined *)this);
    pOVar5 = Object_objGetMain();
    *(ObjInstance **)(puVar4 + 0x2c8) = pOVar5;
    if (*(int *)(puVar4 + 0x2c8) != 0) {
      fVar1 = *(float *)(*(int *)(puVar4 + 0x2c8) + 0x18) - (this->prevPos).x;
      fVar2 = *(float *)(*(int *)(puVar4 + 0x2c8) + 0x1c) - (this->prevPos).y;
      fVar3 = *(float *)(*(int *)(puVar4 + 0x2c8) + 0x20) - (this->prevPos).z;
      dVar8 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
      *(float *)(puVar4 + 0x2b8) = (float)dVar8;
    }
    FUN_800928ac((int)this,(int)(DAT_8039a138 + 0x3b8));
    uVar6 = FUN_802ac52c();
    *(char *)(DAT_8039a13c + 0xff) = (char)uVar6;
    dVar8 = (double)FUN_802ac5b0(*(int *)(puVar4 + 0x2c8),DAT_8039a13c);
    *(float *)(DAT_8039a13c + 0xf4) = (float)dVar8;
    uVar7 = FUN_802ac590((uint)*(ushort *)(DAT_8039a13c + 0xfa));
    *(undefined *)(DAT_8039a13c + 0xfe) = uVar7;
    uVar6 = FUN_802ac678(*(byte *)(DAT_8039a13c + 0xfe));
    *(char *)(DAT_8039a13c + 0x100) = (char)uVar6;
                    /* {@symbol 80163660} */
    (**(code **)(*(int *)pDll_partfx1F + 0x54))
              (this,puVar4,DAT_8039a138 + 0x34c,(int)*(short *)(DAT_8039a138 + 0x39e),
               DAT_8039a138 + 0x3b0,2,2,0);
    if ((*(ushort *)(DAT_8039a13c + 0xfa) & 0x10) == 0) {
      puVar4[0x348] = 0;
    }
    else {
      puVar4[0x348] = 2;
    }
    FUN_802ad4e8((int *)this,(int)puVar4);
    FUN_802acb54((int *)this);
                    /* {@symbol 8016296c} */
    (**(code **)(*(int *)pDll_partfx1F + 0x2c))(0,this,puVar4,0);
    objHitFn_80089074(this,0x18,1,-1);
                    /* {@symbol 8011bdb4} */
    (**(code **)(*(int *)pDll11 + 8))
              ((double)timeDelta,(double)timeDelta,this,puVar4,trexFuncPtrs,0x803965c4);
    (this->pos).pos.y = *(float *)(DAT_8039a13c + 0xec);
  }
  return;
}


/* @description Override hit detection */

void TREX_trex_hitDetect(ObjInstance *this) { //802AC1D8
  return;
}


/* Library Function - Single Match
    dll_299_func06
   
   Library: KioskDefault 0 0 */

void TREX_trex_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802AC1DC
  int iVar1;
  bool bVar3;
  void *__src;
  uint uVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  Mtx44 MStack_60;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  double local_10;
  
  DAT_8039a138 = this->state;
  if ((shouldRender) && (this->field76_0xf4 == 0)) {
    if (*(float *)(DAT_8039a138 + 0x3e4) != 0.0) {
      local_10 = (double)(longlong)(int)*(float *)(DAT_8039a138 + 0x3e4);
      FUN_80096b14(200,0,0,(char)(int)*(float *)(DAT_8039a138 + 0x3e4));
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    iVar1 = FUN_8018d744();
    if ((iVar1 == 0) && (bVar3 = checkSomeDebugFlags_8017c4f8(), !bVar3)) {
      objGetAttachPointWorldPos
                (this,1,(float *)(DAT_8039a13c + 0x130),(float *)(DAT_8039a13c + 0x134),
                 (float *)(DAT_8039a13c + 0x138),FALSE);
      objGetAttachPointWorldPos
                (this,2,(float *)(DAT_8039a13c + 0x148),(float *)(DAT_8039a13c + 0x14c),
                 (float *)(DAT_8039a13c + 0x150),FALSE);
      objGetAttachPointWorldPos
                (this,3,(float *)(DAT_8039a13c + 0x160),(float *)(DAT_8039a13c + 0x164),
                 (float *)(DAT_8039a13c + 0x168),FALSE);
      objGetAttachPointWorldPos
                (this,0,(float *)(DAT_8039a13c + 0x118),(float *)(DAT_8039a13c + 0x11c),
                 (float *)(DAT_8039a13c + 0x120),FALSE);
      __src = (void *)objJointFn_80091db4(this,4);
      memcpy(&MStack_60,__src,0x40);
      MStack_60.m43 = 0.0;
      MStack_60.m42 = 0.0;
      MStack_60.m41 = 0.0;
      uVar2 = randInt(-0x32,0x32);
      local_10 = (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000);
      *(float *)(DAT_8039a13c + 0x16c) = (float)(local_10 - 4503601774854144.0) * 0.1;
      uStack_14 = randInt(0x3c,0x78);
      uStack_14 = uStack_14 ^ 0x80000000;
      local_18 = 0x43300000;
      *(float *)(DAT_8039a13c + 0x170) =
           (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) * 0.1;
      uStack_1c = randInt(100,0x96);
      uStack_1c = uStack_1c ^ 0x80000000;
      local_20 = 0x43300000;
      *(float *)(DAT_8039a13c + 0x174) =
           (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0) * -0.25;
      multVectorByMatrix((double)*(float *)(DAT_8039a13c + 0x16c),
                         (double)*(float *)(DAT_8039a13c + 0x170),
                         (double)*(float *)(DAT_8039a13c + 0x174),&MStack_60,
                         (float *)(DAT_8039a13c + 0x16c),(float *)(DAT_8039a13c + 0x170),
                         (float *)(DAT_8039a13c + 0x174));
      *(uint *)(DAT_8039a13c + 0x104) = *(uint *)(DAT_8039a13c + 0x104) | 0x100000;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_299_func07
   
   Library: KioskDefault 0 0 */

void TREX_trex_free(ObjInstance *this,int param2) { //802AC464
  DAT_8039a138 = this->state;
  DAT_8039a13c = *(void ***)(DAT_8039a138 + 0x3f0);
  Object_removePlayerObj(this,4);
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,DAT_8039a138,0);
  FUN_80070394(*DAT_8039a13c);
  if (DAT_8039a140 != (LoadedDll *)0x0) {
    DLL_free(DAT_8039a140);
  }
  DAT_8039a140 = (LoadedDll *)0x0;
  return;
}


undefined4 TREX_trex_func08(ObjInstance *this) { //802AC4F4
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int TREX_trex_getExtraSize(void) { //802AC4FC
  return 0x570;
}


void TREX_trex_setScale(ObjInstance *this,float scale) { //802AC504
  DAT_8039a138 = this->state;
  return;
}


void TREX_trex_func0B(void) { //802AC528
  return;
}

