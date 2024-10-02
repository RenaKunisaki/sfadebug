
void mikadalonFn_801b7d1c(int param1,int param2) { //801B7D1C
  int iVar1;
  
  iVar1 = randInt(0,2);
  audioSfxFn_800688bc((double)*(float *)(param1 + 0x18),(double)*(float *)(param1 + 0x1c),
                      (double)*(float *)(param1 + 0x20),
                      (ushort)*(undefined4 *)(&DAT_80310040 + iVar1 * 4),0x7f,"mikadalon.c"
                      ,(int *)0x17e);
  *(undefined2 *)(param2 + 0x29c) = 0;
  *(uint *)(param2 + 0x2c8) = *(uint *)(param2 + 0x2c8) | 0x20;
  *(uint *)(param2 + 0x2cc) = *(uint *)(param2 + 0x2cc) | 8;
  return;
}

