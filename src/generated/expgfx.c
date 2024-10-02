
/* Library Function - Single Match
    expgfx_func00
   
   Library: KioskDefault 0 0 */

void expgfx_initialise(undefined4 param) { //800DB40C
  undefined *puVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {
    (&DAT_80384db8)[iVar2] = 0;
    (&DAT_80384e30)[iVar2] = 0;
    (&DAT_802f5360)[iVar2] = 0xffff;
  }
  for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {
    puVar1 = (undefined *)mmAlloc(0x2400,EXPGFX_COL,"expgfx1");
    (&PTR_DAT_80384d40)[iVar2] = puVar1;
    memclr((&PTR_DAT_80384d40)[iVar2],0x2400);
  }
  memclr(&DAT_80384ec8,0x1e0);
  return;
}


/* Library Function - Single Match
    expgfx_func01
   
   Library: KioskDefault 0 0 */

void expgfx_release(void) { //800DB4C8
  int iVar1;
  
  FUN_800dfe1c();
  for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {
    mm_free((&PTR_DAT_80384d40)[iVar1]);
  }
  return;
}


/* Library Function - Single Match
    expgfx_func03
   
   Library: KioskDefault 0 0 */

void expgfx_func03(void) { //800DB51C
  int iVar1;
  
  FUN_800dfe1c();
  for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {
    (&DAT_80384db8)[iVar1] = 0;
    (&DAT_80384e30)[iVar1] = 0;
    (&DAT_802f5360)[iVar1] = 0xffff;
  }
  for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    if ((&DAT_803850a8)[iVar1 * 4] != 0) {
      texFreeTexture((Texture *)(&DAT_803850a8)[iVar1 * 4]);
    }
    (&DAT_803850a8)[iVar1 * 4] = 0;
    (&DAT_803850b0)[iVar1 * 4] = 0;
    (&DAT_803850ac)[iVar1 * 4] = 0;
    (&DAT_803850b4)[iVar1 * 4] = 0;
  }
  return;
}


void expgfx_func04(int *param1,int param2) { //800DB60C
  float fVar1;
  float fVar2;
  N64Button NVar6;
  int iVar3;
  int iVar4;
  ObjInstance *pOVar5;
  int param3;
  int iVar7;
  undefined2 *param2_00;
  undefined2 *puVar8;
  short local_6c;
  short local_6a;
  double local_68;
  double local_60;
  undefined4 local_58;
  uint uStack_54;
  
  _savefpr_30();
  local_6a = 0;
  local_6c = 0;
  NVar6 = n64GetEnabledButtonsHeld(3);
  if ((NVar6 & N64_BUTTON_LEFT) == 0) {
    iVar3 = ret0_800BFC8C();
    iVar4 = expgfxFn_800dfb90(&local_6a,&local_6c,(ushort)*(byte *)((int)param1 + 0x5e),param2,
                              *param1);
    if (iVar4 != -1) {
      if ((local_6a < 0x1e) && ((&DAT_80384e50)[local_6a] = *param1, (param1[0x11] & 0x40000U) != 0)
         ) {
        DAT_803990d4 = DAT_803990d4 | 1 << (int)local_6a;
      }
      else {
        DAT_803990d4 = DAT_803990d4 & ~(1 << (int)local_6a);
      }
      puVar8 = (undefined2 *)((&PTR_DAT_80384d40)[local_6a] + local_6c * 0x90);
      DAT_803990d8 = DAT_803990d8 + 1;
      if (30000 < DAT_803990d8) {
        DAT_803990d8 = 0;
      }
      puVar8[0x13] = DAT_803990d8;
      *(int *)(puVar8 + 0x3e) = param1[0x11];
      *(int *)(puVar8 + 0x40) = param1[0x12];
      *(byte *)((int)puVar8 + 0x8b) = *(byte *)((int)puVar8 + 0x8b) & 0xf3;
      iVar4 = FUN_800e0034((int)*(short *)((int)param1 + 0x42));
      iVar4 = (int)(short)iVar4;
      if (iVar4 < 0) {
        FUN_800dff20((int)local_6a,(int)local_6c,1);
      }
      else {
        iVar7 = (&DAT_803850a8)[iVar4 * 4];
        if (iVar7 == 0) {
          printf("error no texture");
        }
        else {
          *(short *)(iVar7 + 0xe) = *(short *)(iVar7 + 0xe) + 1;
          *(ushort *)(iVar7 + 0x14) = (ushort)*(byte *)((int)param1 + 0x61);
        }
        param2_00 = (undefined2 *)*param1;
        param3 = 0;
        if (param2_00 == (undefined2 *)0x0) {
          *(int *)(puVar8 + 0x26) = param1[6];
          *(int *)(puVar8 + 0x28) = param1[7];
          *(int *)(puVar8 + 0x2a) = param1[8];
          *(int *)(puVar8 + 0x24) = param1[5];
          puVar8[0x22] = *(undefined2 *)(param1 + 4);
          puVar8[0x21] = *(undefined2 *)((int)param1 + 0xe);
          puVar8[0x20] = *(undefined2 *)(param1 + 3);
        }
        else if ((*(uint *)(puVar8 + 0x3e) & 0x200000) != 0) {
          *(undefined4 *)(puVar8 + 0x26) = *(undefined4 *)(param2_00 + 0xc);
          *(undefined4 *)(puVar8 + 0x28) = *(undefined4 *)(param2_00 + 0xe);
          *(undefined4 *)(puVar8 + 0x2a) = *(undefined4 *)(param2_00 + 0x10);
          *(undefined4 *)(puVar8 + 0x24) = *(undefined4 *)(param2_00 + 4);
          puVar8[0x22] = param2_00[2];
          puVar8[0x21] = param2_00[1];
          puVar8[0x20] = *param2_00;
          if (((*(uint *)(puVar8 + 0x3e) & 2) != 0) || ((*(uint *)(puVar8 + 0x3e) & 4) != 0)) {
            param1[9] = (int)((float)param1[9] + *(float *)(param2_00 + 0x12));
            param1[10] = (int)((float)param1[10] + *(float *)(param2_00 + 0x14));
            param1[0xb] = (int)((float)param1[0xb] + *(float *)(param2_00 + 0x16));
          }
          if (param2_00 != (undefined2 *)0x0) {
            param3 = *(int *)(param2_00 + 0x18);
          }
          param2_00 = (undefined2 *)0x0;
        }
        iVar7 = addToTable(iVar7,(int)param2_00,param3);
        if ((short)iVar7 == -1) {
          debugPrint("expgfx.c: invalid tabindex");
        }
        else {
          *(byte *)(puVar8 + 0x45) = (byte)(iVar7 << 1) | *(byte *)(puVar8 + 0x45) & 1;
          iVar7 = param1[0xc];
          *(int *)(puVar8 + 0x32) = iVar7;
          *(int *)(puVar8 + 0x2c) = iVar7;
          iVar7 = param1[0xd];
          *(int *)(puVar8 + 0x34) = iVar7;
          *(int *)(puVar8 + 0x2e) = iVar7;
          iVar7 = param1[0xe];
          *(int *)(puVar8 + 0x36) = iVar7;
          *(int *)(puVar8 + 0x30) = iVar7;
          *(int *)(puVar8 + 0x38) = param1[9];
          *(int *)(puVar8 + 0x3a) = param1[10];
          *(int *)(puVar8 + 0x3c) = param1[0xb];
          *(undefined *)((int)puVar8 + 0xf) = *(undefined *)(param1 + 0x18);
          puVar8[0x1b] = (short)param1[1];
          puVar8[3] = (short)param1[2];
          puVar8[0xb] = (short)param1[2];
          if (1.0 < (float)param1[0xf]) {
            debugPrint("expgfx.c: scale overflow");
          }
          fVar1 = (float)param1[0xf] * 65535.0;
          if ((*(uint *)(puVar8 + 0x3e) & 0x100000) == 0) {
            puVar8[0x42] = (short)(int)fVar1;
            puVar8[0x43] = puVar8[0x42];
            puVar8[0x44] = 0;
          }
          else {
            puVar8[0x42] = 0;
            uStack_54 = (int)(short)puVar8[0xb] ^ 0x80000000;
            local_58 = 0x43300000;
            iVar7 = (int)(fVar1 / (float)((double)CONCAT44(0x43300000,uStack_54) -
                                         4503601774854144.0));
            local_60 = (double)(longlong)iVar7;
            puVar8[0x44] = (short)iVar7;
            puVar8[0x43] = (short)(int)fVar1;
          }
          local_68 = (double)(longlong)(int)fVar1;
          if (((*(uint *)(puVar8 + 0x3e) & 0x20000) != 0) ||
             ((*(uint *)(puVar8 + 0x3e) & 0x4000000) != 0)) {
            *(int *)(puVar8 + 0x26) = param1[6];
            *(int *)(puVar8 + 0x28) = param1[7];
            *(int *)(puVar8 + 0x2a) = param1[8];
            *(int *)(puVar8 + 0x24) = param1[5];
            puVar8[0x22] = *(undefined2 *)(param1 + 4);
            puVar8[0x21] = *(undefined2 *)((int)param1 + 0xe);
            puVar8[0x20] = *(undefined2 *)(param1 + 3);
          }
          *(byte *)((int)puVar8 + 0x8b) = DAT_803990da & 1 | *(byte *)((int)puVar8 + 0x8b) & 0xfe;
          if ((*(uint *)(puVar8 + 0x40) & 8) != 0) {
            *(uint *)(puVar8 + 0x40) = *(uint *)(puVar8 + 0x40) ^ 8;
            local_68 = (double)CONCAT44(0x43300000,(int)(short)puVar8[3] ^ 0x80000000);
            *(float *)(puVar8 + 0x2c) =
                 *(float *)(puVar8 + 0x38) * (float)(local_68 - 4503601774854144.0) * 1.5 +
                 *(float *)(puVar8 + 0x2c);
            local_60 = (double)CONCAT44(0x43300000,(int)(short)puVar8[3] ^ 0x80000000);
            *(float *)(puVar8 + 0x2e) =
                 *(float *)(puVar8 + 0x3a) * (float)(local_60 - 4503601774854144.0) * 1.5 +
                 *(float *)(puVar8 + 0x2e);
            uStack_54 = (int)(short)puVar8[3] ^ 0x80000000;
            local_58 = 0x43300000;
            *(float *)(puVar8 + 0x30) =
                 *(float *)(puVar8 + 0x3c) *
                 (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0) * 1.5 +
                 *(float *)(puVar8 + 0x30);
            *(float *)(puVar8 + 0x38) = *(float *)(puVar8 + 0x38) * -1.0;
            *(float *)(puVar8 + 0x3a) = *(float *)(puVar8 + 0x3a) * -1.0;
            *(float *)(puVar8 + 0x3c) = *(float *)(puVar8 + 0x3c) * -1.0;
          }
          if ((*(uint *)(puVar8 + 0x40) & 0x10) != 0) {
            pOVar5 = Object_objGetMain();
            *(uint *)(puVar8 + 0x40) = *(uint *)(puVar8 + 0x40) ^ 0x10;
            if ((*(uint *)(puVar8 + 0x3e) & 1) == 0) {
              fVar1 = (pOVar5->prevPos).x - (*(float *)(puVar8 + 0x32) + *(float *)(param2_00 + 6));
              fVar2 = (pOVar5->prevPos).z - (*(float *)(puVar8 + 0x36) + *(float *)(param2_00 + 10))
              ;
              if (((fVar1 * fVar1 + fVar2 * fVar2 < 3600.0) && ((pOVar5->vel).x != 0.0)) &&
                 ((pOVar5->vel).z != 0.0)) {
                local_68 = (double)CONCAT44(0x43300000,(int)(short)puVar8[3] << 1 ^ 0x80000000);
                *(float *)(puVar8 + 0x38) =
                     *(float *)(puVar8 + 0x38) -
                     ((pOVar5->prevPos).x - (*(float *)(puVar8 + 0x32) + *(float *)(param2_00 + 6)))
                     / (float)(local_68 - 4503601774854144.0);
                local_60 = (double)CONCAT44(0x43300000,(int)(short)puVar8[3] << 1 ^ 0x80000000);
                *(float *)(puVar8 + 0x3a) =
                     *(float *)(puVar8 + 0x3a) -
                     (((pOVar5->prevPos).y + 30.0) -
                     (*(float *)(puVar8 + 0x34) + *(float *)(param2_00 + 8))) /
                     (float)(local_60 - 4503601774854144.0);
                uStack_54 = (int)(short)puVar8[3] << 1 ^ 0x80000000;
                local_58 = 0x43300000;
                *(float *)(puVar8 + 0x3c) =
                     *(float *)(puVar8 + 0x3c) -
                     ((pOVar5->prevPos).z - (*(float *)(puVar8 + 0x36) + *(float *)(param2_00 + 10))
                     ) / (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
              }
            }
            else {
              fVar1 = (pOVar5->prevPos).x - *(float *)(puVar8 + 0x32);
              fVar2 = (pOVar5->prevPos).z - *(float *)(puVar8 + 0x36);
              if (((fVar1 * fVar1 + fVar2 * fVar2 < 3600.0) && ((pOVar5->vel).x != 0.0)) &&
                 ((pOVar5->vel).z != 0.0)) {
                local_68 = (double)CONCAT44(0x43300000,(int)(short)puVar8[3] << 1 ^ 0x80000000);
                *(float *)(puVar8 + 0x38) =
                     *(float *)(puVar8 + 0x38) +
                     ((pOVar5->prevPos).x - *(float *)(puVar8 + 0x32)) /
                     (float)(local_68 - 4503601774854144.0);
                local_60 = (double)CONCAT44(0x43300000,(int)(short)puVar8[3] << 1 ^ 0x80000000);
                *(float *)(puVar8 + 0x3a) =
                     *(float *)(puVar8 + 0x3a) +
                     (((pOVar5->prevPos).y + 30.0) - *(float *)(puVar8 + 0x34)) /
                     (float)(local_60 - 4503601774854144.0);
                uStack_54 = (int)(short)puVar8[3] << 1 ^ 0x80000000;
                local_58 = 0x43300000;
                *(float *)(puVar8 + 0x3c) =
                     *(float *)(puVar8 + 0x3c) +
                     ((pOVar5->prevPos).z - *(float *)(puVar8 + 0x36)) /
                     (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
              }
            }
          }
          if (iVar4 == 1) {
            DAT_803990e0 = DAT_803990e0 + 1;
            iVar4 = ret0_800BFC8C();
            DAT_803990e4 = DAT_803990e4 + (iVar4 - iVar3);
            DAT_803990e8 = DAT_803990e4 / DAT_803990e0;
          }
          if ((param1[0x12] & 0x20U) != 0) {
            *(char *)(puVar8 + 0x46) = (char)((ushort)*(undefined2 *)(param1 + 0x16) >> 8);
            *(char *)((int)puVar8 + 0x8d) = (char)((ushort)*(undefined2 *)((int)param1 + 0x5a) >> 8)
            ;
            *(char *)(puVar8 + 0x47) = (char)((ushort)*(undefined2 *)(param1 + 0x17) >> 8);
            *(char *)((int)puVar8 + 0x1f) = (char)((uint)param1[0x13] >> 8);
            *(char *)((int)puVar8 + 0x2f) = (char)((uint)param1[0x14] >> 8);
            *(char *)((int)puVar8 + 0x3f) = (char)((uint)param1[0x15] >> 8);
          }
          puVar8[4] = 0;
          puVar8[5] = 0;
          puVar8[0xc] = 0;
          puVar8[0xd] = 0;
          puVar8[0x14] = 0;
          puVar8[0x15] = 0;
          puVar8[0x1c] = 0;
          puVar8[0x1d] = 0;
          if ((*(uint *)(puVar8 + 0x40) & 2) != 0) {
            textureFn_8009b6d4(puVar8);
          }
          isModelAnimDisabled();
        }
      }
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    expgfx_func05
   
   Library: KioskDefault 0 0 */

void expgfx_func05(byte param1,uint param2) { //800DBF50
  N64Button NVar2;
  int iVar1;
  bool bVar3;
  byte bVar4;
  
  NVar2 = n64GetEnabledButtonsHeld(3);
  if (((NVar2 & N64_BUTTON_LEFT) == 0) && (iVar1 = FUN_800671a4(-1), (short)iVar1 != 1)) {
    bVar3 = checkSomeDebugFlags_8017c4f8();
    if ((bVar3) && (iVar1 = isModelAnimDisabled(), iVar1 == 0)) {
      return;
    }
    DAT_80398740 = 1;
    FUN_800dd700((uint)param1,param2);
    DAT_80398740 = 0;
    bVar4 = 0x1e;
    while (bVar4 != 0) {
      bVar4 = bVar4 - 1;
      (&DAT_802f539c)[bVar4] = 0;
    }
                    /* {@symbol 800eb004} */
    (**(code **)(*(int *)pDll_objfsa + 0xc))(0);
    DAT_803990dc = 1;
  }
  return;
}


/* Library Function - Single Match
    expgfx_func06
   
   Library: KioskDefault 0 0 */

void expgfx_func06(void) { //800DC028
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  for (iVar3 = 0; iVar3 < 0x1e; iVar3 = iVar3 + 1) {
    puVar2 = (&PTR_DAT_80384d40)[iVar3];
    iVar1 = 0;
    while( true ) {
      if (0x3f < iVar1) break;
      if ((1 << iVar1 & (&DAT_80384db8)[iVar3]) != 0) {
        if ((&DAT_80384ed0)[((byte)puVar2[0x8a] & 0xfe) * 2] != 0) {
          *(short *)((&DAT_80384ed0)[((byte)puVar2[0x8a] & 0xfe) * 2] + 0xe) =
               *(short *)((&DAT_80384ed0)[((byte)puVar2[0x8a] & 0xfe) * 2] + 0xe) + -1;
        }
        addremove((uint)((byte)puVar2[0x8a] >> 1));
        *(undefined2 *)(puVar2 + 0x26) = 0xffff;
        (&DAT_80384db8)[iVar3] = (&DAT_80384db8)[iVar3] & ~(1 << iVar1);
      }
      puVar2 = puVar2 + 0x90;
      iVar1 = iVar1 + 1;
    }
    (&DAT_80384e30)[iVar3] = 0;
    (&DAT_802f5360)[iVar3] = 0xffff;
    (&DAT_80384e50)[iVar3] = 0;
    (&DAT_802f539c)[iVar3] = 0;
  }
  for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
    if ((&DAT_803850a8)[iVar3 * 4] != 0) {
      texFreeTexture((Texture *)(&DAT_803850a8)[iVar3 * 4]);
    }
    (&DAT_803850a8)[iVar3 * 4] = 0;
    (&DAT_803850b0)[iVar3 * 4] = 0;
    (&DAT_803850ac)[iVar3 * 4] = 0;
    (&DAT_803850b4)[iVar3 * 4] = 0;
  }
  printf("TRACE: '%s' {Line %d}","expgfx.c",0x29b);
  return;
}


/* Library Function - Single Match
    expgfx_func07
   
   Library: KioskDefault 0 0 */

void expgfx_func07(int param1) { //800DC1D4
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  if (param1 == 0) {
    printf("expgfx.c: Error on owner free");
  }
  else {
    for (iVar3 = 0; iVar3 < 0x1e; iVar3 = iVar3 + 1) {
      puVar1 = (&PTR_DAT_80384d40)[iVar3];
      if (param1 == (&DAT_80384e50)[iVar3]) {
        for (iVar2 = 0; iVar2 < 0x40; iVar2 = iVar2 + 1) {
          if (puVar1 != (undefined *)0x0) {
            if ((&DAT_80384ec8)[((byte)puVar1[0x8a] & 0xfe) * 2] == param1) {
              FUN_800dff20(iVar3,iVar2,0);
            }
          }
          puVar1 = puVar1 + 0x90;
          if ((&DAT_80384e30)[iVar3] == '\0') {
            (&DAT_802f5360)[iVar3] = 0xffff;
          }
        }
        (&DAT_80384e50)[iVar3] = 0;
        (&DAT_802f539c)[iVar3] = 0;
      }
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    expgfx_func08
    expgfx_func0C
   
   Library: KioskDefault 0 0 */

void expgfx_func08(int param1) { //800DC2D8
  func07(param1);
  return;
}


/* Library Function - Single Match
    expgfx_func09
   
   Library: KioskDefault 0 0 */

void expgfx_func09(ushort *param1,Gfx *param2,undefined4 param_3,undefined4 param_4,char param5) { //800DC300
  float fVar1;
  byte a;
  N64Button NVar6;
  Mtx44 *pMVar2;
  int iVar3;
  Camera *pCVar4;
  bool bVar7;
  uint uVar5;
  uint uVar8;
  int iVar9;
  char cVar10;
  char cVar11;
  int iVar12;
  char cVar13;
  ushort *puVar14;
  int iVar15;
  undefined *puVar16;
  undefined *puVar17;
  double z;
  double y;
  double x;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  vec3f vStack_12c;
  byte local_120;
  byte local_11f;
  byte local_11e;
  byte local_116;
  byte local_115;
  byte local_114 [4];
  undefined4 local_110;
  int local_10c;
  int local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  ushort local_ec;
  ushort local_ea;
  ushort local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d0;
  uint uStack_cc;
  undefined4 local_c8;
  uint uStack_c4;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  
  _savefpr_22();
  local_110 = 0;
  NVar6 = n64GetEnabledButtonsHeld(3);
  if ((NVar6 & N64_BUTTON_LEFT) == 0) {
    FUN_800d56cc(&vStack_12c.x,&vStack_12c.y,&vStack_12c.z);
    pMVar2 = FUN_80069278();
    MTXMultVec((Mtx43 *)pMVar2,&vStack_12c,&vStack_12c);
    dVar21 = -(double)vStack_12c.z;
    if (dVar21 < 0.2000000029802322) {
      dVar21 = 0.2000000029802322;
    }
    FUN_800d568c(local_114,&local_115,&local_116);
    local_98 = (double)CONCAT44(0x43300000,(uint)local_114[0]);
    iVar3 = (int)((double)(float)(local_98 - 4503599627370496.0) * dVar21);
    local_a0 = (double)(longlong)iVar3;
    local_11e = (byte)iVar3;
    local_a8 = (double)CONCAT44(0x43300000,(uint)local_115);
    iVar3 = (int)((double)(float)(local_a8 - 4503599627370496.0) * dVar21);
    local_b0 = (double)(longlong)iVar3;
    local_11f = (byte)iVar3;
    local_b8 = (double)CONCAT44(0x43300000,(uint)local_116);
    iVar3 = (int)((double)(float)(local_b8 - 4503599627370496.0) * dVar21);
    local_c0 = (double)(longlong)iVar3;
    local_120 = (byte)iVar3;
    GXSetCullMode(GX_CULL_NONE);
    pMVar2 = getCameraMtxs();
    GXLoadPosMtxImm((Mtx43 *)pMVar2,0);
    iVar3 = FUN_800671a4(-1);
    if ((short)iVar3 != 1) {
      pCVar4 = getCurCamera();
      RSP_setTevColor1(param2,0xff,0xff,0xff,0xff);
      cVar10 = -1;
      cVar11 = -1;
      cVar13 = -1;
      iVar3 = 0;
      for (iVar12 = 0; iVar12 < 0x1e; iVar12 = iVar12 + 1) {
        local_108 = 1;
        if (((DAT_803990db == '\x01') && (iVar12 == 0x1d)) ||
           (((&DAT_80384e30)[iVar12] != '\0' && ((&DAT_802f539c)[iVar12] != '\0')))) {
          puVar17 = (&PTR_DAT_80384d40)[iVar12] + -0x90;
          for (iVar15 = 0; iVar15 < 0x40; iVar15 = iVar15 + 1) {
            puVar16 = puVar17 + 0x90;
            puVar14 = (ushort *)(&DAT_80384ec8)[((byte)puVar17[0x11a] & 0xfe) * 2];
            iVar9 = (&DAT_80384ecc)[((byte)puVar17[0x11a] & 0xfe) * 2];
            local_10c = (&DAT_80384ed0)[((byte)puVar17[0x11a] & 0xfe) * 2];
            if ((((((((DAT_803990db != '\x01') || (iVar12 != 0x1d)) || (param1 == puVar14)) &&
                   (((1 << iVar15 & (&DAT_80384db8)[iVar12]) != 0 &&
                    (((byte)puVar17[0x11b] >> 2 & 3) == 0)))) &&
                  ((((byte)puVar17[0x11b] >> 1 & 1) != 0 ||
                   (bVar7 = checkSomeDebugFlags_8017c4f8(), bVar7)))) &&
                 ((*(short *)(puVar17 + 0xb6) != -1 && ((puVar17[0x11b] & 1) == 0)))) &&
                ((param5 != '\0' || ((*(uint *)(puVar17 + 0x10c) & 0x40000) == 0)))) &&
               ((param5 != '\x01' || ((*(uint *)(puVar17 + 0x10c) & 0x40000) != 0)))) {
              puVar17[0x11b] = puVar17[0x11b] & 0xfd;
              uVar8 = (uint)*(short *)(puVar17 + 0xa6);
              uVar8 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
              if ((*(uint *)(puVar17 + 0x10c) & 0x800000) == 0) {
                if ((*(uint *)(puVar17 + 0x10c) & 0x200) == 0) {
                  if (((*(uint *)(puVar17 + 0x110) & 0x400000) == 0) ||
                     ((int)uVar8 < (int)*(short *)(puVar17 + 0x96))) {
                    if (((*(uint *)(puVar17 + 0x10c) & 0x100) == 0) ||
                       ((int)uVar8 < (int)*(short *)(puVar17 + 0x96))) {
                      if ((*(uint *)(puVar17 + 0x10c) & 0x100) == 0) {
                        uVar8 = (uint)(byte)puVar17[0x9f];
                      }
                      else {
                        local_c0 = (double)CONCAT44(0x43300000,
                                                    uVar8 * 2 - (int)*(short *)(puVar17 + 0x96) ^
                                                    0x80000000);
                        local_b8 = (double)CONCAT44(0x43300000,uVar8 ^ 0x80000000);
                        fVar1 = (float)(local_c0 - 4503601774854144.0) /
                                (float)(local_b8 - 4503601774854144.0);
                        if (0.0 <= fVar1) {
                          if (1.0 < fVar1) {
                            fVar1 = 1.0;
                          }
                        }
                        else {
                          fVar1 = 0.0;
                        }
                        local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)puVar17[0x9f]);
                        uVar8 = (uint)((float)(local_c0 - 4503599627370496.0) * fVar1);
                        local_b8 = (double)(longlong)(int)uVar8;
                      }
                    }
                    else {
                      local_c0 = (double)CONCAT44(0x43300000,
                                                  (int)*(short *)(puVar17 + 0x96) ^ 0x80000000);
                      local_b8 = (double)CONCAT44(0x43300000,uVar8 ^ 0x80000000);
                      fVar1 = (float)(local_c0 - 4503601774854144.0) /
                              (float)(local_b8 - 4503601774854144.0);
                      if (0.0 <= fVar1) {
                        if (1.0 < fVar1) {
                          fVar1 = 1.0;
                        }
                      }
                      else {
                        fVar1 = 0.0;
                      }
                      local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)puVar17[0x9f]);
                      uVar8 = (uint)((float)(local_c0 - 4503599627370496.0) * fVar1);
                      local_b8 = (double)(longlong)(int)uVar8;
                    }
                  }
                  else {
                    local_c0 = (double)CONCAT44(0x43300000,
                                                (int)*(short *)(puVar17 + 0x96) ^ 0x80000000);
                    local_b8 = (double)CONCAT44(0x43300000,uVar8 ^ 0x80000000);
                    fVar1 = (float)(local_c0 - 4503601774854144.0) /
                            (float)(local_b8 - 4503601774854144.0);
                    if (0.0 <= fVar1) {
                      if (1.0 < fVar1) {
                        fVar1 = 1.0;
                      }
                    }
                    else {
                      fVar1 = 0.0;
                    }
                    local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)puVar17[0x9f]);
                    uVar8 = (uint)((float)(local_c0 - 4503599627370496.0) * fVar1);
                    local_b8 = (double)(longlong)(int)uVar8;
                  }
                }
                else {
                  local_c0 = (double)CONCAT44(0x43300000,
                                              (int)*(short *)(puVar17 + 0x96) ^ 0x80000000);
                  local_b8 = (double)CONCAT44(0x43300000,
                                              (int)*(short *)(puVar17 + 0xa6) ^ 0x80000000);
                  fVar1 = (float)(local_c0 - 4503601774854144.0) /
                          (float)(local_b8 - 4503601774854144.0);
                  if (0.0 <= fVar1) {
                    if (1.0 < fVar1) {
                      fVar1 = 1.0;
                    }
                  }
                  else {
                    fVar1 = 0.0;
                  }
                  local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)puVar17[0x9f]);
                  uVar8 = (uint)((float)(local_c0 - 4503599627370496.0) * fVar1);
                  local_b8 = (double)(longlong)(int)uVar8;
                }
              }
              else {
                local_c0 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar17 + 0x96) ^ 0x80000000)
                ;
                local_b8 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar17 + 0xa6) ^ 0x80000000)
                ;
                fVar1 = (float)(local_c0 - 4503601774854144.0) /
                        (float)(local_b8 - 4503601774854144.0);
                if (0.0 <= fVar1) {
                  if (1.0 < fVar1) {
                    fVar1 = 1.0;
                  }
                }
                else {
                  fVar1 = 0.0;
                }
                local_c0 = (double)CONCAT44(0x43300000,(byte)puVar17[0x9f] - 0xff ^ 0x80000000);
                local_b8 = (double)CONCAT44(0x43300000,(uint)(byte)puVar17[0x9f]);
                uVar8 = (uint)((float)(local_c0 - 4503601774854144.0) * fVar1 +
                              (float)(local_b8 - 4503599627370496.0));
                local_b0 = (double)(longlong)(int)uVar8;
              }
              local_e0 = 0.0;
              local_dc = 0.0;
              local_d8 = 0.0;
              local_e4 = 1.0;
              if (((*(uint *)(puVar17 + 0x10c) & 0x20000) != 0) &&
                 ((*(uint *)(puVar17 + 0x110) & 0x30000000) == 0)) {
                local_c0 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar17 + 0xd4) ^ 0x80000000)
                ;
                iVar15 = (int)((float)(local_c0 - 4503601774854144.0) * timeDelta);
                local_b8 = (double)(longlong)iVar15;
                local_e8 = (ushort)iVar15;
                local_b0 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar17 + 0xd2) ^ 0x80000000)
                ;
                iVar15 = (int)((float)(local_b0 - 4503601774854144.0) * timeDelta);
                local_a8 = (double)(longlong)iVar15;
                local_ea = (ushort)iVar15;
                local_a0 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar17 + 0xd0) ^ 0x80000000)
                ;
                iVar15 = (int)((float)(local_a0 - 4503601774854144.0) * timeDelta);
                local_98 = (double)(longlong)iVar15;
                local_ec = (ushort)iVar15;
                FUN_8007a878((short *)&local_ec,(float *)(puVar17 + 0xe8));
              }
              local_e8 = 0;
              local_ea = 0;
              local_ec = 0;
              if ((*(uint *)(puVar17 + 0x10c) & 0x4000000) == 0) {
                if ((*(uint *)(puVar17 + 0x10c) & 4) != 0) {
                  if (puVar14 == (ushort *)0x0) {
                    local_ec = *(ushort *)(puVar17 + 0xd0);
                    local_ea = *(ushort *)(puVar17 + 0xd2);
                    local_e8 = *(ushort *)(puVar17 + 0xd4);
                  }
                  else {
                    local_ec = *puVar14;
                    local_ea = puVar14[1];
                    local_e8 = puVar14[2];
                  }
                }
                if ((puVar14 != (ushort *)0x0) && (*(int *)(puVar14 + 0x18) != 0)) {
                  local_ec = local_ec + **(short **)(puVar14 + 0x18);
                }
              }
              local_f8 = *(float *)(puVar17 + 0xe8);
              local_f4 = *(float *)(puVar17 + 0xec);
              local_f0 = *(float *)(puVar17 + 0xf0);
              FUN_8007a878((short *)&local_ec,&local_f8);
              local_104 = 0.0;
              local_100 = 0.0;
              local_fc = 0.0;
              if ((*(uint *)(puVar17 + 0x10c) & 1) == 0) {
                if (puVar14 == (ushort *)0x0) {
                  local_104 = *(float *)(puVar17 + 0xdc);
                  local_100 = *(float *)(puVar17 + 0xe0);
                  local_fc = *(float *)(puVar17 + 0xe4);
                  if (iVar9 != 0) {
                    vecMtxMultFn_8000dd74
                              ((float *)(puVar17 + 0xdc),&local_104,*(s8 *)(iVar9 + 0x35));
                  }
                }
                else {
                  local_104 = *(float *)(puVar14 + 0xc);
                  local_100 = *(float *)(puVar14 + 0xe);
                  local_fc = *(float *)(puVar14 + 0x10);
                }
              }
              local_e4 = 1.0;
              local_e8 = 0;
              local_ea = 0;
              local_ec = 0;
              local_e0 = local_104 + local_f8;
              local_dc = local_100 + local_f4;
              local_d8 = local_fc + local_f0;
              if ((((*(uint *)(puVar17 + 0x10c) & 0x20000) != 0) &&
                  ((*(uint *)(puVar17 + 0x10c) & 0x4000000) == 0)) &&
                 ((*(uint *)(puVar17 + 0x110) & 0x30000000) == 0)) {
                local_e0 = local_e0 + *(float *)(puVar17 + 0xdc);
                local_dc = local_dc + *(float *)(puVar17 + 0xe0);
                local_d8 = local_d8 + *(float *)(puVar17 + 0xe4);
              }
              local_c0 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar17 + 0x114));
              fVar1 = (float)(local_c0 - 4503599627370496.0) * 1.525902e-05;
              dVar21 = (double)fVar1;
              if ((*(uint *)(puVar17 + 0x10c) & 0x400000) != 0) {
                uVar5 = randInt(1,10);
                local_c0 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
                fVar1 = (float)(dVar21 * 0.5 +
                               (double)((float)(dVar21 * 0.5) /
                                       (float)(local_c0 - 4503601774854144.0)));
              }
              local_e4 = fVar1;
              if ((*(uint *)(puVar17 + 0x10c) & 0x4000000) == 0) {
                local_e8 = 0;
                local_ea = 0;
                if ((*(uint *)(puVar17 + 0x10c) & 0x2000000) == 0) {
                  if ((*(uint *)(puVar17 + 0x10c) & 0x80000) == 0) {
                    local_ec = -(pCVar4->rot).x;
                  }
                  else {
                    local_ec = -(pCVar4->rot).x;
                    local_ea = (pCVar4->rot).y;
                  }
                }
                else {
                  local_ec = 0;
                }
              }
              if ((65534.0 < local_104) || (local_104 < -65534.0)) {
                printf(" exp x %f",(double)local_104);
                local_104 = -playerMapOffsetX;
              }
              if ((65534.0 < local_100) || (local_100 < -65534.0)) {
                local_100 = 0.0;
              }
              if ((65534.0 < local_fc) || (local_fc < -65534.0)) {
                printf(" exp z %f",(double)local_fc);
                local_fc = -playerMapOffsetZ;
              }
              uVar5 = scos16(local_ea);
              local_c0 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
              dVar19 = (double)((float)(local_c0 - 4503601774854144.0) * 1.525879e-05);
              uVar5 = ssin16(local_ea);
              local_b8 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
              dVar20 = (double)((float)(local_b8 - 4503601774854144.0) * 1.525879e-05);
              uVar5 = scos16(local_ec);
              local_b0 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
              dVar21 = (double)((float)(local_b0 - 4503601774854144.0) * 1.525879e-05);
              uVar5 = ssin16(local_ec);
              local_a8 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
              dVar18 = (double)((float)(local_a8 - 4503601774854144.0) * 1.525879e-05);
              if ((puVar14 != (ushort *)0x0) && ((*(uint *)(puVar17 + 0x110) & 0x80) != 0)) {
                uVar8 = (int)(uVar8 * *(byte *)(puVar14 + 0x1b)) >> 8;
              }
              a = (byte)uVar8;
              if ((*(uint *)(puVar17 + 0x110) & 0x1000000) == 0) {
                if ((*(uint *)(puVar17 + 0x110) & 0x800000) == 0) {
                  RSP_setTevColor2(param2,0xff,0xff,0xff,a);
                  cVar10 = '\x01';
                }
                else if (cVar10 != '\0') {
                  RSP_setTevColor2(param2,local_11e,local_11f,local_120,a);
                  cVar10 = '\0';
                }
              }
              else {
                RSP_setTevColor2(param2,local_114[0],local_115,local_116,a);
                cVar10 = -1;
              }
              if ((local_108 != 0) || (iVar12 == 0x1d)) {
                local_110 = 0;
                if ((DAT_803990d0 == 0) || ((*(uint *)(puVar17 + 0x110) & 0x2000000) == 0)) {
                  if (iVar3 != local_10c) {
                    FUN_800a3194(local_10c,0);
                  }
                }
                else if (iVar3 != *DAT_802f4b08) {
                  FUN_800a3194(*DAT_802f4b08,0);
                  iVar3 = *DAT_802f4b08;
                }
                if ((*(uint *)(puVar17 + 0x110) & 0x40) == 0) {
                  if ((*(uint *)(puVar17 + 0x110) & 0x20) == 0) {
                    if (cVar11 != '\x03') {
                      FUN_800c41d0();
                      FUN_800c4388();
                      gxSetTevFn_800c420c();
                      cVar11 = '\x03';
                    }
                  }
                  else if (cVar11 != '\x02') {
                    FUN_800c41d0();
                    FUN_800c4914();
                    FUN_800c4610();
                    gxSetTevFn_800c420c();
                    cVar11 = '\x02';
                  }
                  if ((*(uint *)(puVar17 + 0x10c) & 0x10) == 0) {
                    if ((*(uint *)(puVar17 + 0x110) & 1) == 0) {
                      if (cVar13 != '\x02') {
                        gxResetBlendFn_800c4ce8();
                        cVar13 = '\x02';
                      }
                    }
                    else if (cVar13 != '\x01') {
                      gxResetBlendFn_800c4ce8();
                      cVar13 = '\x01';
                    }
                  }
                  else if (cVar13 != '\0') {
                    gxResetBlendFn_800c4ce8();
                    cVar13 = '\0';
                  }
                }
                else {
                  if ((*(uint *)(puVar17 + 0x110) & 0x20) == 0) {
                    if (cVar11 != '\x01') {
                      FUN_800c41d0();
                      gxSetTevFn_800c478c();
                      gxSetTevFn_800c420c();
                      cVar11 = '\x01';
                    }
                  }
                  else if (cVar11 != '\0') {
                    FUN_800c41d0();
                    gxSetTevFn_800c478c();
                    gxSetTevFn_800c420c();
                    cVar11 = '\0';
                  }
                  if ((*(uint *)(puVar17 + 0x10c) & 0x10) == 0) {
                    if ((*(uint *)(puVar17 + 0x110) & 1) == 0) {
                      if (cVar13 != '\x02') {
                        gxResetBlendFn_800c4ce8();
                        cVar13 = '\x02';
                      }
                    }
                    else if (cVar13 != '\x01') {
                      gxResetBlendFn_800c4ce8();
                      cVar13 = '\x01';
                    }
                  }
                  else if (cVar13 != '\0') {
                    gxResetBlendFn_800c4ce8();
                    cVar13 = '\0';
                  }
                }
              }
              GXBegin(DRAW_QUADS_0,4,4);
              for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {
                local_c0 = (double)CONCAT44(0x43300000,
                                            (int)*(short *)(puVar16 + iVar15 * 0x10 + 4) ^
                                            0x80000000);
                local_b8 = (double)CONCAT44(0x43300000,
                                            (int)*(short *)(puVar16 + iVar15 * 0x10) ^ 0x80000000);
                local_b0 = (double)CONCAT44(0x43300000,
                                            (int)*(short *)(puVar16 + iVar15 * 0x10 + 2) ^
                                            0x80000000);
                x = (double)((local_e0 +
                             local_e4 *
                             (float)(dVar21 * (double)(float)(dVar20 * (double)(float)(local_c0 -
                                                                                                                                                                            
                                                  4503601774854144.0))) +
                             local_e4 *
                             (float)(dVar18 * (double)(float)(local_b8 - 4503601774854144.0)) +
                             local_e4 *
                             (float)(dVar21 * (double)(float)(dVar19 * (double)(float)(local_b0 -
                                                                                                                                                                            
                                                  4503601774854144.0)))) - playerMapOffsetX);
                local_a8 = (double)CONCAT44(0x43300000,
                                            (int)*(short *)(puVar16 + iVar15 * 0x10 + 2) ^
                                            0x80000000);
                local_a0 = (double)CONCAT44(0x43300000,
                                            -(int)*(short *)(puVar16 + iVar15 * 0x10 + 4) ^
                                            0x80000000);
                y = (double)(local_dc +
                            local_e4 *
                            (float)(dVar20 * (double)(float)(local_a8 - 4503601774854144.0)) +
                            local_e4 *
                            (float)(dVar19 * (double)(float)(local_a0 - 4503601774854144.0)));
                local_98 = (double)CONCAT44(0x43300000,
                                            (int)*(short *)(puVar16 + iVar15 * 0x10 + 4) ^
                                            0x80000000);
                uStack_c4 = -(int)*(short *)(puVar16 + iVar15 * 0x10) ^ 0x80000000;
                local_c8 = 0x43300000;
                uStack_cc = (int)*(short *)(puVar16 + iVar15 * 0x10 + 2) ^ 0x80000000;
                local_d0 = 0x43300000;
                z = (double)((local_d8 +
                             local_e4 *
                             (float)(dVar18 * (double)(float)(dVar20 * (double)(float)(local_98 -
                                                                                                                                                                            
                                                  4503601774854144.0))) +
                             local_e4 *
                             (float)(dVar21 * (double)(float)((double)CONCAT44(0x43300000,uStack_c4)
                                                             - 4503601774854144.0)) +
                             local_e4 *
                             (float)(dVar18 * (double)(float)(dVar19 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_cc) -
                                                  4503601774854144.0)))) - playerMapOffsetZ);
                gxWrite_byte(0);
                gxWrite_float_3(x,y,z);
                gxWrite_byte_4(puVar16[iVar15 * 0x10 + 0xc],puVar16[iVar15 * 0x10 + 0xd],
                               puVar16[iVar15 * 0x10 + 0xe],puVar16[iVar15 * 0x10 + 0xf]);
                gxWrite_s16_2(*(undefined2 *)(puVar16 + iVar15 * 0x10 + 8),
                              *(undefined2 *)(puVar16 + iVar15 * 0x10 + 10));
              }
              GXEnd8();
            }
            puVar17 = puVar16;
          }
        }
      }
      if (DAT_803990dc != '\0') {
        FUN_800e0414((uint **)param2);
        FUN_800e0284();
        DAT_803990dc = '\0';
      }
    }
  }
  _restfpr_22();
  return;
}


void expgfx_func0A(void) { //800DD3F0
  return;
}


void expgfx_func0B(void) { //800DD3F4
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    expgfx_func08
    expgfx_func0C
   
   Library: KioskDefault 0 0 */

void expgfx_func0C(int param1) { //800DD3F8
  func07(param1);
  return;
}


/* Library Function - Single Match
    expgfx_func0D
   
   Library: KioskDefault 0 0 */

char expgfx_func0D(int param1) { //800DD420
  char cVar1;
  short sVar2;
  
  cVar1 = '\0';
  DAT_803990db = 0;
  sVar2 = 0;
  do {
    if (0x1d < sVar2) {
      if ((*(short *)(param1 + 0x46) == 0x178) && (DAT_802f539a != -1)) {
        DAT_803990db = 1;
      }
      return cVar1;
    }
    if (*(short *)(param1 + 0x46) == 0xd4) {
LAB_800dd470:
      if ((DAT_803990d4 & 1 << (int)sVar2) == 0) {
        (&DAT_802f539c)[sVar2] = 1;
        if (cVar1 == '\x02') {
          cVar1 = '\x03';
        }
        else {
          cVar1 = '\x01';
        }
      }
      else {
        (&DAT_802f539c)[sVar2] = 2;
        if (cVar1 == '\x01') {
          cVar1 = '\x03';
        }
        else {
          cVar1 = '\x02';
        }
      }
    }
    else {
      if ((&DAT_80384e50)[sVar2] == param1) goto LAB_800dd470;
      (&DAT_802f539c)[sVar2] = 0;
    }
    sVar2 = sVar2 + 1;
  } while( true );
}


int expgfx_addToTable(int param1,int param2,int param3) { //800DD530
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (0x1d < iVar1) {
      iVar1 = 0;
      while( true ) {
        if (0x1d < iVar1) {
          debugPrint("expgfx.c: exptab is FULL");
          return -1;
        }
        if ((&expgfxVar_80384ed4)[iVar1 * 8] == 0) break;
        iVar1 = iVar1 + 1;
      }
      (&expgfxVar_80384ed4)[iVar1 * 8] = 1;
      (&DAT_80384ed0)[iVar1 * 4] = param1;
      (&DAT_80384ec8)[iVar1 * 4] = param2;
      (&DAT_80384ecc)[iVar1 * 4] = param3;
      return (int)(short)iVar1;
    }
    if (((((&expgfxVar_80384ed4)[iVar1 * 8] != 0) && ((&DAT_80384ed0)[iVar1 * 4] == param1)) &&
        ((&DAT_80384ec8)[iVar1 * 4] == param2)) && ((&DAT_80384ecc)[iVar1 * 4] == param3)) break;
    iVar1 = iVar1 + 1;
  }
  if ((&expgfxVar_80384ed4)[iVar1 * 8] == -1) {
    debugPrint("expgfx.c: addToTable usage overflow");
    return -1;
  }
  (&expgfxVar_80384ed4)[iVar1 * 8] = (&expgfxVar_80384ed4)[iVar1 * 8] + 1;
  return (int)(short)iVar1;
}


/* Library Function - Single Match
    expgfx_addremove
   
   Library: KioskDefault 0 0 */

void expgfx_addremove(uint param1) { //800DD68C
  if ((&expgfxVar_80384ed4)[(param1 & 0xff) * 8] == 0) {
    debugPrint("expgfx.c: mismatch in add/remove in exptab");
  }
  else {
    (&expgfxVar_80384ed4)[(param1 & 0xff) * 8] = (&expgfxVar_80384ed4)[(param1 & 0xff) * 8] + -1;
  }
  return;
}

