
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SBcloudrunner_initialise(undefined4 param) { //80260B40
  return;
}


/* @description Called when DLL is unloaded */

void SBcloudrunner_release(void) { //80260B44
  return;
}


/* Library Function - Single Match
    dll_229_func03
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //80260B48
  bool bVar2;
  DLL_func **ppDVar1;
  undefined *puVar3;
  
  puVar3 = this->state;
  Object_setPriority(this,0x5a);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80261bdc;
  *(float *)(puVar3 + 0x38) = (this->pos).pos.x;
  *(float *)(puVar3 + 0x3c) = (this->pos).pos.y;
  *(float *)(puVar3 + 0x40) = (this->pos).pos.z;
  puVar3[0x50] = 100;
  (this->pos).rotation.x = 0x4000;
  (this->pos).scale = 0.038;
  Object_ObjAnimSetMove(0.0,this,5,0);
  DAT_80399fc0 = textureLoadAsset(0x156);
  DAT_80399fc4 = textureLoadAsset(0x47);
  *(undefined2 *)(puVar3 + 0x56) = 0x7fff;
  bVar2 = checkSomeDebugFlags_8017c4f8();
  if (!bVar2) {
    ppDVar1 = runlinkDownloadCode(0x1021,1);
    *(DLL_func ***)(puVar3 + 8) = ppDVar1;
  }
  return;
}


/* Library Function - Single Match
    dll_229_func04
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_update(ObjInstance *this) { //80260C0C
  char cVar1;
  float fVar2;
  bool bVar3;
  ObjInstance *pOVar4;
  ObjInstance **ppOVar5;
  s8 sVar8;
  s8 sVar9;
  HitState *pHVar6;
  N64Button32 NVar7;
  ObjDef *def;
  Mtx44 *pMVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  ObjInstance **ppOVar14;
  double dVar15;
  double dVar16;
  float local_fc;
  float local_f8;
  float local_f4;
  float afStack_f0 [6];
  char local_d5;
  short local_d4;
  short local_d2;
  short local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  char local_bc;
  int local_b8;
  undefined4 uStack_b4;
  double local_b0;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  double local_98;
  undefined4 local_90;
  uint uStack_8c;
  double local_88;
  
  _savefpr_24();
  ppOVar14 = (ObjInstance **)this->state;
  pOVar4 = Object_objGetMain();
  pMVar10 = this->modelInstances->mtxs[(char)this->curModel + -3];
  if (*(char *)((int)ppOVar14 + 0x5a) == '\0') {
    if ((*ppOVar14 == (ObjInstance *)0x0) && (*(char *)(ppOVar14 + 0x15) == '\0')) {
      *ppOVar14 = pOVar4;
      FUN_801a8b9c(0.0,(int)pOVar4,3);
    }
    if (*ppOVar14 != (ObjInstance *)0x0) {
      if (ppOVar14[1] == (ObjInstance *)0x0) {
        ppOVar5 = Object_playerGetObject(4,&local_b8);
        for (iVar13 = 0; iVar13 < local_b8; iVar13 = iVar13 + 1) {
          if (ppOVar5[iVar13]->romdefno == SB_Galleon) {
            ppOVar14[1] = ppOVar5[iVar13];
            iVar13 = local_b8;
          }
        }
      }
      sVar8 = getStickX2(0);
      uVar12 = (uint)sVar8;
      sVar9 = getStickY2(0);
      uVar11 = (uint)sVar9;
      iVar13 = FUN_800883e4((int)this,&uStack_b4,(int *)0x0,(uint *)0x0);
      if ((iVar13 != 0) && (*(char *)((int)ppOVar14 + 0x51) == '\0')) {
        iVar13 = randInt(0,2);
        audioTryStartSfx((int *)this,1,*(ushort *)((int)&PTR_DAT_80397ec8 + iVar13 * 2),0x7f,
                         "cloudrunner.c",0xca);
        (this->pos).rotation.y = 8000;
        *(undefined *)((int)ppOVar14 + 0x51) = 1;
        if (pMVar10 != (Mtx44 *)0x0) {
          local_cc = 1.0;
          local_d4 = 0;
          local_d2 = 0;
          local_d0 = 0;
          iVar13 = (int)pMVar10[1].m11 + (char)this->hitstate->field_0x63 * 0x10;
          local_c8 = *(float *)(iVar13 + 4) + playerMapOffsetX;
          local_c4 = *(float *)(iVar13 + 8);
          local_c0 = *(float *)(iVar13 + 0xc) + playerMapOffsetZ;
          pHVar6 = this->hitstate;
          iVar13._0_1_ = pHVar6->damage;
          iVar13._1_1_ = pHVar6->field34_0x6d;
          iVar13._2_1_ = pHVar6->field35_0x6e;
          iVar13._3_1_ = pHVar6->field36_0x6f;
          if ((iVar13 != 0) && (*(short *)(*(int *)&this->hitstate->damage + 0x46) == 0x9a)) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa8,&local_d4,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa8,&local_d4,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa8,&local_d4,&DAT_00200001,0xffffffff,0);
            for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0xa9,&local_d4,&DAT_00200001,0xffffffff,0)
              ;
            }
          }
        }
      }
      this->field76_0xf4 = 0;
      bVar3 = false;
      local_bc = *(char *)((int)ppOVar14 + 0x51);
      *(u8 *)(ppOVar14 + 0x14) = *(char *)(ppOVar14 + 0x14) - framesThisStep;
      if (*(char *)(ppOVar14 + 0x14) < '\0') {
        *(undefined *)(ppOVar14 + 0x14) = 0;
      }
      cVar1 = *(char *)((int)ppOVar14 + 0x51);
      if (cVar1 == '\x02') {
        this->field76_0xf4 = 1;
      }
      else if (cVar1 < '\x02') {
        if (cVar1 == '\0') {
          *(short *)(ppOVar14 + 6) = *(short *)(ppOVar14 + 6) - (short)(uVar12 << 3);
          *(short *)(ppOVar14 + 6) =
               *(short *)(ppOVar14 + 6) -
               (short)((int)((int)*(short *)(ppOVar14 + 6) * (uint)framesThisStep) >> 5);
          *(short *)((int)ppOVar14 + 0x1a) = *(short *)((int)ppOVar14 + 0x1a) + sVar8 * -0x14;
          *(short *)((int)ppOVar14 + 0x1a) =
               *(short *)((int)ppOVar14 + 0x1a) -
               (short)((int)((int)*(short *)((int)ppOVar14 + 0x1a) * (uint)framesThisStep) >> 6);
          if (*(short *)((int)ppOVar14 + 0x1a) < 0x32c9) {
            if (*(short *)((int)ppOVar14 + 0x1a) < -13000) {
              *(undefined2 *)((int)ppOVar14 + 0x1a) = 0xcd38;
            }
          }
          else {
            *(undefined2 *)((int)ppOVar14 + 0x1a) = 13000;
          }
          if ((this->pos).rotation.y < 0x1f41) {
            if ((this->pos).rotation.y < -8000) {
              (this->pos).rotation.y = -8000;
            }
          }
          else {
            (this->pos).rotation.y = 8000;
          }
          (this->pos).rotation.x = *(short *)(ppOVar14 + 6) + 0x4000;
          (this->pos).rotation.z = *(short *)((int)ppOVar14 + 0x1a);
          (this->pos).rotation.y = (this->pos).rotation.y + sVar9 * -0x11;
          (this->pos).rotation.y =
               (this->pos).rotation.y -
               (short)((int)((int)(this->pos).rotation.y * (uint)framesThisStep) >> 6);
          local_d5 = '\0';
          local_88 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000);
          dVar15 = (double)((float)(local_88 - 4503601774854144.0) * 3.051758e-06 + 0.015);
          if (dVar15 <= 0.0130000002682209) {
            dVar15 = 0.01499999966472387;
            if (this->animId != 0x100) {
              Object_ObjAnimSetMove(0.0,this,0x100,0);
            }
          }
          else if (this->animId != 5) {
            Object_ObjAnimSetMove(0.0,this,5,0);
          }
          objRunAnimation(dVar15,(double)timeDelta,(int)this,afStack_f0);
          (this->pos).pos.x = (float)ppOVar14[0xe];
          (this->pos).pos.y = (float)ppOVar14[0xf];
          (this->pos).pos.z = (float)ppOVar14[0x10];
          if (local_d5 != '\0') {
            audioTryStartSfx((int *)this,8,0xf7,0x46,"cloudrunner.c",0x127);
          }
          if ((*(char *)(ppOVar14 + 0x14) == '\0') &&
             (NVar7 = n64GetEnabledButtonsPressed(0), (NVar7 & N64_BUTTON_A) != 0)) {
            bVar3 = true;
            *(undefined *)(ppOVar14 + 0x14) = 0x1e;
          }
        }
        else if (-1 < cVar1) {
          *(short *)(ppOVar14 + 6) = *(short *)(ppOVar14 + 6) - (short)(uVar12 << 3);
          *(short *)(ppOVar14 + 6) =
               *(short *)(ppOVar14 + 6) -
               (short)((int)((int)*(short *)(ppOVar14 + 6) * (uint)framesThisStep) >> 5);
          *(short *)((int)ppOVar14 + 0x1a) = *(short *)((int)ppOVar14 + 0x1a) + sVar8 * -0x14;
          *(short *)((int)ppOVar14 + 0x1a) =
               *(short *)((int)ppOVar14 + 0x1a) -
               (short)((int)((int)*(short *)((int)ppOVar14 + 0x1a) * (uint)framesThisStep) >> 6);
          if (*(short *)((int)ppOVar14 + 0x1a) < 0x32c9) {
            if (*(short *)((int)ppOVar14 + 0x1a) < -13000) {
              *(undefined2 *)((int)ppOVar14 + 0x1a) = 0xcd38;
            }
          }
          else {
            *(undefined2 *)((int)ppOVar14 + 0x1a) = 13000;
          }
          if ((this->pos).rotation.y < 0x1f41) {
            if ((this->pos).rotation.y < -8000) {
              (this->pos).rotation.y = -8000;
            }
          }
          else {
            (this->pos).rotation.y = 8000;
          }
          (this->pos).rotation.x = *(short *)(ppOVar14 + 6) + 0x4000;
          (this->pos).rotation.z = *(short *)((int)ppOVar14 + 0x1a);
          (this->pos).rotation.y = (this->pos).rotation.y + sVar9 * -0x11;
          (this->pos).rotation.y =
               (this->pos).rotation.y -
               (short)((int)((int)(this->pos).rotation.y * (uint)framesThisStep) >> 6);
          if (this->animId != 0xf) {
            Object_ObjAnimSetMove(0.0,this,0xf,0);
                    /* {@symbol 8011fd90} */
            (**(code **)(*(int *)pDll_waterfx + 0x14))(0,100,10);
          }
          iVar13 = objRunAnimation(0.009999999776482582,(double)timeDelta,(int)this,(float *)0x0);
          if (iVar13 != 0) {
            *(undefined *)((int)ppOVar14 + 0x51) = 0;
          }
          this->field76_0xf4 = 1;
        }
      }
      else if (cVar1 == '\x04') {
        if (this->animId != 5) {
          Object_ObjAnimSetMove(0.0,this,5,0);
        }
        if ((*(char *)((int)ppOVar14 + 0x53) == '\0') && (0x78 < *(short *)(ppOVar14 + 0x16))) {
          gfxDllFn_8007399c(9);
          FUN_80074120(0);
          *(undefined *)((int)ppOVar14 + 0x53) = 1;
        }
        (this->pos).rotation.y = (this->pos).rotation.y + -0x3c0;
        (this->pos).rotation.y =
             (this->pos).rotation.y -
             (short)((int)((int)(this->pos).rotation.y * (uint)framesThisStep) >> 5);
        (this->vel).y = timeDelta * 0.15 + (this->vel).y;
        (this->vel).y = (this->vel).y * 0.95;
        (this->pos).pos.y = -((this->vel).y * timeDelta - (this->pos).pos.y);
        this->field76_0xf4 = 1;
      }
      else if (cVar1 < '\x04') {
        this->field76_0xf4 = 1;
      }
      if (*(char *)((int)ppOVar14 + 0x51) != '\x04') {
        local_88 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.z ^ 0x80000000);
        ppOVar14[0x12] =
             (ObjInstance *)
             ((float)ppOVar14[0x12] + ((float)(local_88 - 4503601774854144.0) * timeDelta) / 6370.0)
        ;
        uStack_8c = (int)(this->pos).rotation.y ^ 0x80000000;
        local_90 = 0x43300000;
        ppOVar14[0x11] =
             (ObjInstance *)
             ((float)ppOVar14[0x11] +
             ((float)((double)CONCAT44(0x43300000,uStack_8c) - 4503601774854144.0) * timeDelta) /
             6370.0);
        ppOVar14[0x12] =
             (ObjInstance *)-(timeDelta * (float)ppOVar14[0x12] * 0.01 - (float)ppOVar14[0x12]);
        ppOVar14[0x11] =
             (ObjInstance *)-(timeDelta * (float)ppOVar14[0x11] * 0.01 - (float)ppOVar14[0x11]);
        local_98 = (double)(longlong)(int)((float)ppOVar14[0x11] * 10.0);
        (this->pos).rotation.y = (this->pos).rotation.y - (short)(int)((float)ppOVar14[0x11] * 10.0)
        ;
      }
      (this->pos).pos.y = (float)ppOVar14[0x11] * 0.8 + (float)ppOVar14[0xf];
      (this->pos).pos.z = (float)ppOVar14[0x12] * 2.6 + (float)ppOVar14[0x10];
      *(ushort *)(ppOVar14 + 0x16) = *(short *)(ppOVar14 + 0x16) + (ushort)framesThisStep;
      if (*(char *)((int)ppOVar14 + 0x51) != local_bc) {
        *(undefined2 *)(ppOVar14 + 0x16) = 0;
      }
      if (bVar3) {
        audioTryStartSfx((int *)this,1,0x208,0x7f,"cloudrunner.c",0x19d);
        local_c8 = 0.0;
        local_c4 = 0.0;
        local_c0 = 0.0;
        local_cc = 1.0;
        local_d4 = (this->pos).rotation.x;
        local_d2 = (this->pos).rotation.y;
        local_d0 = (this->pos).rotation.z;
        local_fc = 0.0;
        local_f8 = 38.0;
        local_f4 = -80.0;
        FUN_8007a878(&local_d4,&local_fc);
        def = objAlloc(0x18,SB_CloudBal);
        def->bound = 0xff;
        def->cullDist = 0xff;
        def->loadFlags = isManualLoad;
        def->mapStates2 = 1;
        (def->pos).x = (this->pos).pos.x + local_fc;
        (def->pos).y = (this->pos).pos.y + local_f8;
        (def->pos).z = (this->pos).pos.z + local_f4;
        pOVar4 = objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
        if (pOVar4 != (ObjInstance *)0x0) {
          if ((int)uVar12 < 0) {
            uVar12 = -uVar12;
          }
          if ((int)uVar11 < 0) {
            uVar11 = -uVar11;
          }
          local_c8 = 0.0;
          local_c4 = 0.0;
          local_c0 = 0.0;
          local_cc = 1.0;
          local_98 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x - 0x4000U ^ 0x80000000)
          ;
          uStack_8c = uVar12 ^ 0x80000000;
          local_90 = 0x43300000;
          iVar13 = (int)((float)(local_98 - 4503601774854144.0) *
                         ((float)((double)CONCAT44(0x43300000,uStack_8c) - 4503601774854144.0) /
                         70.0) * 2.0 + 16384.0);
          local_88 = (double)(longlong)iVar13;
          local_d4 = (short)iVar13;
          uStack_9c = (this->pos).rotation.y + -400 >> 1 ^ 0x80000000;
          local_a0 = 0x43300000;
          uStack_a4 = uVar11 ^ 0x80000000;
          local_a8 = 0x43300000;
          iVar13 = (int)((float)((double)CONCAT44(0x43300000,uStack_9c) - 4503601774854144.0) *
                        ((float)((double)CONCAT44(0x43300000,uStack_a4) - 4503601774854144.0) / 70.0
                        ));
          local_b0 = (double)(longlong)iVar13;
          local_d2 = (short)iVar13;
          local_d0 = 0;
          local_fc = 0.0;
          local_f8 = 0.0;
          local_f4 = -16.0;
          FUN_8007a878(&local_d4,&local_fc);
          (pOVar4->vel).x = local_fc;
          (pOVar4->vel).y = local_f8;
          (pOVar4->vel).z = local_f4;
          pOVar4->field76_0xf4 = 0xb4;
          pOVar4->flags_0xf8 = (dword)this;
          (pOVar4->pos).rotation.z = 0;
          (pOVar4->pos).rotation.y = 0;
          (pOVar4->pos).rotation.x = 0;
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(pOVar4,0x66,0,2,0xffffffff,0);
        }
      }
                    /* {@symbol 800d999c} */
      (**(code **)(*(int *)pDll_expgfx + 0x20))((int)*(short *)((int)ppOVar14 + 0x56));
      local_b0 = (double)CONCAT44(0x43300000,(int)*(short *)((int)ppOVar14 + 0x56) ^ 0x80000000);
      dVar15 = (double)mathFn_80294204((double)(((float)(local_b0 - 4503601774854144.0) * 3.141593)
                                               / 32767.0));
      uStack_a4 = (int)*(short *)((int)ppOVar14 + 0x56) ^ 0x80000000;
      local_a8 = 0x43300000;
      dVar16 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_a4)
                                                            - 4503601774854144.0) * 3.141593) /
                                                   32767.0));
      if (ppOVar14[1] == (ObjInstance *)0x0) {
        fVar2 = 0.0;
      }
      else {
        local_b0 = (double)CONCAT44(0x43300000,(int)*(short *)((int)ppOVar14 + 0x1a) ^ 0x80000000);
        fVar2 = (float)(local_b0 - 4503601774854144.0) / 1000.0;
      }
      ppOVar14[0x13] =
           (ObjInstance *)
           (timeDelta * (fVar2 - (float)ppOVar14[0x13]) * 0.0625 + (float)ppOVar14[0x13]);
      ppOVar14[0x17] = ppOVar14[0x13];
      ppOVar14[0x18] = (ObjInstance *)12.0;
                    /* {@symbol 800d99a4} */
      (**(code **)(*(int *)pDll_expgfx + 0x28))
                ((double)(((float)(dVar16 * -(double)(float)ppOVar14[0x13] +
                                  (double)(float)(-dVar15 * 12.0)) * timeDelta) / 3.0),
                 (double)(((float)(dVar15 * -(double)(float)ppOVar14[0x13] +
                                  (double)(float)(dVar16 * 12.0)) * timeDelta) / 3.0));
    }
  }
  else {
    Object_objFreeObject(this);
  }
  _restfpr_24();
  return;
}


/* Library Function - Single Match
    dll_229_func05
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_hitDetect(ObjInstance *this) { //802618C0
  int iVar1;
  ObjInstance *pOVar2;
  int *piVar3;
  
  piVar3 = (int *)this->state;
  iVar1 = isModelAnimDisabled();
  if (((iVar1 == 0) && (*piVar3 != 0)) && (this->pObj_0xc0 == (ObjInstance *)0x0)) {
    *(ushort *)(*(int *)(*piVar3 + 0x54) + 0x58) =
         *(ushort *)(*(int *)(*piVar3 + 0x54) + 0x58) & 0xfffe;
    if (piVar3[1] != 0) {
      *(char *)((int)piVar3 + 0x52) = (char)*(undefined4 *)(piVar3[1] + 0xf4);
    }
  }
  else if (*piVar3 == 0) {
    pOVar2 = Object_objGetMain();
                    /* {@symbol 80153db8} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x28))(pOVar2,0);
  }
  else {
                    /* {@symbol 80153db8} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x28))(this,0);
                    /* {@symbol 800ce728} */
    (**(code **)(*(int *)pDll_checkpoint + 0x50))(0x58,1,0,0x78);
  }
  if (*piVar3 != 0) {
    FUN_80261b40((int)this,(undefined2 *)*piVar3);
  }
  if ((*(char *)((int)piVar3 + 0x52) != '\a') && (iVar1 = randInt(0,0x14), iVar1 == 0)) {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x8a,0,0,0xffffffff,0);
  }
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80261A14
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
    dll_229_func07
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_free(ObjInstance *this,int param2) { //80261A70
  undefined *puVar1;
  
  puVar1 = this->state;
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  if (DAT_80399fc0 != (Texture *)0x0) {
    texFreeTexture(DAT_80399fc0);
  }
  DAT_80399fc0 = (Texture *)0x0;
  if (DAT_80399fc4 != (Texture *)0x0) {
    texFreeTexture(DAT_80399fc4);
  }
  DAT_80399fc4 = (Texture *)0x0;
                    /* {@symbol 800d999c} */
  (**(code **)(*(int *)pDll_expgfx + 0x20))(0);
                    /* {@symbol 800d99a4} */
  (**(code **)(*(int *)pDll_expgfx + 0x28))(0x4028000000000000,0);
  DLL_free(*(LoadedDll **)(puVar1 + 8));
  *(undefined4 *)(puVar1 + 8) = 0;
  return;
}


undefined4 SBcloudrunner_func08(ObjInstance *this) { //80261B30
  return 0x43;
}


/* @description Get extra size for object (size of State struct) */

int SBcloudrunner_getExtraSize(void) { //80261B38
  return 100;
}


/* Library Function - Single Match
    dll_229_func0A
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_setScale(ObjInstance *this,float scale) { //80261D68
  undefined4 *in_r4;
  undefined4 *in_r5;
  undefined4 *in_r6;
  undefined *puVar1;
  
  puVar1 = this->state;
  *in_r4 = *(undefined4 *)(puVar1 + 0x38);
  *in_r5 = *(undefined4 *)(puVar1 + 0x3c);
  *in_r6 = *(undefined4 *)(puVar1 + 0x40);
  return;
}


undefined4 SBcloudrunner_func0B(int param1) { //80261D98
  return *(undefined4 *)(*(int *)(param1 + 0xb8) + 8);
}


void SBcloudrunner_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //80261DB4
  return;
}


/* Library Function - Single Match
    dll_229_func0D
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_render2(ObjInstance *this) { //80261DD0
  undefined4 *in_r4;
  undefined4 *in_r5;
  undefined *puVar1;
  
  puVar1 = this->state;
  *in_r4 = *(undefined4 *)(puVar1 + 0x5c);
  *in_r5 = *(undefined4 *)(puVar1 + 0x60);
  return;
}


/* Library Function - Single Match
    dll_229_func0E
   
   Library: KioskDefault 0 0 */

void SBcloudrunner_func0E(int param1) { //80261DF8
  (**(code **)(**(int **)(*(int *)(*(int *)(param1 + 0xb8) + 4) + 0x68) + 0x24))
            (*(undefined4 *)(*(int *)(param1 + 0xb8) + 4));
  return;
}

