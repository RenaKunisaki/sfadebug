
/* Library Function - Single Match
    cardRdWrFn_8003d15c
   
   Library: KioskDefault 0 0 */

int cardRdWrFn_8003d15c(int chan,undefined4 param2,uint length,undefined4 param4,undefined4 param5) { //8003D15C
  int iVar1;
  
  if (((int)length < 1) || ((length & 0x1ff) != 0)) {
                    
    OSPanic("CARDRdwr.c",0x58,s_Failed_assertion_0_<_length_&&_l_802dfb64);
  }
  if ((-1 < chan) && (chan < 2)) {
    iVar1 = chan * 0x108;
    if (*(int *)(&DAT_80328f40 + iVar1) == 0) {
      iVar1 = -3;
    }
    else {
      *(undefined4 *)(&DAT_80329014 + iVar1) = param5;
      *(uint *)(&DAT_80328fec + iVar1) = length >> 9;
      *(undefined4 *)(&DAT_80328ff0 + iVar1) = param2;
      *(undefined4 *)(&DAT_80328ff4 + iVar1) = param4;
      iVar1 = __CARDReadSegment(chan,-0x7ffc2f78);
    }
    return iVar1;
  }
                    
  OSPanic("CARDRdwr.c",0x59,s_Failed_assertion_0_<__chan_&&_ch_802dfba0);
}


/* Library Function - Single Match
    cardRdWrFn_8003d30c
   
   Library: KioskDefault 0 0 */

int cardRdWrFn_8003d30c(int chan,undefined4 param2,uint length,undefined4 param4,undefined4 param5) { //8003D30C
  int iVar1;
  
  if (((int)length < 1) || ((length & 0x7f) != 0)) {
                    
    OSPanic("CARDRdwr.c",0x95,s_Failed_assertion_0_<_length_&&_l_802dfbc8);
  }
  if ((-1 < chan) && (chan < 2)) {
    iVar1 = chan * 0x108;
    if (*(int *)(&DAT_80328f40 + iVar1) == 0) {
      iVar1 = -3;
    }
    else {
      *(undefined4 *)(&DAT_80329014 + iVar1) = param5;
      *(uint *)(&DAT_80328fec + iVar1) = length >> 7;
      *(undefined4 *)(&DAT_80328ff0 + iVar1) = param2;
      *(undefined4 *)(&DAT_80328ff4 + iVar1) = param4;
      iVar1 = __CARDWritePage(chan,-0x7ffc2dc8);
    }
    return iVar1;
  }
                    
  OSPanic("CARDRdwr.c",0x96,s_Failed_assertion_0_<__chan_&&_ch_802dfba0);
}

