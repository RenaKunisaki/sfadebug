
/* Library Function - Single Match
    siFn_80016e8c
   
   Library: KioskDefault 0 0 */

void siFn_80016e8c(int param1) { //80016E8C
  undefined4 auStack_1c [4];
  
  DAT_803983a4 = DAT_803983a4 | 0x80000000U >> param1;
  SIGetResponse(param1,auStack_1c);
  if ((*(uint *)(&DAT_80326c08 + param1 * 4) & 0x40000) != 0) {
                    
    OSPanic("Pad.c",0x1c4,"Failed assertion !(Type[chan] & RES_WIRELESS_LITE)");
  }
  SISetCommand(param1,DAT_80396834 | 0x400000);
  SIEnablePolling(DAT_803983a4);
  return;
}


/* Library Function - Single Match
    padResetFn_80016fe4
   
   Library: KioskDefault 0 0 */

void padResetFn_80016fe4(int param1,uint param2) { //80016FE4
  if ((-1 < DAT_80396830) && (DAT_80396830 < 4)) {
    if (param1 != DAT_80396830) {
                    
      OSPanic("Pad.c",0x1f6,"Failed assertion chan == ResettingChan");
    }
    if ((param2 & 0xf) == 0) {
      if (((*(uint *)(&DAT_80326c08 + param1 * 4) & 0x80000) == 0) &&
         ((*(uint *)(&DAT_80326c08 + param1 * 4) & 0x40000) == 0)) {
        siFn_80016e8c(DAT_80396830);
        DAT_803983b4 = DAT_803983b4 | 0x80000000U >> DAT_80396830;
      }
      else {
        padFn_80016f24(DAT_80396830);
      }
    }
    FUN_80016d9c();
    return;
  }
                    
  OSPanic("Pad.c",0x1f5,s_Failed_assertion_0_<__ResettingC_802d6dd4);
}


/* Library Function - Single Match
    padResetFn_8001729c
   
   Library: KioskDefault 0 0 */

void padResetFn_8001729c(int param1,uint param2) { //8001729C
  if ((-1 < DAT_80396830) && (DAT_80396830 < 4)) {
    if (param1 != DAT_80396830) {
                    
      OSPanic("Pad.c",0x268,"Failed assertion chan == ResettingChan");
    }
    if ((param2 & 0xf) == 0) {
      UpdateOrigin(DAT_80396830);
      siFn_80016e8c(DAT_80396830);
    }
    FUN_80016d9c();
    return;
  }
                    
  OSPanic("Pad.c",0x267,s_Failed_assertion_0_<__ResettingC_802d6dd4);
}


/* Library Function - Single Match
    padFn_80017338
   
   Library: KioskDefault 0 0 */

void padFn_80017338(int param1,uint param2) { //80017338
  if (-1 < param1) {
    if (param1 < 4) {
      if (((DAT_803983a4 & 0x80000000U >> param1) != 0) && ((param2 & 0xf) == 0)) {
        UpdateOrigin(param1);
      }
      return;
    }
  }
                    
  OSPanic("Pad.c",0x285,s_Failed_assertion_0_<__chan_&&_ch_802d6e40);
}


/* Library Function - Single Match
    padResetFn_800173b4
   
   Library: KioskDefault 0 0 */

void padResetFn_800173b4(undefined4 param_1,uint param2) { //800173B4
  ushort uVar1;
  uint uVar2;
  uint local_14 [2];
  
  if (((int)DAT_80396830 < 0) || (3 < (int)DAT_80396830)) {
                    
    OSPanic("Pad.c",0x2a9,s_Failed_assertion_0_<__ResettingC_802d6dd4);
  }
  if ((param2 & 0xf) == 0) {
    uVar2 = *(uint *)(&DAT_80326c08 + DAT_80396830 * 4);
    uVar1 = FUN_80016ce4(DAT_80396830);
    if (((uVar2 & 0x100000) != 0) && ((uVar1 & 0xcfff) << 8 == (uVar2 & 0xcfff00))) {
      if (((uVar2 & 0x40000000) != 0) && (((uVar2 & 0x80000) == 0 && ((uVar2 & 0x40000) == 0)))) {
        local_14[0] = 0x41000000;
        FUN_8000ce74(DAT_80396830,(int)local_14,1,&DAT_80326c18 + DAT_80396830 * 0xc,10,-0x7ffe8d64,
                     0,0);
        return;
      }
      local_14[0] = DAT_80396830 << 0x16 | 0x4d000000 | (osPadType & 0x3fff) << 8;
      FUN_8000ce74(DAT_80396830,(int)local_14,3,&DAT_80326c18 + DAT_80396830 * 0xc,8,-0x7ffe901c,0,0
                  );
      return;
    }
    FUN_80016d9c();
  }
  else {
    FUN_80016d9c();
  }
  return;
}


/* Library Function - Single Match
    padFn_8001751c
   
   Library: KioskDefault 0 0 */

void padResetFn_8001751c(undefined4 param_1,uint param2) { //8001751C
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *local_24 [2];
  
  if (((int)DAT_80396830 < 0) || (3 < (int)DAT_80396830)) {
                    
    OSPanic("Pad.c",0x2e9,s_Failed_assertion_0_<__ResettingC_802d6dd4);
  }
  uVar5 = *(uint *)(&DAT_80326c08 + DAT_80396830 * 4);
  uVar4 = 0x80000000 >> DAT_80396830;
  uVar3 = DAT_803983b0 & uVar4;
  DAT_803983b0 = DAT_803983b0 & ~uVar4;
  uVar2 = padVar_803983c4 & uVar4;
  padVar_803983c4 = padVar_803983c4 & ~uVar4;
  if (((param2 & 0xf) == 0) && ((uVar5 & 0x18000000) == 0x8000000)) {
    if (padSpec < 2) {
      siFn_80016e8c(DAT_80396830);
      FUN_80016d9c();
    }
    else if (((uVar5 & 0x80000000) == 0) || ((uVar5 & 0x4000000) != 0)) {
      FUN_80016d30(DAT_80396830,0);
      if ((uVar5 & 0x1000000) == 0) {
        FUN_80016d9c();
      }
      else if (uVar3 == 0) {
        local_24[0] = (undefined *)0x41000000;
        FUN_8000ce74(DAT_80396830,(int)local_24,1,&DAT_80326c18 + DAT_80396830 * 0xc,10,-0x7ffe8d64,
                     0,0);
      }
      else {
        local_24[0] = &DAT_42000000;
        FUN_8000ce74(DAT_80396830,(int)local_24,3,&DAT_80326c18 + DAT_80396830 * 0xc,10,-0x7ffe8d64,
                     0,0);
      }
    }
    else {
      uVar1 = FUN_80016ce4(DAT_80396830);
      uVar3 = (uint)uVar1 << 8;
      if ((uVar2 == 0) || ((uVar3 & 0x100000) == 0)) {
        if ((uVar5 & 0x100000) == 0) {
          if ((uVar5 & 0x40000000) == 0) {
            FUN_80016d30(DAT_80396830,0);
            padFn_80016f24(DAT_80396830);
            FUN_80016d9c();
          }
          else {
            FUN_80016d30(DAT_80396830,(ushort)((uVar5 & 0xcfff00) >> 8) | 0x1000);
            local_24[0] = (undefined *)(uVar5 & 0xcfff00 | 0x4e100000);
            FUN_8000ce74(DAT_80396830,(int)local_24,3,&DAT_80326c08 + DAT_80396830 * 4,3,-0x7ffe8c4c
                         ,0,0);
          }
        }
        else if ((uVar3 & 0xcfff00) == (uVar5 & 0xcfff00)) {
          if ((((uVar5 & 0x40000000) != 0) && ((uVar5 & 0x80000) == 0)) && ((uVar5 & 0x40000) == 0))
          {
            local_24[0] = (undefined *)0x41000000;
            FUN_8000ce74(DAT_80396830,(int)local_24,1,&DAT_80326c18 + DAT_80396830 * 0xc,10,
                         -0x7ffe8d64,0,0);
            return;
          }
          local_24[0] = (undefined *)(DAT_80396830 << 0x16 | 0x4d000000 | (osPadType & 0x3fff) << 8)
          ;
          FUN_8000ce74(DAT_80396830,(int)local_24,3,&DAT_80326c18 + DAT_80396830 * 0xc,8,-0x7ffe901c
                       ,0,0);
        }
        else {
          if ((uVar3 & 0x100000) == 0) {
            uVar3 = uVar5 & 0xcfff00 | 0x100000;
            FUN_80016d30(DAT_80396830,(short)(uVar3 >> 8));
          }
          local_24[0] = (undefined *)(uVar3 | 0x4e000000);
          FUN_8000ce74(DAT_80396830,(int)local_24,3,&DAT_80326c08 + DAT_80396830 * 4,3,-0x7ffe8c4c,0
                       ,0);
        }
      }
      else {
        local_24[0] = (undefined *)(uVar3 & 0xcfff00 | 0x4e100000);
        FUN_8000ce74(DAT_80396830,(int)local_24,3,&DAT_80326c08 + DAT_80396830 * 4,3,-0x7ffe8c4c,0,0
                    );
      }
    }
  }
  else {
    FUN_80016d30(DAT_80396830,0);
    FUN_80016d9c();
  }
  return;
}


/* Library Function - Single Match
    PADReset
   
   Library: KioskDefault 0 0 */

BOOL_ PADReset(u32 mask) { //800178D4
  BOOL_ level;
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if ((mask & 0xfffffff) != 0) {
                    
    OSPanic("Pad.c",0x392,"PADReset(): invalid mask");
  }
  level = OSDisableInterrupts();
  uVar2 = mask & ~(DAT_803983b8 | DAT_803983ac | DAT_803983b4);
  DAT_803983a8 = DAT_803983a8 | uVar2;
  DAT_803983a4 = DAT_803983a4 & ~uVar2;
  DAT_803983b4 = DAT_803983b4 & ~uVar2;
  if (padSpec == 4) {
    DAT_803983b0 = DAT_803983b0 | uVar2;
  }
  SIDisablePolling(DAT_803983a8);
  if (DAT_80396830 == 0x20) {
    iVar1 = FUN_80016d9c();
  }
  OSRestoreInterrupts(level);
  return iVar1;
}


/* Library Function - Single Match
    PADReset2
   
   Library: KioskDefault 0 0 */

int PADReset2(uint param1) { //800179A4
  BOOL_ level;
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if ((param1 & 0xfffffff) != 0) {
                    
    OSPanic("Pad.c",0x3bd,"PADReset(): invalid mask");
  }
  level = OSDisableInterrupts();
  uVar2 = param1 & ~(DAT_803983b8 | DAT_803983ac | DAT_803983b4);
  DAT_803983a8 = DAT_803983a8 | uVar2;
  DAT_803983a4 = DAT_803983a4 & ~uVar2;
  DAT_803983b0 = DAT_803983b0 | uVar2;
  SIDisablePolling(DAT_803983a8);
  if (DAT_80396830 == 0x20) {
    iVar1 = FUN_80016d9c();
  }
  OSRestoreInterrupts(level);
  return iVar1;
}


/* Library Function - Single Match
    PADSetSamplingRate
   
   Library: KioskDefault 0 0 */

void PADSetSamplingRate(u32 msec) { //80017EF0
  int iVar1;
  
  if (0xb < msec) {
                    
    OSPanic("Pad.c",0x4ce,"PADSetSamplingRate(): out of rage (0 <= msec <= 11)");
  }
  if (0xb < msec) {
    msec = 0xb;
  }
  iVar1 = VIGetTvFormat();
  if (iVar1 == 1) {
    iVar1 = -0x7fd29158;
  }
  else {
    if (iVar1 < 1) {
      if (iVar1 < 0) {
LAB_80017f6c:
                    
        OSPanic("Pad.c",0x4df,"PADSetSamplingRate: unknown TV format");
      }
    }
    else if (2 < iVar1) goto LAB_80017f6c;
    iVar1 = -0x7fd29170;
  }
  SISetXY((uint)*(byte *)(iVar1 + msec * 2),(uint)*(byte *)(iVar1 + msec * 2 + 1));
  SIEnablePolling(DAT_803983a4);
  return;
}


/* Library Function - Single Match
    PADControlMotor
   
   Library: KioskDefault 0 0 */

void PADControlMotor(int chan,u32 command) { //80017FB4
  BOOL_ level;
  
  if ((command & 0xfffffffc) != 0) {
                    
    OSPanic("Pad.c",0x568,"PADControlMotor(): invalid command");
  }
  level = OSDisableInterrupts();
  if ((DAT_803983a4 & 0x80000000U >> chan) != 0) {
    if (((DAT_803983ac & 0x80000000U >> chan) == 0) &&
       ((*(uint *)(&DAT_80326c08 + chan * 4) & 0x20000000) == 0)) {
      if ((padSpec < 2) && (command == 2)) {
        command = 0;
      }
      SISetCommand(chan,DAT_80396834 | 0x400000 | command & 3);
      set_SR_to_8000_0000();
    }
  }
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    padFn_80018080
   
   Library: KioskDefault 0 0 */

void PADSetSpec(int mode) { //80018080
  if (_padIsInit == FALSE) {
    padSpec2 = 0;
    if (mode == 1) {
      PTR_padCb_final_8039683c = padCb_proto1;
    }
    else if (mode < 1) {
      if (-1 < mode) {
        PTR_padCb_final_8039683c = padCb_breadboard;
      }
    }
    else if (mode < 6) {
      PTR_padCb_final_8039683c = padCb_final;
    }
    padSpec = mode;
    return;
  }
                    
  OSPanic("Pad.c",0x58c,"Failed assertion !Initialized");
}

