
/* Library Function - Single Match
    synthDataInsertSample
   
   Library: KioskDefault 0 0 */

undefined4 synthDataInsertSample(short param1) { //80048A5C
  uint uVar1;
  short *psVar2;
  short *local_14 [2];
  
  for (uVar1 = 0; psVar2 = (short *)0x0, uVar1 < DAT_803985a8; uVar1 = uVar1 + 1) {
    for (psVar2 = (short *)(&PTR_DAT_80338ca8)[uVar1 * 3]; *psVar2 != -1; psVar2 = psVar2 + 0x10) {
      if ((*psVar2 == param1) && (psVar2[1] != -1)) goto LAB_80048ad8;
    }
  }
LAB_80048ad8:
  if (psVar2 != (short *)0x0) {
    if (psVar2[1] == 0) {
      *(undefined **)(psVar2 + 4) = (&PTR_patchStart_80338cac)[uVar1 * 3] + *(int *)(psVar2 + 2);
      local_14[0] = psVar2 + 6;
      aramUploadFn_80058810((int *)local_14,(void **)(psVar2 + 4));
    }
    psVar2[1] = psVar2[1] + 1;
    return 1;
  }
                    
  OSPanic("synthdata.c",0x207,"Sample ID to be inserted could not be found in any sample directory.m");
}

