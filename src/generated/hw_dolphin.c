
/* Library Function - Single Match
    hwInitFn_80059180
   
   Library: KioskDefault 0 0 */

void hwInitFn_80059180(uint cmdList) { //80059180
  ushort uVar1;
  
  DAT_803986c8 = 0;
  syscall_0();
  if ((cmdList & 0x1f) != 0) {
                    
    OSPanic("hw_dolphin.c",0x141,"Failed assertion ((u32)cmdList & 0x1F)==0");
  }
  dspSendMail(dspVar_80398650 | 0xbabe0000);
  do {
    uVar1 = dspGetMailHi();
  } while (uVar1 != 0);
  dspSendMail(cmdList);
  do {
    uVar1 = dspGetMailHi();
  } while (uVar1 != 0);
  return;
}

