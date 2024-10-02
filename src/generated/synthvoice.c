
/* Library Function - Single Match
    synthVoiceFn_8004ece4
   
   Library: KioskDefault 0 0 */

void synthVoiceFn_8004ece4(SynthVoice *svoice) { //8004ECE4
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (svoice->id == 0xffffffff) {
                    
    OSPanic("synthvoice.c",0x274,s_Failed_assertion_svoice_>id__0xF_802e0db0);
  }
  synthMacroFn_8004dbe8(svoice,2);
  FUN_8004e4d8((int)svoice);
  svoice->addr = 0;
  svoice->field253_0x10c = 0;
  bVar1 = (byte)svoice->id;
  uVar2 = svoice->id & 0xff;
  iVar3 = uVar2 * 4;
  if ((&DAT_80343c22)[uVar2 * 2] == 0) {
    (&DAT_80343c22)[uVar2 * 2] = 1;
    if (DAT_80398621 == 0xff) {
      (&DAT_80343c21)[iVar3] = 0xff;
      (&DAT_80343c20)[iVar3] = 0xff;
      DAT_80398621 = bVar1;
    }
    else {
      (&DAT_80343c21)[iVar3] = 0xff;
      (&DAT_80343c20)[iVar3] = DAT_80398620;
      (&DAT_80343c21)[(uint)DAT_80398620 * 4] = bVar1;
    }
    DAT_80398620 = bVar1;
    if (svoice->field270_0x11d == '\0') {
      DAT_8039861e = DAT_8039861e + -1;
    }
    else {
      DAT_8039861f = DAT_8039861f + -1;
    }
  }
  svoice->id = 0xffffffff;
  return;
}

