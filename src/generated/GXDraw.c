
/* Library Function - Single Match
    GXDrawTorus
   
   Library: KioskDefault 0 0 */

void GXDrawTorus(double fatness,uint param2,uint param3) { //8002BD4C
  int iVar1;
  uint uVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  uint local_c8 [2];
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  uint uStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
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
  
  _savefpr_23();
  dVar10 = 6.283185482025146;
  if (1.0 <= fatness) {
                    
    OSPanic("GXDraw.c",0x13c,"GXDrawTorus: doughnut too fat");
  }
  dVar6 = (double)(float)(1.0 - fatness);
  GXGetVtxDesc(0xd,local_c8);
  gxFn_8002bc90();
  if (local_c8[0] != 0) {
    GXSetVtxDesc(TEX0,1);
    GXSetVtxAttrFmt(3,0xd,1,4,0);
  }
  for (iVar3 = 0; iVar3 < (int)(param2 & 0xff); iVar3 = iVar3 + 1) {
    GXBegin(DRAW_TRISTRIP_0,3,(short)((param3 & 0xff) + 1) * 2);
    for (uVar2 = 0; (int)uVar2 <= (int)(param3 & 0xff); uVar2 = uVar2 + 1) {
      for (iVar1 = 1; -1 < iVar1; iVar1 = iVar1 + -1) {
        uStack_64 = (iVar3 + iVar1) - ((iVar3 + iVar1) / (int)(param2 & 0xff)) * (param2 & 0xff) ^
                    0x80000000;
        local_68 = 0x43300000;
        dVar9 = (double)(float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0);
        uStack_6c = uVar2 - ((int)uVar2 / (int)(param3 & 0xff)) * (param3 & 0xff) ^ 0x80000000;
        local_70 = 0x43300000;
        dVar8 = (double)(float)((double)CONCAT44(0x43300000,uStack_6c) - 4503601774854144.0);
        uStack_74 = param3 & 0xff;
        local_78 = 0x43300000;
        dVar4 = mathFn_800633b0((double)((float)(dVar8 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_74) -
                                               4503599627370496.0)));
        uStack_7c = param2 & 0xff;
        local_80 = 0x43300000;
        dVar5 = mathFn_800633b0((double)((float)(dVar9 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_7c) -
                                               4503599627370496.0)));
        dVar7 = (double)(float)((double)(float)(dVar6 - (double)(float)(fatness * dVar5)) * dVar4);
        uStack_84 = param3 & 0xff;
        local_88 = 0x43300000;
        dVar4 = mathFn_80063544((double)((float)(dVar8 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_84) -
                                               4503599627370496.0)));
        uStack_8c = param2 & 0xff;
        local_90 = 0x43300000;
        dVar5 = mathFn_800633b0((double)((float)(dVar9 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_8c) -
                                               4503599627370496.0)));
        dVar5 = (double)(float)((double)(float)(dVar6 - (double)(float)(fatness * dVar5)) * dVar4);
        uStack_94 = param2 & 0xff;
        local_98 = 0x43300000;
        dVar4 = mathFn_80063544((double)((float)(dVar9 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_94) -
                                               4503599627370496.0)));
        gxWrite_float_3(dVar7,dVar5,(double)(float)(fatness * dVar4));
        uStack_9c = param2 & 0xff;
        local_a0 = 0x43300000;
        dVar4 = mathFn_800633b0((double)((float)(dVar9 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_9c) -
                                               4503599627370496.0)));
        uStack_a4 = param3 & 0xff;
        local_a8 = 0x43300000;
        dVar5 = mathFn_800633b0((double)((float)(dVar8 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_a4) -
                                               4503599627370496.0)));
        dVar7 = (double)(float)(-dVar5 * dVar4);
        uStack_ac = param2 & 0xff;
        local_b0 = 0x43300000;
        dVar4 = mathFn_800633b0((double)((float)(dVar9 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_ac) -
                                               4503599627370496.0)));
        uStack_b4 = param3 & 0xff;
        local_b8 = 0x43300000;
        dVar5 = mathFn_80063544((double)((float)(dVar8 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_b4) -
                                               4503599627370496.0)));
        dVar5 = (double)(float)(-dVar5 * dVar4);
        uStack_bc = param2 & 0xff;
        local_c0 = 0x43300000;
        dVar4 = mathFn_80063544((double)((float)(dVar9 * dVar10) /
                                        (float)((double)CONCAT44(0x43300000,uStack_bc) -
                                               4503599627370496.0)));
        FUN_8002c828(dVar7,dVar5,dVar4);
        if (local_c8[0] != 0) {
          uStack_bc = iVar3 + iVar1 ^ 0x80000000;
          local_c0 = 0x43300000;
          uStack_b4 = param2 & 0xff;
          local_b8 = 0x43300000;
          uStack_ac = uVar2 ^ 0x80000000;
          local_b0 = 0x43300000;
          uStack_a4 = param3 & 0xff;
          local_a8 = 0x43300000;
          gxWrite_float_2((double)((float)((double)CONCAT44(0x43300000,uStack_bc) -
                                          4503601774854144.0) /
                                  (float)((double)CONCAT44(0x43300000,uStack_b4) -
                                         4503599627370496.0)),
                          (double)((float)((double)CONCAT44(0x43300000,uStack_ac) -
                                          4503601774854144.0) /
                                  (float)((double)CONCAT44(0x43300000,uStack_a4) -
                                         4503599627370496.0)));
        }
      }
    }
    GXEnd();
  }
  FUN_8002bd14();
  _restfpr_23();
  return;
}

