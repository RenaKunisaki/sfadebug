
void FUN_800c8a10(uint param_1,int param_2,short param_3) { //800C8A10
  byte bVar1;
  bool bVar3;
  int iVar2;
  int iVar4;
  
  iVar4 = 4;
  while (bVar3 = iVar4 != 0, iVar4 = iVar4 + -1, bVar3) {
    bVar1 = (byte)iVar4;
    bVar3 = FUN_80068b20(param_1,bVar1);
    if (bVar3) {
      if (*(short *)(param_2 + iVar4 * 2 + 0x30) < 1) {
        FUN_80068a9c(param_1,bVar1);
        *(undefined2 *)(param_2 + iVar4 * 2 + 0x30) = 0;
        if (iVar4 != 3) {
          *(byte *)(param_2 + 0x76) = bVar1;
        }
      }
      if ((0 < *(short *)(param_2 + iVar4 * 2 + 0x30)) &&
         (*(short *)(param_2 + iVar4 * 2 + 0x30) != 32000)) {
        iVar2 = iVar4 * 2 + 0x30;
        *(short *)(param_2 + iVar2) = *(short *)(param_2 + iVar2) - param_3;
      }
    }
    else {
      *(undefined2 *)(param_2 + iVar4 * 2 + 0x30) = 0;
      if (iVar4 != 3) {
        *(byte *)(param_2 + 0x76) = bVar1;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    ObjSeq_camCtrl
   
   Library: KioskDefault 0 0 */

void ObjSeq_camCtrl(ObjInstance *param1,uint param2) { //800C8B14
  float fVar1;
  int iVar2;
  u16 uVar5;
  int iVar3;
  Camera *pCVar4;
  s8 sVar7;
  s8 sVar8;
  N64Button NVar6;
  bool bVar9;
  int iVar10;
  int unaff_r19;
  uint uVar11;
  uint uVar12;
  ObjDef *pOVar13;
  ObjInstance **param3;
  double dVar14;
  double in_f21;
  double dVar15;
  double in_f26;
  double dVar16;
  double dVar17;
  double dVar18;
  float local_e4;
  short *local_e0;
  Model *local_dc;
  ObjInstance *local_d8 [2];
  double local_d0;
  undefined4 local_c8;
  uint uStack_c4;
  longlong local_c0;
  longlong local_b8;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  
  _savefpr_20();
  iVar10 = 0;
  pOVar13 = param1->def;
  if (pOVar13 != (ObjDef *)0x0) {
    param3 = (ObjInstance **)param1->state;
    local_d8[0] = *param3;
    iVar2 = FUN_8017fac8((int)param1);
    if (iVar2 == 0) {
      DAT_80398f34 = '\0';
      DAT_80398f0a = 0;
      DAT_80398f11 = 0;
      DAT_80398f12 = 0;
      if (((DAT_80399a74 == '\0') && (((&DAT_8038319c)[*(char *)((int)param3 + 0x4f)] & 8) != 0)) &&
         (((&DAT_803832b0)[*(char *)((int)param3 + 0x4f)] != '\0' ||
          (uVar5 = getEnabledButtonsPressed(0), (uVar5 & 0x40) != 0)))) {
        if (*(char *)((int)param3 + 0x77) != '\0') {
          *(byte *)((int)param3 + 0x89) = *(byte *)((int)param3 + 0x89) | 0x80;
          DAT_80398ef8 = 0;
          local_d8[0] = param1;
          if (*param3 != (ObjInstance *)0x0) {
            local_d8[0] = *param3;
            local_d8[0]->pObj_0xc0 = param1;
            local_d8[0]->flags_0xb0 = local_d8[0]->flags_0xb0 | SeqActive;
          }
          if ((&DAT_803832b0)[*(char *)((int)param3 + 0x4f)] == '\0') {
            if ((*param3 != (ObjInstance *)0x0) && ((*param3)->curSeq != -1)) {
                    /* {@symbol 8011b17c} */
              (**(code **)(*(int *)pDll_gplay + 0xc))(0x1e,1);
              *(float *)(&DAT_803832e0 + *(char *)((int)param3 + 0x4f) * 4) = 0.0;
              (&DAT_803832b0)[*(char *)((int)param3 + 0x4f)] = 1;
              DAT_80398f24 = -1;
            }
          }
          else if ((*param3 == (ObjInstance *)0x0) || ((*param3)->curSeq == -1)) {
            if (50.0 < *(float *)(&DAT_803832e0 + *(char *)((int)param3 + 0x4f) * 4)) {
              FUN_800cf11c((uint)param1,(int)local_d8[0],(int *)param3);
              goto LAB_800ca264;
            }
            if (40.0 < *(float *)(&DAT_803832e0 + *(char *)((int)param3 + 0x4f) * 4)) {
              FUN_800ca280(param1,local_d8[0],param3);
            }
          }
          else {
            iVar10 = *(char *)((int)param3 + 0x4f) * 4;
            *(float *)(&DAT_803832e0 + iVar10) = *(float *)(&DAT_803832e0 + iVar10) + timeDelta;
            if (60.0 < *(float *)(&DAT_803832e0 + *(char *)((int)param3 + 0x4f) * 4)) {
              if (DAT_80398f24 == -1) {
                    /* {@symbol 8011b1f0} */
                (**(code **)(*(int *)pDll_gplay + 0x10))(0x1e,1);
              }
              else {
                warpToMap((int)DAT_80398f24,false);
              }
              FUN_800cf11c((uint)param1,(int)local_d8[0],(int *)param3);
              goto LAB_800ca264;
            }
            if (40.0 < *(float *)(&DAT_803832e0 + *(char *)((int)param3 + 0x4f) * 4)) {
              FUN_800ca280(param1,local_d8[0],param3);
                    /* {@symbol 8011e5b4} */
              (**(code **)(*(int *)pDll_Dummy15 + 0x14))();
            }
          }
          FUN_800ca7e4((short *)param1,(int)local_d8[0],(int)param3,(int)*(short *)(param3 + 0x14));
          if (local_d8[0] != param1) {
            objCallSeqFn(local_d8[0],param1,param3);
          }
          objAnimFn_800849e8((int)param1,(int)param3);
          if (*(char *)((int)param3 + 0x72) == '\x01') {
            FUN_800ccee0((int)param1,(int)pOVar13);
          }
          (param1->pos).rotation.x = (param1->pos).rotation.x + *(short *)((int)param3 + 0x1a);
          objAnimFn_8008718c(param1,local_d8[0],(int)param3);
          if (((*param3 != (ObjInstance *)0x0) && ((*param3)->curSeq != -1)) &&
             (((&DAT_8038319c)[*(char *)((int)param3 + 0x4f)] & 0x10) == 0)) {
                    /* {@symbol 801544d0} */
            (**(code **)(*(int *)pDll_ObjSeq + 0x5c))(0x3c,1);
          }
        }
      }
      else if (*(char *)((int)param3 + 0x77) == '\x03') {
        if (*param3 != (ObjInstance *)0x0) {
          local_d8[0]->pObj_0xc0 = param1;
          local_d8[0]->flags_0xb0 = local_d8[0]->flags_0xb0 | SeqActive;
        }
      }
      else {
        if ((&DAT_80383280)[*(char *)((int)param3 + 0x4f)] == '\x01') {
          *(undefined2 *)(param3 + 0x14) =
               *(undefined2 *)(&DAT_803830b4 + *(char *)((int)param3 + 0x4f) * 2);
          *(undefined2 *)((int)param3 + 0x52) = *(undefined2 *)(param3 + 0x14);
          findAction(param1,local_d8[0],(int)param3);
        }
        else {
          *(undefined2 *)(param3 + 0x14) = (&DAT_80382ffc)[*(char *)((int)param3 + 0x4f)];
        }
        FUN_800c8a10((uint)param1,(int)param3,(short)param2);
        (&DAT_80382e00)[*(char *)((int)param3 + 0x4f)] = 0;
        while( true ) {
          DAT_80398f10 = 0;
          if (((DAT_80399a74 != '\0') && (*(char *)((int)param3 + 0x4f) == DAT_80397930)) &&
             (*(char *)((int)param3 + 0x77) == '\0')) {
            *(undefined *)((int)param3 + 0x77) = 2;
          }
          if (*(char *)((int)param3 + 0x77) == '\0') break;
          if ((DAT_80399a74 != '\0') && (*(char *)((int)param3 + 0x4f) != DAT_80397930))
          goto LAB_800ca264;
          dummiedProfFn_8017a59c(0xff0000ff);
          if (*param3 == (ObjInstance *)0x0) {
            local_d8[0] = param1;
            if ((*(char *)((int)param3 + 0x73) == '\0') && (*(char *)((int)param3 + 0x4e) < '\x04'))
            {
              *(undefined *)((int)param3 + 0x4e) = 0xff;
            }
          }
          else {
            local_d8[0] = *param3;
            local_d8[0]->pObj_0xc0 = param1;
            local_d8[0]->flags_0xb0 = local_d8[0]->flags_0xb0 | SeqActive;
          }
          if (((&DAT_80382e80)[*(char *)((int)param3 + 0x4f)] != '\0') &&
             ((&DAT_80382fcc)[*(char *)((int)param3 + 0x4f)] != '\0')) {
            *(short *)(param3 + 0x14) =
                 *(short *)(param3 + 0x14) -
                 (short)(char)(&DAT_80382fcc)[*(char *)((int)param3 + 0x4f)];
            if (*(short *)(param3 + 0x14) < 0) {
              *(undefined2 *)(param3 + 0x14) = 0;
            }
            *(short *)((int)param3 + 0x52) = *(short *)(param3 + 0x14) + -1;
            FUN_800cb048(param1,local_d8[0],(short **)param3,1);
          }
          DAT_80398f3e = 0;
          bVar9 = local_d8[0] != param1;
          if (bVar9) {
            objCallSeqFn(local_d8[0],param1,param3);
          }
          DAT_80398f3e = bVar9;
          FUN_800cbc40(param1,local_d8[0],(int)param3);
          if (DAT_80399a74 != '\0') {
            param3[0x11] = (ObjInstance *)0.0;
            *(undefined *)((int)param3 + 0x4e) = 0;
          }
          if (*(char *)((int)param3 + 0x77) == '\x02') {
            FUN_800cbd70(param1,local_d8,(short **)param3,(int)pOVar13,&local_dc);
            goto LAB_800ca264;
          }
          if ((&DAT_80382e80)[*(char *)((int)param3 + 0x4f)] == '\x01') {
            param2 = 0;
          }
          else if ((&DAT_80382e80)[*(char *)((int)param3 + 0x4f)] == '\x02') {
            *(undefined2 *)(param3 + 0x14) = *(undefined2 *)(param3 + 0x15);
            DAT_80398f11 = 1;
          }
          else if (((&DAT_80382e80)[*(char *)((int)param3 + 0x4f)] == '\x03') &&
                  (iVar2 = findLabel((int)param3), -1 < iVar2)) {
            (&DAT_80382e00)[*(char *)((int)param3 + 0x4f)] = 1;
            *(short *)(param3 + 0x14) = (short)iVar2;
            *(undefined2 *)((int)param3 + 0x52) = *(undefined2 *)(param3 + 0x14);
          }
          if (((*param3 != (ObjInstance *)0x0) && ((*param3)->curSeq != -1)) &&
             (((&DAT_8038319c)[*(char *)((int)param3 + 0x4f)] & 0x10) == 0)) {
                    /* {@symbol 801544d0} */
            (**(code **)(*(int *)pDll_ObjSeq + 0x5c))(0x3c,1);
          }
          if ((&DAT_8038316c)[*(char *)((int)param3 + 0x4f)] != '\0') {
            *(undefined2 *)((int)param3 + 0x1a) =
                 *(undefined2 *)(&DAT_80383110 + *(char *)((int)param3 + 0x4f) * 2);
          }
          uVar12 = DAT_803999b0 & 0xf;
          iVar2 = isModelAnimDisabled();
          if (iVar2 == 0) {
            uVar12 = 1;
          }
          DAT_80398f28 = DAT_80397674;
          if (uVar12 == 0) {
            (&DAT_80383058)[*(char *)((int)param3 + 0x4f)] = (short)DAT_803999b4;
          }
          iVar2 = DAT_803999b4;
          if (*(short *)(param3 + 0x15) <= DAT_803999b4) {
            iVar2 = *(short *)(param3 + 0x15) + -1;
          }
          if (uVar12 == 1) {
            if (*(char *)(param3 + 0x1d) != '\0') {
              bVar9 = checkSomeDebugFlags_8017c4f8();
              if (bVar9) {
                if (DAT_80397674 == 0) {
                  param2 = 0;
                  (&DAT_80383058)[*(char *)((int)param3 + 0x4f)] = *(undefined2 *)(param3 + 0x14);
                }
                else {
                  *(undefined *)(param3 + 0x1d) = 0;
                }
              }
              else {
                iVar2 = evalCondition(*(char *)(param3 + 0x1d) + -1,(int)param3);
                if (iVar2 == 0) {
                  *(undefined *)(param3 + 0x1d) = 0;
                }
                else {
                  param2 = 0;
                  (&DAT_80383058)[*(char *)((int)param3 + 0x4f)] = *(undefined2 *)(param3 + 0x14);
                }
              }
            }
            *(short *)(param3 + 0x14) = *(short *)(param3 + 0x14) + (short)param2;
            if (*(short *)(param3 + 0x15) < *(short *)(param3 + 0x14)) {
              *(undefined2 *)(param3 + 0x14) = *(undefined2 *)(param3 + 0x15);
            }
            unaff_r19 = (int)*(short *)(param3 + 0x14);
          }
          else if (uVar12 == 0) {
            if (true) {
              DAT_80398f28 = 0;
              if ((*(short *)(param3 + 0x14) <= iVar2) && (DAT_80399a76 == '\0')) {
                uVar12 = 1;
              }
              if (iVar2 < *(short *)(param3 + 0x14)) {
                FUN_80068a9c((uint)param1,0x7f);
              }
              *(short *)(param3 + 0x14) = (short)iVar2;
              unaff_r19 = DAT_803999b4;
              *(undefined *)(param3 + 0x1d) = 0;
            }
          }
          else if (uVar12 < 3) {
            *(short *)(param3 + 0x14) = *(short *)(param3 + 0x14) - (short)param2;
            if (*(short *)(param3 + 0x14) < 0) {
              *(undefined2 *)(param3 + 0x14) = 0;
              *(undefined2 *)((int)param3 + 0x5e) = 0;
              *(undefined2 *)(param3 + 0x18) = 0;
            }
            *(undefined *)(param3 + 0x1d) = 0;
            unaff_r19 = (int)*(short *)(param3 + 0x14);
          }
          if (param1 == DAT_80398f40) {
            DAT_803999b4 = unaff_r19;
          }
          iVar2 = (int)*(short *)(param3 + 0x14);
          FUN_800ca7e4((short *)param1,(int)local_d8[0],(int)param3,iVar2);
          if ((DAT_803999b4 != *(short *)((int)param3 + 0x52)) ||
             (*(short *)(param3 + 0x14) != *(short *)((int)param3 + 0x52))) {
            DAT_80398f6c = 0.0;
            DAT_80398f70 = 0.0;
            DAT_80398f74 = 0.0;
            DAT_80398f78 = 0.0;
            DAT_80398f7c = 0.0;
          }
          if (((DAT_80399a74 == '\0') || ((ObjInstance *)camPosOverride != param1)) ||
             ((DAT_80399a75 == '\0' && (iVar3 = func0F(), iVar3 == 0)))) {
            if ((ObjInstance *)camPosOverride == param1) {
              DAT_80398f6c = 0.0;
              DAT_80398f70 = 0.0;
              DAT_80398f74 = 0.0;
              DAT_80398f78 = 0.0;
              DAT_80398f7c = 0.0;
            }
          }
          else {
            pCVar4 = getCurCamera();
            sVar7 = getStickX2(0);
            sVar8 = getStickY2(0);
            NVar6 = n64GetEnabledButtonsHeld(0);
            dVar17 = 0.0;
            dVar15 = 0.0;
            uStack_a4 = param2 ^ 0x80000000;
            local_a8 = 0x43300000;
            fVar1 = (float)((double)CONCAT44(0x43300000,uStack_a4) - 4503601774854144.0);
            if (debugCamMode == 1) {
              fVar1 = 0.1;
            }
            dVar18 = (double)fVar1;
            if ((NVar6 & N64_BUTTON_C_LEFT) != 0) {
              dVar17 = -dVar18;
            }
            if ((NVar6 & N64_BUTTON_C_RIGHT) != 0) {
              dVar17 = dVar18;
            }
            dVar16 = 0.0;
            if ((NVar6 & N64_BUTTON_A) != 0) {
              dVar16 = dVar18;
            }
            if ((NVar6 & N64_BUTTON_B) != 0) {
              dVar16 = -dVar18;
            }
            if ((NVar6 & N64_BUTTON_C_DOWN) != 0) {
              dVar15 = -dVar18;
            }
            if ((NVar6 & N64_BUTTON_C_UP) != 0) {
              dVar15 = dVar18;
            }
            iVar3 = func0F();
            if ((((iVar3 == 0) || (*(char *)((int)param3 + 0x73) == '\0')) ||
                (*(char *)((int)param3 + 0x71) == '\0')) || (*(char *)(param3 + 0x1c) == '\0')) {
              fVar1 = 4.0;
              if (debugCamMode == 1) {
                fVar1 = 0.5;
              }
              if ((NVar6 & N64_BUTTON_DOWN) != 0) {
                DAT_80398f70 = DAT_80398f70 + fVar1;
              }
              if ((NVar6 & N64_BUTTON_UP) != 0) {
                DAT_80398f70 = DAT_80398f70 - fVar1;
              }
              if ((NVar6 & N64_BUTTON_RIGHT) != 0) {
                DAT_80398f6c = DAT_80398f6c + fVar1;
              }
              if ((NVar6 & N64_BUTTON_LEFT) != 0) {
                DAT_80398f6c = DAT_80398f6c - fVar1;
              }
              iVar3 = func0F();
              if (iVar3 == 0) {
                iVar3 = 0x8000 - (pCVar4->rot).x;
              }
              else {
                iVar3 = (int)(param1->pos).rotation.x + (int)(short)(int)(DAT_80398f6c * 182.044);
              }
              uVar11 = iVar3 - *(short *)((int)param3 + 0x1a);
              local_d0 = (double)CONCAT44(0x43300000,uVar11 ^ 0x80000000);
              dVar18 = (double)mathFn_80294204((double)(((float)(local_d0 - 4503601774854144.0) *
                                                        3.141593) / 32767.0));
              uStack_c4 = uVar11 ^ 0x80000000;
              local_c8 = 0x43300000;
              dVar14 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                      uStack_c4) -
                                                                    4503601774854144.0) * 3.141593)
                                                           / 32767.0));
              in_f26 = (double)(float)(dVar17 * dVar18 + (double)(float)(dVar16 * dVar14));
              dVar18 = (double)(float)(-dVar17 * dVar14 + (double)(float)(dVar16 * dVar18));
              local_c0 = (longlong)(int)(DAT_80398f6c * 182.044);
              (param1->pos).rotation.x =
                   (param1->pos).rotation.x + (short)(int)(DAT_80398f6c * 182.044);
              local_b8 = (longlong)(int)(DAT_80398f70 * 182.044);
              (param1->pos).rotation.y =
                   (param1->pos).rotation.y + (short)(int)(DAT_80398f70 * 182.044);
              dVar17 = in_f26;
            }
            else {
              uStack_a4 = (int)sVar7 ^ 0x80000000;
              local_a8 = 0x43300000;
              DAT_80398f6c = DAT_80398f6c -
                             (float)((double)CONCAT44(0x43300000,uStack_a4) - 4503601774854144.0) /
                             30.0;
              uStack_ac = (int)sVar8 ^ 0x80000000;
              local_b0 = 0x43300000;
              DAT_80398f70 = DAT_80398f70 -
                             (float)((double)CONCAT44(0x43300000,uStack_ac) - 4503601774854144.0) /
                             30.0;
              local_b8 = (longlong)(int)(DAT_80398f6c * 182.044);
              (param1->pos).rotation.x =
                   (param1->pos).rotation.x + (short)(int)(DAT_80398f6c * 182.044);
              local_c0 = (longlong)(int)(DAT_80398f70 * 182.044);
              (param1->pos).rotation.y =
                   (param1->pos).rotation.y + (short)(int)(DAT_80398f70 * 182.044);
              uStack_c4 = (int)(param1->pos).rotation.x ^ 0x80000000;
              local_c8 = 0x43300000;
              dVar18 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                                  uStack_c4) -
                                                                4503601774854144.0) * 3.141593) /
                                                       32767.0));
              local_d0 = (double)CONCAT44(0x43300000,(int)(param1->pos).rotation.x ^ 0x80000000);
              dVar14 = (double)distanceFn_80293e80((double)(((float)(local_d0 - 4503601774854144.0)
                                                            * 3.141593) / 32767.0));
              in_f26 = (double)(float)(dVar17 * dVar18 + (double)(float)(dVar16 * dVar14));
              dVar18 = (double)(float)(-dVar17 * dVar14 + (double)(float)(dVar16 * dVar18));
              dVar17 = in_f26;
              uVar5 = getEnabledButtonsPressed(0);
              if ((uVar5 & 0x40) != 0) {
                if (debugCamMode == 0) {
                  debugCamMode = 1;
                }
                else {
                  debugCamMode = 0;
                }
              }
              dprintSetPos(0x1e,0x1e);
              if (debugCamMode == 0) {
                diPrintf("CAMERA CONTROL (Fast)");
              }
              else {
                diPrintf("CAMERA CONTROL (Slow)");
              }
            }
            DAT_80398f74 = (float)((double)DAT_80398f74 + dVar17);
            DAT_80398f78 = (float)((double)DAT_80398f78 + dVar15);
            DAT_80398f7c = (float)((double)DAT_80398f7c + dVar18);
            uVar5 = getEnabledButtonsPressed(0);
            if ((uVar5 & 0x20) != 0) {
              local_d0 = (double)CONCAT44(0x43300000,(int)(param1->pos).rotation.y ^ 0x80000000);
              uStack_c4 = (int)(param1->pos).rotation.x ^ 0x80000000;
              local_c8 = 0x43300000;
              dVar15 = FUN_800ced4c((int)param3,0xd,iVar2);
              DAT_80398f74 = (float)((double)DAT_80398f74 + dVar15);
              dVar15 = FUN_800ced4c((int)param3,0xc,iVar2);
              DAT_80398f78 = (float)((double)DAT_80398f78 + dVar15);
              FUN_800ced4c((int)param3,0xb,iVar2);
              DAT_80398f6c = 0.0;
              DAT_80398f70 = 0.0;
              DAT_80398f74 = 0.0;
              DAT_80398f78 = 0.0;
              DAT_80398f7c = 0.0;
            }
            (param1->pos).pos.x = (param1->pos).pos.x + DAT_80398f74;
            (param1->pos).pos.y = (param1->pos).pos.y + DAT_80398f78;
            (param1->pos).pos.z = (param1->pos).pos.z + DAT_80398f7c;
          }
          (param1->pos).pos.x = (param1->pos).pos.x + (float)param3[1];
          (param1->pos).pos.y = (param1->pos).pos.y + (float)param3[2];
          (param1->pos).pos.z = (param1->pos).pos.z + (float)param3[3];
          (param1->pos).rotation.z = (param1->pos).rotation.z + *(short *)(param3 + 6);
          (param1->pos).rotation.y = (param1->pos).rotation.y + *(short *)((int)param3 + 0x16);
          (param1->pos).rotation.x = (param1->pos).rotation.x + *(short *)(param3 + 5);
          local_dc = (Model *)local_d8[0]->modelInstances->mtxs[(char)local_d8[0]->curModel + -3];
          DAT_80398f5c = 0;
          if (uVar12 == 1) {
            if (local_dc != (Model *)0x0) {
              dVar15 = FUN_800ced4c((int)param3,0xd,(int)*(short *)((int)param3 + 0x52));
              in_f26 = (double)(float)((double)(pOVar13->pos).x + dVar15);
              dVar15 = FUN_800ced4c((int)param3,0xb,(int)*(short *)((int)param3 + 0x52));
              in_f21 = (double)(float)((double)(pOVar13->pos).z + dVar15);
            }
            *(undefined2 *)(param3 + 0x14) = *(undefined2 *)((int)param3 + 0x52);
            while (*(short *)(param3 + 0x14) < iVar2) {
              *(short *)(param3 + 0x14) = *(short *)(param3 + 0x14) + 1;
              dVar15 = FUN_800ced4c((int)param3,0xd,(int)*(short *)(param3 + 0x14));
              dVar17 = (double)(float)((double)(pOVar13->pos).x + dVar15);
              dVar15 = FUN_800ced4c((int)param3,0xb,(int)*(short *)(param3 + 0x14));
              dVar15 = (double)(float)((double)(pOVar13->pos).z + dVar15);
              if ((0 < *(short *)(param3 + 0x14)) && ((*(ushort *)((int)param3 + 0x66) & 4) != 0)) {
                if ((*(char *)(param3 + 0x1c) == '\x01') &&
                   ((*(char *)((int)param3 + 0x73) == '\0' && (local_dc != (Model *)0x0)))) {
                  dVar18 = sqrt((double)((float)(dVar17 - in_f26) * (float)(dVar17 - in_f26) +
                                        (float)(dVar15 - in_f21) * (float)(dVar15 - in_f21)));
                  iVar3 = objGetAnimChange(dVar18,(int)local_d8[0],&local_e4);
                  if (iVar3 == 0) {
                    dVar18 = FUN_800ced4c((int)param3,9,*(short *)(param3 + 0x14) + -1);
                    local_e4 = (float)(dVar18 * 0.0003999999898951501);
                  }
                }
                else {
                  dVar18 = FUN_800ced4c((int)param3,9,*(short *)(param3 + 0x14) + -1);
                  local_e4 = (float)(dVar18 * 0.0003999999898951501);
                }
                if (local_dc == (Model *)0x0) {
                  local_d8[0]->animTimer = local_d8[0]->animTimer + local_e4;
                  while (1.0 < local_d8[0]->animTimer) {
                    local_d8[0]->animTimer = local_d8[0]->animTimer - 1.0;
                  }
                  while (local_d8[0]->animTimer < 0.0) {
                    local_d8[0]->animTimer = local_d8[0]->animTimer + 1.0;
                  }
                }
                else {
                  objRunAnimation((double)local_e4,1.0,(int)local_d8[0],(float *)(param3 + 0x3a));
                  bVar9 = checkSomeDebugFlags_8017c4f8();
                  if (!bVar9) {
                    objAnimFn_80087d88(local_d8[0],(int)(param3 + 0x3a));
                  }
                  bVar9 = FUN_80068b20((int)param1,0x10);
                  if ((bVar9) && ((*(ushort *)(*(int *)local_dc + 2) & 1) != 0)) {
                    nop_80092A14();
                  }
                  modelFn_80080c28(1.0,local_dc);
                  if (0.0 < (float)param3[8]) {
                    if (*(short *)((int)param3 + 0xce) == 0) {
                      dVar18 = 8.0;
                    }
                    else {
                      dVar18 = FUN_800ced4c((int)param3,10,*(short *)(param3 + 0x14) + -1);
                    }
                    if (dVar18 < 1.0) {
                      dVar18 = 1.0;
                    }
                    param3[8] = (ObjInstance *)((float)param3[8] - (float)(1.0 / dVar18));
                    if ((float)param3[8] < 0.0) {
                      param3[8] = (ObjInstance *)0.0;
                    }
                  }
                }
              }
              in_f26 = dVar17;
              in_f21 = dVar15;
              bVar9 = false;
              while ((!bVar9 && (*(short *)((int)param3 + 0x5e) < *(short *)((int)param3 + 0x5a))))
              {
                local_e0 = &(param3[0x23]->pos).rotation.x + *(short *)((int)param3 + 0x5e) * 2;
                if (*(char *)local_e0 == '\0') {
                  if (*(short *)(param3 + 0x14) < local_e0[1]) {
                    bVar9 = true;
                  }
                  else {
                    *(short *)(param3 + 0x18) = local_e0[1];
                    *(short *)((int)param3 + 0x5e) = *(short *)((int)param3 + 0x5e) + 1;
                  }
                }
                else if (*(short *)(param3 + 0x14) < *(short *)(param3 + 0x18)) {
                  bVar9 = true;
                }
                else {
                  if (*(char *)local_e0 != '\x0f') {
                    *(ushort *)(param3 + 0x18) =
                         *(short *)(param3 + 0x18) + (ushort)*(byte *)((int)local_e0 + 1);
                  }
                  *(short *)((int)param3 + 0x5e) = *(short *)((int)param3 + 0x5e) + 1;
                  iVar3 = seqFn_800cbf7c(param1,(int *)local_dc,(char **)&local_e0,0);
                  if (iVar3 != 0) {
                    iVar2 = (int)*(short *)(param3 + 0x14);
                  }
                  FUN_800ccd1c((int)param1,(int *)local_d8,&local_dc);
                }
              }
            }
          }
          else {
            FUN_800cb048(param1,local_d8[0],(short **)param3,1);
            FUN_800ccd1c((int)param1,(int *)local_d8,&local_dc);
          }
          iVar2 = 0;
          while( true ) {
            if (9 < iVar2) goto LAB_800c9fb8;
            if ((*(char *)((int)param3 + iVar2 + 0x124) != '\0') &&
               (iVar3 = FUN_800cdfb8(param1,(uint)*(byte *)((int)param3 + iVar2 + 0x124),(int)param3
                                    ), iVar3 != 0)) break;
            iVar2 = iVar2 + 1;
          }
          (&DAT_80382e00)[*(char *)((int)param3 + 0x4f)] = 1;
          *(undefined2 *)(param3 + 0x14) = *(undefined2 *)((int)param3 + iVar2 * 2 + 0x110);
          *(undefined2 *)((int)param3 + 0x52) = *(undefined2 *)(param3 + 0x14);
          for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
            *(undefined *)((int)param3 + iVar2 + 0x124) = 0;
          }
LAB_800c9fb8:
          if ((DAT_80398f3e == '\0') && (local_d8[0] != param1)) {
            objCallSeqFn(local_d8[0],param1,param3);
          }
          if (*(char *)((int)param3 + 0x89) != '\0') {
            bVar9 = FUN_800cbd1c(param1,local_d8[0],(int)param3);
            (&DAT_80382e00)[*(char *)((int)param3 + 0x4f)] = bVar9;
          }
          *(undefined *)(param3 + 0x21) = 0;
          *(undefined *)((int)param3 + 0x79) = 0;
          if ((local_dc != (Model *)0x0) && ((*(ushort *)((int)param3 + 0x66) & 4) != 0)) {
            local_d0 = (double)(longlong)(int)((float)param3[8] * 16384.0);
            local_dc->normals[0xe].z = (short)(int)((float)param3[8] * 16384.0);
          }
          objAnimFn_800849e8((int)param1,(int)param3);
          if (*(char *)((int)param3 + 0x72) == '\x01') {
            FUN_800ccee0((int)param1,(int)pOVar13);
          }
          (param1->pos).rotation.x = (param1->pos).rotation.x + *(short *)((int)param3 + 0x1a);
          objAnimFn_8008718c(param1,local_d8[0],(int)param3);
          FUN_800cc69c((int)param3,(int)local_d8[0],'\0');
                    /* {@symbol 800e77b4} */
          (**(code **)(*(int *)pDll_0E + 0xc))
                    ((int)*(short *)(param3 + 0x14) - (int)*(short *)((int)param3 + 0x52),
                     local_d8[0]);
          for (iVar2 = 0; iVar2 < DAT_80398f5c; iVar2 = iVar2 + 1) {
            iVar3 = decisionFn_800ce264(param1,local_d8[0],(int)param3,(&DAT_803833a0)[iVar2 * 2],
                                        (&DAT_803833a6)[iVar2 * 4],(&DAT_803833a4)[iVar2 * 4],'\0',
                                        '\0');
            if (iVar3 != 0) {
              iVar2 = DAT_80398f5c;
            }
            FUN_800ccd1c((int)param1,(int *)local_d8,&local_dc);
          }
          *(undefined2 *)((int)param3 + 0x52) = *(undefined2 *)(param3 + 0x14);
          if (DAT_80398f34 == '\0') {
            if ((&DAT_80382e00)[*(char *)((int)param3 + 0x4f)] != '\0') {
              *(undefined2 *)(&DAT_803830b4 + *(char *)((int)param3 + 0x4f) * 2) =
                   *(undefined2 *)(param3 + 0x14);
              (&DAT_80383280)[*(char *)((int)param3 + 0x4f)] = 2;
              (&DAT_80383058)[*(char *)((int)param3 + 0x4f)] = *(undefined2 *)(param3 + 0x14);
            }
            if ((&DAT_80383058)[*(char *)((int)param3 + 0x4f)] == -1) {
              (&DAT_80383058)[*(char *)((int)param3 + 0x4f)] =
                   (short)param2 + (&DAT_80382ffc)[*(char *)((int)param3 + 0x4f)];
            }
          }
          else {
            FUN_800ccd1c((int)param1,(int *)local_d8,&local_dc);
            FUN_800cf11c((uint)param1,(int)local_d8[0],(int *)param3);
          }
          if (((DAT_80398f34 != '\0') || (*(short *)(param3 + 0x15) <= *(short *)(param3 + 0x14)))
             || (bVar9 = iVar10 == 0, iVar10 = iVar10 + -1, bVar9)) {
            dummiedProfFn_8017a59c(0);
            goto LAB_800ca264;
          }
        }
        iVar10 = isModelAnimDisabled();
        if (iVar10 == 0) {
          param1->newOpacity = 0;
        }
      }
    }
  }
LAB_800ca264:
  _restfpr_20();
  return;
}


void FUN_800ca280(ObjInstance *param_1,undefined4 param_2,ObjInstance **param_3) { //800CA280
  int iVar1;
  Mtx44 *param2;
  ObjInstance *param2_00;
  int iVar2;
  short *local_20 [2];
  
  param2 = param_1->modelInstances->mtxs[(char)param_1->curModel + -3];
  param2_00 = param_1;
  if (*param_3 != (ObjInstance *)0x0) {
    param2_00 = *param_3;
    param2_00->pObj_0xc0 = param_1;
    param2_00->flags_0xb0 = param2_00->flags_0xb0 | SeqActive;
  }
  FUN_80068a9c((uint)param_1,0x7f);
  if (param_3[0x23] != (ObjInstance *)0x0) {
    *(undefined2 *)(param_3 + 0x19) = 0xffff;
    DAT_80398f10 = '\0';
    DAT_80398f5c = 0;
    while( true ) {
      if (*(short *)((int)param_3 + 0x5a) <= *(short *)((int)param_3 + 0x5e)) break;
      local_20[0] = &(param_3[0x23]->pos).rotation.x + *(short *)((int)param_3 + 0x5e) * 2;
      if (*(char *)local_20[0] == '\0') {
        *(short *)(param_3 + 0x18) = local_20[0][1];
      }
      else if ((*(char *)local_20[0] == '\v') && (0 < local_20[0][1])) {
        *(ushort *)(param_3 + 0x18) =
             *(short *)(param_3 + 0x18) + (ushort)*(byte *)((int)local_20[0] + 1);
        seqFn_800cbf7c(param_1,(int *)param2,(char **)local_20,0);
      }
      else {
        if (*(char *)local_20[0] != '\x0f') {
          *(ushort *)(param_3 + 0x18) =
               *(short *)(param_3 + 0x18) + (ushort)*(byte *)((int)local_20[0] + 1);
        }
        if ((*(char *)local_20[0] == '\r') && (((uint)(int)local_20[0][1] >> 0xc & 0xf) == 6)) {
          DAT_80398f24 = local_20[0][1] & 0xfff;
        }
        if (*(char *)local_20[0] == '\x02') {
          *(ushort *)(param_3 + 0x19) = local_20[0][1] & 0xfff;
        }
        else {
          seqFn_800cbf7c(param_1,(int *)param2,(char **)local_20,8);
        }
      }
      *(short *)((int)param_3 + 0x5e) = *(short *)((int)param_3 + 0x5e) + 1;
      if (0x13 < DAT_80398f5c) {
        for (iVar2 = 0; iVar2 < DAT_80398f5c; iVar2 = iVar2 + 1) {
          iVar1 = decisionFn_800ce264(param_1,param2_00,(int)param_3,(&DAT_803833a0)[iVar2 * 2],
                                      (&DAT_803833a6)[iVar2 * 4],(&DAT_803833a4)[iVar2 * 4],'\0',
                                      '\x01');
          if (iVar1 != 0) {
            iVar2 = DAT_80398f5c;
          }
        }
        DAT_80398f5c = 0;
      }
      if ('\t' < DAT_80398f10) {
        FUN_800cc69c((int)param_3,(int)param2_00,'\x01');
        DAT_80398f10 = '\0';
      }
      if ((9 < *(byte *)(param_3 + 0x21)) && (param2_00 != param_1)) {
        objCallSeqFn(param2_00,param_1,param_3);
      }
    }
    iVar2 = 0;
    while( true ) {
      if (DAT_80398f5c <= iVar2) break;
      iVar1 = decisionFn_800ce264(param_1,param2_00,(int)param_3,(&DAT_803833a0)[iVar2 * 2],
                                  (&DAT_803833a6)[iVar2 * 4],(&DAT_803833a4)[iVar2 * 4],'\0','\x01')
      ;
      if (iVar1 != 0) {
        iVar2 = DAT_80398f5c;
      }
      iVar2 = iVar2 + 1;
    }
    DAT_80398f5c = 0;
    if (DAT_80398f10 != '\0') {
      FUN_800cc69c((int)param_3,(int)param2_00,'\x01');
      DAT_80398f10 = '\0';
    }
    if ((param2 != (Mtx44 *)0x0) && (*(short *)(param_3 + 0x19) != -1)) {
      Object_ObjAnimSetMove(0.0,param2_00,(int)*(short *)(param_3 + 0x19),0);
      *(undefined2 *)((int)param2->m32 + 0x58) = 0;
    }
  }
  *(short *)(param_3 + 0x14) = *(short *)(param_3 + 0x15) + -1;
  return;
}


void FUN_800ca7e4(short *param_1,int param_2,int param_3,int param_4) { //800CA7E4
  bool bVar7;
  ObjInstance *pOVar1;
  short *psVar2;
  undefined2 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  short sVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double local_a0;
  double local_78;
  
  _savefpr_24();
  iVar9 = *(int *)(param_1 + 0x26);
  *(undefined4 *)(param_1 + 6) = *(undefined4 *)(iVar9 + 8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar9 + 0xc);
  *(undefined4 *)(param_1 + 10) = *(undefined4 *)(iVar9 + 0x10);
  param_1[1] = 0;
  *param_1 = 0;
  param_1[2] = 0;
  if ((*(ushort *)(param_3 + 0x66) & 0x20) != 0) {
    *(undefined *)(param_2 + 0x36) = 0xff;
  }
  FLOAT_80398f50 = 0.0;
  FLOAT_80398f54 = 0.0;
  FLOAT_80398f58 = 0.0;
  if (*(int *)(param_3 + 0x90) == 0) {
    FLOAT_80398efc = 0.0;
    FLOAT_80398f00 = 0.0;
    FLOAT_80398f04 = 0.0;
    DAT_80398f08 = 0;
    DAT_80398f0a = 1;
  }
  else {
    dVar10 = FUN_800ced4c(param_3,0x12,param_4);
    if (0 < (int)dVar10) {
      bVar7 = FUN_80068b20(param_2,3);
      if (bVar7) {
        FUN_800689dc(127.0,param_2,3,(byte)(int)dVar10);
      }
    }
    if ((*(byte *)(param_3 + 0x78) & 2) == 0) {
      dVar10 = FUN_800ced4c(param_3,7,param_4);
      *param_1 = (short)(int)(dVar10 * 182.0440063476562);
      dVar10 = FUN_800ced4c(param_3,8,param_4);
      param_1[1] = (short)(int)(dVar10 * 182.0440063476562);
      dVar10 = FUN_800ced4c(param_3,6,param_4);
      param_1[2] = (short)(int)(dVar10 * 182.0440063476562);
      dVar10 = FUN_800ced4c(param_3,0xd,param_4);
      FLOAT_80398f50 = (float)dVar10;
      dVar10 = FUN_800ced4c(param_3,0xc,param_4);
      FLOAT_80398f54 = (float)dVar10;
      dVar10 = FUN_800ced4c(param_3,0xb,param_4);
      FLOAT_80398f04 = (float)dVar10;
      FLOAT_80398efc = FLOAT_80398f50;
      FLOAT_80398f00 = FLOAT_80398f54;
      DAT_80398f08 = *param_1;
      DAT_80398f0a = 1;
      FLOAT_80398f58 = FLOAT_80398f04;
      *(float *)(param_1 + 6) = *(float *)(iVar9 + 8) + FLOAT_80398f50;
      *(float *)(param_1 + 8) = *(float *)(iVar9 + 0xc) + FLOAT_80398f54;
      *(float *)(param_1 + 10) = *(float *)(iVar9 + 0x10) + FLOAT_80398f58;
    }
    else {
      dVar10 = FUN_800ced4c(param_3,0xc,param_4);
      FLOAT_80398f54 = (float)dVar10;
      dVar10 = FUN_800ced4c(param_3,0xb,param_4);
      FLOAT_80398f58 = (float)dVar10;
      dVar10 = FUN_800ced4c(param_3,7,param_4);
      *param_1 = (short)(int)(dVar10 * 182.0440063476562);
      dVar10 = FUN_800ced4c(param_3,8,param_4);
      param_1[1] = (short)(int)(dVar10 * 182.0440063476562);
      local_78 = (double)CONCAT44(0x43300000,(int)*param_1 - 0x4000U ^ 0x80000000);
      dVar10 = (double)distanceFn_80293e80((double)(((float)(local_78 - 4503601774854144.0) *
                                                    3.141593) / 32767.0));
      dVar11 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                          (int)*param_1 - 0x4000U ^
                                                                          0x80000000) -
                                                        4503601774854144.0) * 3.141593) / 32767.0));
      dVar12 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                          (int)param_1[1] ^
                                                                          0x80000000) -
                                                        4503601774854144.0) * 3.141593) / 32767.0));
      local_a0 = (double)CONCAT44(0x43300000,(int)param_1[1] ^ 0x80000000);
      dVar13 = (double)distanceFn_80293e80((double)(((float)(local_a0 - 4503601774854144.0) *
                                                    3.141593) / 32767.0));
      dVar13 = (double)(float)((double)FLOAT_80398f58 * dVar13);
      dVar11 = (double)(float)((double)(float)((double)FLOAT_80398f58 * dVar12) * dVar11);
      dVar10 = (double)(float)((double)(float)((double)FLOAT_80398f58 * dVar12) * dVar10);
      pOVar1 = Object_objGetMain();
      *(float *)(param_1 + 6) = (float)((double)(pOVar1->pos).pos.x + dVar11);
      *(float *)(param_1 + 8) = (float)(dVar13 + (double)((pOVar1->pos).pos.y + FLOAT_80398f54));
      *(float *)(param_1 + 10) = (float)((double)(pOVar1->pos).pos.z + dVar10);
      *param_1 = -0x8000 - *param_1;
      param_1[1] = -param_1[1];
      FLOAT_80398efc = *(float *)(param_1 + 6) - *(float *)(iVar9 + 8);
      FLOAT_80398f00 = *(float *)(param_1 + 8) - *(float *)(iVar9 + 0xc);
      FLOAT_80398f04 = *(float *)(param_1 + 10) - *(float *)(iVar9 + 0x10);
      DAT_80398f08 = *param_1;
      DAT_80398f0a = 1;
    }
    if (*(short *)(param_3 + 0xd6) != 0) {
      dVar10 = FUN_800ced4c(param_3,0xe,param_4);
      if (*(char *)(param_3 + 0x73) == '\0') {
        *(float *)(param_3 + 0x10) = (float)dVar10;
      }
      else {
        if (dVar10 < 35.0) {
          dVar10 = 35.0;
        }
        if (120.0 < dVar10) {
          dVar10 = 125.0;
        }
        DAT_80398f4c = 1;
        DAT_80398f48 = (float)dVar10;
      }
    }
    if (((*(ushort *)(param_3 + 0x66) & 0x20) != 0) && (*(short *)(param_3 + 0xc0) != 0)) {
      dVar10 = FUN_800ced4c(param_3,3,param_4);
      if (dVar10 < 0.0) {
        dVar10 = 0.0;
      }
      if (255.0 < dVar10) {
        dVar10 = 255.0;
      }
      *(char *)(param_2 + 0x36) = (char)(int)dVar10;
    }
    if (*(short *)(param_3 + 0xc2) != 0) {
      dVar10 = FUN_800ced4c(param_3,4,param_4);
                    /* {@symbol 800d26a8} */
      (**(code **)(*(int *)pDll_newfog + 0x28))((double)(float)(dVar10 * 60.0));
    }
    if ((*(ushort *)(param_3 + 0x66) & 0x10) != 0) {
      if (*(short *)(param_3 + 0xc4) != 0) {
        dVar10 = FUN_800ced4c(param_3,5,param_4);
        *(float *)(param_2 + 8) = (float)(dVar10 * (double)*(float *)(*(int *)(param_2 + 0x50) + 4))
        ;
      }
    }
    if ((*(ushort *)(param_3 + 0x66) & 8) != 0) {
      psVar2 = (short *)objGetJoint(param_2,0);
      if (psVar2 != (short *)0x0) {
        if (*(short *)(param_3 + 0xbc) == 0) {
          dVar10 = 0.0;
        }
        else {
          dVar10 = FUN_800ced4c(param_3,1,param_4);
        }
        *psVar2 = *(short *)(param_3 + 0x10e) + (short)(int)(dVar10 * 182.0440063476562);
        if (*(short *)(param_3 + 0xbe) == 0) {
          dVar10 = 0.0;
        }
        else {
          dVar10 = FUN_800ced4c(param_3,2,param_4);
        }
        psVar2[1] = *(short *)(param_3 + 0x10c) + (short)(int)(dVar10 * 182.0440063476562);
        if (*(short *)(param_3 + 0xba) == 0) {
          dVar10 = 0.0;
        }
        else {
          dVar10 = FUN_800ced4c(param_3,0,param_4);
        }
        psVar2[2] = (short)(int)(dVar10 * 182.0440063476562);
        if ((*(ushort *)(param_3 + 0x66) & 0x400) != 0) {
          FUN_800d16b0(param_2,psVar2,(uint)(*(byte *)(param_3 + 0x12e) >> 4));
        }
      }
    }
    if ((*(ushort *)(param_3 + 0x66) & 0x200) != 0) {
      puVar3 = (undefined2 *)objGetJoint(param_2,1);
      if (puVar3 != (undefined2 *)0x0) {
        if (*(short *)(param_3 + 0xdc) == 0) {
          dVar10 = 0.0;
        }
        else {
          dVar10 = FUN_800ced4c(param_3,0x11,param_4);
        }
        *puVar3 = (short)(int)(dVar10 * 182.0440063476562);
      }
    }
    if ((*(ushort *)(param_3 + 0x66) & 0x40) != 0) {
      iVar9 = FUN_80094400(param_2,1);
      iVar4 = FUN_80094400(param_2,0);
      if ((iVar9 != 0) || (iVar4 != 0)) {
        if (*(short *)(param_3 + 0xd8) == 0) {
          dVar10 = 0.0;
        }
        else {
          dVar10 = FUN_800ced4c(param_3,0xf,param_4);
        }
        sVar8 = (short)(int)(dVar10 * 10.0);
        if (iVar9 != 0) {
          *(short *)(iVar9 + 8) = sVar8;
        }
        if (iVar4 != 0) {
          *(short *)(iVar4 + 8) = -sVar8;
        }
        if (*(short *)(param_3 + 0xda) == 0) {
          dVar10 = 0.0;
        }
        else {
          dVar10 = FUN_800ced4c(param_3,0x10,param_4);
        }
        sVar8 = -(short)(int)(dVar10 * 10.0);
        if (iVar9 != 0) {
          *(short *)(iVar9 + 10) = sVar8;
        }
        if (iVar4 != 0) {
          *(short *)(iVar4 + 10) = sVar8;
        }
      }
      piVar5 = (int *)FUN_80094400(param_2,5);
      piVar6 = (int *)FUN_80094400(param_2,4);
      if (piVar5 != (int *)0x0) {
        *piVar5 = (int)(short)(ushort)*(byte *)(param_3 + 0x86) << 8;
      }
      if (piVar6 != (int *)0x0) {
        *piVar6 = (int)(short)(ushort)*(byte *)(param_3 + 0x87) << 8;
      }
    }
  }
  _restfpr_24();
  return;
}


int FUN_800cbee0(uint param_1,int param_2) { //800CBEE0
  bool bVar1;
  int iVar2;
  
  bVar1 = FUN_80068b20(param_1,*(byte *)(param_2 + 0x76));
  if (bVar1) {
    iVar2 = 3;
    do {
      bVar1 = iVar2 == 0;
      iVar2 = iVar2 + -1;
      if (bVar1) {
        FUN_80068a9c(param_1,3);
        return 3;
      }
      bVar1 = FUN_80068b20(param_1,(byte)iVar2);
    } while (bVar1);
    *(byte *)(param_2 + 0x76) = (byte)iVar2;
  }
  else {
    iVar2 = (int)*(char *)(param_2 + 0x76);
  }
  return iVar2;
}


/* Library Function - Single Match
    seqFn_800cbf7c
   
   Library: KioskDefault 0 0 */

void seqFn_800cbf7c(ObjInstance *param1,int *param2,char **param3,uint param4) { //800CBF7C
  float fVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  ObjInstance *this;
  int iVar5;
  byte bVar6;
  ObjInstance **ppOVar7;
  char *pcVar8;
  double dVar9;
  
  _savefpr_30();
  pcVar8 = *param3;
  bVar6 = (byte)param4 & 2;
  if ((param4 & 1) == 0) {
    bVar6 = 1;
  }
  ppOVar7 = (ObjInstance **)param1->state;
  this = *ppOVar7;
  if (*ppOVar7 == (ObjInstance *)0x0) {
    this = param1;
  }
  if (true) {
                    /* {@symbol 800cc424} */
    switch(*pcVar8) {
    case '\x01':
      if ((param4 & 8) == 0) {
        if ((*(char *)((int)ppOVar7 + 0x73) == '\0') ||
           ((&DAT_80382f9c)[*(char *)((int)ppOVar7 + 0x4f)] == '\0')) {
          *(char *)(ppOVar7 + 0x1c) = '\x01' - *(char *)(ppOVar7 + 0x1c);
        }
        else {
          *(undefined *)(ppOVar7 + 0x1c) = 0;
        }
      }
      break;
    case '\x02':
      if ((param4 & 8) == 0) {
        *(ushort *)(ppOVar7 + 0x19) = *(ushort *)(pcVar8 + 2) & 0xfff;
        *(byte *)((int)ppOVar7 + 0x85) = (byte)((ushort)*(undefined2 *)(pcVar8 + 2) >> 8) & 0xf0;
        if (param2 != (int *)0x0) {
          iVar5 = param2[9];
          if (this->animId == *(word *)(ppOVar7 + 0x19)) {
            if (*(char *)(iVar5 + 0x60) == '\0') {
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
          }
          else {
            bVar3 = true;
          }
          if (((bVar6 != 0) && (bVar3)) && (param2 != (int *)0x0)) {
            *(float *)(iVar5 + 4) = this->animTimer * *(float *)(iVar5 + 0x14);
            if (*(short *)((int)ppOVar7 + 0xce) == 0) {
              dVar9 = 8.0;
            }
            else {
              dVar9 = FUN_800ced4c((int)ppOVar7,10,*(short *)(ppOVar7 + 0x14) + -1);
            }
            Object_ObjAnimSetMove
                      ((double)((float)((double)CONCAT44(0x43300000,
                                                         (uint)*(byte *)((int)ppOVar7 + 0x85)) -
                                       4503599627370496.0) * 0.00390625),this,
                       (int)*(short *)(ppOVar7 + 0x19),dVar9 < 1.0);
            ppOVar7[8] = (ObjInstance *)1.0;
          }
        }
      }
      break;
    case '\x03':
      if (((param4 & 8) == 0) && ((param4 & 4) == 0)) {
        this = (ObjInstance *)FUN_800cbb14((short *)param1,(short **)ppOVar7,(int)param1->def);
        this->animVal_a2 = -1;
      }
      break;
    case '\x04':
      if (((((param4 & 8) == 0) && (bVar6 != 0)) && (param2 != (int *)0x0)) &&
         (*(char *)(*param2 + 0xbb) != '\0')) {
        fVar1 = (float)((double)CONCAT44(0x43300000,
                                         (uint)(int)*(short *)(pcVar8 + 2) >> 8 & 0xff ^ 0x80000000)
                       - 4503601774854144.0);
        if (fVar1 == 0.0) {
          fVar1 = 1.0;
        }
        else {
          fVar1 = 1.0 / fVar1;
        }
        if (((*(ushort *)(*param2 + 2) & 1) == 0) || (0xe < (*(ushort *)(pcVar8 + 2) & 0xff))) {
          vtxAnimFn_800279cc((double)fVar1,param2,0,(int)*(char *)(param2[8] + 0xd),
                             ((int)*(short *)(pcVar8 + 2) & 0xffU) - 1,0);
        }
        else {
          vtxAnimFn_800279cc((double)fVar1,param2,2,(int)*(char *)(param2[8] + 0x2d),
                             ((int)*(short *)(pcVar8 + 2) & 0xffU) - 1,0);
        }
      }
      break;
    case '\a':
      *(char *)((int)ppOVar7 + 0x72) = '\x01' - *(char *)((int)ppOVar7 + 0x72);
      break;
    case '\v':
      if (0x13 < DAT_80398f5c) {
        printf("CODE OVERFLOW");
      }
      if (((bVar6 != 0) && (0 < *(short *)(pcVar8 + 2))) && (DAT_80398f5c < 0x14)) {
        (&DAT_803833a0)[DAT_80398f5c * 2] = pcVar8 + 4;
        (&DAT_803833a6)[DAT_80398f5c * 4] = *(undefined2 *)(ppOVar7 + 0x14);
        iVar5 = DAT_80398f5c * 4;
        DAT_80398f5c = DAT_80398f5c + 1;
        (&DAT_803833a4)[iVar5] = *(undefined2 *)(pcVar8 + 2);
      }
      *(short *)((int)ppOVar7 + 0x5e) = *(short *)((int)ppOVar7 + 0x5e) + *(short *)(pcVar8 + 2);
      break;
    case '\r':
      if ((((param4 & 1) == 0) && (((uint)(int)*(short *)(pcVar8 + 2) >> 0xc & 0xf) != 8)) &&
         (DAT_80398f10 < '\n')) {
        *(ObjInstance **)(&DAT_80382e30 + DAT_80398f10 * 8) = this;
        (&DAT_80382e36)[DAT_80398f10 * 8] = (byte)((uint)(int)*(short *)(pcVar8 + 2) >> 0xc) & 0xf;
        if (((&DAT_80382e36)[DAT_80398f10 * 8] == '\v') ||
           ((&DAT_80382e36)[DAT_80398f10 * 8] == '\f')) {
          iVar5 = (int)DAT_80398f10;
          DAT_80398f10 = DAT_80398f10 + '\x01';
          *(undefined2 *)(&DAT_80382e34 + iVar5 * 8) = *(undefined2 *)(pcVar8 + 6);
        }
        else {
          iVar5 = (int)DAT_80398f10;
          DAT_80398f10 = DAT_80398f10 + '\x01';
          *(ushort *)(&DAT_80382e34 + iVar5 * 8) = *(ushort *)(pcVar8 + 2) & 0xfff;
        }
      }
      break;
    case '\x0e':
      if ((param4 & 8) == 0) {
                    /* {@symbol 8016dea4} */
        (**(code **)(*pdll_camcontrol + 0x38))((int)*(short *)(pcVar8 + 2),200,0x8c);
      }
    }
  }
  if (((param4 & 1) == 0) && ((DAT_80399a74 == '\0' || (DAT_803999b0 != 0)))) {
    if ((DAT_80398f11 == '\0') && (DAT_80398f12 == '\0')) {
      cVar2 = *pcVar8;
      if (cVar2 == '\r') {
        if (true) {
                    /* {@symbol 800cc538} */
          switch((uint)(int)*(short *)(pcVar8 + 2) >> 0xc & 0xf) {
          case 0:
            if ((param4 & 8) == 0) {
                    /* {@symbol 8011bc64} */
              (**(code **)(*(int *)pDll05_2 + 4))
                        (param1,((int)*(short *)(pcVar8 + 2) & 0xfffU) + 1,"anim.c",0x9c4,
                         s__e_>val_0xfff__1_802f4198);
            }
            break;
          case 2:
            iVar5 = isModelAnimDisabled();
            if (iVar5 == 0) {
              loadEnvfxAction(this,this,(int)*(short *)(pcVar8 + 2) & 0xfff,0);
            }
            break;
          case 6:
            if ((param4 & 8) == 0) {
              warpToMap((int)*(short *)(pcVar8 + 2) & 0xfff,false);
            }
            break;
          case 7:
            break;
          case 8:
            if ((param4 & 8) == 0) {
              *(char *)((int)ppOVar7 + 0x86) = (char)*(undefined2 *)(pcVar8 + 2);
              *(undefined *)((int)ppOVar7 + 0x87) = *(undefined *)((int)ppOVar7 + 0x86);
            }
            break;
          case 0xe:
            if ((param4 & 8) == 0) {
              *(char *)((int)ppOVar7 + 0x86) = (char)*(undefined2 *)(pcVar8 + 2);
            }
            break;
          case 0xf:
            if ((param4 & 8) == 0) {
              *(char *)((int)ppOVar7 + 0x87) = (char)*(undefined2 *)(pcVar8 + 2);
            }
          }
        }
      }
      else if ((('\f' < cVar2) && (cVar2 == '\x0f')) && ((param4 & 8) == 0)) {
        FUN_800cbee0((uint)param1,(int)ppOVar7);
        if (((uint)(int)*(short *)(pcVar8 + 2) >> 0xc & 0xf) == 0xf) {
          iVar5 = 3;
        }
        else {
          iVar5 = (int)*(char *)((int)ppOVar7 + 0x76);
          *(char *)((int)ppOVar7 + 0x76) = *(char *)((int)ppOVar7 + 0x76) + '\x01';
          if ('\x02' < *(char *)((int)ppOVar7 + 0x76)) {
            *(undefined *)((int)ppOVar7 + 0x76) = 0;
          }
        }
        pcVar8[1] = pcVar8[5];
        pcVar8[4] = 'c';
        *(undefined2 *)((int)ppOVar7 + iVar5 * 2 + 0x30) = *(undefined2 *)(pcVar8 + 6);
      }
    }
    else if (*pcVar8 == '\r') {
      uVar4 = (uint)(int)*(short *)(pcVar8 + 2) >> 0xc & 0xf;
      if (uVar4 == 6) {
        warpToMap((int)*(short *)(pcVar8 + 2) & 0xfff,false);
      }
      else if (((uVar4 < 6) && (uVar4 == 2)) && (iVar5 = isModelAnimDisabled(), iVar5 == 0)) {
        loadEnvfxAction(this,this,(int)*(short *)(pcVar8 + 2) & 0xfff,0);
      }
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    animCurveFn_800ce73c
   
   Library: KioskDefault 0 0 */

void animCurveFn_800ce73c
               (ObjInstance *param1,ObjInstance *param2,int param3,uint param4,char param5) { //800CE73C
  undefined4 uVar1;
  void *pvVar2;
  ObjInstance *pOVar3;
  int iVar4;
  uint modelNo;
  double dVar5;
  double dVar6;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  uint uStack_34;
  
  _savefpr_30();
  modelNo = param4 >> 8 & 0xff;
  if (true) {
                    /* {@symbol 800ceac0} */
    switch(param4 & 0xff) {
    case 2:
      if (param5 == '\0') {
        local_44 = 0x19;
        local_40 = 0x15;
        if (*(int *)(param3 + 0x28) < 0) {
                    /* {@symbol 80124500} */
          uVar1 = (**(code **)(*(int *)pDll_RomCurve + 0x14))
                            ((double)(param1->pos).pos.x,(double)(param1->pos).pos.y,
                             (double)(param1->pos).pos.z,&local_44,2,modelNo);
          *(undefined4 *)(param3 + 0x28) = uVar1;
          if (-1 < *(int *)(param3 + 0x28)) {
            if (*(int *)(param3 + 0x2c) != 0) {
              mm_free(*(void **)(param3 + 0x2c));
              *(undefined4 *)(param3 + 0x2c) = 0;
            }
            pvVar2 = mmAlloc(0x2c,ANIMSEQ_COL,"anim:curvedata");
            *(void **)(param3 + 0x2c) = pvVar2;
            if (*(int *)(param3 + 0x2c) == 0) {
              *(undefined4 *)(param3 + 0x28) = 0xffffffff;
            }
            else {
              curveFindFn_800843c4(*(undefined4 **)(param3 + 0x2c),*(undefined4 *)(param3 + 0x28));
            }
          }
        }
      }
      break;
    case 9:
      if (param5 == '\0') {
        *(byte *)(param3 + 0x78) = *(byte *)(param3 + 0x78) | 1;
      }
      break;
    case 0xe:
      if ((param5 == '\0') && ((&DAT_80382f9c)[*(char *)(param3 + 0x4f)] == '\0')) {
        if (modelNo < 3) {
          modelNo = 3;
        }
        DAT_80398eec = 0;
        DAT_80398ef4 = (int)*(short *)(param3 + 0x50);
        DAT_80398ef0 = modelNo;
        DAT_80398ef8 = param3;
      }
      break;
    case 0xf:
      if ((param5 == '\0') && ((&DAT_80382f9c)[*(char *)(param3 + 0x4f)] == '\0')) {
        if (modelNo < 3) {
          modelNo = 3;
        }
        DAT_80398eec = 1;
        DAT_80398ef4 = (int)*(short *)(param3 + 0x50);
        DAT_80398ef0 = modelNo;
        DAT_80398ef8 = param3;
      }
      break;
    case 0x12:
      if (param5 == '\0') {
        if (((&DAT_8038319c)[*(char *)(param3 + 0x4f)] & 0x10) == 0) {
          (&DAT_8038319c)[*(char *)(param3 + 0x4f)] =
               (&DAT_8038319c)[*(char *)(param3 + 0x4f)] | 0x10;
        }
        else {
          (&DAT_8038319c)[*(char *)(param3 + 0x4f)] =
               (&DAT_8038319c)[*(char *)(param3 + 0x4f)] & 0xef;
        }
      }
      break;
    case 0x14:
      ObjSeq_func16(0x55,param4 >> 8 & 0x7f,1,0x78);
      break;
    case 0x17:
      if ((param5 == '\0') && ((int)modelNo < (int)param2->data->nModels)) {
        if ((param2->objId == 1) && (param2->curModel == 2)) goto LAB_800ced30;
        printf(" MODEL NO %i ",(int)(char)param2->curModel);
        objSetModelNo(param2,modelNo);
      }
      break;
    case 0x18:
      if (param2->objId == 1) {
        FUN_801a7dc8((int)param2,modelNo);
      }
      break;
    case 0x19:
      if (param2->objId == 1) {
        FUN_801a7dfc((int)param2,modelNo);
      }
      break;
    case 0x1a:
      ObjSeq_func16(0x50,4,0,0);
      break;
    case 0x21:
      *(ushort *)(param3 + 0x66) = *(ushort *)(param3 + 0x66) | 0x400;
      *(byte *)(param3 + 0x12e) = (byte)(modelNo << 4) | *(byte *)(param3 + 0x12e) & 0xf;
      break;
    case 0x22:
      *(ushort *)(param3 + 0x66) = *(ushort *)(param3 + 0x66) & 0xfbff;
      *(byte *)(param3 + 0x12e) = *(byte *)(param3 + 0x12e) & 0xf;
      break;
    case 0x23:
      iVar4 = getCurMapLayer();
                    /* {@symbol 8012d5d4} */
      (**(code **)(*(int *)pDll_SaveGame + 0x1c))
                (&(param2->pos).pos,(int)(param2->pos).rotation.x,0,iVar4);
      break;
    case 0x24:
      iVar4 = getCurMapLayer();
                    /* {@symbol 8012d5d4} */
      (**(code **)(*(int *)pDll_SaveGame + 0x1c))(0,0,1,iVar4);
      break;
    case 0x26:
      pOVar3 = Object_objGetMain();
      FUN_801a7938((int)pOVar3,modelNo);
    }
  }
  iVar4 = isModelAnimDisabled();
  if ((iVar4 == 0) && (true)) {
                    /* {@symbol 800ceaf4} */
    switch(param4 & 0xff) {
    case 0:
      DAT_80398f34 = 1;
      break;
    case 7:
      if (param5 == '\0') {
        enableCameraYOffset();
        pOVar3 = Object_objGetMain();
        if (pOVar3 != (ObjInstance *)0x0) {
          dVar5 = (double)objDistObj2ObjXZ(pOVar3,param1);
          uStack_34 = modelNo - 7 ^ 0x80000000;
          local_38 = 0x43300000;
          dVar6 = (double)((float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0) *
                           2.0 + 1.0);
          if (dVar5 < 200.0) {
            if (50.0 < dVar5) {
              dVar6 = (double)(float)(dVar6 * (double)(1.0 - (float)(dVar5 - 50.0) / 150.0));
            }
            FUN_8006ae50(dVar6);
          }
        }
      }
      break;
    case 10:
      FUN_80073bd8(0x12,modelNo);
      break;
    case 0xb:
      FUN_80073bd8(0x11,modelNo);
      break;
    case 0xc:
      frontFn_80073c58();
      break;
    case 0xd:
      FUN_80068a9c((uint)param2,0x7f);
      break;
    case 0x10:
      *(char *)(param3 + 0x75) = (char)modelNo;
      break;
    case 0x13:
      if (param5 == '\0') {
        (&DAT_8038319c)[*(char *)(param3 + 0x4f)] = (&DAT_8038319c)[*(char *)(param3 + 0x4f)] & 0xef
        ;
      }
      break;
    case 0x15:
      ObjSeq_func16(0x56,modelNo & 0x7f,1,0x78);
      break;
    case 0x17:
      if ((param5 == '\0') && ((int)modelNo < (int)param2->data->nModels)) {
        objSetModelNo(param2,modelNo);
      }
      break;
    case 0x1b:
                    /* {@symbol 8012e228} */
      (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)param2->mapId,modelNo,1);
      break;
    case 0x1c:
                    /* {@symbol 8012e228} */
      (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)param2->mapId,modelNo,0);
      break;
    case 0x1d:
                    /* {@symbol 8012decc} */
      (**(code **)(*(int *)pDll_SaveGame + 0x44))((int)(char)param2->mapId,modelNo);
      break;
    case 0x1e:
      if (param5 == '\0') {
        (&DAT_8038319c)[*(char *)(param3 + 0x4f)] = (&DAT_8038319c)[*(char *)(param3 + 0x4f)] | 0x10
        ;
      }
      break;
    case 0x1f:
                    /* {@symbol 8012d8a0} */
      (**(code **)(*(int *)pDll_SaveGame + 0x2c))();
      break;
    case 0x20:
                    /* {@symbol 8012d84c} */
      (**(code **)(*(int *)pDll_SaveGame + 0x28))();
      break;
    case 0x25:
      FUN_80073dcc();
      break;
    case 0x27:
      FUN_800d1784((int)*(char *)(param3 + 0x4f));
    }
  }
LAB_800ced30:
  _restfpr_30();
  return;
}


void FUN_800cf11c(uint param_1,int param_2,int *param_3) { //800CF11C
  if (param_3[0x38] != 0) {
    (*(code *)param_3[0x38])(param_3[0x42],param_1,param_3);
  }
  FUN_80068a9c(param_1,0x7f);
  if (*(char *)((int)param_3 + 0x77) != '\0') {
    if (*(char *)((int)param_3 + 0x73) != '\0') {
      *(undefined *)((int)param_3 + 0x73) = 0;
    }
    if (*param_3 != 0) {
      *(undefined4 *)(param_2 + 0xc0) = 0;
      *(ushort *)(param_2 + 0xb0) = *(ushort *)(param_2 + 0xb0) & 0xefff;
      *param_3 = 0;
    }
    if (param_3 == DAT_80398ef8) {
      DAT_80398ef8 = (int *)0x0;
    }
  }
  *(undefined *)((int)param_3 + 0x77) = 0;
  return;
}

