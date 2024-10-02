
void newDaySfxFn_800d5858(void) { //800D5858
  s8 cVar1;
  undefined auStack_18 [12];
  
                    /* {@symbol 800d2604} */
  cVar1 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_18);
  if ((cVar1 != DAT_80384b45) || ((DAT_80384b47 & 0x10) != 0)) {
    s8_80384b44 = '<';
    DAT_80384b47 = DAT_80384b47 & 0xef;
  }
  if ('\0' < s8_80384b44) {
    s8_80384b44 = s8_80384b44 + -1;
    if (((cVar1 == 0) && (s8_80384b44 != '\'')) && ('&' < s8_80384b44)) {
      if (s8_80384b44 == ';') {
        DAT_80384b46 = DAT_80384b46 + 1;
        if (0x1b < DAT_80384b46) {
          DAT_80384b46 = 0;
        }
        mainSetBits(0x2ba,(uint)DAT_80384b46);
      }
      else if (((s8_80384b44 < ';') && (s8_80384b44 == '1')) &&
              (((DAT_80384b47 & 1) != 0 && (*(short *)(DAT_80384b24 + (uint)DAT_80384b46 * 2) != 0))
              )) {
        Object_objGetMain();
      }
    }
    if (s8_80384b44 < '\x01') {
      Object_objGetMain();
      if (cVar1 == 0) {
        audioStartSfx((int **)0x0,0x2a,0x7f,0x40,"newday.c",0x8ba);
      }
      else {
        audioStartSfx((int **)0x0,0x2b,0x7f,0x40,"newday.c",0x8b1);
      }
      s8_80384b44 = '\0';
    }
  }
  DAT_80384b45 = cVar1;
  return;
}

