
/* Library Function - Single Match
    cardCheckFn_8003dc7c
   
   Library: KioskDefault 0 0 */

void cardCheckFn_8003dc7c(ushort *param1,uint length,short *param3,short *param4) { //8003DC7C
  int iVar1;
  
  if ((length & 1) != 0) {
                    
    OSPanic("CARDCheck.c",0x44,"Failed assertion length % sizeof(u16) == 0");
  }
  *param4 = 0;
  *param3 = 0;
  for (iVar1 = 0; iVar1 < (int)(((int)length >> 1) + (uint)((int)length < 0 && (length & 1) != 0));
      iVar1 = iVar1 + 1) {
    *param3 = *param3 + *param1;
    *param4 = *param4 + ~*param1;
    param1 = param1 + 1;
  }
  if (*param3 == -1) {
    *param3 = 0;
  }
  if (*param4 == -1) {
    *param4 = 0;
  }
  return;
}


/* Library Function - Single Match
    cardCheckFn_8003e218
   
   Library: KioskDefault 0 0 */

int __CARDVerify(int param1) { //8003E218
  int iVar1;
  int iVar2;
  
  iVar1 = cardCheckFn_8003dd50(param1);
  if (-1 < iVar1) {
    iVar1 = cardCheckFn_8003defc(param1,(uint *)0x0);
    iVar2 = cardCheckFn_8003e07c(param1,(uint *)0x0);
    iVar1 = iVar1 + iVar2;
    if (iVar1 == 1) {
      iVar1 = -6;
    }
    else if ((iVar1 < 1) && (-1 < iVar1)) {
      if (*(int *)(param1 + 0x84) == 0) {
                    
        OSPanic("CARDCheck.c",0x11f,s_Failed_assertion_card_>currentDi_802dfd68);
      }
      if (*(int *)(param1 + 0x88) == 0) {
                    
        OSPanic("CARDCheck.c",0x120,s_Failed_assertion_card_>currentFa_802dfd8c);
      }
      iVar1 = 0;
    }
    else {
      iVar1 = -6;
    }
  }
  return iVar1;
}


/* Library Function - Single Match
    cardCheckFn_8003e2f0
   
   Library: KioskDefault 0 0 */

int cardCheckFn_8003e2f0(int param1,undefined4 param2) { //8003E2F0
  bool bVar1;
  byte bVar2;
  bool bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  ushort uVar8;
  void *__s;
  char *pcVar9;
  ushort uVar10;
  uint local_60;
  uint local_5c;
  void *local_58;
  int local_54;
  void *local_50;
  int local_4c;
  int *local_48 [3];
  
  bVar2 = 0;
  bVar3 = false;
  bVar1 = false;
  if ((param1 < 0) || (1 < param1)) {
                    
    OSPanic("CARDCheck.c",0x14a,s_Failed_assertion_0_<__chan_&&_ch_802dfdb0);
  }
  iVar5 = __CARDGetControlBlock(param1,local_48);
  if (-1 < iVar5) {
    iVar5 = cardCheckFn_8003dd50((int)local_48[0]);
    if (iVar5 < 0) {
      iVar5 = cardBiosFn_8003c3ec(local_48[0],iVar5);
    }
    else {
      iVar5 = cardCheckFn_8003defc((int)local_48[0],&local_60);
      iVar6 = cardCheckFn_8003e07c((int)local_48[0],&local_5c);
      iVar5 = iVar5 + iVar6;
      if (iVar5 < 2) {
        local_50 = (void *)(local_48[0][0x20] + 0x2000);
        local_4c = local_48[0][0x20] + 0x4000;
        local_58 = (void *)(local_48[0][0x20] + 0x6000);
        local_54 = local_48[0][0x20] + 0x8000;
        if ((iVar5 != 0) && (iVar5 != 1)) {
                    
          OSPanic("CARDCheck.c",0x163,"Failed assertion errors == 0 || errors == 1");
        }
        if (iVar5 == 1) {
          if (local_48[0][0x21] == 0) {
            if (local_48[0][0x22] == 0) {
                    
              OSPanic("CARDCheck.c",0x16d,s_Failed_assertion_card_>currentFa_802dfd8c);
            }
            local_48[0][0x21] = (int)(&local_50)[local_60];
            memcpy((&local_50)[local_60],(&local_50)[local_60 ^ 1],0x2000);
            bVar3 = true;
          }
          else {
            if (local_48[0][0x22] != 0) {
                    
              OSPanic("CARDCheck.c",0x174,s_Failed_assertion__card_>currentF_802dfe04);
            }
            local_48[0][0x22] = (int)(&local_58)[local_5c];
            memcpy((&local_58)[local_5c],(&local_58)[local_5c ^ 1],0x2000);
            bVar2 = 1;
          }
        }
        else if ((iVar5 < 1) && (-1 < iVar5)) {
          if (local_48[0][0x21] == 0) {
                    
            OSPanic("CARDCheck.c",0x167,s_Failed_assertion_card_>currentDi_802dfd68);
          }
          if (local_48[0][0x22] == 0) {
                    
            OSPanic("CARDCheck.c",0x168,s_Failed_assertion_card_>currentFa_802dfd8c);
          }
        }
        __s = (&local_58)[local_5c ^ 1];
        memset_(__s,0,0x2000);
        for (iVar5 = 0; iVar5 < 0x7f; iVar5 = iVar5 + 1) {
          pcVar9 = (char *)(local_48[0][0x21] + iVar5 * 0x40);
          if (*pcVar9 != -1) {
            uVar10 = *(ushort *)(pcVar9 + 0x36);
            for (uVar8 = 0; (uVar10 != 0xffff && (uVar8 < *(ushort *)(pcVar9 + 0x38)));
                uVar8 = uVar8 + 1) {
              if ((uVar10 < 5) ||
                 ((*(ushort *)(local_48[0] + 4) <= uVar10 ||
                  (iVar6 = (uint)uVar10 * 2, uVar4 = *(short *)((int)__s + iVar6) + 1,
                  *(ushort *)((int)__s + iVar6) = uVar4, 1 < uVar4)))) {
                iVar5 = cardBiosFn_8003c3ec(local_48[0],-6);
                return iVar5;
              }
              uVar10 = *(ushort *)(local_48[0][0x22] + (uint)uVar10 * 2);
            }
            if ((uVar8 != *(ushort *)(pcVar9 + 0x38)) || (uVar10 != 0xffff)) {
              iVar5 = cardBiosFn_8003c3ec(local_48[0],-6);
              return iVar5;
            }
          }
        }
        sVar7 = 0;
        for (uVar10 = 5; uVar10 < *(ushort *)(local_48[0] + 4); uVar10 = uVar10 + 1) {
          uVar8 = *(ushort *)(local_48[0][0x22] + (uint)uVar10 * 2);
          if (*(short *)((int)__s + (uint)uVar10 * 2) == 0) {
            if (uVar8 != 0) {
              *(undefined2 *)(local_48[0][0x22] + (uint)uVar10 * 2) = 0;
              bVar1 = true;
            }
            sVar7 = sVar7 + 1;
          }
          else if (((uVar8 < 5) || (*(ushort *)(local_48[0] + 4) <= uVar8)) && (uVar8 != 0xffff)) {
            iVar5 = cardBiosFn_8003c3ec(local_48[0],-6);
            return iVar5;
          }
        }
        if (sVar7 != *(short *)(local_48[0][0x22] + 6)) {
          *(short *)(local_48[0][0x22] + 6) = sVar7;
          bVar1 = true;
        }
        if (bVar1) {
          cardCheckFn_8003dc7c
                    ((ushort *)(local_48[0][0x22] + 4),0x1ffc,(short *)local_48[0][0x22],
                     (short *)(local_48[0][0x22] + 2));
        }
        memcpy((&local_58)[local_5c ^ 1],(&local_58)[local_5c],0x2000);
        if (bVar3) {
          iVar5 = cardDirFn_8003db94(param1,param2);
        }
        else if ((bool)(bVar2 | bVar1)) {
          iVar5 = cardBlockFn_8003d898(param1,(short *)local_48[0][0x22],param2);
        }
        else {
          iVar5 = cardBiosFn_8003c3ec(local_48[0],0);
        }
      }
      else {
        iVar5 = cardBiosFn_8003c3ec(local_48[0],-6);
      }
    }
  }
  return iVar5;
}

