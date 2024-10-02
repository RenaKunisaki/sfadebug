
/* Library Function - Single Match
    GameUI_initialise
   
   Library: KioskDefault 0 0 */

void GameUI_initialise(undefined4 param) { //8016CDC8
  uint uVar1;
  Texture *pTVar2;
  int iVar3;
  
  DAT_8039967c = 0xff;
  DAT_8039967e = 0xffff;
  DAT_80399658 = 0xffff;
  DAT_8039965c = 0;
  DAT_803996ec = 0xffff;
  DAT_803996f4 = 0xffff;
  uVar1 = getScreenResolution();
  DAT_8039960c = (uVar1 & 0xffff) - 0x140;
  DAT_80399608 = ((int)uVar1 >> 0x10) + -0xf0;
  for (iVar3 = 0; iVar3 < 0x5a; iVar3 = iVar3 + 1) {
    pTVar2 = textureLoadAsset((int)(short)(&DAT_80304f7c)[iVar3]);
    (&PTR_Texture_8038a6e8)[iVar3] = (undefined *)pTVar2;
    pTVar2 = textureLoadAsset((int)(short)(&DAT_80304f7c)[iVar3]);
    (&PTR_Texture_8038a850)[iVar3 * 6] = (undefined *)pTVar2;
    (&DAT_8038a854)[iVar3 * 6] = 0;
    (&DAT_8038a858)[iVar3 * 0xc] = 0;
    (&DAT_8038a85a)[iVar3 * 0xc] = 0;
    (&DAT_8038a85c)[iVar3 * 6] = 0;
  }
  PTR_Texture_80399654 = (undefined *)textureLoadAsset(0x500);
  *(undefined2 *)((int)PTR_Texture_80399654 + 0x14) = 0x28;
  DAT_803996fc = 0x80000;
  DAT_80399704 = 0;
  PTR_Texture_8039970c = (undefined *)textureLoadAsset(0x3a7);
  PTR_Texture_803996d0 = (undefined *)textureLoadAsset(0x274);
  *(undefined2 *)((int)PTR_Texture_803996d0 + 0x14) = 0x28;
  FUN_80172ab4(&DAT_8038a160);
  fontLoad(7);
  fontLoad(8);
  DAT_8039968e = 0;
  DAT_80399692 = 0;
  return;
}


/* Library Function - Single Match
    GameUI_release
   
   Library: KioskDefault 0 0 */

void GameUI_release(void) { //8016D07C
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x5a; iVar1 = iVar1 + 1) {
    if ((&PTR_Texture_8038a6e8)[iVar1] != (undefined *)0x0) {
      texFreeTexture((Texture *)(&PTR_Texture_8038a6e8)[iVar1]);
    }
  }
  waterfx_release();
  FUN_801711ec();
  texFreeTexture((Texture *)PTR_Texture_8039970c);
  texFreeTexture((Texture *)PTR_Texture_80399654);
  if (PTR_Texture_803996d0 != (undefined *)0x0) {
    texFreeTexture((Texture *)PTR_Texture_803996d0);
  }
  return;
}


void GameUI_func12(undefined param1) { //8016D114
  DAT_80399668 = param1;
  return;
}


void GameUI_func16(undefined param1) { //8016D120
  DAT_80397342 = param1;
  return;
}


/* Library Function - Single Match
    GameUI_frameStart
   
   Library: KioskDefault 0 0 */

int GameUI_frameStart(void) { //8016D128
  ObjDef *pOVar1;
  ObjInstance *pOVar2;
  Model *pMVar3;
  short sVar4;
  int iVar5;
  
  if (!commonObjsLoaded) {
    sVar4 = 0;
    for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
      pOVar1 = objAlloc(0x20,CommandMenu);
      pOVar2 = objInstantiateCharacter(pOVar1,4,-1,-1,(ObjInstance *)0x0);
      commandMenuObjs[iVar5] = pOVar2;
      (commandMenuObjs[iVar5]->pos).pos.x = 0.0;
      (commandMenuObjs[iVar5]->pos).pos.y = 35.0;
      (commandMenuObjs[iVar5]->pos).pos.z = -150.0;
      (commandMenuObjs[iVar5]->pos).rotation.x = sVar4;
      pMVar3 = objGetModelInstance(commandMenuObjs[iVar5]);
      ModelInstance_setField30((ModelInstance *)pMVar3,commandMenuFn_80170cd8);
      pOVar1 = objAlloc(0x20,CommandMenu_065F);
      pOVar2 = objInstantiateCharacter(pOVar1,4,-1,-1,(ObjInstance *)0x0);
      commandMenuObjs2[iVar5] = pOVar2;
      (commandMenuObjs2[iVar5]->pos).pos.x = 0.0;
      (commandMenuObjs2[iVar5]->pos).pos.y = 35.0;
      (commandMenuObjs2[iVar5]->pos).pos.z = -150.0;
      (commandMenuObjs2[iVar5]->pos).rotation.x = sVar4;
      pMVar3 = objGetModelInstance(commandMenuObjs2[iVar5]);
      ModelInstance_setField30((ModelInstance *)pMVar3,commandMenuFn_80170b84);
      sVar4 = sVar4 + 0x5555;
    }
    commonObjsLoaded = true;
  }
  commandMenuRun();
  commandMenuFn_8016df44();
  if (bShowCommandMenu != false) {
    commandMenuFn_8016ec74();
  }
  return 0;
}


/* Library Function - Single Match
    GameUI_frameEnd
   
   Library: KioskDefault 0 0 */

void GameUI_frameEnd(undefined4 param_1,undefined4 param_2,undefined4 param3,undefined4 param4,
                     char *param5,BOOL_ param6) { //8016D2F0
  ObjInstance *pOVar1;
  ObjInstance *pOVar2;
  int iVar3;
  bool bVar7;
  N64Button32 NVar4;
  N64Button NVar6;
  s8 sVar8;
  uint uVar5;
  uint extraout_r4;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  byte bVar12;
  char cVar13;
  short sVar14;
  byte bVar15;
  short sVar16;
  char unaff_r31;
  undefined8 uVar17;
  
  pOVar1 = Object_objGetMain();
  pOVar2 = Object_getSidekicksLoaded();
  iVar3 = isCamRotZdisabled();
  if (iVar3 != 0) {
    return;
  }
  if (DAT_80399a74 != '\0') {
    return;
  }
  bVar7 = checkSomeDebugFlags_8017c4f8();
  if (bVar7) {
    return;
  }
  iVar3 = isModelAnimDisabled();
  if (iVar3 != 0) {
    return;
  }
                    /* {@symbol 80153978} */
  iVar3 = (**(code **)(*(int *)pDll_ObjSeq + 0x10))();
  if (iVar3 == 0x54) {
    return;
  }
  if (pOVar1 == (ObjInstance *)0x0) {
    return;
  }
  NVar4 = n64GetEnabledButtonsPressed(0);
  DAT_80399670 = NVar4 & 0xffff;
  NVar6 = n64GetEnabledButtonsHeld(0);
  DAT_80399678 = (uint)NVar6;
  sVar8 = getCstickX(0);
  commandMenuFn_8016f7fc();
  if ((pOVar1->flags_0xb0 & SeqActive) == 0) {
    uVar9 = extraout_r4;
    if (DAT_80399668 != '\0') {
      uVar9 = (uint)DAT_80399668;
      n64DisableButtons(0,(short)DAT_80399668);
      DAT_80399670 = DAT_80399670 & ~(int)DAT_80399668;
      DAT_80399678 = DAT_80399678 & ~(int)DAT_80399668;
    }
  }
  else {
    uVar9 = 7;
    n64DisableButtons(0,N64_BUTTON_C_RIGHT|N64_BUTTON_C_LEFT|N64_BUTTON_C_DOWN);
    DAT_80399670 = DAT_80399670 &
                   ~(N64_BUTTON_C_RIGHT|N64_BUTTON_C_LEFT|N64_BUTTON_C_DOWN|N64_BUTTON_Z);
    DAT_80399678 = DAT_80399678 & 0xffffdff8;
  }
  if (DAT_80399669 == '\0') {
    DAT_80399670 = DAT_80399670 | DAT_80399674;
    if (((pOVar1->flags_0xb0 & SeqActive) != 0) || (DAT_80399668 != '\0')) {
      DAT_80399670 = DAT_80399670 | N64_BUTTON_B;
    }
  }
  else {
    DAT_80399670 = DAT_80399674;
  }
  sVar16 = DAT_80399632 - DAT_80399634;
  uVar5 = 0x8000;
  if (0x8000 < sVar16) {
    sVar16 = sVar16 + 1;
  }
  if (sVar16 < -0x8000) {
    sVar16 = sVar16 + -1;
  }
  sVar14 = (short)sVar8;
  if (((((DAT_80399670 & N64_BUTTON_C_DOWN) != 0) && (pOVar2 != (ObjInstance *)0x0)) &&
      (DAT_80399708 != 2)) && (uVar5 = FUN_801714b4(), uVar5 != 0)) {
    uVar10 = 1;
    iVar3 = FUN_80171300((undefined **)PTR_PTR_DAT_80304f50,'\x01');
    uVar17 = CONCAT44(iVar3,uVar10);
    if (iVar3 != 0) {
      uVar10 = 0;
      uVar11 = 4;
      n64DisableButtons(0,N64_BUTTON_C_DOWN);
      DAT_80399632 = 0;
      DAT_80399634 = 0;
      DAT_80399709 = 2;
      DAT_8039965d = '\x02';
      DAT_8039965e = 2;
      uVar17 = CONCAT44(uVar10,uVar11);
    }
    goto LAB_8016d8d0;
  }
  if ((((DAT_80399670 & N64_BUTTON_C_RIGHT) != 0) && (DAT_80399708 != 3)) &&
     (uVar5 = FUN_801714b4(), uVar5 != 0)) {
    uVar10 = 0;
    iVar3 = FUN_80171300((undefined **)PTR_PTR_DAT_80304f30,'\0');
    uVar17 = CONCAT44(iVar3,uVar10);
    if (iVar3 != 0) {
      uVar10 = 0;
      uVar11 = 1;
      n64DisableButtons(0,N64_BUTTON_C_RIGHT);
      DAT_80399632 = -0x5556;
      DAT_80399634 = -0x5556;
      DAT_80399709 = 3;
      DAT_8039965d = '\0';
      DAT_8039965e = 0;
      uVar17 = CONCAT44(uVar10,uVar11);
    }
    goto LAB_8016d8d0;
  }
  if ((((DAT_80399670 & N64_BUTTON_C_LEFT) != 0) && (DAT_80399708 != 4)) &&
     (uVar5 = FUN_801714b4(), uVar5 != 0)) {
    uVar10 = 0;
    iVar3 = FUN_80171300((undefined **)PTR_PTR_DAT_80304f40,'\0');
    uVar17 = CONCAT44(iVar3,uVar10);
    if (iVar3 != 0) {
      uVar10 = 0;
      uVar11 = 2;
      n64DisableButtons(0,N64_BUTTON_C_LEFT);
      DAT_80399632 = 0x5555;
      DAT_80399634 = 0x5555;
      DAT_80399709 = 4;
      DAT_8039965d = '\x01';
      DAT_8039965e = 1;
      uVar17 = CONCAT44(uVar10,uVar11);
    }
    goto LAB_8016d8d0;
  }
  if (sVar8 < 0) {
    iVar3 = -(int)sVar14;
  }
  else {
    iVar3 = (int)(short)sVar8;
  }
  if (0xe < iVar3) {
    if (DAT_80399624 < 0) {
      iVar3 = -(int)DAT_80399624;
    }
    else {
      iVar3 = (int)DAT_80399624;
    }
    if ((iVar3 < 0xf) && (DAT_80399629 == '\0')) {
      if (sVar16 < 0) {
        iVar3 = -(int)sVar16;
      }
      else {
        iVar3 = (int)sVar16;
      }
      if (iVar3 < 10000) {
        cVar13 = '\x01';
        bVar7 = false;
        bVar12 = 0;
        DAT_80399630 = 0xffff;
        bVar15 = DAT_80399708;
        if (sVar14 < 0) {
          cVar13 = -1;
          DAT_80399630 = 1;
        }
        while( true ) {
          uVar17 = CONCAT44(uVar5,uVar9);
          if ((bVar7) || (uVar17 = CONCAT44(uVar5,uVar9), 3 < bVar12)) break;
          bVar15 = bVar15 + cVar13;
          if (4 < bVar15) {
            bVar15 = 2;
          }
          if (bVar15 < 2) {
            bVar15 = 4;
          }
          if (bVar15 == 3) {
            DAT_80399634 = -0x5556;
            unaff_r31 = '\0';
          }
          else if (bVar15 < 3) {
            if (1 < bVar15) {
              DAT_80399634 = 0;
              unaff_r31 = '\x02';
            }
          }
          else if (bVar15 < 5) {
            DAT_80399634 = 0x5555;
            unaff_r31 = '\x01';
          }
          uVar5 = countLeadingZeros(2 - unaff_r31);
          uVar9 = uVar5 >> 5 & 0xff;
          iVar3 = FUN_80171300((undefined **)(&PTR_PTR_DAT_80304f30)[unaff_r31 * 4],
                               (char)(uVar5 >> 5));
          if (iVar3 == 0) {
            bVar12 = bVar12 + 1;
            uVar5 = 0;
          }
          else {
            uVar5 = (uint)bVar15;
            if (uVar5 != (int)(char)DAT_80399708) {
              DAT_8039965d = unaff_r31;
              DAT_80399709 = bVar15;
            }
            bVar7 = true;
          }
        }
        goto LAB_8016d8d0;
      }
    }
  }
                    /* {@symbol 80153978} */
  uVar17 = (**(code **)(*(int *)pDll_ObjSeq + 0x10))();
  if ((int)((ulonglong)uVar17 >> 0x20) == 0x5c) {
    uVar17 = FUN_801714e4();
    goto LAB_8016d8d0;
  }
  if (DAT_80399709 == 0) goto LAB_8016d8d0;
  if (DAT_80399709 == 3) {
    param3 = 0x7f;
    param4 = 0x40;
    param5 = "commandmenu.c";
    param6 = 0x6fa;
    audioStartSfx((int **)0x0,0x259,0x7f,0x40,"commandmenu.c",0x6fa);
  }
  else if ((char)DAT_80399709 < '\x03') {
    if ((char)DAT_80399709 < '\x02') {
LAB_8016d884:
      param3 = 0x7f;
      param4 = 0x40;
      param5 = "commandmenu.c";
      param6 = 0x703;
      audioStartSfx((int **)0x0,0x25e,0x7f,0x40,"commandmenu.c",0x703);
    }
    else {
      param3 = 0x7f;
      param4 = 0x40;
      param5 = "commandmenu.c";
      param6 = 0x6fd;
      audioStartSfx((int **)0x0,0x25e,0x7f,0x40,"commandmenu.c",0x6fd);
    }
  }
  else {
    if ('\x04' < (char)DAT_80399709) goto LAB_8016d884;
    param3 = 0x7f;
    param4 = 0x40;
    param5 = "commandmenu.c";
    param6 = 0x700;
    audioStartSfx((int **)0x0,0x25e,0x7f,0x40,"commandmenu.c",0x700);
  }
  uVar17 = FUN_801714f0();
  DAT_80304f54 = 0;
  DAT_80399708 = DAT_80399709;
  DAT_80399670 = 0;
  DAT_80399680 = 0;
  DAT_80399709 = 0;
LAB_8016d8d0:
  DAT_80399624 = sVar14;
  commandMenuFn_80171f08((int)((ulonglong)uVar17 >> 0x20),(int)uVar17,param3,param4,param5,param6);
  cMenuUpdateAnims();
  FUN_80171a00();
  DAT_8039966c = DAT_8039966c + 1;
  if (2 < DAT_8039966c) {
    DAT_8039966c = 2;
  }
  sVar16 = DAT_8039732e;
  if ((DAT_80399628 == '\0') && (DAT_80399709 == 0)) {
                    /* {@symbol 801553b4} */
    sVar16 = (**(code **)(*(int *)pDll_ObjSeq + 100))();
  }
  DAT_8039732e = 0xffff;
  bVar7 = false;
  if (DAT_80399686 < 0) {
    iVar3 = FUN_801719b8();
    if (iVar3 != 0) {
      DAT_80397336 = 0x140;
      DAT_80397334 = 0x154;
    }
  }
  else {
    DAT_80397334 = DAT_8039968a;
    DAT_80397336 = DAT_80399688;
    bVar7 = true;
    sVar16 = DAT_80399686;
  }
  DAT_80399686 = 0xffff;
  if ((((DAT_80399678 & 0x2000) == 0) && (!bVar7)) || (sVar16 < 0)) {
    FUN_801719e8();
    iVar3 = FUN_801719b8();
    if ((iVar3 != 0) && (DAT_803044d8 != (void *)0x0)) {
      mm_free(DAT_803044d8);
      DAT_803044d8 = (void *)0x0;
      DAT_80397338 = -1;
    }
  }
  else {
    if ((sVar16 != DAT_80397338) && (DAT_80397338 = sVar16, DAT_803044d8 != (void *)0x0)) {
      mm_free(DAT_803044d8);
      DAT_803044d8 = (void *)0x0;
    }
    FUN_801719f4();
  }
  n64DisableButtons(0,N64_BUTTON_C_RIGHT|N64_BUTTON_C_LEFT|N64_BUTTON_C_DOWN);
  DAT_80399668 = 0;
  return;
}


/* Library Function - Single Match
    GameUI_render
   
   Library: KioskDefault 0 0 */

void GameUI_render(undefined *this) { //8016DA40
  ObjInstance *pOVar1;
  bool bVar2;
  uint **in_r4;
  undefined4 *in_r5;
  int local_18;
  int local_14;
  
  pOVar1 = Object_objGetMain();
  FUN_80171988();
  if (pOVar1 != (ObjInstance *)0x0) {
    bVar2 = FUN_801a8538((int)pOVar1,&local_14,&local_18);
    if (bVar2) {
      textureAnimFn_80053f2c((int)PTR_Texture_80399654,&DAT_803996fc,&DAT_80399704);
      drawTexture((Texture *)PTR_Texture_80399654,local_14 + -0x10,local_18 + -0x10,0x96,0x100);
    }
    FUN_80172308((F3DEXcommand *)this,in_r4,in_r5);
  }
  FUN_80171988();
  if (pOVar1 != (ObjInstance *)0x0) {
    aButtonFn_80171670((F3DEXcommand *)this,in_r4,in_r5);
    infoTextFn_80171bfc((F3DEXcommand *)this,in_r4,in_r5);
    FUN_8016e0c0((F3DEXcommand *)this,in_r4,in_r5);
    FUN_8016fc00((Gfx *)this,in_r4,in_r5);
  }
  if (bShowCommandMenu != false) {
    e3MenuFn_8016edfc((Gfx *)this,in_r4,in_r5);
  }
  FUN_8016f920((Gfx *)this,in_r4,in_r5);
  gxResetScissor((Gfx *)this);
  return;
}


undefined4 GameUI_func09(void) { //8016DB64
  if (-1 < DAT_80399658) {
    return 1;
  }
  return 0;
}


undefined4 GameUI_func0A(int param1) { //8016DB80
  if (param1 == DAT_80399658) {
    DAT_8039965c = 0;
    return 1;
  }
  return 0;
}


/* Library Function - Single Match
    GameUI_func0B
   
   Library: KioskDefault 0 0 */

undefined4 GameUI_func0B(int param1,int param2) { //8016DBA4
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (param2 <= iVar1) {
      return 0xffffffff;
    }
    if ((int)DAT_80399658 == *(int *)(param1 + iVar1 * 4)) break;
    iVar1 = iVar1 + 1;
  }
  DAT_8039965c = 0;
  return *(undefined4 *)(param1 + iVar1 * 4);
}


int GameUI_func0C(void) { //8016DBF8
  return (int)DAT_80399708;
}


int GameUI_func0D(void) { //8016DC04
  return (int)DAT_8039965a;
}


/* Library Function - Single Match
    GameUI_func08
   
   Library: KioskDefault 0 0 */

void GameUI_func08(double param1,int param2,int param3,byte param4,uint param5) { //8016DC0C
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  Camera *pCVar5;
  ObjInstance **ppOVar6;
  uint uVar7;
  AButtonInteraction *pAVar8;
  int iVar9;
  ObjInstance *obj;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  double dVar13;
  int local_6c;
  int local_68;
  float local_64;
  float local_60;
  float local_5c;
  
  _savefpr_26();
  Camera_setPlayerNo(0);
  pCVar5 = getCurCamera();
  dVar13 = (double)(float)(param1 * param1);
  ppOVar6 = Object_getObjects(&local_6c,&local_68);
  iVar9 = 0;
  for (iVar12 = local_6c; iVar12 < local_68; iVar12 = iVar12 + 1) {
    obj = ppOVar6[iVar12];
    pAVar8 = obj->data->aButtonInteraction;
    if (pAVar8 != (AButtonInteraction *)0x0) {
      if (obj->newOpacity == 0xff) {
        if (((obj->flags_0xaf & ModelDisableFlag08) == 0) && ((pAVar8->field13_0x10 & param4) != 0))
        {
          if ((iVar9 < param3) &&
             (((param5 & 1) != 0 &&
              (objMultPosByMtx(obj,&local_5c,&local_60,&local_64),
              fVar1 = local_5c - (pCVar5->pos).x, fVar2 = local_60 - (pCVar5->pos).y,
              fVar3 = local_64 - (pCVar5->pos).z,
              (double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2) < dVar13)))) {
            uVar7 = getAngle();
            iVar11 = (int)(pCVar5->rot).x - (0x4000 - (uVar7 & 0xffff) & 0xffff);
            if (0x8000 < iVar11) {
              iVar11 = iVar11 + -0xffff;
            }
            if (iVar11 < -0x8000) {
              iVar11 = iVar11 + 0xffff;
            }
            if ((iVar11 < -10000) && (-22000 < iVar11)) {
              *(ObjInstance **)(param2 + iVar9 * 4) = obj;
              iVar9 = iVar9 + 1;
            }
          }
        }
      }
    }
  }
  if (0 < iVar9) {
    do {
      bVar4 = true;
      for (iVar12 = 0; iVar12 < iVar9 + -1; iVar12 = iVar12 + 1) {
        if (*(int *)(param2 + iVar12 * 4) < *(int *)(param2 + (iVar12 + 1) * 4)) {
          uVar10 = *(undefined4 *)(param2 + iVar12 * 4);
          *(undefined4 *)(param2 + iVar12 * 4) = *(undefined4 *)(param2 + (iVar12 + 1) * 4);
          *(undefined4 *)(param2 + (iVar12 + 1) * 4) = uVar10;
          bVar4 = false;
        }
      }
    } while (!bVar4);
  }
  _restfpr_26();
  return;
}


/* Library Function - Single Match
    GameUI_func06
   
   Library: KioskDefault 0 0 */

void GameUI_func06(void) { //8016DE18
  int iVar1;
  
  for (iVar1 = 0; (&PTR_PTR_DAT_80304f30)[iVar1 * 4] != (undefined *)0x0; iVar1 = iVar1 + 1) {
    (&DAT_80304f34)[iVar1 * 8] = 0;
  }
  DAT_80399658 = 0xffff;
  DAT_8039965c = 0;
  return;
}


void GameUI_func07(void) { //8016DE7C
  DAT_803996bc = 1;
  return;
}


void GameUI_func0F(undefined2 param1,undefined2 param2,undefined2 param3) { //8016DE88
  DAT_80399686 = param1;
  DAT_80399688 = param2;
  DAT_8039968a = param3;
  return;
}


/* Library Function - Single Match
    GameUI_func10
   
   Library: KioskDefault 0 0 */

void GameUI_func10(undefined2 param1,undefined2 param2,undefined2 param3) { //8016DEA4
  if (DAT_80399648 == 0) {
    DAT_803996f8 = 0x40000;
    DAT_80399700 = 0;
                    /* {@symbol 8011de8c} */
    DAT_80399648 = (**(code **)((int)*pDll_subtitles + 0x14))(param1);
    DAT_80399644 = 0;
    DAT_8039963c = 1;
    DAT_8039963e = DAT_8039733c;
    DAT_8039733e = param3;
    DAT_80397340 = param2;
  }
  return;
}


void GameUI_func11(void) { //8016DF38
  DAT_8039963c = 0;
  return;
}


void commandMenuFn_8016df44(void) { //8016DF44
  if (DAT_8039963c == '\0') {
    DAT_80399642 = DAT_80399642 + (ushort)framesThisStep * -8;
    if (DAT_80399642 < 0) {
      DAT_80399642 = 0;
    }
    if (DAT_80399642 < DAT_80399640) {
      DAT_80399640 = DAT_80399642;
    }
  }
  else {
    DAT_80399640 = DAT_80399640 + (ushort)framesThisStep * 8;
    if (0xff < DAT_80399640) {
      DAT_80399640 = 0xff;
    }
    DAT_80399642 = DAT_80399642 + (ushort)framesThisStep * 8;
    if (0xff < DAT_80399642) {
      DAT_80399642 = 0xff;
    }
  }
  if (DAT_80399640 == 0) {
    if (DAT_80399648 != (byte *)0x0) {
      mm_free(DAT_80399648);
      DAT_80399648 = (byte *)0x0;
    }
  }
  else {
    textureAnimFn_80053f2c((int)PTR_Texture_803996d0,&DAT_803996f8,&DAT_80399700);
    if ((DAT_80399670 & 0x8000) != 0) {
      DAT_80399644 = DAT_80399644 + 3;
      audioStartSfx((int **)0x0,0x15d,0x7f,0x40,"commandmenu.c",0x86c);
      if (DAT_80399644 < (short)(ushort)*DAT_80399648) {
        n64DisableButtons(0,N64_BUTTON_A);
        disableButtons(0,PAD_BUTTON_A);
      }
      else {
        DAT_80399644 = DAT_80399644 + -3;
        DAT_8039963c = '\0';
      }
    }
  }
  return;
}


void commandMenuRun(void) { //8016E230
  bool bVar1;
  bool bVar2;
  int iVar3;
  ObjInstance *param1;
  N64Button32 NVar4;
  u16 uVar6;
  int iVar5;
  s8 sVar7;
  undefined *param2;
  short sVar8;
  uint param4;
  ushort uVar9;
  
  param1 = Object_objGetMain();
  if (param1 == (ObjInstance *)0x0) {
    return;
  }
  if (DAT_80399a74 != '\0') {
    return;
  }
  if ((param1->flags_0xb0 & SeqActive) == 0) {
    if (DAT_80399668 != '\0') {
      n64DisableButtons(0,(short)DAT_80399668);
    }
  }
  else {
    n64DisableButtons(0,N64_BUTTON_C_RIGHT|N64_BUTTON_C_LEFT|N64_BUTTON_C_DOWN);
  }
  if (DAT_80399669 == '\0') {
    NVar4 = n64GetEnabledButtonsPressed(0);
    DAT_80399670 = NVar4 & 0xffff;
    uVar6 = getEnabledButtonsPressed(0);
    if (((param1->flags_0xb0 & SeqActive) != 0) || (DAT_80399668 != '\0')) {
      DAT_80399670 = DAT_80399670 | N64_BUTTON_B;
    }
  }
  else {
    DAT_80399670 = DAT_80399674;
    uVar6 = 0;
  }
  if (DAT_8039965c == '\x01') {
    audioStartSfx((int **)0x0,0x16c,0x7f,0x40,"commandmenu.c",0x8d3);
  }
  else if (('\0' < DAT_8039965c) && (DAT_8039965c < '\x03')) {
    audioStartSfx((int **)0x0,0x162,0x7f,0x40,"commandmenu.c",0x8d6);
  }
  DAT_80399658 = 0xffff;
  DAT_8039965c = 0;
  iVar3 = (int)DAT_8039965e;
  param2 = (&PTR_DAT_80304f38)[DAT_8039965e * 4];
  bVar1 = DAT_8039965e == '\x02';
  DAT_80399660 = (&DAT_80304f34)[iVar3 * 8];
  DAT_80399664 = FUN_80170db8((undefined **)(&PTR_PTR_DAT_80304f30)[DAT_8039965e * 4],bVar1);
  if (DAT_80399664 == 0) {
    DAT_80399708 = 0;
    FUN_801714e4();
    return;
  }
  if (DAT_80399664 <= DAT_80399660) {
    DAT_80399660 = 0;
  }
  DAT_8039732e = (&DAT_8038a568)[DAT_80399660];
  iVar5 = FUN_80171480();
  if (iVar5 == 0) {
    if ((uVar6 & 0x400) == 0) {
      if ((uVar6 & 0x800) != 0) {
        if (DAT_80399692 == 3) {
          objSendMsg((int)param1,(uint)DAT_80399698,0,(uint)DAT_80399690);
          DAT_80399658 = DAT_80399690;
          disableButtons(0,PAD_BUTTON_Y);
        }
        else if (DAT_80399692 == 2) {
          DAT_80399658 = DAT_80399690;
          disableButtons(0,PAD_BUTTON_Y);
        }
      }
    }
    else if (DAT_8039968e == 3) {
      objSendMsg((int)param1,(uint)DAT_80399694,0,(uint)DAT_8039968c);
      DAT_80399658 = DAT_8039968c;
      disableButtons(0,PAD_BUTTON_X);
    }
    else if (DAT_8039968e == 2) {
      DAT_80399658 = DAT_8039968c;
      disableButtons(0,PAD_BUTTON_X);
    }
    goto LAB_8016ea64;
  }
  sVar7 = getCstickY(0);
  sVar8 = (short)sVar7;
  if (((sVar7 < -9) && (-10 < DAT_80399626)) || (sVar7 < -0x3c)) {
    if (DAT_80399629 < '\0') {
      iVar5 = -(int)DAT_80399629;
    }
    else {
      iVar5 = (int)DAT_80399629;
    }
    if (((7 < iVar5) || (DAT_80399682 != '\0')) || (DAT_80399630 != 0)) goto LAB_8016e510;
    if (DAT_8039732a == '\0') {
      audioStartSfx((int **)0x0,0x25b,0x7f,0x40,"commandmenu.c",0x8fb);
    }
    DAT_80399680 = 1;
    if (DAT_80399629 != '\0') {
      DAT_80399682 = '\x01';
    }
  }
  else {
LAB_8016e510:
    if (((9 < sVar8) && (DAT_80399626 < 10)) || (0x3c < sVar8)) {
      if (DAT_80399629 < '\0') {
        iVar5 = -(int)DAT_80399629;
      }
      else {
        iVar5 = (int)DAT_80399629;
      }
      if (((iVar5 < 8) && (DAT_80399682 == '\0')) && (DAT_80399630 == 0)) {
        if (DAT_8039732a == '\0') {
          audioStartSfx((int **)0x0,0x25b,0x7f,0x40,"commandmenu.c",0x901);
        }
        DAT_80399680 = -1;
        if (DAT_80399629 != '\0') {
          DAT_80399682 = '\x01';
        }
      }
    }
  }
  if (0xff < DAT_80399680) {
    DAT_80399680 = 0xff;
  }
  if (DAT_80399680 < -0xff) {
    DAT_80399680 = -0xff;
  }
  if (DAT_8039967e != -1) {
    DAT_80399660 = DAT_8039967e;
  }
  DAT_80399626 = sVar8;
  if ((DAT_80399680 == 0) || (DAT_80399629 != '\0')) {
    if ((DAT_80399670 & N64_BUTTON_B) == 0) {
      if (((uVar6 & 0xd00) != 0) && (iVar5 = FUN_80171480(), iVar5 != 0)) {
        param4 = (&DAT_8038a468)[DAT_80399660];
        bVar2 = false;
        uVar9 = (ushort)param4;
        if ((uVar6 & 0x400) == 0) {
          if ((uVar6 & 0x800) != 0) {
            if ((DAT_80399692 == 0) || (DAT_80399690 != param4)) {
              DAT_803996a2 = (&DAT_8038a3e8)[DAT_80399660];
              DAT_80399690 = uVar9;
              if (bVar1) {
                if ((&DAT_8038a668)[DAT_80399660] != '\0') {
                  DAT_80399692 = 2;
                }
              }
              else {
                DAT_80399698 = param2;
                if (DAT_80399708 == '\x04') {
                  DAT_80399692 = 1;
                }
                else {
                  DAT_80399692 = 3;
                }
              }
            }
            else {
              bVar2 = true;
            }
          }
        }
        else if ((DAT_8039968e == 0) || (DAT_8039968c != param4)) {
          DAT_803996a0 = (&DAT_8038a3e8)[DAT_80399660];
          DAT_8039968c = uVar9;
          if (bVar1) {
            if ((&DAT_8038a668)[DAT_80399660] != '\0') {
              DAT_8039968e = 2;
            }
          }
          else {
            DAT_80399694 = param2;
            if (DAT_80399708 == '\x04') {
              DAT_8039968e = 1;
            }
            else {
              DAT_8039968e = 3;
            }
          }
        }
        else {
          bVar2 = true;
        }
        disableButtons(0,PAD_BUTTON_A|PAD_BUTTON_X|PAD_BUTTON_Y);
        if (bVar1) {
          if ((&DAT_8038a668)[DAT_80399660] == '\0') {
            DAT_80399658 = 0xffff;
            DAT_8039965c = 0;
            audioStartSfx((int **)0x0,0x1fc,0x7f,0x40,"commandmenu.c",0x992);
          }
          else {
            if (((uVar6 & 0x100) != 0) || (bVar2)) {
              FUN_801714e4();
              DAT_8039965c = 0;
              DAT_80399658 = uVar9;
            }
            audioStartSfx((int **)0x0,0x25c,0x7f,0x40,"commandmenu.c",0x98c);
          }
        }
        else {
          if (((uVar6 & 0x100) != 0) || (bVar2)) {
            objSendMsg((int)param1,(uint)param2,0,param4);
            DAT_8039965c = (&DAT_8038a628)[DAT_80399660];
            DAT_80399658 = uVar9;
            FUN_801714e4();
          }
          audioStartSfx((int **)0x0,0x25c,0x7f,0x40,"commandmenu.c",0x980);
        }
      }
    }
    else {
      audioStartSfx((int **)0x0,0x25a,0x7f,0x40,"commandmenu.c",0x92e);
      FUN_801714e4();
    }
  }
  else if (DAT_80399680 < 1) {
    DAT_80399680 = DAT_80399680 + 1;
    if (1 < DAT_80399664) {
      if ((DAT_80399664 == 2) && (DAT_80399660 == 0)) {
        DAT_80399629 = -100;
      }
      else {
        DAT_80399629 = -0x32;
      }
      DAT_8039732a = -3;
      DAT_80399682 = '\0';
      DAT_80399660 = DAT_80399660 + -1;
      if (DAT_80399660 < 0) {
        DAT_80399660 = (short)DAT_80399664 + -1;
      }
    }
  }
  else {
    DAT_80399680 = DAT_80399680 + -1;
    if (1 < DAT_80399664) {
      if ((DAT_80399664 == 2) && (DAT_80399660 == 1)) {
        DAT_80399629 = 'd';
      }
      else {
        DAT_80399629 = '2';
      }
      DAT_8039732a = '\x03';
      DAT_80399682 = '\0';
      DAT_80399660 = DAT_80399660 + 1;
      if (DAT_80399664 <= DAT_80399660) {
        DAT_80399660 = 0;
      }
    }
  }
LAB_8016ea64:
  FUN_80170198();
  iVar5 = FUN_801714b4();
  if (iVar5 == 0) {
    n64DisableButtons(0,N64_BUTTON_B|N64_BUTTON_A);
    disableButtons(0,PAD_BUTTON_A|PAD_BUTTON_B);
  }
  else {
    DAT_80399708 = '\0';
    DAT_8039966c = 0;
    DAT_80399680 = 0;
  }
  (&DAT_80304f34)[iVar3 * 8] = DAT_80399660;
  return;
}


void commandMenuFn_8016ec74(void) { //8016EC74
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = DAT_80399614;
  uVar1 = DAT_80399612;
  if (DAT_80399612 != 0) {
    if ((DAT_80399623 == '\0') || (0x7e < DAT_80399612)) {
      if (DAT_80399623 == '\0') {
        DAT_80399612 = DAT_80399612 + framesThisStep;
      }
    }
    else {
      DAT_80399612 = DAT_80399612 + framesThisStep;
    }
    if ((0x13 < DAT_80399612) && ((short)uVar1 < 0x14)) {
      audioStartSfx((int **)0x0,0x243,0x7f,0x40,"commandmenu.c",0xa3d);
    }
    if ((0xd8 < DAT_80399612) && ((short)uVar1 < 0xd9)) {
      audioStartSfx((int **)0x0,0x246,0x7f,0x40,"commandmenu.c",0xa3f);
    }
    if (0xff < DAT_80399612) {
      DAT_80399612 = 0;
    }
  }
  if ((DAT_80399614 != 0) && ((DAT_80399614 < 0x78 || (0x82 < DAT_80399614)))) {
    DAT_80399614 = DAT_80399614 + framesThisStep;
    if ((0x1d < DAT_80399614) && ((short)uVar2 < 0x1e)) {
      audioPlayStream((int)*(short *)&E3MenuStruct_ARRAY_80304c04[DAT_80399617].field_0x6,
                      audioStreamCb_80068d3c);
    }
    if (0xff < DAT_80399614) {
      DAT_80399614 = 0;
    }
  }
  return;
}


void commandMenuFn_8016f7fc(void) { //8016F7FC
  short sVar1;
  int iVar2;
  ObjInstance *pOVar3;
  
  sVar1 = DAT_80399610;
  iVar2 = FUN_801714b4();
  if ((iVar2 != 0) && ((DAT_80399670 & 8) != 0)) {
    pOVar3 = Object_objGetMain();
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0xc,pOVar3,0xffffffff);
  }
  if (DAT_80399610 != 0) {
    if ((DAT_80399610 < 0x7f) || (0x96 < DAT_80399610)) {
      DAT_80399610 = DAT_80399610 + (ushort)framesThisStep;
    }
    if ((0x13 < DAT_80399610) && (sVar1 < 0x14)) {
      audioStartSfx((int **)0x0,0x243,0x7f,0x40,"commandmenu.c",0xb24);
    }
    if ((0xd8 < DAT_80399610) && (sVar1 < 0xd9)) {
      audioStartSfx((int **)0x0,0x246,0x7f,0x40,"commandmenu.c",0xb26);
    }
    if (0xff < DAT_80399610) {
      DAT_80399610 = 0;
    }
  }
  return;
}


/* Library Function - Single Match
    commandMenuFn_80170b84
   
   Library: KioskDefault 0 0 */

void commandMenuFn_80170b84(int param_1,Model **param_2,int param_3) { //80170B84
  Shader *pSVar1;
  int iVar2;
  int local_14 [2];
  
  local_14[0] = -1;
  pSVar1 = modelGetShader(*param_2,param_3);
  if (pSVar1->numLayers != 1) {
                    
    OSPanic("commandmenu.c",0xdbf,s_Failed_assertion_shader_>numMate_80305094);
  }
  iVar2 = (byte)pSVar1->layer[0].field_0x5 - 1;
  if (iVar2 < 0) {
                    
    OSPanic("commandmenu.c",0xdc2,s_Failed_assertion_animGroup>_0_803050c4);
  }
  FUN_800a11d4();
  if (((iVar2 < 0) || (4 < iVar2)) || ((&DAT_8038a148)[iVar2] == 0)) {
    local_14[0] = (uint)local_14[0]._0_3_ << 8;
    gxAddTevStage_800a138c(local_14);
  }
  else {
    local_14[0] = CONCAT31(local_14[0]._0_3_,*(undefined *)(param_1 + 0x37));
    gxAddTevStageTexGen_800a190c((&DAT_8038a148)[iVar2],(Mtx43 *)0x0,0,local_14);
  }
  _gxSetupTexGens();
  GXSetBlendMode(1,4,5,5);
  GXSetZMode(false,GX_ALWAYS,false);
  GXSetZCompLoc(0);
  GXSetAlphaCompare(7,0,0,7,0);
  return;
}


/* Library Function - Single Match
    commandMenuFn_80170cd8
   
   Library: KioskDefault 0 0 */

void commandMenuFn_80170cd8(int param_1,Model **param_2,int param_3) { //80170CD8
  Shader *pSVar1;
  undefined4 local_c [2];
  
  local_c[0] = 0xffffffff;
  pSVar1 = modelGetShader(*param_2,param_3);
  if (pSVar1->numLayers != 1) {
                    
    OSPanic("commandmenu.c",0xdf0,s_Failed_assertion_shader_>numMate_80305094);
  }
  FUN_800a11d4();
  local_c[0] = CONCAT31(local_c[0]._0_3_,*(undefined *)(param_1 + 0x37));
  gxAddTevStageTexGen_800a190c((int)pSVar1->layer[0].texture,(Mtx43 *)0x0,0,local_c);
  _gxSetupTexGens();
  GXSetBlendMode(1,4,5,5);
  GXSetZMode(false,GX_ALWAYS,false);
  GXSetZCompLoc(0);
  GXSetAlphaCompare(7,0,0,7,0);
  return;
}


void commandMenuFn_80171f08
               (undefined4 param_1,undefined4 param_2,undefined4 param3,undefined4 param4,
               undefined4 param5,BOOL_ param6) { //80171F08
  float fVar1;
  ObjInstance *pOVar2;
  ObjInstance *this;
  ushort uVar4;
  int iVar3;
  ObjectFuncPtrs2 *pOVar5;
  byte bVar6;
  int local_48 [4];
  uint local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  
  pOVar2 = Object_objGetMain();
  this = Object_getSidekicksLoaded();
  local_48[0] = FUN_801a7aa8((int)pOVar2);
  local_2c = FUN_801a7acc(pOVar2);
  if (this == (ObjInstance *)0x0) {
    local_48[1] = 0;
    local_24 = 0;
  }
  else {
    pOVar5 = this->dll->ptrs2;
    local_48[1] = (*pOVar5[1].render)(this,pOVar5,param3,param4,param5,param6);
    local_24 = 8;
  }
  local_48[2] = FUN_801a7c24((int)pOVar2);
  uVar4 = FUN_801a7af0(pOVar2);
  local_28 = (uint)uVar4;
  local_38 = mainGetBit(0x66c);
  uVar4 = FUN_801a7da8((int)pOVar2);
  local_48[3] = (uint)uVar4;
  if ((DAT_80399670 & 0x2000) != 0) {
    if (DAT_803996b0 == 0.0) {
      audioStartSfx((int **)0x0,0x164,0x7f,0x40,"commandmenu.c",0x108d);
    }
  }
  if ((DAT_80399678 & 0x2000) == 0) {
                    /* {@symbol 80153f40} */
    iVar3 = (**(code **)(*(int *)pDll_ObjSeq + 0x3c))();
    if (iVar3 == 0) {
      if (DAT_80397342 != '\0') {
        iVar3 = FUN_80069024();
        if ((short)iVar3 == 0) goto LAB_80172040;
      }
      local_34 = DAT_8038a1ac;
      goto LAB_80172058;
    }
  }
LAB_80172040:
  local_34 = DAT_8038a1ac + 1;
LAB_80172058:
  if ((pOVar2->flags_0xb0 & SeqActive) == 0) {
    DAT_803996c0 = timeDelta * 8.5 + DAT_803996c0;
    if (255.0 < DAT_803996c0) {
      DAT_803996c0 = 255.0;
    }
  }
  else {
    DAT_803996c0 = -(timeDelta * 8.5 - DAT_803996c0);
    if (DAT_803996c0 < 0.0) {
      DAT_803996c0 = 0.0;
    }
  }
  local_30 = 0;
  if ((DAT_803996bc & 1) == 0) {
    for (bVar6 = 0; bVar6 < 10; bVar6 = bVar6 + 1) {
      fVar1 = (float)(&DAT_8038a1c0)[bVar6];
      (&DAT_8038a1c0)[bVar6] = (float)(&DAT_8038a1c0)[bVar6] - timeDelta;
      if (60.0 < fVar1) {
        if ((float)(&DAT_8038a1c0)[bVar6] <= 60.0) {
          if ((int)(&DAT_8038a170)[bVar6] < local_48[bVar6]) {
            if ((&DAT_803044fc)[(uint)bVar6 * 2] != -1) {
              audioStartSfx((int **)0x0,(&DAT_803044fc)[(uint)bVar6 * 2],0x7f,0x40,
                            "commandmenu.c",0x10c3);
            }
          }
          else if ((&DAT_803044fe)[(uint)bVar6 * 2] != -1) {
            audioStartSfx((int **)0x0,(&DAT_803044fe)[(uint)bVar6 * 2],0x7f,0x40,
                          "commandmenu.c",0x10c6);
          }
          (&DAT_8038a170)[bVar6] = local_48[bVar6];
        }
      }
      if (local_48[bVar6] != (&DAT_8038a198)[bVar6]) {
        (&DAT_8038a198)[bVar6] = local_48[bVar6];
        if ((float)(&DAT_8038a1c0)[bVar6] <= 60.0) {
          (&DAT_8038a1c0)[bVar6] = 90.0 - timeDelta;
        }
      }
      if ((float)(&DAT_8038a1c0)[bVar6] < -30.0) {
        (&DAT_8038a1c0)[bVar6] = -30.0;
      }
    }
  }
  else {
    DAT_803996bc = DAT_803996bc & 0xfe;
    for (bVar6 = 0; bVar6 < 10; bVar6 = bVar6 + 1) {
      (&DAT_8038a170)[bVar6] = local_48[bVar6];
      (&DAT_8038a198)[bVar6] = local_48[bVar6];
      (&DAT_8038a1c0)[bVar6] = -30.0;
    }
    DAT_803996b0 = 0.0;
  }
  return;
}


void GameUI_func13(int param1) { //80172A88
  if (param1 == -1) {
    DAT_80399674 = 0;
    DAT_80399669 = 0;
    return;
  }
  DAT_80399674 = param1;
  DAT_80399669 = 1;
  return;
}


/* Library Function - Single Match
    GameUI_qInfoShow
   
   Library: KioskDefault 0 0 */

void GameUI_qInfoShow(short param1,undefined4 param2,undefined2 param3) { //80172AD8
  undefined **ppuVar1;
  short *psVar2;
  
  ppuVar1 = &PTR_PTR_DAT_80304f30;
  printf("qInfoShow");
  DAT_8038a160 = (Texture *)0x0;
  do {
    if ((short *)*ppuVar1 == (short *)0x0) {
      if (DAT_8038a160 != (Texture *)0x0) {
        DAT_8038a168 = 0.0;
        DAT_8038a164 = param2;
        DAT_8038a16c = param3;
      }
      return;
    }
    for (psVar2 = (short *)*ppuVar1; *psVar2 != -1; psVar2 = psVar2 + 6) {
      if (*psVar2 == param1) {
        DAT_8038a160 = textureLoadAsset((int)psVar2[2]);
        break;
      }
    }
    ppuVar1 = (undefined **)((short **)ppuVar1 + 4);
  } while( true );
}


/* Library Function - Single Match
    GameUI_qInfoShowTex
   
   Library: KioskDefault 0 0 */

void GameUI_qInfoShowTex(short param1,undefined4 param2,undefined2 param3) { //80172BA4
  printf("qInfoShowTex");
  DAT_8038a160 = textureLoadAsset((int)param1);
  if (DAT_8038a160 != (Texture *)0x0) {
    DAT_8038a168 = 0.0;
    DAT_8038a164 = param2;
    DAT_8038a16c = param3;
  }
  return;
}


void GameUI_func0E(undefined param1) { //80172E8C
  DAT_80397343 = param1;
  return;
}


/* Library Function - Single Match
    GameUI_energyBarCreate
   
   Library: KioskDefault 0 0 */

void GameUI_energyBarCreate(int minEnergy,int maxEnergy,int param3,int param4,int param5) { //80172E94
  int *param1;
  Texture *pTVar1;
  
  if (maxEnergy <= minEnergy) {
                    
    OSPanic("commandmenu.c",0x1234,s_Failed_assertion_minenergy_<_max_8030512c);
  }
  if (DAT_803996c8 == (int *)0x0) {
    param1 = (int *)mmAlloc(0x54,GAME_COL,"cmdmenu : Bar");
    memclr(param1,0x54);
    *param1 = minEnergy;
    param1[1] = maxEnergy;
    pTVar1 = textureLoadAsset(param3);
    param1[6] = (int)pTVar1;
    param1[7] = 0;
    *(undefined2 *)(param1 + 8) = 0;
    *(undefined2 *)((int)param1 + 0x22) = 0;
    param1[9] = 0;
    pTVar1 = textureLoadAsset(param4);
    param1[0xc] = (int)pTVar1;
    param1[0xd] = 0;
    *(undefined2 *)(param1 + 0xe) = 0;
    *(undefined2 *)((int)param1 + 0x3a) = 0;
    param1[0xf] = 0;
    param1[2] = (uint)*(ushort *)(param1[6] + 10);
    param1[3] = (uint)*(ushort *)(param1[6] + 0xc);
    if (param5 == 0) {
      param5 = 1;
    }
    param1[0x13] = param5;
    DAT_803996c8 = param1;
    printf(" Width %i Length %i ",param1[2],param1[3]);
    param1[2] = param1[2] * param1[0x13];
    *(undefined *)(param1 + 5) = 0;
    param1[4] = (int)(float)((double)CONCAT44(0x43300000,param1[2]) - 4503599627370496.0);
    param1[0x12] = (int)1.0;
    if (param1[6] == 0) {
                    
      OSPanic("commandmenu.c",0x1262,s_Failed_assertion_enbar_>Fullbart_803051b4);
    }
    if (param1[0xc] == 0) {
                    
      OSPanic("commandmenu.c",0x1263,s_Failed_assertion_enbar_>Emptybar_803051e4);
    }
  }
  else {
    printf("WARNING: ENERGY BAR ALREADY CREATED and need killed ");
  }
  return;
}


/* Library Function - Single Match
    GameUI_energyBarFn18
   
   Library: KioskDefault 0 0 */

void GameUI_energyBarFn18(int param1) { //8017305C
  if (DAT_803996c8 == (int *)0x0) {
    printf(" WARNING: Energy bar not created ");
  }
  else {
    DAT_803996c8[4] =
         (int)(float)((double)CONCAT44(0x43300000,
                                       (int)((float)((double)CONCAT44(0x43300000,DAT_803996c8[2]) -
                                                    4503599627370496.0) *
                                            ((float)((double)CONCAT44(0x43300000,
                                                                      param1 - *DAT_803996c8 ^
                                                                      0x80000000) -
                                                    4503601774854144.0) /
                                            (float)((double)CONCAT44(0x43300000,
                                                                     DAT_803996c8[1] - *DAT_803996c8
                                                                     ^ 0x80000000) -
                                                   4503601774854144.0)))) - 4503599627370496.0);
  }
  return;
}


/* Library Function - Single Match
    GameUI_energyBarKill
   
   Library: KioskDefault 0 0 */

void GameUI_energyBarKill(void) { //80173318
  void *pvVar1;
  
  pvVar1 = DAT_803996c8;
  if (DAT_803996c8 == (void *)0x0) {
    printf(" WARNING : cmdmenu Energy bar alreadby freed ");
  }
  else {
    printf(" Killing Bar ");
    *(undefined *)((int)pvVar1 + 0x14) = 0;
    texFreeTexture(*(Texture **)((int)pvVar1 + 0x18));
    texFreeTexture(*(Texture **)((int)pvVar1 + 0x30));
    mm_free(DAT_803996c8);
    DAT_803996c8 = (void *)0x0;
  }
  return;
}


/* Library Function - Single Match
    GameUI_eneryBarFn1A
   
   Library: KioskDefault 0 0 */

void GameUI_eneryBarFn1A(void) { //80173394
  if (DAT_803996c8 == 0) {
    printf(" WARNING : cmdmenu Energy bar alreadby freed ");
  }
  else {
    *(byte *)(DAT_803996c8 + 0x50) = *(byte *)(DAT_803996c8 + 0x50) & 0x7f | 0x80;
  }
  return;
}


/* Library Function - Single Match
    GameUI_eneryBarFn1B
   
   Library: KioskDefault 0 0 */

void GameUI_eneryBarFn1B(double param1) { //801733E8
  if (DAT_803996c8 == 0) {
    printf(" WARNING : cmdmenu No energy bar present ");
  }
  else {
    *(float *)(DAT_803996c8 + 0x48) = (float)param1;
  }
  return;
}

