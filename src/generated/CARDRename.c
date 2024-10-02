
/* Library Function - Single Match
    cardRenameFn_80040f48
   
   Library: KioskDefault 0 0 */

int cardRenameFn_80040f48(int chan,char *oldName,char *newName,undefined4 param4) { //80040F48
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  OSTime OVar8;
  undefined8 uVar9;
  int *local_38 [2];
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDRename.c",0x49,s_Failed_assertion_0_<__chan_&&_ch_802e05c8);
  }
  if ((*oldName != 0xff) && (*newName != 0xff)) {
    if ((*oldName != '\0') && (*newName != '\0')) {
      if ((((*oldName == 0xff) || (*newName == 0xff)) || (*oldName == '\0')) || (*newName == '\0'))
      {
        iVar1 = -0x80;
      }
      else {
        uVar2 = strlen(oldName);
        if ((uVar2 < 0x21) && (uVar2 = strlen(newName), uVar2 < 0x21)) {
          iVar1 = __CARDGetControlBlock(chan,local_38);
          if (-1 < iVar1) {
            iVar5 = -1;
            iVar1 = -1;
            iVar3 = cardDirFn_8003d960((int)local_38[0]);
            for (iVar6 = 0; iVar6 < 0x7f; iVar6 = iVar6 + 1) {
              pcVar7 = (char *)(iVar3 + iVar6 * 0x40);
              if (((*pcVar7 != -1) && (iVar4 = memcmp(pcVar7,PTR_gameCode_80398538,4), iVar4 == 0))
                 && (iVar4 = memcmp(pcVar7 + 4,PTR_gameCode_80398538 + 4,2), iVar4 == 0)) {
                iVar4 = __CARDCompareFileName((int)pcVar7,oldName);
                if (iVar4 != 0) {
                  iVar5 = iVar6;
                }
                iVar4 = __CARDCompareFileName((int)pcVar7,newName);
                if (iVar4 != 0) {
                  iVar1 = iVar6;
                }
              }
            }
            if (iVar5 == -1) {
              iVar1 = cardBiosFn_8003c3ec(local_38[0],-4);
            }
            else if (iVar1 == -1) {
              pcVar7 = (char *)(iVar3 + iVar5 * 0x40);
              iVar1 = FUN_8003f558(pcVar7);
              if (iVar1 < 0) {
                iVar1 = cardBiosFn_8003c3ec(local_38[0],iVar1);
              }
              else {
                strncpy(pcVar7 + 8,newName,0x20);
                uVar2 = busClockMhz >> 2;
                OVar8 = OSGetTime();
                uVar9 = __div2i((uint)((ulonglong)OVar8 >> 0x20),(uint)OVar8,0,uVar2);
                *(int *)(pcVar7 + 0x28) = (int)uVar9;
                iVar1 = cardDirFn_8003db94(chan,param4);
                if (iVar1 < 0) {
                  cardBiosFn_8003c3ec(local_38[0],iVar1);
                }
              }
            }
            else {
              iVar1 = cardBiosFn_8003c3ec(local_38[0],-7);
            }
          }
        }
        else {
          iVar1 = -0xc;
        }
      }
      return iVar1;
    }
                    
    OSPanic("CARDRename.c",0x4b,"Failed assertion *old != 0x00 && *new != 0x00");
  }
                    
  OSPanic("CARDRename.c",0x4a,"Failed assertion *old != 0xff && *new != 0xff");
}

