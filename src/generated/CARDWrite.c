
/* Library Function - Single Match
    cardWriteFn_80040560
   
   Library: KioskDefault 0 0 */

void WriteCallback(int param1,int param2) { //80040560
  uint param4;
  int iVar1;
  int iVar2;
  undefined4 param2_00;
  code *pcVar3;
  int iVar4;
  int *param1_00;
  OSTime OVar5;
  undefined8 uVar6;
  
  iVar2 = param1 * 0x108;
  param1_00 = (int *)(&DAT_80328f40 + iVar2);
  if (-1 < param2) {
    iVar4 = *(int *)(&DAT_80329000 + iVar2);
    if (*(int *)(iVar4 + 0xc) < 0) {
      param2 = -0xe;
    }
    else {
      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) - *(int *)(&DAT_80328f4c + iVar2);
      if (*(int *)(iVar4 + 0xc) < 1) {
        iVar1 = cardDirFn_8003d960((int)param1_00);
        iVar4 = *(int *)(iVar4 + 4);
        param4 = busClockMhz >> 2;
        OVar5 = OSGetTime();
        uVar6 = __div2i((uint)((ulonglong)OVar5 >> 0x20),(uint)OVar5,0,param4);
        *(int *)(iVar1 + iVar4 * 0x40 + 0x28) = (int)uVar6;
        param2_00 = *(undefined4 *)(&DAT_80329010 + iVar2);
        *(undefined4 *)(&DAT_80329010 + iVar2) = 0;
        param2 = cardDirFn_8003db94(param1,param2_00);
      }
      else {
        iVar1 = cardBlockFn_8003d3e8((int)param1_00);
        *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + *(int *)(&DAT_80328f4c + iVar2);
        *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(iVar1 + (uint)*(ushort *)(iVar4 + 0x10) * 2)
        ;
        if ((*(ushort *)(iVar4 + 0x10) < 5) ||
           (*(ushort *)(&DAT_80328f50 + iVar2) <= *(ushort *)(iVar4 + 0x10))) {
          param2 = -6;
          goto LAB_80040698;
        }
        param2 = cardBiosFn_8003c130(param1,*(int *)(&DAT_80328f4c + iVar2) *
                                            (uint)*(ushort *)(iVar4 + 0x10),-0x7ffbf904);
      }
      if (-1 < param2) {
        return;
      }
    }
  }
LAB_80040698:
  pcVar3 = *(code **)(&DAT_80329010 + iVar2);
  *(undefined4 *)(&DAT_80329010 + iVar2) = 0;
  cardBiosFn_8003c3ec(param1_00,param2);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(param1,param2);
    return;
  }
                    
  OSPanic("CARDWrite.c",0x7d,"Failed assertion callback");
}


/* Library Function - Single Match
    cardWriteFn_800406fc
   
   Library: KioskDefault 0 0 */

void cardWriteCb_800406fc(int param1,int param2) { //800406FC
  int iVar1;
  code *pcVar2;
  
  iVar1 = param1 * 0x108;
  if (-1 < param2) {
    if ((*(uint *)(*(int *)(&DAT_80329000 + iVar1) + 8) & *(int *)(&DAT_80328f4c + iVar1) - 1U) != 0
       ) {
                    
      OSPanic("CARDWrite.c",0x98,"Failed assertion OFFSET(fileInfo->offset, card->sectorSize) == 0");
    }
    param2 = cardRdWrFn_8003d30c(param1,*(int *)(&DAT_80328f4c + iVar1) *
                                        (uint)*(ushort *)(*(int *)(&DAT_80329000 + iVar1) + 0x10),
                                 *(uint *)(&DAT_80328f4c + iVar1),
                                 *(undefined4 *)(&DAT_80328ff4 + iVar1),WriteCallback);
    if (-1 < param2) {
      return;
    }
  }
  pcVar2 = *(code **)(&DAT_80329010 + iVar1);
  *(undefined4 *)(&DAT_80329010 + iVar1) = 0;
  cardBiosFn_8003c3ec((int *)(&DAT_80328f40 + iVar1),param2);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param1,param2);
    return;
  }
                    
  OSPanic("CARDWrite.c",0xa6,"Failed assertion callback");
}


/* Library Function - Single Match
    cardWriteFn_800407ec
   
   Library: KioskDefault 0 0 */

int cardWriteFn_800407ec(int *param1,void *param2,uint param3,uint param4,undefined *param5) { //800407EC
  int iVar1;
  code *pcVar2;
  int *local_2c [2];
  
  if ((param2 == (void *)0x0) || (((uint)param2 & 0x1f) != 0)) {
                    
    OSPanic("CARDWrite.c",0xc9,"Failed assertion buf && ((u32) buf % 32) == 0");
  }
  if ((int)param3 < 1) {
                    
    OSPanic("CARDWrite.c",0xca,s_Failed_assertion_0_<_length_802e044c);
  }
  iVar1 = __CARDSeek(param1,param3,param4,local_2c);
  if (-1 < iVar1) {
    if ((param4 & local_2c[0][3] - 1U) != 0) {
                    
      OSPanic("CARDWrite.c",0xd0,"Failed assertion OFFSET(offset, card->sectorSize) == 0");
    }
    if ((param3 & local_2c[0][3] - 1U) != 0) {
                    
      OSPanic("CARDWrite.c",0xd1,"Failed assertion OFFSET(length, card->sectorSize) == 0");
    }
    if (((param4 & local_2c[0][3] - 1U) == 0) && ((param3 & local_2c[0][3] - 1U) == 0)) {
      iVar1 = cardDirFn_8003d960((int)local_2c[0]);
      iVar1 = FUN_8003f558((char *)(iVar1 + param1[1] * 0x40));
      if (iVar1 < 0) {
        iVar1 = cardBiosFn_8003c3ec(local_2c[0],iVar1);
      }
      else {
        DCStoreRange(param2,param3);
        pcVar2 = (code *)param5;
        if (param5 == (undefined *)0x0) {
          pcVar2 = nop_8003B08C;
        }
        local_2c[0][0x34] = (int)pcVar2;
        local_2c[0][0x2d] = (int)param2;
        iVar1 = cardBiosFn_8003c130(*param1,local_2c[0][3] * (uint)*(ushort *)(param1 + 4),
                                    -0x7ffbf904);
        if (iVar1 < 0) {
          cardBiosFn_8003c3ec(local_2c[0],iVar1);
        }
      }
    }
    else {
      iVar1 = cardBiosFn_8003c3ec(local_2c[0],-0x80);
    }
  }
  return iVar1;
}

