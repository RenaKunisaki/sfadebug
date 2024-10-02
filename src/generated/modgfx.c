
/* Library Function - Single Match
    modgfx_func00
   
   Library: KioskDefault 0 0 */

void modgfx_initialise(undefined4 param) { //800E0870
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x1f0; iVar1 = iVar1 + 1) {
    (&DAT_80385128)[iVar1] = 0;
  }
  return;
}


/* @description Called when DLL is unloaded */

void modgfx_release(void) { //800E08B0
  FUN_800e3de4(0,1);
  return;
}


/* Library Function - Single Match
    modgfx_func03
   
   Library: KioskDefault 0 0 */

void modgfx_func03(void) { //800E08D8
  int iVar1;
  
  FUN_800e3de4(0,1);
  for (iVar1 = 0; iVar1 < 0x1f0; iVar1 = iVar1 + 1) {
    (&DAT_80385128)[iVar1] = 0;
  }
  return;
}


int modgfx_func04(int *param1,undefined4 param_2,int param3,int param4,int param5,int param6,
                  int param7,int param8) { //800E0934
  char cVar1;
  N64Button NVar5;
  int iVar2;
  bool bVar6;
  void *pvVar3;
  Texture *pTVar4;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_7c;
  int local_78;
  int local_74;
  
  local_78 = 0;
  NVar5 = n64GetEnabledButtonsHeld(3);
  if ((NVar5 & N64_BUTTON_LEFT) == 0) {
    bVar6 = checkSomeDebugFlags_8017c4f8();
    if (bVar6) {
      iVar2 = -1;
    }
    else {
      iVar2 = FUN_800e3d78();
      if (iVar2 == -1) {
        debugPrint((char *)&PTR_DAT_802f5650);
        iVar2 = 0;
      }
      else {
        iVar8 = 0;
        if ((param1[0x15] & 0x800U) == 0) {
          iVar8 = param5 * 0x30 + param3 * 0x30;
        }
        (&DAT_80385128)[iVar2] = 0;
        pvVar3 = mmAlloc(0x140,MODGFX_COL,"modgfx:mlist");
        (&DAT_80385128)[iVar2] = pvVar3;
        pvVar3 = mmAlloc(iVar8 + 0x100,MODGFX_COL,"modgfx:mempos");
        if ((pvVar3 == (void *)0x0) || ((&DAT_80385128)[iVar2] == 0)) {
          debugPrint("warning in modgfx dll no spare memory available");
          FUN_800e3de4(0,0);
          iVar2 = -1;
        }
        else {
          *(void **)((&DAT_80385128)[iVar2] + 300) = pvVar3;
          if ((param1[0x15] & 0x800U) == 0) {
            *(void **)((&DAT_80385128)[iVar2] + 0x84) = pvVar3;
            pvVar3 = (void *)((int)pvVar3 + param5 * 0x10);
            *(void **)((&DAT_80385128)[iVar2] + 0x88) = pvVar3;
            pvVar3 = (void *)((int)pvVar3 + param5 * 0x10);
            *(void **)((&DAT_80385128)[iVar2] + 0x8c) = pvVar3;
            pvVar3 = (void *)((int)pvVar3 + param5 * 0x10);
            *(void **)((&DAT_80385128)[iVar2] + 0x78) = pvVar3;
            pvVar3 = (void *)((int)pvVar3 + param3 * 0x10);
            *(void **)((&DAT_80385128)[iVar2] + 0x7c) = pvVar3;
            pvVar3 = (void *)((int)pvVar3 + param3 * 0x10);
            *(void **)((&DAT_80385128)[iVar2] + 0x80) = pvVar3;
            pvVar3 = (void *)((int)pvVar3 + param3 * 0x10);
          }
          *(void **)((&DAT_80385128)[iVar2] + 0x90) = pvVar3;
          *(int *)((&DAT_80385128)[iVar2] + 0x94) = (int)pvVar3 + 0x80;
          local_74 = param5;
          if (param1[0x10] != 0) {
            local_74 = param5 / param1[0x10];
          }
          if ((param1[0x15] & 0x800U) == 0) {
            for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
              iVar12 = *(int *)((&DAT_80385128)[iVar2] + iVar8 * 4 + 0x84);
              iVar7 = 0;
              iVar11 = 0;
              for (iVar10 = 0; iVar10 < param5; iVar10 = iVar10 + 1) {
                if (((param1[0x15] & 0x8000000U) != 0) && (iVar10 == local_74)) {
                  iVar11 = param1[0xf];
                }
                cVar1 = (char)iVar11;
                *(char *)(iVar12 + 1) = (char)*(undefined2 *)(param6 + iVar7 * 2) - cVar1;
                *(char *)(iVar12 + 2) = (char)*(undefined2 *)(param6 + (iVar7 + 1) * 2) - cVar1;
                *(char *)(iVar12 + 3) = (char)*(undefined2 *)(param6 + (iVar7 + 2) * 2) - cVar1;
                iVar7 = iVar7 + 3;
                iVar12 = iVar12 + 0x10;
              }
            }
          }
          *(undefined4 *)((&DAT_80385128)[iVar2] + 0x98) = 0;
          *(undefined *)((&DAT_80385128)[iVar2] + 0x13f) = 0;
          if (param8 == 0) {
            if (param7 != 0) {
              pTVar4 = textureLoadAsset(param7);
              *(Texture **)((&DAT_80385128)[iVar2] + 0x98) = pTVar4;
              *(undefined *)((&DAT_80385128)[iVar2] + 0x13f) = 0;
            }
          }
          else {
            *(int *)((&DAT_80385128)[iVar2] + 0x98) = param8;
            *(undefined *)((&DAT_80385128)[iVar2] + 0x13f) = 1;
          }
          if ((param1[0x15] & 0x800U) == 0) {
            for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
              puVar9 = *(undefined2 **)((&DAT_80385128)[iVar2] + iVar8 * 4 + 0x78);
              iVar12 = 0;
              for (iVar11 = 0; iVar11 < param3; iVar11 = iVar11 + 1) {
                *puVar9 = *(undefined2 *)(param4 + iVar12 * 2);
                puVar9[1] = *(undefined2 *)(param4 + (iVar12 + 1) * 2);
                puVar9[2] = *(undefined2 *)(param4 + (iVar12 + 2) * 2);
                if (*(int *)((&DAT_80385128)[iVar2] + 0x98) != 0) {
                  puVar9[4] = (short)(int)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)*(short *)(param4 + (
                                                  iVar12 + 3) * 2) ^ 0x80000000) -
                                                  4503601774854144.0) /
                                           (float)((double)CONCAT44(0x43300000,
                                                                    (uint)*(ushort *)
                                                                           (*(int *)((&DAT_80385128)
                                                                                     [iVar2] + 0x98)
                                                                           + 10)) -
                                                  4503599627370496.0)) * 128.0);
                  puVar9[5] = (short)(int)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)*(short *)(param4 + (
                                                  iVar12 + 4) * 2) ^ 0x80000000) -
                                                  4503601774854144.0) /
                                           (float)((double)CONCAT44(0x43300000,
                                                                    (uint)*(ushort *)
                                                                           (*(int *)((&DAT_80385128)
                                                                                     [iVar2] + 0x98)
                                                                           + 0xc)) -
                                                  4503599627370496.0)) * 128.0);
                }
                *(undefined *)(puVar9 + 6) = 0xff;
                *(undefined *)((int)puVar9 + 0xd) = 0xff;
                *(undefined *)(puVar9 + 7) = 0xff;
                *(undefined *)((int)puVar9 + 0xf) = 0xff;
                puVar9 = puVar9 + 8;
                iVar12 = iVar12 + 5;
              }
            }
          }
          *(undefined *)((&DAT_80385128)[iVar2] + 0x139) = *(undefined *)((int)param1 + 0x5d);
          *(undefined4 *)((&DAT_80385128)[iVar2] + 0x114) = 0;
          *(undefined4 *)((&DAT_80385128)[iVar2] + 0x118) = 0;
          *(undefined4 *)((&DAT_80385128)[iVar2] + 0x11c) = 0;
          *(undefined4 *)((&DAT_80385128)[iVar2] + 0xa0) = 0;
          *(undefined *)((&DAT_80385128)[iVar2] + 0x13a) = 0;
          *(undefined *)((&DAT_80385128)[iVar2] + 0x13d) = 0;
          *(undefined2 *)((&DAT_80385128)[iVar2] + 0x110) = 0;
          *(undefined2 *)((&DAT_80385128)[iVar2] + 0x10e) = 0xffff;
          *(undefined *)((&DAT_80385128)[iVar2] + 0x13c) = 0;
          for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
            *(undefined2 *)((&DAT_80385128)[iVar2] + iVar8 * 2 + 0xee) =
                 *(undefined2 *)((int)param1 + iVar8 * 2 + 0x46);
          }
          *(undefined4 *)((&DAT_80385128)[iVar2] + 0x9c) = 0;
          pvVar3 = mmAlloc(*(char *)((&DAT_80385128)[iVar2] + 0x139) * 0x18,MODGFX_COL,
                           "modgfx:event");
          *(void **)((&DAT_80385128)[iVar2] + 0x9c) = pvVar3;
          if (*(int *)((&DAT_80385128)[iVar2] + 0x9c) == 0) {
            debugPrint("warning in modgfx dll no spare memory available");
            FUN_800e3de4(0,0);
            iVar2 = -1;
          }
          else {
            *(undefined4 *)((&DAT_80385128)[iVar2] + 8) = 0;
            for (iVar8 = 0; iVar8 < *(char *)((&DAT_80385128)[iVar2] + 0x139); iVar8 = iVar8 + 1) {
              if (((*(uint *)(*param1 + iVar8 * 0x18) & 0xf7fff180) == 0) &&
                 (*(short *)(*param1 + iVar8 * 0x18 + 0x14) != 0)) {
                local_78 = local_78 + *(short *)(*param1 + iVar8 * 0x18 + 0x14);
              }
            }
            if (local_78 != 0) {
              pvVar3 = mmAlloc(local_78 << 1,MODGFX_COL,"modgfx:event2");
              *(void **)((&DAT_80385128)[iVar2] + 8) = pvVar3;
            }
            local_7c = *(int *)((&DAT_80385128)[iVar2] + 8);
            for (iVar8 = 0; iVar8 < *(char *)((&DAT_80385128)[iVar2] + 0x139); iVar8 = iVar8 + 1) {
              *(undefined *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x16) =
                   *(undefined *)(*param1 + iVar8 * 0x18 + 0x16);
              *(undefined2 *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x14) =
                   *(undefined2 *)(*param1 + iVar8 * 0x18 + 0x14);
              *(undefined4 *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x10) = 0;
              *(undefined4 *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18) =
                   *(undefined4 *)(*param1 + iVar8 * 0x18);
              if (((*(uint *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18) & 0xf7fff180)
                   == 0) &&
                 (*(short *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x14) != 0)) {
                *(undefined4 *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x10) = 0;
                *(int *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x10) = local_7c;
                local_7c = local_7c +
                           *(short *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x14)
                           * 2;
                if (*(int *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x10) == 0) {
                  debugPrint("warning in modgfx dll no spare memory available");
                  FUN_800e3de4(0,0);
                  return -1;
                }
                for (iVar12 = 0;
                    iVar12 < *(short *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) +
                                       iVar8 * 0x18 + 0x14); iVar12 = iVar12 + 1) {
                  *(undefined2 *)
                   (*(int *)(*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + 0x10) +
                   iVar12 * 2) = *(undefined2 *)
                                  (*(int *)(*param1 + iVar8 * 0x18 + 0x10) + iVar12 * 2);
                }
              }
              for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
                *(undefined4 *)
                 (*(int *)((&DAT_80385128)[iVar2] + 0x9c) + iVar8 * 0x18 + iVar12 * 4 + 4) =
                     *(undefined4 *)(*param1 + iVar8 * 0x18 + iVar12 * 4 + 4);
              }
            }
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0xfc) = 0xffff;
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0xfe) =
                 *(undefined2 *)
                  ((&DAT_80385128)[iVar2] + *(short *)((&DAT_80385128)[iVar2] + 0xfc) * 2 + 0xee);
            *(int *)((&DAT_80385128)[iVar2] + 0xa4) = param1[0x15];
            *(int *)((&DAT_80385128)[iVar2] + 0x60) = param1[0xb];
            *(int *)((&DAT_80385128)[iVar2] + 100) = param1[0xc];
            *(int *)((&DAT_80385128)[iVar2] + 0x68) = param1[0xd];
            *(int *)((&DAT_80385128)[iVar2] + 0xd4) = param1[0xe];
            if ((*(uint *)((&DAT_80385128)[iVar2] + 0xa4) & 1) != 0) {
              *(int *)((&DAT_80385128)[iVar2] + 0x18) = param1[0xb];
              *(int *)((&DAT_80385128)[iVar2] + 0x1c) = param1[0xc];
              *(int *)((&DAT_80385128)[iVar2] + 0x20) = param1[0xd];
            }
            *(float *)((&DAT_80385128)[iVar2] + 0x24) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x28) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x2c) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x30) = 1.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x34) = 1.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x38) = 1.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x40) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x44) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x3c) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x50) = 1.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x48) = 1.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x4c) = 1.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x5c) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x54) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0x58) = 0.0;
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0x106) = 0;
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0x108) = 0;
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0x10a) = 0;
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0x120) = 0;
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0x122) = 0;
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0x124) = 0;
            *(float *)((&DAT_80385128)[iVar2] + 0xac) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xb0) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xb4) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xb8) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xbc) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xc0) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xc4) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 200) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xcc) = 0.0;
            *(float *)((&DAT_80385128)[iVar2] + 0xd0) = 0.0;
            *(int *)((&DAT_80385128)[iVar2] + 0x6c) = param1[8];
            *(int *)((&DAT_80385128)[iVar2] + 0x70) = param1[9];
            *(int *)((&DAT_80385128)[iVar2] + 0x74) = param1[10];
            DAT_803990f8 = DAT_803990f8 + 1;
            if (20000 < DAT_803990f8) {
              DAT_803990f8 = 0;
            }
            *(short *)((&DAT_80385128)[iVar2] + 0x10c) = DAT_803990f8;
            *(undefined *)((&DAT_80385128)[iVar2] + 0x126) = DAT_803990fa;
            *(short *)((&DAT_80385128)[iVar2] + 0xea) = (short)param3;
            *(short *)((&DAT_80385128)[iVar2] + 0xec) = (short)param5;
            *(int *)((&DAT_80385128)[iVar2] + 4) = param1[1];
            *(undefined4 *)(&DAT_80385128)[iVar2] = 0;
            *(undefined *)((&DAT_80385128)[iVar2] + 0x135) = *(undefined *)(param1 + 0x17);
            *(char *)((&DAT_80385128)[iVar2] + 0x136) = (char)param1[0x10];
            *(char *)((&DAT_80385128)[iVar2] + 0x137) = (char)param1[0xf];
            *(undefined *)((&DAT_80385128)[iVar2] + 0x138) = *(undefined *)((int)param1 + 0x59);
            *(undefined2 *)((&DAT_80385128)[iVar2] + 0xe6) = 0;
            *(undefined *)((&DAT_80385128)[iVar2] + 0x130) = 0;
            *(undefined *)((&DAT_80385128)[iVar2] + 0x13b) = 0;
            *(undefined *)((&DAT_80385128)[iVar2] + 0x13e) = 0;
            if ((param1[0x15] & 0x40000U) != 0) {
              FUN_800e4044((int)(&DAT_80385128 + iVar2),'\x01');
            }
            *(undefined *)((&DAT_80385128)[iVar2] + 0x132) = *(undefined *)((int)param1 + 0x5b);
            if (*(char *)((&DAT_80385128)[iVar2] + 0x132) == '\0') {
              *(undefined *)((&DAT_80385128)[iVar2] + 0x133) = 0;
            }
            else {
              *(char *)((&DAT_80385128)[iVar2] + 0x133) =
                   (char)(0x3c / *(byte *)((&DAT_80385128)[iVar2] + 0x132));
            }
            if (*(char *)((&DAT_80385128)[iVar2] + 0x133) == '\0') {
              *(undefined *)((&DAT_80385128)[iVar2] + 0x134) = 0;
            }
            else {
              *(char *)((&DAT_80385128)[iVar2] + 0x134) =
                   (char)(0xff / *(byte *)((&DAT_80385128)[iVar2] + 0x133));
            }
            *(undefined *)((&DAT_80385128)[iVar2] + 0x131) = 0;
            *(int *)((&DAT_80385128)[iVar2] + 0xa8) = (int)*(short *)(param1 + 0x11);
            iVar8 = isModelAnimDisabled();
            if (iVar8 == 0) {
              iVar2 = (int)*(short *)((&DAT_80385128)[iVar2] + 0x10c);
            }
            else {
              iVar2 = (int)*(char *)((&DAT_80385128)[iVar2] + 0x126);
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


/* Library Function - Single Match
    modgfx_func05
   
   Library: KioskDefault 0 0 */

void modgfx_func05(void) { //800E1764
  int iVar1;
  ObjInstance *pOVar2;
  ObjInstance *pOVar3;
  ObjPos *pOVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  N64Button NVar28;
  int iVar16;
  bool bVar29;
  uint uVar17;
  ObjDef *def;
  ObjInstance **ppOVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  bool bVar30;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  LoadedDll *dll;
  uint uVar27;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  ObjInstance *pOVar34;
  int iVar35;
  uint uVar36;
  uint uVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  ObjInstance **param1;
  double dVar42;
  int local_98;
  int local_94;
  float local_90;
  float local_8c;
  float local_88;
  short local_84;
  undefined2 local_82;
  undefined2 local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined auStack_6c [12];
  ObjInstance *local_60;
  ObjInstance *local_5c;
  ObjInstance *local_58;
  double local_50;
  
  iVar38 = 0;
  NVar28 = n64GetEnabledButtonsHeld(3);
  if ((NVar28 & N64_BUTTON_LEFT) == 0) {
    DAT_80398740 = 2;
    iVar16 = FUN_800671a4(-1);
    if ((short)iVar16 != 1) {
      DAT_803990fc = timeDelta;
      bVar29 = checkSomeDebugFlags_8017c4f8();
      if (((!bVar29) || (iVar16 = isModelAnimDisabled(), iVar16 != 0)) &&
         (iVar16 = isModelAnimDisabled(), iVar16 == 0)) {
        for (iVar16 = 0; iVar16 < 0x1f0; iVar16 = iVar16 + 1) {
          bVar29 = true;
          while (bVar29) {
            bVar29 = false;
            if (((&DAT_80385128)[iVar16] != 0) &&
               (*(short *)((&DAT_80385128)[iVar16] + 0x10c) != -1)) {
              param1 = (ObjInstance **)(&DAT_80385128)[iVar16];
              iVar40 = 0;
              *(undefined *)((int)param1 + 0x13e) = 0;
              if ((*(short *)((int)param1 + 0xfe) < 0) || (*(short *)(param1 + 0x3f) == -1)) {
                *(short *)(param1 + 0x3f) = *(short *)(param1 + 0x3f) + 1;
                if (6 < *(short *)(param1 + 0x3f)) {
                  FUN_800e3de4(*(short *)(param1 + 0x43),0);
                  break;
                }
                *(undefined2 *)((int)param1 + 0xfe) =
                     *(undefined2 *)((int)param1 + *(short *)(param1 + 0x3f) * 2 + 0xee);
                iVar40 = 1;
                FUN_800e56f8((int)param1);
              }
              else if (*(char *)(param1 + 0x4f) != '\0') {
                *(ushort *)(param1 + 0x3f) = (ushort)*(byte *)(param1 + 0x4f);
                *(undefined *)(param1 + 0x4f) = 0;
                if (6 < *(short *)(param1 + 0x3f)) {
                  FUN_800e3de4(*(short *)(param1 + 0x43),0);
                  break;
                }
                *(undefined2 *)((int)param1 + 0xfe) =
                     *(undefined2 *)((int)param1 + *(short *)(param1 + 0x3f) * 2 + 0xee);
                iVar40 = 1;
                FUN_800e56f8((int)param1);
              }
              uVar37 = 0;
              uVar36 = 0;
              FUN_800e3fc4((int)param1);
              bVar5 = false;
              for (iVar41 = 0; iVar41 < *(char *)((int)param1 + 0x139); iVar41 = iVar41 + 1) {
                iVar39 = iVar38;
                if (*(ushort *)(param1 + 0x3f) ==
                    (ushort)*(byte *)((int)&(&param1[0x27]->pos)[iVar41].pos.z + 2)) {
                  uVar22._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar22._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((((uVar22 & 0x1000) != 0) &&
                      (0.0 < *(float *)&(&param1[0x27]->pos)[iVar41].rotation.z)) &&
                     (0 < *(short *)(param1 + 0x3f))) {
                    *(undefined2 *)(param1 + 0x3f) =
                         *(undefined2 *)&(&param1[0x27]->pos)[iVar41].pos.z;
                    *(float *)&(&param1[0x27]->pos)[iVar41].rotation.z =
                         *(float *)&(&param1[0x27]->pos)[iVar41].rotation.z - 1.0;
                    *(undefined2 *)((int)param1 + 0xfe) = 0xffff;
                    break;
                  }
                  uVar17._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar17._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar17 & 0x2000) != 0) {
                    if (*(char *)((int)param1 + 0x13a) != '\0') {
                      *(undefined *)((int)param1 + 0x13a) = 0;
                      pOVar34 = param1[0x27];
                      (&pOVar34->pos)[iVar41].rotation.x = 0;
                      (&pOVar34->pos)[iVar41].rotation.y = 0;
                      pOVar34 = param1[0x27];
                      (&pOVar34->pos)[iVar41].rotation.x = 0;
                      (&pOVar34->pos)[iVar41].rotation.y = 0x20;
                      *(undefined2 *)((int)param1 + 0xfe) = 0xffff;
                      bVar29 = true;
                      bVar5 = false;
                      break;
                    }
                    if (0 < *(short *)(param1 + 0x3f)) {
                      bVar5 = true;
                      *(undefined2 *)(param1 + 0x3f) =
                           *(undefined2 *)&(&param1[0x27]->pos)[iVar41].pos.z;
                      *(undefined2 *)((int)param1 + 0xfe) = 0xffff;
                      bVar29 = true;
                      break;
                    }
                  }
                  uVar6._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar6._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar6 & 0x10000000) != 0) {
                    local_60 = param1[0x18];
                    local_5c = param1[0x19];
                    local_58 = param1[0x1a];
                    local_78 = 0.0;
                    local_74 = 0.0;
                    local_70 = 0.0;
                    local_7c = 1.0;
                    if (((uint)param1[0x29] & 1) == 0) {
                      local_84 = (param1[1]->pos).rotation.x;
                    }
                    else {
                      local_84 = *(short *)(param1 + 3);
                    }
                    local_82 = 0;
                    local_80 = 0;
                    FUN_8007a878(&local_84,(float *)&local_60);
                    if (*param1 == (ObjInstance *)0x0) {
                      if (((uint)param1[0x29] & 1) == 0) {
                        pOVar34 = (ObjInstance *)(param1[1]->prevPos).x;
                        pOVar2 = (ObjInstance *)(param1[1]->prevPos).y;
                        pOVar3 = (ObjInstance *)(param1[1]->prevPos).z;
                      }
                      else {
                        pOVar34 = param1[6];
                        pOVar2 = param1[7];
                        pOVar3 = param1[8];
                      }
                      local_58 = (ObjInstance *)((float)pOVar3 + (float)local_58);
                      local_5c = (ObjInstance *)((float)pOVar2 + (float)local_5c);
                      local_60 = (ObjInstance *)((float)pOVar34 + (float)local_60);
                      def = objAlloc(0x20,InvHit);
                      (def->pos).x = (float)local_60;
                      (def->pos).y = (float)local_5c;
                      (def->pos).z = (float)local_58;
                      pOVar34 = objInstantiateCharacter(def,5,-1,-1,(ObjInstance *)0x0);
                      *param1 = pOVar34;
                      (*param1)->flags_0xf8 = 1;
                    }
                    else if (*param1 != (ObjInstance *)0x0) {
                      if (((uint)param1[0x29] & 1) == 0) {
                        pOVar34 = (ObjInstance *)(param1[1]->prevPos).x;
                        pOVar2 = (ObjInstance *)(param1[1]->prevPos).y;
                        pOVar3 = (ObjInstance *)(param1[1]->prevPos).z;
                      }
                      else {
                        pOVar34 = param1[6];
                        pOVar2 = param1[7];
                        pOVar3 = param1[8];
                      }
                      local_58 = (ObjInstance *)((float)pOVar3 + (float)local_58);
                      local_5c = (ObjInstance *)((float)pOVar2 + (float)local_5c);
                      local_60 = (ObjInstance *)((float)pOVar34 + (float)local_60);
                      ((*param1)->prevPos).x = (float)local_60;
                      ((*param1)->prevPos).y = (float)local_5c;
                      ((*param1)->prevPos).z = (float)local_58;
                    }
                    if (((*param1 != (ObjInstance *)0x0) &&
                        (iVar35 = (*param1)->hitstate->field13_0x48, iVar35 != 0)) &&
                       (iVar1 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z,
                       local_50 = (double)(longlong)iVar1, *(short *)(iVar35 + 0x44) == iVar1)) {
                      Object_objFreeObject(*param1);
                      *param1 = (ObjInstance *)0x0;
                      pOVar4 = &param1[0x27]->pos + iVar41;
                      uVar36._0_2_ = (pOVar4->rotation).x;
                      uVar36._2_2_ = (pOVar4->rotation).y;
                      pOVar4 = &param1[0x27]->pos + iVar41;
                      (pOVar4->rotation).x = (short)((uVar36 ^ 0x10000000) >> 0x10);
                      (pOVar4->rotation).y = (short)(uVar36 ^ 0x10000000);
                      if ((0.0 <= (&param1[0x27]->pos)[iVar41].pos.x) &&
                         (param1[1] != (ObjInstance *)0x0)) {
                        iVar40 = (int)(&param1[0x27]->pos)[iVar41].pos.x;
                        local_50 = (double)(longlong)iVar40;
                    /* {@symbol 800ed30c} */
                        (**(code **)(*(int *)pDll_objfsa + 8))
                                  (param1[1],iVar40,auStack_6c,&DAT_00200001,0xffffffff,0);
                      }
                      iVar40 = (int)(&param1[0x27]->pos)[iVar41].scale;
                      local_50 = (double)(longlong)iVar40;
                      *(char *)(param1 + 0x4f) = (char)iVar40;
                      break;
                    }
                  }
                  ppOVar18 = Object_getObjects(&local_98,&local_94);
                  uVar19._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar19._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((((uVar19 & 0x20000000) == 0) || (param1[1] == (ObjInstance *)0x0)) ||
                     (*(short *)&(&param1[0x27]->pos)[iVar41].pos.z == 0)) {
                    uVar20._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                    uVar20._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                    if ((((uVar20 & 0x20000000) != 0) && (param1[1] != (ObjInstance *)0x0)) &&
                       (*(short *)&(&param1[0x27]->pos)[iVar41].pos.z == 0)) {
                      iVar38 = (int)(&param1[0x27]->pos)[iVar41].pos.x;
                      local_50 = (double)(longlong)iVar38;
                      loadLfxAction(param1[1],ppOVar18[iVar38],(ushort)iVar38);
                      pOVar4 = &param1[0x27]->pos + iVar41;
                      uVar31._0_2_ = (pOVar4->rotation).x;
                      uVar31._2_2_ = (pOVar4->rotation).y;
                      pOVar4 = &param1[0x27]->pos + iVar41;
                      (pOVar4->rotation).x = (short)((uVar31 ^ 0x20000000) >> 0x10);
                      (pOVar4->rotation).y = (short)(uVar31 ^ 0x20000000);
                    }
                  }
                  else {
                    if (*(short *)((int)param1 + 0x10e) == -1) {
                      iVar39 = (int)(&param1[0x27]->pos)[iVar41].pos.x;
                      local_50 = (double)(longlong)iVar39;
                      *(short *)((int)param1 + 0x10e) = (short)iVar39;
                    }
                    if (((uint)param1[0x29] & 1) == 0) {
                      local_60 = (ObjInstance *)((param1[1]->prevPos).x + (float)param1[0x18]);
                      local_5c = (ObjInstance *)((param1[1]->prevPos).y + (float)param1[0x19]);
                      local_58 = (ObjInstance *)((param1[1]->prevPos).z + (float)param1[0x1a]);
                    }
                    else {
                      local_60 = param1[6];
                      local_5c = param1[7];
                      local_58 = param1[8];
                    }
                    iVar39 = local_98;
                    if ((*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z == 999.0) &&
                       (param1[0x28] == (ObjInstance *)0x0)) {
                      printf("TRACE: '%s' {Line %d}","modgfx.c",0x2f4);
                      pOVar34 = (ObjInstance *)mmAlloc(0x28,LFX_COL,"modgfx:light1");
                      param1[0x28] = pOVar34;
                      iVar39 = (int)(&param1[0x27]->pos)[iVar41].scale;
                      local_50 = (double)(longlong)iVar39;
                      loadAsset_fileWithOffsetLength
                                (param1[0x28],LACTIONS.bin,(short)iVar39 * 0x28,0x28);
                      *(undefined *)((int)param1 + 0x13d) = 1;
                      iVar39 = iVar38;
                    }
                    else {
                      for (; iVar39 < local_94; iVar39 = iVar39 + 1) {
                        iVar38 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z;
                        local_50 = (double)(longlong)iVar38;
                        if ((int)(short)ppOVar18[iVar39]->objId == (int)(char)iVar38) {
                          local_90 = (ppOVar18[iVar39]->prevPos).x - (float)local_60;
                          local_8c = (ppOVar18[iVar39]->prevPos).y - (float)local_5c;
                          local_88 = (ppOVar18[iVar39]->prevPos).z - (float)local_58;
                          dVar42 = sqrt((double)(local_88 * local_88 +
                                                local_90 * local_90 + local_8c * local_8c));
                          if ((*(char *)((int)param1 + 0x13d) != '\0') ||
                             (local_50 = (double)CONCAT44(0x43300000,
                                                          (int)*(short *)&(&param1[0x27]->pos)
                                                                          [iVar41].pos.z ^
                                                          0x80000000),
                             (double)(float)(local_50 - 4503601774854144.0) <= dVar42)) {
                            if ((*(char *)((int)param1 + 0x13d) == '\x01') &&
                               (local_50 = (double)CONCAT44(0x43300000,
                                                            (int)*(short *)&(&param1[0x27]->pos)
                                                                            [iVar41].pos.z ^
                                                            0x80000000),
                               (double)(float)(local_50 - 4503601774854144.0) < dVar42)) {
                              iVar38 = (int)(&param1[0x27]->pos)[iVar41].pos.x;
                              local_50 = (double)(longlong)iVar38;
                              loadLfxAction(param1[1],ppOVar18[iVar39],(ushort)iVar38);
                              *(undefined *)((int)param1 + 0x13d) = 0;
                            }
                          }
                          else {
                            iVar38 = (int)(&param1[0x27]->pos)[iVar41].scale;
                            local_50 = (double)(longlong)iVar38;
                            loadLfxAction(param1[1],ppOVar18[iVar39],(ushort)iVar38);
                            *(undefined *)((int)param1 + 0x13d) = 1;
                          }
                          break;
                        }
                      }
                    }
                  }
                  uVar7._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar7._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar7 & 2) != 0) {
                    FUN_800e4144((int)param1,(int)(&param1[0x27]->pos + iVar41),iVar40,uVar37 & 0xff
                                );
                    uVar37 = uVar37 + 1;
                  }
                  uVar8._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar8._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar8 & 4) != 0) {
                    FUN_800e4648((int)param1,(int)(&param1[0x27]->pos + iVar41),iVar40,uVar36 & 0xff
                                );
                    uVar36 = uVar36 + 1;
                  }
                  uVar9._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar9._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar9 & 8) != 0) {
                    FUN_800e5380((int)param1,(int)(&param1[0x27]->pos + iVar41),iVar40);
                  }
                  uVar21._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar21._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar21 & 0x100) != 0) {
                    FUN_800e5308((int)param1,(int)(&param1[0x27]->pos + iVar41));
                  }
                  uVar10._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar10._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar10 & 0x80) != 0) {
                    FUN_800e49e4((int)param1,(int)(&param1[0x27]->pos + iVar41),iVar40);
                  }
                  uVar11._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar11._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar11 & 0x8000000) != 0) {
                    uVar22 = randInt(0,0xffff);
                    local_50 = (double)CONCAT44(0x43300000,uVar22 ^ 0x80000000);
                    (&param1[0x27]->pos)[iVar41].pos.x = (float)(local_50 - 4503601774854144.0);
                    FUN_800e49e4((int)param1,(int)(&param1[0x27]->pos + iVar41),iVar40);
                  }
                  uVar12._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar12._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar12 & 0x4000) != 0) {
                    FUN_800e57dc((int)param1,(int)(&param1[0x27]->pos + iVar41));
                  }
                  uVar32._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar32._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((((uVar32 & 0x10000) != 0) && (iVar38 = isModelAnimDisabled(), iVar38 == 0))
                     && (iVar40 != 0)) {
                    audioTryStartSfx((int *)param1[1],1,
                                     *(ushort *)&(&param1[0x27]->pos)[iVar41].pos.z,0x7f,
                                     "modgfx.c",0x33e);
                  }
                  uVar13._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar13._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((((uVar13 & 0x20000) != 0) && (iVar38 = isModelAnimDisabled(), iVar38 == 0))
                     && (iVar40 != 0)) {
                    iVar38 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z;
                    local_50 = (double)(longlong)iVar38;
                    bVar30 = FUN_80068b20((int)param1[1],(byte)iVar38);
                    if (bVar30) {
                      iVar38 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z;
                      local_50 = (double)(longlong)iVar38;
                      audioTryStartSfx((int *)param1[1],(byte)iVar38,
                                       *(ushort *)&(&param1[0x27]->pos)[iVar41].pos.z,0x7f,
                                       "modgfx.c",0x34a);
                    }
                  }
                  uVar33._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar33._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar33 & 0x42288000) != 0) {
                    modgfxFn_800e5988((int)param1,(uint *)(&param1[0x27]->pos + iVar41),
                                      (int)*(short *)&(&param1[0x27]->pos)[iVar41].pos.z,iVar40);
                  }
                  uVar14._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar14._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar14 & 0x100000) != 0) {
                    FUN_800e48bc((int)param1,(int)(&param1[0x27]->pos + iVar41),iVar40);
                  }
                  uVar23._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar23._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar23 & 0x400000) != 0) {
                    FUN_800e50fc((int)param1,(int)(&param1[0x27]->pos + iVar41),iVar40);
                  }
                  uVar15._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar15._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar15 & 0x80000000) != 0) {
                    FUN_800e52c8((int)param1,(int)(&param1[0x27]->pos + iVar41));
                  }
                  uVar24._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar24._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar24 & 0x800000) != 0) {
                    uVar25._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                    uVar25._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                    if (((uVar25 & 0x1000000) == 0) || ((&param1[0x27]->pos)[iVar41].scale != 0.0))
                    {
                      if ((&param1[0x27]->pos)[iVar41].scale == 0.0) {
                        for (iVar38 = 0;
                            iVar35 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z,
                            local_50 = (double)(longlong)iVar35, iVar38 < iVar35;
                            iVar38 = iVar38 + 1) {
                          if (((uint)param1[0x29] & 1) == 0) {
                    /* {@symbol 800ed30c} */
                            (**(code **)(*(int *)pDll_objfsa + 8))
                                      (param1[1],(int)*(short *)&(&param1[0x27]->pos)[iVar41].pos.z,
                                       0,&DAT_00010002,0xffffffff,0);
                          }
                          else {
                    /* {@symbol 800ed30c} */
                            (**(code **)(*(int *)pDll_objfsa + 8))
                                      (param1[1],(int)*(short *)&(&param1[0x27]->pos)[iVar41].pos.z,
                                       param1 + 3,&DAT_00010002,0xffffffff,0);
                          }
                        }
                      }
                      else if ((&param1[0x27]->pos)[iVar41].scale == 1.0) {
                        if (((uint)param1[0x29] & 1) == 0) {
                          local_60 = (ObjInstance *)((param1[1]->prevPos).x + (float)param1[0x18]);
                          local_5c = (ObjInstance *)((param1[1]->prevPos).y + (float)param1[0x19]);
                          local_58 = (ObjInstance *)((param1[1]->prevPos).z + (float)param1[0x1a]);
                          if (param1[1] != (ObjInstance *)0x0) {
                    /* {@symbol 800ed30c} */
                            (**(code **)(*(int *)pDll_objfsa + 8))
                                      (param1[1],(int)*(short *)&(&param1[0x27]->pos)[iVar41].pos.z,
                                       auStack_6c,&DAT_00010001,0xffffffff,0);
                          }
                        }
                        else {
                          local_60 = param1[0x18];
                          local_5c = param1[0x19];
                          local_58 = param1[0x1a];
                          if (param1[1] != (ObjInstance *)0x0) {
                    /* {@symbol 800ed30c} */
                            (**(code **)(*(int *)pDll_objfsa + 8))
                                      (param1[1],(int)*(short *)&(&param1[0x27]->pos)[iVar41].pos.z,
                                       auStack_6c,&DAT_00010001,0xffffffff,0);
                          }
                        }
                      }
                    }
                    else {
                      for (iVar38 = 0;
                          iVar35 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z,
                          local_50 = (double)(longlong)iVar35, iVar38 < iVar35; iVar38 = iVar38 + 1)
                      {
                        iVar35 = (int)(&param1[0x27]->pos)[iVar41].pos.x;
                        local_50 = (double)(longlong)iVar35;
                        iVar35 = randInt(0,iVar35);
                        if (iVar35 == 0) {
                          if (((uint)param1[0x29] & 1) == 0) {
                    /* {@symbol 800ed30c} */
                            (**(code **)(*(int *)pDll_objfsa + 8))
                                      (param1[1],(int)*(short *)&(&param1[0x27]->pos)[iVar41].pos.z,
                                       0,&DAT_00010001,0xffffffff,0);
                          }
                          else {
                    /* {@symbol 800ed30c} */
                            (**(code **)(*(int *)pDll_objfsa + 8))
                                      (param1[1],(int)*(short *)&(&param1[0x27]->pos)[iVar41].pos.z,
                                       0,&DAT_00010001,0xffffffff,0);
                          }
                        }
                      }
                    }
                  }
                  uVar26._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                  uVar26._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                  if ((uVar26 & 0x4000000) != 0) {
                    dll = (LoadedDll *)
                          runlinkDownloadCode(*(short *)&(&param1[0x27]->pos)[iVar41].pos.z + 0x1000
                                              ,1);
                    uVar27._0_2_ = (&param1[0x27]->pos)[iVar41].rotation.x;
                    uVar27._2_2_ = (&param1[0x27]->pos)[iVar41].rotation.y;
                    if ((uVar27 & 0x1000000) == 0) {
                      for (iVar38 = 0;
                          iVar35 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z,
                          local_50 = (double)(longlong)iVar35, iVar38 < iVar35; iVar38 = iVar38 + 1)
                      {
                        if (((uint)param1[0x29] & 1) == 0) {
                          (**(code **)(dll->id + 4))(param1[1],0,0,1,0xffffffff,0);
                        }
                        else {
                          (**(code **)(dll->id + 4))(0,0,param1 + 3,1,0xffffffff,0);
                        }
                      }
                    }
                    else {
                      for (iVar38 = 0;
                          iVar35 = (int)*(float *)&(&param1[0x27]->pos)[iVar41].rotation.z,
                          local_50 = (double)(longlong)iVar35, iVar38 < iVar35; iVar38 = iVar38 + 1)
                      {
                        iVar35 = randInt(0,5);
                        if (iVar35 == 0) {
                          if (((uint)param1[0x29] & 1) == 0) {
                            (**(code **)(dll->id + 4))(param1[1],0,0,1,0xffffffff,0);
                          }
                          else {
                            (**(code **)(dll->id + 4))(0,0,param1 + 3,1,0xffffffff,0);
                          }
                        }
                      }
                    }
                    DLL_free(dll);
                  }
                }
                iVar38 = iVar39;
              }
              if (!bVar5) {
                *(ushort *)((int)param1 + 0xfe) =
                     *(short *)((int)param1 + 0xfe) - (ushort)framesThisStep;
              }
            }
          }
          DAT_80398740 = 0;
        }
      }
    }
  }
  return;
}


void modgfx_func06(void) { //800E2990
  FUN_800e3de4(0,1);
  return;
}


/* Library Function - Single Match
    modgfx_func07
   
   Library: KioskDefault 0 0 */

void modgfx_func07(int param1) { //800E29B8
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x1f0; iVar1 = iVar1 + 1) {
    if (((&DAT_80385128)[iVar1] != 0) && (*(int *)((&DAT_80385128)[iVar1] + 4) == param1)) {
      if (*(int *)((&DAT_80385128)[iVar1] + 0xa0) != 0) {
        mm_free(*(void **)((&DAT_80385128)[iVar1] + 0xa0));
      }
      if (*(short *)((&DAT_80385128)[iVar1] + 0x10e) != -1) {
        loadLfxAction(*(undefined4 *)((&DAT_80385128)[iVar1] + 4),0,
                      *(ushort *)((&DAT_80385128)[iVar1] + 0x10e));
      }
      if (*(int *)(&DAT_80385128)[iVar1] != 0) {
        Object_objFreeObject(*(ObjInstance **)(&DAT_80385128)[iVar1]);
      }
      mm_free(*(void **)((&DAT_80385128)[iVar1] + 300));
      *(undefined4 *)((&DAT_80385128)[iVar1] + 300) = 0;
      if ((*(char *)((&DAT_80385128)[iVar1] + 0x13f) == '\0') &&
         (*(int *)((&DAT_80385128)[iVar1] + 0x98) != 0)) {
        texFreeTexture(*(Texture **)((&DAT_80385128)[iVar1] + 0x98));
      }
      if (*(char *)((&DAT_80385128)[iVar1] + 0x13f) == '\0') {
        *(undefined4 *)((&DAT_80385128)[iVar1] + 0x98) = 0;
      }
      if (*(int *)((&DAT_80385128)[iVar1] + 8) != 0) {
        mm_free(*(void **)((&DAT_80385128)[iVar1] + 8));
      }
      if (*(int *)((&DAT_80385128)[iVar1] + 0x9c) != 0) {
        mm_free(*(void **)((&DAT_80385128)[iVar1] + 0x9c));
      }
      mm_free((void *)(&DAT_80385128)[iVar1]);
      (&DAT_80385128)[iVar1] = 0;
    }
  }
  return;
}


/* Library Function - Single Match
    modgfx_func08
   
   Library: KioskDefault 0 0 */

void modgfx_func08(int param1) { //800E2B88
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x1f0; iVar1 = iVar1 + 1) {
    if ((&DAT_80385128)[iVar1] != 0) {
      if (*(int *)((&DAT_80385128)[iVar1] + 4) == param1) {
        if ((*(uint *)((&DAT_80385128)[iVar1] + 0xa4) & 0x10000) == 0) {
          *(undefined4 *)((&DAT_80385128)[iVar1] + 0x18) =
               *(undefined4 *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 0x18);
          *(undefined4 *)((&DAT_80385128)[iVar1] + 0x1c) =
               *(undefined4 *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 0x1c);
          *(undefined4 *)((&DAT_80385128)[iVar1] + 0x20) =
               *(undefined4 *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 0x20);
          *(undefined4 *)((&DAT_80385128)[iVar1] + 0x14) =
               *(undefined4 *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 8);
          *(undefined2 *)((&DAT_80385128)[iVar1] + 0x10) =
               *(undefined2 *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 4);
          *(undefined2 *)((&DAT_80385128)[iVar1] + 0xe) =
               *(undefined2 *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 2);
          *(undefined2 *)((&DAT_80385128)[iVar1] + 0xc) =
               **(undefined2 **)((&DAT_80385128)[iVar1] + 4);
          if ((*(uint *)((&DAT_80385128)[iVar1] + 0xa4) & 2) != 0) {
            *(float *)((&DAT_80385128)[iVar1] + 0x6c) =
                 *(float *)((&DAT_80385128)[iVar1] + 0x6c) +
                 *(float *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 0x24);
            *(float *)((&DAT_80385128)[iVar1] + 0x70) =
                 *(float *)((&DAT_80385128)[iVar1] + 0x70) +
                 *(float *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 0x28);
            *(float *)((&DAT_80385128)[iVar1] + 0x74) =
                 *(float *)((&DAT_80385128)[iVar1] + 0x74) +
                 *(float *)(*(int *)((&DAT_80385128)[iVar1] + 4) + 0x2c);
          }
          if ((*(uint *)((&DAT_80385128)[iVar1] + 0xa4) & 0x200000) == 0) {
            *(uint *)((&DAT_80385128)[iVar1] + 0xa4) =
                 *(uint *)((&DAT_80385128)[iVar1] + 0xa4) | 0x200000;
          }
          *(undefined4 *)((&DAT_80385128)[iVar1] + 4) = 0;
        }
        else {
          FUN_800e3de4(*(short *)((&DAT_80385128)[iVar1] + 0x10c),0);
        }
      }
    }
  }
  return;
}


undefined4 modgfx_func09(Gfx *param1,undefined4 param_2,undefined4 param_3,char param4,int param5) { //800E2DA0
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  N64Button NVar6;
  undefined4 uVar4;
  Camera *pCVar5;
  Mtx44 *a;
  bool bVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  double dVar16;
  undefined auStack_134 [108];
  undefined4 uStack_c8;
  char local_c4;
  byte local_c3;
  byte local_c2;
  byte local_c1;
  undefined4 local_c0 [2];
  undefined2 local_b8 [5];
  undefined local_ae;
  undefined local_ad;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  ObjPos local_7c;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  undefined4 local_50;
  uint uStack_4c;
  
  local_5c = 0;
  local_60 = 0;
  local_64 = 0;
  uVar13 = 0;
  uVar9 = 0;
  local_ad = 0;
  local_ae = 0;
  iVar15 = 2;
  ppuVar1 = &PTR_DAT_802cf780;
  puVar12 = &uStack_c8;
  do {
    puVar8 = puVar12;
    ppuVar3 = ppuVar1;
    puVar2 = ppuVar3[3];
    puVar8[2] = ppuVar3[2];
    puVar8[3] = puVar2;
    iVar15 = iVar15 + -1;
    ppuVar1 = ppuVar3 + 2;
    puVar12 = puVar8 + 2;
  } while (iVar15 != 0);
  *(undefined2 *)(puVar8 + 4) = *(undefined2 *)(ppuVar3 + 4);
  NVar6 = n64GetEnabledButtonsHeld(3);
  if ((NVar6 & N64_BUTTON_LEFT) == 0) {
    FUN_800d568c(&local_c1,&local_c2,&local_c3);
    GXSetCullMode(GX_CULL_NONE);
    iVar15 = FUN_800671a4(-1);
    if ((short)iVar15 == 1) {
      uVar4 = 1;
    }
    else {
      pCVar5 = getCurCamera();
      for (iVar15 = 0; iVar15 < 0x1f0; iVar15 = iVar15 + 1) {
        if (((&DAT_80385128)[iVar15] != 0) && (*(short *)((&DAT_80385128)[iVar15] + 0x10c) != -1)) {
          if (((param4 == '\0') || ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x2000) != 0)) &&
             ((param4 == '\0' || (*(int *)((&DAT_80385128)[iVar15] + 4) == param5)))) {
            if ((param4 != '\0') || ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x2000) == 0)) {
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x800) != 0) {
                *(undefined *)((&DAT_80385128)[iVar15] + 0x13e) = 0;
              }
              bVar7 = false;
              local_64 = local_64 + 1;
              iVar11 = *(int *)((&DAT_80385128)[iVar15] +
                               (uint)*(byte *)((&DAT_80385128)[iVar15] + 0x130) * 4 + 0x78);
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x40000) != 0) {
                FUN_800e4044((&DAT_80385128)[iVar15],'\0');
              }
              iVar10 = *(int *)((&DAT_80385128)[iVar15] +
                               (uint)*(byte *)((&DAT_80385128)[iVar15] + 0x130) * 4 + 0x84);
              local_7c.pos.x = 0.0;
              local_7c.pos.y = 0.0;
              local_7c.pos.z = 0.0;
              local_7c.scale = 1.0;
              local_7c.rotation.z = 0;
              local_7c.rotation.y = 0;
              local_88 = *(float *)((&DAT_80385128)[iVar15] + 0x60);
              local_84 = *(float *)((&DAT_80385128)[iVar15] + 100);
              local_80 = *(float *)((&DAT_80385128)[iVar15] + 0x68);
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 4) != 0) {
                if (local_80 + local_88 + local_84 == 0.0) {
                  bVar7 = true;
                }
              }
              if ((((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 4) != 0) && (!bVar7)) &&
                 (*(int *)((&DAT_80385128)[iVar15] + 4) != 0)) {
                local_7c.rotation.x = **(short **)((&DAT_80385128)[iVar15] + 4);
                local_7c.rotation.y = *(short *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 2);
                local_7c.rotation.z = *(short *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 4);
                FUN_8007a878((short *)&local_7c,&local_88);
              }
              local_ac = 0.0;
              local_a8 = 0.0;
              local_a4 = 0.0;
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 1) == 0) {
                if (*(int *)((&DAT_80385128)[iVar15] + 4) == 0) {
                  local_ac = *(float *)((&DAT_80385128)[iVar15] + 0x18);
                  local_a8 = *(float *)((&DAT_80385128)[iVar15] + 0x1c);
                  local_a4 = *(float *)((&DAT_80385128)[iVar15] + 0x20);
                  vecMtxMultFn_8000dd74
                            ((float *)((&DAT_80385128)[iVar15] + 0x18),&local_ac,
                             *(s8 *)((&DAT_80385128)[iVar15] + 0x135));
                }
                else {
                  local_ac = *(float *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 0x18);
                  local_a8 = *(float *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 0x1c);
                  local_a4 = *(float *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 0x20);
                }
              }
              if ((65534.0 < local_ac) || (local_ac < -65534.0)) {
                printf(" modgfx x %f",(double)local_ac);
                local_ac = -playerMapOffsetX;
              }
              if ((65534.0 < local_a8) || (local_a8 < -65534.0)) {
                local_a8 = 0.0;
              }
              if (65534.0 < local_a4) {
LAB_800e3224:
                printf(" modgfx z %f",(double)local_a4);
                local_a4 = -playerMapOffsetZ;
              }
              else if (local_a4 < -65534.0) goto LAB_800e3224;
              local_7c.pos.x = local_ac + local_88;
              local_7c.pos.y = local_a8 + local_84;
              local_7c.pos.z = local_a4 + local_80;
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x400000) == 0) {
                local_7c.scale = *(float *)((&DAT_80385128)[iVar15] + 0xd4) * 0.01;
              }
              else {
                uStack_4c = randInt(1,10);
                uStack_4c = uStack_4c ^ 0x80000000;
                local_50 = 0x43300000;
                local_7c.scale =
                     *(float *)((&DAT_80385128)[iVar15] + 0xd4) * 0.5 +
                     (*(float *)((&DAT_80385128)[iVar15] + 0xd4) * 0.5) /
                     (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
              }
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x80000) == 0) {
                if ((bVar7) && (*(int *)((&DAT_80385128)[iVar15] + 4) != 0)) {
                  local_7c.rotation.z =
                       *(short *)((&DAT_80385128)[iVar15] + 0x106) +
                       *(short *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 4);
                  local_7c.rotation.y =
                       *(short *)((&DAT_80385128)[iVar15] + 0x108) +
                       *(short *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 2);
                  local_7c.rotation.x =
                       *(short *)((&DAT_80385128)[iVar15] + 0x10a) +
                       **(short **)((&DAT_80385128)[iVar15] + 4);
                }
                else if (bVar7) {
                  local_7c.rotation.z =
                       *(short *)((&DAT_80385128)[iVar15] + 0x106) +
                       *(short *)((&DAT_80385128)[iVar15] + 0x10);
                  local_7c.rotation.y =
                       *(short *)((&DAT_80385128)[iVar15] + 0x108) +
                       *(short *)((&DAT_80385128)[iVar15] + 0xe);
                  local_7c.rotation.x =
                       *(short *)((&DAT_80385128)[iVar15] + 0x10a) +
                       *(short *)((&DAT_80385128)[iVar15] + 0xc);
                }
                else {
                  local_7c.rotation.z = *(short *)((&DAT_80385128)[iVar15] + 0x106);
                  local_7c.rotation.y = *(short *)((&DAT_80385128)[iVar15] + 0x108);
                  local_7c.rotation.x = *(short *)((&DAT_80385128)[iVar15] + 0x10a);
                }
              }
              else {
                local_7c.rotation.z = *(short *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 4);
                local_7c.rotation.y = *(short *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 2);
                local_7c.rotation.x = **(short **)((&DAT_80385128)[iVar15] + 4);
              }
              if (((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x1000) != 0) &&
                 (*(int *)((&DAT_80385128)[iVar15] + 4) != 0)) {
                local_94 = 0.0;
                local_90 = 0.0;
                local_8c = -1.0;
                local_a0 = (pCVar5->prevPos44).x -
                           *(float *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 0x18);
                local_9c = 0.0;
                local_98 = (pCVar5->prevPos44).z -
                           *(float *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 0x20);
                dVar16 = sqrt((double)(local_a0 * local_a0 + local_98 * local_98));
                if (dVar16 != 0.0) {
                  local_a0 = (float)((double)local_a0 / dVar16);
                  local_98 = (float)((double)local_98 / dVar16);
                }
                uStack_4c = getAngle();
                uStack_4c = uStack_4c & 0xffff;
                local_50 = 0x43300000;
                iVar14 = (int)((double)CONCAT44(0x43300000,uStack_4c) - 4503599627370496.0);
                local_58 = (longlong)iVar14;
                local_7c.rotation.x = local_7c.rotation.x + (short)iVar14;
              }
              local_7c.pos.x = local_7c.pos.x - playerMapOffsetX;
              local_7c.pos.z = local_7c.pos.z - playerMapOffsetZ;
              mtxSetFromObjPos((Mtx44 *)(auStack_134 + 0x30),&local_7c);
              mtx44Transpose((Mtx44 *)(auStack_134 + 0x30),(Mtx44 *)auStack_134);
              a = getCameraMtxs();
              MTXConcat((Mtx43 *)a,(Mtx43 *)auStack_134,(Mtx43 *)auStack_134);
              GXLoadPosMtxImm((Mtx43 *)auStack_134,0);
              if ((((*(int *)((&DAT_80385128)[iVar15] + 0x98) != 0) &&
                   (**(int **)((&DAT_80385128)[iVar15] + 0x98) != 0)) &&
                  (*(char *)((&DAT_80385128)[iVar15] + 0x132) != '\0')) &&
                 (*(char *)((&DAT_80385128)[iVar15] + 0x133) =
                       *(char *)((&DAT_80385128)[iVar15] + 0x133) + -1,
                 *(char *)((&DAT_80385128)[iVar15] + 0x133) == '\0')) {
                *(char *)((&DAT_80385128)[iVar15] + 0x133) =
                     (char)(0x3c / *(byte *)((&DAT_80385128)[iVar15] + 0x132));
                *(char *)((&DAT_80385128)[iVar15] + 0x131) =
                     *(char *)((&DAT_80385128)[iVar15] + 0x131) + '\x01';
                if ((uint)((int)(uint)*(ushort *)(*(int *)((&DAT_80385128)[iVar15] + 0x98) + 0x10)
                          >> 8) <= (uint)*(byte *)((&DAT_80385128)[iVar15] + 0x131)) {
                  *(undefined *)((&DAT_80385128)[iVar15] + 0x131) = 0;
                }
              }
              if (*(int *)((&DAT_80385128)[iVar15] + 0x98) != 0) {
                local_5c = 0;
              }
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x10000000) == 0) {
                if ((*(int *)((&DAT_80385128)[iVar15] + 4) == 0) ||
                   ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x4000) == 0)) {
                  RSP_setTevColor2(param1,0xff,0xff,0xff,0xff);
                }
                else {
                  RSP_setTevColor2(param1,0xff,0xff,0xff,
                                    *(byte *)(*(int *)((&DAT_80385128)[iVar15] + 4) + 0x37));
                }
              }
              else {
                RSP_setTevColor2(param1,local_c1,local_c2,local_c3,0xff);
              }
              if (*(int *)((&DAT_80385128)[iVar15] + 0x98) != 0) {
                local_60 = 0;
                uVar9 = (uint)*(byte *)((&DAT_80385128)[iVar15] + 0x131);
                uVar13 = uVar9 + 1;
                if (((int)(uint)*(ushort *)(*(int *)((&DAT_80385128)[iVar15] + 0x98) + 0x10) >> 8) +
                    -1 < (int)(uVar13 & 0xff)) {
                  uVar13 = 0;
                }
                if ((false) && ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x1000000) != 0)) {
                  debugPrint("modgfx can't TEXMIX framesize %d",0);
                  *(uint *)((&DAT_80385128)[iVar15] + 0xa4) =
                       *(uint *)((&DAT_80385128)[iVar15] + 0xa4) ^ 0x1000000;
                  *(uint *)((&DAT_80385128)[iVar15] + 0xa4) =
                       *(uint *)((&DAT_80385128)[iVar15] + 0xa4) | 0x4000000;
                }
              }
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x1000000) == 0) {
LAB_800e38c0:
                if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x2000000) == 0) {
                  if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x4000000) != 0) {
                    FUN_800c41d0();
                    FUN_800c428c();
                    FUN_800c4610();
                    gxSetTevFn_800c420c();
                  }
                }
                else {
                  FUN_800c41d0();
                  gxSetTevFn_800c478c();
                  gxSetTevFn_800c420c();
                }
              }
              else {
                if ((*(char *)((&DAT_80385128)[iVar15] + 0x13e) == '\0') &&
                   ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x400) == 0)) goto LAB_800e38c0;
                puVar12 = *(undefined4 **)((&DAT_80385128)[iVar15] + 0x98);
                iVar14 = 0;
                while( true ) {
                  if ((int)(uVar13 & 0xff) <= iVar14) break;
                  puVar12 = (undefined4 *)*puVar12;
                  iVar14 = iVar14 + 1;
                }
                RSP_setTevColor1(param1,0xff,0xff,0xff,
                                  -(*(char *)((&DAT_80385128)[iVar15] + 0x133) *
                                   *(char *)((&DAT_80385128)[iVar15] + 0x134)) - 1);
                FUN_800c41d0();
                FUN_800c4478();
                gxSetTevFn_800c478c();
                gxSetTevFn_800c420c();
                FUN_800a3194((int)puVar12,1);
              }
              local_c4 = '\0';
              if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x5000000) != 0) {
                if ((*(char *)((&DAT_80385128)[iVar15] + 0x13e) != '\0') ||
                   ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x400) != 0)) {
                  puVar12 = *(undefined4 **)((&DAT_80385128)[iVar15] + 0x98);
                  for (iVar14 = 0; iVar14 < (int)uVar9; iVar14 = iVar14 + 1) {
                    puVar12 = (undefined4 *)*puVar12;
                  }
                  FUN_800a3194((int)puVar12,0);
                }
              }
              if (local_c4 == '\0') {
                if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x100) == 0) {
                  if (((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x10) == 0) ||
                     ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x80) == 0)) {
                    if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x80) == 0) {
                      if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x10) == 0) {
                        gxResetBlendFn_800c4ce8();
                      }
                      else {
                        gxResetBlendFn_800c4ce8();
                      }
                    }
                    else {
                      gxResetBlendFn_800c4ce8();
                    }
                  }
                  else {
                    gxResetBlendFn_800c4ce8();
                  }
                }
                else {
                  gxResetBlendFn_800c4ce8();
                }
              }
              if ((*(char *)((&DAT_80385128)[iVar15] + 0x13e) != '\0') ||
                 ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x400) != 0)) {
                iVar14 = 0;
                while( true ) {
                  if ((int)(uint)*(byte *)((&DAT_80385128)[iVar15] + 0x136) <= iVar14) break;
                  if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x8000000) == 0) {
                    FUN_800a6e50(iVar11,iVar10,(int)*(short *)((&DAT_80385128)[iVar15] + 0xec));
                  }
                  else {
                    FUN_800a6e50(iVar11,iVar10,
                                 (int)*(short *)((&DAT_80385128)[iVar15] + 0xec) /
                                 (int)(uint)*(byte *)((&DAT_80385128)[iVar15] + 0x136));
                  }
                  iVar11 = iVar11 + (uint)*(byte *)((&DAT_80385128)[iVar15] + 0x137) * 0x10;
                  if ((*(uint *)((&DAT_80385128)[iVar15] + 0xa4) & 0x8000000) != 0) {
                    iVar10 = iVar10 + ((int)*(short *)((&DAT_80385128)[iVar15] + 0xec) /
                                      (int)(uint)*(byte *)((&DAT_80385128)[iVar15] + 0x136)) * 0x10;
                  }
                  iVar14 = iVar14 + 1;
                }
              }
              RSP_rcpInitDp();
              bVar7 = checkSomeDebugFlags_8017c4f8();
              if (!bVar7) {
                *(char *)((&DAT_80385128)[iVar15] + 0x130) =
                     '\x01' - *(char *)((&DAT_80385128)[iVar15] + 0x130);
              }
            }
          }
        }
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


/* Library Function - Single Match
    modgfx_func0A
   
   Library: KioskDefault 0 0 */

void modgfx_func0A(short *param1) { //800E3B54
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x1f0; iVar1 = iVar1 + 1) {
    if (((&DAT_80385128)[iVar1] != 0) && (*param1 == *(short *)((&DAT_80385128)[iVar1] + 0x10c))) {
      *(undefined *)((&DAT_80385128)[iVar1] + 0x13a) = 1;
    }
  }
  *param1 = -1;
  return;
}


void modgfx_func0B(void) { //800E3BC4
  DAT_803990fa = DAT_803990fa + '\x01';
  return;
}


/* Library Function - Single Match
    modgfx_func0C
   
   Library: KioskDefault 0 0 */

void modgfx_func0C(int param1,undefined param2) { //800E3BD4
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x1f0; iVar1 = iVar1 + 1) {
    if (((&DAT_80385128)[iVar1] != 0) && (*(int *)((&DAT_80385128)[iVar1] + 4) == param1)) {
      *(undefined *)((&DAT_80385128)[iVar1] + 0x13b) = param2;
    }
  }
  return;
}


/* Library Function - Single Match
    modgfx_func0D
   
   Library: KioskDefault 0 0 */

void modgfx_func0D(int param1) { //800E3C34
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x1f0; iVar1 = iVar1 + 1) {
    if (((&DAT_80385128)[iVar1] != 0) && (*(int *)((&DAT_80385128)[iVar1] + 4) == param1)) {
      *(undefined *)((&DAT_80385128)[iVar1] + 0x13a) = 1;
    }
  }
  return;
}


/* Library Function - Single Match
    modgfx_func0E
   
   Library: KioskDefault 0 0 */

void modgfx_func0E(int param1) { //800E3C98
  bool bVar1;
  int iVar2;
  ObjInstance *pOVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_80082ab4();
  for (iVar4 = 0; iVar4 < 0x1f0; iVar4 = iVar4 + 1) {
    if (((&DAT_80385128)[iVar4] != 0) && (*(int *)((&DAT_80385128)[iVar4] + 4) != 0)) {
      iVar5 = 0;
      bVar1 = true;
      while ((iVar5 < iVar2 && (bVar1))) {
        pOVar3 = FUN_80082a28(iVar5);
        if (*(ObjInstance **)((&DAT_80385128)[iVar4] + 4) == pOVar3) {
          bVar1 = false;
        }
        iVar5 = iVar5 + 1;
      }
      if ((!bVar1) && (*(char *)(param1 + iVar5 + -1) != '\0')) {
        *(undefined *)((&DAT_80385128)[iVar4] + 0x13e) = 1;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    modgfx_func0F
   
   Library: KioskDefault 0 0 */

void modgfx_func0F(undefined4 param1,byte param2,undefined param3,undefined4 param4,
                   undefined4 param5) { //800E5C74
  memclr(&DAT_80385be8,0x60);
  DAT_80385c40 = param2;
  DAT_80385bec = param1;
  DAT_80385c2c = (ushort)param2;
  DAT_80385c14 = 0.0;
  DAT_80385c18 = 0.0;
  DAT_80385c1c = 0.0;
  DAT_80385c08 = 0.0;
  DAT_80385c0c = 0.0;
  DAT_80385c10 = 0.0;
  DAT_80385c20 = 1.0;
  DAT_80385c28 = param4;
  DAT_80385c24 = param5;
  DAT_80385c41 = param3;
  DAT_80385c42 = 0;
  DAT_80385c43 = 0;
  return;
}


void modgfx_func10(void) { //800E5D34
  DAT_80399104 = &DAT_803858e8;
  DAT_8039910c = &DAT_803858e8;
  DAT_80399110 = 0;
  return;
}


/* Library Function - Single Match
    modgfx_func11
   
   Library: KioskDefault 0 0 */

void modgfx_func11(double param1,double param2,double param3,undefined4 param4,undefined2 param5,
                   undefined4 param6) { //800E5D50
  *(char *)((int)DAT_8039910c + 0x16) = (char)DAT_80399110;
  *(undefined2 *)(DAT_8039910c + 5) = param5;
  DAT_8039910c[4] = param6;
  *DAT_8039910c = param4;
  DAT_8039910c[1] = (float)param1;
  DAT_8039910c[2] = (float)param2;
  DAT_8039910c[3] = (float)param3;
  DAT_8039910c = DAT_8039910c + 6;
  return;
}


void modgfx_func12(void) { //800E5D9C
  DAT_80399110 = DAT_80399110 + 1;
  return;
}


void modgfx_func13(undefined2 param1) { //800E5DAC
  DAT_80399110 = param1;
  return;
}


void modgfx_func14(undefined2 param1) { //800E5DB4
  *(undefined2 *)(&DAT_80385c2e + DAT_80399110 * 2) = param1;
  return;
}


/* Library Function - Single Match
    modgfx_func15
   
   Library: KioskDefault 0 0 */

void modgfx_func15(void *param1) { //800E5DD0
  memcpy_src_dst_len(param1,&DAT_80385c2e,0xe);
  return;
}


/* Library Function - Single Match
    modgfx_func16
   
   Library: KioskDefault 0 0 */

void modgfx_func16(int param1,int param2,int param3,int param4,int param5,int param6,int param7) { //800E5E08
  int iVar1;
  
  DAT_80385be8 = &DAT_803858e8;
  DAT_80385c45 = (undefined)((DAT_8039910c - DAT_80399104) / 0x18);
  if ((param7 == 0) && (param6 == 0)) {
    DAT_80385c3c = DAT_80385c3c | 0x2000000;
  }
  else {
    DAT_80385c3c = DAT_80385c3c | 0x4000000;
  }
  if ((DAT_80385c3c & 1) != 0) {
    if (DAT_80385bec == 0) {
      DAT_80385c14 = DAT_80385c14 + *(float *)(param1 + 0xc);
      DAT_80385c18 = DAT_80385c18 + *(float *)(param1 + 0x10);
      DAT_80385c1c = DAT_80385c1c + *(float *)(param1 + 0x14);
    }
    else {
      DAT_80385c14 = DAT_80385c14 + *(float *)(DAT_80385bec + 0x18);
      DAT_80385c18 = DAT_80385c18 + *(float *)(DAT_80385bec + 0x1c);
      DAT_80385c1c = DAT_80385c1c + *(float *)(DAT_80385bec + 0x20);
    }
  }
  iVar1 = func04((int *)&DAT_80385be8,0,param3,param2,param5,param4,param6,param7);
  DAT_80399108 = (short)iVar1;
  return;
}


void modgfx_func17(uint param1) { //800E5F50
  DAT_80385c3c = DAT_80385c3c | param1;
  return;
}


int modgfx_func18(void) { //800E5F68
  return (int)DAT_80399108;
}

