
void frontFn_80073c58(void) { //80073C58
  uint uVar1;
  bool bVar2;
  double dVar3;
  
  _savefpr_30();
  if (DAT_80398824 != 0) {
    DAT_80398824 = 0;
    if ((debugRenderFlags & 4) == 0) {
      DAT_80398834 = 0;
    }
    else {
      audioStartSfx((int **)&DAT_80398834,0xab,0x7f,0x40,"front.c",300);
    }
    bVar2 = FUN_8006887c(&DAT_80398834);
    if (bVar2) {
      if ((debugRenderFlags & 1) == 0) {
        uVar1 = ((int)((DAT_80398828 / DAT_8039882c) * 80.0) & 0xffU) + 0x2f;
        dVar3 = (double)((DAT_80398828 / DAT_8039882c) * 0.6 + 0.7);
      }
      else {
        uVar1 = 0x7f - ((int)((DAT_80398828 / DAT_8039882c) * 80.0) & 0xffU);
        dVar3 = -(double)((DAT_80398828 / DAT_8039882c) * 0.6 - 1.3);
      }
      FUN_80068740(dVar3,&DAT_80398834,
                   (byte)(int)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0)
                   ,0x40);
    }
  }
  _restfpr_30();
  return;
}


void FUN_80073dcc(void) { //80073DCC
  DAT_8039885d = 0;
  debugRenderFlags = 0;
  audioStopSfx(&DAT_80398834,"front.c",0x153);
  if ((debugRenderFlags & 8) != 0) {
    audioStartSfx((int **)0x0,0x53,0x7f,0x40,"front.c",0x157);
  }
  return;
}


void FUN_80073e34(void) { //80073E34
  DAT_8039885d = 0;
  debugRenderFlags = 0;
  audioStopSfx(&DAT_80398834,"front.c",0x163);
  return;
}

