
/* Library Function - Single Match
    dll_3C_func00
   
   Library: KioskDefault 0 0 */

void optionsmenu_initialise(undefined4 param) { //80169150
  Texture *pTVar1;
  int iVar2;
  
                    /* {@symbol 8011b1f0} */
  (**(code **)(*(int *)pDll_gplay + 0x10))(0x14,1);
  DAT_803995b4 = textureLoadAsset(0x2df);
  DAT_803995bc = textureLoadAsset(0x30e);
  DAT_803995b8 = textureLoadAsset(0x30d);
  if (DAT_80399598 == 0) {
                    /* {@symbol 8011de8c} */
    DAT_80399598 = (**(code **)((int)*pDll_subtitles + 0x14))(0xef);
  }
                    /* {@symbol 8011de8c} */
  DAT_8039959c = (**(code **)((int)*pDll_subtitles + 0x14))(0x1f5);
                    /* {@symbol 8011de8c} */
  DAT_803995a4 = (**(code **)((int)*pDll_subtitles + 0x14))(0x1f6);
                    /* {@symbol 8011de8c} */
  DAT_803995a0 = (**(code **)((int)*pDll_subtitles + 0x14))(0x1f7);
  for (iVar2 = 0; iVar2 < 0x12; iVar2 = iVar2 + 1) {
    pTVar1 = textureLoadAsset((int)(short)(&DAT_803041f0)[iVar2]);
    (&DAT_8038a0c0)[iVar2] = pTVar1;
  }
  FUN_8016a038();
  DAT_803995a8 = 0;
  DAT_803995a9 = 0;
                    /* {@symbol 8012d558} */
  DAT_803995ac = (**(code **)(*(int *)pDll_SaveGame + 0x3c))();
  DAT_803995b0 = 2;
  DAT_803995b2 = 0;
  return;
}


/* @description Called when DLL is unloaded */

void optionsmenu_release(void) { //801692AC
  return;
}


/* Library Function - Single Match
    dll_3C_func03
   
   Library: KioskDefault 0 0 */

bool optionsmenu_func03(void) { //801692B0
  char cVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  u8 uVar5;
  char local_28;
  char local_27 [11];
  
  cVar1 = DAT_803995b3;
  uVar5 = framesThisStep;
  if (3 < framesThisStep) {
    uVar5 = '\x03';
  }
  if ('\0' < DAT_803995b3) {
    DAT_803995b3 = DAT_803995b3 - uVar5;
  }
                    /* {@symbol 8011b2c8} */
  iVar2 = (**(code **)(*(int *)pDll_gplay + 0x18))();
  if (iVar2 == 0) {
                    /* {@symbol 80174938} */
    (**(code **)(*(int *)pDll_frontend_control + 0x34))();
    DAT_803995b0 = 2;
  }
  if (DAT_803995b2 != '\0') {
    if ((cVar1 < '\r') || ('\f' < DAT_803995b3)) {
      if (DAT_803995b3 < '\x01') {
        FUN_80079cd0();
        newGameAtPos(12457.099609375,-1474.875,-6690.39794921875,1);
        gfxDllFn_8007399c(4);
      }
    }
    else {
      FUN_800794e4();
      nop_800BF4AC();
      FUN_8016b734();
      FUN_800a6ffc(1);
      setDrawTrackSky(TRUE);
    }
    return DAT_803995b3 < '\r';
  }
                    /* {@symbol 80173e80} */
  iVar2 = (**(code **)(*(int *)pDll_frontend_control + 0xc))();
                    /* {@symbol 8017481c} */
  iVar3 = (**(code **)(*(int *)pDll_frontend_control + 0x14))();
                    /* {@symbol 8016942c} */
  switch(DAT_803972fd) {
  case '\0':
    DAT_803995a9 = (undefined)iVar3;
    iVar2 = FUN_8016af44(iVar2,iVar3);
    if (iVar2 != 0) {
      return false;
    }
    break;
  case '\x01':
    FUN_8016b5f8(iVar2,iVar3);
    if (iVar2 == 0) {
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe0);
      *(undefined *)(DAT_803995ac + 4) = uVar4;
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe4);
      *(undefined *)(DAT_803995ac + 5) = uVar4;
      FUN_8016a038();
    }
    break;
  case '\x02':
    FUN_8016b688(iVar2,iVar3);
    if (iVar2 == 0) {
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe0);
      *(undefined *)(DAT_803995ac + 7) = uVar4;
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe4);
      *(undefined *)(DAT_803995ac + 8) = uVar4;
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe8);
      *(undefined *)(DAT_803995ac + 9) = uVar4;
      FUN_8016a038();
    }
    break;
  case '\x03':
    FUN_8016b024(iVar2,iVar3);
    if (iVar2 == 0) {
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe0);
      *(undefined *)(DAT_803995ac + 1) = uVar4;
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe4);
      *(undefined *)(DAT_803995ac + 2) = uVar4;
      FUN_8016a038();
    }
    break;
  case '\x04':
    FUN_8016b0f8(iVar2,iVar3);
    if (iVar2 == 0) {
      uVar4 = (**(code **)(*pDLL_47 + 0x24))(DAT_80389fe0);
      *(undefined *)(DAT_803995ac + 3) = uVar4;
      FUN_8016a038();
    }
    break;
  case '\x05':
    FUN_8016b1bc(iVar2,iVar3);
    if (iVar2 == 0) {
      for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
        uVar4 = (**(code **)(*pDLL_47 + 0x24))((&DAT_80389fe0)[iVar2 + 1]);
                    /* {@symbol 8012e580} */
        (**(code **)(*(int *)pDll_SaveGame + 0xbc))((uint)DAT_803995b1 + iVar2,uVar4);
      }
      FUN_8016a038();
    }
    break;
  case '\x06':
    nop_8016B730();
    if (iVar2 == 0) {
      FUN_8016a038();
    }
    break;
  case '\a':
    if (iVar2 != -1) {
      texFreeTexture(DAT_803995b4);
      DAT_803995b4 = textureLoadAsset(0x2df);
      FUN_8016a320(1);
      return false;
    }
    break;
  case '\b':
    getStickXY(0,local_27,&local_28);
    if (local_27[0] < '\x01') {
      if (local_27[0] < '\0') {
        audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"n_options.c",0x2a7);
        *(char *)(DAT_803995ac + 0xb) = *(char *)(DAT_803995ac + 0xb) + -1;
        if (*(char *)(DAT_803995ac + 0xb) < -7) {
          *(undefined *)(DAT_803995ac + 0xb) = 0xf9;
          local_27[0] = '\0';
        }
      }
    }
    else {
      audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"n_options.c",0x2a0);
      *(char *)(DAT_803995ac + 0xb) = *(char *)(DAT_803995ac + 0xb) + '\x01';
      if ('\a' < *(char *)(DAT_803995ac + 0xb)) {
        *(undefined *)(DAT_803995ac + 0xb) = 7;
        local_27[0] = '\0';
      }
    }
    if (local_28 < '\x01') {
      if (local_28 < '\0') {
        audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"n_options.c",0x2b7);
        *(char *)(DAT_803995ac + 0xc) = *(char *)(DAT_803995ac + 0xc) + '\x01';
        if ('\a' < *(char *)(DAT_803995ac + 0xc)) {
          *(undefined *)(DAT_803995ac + 0xc) = 7;
          local_28 = '\0';
        }
      }
    }
    else {
      audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"n_options.c",0x2b0);
      *(char *)(DAT_803995ac + 0xc) = *(char *)(DAT_803995ac + 0xc) + -1;
      if (*(char *)(DAT_803995ac + 0xc) < -7) {
        *(undefined *)(DAT_803995ac + 0xc) = 0xf9;
        local_28 = '\0';
      }
    }
    if ((local_27[0] != '\0') || (local_28 != '\0')) {
      nop_800BF5B0();
    }
    if (iVar2 != -1) {
      resetStickDeadZone();
      FUN_8016a7d0(2);
      return false;
    }
  }
  if (DAT_803972fd != '\0') {
    for (iVar2 = 0; iVar2 < DAT_803995a8; iVar2 = iVar2 + 1) {
      if ((&DAT_80389fe0)[iVar2] != 0) {
        if (iVar2 == iVar3) {
          (**(code **)(*pDLL_47 + 0x20))((&DAT_80389fe0)[iVar2],1);
        }
        else {
          (**(code **)(*pDLL_47 + 0x20))((&DAT_80389fe0)[iVar2],0);
        }
        (**(code **)(*pDLL_47 + 0x14))((&DAT_80389fe0)[iVar2]);
      }
    }
  }
  return false;
}


void optionsmenu_func04(void) { //80169924
  return;
}


void optionsmenu_func05(Gfx *param1) { //80169928
  uint uVar1;
  uint uVar2;
  byte param6;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_803972fd * 0x10;
  if ((DAT_803995b2 == '\0') || ('\n' < DAT_803995b3)) {
    uVar1 = getScreenResolution();
    uVar2 = getScreenResolution();
    textWindowSetBounds(1,0,0,uVar2 & 0xffff,uVar1 >> 0x10);
    textWindowAddString(1);
    if (DAT_803972fd == '\b') {
      FUN_8009f0fc(&param1->cmd,DAT_803995b4,0,0,0,0,0xff,2);
      FUN_8009f0fc(&param1->cmd,DAT_803995b8,0x26,0x24,0,0,0xff,1);
      FUN_8009f0fc(&param1->cmd,DAT_803995bc,0x26,0x24,0,0,0xff,1);
      FUN_8009f0fc(&param1->cmd,DAT_803995b8,599,0x24,0,0,0xff,1);
      FUN_8009f0fc(&param1->cmd,DAT_803995bc,0x26,0x1b6,0,0,0xff,1);
      textWindowSetFontNo(1,5);
                    /* {@symbol 801748dc} */
      param6 = (**(code **)(*(int *)pDll_frontend_control + 0x28))();
      textWindowSetColor14(1,0xff,0xff,0xff,0,param6);
      fontAddString_80072fb0(1,0x140,0x2a,s__803972c0,1,4);
      fontAddString_80072fb0(1,0x140,400,s__803972c4,1,4);
      fontAddString_80072fb0(1,0x30,0xeb,s_<_803972c8,1,0);
      fontAddString_80072fb0(1,0x242,0xeb,s_>_803972cc,1,0);
    }
    else if (DAT_803972fd == '\a') {
      FUN_8009f0fc(&param1->cmd,DAT_803995b4,0,0,0,0,0xff,2);
      textWindowSetFontNo(1,1);
      for (iVar4 = 0; iVar4 < 0xb; iVar4 = iVar4 + 1) {
        textWindowSetColor14(1,0xe1,0xab,0x61,0xff,0xff);
        fontAddString_80072fb0
                  (1,(int)(short)(&DAT_80304184)[iVar4 * 2],
                   (int)*(short *)(&PTR_DAT_80304186 + iVar4),
                   *(char **)(*(int *)(DAT_8039959c + 8) + iVar4 * 4),1,0);
        textWindowSetColor14(1,0,0,0,0xff,0x96);
        fontAddString_80072fb0
                  (1,(int)(short)(&DAT_80304184)[iVar4 * 2] - 1,
                   *(short *)(&PTR_DAT_80304186 + iVar4) + -1,
                   *(char **)(*(int *)(DAT_8039959c + 8) + iVar4 * 4),2,0);
      }
      textWindowSetFontNo(1,2);
      iVar3 = 0;
      for (; iVar4 < 0x1b; iVar4 = iVar4 + 1) {
        textWindowSetColor14(1,0xb7,0x8b,0x61,0xff,0xff);
        fontAddString_80072fb0
                  (1,(int)(short)(&DAT_803041b0)[iVar3 * 2],
                   (int)*(short *)(&PTR_DAT_803041b2 + iVar3),
                   *(char **)(*(int *)(DAT_8039959c + 8) + iVar4 * 4),1,0);
        textWindowSetColor14(1,0,0,0,0xff,0x96);
        fontAddString_80072fb0
                  (1,(int)(short)(&DAT_803041b0)[iVar3 * 2] - 1,
                   *(short *)(&PTR_DAT_803041b2 + iVar3) + -1,
                   *(char **)(*(int *)(DAT_8039959c + 8) + iVar4 * 4),2,0);
        iVar3 = iVar3 + 1;
      }
    }
    else {
      FUN_8009f0fc(&param1->cmd,DAT_803995b4,0,0,0,0,0xff,2);
      textWindowSetFontNo(1,4);
      textWindowSetColor14(1,0xff,0xff,0xff,0,0xff);
      fontAddString_80072fb0(1,0x238,0x3f,*(char **)(*(int *)(DAT_80399598 + 8) + 4),1,1);
      textWindowSetColor14(1,0,0,0,0xff,0xff);
      fontAddString_80072fb0(1,0x233,0x3a,*(char **)(*(int *)(DAT_80399598 + 8) + 4),2,1);
      if (*(char *)(iVar4 + -0x7fcfbf03) != -1) {
        textWindowSetColor14(1,0xff,0xff,0xff,0,0xff);
        fontAddString_80072fb0
                  (1,0x53,0xb2,
                   *(char **)(*(int *)(DAT_80399598 + 8) + *(char *)(iVar4 + -0x7fcfbf03) * 4),1,0);
        textWindowSetColor14(1,0,0,0,0xff,0xff);
        fontAddString_80072fb0
                  (1,0x4e,0xad,
                   *(char **)(*(int *)(DAT_80399598 + 8) + *(char *)(iVar4 + -0x7fcfbf03) * 4),2,0);
      }
      if (*(char *)(iVar4 + -0x7fcfbf02) != -1) {
        textWindowSetFontNo(1,0);
        textWindowSetColor14(1,0xb7,0x8b,0x61,0xff,0xff);
        fontAddString_80072fb0
                  (1,0x140,0x195,
                   *(char **)(*(int *)(DAT_80399598 + 8) + *(char *)(iVar4 + -0x7fcfbf02) * 4),1,4);
        textWindowSetColor14(1,0,0,0,0xff,0xff);
        fontAddString_80072fb0
                  (1,0x13e,0x193,
                   *(char **)(*(int *)(DAT_80399598 + 8) + *(char *)(iVar4 + -0x7fcfbf02) * 4),2,4);
      }
      if (*(char *)(iVar4 + -0x7fcfbf03) != -1) {
        FUN_8016b87c(&param1->cmd,0x38,0xdc,0,0x1e0);
      }
      for (iVar4 = 0; iVar4 < DAT_803995a8; iVar4 = iVar4 + 1) {
        if ((&DAT_80389fe0)[iVar4] != 0) {
          (**(code **)(*pDLL_47 + 0x18))((&DAT_80389fe0)[iVar4],param1);
        }
      }
    }
                    /* {@symbol 801743f0} */
    (**(code **)(*(int *)pDll_frontend_control + 0x10))(param1);
    textRenderWindow(param1,0,0,1);
    DAT_803995b0 = DAT_803995b0 + -1;
    if (DAT_803995b0 < '\0') {
      DAT_803995b0 = '\0';
    }
  }
  return;
}

