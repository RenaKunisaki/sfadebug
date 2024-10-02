
/* Library Function - Single Match
    cardUnlockFn_8003c7ec
   
   Library: KioskDefault 0 0 */

undefined4 ReadArrayUnlock(int param1,uint param2,int param3,int param4,int param5) { //8003C7EC
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined local_1c;
  byte local_1b;
  undefined local_1a;
  byte local_19;
  byte local_18;
  
  if ((-1 < param1) && (param1 < 2)) {
    iVar5 = EXISelect(param1,0,4);
    if (iVar5 == 0) {
      uVar6 = 0xfffffffd;
    }
    else {
      memset_(&local_1c,0,5);
      local_1c = 0x52;
      local_1b = (byte)((param2 & 0xfffff000) >> 0x18);
      if (param5 == 0) {
        local_1b = local_1b >> 5 & 3;
        local_1a = (undefined)(param2 >> 0x15);
        local_19 = (byte)(param2 >> 0x13) & 3;
        local_18 = (byte)(param2 >> 0xc) & 0x7f;
      }
      else {
        local_1a = (undefined)((param2 & 0xfffff000) >> 0x10);
      }
      uVar6 = EXIImmEx(param1,(int)&local_1c,5,1);
      uVar1 = countLeadingZeros(uVar6);
      uVar6 = EXIImmEx(param1,*(int *)(&DAT_80328fc0 + param1 * 0x108) + 0x200,
                       *(int *)(&DAT_80328f54 + param1 * 0x108),1);
      uVar2 = countLeadingZeros(uVar6);
      uVar6 = EXIImmEx(param1,param3,param4,0);
      uVar3 = countLeadingZeros(uVar6);
      uVar6 = EXIDeselect(param1);
      uVar4 = countLeadingZeros(uVar6);
      if ((uVar1 | uVar2 | uVar3 | uVar4) >> 5 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = 0xfffffffd;
      }
    }
    return uVar6;
  }
                    
  OSPanic("CARDUnlock.c",0xd1,s_Failed_assertion_0_<__chan_&&_ch_802dfb30);
}


/* Library Function - Single Match
    cardUnlockFn_8003cdf0
   
   Library: KioskDefault 0 0 */

void cardUnlockFn_8003cdf0(int chan) { //8003CDF0
  ushort uVar1;
  undefined4 param1;
  undefined *unaff_r30;
  int iVar2;
  
  for (iVar2 = 0;
      (iVar2 < 2 && (unaff_r30 = &DAT_80328f40 + iVar2 * 0x108, iVar2 * 0x108 + -0x7fcd7090 != chan)
      ); iVar2 = iVar2 + 1) {
  }
  if ((-1 < iVar2) && (iVar2 < 2)) {
    param1 = *(undefined4 *)(unaff_r30 + 0x80);
    dspSendMail(0xff000000);
    do {
      uVar1 = dspGetMailHi();
    } while (uVar1 != 0);
    dspSendMail(param1);
    do {
      uVar1 = dspGetMailHi();
    } while (uVar1 != 0);
    return;
  }
                    
  OSPanic("CARDUnlock.c",0x1e3,s_Failed_assertion_0_<__chan_&&_ch_802dfb30);
}


/* Library Function - Single Match
    cardUnlockFn_8003cea4
   
   Library: KioskDefault 0 0 */

void cardUnlockFn_8003cea4(int param1) { //8003CEA4
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *unaff_r30;
  int param1_00;
  byte local_7c [4];
  undefined auStack_78 [64];
  
  for (param1_00 = 0;
      (param1_00 < 2 &&
      (unaff_r30 = &DAT_80328f40 + param1_00 * 0x108, param1_00 * 0x108 + -0x7fcd7090 != param1));
      param1_00 = param1_00 + 1) {
  }
  if ((-1 < param1_00) && (param1_00 < 2)) {
    uVar4 = *(uint *)((*(int *)(unaff_r30 + 0x80) + 0x2fU & 0xffffffe0) + 0x20);
    uVar1 = FUN_8003c9b8();
    iVar2 = ReadArrayUnlock(param1_00,(uVar4 ^ *(uint *)(unaff_r30 + 0x28)) & 0xffff0000,
                            (int)auStack_78,uVar1,1);
    if (iVar2 < 0) {
      EXIUnlock(param1_00);
      __CARDMountCallback(param1_00,-3);
    }
    uVar1 = FUN_8003c708(*(uint *)(unaff_r30 + 0x28),
                         (uVar1 + *(int *)(unaff_r30 + 0x14) + 4) * 8 + 1);
    *(uint *)(unaff_r30 + 0x28) =
         uVar1 | ~(uVar1 << 0x17 ^ uVar1 << 0xf ^ uVar1 ^ uVar1 << 7) >> 0x1f;
    uVar1 = FUN_8003c9b8();
    iVar2 = ReadArrayUnlock(param1_00,(uVar4 << 0x10 ^ *(uint *)(unaff_r30 + 0x28)) & 0xffff0000,
                            (int)auStack_78,uVar1,1);
    if (iVar2 < 0) {
      EXIUnlock(param1_00);
      __CARDMountCallback(param1_00,-3);
    }
    iVar2 = __CARDReadStatus(param1_00,(int)local_7c);
    iVar3 = __EXIProbe(param1_00);
    if (iVar3 == 0) {
      EXIUnlock(param1_00);
      __CARDMountCallback(param1_00,-3);
    }
    if ((iVar2 == 0) && ((local_7c[0] & 0x40) == 0)) {
      EXIUnlock(param1_00);
      iVar2 = -5;
    }
    __CARDMountCallback(param1_00,iVar2);
    return;
  }
                    
  OSPanic("CARDUnlock.c",0x214,s_Failed_assertion_0_<__chan_&&_ch_802dfb30);
}

