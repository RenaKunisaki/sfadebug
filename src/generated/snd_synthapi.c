
/* Library Function - Single Match
    sndSynthApiFn_80046f7c
   
   Library: KioskDefault 0 0 */

undefined4 sndSynthApiFn_80046f7c(uint param1,byte param2,byte param3) { //80046F7C
  undefined4 uVar1;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x26,"Sound system is not initialized.");
  }
  sndBegin();
  uVar1 = sndSynthApiFn_800461b8(param1,param2,param3);
  sndEnd();
  return uVar1;
}


/* Library Function - Single Match
    sndSynthApiFn_80046ff4
   
   Library: KioskDefault 0 0 */

undefined4 sndSynthApiFn_80046ff4(uint param1,byte param2,ushort param3) { //80046FF4
  undefined4 uVar1;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x35,"Sound system is not initialized.");
  }
  sndBegin();
  uVar1 = sndSynthApiFn_800461b8(param1,param2,(uint)param3);
  sndEnd();
  return uVar1;
}


/* Library Function - Single Match
    sndSynthApiFn_8004706c
   
   Library: KioskDefault 0 0 */

undefined4 sndSynthApiFn_8004706c(uint param1) { //8004706C
  undefined4 uVar1;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x44,"Sound system is not initialized.");
  }
  sndBegin();
  uVar1 = audioStopSoundInternal(param1);
  sndEnd();
  return uVar1;
}


/* Library Function - Single Match
    sndFXStart
   
   Library: KioskDefault 0 0 */

uint sndFXStart(undefined2 param1,byte param2,byte param3,byte param4) { //800470D4
  uint uVar1;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x53,"Sound system is not initialized.");
  }
  sndBegin();
  uVar1 = _sndFxStart(param1,param2,(uint)param3,param4,
                      (uint)(byte)(&DAT_80398565)[(uint)param4 * 2]);
  sndEnd();
  return uVar1;
}


/* Library Function - Single Match
    sndSynthApiFn_80047164
   
   Library: KioskDefault 0 0 */

uint sndSynthApiFn_80047164(uint param1) { //80047164
  int iVar1;
  
  if (bSndIsInstalled) {
    iVar1 = FUN_8004e408(param1);
    if (iVar1 == -1) {
      param1 = 0xffffffff;
    }
    return param1;
  }
                    
  OSPanic("snd_synthapi.c",0xc1,"Sound system is not initialized.");
}


/* Library Function - Single Match
    sndSynthApiFn_800471d4
   
   Library: KioskDefault 0 0 */

void sndSynthApiFn_800471d4(byte param1,ushort param2,byte param3) { //800471D4
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x162,"Sound system is not initialized.");
  }
  sndBegin();
  audioSetChannelVolume((uint)param1,param2,param3,0,-NAN);
  sndEnd();
  return;
}


/* Library Function - Single Match
    sndSynthApiFn_80047244
   
   Library: KioskDefault 0 0 */

void audioSetMusicSfxVolume(uint param1,ushort param2,char param3,char param4) { //80047244
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x16e,"Sound system is not initialized.");
  }
  sndBegin();
  if (param3 != '\0') {
    audioSetChannelVolume(param1,param2,0x15,0,-NAN);
  }
  if (param4 != '\0') {
    audioSetChannelVolume(param1,param2,0x16,0,-NAN);
  }
  sndEnd();
  return;
}


/* Library Function - Single Match
    sndSynthApiFn_800472f0
   
   Library: KioskDefault 0 0 */

void sndSynthApiFn_800472f0(int param1) { //800472F0
  uint uVar1;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x17d,"Sound system is not initialized.");
  }
  uVar1 = countLeadingZeros(-param1);
  DAT_80398584 = (undefined)(uVar1 >> 5);
  if ((uVar1 >> 5 & 0xff) == 0) {
    if (param1 == 2) {
      sndSynthApiFn_80058904();
    }
    else {
      FUN_80058938();
    }
  }
  return;
}


/* Library Function - Single Match
    sndSynthApiFn_8004736c
   
   Library: KioskDefault 0 0 */

void sndSynthApiFn_8004736c
               (uint param_1,undefined *param_2,undefined *param_3,char param_4,uint param_5,
               undefined *param_6,undefined *param_7,char param_8,uint param_9) { //8004736C
  uint uVar1;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x193,"Sound system is not initialized.");
  }
  sndBegin();
  if (param_2 == (undefined *)0x0) {
    (&DAT_80336fa4)[param_1 & 0xff] = 0;
    (&DAT_80398578)[param_1 & 0xff] = 0xff;
  }
  else {
    (&DAT_80398578)[param_1 & 0xff] = param_4;
    if (param_4 != -1) {
      uVar1 = seqGetVolumeGroup(param_5);
      (&DAT_80398574)[param_1 & 0xff] = (char)uVar1;
      (&DAT_80336fa4)[param_1 & 0xff] = param_2;
      (&DAT_80336fb4)[param_1 & 0xff] = param_3;
    }
  }
  if (param_6 == (undefined *)0x0) {
    (&DAT_80336fc4)[param_1 & 0xff] = 0;
    (&DAT_80398570)[param_1 & 0xff] = 0xff;
  }
  else {
    (&DAT_80398570)[param_1 & 0xff] = param_8;
    if (param_8 != -1) {
      uVar1 = seqGetVolumeGroup(param_9);
      (&DAT_8039856c)[param_1 & 0xff] = (char)uVar1;
      (&DAT_80336fc4)[param_1 & 0xff] = param_6;
      (&DAT_80336fd4)[param_1 & 0xff] = param_7;
    }
  }
  FUN_800583fc(param_1,param_2,param_3,param_6,param_7);
  sndEnd();
  return;
}


/* Library Function - Single Match
    sndSynthApiFn_80047510
   
   Library: KioskDefault 0 0 */

void sndSynthApiFn_80047510(byte param1,undefined param2,undefined4 param3) { //80047510
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x1e8,"Sound system is not initialized.");
  }
  sndBegin();
  (&DAT_80336fa4)[param1] = 0;
  (&DAT_80336fc4)[param1] = 0;
  (&DAT_80398578)[param1] = 0xff;
  (&DAT_80398570)[param1] = 0xff;
  (&DAT_80398565)[(uint)param1 * 2] = 0;
  (&DAT_80398564)[(uint)param1 * 2] = 0;
  sndEnd();
  FUN_80058460(param1,param2,param3);
  return;
}


/* Library Function - Single Match
    sndSynthApiFn_800475f4
   
   Library: KioskDefault 0 0 */

void sndSynthApiFn_800475f4(byte param1) { //800475F4
  bool bVar1;
  uint uVar2;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x20d,"Sound system is not initialized.");
  }
  for (uVar2 = 0; uVar2 < maxVoices; uVar2 = uVar2 + 1) {
    if (param1 == synthVoiceArray[uVar2].field_0x11f) {
      if (synthVoiceArray[uVar2].id == 0xffffffff) {
        bVar1 = FUN_800579a8(uVar2);
        if (bVar1) {
          FUN_800583c8(uVar2);
        }
      }
      else {
        FUN_8004ef6c(*(uint *)(*(int *)&synthVoiceArray[uVar2].field_0xf8 + 8));
      }
    }
  }
  sndBegin();
  (&DAT_80336fa4)[param1] = 0;
  (&DAT_80336fc4)[param1] = 0;
  (&DAT_80398578)[param1] = 0xff;
  (&DAT_80398570)[param1] = 0xff;
  sndEnd();
  FUN_80058498(param1);
  return;
}


/* Library Function - Single Match
    sndSynthApiFn_80047788
   
   Library: KioskDefault 0 0 */

void sndSynthApiFn_80047788(byte param1,byte *param2) { //80047730
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x259,"Sound system is not initialized.");
  }
  sndSynthApiFn_80058500(param1,param2);
  return;
}


/* Library Function - Single Match
    sndSynthApiFn_80047788
   
   Library: KioskDefault 0 0 */

void sndSynthApiFn_80047788(byte param1,int param2) { //80047788
  if (!bSndIsInstalled) {
                    
    OSPanic("snd_synthapi.c",0x26d,"Sound system is not initialized.");
  }
  sndSynthApiFn_80058500(param1,param2);
  return;
}

