
int cardOpenFn_8003f6c0(int param1,int param2,int *param3) { //8003F6C0
  int iVar1;
  char *pcVar2;
  int *local_24 [2];
  
  if ((param2 < 0) || (0x7e < param2)) {
                    
    OSPanic("CARDOpen.c",0xdc,s_Failed_assertion_0_<__fileNo_&&_f_802dff54);
  }
  if ((-1 < param1) && (param1 < 2)) {
    if ((param2 < 0) || (0x7e < param2)) {
      iVar1 = -0x80;
    }
    else {
      *param3 = -1;
      iVar1 = __CARDGetControlBlock(param1,local_24);
      if (-1 < iVar1) {
        iVar1 = cardDirFn_8003d960((int)local_24[0]);
        pcVar2 = (char *)(iVar1 + param2 * 0x40);
        iVar1 = FUN_8003f558(pcVar2);
        if (iVar1 == -10) {
          iVar1 = FUN_8003f5e8(pcVar2);
        }
        if (-1 < iVar1) {
          if ((*(ushort *)(pcVar2 + 0x36) < 5) ||
             (*(ushort *)(local_24[0] + 4) <= *(ushort *)(pcVar2 + 0x36))) {
            iVar1 = -6;
          }
          else {
            *param3 = param1;
            param3[1] = param2;
            param3[2] = 0;
            *(undefined2 *)(param3 + 4) = *(undefined2 *)(pcVar2 + 0x36);
          }
        }
        iVar1 = cardBiosFn_8003c3ec(local_24[0],iVar1);
      }
    }
    return iVar1;
  }
                    
  OSPanic("CARDOpen.c",0xdd,s_Failed_assertion_0_<__chan_&&_ch_802dff8c);
}


/* Library Function - Single Match
    cardOpenFn_8003f808
   
   Library: KioskDefault 0 0 */

int cardOpenFn_8003f808(int chan,char *param2,int *param3) { //8003F808
  int iVar1;
  int iVar2;
  int local_24;
  int *local_20 [3];
  
  if ((-1 < chan) && (chan < 2)) {
    *param3 = -1;
    iVar1 = __CARDGetControlBlock(chan,local_20);
    if (-1 < iVar1) {
      iVar1 = FUN_8003f618(local_20[0],param2,&local_24);
      if (-1 < iVar1) {
        iVar2 = cardDirFn_8003d960((int)local_20[0]);
        iVar2 = iVar2 + local_24 * 0x40;
        if ((*(ushort *)(iVar2 + 0x36) < 5) ||
           (*(ushort *)(local_20[0] + 4) <= *(ushort *)(iVar2 + 0x36))) {
          iVar1 = -6;
        }
        else {
          *param3 = chan;
          param3[1] = local_24;
          param3[2] = 0;
          *(undefined2 *)(param3 + 4) = *(undefined2 *)(iVar2 + 0x36);
        }
      }
      iVar1 = cardBiosFn_8003c3ec(local_20[0],iVar1);
    }
    return iVar1;
  }
                    
  OSPanic("CARDOpen.c",0x11a,s_Failed_assertion_0_<__chan_&&_ch_802dff8c);
}


/* Library Function - Single Match
    cardOpenFn_8003f910
   
   Library: KioskDefault 0 0 */

int cardOpenFn_8003f910(int *param1) { //8003F910
  int iVar1;
  int *local_14 [2];
  
  if ((*param1 < 0) || (1 < *param1)) {
                    
    OSPanic("CARDOpen.c",0x146,s_Failed_assertion_0_<__fileInfo_>_802dffb4);
  }
  if ((-1 < param1[1]) && (param1[1] < 0x7f)) {
    iVar1 = __CARDGetControlBlock(*param1,local_14);
    if (-1 < iVar1) {
      *param1 = -1;
      iVar1 = cardBiosFn_8003c3ec(local_14[0],0);
    }
    return iVar1;
  }
                    
  OSPanic("CARDOpen.c",0x147,s_Failed_assertion_0_<__fileInfo_>_802dfff0);
}

