
/* Library Function - Single Match
    perfFn_80037e58
   
   Library: KioskDefault 0 0 */

void perfFn_80037e58(uint param1) { //80037E58
  u32 uVar1;
  uint uVar2;
  
  if ((((param1 & 0xffff) < 0xe000) || ((param1 >> 8 & 0xf) != (uint)perfTokenVar_803984f0)) ||
     (PERFCurrSample == 0)) {
    if (DAT_803984fc != (code *)0x0) {
      (*DAT_803984fc)(param1);
    }
  }
  else if ((param1 & 0xffff) < 0xf000) {
    if (&DAT_0000fffe < CurrToken) {
      if (CurrAutoSample < 0) {
                    
        OSPanic("perf.c",0x180,s_Failed_assertion_CurrAutoSample_>_802df598);
      }
      FUN_80038a3c();
    }
    else {
      if (-1 < CurrAutoSample) {
                    
        OSPanic("perf.c",0x176,s_Failed_assertion_CurrAutoSample_<_802df614);
      }
      uVar2 = (uint)CurrToken & 0xff;
      uVar1 = get_PMC4();
      *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x10) = uVar1;
      uVar1 = get_PMC3();
      *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x24) = uVar1;
      uVar1 = get_PMC1();
      *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x34) = uVar1;
      FUN_80037c90(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0,1);
    }
    uVar2 = param1 & 0xff;
    uVar1 = get_PMC3();
    *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x20) = uVar1;
    uVar1 = get_PMC1();
    *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x30) = uVar1;
    uVar1 = get_PMC4();
    *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x1c) = uVar1;
    *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0xc) = uVar1;
    FUN_80037c90(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0,0);
    CurrToken = (undefined *)(param1 & 0xffff);
  }
  else if (CurrToken == &DAT_0000ffff) {
    if (CurrAutoSample < 0) {
                    
      OSPanic("perf.c",0x14b,s_Failed_assertion_CurrAutoSample_>_802df598);
    }
    FUN_80038a3c();
    FUN_80038920();
  }
  else {
    uVar2 = param1 & 0xff;
    if (((uint)CurrToken & 0xff) != uVar2) {
      uVar2 = (uint)CurrToken & 0xff;
    }
    if (PERFCurrSample <= (int)uVar2) {
                    
      OSPanic("perf.c",0x15b,s_Failed_assertion_sample_<_PERFCu_802df5c0);
    }
    uVar1 = get_PMC4();
    *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x10) = uVar1;
    uVar1 = get_PMC3();
    *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x24) = uVar1;
    uVar1 = get_PMC1();
    *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x34) = uVar1;
    FUN_80037c90(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0,1);
    if (-1 < CurrAutoSample) {
      if (CurrToken != &DAT_0000ffff) {
                    
        OSPanic("perf.c",0x167,"Failed assertion CurrToken == TOKEN_MAX");
      }
      FUN_80038a3c();
    }
    CurrToken = &DAT_0000ffff;
    FUN_80038920();
  }
  return;
}


/* Library Function - Single Match
    perfAutoSampleFn_80038afc
   
   Library: KioskDefault 0 0 */

void perfAutoSampleFn_80038afc(void) { //80038AFC
  uint uVar1;
  uint uVar2;
  u32 uVar3;
  
  if (PERFCurrSample != 0) {
    if (&DAT_0000fffe < CurrToken) {
      if (CurrAutoSample < 0) {
        OSReport(s_PERF___AUTOSAMPLE_<_0_____SHOULD_802df6cc);
      }
      else {
        FUN_80038a3c();
        FUN_80038920();
      }
    }
    else {
      uVar1 = (uint)CurrToken & 0xff;
      if (((uint)CurrToken >> 8 & 0xf) == (uint)perfTokenVar_803984f0) {
        if (-1 < CurrAutoSample) {
                    
          OSPanic("perf.c",0x36a,s_Failed_assertion_CurrAutoSample_<_802df614);
        }
        uVar2 = FUN_8003879c();
        memcpy((void *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0),
               (void *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar1 * 0xb0),0xb0);
        uVar3 = get_PMC4();
        *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x10) = uVar3
        ;
        uVar3 = get_PMC3();
        *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x24) = uVar3
        ;
        uVar3 = get_PMC1();
        *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0 + 0x34) = uVar3
        ;
        FUN_80037c90(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0,1);
        *(undefined *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar2 * 0xb0) = 0xff;
        uVar3 = get_PMC4();
        *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar1 * 0xb0 + 0xc) = uVar3;
        uVar3 = get_PMC3();
        *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar1 * 0xb0 + 0x20) = uVar3
        ;
        uVar3 = get_PMC1();
        *(u32 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar1 * 0xb0 + 0x30) = uVar3
        ;
        FUN_80037c90(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar1 * 0xb0,0);
        *(undefined4 *)(*(int *)(PTR_PTR_DAT_8039850c + DAT_80398504 * 0x10) + uVar1 * 0xb0 + 0x14)
             = 1;
        CurrAutoSample = -1;
      }
      else {
        FUN_80038a3c();
        FUN_80038920();
      }
    }
  }
  return;
}

