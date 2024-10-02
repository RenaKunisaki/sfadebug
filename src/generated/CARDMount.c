
/* Library Function - Single Match
    cardMountFn_8003e87c
   
   Library: KioskDefault 0 0 */

int cardMountFn_8003e87c(int chan) { //8003E87C
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int *param1;
  byte local_2c [4];
  uint local_28 [2];
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDMount.c",0xfe,s_Failed_assertion_0_<__chan_&&_ch_802dfe74);
  }
  iVar2 = chan * 0x108;
  param1 = (int *)(&DAT_80328f40 + iVar2);
  if (*(int *)(&DAT_80328f64 + iVar2) == 0) {
    iVar1 = cardBiosFn_8003b468(chan,local_28);
    if (-1 < iVar1) {
      *(ushort *)(&DAT_80328f48 + iVar2) = (ushort)local_28[0] & 0xfc;
      *(undefined4 *)(&DAT_80328f4c + iVar2) =
           *(undefined4 *)((int)&PTR_DAT_802dfe28 + (local_28[0] >> 9 & 0x1c));
      *(short *)(&DAT_80328f50 + iVar2) =
           (short)(((int)((uint)*(ushort *)(&DAT_80328f48 + iVar2) << 0x14) >> 3) /
                  *(int *)(&DAT_80328f4c + iVar2));
      *(undefined4 *)(&DAT_80328f54 + iVar2) =
           *(undefined4 *)(&DAT_802dfe48 + (local_28[0] >> 6 & 0x1c));
      if ((*(int *)(&DAT_80328f4c + iVar2) == 0) || (*(ushort *)(&DAT_80328f50 + iVar2) < 8)) {
        iVar1 = -2;
      }
      else {
        iVar1 = __CARDClearStatus(chan);
        if ((-1 < iVar1) && (iVar1 = __CARDReadStatus(chan,(int)local_2c), -1 < iVar1)) {
          iVar1 = __EXIProbe(chan);
          if (iVar1 == 0) {
            iVar1 = -3;
          }
          else if ((local_2c[0] & 0x40) == 0) {
            iVar1 = FUN_8003ca60(chan,(uint *)(&DAT_80328f58 + iVar2));
            if (-1 < iVar1) {
              bVar3 = 0;
              iVar2 = FUN_8000c390();
              for (iVar4 = 0; iVar4 < 0xc; iVar4 = iVar4 + 1) {
                *(undefined *)(iVar2 + chan * 0xc + iVar4) =
                     *(undefined *)((int)param1 + iVar4 + 0x18);
                bVar3 = bVar3 + *(char *)((int)param1 + iVar4 + 0x18);
              }
              *(byte *)(iVar2 + chan + 0x26) = ~bVar3;
              FUN_8000c4ec(1);
              return iVar1;
            }
          }
          else {
            *(undefined4 *)(&DAT_80328f64 + iVar2) = 1;
            bVar3 = 0;
            iVar1 = FUN_8000c390();
            for (iVar4 = 0; iVar4 < 0xc; iVar4 = iVar4 + 1) {
              bVar3 = bVar3 + *(char *)(iVar1 + chan * 0xc + iVar4);
            }
            FUN_8000c4ec(0);
            if (*(byte *)(iVar1 + chan + 0x26) == (byte)~bVar3) goto LAB_8003ea80;
            iVar1 = -5;
          }
        }
      }
    }
LAB_8003eb24:
    EXIUnlock(chan);
    cardMountFn_8003eecc(chan);
  }
  else {
LAB_8003ea80:
    if (*(int *)(&DAT_80328f64 + iVar2) == 1) {
      *(undefined4 *)(&DAT_80328f64 + iVar2) = 2;
      iVar1 = __CARDEnableInterrupt(chan,1);
      if (iVar1 < 0) goto LAB_8003eb24;
      osExiFn_8000a4fc(chan,-0x7ffc4e24);
      EXIUnlock(chan);
      DCInvalidateRange(*(void **)(&DAT_80328fc0 + iVar2),0xa000);
    }
    iVar1 = cardRdWrFn_8003d15c(chan,*(int *)(&DAT_80328f4c + iVar2) *
                                     (*(int *)(&DAT_80328f64 + iVar2) + -2),0x2000,
                                *(int *)(&DAT_80328fc0 + iVar2) +
                                (*(int *)(&DAT_80328f64 + iVar2) + -2) * 0x2000,__CARDMountCallback)
    ;
    if (iVar1 < 0) {
      cardBiosFn_8003c3ec(param1,iVar1);
    }
  }
  return iVar1;
}


/* Library Function - Single Match
    cardMountFn_8003eb4c
   
   Library: KioskDefault 0 0 */

void __CARDMountCallback(int chan,int param2) { //8003EB4C
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if ((chan < 0) || (1 < chan)) {
                    
    OSPanic("CARDMount.c",0x181,s_Failed_assertion_0_<__chan_&&_ch_802dfe74);
  }
  iVar2 = chan * 0x108;
  if (param2 != -3) {
    if (-4 < param2) {
      if (param2 == 1) {
        param2 = cardMountFn_8003e87c(chan);
      }
      else {
        if ((0 < param2) || (param2 < 0)) goto LAB_8003ec2c;
        iVar1 = *(int *)(&DAT_80328f64 + iVar2);
        *(int *)(&DAT_80328f64 + iVar2) = iVar1 + 1;
        if (6 < iVar1 + 1) {
          param2 = __CARDVerify((int)(&DAT_80328f40 + iVar2));
          goto LAB_8003ec2c;
        }
        param2 = cardMountFn_8003e87c(chan);
      }
      if (-1 < param2) {
        return;
      }
      goto LAB_8003ec2c;
    }
    if (param2 != -5) goto LAB_8003ec2c;
  }
  cardMountFn_8003eecc(chan);
LAB_8003ec2c:
  pcVar3 = *(code **)(&DAT_80329010 + iVar2);
  *(undefined4 *)(&DAT_80329010 + iVar2) = 0;
  cardBiosFn_8003c3ec((int *)(&DAT_80328f40 + iVar2),param2);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(chan,param2);
    return;
  }
                    
  OSPanic("CARDMount.c",0x1ab,"Failed assertion callback");
}


/* Library Function - Single Match
    cardMountFn_8003ec88
   
   Library: KioskDefault 0 0 */

int CARDMountAsync(int param1,uint workArea,undefined4 param3,undefined *param4) { //8003EC88
  int iVar1;
  BOOL_ level;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  
  if ((workArea == 0) || ((workArea & 0x1f) != 0)) {
                    
    OSPanic("CARDMount.c",0x1cb,"Failed assertion workArea && ((u32) workArea % 32 == 0)");
  }
  if ((-1 < param1) && (param1 < 2)) {
    if ((param1 < 0) || (1 < param1)) {
      iVar1 = -0x80;
    }
    else {
      iVar1 = param1 * 0x108;
      piVar5 = (int *)(&DAT_80328f40 + iVar1);
      level = OSDisableInterrupts();
      if ((&DAT_80328f44)[param1 * 0x42] == -1) {
        OSRestoreInterrupts(level);
        iVar1 = -1;
      }
      else if ((*piVar5 == 0) && (uVar2 = osExiFn_8000b218(param1), (uVar2 & 8) != 0)) {
        OSRestoreInterrupts(level);
        iVar1 = -2;
      }
      else {
        (&DAT_80328f44)[param1 * 0x42] = 0xffffffff;
        *(uint *)(&DAT_80328fc0 + iVar1) = workArea;
        *(undefined4 *)(&DAT_80329004 + iVar1) = param3;
        pcVar4 = (code *)param4;
        if (param4 == (undefined *)0x0) {
          pcVar4 = nop_8003B08C;
        }
        *(code **)(&DAT_80329010 + iVar1) = pcVar4;
        *(undefined4 *)(&DAT_8032900c + iVar1) = 0;
        if ((*piVar5 == 0) && (iVar3 = osExiFn_8000a798(param1,cardBiosCbFn_8003b0d4), iVar3 == 0))
        {
          (&DAT_80328f44)[param1 * 0x42] = 0xfffffffd;
          OSRestoreInterrupts(level);
          iVar1 = -3;
        }
        else {
          *(undefined4 *)(&DAT_80328f64 + iVar1) = 0;
          *piVar5 = 1;
          osExiFn_8000a4fc(param1,0);
          *(undefined4 *)(&DAT_80328fc4 + iVar1) = 0;
          *(undefined4 *)(&DAT_80328fc8 + iVar1) = 0;
          OSRestoreInterrupts(level);
          *(code **)(&DAT_8032901c + iVar1) = __CARDMountCallback;
          iVar3 = osExiFn_8000af80(param1,0,-0x7ffc4c3c);
          if (iVar3 == 0) {
            iVar1 = 0;
          }
          else {
            *(undefined4 *)(&DAT_8032901c + iVar1) = 0;
            iVar1 = cardMountFn_8003e87c(param1);
          }
        }
      }
    }
    return iVar1;
  }
                    
  OSPanic("CARDMount.c",0x1cc,s_Failed_assertion_0_<__chan_&&_ch_802dfe74);
}


/* Library Function - Single Match
    cardMountFn_8003eecc
   
   Library: KioskDefault 0 0 */

void cardMountFn_8003eecc(int chan) { //8003EECC
  BOOL_ level;
  
  if ((-1 < chan) && (chan < 2)) {
    level = OSDisableInterrupts();
    if (*(int *)(&DAT_80328f40 + chan * 0x108) != 0) {
      osExiFn_8000a4fc(chan,0);
      EXIDetach(chan);
      *(int *)(&DAT_80328f40 + chan * 0x108) = 0;
      (&DAT_80328f44)[chan * 0x42] = 0xfffffffd;
      *(undefined4 *)(&DAT_80328f64 + chan * 0x108) = 0;
    }
    OSRestoreInterrupts(level);
    return;
  }
                    
  OSPanic("CARDMount.c",0x22f,s_Failed_assertion_0_<__chan_&&_ch_802dfe74);
}


/* Library Function - Single Match
    cardMountFn_8003ef78
   
   Library: KioskDefault 0 0 */

int cardMountFn_8003ef78(int chan) { //8003EF78
  int iVar1;
  int *piStack_c;
  
  if ((-1 < chan) && (chan < 2)) {
    iVar1 = __CARDGetControlBlock(chan,&piStack_c);
    if (-1 < iVar1) {
      cardMountFn_8003eecc(chan);
      iVar1 = 0;
    }
    return iVar1;
  }
                    
  OSPanic("CARDMount.c",0x252,s_Failed_assertion_0_<__chan_&&_ch_802dfe74);
}

