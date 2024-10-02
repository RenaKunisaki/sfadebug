
/* Library Function - Single Match
    cardFormatFn_8003eff8
   
   Library: KioskDefault 0 0 */

void FormatCallback(int param1,int param2) { //8003EFF8
  int iVar1;
  code *pcVar2;
  
  iVar1 = param1 * 0x108;
  if (-1 < param2) {
    *(int *)(&DAT_80328f64 + iVar1) = *(int *)(&DAT_80328f64 + iVar1) + 1;
    if (*(int *)(&DAT_80328f64 + iVar1) < 5) {
      param2 = cardBiosFn_8003c130(param1,*(int *)(&DAT_80328f4c + iVar1) *
                                          *(int *)(&DAT_80328f64 + iVar1),-0x7ffc1008);
    }
    else {
      if (9 < *(int *)(&DAT_80328f64 + iVar1)) {
        *(int *)(&DAT_80328fc4 + iVar1) = *(int *)(&DAT_80328fc0 + iVar1) + 0x2000;
        memcpy(*(void **)(&DAT_80328fc4 + iVar1),(void *)(*(int *)(&DAT_80328fc0 + iVar1) + 0x4000),
               0x2000);
        *(int *)(&DAT_80328fc8 + iVar1) = *(int *)(&DAT_80328fc0 + iVar1) + 0x6000;
        memcpy(*(void **)(&DAT_80328fc8 + iVar1),(void *)(*(int *)(&DAT_80328fc0 + iVar1) + 0x8000),
               0x2000);
        goto LAB_8003f0fc;
      }
      param2 = cardRdWrFn_8003d30c(param1,*(int *)(&DAT_80328f4c + iVar1) *
                                          (*(int *)(&DAT_80328f64 + iVar1) + -5),0x2000,
                                   *(int *)(&DAT_80328fc0 + iVar1) +
                                   (*(int *)(&DAT_80328f64 + iVar1) + -5) * 0x2000,FormatCallback);
    }
    if (-1 < param2) {
      return;
    }
  }
LAB_8003f0fc:
  pcVar2 = *(code **)(&DAT_80329010 + iVar1);
  *(undefined4 *)(&DAT_80329010 + iVar1) = 0;
  cardBiosFn_8003c3ec((int *)(&DAT_80328f40 + iVar1),param2);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param1,param2);
    return;
  }
                    
  OSPanic("CARDFormat.c",0x79,"Failed assertion callback");
}


/* Library Function - Single Match
    cardFormatFn_8003f160
   
   Library: KioskDefault 0 0 */

int cardFormatFn_8003f160(int param1,undefined *param2) { //8003F160
  ulonglong uVar1;
  word wVar2;
  int iVar3;
  ushort uVar6;
  SramState *pSVar4;
  uint uVar5;
  code *pcVar7;
  short *param3;
  ushort *puVar8;
  short sVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 uVar12;
  int *local_48 [3];
  
  if ((-1 < param1) && (param1 < 2)) {
    iVar3 = __CARDGetControlBlock(param1,local_48);
    if (-1 < iVar3) {
      puVar8 = (ushort *)local_48[0][0x20];
      memset_(puVar8,0xff,0x2000);
      wVar2 = vi_VISEL;
      uVar6 = cardCheckRegion();
      puVar8[0x12] = uVar6;
      pSVar4 = osOpenSram();
      *(u32 *)(puVar8 + 10) = pSVar4->rtcOffset;
      *(uint *)(puVar8 + 0xc) = (uint)pSVar4->language;
      osCloseSram(0);
      uVar10 = OSGetTime();
      iVar3 = FUN_8000c390();
      sVar9 = 0;
      uVar1 = uVar10;
      while( true ) {
        if (0xb < sVar9) break;
        uVar5 = (int)uVar1 * 0x41c64e6d;
        lVar11 = __shr2i((int)(uVar1 >> 0x20) * 0x41c64e6d +
                         (int)((uVar1 & 0xffffffff) * 0x41c64e6d >> 0x20) +
                         (uint)(0xffffcfc6 < uVar5),(uint)(&DAT_00003039 + uVar5),0x10);
        *(char *)((int)puVar8 + (int)sVar9) =
             (char)lVar11 + *(char *)(iVar3 + param1 * 0xc + (int)sVar9);
        lVar11 = lVar11 * 0x41c64e6d + 0x3039;
        uVar12 = __shr2i((int)((ulonglong)lVar11 >> 0x20),(uint)lVar11,0x10);
        uVar1 = (ulonglong)((uint)uVar12 & 0x7fff);
        sVar9 = sVar9 + 1;
      }
      FUN_8000c4ec(0);
      *(uint *)(puVar8 + 0xe) = (uint)wVar2;
      *(ulonglong *)(puVar8 + 6) = uVar10;
      puVar8[0x10] = 0;
      puVar8[0x11] = *(ushort *)(local_48[0] + 2);
      cardCheckFn_8003dc7c(puVar8,0x1fc,(short *)(puVar8 + 0xfe),(short *)(puVar8 + 0xff));
      for (uVar6 = 0; (short)uVar6 < 2; uVar6 = uVar6 + 1) {
        puVar8 = (ushort *)(local_48[0][0x20] + ((short)uVar6 + 1) * 0x2000);
        memset_(puVar8,0xff,0x2000);
        puVar8[0xffd] = uVar6;
        cardCheckFn_8003dc7c(puVar8,0x1ffc,(short *)(puVar8 + 0xffe),(short *)(puVar8 + 0xfff));
      }
      for (sVar9 = 0; sVar9 < 2; sVar9 = sVar9 + 1) {
        param3 = (short *)(local_48[0][0x20] + (sVar9 + 3) * 0x2000);
        memset_(param3,0,0x2000);
        param3[2] = sVar9;
        param3[3] = *(short *)(local_48[0] + 4) + -5;
        param3[4] = 4;
        cardCheckFn_8003dc7c((ushort *)(param3 + 2),0x1ffc,param3,param3 + 1);
      }
      pcVar7 = (code *)param2;
      if (param2 == (undefined *)0x0) {
        pcVar7 = nop_8003B08C;
      }
      local_48[0][0x34] = (int)pcVar7;
      DCStoreRange((void *)local_48[0][0x20],0xa000);
      local_48[0][9] = 0;
      iVar3 = cardBiosFn_8003c130(param1,local_48[0][3] * local_48[0][9],-0x7ffc1008);
      if (iVar3 < 0) {
        cardBiosFn_8003c3ec(local_48[0],iVar3);
      }
    }
    return iVar3;
  }
                    
  OSPanic("CARDFormat.c",0x9a,s_Failed_assertion_0_<__chan_&&_ch_802dff1c);
}

