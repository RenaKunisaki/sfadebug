
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void tricky_initialise(undefined4 param) { //801A9128
  trickyStateFuncs[0] = trickyState0;
  trickyStateFuncs[1] = trickyState1;
  trickyStateFuncs[2] = trickyState2;
  trickyStateFuncs[3] = trickyState3;
  trickyStateFuncs[4] = nop_801AB410;
  trickyStateFuncs[5] = trickyState5;
  trickyStateFuncs[6] = trickyState6;
  trickyStateFuncs[7] = trickyState7;
  trickyStateFuncs[8] = trickyState8;
  trickyStateFuncs[9] = nop_801ABDCC;
  trickyStateFuncs[10] = trickyState10;
  trickyStateFuncs[11] = trickyState11;
  trickyStateFuncs[12] = trickyState12;
  trickyStateFuncs[13] = trickyState13;
  trickyStateFuncs[14] = trickyState14;
  trickyStateFuncs[15] = trickyState15;
  trickyStateFuncs[16] = trickyState16;
  trickyStateFuncs[17] = trickyState17;
  trickyStateFuncs[18] = trickyState18;
  return;
}


/* @description Called when DLL is unloaded */

void tricky_release(void) { //801A9228
  return;
}


/* @description Set up object instance */

void tricky_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801A922C
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  undefined4 uVar5;
  ObjInstance *pOVar6;
  int iVar7;
  undefined *puVar8;
  undefined2 local_34 [2];
  
  _savefpr_29();
  puVar8 = this->state;
  local_34[0] = 0x102;
  mainSetBits(0xc1,3);
  mainSetBits(0x4e3,0xff);
  uVar4 = mainGetBit(0x25);
  if (uVar4 != 0) {
    mainSetBits(0x3f8,1);
  }
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801aa540;
  Object_objAddObjectType(this,1);
  allocVoxRoute((void **)(puVar8 + 0x4e0));
  allocVoxRoute((void **)(puVar8 + 0x510));
  allocVoxRoute((void **)(puVar8 + 0x540));
  allocVoxRoute((void **)(puVar8 + 0x570));
  allocVoxRoute((void **)(puVar8 + 0x5a0));
                    /* {@symbol 8012da4c} */
  uVar5 = (**(code **)(*(int *)pDll_SaveGame + 0x94))();
  *(undefined4 *)(puVar8 + 4) = uVar5;
  pOVar6 = Object_objGetMain();
  *(ObjInstance **)(puVar8 + 8) = pOVar6;
  iVar7 = getMapId_800aa5dc();
  uVar4 = (uint)(byte)(&DAT_8030eecc)[iVar7];
  *(uint *)(puVar8 + 0x14) = uVar4;
  *(uint *)(puVar8 + 0x10) = uVar4;
  *(uint *)(puVar8 + 0xc) = uVar4;
  puVar8[0x18] = 0;
  puVar8[0x1b] = 0;
  *(undefined4 *)(puVar8 + 0x5d8) = 0;
  *(undefined2 *)(puVar8 + 0xa4) = 0;
  *(float *)(puVar8 + 0xb4) = (this->pos).pos.x;
  *(float *)(puVar8 + 0xb8) = (this->pos).pos.y;
  *(float *)(puVar8 + 0xbc) = (this->pos).pos.z;
  puVar8 = puVar8 + 0xcc;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(puVar8,0x2000000,0xa7,1);
                    /* {@symbol 8012ab74} */
  (**(code **)(*(int *)pDll1A + 8))(puVar8,1,&DAT_8030ee78,&DAT_80397b1c,2);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(puVar8,2,&DAT_8030ee60,&DAT_80397b14,local_34);
                    /* {@symbol 8011fe30} */
  (**(code **)(*(int *)pDll_curve + 4))();
  iVar7 = 0;
  for (fVar1 = 0.0; fVar1 < 1.8; fVar1 = fVar1 + 0.1) {
    fVar2 = 0.0;
    for (fVar3 = fVar1; 0.0 < fVar3; fVar3 = fVar3 - 0.09) {
      fVar2 = fVar3 * 3.0 + fVar2;
    }
    (&DAT_8030ee84)[iVar7] = fVar2 * 1.75;
    iVar7 = iVar7 + 1;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  _restfpr_29();
  return;
}


/* @description Update object instance */

void tricky_update(ObjInstance *this) { //801A9458
  short sVar1;
  undefined4 uVar2;
  N64Button NVar6;
  mapId32 mVar3;
  ObjInstance *pOVar4;
  ObjInstance *pOVar5;
  ObjDef *def;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined *param1;
  int iVar9;
  double dVar10;
  undefined4 auStack_7c [2];
  undefined4 local_74 [6];
  float local_5c;
  float local_58;
  float local_54;
  short local_4e;
  float local_40;
  uint local_3c;
  longlong local_38;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  param1 = this->state;
  iVar9 = 3;
  puVar7 = null_ARRAY_802cfe4c + 7;
  puVar8 = auStack_7c;
  do {
    uVar2 = puVar7[3];
    puVar8[2] = puVar7[2];
    puVar8[3] = uVar2;
    iVar9 = iVar9 + -1;
    puVar7 = puVar7 + 2;
    puVar8 = puVar8 + 2;
  } while (iVar9 != 0);
  NVar6 = n64GetEnabledButtonsHeld(0);
  if ((NVar6 & N64_BUTTON_RIGHT) == 0) {
    NVar6 = n64GetEnabledButtonsHeld(0);
    if ((NVar6 & N64_BUTTON_LEFT) != 0) {
      pOVar4 = Object_objGetMain();
                    /* {@symbol 80153db8} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x28))(pOVar4,500);
    }
  }
  else {
                    /* {@symbol 80153db8} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x28))(this,500);
  }
  iVar9 = getMapId_800aa5dc();
  local_3c = (uint)(byte)(&DAT_8030eecc)[iVar9];
  mVar3 = mapCoordsToId(SUB84((double)*(float *)(*(int *)(param1 + 8) + 0x18),0),
                        SUB84((double)*(float *)(*(int *)(param1 + 8) + 0x20),0));
  *(uint *)(param1 + 0x14) = (uint)(byte)(&DAT_8030eecc)[mVar3];
  if ((local_3c != *(uint *)(param1 + 0xc)) && (local_3c != *(uint *)(param1 + 0x10))) {
    if (*(int *)(param1 + 0xc) == *(int *)(param1 + 0x14)) {
      *(uint *)(param1 + 0x10) = local_3c;
    }
    else {
      *(uint *)(param1 + 0xc) = local_3c;
    }
                    /* {@symbol 8011fe30} */
    (**(code **)(*(int *)pDll_curve + 4))();
  }
  if ((*(uint *)(param1 + 0x4c) & 0x200) != 0) {
    if ((*(uint *)(param1 + 0x4c) & 0x4000) == 0) {
                    /* {@symbol 8012b80c} */
      (**(code **)(*(int *)pDll1A + 0x20))(this,param1 + 0xcc);
      FUN_801afff4((int)param1);
      param1[0x19] = 0;
      *(float *)(param1 + 0x20) = 0.0;
      *(float *)(param1 + 0xb4) = (this->pos).pos.x;
      *(float *)(param1 + 0xb8) = (this->pos).pos.y;
      *(float *)(param1 + 0xbc) = (this->pos).pos.z;
    }
    *(uint *)(param1 + 0x4c) = *(uint *)(param1 + 0x4c) & 0xffffbdff;
  }
  if ((*(int *)(param1 + 0x28) != 0) && ((*(ushort *)(*(int *)(param1 + 0x28) + 0xb0) & 0x40) != 0))
  {
    FUN_801afff4((int)param1);
    *(undefined4 *)(param1 + 0x28) = 0;
  }
                    /* {@symbol 8016dba4} */
  iVar9 = (**(code **)(*pdll_camcontrol + 0x24))(local_74,6);
  if ((param1[0x18] == '\v') && (iVar9 == 4)) {
    param1[0x610] = param1[0x610] ^ 1;
    goto LAB_801a9b58;
  }
  if ((param1[0x18] == '\x10') && (iVar9 == 4)) {
    *(undefined4 *)(param1 + 0x5fc) = 1;
    goto LAB_801a9b58;
  }
  if ((param1[0x18] == '\x11') && (iVar9 == 4)) {
    *(undefined4 *)(param1 + 0x5fc) = 1;
    goto LAB_801a9b58;
  }
  if (iVar9 == 0) {
    *(uint *)(param1 + 0x4c) = *(uint *)(param1 + 0x4c) | 0x10000;
    goto LAB_801a9b58;
  }
  if ((*(uint *)(param1 + 0x4c) & 0x10) != 0) {
    if (iVar9 == 3) {
      *(uint *)(param1 + 0x4c) = *(uint *)(param1 + 0x4c) | 0x20000;
    }
    goto LAB_801a9b58;
  }
  if (iVar9 == 3) {
    param1[0x1d] = 3;
    iVar9 = trickyNearObjFn_801b0af0((int)param1,3);
    if (iVar9 == 0) {
      *(uint *)(param1 + 0x4c) = *(uint *)(param1 + 0x4c) | 0x20000;
    }
    else {
      sVar1 = *(short *)(*(int *)(param1 + 0x28) + 0x46);
      if (sVar1 == 0x546) {
        param1[0x18] = 0xd;
      }
      else {
        if (sVar1 < 0x546) {
          if (sVar1 == 0x475) {
            param1[0x18] = 0xd;
            goto LAB_801a9b58;
          }
        }
        else if (sVar1 == 0x5bc) {
          param1[0x18] = 0x11;
          goto LAB_801a9b58;
        }
        param1[0x18] = 0xb;
      }
    }
    goto LAB_801a9b58;
  }
  if (iVar9 < 3) {
    if (iVar9 == 1) {
      param1[0x1d] = 1;
      trickyNearObjFn_801b0af0((int)param1,1);
      iVar9 = randInt(0,1);
      audioTryStartSfx((int *)this,0x90,*(ushort *)((int)&PTR_DAT_80397b10 + iVar9 * 2),0x7f,
                       "tricky.c",0x35d);
      sVar1 = *(short *)(*(int *)(param1 + 0x28) + 0x46);
      if (sVar1 == 0x31c) {
        if (**(byte **)(param1 + 4) < 4) {
          FUN_801b10ac((int *)this,(int)param1);
        }
        else {
          param1[0x18] = 8;
        }
        goto LAB_801a9b58;
      }
      if (sVar1 < 0x31c) {
        if (sVar1 == 0x160) {
          if (**(byte **)(param1 + 4) < 4) {
            FUN_801b10ac((int *)this,(int)param1);
          }
          else {
            param1[0x18] = 3;
          }
          goto LAB_801a9b58;
        }
        if (sVar1 < 0x160) {
          if (sVar1 == 0x6a) {
LAB_801a982c:
            param1[0x18] = 0xc;
            goto LAB_801a9b58;
          }
        }
        else if (sVar1 == 0x1ca) {
          if (**(byte **)(param1 + 4) < 4) {
            FUN_801b10ac((int *)this,(int)param1);
          }
          else {
            param1[0x18] = 2;
          }
          goto LAB_801a9b58;
        }
      }
      else {
        if (sVar1 == 0x358) {
          param1[0x18] = 0x11;
          goto LAB_801a9b58;
        }
        if (sVar1 < 0x358) {
          if (sVar1 == 0x352) {
            if (**(byte **)(param1 + 4) < 4) {
              FUN_801b10ac((int *)this,(int)param1);
            }
            else {
              param1[0x18] = 2;
            }
            goto LAB_801a9b58;
          }
        }
        else if (sVar1 == 0x3fb) goto LAB_801a982c;
      }
      FUN_801afff4((int)param1);
      goto LAB_801a9b58;
    }
    if (0 < iVar9) {
      param1[0x1d] = 2;
      local_40 = 3.402823e+38;
      pOVar4 = getSeqObj(4,this,&local_40);
      pOVar5 = getSeqObj(0x28,this,&local_40);
      if (pOVar5 == (ObjInstance *)0x0) {
        FUN_801aa3a4((int)this,(int)pOVar4);
      }
      else {
        FUN_801aa3a4((int)this,(int)pOVar5);
      }
      goto LAB_801a9b58;
    }
  }
  else {
    if (iVar9 == 5) {
      param1[0x1d] = 5;
      def = objAlloc(0x18,SidekickBal);
      def->cullDist = 0x96;
      def->loadFlags = isManualLoad;
      (def->pos).x = (this->prevPos).x;
      (def->pos).y = (this->prevPos).y;
      (def->pos).z = (this->prevPos).z;
      pOVar4 = objInstantiateCharacter(def,5,-1,-1,this->pMatrix);
      *(ObjInstance **)(param1 + 0x28) = pOVar4;
      FUN_801b0cd0((int)param1,*(int *)(param1 + 0x28) + 0x18);
      param1[0x1a] = 0;
      param1[0x18] = 0xe;
      goto LAB_801a9b58;
    }
    if (iVar9 < 5) {
      if (**(byte **)(param1 + 4) < 4) {
        FUN_801b10ac((int *)this,(int)param1);
        goto LAB_801a9b58;
      }
      param1[0x1d] = 4;
      trickyNearObjFn_801b0af0((int)param1,4);
      param1[0x18] = 10;
      sVar1 = *(short *)(*(int *)(param1 + 0x28) + 0x46);
      if (sVar1 == 0x46b) {
LAB_801a9a5c:
        *(undefined4 *)(param1 + 0x600) = 0;
      }
      else {
        if (sVar1 < 0x46b) {
          if (sVar1 == 0x194) goto LAB_801a9a5c;
          if (sVar1 < 0x194) {
            if (sVar1 == 0x191) {
              *(undefined4 *)(param1 + 0x600) =
                   *(undefined4 *)(**(int **)(*(int *)(param1 + 0x28) + 0x68) + 0x20);
              goto LAB_801a9b58;
            }
          }
          else if (sVar1 == 0x1c9) {
            *(undefined4 *)(param1 + 0x600) =
                 *(undefined4 *)(**(int **)(*(int *)(param1 + 0x28) + 0x68) + 0x20);
            goto LAB_801a9b58;
          }
        }
        else {
          if (sVar1 == 0x542) goto LAB_801a9a5c;
          if (sVar1 < 0x542) {
            if (sVar1 == 0x470) {
              *(undefined4 *)(param1 + 0x600) =
                   *(undefined4 *)(**(int **)(*(int *)(param1 + 0x28) + 0x68) + 0x20);
              goto LAB_801a9b58;
            }
          }
          else if (sVar1 == 0x551) {
            *(undefined4 *)(param1 + 0x600) =
                 *(undefined4 *)(**(int **)(*(int *)(param1 + 0x28) + 0x68) + 0x20);
            goto LAB_801a9b58;
          }
        }
        FUN_801afff4((int)param1);
      }
      goto LAB_801a9b58;
    }
  }
  if ((param1[0x18] == '\x01') && (*(float *)(param1 + 0x5f8) <= 0.0)) {
    local_40 = 150.0;
    iVar9 = FUN_801b0f0c(150.0,*(ObjInstance **)(param1 + 8));
    if (iVar9 != 0) {
      param1[0x18] = 0x10;
      param1[0x1a] = 0;
    }
  }
LAB_801a9b58:
  if ((*(uint *)(param1 + 0x4c) & 0x10) == 0) {
    if ((*(uint *)(param1 + 0x4c) & 0x10000) == 0) {
      if ((*(uint *)(param1 + 0x4c) & 0x20000) != 0) {
        *(ObjInstance **)(param1 + 0x28) = this;
        param1[0x18] = 0x12;
        param1[0x1a] = 0;
        *(float *)(param1 + 0x5f8) = 0.0;
        *(float *)(param1 + 0x5fc) = 0.0;
        *(float *)(param1 + 0x600) = 0.0;
        *(float *)(param1 + 0x604) = 600.0;
        *(uint *)(param1 + 0x4c) = *(uint *)(param1 + 0x4c) & 0xfffdffff;
        param1[0x1d] = 3;
        FUN_801b0cd0((int)param1,(int)(param1 + 0x608));
      }
    }
    else {
      FUN_801afff4((int)param1);
      *(float *)(param1 + 0x5f8) = 600.0;
    }
  }
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  param1[0x323] = 1;
  *(float *)(param1 + 0x24) = *(float *)(param1 + 0x24) + timeDelta;
  (*(code *)trickyStateFuncs[(byte)param1[0x18]])(this,param1);
  objRunAnimation((double)*(float *)(param1 + 0x38),(double)timeDelta,(int)this,&local_5c);
  if ((*(uint *)(param1 + 0x4c) & 0x40) != 0) {
    (this->pos).pos.x =
         *(float *)(param1 + 0x40) * *(float *)(param1 + 0x30) * -local_54 + (this->pos).pos.x;
    (this->pos).pos.z =
         *(float *)(param1 + 0x40) * *(float *)(param1 + 0x34) * -local_54 + (this->pos).pos.z;
  }
  if ((*(uint *)(param1 + 0x4c) & 0x80) != 0) {
    (this->pos).pos.y = local_58 * *(float *)(param1 + 0x44) + (this->pos).pos.y;
  }
  if ((*(uint *)(param1 + 0x4c) & 0x20) != 0) {
    (this->pos).pos.x =
         *(float *)(param1 + 0x3c) * *(float *)(param1 + 0x34) * local_5c + (this->pos).pos.x;
    (this->pos).pos.z =
         *(float *)(param1 + 0x3c) * *(float *)(param1 + 0x30) * -local_5c + (this->pos).pos.z;
  }
  if ((*(uint *)(param1 + 0x4c) & 0x100) != 0) {
    uStack_24 = (int)local_4e ^ 0x80000000;
    local_28 = 0x43300000;
    uStack_2c = (int)(this->pos).rotation.x ^ 0x80000000;
    local_30 = 0x43300000;
    iVar9 = (int)((float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) *
                  *(float *)(param1 + 0x48) +
                 (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0));
    local_38 = (longlong)iVar9;
    (this->pos).rotation.x = (short)iVar9;
  }
  if (*(int *)(param1 + 0x28) == 0) {
    param1[0x33c] = 0;
  }
  else {
    param1[0x33c] = 1;
    *(undefined4 *)(param1 + 0x340) = *(undefined4 *)(*(int *)(param1 + 0x28) + 0xc);
    *(undefined4 *)(param1 + 0x344) = *(undefined4 *)(*(int *)(param1 + 0x28) + 0x10);
    *(undefined4 *)(param1 + 0x348) = *(undefined4 *)(*(int *)(param1 + 0x28) + 0x14);
  }
  FUN_800927d4((short *)this,param1 + 0x33c);
  FUN_800928ac((int)this,(int)(param1 + 0x33c));
  exprFn_800945c0((uint)this,param1 + 0x360);
  FUN_801afefc((int)this);
  param1[0x68c] = 0;
  dVar10 = (double)objDistSqObj2ObjXZ(this,*(ObjInstance **)(param1 + 8));
  if (360000.0 <= dVar10) {
    *(uint *)(param1 + 0x4c) = *(uint *)(param1 + 0x4c) | 0x10000;
  }
  trickyHitsFn_801b0818((int)this);
  return;
}


/* Library Function - Single Match
    dll_D0_func06
   
   Library: KioskDefault 0 0 */

void tricky_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801A9E1C
  byte bVar1;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  if (shouldRender) {
    puVar2 = this->state;
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,param4_00,
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    FUN_801af16c(this);
    if ((*(uint *)(puVar2 + 0x4c) & 0x10) != 0) {
      bVar1 = puVar2[0x18];
      if (bVar1 == 3) {
        if (puVar2[0x1a] == '\x04') {
          Tricky_doDigPartFx((undefined2 *)this);
        }
      }
      else if (bVar1 < 3) {
        if (1 < bVar1) {
          Tricky_doDigPartFx((undefined2 *)this);
        }
      }
      else if (bVar1 == 8) {
        if ((puVar2[0x1a] == '\x03') || (puVar2[0x1a] == '\x02')) {
          FUN_801af3d4((short *)this,param2_00,param3_00,param4_00);
        }
        else if (puVar2[0x1a] == '\x04') {
          return;
        }
      }
      if ((puVar2[0x18] == '\x0e') && (2 < (byte)puVar2[0x1a])) {
        if (puVar2[0x1a] != '\x03') {
          *(undefined4 *)(*(int *)(puVar2 + 0x5e8) + 0xc) = *(undefined4 *)(puVar2 + 0x3b4);
          *(undefined4 *)(*(int *)(puVar2 + 0x5e8) + 0x10) = *(undefined4 *)(puVar2 + 0x3b8);
          *(undefined4 *)(*(int *)(puVar2 + 0x5e8) + 0x14) = *(undefined4 *)(puVar2 + 0x3bc);
        }
        objRenderCurrentModel
                  (*(ObjInstance **)(puVar2 + 0x5e8),(Gfx **)param2_00,param3_00,param4_00,
                   (undefined4 *)CONCAT31(in_register_0000001c,param5));
      }
    }
    FUN_801b0e7c();
  }
  return;
}


/* Library Function - Single Match
    dll_D0_func07
   
   Library: KioskDefault 0 0 */

void tricky_free(ObjInstance *this,int param2) { //801A9F94
  int *piVar1;
  
  piVar1 = (int *)this->state;
  FUN_8009fefc((void **)(piVar1 + 0x138));
  FUN_8009fefc((void **)(piVar1 + 0x144));
  FUN_8009fefc((void **)(piVar1 + 0x150));
  FUN_8009fefc((void **)(piVar1 + 0x15c));
  FUN_8009fefc((void **)(piVar1 + 0x168));
  Object_removePlayerObj(this,1);
                    /* {@symbol 800dc1d4} */
  (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
                    /* {@symbol 800e29b8} */
  (**(code **)(*(int *)pDll_projgfx + 0x14))(this);
  if (param2 == 0) {
    FUN_801b0e90(this,piVar1);
  }
  return;
}


undefined4 tricky_func08(ObjInstance *this) { //801AA040
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int tricky_getExtraSize(void) { //801AA048
  return 0x690;
}


void tricky_setScale(ObjInstance *this,float scale) { //801AA050
  return;
}


void tricky_func0B(void) { //801AA058
  return;
}


void tricky_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //801AA05C
  return;
}


void tricky_render2(ObjInstance *this) { //801AA060
  return;
}


double tricky_func0E(int param1) { //801AA064
  return (double)*(float *)(*(int *)(param1 + 0xb8) + 0x20);
}


undefined4 tricky_func0F(void) { //801AA080
  return 0;
}


/* Library Function - Single Match
    dll_D0_func10
   
   Library: KioskDefault 0 0 */

uint tricky_func10(int param1) { //801AA088
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param1 + 0xb8);
  uVar1 = mainGetBit(0x4e4);
  if (uVar1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(byte *)(iVar3 + 0x1b) | 9;
    if (((*(char *)(iVar3 + 0x18) == '\v') ||
        ((*(char *)(iVar3 + 0x18) == '\x10' && (*(char *)(iVar3 + 0x1a) == '\x01')))) ||
       ((*(char *)(iVar3 + 0x18) == '\x11' && (*(char *)(iVar3 + 0x1a) == '\x01')))) {
      uVar1 = *(byte *)(iVar3 + 0x1b) | 0x19;
    }
    uVar2 = mainGetBit(0x3f8);
    if (uVar2 != 0) {
      uVar1 = uVar1 | 0x20;
    }
    uVar2 = mainGetBit(0xdd);
    if (uVar2 == 0) {
      uVar1 = uVar1 & 0xfffffff7;
    }
    uVar2 = mainGetBit(0x9e);
    if (uVar2 == 0) {
      uVar1 = uVar1 & 0xfffffffb;
    }
    uVar2 = mainGetBit(0x245);
    if (uVar2 == 0) {
      uVar1 = uVar1 & 0xffffffef;
    }
    uVar1 = uVar1 | 4;
    *(undefined *)(iVar3 + 0x1b) = 0;
  }
  return uVar1;
}


undefined4 tricky_func1D(int param1,uint *param2) { //801AA17C
  *param2 = (uint)*(byte *)(*(int *)(param1 + 0xb8) + 0x1d);
  return 1;
}


/* Library Function - Single Match
    dll_D0_func11
   
   Library: KioskDefault 0 0 */

void tricky_func11(int param1,undefined4 param2,undefined4 param3,int param4) { //801AA1A0
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  if ((param4 < 6) && (*(char *)(iVar1 + 0x68c) != '\n')) {
    *(byte *)(iVar1 + 0x1b) = *(byte *)(iVar1 + 0x1b) | (byte)(1 << param4);
    *(undefined4 *)(iVar1 + (uint)*(byte *)(iVar1 + 0x68c) * 0xc + 0x614) = param2;
    *(undefined4 *)(iVar1 + (uint)*(byte *)(iVar1 + 0x68c) * 0xc + 0x618) = param3;
    *(int *)(iVar1 + (uint)*(byte *)(iVar1 + 0x68c) * 0xc + 0x61c) = param4;
    *(char *)(iVar1 + 0x68c) = *(char *)(iVar1 + 0x68c) + '\x01';
  }
  return;
}


undefined tricky_func12(int param1) { //801AA224
  return **(undefined **)(*(int *)(param1 + 0xb8) + 4);
}


undefined tricky_func13(int param1) { //801AA244
  return *(undefined *)(*(int *)(*(int *)(param1 + 0xb8) + 4) + 1);
}


/* Library Function - Single Match
    dll_D0_func14
   
   Library: KioskDefault 0 0 */

int tricky_func14(int param1) { //801AA264
  return (uint)**(byte **)(*(int *)(param1 + 0xb8) + 4) +
         (uint)*(byte *)(*(int *)(*(int *)(param1 + 0xb8) + 4) + 1);
}


void tricky_func15(int param1,undefined param2) { //801AA290
  *(undefined *)(*(int *)(*(int *)(param1 + 0xb8) + 4) + 1) = param2;
  return;
}


undefined4 tricky_func16(void) { //801AA2B0
  return 1;
}


void tricky_func17(void) { //801AA2B8
  return;
}


/* Library Function - Single Match
    dll_D0_func18
   
   Library: KioskDefault 0 0 */

void tricky_func18(int param1,int param2,int param3) { //801AA2BC
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  if (param2 == 0) {
    *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) | 0x10000;
  }
  else if ((*(uint *)(iVar1 + 0x4c) & 0x10) == 0) {
    FUN_801aa3a4(param1,param3);
  }
  return;
}


/* Library Function - Single Match
    dll_D0_sideFind
   
   Library: KioskDefault 0 0 */

void tricky_sideFind(ObjInstance *param1,int param2) { //801AA324
  undefined *puVar1;
  
  puVar1 = param1->state;
  printf("sideFind 1");
  if ((*(uint *)(puVar1 + 0x4c) & 0x10) == 0) {
    printf("sideFind 2");
    *(int *)(puVar1 + 0x28) = param2;
    FUN_801b0cd0((int)puVar1,param2 + 0x18);
    puVar1[0x1a] = 0;
    puVar1[0x18] = 0xd;
  }
  return;
}


/* Library Function - Single Match
    dll_D0_func1B
   
   Library: KioskDefault 0 0 */

undefined4 tricky_func1B(int param1) { //801AA464
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(*(int *)(param1 + 0xb8) + 0x18);
  if (bVar1 == 7) {
    uVar2 = 1;
  }
  else if (((bVar1 < 7) && (4 < bVar1)) &&
          ((*(uint *)(*(int *)(param1 + 0xb8) + 0x4c) & 0x200) != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* Library Function - Single Match
    dll_D0_func1C
   
   Library: KioskDefault 0 0 */

undefined4 tricky_func1C(int param1) { //801AA4B8
  undefined4 uVar1;
  
  if ((*(char *)(*(int *)(param1 + 0xb8) + 0x18) == '\v') ||
     (*(char *)(*(int *)(param1 + 0xb8) + 0x18) == '\x11')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* Library Function - Single Match
    dll_D0_func1A
   
   Library: KioskDefault 0 0 */

void tricky_func1A(int param1) { //801AA4F4
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param1 + 0xb8);
  uVar1 = mainGetBit(0x4e4);
  if (uVar1 != 0) {
    *(uint *)(iVar2 + 0x4c) = *(uint *)(iVar2 + 0x4c) | 0x10000;
  }
  return;
}


void trickyState2(undefined8 param_1,undefined8 param2,double param3,ObjInstance *param4,int param5) { //801AAC84
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  float *pfVar5;
  double dVar6;
  
  pfVar5 = (float *)(param5 + 0x30);
  iVar4 = *(int *)(param5 + 0x28);
  bVar1 = *(byte *)(param5 + 0x1a);
  if (bVar1 == 2) {
    *(float *)(param5 + 0x5e8) = *(float *)(param5 + 0x5e8) + timeDelta;
    tricky_yawOfVector((ushort *)param4,1);
    if (60.0 <= *(float *)(param5 + 0x5e8)) {
      *(undefined *)(param5 + 0x1a) = 3;
      *(float *)(param5 + 0x5ec) = (param4->pos).pos.x;
      *(float *)(param5 + 0x5f0) = (param4->pos).pos.z;
      if (*(int *)(param5 + 0x5f4) != 0) {
        FUN_801b0c34(*(int *)(param5 + 0x28),(float *)(*(int *)(param5 + 0x5f4) + 8),pfVar5);
      }
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
                    /* {@symbol 80122d00} */
      uVar2 = (**(code **)(*(int *)pDll_curve + 0x18))(*(int *)(param5 + 0x28) + 0xc,0xffffffff,2);
      *(undefined4 *)(param5 + 0x5f4) = uVar2;
      *(float *)(param5 + 0x5f8) = 1.0;
      if ((*(int *)(param5 + 0x5f4) != 0) &&
         (dVar6 = (double)objDistObj2Def(*(ObjInstance **)(param5 + 0x28),
                                         *(ObjDef **)(param5 + 0x5f4)), 10000.0 < dVar6)) {
        *(undefined4 *)(param5 + 0x5f4) = 0;
        *(float *)(param5 + 0x5f8) = 2.0;
      }
      if (*(int *)(param5 + 0x5f4) != 0) {
        FUN_801b0cd0(param5,*(int *)(param5 + 0x5f4) + 8);
      }
      *(undefined *)(param5 + 0x1a) = 1;
    }
    else if (false) {
      return;
    }
    iVar4 = walkTypeFn_801ad4d4(5.0,param2,param3,param4,param5);
    if (iVar4 == 0) {
      *(uint *)(param5 + 0x4c) = *(uint *)(param5 + 0x4c) | 0x10;
      *(undefined *)(param5 + 0x1a) = 2;
      *(float *)(param5 + 0x5e8) = 0.0;
      audioTryStartSfx((int *)param4,0x20,0x186,0x7f,"tricky.c",0x70b);
      Object_ObjAnimSetMove(0.0,param4,0xe,0);
      *(float *)(param5 + 0x38) = 0.033;
      if (*(int *)(param5 + 0x5f4) != 0) {
        FUN_801b0c34(*(int *)(param5 + 0x28),(float *)(*(int *)(param5 + 0x5f4) + 8),pfVar5);
      }
    }
  }
  else if (bVar1 < 4) {
    dVar6 = (double)(**(code **)(**(int **)(iVar4 + 0x68) + 0x20))(iVar4,param4);
    (param4->pos).pos.x =
         -(*pfVar5 * (float)(dVar6 / (double)*(float *)(param5 + 0x5f8)) -
          *(float *)(param5 + 0x5ec));
    (param4->pos).pos.z =
         -(*(float *)(param5 + 0x34) * (float)(dVar6 / (double)*(float *)(param5 + 0x5f8)) -
          *(float *)(param5 + 0x5f0));
    tricky_yawOfVector((ushort *)param4,1);
    cVar3 = (**(code **)(**(int **)(iVar4 + 0x68) + 0x24))(iVar4);
    if (cVar3 != '\0') {
      FUN_80068a9c((uint)param4,0x20);
      **(char **)(param5 + 4) = **(char **)(param5 + 4) + -4;
      FUN_801afff4(param5);
    }
  }
  return;
}


void trickyState3(undefined8 param_1,undefined8 param2,double param3,ObjInstance *param4,int param5) { //801AAF28
  uint uVar1;
  char cVar5;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  double extraout_f1;
  double dVar6;
  
                    /* {@symbol 801aaf68} */
  switch(*(undefined *)(param5 + 0x1a)) {
  case 0:
                    /* {@symbol 80122e5c} */
    iVar3 = (**(code **)(*(int *)pDll_curve + 0x1c))(*(undefined4 *)(param5 + 0x2c),0xffffffff,2);
                    /* {@symbol 8012464c} */
    uVar2 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))(*(undefined4 *)(iVar3 + 0x1c));
    *(undefined4 *)(param5 + 0x5f0) = uVar2;
    *(int *)(param5 + 0x5e8) = iVar3;
                    /* {@symbol 8012464c} */
    uVar2 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))(*(undefined4 *)(iVar3 + 0x20));
    *(undefined4 *)(param5 + 0x5ec) = uVar2;
    if (*(char *)(*(int *)(param5 + 0x5ec) + 3) != '\0') {
      *(uint *)(param5 + 0x5ec) = *(uint *)(param5 + 0x5ec) ^ *(uint *)(param5 + 0x5f0);
      *(uint *)(param5 + 0x5f0) = *(uint *)(param5 + 0x5f0) ^ *(uint *)(param5 + 0x5ec);
      *(uint *)(param5 + 0x5ec) = *(uint *)(param5 + 0x5ec) ^ *(uint *)(param5 + 0x5f0);
    }
    FUN_801b0cd0(param5,*(int *)(param5 + 0x5f0) + 8);
    *(undefined *)(param5 + 0x1a) = 1;
  case 1:
    walkTypeFn_801ad4d4(5.0,param2,param3,param4,param5);
                    /* {@symbol 80121f7c} */
    uVar1 = (**(code **)(*(int *)pDll_curve + 8))(&(param4->pos).pos,0);
    if (*(byte *)(*(int *)(param5 + 0x5f0) + 3) == uVar1) {
      *(undefined *)(param5 + 0x19) = 1;
      *(undefined *)(param5 + 0x1a) = 2;
    }
    break;
  case 2:
    iVar3 = FUN_801ad188(2.5,param4,param5,(float *)(*(int *)(param5 + 0x5e8) + 8));
    if (iVar3 == 0) {
      dVar6 = extraout_f1;
      objDistSqObj2Def(param4,*(ObjDef **)(param5 + 0x5e8));
      *(float *)(param5 + 0x20) = (float)(dVar6 / (double)timeDelta);
      FUN_801b0168(param4,(float *)(*(int *)(param5 + 0x5e8) + 8),1);
      *(uint *)(param5 + 0x4c) = *(uint *)(param5 + 0x4c) | 0x10;
      *(undefined *)(param5 + 0x1a) = 3;
    }
    else {
                    /* {@symbol 80121f7c} */
      iVar3 = (**(code **)(*(int *)pDll_curve + 8))(&(param4->pos).pos,0);
      if (iVar3 == 0) {
        *(uint *)(param5 + 0x4c) = *(uint *)(param5 + 0x4c) | 0x2010;
      }
    }
    break;
  case 3:
    Object_ObjAnimSetMove(0.0,param4,0xe,0);
    *(float *)(param5 + 0x38) = 0.033;
    *(float *)(param5 + 0x30) =
         *(float *)(*(int *)(param5 + 0x5ec) + 8) - *(float *)(*(int *)(param5 + 0x5e8) + 8);
    *(float *)(param5 + 0x34) =
         *(float *)(*(int *)(param5 + 0x5ec) + 0x10) - *(float *)(*(int *)(param5 + 0x5e8) + 0x10);
    audioTryStartSfx((int *)param4,0x20,0x186,0x7f,"tricky.c",0x766);
    *(undefined *)(param5 + 0x1a) = 4;
  case 4:
    dVar6 = (double)(**(code **)(**(int **)(*(int *)(param5 + 0x28) + 0x68) + 0x20))
                              (*(undefined4 *)(param5 + 0x28),param4);
    (param4->pos).pos.x =
         (float)((double)*(float *)(param5 + 0x30) * dVar6 +
                (double)*(float *)(*(int *)(param5 + 0x5e8) + 8));
    (param4->pos).pos.z =
         (float)((double)*(float *)(param5 + 0x34) * dVar6 +
                (double)*(float *)(*(int *)(param5 + 0x5e8) + 0x10));
    tricky_yawOfVector((ushort *)param4,1);
    cVar5 = (**(code **)(**(int **)(*(int *)(param5 + 0x28) + 0x68) + 0x24))
                      (*(undefined4 *)(param5 + 0x28));
    if (cVar5 != '\0') {
      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        if ((-1 < *(int *)(*(int *)(param5 + 0x5ec) + iVar3 * 4 + 0x1c)) &&
           (*(int *)(*(int *)(param5 + 0x5ec) + iVar3 * 4 + 0x1c) !=
            *(int *)(*(int *)(param5 + 0x5e8) + 0x14))) {
          *(undefined4 *)(param5 + 0x5e8) = *(undefined4 *)(param5 + 0x5ec);
                    /* {@symbol 8012464c} */
          uVar2 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))
                            (*(undefined4 *)(*(int *)(param5 + 0x5ec) + iVar3 * 4 + 0x1c));
          *(undefined4 *)(param5 + 0x5ec) = uVar2;
          break;
        }
      }
      **(char **)(param5 + 4) = **(char **)(param5 + 4) + -4;
      FUN_80068a9c((uint)param4,0x20);
      *(undefined *)(param5 + 0x1a) = 5;
    }
    break;
  case 5:
    iVar3 = FUN_801ad188(2.5,param4,param5,(float *)(*(int *)(param5 + 0x5ec) + 8));
    if (iVar3 == 0) {
      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        if ((-1 < *(int *)(*(int *)(param5 + 0x5ec) + iVar3 * 4 + 0x1c)) &&
           (*(int *)(*(int *)(param5 + 0x5ec) + iVar3 * 4 + 0x1c) !=
            *(int *)(*(int *)(param5 + 0x5e8) + 0x14))) {
          *(undefined4 *)(param5 + 0x5e8) = *(undefined4 *)(param5 + 0x5ec);
                    /* {@symbol 8012464c} */
          uVar2 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))
                            (*(undefined4 *)(*(int *)(param5 + 0x5ec) + iVar3 * 4 + 0x1c));
          *(undefined4 *)(param5 + 0x5ec) = uVar2;
          break;
        }
      }
      *(undefined *)(param5 + 0x1a) = 6;
    }
    break;
  case 6:
    iVar3 = FUN_801ad188(2.5,param4,param5,(float *)(*(int *)(param5 + 0x5ec) + 8));
    if (iVar3 == 0) {
      FUN_801b00f8(param4,param5);
      *(uint *)(param5 + 0x4c) = *(uint *)(param5 + 0x4c) & 0xffffdfef;
      *(undefined *)(param5 + 0x1a) = 7;
    }
    break;
  case 7:
                    /* {@symbol 80121f7c} */
    iVar3 = (**(code **)(*(int *)pDll_curve + 8))(*(int *)(param5 + 8) + 0xc,0);
                    /* {@symbol 80121f7c} */
    iVar4 = (**(code **)(*(int *)pDll_curve + 8))(&(param4->pos).pos,0);
    if (iVar4 == iVar3) {
      FUN_801afff4(param5);
    }
  }
  return;
}


void trickyState8(undefined8 param_1,undefined8 param2,double param3,ObjInstance *param4,int param5) { //801ABAD0
  byte bVar1;
  float fVar2;
  ObjDef *pOVar3;
  int iVar4;
  double dVar5;
  
  if ((*(uint *)(param5 + 0x4c) & 0x10) == 0) {
    iVar4 = walkTypeFn_801ad4d4(5.0,param2,param3,param4,param5);
    if (iVar4 != 0) {
      return;
    }
    iVar4 = *(int *)(*(int *)(param5 + 0x28) + 0x4c);
    *(float *)(param5 + 0x5e8) = -5.0;
    *(float *)(param5 + 0x5f0) = 0.0001;
    FUN_801b00f8(param4,param5);
    if (*(char *)(param5 + 0x1a) == '\0') {
      dVar5 = (double)objDistSqObj2ObjXZ(param4,*(ObjInstance **)(param5 + 0x28));
      if (dVar5 <= 400.0) {
        pOVar3 = mapObjFindFn_800a8cb4
                           (*(int *)(iVar4 + 0x1c),(int *)0x0,(int *)0x0,(int *)0x0,(uint *)0x0);
        *(ObjDef **)(param5 + 0x5ec) = pOVar3;
        *(uint *)(param5 + 0x4c) = *(uint *)(param5 + 0x4c) | 0x10;
        *(undefined *)(param5 + 0x1a) = 3;
        audioTryStartSfx((int *)param4,8,0x1e9,0x7f,"tricky.c",0x88a);
        **(char **)(param5 + 4) = **(char **)(param5 + 4) + -4;
      }
      else {
        pOVar3 = mapObjFindFn_800a8cb4
                           (*(int *)(iVar4 + 0x1c),(int *)0x0,(int *)0x0,(int *)0x0,(uint *)0x0);
        FUN_801b0cd0(param5,(int)&pOVar3->pos);
        *(undefined *)(param5 + 0x1a) = 1;
      }
    }
    else {
      *(int *)(param5 + 0x5ec) = iVar4;
      *(uint *)(param5 + 0x4c) = *(uint *)(param5 + 0x4c) | 0x10;
      *(undefined *)(param5 + 0x1a) = 3;
      audioTryStartSfx((int *)param4,8,0x1e9,0x7f,"tricky.c",0x892);
      **(char **)(param5 + 4) = **(char **)(param5 + 4) + -4;
    }
  }
  else {
    bVar1 = *(byte *)(param5 + 0x1a);
    if (bVar1 == 3) {
      param4->shadow->flags = param4->shadow->flags | 0x1000;
      *(float *)(param5 + 0x5e8) = timeDelta * 0.1 + *(float *)(param5 + 0x5e8);
      if (20.0 < *(float *)(param5 + 0x5e8)) {
        *(float *)(param5 + 0x5e8) = 20.0;
        *(float *)(param5 + 0x5f4) = 30.0;
        *(undefined *)(param5 + 0x1a) = 4;
        FUN_80068a9c((uint)param4,8);
        iVar4 = *(int *)(param5 + 0x5ec);
        (param4->pos).pos.x = *(float *)(iVar4 + 8);
        (param4->pos).pos.y = *(float *)(iVar4 + 0xc);
        (param4->pos).pos.z = *(float *)(iVar4 + 0x10);
        *(undefined *)(param5 + 0x323) = 0;
      }
    }
    else if (bVar1 < 3) {
      if ((1 < bVar1) &&
         (*(float *)(param5 + 0x5e8) = -(timeDelta * 0.1 - *(float *)(param5 + 0x5e8)),
         *(float *)(param5 + 0x5e8) < -5.0)) {
        **(char **)(param5 + 4) = **(char **)(param5 + 4) + -4;
        FUN_801afff4(param5);
        FUN_80068a9c((uint)param4,8);
        param4->shadow->flags = param4->shadow->flags & 0xffffefff;
      }
    }
    else if ((bVar1 < 5) &&
            (fVar2 = *(float *)(param5 + 0x5f4) - timeDelta, *(float *)(param5 + 0x5f4) = fVar2,
            fVar2 <= 0.0)) {
      *(undefined *)(param5 + 0x1a) = 2;
      audioTryStartSfx((int *)param4,8,0x1e9,0x7f,"tricky.c",0x872);
    }
  }
  *(float *)(param5 + 0x38) = 0.005;
  return;
}


/* Library Function - Single Match
    tricky_yawOfVector
   
   Library: KioskDefault 0 0 */

void tricky_yawOfVector(ushort *param1,int param2) { //801B0420
  int iVar1;
  int iVar2;
  float *pfVar3;
  double dVar4;
  
  iVar1 = *(int *)(param1 + 0x5c);
  pfVar3 = (float *)(iVar1 + 0x30);
  dVar4 = (double)(*pfVar3 * *pfVar3 + *(float *)(iVar1 + 0x34) * *(float *)(iVar1 + 0x34));
  if (0.009999999776482582 < dVar4) {
    iVar2 = getAngle();
    FUN_801b05cc(param1,(ushort)iVar2);
    if (param2 == 0) {
      if ((dVar4 <= 0.9900000095367432) || (1.009999990463257 <= dVar4)) {
                    
        OSPanic("tricky.c",0x1159,"yawOfVector: need to recalculate the vector with length");
      }
      dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)(short)*param1 ^
                                                                             0x80000000) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      *pfVar3 = (float)-dVar4;
      dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(short)*param1 ^
                                                                         0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
      *(float *)(iVar1 + 0x34) = (float)-dVar4;
    }
  }
  return;
}


/* Library Function - Single Match
    trickyNearObjFn_801b0af0
   
   Library: KioskDefault 0 0 */

void trickyNearObjFn_801b0af0(int param1,int param2) { //801B0AF0
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  _savefpr_29();
  dVar6 = 3.402823466385289e+38;
  iVar1 = 0;
  dVar5 = 3.402823466385289e+38;
  iVar2 = 0;
  for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(param1 + 0x68c); iVar3 = iVar3 + 1) {
    if (*(int *)(param1 + iVar3 * 0xc + 0x61c) == param2) {
      dVar4 = (double)objDistSqObj2ObjXZ(*(ObjInstance **)(param1 + 8),
                                         *(ObjInstance **)(param1 + iVar3 * 0xc + 0x614));
      if (*(int *)(param1 + iVar3 * 0xc + 0x618) == 1) {
        if (dVar4 < dVar6) {
          iVar1 = *(int *)(param1 + iVar3 * 0xc + 0x614);
          dVar6 = dVar4;
        }
      }
      else if (dVar4 < dVar5) {
        iVar2 = *(int *)(param1 + iVar3 * 0xc + 0x614);
        dVar5 = dVar4;
      }
    }
  }
  if (iVar1 == 0) {
    if ((iVar2 == 0) && (param2 != 3)) {
                    
      OSPanic("tricky.c",0x1274,"Failed assertion !( !nearestLowObj && command != SIDECMD_GUARD )");
    }
    if (iVar2 == 0) goto LAB_801b0c18;
    *(int *)(param1 + 0x28) = iVar2;
  }
  else {
    *(int *)(param1 + 0x28) = iVar1;
  }
  FUN_801b0cd0(param1,*(int *)(param1 + 0x28) + 0x18);
  *(undefined *)(param1 + 0x1a) = 0;
LAB_801b0c18:
  _restfpr_29();
  return;
}

