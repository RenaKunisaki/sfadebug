
void exprFn_8009446c(int *param1,undefined *param2,ushort param3,short param4,uint param5,
                    char param6) { //8009446C
  bool bVar1;
  
  if ((param6 != '\0') || (bVar1 = FUN_80068b20((int)param1,0x10), !bVar1)) {
    audioTryStartSfx(param1,0x10,param3,0x7f,"expr.c",0x401);
    *(float *)(param2 + 0xc) =
         (float)((double)CONCAT44(0x43300000,param5 ^ 0x80000000) - 4503601774854144.0);
    *(short *)(param2 + 0x14) = -param4;
    *param2 = 1;
  }
  return;
}


void exprFn_800945c0(uint param1,char *param2) { //800945C0
  float fVar1;
  short *psVar2;
  bool bVar3;
  uint uVar4;
  double local_18;
  
  fVar1 = *(float *)(param2 + 0xc);
  psVar2 = (short *)objGetJoint(param1,1);
  if (*param2 == '\0') {
    bVar3 = FUN_80068b20(param1,0x10);
    if (bVar3) {
      if ((int)fVar1 != -1) {
        uVar4 = (int)fVar1 - (uint)framesThisStep;
        if ((int)uVar4 < 0) {
          FUN_80068a9c(param1,0x10);
          *(float *)(param2 + 4) = 0.0;
          *(undefined2 *)(param2 + 0x14) = 0;
        }
        local_18 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
        *(float *)(param2 + 0xc) = (float)(local_18 - 4503601774854144.0);
      }
    }
    else {
      *(float *)(param2 + 4) = 0.0;
      *(float *)(param2 + 0xc) = -1.0;
      *(undefined2 *)(param2 + 0x14) = 0;
    }
  }
  else {
    *param2 = '\0';
  }
  *psVar2 = (short)((int)*psVar2 + (int)*(short *)(param2 + 0x14) >> 1);
  return;
}

