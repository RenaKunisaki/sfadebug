
/* Library Function - Single Match
    cardBlockFn_8003d3e8
   
   Library: KioskDefault 0 0 */

undefined4 cardBlockFn_8003d3e8(int param1) { //8003D3E8
  if (*(int *)(param1 + 0x88) == 0) {
                    
    OSPanic("CARDBlock.c",0x39,s_Failed_assertion_card_>currentFa_802dfc14);
  }
  return *(undefined4 *)(param1 + 0x88);
}


/* Library Function - Single Match
    cardBlockFn_8003d43c
   
   Library: KioskDefault 0 0 */

void cardBlockFn_8003d43c(int param1,int param2) { //8003D43C
  int iVar1;
  code *pcVar2;
  void *__src;
  void *__dest;
  
  iVar1 = param1 * 0x108;
  if (-1 < param2) {
    __dest = (void *)(*(int *)(&DAT_80328fc0 + iVar1) + 0x6000);
    __src = (void *)(*(int *)(&DAT_80328fc0 + iVar1) + 0x8000);
    if (*(int *)(&DAT_80328fc8 + iVar1) == 0) {
                    
      OSPanic("CARDBlock.c",0x52,s_Failed_assertion_card_>currentFa_802dfc14);
    }
    if (*(void **)(&DAT_80328fc8 + iVar1) == __dest) {
      *(void **)(&DAT_80328fc8 + iVar1) = __src;
      memcpy(__src,__dest,0x2000);
    }
    else {
      if (*(void **)(&DAT_80328fc8 + iVar1) != __src) {
                    
        OSPanic("CARDBlock.c",0x5a,s_Failed_assertion_card_>currentFa_802dfc38);
      }
      *(void **)(&DAT_80328fc8 + iVar1) = __dest;
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
    cardBlockFn_8003d620
   
   Library: KioskDefault 0 0 */

undefined4 cardBlockFn_8003d620(int chan,uint cBlock,undefined4 param3) { //8003D620
  undefined4 uVar1;
  short *param2;
  int iVar2;
  uint uVar3;
  ushort unaff_r24;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  
  if (cBlock == 0) {
                    
    OSPanic("CARDBlock.c",0xb6,s_Failed_assertion_0_<_cBlock_802dfc64);
  }
  if ((-1 < chan) && (chan < 2)) {
    iVar2 = chan * 0x108;
    if (*(int *)(&DAT_80328f40 + iVar2) == 0) {
      uVar1 = 0xfffffffd;
    }
    else {
      param2 = (short *)cardBlockFn_8003d3e8((int)(&DAT_80328f40 + iVar2));
      if ((ushort)param2[3] < cBlock) {
        uVar1 = 0xfffffff7;
      }
      else {
        param2[3] = param2[3] - (short)cBlock;
        uVar6 = param2[4];
        uVar3 = 0;
        uVar5 = 0xffff;
        while (cBlock != 0) {
          uVar3 = uVar3 + 1;
          if ((int)(*(ushort *)(&DAT_80328f50 + iVar2) - 5) < (int)(uVar3 & 0xffff)) {
            return 0xfffffffa;
          }
          uVar6 = uVar6 + 1;
          if ((uVar6 < 5) || (*(ushort *)(&DAT_80328f50 + iVar2) <= uVar6)) {
            uVar6 = 5;
          }
          if (param2[uVar6] == 0) {
            uVar4 = uVar6;
            if (uVar5 != 0xffff) {
              param2[unaff_r24] = uVar6;
              uVar4 = uVar5;
            }
            param2[uVar6] = -1;
            cBlock = cBlock - 1;
            unaff_r24 = uVar6;
            uVar5 = uVar4;
          }
        }
        param2[4] = uVar6;
        *(ushort *)(&DAT_80328ffe + iVar2) = uVar5;
        uVar1 = cardBlockFn_8003d898(chan,param2,param3);
      }
    }
    return uVar1;
  }
                    
  OSPanic("CARDBlock.c",0xb7,s_Failed_assertion_0_<__chan_&&_ch_802dfc80);
}


/* Library Function - Single Match
    cardBlockFn_8003d7a4
   
   Library: KioskDefault 0 0 */

undefined4 cardBlockFn_8003d7a4(int chan,ushort param2,undefined4 param3) { //8003D7A4
  ushort uVar1;
  undefined4 uVar2;
  short *param2_00;
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDBlock.c",0xfd,s_Failed_assertion_0_<__chan_&&_ch_802dfc80);
  }
  if (*(int *)(&DAT_80328f40 + chan * 0x108) == 0) {
    uVar2 = 0xfffffffd;
  }
  else {
    param2_00 = (short *)cardBlockFn_8003d3e8((int)(&DAT_80328f40 + chan * 0x108));
    while (param2 != 0xffff) {
      if ((param2 < 5) || (*(ushort *)(&DAT_80328f50 + chan * 0x108) <= param2)) {
        return 0xfffffffa;
      }
      uVar1 = param2_00[param2];
      param2_00[param2] = 0;
      param2_00[3] = param2_00[3] + 1;
      param2 = uVar1;
    }
    uVar2 = cardBlockFn_8003d898(chan,param2_00,param3);
  }
  return uVar2;
}


/* Library Function - Single Match
    cardBlockFn_8003d898
   
   Library: KioskDefault 0 0 */

void cardBlockFn_8003d898(int chan,short *param2,undefined4 param3) { //8003D898
  int iVar1;
  
  if ((-1 < chan) && (chan < 2)) {
    iVar1 = chan * 0x108;
    param2[2] = param2[2] + 1;
    cardCheckFn_8003dc7c((ushort *)(param2 + 2),0x1ffc,param2,param2 + 1);
    DCStoreRange(param2,0x2000);
    *(undefined4 *)(&DAT_80329018 + iVar1) = param3;
    cardBiosFn_8003c130(chan,*(int *)(&DAT_80328f4c + iVar1) *
                             ((uint)((int)param2 - *(int *)(&DAT_80328fc0 + iVar1)) >> 0xd),
                        -0x7ffc2aac);
    return;
  }
                    
  OSPanic("CARDBlock.c",0x127,s_Failed_assertion_0_<__chan_&&_ch_802dfc80);
}

