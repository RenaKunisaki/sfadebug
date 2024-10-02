
/* Library Function - Single Match
    diPrintFn_8017a37c
   
   Library: KioskDefault 0 0 */

void printRspStatus(void) { //8017A37C
  int iVar1;
  float local_50 [2];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  nop_800BFC0C();
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    (&rspTotalTime)[iVar1] = (&DAT_80390270)[iVar1] - (&DAT_80390260)[iVar1] & 0xffffff;
  }
  iVar1 = FUN_8017afc4();
  if ((iVar1 == 0) && (bEnableRspStatusDisplay != FALSE)) {
    dprintReset();
    dprintSetBgColor(0,0,0xff,0x80);
    uStack_14 = rspTotalTime;
    local_18 = 0x43300000;
    local_50[0] = ((float)((double)CONCAT44(0x43300000,rspTotalTime) - 4503599627370496.0) * 1000.0)
                  / 6.26e+07;
    diPrintf("Total time. = %2.1fmS",local_50);
    uStack_1c = rdpWorkingTime;
    local_20 = 0x43300000;
    uStack_24 = rspTotalTime;
    local_28 = 0x43300000;
    local_50[0] = ((float)((double)CONCAT44(0x43300000,rdpWorkingTime) - 4503599627370496.0) * 100.0
                  ) / (float)((double)CONCAT44(0x43300000,rspTotalTime) - 4503599627370496.0);
    diPrintf("RDP working.   = %2.0f%%",local_50);
    uStack_2c = rdpPipeNotStalledTime;
    local_30 = 0x43300000;
    uStack_34 = rspTotalTime;
    local_38 = 0x43300000;
    local_50[0] = ((float)((double)CONCAT44(0x43300000,rdpPipeNotStalledTime) - 4503599627370496.0)
                  * 100.0) / (float)((double)CONCAT44(0x43300000,rspTotalTime) - 4503599627370496.0)
    ;
    diPrintf("Pipe not stalled.  = %2.0f%%",local_50);
    uStack_3c = tmemLoadingTime;
    local_40 = 0x43300000;
    uStack_44 = rspTotalTime;
    local_48 = 0x43300000;
    local_50[0] = ((float)((double)CONCAT44(0x43300000,tmemLoadingTime) - 4503599627370496.0) *
                  100.0) / (float)((double)CONCAT44(0x43300000,rspTotalTime) - 4503599627370496.0);
    diPrintf("TMEM loading. = %2.0f%%",local_50);
  }
  if (DAT_80399828 != 0) {
    retM1_afterLoadAsset_ret0xFFFF();
    retM1_800BFBFC_ret0xFFFF();
  }
  return;
}

