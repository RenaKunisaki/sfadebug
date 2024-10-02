
/* Library Function - Single Match
    synthMacroFn_8004d6fc
   
   Library: KioskDefault 0 0 */

void synthMacroFn_8004d6fc(SynthVoice *sv) { //8004D6FC
  int iVar1;
  
  if (sv->valid == 1) {
    if (sv->addr == 0) {
                    
      OSPanic("synthmacros.c",0xc45,s_Failed_assertion_sv_>addr__NULL_802e0d58);
    }
    iVar1 = synthMacroFn_8004960c(sv,1);
    if ((iVar1 == 0) && ((*(uint *)&sv->field_0x118 & 0x40000) != 0)) {
      synthMacroFn_8004db54(sv);
    }
  }
  return;
}


/* Library Function - Single Match
    synthMacroFn_8004db54
   
   Library: KioskDefault 0 0 */

void synthMacroFn_8004db54(SynthVoice *svoice) { //8004DB54
  SynthVoice *pSVar1;
  
  if (svoice->valid != 0) {
    if (svoice->addr == 0) {
                    
      OSPanic("synthmacros.c",0xcd2,s_Failed_assertion_svoice_>addr__N_802e0d78);
    }
    synthMacroFn_8004da54();
    pSVar1 = synthVoiceVar_803985f4;
    svoice->field57_0x3c = (int)synthVoiceVar_803985f4;
    if (pSVar1 != (SynthVoice *)0x0) {
      synthVoiceVar_803985f4->field58_0x40 = (int)svoice;
    }
    svoice->field58_0x40 = 0;
    synthVoiceVar_803985f4 = svoice;
    svoice->valid = 0;
  }
  return;
}


/* Library Function - Single Match
    synthMacroFn_8004dbe8
   
   Library: KioskDefault 0 0 */

void synthMacroFn_8004dbe8(SynthVoice *svoice,int param2) { //8004DBE8
  if (svoice->valid != param2) {
    if (svoice->addr == 0) {
                    
      OSPanic("synthmacros.c",0xcf6,s_Failed_assertion_svoice_>addr__N_802e0d78);
    }
    if (svoice->valid == 0) {
      if (svoice->field58_0x40 == 0) {
        synthVoiceVar_803985f4 = svoice->field57_0x3c;
      }
      else {
        *(int *)(svoice->field58_0x40 + 0x3c) = svoice->field57_0x3c;
      }
      if (svoice->field57_0x3c != 0) {
        *(int *)(svoice->field57_0x3c + 0x40) = svoice->field58_0x40;
      }
    }
    if (param2 == 2) {
      synthMacroFn_8004da54();
    }
    svoice->valid = param2;
  }
  return;
}

