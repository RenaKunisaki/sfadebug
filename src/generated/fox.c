
void foxFn_8019460c(ObjInstance *param1,int param2,int param3) { //8019460C
  uint uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined *local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  uint uStack_34;
  
  _savefpr_29();
  local_40 = 0;
  while (iVar2 = FUN_80091100((int)param1,(uint *)&local_44,&local_3c,&local_40), iVar2 != 0) {
    if (local_44 == (undefined *)0x80002) {
      if (((local_40 == 0x2d) || (local_40 == 0x958)) || (local_40 == 0x5ce)) {
                    /* {@symbol 80153978} */
        iVar2 = (**(code **)(*(int *)pDll_ObjSeq + 0x10))();
        if (iVar2 == 0x60) {
          FUN_801968a4((int *)param1,param2,local_40);
        }
        else {
          iVar2 = FUN_80198290(param1,param3);
          if (iVar2 == 0) {
            audioStartSfx((int **)0x0,0x16b,0x7f,0x40,"fox.c",0xcfe);
          }
          else if (*(int *)(param3 + 0x2c8) == 0) {
                    /* {@symbol 801539f0} */
            (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x60,1,0,0,0,0x2d,0xff);
            FUN_801968a4((int *)param1,param2,local_40);
                    /* {@symbol 8011c3c0} */
            (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,0x39);
          }
        }
      }
      else {
        FUN_801968a4((int *)param1,param2,local_40);
      }
    }
    else if ((int)local_44 < 0x80002) {
      if (local_44 == &DAT_00060005) {
        dVar5 = (double)(*(float *)(local_3c + 0xc) - (param1->pos).pos.x);
        dVar4 = (double)(*(float *)(local_3c + 0x14) - (param1->pos).pos.z);
        dVar3 = sqrt((double)(float)(dVar5 * dVar5 + (double)(float)(dVar4 * dVar4)));
        if (1.0 < dVar3) {
          dVar5 = (double)(float)(dVar5 / dVar3);
          dVar4 = (double)(float)(dVar4 / dVar3);
        }
        (param1->vel).x = (float)(-dVar5 * 2.5);
        (param1->vel).z = (float)(-dVar4 * 2.5);
        (param1->vel).y = 2.5;
        audioTryStartSfx((int *)param1,0x10,0x199,0x7f,"fox.c",0xd50);
                    /* {@symbol 8011c3c0} */
        (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,0x2e);
        Object_ObjAnimSetMove(0.0,param1,0x450,0);
        FUN_801a7a44((int)param1,-local_40);
        if (*(int *)(param2 + 0x864) != 0) {
          *(undefined4 *)(*(int *)(param2 + 0x864) + 0xf8) = 0;
          *(undefined4 *)(param2 + 0x864) = 0;
          *(undefined *)(param2 + 0x86c) = 0;
        }
      }
      else if ((int)local_44 < 0x60005) {
        if (local_44 == (undefined *)0x60003) {
          dVar5 = (double)(*(float *)(local_3c + 0xc) - (param1->pos).pos.x);
          dVar4 = (double)(*(float *)(local_3c + 0x14) - (param1->pos).pos.z);
          dVar3 = sqrt((double)(float)(dVar5 * dVar5 + (double)(float)(dVar4 * dVar4)));
          if (1.0 < dVar3) {
            dVar5 = (double)(float)(dVar5 / dVar3);
            dVar4 = (double)(float)(dVar4 / dVar3);
          }
          (param1->vel).x = (float)(dVar5 * 2.5);
          (param1->vel).z = (float)(dVar4 * 2.5);
          (param1->vel).y = 2.5;
                    /* {@symbol 8011c3c0} */
          (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,0x2e);
          FUN_801a7a44((int)param1,-local_40);
          if (*(int *)(param2 + 0x864) != 0) {
            *(undefined4 *)(*(int *)(param2 + 0x864) + 0xf8) = 0;
            *(undefined4 *)(param2 + 0x864) = 0;
            *(undefined *)(param2 + 0x86c) = 0;
          }
        }
        else if (0x60002 < (int)local_44) {
          dVar5 = (double)(*(float *)(local_3c + 0xc) - (param1->pos).pos.x);
          dVar4 = (double)(*(float *)(local_3c + 0x14) - (param1->pos).pos.z);
          dVar3 = sqrt((double)(float)(dVar5 * dVar5 + (double)(float)(dVar4 * dVar4)));
          if (1.0 < dVar3) {
            dVar5 = (double)(float)(dVar5 / dVar3);
            dVar4 = (double)(float)(dVar4 / dVar3);
          }
          (param1->vel).x = (float)(-dVar5 * 2.5);
          (param1->vel).z = (float)(-dVar4 * 2.5);
          (param1->vel).y = 2.5;
                    /* {@symbol 8011c3c0} */
          (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,0x2e);
          FUN_801a7a44((int)param1,-local_40);
          if (*(int *)(param2 + 0x864) != 0) {
            *(undefined4 *)(*(int *)(param2 + 0x864) + 0xf8) = 0;
            *(undefined4 *)(param2 + 0x864) = 0;
            *(undefined *)(param2 + 0x86c) = 0;
          }
        }
      }
      else if (local_44 == &DAT_0007000a) {
        if ((int)local_40 < 1) {
          if (*(short *)(param3 + 0x26c) != 0x27) {
                    /* {@symbol 8011c3c0} */
            (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,0x27);
          }
        }
        else {
          uVar1 = mainGetBit(local_40);
          if (uVar1 == 0) {
            mainSetBits(local_40,1);
            if (*(short *)(param3 + 0x26c) != 0x27) {
                    /* {@symbol 8011c3c0} */
              (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,0x27);
            }
          }
          else {
            objSendMsg(local_3c,0x7000b,(uint)param1,0);
            if (*(short *)(param3 + 0x26c) != 0x28) {
                    /* {@symbol 8011c3c0} */
              (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,0x28);
            }
          }
        }
        *(uint *)(param2 + 0x708) = local_3c;
        *(short *)(param2 + 0x70c) = (short)local_40;
        iVar2 = *(int *)(*(int *)(param2 + 0x708) + 100);
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x30) = 0x20000;
        }
        *(undefined *)(param2 + 0x8a5) = 1;
      }
    }
    else if (local_44 == &DAT_00100008) {
      *(undefined *)(param2 + 0x86c) = 1;
      if (*(int *)(param2 + 0x864) == 0) {
        *(uint *)(param2 + 0x864) = local_3c;
        uStack_34 = (int)local_40 >> 0x10 ^ 0x80000000;
        local_38 = 0x43300000;
        *(float *)(param2 + 0x868) =
             (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0) / 10.0;
                    /* {@symbol 8011c3c0} */
        (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,5);
        *(undefined *)(param2 + 0x8a5) = 1;
      }
    }
    else if ((int)local_44 < 0x100008) {
      if ((local_44 == (undefined *)0xe0000) && (*(uint *)(param3 + 0x2c8) == local_3c)) {
        *(undefined4 *)(param3 + 0x2c8) = 0;
        *(undefined *)(param3 + 0x33d) = 0;
                    /* {@symbol 80153f58} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x48))(0);
      }
    }
    else if ((local_44 == (undefined *)0x100010) &&
            (*(undefined *)(param2 + 0x86c) = 1, *(int *)(param2 + 0x864) == 0)) {
      *(uint *)(param2 + 0x864) = local_3c;
      uStack_34 = (int)local_40 >> 0x10 ^ 0x80000000;
      local_38 = 0x43300000;
      *(float *)(param2 + 0x868) =
           (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0);
                    /* {@symbol 8011c3c0} */
      (**(code **)(*(int *)pDll11 + 0x14))(param1,param3,5);
      *(undefined *)(param2 + 0x8a5) = 1;
    }
  }
  _restfpr_29();
  return;
}


void FUN_80194cbc(double param_1_00,ObjInstance *param_2,int param_3,int param_4) { //80194CBC
  float fVar1;
  short sVar2;
  ushort param3;
  ObjInstance *pOVar3;
  uint uVar4;
  int iVar5;
  double in_f31;
  float **local_80 [17];
  float local_3c;
  double local_38;
  double local_30;
  
  _savefpr_30();
  if ((*(byte *)(param_4 + 0x260) & 0x10) == 0) goto LAB_80195138;
  if (false) {
switchD_80194d1c_caseD_7:
    *(undefined2 *)(param_3 + 0x876) = 0x3c;
    if (*(float *)(param_3 + 0x83c) < 0.0) {
      if (0.0 <= *(float *)(param_4 + 0x278) * 0.1 + *(float *)(param_3 + 0x83c)) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = *(float *)(param_4 + 0x278) * 0.1 + *(float *)(param_3 + 0x83c);
      }
      *(float *)(param_3 + 0x83c) = fVar1;
      in_f31 = -(double)*(float *)(param_3 + 0x83c);
    }
  }
  else {
                    /* {@symbol 80194d20} */
    switch(*(undefined *)(param_4 + 0xbc)) {
    case 6:
      local_30 = (double)CONCAT44(0x43300000,(int)*(short *)(param_3 + 0x876) ^ 0x80000000);
      iVar5 = (int)((double)(float)(local_30 - 4503601774854144.0) - param_1_00);
      local_38 = (double)(longlong)iVar5;
      sVar2 = (short)iVar5;
      *(short *)(param_3 + 0x876) = sVar2;
      if (sVar2 < 1) {
        *(undefined2 *)(param_3 + 0x876) = 0x3c;
        FUN_80088818((int)param_2,0,'\x14',1,0);
      }
      break;
    default:
      goto switchD_80194d1c_caseD_7;
    case 8:
      FUN_80088818((int)param_2,0,'\x01',0,0);
      break;
    case 0x1a:
      local_38 = (double)CONCAT44(0x43300000,(int)*(short *)(param_3 + 0x876) ^ 0x80000000);
      iVar5 = (int)((double)(float)(local_38 - 4503601774854144.0) - param_1_00);
      local_30 = (double)(longlong)iVar5;
      sVar2 = (short)iVar5;
      *(short *)(param_3 + 0x876) = sVar2;
      if (sVar2 < 1) {
        *(undefined2 *)(param_3 + 0x876) = 0x3c;
        FUN_80088818((int)param_2,0,'\x14',1,0);
      }
      break;
    case 0x1c:
      uVar4 = mainGetBit(0x21);
      if (uVar4 == 0) {
        local_38 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(param_3 + 0x88a));
        iVar5 = (int)((double)(float)(local_38 - 4503599627370496.0) + param_1_00);
        local_30 = (double)(longlong)iVar5;
        *(short *)(param_3 + 0x88a) = (short)iVar5;
        if (0x78 < *(ushort *)(param_3 + 0x88a)) {
          *(short *)(param_3 + 0x88a) = *(short *)(param_3 + 0x88a) + -0x78;
          FUN_80088818((int)param_2,0,'\x16',2,0);
        }
      }
      break;
    case 0x1d:
      local_3c = 500.0;
      pOVar3 = getSeqObj(0x18,param_2,&local_3c);
      if (pOVar3 != (ObjInstance *)0x0) {
        (*(code *)pOVar3->dll->ptrs2->setScale)(0x3ff0000000000000,pOVar3,param_2);
      }
      break;
    case 0x1f:
      mainSetBits(0x643,1);
      break;
    case 0x20:
      if (*(float *)(param_4 + 0x278) <= 0.5) {
        *(float *)(param_3 + 0x83c) =
             -(float)(param_1_00 * 0.03999999910593033 - (double)*(float *)(param_3 + 0x83c));
        if (FLOAT_80399c60 <= 0.0) {
          iVar5 = randInt(0,1);
          if (iVar5 == 0) {
            param3 = 0x105;
          }
          else {
            param3 = 0x104;
          }
          audioTryStartSfx((int *)param_2,8,param3,0x7f,"fox.c",0xdf9);
          uVar4 = randInt(0x27,0x3c);
          local_38 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
          FLOAT_80399c60 = (float)(local_38 - 4503601774854144.0);
        }
        else {
          FLOAT_80399c60 = (float)((double)FLOAT_80399c60 - param_1_00);
        }
      }
      else {
        if (0.0 <= *(float *)(param_3 + 0x83c) + 0.05) {
          fVar1 = 0.0;
        }
        else {
          fVar1 = *(float *)(param_3 + 0x83c) + 0.05;
        }
        *(float *)(param_3 + 0x83c) = fVar1;
      }
      iVar5 = FUN_800b9dcc((double)(param_2->pos).pos.x,(double)(param_2->pos).pos.y,
                           (double)(param_2->pos).pos.z,(int)param_2,local_80,0,0x20);
      in_f31 = -(double)*(float *)(param_3 + 0x83c);
      if ((1 < iVar5) &&
         (in_f31 = (double)(float)(in_f31 + (double)(**local_80[0] - *local_80[0][iVar5 + -1])),
         25.0 < in_f31)) {
        FUN_801a7a44((int)param_2,-1);
        if (*(char *)(*(int *)(param_3 + 0x34c) + 1) < '\x01') {
                    /* {@symbol 8011c3c0} */
          (**(code **)(*(int *)pDll11 + 0x14))(param_2,param_4,0x32);
        }
        else {
          iVar5 = getCurMapLayer();
                    /* {@symbol 8012d5d4} */
          (**(code **)(*(int *)pDll_SaveGame + 0x1c))(0,0,1,iVar5);
                    /* {@symbol 8012d6cc} */
          (**(code **)(*(int *)pDll_SaveGame + 0x20))();
        }
      }
    }
  }
  if (in_f31 != 0.0) {
    if (0.2 <= -(float)(in_f31 * 0.05000000074505806 - 1.0)) {
      fVar1 = -(float)(in_f31 * 0.05000000074505806 - 1.0);
    }
    else {
      fVar1 = 0.2;
    }
    (param_2->vel).x = (param_2->vel).x * fVar1;
    (param_2->vel).z = (param_2->vel).z * fVar1;
  }
LAB_80195138:
  _restfpr_30();
  return;
}


void FUN_801958d0(int *param_1) { //801958D0
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uStack_2c;
  int *local_28;
  undefined4 local_24 [8];
  
  iVar4 = 3;
  puVar2 = (undefined4 *)&UNK_802cfda8;
  puVar3 = &uStack_2c;
  do {
    uVar1 = puVar2[3];
    puVar3[2] = puVar2[2];
    puVar3[3] = uVar1;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + 2;
    puVar3 = puVar3 + 2;
  } while (iVar4 != 0);
  local_28 = param_1;
                    /* {@symbol 8016dba4} */
  iVar4 = (**(code **)(*pdll_camcontrol + 0x24))(local_24,6);
  if (iVar4 != -1) {
    audioTryStartSfx(local_28,0x10,*(ushort *)((int)&PTR_DAT_8030e8c4 + iVar4 * 2),0x7f,
                     "fox.c",0xf70);
  }
  return;
}


void FUN_80195b68(ObjInstance *param_1,ObjState_Player *param_2,int param_3) { //80195B68
  int iVar1;
  ushort uVar3;
  BOOL BVar2;
  float fVar4;
  int iVar5;
  double dVar6;
  undefined2 local_64;
  undefined2 local_62;
  undefined2 local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  local_4c = 6;
  local_48 = 0x69;
  local_44 = 0x69;
  local_40 = 0xff;
  iVar1 = FUN_800883e4((int)param_1,&uStack_3c,&local_34,&local_38);
  uVar3 = objHitGetFlag1(param_1);
  if (uVar3 == 0) {
    return;
  }
  if ((param_2->ridingObject != (short *)0x0) && (iVar1 != 0)) {
    iVar1 = 0x15;
  }
  if (iVar1 == 0) {
    return;
  }
  BVar2 = krystalIsClaw(param_1);
  if (BVar2 != FALSE) {
    backpackFn_801ec694(&DAT_80399c7c);
    param_2->field2084_0x878 = 0xffff;
  }
  if (*(short *)(param_3 + 0x270) != 0) {
    iVar1 = 0x1b;
  }
  if ((*(char *)(param_3 + 0x341) == '\x03') && (*(char *)(param_3 + 0x343) <= iVar1)) {
    return;
  }
  *(char *)(param_3 + 0x343) = (char)iVar1;
  param_1->animVal_a2 = -1;
  iVar5 = -1;
  if (false) {
switchD_80195c70_caseD_0:
    iVar5 = 0x30;
  }
  else {
                    /* {@symbol 80195dbc} */
    switch(iVar1) {
    default:
      goto switchD_80195c70_caseD_0;
    case 1:
      local_38 = (uint)param_2->charState->maxHealth;
      break;
    case 2:
    case 0x12:
    case 0x14:
    case 0x17:
    case 0x1a:
      break;
    case 4:
      iVar5 = 0x2c;
      break;
    case 5:
      iVar5 = 0x2a;
      break;
    case 7:
    case 8:
    case 9:
    case 0xb:
      iVar5 = 0x30;
      break;
    case 10:
    case 0xc:
      iVar5 = 0x31;
      break;
    case 0x15:
      audioTryStartSfx((int *)param_1,0x10,0x198,0x7f,"fox.c",0x1069);
      break;
    case 0x16:
      iVar5 = 0x2b;
      break;
    case 0x18:
      iVar5 = 0x2d;
      break;
    case 0x19:
      audioTryStartSfx((int *)param_1,0x10,0x198,0x7f,"fox.c",0x1072);
      enableCameraYOffset();
      FUN_8006ae50(1.0);
      break;
    case 0x1b:
      iVar5 = (int)*(short *)(param_3 + 0x270);
      if (iVar5 == 0xc) {
        FUN_801976e4((int)param_1,param_3);
        uStack_24 = (int)(param_1->pos).rotation.x ^ 0x80000000;
        local_28 = 0x43300000;
        dVar6 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_24)
                                                             - 4503601774854144.0) * 3.141593) /
                                                    32767.0));
        (param_1->pos).pos.x = (float)(dVar6 * 10.0 + (double)(param_1->pos).pos.x);
        uStack_2c = (int)(param_1->pos).rotation.x ^ 0x80000000;
        local_30 = 0x43300000;
        dVar6 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_2c) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
        ;
        (param_1->pos).pos.z = (float)(dVar6 * 10.0 + (double)(param_1->pos).pos.z);
        objFn_8019680c(param_1,param_2);
      }
    }
  }
  if ((param_2->flags360 & 0x800) == 0) {
    if (local_38 != 0) {
      iVar1 = randInt(0x13,0x15);
      audioTryStartSfx((int *)param_1,1,*(ushort *)(param_2->field927_0x3b8 + iVar1 * 2),0x7f,
                       "fox.c",0x10b7);
      if (iVar5 != -1) {
        if (param_2->heldObject != (ObjInstance *)0x0) {
          param_2->heldObject->flags_0xf8 = 0;
          param_2->heldObject = (ObjInstance *)0x0;
          param_2->field_0x86c = 0;
        }
        param_2->field1760_0x708 = (ObjInstance *)0x0;
                    /* {@symbol 8011c3c0} */
        (**(code **)(*(int *)pDll11 + 0x14))(param_1,param_3,iVar5);
      }
    }
  }
  else {
    local_38 = 0;
    audioTryStartSfx((int *)param_1,1,0x20a,0x7f,"fox.c",0x108f);
    fVar4 = param_1->modelInstances->mtxs[(char)param_1->curModel + -3][1].m11;
    local_58 = playerMapOffsetX + *(float *)((int)fVar4 + local_34 * 0x10 + 4);
    local_54 = *(float *)((int)fVar4 + local_34 * 0x10 + 8);
    local_50 = playerMapOffsetZ + *(float *)((int)fVar4 + local_34 * 0x10 + 0xc);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(param_1,0x328,&local_64,&DAT_00200001,0xffffffff,0);
    local_58 = local_58 - (param_1->prevPos).x;
    local_54 = local_54 - (param_1->prevPos).y;
    local_50 = local_50 - (param_1->prevPos).z;
    if (DAT_80399c70 == (LoadedDll *)0x0) {
      DAT_80399c70 = (LoadedDll *)runlinkDownloadCode(0x1002,1);
    }
    iVar1 = randInt(0,0x9b);
    local_48 = local_48 + iVar1;
    iVar1 = randInt(0,0x9b);
    local_44 = local_44 + iVar1;
    local_5c = 1.0;
    local_64 = 0;
    local_62 = 0;
    local_60 = 0;
    (**(code **)(DAT_80399c70->id + 4))(param_1,0,&local_64,1,0xffffffff,&local_4c);
    if (DAT_80399c70 != (LoadedDll *)0x0) {
      DLL_free(DAT_80399c70);
    }
    DAT_80399c70 = (LoadedDll *)0x0;
  }
  FUN_801a7a44((int)param_1,-local_38);
  if (param_2->charState->maxHealth < 1) {
                    /* {@symbol 8011c3c0} */
    (**(code **)(*(int *)pDll11 + 0x14))(param_1,param_3,0x32);
  }
  return;
}


void FUN_801968a4(int *param_1,int param_2,int param_3) { //801968A4
  int iVar1;
  
  if ((*(short *)(param_2 + 0x878) == 0x40) && (param_3 != 0x40)) {
    *(undefined *)(param_2 + 0x8bc) = 0xff;
    backpackFn_801ec694(&DAT_80399c7c);
    *(undefined2 *)(param_2 + 0x878) = 0xffff;
  }
  else {
    if (param_3 == 0x5bd) {
      param_3 = -1;
                    /* {@symbol 80153f4c} */
      iVar1 = (**(code **)(*(int *)pDll_ObjSeq + 0x40))();
      if ((iVar1 != 0) &&
         ((*(short *)(iVar1 + 0x46) == 0x414 || (*(short *)(iVar1 + 0x46) == 0x4a9)))) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(5,param_1,0xffffffff);
        param_3 = 0x5bd;
        iVar1 = getAngle();
                    /* {@symbol 800c89e0} */
        (**(code **)(*(int *)pDll_checkpoint + 0x74))
                  ((int)*(short *)(param_1 + 0x2d),(int)(short)((short)iVar1 + -0x8000));
      }
    }
    else if (param_3 < 0x5bd) {
      if (param_3 == 0x40) {
        if (*(short *)(param_2 + 0x878) == 0x40) {
          backpackFn_801ec694(&DAT_80399c7c);
          *(undefined2 *)(param_2 + 0x878) = 0xffff;
          return;
        }
        iVar1 = FUN_801a7c24((int)param_1);
        if (iVar1 < 6) {
          param_3 = -1;
        }
        else {
          DAT_80399c7c = playerAddChildObj_(0x612);
          FLOAT_80399c40 = 0.0;
                    /* {@symbol 8011c3c0} */
          (**(code **)(*(int *)pDll11 + 0x14))(param_1,param_2,1);
        }
        audioTryStartSfx(param_1,2,0x169,0x7f,"fox.c",0x1282);
      }
      else if ((param_3 < 0x40) && (param_3 == 0x2d)) {
        DAT_80399c86 = 0x2d;
        FUN_801c9bd4(maybeStaff,'\x01',0);
      }
    }
    else if (param_3 == 0x958) {
      DAT_80399c86 = 0x958;
      FUN_801c9bd4(maybeStaff,'\x01',1);
    }
    else if ((param_3 < 0x958) && (param_3 == 0x5ce)) {
      DAT_80399c86 = 0x5ce;
      FUN_801c9bd4(maybeStaff,'\x01',2);
    }
    *(short *)(param_2 + 0x878) = (short)param_3;
  }
  return;
}


void FUN_80197a10(int *param_1,int param_2) { //80197A10
  float fVar1;
  Camera *pCVar2;
  ObjDef *def;
  undefined uVar7;
  ObjInstance *pOVar3;
  int iVar4;
  uint uVar5;
  Mtx44 *pMVar6;
  ObjectFuncPtrs2 *pOVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  dword dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  ObjPos local_114;
  Mtx44 MStack_fc;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  
  _savefpr_20();
  dVar12 = 0;
  iVar9 = param_1[0x2e];
  pCVar2 = getCurCamera();
  audioTryStartSfx(param_1,0x20,0x1fe,0x7f,"fox.c",0x154b);
  for (iVar10 = 1; iVar10 != 0; iVar10 = iVar10 + -1) {
    def = objAlloc(0x24,projball);
    def->loadFlags = isManualLoad;
    def->mapStates2 = 1;
    def->bound = 0xff;
    def->cullDist = 0xff;
    if (*(int *)(param_2 + 0x2c8) == 0) {
      (def->pos).x = (pCVar2->pos).x;
      (def->pos).y = (pCVar2->pos).y;
      (def->pos).z = (pCVar2->pos).z;
    }
    else {
      (def->pos).x = (maybeStaff->pos).pos.x;
      (def->pos).y = (maybeStaff->pos).pos.y;
      (def->pos).z = (maybeStaff->pos).pos.z;
    }
    pOVar8 = maybeStaff->dll->ptrs2;
    uVar7 = (*pOVar8[1].onFreeObjDef)(maybeStaff,pOVar8);
    *(undefined *)((int)&def[1].objType + 1) = uVar7;
    pOVar3 = objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
    if (pOVar3 != (ObjInstance *)0x0) {
      (pOVar3->pos).flags = (pOVar3->pos).flags | DontSave;
      if (*(int *)(param_2 + 0x2c8) == 0) {
        uVar5 = getScreenResolution();
        uVar11 = (int)(uVar5 & 0xffff) >> 1;
        (pOVar3->pos).rotation.x = (pCVar2->rot).x;
        fVar17 = getFovY();
        dVar14 = (double)(fVar17 * 91.022);
        dVar13 = (double)distanceFn_80293e80((double)((float)(dVar14 * 3.141592741012573) / 32767.0)
                                            );
        dVar14 = (double)mathFn_80294204((double)((float)(dVar14 * 3.141592741012573) / 32767.0));
        fVar17 = (float)(dVar13 / dVar14) * 100.0;
        dVar14 = 100.0;
        uStack_94 = *(int *)(iVar9 + 0x80c) - uVar11 ^ 0x80000000;
        local_98 = 0x43300000;
        uStack_9c = uVar11 ^ 0x80000000;
        local_a0 = 0x43300000;
        uStack_a4 = *(int *)(iVar9 + 0x810) - ((int)uVar5 >> 0x11) ^ 0x80000000;
        local_a8 = 0x43300000;
        uStack_ac = (int)uVar5 >> 0x11 ^ 0x80000000;
        local_b0 = 0x43300000;
        dVar16 = (double)(fVar17 * -(((float)((double)CONCAT44(0x43300000,uStack_94) -
                                             4503601774854144.0) /
                                     (float)((double)CONCAT44(0x43300000,uStack_9c) -
                                            4503601774854144.0)) * 1.333333));
        dVar15 = (double)(fVar17 * ((float)((double)CONCAT44(0x43300000,uStack_a4) -
                                           4503601774854144.0) /
                                   (float)((double)CONCAT44(0x43300000,uStack_ac) -
                                          4503601774854144.0)));
        dVar13 = sqrt((double)((float)(dVar16 * dVar16 + (double)(float)(dVar15 * dVar15)) + 10000.0
                              ));
        local_bc = (float)(dVar16 / dVar13);
        local_b8 = (float)(dVar15 / dVar13);
        local_b4 = (float)(dVar14 / dVar13);
        pMVar6 = FUN_8006ad98();
        mathMtxFastXFMF(&pMVar6->m11,&local_bc,&local_bc);
        (pOVar3->vel).x = local_bc * -5.0;
        (pOVar3->vel).y = local_b8 * -5.0;
        (pOVar3->vel).z = local_b4 * -5.0;
        fVar17 = (pCVar2->pos).x;
        (pOVar3->prevPos).x = fVar17;
        (pOVar3->pos).pos.x = fVar17;
        fVar17 = (pCVar2->pos).y;
        (pOVar3->prevPos).y = fVar17;
        (pOVar3->pos).pos.y = fVar17;
        fVar17 = (pCVar2->pos).z;
        (pOVar3->prevPos).z = fVar17;
        (pOVar3->pos).pos.z = fVar17;
        (pOVar3->pos).rotation.y = 0;
      }
      else {
        dVar12 = *(dword *)(param_2 + 0x2c8);
        fVar17 = *(float *)(dVar12 + 0xc) - (maybeStaff->pos).pos.x;
        fVar1 = *(float *)(dVar12 + 0x14) - (maybeStaff->pos).pos.z;
        local_114.pos.x = 0.0;
        local_114.pos.y = 0.0;
        local_114.pos.z = 0.0;
        local_114.scale = 1.0;
        local_114.rotation.x = *(short *)param_1;
        sqrt((double)(fVar17 * fVar17 + fVar1 * fVar1));
        iVar4 = getAngle();
        local_114.rotation.y = (short)iVar4;
        local_114.rotation.z = 0;
        if (param_1[0xc] != 0) {
          local_114.rotation.x = local_114.rotation.x + *(short *)param_1[0xc];
        }
        mtxSetFromObjPos(&MStack_fc,&local_114);
        multVectorByMatrix(0.0,0.0,-5.0,&MStack_fc,&(pOVar3->vel).x,&(pOVar3->vel).y,
                           &(pOVar3->vel).z);
        (pOVar3->prevPos).x = (pOVar3->pos).pos.x;
        (pOVar3->prevPos).y = (pOVar3->pos).pos.y;
        (pOVar3->prevPos).z = (pOVar3->pos).pos.z;
        (pOVar3->pos).rotation.x = *(short *)param_1;
        (pOVar3->pos).rotation.y = 0;
      }
      pOVar3->field76_0xf4 = 0xbe;
      pOVar3->flags_0xf8 = dVar12;
    }
  }
  _restfpr_20();
  return;
}


void FUN_80197e1c(int *param_1) { //80197E1C
  ObjDef *def;
  ObjInstance *pOVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0 [7];
  Camera *local_c4;
  int local_c0;
  undefined4 local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  
  _savefpr_28();
  local_4c = 0;
  iVar3 = 1;
  local_c0 = param_1[0x2e];
  local_c4 = getCurCamera();
  audioTryStartSfx(param_1,(byte)DAT_80397b08,0x275,0x7f,"fox.c",0x15e7);
  DAT_80397b08 = DAT_80397b08 << 1;
  if (4 < DAT_80397b08) {
    DAT_80397b08 = 1;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    def = objAlloc(0x24,rapidFireLa);
    def->loadFlags = isManualLoad;
    def->mapStates2 = 1;
    def->bound = 0xff;
    def->cullDist = 0xff;
    objGetAttachPointWorldPos(maybeStaff,4,&local_ec,&local_f0,&local_f4,FALSE);
    uStack_34 = randInt(-200,200);
    uStack_34 = uStack_34 ^ 0x80000000;
    local_38 = 0x43300000;
    (def->pos).x = local_ec +
                   (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0) / 100.0;
    uStack_3c = randInt(-200,200);
    uStack_3c = uStack_3c ^ 0x80000000;
    local_40 = 0x43300000;
    (def->pos).y = local_f0 +
                   (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) / 100.0;
    uStack_44 = randInt(-200,200);
    uStack_44 = uStack_44 ^ 0x80000000;
    local_48 = 0x43300000;
    (def->pos).z = local_f4 +
                   (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0) / 100.0;
    pOVar1 = objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
    if (pOVar1 != (ObjInstance *)0x0) {
      objGetAttachPointWorldPos(maybeStaff,1,&local_ec,&local_f0,&local_f4,FALSE);
      objGetAttachPointWorldPos(maybeStaff,2,local_e0,&local_e4,&local_e8,FALSE);
      dVar6 = (double)(local_ec - local_e0[0]);
      dVar5 = (double)(local_f4 - local_e8);
      dVar4 = sqrt((double)(float)(dVar5 * dVar5 +
                                  (double)(float)(dVar6 * dVar6 +
                                                 (double)((local_f0 - local_e4) *
                                                         (local_f0 - local_e4)))));
      dVar6 = (double)(float)(dVar6 / dVar4);
      dVar4 = (double)(float)(dVar5 / dVar4);
      iVar2 = getAngle();
      (pOVar1->pos).rotation.x = (short)iVar2;
      sqrt((double)(float)(dVar6 * dVar6 + (double)(float)(dVar4 * dVar4)));
      iVar2 = getAngle();
      (pOVar1->pos).rotation.y = -(short)iVar2;
      (pOVar1->pos).scale = (pOVar1->pos).scale * 6.0;
      FUN_802c9d58(8.0,(short *)pOVar1);
      FUN_802c9d20((int)pOVar1,100);
    }
  }
  _restfpr_28();
  return;
}


undefined4 FUN_8019ac74(double param_1,ObjInstance *param_2,int param_3) { //8019AC74
  short sVar2;
  BOOL BVar1;
  undefined *puVar3;
  
  puVar3 = param_2->state;
  *(float *)(param_3 + 0x27c) = 0.0;
  puVar3[0x8a5] = 1;
  if (param_2->animId == 5) {
    *(float *)(param_3 + 0x298) = 0.02857;
    *(float *)(param_3 + 0x278) = 0.0;
    if (*(int *)(puVar3 + 0x864) != 0) {
      if (param_2->animTimer <= 0.5) {
        sVar2 = objDistFn_80091a84((int)param_2,*(int *)(puVar3 + 0x864),(float *)0x0);
        (param_2->pos).rotation.x =
             (param_2->pos).rotation.x + (short)((int)sVar2 * (int)param_1 >> 4);
      }
      else {
        *(undefined4 *)(*(int *)(puVar3 + 0x864) + 0xf8) = 1;
      }
    }
    if (0.8 < param_2->animTimer) {
      BVar1 = krystalIsClaw(param_2);
      if (BVar1 == FALSE) {
        *(undefined ***)(puVar3 + 0x3c0) = &PTR_DAT_8030e5c0;
      }
      else {
        *(wchar_t **)(puVar3 + 0x3c0) = u_________________________8030e650;
      }
      Object_ObjAnimSetMove(0.0,param_2,(int)**(short **)(puVar3 + 0x3c0),0);
      return 2;
    }
  }
  else {
    Object_ObjAnimSetMove(0.0,param_2,5,0);
    audioTryStartSfx((int *)param_2,1,0x19c,0x25,"fox.c",0x1dde);
    audioTryStartSfx((int *)param_2,2,0x121,0x61,"fox.c",0x1ddf);
  }
  return 0;
}


undefined4 FUN_8019ae08(ObjInstance *param_1,int param_2) { //8019AE08
  BOOL BVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar3 = param_1->state;
  if (*(char *)(param_2 + 0x272) != '\0') {
    *(code **)(param_2 + 0x2fc) = FUN_8019b06c;
    BVar1 = krystalIsClaw(param_1);
    if (BVar1 == FALSE) {
      Object_ObjAnimSetMove(0.0,param_1,0x447,0);
    }
    else {
      Object_ObjAnimSetMove(0.0,param_1,0x26,0);
    }
    audioTryStartSfx((int *)param_1,2,0x121,0x61,"fox.c",0x1e00);
  }
  *(float *)(param_2 + 0x278) = 0.0;
  *(float *)(param_2 + 0x298) = 0.02857;
  if ((*(int *)(puVar3 + 0x864) == 0) && (*(char *)(param_2 + 0x33a) != '\0')) {
    uVar2 = 2;
  }
  else {
    if ((*(int *)(puVar3 + 0x864) != 0) && (0.6 < param_1->animTimer)) {
      *(undefined4 *)(*(int *)(puVar3 + 0x864) + 0xf8) = 0;
      *(undefined4 *)(puVar3 + 0x864) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


undefined4 FUN_8019af10(ObjInstance *param_1,int param_2) { //8019AF10
  BOOL BVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar3 = param_1->state;
  if (*(char *)(param_2 + 0x272) != '\0') {
    *(code **)(param_2 + 0x2fc) = FUN_8019b06c;
    objSetHitNeedsPosUpdate(*(ObjInstance **)(puVar3 + 0x864));
    BVar1 = krystalIsClaw(param_1);
    if (BVar1 == FALSE) {
      Object_ObjAnimSetMove(0.300000011920929,param_1,0x443,0);
    }
    else {
      Object_ObjAnimSetMove(0.300000011920929,param_1,0x24,0);
    }
    audioTryStartSfx((int *)param_1,2,0x121,0x61,"fox.c",0x1e2f);
  }
  FUN_801976e4((int)param_1,param_2);
  *(float *)(param_2 + 0x298) = 0.0165;
  if ((*(int *)(puVar3 + 0x864) == 0) && (*(char *)(param_2 + 0x33a) != '\0')) {
    uVar2 = 2;
  }
  else {
    if ((*(int *)(puVar3 + 0x864) != 0) && (0.4 < param_1->animTimer)) {
      if (*(int *)(*(int *)(puVar3 + 0x864) + 0xf8) == 1) {
        audioTryStartSfx((int *)param_1,1,0x19c,0x25,"fox.c",0x1e3e);
      }
      *(undefined4 *)(*(int *)(puVar3 + 0x864) + 0xf8) = 0;
      *(undefined4 *)(puVar3 + 0x864) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


int FUN_8019b09c(double param_1_00,ObjInstance *param_2,int param_3) { //8019B09C
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  BOOL BVar4;
  short sVar8;
  char cVar9;
  ObjInstance **ppOVar5;
  byte bVar10;
  uint uVar6;
  ObjInstance *pOVar7;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int unaff_r23;
  undefined *puVar13;
  int iVar14;
  undefined4 auStack_cc [2];
  undefined4 local_c4 [17];
  int local_80;
  float local_7c;
  float local_78 [3];
  undefined auStack_6c [56];
  
  puVar13 = param_2->state;
  local_78[0] = 200.0;
  iVar14 = 8;
  puVar1 = (undefined4 *)&UNK_802cfe00;
  puVar2 = auStack_cc;
  do {
    puVar12 = puVar2;
    puVar11 = puVar1;
    uVar3 = puVar11[3];
    puVar12[2] = puVar11[2];
    puVar12[3] = uVar3;
    iVar14 = iVar14 + -1;
    puVar1 = puVar11 + 2;
    puVar2 = puVar12 + 2;
  } while (iVar14 != 0);
  puVar12[4] = puVar11[4];
  BVar4 = krystalIsClaw(param_2);
  if (BVar4 != FALSE) {
    return 0;
  }
  if ((PTR_DAT_80397ab8._0_1_ != '\0') && ((*(ushort *)(puVar13 + 0x766) & 0xc00) != 0)) {
    if ((*(ushort *)(puVar13 + 0x766) & 0x400) == 0) {
      if ((*(ushort *)(puVar13 + 0x766) & 0x800) != 0) {
        sVar8 = FUN_80173464((undefined2 *)(puVar13 + 0x878));
        unaff_r23 = (int)sVar8;
      }
    }
    else {
      sVar8 = FUN_80173448((undefined2 *)(puVar13 + 0x878));
      unaff_r23 = (int)sVar8;
    }
                    /* {@symbol 80153978} */
    if ((((unaff_r23 == 1) && (iVar14 = (**(code **)(*(int *)pDll_ObjSeq + 0x10))(), iVar14 != 0x60)
         ) && (iVar14 != 0x5a)) && (*(int *)(param_3 + 0x2c8) == 0)) {
                    /* {@symbol 801539f0} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x60,1,0,0,0,0x2d,0xff);
      FUN_801968a4((int *)param_2,(int)puVar13,(int)*(short *)(puVar13 + 0x878));
      return 0x3a;
    }
  }
  if (60.0 < FLOAT_80399c74) {
    if (((puVar13[0x8b7] != '\0') && (PTR_DAT_80397ab8._0_1_ != '\0')) &&
       (iVar14 = FUN_801a7c24((int)param_2), 0 < iVar14)) {
      return -0x45;
    }
    FLOAT_80399c74 = 60.0;
  }
  if ((*(int *)(puVar13 + 0x708) != 0) && (*(short *)(*(int *)(puVar13 + 0x708) + 0x46) == 0x112)) {
    if ((*(uint *)(param_3 + 0x310) & 0x100) != 0) {
      return 0x2a;
    }
    return 0;
  }
  cVar9 = FUN_80198f5c(param_1_00,param_2,(int)puVar13,param_3,auStack_6c,0xffffff7f);
  if (cVar9 == -1) {
    puVar13[0x8b1] = 0xff;
    puVar13[0x8b2] = 0;
  }
  else if (cVar9 == puVar13[0x8b1]) {
    cVar9 = puVar13[0x8b2];
    puVar13[0x8b2] = cVar9 + 1U;
    if (200 < (byte)(cVar9 + 1U)) {
      puVar13[0x8b2] = 200;
    }
  }
  else {
    puVar13[0x8b1] = cVar9;
    puVar13[0x8b2] = 0;
  }
  if (false) goto switchD_8019b30c_caseD_1;
                    /* {@symbol 8019b310} */
  switch(puVar13[0x8b1]) {
  case 0:
    if ((*(byte *)(param_3 + 0x260) & 0x10) != 0) {
      return 0x16;
    }
  default:
    goto switchD_8019b30c_caseD_1;
  case 4:
    DAT_80399c4c = 0xffff;
    iVar14 = 0x13;
    break;
  case 5:
    DAT_80399c4c = 0xffff;
    iVar14 = 0x12;
    break;
  case 8:
    iVar14 = -0x26;
    break;
  case 9:
    iVar14 = -10;
    break;
  case 10:
    iVar14 = 0x11;
    break;
  case 0xc:
    if ((*(byte *)(param_3 + 0x260) & 0x10) != 0) {
      return 0x1a;
    }
    goto switchD_8019b30c_caseD_1;
  case 0xd:
    iVar14 = 0x21;
    break;
  case 0xe:
    if (0xc < (byte)puVar13[0x8b2]) {
      return 0x25;
    }
switchD_8019b30c_caseD_1:
    local_7c = 255.0;
    ppOVar5 = Object_playerGetObject(0x43,&local_80);
    for (iVar14 = 0; iVar14 < local_80; iVar14 = iVar14 + 1) {
      DAT_80399c3c = ppOVar5[iVar14];
      cVar9 = FUN_801ed708((int)DAT_80399c3c,(int)param_2);
      if (cVar9 != '\0') {
        bVar10 = FUN_801ed7c4((int)DAT_80399c3c);
        if (bVar10 == 2) {
          FUN_80173438(2);
          if ((*(uint *)(param_3 + 0x310) & 0x100) != 0) {
            return 0x43;
          }
        }
        else if (bVar10 < 2) {
          if ((bVar10 == 0) && (FUN_80173438(3), (*(uint *)(param_3 + 0x310) & 0x100) != 0)) {
            return 0x41;
          }
        }
        else if (bVar10 == 4) {
          FUN_80173438(2);
          if ((*(uint *)(param_3 + 0x310) & 0x100) != 0) {
            return 0x45;
          }
        }
        else if ((bVar10 < 4) && (FUN_80173438(2), (*(uint *)(param_3 + 0x310) & 0x100) != 0)) {
          return 0x44;
        }
      }
    }
                    /* {@symbol 8016db64} */
    iVar14 = (**(code **)(*pdll_camcontrol + 0x1c))();
    if (iVar14 != 0) {
                    /* {@symbol 8016db80} */
      iVar14 = (**(code **)(*pdll_camcontrol + 0x20))(0x1ee);
      if (iVar14 != 0) {
        disableButtons(0,PAD_BUTTON_A);
        uVar6 = mainGetBit(0x3dc);
        if ((uVar6 == 0) || (uVar6 = mainGetBit(0x449), uVar6 == 0)) {
          pOVar7 = getSeqObj(0x3b,param_2,local_78);
          if (pOVar7 != (ObjInstance *)0x0) {
            (*(code *)pOVar7->dll->ptrs2->setScale)(pOVar7);
          }
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(7,param_2,0xffffffff);
        }
        else {
          mainSetBits(0x3f1,1);
          mainSetBits(0x3d8,1);
        }
        return 0;
      }
                    /* {@symbol 8016db80} */
      iVar14 = (**(code **)(*pdll_camcontrol + 0x20))(0x953);
      if ((iVar14 != 0) && (playerObj_80399c64 == (ObjInstance *)0x0)) {
        disableButtons(0,PAD_BUTTON_A);
        puVar13[0x8a4] = 0;
        playerObj_80399c64 = (ObjInstance *)playerAddChildObj(CFCloudCall);
        objAddChild(param_2,playerObj_80399c64,1);
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0xd,param_2,0xffffffff);
        audioTryStartSfx((int *)param_2,0x10,0x23f,0x7f,"fox.c",0x1f4d);
      }
      cVar9 = '\0';
                    /* {@symbol 8016db80} */
      iVar14 = (**(code **)(*pdll_camcontrol + 0x20))(0x5d6);
      if (iVar14 != 0) {
        uVar6 = mainGetBit(0x7e2);
        if (uVar6 == 0) {
          cVar9 = '\n';
          mainSetBits(0x7e2,1);
        }
        else {
          cVar9 = '\n';
        }
      }
      if (cVar9 != '\0') {
        FUN_80196c3c((int)param_2);
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(cVar9,param_2,0xffffffff);
                    /* {@symbol 8016de18} */
        (**(code **)(*pdll_camcontrol + 0x10))();
        return 0;
      }
    }
    if (*(float *)(puVar13 + 0x808) == 0.0) {
      if (puVar13[0x8a0] == '\0') {
        if (puVar13[0x8a4] == '\0') {
          if ((((*(uint *)(param_3 + 0x310) & 0x100) != 0) && (*(int *)(puVar13 + 0x708) == 0)) &&
             (PTR_DAT_80397ab8._0_1_ != '\0')) {
            puVar13[0x8a5] = 4;
            return 0x40;
          }
        }
        else {
          if ((*(uint *)(param_3 + 0x310) & 0x200) != 0) {
            puVar13[0x8a5] = 0;
          }
          iVar14 = FUN_801a4b18(param_2,param_3);
          if (iVar14 != 0) {
            return iVar14;
          }
        }
        iVar14 = 0;
      }
      else {
        iVar14 = 0x54;
      }
    }
    else {
      iVar14 = 0x53;
    }
    break;
  case 0x12:
    iVar14 = 0x26;
  }
  return iVar14;
}


void FUN_8019b7a0(double param_1,ObjInstance *param_2,uint *param_3) { //8019B7A0
  float fVar1;
  float fVar2;
  word wVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined auStack_c4 [52];
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  
  _savefpr_21();
  puVar6 = param_2->state;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    *(undefined2 *)(param_3 + 0x9c) = 0xc;
  }
  iVar4 = FUN_80198f5c(param_1,param_2,(int)puVar6,(int)param_3,auStack_c4,0x14);
  if ((iVar4 != 0x11) &&
     (((iVar4 != 0xc || ((param_2->pos).pos.y + 26.0 < *(float *)(puVar6 + 0x438) + 30.0)) ||
      (*(float *)(puVar6 + 0x434) - 5.0 < (param_2->pos).pos.y + 26.0)))) {
    puVar6[0x8b4] = 1;
    *param_3 = *param_3 | 0x200000;
    FUN_80196490(param_1,(int)param_3);
    wVar3 = param_2->animId;
    if (wVar3 == 0x12) {
      (param_2->vel).y = (float)(param_1 * -0.1000000014901161 + (double)(param_2->vel).y);
      FLOAT_80399ca4 = (float)((double)FLOAT_80399ca4 + param_1);
      FUN_80086488((double)(FLOAT_80399ca4 / FLOAT_80399ca8),(int)param_2);
      if ((FLOAT_80399ca4 <= 10.0) || ((*(byte *)(param_3 + 0x98) & 0x10) == 0)) {
        if ((FLOAT_80399ca8 + 2.0 < FLOAT_80399ca4) ||
           (((param_2->vel).y < 0.0 && (5.0 < (float)param_3[0x6d])))) goto LAB_8019bd1c;
      }
      else {
        Object_ObjAnimSetMove(0.0,param_2,0x11,0);
        param_3[0x9e] = (uint)0.0;
        param_3[0x9f] = (uint)0.0;
        param_3[0xa6] = (uint)0.045;
        iVar4 = FUN_8008820c((int)*(char *)(param_3 + 0x2f));
        audioTryStartSfx((int *)param_2,8,*(ushort *)(*(int *)(puVar6 + 0x894) + iVar4 * 2),0x7f,
                         "fox.c",0x2038);
        audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar6 + 0x3b8) + 0x2c),0x7f,
                         "fox.c",0x2039);
      }
      uStack_74 = (int)(param_2->pos).rotation.x ^ 0x80000000;
      local_78 = 0x43300000;
      dVar7 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_74) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      uStack_7c = (int)(param_2->pos).rotation.x ^ 0x80000000;
      local_80 = 0x43300000;
      dVar8 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_7c) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
      uVar5 = getAngle();
      uVar5 = (uVar5 & 0xffff) - (int)*(short *)(param_3 + 0xc9);
      uStack_84 = uVar5 ^ 0x80000000;
      local_88 = 0x43300000;
      dVar9 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_84) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      uStack_8c = uVar5 ^ 0x80000000;
      local_90 = 0x43300000;
      dVar10 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_8c) -
                                                        4503601774854144.0) * 3.141593) / 32767.0));
      fVar1 = (float)(dVar7 * dVar9 + (double)(float)(dVar8 * dVar10));
      if (fVar1 < 0.0) {
        fVar1 = -fVar1;
      }
      fVar2 = (float)param_3[0xa4];
      if (fVar2 < 0.4) {
        fVar2 = 0.0;
      }
      fVar2 = (1.0 - fVar1) * fVar2;
      if (0 < *(short *)((int)param_3 + 0x32a)) {
        fVar2 = -fVar2;
      }
      param_3[0x9f] =
           (uint)(float)(param_1 * (double)((fVar2 - (float)param_3[0x9f]) * 0.05) +
                        (double)(float)param_3[0x9f]);
      param_3[0x9f] = (uint)((float)param_3[0x9f] * 0.98);
      param_3[0x9f] =
           (uint)(float)(param_1 * (double)((fVar2 - (float)param_3[0x9f]) * 0.015) +
                        (double)(float)param_3[0x9f]);
      if (-0.3 <= (float)param_3[0x9f]) {
        if ((float)param_3[0x9f] <= 0.3) {
          fVar1 = (float)param_3[0x9f];
        }
        else {
          fVar1 = 0.3;
        }
      }
      else {
        fVar1 = -0.3;
      }
      param_3[0x9f] = (uint)fVar1;
      param_3[0x9f] = (uint)((float)param_3[0x9f] * 0.99);
    }
    else {
      if ((short)wVar3 < 0x12) {
        if (0x10 < (short)wVar3) {
                    /* {@symbol 8011c91c} */
          (**(code **)(*(int *)pDll11 + 0x20))(0x3ff0000000000000,param_2,param_3,1);
          (param_2->vel).y = (float)(param_1 * -0.1000000014901161 + (double)(param_2->vel).y);
          if (0.99 < param_2->animTimer) {
            (param_2->vel).y = 0.0;
          }
          goto LAB_8019bd1c;
        }
      }
      else if (wVar3 == 0x417) {
        param_3[0xa6] = (uint)0.01;
                    /* {@symbol 8011c91c} */
        (**(code **)(*(int *)pDll11 + 0x20))(0x3ff0000000000000,param_2,param_3,1);
        if (0.99 < param_2->animTimer) {
          Object_ObjAnimSetMove(0.0,param_2,0x12,0);
          param_3[0xa6] = (uint)0.0;
          param_3[0x9e] = (uint)2.0;
          FLOAT_80399ca8 = 38.4 / (float)param_3[0x9e];
          FLOAT_80399ca4 = 0.0;
          (param_2->vel).y = FLOAT_80399ca8 * 0.1;
          FLOAT_80399ca8 = FLOAT_80399ca8 * 2.0;
          audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar6 + 0x3b8) + 0x10),0x7f,
                           "fox.c",0x201c);
          if (DAT_80399cac != '\0') {
            (param_2->vel).y = (param_2->vel).y * FLOAT_80397ac8;
            param_3[0x9e] = (uint)((float)param_3[0x9e] * FLOAT_80397ac8);
          }
        }
        goto LAB_8019bd1c;
      }
      DAT_80399cac = (float)param_3[0xa4] < FLOAT_80397ac4;
      Object_ObjAnimSetMove(0.0,param_2,0x417,0);
    }
  }
LAB_8019bd1c:
  _restfpr_21();
  return;
}


undefined4 FUN_8019bd38(double param_1,ObjInstance *param_2,uint *param_3) { //8019BD38
  undefined *puVar1;
  
  puVar1 = param_2->state;
  param_3[0x9f] = (uint)0.0;
  *param_3 = *param_3 | 0x200000;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    (param_2->vel).y = -2.0;
    audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar1 + 0x3b8) + 0x12),0x7f,
                     "fox.c",0x209b);
                    /* {@symbol 801539f0} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(99,1,0,0,0,0,0);
    Object_ObjAnimSetMove(0.0,param_2,10,0);
  }
  (param_2->vel).y = -((float)param_1 * 0.12 - (param_2->vel).y);
  param_3[0x9e] = (uint)((float)param_3[0x9e] * 0.98);
  if (param_2->animId == 10) {
    param_3[0xa6] = (uint)0.01;
  }
  if (0x1e < *(short *)(param_3 + 0xcb)) {
    FUN_801a8b9c(0.0,(int)param_2,9);
  }
  return 0;
}


undefined4 FUN_8019be58(double param_1,ObjInstance *param_2,uint *param_3) { //8019BE58
  word wVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  puVar5 = param_2->state;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    *(undefined2 *)(param_3 + 0x9c) = 0xc;
    BVar2 = krystalIsClaw(param_2);
    if (BVar2 != FALSE) {
      backpackFn_801ec694(&DAT_80399c7c);
      *(undefined2 *)(puVar5 + 0x878) = 0xffff;
    }
  }
  param_3[0x9f] = (uint)0.0;
  *param_3 = *param_3 | 0x200000;
  puVar5[0x8b4] = 2;
  wVar1 = param_2->animId;
  if (wVar1 == 0x13) {
                    /* {@symbol 8011c91c} */
    (**(code **)(*(int *)pDll11 + 0x20))(0x3ff0000000000000,param_2,param_3,1);
    (param_2->vel).y = 0.0;
    if (0.99 < param_2->animTimer) {
      return 2;
    }
    puVar5[0x8b4] = 3;
    goto LAB_8019c3a0;
  }
  if ((short)wVar1 < 0x13) {
    if (wVar1 == 0xb) {
      param_3[0xa6] = (uint)0.015;
      param_3[0x9e] = (uint)0.0;
      if (*(char *)((int)param_3 + 0x33a) != '\0') {
        if (*(char *)(*(int *)(puVar5 + 0x34c) + 1) < '\x01') {
          FUN_80197720(param_2,1);
          return 0xfffffff3;
        }
        Object_ObjAnimSetMove(0.0,param_2,0xc,0);
      }
      goto LAB_8019c3a0;
    }
    if ((short)wVar1 < 0xb) {
      if (wVar1 == 9) {
        param_3[0xa6] = (uint)0.02;
        if (*(char *)((int)param_3 + 0x33a) != '\0') {
          Object_ObjAnimSetMove(0.0,param_2,10,0);
        }
        if ((float)param_3[0x6b] == 0.0) {
          if (*(char *)(param_3 + 0x2f) == '\b') {
            FUN_801a8b9c(0.0,(int)param_2,9);
            return 0xf;
          }
          audioTryStartSfx((int *)param_2,8,0xf3,0x7f,"fox.c",0x212b);
          Object_ObjAnimSetMove(0.0,param_2,0xb,0);
          FUN_801a7a44((int)param_2,-4);
        }
        (param_2->vel).y = -(float)(param_1 * 0.1000000014901161 - (double)(param_2->vel).y);
        param_3[0x9e] = (uint)((float)param_3[0x9e] * 0.98);
        goto LAB_8019c3a0;
      }
      if (8 < (short)wVar1) {
        param_3[0xa6] = (uint)0.01;
        if ((float)param_3[0x6b] == 0.0) {
          if (*(char *)(param_3 + 0x2f) == '\b') {
            FUN_801a8b9c(0.0,(int)param_2,9);
            return 0xf;
          }
          audioTryStartSfx((int *)param_2,8,0xf3,0x7f,"fox.c",0x2142);
          Object_ObjAnimSetMove(0.0,param_2,0xb,0);
          FUN_801a7a44((int)param_2,-8);
        }
        if (0x3c < *(short *)(param_3 + 0xcb)) {
          FUN_801a8b9c(0.0,(int)param_2,9);
        }
        (param_2->vel).y = -(float)(param_1 * 0.1000000014901161 - (double)(param_2->vel).y);
        param_3[0x9e] = (uint)((float)param_3[0x9e] * 0.98);
        goto LAB_8019c3a0;
      }
    }
    else if ((short)wVar1 < 0xd) {
      param_3[0xa6] = (uint)0.004;
      param_3[0x9e] = (uint)0.0;
      if (*(char *)((int)param_3 + 0x33a) != '\0') {
        return 0xffffffff;
      }
      goto LAB_8019c3a0;
    }
  }
  else {
    if (wVar1 == 0x418) {
                    /* {@symbol 8011c91c} */
      (**(code **)(*(int *)pDll11 + 0x20))(0x3ff0000000000000,param_2,param_3,1);
      (param_2->vel).y = 0.0;
      if (0.99 < param_2->animTimer) {
        if (((0.42 <= (float)param_3[0xa5]) && (0.42 <= (float)param_3[0xa4])) &&
           (DAT_8030e684 <= (float)param_3[0xa3])) {
          return 5;
        }
        return 2;
      }
      puVar5[0x8b4] = 3;
      goto LAB_8019c3a0;
    }
    if (((short)wVar1 < 0x418) && (wVar1 == 0x54)) {
      param_3[0xa6] = (uint)0.01;
      if ((*(byte *)(param_3 + 0x98) & 0x10) != 0) {
        if (*(char *)(param_3 + 0x2f) == '\b') {
          FUN_801a8b9c(0.0,(int)param_2,9);
          return 0xf;
        }
        if ((((float)param_3[0xa5] < 0.42) || ((float)param_3[0xa4] < 0.42)) ||
           ((float)param_3[0xa3] < DAT_8030e684)) {
          Object_ObjAnimSetMove(0.0,param_2,0x13,0);
          param_3[0x9e] = (uint)0.0;
          param_3[0x9f] = (uint)0.0;
          param_3[0xa6] = (uint)0.035;
        }
        else {
          Object_ObjAnimSetMove(0.0,param_2,0x418,0);
          param_3[0xa6] = (uint)0.08;
        }
        iVar3 = FUN_8008820c((int)*(char *)(param_3 + 0x2f));
        audioTryStartSfx((int *)param_2,8,*(ushort *)(*(int *)(puVar5 + 0x894) + iVar3 * 2),0x7f,
                         "fox.c",0x20ee);
        audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar5 + 0x3b8) + 0x2c),0x7f,
                         "fox.c",0x20ef);
      }
      if (0x50 < *(short *)(param_3 + 0xcb)) {
        audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar5 + 0x3b8) + 0x12),0x7f,
                         "fox.c",0x20f6);
        Object_ObjAnimSetMove(0.0,param_2,9,0);
      }
      (param_2->vel).y = -(float)(param_1 * 0.1000000014901161 - (double)(param_2->vel).y);
      param_3[0x9e] = (uint)((float)param_3[0x9e] * 0.98);
      goto LAB_8019c3a0;
    }
  }
  Object_ObjAnimSetMove(0.0,param_2,0x54,0);
LAB_8019c3a0:
                    /* {@symbol 80153978} */
  iVar3 = (**(code **)(*(int *)pDll_ObjSeq + 0x10))();
  if (iVar3 == 0x59) {
                    /* {@symbol 801539f0} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,2,0,0,0,0xff);
  }
  if ((0.0 <= (param_2->vel).y) || ((float)param_3[0x6d] <= 5.0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x1e;
  }
  return uVar4;
}


void FUN_8019c670(undefined8 param_1,ObjInstance *param_2,uint *param_3) { //8019C670
  word wVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined2 local_44;
  undefined local_42;
  undefined local_41;
  
  _savefpr_28();
  puVar5 = param_2->state;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    audioTryStartSfx((int *)param_2,8,*(ushort *)(*(int *)(puVar5 + 0x3b8) + 0x2e),0x7f,
                     "fox.c",0x21fc);
    *(undefined2 *)(param_3 + 0x9c) = 0x10;
  }
  *(float *)(puVar5 + 0x7fc) = 0.0;
  iVar2 = FUN_8019d94c((int)param_2,param_3);
  if (iVar2 != 0) goto LAB_8019ca24;
  (param_2->vel).y = 0.0;
  dVar7 = (double)*(float *)(puVar5 + 0x4bc);
  dVar6 = (double)*(float *)(puVar5 + 0x4c4);
  wVar1 = param_2->animId;
  if (wVar1 == 0x22) {
    dVar8 = (double)(param_2->animTimer * (*(float *)(puVar5 + 0x4a0) - *(float *)(puVar5 + 0x494))
                    + *(float *)(puVar5 + 0x494));
                    /* {@symbol 8011cb20} */
    (**(code **)(*(int *)pDll11 + 0x28))(param_1,0x3fc99999a0000000,param_2,param_3);
    if (*(char *)((int)param_3 + 0x33a) != '\0') {
      Object_ObjAnimSetMove(0.0,param_2,(int)DAT_8030e3d2,0);
      param_3[0xa6] = (uint)0.021;
      local_44 = 0;
      local_42 = 0;
      local_41 = 1;
    }
  }
  else if ((short)wVar1 < 0x22) {
    if (wVar1 == 0xd) {
      dVar8 = (double)(param_2->animTimer *
                       (*(float *)(puVar5 + 0x4a0) - *(float *)(puVar5 + 0x494)) +
                      *(float *)(puVar5 + 0x494));
                    /* {@symbol 8011cb20} */
      (**(code **)(*(int *)pDll11 + 0x28))(param_1,0x3fc99999a0000000,param_2,param_3);
      if (*(char *)((int)param_3 + 0x33a) != '\0') {
        Object_ObjAnimSetMove(0.0,param_2,(int)DAT_8030e3d0,0);
        param_3[0xa6] = (uint)0.021;
        local_44 = 0;
        local_42 = 0;
        local_41 = 1;
      }
    }
    else {
LAB_8019c8cc:
      uVar3 = getAngle();
      iVar2 = (uVar3 & 0xffff) - (int)(param_2->pos).rotation.x;
      if (0x8000 < iVar2) {
        iVar2 = iVar2 + -0xffff;
      }
      if (iVar2 < -0x8000) {
        iVar2 = iVar2 + 0xffff;
      }
      if (puVar5[0x4d7] == '\x01') {
        iVar4 = 10;
      }
      else {
        iVar4 = 0xb;
      }
      (param_2->pos).rotation.x = (param_2->pos).rotation.x + (short)iVar2;
      (param_2->pos).pos.y = *(float *)(puVar5 + 0x494);
      Object_ObjAnimSetMove(0.0,param_2,(int)(short)(&DAT_8030e3b8)[iVar4],4);
      param_3[0xa6] = (uint)0.03;
      param_3[0xbb] =
           (uint)(*(float *)(puVar5 + 0x4ac) * 0.5 +
                 (*(float *)(puVar5 + 0x4bc) - (param_2->pos).pos.x));
      param_3[0xbc] = (uint)0.0;
      param_3[0xbd] =
           (uint)(*(float *)(puVar5 + 0x4b4) * 0.5 +
                 (*(float *)(puVar5 + 0x4c4) - (param_2->pos).pos.z));
      param_3[0xa9] = (uint)0.0;
      *(undefined4 *)(puVar5 + 0x49c) = *(undefined4 *)(puVar5 + 0x4bc);
      *(float *)(puVar5 + 0x4a0) = *(float *)(puVar5 + 0x494) - 26.0;
      *(undefined4 *)(puVar5 + 0x4a4) = *(undefined4 *)(puVar5 + 0x4c4);
      dVar8 = (double)*(float *)(puVar5 + 0x494);
                    /* {@symbol 801539f0} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x51,1,0,4,&local_44,0,0xff);
    }
  }
  else {
    if ((0x50 < (short)wVar1) || ((short)wVar1 < 0x4f)) goto LAB_8019c8cc;
    dVar8 = (double)*(float *)(puVar5 + 0x4a0);
                    /* {@symbol 8011cb20} */
    (**(code **)(*(int *)pDll11 + 0x28))(param_1,0x3fc99999a0000000,param_2,param_3);
                    /* {@symbol 8011c91c} */
    (**(code **)(*(int *)pDll11 + 0x20))(param_1,param_2,param_3,2);
    if (*(char *)((int)param_3 + 0x33a) != '\0') {
      DAT_80399c4c = 3;
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar7,dVar8,dVar6);
      goto LAB_8019ca24;
    }
  }
  puVar5[0x8ba] = puVar5[0x8ba] | 4;
                    /* {@symbol 80153dd4} */
  (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar7,dVar8,dVar6);
LAB_8019ca24:
  _restfpr_28();
  return;
}


void FUN_8019ca40(double param_1,ObjInstance *param_2,uint *param_3) { //8019CA40
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  ObjState_Player *state;
  double dVar10;
  double dVar11;
  double dVar12;
  
  _savefpr_25();
  state = (ObjState_Player *)param_2->state;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    *(undefined2 *)(param_3 + 0x9c) = 0x11;
  }
  iVar9 = FUN_8019d94c((int)param_2,param_3);
  if (iVar9 != 0) goto LAB_8019ce1c;
  (param_2->vel).y = 0.0;
  fVar2 = DAT_8039576c;
  fVar1 = DAT_80395768;
  fVar8 = DAT_80395764;
  fVar7 = DAT_80395760;
  fVar6 = DAT_8039575c;
  fVar5 = DAT_80395758;
  fVar4 = DAT_80395754;
  fVar3 = DAT_80395750;
  if (false) {
switchD_8019cadc_caseD_f:
    if (state->field_0x4d6 == '\x06') {
      if (*(float *)&state->field_0x490 < DAT_80395750) {
        if (*(float *)&state->field_0x490 < DAT_80395760) {
          DAT_80399c4c = 0x12;
          param_3[0xa6] = (uint)0.014;
          fVar1 = fVar5;
          fVar2 = fVar6;
        }
        else {
          DAT_80399c4c = 0x16;
          param_3[0xa6] = (uint)0.011;
          fVar1 = fVar7;
          fVar2 = fVar8;
        }
      }
      else {
        DAT_80399c4c = 0xe;
        param_3[0xa6] = (uint)0.009;
        fVar1 = fVar3;
        fVar2 = fVar4;
      }
    }
    else {
      DAT_80399c4c = 0x1a;
      param_3[0xa6] = (uint)0.01;
    }
    fVar1 = ((*(float *)&state->field_0x490 - fVar1) / (fVar2 - fVar1)) * 16384.0;
    if (0.0 <= fVar1) {
      if (16384.0 < fVar1) {
        fVar1 = 16384.0;
      }
    }
    else {
      fVar1 = 0.0;
    }
    *(short *)&state->field_0x4d4 = (short)(int)fVar1;
    playerMoveFn_802a71e0
              (0.0,(double)(float)param_3[0xa6],param_2,(int)(short)(&DAT_8030e3b8)[DAT_80399c4c],
               (int)(short)(&DAT_8030e3b8)[DAT_80399c4c + 2],(float *)&state->field_0x4c8,
               (float *)&state->field_0x4ac,2,9);
    playerMoveFn_802a71e0
              (0.0,(double)(float)param_3[0xa6],param_2,(int)(short)(&DAT_8030e3b8)[DAT_80399c4c],
               (int)(short)(&DAT_8030e3b8)[DAT_80399c4c + 1],(float *)&state->field_0x4c8,
               (float *)&state->field_0x4ac,2,0x34);
    playerMoveFn_802a71e0
              (0.0,(double)(float)param_3[0xa6],param_2,
               (int)(short)(&DAT_8030e3b8)[DAT_80399c4c + 2],
               (int)(short)(&DAT_8030e3b8)[DAT_80399c4c + 3],(float *)&state->field_0x4c8,
               (float *)&state->field_0x4ac,2,0x1a);
    iVar9 = getAngle();
    (param_2->pos).rotation.x = (short)iVar9;
    (param_2->pos).pos.x = *(float *)&state->field_0x4bc;
    (param_2->pos).pos.z = *(float *)&state->field_0x4c4;
    objFn_8019680c(param_2,state);
  }
  else {
                    /* {@symbol 8019cae0} */
    switch(DAT_80399c4c) {
    case 0xe:
    case 0x12:
    case 0x16:
    case 0x1a:
      if ((param_3[0xc2] & 1) != 0) {
        iVar9 = randInt(10,0xb);
        audioTryStartSfx((int *)param_2,8,*(ushort *)(state->field927_0x3b8 + iVar9 * 2),0x7f,
                         "fox.c",0x2292);
      }
      if (*(char *)((int)param_3 + 0x33a) != '\0') {
        (param_2->prevPos).x = state->field1969_0x7ec;
        (param_2->prevPos).y = *(float *)&state->field_0x494;
        (param_2->prevPos).z = state->field1971_0x7f4;
        param_2->animVal_a2 = -1;
        multVectorByObjMtx2((double)(param_2->prevPos).x,(double)(param_2->prevPos).y,
                            (double)(param_2->prevPos).z,&(param_2->pos).pos.x,&(param_2->pos).pos.y
                            ,&(param_2->pos).pos.z,(int)param_2->pMatrix);
        objFn_8019680c(param_2,state);
        Object_ObjAnimSetMove(0.0,param_2,(int)*(short *)state->field932_0x3c0,1);
        goto LAB_8019ce1c;
      }
      break;
    default:
      goto switchD_8019cadc_caseD_f;
    }
  }
  FUN_80087380((int)param_2,0,2,0);
  FUN_80087380((int)param_2,1,2,0);
  FUN_80087380((int)param_2,1,0,*(undefined2 *)&state->field_0x4d4);
  FUN_800876b8((double)(float)param_3[0xa6],param_1,(int)param_2,0);
  dVar12 = (double)state->field1969_0x7ec;
  dVar11 = (double)(param_2->animTimer * (*(float *)&state->field_0x494 - (param_2->pos).pos.y) +
                   (param_2->pos).pos.y);
  dVar10 = (double)state->field1971_0x7f4;
                    /* {@symbol 80153dd4} */
  (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar12,dVar11,dVar10);
  FUN_800b26dc(dVar12,dVar11,dVar10,(int)param_2);
LAB_8019ce1c:
  _restfpr_25();
  return;
}


void FUN_8019ce38(double param_1,ObjInstance *param_2,uint *param_3) { //8019CE38
  float fVar1;
  int iVar2;
  uint uVar3;
  ModelInstance *mInst;
  bool flags;
  short sVar4;
  ObjState_Player *state;
  double dVar5;
  double dVar6;
  double dVar7;
  double in_f30;
  vec3s vStack_94;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  vec3f vStack_7c;
  undefined4 local_70;
  uint uStack_6c;
  longlong local_68;
  
  _savefpr_25();
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    *(undefined2 *)(param_3 + 0x9c) = 0x12;
    (param_2->vel).y = 0.0;
  }
  state = (ObjState_Player *)param_2->state;
  *(float *)&state->field_0x7fc = 0.0;
  mInst = (ModelInstance *)param_2->modelInstances->mtxs[(char)param_2->curModel + -3];
  iVar2 = FUN_8019d94c((int)param_2,param_3);
  if (iVar2 != 0) goto LAB_8019d5a8;
  sVar4 = 0;
  flags = false;
  DAT_80399c4e = DAT_80399c4c;
  if (false) {
switchD_8019cefc_caseD_1:
    (param_2->vel).y = 0.0;
    iVar2 = (int)(-((*(float *)&state->field_0x490 - 32.0) * 0.03125 - 1.0) * 16384.0);
    local_68 = (longlong)iVar2;
    sVar4 = (short)iVar2;
    DAT_80399c4c = 0;
    in_f30 = 0.02899999916553497;
    uVar3 = getAngle();
    uStack_6c = (uVar3 & 0xffff) - (int)(param_2->pos).rotation.x ^ 0x80000000;
    local_70 = 0x43300000;
    param_3[0xbe] = (uint)(float)((double)CONCAT44(0x43300000,uStack_6c) - 4503601774854144.0);
    if (32768.0 < (float)param_3[0xbe]) {
      param_3[0xbe] = (uint)((float)param_3[0xbe] + -65535.0);
    }
    if ((float)param_3[0xbe] < -32768.0) {
      param_3[0xbe] = (uint)((float)param_3[0xbe] + 65535.0);
    }
    param_3[0xa8] = (uint)0.0;
    *(float *)&state->field_0x49c = (param_2->pos).pos.x;
    *(float *)&state->field_0x4a0 = (param_2->pos).pos.y;
    *(float *)&state->field_0x4a4 = (param_2->pos).pos.z;
  }
  else {
                    /* {@symbol 8019cf00} */
    switch(DAT_80399c4c) {
    case 0:
      if (*(char *)((int)param_3 + 0x33a) == '\0') {
                    /* {@symbol 8011cb9c} */
        (**(code **)(*(int *)pDll11 + 0x2c))(param_1,0x3fb99999a0000000,param_2,param_3);
      }
      else {
        (param_2->prevPos).x = state->field1969_0x7ec;
        (param_2->prevPos).y = state->field1970_0x7f0;
        (param_2->prevPos).z = state->field1971_0x7f4;
        multVectorByObjMtx2((double)(param_2->prevPos).x,(double)(param_2->prevPos).y,
                            (double)(param_2->prevPos).z,&(param_2->pos).pos.x,&(param_2->pos).pos.y
                            ,&(param_2->pos).pos.z,(int)param_2->pMatrix);
        Object_ObjAnimSetMove(0.0,param_2,(int)DAT_8030e3bc,1);
        param_3[0xa6] = (uint)0.01;
        DAT_80399c4c = 2;
        DAT_80399c4e = 2;
        objAnimFn_8008045c(0.0,(double)(param_2->pos).scale,mInst,0,0,&vStack_7c,&vStack_94);
        (param_2->pos).pos.y = (param_2->pos).pos.y - vStack_7c.y;
        dVar5 = (double)(-(DAT_80395748 + (*(float *)&state->field_0x494 - state->field1970_0x7f0))
                        * -0.3);
        if (dVar5 < 0.0) {
          (param_2->vel).y = 0.0;
        }
        else {
          dVar5 = sqrt(dVar5);
          (param_2->vel).y = (float)dVar5;
        }
        local_88 = *(float *)&state->field_0x4ac * DAT_80395788 + *(float *)&state->field_0x4bc;
        local_84 = *(float *)&state->field_0x4b0 * DAT_80395788 + *(float *)&state->field_0x4c0;
        local_80 = *(float *)&state->field_0x4b4 * DAT_80395788 + *(float *)&state->field_0x4c4;
        param_3[0xbb] = (uint)(*(float *)&state->field_0x4bc - (param_2->pos).pos.x);
        param_3[0xbc] = (uint)0.0;
        param_3[0xbd] = (uint)(*(float *)&state->field_0x4c4 - (param_2->pos).pos.z);
        FLOAT_80399c50 = (param_2->pos).pos.x;
        FLOAT_80399c54 = (param_2->pos).pos.z;
        audioTryStartSfx((int *)param_2,0x10,*(ushort *)(state->field927_0x3b8 + 0x10),0x7f,
                         "fox.c",0x234a);
      }
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))
                ((double)*(float *)&state->field_0x49c,(double)*(float *)&state->field_0x4a0,
                 (double)*(float *)&state->field_0x4a4);
      break;
    default:
      goto switchD_8019cefc_caseD_1;
    case 2:
      fVar1 = *(float *)&state->field_0x494 + DAT_80395748;
      (param_2->vel).y = (float)(param_1 * -0.1500000059604645 + (double)(param_2->vel).y);
      local_8c = (state->field1970_0x7f0 - *(float *)&state->field_0x498) /
                 (fVar1 - *(float *)&state->field_0x498);
      if (0.0 <= local_8c) {
        if (1.0 < local_8c) {
          local_8c = 1.0;
        }
      }
      else {
        local_8c = 0.0;
      }
      (param_2->pos).pos.x = local_8c * (float)param_3[0xbb] + FLOAT_80399c50;
      (param_2->pos).pos.z = local_8c * (float)param_3[0xbd] + FLOAT_80399c54;
      flags = fVar1 <= state->field1970_0x7f0;
      if (flags) {
        DAT_80399c4c = 3;
        in_f30 = 0.03500000014901161;
        (param_2->pos).pos.y = *(float *)&state->field_0x494;
        (param_2->vel).y = 0.0;
      }
      *(float *)&state->field_0x4a0 =
           (float)(param_1 * (double)(((param_2->pos).pos.y - *(float *)&state->field_0x4a0) * 0.02)
                  + (double)*(float *)&state->field_0x4a0);
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))
                ((double)*(float *)&state->field_0x49c,(double)*(float *)&state->field_0x4a0,
                 (double)*(float *)&state->field_0x4a4);
      FUN_800b26dc((double)*(float *)&state->field_0x49c,(double)*(float *)&state->field_0x4a0,
                   (double)*(float *)&state->field_0x4a4,(int)param_2);
      break;
    case 3:
      if (*(char *)((int)param_3 + 0x33a) != '\0') {
        if ((float)param_3[0xa1] <= 5.0) {
          if (((float)param_3[0xa1] < -5.0) && (state->field_0x4d6 != '\x11')) goto LAB_8019d5a8;
          DAT_80399c4c = 6;
          in_f30 = 0.00800000037997961;
        }
        else {
          DAT_80399c4c = 5;
          in_f30 = 0.01400000043213367;
          iVar2 = randInt(10,0xb);
          audioTryStartSfx((int *)param_2,8,*(ushort *)(state->field927_0x3b8 + iVar2 * 2),0x7f,
                           "fox.c",0x2376);
        }
      }
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))
                ((double)*(float *)&state->field_0x49c,(double)*(float *)&state->field_0x4a0,
                 (double)*(float *)&state->field_0x4a4);
      FUN_800b26dc((double)*(float *)&state->field_0x49c,(double)*(float *)&state->field_0x4a0,
                   (double)*(float *)&state->field_0x4a4,(int)param_2);
      break;
    case 5:
      if (*(char *)((int)param_3 + 0x33a) != '\0') {
        (param_2->prevPos).x = state->field1969_0x7ec;
        (param_2->prevPos).z = state->field1971_0x7f4;
        multVectorByObjMtx2((double)(param_2->prevPos).x,0.0,(double)(param_2->prevPos).z,
                            &(param_2->pos).pos.x,&local_8c,&(param_2->pos).pos.z,
                            (int)param_2->pMatrix);
        objFn_8019680c(param_2,state);
        Object_ObjAnimSetMove(0.0,param_2,(int)*(short *)state->field932_0x3c0,1);
        goto LAB_8019d5a8;
      }
      dVar7 = (double)(param_2->animTimer * ((param_2->pos).pos.x - *(float *)&state->field_0x49c) +
                      *(float *)&state->field_0x49c);
      dVar6 = (double)(param_2->animTimer *
                       (*(float *)&state->field_0x494 - *(float *)&state->field_0x4a0) +
                      *(float *)&state->field_0x4a0);
      dVar5 = (double)(param_2->animTimer * ((param_2->pos).pos.z - *(float *)&state->field_0x4a4) +
                      *(float *)&state->field_0x4a4);
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar7,dVar6,dVar5);
      FUN_800b26dc(dVar7,dVar6,dVar5,(int)param_2);
      break;
    case 6:
      if ((float)param_3[0xa1] <= 5.0) {
        if (((float)param_3[0xa1] < -5.0) && (state->field_0x4d6 != '\x11')) goto LAB_8019d5a8;
      }
      else {
        DAT_80399c4c = 5;
        in_f30 = 0.01400000043213367;
        iVar2 = randInt(10,0xb);
        audioTryStartSfx((int *)param_2,8,*(ushort *)(state->field927_0x3b8 + iVar2 * 2),0x7f,
                         "fox.c",0x238d);
      }
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))
                ((double)*(float *)&state->field_0x49c,(double)*(float *)&state->field_0x4a0,
                 (double)*(float *)&state->field_0x4a4);
      FUN_800b26dc((double)*(float *)&state->field_0x49c,(double)*(float *)&state->field_0x4a0,
                   (double)*(float *)&state->field_0x4a4,(int)param_2);
    }
  }
  if (DAT_80399c4e != DAT_80399c4c) {
    Object_ObjAnimSetMove(0.0,param_2,(int)(short)(&DAT_8030e3b8)[DAT_80399c4c],flags);
    if (sVar4 != 0) {
      FUN_80087afc((int)param_2,(int)(short)(&DAT_8030e3b8)[DAT_80399c4c + 1],sVar4);
    }
    param_3[0xa6] = (uint)(float)in_f30;
  }
  objFn_8019680c(param_2,state);
LAB_8019d5a8:
  _restfpr_25();
  return;
}


void FUN_8019d9a8(double param_1,ObjInstance *param_2,uint *param_3) { //8019D9A8
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  undefined4 local_70;
  vec3f vStack_6c;
  vec3s vStack_60;
  undefined4 local_58;
  uint uStack_54;
  
  _savefpr_27();
  puVar6 = param_2->state;
  iVar2 = FUN_8019d94c((int)param_2,param_3);
  if (iVar2 == 0) {
    (param_2->vel).y = 0.0;
    bVar7 = puVar6[0x3cc] == '\x01';
    if (bVar7) {
      param_3[0xa6] = (uint)0.014;
    }
    else {
      param_3[0xa6] = (uint)0.01;
    }
    if ((param_3[0xc2] & 0x80) != 0) {
      iVar2 = randInt(10,0xe);
      audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar6 + 0x3b8) + iVar2 * 2),0x7f,
                       "fox.c",0x24a4);
    }
    if ((param_3[0xc2] & 1) != 0) {
      audioTryStartSfx((int *)param_2,8,0x100,0x7f,"fox.c",0x24a8);
    }
    if (*(char *)((int)param_3 + 0x272) == '\0') {
      if (0.9 < param_2->animTimer) {
        FUN_800876b8((double)(float)param_3[0xa6],param_1,(int)param_2,0);
        goto LAB_8019ded8;
      }
    }
    else {
      puVar6[0x8a5] = 1;
      param_3[0x9e] = (uint)0.0;
      param_3[0x9f] = (uint)0.0;
      *(undefined2 *)(param_3 + 0x9c) = 0x15;
      param_3[0xbf] = (uint)&LAB_801a02b8;
      local_80 = 0.0;
      if (bVar7) {
        local_84 = *(float *)(puVar6 + 0x3f4);
        local_7c = *(float *)(puVar6 + 0x3fc);
        local_78 = *(float *)(puVar6 + 0x400);
      }
      else {
        local_84 = -*(float *)(puVar6 + 0x3f4);
        local_7c = -*(float *)(puVar6 + 0x3fc);
        local_78 = -*(float *)(puVar6 + 0x400);
      }
      uVar3 = getAngle();
      iVar2 = (uVar3 & 0xffff) - (int)(param_2->pos).rotation.x;
      if (0x8000 < iVar2) {
        iVar2 = iVar2 + -0xffff;
      }
      if (iVar2 < -0x8000) {
        iVar2 = iVar2 + 0xffff;
      }
      (param_2->pos).rotation.x = (param_2->pos).rotation.x + (short)iVar2;
      *(float *)(puVar6 + 0x3ec) = (param_2->pos).pos.x;
      *(float *)(puVar6 + 0x3f0) = (param_2->pos).pos.z;
      (param_2->pos).pos.x = *(float *)(puVar6 + 0x414);
      (param_2->pos).pos.z = *(float *)(puVar6 + 0x41c);
      if (*(float *)(puVar6 + 0x3e4) < 0.0) {
        iVar2 = 4;
      }
      else {
        iVar2 = 0;
      }
      if (bVar7) {
        ppuVar5 = &PTR_DAT_8030e4ac;
      }
      else {
        ppuVar5 = (undefined **)&DAT_8030e4bc;
      }
      uVar4 = playerMoveFn_802a71e0
                        (0.0,(double)(float)param_3[0xa6],param_2,
                         (int)*(short *)((int)ppuVar5 + iVar2 * 2),
                         (int)*(short *)((int)ppuVar5 + (iVar2 + 2) * 2),(float *)(puVar6 + 0x420),
                         &local_84,2,9);
      *(undefined2 *)(puVar6 + 0x42c) = uVar4;
      uVar3 = 0x34;
      if (!bVar7) {
        uVar3 = 0x74;
      }
      playerMoveFn_802a71e0
                (0.0,(double)(float)param_3[0xa6],param_2,(int)*(short *)((int)ppuVar5 + iVar2 * 2),
                 (int)*(short *)((int)ppuVar5 + (iVar2 + 1) * 2),(float *)(puVar6 + 0x420),
                 (float *)(puVar6 + 0x404),0,uVar3);
      playerMoveFn_802a71e0
                (0.0,(double)(float)param_3[0xa6],param_2,
                 (int)*(short *)((int)ppuVar5 + (iVar2 + 2) * 2),
                 (int)*(short *)((int)ppuVar5 + (iVar2 + 3) * 2),(float *)(puVar6 + 0x420),
                 (float *)(puVar6 + 0x404),0,0x1a);
      uStack_54 = (int)(char)puVar6[0x3cc] ^ 0x80000000;
      local_58 = 0x43300000;
      *(float *)(puVar6 + 0x3dc) =
           *(float *)(puVar6 + 0x3d8) *
           (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0) +
           *(float *)(puVar6 + 0x3d4);
      *(float *)(puVar6 + 0x3e0) = (param_2->pos).pos.y;
      objAnimFn_8008045c(1.0,(double)(param_2->pos).scale,
                         (ModelInstance *)
                         param_2->modelInstances->mtxs[(char)param_2->curModel + -3],0,0,&vStack_6c,
                         &vStack_60);
      FLOAT_80399c50 = (param_2->pos).pos.y + vStack_6c.y;
      FLOAT_80399c54 = *(float *)(puVar6 + 0x3dc) + DAT_80395744;
      local_74 = *(undefined4 *)(puVar6 + 0x3d0);
      local_70 = *(undefined4 *)(puVar6 + 0x3d4);
                    /* {@symbol 801539f0} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x59,1,1,8,&local_74,0,0);
    }
    if (0.7 <= param_2->animTimer) {
      fVar1 = (param_2->animTimer * 1.052 - 0.7) * 3.333;
      if (0.0 <= fVar1) {
        if (1.0 < fVar1) {
          fVar1 = 1.0;
        }
      }
      else {
        fVar1 = 0.0;
      }
      (param_2->pos).pos.y = fVar1 * (FLOAT_80399c54 - FLOAT_80399c50) + *(float *)(puVar6 + 0x3e0);
    }
    FUN_80087380((int)param_2,0,2,0);
    FUN_80087380((int)param_2,1,2,0);
    FUN_80087380((int)param_2,1,0,*(undefined2 *)(puVar6 + 0x42c));
    FUN_800876b8((double)(float)param_3[0xa6],param_1,(int)param_2,0);
    dVar9 = (double)(param_2->animTimer * ((param_2->pos).pos.x - *(float *)(puVar6 + 0x3ec)) +
                    *(float *)(puVar6 + 0x3ec));
    dVar10 = (double)(param_2->animTimer * (*(float *)(puVar6 + 0x3dc) - (param_2->pos).pos.y) +
                     (param_2->pos).pos.y);
    dVar8 = (double)(param_2->animTimer * ((param_2->pos).pos.z - *(float *)(puVar6 + 0x3f0)) +
                    *(float *)(puVar6 + 0x3f0));
                    /* {@symbol 80153dd4} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x2c))
              ((double)(param_2->pos).pos.x,dVar10,(double)(param_2->pos).pos.z);
    FUN_800b26dc(dVar9,dVar10,dVar8,(int)param_2);
    objFn_8019680c(param_2,(ObjState_Player *)param_2->state);
  }
LAB_8019ded8:
  _restfpr_27();
  return;
}


void FUN_8019def4(ObjInstance *param_1,uint *param_2) { //8019DEF4
  float fVar1;
  int iVar2;
  short sVar3;
  ModelInstance *mInst;
  ObjState_Player *state;
  double dVar4;
  double dVar5;
  double dVar6;
  vec3s vStack_84;
  vec3f vStack_7c;
  vec3f vStack_70;
  float fStack_64;
  undefined4 local_60;
  uint uStack_5c;
  
  _savefpr_24();
  state = (ObjState_Player *)param_1->state;
  if (*(char *)((int)param_2 + 0x272) != '\0') {
    state->field_0x8a5 = 1;
    if ((param_1->animId == PTR_DAT_8030e404._0_2_) || (param_1->animId == PTR_DAT_8030e40c._0_2_))
    {
      DAT_80399c4c = 8;
    }
    else {
      DAT_80399c4c = 9;
    }
    *(undefined2 *)(param_2 + 0x9c) = 0xc;
    param_2[0xbf] = (uint)&LAB_801a02b8;
  }
  iVar2 = FUN_8019d94c((int)param_1,param_2);
  if ((iVar2 != 0) || ((25.0 < (float)param_2[0x6d] && ((float)param_2[0x6b] < 120.0))))
  goto LAB_8019e8c0;
  (param_1->vel).y = 0.0;
  dVar5 = (double)((float)param_2[0xa1] / 60.0);
  if (dVar5 < 0.0) {
    dVar5 = -dVar5;
  }
  if (0.1000000014901161 <= dVar5) {
    if (1.0 < dVar5) {
      dVar5 = 1.0;
    }
  }
  else {
    dVar5 = 0.1000000014901161;
  }
  mInst = (ModelInstance *)param_1->modelInstances->mtxs[(char)param_1->curModel + -3];
  dVar4 = 0.0;
  dVar6 = (double)(float)param_2[0xa6];
  DAT_80399c4e = DAT_80399c4c;
  if ((param_2[0xc2] & 1) != 0) {
    audioTryStartSfx((int *)param_1,8,0x100,0x7f,"fox.c",0x256c);
  }
  if ((short)DAT_80399c4c < 10) {
    if ((short)DAT_80399c4c < 6) {
      if (3 < (short)DAT_80399c4c) {
        if ((float)param_2[0xa1] <= 5.0) {
          if (-5.0 <= (float)param_2[0xa1]) {
            if (((param_2[0xc4] & 0x100) != 0) && ('\x03' < (char)state->field_0x3cc))
            goto LAB_8019e8c0;
            goto LAB_8019e6a0;
          }
          FUN_80086488(0.0,(int)param_1);
        }
        else {
          FUN_80086488(0.0,(int)param_1);
        }
      }
LAB_8019e288:
      if ((param_2[0xc2] & 0x80) != 0) {
        audioTryStartSfx((int *)param_1,8,0x101,0x7f,"fox.c",0x25c6);
      }
      if (((param_2[0xc4] & 0x100) != 0) && ('\x03' < (char)state->field_0x3cc)) goto LAB_8019e8c0;
      if (param_1->animTimer == 1.0) {
        if (-5.0 <= (float)param_2[0xa1]) {
          state->field_0x3cc = state->field_0x3cc + '\x01';
          state->field_0x3ce = 1;
          dVar6 = 0.0;
          if ((short)DAT_80399c4c < 2) {
            DAT_80399c4c = DAT_80399c4c ^ 1;
            dVar4 = 0.0;
          }
          *(float *)&state->field_0x3e0 = (param_1->pos).pos.y + *(float *)&state->field_0x3e8;
          uStack_5c = (int)(char)state->field_0x3cc ^ 0x80000000;
          local_60 = 0x43300000;
          *(float *)&state->field_0x3dc =
               (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0) *
               *(float *)&state->field_0x3d8 + *(float *)&state->field_0x3d4;
          (param_1->pos).pos.y = *(float *)&state->field_0x3e0;
        }
        else {
          state->field_0x3ce = 0;
          dVar6 = -(double)(float)(dVar5 * 0.009999999776482582 + 0.02500000037252903);
          if ((short)DAT_80399c4c < 2) {
            DAT_80399c4c = DAT_80399c4c + 2;
            dVar4 = 0.9900000095367432;
          }
        }
      }
      if (param_1->animTimer == 0.0) {
        if ((float)param_2[0xa1] <= 5.0) {
          if (-5.0 <= (float)param_2[0xa1]) {
            sVar3 = FUN_800873d4((int)param_1);
            if (sVar3 != 0) goto LAB_8019e61c;
            dVar4 = 0.0;
            dVar6 = 0.009999999776482582;
            if (((DAT_80399c4c & 1) == 0) || (DAT_80399c4c == 5)) {
              if (((DAT_80399c4c & 1) == 0) && (DAT_80399c4c != 4)) {
                DAT_80399c4c = 4;
              }
            }
            else {
              DAT_80399c4c = 5;
            }
          }
          else {
            state->field_0x3cc = state->field_0x3cc + -1;
            state->field_0x3ce = 0;
            if ('\0' < (char)state->field_0x3cc) {
              dVar4 = 0.9900000095367432;
              dVar6 = -(double)(float)(dVar5 * 0.009999999776482582 + 0.02500000037252903);
              if ((DAT_80399c4c & 1) == 0) {
                DAT_80399c4c = 3;
              }
              else {
                DAT_80399c4c = 2;
              }
              uStack_5c = (int)(char)state->field_0x3cc ^ 0x80000000;
              local_60 = 0x43300000;
              *(float *)&state->field_0x3dc =
                   (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0) *
                   *(float *)&state->field_0x3d8 + *(float *)&state->field_0x3d4;
              fVar1 = (param_1->pos).pos.y - *(float *)&state->field_0x3e8;
              *(float *)&state->field_0x3e0 = fVar1;
              (param_1->pos).pos.y = fVar1;
              goto LAB_8019e61c;
            }
            dVar4 = 0.0;
            dVar6 = 0.01600000075995922;
            if ((DAT_80399c4c & 1) == 0) {
              DAT_80399c4c = 10;
            }
            else {
              DAT_80399c4c = 0xb;
            }
                    /* {@symbol 801539f0} */
            (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0x1e,0xff);
            (param_1->pos).pos.y = *(float *)&state->field_0x3d4;
          }
          goto LAB_8019e6a0;
        }
        state->field_0x3ce = 1;
        if ((char)state->field_0x3cd + -3 <= (int)(char)state->field_0x3cc) {
          dVar4 = 0.0;
          dVar6 = 0.01099999994039536;
          if ((DAT_80399c4c & 1) == 0) {
            DAT_80399c4c = 6;
          }
          else {
            DAT_80399c4c = 7;
          }
          FLOAT_80399c50 = (param_1->pos).pos.y;
          FLOAT_80399c54 = *(float *)&state->field_0x3d0 + DAT_80395740;
                    /* {@symbol 801539f0} */
          (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0x1e,0xff);
          goto LAB_8019e6a0;
        }
        dVar4 = 0.0;
        dVar6 = (double)(float)(dVar5 * 0.01200000010430813 + 0.02500000037252903);
        if (1 < (short)DAT_80399c4c) {
          if ((DAT_80399c4c & 1) == 0) {
            DAT_80399c4c = 0;
          }
          else {
            DAT_80399c4c = 1;
          }
        }
      }
LAB_8019e61c:
      if (0.0 <= dVar6) {
        if (0.0 < dVar6) {
          dVar6 = (double)(float)(dVar5 * 0.01200000010430813 + 0.02500000037252903);
        }
      }
      else {
        dVar6 = -(double)(float)(dVar5 * 0.009999999776482582 + 0.02500000037252903);
      }
      if (state->field_0x3ce == '\0') {
        (param_1->pos).pos.y =
             (1.0 - param_1->animTimer) *
             (*(float *)&state->field_0x3dc - *(float *)&state->field_0x3e0) +
             *(float *)&state->field_0x3e0;
      }
      else {
        (param_1->pos).pos.y =
             param_1->animTimer * (*(float *)&state->field_0x3dc - *(float *)&state->field_0x3e0) +
             *(float *)&state->field_0x3e0;
      }
    }
    else {
      if (7 < (short)DAT_80399c4c) goto LAB_8019e0a4;
      if ((param_2[0xc2] & 0x80) != 0) {
        iVar2 = randInt(10,0xe);
        audioTryStartSfx((int *)param_1,8,*(ushort *)(state->field927_0x3b8 + iVar2 * 2),0x7f,
                         "fox.c",0x258d);
      }
      if (*(char *)((int)param_2 + 0x33a) == '\0') {
        objAnimFn_8008045c(0.0,(double)(param_1->pos).scale,mInst,0,0,&vStack_70,&vStack_84);
        objAnimFn_8008045c(1.0,(double)(param_1->pos).scale,mInst,0,0,&vStack_7c,&vStack_84);
        (param_1->pos).pos.y =
             param_1->animTimer *
             ((FLOAT_80399c54 - (vStack_7c.y - vStack_70.y)) - (FLOAT_80399c50 + vStack_70.y)) +
             FLOAT_80399c50;
      }
      else {
        (param_1->pos).pos.y = *(float *)&state->field_0x3d0;
      }
LAB_8019e1bc:
      if (*(char *)((int)param_2 + 0x33a) != '\0') {
        (param_1->prevPos).x = state->field1969_0x7ec;
        (param_1->prevPos).z = state->field1971_0x7f4;
        multVectorByObjMtx2((double)(param_1->prevPos).x,0.0,(double)(param_1->prevPos).z,
                            &(param_1->pos).pos.x,&fStack_64,&(param_1->pos).pos.z,
                            (int)param_1->pMatrix);
        objFn_8019680c(param_1,state);
        Object_ObjAnimSetMove(0.0,param_1,(int)*(short *)state->field932_0x3c0,1);
        goto LAB_8019e8c0;
      }
    }
  }
  else {
    if (0xd < (short)DAT_80399c4c) goto LAB_8019e288;
    if ((short)DAT_80399c4c < 0xc) goto LAB_8019e1bc;
LAB_8019e0a4:
    (param_1->pos).pos.y = *(float *)&state->field_0x3dc;
    param_1->animVal_a2 = -1;
    state->field_0x3ce = 0;
    *(undefined4 *)&state->field_0x3e0 = *(undefined4 *)&state->field_0x3dc;
    dVar4 = 0.0;
    dVar6 = 0.0;
    if ((DAT_80399c4c & 1) == 0) {
      DAT_80399c4c = 0;
    }
    else {
      DAT_80399c4c = 1;
    }
  }
LAB_8019e6a0:
  param_2[0xa6] = (uint)(float)dVar6;
  if (((DAT_80399c4e != DAT_80399c4c) &&
      (Object_ObjAnimSetMove(dVar4,param_1,(int)(short)(&DAT_8030e3f4)[(short)DAT_80399c4c],1),
      (short)DAT_80399c4c < 2)) && (state->field_0x3cf == '\0')) {
    objAnimFn_8008045c(0.0,(double)(param_1->pos).scale,mInst,0,0,&vStack_70,&vStack_84);
    objAnimFn_8008045c(1.0,(double)(param_1->pos).scale,mInst,0,0,&vStack_7c,&vStack_84);
    *(float *)&state->field_0x3e8 = vStack_7c.y - vStack_70.y;
    state->field_0x3cf = 1;
  }
  dVar4 = (double)(param_1->pos).pos.x;
  dVar5 = (double)(param_1->pos).pos.z;
  if ((short)DAT_80399c4c < 8) {
    if ((short)DAT_80399c4c < 4) {
      if ((short)DAT_80399c4c < 0) {
LAB_8019e878:
        dVar6 = (double)(param_1->pos).pos.y;
      }
      else {
        uStack_5c = (int)(char)state->field_0x3cc + 1U ^ 0x80000000;
        local_60 = 0x43300000;
        dVar6 = (double)(param_1->animTimer *
                         (((float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0) *
                           *(float *)&state->field_0x3d8 + *(float *)&state->field_0x3d4) -
                         (param_1->pos).pos.y) + (param_1->pos).pos.y);
      }
    }
    else {
      if ((short)DAT_80399c4c < 6) goto LAB_8019e878;
      dVar4 = (double)(param_1->animTimer * (state->field1969_0x7ec - (param_1->pos).pos.x) +
                      (param_1->pos).pos.x);
      dVar6 = (double)(param_1->animTimer * (*(float *)&state->field_0x3d0 - (param_1->pos).pos.y) +
                      (param_1->pos).pos.y);
      dVar5 = (double)(param_1->animTimer * (state->field1971_0x7f4 - (param_1->pos).pos.z) +
                      (param_1->pos).pos.z);
    }
  }
  else {
    if ((0xb < (short)DAT_80399c4c) || ((short)DAT_80399c4c < 10)) goto LAB_8019e878;
    dVar4 = (double)(param_1->animTimer * (state->field1969_0x7ec - (param_1->pos).pos.x) +
                    (param_1->pos).pos.x);
    dVar6 = (double)((1.0 - param_1->animTimer) *
                     (*(float *)&state->field_0x3dc - (param_1->pos).pos.y) + (param_1->pos).pos.y);
    dVar5 = (double)(param_1->animTimer * (state->field1971_0x7f4 - (param_1->pos).pos.z) +
                    (param_1->pos).pos.z);
  }
                    /* {@symbol 80153dd4} */
  (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar4,dVar6,dVar5);
  FUN_800b26dc(dVar4,dVar6,dVar5,(int)param_1);
  objFn_8019680c(param_1,state);
LAB_8019e8c0:
  _restfpr_24();
  return;
}


void FUN_8019e8dc(double param_1,ObjInstance *param_2,uint *param_3) { //8019E8DC
  word wVar1;
  int iVar2;
  ObjState_Player *state;
  double dVar3;
  double dVar4;
  double dVar5;
  float fStack_44;
  
  _savefpr_26();
  state = (ObjState_Player *)param_2->state;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    FLOAT_80399cb0 = 0.0;
    Object_ObjAnimSetMove(0.0,param_2,0x35,1);
    param_3[0xa6] = (uint)0.025;
    *(float *)&state->field_0x3e8 = (param_2->pos).pos.y;
    (param_2->pos).pos.y = state->field1970_0x7f0;
    objFn_8019680c(param_2,state);
    *(undefined2 *)(param_3 + 0x9c) = 0xc;
  }
  if (((*(byte *)(param_3 + 0x98) & 0x10) == 0) && (5.0 < (float)param_3[0x6d])) goto LAB_8019ece0;
  *(undefined *)((int)param_3 + 0x25b) = 2;
  *param_3 = *param_3 | 0x200000;
  wVar1 = param_2->animId;
  if (wVar1 == 0x36) {
LAB_8019e9e0:
    dVar3 = (double)(-FLOAT_80399cb0 * 10.0);
    if ((param_3[0xc2] & 1) != 0) {
      audioTryStartSfx((int *)param_2,8,0xff,0x7f,"fox.c",0x26ed);
    }
    dVar4 = (double)((param_2->pos).pos.y - (*(float *)&state->field_0x3d4 + 32.0));
    if (dVar4 < 0.0) {
      dVar4 = 0.0;
    }
    if (dVar3 <= dVar4) {
      if (-3.0 < (param_2->vel).y) {
        (param_2->vel).y = -((float)param_1 * 0.05 - (param_2->vel).y);
      }
      if ((param_2->vel).y < -3.0) {
        (param_2->vel).y = -3.0;
      }
      if ((param_2->vel).y < FLOAT_80399cb0) {
        FLOAT_80399cb0 = (param_2->vel).y;
      }
    }
    else {
      dVar3 = sqrt((double)(float)((double)(((FLOAT_80399cb0 * FLOAT_80399cb0) /
                                            (float)(dVar3 * 2.0)) * 2.0) * dVar4));
      (param_2->vel).y = (float)-dVar3;
      if (-0.01 <= (param_2->vel).y) {
        Object_ObjAnimSetMove(0.0,param_2,0x37,1);
                    /* {@symbol 801539f0} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0,0xff);
        param_3[0xa6] = (uint)0.02;
        *(float *)&state->field_0x3e8 = (param_2->pos).pos.y;
        (param_2->pos).pos.y = *(float *)&state->field_0x3d4;
        objFn_8019680c(param_2,state);
        (param_2->vel).y = 0.0;
      }
    }
  }
  else if ((short)wVar1 < 0x36) {
    if (0x34 < (short)wVar1) {
      if (*(char *)((int)param_3 + 0x33a) != '\0') {
        Object_ObjAnimSetMove(0.0,param_2,0x36,0);
        param_3[0xa6] = (uint)0.025;
      }
      goto LAB_8019e9e0;
    }
  }
  else if ((short)wVar1 < 0x38) {
    if ((param_3[0xc2] & 1) != 0) {
      iVar2 = FUN_8008820c((int)*(char *)(param_3 + 0x2f));
      audioTryStartSfx((int *)param_2,8,*(ushort *)((int)state->field2104_0x894 + iVar2 * 2),0x7f,
                       "fox.c",0x271a);
    }
    if (*(char *)((int)param_3 + 0x33a) != '\0') {
      (param_2->prevPos).x = state->field1969_0x7ec;
      (param_2->prevPos).z = state->field1971_0x7f4;
      multVectorByObjMtx2((double)(param_2->prevPos).x,0.0,(double)(param_2->prevPos).z,
                          &(param_2->pos).pos.x,&fStack_44,&(param_2->pos).pos.z,
                          (int)param_2->pMatrix);
      objFn_8019680c(param_2,state);
      Object_ObjAnimSetMove(0.0,param_2,(int)*(short *)state->field932_0x3c0,1);
      goto LAB_8019ece0;
    }
  }
  dVar4 = (double)(param_2->pos).pos.x;
  dVar3 = (double)(param_2->pos).pos.z;
  wVar1 = param_2->animId;
  if (wVar1 == 0x36) {
LAB_8019eca4:
    dVar5 = (double)(param_2->pos).pos.y;
  }
  else if ((short)wVar1 < 0x36) {
    if ((short)wVar1 < 0x35) goto LAB_8019eca4;
    dVar5 = (double)(param_2->animTimer * ((param_2->pos).pos.y - *(float *)&state->field_0x3e8) +
                    *(float *)&state->field_0x3e8);
  }
  else {
    if (0x37 < (short)wVar1) goto LAB_8019eca4;
    dVar4 = (double)(param_2->animTimer * (state->field1969_0x7ec - (param_2->pos).pos.x) +
                    (param_2->pos).pos.x);
    dVar5 = (double)((1.0 - param_2->animTimer) *
                     (*(float *)&state->field_0x3e8 - (param_2->pos).pos.y) + (param_2->pos).pos.y);
    dVar3 = (double)(param_2->animTimer * (state->field1971_0x7f4 - (param_2->pos).pos.z) +
                    (param_2->pos).pos.z);
  }
                    /* {@symbol 80153dd4} */
  (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar4,dVar5,dVar3);
  FUN_800b26dc(dVar4,dVar5,dVar3,(int)param_2);
LAB_8019ece0:
  _restfpr_26();
  return;
}


void FUN_8019ee28(ObjInstance *param_1,uint *param_2) { //8019EE28
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined4 local_64;
  undefined4 local_60;
  vec3f vStack_5c;
  vec3s vStack_50;
  undefined4 local_48;
  uint uStack_44;
  
  _savefpr_28();
  puVar6 = param_1->state;
  iVar2 = FUN_8019d94c((int)param_1,param_2);
  if (iVar2 == 0) {
    (param_1->vel).y = 0.0;
    if (*(char *)((int)param_2 + 0x272) != '\0') {
      *(undefined2 *)(param_2 + 0x9c) = 0x19;
      param_2[0xbf] = (uint)&LAB_801a02b8;
      puVar6[0x8a5] = 1;
    }
    cVar1 = puVar6[0x431];
    if (cVar1 == '\0') {
      param_2[0xa6] = (uint)0.0145;
    }
    else {
      param_2[0xa6] = (uint)0.01;
    }
    if (((float)param_2[0x6d] <= 25.0) || (120.0 <= (float)param_2[0x6b])) {
      if ((param_2[0xc2] & 1) != 0) {
        iVar2 = randInt(10,0xe);
        audioTryStartSfx((int *)param_1,8,*(ushort *)(*(int *)(puVar6 + 0x3b8) + iVar2 * 2),0x7f,
                         "fox.c",0x27b2);
      }
      if ((param_2[0xc2] & 0x80) != 0) {
        uStack_44 = randInt(-100,100);
        uStack_44 = uStack_44 ^ 0x80000000;
        local_48 = 0x43300000;
        iVar2 = randInt(0x5a,0x7f);
        audioTryStartSfx((int *)param_1,8,
                         *(ushort *)((int)&PTR_DAT_80397af8 + (char)puVar6[0x432] * 2),(byte)iVar2,
                         "fox.c",0x27b6);
      }
      if (*(char *)((int)param_2 + 0x272) == '\0') {
        if (*(char *)((int)param_2 + 0x33a) != '\0') goto LAB_8019f164;
      }
      else {
        param_2[0x9e] = (uint)0.0;
        param_2[0x9f] = (uint)0.0;
        iVar2 = getAngle();
        (param_1->pos).rotation.x = (short)iVar2;
        (param_1->pos).pos.x = *(float *)(puVar6 + 0x474);
        (param_1->pos).pos.z = *(float *)(puVar6 + 0x47c);
        if (cVar1 == '\0') {
          ppuVar5 = &PTR_DAT_80397abc;
        }
        else {
          ppuVar5 = (undefined **)&DAT_80397ac0;
        }
        uVar4 = 0x25;
        if (cVar1 != '\0') {
          uVar4 = 0x65;
        }
        uVar3 = playerMoveFn_802a71e0
                          (0.0,0.0,param_1,(int)*(short *)ppuVar5,(int)*(short *)((int)ppuVar5 + 2),
                           (float *)(puVar6 + 0x480),(float *)(puVar6 + 0x454),2,uVar4);
        *(undefined2 *)(puVar6 + 0x48c) = uVar3;
        objAnimFn_8008045c(1.0,(double)(param_1->pos).scale,
                           (ModelInstance *)
                           param_1->modelInstances->mtxs[(char)param_1->curModel + -3],0,0,
                           &vStack_5c,&vStack_50);
        *(float *)(puVar6 + 0x44c) = 0.0;
        *(float *)(puVar6 + 0x448) = vStack_5c.y;
        *(float *)(puVar6 + 0x450) = 0.0;
        local_64 = *(undefined4 *)(puVar6 + 0x434);
        local_60 = *(undefined4 *)(puVar6 + 0x438);
                    /* {@symbol 801539f0} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x59,1,1,8,&local_64,0,0);
      }
      FUN_80087380((int)param_1,0,1,*(undefined2 *)(puVar6 + 0x48c));
      dVar8 = (double)(*(float *)(puVar6 + 0x44c) * param_1->animTimer + (param_1->pos).pos.x);
      dVar9 = (double)(*(float *)(puVar6 + 0x448) * param_1->animTimer + (param_1->pos).pos.y);
      dVar7 = (double)(*(float *)(puVar6 + 0x450) * param_1->animTimer + (param_1->pos).pos.z);
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))
                ((double)(param_1->pos).pos.x,dVar9,(double)(param_1->pos).pos.z);
      FUN_800b26dc(dVar8,dVar9,dVar7,(int)param_1);
      objFn_8019680c(param_1,(ObjState_Player *)param_1->state);
    }
  }
LAB_8019f164:
  _restfpr_28();
  return;
}


void playerStateClimbWall(ObjInstance *param_1,uint *param_2) { //8019F180
  double dVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  ModelInstance *mInst;
  short sVar11;
  undefined *puVar12;
  double in_f21;
  double dVar13;
  double dVar14;
  double dVar15;
  ObjInstance *apOStack_12c [3];
  float local_120;
  float local_11c;
  undefined4 local_110;
  undefined4 local_10c;
  float local_108;
  undefined4 local_104;
  float local_f0;
  float local_ec;
  float local_e4;
  byte local_da;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  vec3s vStack_c0;
  vec3f local_b8;
  longlong local_a8;
  
  _savefpr_20();
  puVar12 = param_1->state;
  if (*(char *)((int)param_2 + 0x272) != '\0') {
    DAT_80399c4c = 0x10;
    *(undefined2 *)(param_2 + 0x9c) = 0xc;
    param_2[0xbf] = (uint)&LAB_801a02b8;
  }
  if (((25.0 < (float)param_2[0x6d]) && ((float)param_2[0x6b] < 120.0)) ||
     (iVar9 = FUN_8019d94c((int)param_1,param_2), iVar9 != 0)) goto LAB_8019fc6c;
  (param_1->vel).y = 0.0;
  mInst = (ModelInstance *)param_1->modelInstances->mtxs[(char)param_1->curModel + -3];
  dVar15 = (double)(float)param_2[0xa6];
  DAT_80399c4e = DAT_80399c4c;
  if ((short)DAT_80399c4c < 0x15) {
    if (DAT_80399c4c != 0x10) goto LAB_8019f2ec;
    if (param_1->animId == 0x66) {
      *(undefined2 *)(puVar12 + 0x48e) = 0;
      DAT_80399c4c = 0x16;
    }
    else {
      *(undefined2 *)(puVar12 + 0x48e) = 1;
      DAT_80399c4c = 0x15;
    }
    (param_1->pos).pos.y = *(float *)(puVar12 + 0x7f0);
    dVar15 = 0.006000000052154064;
LAB_8019f2b4:
    *(float *)(puVar12 + 0x44c) = 0.0;
    *(float *)(puVar12 + 0x448) = 0.0;
    *(float *)(puVar12 + 0x450) = 0.0;
    if (0.1 < (float)param_2[0xa4]) {
      in_f21 = (double)param_1->animTimer;
      param_1->animTimer = 1.0;
      goto LAB_8019f2ec;
    }
  }
  else {
    if ((short)DAT_80399c4c < 0x17) goto LAB_8019f2b4;
LAB_8019f2ec:
    if (param_1->animTimer == 1.0) {
      local_cc = -(*(float *)(puVar12 + 0x454) * 30.0 - *(float *)(puVar12 + 0x7ec));
      local_c8 = *(float *)(puVar12 + 0x7f0);
      local_c4 = -(*(float *)(puVar12 + 0x45c) * 30.0 - *(float *)(puVar12 + 0x7f4));
      iVar9 = FUN_800bb7e0(0.0,(float *)(puVar12 + 0x7ec),&local_cc,3,apOStack_12c,param_1,
                           *(byte *)((int)param_2 + 0x25d),'\x03',0xff,'\0');
      if (iVar9 == 0) {
        iVar9 = 2;
      }
      else {
        (param_1->pos).pos.x = local_cc;
        (param_1->pos).pos.z = local_c4;
        *(float *)(puVar12 + 0x434) = local_e4 * (local_ec - local_f0) + local_f0;
        *(float *)(puVar12 + 0x438) = local_e4 * (local_11c - local_120) + local_120;
        *(undefined4 *)(puVar12 + 0x454) = local_110;
        *(undefined4 *)(puVar12 + 0x458) = local_10c;
        *(float *)(puVar12 + 0x45c) = local_108;
        *(undefined4 *)(puVar12 + 0x460) = local_104;
        *(float *)(puVar12 + 0x464) = -local_108;
        *(float *)(puVar12 + 0x468) = 0.0;
        *(undefined4 *)(puVar12 + 0x46c) = local_110;
        *(float *)(puVar12 + 0x470) =
             -(local_c4 * *(float *)(puVar12 + 0x46c) +
              local_cc * *(float *)(puVar12 + 0x464) + local_c8 * *(float *)(puVar12 + 0x468));
        iVar9 = getAngle();
        (param_1->pos).rotation.x = (short)iVar9;
        if ((local_da & 4) == 0) {
          if ((local_da & 8) == 0) {
            if ((local_da & 2) == 0) {
              iVar9 = 3;
            }
            else {
              iVar9 = 2;
            }
          }
          else {
            iVar9 = 1;
          }
        }
        else {
          iVar9 = 0;
        }
      }
      if ((DAT_80399c4c != 0x15) && (DAT_80399c4c != 0x16)) {
        (param_1->pos).pos.y = *(float *)(puVar12 + 0x7f0);
      }
      if ((float)param_2[0xa4] <= 0.1) {
        (param_1->pos).pos.y = *(float *)(puVar12 + 0x7f0);
        if (*(short *)(puVar12 + 0x48e) == 0) {
          DAT_80399c4c = 0x16;
        }
        else {
          DAT_80399c4c = 0x15;
        }
        dVar15 = 0.006000000052154064;
      }
      else {
        uVar10 = getAngle();
        uVar10 = (uVar10 & 0xffff) + 0x1000 >> 0xd;
        DAT_80399c4c = (ushort)uVar10 & 7;
        DAT_80399c4e = 0xffff;
        if ((DAT_80399c4c == 4) || ((uVar10 & 7) == 0)) {
          *(ushort *)(puVar12 + 0x48e) = *(ushort *)(puVar12 + 0x48e) ^ 1;
        }
        bVar4 = false;
        bVar5 = false;
        bVar6 = false;
        bVar7 = false;
                    /* {@symbol 8019f524} */
        switch(DAT_80399c4c) {
        case 0:
          bVar5 = true;
          break;
        case 1:
          bVar5 = true;
          bVar7 = true;
          break;
        case 2:
          bVar7 = true;
          break;
        case 3:
          bVar4 = true;
          bVar7 = true;
          break;
        case 4:
          bVar4 = true;
          break;
        case 5:
          bVar4 = true;
          bVar6 = true;
          break;
        case 6:
          bVar6 = true;
          break;
        case 7:
          bVar5 = true;
          bVar6 = true;
        }
        if (*(short *)(puVar12 + 0x48e) != 0) {
          DAT_80399c4c = DAT_80399c4c + 8;
        }
        if (bVar4) {
          fVar2 = DAT_80395770;
          if (DAT_80395770 < 0.0) {
            fVar2 = -DAT_80395770;
          }
          fVar3 = DAT_80395774;
          if (DAT_80395774 < 0.0) {
            fVar3 = -DAT_80395774;
          }
          if ((*(float *)(puVar12 + 0x434) - *(float *)(puVar12 + 0x7f0) < fVar3) &&
             ((iVar9 == 0 || (iVar9 == 3)))) {
            fVar2 = ((*(float *)(puVar12 + 0x434) - *(float *)(puVar12 + 0x7f0)) - fVar2) /
                    (fVar3 - fVar2);
            if (0.0 <= fVar2) {
              if (1.0 < fVar2) {
                fVar2 = 1.0;
              }
            }
            else {
              fVar2 = 0.0;
            }
            local_a8 = (longlong)(int)(fVar2 * 16384.0);
            *(short *)(puVar12 + 0x48c) = (short)(int)(fVar2 * 16384.0);
            *(float *)(puVar12 + 0x448) = fVar2;
            goto LAB_8019fc6c;
          }
        }
        else if (bVar5) {
          fVar2 = DAT_80395778;
          if (DAT_80395778 < 0.0) {
            fVar2 = -DAT_80395778;
          }
          fVar3 = DAT_8039577c;
          if (DAT_8039577c < 0.0) {
            fVar3 = -DAT_8039577c;
          }
          if ((*(float *)(puVar12 + 0x7f0) - *(float *)(puVar12 + 0x438) < fVar3) &&
             ((iVar9 == 1 || (iVar9 == 3)))) {
            fVar2 = ((*(float *)(puVar12 + 0x7f0) - *(float *)(puVar12 + 0x438)) - fVar2) /
                    (fVar3 - fVar2);
            if (0.0 <= fVar2) {
              if (1.0 < fVar2) {
                fVar2 = 1.0;
              }
            }
            else {
              fVar2 = 0.0;
            }
            local_a8 = (longlong)(int)(fVar2 * 16384.0);
            *(short *)(puVar12 + 0x48c) = (short)(int)(fVar2 * 16384.0);
            *(float *)(puVar12 + 0x448) = fVar2;
            goto LAB_8019fc6c;
          }
        }
        objSetBlendMove(0.0,(int)param_1,
                        (int)*(short *)((int)&PTR_DAT_8030e410 + (short)DAT_80399c4c * 2),1);
        objAnimFn_8008045c(1.0,(double)(param_1->pos).scale,mInst,1,0,&local_b8,&vStack_c0);
        param_1->animVal_a2 = -1;
        *(float *)(puVar12 + 0x44c) = *(float *)(puVar12 + 0x464) * -local_b8.x;
        *(float *)(puVar12 + 0x448) = local_b8.y;
        *(float *)(puVar12 + 0x450) = *(float *)(puVar12 + 0x46c) * -local_b8.x;
        if ((!bVar4) && (!bVar5)) {
          *(float *)(puVar12 + 0x448) = 0.0;
        }
        if ((!bVar6) && (!bVar7)) {
          *(float *)(puVar12 + 0x44c) = 0.0;
          *(float *)(puVar12 + 0x450) = 0.0;
        }
        uVar10 = 0;
        if (0.0 <= local_b8.x) {
          fVar2 = -*(float *)(puVar12 + 0x464);
          fVar3 = -*(float *)(puVar12 + 0x46c);
        }
        else {
          fVar2 = *(float *)(puVar12 + 0x464);
          fVar3 = *(float *)(puVar12 + 0x46c);
        }
        dVar14 = (double)(fVar2 * 7.0);
        dVar15 = (double)(fVar3 * 7.0);
        if ((bVar4) || (bVar5)) {
          if (0.0 <= local_b8.y) {
            local_c8 = *(float *)(puVar12 + 0x7f0) + local_b8.y + 11.0;
          }
          else {
            local_c8 = (*(float *)(puVar12 + 0x7f0) + local_b8.y) - 11.0;
          }
          for (sVar11 = 0; sVar11 < 2; sVar11 = sVar11 + 1) {
            if (sVar11 == 0) {
              dVar13 = (double)*(float *)(puVar12 + 0x7ec) - dVar14;
              dVar1 = (double)*(float *)(puVar12 + 0x7f4) - dVar15;
            }
            else {
              dVar13 = (double)*(float *)(puVar12 + 0x7ec) + dVar14;
              dVar1 = (double)*(float *)(puVar12 + 0x7f4) + dVar15;
            }
            local_c4 = (float)dVar1;
            local_cc = (float)dVar13;
            local_d8 = -(*(float *)(puVar12 + 0x454) * 30.0 - local_cc);
            local_d4 = local_c8;
            local_d0 = -(*(float *)(puVar12 + 0x45c) * 30.0 - local_c4);
            iVar9 = FUN_800bb7e0(0.0,&local_cc,&local_d8,3,(ObjInstance **)0x0,param_1,
                                 *(byte *)((int)param_2 + 0x25d),'\x03',0xff,'\0');
            if (iVar9 != 0) {
              uVar10 = uVar10 | 1 << (int)sVar11;
            }
          }
        }
        else {
          uVar10 = 3;
        }
        if ((bVar6) || (bVar7)) {
          local_cc = (float)(dVar14 + (double)(*(float *)(puVar12 + 0x7ec) +
                                              *(float *)(puVar12 + 0x44c)));
          local_c4 = (float)(dVar15 + (double)(*(float *)(puVar12 + 0x7f4) +
                                              *(float *)(puVar12 + 0x450)));
          for (sVar11 = 0; sVar11 < 2; sVar11 = sVar11 + 1) {
            if (sVar11 == 0) {
              local_c8 = *(float *)(puVar12 + 0x7f0) - 11.0;
            }
            else {
              local_c8 = *(float *)(puVar12 + 0x7f0) + 11.0;
            }
            local_d8 = -(*(float *)(puVar12 + 0x454) * 30.0 - local_cc);
            local_d4 = local_c8;
            local_d0 = -(*(float *)(puVar12 + 0x45c) * 30.0 - local_c4);
            iVar9 = FUN_800bb7e0(0.0,&local_cc,&local_d8,3,(ObjInstance **)0x0,param_1,
                                 *(byte *)((int)param_2 + 0x25d),'\x03',0xff,'\0');
            if (iVar9 != 0) {
              uVar10 = uVar10 | 1 << sVar11 + 2;
            }
          }
        }
        else {
          uVar10 = uVar10 | 0xc;
        }
        dVar15 = 0.01999999955296516;
        if (uVar10 != 0xf) {
          *(float *)(puVar12 + 0x44c) = 0.0;
          *(float *)(puVar12 + 0x448) = 0.0;
          *(float *)(puVar12 + 0x450) = 0.0;
          if ((DAT_80399c4c == 4) || (DAT_80399c4c == 0)) {
LAB_8019fa6c:
            *(ushort *)(puVar12 + 0x48e) = *(ushort *)(puVar12 + 0x48e) ^ 1;
          }
          else {
            uVar10 = countLeadingZeros(0xc - (short)DAT_80399c4c);
            uVar8 = countLeadingZeros(8 - (short)DAT_80399c4c);
            if ((uVar10 | uVar8) >> 5 != 0) goto LAB_8019fa6c;
          }
          if (*(short *)(puVar12 + 0x48e) == 0) {
            DAT_80399c4c = 0x16;
          }
          else {
            DAT_80399c4c = 0x15;
          }
          if ((param_1->animId == DAT_8030e43a) || (param_1->animId == PTR_DAT_8030e43c._0_2_)) {
            DAT_80399c4e = DAT_80399c4c;
            param_1->animTimer = (float)in_f21;
          }
          dVar15 = 0.006000000052154064;
        }
      }
    }
    if ((DAT_80399c4c != 0x15) && (DAT_80399c4c != 0x16)) {
      if (0.0 <= dVar15) {
        if (0.0 < dVar15) {
          dVar15 = (double)((float)param_2[0xa4] * 0.003999997 + 0.034);
        }
      }
      else {
        dVar15 = -(double)((float)param_2[0xa4] * 0.003999997 + 0.034);
      }
    }
    if ((param_2[0xc2] & 0x80) != 0) {
      uVar10 = randInt(-100,100);
      local_a8 = CONCAT44(0x43300000,uVar10 ^ 0x80000000);
      iVar9 = randInt(0x5a,0x7f);
      audioTryStartSfx((int *)param_1,8,
                       *(ushort *)((int)&PTR_DAT_80397af8 + (char)puVar12[0x432] * 2),(byte)iVar9,
                       "fox.c",0x29aa);
    }
  }
  param_2[0xa6] = (uint)(float)dVar15;
  if (DAT_80399c4e != DAT_80399c4c) {
    Object_ObjAnimSetMove
              (0.0,param_1,(int)*(short *)((int)&PTR_DAT_8030e410 + (short)DAT_80399c4c * 2),1);
  }
  dVar13 = (double)(*(float *)(puVar12 + 0x44c) * param_1->animTimer + (param_1->pos).pos.x);
  dVar14 = (double)(*(float *)(puVar12 + 0x448) * param_1->animTimer + (param_1->pos).pos.y);
  dVar15 = (double)(*(float *)(puVar12 + 0x450) * param_1->animTimer + (param_1->pos).pos.z);
                    /* {@symbol 80153dd4} */
  (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar13,dVar14,dVar15);
  FUN_800b26dc(dVar13,dVar14,dVar15,(int)param_1);
  objFn_8019680c(param_1,(ObjState_Player *)param_1->state);
LAB_8019fc6c:
  _restfpr_20();
  return;
}


void FUN_8019fc88(ObjInstance *param_1,uint *param_2) { //8019FC88
  int iVar1;
  ObjState_Player *state;
  double dVar2;
  double dVar3;
  double dVar4;
  vec3s vStack_54;
  float fStack_4c;
  vec3f vStack_48;
  undefined4 local_38;
  uint uStack_34;
  
  _savefpr_28();
  state = (ObjState_Player *)param_1->state;
  if ((param_2[0xc2] & 0x80) != 0) {
    uStack_34 = randInt(-100,100);
    uStack_34 = uStack_34 ^ 0x80000000;
    local_38 = 0x43300000;
    iVar1 = randInt(0x5a,0x7f);
    audioTryStartSfx((int *)param_1,8,
                     *(ushort *)((int)&PTR_DAT_80397af8 + (char)state->field_0x432 * 2),(byte)iVar1,
                     "fox.c",0x29d8);
  }
  if (*(char *)((int)param_2 + 0x272) != '\0') {
                    /* {@symbol 801539f0} */
    (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0x3c,0xff);
    iVar1 = randInt(10,0xe);
    audioTryStartSfx((int *)param_1,8,*(ushort *)(state->field927_0x3b8 + iVar1 * 2),0x7f,
                     "fox.c",0x29de);
    Object_ObjAnimSetMove(0.0,param_1,(int)DAT_8030e432,1);
    FUN_80087afc((int)param_1,(int)DAT_8030e434,0);
    param_2[0xa6] = (uint)0.012;
    objAnimFn_8008045c(1.0,(double)(param_1->pos).scale,
                       (ModelInstance *)param_1->modelInstances->mtxs[(char)param_1->curModel + -3],
                       0,0,&vStack_48,&vStack_54);
    *(float *)&state->field_0x44c = *(float *)&state->field_0x454 * vStack_48.z;
    *(float *)&state->field_0x450 = *(float *)&state->field_0x45c * vStack_48.z;
    (param_1->pos).pos.y = *(float *)&state->field_0x434;
    *(undefined2 *)(param_2 + 0x9c) = 0x1b;
    param_2[0xbf] = (uint)&LAB_801a02b8;
  }
  iVar1 = FUN_8019d94c((int)param_1,param_2);
  if (iVar1 == 0) {
    (param_1->vel).y = 0.0;
    FUN_80087380((int)param_1,0,1,*(undefined2 *)&state->field_0x48c);
    if (param_1->animTimer <= 0.99) {
      dVar4 = (double)(*(float *)&state->field_0x44c * param_1->animTimer + (param_1->pos).pos.x);
      dVar3 = -(double)(*(float *)&state->field_0x448 * (1.0 - param_1->animTimer) -
                       (param_1->pos).pos.y);
      dVar2 = (double)(*(float *)&state->field_0x450 * param_1->animTimer + (param_1->pos).pos.z);
                    /* {@symbol 80153dd4} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar4,dVar3,dVar2);
      FUN_800b26dc(dVar4,dVar3,dVar2,(int)param_1);
      objFn_8019680c(param_1,state);
    }
    else {
      (param_1->prevPos).x = state->field1969_0x7ec;
      (param_1->prevPos).z = state->field1971_0x7f4;
      multVectorByObjMtx2((double)(param_1->prevPos).x,0.0,(double)(param_1->prevPos).z,
                          &(param_1->pos).pos.x,&fStack_4c,&(param_1->pos).pos.z,
                          (int)param_1->pMatrix);
      objFn_8019680c(param_1,state);
      Object_ObjAnimSetMove(0.0,param_1,(int)*(short *)state->field932_0x3c0,1);
    }
  }
  _restfpr_28();
  return;
}


void FUN_8019ff88(ObjInstance *param_1,uint *param_2) { //8019FF88
  int iVar1;
  ObjState_Player *state;
  double dVar2;
  double dVar3;
  double dVar4;
  vec3s vStack_54;
  float fStack_4c;
  vec3f vStack_48;
  undefined4 local_38;
  uint uStack_34;
  
  _savefpr_28();
  state = (ObjState_Player *)param_1->state;
  if (((*(byte *)(param_2 + 0x98) & 0x10) != 0) || ((float)param_2[0x6d] <= 5.0)) {
    if ((param_2[0xc2] & 1) != 0) {
      iVar1 = randInt(10,0xe);
      audioTryStartSfx((int *)param_1,8,*(ushort *)(state->field927_0x3b8 + iVar1 * 2),0x7f,
                       "fox.c",0x2a26);
    }
    if ((param_2[0xc2] & 0x80) != 0) {
      uStack_34 = randInt(-100,100);
      uStack_34 = uStack_34 ^ 0x80000000;
      local_38 = 0x43300000;
      iVar1 = randInt(0x5a,0x7f);
      audioTryStartSfx((int *)param_1,8,
                       *(ushort *)((int)&PTR_DAT_80397af8 + (char)state->field_0x432 * 2),
                       (byte)iVar1,"fox.c",0x2a2a);
    }
    if (*(char *)((int)param_2 + 0x272) != '\0') {
                    /* {@symbol 801539f0} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x50,0,1,0,0,0x3c,0xff);
      Object_ObjAnimSetMove(0.0,param_1,(int)DAT_8030e436,1);
      FUN_80087afc((int)param_1,(int)DAT_8030e438,0);
      param_2[0xa6] = (uint)0.015;
      objAnimFn_8008045c(1.0,(double)(param_1->pos).scale,
                         (ModelInstance *)
                         param_1->modelInstances->mtxs[(char)param_1->curModel + -3],0,0,&vStack_48,
                         &vStack_54);
      *(float *)&state->field_0x44c = *(float *)&state->field_0x454 * vStack_48.z;
      *(float *)&state->field_0x450 = *(float *)&state->field_0x45c * vStack_48.z;
      (param_1->pos).pos.y = *(float *)&state->field_0x438;
      *(undefined2 *)(param_2 + 0x9c) = 0x1c;
      param_2[0xbf] = (uint)&LAB_801a02b8;
    }
    iVar1 = FUN_8019d94c((int)param_1,param_2);
    if (iVar1 == 0) {
      (param_1->vel).y = 0.0;
      FUN_80087380((int)param_1,0,1,*(undefined2 *)&state->field_0x48c);
      if (param_1->animTimer <= 0.99) {
        dVar4 = (double)(*(float *)&state->field_0x44c * param_1->animTimer + (param_1->pos).pos.x);
        dVar3 = -(double)(*(float *)&state->field_0x448 * (1.0 - param_1->animTimer) -
                         (param_1->pos).pos.y);
        dVar2 = (double)(*(float *)&state->field_0x450 * param_1->animTimer + (param_1->pos).pos.z);
                    /* {@symbol 80153dd4} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x2c))(dVar4,dVar3,dVar2);
        FUN_800b26dc(dVar4,dVar3,dVar2,(int)param_1);
        objFn_8019680c(param_1,state);
      }
      else {
        (param_1->prevPos).x = state->field1969_0x7ec;
        (param_1->prevPos).z = state->field1971_0x7f4;
        multVectorByObjMtx2((double)(param_1->prevPos).x,0.0,(double)(param_1->prevPos).z,
                            &(param_1->pos).pos.x,&fStack_4c,&(param_1->pos).pos.z,
                            (int)param_1->pMatrix);
        objFn_8019680c(param_1,state);
        Object_ObjAnimSetMove(0.0,param_1,(int)*(short *)state->field932_0x3c0,1);
      }
    }
  }
  _restfpr_28();
  return;
}


void FUN_801a0330(int param_1,uint *param_2) { //801A0330
  float fVar1;
  uint uVar2;
  int iVar3;
  double dVar4;
  
  _savefpr_27();
  if (*(char *)((int)param_2 + 0x272) != '\0') {
    *(undefined2 *)(param_2 + 0x9c) = 0x1d;
  }
  *param_2 = *param_2 | 0x200000;
  if (*(char *)((int)param_2 + 0x272) != '\0') {
    audioSfxFn_800688bc((double)*(float *)(param_1 + 0x18),(double)*(float *)(param_1 + 0x1c),
                        (double)*(float *)(param_1 + 0x20),0xf9,0x7f,"fox.c",
                        (int *)&DAT_00002a8f);
    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
      uVar2 = randInt(-0x32,0x32);
      dVar4 = (double)(*(float *)(param_1 + 0xc) +
                      (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - 4503601774854144.0)
                      / 10.0);
      uVar2 = randInt(-0x32,0x32);
                    /* {@symbol 800db230} */
      (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                (dVar4,(double)(float)param_2[0x6f],
                 (double)(*(float *)(param_1 + 0x14) +
                         (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) -
                                4503601774854144.0) / 10.0),0,0,3);
    }
  }
  if ((((float)param_2[0x6d] <= 25.0) || (120.0 <= (float)param_2[0x6b])) &&
     ((*(byte *)(param_2 + 0x98) & 0x10) == 0)) {
    fVar1 = ((float)param_2[0x6f] - 6.0) - *(float *)(param_1 + 0x10);
    if (25.0 < fVar1) {
      fVar1 = 25.0;
    }
    *(float *)(param_1 + 0x28) = (fVar1 / 25.0) * 0.13 * timeDelta + *(float *)(param_1 + 0x28);
    *(float *)(param_1 + 0x28) = -(timeDelta * 0.1 - *(float *)(param_1 + 0x28));
    *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x28) * 0.96;
    if (1.4 < *(float *)(param_1 + 0x28)) {
      *(float *)(param_1 + 0x28) = 1.4;
    }
    *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) * 0.98;
    *(float *)(param_1 + 0x2c) = *(float *)(param_1 + 0x2c) * 0.98;
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(param_1,0x202,0,0,0xffffffff,0);
    }
  }
  _restfpr_27();
  return;
}


void FUN_801a0590(double param_1,ObjInstance *param_2,uint *param_3) { //801A0590
  float fVar1;
  short sVar2;
  ushort uVar3;
  BOOL BVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  double dVar8;
  double dVar9;
  ObjPos local_cc;
  float local_b4;
  float fStack_b0;
  float local_ac;
  Mtx44 MStack_a8;
  undefined4 local_68;
  uint uStack_64;
  double local_60;
  undefined4 local_58;
  uint uStack_54;
  double local_50;
  
  _savefpr_26();
  puVar7 = param_2->state;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    *(undefined2 *)(param_3 + 0x9c) = 0x1e;
    BVar4 = krystalIsClaw(param_2);
    if (BVar4 != FALSE) {
      backpackFn_801ec694(&DAT_80399c7c);
      *(undefined2 *)(puVar7 + 0x878) = 0xffff;
    }
    puVar7[0x8a4] = 0;
  }
  *param_3 = *param_3 | 0x200000;
  *(byte *)(param_3 + 0xd0) = *(byte *)(param_3 + 0xd0) | 2;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    iVar5 = randInt(300,600);
    *(short *)(puVar7 + 0x87c) = (short)iVar5;
    *(undefined2 *)(puVar7 + 0x886) = 0;
    Object_ObjAnimSetMove(0.0,param_2,0x412,0);
    param_3[0xa6] = (uint)0.015;
    if (*(short *)((int)param_3 + 0x26e) == 0x1d) {
      puVar7[0x67c] = 1;
    }
    else {
      puVar7[0x67c] = 0;
    }
    *(float *)(puVar7 + 0x674) = 0.0;
    *(float *)(puVar7 + 0x678) = 0.0;
    if (*(short *)((int)param_3 + 0x26e) != 0x1f) {
      *(float *)(puVar7 + 0x838) = 0.0;
    }
  }
  *(float *)(puVar7 + 0x838) = *(float *)(puVar7 + 0x838) + timeDelta;
  if ((*(float *)(puVar7 + 0x838) <= 120.0) || ((*(uint *)(puVar7 + 0x350) & 0x80000) == 0)) {
    if (((0.0 < (float)param_3[0x6d]) || ((float)param_3[0x6b] <= 20.0)) &&
       ((23.0 <= (float)param_3[0x6d] || ((*(byte *)(param_3 + 0x98) & 0x10) == 0)))) {
      dVar9 = (double)((float)param_3[0x6f] - 3.0);
      local_50 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar7 + 0x886));
      dVar8 = (double)distanceFn_80293e80((double)(((float)(local_50 - 4503599627370496.0) *
                                                   3.141593) / 32767.0));
      uStack_54 = (uint)*(ushort *)(puVar7 + 0x886);
      iVar5 = (int)(timeDelta * 128.0 +
                   (float)((double)CONCAT44(0x43300000,uStack_54) - 4503599627370496.0));
      local_60 = (double)(longlong)iVar5;
      *(short *)(puVar7 + 0x886) = (short)iVar5;
      fVar1 = (float)(dVar9 + dVar8) - (param_2->pos).pos.y;
      if (25.0 < fVar1) {
        fVar1 = 25.0;
      }
      (param_2->vel).y = (fVar1 / 25.0) * 0.13 * timeDelta + (param_2->vel).y;
      (param_2->vel).y = -(timeDelta * 0.1 - (param_2->vel).y);
      (param_2->vel).y = (param_2->vel).y * 0.96;
      if (1.4 < (param_2->vel).y) {
        (param_2->vel).y = 1.4;
      }
      if (0.1 < (float)param_3[0xa4]) {
        local_60 = (double)CONCAT44(0x43300000,(int)*(short *)((int)param_3 + 0x32a) ^ 0x80000000);
        uStack_54 = (int)(param_2->pos).rotation.x ^ 0x80000000;
        iVar5 = (int)(((float)((double)(float)(local_60 - 4503601774854144.0) * param_1) / 24.0) *
                      182.0 + (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0));
        local_50 = (double)(longlong)iVar5;
        (param_2->pos).rotation.x = (short)iVar5;
      }
      local_58 = 0x43300000;
      if (fVar1 < 25.0) {
        if ((param_3[0xc2] & 0x200) != 0) {
          local_cc.pos.x = (param_2->pos).pos.x;
          local_cc.pos.y = 0.0;
          local_cc.pos.z = (param_2->pos).pos.z;
          local_cc.rotation.x = (param_2->pos).rotation.x;
          local_cc.rotation.y = 0;
          local_cc.rotation.z = 0;
          local_cc.scale = 1.0;
          mtxSetFromObjPos(&MStack_a8,&local_cc);
          uVar6 = randInt(-0x14,0x14);
          local_60 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
          local_ac = (float)(local_60 - 4503601774854144.0) / 10.0 + 5.0;
          uStack_54 = randInt(-0x14,0x14);
          uStack_54 = uStack_54 ^ 0x80000000;
          local_58 = 0x43300000;
          local_b4 = (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0) / 10.0 +
                     2.0;
          multVectorByMatrix((double)local_ac,0.0,(double)local_b4,&MStack_a8,&local_ac,&fStack_b0,
                             &local_b4);
                    /* {@symbol 800db230} */
          (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                    ((double)local_ac,(double)(float)param_3[0x6f],(double)local_b4,0,0,3);
                    /* {@symbol 800dac04} */
          (**(code **)(*(int *)pDll_TrickyWalk + 0x10))
                    ((double)local_ac,(double)(float)param_3[0x6f],(double)local_b4,
                     0x4010000000000000);
          uVar6 = randInt(-0x14,0x14);
          local_50 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
          local_ac = (float)(local_50 - 4503601774854144.0) / 10.0 + -5.0;
          uStack_64 = randInt(-0x14,0x14);
          uStack_64 = uStack_64 ^ 0x80000000;
          local_68 = 0x43300000;
          local_b4 = (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0) / 10.0 +
                     2.0;
          multVectorByMatrix((double)local_ac,0.0,(double)local_b4,&MStack_a8,&local_ac,&fStack_b0,
                             &local_b4);
                    /* {@symbol 800db230} */
          (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                    ((double)local_ac,(double)(float)param_3[0x6f],(double)local_b4,0,0,3);
        }
        if (((-0.1 < (param_2->vel).y) && ((param_2->vel).y < 0.1)) &&
           (sVar2 = *(short *)(puVar7 + 0x87c), uVar3 = (ushort)framesThisStep,
           *(ushort *)(puVar7 + 0x87c) = sVar2 - uVar3, (short)(sVar2 - uVar3) < 1)) {
          iVar5 = randInt(0,1);
          if (iVar5 == 0) {
            uVar3 = 0x11d;
          }
          else {
            uVar3 = 0x11c;
          }
          audioSfxFn_800688bc((double)(param_2->prevPos).x,(double)(param_2->prevPos).y,
                              (double)(param_2->prevPos).z,uVar3,0x7f,"fox.c",
                              (int *)&DAT_00002b5f);
          iVar5 = randInt(300,600);
          *(short *)(puVar7 + 0x87c) = (short)iVar5;
        }
      }
      if ((0.0 <= (param_2->vel).y) || (puVar7[0x67c] == '\0')) {
        puVar7[0x67c] = 0;
        for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(param_2,0x201,0,0,0xffffffff,0);
        }
      }
      else {
        for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(param_2,0x202,0,0,0xffffffff,0);
        }
      }
      FUN_80196568(param_1,&(param_2->vel).x,&(param_2->vel).z,(int)param_2);
      (param_2->vel).x = (param_2->vel).x * 0.98;
      (param_2->vel).z = (param_2->vel).z * 0.98;
      if ((float)param_3[0xa4] < 0.05) {
        *(undefined2 *)(param_3 + 0xca) = 0;
        *(undefined2 *)((int)param_3 + 0x32a) = 0;
        param_3[0xa4] = (uint)0.0;
      }
      fVar1 = ((float)param_3[0xa4] - 0.4) / 0.6;
      if (0.0 <= fVar1) {
        if (1.0 < fVar1) {
          fVar1 = 1.0;
        }
      }
      else {
        fVar1 = 0.0;
      }
      param_3[0xa3] =
           (uint)(float)(param_1 * (double)((fVar1 * 1.6 - (float)param_3[0xa3]) / 24.0) +
                        (double)(float)param_3[0xa3]);
      if (2.3994 < (float)param_3[0xa3]) {
        param_3[0xa3] = (uint)2.3994;
      }
    }
  }
  else {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0xb,param_2,0xffffffff);
  }
  _restfpr_26();
  return;
}


void FUN_801a0d14(double param_1,ObjInstance *param_2,uint *param_3) { //801A0D14
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined auStack_10c [52];
  ObjPos local_d8;
  Mtx44 MStack_c0;
  float local_80;
  float fStack_7c;
  float local_78 [2];
  double local_70;
  undefined4 local_68;
  uint uStack_64;
  double local_60;
  
  _savefpr_24();
  puVar4 = param_2->state;
  if (*(char *)((int)param_3 + 0x272) != '\0') {
    *(undefined2 *)(param_3 + 0x9c) = 0x1f;
  }
  if ((24.0 <= (float)param_3[0x6d]) || ((*(byte *)(param_3 + 0x98) & 0x10) == 0)) {
    iVar2 = FUN_80198f5c(param_1,param_2,(int)puVar4,(int)param_3,auStack_10c,0x400);
    if (iVar2 == 5) {
      DAT_80399c4c = 0xffff;
    }
    else {
      *param_3 = *param_3 | 0x200000;
      if (*(char *)((int)param_3 + 0x272) != '\0') {
        (param_2->pos).rotation.x =
             (param_2->pos).rotation.x + *(short *)((int)param_3 + 0x32a) * 0xb6;
        *(undefined2 *)(param_3 + 0xca) = 0;
        *(undefined2 *)((int)param_3 + 0x32a) = 0;
        if (*(short *)((int)param_3 + 0x26e) != 0x1e) {
          *(float *)(puVar4 + 0x838) = 0.0;
        }
      }
      *(float *)(puVar4 + 0x838) = *(float *)(puVar4 + 0x838) + timeDelta;
      if ((*(float *)(puVar4 + 0x838) <= 120.0) || ((*(uint *)(puVar4 + 0x350) & 0x80000) == 0)) {
        dVar8 = (double)((float)param_3[0x6f] - 3.0);
        local_60 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar4 + 0x886));
        dVar5 = (double)distanceFn_80293e80((double)(((float)(local_60 - 4503599627370496.0) *
                                                     3.141593) / 32767.0));
        uStack_64 = (uint)*(ushort *)(puVar4 + 0x886);
        iVar2 = (int)(timeDelta * 128.0 +
                     (float)((double)CONCAT44(0x43300000,uStack_64) - 4503599627370496.0));
        local_70 = (double)(longlong)iVar2;
        *(short *)(puVar4 + 0x886) = (short)iVar2;
        dVar5 = (double)((float)(dVar8 + dVar5) - (param_2->pos).pos.y);
        if (25.0 < dVar5) {
          dVar5 = 25.0;
        }
        (param_2->vel).y = (float)(dVar5 / 25.0) * 0.13 * timeDelta + (param_2->vel).y;
        (param_2->vel).y = -(timeDelta * 0.1 - (param_2->vel).y);
        (param_2->vel).y = (param_2->vel).y * 0.96;
        if (1.4 < (param_2->vel).y) {
          (param_2->vel).y = 1.4;
        }
        if ((float)param_3[0xa4] < 0.05) {
          *(undefined2 *)(param_3 + 0xca) = 0;
          *(undefined2 *)((int)param_3 + 0x32a) = 0;
          param_3[0xa4] = (uint)0.0;
        }
        fVar1 = ((float)param_3[0xa4] - 0.4) / 0.6;
        if (0.0 <= fVar1) {
          if (1.0 < fVar1) {
            fVar1 = 1.0;
          }
        }
        else {
          fVar1 = 0.0;
        }
        dVar8 = (double)(fVar1 * 0.7 * 1.333);
        if (*(short *)(param_3 + 0xca) < 0x5a) {
          local_70 = (double)CONCAT44(0x43300000,(int)*(short *)((int)param_3 + 0x32a) ^ 0x80000000)
          ;
          uStack_64 = (int)(param_2->pos).rotation.x ^ 0x80000000;
          iVar2 = (int)(((float)((double)(float)(local_70 - 4503601774854144.0) * param_1) / 28.0) *
                        182.0 + (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0)
                       );
          local_60 = (double)(longlong)iVar2;
          (param_2->pos).rotation.x = (short)iVar2;
        }
        else {
          dVar8 = -dVar8;
        }
        local_68 = 0x43300000;
        FUN_80196568(param_1,&(param_2->vel).x,&(param_2->vel).z,(int)param_2);
        local_70 = (double)CONCAT44(0x43300000,(int)(param_2->pos).rotation.x ^ 0x80000000);
        dVar6 = (double)distanceFn_80293e80((double)(((float)(local_70 - 4503601774854144.0) *
                                                     3.141593) / 32767.0));
        uStack_64 = (int)(param_2->pos).rotation.x ^ 0x80000000;
        local_68 = 0x43300000;
        dVar7 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_64) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
        ;
        param_3[0x9f] =
             (uint)(float)((double)(param_2->vel).x * dVar7 -
                          (double)(float)((double)(param_2->vel).z * dVar6));
        param_3[0x9e] =
             (uint)(float)(-(double)(param_2->vel).z * dVar7 -
                          (double)(float)((double)(param_2->vel).x * dVar6));
        param_3[0xa3] =
             (uint)(float)(param_1 * (double)((float)(dVar8 - (double)(float)param_3[0xa3]) / 25.0)
                          + (double)(float)param_3[0xa3]);
        param_3[0x9e] = (uint)((float)param_3[0x9e] + (float)param_3[0xa3]);
        param_3[0x9e] = (uint)((float)param_3[0x9e] * 0.98);
        param_3[0x9f] = (uint)((float)param_3[0x9f] * 0.97);
        if (DAT_8030e4d4 <= (float)param_3[0xa3]) {
          if (param_2->animId != 0x413) {
            Object_ObjAnimSetMove(0.0,param_2,0x413,0);
          }
          objGetAnimChange((double)(float)param_3[0xa3],(int)param_2,(float *)(param_3 + 0xa6));
          if (dVar5 < 25.0) {
            local_d8.pos.x = (param_2->pos).pos.x;
            local_d8.pos.y = 0.0;
            local_d8.pos.z = (param_2->pos).pos.z;
            local_d8.rotation.x = (param_2->pos).rotation.x;
            local_d8.rotation.y = 0;
            local_d8.rotation.z = 0;
            local_d8.scale = 1.0;
            mtxSetFromObjPos(&MStack_c0,&local_d8);
            if ((param_3[0xc2] & 0x200) != 0) {
              for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
                uVar3 = randInt(-0x14,0x14);
                local_70 = (double)CONCAT44(0x43300000,uVar3 ^ 0x80000000);
                local_78[0] = (float)(local_70 - 4503601774854144.0) / 10.0 + 10.0;
                uStack_64 = randInt(-0x14,0x14);
                uStack_64 = uStack_64 ^ 0x80000000;
                local_68 = 0x43300000;
                local_80 = (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0) /
                           10.0 + -17.0;
                multVectorByMatrix((double)local_78[0],0.0,(double)local_80,&MStack_c0,local_78,
                                   &fStack_7c,&local_80);
                    /* {@symbol 800db230} */
                (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                          ((double)local_78[0],(double)(float)param_3[0x6f],(double)local_80,0,0,3);
              }
              audioSfxFn_800688bc((double)(param_2->pos).pos.x,(double)(param_2->pos).pos.y,
                                  (double)(param_2->pos).pos.z,
                                  *(ushort *)(*(int *)(puVar4 + 0x3b8) + 0x30),0x7f,"fox.c"
                                  ,(int *)&DAT_00002c48);
            }
            if ((param_3[0xc2] & 0x400) != 0) {
              for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
                uVar3 = randInt(-0x14,0x14);
                local_70 = (double)CONCAT44(0x43300000,uVar3 ^ 0x80000000);
                local_78[0] = (float)(local_70 - 4503601774854144.0) / 10.0 + -10.0;
                uStack_64 = randInt(-0x14,0x14);
                uStack_64 = uStack_64 ^ 0x80000000;
                local_68 = 0x43300000;
                local_80 = (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0) /
                           10.0 + -17.0;
                multVectorByMatrix((double)local_78[0],0.0,(double)local_80,&MStack_c0,local_78,
                                   &fStack_7c,&local_80);
                    /* {@symbol 800db230} */
                (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                          ((double)local_78[0],(double)(float)param_3[0x6f],(double)local_80,0,0,3);
              }
              audioSfxFn_800688bc((double)(param_2->pos).pos.x,(double)(param_2->pos).pos.y,
                                  (double)(param_2->pos).pos.z,
                                  *(ushort *)(*(int *)(puVar4 + 0x3b8) + 0x32),0x7f,"fox.c"
                                  ,(int *)&DAT_00002c55);
            }
          }
        }
      }
      else {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0xb,param_2,0xffffffff);
      }
    }
  }
  _restfpr_24();
  return;
}


void FUN_801a262c(ObjInstance *param_1,int param_2) { //801A262C
  float fVar1;
  float fVar2;
  int iVar3;
  undefined *puVar4;
  bool bVar5;
  bool bVar6;
  
  _savefpr_30();
  puVar4 = param_1->state;
  if (*(char *)(param_2 + 0x272) != '\0') {
    *(undefined2 *)(param_2 + 0x270) = 0x25;
  }
  FUN_801976e4((int)param_1,param_2);
  if (*(char *)(param_2 + 0x272) != '\0') {
    fVar1 = *(float *)(puVar4 + 0x680);
    bVar5 = fVar1 < 0.0;
    if (bVar5) {
      fVar1 = -fVar1;
    }
    fVar2 = *(float *)(puVar4 + 0x688);
    bVar6 = fVar2 < 0.0;
    if (bVar6) {
      fVar2 = -fVar2;
    }
    if (fVar1 <= fVar2) {
      if (bVar6) {
        puVar4[0x6ae] = 2;
      }
      else {
        puVar4[0x6ae] = 3;
      }
    }
    else if (bVar5) {
      puVar4[0x6ae] = 0;
    }
    else {
      puVar4[0x6ae] = 1;
    }
    Object_ObjAnimSetMove(0.0,param_1,0x57,0);
    *(float *)(param_2 + 0x298) = 0.016;
    iVar3 = randInt(0,3);
    audioTryStartSfx((int *)param_1,0x10,*(ushort *)(*(int *)(puVar4 + 0x3b8) + (iVar3 + 0xf) * 2),
                     0x7f,"fox.c",0x2f31);
  }
  _restfpr_30();
  return;
}


void FUN_801a379c(double param_1,ObjInstance *param_2,int param_3) { //801A379C
  word wVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  
  _savefpr_30();
  puVar3 = param_2->state;
  wVar1 = param_2->animId;
  if (wVar1 == 199) {
LAB_801a3a5c:
    Object_ObjAnimSetMove(0.0,param_2,0xc4,0);
  }
  else if ((short)wVar1 < 199) {
    if (wVar1 == 0xc5) goto LAB_801a3a5c;
    if ((short)wVar1 < 0xc5) {
      if ((short)wVar1 < 0xc4) goto LAB_801a3a5c;
      *(float *)(param_3 + 0x298) = 0.05;
      if (((param_2->vel).y < 1.0) && ((*(byte *)(param_3 + 0x260) & 0x10) != 0)) {
        audioSfxFn_800688bc((double)(param_2->prevPos).x,(double)(param_2->prevPos).y,
                            (double)(param_2->prevPos).z,
                            *(ushort *)(*(int *)(puVar3 + 0x3b8) + 0x1e6),0x7f,"fox.c",
                            (int *)&DAT_00003221);
        Object_ObjAnimSetMove(0.0,param_2,0xc6,0);
      }
      if (1.0 < (param_2->vel).x * (param_2->vel).x + (param_2->vel).z * (param_2->vel).z) {
        uVar2 = getAngle();
        iVar4 = (uVar2 & 0xffff) - (uint)(ushort)(param_2->pos).rotation.x;
        if (0x8000 < iVar4) {
          iVar4 = iVar4 + -0xffff;
        }
        if (iVar4 < -0x8000) {
          iVar4 = iVar4 + 0xffff;
        }
        (param_2->pos).rotation.x = (param_2->pos).rotation.x + (short)(iVar4 * (int)param_1 >> 3);
      }
    }
    else {
      *(float *)(param_3 + 0x298) = 0.05;
      if (*(char *)(param_3 + 0x33a) != '\0') {
        if (*(char *)(*(int *)(puVar3 + 0x34c) + 1) < '\x01') {
          FUN_80197720(param_2,0);
          goto LAB_801a3aa0;
        }
        Object_ObjAnimSetMove(0.0,param_2,200,0);
      }
      (param_2->vel).x = 0.0;
      (param_2->vel).z = 0.0;
    }
  }
  else if (wVar1 == 0x450) {
    *(float *)(param_3 + 0x298) = 0.02;
    if (((param_2->vel).y < 1.0) && ((*(byte *)(param_3 + 0x260) & 0x10) != 0)) {
      audioSfxFn_800688bc((double)(param_2->prevPos).x,(double)(param_2->prevPos).y,
                          (double)(param_2->prevPos).z,*(ushort *)(*(int *)(puVar3 + 0x3b8) + 0x1e6)
                          ,0x7f,"fox.c",(int *)&DAT_00003212);
      Object_ObjAnimSetMove(0.0,param_2,0xc6,0);
    }
    if (1.0 < (param_2->vel).x * (param_2->vel).x + (param_2->vel).z * (param_2->vel).z) {
      uVar2 = getAngle();
      iVar4 = (uVar2 & 0xffff) - (uint)(ushort)(param_2->pos).rotation.x;
      if (0x8000 < iVar4) {
        iVar4 = iVar4 + -0xffff;
      }
      if (iVar4 < -0x8000) {
        iVar4 = iVar4 + 0xffff;
      }
      (param_2->pos).rotation.x = (param_2->pos).rotation.x + (short)(iVar4 * (int)param_1 >> 3);
    }
  }
  else {
    if ((0x44f < (short)wVar1) || (200 < (short)wVar1)) goto LAB_801a3a5c;
    *(float *)(param_3 + 0x298) = 0.01;
    if (*(char *)(param_3 + 0x33a) != '\0') goto LAB_801a3aa0;
  }
  *(byte *)(param_3 + 0x340) = *(byte *)(param_3 + 0x340) | 2;
  (param_2->vel).x = (param_2->vel).x * 0.96;
  (param_2->vel).z = (param_2->vel).z * 0.96;
LAB_801a3aa0:
  _restfpr_30();
  return;
}


undefined4 FUN_801a4344(undefined8 param_1,ObjInstance *param_2,int param_3) { //801A4344
  bool bVar1;
  ObjInstance *this;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  ObjectFuncPtrs2 *size;
  undefined *puVar5;
  
  this = maybeStaff;
  puVar5 = param_2->state;
  *(undefined *)(param_3 + 0x341) = 1;
  if (*(char *)(param_3 + 0x272) == '\0') {
    if (DAT_80399c84 != '\0') {
      doRumble(20.0);
      return 0x37;
    }
    bVar1 = false;
    if (0.0 < *(float *)(param_3 + 0x298)) {
      if (((*(byte *)(param_3 + 0x34a) & 1) == 0) &&
         (*(float *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x28) <
          param_2->animTimer)) {
        audioTryStartSfx((int *)param_2,0x10,
                         *(ushort *)
                          (*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x30),0x7f,
                         "fox.c",0x339b);
        *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 1;
      }
      if (((*(byte *)(param_3 + 0x34a) & 2) == 0) &&
         (*(float *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x2c) <
          param_2->animTimer)) {
        iVar3 = randInt(0,2);
        audioTryStartSfx((int *)param_2,0x20,*(ushort *)(*(int *)(puVar5 + 0x3b8) + iVar3 * 2),0x7f,
                         "fox.c",0x33a1);
        *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 2;
      }
    }
    if (-1 < *(char *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0xd)) {
      if ((*(float *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x1c) <
           param_2->animTimer) ||
         ((*(float *)(param_3 + 0x298) < 0.0 && (param_2->animTimer < FLOAT_80399cb4)))) {
        *(byte *)(param_3 + 0x33e) = *(byte *)(param_3 + 0x33e) | 2;
      }
      if (*(float *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x14) <
          param_2->animTimer) {
        *(byte *)(param_3 + 0x33e) = *(byte *)(param_3 + 0x33e) | 1;
      }
      if (*(float *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x18) <
          param_2->animTimer) {
        *(byte *)(param_3 + 0x33e) = *(byte *)(param_3 + 0x33e) & 0xfe;
      }
      if (((*(uint *)(param_3 + 0x310) & 0x100) != 0) && ((*(byte *)(param_3 + 0x33e) & 1) != 0)) {
        *(byte *)(param_3 + 0x33e) = *(byte *)(param_3 + 0x33e) | 4;
      }
      if (((*(byte *)(param_3 + 0x33e) & 4) != 0) && ((*(byte *)(param_3 + 0x33e) & 2) != 0)) {
        puVar5[0x89d] =
             *(undefined *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0xd);
        bVar1 = true;
      }
    }
  }
  else {
    DAT_80399c84 = '\0';
    if (this->objId == 0x2f) {
      (*(code *)this->dll->ptrs2[1].field0_0x0)(this);
    }
    bVar1 = true;
    *(uint *)(puVar5 + 0x350) = *(uint *)(puVar5 + 0x350) & 0xffffffbf;
    *(undefined *)((int)&param_2->hitstate->flags_0x60 + 1) = 0;
    FUN_801976e4((int)param_2,param_3);
    *(undefined **)(param_3 + 0x2fc) = &LAB_801a4a64;
  }
  if (bVar1) {
    param_2->models = (Model *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x38);
    if ((param_2->animId != *(word *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40))
       && (param_2->animId !=
           *(word *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 2))) {
      if (*(int *)(param_3 + 0x2c8) == 0) {
        sVar2 = *(short *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 2);
      }
      else {
        sVar2 = *(short *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40);
      }
      Object_ObjAnimSetMove(0.0,param_2,(int)sVar2,0);
    }
    *(byte *)(param_3 + 0x33e) = *(byte *)(param_3 + 0x33e) & 0x10;
    *(undefined4 *)(param_3 + 0x298) =
         *(undefined4 *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0x10);
    *(float *)(param_3 + 0x27c) = 0.0;
    *(undefined *)(param_3 + 0x34a) = 0;
    if (*(int *)(param_3 + 0x2c8) == 0) {
      if (0.3 < *(float *)(param_3 + 0x290)) {
        (param_2->pos).rotation.x = (param_2->pos).rotation.x + *(short *)(param_3 + 0x32a) * 0xb6;
        *(undefined2 *)(param_3 + 0x328) = 0;
        *(undefined2 *)(param_3 + 0x32a) = 0;
      }
    }
    else {
                    /* {@symbol 8011cc08} */
      (**(code **)(*(int *)pDll11 + 0x30))(param_1,param_2,param_3,2);
    }
    if (param_2->hitstate != (HitState *)0x0) {
      *(undefined *)((int)&param_2->hitstate->flags_0x60 + 1) = 0;
    }
    if (this->objId == 0x2f) {
      (*this->dll->ptrs2[1].onLoad)(this);
      (*this->dll->ptrs2[1].update)(this);
      size = this->dll->ptrs2;
      (*size[1].getExtraSize)(this,(int)size);
    }
  }
  *(char *)((int)&param_2->hitstate->sizeX2 + 1) =
       (char)*(undefined4 *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 8);
  *(undefined *)&param_2->hitstate->flags_0x60 =
       *(undefined *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0xc);
                    /* {@symbol 8011c91c} */
  (**(code **)(*(int *)pDll11 + 0x20))(param_1,param_2,param_3,1);
  if (param_2->animTimer <= 0.99) {
    if (((0.7 < param_2->animTimer) &&
        (*(char *)(*(int *)(puVar5 + 0x3b4) + (uint)(byte)puVar5[0x89d] * 0x40 + 0xd) < '\0')) &&
       ((*(uint *)(param_3 + 0x310) & 0x100) != 0)) {
      *(undefined *)((int)&param_2->hitstate->flags_0x60 + 1) = 0;
      if (*(int *)(param_3 + 0x2c8) != 0) {
                    /* {@symbol 8011cc08} */
        (**(code **)(*(int *)pDll11 + 0x30))(param_1,param_2,param_3,2);
        return 0x3f;
      }
      if (0.3 < *(float *)(param_3 + 0x290)) {
        (param_2->pos).rotation.x = (param_2->pos).rotation.x + *(short *)(param_3 + 0x32a) * 0xb6;
        *(undefined2 *)(param_3 + 0x328) = 0;
        *(undefined2 *)(param_3 + 0x32a) = 0;
      }
      return 0x40;
    }
    uVar4 = 0;
  }
  else {
    *(undefined *)((int)&param_2->hitstate->flags_0x60 + 1) = 0;
    if (*(int *)(param_3 + 0x2c8) == 0) {
      uVar4 = 3;
    }
    else {
                    /* {@symbol 8011d1cc} */
      (**(code **)(*(int *)pDll11 + 0x48))(param_2,param_3);
      uVar4 = 0x34;
    }
  }
  return uVar4;
}


undefined4 FUN_801a4b34(ObjInstance *param_1,int param_2) { //801A4B34
  word wVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar3 = param_1->state;
  FUN_801976e4((int)param_1,param_2);
  wVar1 = param_1->animId;
  if (wVar1 == 0x448) {
    if ((0.4 < param_1->animTimer) && (puVar3[0x8a4] == '\0')) {
      audioTryStartSfx((int *)param_1,1,*(ushort *)(*(int *)(puVar3 + 0x3b8) + 8),0x7f,
                       "fox.c",0x34bf);
      puVar3[0x8a4] = 2;
      puVar3[0x8a5] = 2;
      (*(code *)maybeStaff->dll->ptrs2->setScale)(0x3fc3333340000000,maybeStaff);
    }
    if (*(char *)(param_2 + 0x33a) != '\0') {
      *(undefined4 *)(param_2 + 0x2fc) = 0;
      return 0x3c;
    }
  }
  else if (((short)wVar1 < 0x448) && (wVar1 == 0x43d)) {
    if (*(char *)(param_2 + 0x33a) != '\0') {
      *(undefined4 *)(param_2 + 0x2fc) = 0;
      return 0x3c;
    }
  }
  else {
    if (puVar3[0x8a4] == '\0') {
      Object_ObjAnimSetMove(0.0,param_1,0x448,0);
      *(float *)(param_2 + 0x298) = 0.0333;
    }
    else {
      Object_ObjAnimSetMove(0.0,param_1,0x43d,0);
      *(float *)(param_2 + 0x298) = 0.0333;
    }
    *(undefined **)(param_2 + 0x2fc) = &LAB_801a5488;
    FLOAT_80399c8c = 0.0;
    FLOAT_80399c90 = 0.0;
    *(float *)(puVar3 + 0x830) = 0.0;
    *(float *)(puVar3 + 0x82c) = 0.0;
  }
  if ((*(ushort *)(puVar3 + 0x766) & 0x200) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x3b;
  }
  return uVar2;
}


void FUN_801a4d90(double param_1,ObjInstance *param_2,int param_3) { //801A4D90
  float fVar1;
  int iVar2;
  short sVar3;
  int unaff_r27;
  ushort uVar4;
  undefined *puVar5;
  
  _savefpr_29();
  puVar5 = param_2->state;
  FUN_801976e4((int)param_2,param_3);
  if (param_2->animId == 0x43e) {
    fVar1 = *(float *)(param_3 + 0x284) / 60.0;
    if (-1.0 <= fVar1) {
      if (1.0 < fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = -1.0;
    }
    *(float *)(puVar5 + 0x830) =
         (float)((double)((fVar1 - *(float *)(puVar5 + 0x830)) * 0.1) * param_1 +
                (double)*(float *)(puVar5 + 0x830));
    fVar1 = *(float *)(param_3 + 0x288) / 60.0;
    if (-1.0 <= fVar1) {
      if (1.0 < fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = -1.0;
    }
    *(float *)(puVar5 + 0x82c) =
         (float)((double)((fVar1 - *(float *)(puVar5 + 0x82c)) * 0.1) * param_1 +
                (double)*(float *)(puVar5 + 0x82c));
    if (*(float *)(puVar5 + 0x82c) <= 0.0) {
      fVar1 = *(float *)(puVar5 + 0x82c) + 0.75;
      if (0.0 < fVar1) {
        fVar1 = 0.0;
      }
    }
    else {
      fVar1 = *(float *)(puVar5 + 0x82c) - 0.75;
      if (fVar1 < 0.0) {
        fVar1 = 0.0;
      }
    }
    (param_2->pos).rotation.x =
         (short)(int)(fVar1 * -1000.0 +
                     (float)((double)CONCAT44(0x43300000,(int)(param_2->pos).rotation.x ^ 0x80000000
                                             ) - 4503601774854144.0));
    if (*(float *)(puVar5 + 0x830) <= 0.0) {
      FUN_80087afc((int)param_2,0x440,(short)(int)(-*(float *)(puVar5 + 0x830) * 16384.0));
    }
    else {
      FUN_80087afc((int)param_2,0x441,(short)(int)(*(float *)(puVar5 + 0x830) * 16384.0));
    }
    iVar2 = objGetJoint((int)param_2,9);
    if (iVar2 != 0) {
      *(short *)(iVar2 + 2) = (short)(int)(*(float *)(puVar5 + 0x82c) * -10240.0);
    }
    *(uint *)(puVar5 + 0x350) = *(uint *)(puVar5 + 0x350) & 0xfffffbff;
    if ((DAT_80399c86 == 0x2d) &&
       (iVar2 = FUN_80196ad4((double)*(float *)(puVar5 + 0x82c),(double)*(float *)(puVar5 + 0x830),
                             param_2,(int *)(puVar5 + 0x80c),(int *)(puVar5 + 0x810)), iVar2 != 0))
    {
      *(uint *)(puVar5 + 0x350) = *(uint *)(puVar5 + 0x350) | 0x400;
    }
    if (DAT_80399c34 == '\0') {
      if ((*(ushort *)(puVar5 + 0x766) & 0xd00) != 0) {
        if ((*(ushort *)(puVar5 + 0x766) & 0x400) == 0) {
          if ((*(ushort *)(puVar5 + 0x766) & 0x800) == 0) {
            uVar4 = 0x100;
          }
          else {
            sVar3 = FUN_80173464(&DAT_80399c86);
            unaff_r27 = (int)sVar3;
            uVar4 = 0x800;
          }
        }
        else {
          sVar3 = FUN_80173448(&DAT_80399c86);
          unaff_r27 = (int)sVar3;
          uVar4 = 0x400;
        }
        if (((*(ushort *)(puVar5 + 0x766) & 0x100) != 0) || (unaff_r27 == 1)) {
          if (DAT_80399c86 != *(short *)(puVar5 + 0x878)) {
            FUN_801968a4((int *)param_2,(int)puVar5,(int)DAT_80399c86);
          }
          if (DAT_80399c86 == 0x5ce) {
            FUN_80198310((int)param_2);
            DAT_80399c34 = '\x01';
            FLOAT_80399c38 = 0.0;
            DAT_80399c36 = uVar4;
          }
          else if (DAT_80399c86 < 0x5ce) {
            if (DAT_80399c86 == 0x2d) {
              iVar2 = FUN_801a7c24((int)param_2);
              if (iVar2 < 0) {
                audioStartSfx((int **)0x0,0x16b,0x7f,0x40,"fox.c",0x358e);
              }
              else {
                *(undefined4 *)(param_3 + 0x2fc) = 0;
              }
            }
          }
          else if (DAT_80399c86 == 0x958) {
            iVar2 = FUN_801a7c24((int)param_2);
            if (iVar2 < 0) {
              audioStartSfx((int **)0x0,0x16b,0x7f,0x40,"fox.c",0x3599);
            }
            else {
              *(undefined4 *)(param_3 + 0x2fc) = 0;
            }
          }
        }
      }
    }
    else {
      FUN_80195154();
      if ((*(ushort *)(puVar5 + 0x768) & DAT_80399c36) != 0) {
        DAT_80399c34 = '\0';
        FUN_80198400();
      }
    }
  }
  else {
    Object_ObjAnimSetMove(0.0,param_2,0x43e,0);
    *(float *)(param_3 + 0x298) = 0.015;
    *(undefined **)(param_3 + 0x2fc) = &LAB_801a5488;
    DAT_80399c34 = '\0';
    FLOAT_80399c38 = 0.0;
  }
  _restfpr_29();
  return;
}


undefined4 FUN_801a5860(double param_1,ObjInstance *param_2,uint *param_3) { //801A5860
  word wVar1;
  int iVar2;
  undefined *puVar3;
  double dVar4;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  ObjInstance *apOStack_7c [15];
  float local_40;
  undefined4 local_28;
  uint uStack_24;
  undefined4 local_20;
  uint uStack_1c;
  
  puVar3 = param_2->state;
  *param_3 = *param_3 | 0x200000;
  wVar1 = param_2->animId;
  if (wVar1 == 0x80) {
    (param_2->vel).y = -(timeDelta * 0.1 - (param_2->vel).y);
    (param_2->vel).y = (param_2->vel).y * 0.98;
                    /* {@symbol 8011c91c} */
    (**(code **)(*(int *)pDll11 + 0x20))(param_1,param_2,param_3,1);
    if (*(char *)((int)param_3 + 0x33a) == '\0') {
      return 0;
    }
    (param_2->vel).y = 0.0;
    return 2;
  }
  if ((short)wVar1 < 0x80) {
    if (wVar1 == 0x7e) {
      if ((DAT_80399cc4 == '\0') && (0.35 < param_2->animTimer)) {
        audioTryStartSfx((int *)param_2,1,0x270,0x7f,"fox.c",0x3714);
        DAT_80399cc4 = '\x01';
      }
      if (*(char *)((int)param_3 + 0x33a) == '\0') {
        return 0;
      }
      if ((*(ushort *)(puVar3 + 0x764) & 0x100) == 0) {
        return 0;
      }
      audioTryStartSfx((int *)param_2,2,0x271,0x7f,"fox.c",0x371c);
      Object_ObjAnimSetMove(0.0,param_2,0x87,0);
      param_3[0xa6] = (uint)0.05;
      FLOAT_80399cc0 = 0.0;
      FLOAT_80399cc8 = 0.0;
      return 0;
    }
    if (0x7d < (short)wVar1) {
      FLOAT_80399cc0 = -(float)(param_1 * 2.0 - (double)FLOAT_80399cc0);
      if (FLOAT_80399cc0 <= 0.0) {
        return 0xd;
      }
      (param_2->vel).y = timeDelta * 0.1 + (param_2->vel).y;
      if (5.0 < (param_2->vel).y) {
        (param_2->vel).y = 5.0;
      }
      if ((param_2->pos).pos.y <= FLOAT_80399cbc) {
        return 0;
      }
      Object_ObjAnimSetMove(0.0,param_2,0x80,0);
      param_3[0xa6] = (uint)0.012;
      return 0;
    }
  }
  else {
    if (wVar1 == 0x88) {
      (param_2->vel).y = timeDelta * 0.05 + (param_2->vel).y;
      if (*(char *)((int)param_3 + 0x33a) == '\0') {
        return 0;
      }
      Object_ObjAnimSetMove(0.0,param_2,0x7f,0);
      param_3[0xa6] = (uint)0.15;
      return 0;
    }
    if (((short)wVar1 < 0x88) && (0x86 < (short)wVar1)) {
      if ((*(ushort *)(puVar3 + 0x764) & 0x100) == 0) {
        audioTryStartSfx((int *)param_2,4,0x26f,0x7f,"fox.c",0x3731);
        Object_ObjAnimSetMove(0.0,param_2,0x88,0);
        param_3[0xa6] = (uint)0.05;
        return 0;
      }
      FLOAT_80399cc0 = (float)((double)FLOAT_80399cc0 + param_1);
      FLOAT_80399cc8 = (float)((double)FLOAT_80399cc8 + param_1);
      if (FLOAT_80399cc8 <= 5.0) {
        return 0;
      }
      FUN_801a7b7c((int)param_2,0);
      FLOAT_80399cc8 = FLOAT_80399cc8 - 5.0;
      return 0;
    }
  }
  FUN_801976e4((int)param_2,(int)param_3);
  Object_ObjAnimSetMove(0.0,param_2,0x7e,0);
  param_3[0xa6] = (uint)0.012;
  FLOAT_80399cb8 = (param_2->pos).pos.y;
  (param_2->pos).rotation.x = *DAT_80399c3c;
  FUN_801ed820(DAT_80399c3c,&(param_2->pos).pos.x,&(param_2->pos).pos.z);
  local_88 = (param_2->pos).pos.x;
  local_84 = (param_2->pos).pos.y + 10.0;
  local_80 = (param_2->pos).pos.z;
  uStack_1c = (int)(param_2->pos).rotation.x ^ 0x80000000;
  local_20 = 0x43300000;
  dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_1c) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  local_94 = -(float)(dVar4 * 100.0 - (double)local_88);
  local_90 = local_84;
  uStack_24 = (int)(param_2->pos).rotation.x ^ 0x80000000;
  local_28 = 0x43300000;
  dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_24) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  local_8c = -(float)(dVar4 * 100.0 - (double)local_80);
  iVar2 = FUN_800bb7e0(0.0,&local_88,&local_94,3,apOStack_7c,param_2,1,'\x01',0xff,'\0');
  if (iVar2 == 0) {
    FLOAT_80399cbc = (param_2->pos).pos.y + 100.0;
  }
  else {
    FLOAT_80399cbc = local_40 - 30.0;
  }
  DAT_80399cc4 = 0;
  puVar3[0x8a5] = 4;
  return 0;
}


void FUN_801a5cc0(double param_1,ObjInstance *param_2,int param_3) { //801A5CC0
  word wVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  double dVar6;
  undefined4 local_44 [5];
  double local_30;
  undefined4 local_28;
  uint uStack_24;
  
  _savefpr_30();
  puVar4 = param_2->state;
  local_44[0] = 0x1b2;
  local_44[1] = 0x1b3;
  local_44[2] = 0x1b4;
  local_44[3] = 0x1b5;
  FUN_80173440(1);
  FUN_801976e4((int)param_2,param_3);
  wVar1 = param_2->animId;
  if (wVar1 == 0xb1) {
    FUN_80173438(2);
    FUN_801ed7e0((int)DAT_80399c3c,0);
    if ((*(ushort *)(puVar4 + 0x766) & 0x100) == 0) {
      if ((*(ushort *)(puVar4 + 0x766) & 0x200) != 0) {
        audioTryStartSfx((int *)param_2,1,0x272,0x7f,"fox.c",0x37bd);
        Object_ObjAnimSetMove(0.0,param_2,0xd1,0);
        *(float *)(param_3 + 0x298) = 0.0333;
      }
    }
    else {
      FLOAT_80399cd0 = 10.0;
      Object_ObjAnimSetMove(0.0,param_2,0xac,0);
      *(float *)(param_3 + 0x298) = 0.0;
    }
    goto LAB_801a6244;
  }
  if ((short)wVar1 < 0xb1) {
    if (wVar1 == 0xac) {
      FUN_80173438(2);
      FLOAT_80399cd0 = FLOAT_80399cd0 - 1.0;
      if ((*(ushort *)(puVar4 + 0x768) & 0x100) == 0) goto LAB_801a5fa0;
      FLOAT_80399c8c = (float)((double)FLOAT_80399c8c - param_1);
      if (FLOAT_80399c8c < 0.0) {
        iVar2 = randInt(0,3);
        audioTryStartSfx((int *)param_2,1,(ushort)local_44[iVar2],0x7f,"fox.c",0x37d0);
        uStack_24 = randInt(10,0x12);
        uStack_24 = uStack_24 ^ 0x80000000;
        local_28 = 0x43300000;
        FLOAT_80399c8c = (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0);
      }
      iVar2 = FUN_801eda14((int)DAT_80399c3c);
      if (iVar2 == 1) {
LAB_801a5f7c:
        FLOAT_80399cd0 = FLOAT_80399cd0 + 9.0;
      }
      else if (iVar2 < 1) {
        if (iVar2 < 0) goto LAB_801a5f7c;
        FLOAT_80399cd0 = FLOAT_80399cd0 + 11.0;
      }
      else {
        if (2 < iVar2) goto LAB_801a5f7c;
        FLOAT_80399cd0 = FLOAT_80399cd0 + 7.0;
      }
LAB_801a5fa0:
      if (FLOAT_80399cd0 <= 100.0) {
        if (FLOAT_80399cd0 < -400.0) {
          FLOAT_80399cd0 = -400.0;
        }
      }
      else {
        FLOAT_80399cd0 = 100.0;
      }
      uStack_24 = FUN_801ed804((int)DAT_80399c3c);
      uStack_24 = uStack_24 ^ 0x80000000;
      local_28 = 0x43300000;
      uVar5 = (uint)((double)FLOAT_80399cd0 * param_1 +
                    (double)(float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0));
      local_30 = (double)(longlong)(int)uVar5;
      if ((int)uVar5 < 1) {
        FLOAT_80399cd0 = 0.0;
        uVar5 = 0;
        Object_ObjAnimSetMove(0.0,param_2,0xb1,0);
        *(float *)(param_3 + 0x298) = 0.01;
      }
      else if (0x800 < (int)uVar5) {
        uVar5 = 0x800;
      }
      local_30 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
      dVar6 = (double)((float)(local_30 - 4503601774854144.0) / 2048.0);
      if (dVar6 < 0.9900000095367432) {
        uVar3 = randInt(-100,100);
        local_30 = (double)CONCAT44(0x43300000,uVar3 ^ 0x80000000);
        FUN_80086488((double)(float)(dVar6 + (double)((float)(local_30 - 4503601774854144.0) /
                                                     20000.0)),(int)param_2);
      }
      else {
        liftRockSpawnScarabs((int)DAT_80399c3c);
        audioTryStartSfx((int *)param_2,4,0x1b2,0x7f,"fox.c",0x37fe);
        Object_ObjAnimSetMove(0.0,param_2,0xd0,0);
        *(float *)(param_3 + 0x298) = 0.05;
      }
      FUN_801ed7e0((int)DAT_80399c3c,uVar5);
      goto LAB_801a6244;
    }
    if ((short)wVar1 < 0xac) {
      if (0xaa < (short)wVar1) {
        FUN_80173438(2);
        if ((DAT_80399ccc == '\0') && (0.4 < param_2->animTimer)) {
          audioTryStartSfx((int *)param_2,1,0x272,0x7f,"fox.c",0x37a7);
          DAT_80399ccc = '\x01';
        }
        if (*(char *)(param_3 + 0x33a) != '\0') {
          Object_ObjAnimSetMove(0.0,param_2,0xb1,0);
          *(float *)(param_3 + 0x298) = 0.01;
        }
        goto LAB_801a6244;
      }
    }
    else if ((short)wVar1 < 0xae) goto LAB_801a6244;
  }
  else {
    if (wVar1 == 0xd0) {
      FUN_801ed7e0((int)DAT_80399c3c,0x800);
      if (*(char *)(param_3 + 0x33a) != '\0') {
        audioTryStartSfx((int *)param_2,2,0x160,0x7f,"fox.c",0x380f);
        Object_ObjAnimSetMove(0.0,param_2,0xb2,0);
        *(float *)(param_3 + 0x298) = 0.01;
      }
      goto LAB_801a6244;
    }
    if ((short)wVar1 < 0xd0) {
      if ((short)wVar1 < 0xb3) {
        FUN_801ed7e0((int)DAT_80399c3c,0x800);
        if ((*(ushort *)(puVar4 + 0x766) & 0x200) != 0) {
          audioTryStartSfx((int *)param_2,1,0x272,0x7f,"fox.c",0x381a);
          Object_ObjAnimSetMove(0.0,param_2,0xad,0);
          *(float *)(param_3 + 0x298) = 0.0333;
        }
        goto LAB_801a6244;
      }
    }
    else if ((short)wVar1 < 0xd2) goto LAB_801a6244;
  }
  Object_ObjAnimSetMove(0.0,param_2,0xab,0);
  *(float *)(param_3 + 0x298) = 0.02857;
  FUN_801ed820(DAT_80399c3c,&(param_2->pos).pos.x,&(param_2->pos).pos.z);
  (param_2->pos).rotation.x = *DAT_80399c3c + -0x8000;
  puVar4[0x8a5] = 4;
  FLOAT_80399cd0 = 0.0;
  DAT_80399ccc = '\0';
  FLOAT_80399c8c = 0.0;
LAB_801a6244:
  _restfpr_30();
  return;
}


undefined4 playerSpellFn_801a65ac(ObjInstance *this,int param_2) { //801A65AC
  word wVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  wVar1 = this->animId;
  if (wVar1 == 0x85) {
    if ((*(uint *)(param_2 + 0x30c) & 0x100) == 0) {
      DAT_80399c78 = 0;
      FLOAT_80399c74 = 0.0;
      FUN_801c9bd4(maybeStaff,'\0',0);
      return 0xfffffff4;
    }
    FLOAT_80399cd4 = FLOAT_80399cd4 + timeDelta;
    if (60.0 < FLOAT_80399cd4) {
      FUN_801a7b7c((int)this,0);
      Object_ObjAnimSetMove(0.0,this,0x86,0);
      *(float *)(param_2 + 0x298) = 0.01;
    }
  }
  else {
    if ((short)wVar1 < 0x85) {
      if (0x83 < (short)wVar1) {
        if (*(char *)(param_2 + 0x33a) == '\0') {
          return 0;
        }
        Object_ObjAnimSetMove(0.0,this,0x85,0);
        *(float *)(param_2 + 0x298) = 0.1;
        return 0;
      }
    }
    else if ((short)wVar1 < 0x87) {
      if ((DAT_80399cd8 == '\0') && (0.1 < this->animTimer)) {
        audioTryStartSfx((int *)this,2,0x26e,0x7f,"fox.c",0x38fe);
        spawnGroundQuakeFx(&(this->pos).pos);
        DAT_80399cd8 = '\x01';
      }
      if (*(char *)(param_2 + 0x33a) == '\0') {
        return 0;
      }
      DAT_80399c78 = 0;
      FLOAT_80399c74 = 0.0;
      FUN_801c9bd4(maybeStaff,'\0',0);
      return 0xffffffff;
    }
    audioTryStartSfx((int *)this,1,0x26d,0x7f,"fox.c",0x390c);
    FUN_801976e4((int)this,param_2);
    Object_ObjAnimSetMove(0.0,this,0x84,0);
    *(float *)(param_2 + 0x298) = 0.015;
    FLOAT_80399cd4 = 0.0;
    DAT_80399cd8 = '\0';
    FUN_801c9bd4(maybeStaff,'\x01',3);
    puVar2[0x8a5] = 4;
  }
  return 0;
}


undefined4 FUN_801a693c(undefined8 param_1,ObjInstance *param_2,int param_3) { //801A693C
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = param_2->state;
  if (*(char *)(param_3 + 0x272) != '\0') {
    *(uint *)(puVar2 + 0x350) = *(uint *)(puVar2 + 0x350) | 0x800;
    *(code **)(param_3 + 0x2fc) = FUN_801a6f8c;
    Object_ObjAnimSetMove(0.0,param_2,0x97,0);
    *(float *)(param_3 + 0x298) = 0.021;
    *(undefined *)(param_3 + 0x34a) = 0;
    FUN_801976e4((int)param_2,param_3);
  }
                    /* {@symbol 8011cc08} */
  (**(code **)(*(int *)pDll11 + 0x30))(param_1,param_2,param_3,1);
                    /* {@symbol 8011c91c} */
  (**(code **)(*(int *)pDll11 + 0x20))(param_1,param_2,param_3,2);
  if ((*(uint *)(param_3 + 0x308) & 1) != 0) {
    audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 10),0x7f,
                     "fox.c",0x3989);
  }
  if ((*(byte *)(param_3 + 0x34a) & 1) == 0) {
    if (0.2 < param_2->animTimer) {
      audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 0xe),0x7f,
                       "fox.c",0x3990);
      *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 1;
    }
  }
  if (*(char *)(param_3 + 0x33a) == '\0') {
    if ((param_2->animTimer <= 0.85) || ((*(uint *)(param_3 + 0x310) & 0x100) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffc2;
    }
  }
  else {
    uVar1 = 0x55;
  }
  return uVar1;
}


undefined4 FUN_801a6acc(undefined8 param_1,ObjInstance *param_2,int param_3) { //801A6ACC
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = param_2->state;
  if (*(char *)(param_3 + 0x272) != '\0') {
    *(uint *)(puVar2 + 0x350) = *(uint *)(puVar2 + 0x350) | 0x800;
    *(code **)(param_3 + 0x2fc) = FUN_801a6f8c;
    Object_ObjAnimSetMove(0.0,param_2,0x98,0);
    *(float *)(param_3 + 0x298) = 0.021;
    *(undefined *)(param_3 + 0x34a) = 0;
    FUN_801976e4((int)param_2,param_3);
  }
                    /* {@symbol 8011cc08} */
  (**(code **)(*(int *)pDll11 + 0x30))(param_1,param_2,param_3,1);
                    /* {@symbol 8011c91c} */
  (**(code **)(*(int *)pDll11 + 0x20))(param_1,param_2,param_3,2);
  if ((*(uint *)(param_3 + 0x308) & 1) != 0) {
    audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 10),0x7f,
                     "fox.c",0x39c9);
  }
  if ((*(byte *)(param_3 + 0x34a) & 1) == 0) {
    if (0.2 < param_2->animTimer) {
      audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 0xc),0x7f,
                       "fox.c",0x39d0);
      *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 1;
    }
  }
  if (*(char *)(param_3 + 0x33a) == '\0') {
    if ((param_2->animTimer <= 0.85) || ((*(uint *)(param_3 + 0x310) & 0x100) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffc2;
    }
  }
  else {
    uVar1 = 0x55;
  }
  return uVar1;
}


undefined4 FUN_801a6c5c(undefined8 param_1,ObjInstance *param_2,int param_3) { //801A6C5C
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = param_2->state;
  if (*(char *)(param_3 + 0x272) != '\0') {
    Object_ObjAnimSetMove(0.0,param_2,0x99,0);
    *(float *)(param_3 + 0x298) = 0.025;
    FUN_801976e4((int)param_2,param_3);
  }
                    /* {@symbol 8011cc08} */
  (**(code **)(*(int *)pDll11 + 0x30))(param_1,param_2,param_3,0x10);
                    /* {@symbol 8011c91c} */
  (**(code **)(*(int *)pDll11 + 0x20))(param_1,param_2,param_3,1);
  if ((*(byte *)(param_3 + 0x34a) & 1) == 0) {
    if (0.2 < param_2->animTimer) {
      audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 0xc),0x7f,
                       "fox.c",0x3a06);
      *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 1;
    }
  }
  if ((*(byte *)(param_3 + 0x34a) & 2) == 0) {
    if (0.7 < param_2->animTimer) {
      audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 10),0x7f,
                       "fox.c",0x3a0c);
      *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 2;
    }
  }
  if (*(char *)(param_3 + 0x33a) == '\0') {
    if ((param_2->animTimer <= 0.85) || ((*(uint *)(param_3 + 0x310) & 0x100) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffc2;
    }
  }
  else {
    uVar1 = 0x55;
  }
  return uVar1;
}


undefined4 FUN_801a6de8(undefined8 param_1,ObjInstance *param_2,int param_3) { //801A6DE8
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = param_2->state;
  if (*(char *)(param_3 + 0x272) != '\0') {
    *(uint *)(puVar2 + 0x350) = *(uint *)(puVar2 + 0x350) | 0x800;
    *(code **)(param_3 + 0x2fc) = FUN_801a6f8c;
    Object_ObjAnimSetMove(0.0,param_2,0x9a,0);
    *(float *)(param_3 + 0x298) = 0.018;
    FUN_801976e4((int)param_2,param_3);
  }
                    /* {@symbol 8011cc08} */
  (**(code **)(*(int *)pDll11 + 0x30))(param_1,param_2,param_3,0x10);
                    /* {@symbol 8011c91c} */
  (**(code **)(*(int *)pDll11 + 0x20))(param_1,param_2,param_3,1);
  if ((*(byte *)(param_3 + 0x34a) & 1) == 0) {
    if (0.2 < param_2->animTimer) {
      audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 0xe),0x7f,
                       "fox.c",0x3a45);
      *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 1;
    }
  }
  if ((*(byte *)(param_3 + 0x34a) & 2) == 0) {
    if (0.7 < param_2->animTimer) {
      audioTryStartSfx((int *)param_2,0x10,*(ushort *)(*(int *)(puVar2 + 0x3b8) + 10),0x7f,
                       "fox.c",0x3a4b);
      *(byte *)(param_3 + 0x34a) = *(byte *)(param_3 + 0x34a) | 2;
    }
  }
  if (*(char *)(param_3 + 0x33a) == '\0') {
    if ((param_2->animTimer <= 0.85) || ((*(uint *)(param_3 + 0x310) & 0x100) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffc2;
    }
  }
  else {
    uVar1 = 0x55;
  }
  return uVar1;
}


void FUN_801a7b7c(int param_1,int param_2) { //801A7B7C
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xb8);
  if (*(char *)(iVar1 + 0x8b7) != '\0') {
    iVar2 = *(short *)(*(int *)(iVar1 + 0x34c) + 4) + param_2;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (*(short *)(*(int *)(iVar1 + 0x34c) + 6) < iVar2) {
      iVar2 = (int)*(short *)(*(int *)(iVar1 + 0x34c) + 6);
    }
    *(short *)(*(int *)(iVar1 + 0x34c) + 4) = (short)iVar2;
    if (0 < param_2) {
      audioStartSfx((int **)0x0,0x5eb,0x7f,0x7f,"fox.c",0x3dcc);
    }
  }
  return;
}


/* Library Function - Single Match
    foxWeaponFn_801a87b4
   
   Library: KioskDefault 0 0 */

void foxWeaponFn_801a87b4(int param1,uint param2) { //801A87B4
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  if (PTR_DAT_80397ab8._0_1_ != param2) {
    if (param2 == 0) {
      if (maybeStaff == (ObjInstance *)0x0) {
                    
        OSPanic("fox.c",0x4339,"Failed assertion weaponObject");
      }
      FUN_801c9bd4(maybeStaff,'\0',0);
      (maybeStaff->pos).flags = (maybeStaff->pos).flags | Invisible;
      *(undefined *)(iVar1 + 0x8a4) = 0;
      mainSetBits(0x96b,1);
      mainSetBits(0x961,1);
      mainSetBits(0x964,1);
      mainSetBits(0x965,1);
      mainSetBits(0x986,1);
    }
    else {
      if (maybeStaff == (ObjInstance *)0x0) {
                    
        OSPanic("fox.c",0x4347,"Failed assertion weaponObject");
      }
      *(undefined *)(iVar1 + 0x8a4) = 2;
      (maybeStaff->pos).flags = (maybeStaff->pos).flags & ~Invisible;
      mainSetBits(0x96b,0);
      mainSetBits(0x961,0);
      mainSetBits(0x964,0);
      mainSetBits(0x965,0);
      mainSetBits(0x986,0);
    }
    PTR_DAT_80397ab8._0_1_ = (byte)param2;
  }
  return;
}

