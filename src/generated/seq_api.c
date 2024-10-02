
/* Library Function - Single Match
    sequencerFn_80046ce4
   
   Library: KioskDefault 0 0 */

void sequencerFn_80046ce4(uint param1) { //80046CE4
  if (!bSndIsInstalled) {
                    
    OSPanic("seq_api.c",0x7c,"Sound system is not initialized.");
  }
  sndBegin();
  FUN_800422e0(param1);
  sndEnd();
  return;
}


/* Library Function - Single Match
    sequencerFn_80046d3c
   
   Library: KioskDefault 0 0 */

void sequencerFn_80046d3c(uint param1,undefined2 param2) { //80046D3C
  if (!bSndIsInstalled) {
                    
    OSPanic("seq_api.c",200,"Sound system is not initialized.");
  }
  sndBegin();
  sequencerFn_80042434(param1,param2);
  sndEnd();
  return;
}


/* Library Function - Single Match
    sequencerFn_80046d9c
   
   Library: KioskDefault 0 0 */

void sequencerFn_80046d9c(uint param1) { //80046D9C
  if (!bSndIsInstalled) {
                    
    OSPanic("seq_api.c",0xd4,"Sound system is not initialized.");
  }
  sndBegin();
  sequencerFn_800424f0(param1);
  sndEnd();
  return;
}


/* Library Function - Single Match
    sequencerFn_80046df4
   
   Library: KioskDefault 0 0 */

void sequencerFn_80046df4(uint param1,undefined4 param2,undefined4 param3) { //80046DF4
  if (!bSndIsInstalled) {
                    
    OSPanic("seq_api.c",0xe0,"Sound system is not initialized.");
  }
  sndBegin();
  sequencerFn_800425f8(param1,param2,param3);
  sndEnd();
  return;
}


/* Library Function - Single Match
    sequencerFn_80046e5c
   
   Library: KioskDefault 0 0 */

void sequencerFn_80046e5c(byte param1,ushort param2,float param3,byte param4) { //80046E5C
  if (!bSndIsInstalled) {
                    
    OSPanic("seq_api.c",0xec,"Sound system is not initialized.");
  }
  sndBegin();
  sequencerFn_8004269c((uint)param1,param2,param3,param4);
  sndEnd();
  return;
}


/* Library Function - Single Match
    volumeGroupFn_80046ecc
   
   Library: KioskDefault 0 0 */

undefined volumeGroupFn_80046ecc(uint param1) { //80046ECC
  uint uVar1;
  undefined uVar2;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("seq_api.c",0xf8,"Sound system is not initialized.");
  }
  uVar1 = seqGetVolumeGroup(param1);
  if (uVar1 == 0xffffffff) {
    OSReport("Volume group could not be received from sequencer.");
    uVar2 = 0;
  }
  else {
    uVar2 = (&DAT_8032b41c)[uVar1 * 0x17a4];
  }
  return uVar2;
}

