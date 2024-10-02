
/* Library Function - Single Match
    cardBiosFn_8003b0d4
   
   Library: KioskDefault 0 0 */

void cardBiosCbFn_8003b0d4(int param1) { //8003B0D4
  int iVar1;
  code *pcVar2;
  
  if ((-1 < param1) && (param1 < 2)) {
    iVar1 = param1 * 0x108;
    if (*(int *)(&DAT_80328f40 + iVar1) != 0) {
      if (*(int *)(&DAT_80329008 + iVar1) != 0) {
                    
        OSPanic("CARDBios.c",0xba,s_Failed_assertion_card_>txCallbac_802df804);
      }
      *(int *)(&DAT_80328f40 + iVar1) = 0;
      (&DAT_80328f44)[param1 * 0x42] = 0xfffffffd;
      osExiFn_8000a4fc(param1,0);
      pcVar2 = *(code **)(&DAT_8032900c + iVar1);
      if (pcVar2 != (code *)0x0) {
        *(undefined4 *)(&DAT_8032900c + iVar1) = 0;
        (*pcVar2)(param1,0xfffffffd);
      }
      pcVar2 = *(code **)(&DAT_80329004 + iVar1);
      if ((pcVar2 != (code *)0x0) && (6 < *(int *)(&DAT_80328f64 + iVar1))) {
        *(undefined4 *)(&DAT_80329004 + iVar1) = 0;
        (*pcVar2)(param1,0xfffffffd);
      }
    }
    return;
  }
                    
  OSPanic("CARDBios.c",0xb6,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003b1dc
   
   Library: KioskDefault 0 0 */

void __CARDExiHandler(int chan) { //8003B1DC
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  byte local_18 [8];
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDBios.c",0xdc,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
  }
  iVar3 = chan * 0x108;
  osAlarmFn_80007e28((int *)(&DAT_80329020 + iVar3));
  if (*(int *)(&DAT_80328f40 + iVar3) == 0) {
    return;
  }
  iVar1 = osExiFn_8000af80(chan,0,0);
  if (iVar1 == 0) {
    iVar1 = -0x80;
  }
  else {
    iVar1 = __CARDReadStatus(chan,(int)local_18);
    if ((-1 < iVar1) && (iVar1 = __CARDClearStatus(chan), -1 < iVar1)) {
      if ((local_18[0] & 0x18) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = -5;
      }
      if ((iVar1 == -5) &&
         (iVar2 = *(int *)(&DAT_80328fe8 + iVar3), *(int *)(&DAT_80328fe8 + iVar3) = iVar2 + -1,
         0 < iVar2 + -1)) {
        iVar1 = cardBiosFn_8003ba10(chan);
        if (-1 < iVar1) {
          return;
        }
        goto LAB_8003b2d4;
      }
    }
    EXIUnlock(chan);
  }
LAB_8003b2d4:
  pcVar4 = *(code **)(&DAT_8032900c + iVar3);
  if (pcVar4 != (code *)0x0) {
    *(undefined4 *)(&DAT_8032900c + iVar3) = 0;
    (*pcVar4)(chan,iVar1);
  }
  return;
}


/* Library Function - Single Match
    cardBiosFn_8003b310
   
   Library: KioskDefault 0 0 */

void cardBiosFn_8003b310(int chan) { //8003B310
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if ((-1 < chan) && (chan < 2)) {
    EXIDeselect(chan);
    EXIUnlock(chan);
    pcVar3 = *(code **)(&DAT_80329008 + chan * 0x108);
    if (pcVar3 != (code *)0x0) {
      *(undefined4 *)(&DAT_80329008 + chan * 0x108) = 0;
      iVar1 = __EXIProbe(chan);
      if (iVar1 == 0) {
        uVar2 = 0xfffffffd;
      }
      else {
        uVar2 = 0;
      }
      (*pcVar3)(chan,uVar2);
    }
    return;
  }
                    
  OSPanic("CARDBios.c",0x12d,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosCb_8003b3c4
   
   Library: KioskDefault 0 0 */

void cardBiosFn_8003b3c4(int chan) { //8003B3C4
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if ((-1 < chan) && (chan < 2)) {
    pcVar3 = *(code **)(&DAT_8032901c + chan * 0x108);
    if (pcVar3 != (code *)0x0) {
      *(undefined4 *)(&DAT_8032901c + chan * 0x108) = 0;
      iVar1 = __EXIProbe(chan);
      if (iVar1 == 0) {
        uVar2 = 0xfffffffd;
      }
      else {
        uVar2 = 1;
      }
      (*pcVar3)(chan,uVar2);
    }
    return;
  }
                    
  OSPanic("CARDBios.c",0x15c,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003b468
   
   Library: KioskDefault 0 0 */

undefined4 cardBiosFn_8003b468(int chan,uint *param2) { //8003B468
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_18 [3];
  
  if ((-1 < chan) && (chan < 2)) {
    iVar6 = EXISelect(chan,0,0);
    if (iVar6 == 0) {
      uVar7 = 0xfffffffd;
    }
    else {
      local_18[0] = 0;
      uVar7 = osExiFn_80009f08(chan,(int)local_18,2,1,0);
      uVar1 = countLeadingZeros(uVar7);
      uVar7 = osExiFn_8000a354(chan);
      uVar2 = countLeadingZeros(uVar7);
      uVar7 = osExiFn_80009f08(chan,(int)param2,4,0,0);
      uVar3 = countLeadingZeros(uVar7);
      uVar7 = osExiFn_8000a354(chan);
      uVar4 = countLeadingZeros(uVar7);
      uVar7 = EXIDeselect(chan);
      uVar5 = countLeadingZeros(uVar7);
      if ((uVar1 | uVar2 | uVar3 | uVar4 | uVar5) >> 5 == 0) {
        if (((*param2 & 0xffff0000) == 0) && ((*param2 & 3) == 0)) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0xfffffffe;
        }
      }
      else {
        uVar7 = 0xfffffffd;
      }
    }
    return uVar7;
  }
                    
  OSPanic("CARDBios.c",0x16f,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003b5a4
   
   Library: KioskDefault 0 0 */

undefined4 __CARDEnableInterrupt(int chan,int param2) { //8003B5A4
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *local_10 [2];
  
  if ((-1 < chan) && (chan < 2)) {
    iVar4 = EXISelect(chan,0,4);
    if (iVar4 == 0) {
      uVar5 = 0xfffffffd;
    }
    else {
      if (param2 == 0) {
        local_10[0] = &DAT_81000000;
      }
      else {
        local_10[0] = &DAT_81010000;
      }
      uVar5 = osExiFn_80009f08(chan,(int)local_10,2,1,0);
      uVar1 = countLeadingZeros(uVar5);
      uVar5 = osExiFn_8000a354(chan);
      uVar2 = countLeadingZeros(uVar5);
      uVar5 = EXIDeselect(chan);
      uVar3 = countLeadingZeros(uVar5);
      if ((uVar1 | uVar2 | uVar3) >> 5 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xfffffffd;
      }
    }
    return uVar5;
  }
                    
  OSPanic("CARDBios.c",400,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003b69c
   
   Library: KioskDefault 0 0 */

undefined4 __CARDReadStatus(int chan,int param2) { //8003B69C
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_10 [2];
  
  if ((-1 < chan) && (chan < 2)) {
    iVar6 = EXISelect(chan,0,4);
    if (iVar6 == 0) {
      uVar7 = 0xfffffffd;
    }
    else {
      local_10[0] = 0x83000000;
      uVar7 = osExiFn_80009f08(chan,(int)local_10,2,1,0);
      uVar1 = countLeadingZeros(uVar7);
      uVar7 = osExiFn_8000a354(chan);
      uVar2 = countLeadingZeros(uVar7);
      uVar7 = osExiFn_80009f08(chan,param2,1,0,0);
      uVar3 = countLeadingZeros(uVar7);
      uVar7 = osExiFn_8000a354(chan);
      uVar4 = countLeadingZeros(uVar7);
      uVar7 = EXIDeselect(chan);
      uVar5 = countLeadingZeros(uVar7);
      if ((uVar1 | uVar2 | uVar3 | uVar4 | uVar5) >> 5 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 0xfffffffd;
      }
    }
    return uVar7;
  }
                    
  OSPanic("CARDBios.c",0x1a3,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003b7b8
   
   Library: KioskDefault 0 0 */

undefined4 __CARDClearStatus(int chan) { //8003B7B8
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_c;
  
  if ((-1 < chan) && (chan < 2)) {
    iVar4 = EXISelect(chan,0,4);
    if (iVar4 == 0) {
      uVar5 = 0xfffffffd;
    }
    else {
      local_c = 0x89000000;
      uVar5 = osExiFn_80009f08(chan,(int)&local_c,1,1,0);
      uVar1 = countLeadingZeros(uVar5);
      uVar5 = osExiFn_8000a354(chan);
      uVar2 = countLeadingZeros(uVar5);
      uVar5 = EXIDeselect(chan);
      uVar3 = countLeadingZeros(uVar5);
      if ((uVar1 | uVar2 | uVar3) >> 5 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xfffffffd;
      }
    }
    return uVar5;
  }
                    
  OSPanic("CARDBios.c",0x1b8,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003b898
   
   Library: KioskDefault 0 0 */

void cardBiosFn_8003b898(undefined *param1) { //8003B898
  code *pcVar1;
  undefined *unaff_r30;
  int chan;
  
  for (chan = 0;
      (chan < 2 &&
      (unaff_r30 = &DAT_80328f40 + chan * 0x108, param1 != &DAT_80329020 + chan * 0x108));
      chan = chan + 1) {
  }
  if ((-1 < chan) && (chan < 2)) {
    osExiFn_8000a4fc(chan,0);
    pcVar1 = *(code **)(unaff_r30 + 0xcc);
    if (pcVar1 != (code *)0x0) {
      *(undefined4 *)(unaff_r30 + 0xcc) = 0;
      (*pcVar1)(chan,0xfffffffb);
    }
    return;
  }
                    
  OSPanic("CARDBios.c",0x20e,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003ba10
   
   Library: KioskDefault 0 0 */

undefined4 cardBiosFn_8003ba10(int param1) { //8003BA10
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint len;
  
  if ((-1 < param1) && (param1 < 2)) {
    iVar3 = param1 * 0x108;
    iVar1 = EXISelect(param1,0,4);
    if (iVar1 == 0) {
      EXIUnlock(param1);
      uVar2 = 0xfffffffd;
    }
    else {
      FUN_8003b954((int)(&DAT_80328f40 + iVar3));
      iVar1 = EXIImmEx(param1,(int)(&DAT_80328fd4 + iVar3),*(int *)(&DAT_80328fe0 + iVar3),1);
      if (iVar1 == 0) {
        EXIDeselect(param1);
        EXIUnlock(param1);
        uVar2 = 0xfffffffd;
      }
      else if (((&DAT_80328fd4)[iVar3] == 'R') &&
              (iVar1 = EXIImmEx(param1,*(int *)(&DAT_80328fc0 + iVar3) + 0x200,
                                *(int *)(&DAT_80328f54 + iVar3),1), iVar1 == 0)) {
        EXIDeselect(param1);
        EXIUnlock(param1);
        uVar2 = 0xfffffffd;
      }
      else if (*(int *)(&DAT_80328fe4 + iVar3) == -1) {
        EXIDeselect(param1);
        EXIUnlock(param1);
        uVar2 = 0;
      }
      else {
        if ((&DAT_80328fd4)[iVar3] == 'R') {
          len = 0x200;
        }
        else {
          len = 0x80;
        }
        iVar1 = osExiFn_8000a190(param1,*(uint *)(&DAT_80328ff4 + iVar3),len,
                                 *(int *)(&DAT_80328fe4 + iVar3),cardBiosFn_8003b310);
        if (iVar1 == 0) {
          EXIDeselect(param1);
          EXIUnlock(param1);
          uVar2 = 0xfffffffd;
        }
        else {
          uVar2 = 0;
        }
      }
    }
    return uVar2;
  }
                    
  OSPanic("CARDBios.c",0x247,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003bb98
   
   Library: KioskDefault 0 0 */

void UnlockedCallback(int chan,int param2) { //8003BB98
  byte bVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDBios.c",0x287,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
  }
  iVar3 = chan * 0x108;
  if (-1 < param2) {
    *(code **)(&DAT_8032901c + iVar3) = UnlockedCallback;
    iVar2 = osExiFn_8000af80(chan,0,-0x7ffc4c3c);
    if (iVar2 == 0) {
      param2 = 0;
    }
    else {
      *(undefined4 *)(&DAT_8032901c + iVar3) = 0;
      param2 = cardBiosFn_8003ba10(chan);
    }
  }
  if (param2 < 0) {
    bVar1 = (&DAT_80328fd4)[iVar3];
    if (bVar1 != 0xf3) {
      if (bVar1 < 0xf3) {
        if (bVar1 == 0x52) {
          pcVar4 = *(code **)(&DAT_80329008 + iVar3);
          if (pcVar4 == (code *)0x0) {
            return;
          }
          *(undefined4 *)(&DAT_80329008 + iVar3) = 0;
          (*pcVar4)(chan,param2);
          return;
        }
        if (bVar1 < 0x52) {
          return;
        }
        if (bVar1 < 0xf1) {
          return;
        }
      }
      else if (0xf4 < bVar1) {
        return;
      }
      pcVar4 = *(code **)(&DAT_8032900c + iVar3);
      if (pcVar4 != (code *)0x0) {
        *(undefined4 *)(&DAT_8032900c + iVar3) = 0;
        (*pcVar4)(chan,param2);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    cardBiosFn_8003bcdc
   
   Library: KioskDefault 0 0 */

undefined4 cardBiosFn_8003bcdc(int chan,int param2,int param3) { //8003BCDC
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((-1 < chan) && (chan < 2)) {
    iVar3 = chan * 0x108;
    if (*(int *)(&DAT_80328f40 + iVar3) == 0) {
      uVar1 = 0xfffffffd;
    }
    else {
      if (param2 != 0) {
        *(int *)(&DAT_80329008 + iVar3) = param2;
      }
      if (param3 != 0) {
        *(int *)(&DAT_8032900c + iVar3) = param3;
      }
      *(code **)(&DAT_8032901c + iVar3) = UnlockedCallback;
      iVar2 = osExiFn_8000af80(chan,0,-0x7ffc4c3c);
      if (iVar2 == 0) {
        uVar1 = 0xffffffff;
      }
      else {
        *(undefined4 *)(&DAT_8032901c + iVar3) = 0;
        iVar2 = EXISelect(chan,0,4);
        if (iVar2 == 0) {
          EXIUnlock(chan);
          uVar1 = 0xfffffffd;
        }
        else {
          FUN_8003b954((int)(&DAT_80328f40 + iVar3));
          uVar1 = 0;
        }
      }
    }
    return uVar1;
  }
                    
  OSPanic("CARDBios.c",0x2c5,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}


/* Library Function - Single Match
    cardBiosFn_8003bde0
   
   Library: KioskDefault 0 0 */

int __CARDReadSegment(int chan,int param2) { //8003BDE0
  int iVar1;
  int iVar2;
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDBios.c",0x2f9,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
  }
  iVar2 = chan * 0x108;
  if ((*(uint *)(&DAT_80328ff0 + iVar2) & 0x1ff) != 0) {
                    
    OSPanic("CARDBios.c",0x2fb,s_Failed_assertion_card_>addr___CA_802df82c);
  }
  if (*(uint *)(&DAT_80328ff0 + iVar2) < (*(ushort *)(&DAT_80328f48 + iVar2) & 0xfff) << 0x11) {
    (&DAT_80328fd4)[iVar2] = 0x52;
    (&DAT_80328fd5)[iVar2] = (byte)(*(uint *)(&DAT_80328ff0 + iVar2) >> 0x11) & 0x7f;
    (&DAT_80328fd6)[iVar2] = (char)(*(uint *)(&DAT_80328ff0 + iVar2) >> 9);
    (&DAT_80328fd7)[iVar2] = (byte)(*(uint *)(&DAT_80328ff0 + iVar2) >> 7) & 3;
    (&DAT_80328fd8)[iVar2] = (byte)*(undefined4 *)(&DAT_80328ff0 + iVar2) & 0x7f;
    *(undefined4 *)(&DAT_80328fe0 + iVar2) = 5;
    *(undefined4 *)(&DAT_80328fe4 + iVar2) = 0;
    *(undefined4 *)(&DAT_80328fe8 + iVar2) = 0;
    iVar1 = cardBiosFn_8003bcdc(chan,param2,0);
    if (iVar1 == -1) {
      iVar1 = 0;
    }
    else if (-1 < iVar1) {
      iVar1 = EXIImmEx(chan,(int)(&DAT_80328fd4 + iVar2),*(int *)(&DAT_80328fe0 + iVar2),1);
      if (((iVar1 == 0) ||
          (iVar1 = EXIImmEx(chan,*(int *)(&DAT_80328fc0 + iVar2) + 0x200,
                            *(int *)(&DAT_80328f54 + iVar2),1), iVar1 == 0)) ||
         (iVar1 = osExiFn_8000a190(chan,*(uint *)(&DAT_80328ff4 + iVar2),0x200,
                                   *(int *)(&DAT_80328fe4 + iVar2),cardBiosFn_8003b310), iVar1 == 0)
         ) {
        *(undefined4 *)(&DAT_80329008 + iVar2) = 0;
        EXIDeselect(chan);
        EXIUnlock(chan);
        iVar1 = -3;
      }
      else {
        iVar1 = 0;
      }
    }
    return iVar1;
  }
                    
  OSPanic("CARDBios.c",0x2fc,s_Failed_assertion_card_>addr_<_(u_802df860);
}


/* Library Function - Single Match
    cardBiosFn_8003bf98
   
   Library: KioskDefault 0 0 */

int __CARDWritePage(int chan,int param2) { //8003BF98
  int iVar1;
  int iVar2;
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDBios.c",0x331,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
  }
  iVar2 = chan * 0x108;
  if ((*(uint *)(&DAT_80328ff0 + iVar2) & 0x7f) != 0) {
                    
    OSPanic("CARDBios.c",0x333,s_Failed_assertion_card_>addr___CA_802df8a4);
  }
  if (*(uint *)(&DAT_80328ff0 + iVar2) < (*(ushort *)(&DAT_80328f48 + iVar2) & 0xfff) << 0x11) {
    (&DAT_80328fd4)[iVar2] = 0xf2;
    (&DAT_80328fd5)[iVar2] = (byte)(*(uint *)(&DAT_80328ff0 + iVar2) >> 0x11) & 0x7f;
    (&DAT_80328fd6)[iVar2] = (char)(*(uint *)(&DAT_80328ff0 + iVar2) >> 9);
    (&DAT_80328fd7)[iVar2] = (byte)(*(uint *)(&DAT_80328ff0 + iVar2) >> 7) & 3;
    (&DAT_80328fd8)[iVar2] = (byte)*(undefined4 *)(&DAT_80328ff0 + iVar2) & 0x7f;
    *(undefined4 *)(&DAT_80328fe0 + iVar2) = 5;
    *(undefined4 *)(&DAT_80328fe4 + iVar2) = 1;
    *(undefined4 *)(&DAT_80328fe8 + iVar2) = 3;
    iVar1 = cardBiosFn_8003bcdc(chan,0,param2);
    if (iVar1 == -1) {
      iVar1 = 0;
    }
    else if (-1 < iVar1) {
      iVar1 = EXIImmEx(chan,(int)(&DAT_80328fd4 + iVar2),*(int *)(&DAT_80328fe0 + iVar2),1);
      if ((iVar1 == 0) ||
         (iVar1 = osExiFn_8000a190(chan,*(uint *)(&DAT_80328ff4 + iVar2),0x80,
                                   *(int *)(&DAT_80328fe4 + iVar2),cardBiosFn_8003b310), iVar1 == 0)
         ) {
        *(undefined4 *)(&DAT_8032900c + iVar2) = 0;
        EXIDeselect(chan);
        EXIUnlock(chan);
        iVar1 = -3;
      }
      else {
        iVar1 = 0;
      }
    }
    return iVar1;
  }
                    
  OSPanic("CARDBios.c",0x334,s_Failed_assertion_card_>addr_<_(u_802df860);
}


/* Library Function - Single Match
    cardBiosFn_8003c130
   
   Library: KioskDefault 0 0 */

int cardBiosFn_8003c130(int chan,uint param2,int param3) { //8003C130
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDBios.c",0x394,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
  }
  iVar3 = chan * 0x108;
  if (param2 != (param2 / *(uint *)(&DAT_80328f4c + iVar3)) * *(uint *)(&DAT_80328f4c + iVar3)) {
                    
    OSPanic("CARDBios.c",0x396,s_Failed_assertion_addr___card_>se_802df8d8);
  }
  if (param2 < (*(ushort *)(&DAT_80328f48 + iVar3) & 0xfff) << 0x11) {
    (&DAT_80328fd4)[iVar3] = 0xf1;
    (&DAT_80328fd5)[iVar3] = (byte)(param2 >> 0x11) & 0x7f;
    (&DAT_80328fd6)[iVar3] = (char)(param2 >> 9);
    *(undefined4 *)(&DAT_80328fe0 + iVar3) = 3;
    *(undefined4 *)(&DAT_80328fe4 + iVar3) = 0xffffffff;
    *(undefined4 *)(&DAT_80328fe8 + iVar3) = 3;
    iVar1 = cardBiosFn_8003bcdc(chan,0,param3);
    if (iVar1 == -1) {
      iVar1 = 0;
    }
    else if (-1 < iVar1) {
      iVar1 = 0;
      iVar2 = EXIImmEx(chan,(int)(&DAT_80328fd4 + iVar3),*(int *)(&DAT_80328fe0 + iVar3),1);
      if (iVar2 == 0) {
        iVar1 = -3;
        *(undefined4 *)(&DAT_8032900c + iVar3) = 0;
      }
      EXIDeselect(chan);
      EXIUnlock(chan);
    }
    return iVar1;
  }
                    
  OSPanic("CARDBios.c",0x397,s_Failed_assertion_addr_<_(u32)_ca_802df908);
}


undefined4 __CARDGetControlBlock(int param1,int **param2) { //8003C334
  undefined4 uVar1;
  BOOL_ level;
  
  if (((param1 < 0) || (1 < param1)) || (PTR_gameCode_80398538 == (undefined *)0x0)) {
    uVar1 = 0xffffff80;
  }
  else {
    level = OSDisableInterrupts();
    if (*(int *)(&DAT_80328f40 + param1 * 0x108) == 0) {
      uVar1 = 0xfffffffd;
    }
    else if ((&DAT_80328f44)[param1 * 0x42] == -1) {
      uVar1 = 0xffffffff;
    }
    else {
      (&DAT_80328f44)[param1 * 0x42] = 0xffffffff;
      uVar1 = 0;
      *(undefined4 *)(&DAT_80329010 + param1 * 0x108) = 0;
      *param2 = (int *)(&DAT_80328f40 + param1 * 0x108);
    }
    OSRestoreInterrupts(level);
  }
  return uVar1;
}


/* Library Function - Single Match
    cardBiosFn_8003c3ec
   
   Library: KioskDefault 0 0 */

int cardBiosFn_8003c3ec(int *param1,int result) { //8003C3EC
  BOOL_ level;
  
  if (result == -1) {
                    
    OSPanic("CARDBios.c",0x43a,"Failed assertion result != CARD_RESULT_BUSY");
  }
  level = OSDisableInterrupts();
  if (*param1 == 0) {
    if (param1[1] != -3) {
                    
      OSPanic("CARDBios.c",0x442,s_Failed_assertion_card_>result____802df970);
    }
  }
  else {
    param1[1] = result;
  }
  OSRestoreInterrupts(level);
  return result;
}


/* Library Function - Single Match
    cardBiosFn_8003c484
   
   Library: KioskDefault 0 0 */

undefined4 cardBiosFn_8003c484(int chan) { //8003C484
  undefined4 uVar1;
  
  if ((-1 < chan) && (chan < 2)) {
    if ((chan < 0) || (1 < chan)) {
      uVar1 = 0xffffff80;
    }
    else {
      uVar1 = (&DAT_80328f44)[chan * 0x42];
    }
    return uVar1;
  }
                    
  OSPanic("CARDBios.c",0x455,s_Failed_assertion_0_<__chan_&&_ch_802df7dc);
}

