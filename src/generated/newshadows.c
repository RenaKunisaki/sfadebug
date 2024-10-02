
/* Library Function - Single Match
    shadowLiftPlaneFn_800b46c0
   
   Library: KioskDefault 0 0 */

void shadowLiftPlaneFn_800b46c0
               (double param1,double param2,int param3,int param4,int param5,float *param6,
               undefined4 param_7,undefined4 param_8,int param9) { //800B46C0
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  uint local_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  
  _savefpr_30();
  dVar7 = (double)*(float *)(param3 + 0xc);
  dVar6 = (double)*(float *)(param3 + 0x14);
  if (*(int *)(param3 + 0x30) == 0) {
    dVar7 = (double)(float)(dVar7 - (double)(float)param1);
    dVar6 = (double)(float)(dVar6 - (double)(float)param2);
  }
  pfVar1 = FUN_800b4d00(&local_a4);
  pfVar2 = pfVar1 + local_a4 * 4;
  iVar5 = 0;
  local_a4 = 0;
  iVar3 = 0;
  if (param9 == 0) {
    bVar4 = 8;
  }
  else {
    bVar4 = 4;
  }
  for (; pfVar1 < pfVar2; pfVar1 = pfVar1 + 4) {
    if (*pfVar1 == *(float *)(param3 + 0x30)) {
      local_a4 = (uint)*(short *)(pfVar1 + 1);
      while ((((int)local_a4 < (int)*(short *)(pfVar1 + 5) && (iVar5 < 300)) && (iVar3 < 0x4b0))) {
        if ((bVar4 & *(byte *)(param4 + local_a4 * 0x34 + 0x2f)) != 0) {
          uStack_44 = (int)*(short *)(param4 + local_a4 * 0x34 + 10) ^ 0x80000000;
          local_48 = 0x43300000;
          *param6 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_44) -
                                           4503601774854144.0) - dVar7);
          uStack_4c = (int)*(short *)(param4 + local_a4 * 0x34 + 0x10) ^ 0x80000000;
          local_50 = 0x43300000;
          param6[1] = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0) -
                      *(float *)(param3 + 0x10);
          uStack_54 = (int)*(short *)(param4 + local_a4 * 0x34 + 0x16) ^ 0x80000000;
          local_58 = 0x43300000;
          param6[2] = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_54) -
                                             4503601774854144.0) - dVar6);
          uStack_5c = (int)*(short *)(param4 + local_a4 * 0x34 + 0xc) ^ 0x80000000;
          local_60 = 0x43300000;
          param6[3] = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_5c) -
                                             4503601774854144.0) - dVar7);
          uStack_64 = (int)*(short *)(param4 + local_a4 * 0x34 + 0x12) ^ 0x80000000;
          local_68 = 0x43300000;
          param6[4] = (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0) -
                      *(float *)(param3 + 0x10);
          uStack_6c = (int)*(short *)(param4 + local_a4 * 0x34 + 0x18) ^ 0x80000000;
          local_70 = 0x43300000;
          param6[5] = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_6c) -
                                             4503601774854144.0) - dVar6);
          uStack_74 = (int)*(short *)(param4 + local_a4 * 0x34 + 0xe) ^ 0x80000000;
          local_78 = 0x43300000;
          param6[6] = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_74) -
                                             4503601774854144.0) - dVar7);
          uStack_7c = (int)*(short *)(param4 + local_a4 * 0x34 + 0x14) ^ 0x80000000;
          local_80 = 0x43300000;
          param6[7] = (float)((double)CONCAT44(0x43300000,uStack_7c) - 4503601774854144.0) -
                      *(float *)(param3 + 0x10);
          uStack_84 = (int)*(short *)(param4 + local_a4 * 0x34 + 0x1a) ^ 0x80000000;
          local_88 = 0x43300000;
          param6[8] = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_84) -
                                             4503601774854144.0) - dVar6);
          param6 = param6 + 9;
          iVar3 = iVar3 + 3;
          uStack_8c = (int)*(short *)(param4 + local_a4 * 0x34 + 4) ^ 0x80000000;
          local_90 = 0x43300000;
          *(float *)(param5 + iVar5 * 0x14) =
               (float)((double)CONCAT44(0x43300000,uStack_8c) - 4503601774854144.0) * 3.051851e-05;
          uStack_94 = (int)*(short *)(param4 + local_a4 * 0x34 + 6) ^ 0x80000000;
          local_98 = 0x43300000;
          *(float *)(param5 + iVar5 * 0x14 + 4) =
               (float)((double)CONCAT44(0x43300000,uStack_94) - 4503601774854144.0) * 3.051851e-05;
          uStack_9c = (int)*(short *)(param4 + local_a4 * 0x34 + 8) ^ 0x80000000;
          local_a0 = 0x43300000;
          *(float *)(param5 + iVar5 * 0x14 + 8) =
               (float)((double)CONCAT44(0x43300000,uStack_9c) - 4503601774854144.0) * 3.051851e-05;
          *(undefined *)(param5 + iVar5 * 0x14 + 0x10) =
               *(undefined *)(param4 + local_a4 * 0x34 + 0x2f);
          if (300 < iVar5) {
            printf("newshadows.c: max lift planes exceeded");
          }
          iVar5 = iVar5 + 1;
        }
        local_a4 = local_a4 + 1;
      }
    }
  }
  _restfpr_30();
  return;
}

