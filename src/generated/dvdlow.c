
/* Library Function - Single Match
    interruptHandler0x15
   
   Library: KioskDefault 0 0 */

void __DVDInterruptHandler(undefined4 param_1,OSContext *param2) { //8001090C
  uint uVar1;
  dword dVar2;
  uint uVar3;
  longlong lVar4;
  OSContext OStack_2d8;
  
  uVar3 = 0;
  dVar2 = dvd_DISR;
  uVar1 = (dVar2 & 0x2a) << 1 & dVar2 & 0x54;
  if ((uVar1 & 0x40) != 0) {
    uVar3 = 8;
  }
  if ((uVar1 & 0x10) != 0) {
    uVar3 = uVar3 | 1;
  }
  if ((uVar1 & 4) != 0) {
    uVar3 = uVar3 | 2;
  }
  if (uVar3 != 0) {
    DAT_803982c0 = 0;
  }
  dvd_DISR = uVar1 | dVar2 & 0x2a;
  if (DAT_803982c0 != 0) {
    lVar4 = FUN_8000e4c0();
    if (((int)((ulonglong)lVar4 >> 0x20) - ((uint)((uint)lVar4 < DAT_803982bc) + DAT_803982b8) ^
        0x80000000) < ((uint)lVar4 - DAT_803982bc < (busClockMhz / 4000) * 200) + 0x80000000) {
      dVar2 = dvd_DICVR;
      if (((dVar2 & 2) << 1 & dVar2 & 4) != 0) {
        if (DAT_803982b4 != (code *)0x0) {
          (*DAT_803982b4)(4);
        }
        DAT_803982b4 = (code *)0x0;
      }
      dVar2 = dvd_DICVR;
      dvd_DICVR = dVar2;
      goto LAB_80010a80;
    }
  }
  if (DAT_803982c4 == 0) {
    dvd_DICVR = 0;
  }
  else {
    dVar2 = dvd_DICVR;
    uVar1 = (dVar2 & 2) << 1 & dVar2 & 4;
    if (uVar1 != 0) {
      uVar3 = uVar3 | 4;
    }
    dvd_DICVR = uVar1 | dVar2 & 2;
    DAT_803982c4 = 0;
  }
LAB_80010a80:
  if (((uVar3 & 8) != 0) && (DAT_803982c8 == 0)) {
    uVar3 = uVar3 & 0xfffffff7;
  }
  OSClearContext(&OStack_2d8);
  OSSetCurrentContext(&OStack_2d8);
  if (uVar3 != 0) {
    if (PTR_dvdCb_803982b0 != (undefined *)0x0) {
                    /* {@symbol 80013020} */
      (*(code *)PTR_dvdCb_803982b0)(uVar3);
    }
    DAT_803982c8 = 0;
  }
  OSClearContext(&OStack_2d8);
  OSSetCurrentContext(param2);
  return;
}


/* Library Function - Single Match
    DVDLowRead
   
   Library: KioskDefault 0 0 */

undefined4 DVDLowRead(uint param1,uint param2,uint param3,undefined *param4) { //80010AF8
  if ((param1 & 0x1f) != 0) {
                    
    OSPanic("dvdlow.c",0x143,"DVDLowRead(): address must be aligned with 32 byte boundary.");
  }
  if ((param2 & 0x1f) != 0) {
                    
    OSPanic("dvdlow.c",0x144,"DVDLowRead(): length must be a multiple of 32.");
  }
  if ((param3 & 3) != 0) {
                    
    OSPanic("dvdlow.c",0x145,"DVDLowRead(): offset must be a multiple of 4.");
  }
  if (param2 == 0) {
                    
    OSPanic("dvdlow.c",0x147,"DVD read: 0 was specified to length of the read");
  }
  PTR_dvdCb_803982b0 = param4;
  dvd_DICMDBUF0 = 0xa8000000;
  dvd_DICMDBUF1 = param3 >> 2;
  dvd_DICMDBUF2 = param2;
  dvd_DIMAR = param1;
  dvd_DILENGTH = param2;
  dvd_DICR = 3;
  return 1;
}


/* Library Function - Single Match
    DVDLowSeek
   
   Library: KioskDefault 0 0 */

undefined4 DVDLowSeek(uint param1,undefined *param2) { //80010BEC
  if ((param1 & 3) != 0) {
                    
    OSPanic("dvdlow.c",0x166,"DVDLowSeek(): offset must be a multiple of 4.");
  }
  PTR_dvdCb_803982b0 = param2;
  dvd_DICMDBUF0 = 0xab000000;
  dvd_DICMDBUF1 = param1 >> 2;
  dvd_DICR = 1;
  return 1;
}


undefined4 FUN_80010c6c(undefined *param_1) { //80010C6C
  PTR_dvdCb_803982b0 = param_1;
  DAT_803982c4 = 1;
  dvd_DICVR = 2;
  return 1;
}


/* Library Function - Single Match
    DVDLowReadID
   
   Library: KioskDefault 0 0 */

undefined4 DVDLowReadID(uint param1,undefined *param2) { //80010C8C
  if ((param1 & 0x1f) != 0) {
                    
    OSPanic("dvdlow.c",0x19b,"DVDLowReadID(): id must be aligned with 32 byte boundary.");
  }
  PTR_dvdCb_803982b0 = param2;
  dvd_DICMDBUF0 = 0xa8000040;
  dvd_DICMDBUF1 = 0;
  dvd_DICMDBUF2 = 0x20;
  dvd_DIMAR = param1;
  dvd_DILENGTH = 0x20;
  dvd_DICR = 3;
  return 1;
}


undefined4 FUN_80010d30(undefined *param_1) { //80010D30
  PTR_dvdCb_803982b0 = param_1;
  dvd_DICMDBUF0 = 0xe3000000;
  dvd_DICR = 1;
  return 1;
}


undefined4 FUN_80010d54(undefined *param_1) { //80010D54
  PTR_dvdCb_803982b0 = param_1;
  dvd_DICMDBUF0 = 0xe0000000;
  dvd_DICR = 1;
  return 1;
}


undefined4 FUN_80010d78(dword param_1,undefined *param_2) { //80010D78
  PTR_dvdCb_803982b0 = param_2;
  dvd_DICMDBUF0 = 0x12000000;
  dvd_DICMDBUF2 = 0x20;
  dvd_DIMAR = param_1;
  dvd_DILENGTH = 0x20;
  dvd_DICR = 3;
  return 1;
}


undefined4 FUN_80010dbc(uint param_1,dword param_2,uint param_3,undefined *param_4) { //80010DBC
  PTR_dvdCb_803982b0 = param_4;
  dvd_DICMDBUF0 = param_1 | 0xe1000000;
  dvd_DICMDBUF1 = param_3 >> 2;
  dvd_DICMDBUF2 = param_2;
  dvd_DICR = 1;
  return 1;
}


undefined4 FUN_80010df4(uint param_1,undefined *param_2) { //80010DF4
  PTR_dvdCb_803982b0 = param_2;
  dvd_DICMDBUF0 = param_1 | 0xe2000000;
  dvd_DICR = 1;
  return 1;
}


/* Library Function - Single Match
    dvdLowFn_80010e18
   
   Library: KioskDefault 0 0 */

undefined4 dvdLowFn_80010e18(int param1,uint param2,undefined *param3) { //80010E18
  uint uVar1;
  
  PTR_dvdCb_803982b0 = param3;
  if (0xf < (param2 & 0xf)) {
                    
    OSPanic("dvdlow.c",0x25b,s_Failed_assertion_bufSize_<_16_802d50a4);
  }
  if (2 < (param2 >> 4 & 0xf)) {
                    
    OSPanic("dvdlow.c",0x25c,s_Failed_assertion_trigger_<__2_802d50c4);
  }
  if (param1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10000;
  }
  dvd_DICMDBUF0 = param2 | uVar1 | 0xe4000000;
  dvd_DICR = 1;
  return 1;
}


void DVDLowReset(void) { //80010ED0
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
  dvd_DICVR = 2;
  uVar1 = pi_RESET;
  pi_RESET = uVar1 & 0xfffffffb | 1;
  lVar2 = FUN_8000e4c0();
  do {
    lVar3 = FUN_8000e4c0();
  } while (((int)((ulonglong)lVar3 >> 0x20) -
            ((uint)((uint)lVar3 < (uint)lVar2) + (int)((ulonglong)lVar2 >> 0x20)) ^ 0x80000000) <
           ((uint)lVar3 - (uint)lVar2 < (busClockMhz / 500000) * 0xc >> 3) + 0x80000000);
  pi_RESET = uVar1 | 5;
  DAT_803982c0 = 1;
  lVar2 = FUN_8000e4c0();
  DAT_803982bc = (int)lVar2;
  DAT_803982b8 = (int)((ulonglong)lVar2 >> 0x20);
  return;
}


undefined4 FUN_80010f94(void) { //80010F94
  dword dVar1;
  
  dVar1 = dvd_DISR;
  dvd_DISR = dVar1 | 0x41;
  DAT_803982c8 = 1;
  return 1;
}


undefined * FUN_80010fc8(void) { //80010FC8
  undefined *puVar1;
  
  puVar1 = PTR_dvdCb_803982b0;
  dvd_DICVR = 0;
  PTR_dvdCb_803982b0 = (undefined *)0x0;
  return puVar1;
}

