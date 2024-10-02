
undefined4 sDataFn_80048154(short param1) { //80048154
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  sndBegin();
  for (uVar4 = 0;
      ((int)uVar4 < (int)(uint)DAT_803985ac && (param1 != *(short *)(&DAT_8033cd0c + uVar4 * 2)));
      uVar4 = uVar4 + 1) {
  }
  if ((uVar4 == DAT_803985ac) ||
     (sVar1 = *(short *)((int)&DAT_8033cd0c + uVar4 * 8 + 2) + -1,
     *(short *)((int)&DAT_8033cd0c + uVar4 * 8 + 2) = sVar1, sVar1 != 0)) {
    sndEnd();
    uVar2 = 0;
  }
  else {
    while (uVar3 = uVar4 + 1, (int)uVar3 < (int)(uint)DAT_803985ac) {
      uVar2 = (&DAT_8033cd0c)[uVar3 * 2];
      (&PTR_DAT_8033cd08)[uVar4 * 2] = (&PTR_DAT_8033cd08)[uVar3 * 2];
      (&DAT_8033cd0c)[uVar4 * 2] = uVar2;
      uVar4 = uVar3;
    }
    DAT_803985ac = DAT_803985ac - 1;
    sndEnd();
    uVar2 = 1;
  }
  return uVar2;
}


undefined4 sDataFn_800483c4(short param1) { //800483C4
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  sndBegin();
  for (uVar4 = 0;
      ((int)uVar4 < (int)(uint)DAT_803985ae && (param1 != *(short *)(&DAT_8033d50c + uVar4 * 3)));
      uVar4 = uVar4 + 1) {
  }
  if ((uVar4 == DAT_803985ae) ||
     (sVar1 = *(short *)(&DAT_8033d510 + uVar4 * 3),
     *(short *)(&DAT_8033d510 + uVar4 * 3) = sVar1 + -1, (short)(sVar1 + -1) != 0)) {
    sndEnd();
    uVar2 = 0;
  }
  else {
    while (uVar3 = uVar4 + 1, (int)uVar3 < (int)(uint)DAT_803985ae) {
      uVar2 = (&DAT_8033d50c)[uVar3 * 3];
      (&PTR_DAT_8033d508)[uVar4 * 3] = (&PTR_DAT_8033d508)[uVar3 * 3];
      (&DAT_8033d50c)[uVar4 * 3] = uVar2;
      (&DAT_8033d510)[uVar4 * 3] = (&DAT_8033d510)[uVar3 * 3];
      uVar4 = uVar3;
    }
    DAT_803985ae = DAT_803985ae - 1;
    sndEnd();
    uVar2 = 1;
  }
  return uVar2;
}


undefined4 sDataFn_80048620(short param1) { //80048620
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  sndBegin();
  for (uVar4 = 0;
      ((int)uVar4 < (int)(uint)DAT_803985aa && (param1 != *(short *)(&DAT_80338d0c + uVar4 * 2)));
      uVar4 = uVar4 + 1) {
  }
  if ((uVar4 == DAT_803985aa) ||
     (sVar1 = *(short *)((int)&DAT_80338d0c + uVar4 * 8 + 2) + -1,
     *(short *)((int)&DAT_80338d0c + uVar4 * 8 + 2) = sVar1, sVar1 != 0)) {
    sndEnd();
    uVar2 = 0;
  }
  else {
    while (uVar3 = uVar4 + 1, (int)uVar3 < (int)(uint)DAT_803985aa) {
      uVar2 = (&DAT_80338d0c)[uVar3 * 2];
      (&PTR_DAT_80338d08)[uVar4 * 2] = (&PTR_DAT_80338d08)[uVar3 * 2];
      (&DAT_80338d0c)[uVar4 * 2] = uVar2;
      uVar4 = uVar3;
    }
    DAT_803985aa = DAT_803985aa - 1;
    sndEnd();
    uVar2 = 1;
  }
  return uVar2;
}


undefined4 sDataFn_80048b60(short param1) { //80048B60
  bool bVar1;
  bool bVar2;
  uint uVar3;
  short *psVar4;
  
  bVar1 = false;
  uVar3 = 0;
  while( true ) {
    if (DAT_803985a8 <= uVar3) {
      return 0;
    }
    bVar2 = false;
    for (psVar4 = (short *)(&PTR_DAT_80338ca8)[uVar3 * 3]; *psVar4 != -1; psVar4 = psVar4 + 0x10) {
      if ((*psVar4 == param1) && (psVar4[1] != -1)) {
        psVar4[1] = psVar4[1] + -1;
        if (psVar4[1] == 0) {
          FUN_80058874((int)(psVar4 + 6),*(void **)(psVar4 + 4));
        }
        bVar1 = true;
      }
      if (psVar4[1] != 0) {
        bVar2 = true;
      }
    }
    if (bVar1) break;
    uVar3 = uVar3 + 1;
  }
  if (!bVar2) {
    FUN_800488a0((short *)(&PTR_DAT_80338ca8)[uVar3 * 3]);
  }
  return 1;
}


undefined4 sDataFn_80048c58(short param1,int param2,ushort param3) { //80048C58
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  for (uVar2 = 0; ((int)uVar2 < (int)(uint)DAT_803985b2 && (param1 != (&DAT_80342908)[uVar2 * 4]));
      uVar2 = uVar2 + 1) {
  }
  if ((uVar2 == DAT_803985b2) && (DAT_803985b2 < 0x80)) {
    sndBegin();
    (&DAT_80342908)[(uint)DAT_803985b2 * 4] = param1;
    (&DAT_8034290a)[(uint)DAT_803985b2 * 4] = param3;
    (&DAT_8034290c)[(uint)DAT_803985b2 * 2] = param2;
    for (iVar3 = 0; iVar3 < (int)(uint)param3; iVar3 = iVar3 + 1) {
      *(undefined *)(param2 + 9) = 0x1f;
      param2 = param2 + 10;
    }
    DAT_803985b2 = DAT_803985b2 + 1;
    sndEnd();
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


undefined4 sDataFn_80048f48(uint param1) { //80048F48
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  sndBegin();
  uVar5 = param1 >> 6 & 0x3ff;
  if ((&DAT_8033e108)[uVar5 * 2] != 0) {
    uVar4 = (uint)(ushort)(&DAT_8033e10a)[uVar5 * 2];
    iVar6 = 0;
    while ((iVar6 < (int)(uint)(ushort)(&DAT_8033e108)[uVar5 * 2] &&
           ((param1 & 0xffff) != (uint)*(ushort *)(&DAT_8033e90c + (uVar4 + iVar6) * 8)))) {
      iVar6 = iVar6 + 1;
    }
    if ((iVar6 < (int)(uint)(ushort)(&DAT_8033e108)[uVar5 * 2]) &&
       (iVar2 = (uVar4 + iVar6) * 8, sVar1 = *(short *)(&DAT_8033e90e + iVar2),
       *(short *)(&DAT_8033e90e + iVar2) = sVar1 + -1, (short)(sVar1 + -1) == 0)) {
      for (iVar6 = uVar4 + iVar6 + 1; iVar6 < (int)(uint)DAT_803985b0; iVar6 = iVar6 + 1) {
        uVar3 = *(undefined4 *)(&DAT_8033e90c + iVar6 * 8);
        (&PTR_DAT_8033e908)[(iVar6 + -1) * 2] = (&PTR_DAT_8033e908)[iVar6 * 2];
        *(undefined4 *)(&DAT_8033e90c + (iVar6 + -1) * 8) = uVar3;
      }
      for (iVar6 = 0; iVar6 < 0x200; iVar6 = iVar6 + 1) {
        if (uVar4 < (ushort)(&DAT_8033e10a)[iVar6 * 2]) {
          (&DAT_8033e10a)[iVar6 * 2] = (&DAT_8033e10a)[iVar6 * 2] + -1;
        }
      }
      (&DAT_8033e108)[uVar5 * 2] = (&DAT_8033e108)[uVar5 * 2] + -1;
      DAT_803985b0 = DAT_803985b0 - 1;
    }
  }
  sndEnd();
  return 0;
}


void sDataFn_8004fbec(uint param1,int *param2,byte param3,int param4) { //8004FBEC
  int iVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param1;
  if (param3 == 2) {
    uVar2 = uVar2 | 0x4000;
    if (param4 == 0) {
      iVar1 = FUN_8004fb74(uVar2,(int)param2);
      if (iVar1 != 0) {
        FUN_80047fe8(uVar2,(undefined *)(iVar1 + 8));
      }
    }
    else {
      sDataFn_80048154(uVar2);
    }
  }
  else if (param3 < 2) {
    if (param3 == 0) {
      if (param4 == 0) {
        iVar1 = FUN_8004fafc(uVar2,param2);
        if (iVar1 != 0) {
          FUN_80048d5c(param1,(undefined *)(iVar1 + 8));
        }
      }
      else {
        sDataFn_80048f48(param1);
      }
    }
    else if (true) {
      if (param4 == 0) {
        synthDataInsertSample(uVar2);
      }
      else {
        sDataFn_80048b60(uVar2);
      }
    }
  }
  else if (param3 == 4) {
    if (param4 == 0) {
      iVar1 = FUN_8004fb38(uVar2,(int)param2);
      if (iVar1 != 0) {
        FUN_800484b4(uVar2,(undefined *)(iVar1 + 8));
      }
    }
    else {
      sDataFn_80048620(uVar2);
    }
  }
  else if (param3 < 4) {
    uVar2 = uVar2 | 0x8000;
    if (param4 == 0) {
      iVar1 = FUN_8004fbb0(uVar2,(int)param2);
      if (iVar1 != 0) {
        FUN_8004823c(uVar2,(undefined *)(iVar1 + 0xc),(short)*(undefined4 *)(iVar1 + 8));
      }
    }
    else {
      sDataFn_800483c4(uVar2);
    }
  }
  return;
}


void sDataFn_8004fd5c(ushort *param1,int *param2,byte param3,int param4) { //8004FD5C
  ushort uVar1;
  uint param1_00;
  
  while( true ) {
    if (*param1 == 0xffff) break;
    if ((*param1 & 0x8000) == 0) {
      uVar1 = *param1;
      param1 = param1 + 1;
      sDataFn_8004fbec((uint)uVar1,param2,param3,param4);
    }
    else {
      for (param1_00 = *param1 & 0x3fff; (param1_00 & 0xffff) <= (uint)param1[1];
          param1_00 = param1_00 + 1) {
        sDataFn_8004fbec(param1_00,param2,param3,param4);
      }
      param1 = param1 + 2;
    }
  }
  return;
}


void sDataFn_8004fee0(ushort *param1,undefined4 param_2,int *param3) { //8004FEE0
  undefined *puVar1;
  int iVar2;
  
  puVar1 = (undefined *)nop_80058704();
  iVar2 = FUN_80048708((short *)param3,puVar1);
  if (iVar2 != 0) {
    sDataFn_8004fd5c(param1,param3,1,0);
  }
  return;
}


/* Library Function - Single Match
    sndLoadProject
   
   Library: KioskDefault 0 0 */

BOOL sndLoadProject(int *projData,ushort groupId,int samData,int *samDir,int *poolData) { //8004FF80
  int *piVar1;
  
  if (projData == (int *)0x0) {
                    
    OSPanic("s_data.c",0x16f,"Project data pointer is NULL");
  }
  if (samData == 0) {
                    
    OSPanic("s_data.c",0x170,"Sample data pointer is NULL");
  }
  if (samDir == (int *)0x0) {
                    
    OSPanic("s_data.c",0x171,"Sample directory pointer is NULL");
  }
  if (poolData != (int *)0x0) {
    if ((bSndIsInstalled) && (piVar1 = projData, DAT_80398628 < 0x80)) {
      for (; *piVar1 != -1; piVar1 = (int *)((int)projData + *piVar1)) {
        if (*(ushort *)(piVar1 + 1) == groupId) {
          (&songGroups_80343d20)[DAT_80398628 * 2] = (undefined *)piVar1;
          (&PTR_DAT_80343d24)[DAT_80398628 * 2] = (undefined *)projData;
          sDataFn_8004fee0((ushort *)((int)projData + piVar1[3]),samData,samDir);
          FUN_8004fe00((ushort *)((int)projData + piVar1[2]),poolData);
          FUN_8004fe38((ushort *)((int)projData + piVar1[4]),poolData);
          FUN_8004fe70((ushort *)((int)projData + piVar1[5]),poolData);
          FUN_8004fea8((ushort *)((int)projData + piVar1[6]),poolData);
          if (*(short *)((int)piVar1 + 6) == 1) {
            FUN_8004ff44(groupId,(ushort *)((int)projData + piVar1[7]));
          }
          IFFifoAlloc();
          DAT_80398628 = DAT_80398628 + 1;
          return TRUE;
        }
      }
    }
    OSReport("Group ID=%d could not be pushed.",groupId);
    return FALSE;
  }
                    
  OSPanic("s_data.c",0x172,"Pool data pointer is NULL");
}


/* Library Function - Single Match
    musicFn_80050144
   
   Library: KioskDefault 0 0 */

uint musicFn_80050144(ushort groupId,ushort songId,int *param3,uint *param4,char param5,
                     undefined param6) { //80050144
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  ushort *puVar5;
  int iVar6;
  
  if (!bSndIsInstalled) {
                    
    OSPanic("s_data.c",0x1cf,"Sound system is not initialized.");
  }
  iVar6 = 0;
  while( true ) {
    if (DAT_80398628 <= iVar6) {
      OSReport("Group ID=%d is not on soundstack.",groupId);
      return 0xffffffff;
    }
    if (groupId == *(ushort *)((&songGroups_80343d20)[iVar6 * 2] + 4)) break;
    iVar6 = iVar6 + 1;
  }
  if (*(short *)((&songGroups_80343d20)[iVar6 * 2] + 6) != 0) {
    OSReport("Group ID=%d is no songgroup.",groupId);
    return 0xffffffff;
  }
  puVar4 = (&songGroups_80343d20)[iVar6 * 2];
  puVar3 = (&PTR_DAT_80343d24)[iVar6 * 2];
  iVar6 = *(int *)(puVar4 + 0x1c);
  iVar1 = *(int *)(puVar4 + 0x20);
  puVar5 = (ushort *)(puVar3 + *(int *)(puVar4 + 0x24));
  while( true ) {
    if (*puVar5 == 0xffff) {
      OSReport("Song ID=%d is not in group ID=%d.",songId,groupId);
      return 0xffffffff;
    }
    if (*puVar5 == songId) break;
    puVar5 = puVar5 + 0x2a;
  }
  if (param5 != '\0') {
    uVar2 = FUN_80041a48(puVar3 + iVar6,puVar3 + iVar1,(int)puVar5,param3,param4,param6,groupId);
    return uVar2;
  }
  sndBegin();
  uVar2 = FUN_80041a48(puVar3 + iVar6,puVar3 + iVar1,(int)puVar5,param3,param4,param6,groupId);
  sndEnd();
  return uVar2;
}


void aramUploadFn_80058810(int *param1,void **src) { //80058810
  int size;
  void *pvVar1;
  
  size = FUN_800587c8(*(uint *)(*param1 + 4) & 0xffffff,
                      (byte)((uint)*(undefined4 *)(*param1 + 4) >> 0x18));
  pvVar1 = (void *)aramUpload(*src,size);
  *src = pvVar1;
  return;
}

