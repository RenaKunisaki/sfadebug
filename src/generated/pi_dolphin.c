
/* Library Function - Single Match
    piRomLoadSection
   
   Library: KioskDefault 0 0 */

void piRomLoadSection(int id,byte *dest) { //80099CEC
  int iVar1;
  int *entry;
  int len;
  longlong local_58;
  undefined4 local_50;
  u32 uStack_4c;
  longlong local_48;
  undefined4 local_40;
  u32 uStack_3c;
  longlong local_38;
  undefined4 local_30;
  u32 uStack_2c;
  longlong local_28;
  undefined4 local_20;
  u32 uStack_1c;
  
                    /* MAPS.bin */
  if (dataFilePtrs[29] == (void *)0x0) {
                    
    OSPanic("pi_dolphin.c",0x43c,"piRomLoadSection(): DB_MAPS Bin Not Loaded");
  }
  entry = (int *)((int)dataFilePtrs[29] + id);
  if (*entry == -0x1f1f1f20) {
    memcpy_src_dst_len((void *)((int)entry + entry[2] + 0x18),dest,entry[1]);
  }
  else if (*entry == -0xf0f0f10) {
    iVar1 = (entry[2] + 0x28) - (int)dataFilePtrs[29];
    set_MMCR1(0x7fc00000);
    set_MMCR0(0x42);
    lzoDecompress((byte *)((int)dataFilePtrs[29] + (int)entry + iVar1),entry[3],dest,&len);
    set_MMCR0(0);
    set_MMCR1(0);
    uStack_1c = get_PMC1();
    local_20 = 0x43300000;
    local_28 = (longlong)
               (int)((float)((double)CONCAT44(0x43300000,uStack_1c) - 4503599627370496.0) * 0.001);
    uStack_2c = get_PMC2();
    local_30 = 0x43300000;
    local_38 = (longlong)
               (int)((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503599627370496.0) * 0.001);
    uStack_3c = get_PMC3();
    local_40 = 0x43300000;
    local_48 = (longlong)
               (int)((float)((double)CONCAT44(0x43300000,uStack_3c) - 4503599627370496.0) * 0.001);
    uStack_4c = get_PMC4();
    local_50 = 0x43300000;
    local_58 = (longlong)
               (int)((float)((double)CONCAT44(0x43300000,uStack_4c) - 4503599627370496.0) * 0.001);
    set_PMC1(0);
    set_PMC2(0);
    set_PMC3(0);
    set_PMC4(0);
    DCStoreRange(dest,len);
  }
  return;
}


/* Library Function - Single Match
    piRomFreeLevel
   
   Library: KioskDefault 0 0 */

undefined4 piRomFreeLevel(int map,uint flags) { //8009D140
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int local_b8 [2];
  int local_b0 [40];
  
  iVar4 = 0x14;
  piVar2 = null_ARRAY_802cf028 + 0x10c;
  piVar3 = local_b8;
  do {
    iVar1 = piVar2[3];
    piVar3[2] = piVar2[2];
    piVar3[3] = iVar1;
    iVar4 = iVar4 + -1;
    piVar2 = piVar2 + 2;
    piVar3 = piVar3 + 2;
  } while (iVar4 != 0);
  iVar4 = 0;
  local_b8[0] = map;
  while( true ) {
    if (0x27 < iVar4) {
      return 1;
    }
    if ((dataFilePtrs[local_b0[iVar4]] != (void *)0x0) &&
       ((((flags & 0x80000000) != 0 ||
         (((flags & local_b0[iVar4] + 1U) != 0 && (local_b8[0] == loadedFileMapIds[local_b0[iVar4]])
          ))) || (((flags & 0x10000000) != 0 && (local_b8[0] != loadedFileMapIds[local_b0[iVar4]])))
        ))) {
      mm_free(dataFilePtrs[local_b0[iVar4]]);
      dataFilePtrs[local_b0[iVar4]] = (void *)0x0;
      loadedFileMapIds[local_b0[iVar4]] = -1;
      if (true) {
                    /* {@symbol 8009d32c} */
        switch(local_b0[iVar4]) {
        case 0x21:
        case 0x4c:
          mergeTableFiles((undefined *)&TEX1_TAB,TEX1.tab,TEX1.tab_4C);
          break;
        case 0x24:
        case 0x4e:
          mergeTableFiles((undefined *)&TEX0_TAB,TEX0.tab,TEX0.tab_4E);
          break;
        case 0x26:
        case 0x48:
          mergeTableFiles(&BLOCKS_TAB,BLOCKS.tab,BLOCKS.tab_48);
          break;
        case 0x2a:
        case 0x45:
          mergeTableFiles(&MODELS_TAB,MODELS.tab,MODELS.tab_45);
          break;
        case 0x2f:
        case 0x49:
          mergeTableFiles(&ANIM_TAB,ANIM.TAB,ANIM.TAB_49);
        }
      }
    }
    if (0x27 < iVar4) break;
    iVar4 = iVar4 + 2;
  }
                    
  OSPanic("pi_dolphin.c",0xddd,"piRomFreeLevel(): flist array overflow");
}

