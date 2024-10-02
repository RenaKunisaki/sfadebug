
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRicefire_initialise(undefined4 param) { //802BADF8
  return;
}


/* @description Called when DLL is unloaded */

void DRicefire_release(void) { //802BADFC
  return;
}


/* Library Function - Single Match
    dll_2BB_func03
   
   Library: KioskDefault 0 0 */

void DRicefire_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802BAE00
  float fVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)this->state;
  if (objDef[1].allocatedSize != 0) {
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,(uint)objDef[1].allocatedSize) - 4503599627370496.0) *
         0.13;
  }
  this->flags_0xf8 = 0;
  uVar2 = mainGetBit((int)(short)objDef[1].objType);
  *(short *)(puVar3 + 1) = (short)uVar2;
  if ((short)uVar2 == 0) {
    objHitFn_80089074(this,0x14,1,0xf);
    audioTryStartSfx((int *)this,1,0x6e,0x7f,(char *)&PTR_DAT_80323ee0,0x67);
    audioTryStartSfx((int *)this,2,0x7a,0x7f,(char *)&PTR_DAT_80323ee0,0x68);
  }
  else {
    objSetModelNo(this,1);
    FUN_80088da4((int)this);
  }
  (this->pos).rotation.z = 0x7fff;
  (this->pos).rotation.x = 0x7fff;
  *(byte *)((int)puVar3 + 9) = objDef[1].mapStates1;
  *puVar3 = 0;
  *(undefined *)(puVar3 + 2) = 0x14;
  fVar1 = ((this->pos).scale / this->data->scale) * 1.6;
  if (this->hitstate != (HitState *)0x0) {
    this->hitstate->field16_0x52 =
         (ushort)(int)((float)((double)CONCAT44(0x43300000,
                                                (int)(short)this->hitstate->field16_0x52 ^
                                                0x80000000) - 4503601774854144.0) * fVar1);
    this->hitstate->field18_0x56 =
         (short)(int)((float)((double)CONCAT44(0x43300000,
                                               (int)this->hitstate->field18_0x56 ^ 0x80000000) -
                             4503601774854144.0) * fVar1);
    this->hitstate->field17_0x54 =
         (short)(int)((float)((double)CONCAT44(0x43300000,
                                               (int)this->hitstate->field17_0x54 ^ 0x80000000) -
                             4503601774854144.0) * fVar1);
  }
  return;
}


/* Library Function - Single Match
    dll_2BB_func04
   
   Library: KioskDefault 0 0 */

void DRicefire_update(ObjInstance *this) { //802BAFF4
  byte bVar1;
  short sVar2;
  ObjInstance *pOVar3;
  bool bVar5;
  LoadedDll *pLVar4;
  ObjDef *def;
  ObjDef *pOVar6;
  ObjDef *pOVar7;
  ObjInstance **ppOVar8;
  double dVar9;
  undefined2 local_54 [2];
  undefined2 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_38;
  uint uStack_34;
  
  ppOVar8 = (ObjInstance **)this->state;
  pOVar3 = Object_objGetMain();
  pOVar7 = this->def;
  if (*(short *)(ppOVar8 + 1) != 1) {
    if (*(short *)(ppOVar8 + 1) == 0) {
      if ((this->flags_0xf8 == 0) && (bVar5 = checkSomeDebugFlags_8017c4f8(), !bVar5)) {
        local_48 = 0.0;
        local_44 = 0.0;
        local_40 = 0.0;
        uStack_34 = (uint)pOVar7[1].allocatedSize;
        local_38 = 0x43300000;
        local_4c = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503599627370496.0);
        local_50 = 0;
        local_54[0] = 0;
                    /* {@symbol 800e3c34} */
        (**(code **)(*(int *)pDll_projgfx + 0x2c))(this);
        pLVar4 = (LoadedDll *)runlinkDownloadCode(0x100c,1);
        (**(code **)(pLVar4->id + 4))(this,0,local_54,&DAT_00010004,0xffffffff,0);
        DLL_free(pLVar4);
        pLVar4 = (LoadedDll *)runlinkDownloadCode(0x100b,1);
        (**(code **)(pLVar4->id + 4))(this,0,local_54,&DAT_00010004,0xffffffff,0);
        DLL_free(pLVar4);
        pLVar4 = (LoadedDll *)runlinkDownloadCode(0x100a,1);
        (**(code **)(pLVar4->id + 4))(this,0,local_54,&DAT_00010004,0xffffffff,0);
        DLL_free(pLVar4);
        this->flags_0xf8 = 1;
      }
    }
    dVar9 = (double)objHitFn_80089074(this,8,1,0);
    objDistObj2Obj(pOVar3,this);
    if (*(short *)(ppOVar8 + 1) == 2) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x5a,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x5b,0,0,0xffffffff,0);
      if (*(short *)((int)ppOVar8 + 6) < 0x3c) {
        if ((int)(0x3c - (uint)framesThisStep) <= (int)*(short *)((int)ppOVar8 + 6)) {
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x52,0x7f,(char *)&PTR_DAT_80323ee0,
                              (int *)0xbe);
        }
      }
      sVar2 = *(short *)((int)ppOVar8 + 6) - (ushort)framesThisStep;
      *(short *)((int)ppOVar8 + 6) = sVar2;
      if (sVar2 < 0) {
        *(undefined2 *)(ppOVar8 + 1) = 1;
        FUN_80068a9c((uint)this,3);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x42,0x7f,(char *)&PTR_DAT_80323ee0,
                            (int *)0xc4);
        if (*ppOVar8 != (ObjInstance *)0x0) {
          Object_objFreeObject(*ppOVar8);
          *ppOVar8 = (ObjInstance *)0x0;
        }
      }
    }
    if (*ppOVar8 == (ObjInstance *)0x0) {
      bVar5 = false;
      if (pOVar7[1].loadFlags == 0) {
        if (dVar9 < 100.0) {
          bVar5 = true;
        }
      }
      else {
        bVar5 = true;
      }
      if (bVar5) {
        def = objAlloc(0x28,LFXEmitter);
        pOVar6 = this->def;
        def->loadFlags = pOVar6->loadFlags;
        def->bound = pOVar6->bound;
        (def->pos).x = (this->pos).pos.x;
        uStack_34 = randInt(0,0x1e);
        uStack_34 = uStack_34 ^ 0x80000000;
        local_38 = 0x43300000;
        (def->pos).y = (this->pos).pos.y +
                       (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0);
        (def->pos).z = (this->pos).pos.z;
        bVar1 = pOVar7[1].cullDist;
        def[1].bound = pOVar7[1].bound;
        def[1].cullDist = bVar1;
        sVar2._0_1_ = def[1].bound;
        sVar2._1_1_ = def[1].cullDist;
        if (sVar2 == 0) {
          def[1].bound = 0;
          def[1].cullDist = 0x59;
        }
        *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
        def[1].objType = 0x960;
        def[1].allocatedSize = 9;
        def[1].mapStates1 = 0x60;
        def[1].loadFlags = 0;
        def[1].mapStates2 = 200;
        pOVar3 = objInstantiateCharacter(def,5,(int)(char)this->mapId,-1,this->pMatrix);
        *ppOVar8 = pOVar3;
      }
    }
    else if ((pOVar7[1].loadFlags == 0) && (110.0 < dVar9)) {
      Object_objFreeObject(*ppOVar8);
      *ppOVar8 = (ObjInstance *)0x0;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2BB_func05
   
   Library: KioskDefault 0 0 */

void DRicefire_hitDetect(ObjInstance *this) { //802BB40C
  char cVar1;
  int iVar2;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  pOVar3 = this->def;
  iVar2 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if (iVar2 == 0x10) {
    cVar1 = puVar4[8];
    puVar4[8] = cVar1 + -1;
    if (cVar1 < '\0') {
      mainSetBits((int)(short)pOVar3[1].objType,1);
      *(undefined2 *)(puVar4 + 4) = 2;
      objSetModelNo(this,1);
                    /* {@symbol 800e3c34} */
      (**(code **)(*(int *)pDll_projgfx + 0x2c))(this);
      *(undefined2 *)(puVar4 + 6) = 0xb4;
      FUN_80088da4((int)this);
      objHitFn_80089114(this);
    }
    else {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x5a,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x5b,0,0,0xffffffff,0);
      audioTryStartSfx((int *)this,4,0x3d,0x7f,(char *)&PTR_DAT_80323ee0,0x10c);
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_135_func06
    dll_2BB_func06
   
   Library: KioskDefault 0 0 */

void DRicefire_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802BB540
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  if ((((this->pos).flags & 0x100) != 0) && (this->def != (ObjDef *)0x0)) {
    FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (double)(float)((double)CONCAT44(0x43300000,(uint)this->def[1].mapStates1) -
                                4503599627370496.0),5.0,(Gfx *)CONCAT31(in_register_00000010,param2)
                 ,(int *)CONCAT31(in_register_00000014,param3),0,0,0xff);
  }
  return;
}


/* @description Free object instance */

void DRicefire_free(ObjInstance *this,int param2) { //802BB600
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 DRicefire_func08(ObjInstance *this) { //802BB658
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int DRicefire_getExtraSize(void) { //802BB660
  return 0xc;
}

