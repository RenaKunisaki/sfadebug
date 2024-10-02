
/* Library Function - Single Match
    cardStatFn_80040dc8
   
   Library: KioskDefault 0 0 */

int cardStatFn_80040dc8(int chan,int fileNo,void *out) { //80040DC8
  int iVar1;
  char *__src;
  int *local_24 [2];
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDStat.c",0x97,s_Failed_assertion_0_<__chan_&&_ch_802e0554);
  }
  if ((-1 < fileNo) && (fileNo < 0x7f)) {
    if ((fileNo < 0) || (0x7e < fileNo)) {
      iVar1 = -0x80;
    }
    else {
      iVar1 = __CARDGetControlBlock(chan,local_24);
      if (-1 < iVar1) {
        iVar1 = cardDirFn_8003d960((int)local_24[0]);
        __src = (char *)(iVar1 + fileNo * 0x40);
        iVar1 = FUN_8003f558(__src);
        if (iVar1 == -10) {
          iVar1 = FUN_8003f5e8(__src);
        }
        if (-1 < iVar1) {
          memcpy((void *)((int)out + 0x28),__src,4);
          memcpy((void *)((int)out + 0x2c),__src + 4,2);
          *(uint *)((int)out + 0x20) = (uint)*(ushort *)(__src + 0x38) * local_24[0][3];
          memcpy(out,__src + 8,0x20);
          *(undefined4 *)((int)out + 0x24) = *(undefined4 *)(__src + 0x28);
          *(char *)((int)out + 0x2e) = __src[7];
          *(undefined4 *)((int)out + 0x30) = *(undefined4 *)(__src + 0x2c);
          *(undefined2 *)((int)out + 0x34) = *(undefined2 *)(__src + 0x30);
          *(undefined2 *)((int)out + 0x36) = *(undefined2 *)(__src + 0x32);
          *(undefined4 *)((int)out + 0x38) = *(undefined4 *)(__src + 0x3c);
          FUN_80040c98((int)__src,(int)out);
        }
        iVar1 = cardBiosFn_8003c3ec(local_24[0],iVar1);
      }
    }
    return iVar1;
  }
                    
  OSPanic("CARDStat.c",0x98,s_Failed_assertion_0_<__fileNo_&&_f_802e057c);
}

