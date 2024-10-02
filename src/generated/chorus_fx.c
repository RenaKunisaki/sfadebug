
/* Library Function - Single Match
    chorusFxFn_8005a41c
   
   Library: KioskDefault 0 0 */

void chorusFxCb_8005a41c(char param1,undefined4 *param2,undefined4 *param3) { //8005A41C
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  if (param1 != '\x01') {
    if ((param1 != '\0') || (false)) {
                    
      OSPanic("chorus_fx.c",0x3cd,"Failed assertion FALSE");
    }
    uVar1 = (*(byte *)(param3 + 9) + 1) % 3;
    puVar9 = (undefined4 *)param3[uVar1];
    puVar8 = (undefined4 *)param3[uVar1 + 3];
    puVar7 = (undefined4 *)param3[uVar1 + 6];
    puVar6 = (undefined4 *)*param2;
    puVar5 = (undefined4 *)param2[1];
    puVar4 = (undefined4 *)param2[2];
    for (uVar10 = 0; uVar10 < 0xa0; uVar10 = uVar10 + 1) {
      uVar2 = *puVar6;
      puVar6 = puVar6 + 1;
      *puVar9 = uVar2;
      puVar9 = puVar9 + 1;
      uVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      *puVar8 = uVar2;
      puVar8 = puVar8 + 1;
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar7 = uVar2;
      puVar7 = puVar7 + 1;
    }
    param3[0x21] = ((int)param3[0x18] >> 0x10) + 1;
    param3[0x20] = param3[0x18] << 0x10;
    iVar3 = param3[0x19];
    param3[0x19] = iVar3 + -1;
    if (iVar3 + -1 == 0) {
      param3[0x19] = param3[0x1a];
      param3[0x18] = -param3[0x18];
    }
    for (uVar10 = 0; uVar10 < 3; uVar10 = uVar10 + 1) {
      param3[0x1f] = param3[0x17];
      param3[0x1e] = param3[0x16];
      if (uVar10 == 1) {
        param3[0x1c] = param3[3];
        param3[0x1b] = param2[1];
        param3[0x1d] = param3 + 0xe;
      }
      else if ((int)uVar10 < 1) {
        if (-1 < (int)uVar10) {
          param3[0x1c] = *param3;
          param3[0x1b] = *param2;
          param3[0x1d] = param3 + 10;
        }
      }
      else if ((int)uVar10 < 3) {
        param3[0x1c] = param3[6];
        param3[0x1b] = param2[2];
        param3[0x1d] = param3 + 0x12;
      }
      iVar3 = param3[0x21];
      if (iVar3 == 1) {
        do_src2((int **)(param3 + 0x1b));
      }
      else if ((iVar3 < 1) && (-1 < iVar3)) {
        do_src1((int **)(param3 + 0x1b));
      }
    }
    param3[0x17] = (uint)param3[0x1f] % 0x1e0;
    param3[0x16] = param3[0x1e];
    *(char *)(param3 + 9) = (char)uVar1;
  }
  return;
}

