
/* Library Function - Single Match
    cardReadFn_8003fe74
   
   Library: KioskDefault 0 0 */

int __CARDSeek(int *fileInfo,int param2,uint param3,int **param4) { //8003FE74
  int iVar1;
  char *pcVar2;
  int *local_28 [2];
  
  if ((*fileInfo < 0) || (1 < *fileInfo)) {
                    
    OSPanic("CARDRead.c",0x57,s_Failed_assertion_0_<__fileInfo_>_802e0134);
  }
  if ((-1 < fileInfo[1]) && (fileInfo[1] < 0x7f)) {
    iVar1 = __CARDGetControlBlock(*fileInfo,local_28);
    if (-1 < iVar1) {
      if ((*(ushort *)(fileInfo + 4) < 5) ||
         (*(ushort *)(local_28[0] + 4) <= *(ushort *)(fileInfo + 4))) {
                    
        OSPanic("CARDRead.c",0x5f,"Failed assertion CARDIsValidBlockNo(card, fileInfo->iBlock)");
      }
      if ((int)((uint)*(ushort *)(local_28[0] + 4) * local_28[0][3]) <= fileInfo[2]) {
                    
        OSPanic("CARDRead.c",0x60,s_Failed_assertion_fileInfo_>offse_802e01f8);
      }
      if (((*(ushort *)(fileInfo + 4) < 5) ||
          (*(ushort *)(local_28[0] + 4) <= *(ushort *)(fileInfo + 4))) ||
         ((int)((uint)*(ushort *)(local_28[0] + 4) * local_28[0][3]) <= fileInfo[2])) {
        iVar1 = cardBiosFn_8003c3ec(local_28[0],-0x80);
      }
      else {
        iVar1 = cardDirFn_8003d960((int)local_28[0]);
        pcVar2 = (char *)(iVar1 + fileInfo[1] * 0x40);
        if (*pcVar2 == -1) {
                    
          OSPanic("CARDRead.c",0x6a,s_Failed_assertion_ent_>gameName_0_802e023c);
        }
        if (((int)param3 < (int)((uint)*(ushort *)(pcVar2 + 0x38) * local_28[0][3])) &&
           ((int)(param3 + param2) <= (int)((uint)*(ushort *)(pcVar2 + 0x38) * local_28[0][3]))) {
          local_28[0][0x30] = (int)fileInfo;
          fileInfo[3] = param2;
          if ((int)param3 < fileInfo[2]) {
            fileInfo[2] = 0;
            *(undefined2 *)(fileInfo + 4) = *(undefined2 *)(pcVar2 + 0x36);
            if ((*(ushort *)(fileInfo + 4) < 5) ||
               (*(ushort *)(local_28[0] + 4) <= *(ushort *)(fileInfo + 4))) {
              iVar1 = cardBiosFn_8003c3ec(local_28[0],-6);
              return iVar1;
            }
          }
          iVar1 = cardBlockFn_8003d3e8((int)local_28[0]);
          do {
            if ((param3 & ~(local_28[0][3] - 1U)) <= (uint)fileInfo[2]) {
              fileInfo[2] = param3;
              *param4 = local_28[0];
              return 0;
            }
            fileInfo[2] = fileInfo[2] + local_28[0][3];
            *(undefined2 *)(fileInfo + 4) =
                 *(undefined2 *)(iVar1 + (uint)*(ushort *)(fileInfo + 4) * 2);
          } while ((4 < *(ushort *)(fileInfo + 4)) &&
                  (*(ushort *)(fileInfo + 4) < *(ushort *)(local_28[0] + 4)));
          iVar1 = cardBiosFn_8003c3ec(local_28[0],-6);
        }
        else {
          iVar1 = cardBiosFn_8003c3ec(local_28[0],-0xb);
        }
      }
    }
    return iVar1;
  }
                    
  OSPanic("CARDRead.c",0x58,s_Failed_assertion_0_<__fileInfo_>_802e0170);
}


/* Library Function - Single Match
    cardReadFn_80040148
   
   Library: KioskDefault 0 0 */

void cardReadCb_80040148(int param1,int param2) { //80040148
  int iVar1;
  int iVar2;
  uint length;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  iVar2 = param1 * 0x108;
  if (-1 < param2) {
    iVar5 = *(int *)(&DAT_80329000 + iVar2);
    if (*(int *)(iVar5 + 0xc) < 0) {
      param2 = -0xe;
    }
    else {
      iVar3 = (~(*(int *)(&DAT_80328f4c + iVar2) - 1U) &
              *(int *)(iVar5 + 8) +
              *(int *)(&DAT_80328f4c + iVar2) + *(int *)(&DAT_80328f4c + iVar2) + -1) -
              *(int *)(iVar5 + 8);
      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) - iVar3;
      if (0 < *(int *)(iVar5 + 0xc)) {
        iVar1 = cardBlockFn_8003d3e8((int)(&DAT_80328f40 + iVar2));
        *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + iVar3;
        *(undefined2 *)(iVar5 + 0x10) = *(undefined2 *)(iVar1 + (uint)*(ushort *)(iVar5 + 0x10) * 2)
        ;
        if ((*(ushort *)(iVar5 + 0x10) < 5) ||
           (*(ushort *)(&DAT_80328f50 + iVar2) <= *(ushort *)(iVar5 + 0x10))) {
          param2 = -6;
        }
        else {
          if ((*(uint *)(iVar5 + 0xc) & 0x1ff) != 0) {
                    
            OSPanic("CARDRead.c",0xbc,"Failed assertion OFFSET(fileInfo->length, CARD_SEG_SIZE) == 0");
          }
          if ((*(uint *)(iVar5 + 8) & *(int *)(&DAT_80328f4c + iVar2) - 1U) != 0) {
                    
            OSPanic("CARDRead.c",0xbd,"Failed assertion OFFSET(fileInfo->offset, card->sectorSize) == 0");
          }
          if (*(int *)(iVar5 + 0xc) < *(int *)(&DAT_80328f4c + iVar2)) {
            length = *(uint *)(iVar5 + 0xc);
          }
          else {
            length = *(uint *)(&DAT_80328f4c + iVar2);
          }
          param2 = cardRdWrFn_8003d15c(param1,*(int *)(&DAT_80328f4c + iVar2) *
                                              (uint)*(ushort *)(iVar5 + 0x10),length,
                                       *(undefined4 *)(&DAT_80328ff4 + iVar2),cardReadCb_80040148);
          if (-1 < param2) {
            return;
          }
        }
      }
    }
  }
  pcVar4 = *(code **)(&DAT_80329010 + iVar2);
  *(undefined4 *)(&DAT_80329010 + iVar2) = 0;
  cardBiosFn_8003c3ec((int *)(&DAT_80328f40 + iVar2),param2);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(param1,param2);
    return;
  }
                    
  OSPanic("CARDRead.c",0xce,"Failed assertion callback");
}


/* Library Function - Single Match
    cardReadFn_80040318
   
   Library: KioskDefault 0 0 */

int cardReadFn_80040318(int *param1,void *buf,uint param3,uint offset,undefined *callback) { //80040318
  int iVar1;
  code *callback_;
  char *pcVar2;
  uint uVar3;
  int *local_2c [2];
  
  if ((buf == (void *)0x0) || (((uint)buf & 0x1f) != 0)) {
                    
    OSPanic("CARDRead.c",0xf0,"Failed assertion buf && OFFSET(buf, 32) == 0");
  }
  if ((offset & 0x1ff) != 0) {
                    
    OSPanic("CARDRead.c",0xf1,"Failed assertion OFFSET(offset, CARD_SEG_SIZE) == 0");
  }
  if ((0 < (int)param3) && ((param3 & 0x1ff) == 0)) {
    if (((offset & 0x1ff) == 0) && ((param3 & 0x1ff) == 0)) {
      iVar1 = __CARDSeek(param1,param3,offset,local_2c);
      if (-1 < iVar1) {
        iVar1 = cardDirFn_8003d960((int)local_2c[0]);
        pcVar2 = (char *)(iVar1 + param1[1] * 0x40);
        iVar1 = FUN_8003f558(pcVar2);
        if (iVar1 == -10) {
          iVar1 = FUN_8003f5e8(pcVar2);
        }
        if (iVar1 < 0) {
          iVar1 = cardBiosFn_8003c3ec(local_2c[0],iVar1);
        }
        else {
          DCInvalidateRange(buf,param3);
          callback_ = (code *)callback;
          if (callback == (undefined *)0x0) {
            callback_ = nop_8003B08C;
          }
          local_2c[0][0x34] = (int)callback_;
          uVar3 = param1[2] & local_2c[0][3] - 1U;
          if ((int)(local_2c[0][3] - uVar3) <= (int)param3) {
            param3 = local_2c[0][3] - uVar3;
          }
          iVar1 = cardRdWrFn_8003d15c(*param1,uVar3 + local_2c[0][3] * (uint)*(ushort *)(param1 + 4)
                                      ,param3,buf,cardReadCb_80040148);
          if (iVar1 < 0) {
            cardBiosFn_8003c3ec(local_2c[0],iVar1);
          }
        }
      }
    }
    else {
      iVar1 = -0x80;
    }
    return iVar1;
  }
                    
  OSPanic("CARDRead.c",0xf2,s_Failed_assertion_0_<_length_&&_O_802e036c);
}

