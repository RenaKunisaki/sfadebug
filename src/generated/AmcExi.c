
/* Library Function - Single Match
    AmcExiFn_8005a8e4
   
   Library: KioskDefault 0 0 */

BOOL AmcExiFn_8005a8e4(int param1,int len,uint type,undefined4 param4) { //8005A8E4
  BOOL_ level;
  BOOL result;
  uint uVar1;
  int iVar2;
  
  if ((*(uint *)(exiState_80396a08 + 0xc) & 4) == 0) {
                    
    OSPanic("AmcExi.c",0x8c,s_Failed_assertion_exi_>state___ST_802e4d5c);
  }
  if ((0 < len) && (len < 5)) {
    if (type < 3) {
      level = OSDisableInterrupts();
      if (((*(uint *)(exiState_80396a08 + 0xc) & 3) == 0) &&
         ((*(uint *)(exiState_80396a08 + 0xc) & 4) != 0)) {
        *(undefined4 *)(exiState_80396a08 + 4) = param4;
        if (*(int *)(exiState_80396a08 + 4) != 0) {
          FUN_8005ab1c(0,1);
          __OSUnmaskInterrupts(0x8000);
        }
        *(uint *)(exiState_80396a08 + 0xc) = *(uint *)(exiState_80396a08 + 0xc) | 2;
        if (type != 0) {
          uVar1 = 0;
          for (iVar2 = 0; iVar2 < len; iVar2 = iVar2 + 1) {
            uVar1 = uVar1 | (uint)*(byte *)(param1 + iVar2) << (3 - iVar2) * 8;
          }
          DAT_cc006838 = uVar1;
        }
        *(int *)(exiState_80396a08 + 0x14) = param1;
        iVar2 = len;
        if (type == 1) {
          iVar2 = 0;
        }
        *(int *)(exiState_80396a08 + 0x10) = iVar2;
        DAT_cc006834 = type << 2 | 1 | (len + -1) * 0x10;
        OSRestoreInterrupts(level);
        result = TRUE;
      }
      else {
        OSRestoreInterrupts(level);
        result = FALSE;
      }
      return result;
    }
                    
    OSPanic("AmcExi.c",0x8e,s_Failed_assertion_type_<_MAX_TYPE_802e4db8);
  }
                    
  OSPanic("AmcExi.c",0x8d,s_Failed_assertion_0_<_len_&&_len_<_802e4d8c);
}


/* Library Function - Single Match
    AmcExiFn_8005aa90
   
   Library: KioskDefault 0 0 */

void AmcExiFn_8005aa90(void) { //8005AA90
  uint uVar1;
  BOOL_ level;
  
  do {
    if ((*(uint *)(exiState_80396a08 + 0xc) & 4) == 0) goto LAB_8005aadc;
    uVar1 = DAT_cc006834;
  } while ((uVar1 & 1) != 0);
  level = OSDisableInterrupts();
  FUN_8005a858();
  OSRestoreInterrupts(level);
LAB_8005aadc:
  if ((*(uint *)(exiState_80396a08 + 0xc) & 3) != 0) {
                    
    OSPanic("AmcExi.c",0x10e,s_Failed_assertion___exi_>state___S_802e4eb0);
  }
  return;
}


/* Library Function - Single Match
    amcExiFreqFn_8005abe8
   
   Library: KioskDefault 0 0 */

bool amcExiFreqFn_8005abe8(uint param1) { //8005ABE8
  bool bVar1;
  dword dVar2;
  BOOL_ level;
  
  if (5 < param1) {
                    
    OSPanic("AmcExi.c",0x187,s_Failed_assertion_freq_<_MAX_FREQ_802e4edc);
  }
  if ((*(uint *)(exiState_80396a08 + 0xc) & 4) != 0) {
                    
    OSPanic("AmcExi.c",0x188,s_Failed_assertion___exi_>state___S_802e4f00);
  }
  level = OSDisableInterrupts();
  bVar1 = (*(uint *)(exiState_80396a08 + 0xc) & 4) == 0;
  if (bVar1) {
    *(uint *)(exiState_80396a08 + 0xc) = *(uint *)(exiState_80396a08 + 0xc) | 4;
    dVar2 = EXI_CHANNEL2;
    EXI_CHANNEL2 = dVar2 & 0x405 | param1 << 4 | 0x80;
    OSRestoreInterrupts(level);
  }
  else {
    OSRestoreInterrupts(level);
  }
  return bVar1;
}

