
void templateFn_801b6210(int param1,int param2) { //801B6210
  int iVar1;
  
  iVar1 = randInt(0,2);
  audioSfxFn_800688bc((double)*(float *)(param1 + 0x18),(double)*(float *)(param1 + 0x1c),
                      (double)*(float *)(param1 + 0x20),(ushort)(&PTR_DAT_8030fd40)[iVar1],0x7f,
                      "template.c",(int *)0xe2);
  *(uint *)(param2 + 0x2cc) = *(uint *)(param2 + 0x2cc) | 8;
  return;
}

