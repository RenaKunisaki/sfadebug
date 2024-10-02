
/* Library Function - Single Match
    dll_46_func00
   
   Library: KioskDefault 0 0 */

void frontend_control_initialise(undefined4 param) { //80174D74
  Texture *pTVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < 7; iVar2 = iVar2 + 1) {
    pTVar1 = textureLoadAsset((int)*(short *)((int)&PTR_DAT_80305490 + iVar2 * 2));
    (&DAT_8038ba20)[iVar2] = pTVar1;
  }
  return;
}


/* Library Function - Single Match
    dll_46_func01
   
   Library: KioskDefault 0 0 */

void frontend_control_release(void) { //80174DD8
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 7; iVar1 = iVar1 + 1) {
    texFreeTexture((Texture *)(&DAT_8038ba20)[iVar1]);
  }
  return;
}


/* Library Function - Single Match
    dll_46_func03
   
   Library: KioskDefault 0 0 */

undefined2 *
frontend_control_func03(undefined2 param1,undefined2 param2,short param3,short param4,short param5) { //80174E28
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = DAT_8038ba20;
  if (param5 < param3) {
    param5 = param3;
  }
  if (param4 < param5) {
    param5 = param4;
  }
  puVar2 = (undefined2 *)mmAlloc(0x10,TRACK_COL,"frontend:control");
  *(undefined *)((int)puVar2 + 5) = 0;
  puVar2[6] = param5;
  puVar2[4] = param3;
  puVar2[5] = param4;
  *puVar2 = param1;
  puVar2[1] = param2;
  *(undefined *)(puVar2 + 2) = 0;
  *(undefined *)(puVar2 + 3) = 4;
  puVar2[7] = *(short *)(iVar1 + 10) + -8;
  return puVar2;
}


/* Library Function - Single Match
    dll_46_func04
   
   Library: KioskDefault 0 0 */

undefined2 *
frontend_control_func04(undefined2 param1,undefined2 param2,short param3,short param4,short param5) { //80174EEC
  undefined2 *puVar1;
  
  if (param5 < param3) {
    param5 = param3;
  }
  if (param4 < param5) {
    param5 = param4;
  }
  puVar1 = (undefined2 *)mmAlloc(0xe,TRACK_COL,"frontend:control");
  *(undefined *)((int)puVar1 + 5) = 1;
  puVar1[6] = param5;
  puVar1[4] = param3;
  puVar1[5] = param4;
  *puVar1 = param1;
  puVar1[1] = param2;
  *(undefined *)(puVar1 + 2) = 0;
  *(undefined *)(puVar1 + 3) = 4;
  return puVar1;
}


/* Library Function - Single Match
    dll_46_func05
   
   Library: KioskDefault 0 0 */

undefined2 *
frontend_control_func05
          (undefined2 param1,undefined2 param2,short param3,short param4,short param5,
          undefined4 param6,undefined param7) { //80174F9C
  undefined2 *puVar1;
  
  if (param5 < param3) {
    param5 = param3;
  }
  if (param4 < param5) {
    param5 = param4;
  }
  puVar1 = (undefined2 *)mmAlloc(0x18,TRACK_COL,"frontend:control");
  *(undefined *)((int)puVar1 + 5) = 2;
  puVar1[6] = param5;
  puVar1[4] = param3;
  puVar1[5] = param4;
  *(undefined4 *)(puVar1 + 8) = param6;
  *puVar1 = param1;
  puVar1[1] = param2;
  *(undefined *)(puVar1 + 2) = 2;
  *(undefined *)(puVar1 + 3) = 4;
  *(undefined *)(puVar1 + 10) = param7;
  return puVar1;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_46_func06
    musyxFree
   
   Library: KioskDefault 0 0 */

void frontend_control_func06(void *param1) { //80175064
  mm_free(param1);
  return;
}


/* Library Function - Single Match
    dll_46_func07
   
   Library: KioskDefault 0 0 */

void frontend_control_func07(FrontendControlStruct *param1) { //8017508C
  byte bVar1;
  ushort uVar2;
  s8 sVar4;
  N64Button32 NVar3;
  uint screenY;
  int screenH;
  uint screenX;
  int screenW;
  s8 stickY;
  s8 stickX;
  s8 local_21;
  
  videoBackendGetResolution(&screenW,&screenX,&screenH,&screenY);
  if (param1->field5_0x5 == 0) {
    screenY = screenY + 4;
  }
  else if (param1->field5_0x5 == 1) {
    screenY = screenY + 4;
  }
  videoBackendSetResolution(screenW,screenX,screenH,screenY);
  if ((param1->flags04 & 1) == 0) {
    return;
  }
  param1->flags04 = param1->flags04 & 0xe3;
  uVar2 = param1->timer0C;
  param1->field6_0x6 = 4;
  bVar1 = param1->field5_0x5;
  if (bVar1 != 1) {
    if (bVar1 == 0) {
      if (true) {
        sVar4 = getStickX2(0);
        param1->timer0C =
             param1->timer0C +
             (short)(char)(int)((timeDelta *
                                (float)((double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000) -
                                       4503601774854144.0)) / 40.0);
        goto LAB_80175294;
      }
    }
    else if (bVar1 < 3) {
      getStickXY(0,&stickX,&stickY);
      if (stickX < 0) {
        audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"control.c",0xfe);
        param1->timer0C = param1->timer0C - 1;
        param1->flags04 = param1->flags04 | 4;
      }
      else if (0 < stickX) {
        audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"control.c",0x102);
        param1->timer0C = param1->timer0C + 1;
        param1->flags04 = param1->flags04 | 8;
      }
      goto LAB_80175294;
    }
  }
  if (((param1->flags04 & 0x20) == 0) &&
     (NVar3 = n64GetEnabledButtonsPressed(0), (NVar3 & N64_BUTTON_A) != 0)) {
    audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"control.c",0x110);
    param1->timer0C = param1->timer0C ^ 1;
  }
LAB_80175294:
  if (param1->timerInit0A < (short)param1->timer0C) {
    if ((param1->flags04 & 2) == 0) {
      param1->timer0C = param1->timerInit0A;
    }
    else {
      param1->timer0C = 0;
    }
  }
  else if ((short)param1->timer0C < param1->timerInit08) {
    if ((param1->flags04 & 2) == 0) {
      param1->timer0C = param1->timerInit08;
    }
    else {
      param1->timer0C = param1->timerInit0A;
    }
  }
  if (uVar2 != param1->timer0C) {
    param1->flags04 = param1->flags04 | 0x10;
  }
  return;
}


/* Library Function - Single Match
    dll_46_func08
   
   Library: KioskDefault 0 0 */

void frontend_control_func08(short *param1,undefined4 *param2) { //80175328
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param1 + 5);
  if (bVar1 == 1) {
    FUN_8017559c(param1,param2);
  }
  else if (bVar1 == 0) {
    if (true) {
      FUN_80175448(param1,param2);
    }
  }
  else if (bVar1 < 3) {
    FUN_80175650(param1);
  }
  cVar2 = *(char *)(param1 + 3);
  *(char *)(param1 + 3) = cVar2 + -1;
  if ((char)(cVar2 + -1) < '\0') {
    *(undefined *)(param1 + 3) = 0;
  }
  return;
}


byte frontend_control_func09(int param1) { //801753C4
  return *(byte *)(param1 + 4) & 1;
}


/* Library Function - Single Match
    dll_46_func0A
   
   Library: KioskDefault 0 0 */

void frontend_control_func0A(int param1,int param2) { //801753D0
  if (param2 != 0) {
    *(byte *)(param1 + 4) = *(byte *)(param1 + 4) | 1;
    return;
  }
  *(byte *)(param1 + 4) = *(byte *)(param1 + 4) & 0xfe;
  return;
}


int frontend_control_func0B(int param1) { //801753F8
  return (int)*(short *)(param1 + 0xc);
}


void frontend_control_func0C(int param1,undefined2 param2) { //80175400
  *(undefined2 *)(param1 + 0xc) = param2;
  *(undefined *)(param1 + 6) = 2;
  return;
}


byte frontend_control_func0D(int param1) { //80175414
  return *(byte *)(param1 + 4) & 0x10;
}


/* Library Function - Single Match
    dll_46_func0E
   
   Library: KioskDefault 0 0 */

void frontend_control_func0E(int param1,int param2) { //80175420
  if (param2 != 0) {
    *(byte *)(param1 + 4) = *(byte *)(param1 + 4) & 0xdf;
    return;
  }
  *(byte *)(param1 + 4) = *(byte *)(param1 + 4) | 0x20;
  return;
}

