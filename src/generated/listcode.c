
/* Library Function - Single Match
    listCodeFn_8017c104
   
   Library: KioskDefault 0 0 */

void listCodeRender(Gfx *param_1) { //8017C104
  F3DEXcommand FVar1;
  F3DEXcommand FVar2;
  uint uVar3;
  
  debugPrintDraw(&Gfx_803998a0);
  FVar1 = Gfx_803998a0.cmd;
  FVar2 = Gfx_803998a0.cmd + 8;
  *(undefined4 *)Gfx_803998a0.cmd = 0xe9000000;
  Gfx_803998a0.cmd = FVar2;
  *(undefined4 *)(FVar1 + 4) = 0;
  FVar1 = Gfx_803998a0.cmd;
  FVar2 = Gfx_803998a0.cmd + 8;
  *(undefined4 *)Gfx_803998a0.cmd = 0xdf000000;
  Gfx_803998a0.cmd = FVar2;
  *(undefined4 *)(FVar1 + 4) = 0;
  uVar3 = Gfx_803998a0.cmd - (int)(&rspCmdBuf_803998b0)[curRspBufIdx];
  if (40000 < (int)(((int)uVar3 >> 3) + (uint)((int)uVar3 < 0 && (uVar3 & 7) != 0))) {
                    
    OSPanic("listcode.c",0x5a,(char *)0x0);
  }
  uVar3 = Gfx_803998a0.param - (int)(&PTR_DAT_803998b8)[curRspBufIdx];
  if (0x5e8 < (int)(((int)uVar3 >> 6) + (uint)((int)uVar3 < 0 && (uVar3 & 0x3f) != 0))) {
    printf("Warning: di-mtx-list overflow! (diPrintf)");
  }
  uVar3 = (int)rspVar_803998a8 - (int)(&rspVar_803998c0)[curRspBufIdx];
  if (0x708 < (int)(((int)uVar3 >> 4) + (uint)((int)uVar3 < 0 && (uVar3 & 0xf) != 0))) {
    printf("Warning: di-vtx-list overflow! (diPrintf)");
  }
  uVar3 = (int)rspVar_803998ac - (int)(&rspVar_803998c8)[curRspBufIdx];
  if (3000 < (int)(((int)uVar3 >> 4) + (uint)((int)uVar3 < 0 && (uVar3 & 0xf) != 0))) {
    printf("Warning: di-pol-list overflow! (diPrintf)");
  }
  mainRender((Gfx **)(&rspCmdBuf_803998b0)[curRspBufIdx],(Mtx44 **)Gfx_803998a0.cmd,
             (N64Vtx **)&DAT_00000001);
  return;
}

