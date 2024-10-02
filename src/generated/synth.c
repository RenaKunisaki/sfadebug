
/* Library Function - Single Match
    synthInitFn_8004680c
   
   Library: KioskDefault 0 0 */

void synthInitFn_8004680c(undefined4 param1,uint nVoices) { //8004680C
  SynthVoice *pSVar1;
  uint uVar2;
  undefined uVar3;
  
  DAT_8039859c = 0;
  DAT_80398598 = 0;
  DAT_80336750 = param1;
  FUN_80043bb4(0x78,0xff,0);
  DAT_80398584 = 0;
  DAT_8039858c = 0;
  synthVoiceArray = (SynthVoice *)audioAlloc(nVoices * 0x404);
  if (synthVoiceArray == (SynthVoice *)0x0) {
                    
    OSPanic("synth.c",0x7fe,"Fatal: Could not allocate synthesizer voice array.");
  }
  memset_(synthVoiceArray,0,nVoices * 0x404);
  for (uVar2 = 0; uVar2 < nVoices; uVar2 = uVar2 + 1) {
    synthVoiceArray[uVar2].id = 0xffffffff;
    pSVar1 = synthVoiceArray + uVar2;
    *(undefined4 *)(&pSVar1->field_0x114 + 4) = 0;
    *(undefined4 *)&pSVar1->field_0x114 = 0;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x110 = 0;
    synthVoiceArray[uVar2].field253_0x10c = 0;
    synthVoiceArray[uVar2].field_0x121 = 0xff;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x158 = 0;
    synthVoiceArray[uVar2].field_0x196 = 0;
    synthVoiceArray[uVar2].field_0x194 = 0x80;
    synthVoiceArray[uVar2].field_0x195 = 0;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x184 = 0x400000;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x174 = 0x400000;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x188 = 0;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x178 = 0;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x1a4 = 0;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x1a8 = 0;
    synthVoiceArray[uVar2].field_0x1bc = 0;
    synthVoiceArray[uVar2].field_0x1bd = 0;
    synthVoiceArray[uVar2].field_0x11c = 0;
    synthVoiceArray[uVar2].field_0x11e = 0x17;
    synthVoiceArray[uVar2].field_0x104 = 0;
    synthVoiceArray[uVar2].field_0x197 = 1;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x1c4 = 0;
    *(undefined2 *)&synthVoiceArray[uVar2].field_0x1c8 = 0;
    *(undefined2 *)&synthVoiceArray[uVar2].field_0x1ca = 0x7fff;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x1d0 = 0;
    *(undefined2 *)&synthVoiceArray[uVar2].field_0x1d4 = 0;
    *(undefined2 *)&synthVoiceArray[uVar2].field_0x1d6 = 0x7fff;
    *(undefined4 *)&synthVoiceArray[uVar2].field_0x140 = 100;
    synthVoiceArray[uVar2].field_0x135 = 0;
    synthVoiceArray[uVar2].field_0x11f = 0;
    uVar3 = (undefined)uVar2;
    synthVoiceArray[uVar2].field_0x8 = uVar3;
    synthVoiceArray[uVar2].field_0x9 = 0xff;
    synthVoiceArray[uVar2].field_0x14 = uVar3;
    synthVoiceArray[uVar2].field_0x15 = 0xff;
    synthVoiceArray[uVar2].field_0x20 = uVar3;
    synthVoiceArray[uVar2].field_0x21 = 0xff;
  }
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1) {
    (&FLOAT_80336964)[uVar2 * 0xc] = 0.0;
    (&DAT_80336978)[uVar2 * 0xc] = 1.0;
    (&DAT_80336991)[uVar2 * 0x30] = 4;
  }
  DAT_80398580 = 0;
  DAT_8039857c = 0;
  DAT_80336f61 = 1;
  for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
    (&DAT_80336991)[(uVar2 + 0x17) * 0x30] = 0;
  }
  DAT_80336d54 = 1.0;
  DAT_80336d84 = 1.0;
  FUN_800571b8(0);
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1) {
    (&DAT_80336fa4)[uVar2] = 0;
    (&DAT_80398578)[uVar2] = 0xff;
    (&DAT_80336fc4)[uVar2] = 0;
    (&DAT_80398570)[uVar2] = 0xff;
    (&DAT_80398565)[uVar2 * 2] = 0;
    (&DAT_80398564)[uVar2 * 2] = 0;
  }
  FUN_8004df78();
  FUN_8004e008();
  FUN_8004eeb8();
  for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1) {
    (&DAT_80336fe4)[uVar2] = 0;
  }
  FUN_8004f1b8();
  FUN_8004591c();
  FUN_800579d0(FUN_80046788);
  return;
}

