
/* Library Function - Single Match
    cardDirFn_8003d960
   
   Library: KioskDefault 0 0 */

undefined4 cardDirFn_8003d960(int param1) { //8003D960
  if (*(int *)(param1 + 0x84) == 0) {
                    
    OSPanic("CARDDir.c",0x36,s_Failed_assertion_card_>currentDi_802dfcb4);
  }
  return *(undefined4 *)(param1 + 0x84);
}


/* Library Function - Single Match
    cardDirFn_8003d9b4
   
   Library: KioskDefault 0 0 */

void WriteCallback(int param1,int param2) { //8003D9B4
  int iVar1;
  code *pcVar2;
  void *__src;
  void *__dest;
  
  iVar1 = param1 * 0x108;
  if (-1 < param2) {
    __dest = (void *)(*(int *)(&DAT_80328fc0 + iVar1) + 0x2000);
    __src = (void *)(*(int *)(&DAT_80328fc0 + iVar1) + 0x4000);
    if (*(int *)(&DAT_80328fc4 + iVar1) == 0) {
                    
      OSPanic("CARDDir.c",0x4f,s_Failed_assertion_card_>currentDi_802dfcb4);
    }
    if (*(void **)(&DAT_80328fc4 + iVar1) == __dest) {
      *(void **)(&DAT_80328fc4 + iVar1) = __src;
      memcpy(__src,__dest,0x2000);
    }
    else {
      if (*(void **)(&DAT_80328fc4 + iVar1) != __src) {
                    
        OSPanic("CARDDir.c",0x57,s_Failed_assertion_card_>currentDi_802dfcd8);
      }
      *(void **)(&DAT_80328fc4 + iVar1) = __dest;
      memcpy(__dest,__src,0x2000);
    }
  }
  if (*(int *)(&DAT_80329010 + iVar1) == 0) {
    cardBiosFn_8003c3ec((int *)(&DAT_80328f40 + iVar1),param2);
  }
  pcVar2 = *(code **)(&DAT_80329018 + iVar1);
  if (pcVar2 != (code *)0x0) {
    *(undefined4 *)(&DAT_80329018 + iVar1) = 0;
    (*pcVar2)(param1,param2);
  }
  return;
}


/* Library Function - Single Match
    cardDirFn_8003db94
   
   Library: KioskDefault 0 0 */

int cardDirFn_8003db94(int param1,undefined4 param2) { //8003DB94
  ushort *param1_00;
  int iVar1;
  
  if ((-1 < param1) && (param1 < 2)) {
    iVar1 = param1 * 0x108;
    if (*(int *)(&DAT_80328f40 + iVar1) == 0) {
      iVar1 = -3;
    }
    else {
      param1_00 = (ushort *)cardDirFn_8003d960((int)(&DAT_80328f40 + iVar1));
      param1_00[0xffd] = param1_00[0xffd] + 1;
      cardCheckFn_8003dc7c
                (param1_00,0x1ffc,(short *)(param1_00 + 0xffe),(short *)(param1_00 + 0xfff));
      DCStoreRange(param1_00,0x2000);
      *(undefined4 *)(&DAT_80329018 + iVar1) = param2;
      iVar1 = cardBiosFn_8003c130(param1,*(int *)(&DAT_80328f4c + iVar1) *
                                         ((uint)((int)param1_00 - *(int *)(&DAT_80328fc0 + iVar1))
                                         >> 0xd),-0x7ffc2538);
    }
    return iVar1;
  }
                    
  OSPanic("CARDDir.c",0xad,s_Failed_assertion_0_<__chan_&&_ch_802dfd04);
}

