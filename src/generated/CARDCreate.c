
/* Library Function - Single Match
    cardCreateFn_8003f9d4
   
   Library: KioskDefault 0 0 */

void CreateCallbackFat(int param1,int param2) { //8003F9D4
  uint param4;
  int iVar1;
  int iVar2;
  code *param2_00;
  void *__dest;
  OSTime OVar3;
  undefined8 uVar4;
  
  iVar2 = param1 * 0x108;
  param2_00 = *(code **)(&DAT_80329010 + iVar2);
  *(undefined4 *)(&DAT_80329010 + iVar2) = 0;
  if (-1 < param2) {
    iVar1 = cardDirFn_8003d960((int)(&DAT_80328f40 + iVar2));
    __dest = (void *)(iVar1 + (uint)*(ushort *)(&DAT_80328ffc + iVar2) * 0x40);
    memcpy(__dest,PTR_gameCode_80398538,4);
    memcpy((void *)((int)__dest + 4),PTR_gameCode_80398538 + 4,2);
    *(undefined *)((int)__dest + 0x34) = 4;
    *(undefined *)((int)__dest + 0x35) = 0;
    if ((*(ushort *)(&DAT_80328ffe + iVar2) < 5) ||
       (*(ushort *)(&DAT_80328f50 + iVar2) <= *(ushort *)(&DAT_80328ffe + iVar2))) {
                    
      OSPanic("CARDCreate.c",0x66,"Failed assertion CARDIsValidBlockNo(card, card->startBlock)");
    }
    *(undefined2 *)((int)__dest + 0x36) = *(undefined2 *)(&DAT_80328ffe + iVar2);
    *(undefined *)((int)__dest + 7) = 0;
    *(undefined4 *)((int)__dest + 0x2c) = 0xffffffff;
    *(undefined2 *)((int)__dest + 0x30) = 0;
    *(undefined2 *)((int)__dest + 0x32) = 0;
    *(undefined4 *)((int)__dest + 0x3c) = 0xffffffff;
    *(undefined4 *)(*(int *)(&DAT_80329000 + iVar2) + 8) = 0;
    *(undefined2 *)(*(int *)(&DAT_80329000 + iVar2) + 0x10) = *(undefined2 *)((int)__dest + 0x36);
    param4 = busClockMhz >> 2;
    OVar3 = OSGetTime();
    uVar4 = __div2i((uint)((ulonglong)OVar3 >> 0x20),(uint)OVar3,0,param4);
    *(int *)((int)__dest + 0x28) = (int)uVar4;
    param2 = cardDirFn_8003db94(param1,param2_00);
    if (-1 < param2) {
      return;
    }
  }
  cardBiosFn_8003c3ec((int *)(&DAT_80328f40 + iVar2),param2);
  if (param2_00 != (code *)0x0) {
    (*param2_00)(param1,param2);
  }
  return;
}


/* Library Function - Single Match
    cardCreateFn_8003fb54
   
   Library: KioskDefault 0 0 */

int CARDCreateAsync(int chan,char *fileName,uint param3,int *param4,undefined *param5) { //8003FB54
  uint uVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  ushort uVar5;
  ushort uVar6;
  char *__s1;
  int *local_34;
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDCreate.c",0xa4,s_Failed_assertion_0_<__chan_&&_ch_802e008c);
  }
  uVar1 = strlen(fileName);
  if (0x20 < uVar1) {
                    
    OSPanic("CARDCreate.c",0xa5,"Failed assertion strlen(fileName) <= CARD_FILENAME_MAX");
  }
  uVar1 = strlen(fileName);
  if (uVar1 < 0x21) {
    iVar2 = __CARDGetControlBlock(chan,&local_34);
    if (-1 < iVar2) {
      if ((param3 == 0) || (param3 != (param3 / (uint)local_34[3]) * local_34[3])) {
                    
        OSPanic("CARDCreate.c",0xb1,s_Failed_assertion_0_<_size_&&_(si_802e00ec);
      }
      if ((param3 == 0) || (param3 != (param3 / (uint)local_34[3]) * local_34[3])) {
        iVar2 = -0x80;
      }
      else {
        uVar6 = 0xffff;
        iVar2 = cardDirFn_8003d960((int)local_34);
        for (uVar5 = 0; uVar5 < 0x7f; uVar5 = uVar5 + 1) {
          __s1 = (char *)(iVar2 + (uint)uVar5 * 0x40);
          if (*__s1 == -1) {
            if (uVar6 == 0xffff) {
              uVar6 = uVar5;
            }
          }
          else {
            iVar3 = memcmp(__s1,PTR_gameCode_80398538,4);
            if (((iVar3 == 0) && (iVar3 = memcmp(__s1 + 4,PTR_gameCode_80398538 + 4,2), iVar3 == 0))
               && (iVar3 = __CARDCompareFileName((int)__s1,fileName), iVar3 != 0)) {
              iVar2 = cardBiosFn_8003c3ec(local_34,-7);
              return iVar2;
            }
          }
        }
        if (uVar6 == 0xffff) {
          iVar2 = cardBiosFn_8003c3ec(local_34,-8);
        }
        else {
          iVar3 = cardBlockFn_8003d3e8((int)local_34);
          if (local_34[3] * (uint)*(ushort *)(iVar3 + 6) < param3) {
            iVar2 = cardBiosFn_8003c3ec(local_34,-9);
          }
          else {
            pcVar4 = (code *)param5;
            if (param5 == (undefined *)0x0) {
              pcVar4 = nop_8003B08C;
            }
            local_34[0x34] = (int)pcVar4;
            *(ushort *)(local_34 + 0x2f) = uVar6;
            iVar2 = iVar2 + (uint)uVar6 * 0x40;
            *(short *)(iVar2 + 0x38) = (short)(param3 / (uint)local_34[3]);
            strncpy((char *)(iVar2 + 8),fileName,0x20);
            local_34[0x30] = (int)param4;
            *param4 = chan;
            param4[1] = (uint)uVar6;
            iVar2 = cardBlockFn_8003d620(chan,param3 / (uint)local_34[3],CreateCallbackFat);
            if (iVar2 < 0) {
              iVar2 = cardBiosFn_8003c3ec(local_34,iVar2);
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = -0xc;
  }
  return iVar2;
}

