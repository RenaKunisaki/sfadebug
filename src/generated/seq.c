
/* Library Function - Single Match
    sequencerFn_80042434
   
   Library: KioskDefault 0 0 */

void sequencerFn_80042434(uint param1,undefined2 param2) { //80042434
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = seqGetVolumeGroup(param1);
  if (uVar2 != 0xffffffff) {
    if ((uVar2 & 0x80000000) == 0) {
      for (uVar3 = 0; uVar3 < 0x10; uVar3 = uVar3 + 1) {
        (&DAT_8032ba78)[uVar3 * 0x16 + uVar2 * 0xbd2] = param2;
      }
    }
    else {
      iVar1 = (uVar2 & 0x7fffffff) * 0x17a4;
      (&DAT_8032b446)[iVar1] = (&DAT_8032b446)[iVar1] | 0x20;
      *(undefined2 *)(&DAT_8032b444 + (uVar2 & 0x7fffffff) * 0x17a4) = param2;
    }
    return;
  }
                    
  OSPanic("seq.c",999,"Sequencer ID is not valid.");
}


/* Library Function - Single Match
    sequencerFn_800424f0
   
   Library: KioskDefault 0 0 */

void sequencerFn_800424f0(uint param1) { //800424F0
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined **ppuVar4;
  
  uVar2 = seqGetVolumeGroup(param1);
  if (uVar2 == 0xffffffff) {
                    
    OSPanic("seq.c",0x400,"Sequencer ID is not valid.");
  }
  if ((uVar2 & 0x80000000) == 0) {
    ppuVar4 = &PTR_PTR_8032a570 + uVar2 * 0x5e9;
    if ((&DAT_8032a578)[uVar2 * 0x17a4] == '\x02') {
      if ((&DAT_8032a574)[uVar2 * 0x5e9] == 0) {
        seqVolGrpVar_80398558 = *ppuVar4;
      }
      else {
        *(undefined **)(&DAT_8032a574)[uVar2 * 0x5e9] = *ppuVar4;
      }
      if (*ppuVar4 != (undefined *)0x0) {
        *(undefined4 *)(*ppuVar4 + 4) = (&DAT_8032a574)[uVar2 * 0x5e9];
      }
      puVar1 = seqVolumeGroups;
      *ppuVar4 = seqVolumeGroups;
      if (puVar1 != (undefined *)0x0) {
        *(undefined ***)(seqVolumeGroups + 4) = ppuVar4;
      }
      (&DAT_8032a574)[uVar2 * 0x5e9] = 0;
      seqVolumeGroups = (undefined *)ppuVar4;
      (&DAT_8032a578)[uVar2 * 0x17a4] = 1;
    }
  }
  else {
    iVar3 = (uVar2 & 0x7fffffff) * 0x17a4;
    (&DAT_8032b446)[iVar3] = (&DAT_8032b446)[iVar3] & 0xf7;
  }
  return;
}


/* Library Function - Single Match
    sequencerFn_8004269c
   
   Library: KioskDefault 0 0 */

void sequencerFn_8004269c(uint param1,ushort param2,float param3,byte param4) { //8004269C
  byte bVar1;
  uint uVar2;
  undefined uVar3;
  uint uVar4;
  
  uVar2 = seqGetVolumeGroup((uint)param3);
  if (uVar2 != 0xffffffff) {
    if ((uVar2 & 0x80000000) == 0) {
      audioSetChannelVolume(param1,param2,(&DAT_8032b41c)[uVar2 * 0x17a4],param4,param3);
      for (uVar4 = 0; uVar4 < 0x40; uVar4 = uVar4 + 1) {
        if ((&DAT_8032a894)[uVar2 * 0x17a4 + uVar4] != (&DAT_8032b41c)[uVar2 * 0x17a4]) {
          audioSetChannelVolume(param1,param2,(&DAT_8032a894)[uVar2 * 0x17a4 + uVar4],0,-NAN);
        }
      }
    }
    else {
      uVar2 = uVar2 & 0x7fffffff;
      bVar1 = param4 & 0xf;
      uVar3 = (undefined)param1;
      if (bVar1 == 2) {
        (&DAT_8032b446)[uVar2 * 0x17a4] = (&DAT_8032b446)[uVar2 * 0x17a4] | 8;
        (&DAT_8032b438)[uVar2 * 0x17a4] = uVar3;
      }
      else if (bVar1 < 2) {
        if ((param4 & 0xf) == 0) {
          (&DAT_8032b438)[uVar2 * 0x17a4] = uVar3;
        }
        else {
          if (false) goto LAB_80042804;
          *(undefined4 *)(&DAT_8032b448 + uVar2 * 0x17a4) = 0;
        }
      }
      else {
        if (3 < bVar1) {
LAB_80042804:
                    
          OSPanic("seq.c",0x46e,"Illegal sequencer fade mode detected.");
        }
        (&DAT_8032b446)[uVar2 * 0x17a4] = (&DAT_8032b446)[uVar2 * 0x17a4] | 0x80;
        (&DAT_8032b438)[uVar2 * 0x17a4] = uVar3;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    sequencerFn_80042830
   
   Library: KioskDefault 0 0 */

void sequencerFn_80042830(float *param1,float *param2,char param3) { //80042830
  float fVar1;
  ushort param2_00;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  uint local_3c;
  float local_38;
  float local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined local_2c;
  undefined local_24;
  
  uVar2 = seqGetVolumeGroup((uint)*param1);
  if (uVar2 == 0xffffffff) {
                    
    OSPanic("seq.c",0x47f,"Sequencer ID is not valid.");
  }
  if ((*(byte *)((int)param1 + 0x26) & 4) == 0) {
    if (param3 == '\0') {
      if ((*(byte *)((int)param1 + 0x26) & 1) == 0) {
        if ((*(byte *)((int)param1 + 0x26) & 0x40) == 0) {
          sequencerFn_80046e5c(0,*(ushort *)(param1 + 1),*param1,1);
        }
        else {
          sequencerFn_80046e5c(0,*(ushort *)(param1 + 1),*param1,3);
        }
      }
      else {
        sequencerFn_80046e5c(0,*(ushort *)(param1 + 1),*param1,2);
      }
    }
    else {
      if (*(ushort *)(param1 + 1) < 5) {
        param2_00 = 5;
      }
      else {
        param2_00 = *(ushort *)(param1 + 1);
      }
      if ((*(byte *)((int)param1 + 0x26) & 1) == 0) {
        if ((*(byte *)((int)param1 + 0x26) & 0x40) == 0) {
          sequencerFn_8004269c(0,param2_00,*param1,1);
        }
        else {
          sequencerFn_8004269c(0,param2_00,*param1,3);
        }
      }
      else {
        sequencerFn_8004269c(0,param2_00,*param1,2);
      }
    }
    if (param2 != (float *)0x0) {
      if ((*(byte *)((int)param1 + 0x26) & 2) == 0) {
        local_3c = 4;
        if ((*(byte *)((int)param1 + 0x26) & 8) != 0) {
          local_3c = 0x14;
        }
        if ((*(byte *)((int)param1 + 0x26) & 0x20) != 0) {
          local_3c = local_3c | 2;
          local_30 = *(undefined2 *)(param1 + 9);
        }
        if ((*(byte *)((int)param1 + 0x26) & 0x10) != 0) {
          local_3c = local_3c | 1;
          local_38 = param1[7];
          local_34 = param1[8];
        }
        local_2e = *(undefined2 *)(param1 + 3);
        local_2c = *(undefined *)(param1 + 6);
        local_24 = 0;
        if (param3 == '\0') {
          fVar1 = (float)FUN_800502f4(*(ushort *)(param1 + 5),*(ushort *)((int)param1 + 0x16),
                                      (int *)param1[4],&local_3c,*(undefined *)((int)param1 + 0x19))
          ;
          *param2 = fVar1;
          if ((fVar1 != -NAN) && ((*(byte *)((int)param1 + 0x26) & 0x80) != 0)) {
            sequencerFn_80046df4((uint)*param2,0,0);
          }
        }
        else {
          fVar1 = (float)musicFn_80050144(*(ushort *)(param1 + 5),*(ushort *)((int)param1 + 0x16),
                                          (int *)param1[4],&local_3c,'\x01',
                                          *(undefined *)((int)param1 + 0x19));
          *param2 = fVar1;
          if ((fVar1 != -NAN) && ((*(byte *)((int)param1 + 0x26) & 0x80) != 0)) {
            sequencerFn_800425f8((uint)*param2,0,0);
          }
        }
      }
      else {
        uVar2 = seqGetVolumeGroup((uint)param1[2]);
        if (uVar2 == 0xffffffff) {
          *param2 = -NAN;
        }
        else {
          if (param3 == '\0') {
            sequencerFn_80046d9c((uint)param1[2]);
            sequencerFn_80046e5c(*(byte *)(param1 + 6),*(ushort *)(param1 + 3),param1[2],0);
            if ((*(byte *)((int)param1 + 0x26) & 0x10) != 0) {
              sequencerFn_80046df4((uint)param1[2],param1[7],param1[8]);
            }
            if ((*(byte *)((int)param1 + 0x26) & 0x20) != 0) {
              sequencerFn_80046d3c((uint)param1[2],*(undefined2 *)(param1 + 9));
            }
          }
          else {
            sequencerFn_800424f0((uint)param1[2]);
            sequencerFn_8004269c((uint)*(byte *)(param1 + 6),*(ushort *)(param1 + 3),param1[2],0);
            if ((*(byte *)((int)param1 + 0x26) & 0x10) != 0) {
              sequencerFn_800425f8((uint)param1[2],param1[7],param1[8]);
            }
            if ((*(byte *)((int)param1 + 0x26) & 0x20) != 0) {
              sequencerFn_80042434((uint)param1[2],*(undefined2 *)(param1 + 9));
            }
          }
          *param2 = param1[2];
        }
      }
    }
  }
  else {
    iVar5 = 5;
    pfVar3 = param1 + -2;
    pfVar4 = (float *)(uVar2 * 0x17a4 + -0x7fcd4be8);
    do {
      fVar1 = pfVar3[3];
      pfVar4[2] = pfVar3[2];
      pfVar4[3] = fVar1;
      iVar5 = iVar5 + -1;
      pfVar3 = pfVar3 + 2;
      pfVar4 = pfVar4 + 2;
    } while (iVar5 != 0);
    (&DAT_8032b44c)[uVar2 * 0x17a4] = 1;
    *(float **)(&DAT_8032b448 + uVar2 * 0x17a4) = param2;
    (&DAT_8032b446)[uVar2 * 0x17a4] = (&DAT_8032b446)[uVar2 * 0x17a4] & 0xfb;
    *param2 = (float)((uint)*param1 | 0x80000000);
  }
  return;
}

