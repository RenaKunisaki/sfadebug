
/* Library Function - Single Match
    dspCtrlFn_80050f28
   
   Library: KioskDefault 0 0 */

void dspCtrlFn_80050f28(undefined4 param1,uint param2) { //80050F28
  bool bVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  bool bVar5;
  undefined *puVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  undefined2 *puVar10;
  uint uVar11;
  undefined *puVar12;
  byte bVar13;
  byte bVar14;
  undefined2 *puVar15;
  int **ppiVar16;
  int *piVar17;
  int *piVar18;
  int iVar19;
  undefined2 *puVar20;
  uint local_a4;
  int local_98;
  int local_94;
  byte local_90;
  byte local_8f;
  byte local_8e;
  byte local_88;
  uint local_78;
  int local_6c;
  short local_64;
  short local_62;
  undefined2 local_60 [2];
  undefined2 *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int *local_4c;
  byte local_48;
  byte local_47;
  
  local_78 = 0;
  PTR_DAT_8039864c = PTR_DAT_80398654;
  PTR_DAT_80398644 = PTR_DAT_80398654;
  PTR_DAT_80398648 = PTR_DAT_80398654 + 0x180;
  DAT_80398638 = (undefined *)0x0;
  if (param2 < 200) {
    puVar12 = (undefined *)0x28be;
  }
  else {
    puVar12 = (undefined *)((param2 - 200) * (busClockMhz / 2000000) + 0x28be);
  }
  if (DAT_80398658 != 0) {
    puVar12 = &DAT_0000afc8 + (int)puVar12;
  }
  bVar13 = 0;
  while( true ) {
    if (7 < bVar13) {
      if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 6) {
        *(undefined2 *)PTR_DAT_8039864c = 0xd;
        *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
        *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
        uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
        uVar7 = uVar2;
        if (DAT_80398638 != (undefined *)0x0) {
          *(ushort *)(DAT_80398638 + 6) = uVar2;
          DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
          uVar7 = dspVar_80398650;
        }
        dspVar_80398650 = uVar7;
        DAT_80398638 = PTR_DAT_8039864c;
        DAT_8039863c = PTR_DAT_80398644;
        PTR_DAT_8039864c = PTR_DAT_80398648;
        PTR_DAT_80398644 = PTR_DAT_80398648;
        PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
        DAT_80398640 = uVar2;
      }
      *(undefined2 *)PTR_DAT_8039864c = 7;
      *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398660 >> 0x10);
      *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398660;
      PTR_DAT_8039864c = PTR_DAT_8039864c + 6;
      for (bVar13 = 0; bVar13 < 8; bVar13 = bVar13 + 1) {
        if (((&DAT_80344170)[(uint)bVar13 * 0xbc] == '\x01') &&
           ((&DAT_80344171)[(uint)bVar13 * 0xbc] != '\0')) {
          if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 6) {
            *(undefined2 *)PTR_DAT_8039864c = 0xd;
            *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
            *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
            uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
            uVar7 = uVar2;
            if (DAT_80398638 != (undefined *)0x0) {
              *(ushort *)(DAT_80398638 + 6) = uVar2;
              DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
              uVar7 = dspVar_80398650;
            }
            dspVar_80398650 = uVar7;
            DAT_80398638 = PTR_DAT_8039864c;
            DAT_8039863c = PTR_DAT_80398644;
            PTR_DAT_8039864c = PTR_DAT_80398648;
            PTR_DAT_80398644 = PTR_DAT_80398648;
            PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
            DAT_80398640 = uVar2;
          }
          *(undefined2 *)PTR_DAT_8039864c = 9;
          *(short *)(PTR_DAT_8039864c + 2) =
               (short)((uint)(&PTR_DAT_80344148)[(uint)DAT_8039869e + (uint)bVar13 * 0x2f] >> 0x10);
          *(short *)(PTR_DAT_8039864c + 4) =
               (short)(&PTR_DAT_80344148)[(uint)DAT_8039869e + (uint)bVar13 * 0x2f];
          PTR_DAT_8039864c = PTR_DAT_8039864c + 6;
        }
      }
      if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 10) {
        *(undefined2 *)PTR_DAT_8039864c = 0xd;
        *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
        *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
        uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
        uVar7 = uVar2;
        if (DAT_80398638 != (undefined *)0x0) {
          *(ushort *)(DAT_80398638 + 6) = uVar2;
          DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
          uVar7 = dspVar_80398650;
        }
        dspVar_80398650 = uVar7;
        DAT_80398638 = PTR_DAT_8039864c;
        DAT_8039863c = PTR_DAT_80398644;
        PTR_DAT_8039864c = PTR_DAT_80398648;
        PTR_DAT_80398644 = PTR_DAT_80398648;
        PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
        DAT_80398640 = uVar2;
      }
      *(undefined2 *)PTR_DAT_8039864c = 0xe;
      *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398660 >> 0x10);
      *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398660;
      *(short *)(PTR_DAT_8039864c + 6) = (short)((uint)param1 >> 0x10);
      *(short *)(PTR_DAT_8039864c + 8) = (short)param1;
      puVar10 = (undefined2 *)(PTR_DAT_8039864c + 10);
      PTR_DAT_8039864c = PTR_DAT_8039864c + 0xc;
      *puVar10 = 0xf;
      uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 3U & 0xfffc;
      if (DAT_80398638 != (undefined *)0x0) {
        *(ushort *)(DAT_80398638 + 6) = uVar2;
        DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
        uVar2 = dspVar_80398650;
      }
      dspVar_80398650 = uVar2;
      DCStoreRangeNoSync(PTR_DAT_80398644,(int)PTR_DAT_8039864c - (int)PTR_DAT_80398644);
      if (DAT_80398630 < local_78) {
        DAT_80398630 = local_78;
      }
      return;
    }
    if ((&DAT_80344170)[(uint)bVar13 * 0xbc] == '\x01') break;
LAB_80052ce8:
    bVar13 = bVar13 + 1;
  }
  uVar4 = (uint)bVar13;
  ppiVar16 = (int **)(&PTR_DAT_80344120 + uVar4 * 0x2f);
  piVar18 = (int *)(&DAT_80344168)[uVar4 * 0x2f];
  while (piVar17 = piVar18, piVar17 != (int *)0x0) {
    local_4c = (int *)piVar17[3];
    if (((*(char *)((int)piVar17 + 0xd5) != '\0') || (piVar18 = local_4c, (piVar17[9] & 0x20U) != 0)
        ) && (FUN_80050cfc((int)ppiVar16,piVar17), piVar18 = local_4c,
             *(char *)(piVar17 + 0x35) != '\x01')) {
      salDeactivateVoice((int)piVar17);
      piVar18 = local_4c;
    }
  }
  for (piVar18 = (int *)(&DAT_8034416c)[uVar4 * 0x2f]; piVar18 != (int *)0x0;
      piVar18 = (int *)piVar18[5]) {
    FUN_80050cfc((int)ppiVar16,piVar18);
  }
  (&DAT_8034416c)[uVar4 * 0x2f] = 0;
  if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 6) {
    *(undefined2 *)PTR_DAT_8039864c = 0xd;
    *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
    *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
    uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
    uVar7 = uVar2;
    if (DAT_80398638 != (undefined *)0x0) {
      *(ushort *)(DAT_80398638 + 6) = uVar2;
      DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
      uVar7 = dspVar_80398650;
    }
    dspVar_80398650 = uVar7;
    DAT_80398638 = PTR_DAT_8039864c;
    DAT_8039863c = PTR_DAT_80398644;
    PTR_DAT_8039864c = PTR_DAT_80398648;
    PTR_DAT_80398644 = PTR_DAT_80398648;
    PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
    DAT_80398640 = uVar2;
  }
  *(undefined2 *)PTR_DAT_8039864c = 0;
  *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)*ppiVar16 >> 0x10);
  *(short *)(PTR_DAT_8039864c + 4) = (short)*ppiVar16;
  PTR_DAT_8039864c = PTR_DAT_8039864c + 6;
  puVar12 = puVar12 + 0x2c62;
  for (uVar11 = 0; uVar11 < (byte)(&DAT_80344172)[uVar4 * 0xbc]; uVar11 = uVar11 + 1) {
    if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 0xc) {
      *(undefined2 *)PTR_DAT_8039864c = 0xd;
      *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
      *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
      uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
      uVar7 = uVar2;
      if (DAT_80398638 != (undefined *)0x0) {
        *(ushort *)(DAT_80398638 + 6) = uVar2;
        DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
        uVar7 = dspVar_80398650;
      }
      dspVar_80398650 = uVar7;
      DAT_80398638 = PTR_DAT_8039864c;
      DAT_8039863c = PTR_DAT_80398644;
      PTR_DAT_8039864c = PTR_DAT_80398648;
      PTR_DAT_80398644 = PTR_DAT_80398648;
      PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
      DAT_80398640 = uVar2;
    }
    *(undefined2 *)PTR_DAT_8039864c = 1;
    *(short *)(PTR_DAT_8039864c + 2) =
         (short)((uint)(&PTR_DAT_80344148)
                       [(DAT_8039869e ^ 1) + (uint)*(byte *)(ppiVar16 + uVar11 * 3 + 0x16) * 0x2f]
                >> 0x10);
    *(short *)(PTR_DAT_8039864c + 4) =
         (short)(&PTR_DAT_80344148)
                [(DAT_8039869e ^ 1) + (uint)*(byte *)(ppiVar16 + uVar11 * 3 + 0x16) * 0x2f];
    *(undefined2 *)(PTR_DAT_8039864c + 6) = *(undefined2 *)((int)ppiVar16 + uVar11 * 0xc + 0x5a);
    *(undefined2 *)(PTR_DAT_8039864c + 8) = *(undefined2 *)(ppiVar16 + uVar11 * 3 + 0x17);
    *(undefined2 *)(PTR_DAT_8039864c + 10) = *(undefined2 *)((int)ppiVar16 + uVar11 * 0xc + 0x5e);
    PTR_DAT_8039864c = PTR_DAT_8039864c + 0xc;
    puVar12 = puVar12 + 0x294d;
  }
  puVar10 = (undefined2 *)0x0;
  local_58 = 0;
  for (iVar19 = (&DAT_80344168)[uVar4 * 0x2f]; iVar19 != 0; iVar19 = *(int *)(iVar19 + 0xc)) {
    (&DAT_80344700)[local_58] = iVar19;
    local_58 = local_58 + 1;
  }
  FUN_80050e1c(-0x7fcbb900,0,local_58 + -1);
  bVar5 = false;
  iVar19 = local_58;
LAB_80052618:
  if (0 < iVar19) {
    piVar18 = (int *)(&DAT_80344700)[iVar19 + -1];
    if (*(char *)(piVar18 + 0x35) == '\0') goto LAB_80052614;
    puVar20 = (undefined2 *)*piVar18;
    if (*(char *)(piVar18 + 0x35) != '\x01') {
      if (*(char *)(piVar18 + 0x23) == '\x04') {
        puVar20[0x5a] = (ushort)*(byte *)(piVar18[0x1e] + 3);
      }
      if ((piVar18[0x22] == 0) && ((uint)piVar18[0x20] <= (uint)piVar18[0x31])) {
        FUN_80053108((int)piVar18,0);
        salDeactivateVoice((int)piVar18);
      }
      else {
        if (((piVar18[9] & 0x10U) == 0) ||
           (iVar8 = FUN_8004f6a0((char *)(piVar18 + 0x24)), iVar8 == 0)) {
          bVar1 = (piVar18[9] & 1U) == 0;
          if (bVar1) {
            puVar20[10] = 0;
            puVar20[0xc] = 0;
            puVar20[0x18] = 0;
          }
          else {
            FUN_80050b38(puVar20 + 10,(short *)((int)piVar18 + 0x5e),*(short *)(piVar18 + 0x13));
            FUN_80050b38(puVar20 + 0xc,(short *)(piVar18 + 0x18),*(short *)((int)piVar18 + 0x4e));
            FUN_80050b38(puVar20 + 0x18,(short *)((int)piVar18 + 0x62),*(short *)(piVar18 + 0x14));
          }
          bVar1 = !bVar1;
          if ((piVar18[9] & 2U) == 0) {
            puVar20[0xe] = 0;
            puVar20[0x10] = 0;
            puVar20[0x1a] = 0;
            if (((puVar20[6] & 1) != 0) &&
               ((ushort)(puVar20[0x19] | puVar20[0xd] | puVar20[0xf]) == 0)) {
              puVar20[6] = puVar20[6] & 0xfffe;
            }
          }
          else {
            FUN_80050b38(puVar20 + 0xe,(short *)(piVar18 + 0x19),*(short *)((int)piVar18 + 0x52));
            FUN_80050b38(puVar20 + 0x10,(short *)((int)piVar18 + 0x66),*(short *)(piVar18 + 0x15));
            FUN_80050b38(puVar20 + 0x1a,(short *)(piVar18 + 0x1a),*(short *)((int)piVar18 + 0x56));
            if ((ushort)(puVar20[0x1a] | puVar20[0xe] | puVar20[0x10]) == 0) {
              if ((ushort)(puVar20[0x19] | puVar20[0xd] | puVar20[0xf]) == 0) {
                puVar20[6] = puVar20[6] & 0xfffe;
              }
              else {
                puVar20[6] = puVar20[6] | 1;
              }
            }
            else {
              puVar20[6] = puVar20[6] | 1;
              bVar1 = true;
            }
          }
          if ((piVar18[9] & 4U) == 0) {
            puVar20[0x12] = 0;
            puVar20[0x14] = 0;
            puVar20[0x16] = 0;
            if ((((&DAT_80344174)[uVar4 * 0x2f] == 0) && ((puVar20[6] & 2) != 0)) &&
               ((ushort)(puVar20[0x15] | puVar20[0x11] | puVar20[0x13]) == 0)) {
              puVar20[6] = puVar20[6] & 0xfffd;
            }
          }
          else {
            FUN_80050b38(puVar20 + 0x12,(short *)((int)piVar18 + 0x6a),*(short *)(piVar18 + 0x16));
            FUN_80050b38(puVar20 + 0x14,(short *)(piVar18 + 0x1b),*(short *)((int)piVar18 + 0x5a));
            FUN_80050b38(puVar20 + 0x16,(short *)((int)piVar18 + 0x6e),*(short *)(piVar18 + 0x17));
            if ((&DAT_80344174)[uVar4 * 0x2f] == 0) {
              if ((ushort)(puVar20[0x16] | puVar20[0x12] | puVar20[0x14]) == 0) {
                if ((ushort)(puVar20[0x15] | puVar20[0x11] | puVar20[0x13]) == 0) {
                  puVar20[6] = puVar20[6] & 0xfffd;
                }
                else {
                  puVar20[6] = puVar20[6] | 2;
                }
              }
              else {
                puVar20[6] = puVar20[6] | 2;
                bVar1 = true;
              }
            }
            else if ((puVar20[0x12] | puVar20[0x14]) != 0) {
              bVar1 = true;
            }
          }
          if (bVar1) {
            puVar20[6] = puVar20[6] | 8;
          }
          else {
            puVar20[6] = puVar20[6] & 0xfff7;
          }
          if ((&DAT_80344174)[uVar4 * 0x2f] == 0) {
            if ((((puVar20[0x17] == 0) && (puVar20[0x18] == 0)) &&
                ((puVar20[0x19] == 0 && ((puVar20[0x1a] == 0 && (puVar20[0x15] == 0)))))) &&
               (puVar20[0x16] == 0)) {
              puVar20[6] = puVar20[6] & 0xfffb;
            }
            else {
              puVar20[6] = puVar20[6] | 4;
            }
          }
          if ((piVar18[9] & 0x200U) != 0) {
            puVar20[0x20] = *(undefined2 *)(piVar18 + 0x2f);
            puVar20[0x21] = *(undefined2 *)((int)piVar18 + 0xbe);
          }
          if ((piVar18[9] & 0x100U) != 0) {
            puVar20[4] = *(undefined2 *)(piVar18 + 0x2e);
          }
          if ((piVar18[9] & 0x80U) != 0) {
            puVar20[5] = *(undefined2 *)((int)piVar18 + 0xba);
          }
          uVar11 = 0;
          bVar1 = false;
          piVar18[8] = *(int *)(puVar20 + 0x3d);
          goto LAB_80051f34;
        }
        FUN_80053108((int)piVar18,0);
        salDeactivateVoice((int)piVar18);
      }
      goto LAB_80052614;
    }
    *(undefined2 *)(*piVar18 + 0x66) = 0x8000;
    iVar8 = FUN_8004f6a0((char *)(piVar18 + 0x24));
    if (iVar8 != 0) {
      FUN_80053108((int)piVar18,0);
      salDeactivateVoice((int)piVar18);
      goto LAB_80052614;
    }
    puVar20[0x55] = 0;
    puVar20[0x56] = 0;
    puVar20[0x57] = 0;
    puVar20[0x58] = 0;
    puVar20[0x59] = 0;
    if ((piVar18[0x36] & 0x80000000U) == 0) {
      puVar20[0x1b] = 0;
    }
    else {
      memset_((void *)piVar18[2],0,0x40);
      DCFlushRange((void *)piVar18[2],0x40);
      puVar20[0x20] = *(undefined2 *)(piVar18 + 0x2f);
      puVar20[0x1e] = *(undefined2 *)(piVar18 + 0x2f);
      puVar20[0x21] = *(undefined2 *)((int)piVar18 + 0xbe);
      puVar20[0x1f] = *(undefined2 *)((int)piVar18 + 0xbe);
      puVar20[0x1b] = 1;
    }
    bVar14 = *(byte *)(piVar18 + 0x23);
    if (bVar14 == 2) {
      puVar20[0x38] = 10;
      puVar20[0x4f] = 0x800;
      for (local_90 = 0; local_90 < 8; local_90 = local_90 + 1) {
        puVar20[(uint)local_90 * 2 + 0x3f] = 0;
        puVar20[(uint)local_90 * 2 + 0x40] = 0;
      }
      uVar11 = (uint)piVar18[0x1d] >> 1;
      local_54 = piVar18[0x1f] + uVar11;
      piVar18[0x31] = piVar18[0x1f];
      piVar18[0x32] = 0;
    }
    else if (bVar14 < 2) {
      if (bVar14 == 0) {
LAB_8005146c:
        puVar20[0x38] = 0;
        puVar20[0x4f] = 0;
        iVar8 = piVar18[0x1e];
        puVar20[0x52] = 0;
        puVar20[0x51] = 0;
        puVar20[0x50] = (ushort)*(byte *)(iVar8 + 2);
        puVar20[0x5c] = *(undefined2 *)(iVar8 + 4);
        puVar20[0x5b] = *(undefined2 *)(iVar8 + 6);
        puVar20[0x5a] = (ushort)*(byte *)(iVar8 + 3);
        for (local_88 = 0; local_88 < 8; local_88 = local_88 + 1) {
          puVar20[(uint)local_88 * 2 + 0x3f] = *(undefined2 *)(iVar8 + (uint)local_88 * 4 + 8);
          puVar20[(uint)local_88 * 2 + 0x40] = *(undefined2 *)(iVar8 + (uint)local_88 * 4 + 10);
        }
        uVar11 = piVar18[0x1d] * 2;
        local_54 = uVar11 + 2;
        piVar18[0x32] = 0;
        piVar18[0x31] = 0;
        if (*(char *)(piVar18 + 0x23) == '\x04') {
          puVar20[8] = 1;
        }
        else {
          puVar20[8] = 0;
        }
      }
      else {
        if (false) {
LAB_80051788:
                    
          OSPanic("hw_dspctrl.c",0x409,"Failed assertion FALSE");
        }
        puVar20[0x38] = 0;
        puVar20[0x4f] = 0;
        uVar9 = (piVar18[0x1f] + 0xdU) / 0xe;
        iVar8 = piVar18[0x1e];
        puVar20[0x52] = *(undefined2 *)(iVar8 + uVar9 * 6 + 0x28);
        puVar20[0x51] = *(undefined2 *)(iVar8 + uVar9 * 6 + 0x2a);
        puVar20[0x50] = (ushort)*(byte *)(iVar8 + uVar9 * 6 + 0x2c);
        puVar20[0x5c] = *(undefined2 *)(iVar8 + 4);
        puVar20[0x5b] = *(undefined2 *)(iVar8 + 6);
        puVar20[0x5a] = (ushort)*(byte *)(iVar8 + 3);
        for (local_8e = 0; local_8e < 8; local_8e = local_8e + 1) {
          puVar20[(uint)local_8e * 2 + 0x3f] = *(undefined2 *)(iVar8 + (uint)local_8e * 4 + 8);
          puVar20[(uint)local_8e * 2 + 0x40] = *(undefined2 *)(iVar8 + (uint)local_8e * 4 + 10);
        }
        uVar11 = piVar18[0x1d] * 2;
        local_54 = uVar11 + uVar9 * 0x10 + 2;
        piVar18[0x31] = uVar9 * 0xe;
        piVar18[0x32] = 0;
      }
    }
    else {
      if (bVar14 == 4) goto LAB_8005146c;
      if (3 < bVar14) goto LAB_80051788;
      puVar20[0x38] = 0x19;
      puVar20[0x4f] = 0x100;
      for (local_8f = 0; local_8f < 8; local_8f = local_8f + 1) {
        puVar20[(uint)local_8f * 2 + 0x3f] = 0;
        puVar20[(uint)local_8f * 2 + 0x40] = 0;
      }
      uVar11 = piVar18[0x1d];
      local_54 = piVar18[0x1f] + uVar11;
      piVar18[0x31] = piVar18[0x1f];
      piVar18[0x32] = 0;
    }
    puVar20[0x3d] = (short)((uint)local_54 >> 0x10);
    puVar20[0x3e] = (short)local_54;
    piVar18[8] = local_54;
    if (piVar18[0x22] == 0) {
      puVar20[0x37] = 0;
      bVar14 = *(byte *)(piVar18 + 0x23);
      if (bVar14 == 3) {
        local_50 = uVar11 + piVar18[0x20];
        local_a4 = DAT_80398634;
      }
      else if (bVar14 < 3) {
        if (bVar14 < 2) {
          if (true) goto LAB_80051914;
        }
        else {
          local_50 = uVar11 + piVar18[0x20];
          local_a4 = DAT_80398634 >> 1;
        }
      }
      else if (bVar14 < 5) {
LAB_80051914:
        local_50 = uVar11 + ((uint)piVar18[0x20] / 0xe) * 2 + 2 + piVar18[0x20];
        local_a4 = DAT_80398634 * 2 + 2;
      }
      puVar20[0x39] = (short)(local_a4 >> 0x10);
      puVar20[0x3a] = (short)local_a4;
      puVar20[0x3b] = (short)((uint)local_50 >> 0x10);
      puVar20[0x3c] = (short)local_50;
    }
    else {
      puVar20[0x37] = 1;
      bVar14 = *(byte *)(piVar18 + 0x23);
      if ((bVar14 == 4) || (((bVar14 < 4 && (bVar14 < 2)) && (true)))) {
        local_98 = ((uint)piVar18[0x21] / 0xe) * 2 + 2 + piVar18[0x21];
        uVar9 = piVar18[0x21] + piVar18[0x22] + -1;
        local_94 = (uVar9 / 0xe) * 0x10 + 2 + uVar9 % 0xe;
      }
      else {
        local_98 = piVar18[0x21];
        local_94 = piVar18[0x21] + piVar18[0x22] + -1;
      }
      local_94 = uVar11 + local_94;
      local_98 = uVar11 + local_98;
      *(int *)(puVar20 + 0x39) = local_98;
      *(int *)(puVar20 + 0x3b) = local_94;
    }
    puVar20[4] = *(undefined2 *)(piVar18 + 0x2e);
    puVar20[5] = *(undefined2 *)((int)piVar18 + 0xba);
    uVar11 = (uint)*(byte *)(piVar18 + 0x30);
    puVar20[7] = (ushort)(*(byte *)(piVar18 + 0x30) == 0);
    *(undefined2 *)((int)piVar18 + 0x5e) = *(undefined2 *)(piVar18 + 0x13);
    puVar20[9] = *(undefined2 *)(piVar18 + 0x13);
    *(undefined2 *)(piVar18 + 0x18) = *(undefined2 *)((int)piVar18 + 0x4e);
    puVar20[0xb] = *(undefined2 *)((int)piVar18 + 0x4e);
    *(undefined2 *)((int)piVar18 + 0x62) = *(undefined2 *)(piVar18 + 0x14);
    puVar20[0x17] = *(undefined2 *)(piVar18 + 0x14);
    *(undefined2 *)(piVar18 + 0x19) = *(undefined2 *)((int)piVar18 + 0x52);
    puVar20[0xd] = *(undefined2 *)((int)piVar18 + 0x52);
    *(undefined2 *)((int)piVar18 + 0x66) = *(undefined2 *)(piVar18 + 0x15);
    puVar20[0xf] = *(undefined2 *)(piVar18 + 0x15);
    *(undefined2 *)(piVar18 + 0x1a) = *(undefined2 *)((int)piVar18 + 0x56);
    puVar20[0x19] = *(undefined2 *)((int)piVar18 + 0x56);
    puVar20[6] = (ushort)((ushort)(puVar20[0x19] | puVar20[0xd] | puVar20[0xf]) != 0);
    *(undefined2 *)((int)piVar18 + 0x6a) = *(undefined2 *)(piVar18 + 0x16);
    puVar20[0x11] = *(undefined2 *)(piVar18 + 0x16);
    *(undefined2 *)(piVar18 + 0x1b) = *(undefined2 *)((int)piVar18 + 0x5a);
    puVar20[0x13] = *(undefined2 *)((int)piVar18 + 0x5a);
    *(undefined2 *)((int)piVar18 + 0x6e) = *(undefined2 *)(piVar18 + 0x17);
    puVar20[0x15] = *(undefined2 *)(piVar18 + 0x17);
    puVar20[10] = 0;
    puVar20[0xc] = 0;
    puVar20[0x18] = 0;
    puVar20[0xe] = 0;
    puVar20[0x10] = 0;
    puVar20[0x1a] = 0;
    puVar20[0x12] = 0;
    puVar20[0x14] = 0;
    puVar20[0x16] = 0;
    if ((&DAT_80344174)[uVar4 * 0x2f] == 0) {
      if ((ushort)(puVar20[0x15] | puVar20[0x11] | puVar20[0x13]) != 0) {
        puVar20[6] = puVar20[6] | 2;
      }
      if ((ushort)(puVar20[0x15] | puVar20[0x17] | puVar20[0x19]) != 0) {
        puVar20[6] = puVar20[6] | 4;
      }
    }
    else {
      puVar20[6] = puVar20[6] | 0x10;
    }
    *(undefined *)(piVar18 + 0x35) = 2;
    bVar1 = true;
LAB_80051f34:
    if ((piVar18[uVar11 + 9] & 0x40U) != 0) {
      FUN_8004f838((byte *)(piVar18 + 0x24));
    }
    if ((piVar18[uVar11 + 9] & 8U) != 0) {
      puVar20[0x53] = (short)((uint)piVar18[uVar11 + 0xe] >> 0x10);
      puVar20[0x54] = (short)piVar18[uVar11 + 0xe];
      piVar18[0x33] = piVar18[uVar11 + 0xe];
    }
    local_6c = FUN_8004f88c((char *)(piVar18 + 0x24),puVar20 + 0x32,puVar20 + 0x33);
    local_64 = puVar20[0x33];
    for (bVar14 = 0; bVar14 < 5; bVar14 = bVar14 + 1) {
      puVar20[bVar14 + 0x22] = 0;
    }
    puVar15 = (undefined2 *)piVar18[1];
    local_5c = (undefined2 *)(piVar18[1] + 0x80);
    if (uVar11 != 0) {
      if (local_5c < puVar15 + 2) {
                    
        OSPanic("hw_dspctrl.c",0x5bf,s_Failed_assertion__pptr_2_<_pend_802e1c40);
      }
      *puVar15 = 7;
      puVar15[1] = 1;
      puVar15 = puVar15 + 2;
      puVar20[uVar11 + 0x22] = puVar20[uVar11 + 0x22] + 1;
    }
    FUN_80050b68(piVar18);
    while (uVar11 = uVar11 + 1, (uVar11 & 0xff) < 5) {
      if (local_6c != 0) {
        if (local_5c < puVar15 + 2) {
                    
          OSPanic("hw_dspctrl.c",0x5d2,s_Failed_assertion__pptr_2_<_pend_802e1c40);
        }
        *puVar15 = 7;
        puVar15[1] = 0;
        puVar15 = puVar15 + 2;
        iVar8 = (uVar11 * 2 & 0x1fe) + 0x44;
        *(short *)((int)puVar20 + iVar8) = *(short *)((int)puVar20 + iVar8) + 1;
        FUN_80053108((int)piVar18,0);
        salDeactivateVoice((int)piVar18);
        break;
      }
      if ((*(uint *)((int)piVar18 + (uVar11 * 4 & 0x3fc) + 0x24) & 0x20) != 0) {
        FUN_8004f6d8();
        *(undefined *)((int)piVar18 + 0xd5) = 1;
      }
      if (*(char *)((int)piVar18 + 0xd5) == '\0') {
        if ((*(uint *)((int)piVar18 + (uVar11 * 4 & 0x3fc) + 0x24) & 0x40) != 0) {
          FUN_8004f838((byte *)(piVar18 + 0x24));
        }
        if ((*(uint *)((int)piVar18 + (uVar11 * 4 & 0x3fc) + 0x24) & 8) != 0) {
          if (local_5c < puVar15 + 4) {
                    
            OSPanic("hw_dspctrl.c",0x5f4,s_Failed_assertion__pptr_4_<_pend_802e1c60);
          }
          *puVar15 = 0x53;
          puVar15[1] = (short)((uint)*(undefined4 *)((int)piVar18 + (uVar11 * 4 & 0x3fc) + 0x38) >>
                              0x10);
          puVar15[2] = 0x54;
          puVar15[3] = (short)*(undefined4 *)((int)piVar18 + (uVar11 * 4 & 0x3fc) + 0x38);
          puVar15 = puVar15 + 4;
          iVar8 = (uVar11 * 2 & 0x1fe) + 0x44;
          *(short *)((int)puVar20 + iVar8) = *(short *)((int)puVar20 + iVar8) + 2;
          piVar18[0x33] = *(int *)((int)piVar18 + (uVar11 * 4 & 0x3fc) + 0x38);
        }
      }
      iVar8 = piVar18[0x28];
      local_6c = FUN_8004f88c((char *)(piVar18 + 0x24),local_60,&local_62);
      if (local_64 == local_62) {
        if (iVar8 != 0) {
          if (local_5c < puVar15 + 2) {
                    
            OSPanic("hw_dspctrl.c",0x60f,s_Failed_assertion__pptr_2_<_pend_802e1c40);
          }
          *puVar15 = 0x32;
          puVar15[1] = local_60[0];
          puVar15 = puVar15 + 2;
          iVar8 = (uVar11 * 2 & 0x1fe) + 0x44;
          *(short *)((int)puVar20 + iVar8) = *(short *)((int)puVar20 + iVar8) + 1;
        }
      }
      else {
        if (local_5c < puVar15 + 4) {
                    
          OSPanic("hw_dspctrl.c",0x61e,s_Failed_assertion__pptr_4_<_pend_802e1c60);
        }
        *puVar15 = 0x32;
        puVar15[1] = local_60[0];
        puVar15[2] = 0x33;
        puVar15[3] = local_62;
        puVar15 = puVar15 + 4;
        iVar8 = (uVar11 * 2 & 0x1fe) + 0x44;
        *(short *)((int)puVar20 + iVar8) = *(short *)((int)puVar20 + iVar8) + 2;
        local_64 = local_62;
      }
      FUN_80050b68(piVar18);
    }
    if (local_6c != 0) {
      FUN_80053108((int)piVar18,0);
      salDeactivateVoice((int)piVar18);
    }
    DCStoreRangeNoSync((void *)piVar18[1],(int)puVar15 - piVar18[1]);
    if ((1 < (ushort)puVar20[0x53]) || (false)) {
      uVar2 = *(ushort *)(&DAT_802e1c10 + (uint)(ushort)puVar20[4] * 2);
    }
    else {
      uVar2 = *(ushort *)
               ((uint)(ushort)puVar20[0x53] * 6 + (uint)(ushort)puVar20[4] * 2 + -0x7fd1e3fc);
    }
    puVar12 = puVar12 + (uint)uVar2 +
                        *(ushort *)(&DAT_802e1be4 + (uint)(ushort)puVar20[6] * 2) + 0x4fe;
    for (bVar14 = 0; bVar14 < 5; bVar14 = bVar14 + 1) {
      puVar12 = puVar12 + (uint)(ushort)puVar20[bVar14 + 0x22] * 4;
    }
    if (puVar12 <= (undefined *)(busClockMhz / 400)) {
      uVar3 = (undefined2)((uint)puVar20 >> 0x10);
      if (puVar10 == (undefined2 *)0x0) {
        if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 6) {
          *(undefined2 *)PTR_DAT_8039864c = 0xd;
          *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
          *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
          uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
          uVar7 = uVar2;
          if (DAT_80398638 != (undefined *)0x0) {
            *(ushort *)(DAT_80398638 + 6) = uVar2;
            DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
            uVar7 = dspVar_80398650;
          }
          dspVar_80398650 = uVar7;
          DAT_80398638 = PTR_DAT_8039864c;
          DAT_8039863c = PTR_DAT_80398644;
          PTR_DAT_8039864c = PTR_DAT_80398648;
          PTR_DAT_80398644 = PTR_DAT_80398648;
          PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
          DAT_80398640 = uVar2;
        }
        *(undefined2 *)PTR_DAT_8039864c = 2;
        *(undefined2 *)(PTR_DAT_8039864c + 2) = uVar3;
        *(short *)(PTR_DAT_8039864c + 4) = (short)puVar20;
        PTR_DAT_8039864c = PTR_DAT_8039864c + 6;
      }
      else {
        *puVar10 = uVar3;
        puVar10[1] = (short)puVar20;
        DCFlushRange(puVar10,0xba);
      }
      local_78 = local_78 + 1;
      bVar5 = true;
      puVar10 = puVar20;
      goto LAB_80052614;
    }
    if ((!bVar1) && (local_6c == 0)) {
      FUN_80050cfc((int)ppiVar16,piVar18);
    }
    salDeactivateVoice((int)piVar18);
    FUN_80053108((int)piVar18,1);
    while (bVar14 = bVar13, 0 < iVar19 + -1) {
      if (*(char *)((&DAT_80344700)[iVar19 + -2] + 0xd4) == '\x02') {
        FUN_80050cfc((int)ppiVar16,(int *)(&DAT_80344700)[iVar19 + -2]);
      }
      salDeactivateVoice((&DAT_80344700)[iVar19 + -2]);
      FUN_80053108((&DAT_80344700)[iVar19 + -2],1);
      iVar19 = iVar19 + -1;
    }
    while (local_47 = bVar14 + 1, local_47 < 8) {
      bVar14 = local_47;
      if ((&DAT_80344170)[(uint)local_47 * 0xbc] == '\x01') {
        piVar18 = (int *)(&DAT_80344168)[(uint)local_47 * 0x2f];
        while (bVar14 = local_47, piVar18 != (int *)0x0) {
          local_4c = (int *)piVar18[3];
          if (*(char *)(piVar18 + 0x35) == '\x02') {
            FUN_80050cfc((int)(&PTR_DAT_80344120 + (uint)local_47 * 0x2f),piVar18);
          }
          salDeactivateVoice((int)piVar18);
          FUN_80053108((int)piVar18,1);
          piVar18 = local_4c;
        }
      }
    }
  }
  if (bVar5) {
    if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 2) {
      *(undefined2 *)PTR_DAT_8039864c = 0xd;
      *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
      *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
      uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
      uVar7 = uVar2;
      if (DAT_80398638 != (undefined *)0x0) {
        *(ushort *)(DAT_80398638 + 6) = uVar2;
        DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
        uVar7 = dspVar_80398650;
      }
      dspVar_80398650 = uVar7;
      DAT_80398638 = PTR_DAT_8039864c;
      DAT_8039863c = PTR_DAT_80398644;
      PTR_DAT_8039864c = PTR_DAT_80398648;
      PTR_DAT_80398644 = PTR_DAT_80398648;
      PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
      DAT_80398640 = uVar2;
    }
    puVar6 = PTR_DAT_8039864c + 2;
    *(undefined2 *)PTR_DAT_8039864c = 3;
    PTR_DAT_8039864c = puVar6;
  }
  if (puVar10 != (undefined2 *)0x0) {
    *puVar10 = 0;
    puVar10[1] = 0;
    DCFlushRange(puVar10,0xba);
  }
  local_48 = (char)(DAT_8039869d + 1) + (char)((DAT_8039869d + 1) / 3) * -3;
  if ((&PTR_reverbFxCb_803441cc)[uVar4 * 0x2f] != (undefined *)0x0) {
    if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 10) {
      *(undefined2 *)PTR_DAT_8039864c = 0xd;
      *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
      *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
      uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
      uVar7 = uVar2;
      if (DAT_80398638 != (undefined *)0x0) {
        *(ushort *)(DAT_80398638 + 6) = uVar2;
        DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
        uVar7 = dspVar_80398650;
      }
      dspVar_80398650 = uVar7;
      DAT_80398638 = PTR_DAT_8039864c;
      DAT_8039863c = PTR_DAT_80398644;
      PTR_DAT_8039864c = PTR_DAT_80398648;
      PTR_DAT_80398644 = PTR_DAT_80398648;
      PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
      DAT_80398640 = uVar2;
    }
    *(undefined2 *)PTR_DAT_8039864c = 4;
    *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)ppiVar16[DAT_8039869d + 0xc] >> 0x10);
    *(short *)(PTR_DAT_8039864c + 4) = (short)ppiVar16[DAT_8039869d + 0xc];
    *(short *)(PTR_DAT_8039864c + 6) = (short)((uint)ppiVar16[local_48 + 0xc] >> 0x10);
    *(short *)(PTR_DAT_8039864c + 8) = (short)ppiVar16[local_48 + 0xc];
    PTR_DAT_8039864c = PTR_DAT_8039864c + 10;
  }
  if ((&DAT_80344174)[uVar4 * 0x2f] == 0) {
    if ((&PTR_chorusFxCb_803441d0)[uVar4 * 0x2f] != (undefined *)0x0) {
      if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 10) {
        *(undefined2 *)PTR_DAT_8039864c = 0xd;
        *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
        *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
        uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
        uVar7 = uVar2;
        if (DAT_80398638 != (undefined *)0x0) {
          *(ushort *)(DAT_80398638 + 6) = uVar2;
          DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
          uVar7 = dspVar_80398650;
        }
        dspVar_80398650 = uVar7;
        DAT_80398638 = PTR_DAT_8039864c;
        DAT_8039863c = PTR_DAT_80398644;
        PTR_DAT_8039864c = PTR_DAT_80398648;
        PTR_DAT_80398644 = PTR_DAT_80398648;
        PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
        DAT_80398640 = uVar2;
      }
      *(undefined2 *)PTR_DAT_8039864c = 5;
      *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)ppiVar16[DAT_8039869d + 0xf] >> 0x10);
      *(short *)(PTR_DAT_8039864c + 4) = (short)ppiVar16[DAT_8039869d + 0xf];
      *(short *)(PTR_DAT_8039864c + 6) = (short)((uint)ppiVar16[local_48 + 0xf] >> 0x10);
      *(short *)(PTR_DAT_8039864c + 8) = (short)ppiVar16[local_48 + 0xf];
      PTR_DAT_8039864c = PTR_DAT_8039864c + 10;
    }
  }
  else {
    if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 10) {
      *(undefined2 *)PTR_DAT_8039864c = 0xd;
      *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
      *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
      uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
      uVar7 = uVar2;
      if (DAT_80398638 != (undefined *)0x0) {
        *(ushort *)(DAT_80398638 + 6) = uVar2;
        DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
        uVar7 = dspVar_80398650;
      }
      dspVar_80398650 = uVar7;
      DAT_80398638 = PTR_DAT_8039864c;
      DAT_8039863c = PTR_DAT_80398644;
      PTR_DAT_8039864c = PTR_DAT_80398648;
      PTR_DAT_80398644 = PTR_DAT_80398648;
      PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
      DAT_80398640 = uVar2;
    }
    *(undefined2 *)PTR_DAT_8039864c = 0x10;
    *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)ppiVar16[DAT_8039869e + 0xf] >> 0x10);
    *(short *)(PTR_DAT_8039864c + 4) = (short)ppiVar16[DAT_8039869e + 0xf];
    *(short *)(PTR_DAT_8039864c + 6) = (short)((uint)ppiVar16[(DAT_8039869e ^ 1) + 0xf] >> 0x10);
    *(short *)(PTR_DAT_8039864c + 8) = (short)ppiVar16[(DAT_8039869e ^ 1) + 0xf];
    PTR_DAT_8039864c = PTR_DAT_8039864c + 10;
  }
  if (PTR_DAT_80398648 + -8 < PTR_DAT_8039864c + 6) {
    *(undefined2 *)PTR_DAT_8039864c = 0xd;
    *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)PTR_DAT_80398648 >> 0x10);
    *(short *)(PTR_DAT_8039864c + 4) = (short)PTR_DAT_80398648;
    uVar2 = ((short)PTR_DAT_8039864c - (short)PTR_DAT_80398644) + 0xbU & 0xfffc;
    uVar7 = uVar2;
    if (DAT_80398638 != (undefined *)0x0) {
      *(ushort *)(DAT_80398638 + 6) = uVar2;
      DCStoreRangeNoSync(DAT_8039863c,(uint)DAT_80398640);
      uVar7 = dspVar_80398650;
    }
    dspVar_80398650 = uVar7;
    DAT_80398638 = PTR_DAT_8039864c;
    DAT_8039863c = PTR_DAT_80398644;
    PTR_DAT_8039864c = PTR_DAT_80398648;
    PTR_DAT_80398644 = PTR_DAT_80398648;
    PTR_DAT_80398648 = PTR_DAT_80398648 + 0x180;
    DAT_80398640 = uVar2;
  }
  *(undefined2 *)PTR_DAT_8039864c = 6;
  *(short *)(PTR_DAT_8039864c + 2) = (short)((uint)ppiVar16[DAT_8039869e + 10] >> 0x10);
  *(short *)(PTR_DAT_8039864c + 4) = (short)ppiVar16[DAT_8039869e + 10];
  PTR_DAT_8039864c = PTR_DAT_8039864c + 6;
  piVar18 = *ppiVar16;
  FUN_80050c4c(piVar18,(short *)(piVar18 + 1),&DAT_80344124 + uVar4 * 0x2f);
  FUN_80050c4c((int *)((int)piVar18 + 6),(short *)((int)piVar18 + 10),&DAT_80344128 + uVar4 * 0x2f);
  FUN_80050c4c(piVar18 + 3,(short *)(piVar18 + 4),&DAT_8034412c + uVar4 * 0x2f);
  FUN_80050c4c((int *)((int)piVar18 + 0x12),(short *)((int)piVar18 + 0x16),
               &DAT_80344130 + uVar4 * 0x2f);
  FUN_80050c4c(piVar18 + 6,(short *)(piVar18 + 7),&DAT_80344134 + uVar4 * 0x2f);
  FUN_80050c4c((int *)((int)piVar18 + 0x1e),(short *)((int)piVar18 + 0x22),
               &DAT_80344138 + uVar4 * 0x2f);
  FUN_80050c4c(piVar18 + 9,(short *)(piVar18 + 10),&DAT_8034413c + uVar4 * 0x2f);
  FUN_80050c4c((int *)((int)piVar18 + 0x2a),(short *)((int)piVar18 + 0x2e),
               &DAT_80344140 + uVar4 * 0x2f);
  FUN_80050c4c(piVar18 + 0xc,(short *)(piVar18 + 0xd),&DAT_80344144 + uVar4 * 0x2f);
  DCFlushRange(piVar18,0x36);
  goto LAB_80052ce8;
LAB_80052614:
  iVar19 = iVar19 + -1;
  goto LAB_80052618;
}

