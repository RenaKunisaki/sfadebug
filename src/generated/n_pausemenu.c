
/* Library Function - Single Match
    dll_3D_func00
   
   Library: KioskDefault 0 0 */

void pausemenu_initialise(undefined4 param) { //8016B948
  DAT_803995c4 = textureLoadAsset(0x31e);
  DAT_803995c8 = textureLoadAsset(0x310);
  DAT_803995cc = textureLoadAsset(799);
                    /* {@symbol 8011de8c} */
  DAT_803995c0 = (**(code **)((int)*pDll_subtitles + 0x14))(0);
  PTR_803042c8 = (undefined *)**(undefined4 **)(DAT_803995c0 + 8);
  DAT_80304304 = *(undefined4 *)(*(int *)(DAT_803995c0 + 8) + 4);
  fontLoad(1);
                    /* {@symbol 80173b18} */
  (**(code **)(*(int *)pDll_frontend_control + 4))
            (&PTR_803042c8,2,0,&DAT_80304340,0,0,0x5b,0x45,0x30,0xff,0xd7,0x3d);
  DAT_803995e4 = 0;
  DAT_803995e2 = 0;
  return;
}


/* Library Function - Single Match
    dll_3D_func01
   
   Library: KioskDefault 0 0 */

void pausemenu_release(void) { //8016BA40
  texFreeTexture(DAT_803995c4);
  texFreeTexture(DAT_803995c8);
  texFreeTexture(DAT_803995cc);
  mm_free(DAT_803995c0);
  warpToMap(0,true);
  fontFree(1);
                    /* {@symbol 80173e04} */
  (**(code **)(*(int *)pDll_frontend_control + 8))();
  return;
}


undefined4 pausemenu_func03(void) { //8016BAA4
  int iVar1;
  int iVar2;
  
  if (DAT_803995e2 == '\0') {
                    /* {@symbol 80173e80} */
    iVar1 = (**(code **)(*(int *)pDll_frontend_control + 0xc))();
                    /* {@symbol 8017481c} */
    iVar2 = (**(code **)(*(int *)pDll_frontend_control + 0x14))();
    if (iVar1 == 1) {
      if (iVar2 == 0) {
        audioStartSfx((int **)0x0,0x15e,0x7f,0x40,"n_pausemenu.c",0x9d);
        gfxDllFn_8007399c(1);
        cutsceneExit();
        n64DisableButtons(0,N64_BUTTON_B|N64_BUTTON_A);
      }
      else {
        audioStartSfx((int **)0x0,0x15c,0x7f,0x40,"n_pausemenu.c",0xa2);
        DAT_803995e3 = '\0';
        DAT_803995e2 = '\x01';
        for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
          (&DAT_803042de)[iVar1 * 0x1e] = (&DAT_803042de)[iVar1 * 0x1e] | 0x1000;
        }
                    /* {@symbol 801748e8} */
        (**(code **)(*(int *)pDll_frontend_control + 0x2c))(&PTR_803042c8);
      }
    }
    else if (iVar1 == 0) {
      gfxDllFn_8007399c(1);
      cutsceneExit();
      n64DisableButtons(0,N64_BUTTON_B|N64_BUTTON_A);
    }
  }
  else if (DAT_803995e2 == '\x01') {
    if (DAT_803995e3 == '\0') {
                    /* {@symbol 8012d3b8} */
      (**(code **)(*(int *)pDll_SaveGame + 0x14))();
    }
    DAT_803995e3 = (char)(int)((float)((double)CONCAT44(0x43300000,(int)DAT_803995e3 ^ 0x80000000) -
                                      4503601774854144.0) + timeDelta);
    if (120.0 <= (float)((double)CONCAT44(0x43300000,(int)DAT_803995e3 ^ 0x80000000) -
                        4503601774854144.0)) {
      DAT_803995e2 = '\0';
      for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
        (&DAT_803042de)[iVar1 * 0x1e] = (&DAT_803042de)[iVar1 * 0x1e] & 0xefff;
      }
                    /* {@symbol 801748e8} */
      (**(code **)(*(int *)pDll_frontend_control + 0x2c))(&PTR_803042c8);
                    /* {@symbol 80174828} */
      (**(code **)(*(int *)pDll_frontend_control + 0x18))(0);
    }
  }
  DAT_803995e4 = DAT_803995e4 + (ushort)framesThisStep * 8;
  if (0x8c < DAT_803995e4) {
    DAT_803995e4 = 0x8c;
  }
  return 0;
}


void pausemenu_func04(void) { //8016BD1C
  return;
}


void pausemenu_func05(Gfx *param1) { //8016BD20
  int iVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint *puVar7;
  undefined4 *puVar8;
  double dVar9;
  short local_7c;
  short local_7a;
  short local_78 [2];
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68 [2];
  longlong local_60;
  longlong local_58;
  longlong local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  longlong local_40;
  longlong local_38;
  double local_30;
  
                    /* {@symbol 8012da08} */
  iVar3 = (**(code **)(*(int *)pDll_SaveGame + 0x8c))();
  FUN_80069838(local_68,(int *)&local_6c,&local_70,(int *)&local_74);
  puVar8 = (undefined4 *)param1->cmd;
  *puVar8 = 0xfcffffff;
  puVar8[1] = 0xfffdf6fb;
  RSP_pipeSync(param1);
  puVar8 = (undefined4 *)param1->cmd;
  *puVar8 = 0xef002c00;
  puVar8[1] = 0x504340;
  FUN_800a6900(param1);
  RSP_setTevColor2(param1,0,0,0,(byte)DAT_803995e4);
  puVar7 = (uint *)param1->cmd;
  param1->cmd = (F3DEXcommand)(puVar7 + 2);
  *puVar7 = (local_70 & 0x3ff) << 0xe | 0xf6000000 | (local_74 & 0x3ff) << 2;
  puVar7[1] = (local_68[0] & 0x3ff) << 0xe | (local_6c & 0x3ff) << 2;
  RSP_pState->bNeedPipeSync = true;
  uVar4 = getScreenResolution();
  uVar5 = getScreenResolution();
  textWindowSetBounds(1,0,0,uVar5 & 0xffff,uVar4 >> 0x10);
  textWindowAddString(1);
  local_30 = (double)CONCAT44(0x43300000,(int)DAT_803995e4 ^ 0x80000000);
  fVar2 = ((float)(local_30 - 4503601774854144.0) / 140.0) * 255.0;
  dVar9 = (double)fVar2;
  iVar1 = (int)fVar2;
  local_38 = (longlong)iVar1;
                    /* {@symbol 80174834} */
  (**(code **)(*(int *)pDll_frontend_control + 0x30))(iVar1);
                    /* {@symbol 801743f0} */
  (**(code **)(*(int *)pDll_frontend_control + 0x10))(param1);
  local_40 = (longlong)(int)dVar9;
  textWindowSetColor14(1,0xb7,0x8b,0x61,0xff,(byte)(int)dVar9);
  textWindowSetFontNo(1,1);
  if (DAT_803995e2 == '\x01') {
    fontAddString_80072fb0(1,0xa0,0x73,*(char **)(*(int *)(DAT_803995c0 + 8) + 0x10),1,4);
    local_40 = (longlong)(int)dVar9;
    textWindowSetColor14(1,0,0,0,0xff,(byte)(((int)dVar9 & 0xffU) * 0x96 >> 8));
    fontAddString_80072fb0(1,0x9f,0x72,*(char **)(*(int *)(DAT_803995c0 + 8) + 0x10),1,4);
  }
  else {
    local_40 = (longlong)(int)dVar9;
    FUN_8009f0fc(&param1->cmd,DAT_803995c4,0x2c,0x88,0,0,(int)dVar9,0);
    local_38 = (longlong)(int)dVar9;
    FUN_8009f0fc(&param1->cmd,DAT_803995c8,0x7f,0xa2,0,0,(int)dVar9,0);
    local_30 = (double)(longlong)(int)dVar9;
    FUN_8009f0fc(&param1->cmd,DAT_803995cc,0xd8,0x89,0,0,(int)dVar9,0);
                    /* {@symbol 8012f358} */
    sVar6 = (**(code **)(*(int *)pDll_modelfx + 0x18))();
    sprintf(s__803995dc,"%3d%%",(int)sVar6);
    fontAddString_80072fb0(1,0x108,0x24,s__803995dc,1,4);
                    /* {@symbol 8012de54} */
    uStack_44 = (**(code **)(*(int *)pDll_SaveGame + 0xac))();
    local_48 = 0x43300000;
                    /* {@symbol 800d2750} */
    (**(code **)(*(int *)pDll_newfog + 0x30))
              ((double)(float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0),local_78
               ,&local_7a,&local_7c);
    sprintf(s__8038a108,"%3d:%02d:%02d",(int)local_78[0],(int)local_7a,(int)local_7c);
    fontAddString_80072fb0(1,0x4a,0x24,s__8038a108,1,4);
    local_50 = (longlong)(int)dVar9;
    textWindowSetColor14(1,0,0,0,0xff,(byte)(((int)dVar9 & 0xffU) * 0x96 >> 8));
    fontAddString_80072fb0(1,0x49,0x23,s__8038a108,2,4);
    textWindowSetFontNo(1,2);
    sprintf(s__803995d4,"%1d",0);
    fontAddString_80072fb0(1,0x55,0x9c,s__803995d4,1,0);
    sprintf(s__803995d8,"%1d",(int)*(char *)(iVar3 + 0xb));
    fontAddString_80072fb0(1,0xb6,0xb8,s__803995d8,1,1);
    sprintf(s__803995d0,"%1d",0);
    fontAddString_80072fb0(1,0xe8,0x9c,s__803995d0,1,0);
    local_58 = (longlong)(int)dVar9;
    textWindowSetColor14(1,0xb7,0x8b,0x61,0xff,(byte)(int)dVar9);
    fontAddString_80072fb0(1,0x108,0x15,*(char **)(*(int *)(DAT_803995c0 + 8) + 0xc),2,4);
    fontAddString_80072fb0(1,0x4a,0x15,*(char **)(*(int *)(DAT_803995c0 + 8) + 8),2,4);
    local_60 = (longlong)(int)dVar9;
    textWindowSetColor14(1,0,0,0,0xff,(byte)(((int)dVar9 & 0xffU) * 0x96 >> 8));
    fontAddString_80072fb0(1,0x107,0x14,*(char **)(*(int *)(DAT_803995c0 + 8) + 0xc),2,4);
    fontAddString_80072fb0(1,0x49,0x14,*(char **)(*(int *)(DAT_803995c0 + 8) + 8),2,4);
  }
  textRenderWindow(param1,0,0,1);
  return;
}

