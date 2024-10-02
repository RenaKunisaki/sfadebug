
/* Library Function - Single Match
    cardDeleteFn_80040ac4
   
   Library: KioskDefault 0 0 */

int cardDeleteFn_80040ac4(int chan,int fileNo,undefined *param3) { //80040AC4
  int iVar1;
  code *pcVar2;
  char *__s;
  int *local_24 [2];
  
  if ((fileNo < 0) || (0x7e < fileNo)) {
                    
    OSPanic("CARDDelete.c",0x78,s_Failed_assertion_0_<__fileNo_&&_f_802e04e8);
  }
  if ((-1 < chan) && (chan < 2)) {
    if ((fileNo < 0) || (0x7e < fileNo)) {
      iVar1 = -0x80;
    }
    else {
      iVar1 = __CARDGetControlBlock(chan,local_24);
      if (-1 < iVar1) {
        iVar1 = cardDirFn_8003d960((int)local_24[0]);
        __s = (char *)(iVar1 + fileNo * 0x40);
        iVar1 = FUN_8003f558(__s);
        if (iVar1 < 0) {
          iVar1 = cardBiosFn_8003c3ec(local_24[0],iVar1);
        }
        else {
          iVar1 = ret0_8003F9CC();
          if (iVar1 == 0) {
            *(undefined2 *)((int)local_24[0] + 0xbe) = *(undefined2 *)(__s + 0x36);
            memset_(__s,0xff,0x40);
            pcVar2 = (code *)param3;
            if (param3 == (undefined *)0x0) {
              pcVar2 = nop_8003B08C;
            }
            local_24[0][0x34] = (int)pcVar2;
            iVar1 = cardDirFn_8003db94(chan,cardDeleteCb_80040a30);
            if (iVar1 < 0) {
              cardBiosFn_8003c3ec(local_24[0],iVar1);
            }
          }
          else {
            iVar1 = cardBiosFn_8003c3ec(local_24[0],-1);
          }
        }
      }
    }
    return iVar1;
  }
                    
  OSPanic("CARDDelete.c",0x79,s_Failed_assertion_0_<__chan_&&_ch_802e0520);
}

