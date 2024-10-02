
/* Library Function - Single Match
    picmenu_func00
   
   Library: KioskDefault 0 0 */

void picmenu_initialise(undefined4 param) { //80173A5C
  Texture *pTVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    pTVar1 = textureLoadAsset((int)(short)(&DAT_80305378)[iVar2 * 4]);
    (&DAT_80305374)[iVar2 * 2] = pTVar1;
  }
  DAT_80399726 = 0xff;
  return;
}


/* Library Function - Single Match
    picmenu_func01
   
   Library: KioskDefault 0 0 */

void picmenu_release(void) { //80173AC8
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    texFreeTexture((Texture *)(&DAT_80305374)[iVar1 * 2]);
  }
  return;
}


/* Library Function - Single Match
    picmenu_func03
   
   Library: KioskDefault 0 0 */

void picmenu_func03(void *param_1,int param_2,undefined param_3,undefined **param_4,
                    undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined2 param_8,
                    undefined2 param_9,undefined2 param_10,undefined2 param_11,undefined2 param_12) { //80173B18
  int iVar1;
  int iVar2;
  Texture *pTVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 < 0x29) {
    DAT_80399722 = (undefined)param_2;
    DAT_80399724 = 0xff;
    DAT_80399723 = 0;
    DAT_80399720 = 0;
    DAT_80399721 = param_3;
    memcpy_src_dst_len(param_1,&DAT_8038b0c0,param_2 * 0x3c);
    for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
      iVar1 = iVar5 * 0x3c;
      if (((char)(&DAT_8038b0da)[iVar1] < -1) || (param_2 <= (char)(&DAT_8038b0da)[iVar1])) {
        OSReport("UPLINK overflow=%d",(int)(char)(&DAT_8038b0da)[iVar1]);
      }
      if (((char)(&DAT_8038b0db)[iVar1] < -1) || (param_2 <= (char)(&DAT_8038b0db)[iVar1])) {
        OSReport("DOWNLINK overflow=%d",(int)(char)(&DAT_8038b0db)[iVar1]);
      }
      if (((char)(&DAT_8038b0dc)[iVar1] < -1) || (param_2 <= (char)(&DAT_8038b0dc)[iVar1])) {
        OSReport("LEFTLINK overflow=%d",(int)(char)(&DAT_8038b0dc)[iVar1]);
      }
      if (((char)(&DAT_8038b0dd)[iVar1] < -1) || (param_2 <= (char)(&DAT_8038b0dd)[iVar1])) {
        OSReport("RIGHTLINK overflow=%d",(int)(char)(&DAT_8038b0dd)[iVar1]);
      }
      if (*(int *)((int)param_1 + iVar5 * 0x3c + 0x10) == -1) {
        (&DAT_8038b0d0)[iVar5 * 0xf] = 0;
      }
      else {
        pTVar3 = textureLoadAsset(*(int *)((int)param_1 + iVar5 * 0x3c + 0x10));
        (&DAT_8038b0d0)[iVar5 * 0xf] = pTVar3;
      }
      if (((&DAT_8038b0d6)[iVar5 * 0x1e] & 0x10) != 0) {
        uVar4 = FUN_80174be8((char *)(&DAT_8038b0c0)[iVar5 * 0xf],(uint)(byte)(&DAT_8038b0d8)[iVar1]
                            );
        (&DAT_8038b0d4)[iVar5 * 0x1e] = (short)uVar4;
        (&DAT_8038b0c8)[iVar5 * 0x1e] = (short)uVar4;
      }
      if (((&DAT_8038b0d6)[iVar5 * 0x1e] & 4) != 0) {
        picMenuTexFn_80174c58((int)(&DAT_8038b0c0 + iVar5 * 0xf));
      }
      if (((&DAT_8038b0dc)[iVar1] != -1) && (((&DAT_8038b0d6)[iVar5 * 0x1e] & 8) != 0)) {
        iVar2 = (int)(char)(&DAT_8038b0dc)[iVar1];
        (&DAT_8038b0ca)[iVar5 * 0x1e] =
             (&DAT_8038b0ca)[iVar2 * 0x1e] + (&DAT_8038b0d4)[iVar2 * 0x1e];
        (&DAT_8038b0c4)[iVar5 * 0x1e] =
             (&DAT_8038b0c4)[iVar2 * 0x1e] + (&DAT_8038b0d4)[iVar2 * 0x1e];
      }
      if (((&DAT_8038b0d6)[iVar5 * 0x1e] & 0x400) != 0) {
        (&DAT_8038b0ca)[iVar5 * 0x1e] =
             (&DAT_8038b0ca)[iVar5 * 0x1e] -
             (short)((int)(uint)(ushort)(&DAT_8038b0d4)[iVar5 * 0x1e] >> 1);
        (&DAT_8038b0c4)[iVar5 * 0x1e] = (&DAT_8038b0ca)[iVar5 * 0x1e];
      }
      if (((&DAT_8038b0d6)[iVar5 * 0x1e] & 2) != 0) {
        (&DAT_8038b0c4)[iVar5 * 0x1e] =
             (&DAT_8038b0ca)[iVar5 * 0x1e] +
             (short)((int)(uint)(ushort)(&DAT_8038b0c8)[iVar5 * 0x1e] >> 1);
      }
      (&DAT_8038b0f8)[iVar1] = 4;
    }
    DAT_80399730 = param_9;
    DAT_80399732 = param_10;
    DAT_80399734 = param_11;
    DAT_80399736 = param_12;
    DAT_80399728 = param_4;
    DAT_8039972c = param_7;
    DAT_8039972e = param_8;
    if (param_4 == (undefined **)0x0) {
      DAT_80399728 = &PTR_DAT_80305368;
    }
  }
  else {
    printf("PICMENU: maxitems exceeded");
  }
  return;
}


/* Library Function - Single Match
    picmenu_func04
   
   Library: KioskDefault 0 0 */

void picmenu_func04(void) { //80173E04
  int iVar1;
  
  for (iVar1 = 0; iVar1 < DAT_80399722; iVar1 = iVar1 + 1) {
    if ((&DAT_8038b0d0)[iVar1 * 0xf] != 0) {
      texFreeTexture((Texture *)(&DAT_8038b0d0)[iVar1 * 0xf]);
    }
  }
  DAT_80399722 = 0;
  return;
}


/* Library Function - Single Match
    picmenu_func05
   
   Library: KioskDefault 0 0 */

undefined4 picmenu_func05(void) { //80173E80
  short sVar1;
  int iVar2;
  N64Button32 NVar3;
  uint uVar4;
  undefined4 uVar5;
  char local_20;
  char local_1f [11];
  
  iVar2 = DAT_80399721 * 0x3c;
  if (DAT_80399722 != '\0') {
    uVar5 = 0xffffffff;
    getStickXY(0,local_1f,&local_20);
    if (local_20 != '\0') {
      local_1f[0] = '\0';
    }
    if ((local_1f[0] != '\0') || (local_20 != '\0')) {
      if ((local_20 < '\0') &&
         (((&DAT_8038b0db)[iVar2] != -1 &&
          (((&DAT_8038b0d6)[(char)(&DAT_8038b0db)[iVar2] * 0x1e] & 0x1000) == 0)))) {
        DAT_80399721 = (&DAT_8038b0db)[iVar2];
        DAT_80399724 = 0xff;
        if (-1 < *DAT_80399728) {
          audioStartSfx((int **)0x0,(ushort)*DAT_80399728,0x7f,0x40,"picmenu.c",0x10a);
        }
      }
      else if (('\0' < local_20) &&
              (((&DAT_8038b0da)[iVar2] != -1 &&
               (((&DAT_8038b0d6)[(char)(&DAT_8038b0da)[iVar2] * 0x1e] & 0x1000) == 0)))) {
        DAT_80399721 = (&DAT_8038b0da)[iVar2];
        DAT_80399724 = 0xff;
        if (-1 < *DAT_80399728) {
          audioStartSfx((int **)0x0,(ushort)*DAT_80399728,0x7f,0x40,"picmenu.c",0x10e);
        }
      }
      if ((&DAT_8038b0de)[iVar2] == -1) {
        if (((local_1f[0] < '\0') && ((&DAT_8038b0dc)[iVar2] != -1)) &&
           (((&DAT_8038b0d6)[(char)(&DAT_8038b0dc)[iVar2] * 0x1e] & 0x1000) == 0)) {
          DAT_80399721 = (&DAT_8038b0dc)[iVar2];
          DAT_80399724 = 0xff;
          if (-1 < *DAT_80399728) {
            audioStartSfx((int **)0x0,(ushort)*DAT_80399728,0x7f,0x40,"picmenu.c",0x120);
          }
        }
        else if ((('\0' < local_1f[0]) && ((&DAT_8038b0dd)[iVar2] != -1)) &&
                (((&DAT_8038b0d6)[(char)(&DAT_8038b0dd)[iVar2] * 0x1e] & 0x1000) == 0)) {
          DAT_80399721 = (&DAT_8038b0dd)[iVar2];
          DAT_80399724 = 0xff;
          if (-1 < *DAT_80399728) {
            audioStartSfx((int **)0x0,(ushort)*DAT_80399728,0x7f,0x40,"picmenu.c",0x124);
          }
        }
      }
      else {
        iVar2 = (char)(&DAT_8038b0de)[iVar2] * 0x3c;
        if ((local_1f[0] < '\0') && ((&DAT_8038b0dc)[iVar2] != -1)) {
          (&DAT_8038b0de)[DAT_80399721 * 0x3c] = (&DAT_8038b0dc)[iVar2];
          DAT_80399724 = 0xff;
          if (-1 < *DAT_80399728) {
            audioStartSfx((int **)0x0,(ushort)*DAT_80399728,0x7f,0x40,"picmenu.c",0x116);
          }
        }
        else if (('\0' < local_1f[0]) && ((&DAT_8038b0dd)[iVar2] != -1)) {
          (&DAT_8038b0de)[DAT_80399721 * 0x3c] = (&DAT_8038b0dd)[iVar2];
          DAT_80399724 = 0xff;
          if (-1 < *DAT_80399728) {
            audioStartSfx((int **)0x0,(ushort)*DAT_80399728,0x7f,0x40,"picmenu.c",0x11a);
          }
        }
      }
      if (DAT_80399721 < '\0') {
        DAT_80399721 = DAT_80399722 + -1;
      }
      if (DAT_80399722 <= DAT_80399721) {
        DAT_80399721 = '\0';
      }
    }
    if (DAT_80399720 != '\0') {
      NVar3 = n64GetEnabledButtonsPressed(0);
      if ((NVar3 & (N64_BUTTON_START|N64_BUTTON_A)) == 0) {
        if ((NVar3 & N64_BUTTON_B) != 0) {
          if (-1 < DAT_80399728[2]) {
            audioStartSfx((int **)0x0,(ushort)DAT_80399728[2],0x7f,0x40,"picmenu.c",0x13a);
          }
          n64DisableButtons(0,N64_BUTTON_B);
          uVar5 = 0;
        }
      }
      else if ((((&DAT_8038b0d6)[DAT_80399721 * 0x1e] & 0x20) == 0) &&
              (uVar4 = mainGetBit(0x44f), uVar4 == 0)) {
        n64DisableButtons(0,N64_BUTTON_START|N64_BUTTON_A);
        if (-1 < DAT_80399728[1]) {
          audioStartSfx((int **)0x0,(ushort)DAT_80399728[1],0x7f,0x40,"picmenu.c",0x136);
        }
        uVar5 = 1;
      }
    }
    if (DAT_80399723 == 0) {
      sVar1 = (ushort)framesThisStep * -5;
    }
    else {
      sVar1 = (ushort)framesThisStep * 5;
    }
    DAT_80399724 = DAT_80399724 + sVar1;
    if (DAT_80399724 < 0x100) {
      if (DAT_80399724 < 0) {
        DAT_80399724 = -DAT_80399724;
        DAT_80399723 = DAT_80399723 ^ 1;
      }
    }
    else {
      DAT_80399724 = 0xff - (DAT_80399724 + -0xff);
      DAT_80399723 = DAT_80399723 ^ 1;
    }
    DAT_80399720 = 1;
    FUN_80174a70();
    FUN_80174980();
    return uVar5;
  }
  return 0xffffffff;
}


/* Library Function - Single Match
    picmenu_func06
   
   Library: KioskDefault 0 0 */

void picmenu_func06(void) { //801743F0
  char cVar1;
  short sVar2;
  u8 uVar3;
  int iVar4;
  ushort uVar5;
  int x;
  int iVar6;
  int iVar7;
  byte param6;
  byte param6_00;
  char **ppcVar8;
  
  for (iVar7 = 0; iVar7 < DAT_80399722; iVar7 = iVar7 + 1) {
    iVar4 = iVar7 * 0x3c;
    if (((&DAT_8038b0d6)[iVar7 * 0x1e] & 0x1040) == 0) {
      if ((&DAT_8038b0de)[iVar4] != -1) {
        iVar4 = (char)(&DAT_8038b0de)[iVar4] * 0x3c;
      }
      ppcVar8 = (char **)((int)&DAT_8038b0c0 + iVar4);
      if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 4) != 0) {
        x = (int)*(short *)((int)&DAT_8038b0ca + iVar4);
        sVar2 = *(short *)((int)&DAT_8038b0cc + iVar4);
        for (iVar6 = 0; (*(char *)((int)ppcVar8 + iVar6 + 0x1f) != -1 && (iVar6 < 0x19));
            iVar6 = iVar6 + 1) {
          drawTexture((Texture *)(&DAT_80305374)[*(char *)((int)ppcVar8 + iVar6 + 0x1f) * 2],x,
                      (int)sVar2,0xff,0x100);
          x = x + (uint)(byte)(&DAT_8030537a)[*(char *)((int)ppcVar8 + iVar6 + 0x1f) * 8];
        }
      }
      param6 = (byte)DAT_80399726;
      param6_00 = param6;
      if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 0x800) != 0) {
        param6_00 = (byte)((uint)((int)DAT_80399726 << 7) >> 8);
      }
      if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 0x80) == 0) {
        textWindowSetColor14(1,0xff,0xff,0xff,0,param6_00);
      }
      else if (DAT_80399721 == iVar7) {
        if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 0x800) != 0) {
          param6 = (byte)((uint)((int)DAT_80399726 << 7) >> 8);
        }
        textWindowSetColor14
                  (1,(u8)DAT_8039972c +
                     (char)((uint)((int)DAT_80399724 * ((int)DAT_80399732 - (int)DAT_8039972c)) >> 8
                           ),
                   (u8)DAT_8039972e +
                   (char)((uint)((int)DAT_80399724 * ((int)DAT_80399734 - (int)DAT_8039972e)) >> 8),
                   (u8)DAT_80399730 +
                   (char)((uint)((int)DAT_80399724 * ((int)DAT_80399736 - (int)DAT_80399730)) >> 8),
                   0xff,param6);
      }
      else {
        textWindowSetColor14(1,(u8)DAT_8039972c,(u8)DAT_8039972e,(u8)DAT_80399730,0xff,param6_00);
      }
      textWindowSetFontNo(1,(uint)(byte)(&DAT_8038b0d8)[iVar4]);
      if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 2) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 4;
      }
      fontAddString_80072fb0
                (1,(int)*(short *)((int)&DAT_8038b0c4 + iVar4),
                 (int)*(short *)((int)&DAT_8038b0c6 + iVar4),*ppcVar8,2,uVar5);
      if (((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 0x80) == 0) && (DAT_80399721 == iVar7)) {
        textWindowSetColor14
                  (1,0xff,0xff,0xff,0,(byte)((uint)((DAT_80399724 + 1) * (int)DAT_80399726) >> 8));
        textWindowSetFontNo(1,(uint)(byte)(&DAT_8038b0d9)[iVar4]);
        if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 2) == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 4;
        }
        fontAddString_80072fb0
                  (1,(int)*(short *)((int)&DAT_8038b0c4 + iVar4),
                   (int)*(short *)((int)&DAT_8038b0c6 + iVar4),*ppcVar8,1,uVar5);
      }
      if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 0x100) != 0) {
        textWindowSetColor14(1,0,0,0,0xff,(byte)((uint)(DAT_80399726 * 0x96) >> 8));
        if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 2) == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 4;
        }
        fontAddString_80072fb0
                  (1,(int)*(short *)((int)&DAT_8038b0c4 + iVar4) - 1,
                   *(short *)((int)&DAT_8038b0c6 + iVar4) + -1,*ppcVar8,3,uVar5);
      }
      if (*(int *)((int)&DAT_8038b0d0 + iVar4) != 0) {
        if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 4) == 0) {
          if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 0x800) == 0) {
            uVar3 = 0xff;
          }
          else {
            uVar3 = 0x80;
          }
          drawTexture(*(Texture **)((int)&DAT_8038b0d0 + iVar4),
                      (int)*(short *)((int)&DAT_8038b0ca + iVar4),
                      (int)*(short *)((int)&DAT_8038b0cc + iVar4),uVar3,0x100);
        }
        else {
          if ((*(ushort *)((int)&DAT_8038b0d6 + iVar4) & 0x800) == 0) {
            uVar3 = 0xff;
          }
          else {
            uVar3 = 0x80;
          }
          drawTexture(*(Texture **)((int)&DAT_8038b0d0 + iVar4),
                      *(short *)((int)&DAT_8038b0ca + iVar4) + 0xb,
                      (int)*(short *)((int)&DAT_8038b0cc + iVar4),uVar3,0x100);
        }
      }
      cVar1 = (&DAT_8038b0f8)[iVar4];
      (&DAT_8038b0f8)[iVar4] = cVar1 + -1;
      if ((char)(cVar1 + -1) < '\0') {
        (&DAT_8038b0f8)[iVar4] = 0;
      }
    }
    else {
      cVar1 = (&DAT_8038b0f8)[iVar4];
      (&DAT_8038b0f8)[iVar4] = cVar1 + -1;
      if ((char)(cVar1 + -1) < '\0') {
        (&DAT_8038b0f8)[iVar4] = 0;
      }
    }
  }
  return;
}


int picmenu_func07(void) { //8017481C
  return (int)DAT_80399721;
}


void picmenu_func08(undefined param1) { //80174828
  DAT_80399721 = param1;
  return;
}


void picmenu_func0E(ushort param1) { //80174834
  DAT_80399726 = param1 & 0xff;
  return;
}


int picmenu_func09(int param1) { //80174840
  return (int)(char)(&DAT_8038b0de)[param1 * 0x3c];
}


void picmenu_func0A(int param1,undefined param2) { //8017485C
  (&DAT_8038b0de)[param1 * 0x3c] = param2;
  return;
}


/* Library Function - Single Match
    picmenu_func0B
   
   Library: KioskDefault 0 0 */

void picmenu_func0B(int param1) { //80174878
  int iVar1;
  
  for (iVar1 = 0; iVar1 < DAT_80399722; iVar1 = iVar1 + 1) {
    (&DAT_8038b0c0)[iVar1 * 0xf] = *(undefined4 *)(param1 + iVar1 * 0x3c);
    (&DAT_8038b0f8)[iVar1 * 0x3c] = 2;
  }
  return;
}


ushort picmenu_func0C(void) { //801748DC
  return DAT_80399724 & 0xff;
}


/* Library Function - Single Match
    picmenu_func0D
   
   Library: KioskDefault 0 0 */

void picmenu_func0D(int param1) { //801748E8
  int iVar1;
  
  for (iVar1 = 0; iVar1 < DAT_80399722; iVar1 = iVar1 + 1) {
    (&DAT_8038b0d6)[iVar1 * 0x1e] = *(undefined2 *)(param1 + iVar1 * 0x3c + 0x16);
  }
  return;
}


/* Library Function - Single Match
    picmenu_func0F
   
   Library: KioskDefault 0 0 */

void picmenu_func0F(void) { //80174938
  int iVar1;
  
  for (iVar1 = 0; iVar1 < DAT_80399722; iVar1 = iVar1 + 1) {
    (&DAT_8038b0f8)[iVar1 * 0x3c] = 4;
  }
  return;
}

