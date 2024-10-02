
/* Library Function - Single Match
    gxAddTevStage_800a138c
   
   Library: KioskDefault 0 0 */

void gxAddTevStage_800a138c(undefined4 *param1) { //800A138C
  undefined4 local_4;
  
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x104,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  GXSetTevDirect(DAT_80398ba8);
  local_4 = *param1;
  GXSetTevKColor(DAT_80398bc4,(byte *)&local_4);
  GXSetTevKAlphaSel(DAT_80398ba8,DAT_80398bcc);
  GXSetTevKColorSel(DAT_80398ba8,DAT_80398bc8);
  GXSetTevOrder(DAT_80398ba8,0xff,0xff,4);
  if (numTevStages == 0) {
    GXSetTevColorIn(DAT_80398ba8,0xf,0xf,0xf,0xe);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,6);
  }
  else {
    GXSetTevColorIn(DAT_80398ba8,0xf,0,0xe,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,0,6,7);
  }
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  DAT_80398ba8 = DAT_80398ba8 + 1;
  DAT_80398bc4 = DAT_80398bc4 + 1;
  DAT_80398bc8 = DAT_80398bc8 + 1;
  DAT_80398bcc = DAT_80398bcc + 1;
  numTevStages = numTevStages + 1;
  return;
}


/* Library Function - Single Match
    shaderTevStageColorFn_800a1504
   
   Library: KioskDefault 0 0 */

void shaderTevStageColorFn_800a1504(undefined4 *param1) { //800A1504
  undefined4 local_c [2];
  
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x139,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  GXSetTevDirect(DAT_80398ba8);
  local_c[0] = *param1;
  GXSetTevColor(1,(byte *)local_c);
  GXSetTevOrder(DAT_80398ba8,0xff,0xff,4);
  if (numTevStages == 0) {
                    
    OSPanic("shader.c",0x148,"Failed assertion 0");
  }
  GXSetTevColorIn(DAT_80398ba8,0,2,3,0xf);
  GXSetTevAlphaIn(DAT_80398ba8,7,7,7,0);
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  DAT_80398ba8 = DAT_80398ba8 + 1;
  DAT_80398bc4 = DAT_80398bc4 + 1;
  DAT_80398bc8 = DAT_80398bc8 + 1;
  DAT_80398bcc = DAT_80398bcc + 1;
  numTevStages = numTevStages + 1;
  return;
}


/* Library Function - Single Match
    gxAddTevStageWithColor
   
   Library: KioskDefault 0 0 */

void gxAddTevStageWithColor(undefined4 *param1) { //800A1650
  undefined4 local_c [2];
  
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x16e,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  GXSetTevDirect(DAT_80398ba8);
  local_c[0] = *param1;
  GXSetTevKColor(DAT_80398bc4,(byte *)local_c);
  GXSetTevKAlphaSel(DAT_80398ba8,DAT_80398bcc);
  GXSetTevOrder(DAT_80398ba8,0xff,0xff,4);
  if (numTevStages == 0) {
    GXSetTevColorIn(DAT_80398ba8,0xf,0xf,0xf,10);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,6);
  }
  else {
    GXSetTevColorIn(DAT_80398ba8,0xf,0,10,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,0,6,7);
  }
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  DAT_80398ba8 = DAT_80398ba8 + 1;
  DAT_80398bc4 = DAT_80398bc4 + 1;
  DAT_80398bc8 = DAT_80398bc8 + 1;
  DAT_80398bcc = DAT_80398bcc + 1;
  numTevStages = numTevStages + 1;
  return;
}


/* Library Function - Single Match
    gxAddTevStage
   
   Library: KioskDefault 0 0 */

void gxAddTevStage(void) { //800A17C4
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x1a4,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  if (7 < gxNumTexGens) {
                    
    OSPanic("shader.c",0x1a5,s_Failed_assertion_numTexGens<8_802f0a80);
  }
  GXSetTevDirect(DAT_80398ba8);
  GXSetTevOrder(DAT_80398ba8,0xff,0xff,4);
  if (numTevStages == 0) {
    GXSetTevColorIn(DAT_80398ba8,0xf,0xf,0xf,10);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,5);
  }
  else {
    GXSetTevColorIn(DAT_80398ba8,0xf,0,10,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,0,5,7);
  }
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  DAT_80398ba8 = DAT_80398ba8 + 1;
  numTevStages = numTevStages + 1;
  return;
}


/* Library Function - Single Match
    gxAddTevStageTexGen_800a190c
   
   Library: KioskDefault 0 0 */

void gxAddTevStageTexGen_800a190c(int param1,Mtx43 *param2,int param3,undefined4 *param4) { //800A190C
  undefined4 local_18 [3];
  
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x1e0,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  if (7 < gxNumTexGens) {
                    
    OSPanic("shader.c",0x1e1,s_Failed_assertion_numTexGens<8_802f0a80);
  }
  GXSetTevDirect(DAT_80398ba8);
  if (param2 == (Mtx43 *)0x0) {
    GXSetTexCoordGen(DAT_80398bb0,1,DAT_80398bc0,0x3c,0,0x7d);
  }
  else {
    GXLoadTexMtxImm(param2,DAT_80398bb8,0);
    GXSetTexCoordGen(DAT_80398bb0,1,DAT_80398bc0,0x3c,0,DAT_80398bb8);
    DAT_80398bb8 = DAT_80398bb8 + 3;
  }
  GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,0xff);
  local_18[0] = *param4;
  GXSetTevKColor(DAT_80398bc4,(byte *)local_18);
  GXSetTevKAlphaSel(DAT_80398ba8,DAT_80398bcc);
  GXSetTevKColorSel(DAT_80398ba8,DAT_80398bc8);
  if (param3 == 0) {
    GXSetTevColorIn(DAT_80398ba8,0xf,8,0xe,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,6,7);
  }
  else if (param3 == 8) {
    GXSetTevColorIn(DAT_80398ba8,0xf,8,4,6);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,6,7);
  }
  else {
    GXSetTevColorIn(DAT_80398ba8,8,0,1,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,0,7);
  }
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  FUN_800a3194(param1,DAT_80398bac);
  DAT_80398bc0 = DAT_80398bc0 + 1;
  DAT_80398bb0 = DAT_80398bb0 + 1;
  DAT_80398ba8 = DAT_80398ba8 + 1;
  DAT_80398bac = DAT_80398bac + 1;
  DAT_80398bc4 = DAT_80398bc4 + 1;
  DAT_80398bc8 = DAT_80398bc8 + 1;
  DAT_80398bcc = DAT_80398bcc + 1;
  numTevStages = numTevStages + 1;
  gxNumTexGens = gxNumTexGens + 1;
  return;
}


/* Library Function - Single Match
    gxAddTevStageTexGenColor
   
   Library: KioskDefault 0 0 */

void gxAddTevStageTexGenColor(int param1,Mtx43 *param2,int param3,undefined4 *param4) { //800A1B8C
  undefined4 local_18 [3];
  
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x23c,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  if (7 < gxNumTexGens) {
                    
    OSPanic("shader.c",0x23d,s_Failed_assertion_numTexGens<8_802f0a80);
  }
  GXSetTevDirect(DAT_80398ba8);
  if (param2 == (Mtx43 *)0x0) {
    GXSetTexCoordGen(DAT_80398bb0,1,DAT_80398bc0,0x3c,0,0x7d);
  }
  else {
    GXLoadTexMtxImm(param2,DAT_80398bb8,0);
    GXSetTexCoordGen(DAT_80398bb0,1,DAT_80398bc0,0x3c,0,DAT_80398bb8);
    DAT_80398bb8 = DAT_80398bb8 + 3;
  }
  local_18[0] = *param4;
  GXSetTevKColor(DAT_80398bc4,(byte *)local_18);
  GXSetTevKAlphaSel(DAT_80398ba8,DAT_80398bcc);
  if (param3 == 0) {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,4);
    GXSetTevColorIn(DAT_80398ba8,0xf,8,10,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,6,7);
  }
  else if (param3 == 8) {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,4);
    GXSetTevColorIn(DAT_80398ba8,0xf,8,10,6);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,6,7);
  }
  else {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,0xff);
    GXSetTevColorIn(DAT_80398ba8,8,0,1,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,0,7);
  }
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  FUN_800a3194(param1,DAT_80398bac);
  DAT_80398bc0 = DAT_80398bc0 + 1;
  DAT_80398bb0 = DAT_80398bb0 + 1;
  DAT_80398ba8 = DAT_80398ba8 + 1;
  DAT_80398bac = DAT_80398bac + 1;
  DAT_80398bc4 = DAT_80398bc4 + 1;
  DAT_80398bc8 = DAT_80398bc8 + 1;
  DAT_80398bcc = DAT_80398bcc + 1;
  numTevStages = numTevStages + 1;
  gxNumTexGens = gxNumTexGens + 1;
  return;
}


/* Library Function - Single Match
    shaderFn_800a1e28
   
   Library: KioskDefault 0 0 */

void shaderFn_800a1e28(int param1,Mtx43 *param2,int param3) { //800A1E28
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x29b,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  if (7 < gxNumTexGens) {
                    
    OSPanic("shader.c",0x29c,s_Failed_assertion_numTexGens<8_802f0a80);
  }
  GXSetTevDirect(DAT_80398ba8);
  if (param2 == (Mtx43 *)0x0) {
    GXSetTexCoordGen(DAT_80398bb0,1,DAT_80398bc0,0x3c,0,0x7d);
  }
  else {
    GXLoadTexMtxImm(param2,DAT_80398bb8,0);
    GXSetTexCoordGen(DAT_80398bb0,1,DAT_80398bc0,0x3c,0,DAT_80398bb8);
    DAT_80398bb8 = DAT_80398bb8 + 3;
  }
  if (param3 == 0) {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,4);
    GXSetTevColorIn(DAT_80398ba8,0xf,8,10,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,5,7);
  }
  else if (param3 == 8) {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,4);
    GXSetTevColorIn(DAT_80398ba8,0xf,8,10,6);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,5,7);
  }
  else if (param3 == 4) {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,0xff);
    GXSetTevColorIn(DAT_80398ba8,8,0xf,0xf,0);
    GXSetTevAlphaIn(DAT_80398ba8,4,7,7,0);
  }
  else if (param3 == 6) {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,0xff);
    GXSetTevColorIn(DAT_80398ba8,0xf,8,0,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,0,7);
  }
  else if (param3 == 9) {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,4);
    GXSetTevColorIn(DAT_80398ba8,0,8,0xb,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,0,7);
  }
  else {
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,0xff);
    GXSetTevColorIn(DAT_80398ba8,8,0,1,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,4,0,7);
  }
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  FUN_800a3194(param1,DAT_80398bac);
  DAT_80398bc0 = DAT_80398bc0 + 1;
  DAT_80398bb0 = DAT_80398bb0 + 1;
  DAT_80398ba8 = DAT_80398ba8 + 1;
  DAT_80398bac = DAT_80398bac + 1;
  numTevStages = numTevStages + 1;
  gxNumTexGens = gxNumTexGens + 1;
  return;
}


/* Library Function - Single Match
    shaderFn_800a2168
   
   Library: KioskDefault 0 0 */

void shaderFn_800a2168(int param1) { //800A2168
  undefined4 local_6c;
  Mtx43 MStack_68;
  Mtx43 MStack_38;
  
  if ((DAT_80396df8 & 4) == 0) {
    local_6c = DAT_80396dfc;
    GXSetTevColor(2,(byte *)&local_6c);
  }
  else {
    if (0xf < numTevStages) {
                    
      OSPanic("shader.c",0x318,s_Failed_assertion_numTevStages<16_802f0a08);
    }
    if (7 < gxNumTexGens) {
                    
      OSPanic("shader.c",0x319,s_Failed_assertion_numTexGens<8_802f0a80);
    }
    MTXScale(-0.3535000085830688,-0.3535000085830688,0.0,&MStack_68.m11);
    MTXTrans(0.5,0.5,1.0,&MStack_38.m11);
    MTXConcat(&MStack_38,&MStack_68,&MStack_68);
    GXLoadTexMtxImm(&MStack_68,DAT_80398bb8,0);
    GXSetTexCoordGen(DAT_80398bb0,1,1,0x1e,0,DAT_80398bb8);
    if (gxNumIndStages == '\0') {
      GXSetTevDirect(DAT_80398ba8);
    }
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,4);
    GXSetTevColorIn(DAT_80398ba8,8,0xf,0xf,10);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,7);
    GXSetTevColorOp(DAT_80398ba8,0,0,0,1,2);
    GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,2);
    FUN_800a3194(param1,DAT_80398bac);
    DAT_80398bb8 = DAT_80398bb8 + 3;
    DAT_80398ba8 = DAT_80398ba8 + 1;
    DAT_80398bb0 = DAT_80398bb0 + 1;
    DAT_80398bac = DAT_80398bac + 1;
    numTevStages = numTevStages + 1;
    gxNumTexGens = gxNumTexGens + 1;
  }
  return;
}


/* Library Function - Single Match
    shaderFn_800a2344
   
   Library: KioskDefault 0 0 */

void shaderFn_800a2344(int param1,char param2) { //800A2344
  undefined4 local_70;
  Mtx43 MStack_6c;
  Mtx43 MStack_3c;
  
  if ((DAT_80396df8 & 2) == 0) {
    local_70 = DAT_80396e00;
    GXSetTevColor(3,(byte *)&local_70);
  }
  else {
    if (0xf < numTevStages) {
                    
      OSPanic("shader.c",0x364,s_Failed_assertion_numTevStages<16_802f0a08);
    }
    if (8 < gxNumTexGens) {
                    
      OSPanic("shader.c",0x365,s_Failed_assertion_numTexGens<_8_802f0ae0);
    }
    if (gxNumIndStages == '\0') {
      GXSetTevDirect(DAT_80398ba8);
    }
    if (param2 == '\0') {
      MTXScale(-0.3535000085830688,-0.3535000085830688,0.0,&MStack_6c.m11);
      MTXTrans(0.5,0.5,1.0,&MStack_3c.m11);
      MTXConcat(&MStack_3c,&MStack_6c,&MStack_6c);
      GXLoadTexMtxImm(&MStack_6c,DAT_80398bb8,0);
      GXSetTexCoordGen(DAT_80398bb0,1,1,0x1e,0,DAT_80398bb8);
      GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,0xff);
      DAT_80398bb8 = DAT_80398bb8 + 3;
      DAT_80398bb0 = DAT_80398bb0 + 1;
      gxNumTexGens = gxNumTexGens + 1;
    }
    else {
      GXSetTevIndRepeat(DAT_80398ba8);
      GXSetTevOrder(DAT_80398ba8,DAT_80398bb0 - 1,DAT_80398bac,0xff);
    }
    GXSetTevColorIn(DAT_80398ba8,0xf,0xf,0xf,8);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,4);
    GXSetTevColorOp(DAT_80398ba8,0,0,0,1,3);
    GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,3);
    FUN_800a3194(param1,DAT_80398bac);
    DAT_80398ba8 = DAT_80398ba8 + 1;
    DAT_80398bac = DAT_80398bac + 1;
    numTevStages = numTevStages + 1;
  }
  return;
}


/* Library Function - Single Match
    shaderFn_800a2554
   
   Library: KioskDefault 0 0 */

void shaderFn_800a2554(void) { //800A2554
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x3df,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  GXSetTevDirect(DAT_80398ba8);
  GXSetTevOrder(DAT_80398ba8,0xff,0xff,4);
  GXSetTevColorIn(DAT_80398ba8,0xf,0,4,6);
  GXSetTevAlphaIn(DAT_80398ba8,7,7,7,7);
  GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
  GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  DAT_80398ba8 = DAT_80398ba8 + 1;
  numTevStages = numTevStages + 1;
  return;
}


/* Library Function - Single Match
    shaderFn_800a2634
   
   Library: KioskDefault 0 0 */

void shaderFn_800a2634(int param1,int param2,int param3) { //800A2634
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 auStack_28 [2];
  float local_20 [6];
  
  iVar4 = 3;
  puVar2 = (undefined4 *)&UNK_802cf4f8;
  puVar3 = auStack_28;
  do {
    uVar1 = puVar2[3];
    puVar3[2] = puVar2[2];
    puVar3[3] = uVar1;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + 2;
    puVar3 = puVar3 + 2;
  } while (iVar4 != 0);
  if ((DAT_80396df8 & 1) != 0) {
    if (0xe < numTevStages) {
                    
      OSPanic("shader.c",0x412,s_Failed_assertion_numTevStages<15_802f0b00);
    }
    if (6 < gxNumTexGens) {
                    
      OSPanic("shader.c",0x413,s_Failed_assertion_numTexGens<7_802f0b24);
    }
    GXSetIndTexMtx(1,local_20,'\0');
    GXSetIndTexOrder(DAT_80398bbc,DAT_80398bb0 + param2,DAT_80398bac);
    GXSetIndTexScale(DAT_80398bbc,*(uint *)(&DAT_802f09d8 + (param3 + -1) * 4),
                     *(uint *)(&DAT_802f09d8 + (param3 + -1) * 4));
    GXSetTexCoordGen(DAT_80398bb0,1,2,0x1e,0,0x7d);
    GXSetTexCoordGen(DAT_80398bb0 + 1,1,3,0x1e,0,0x7d);
    GXInitIndTexture(DAT_80398ba8,DAT_80398bbc,0,3,5,6,6,0,0,0);
    GXInitIndTexture(DAT_80398ba8 + 1,DAT_80398bbc,0,3,9,6,6,1,0,0);
    GXInitIndTexture(DAT_80398ba8 + 2,DAT_80398bbc,0,0,0,0,0,1,0,0);
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac + 1 | 0x100,0xff);
    GXSetTevOp(DAT_80398ba8,4);
    GXSetTevOrder(DAT_80398ba8 + 1,DAT_80398bb0 + 1,DAT_80398bac + 1 | 0x100,0xff);
    GXSetTevOp(DAT_80398ba8 + 1,4);
    FUN_800a3194(param1,DAT_80398bac);
    DAT_80398bbc = DAT_80398bbc + 1;
    DAT_80398bb0 = DAT_80398bb0 + 2;
    DAT_80398ba8 = DAT_80398ba8 + 2;
    DAT_80398bac = DAT_80398bac + 1;
    numTevStages = numTevStages + 2;
    gxNumIndStages = gxNumIndStages + '\x01';
    gxNumTexGens = gxNumTexGens + 2;
  }
  return;
}


/* Library Function - Single Match
    shaderFn_800a28c8
   
   Library: KioskDefault 0 0 */

void shaderFn_800a28c8(int param1,Mtx43 *param2,int param3,int param4,int param5) { //800A28C8
  uint param6;
  
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x455,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  if (7 < gxNumTexGens) {
                    
    OSPanic("shader.c",0x456,s_Failed_assertion_numTexGens<8_802f0a80);
  }
  GXSetTevDirect(DAT_80398ba8);
  GXLoadTexMtxImm(param2,DAT_80398bb8,0);
  GXSetTexCoordGen(DAT_80398bb0,0,0,0x3c,0,DAT_80398bb8);
  GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,param5);
  if (param3 == 0) {
    if (param4 == 2) {
      GXSetTevColorIn(DAT_80398ba8,0xf,4,8,0xf);
    }
    else if (param4 == 3) {
      GXSetTevColorIn(DAT_80398ba8,4,0xf,8,0xf);
    }
    else if (param4 == 1) {
      GXSetTevColorIn(DAT_80398ba8,0xf,0xf,8,4);
    }
    else if ((param5 == 0) || (param5 == 1)) {
      GXSetTevColorIn(DAT_80398ba8,0xf,10,8,4);
    }
    else {
      GXSetTevColorIn(DAT_80398ba8,0xf,0xb,8,4);
    }
    param6 = 2;
  }
  else {
    if (param4 == 2) {
      GXSetTevColorIn(DAT_80398ba8,0xf,6,8,0xf);
    }
    else if (param4 == 3) {
      GXSetTevColorIn(DAT_80398ba8,6,0xf,8,0xf);
    }
    else if (param4 == 1) {
      GXSetTevColorIn(DAT_80398ba8,0xf,0xf,8,6);
    }
    else if ((param5 == 0) || (param5 == 1)) {
      GXSetTevColorIn(DAT_80398ba8,0xf,10,8,6);
    }
    else {
      GXSetTevColorIn(DAT_80398ba8,0xf,0xb,8,6);
    }
    param6 = 3;
  }
  GXSetTevAlphaIn(DAT_80398ba8,7,7,7,7);
  if (param4 == 1) {
    GXSetTevColorOp(DAT_80398ba8,1,0,0,1,param6);
    GXSetTevAlphaOp(DAT_80398ba8,1,0,0,1,param6);
  }
  else {
    GXSetTevColorOp(DAT_80398ba8,0,0,0,1,param6);
    GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,param6);
  }
  FUN_800a3194(param1,DAT_80398bac);
  DAT_80398bb8 = DAT_80398bb8 + 3;
  DAT_80398bb0 = DAT_80398bb0 + 1;
  DAT_80398ba8 = DAT_80398ba8 + 1;
  DAT_80398bac = DAT_80398bac + 1;
  numTevStages = numTevStages + 1;
  gxNumTexGens = gxNumTexGens + 1;
  return;
}


/* Library Function - Single Match
    shaderFn_800a2bf0
   
   Library: KioskDefault 0 0 */

void shaderFn_800a2bf0(int param1,undefined4 param_2,undefined4 *param3,char param4) { //800A2BF0
  undefined4 local_10 [2];
  undefined4 *local_8;
  
  local_8 = &DAT_8036d060;
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x4d1,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  if (param1 == 0) {
    GXSetTevDirect(DAT_80398ba8);
    GXSetTevOrder(DAT_80398ba8,0xff,0xff,4);
    GXSetTevColorIn(DAT_80398ba8,0xf,0xf,0xf,10);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,6);
    GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
    GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
  }
  else {
    GXSetTexCoordGen(DAT_80398bb0,1,1,0x1e,0,0x7d);
    local_10[0] = *param3;
    GXSetTevColor(1,(byte *)local_10);
    GXSetTevDirect(DAT_80398ba8);
    GXSetTevOrder(DAT_80398ba8,DAT_80398bb0,DAT_80398bac,4);
    GXSetTevColorIn(DAT_80398ba8,0xf,8,2,10);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,5);
    GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
    GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
    FUN_800a3194(param1,DAT_80398bac);
    DAT_80398bc0 = DAT_80398bc0 + 1;
    DAT_80398bb0 = DAT_80398bb0 + 1;
    DAT_80398bac = DAT_80398bac + 1;
    gxNumTexGens = gxNumTexGens + '\x01';
  }
  numTevStages = numTevStages + 1;
  DAT_80398ba8 = DAT_80398ba8 + 1;
  if (param4 != '\0') {
    GXSetTevDirect(DAT_80398ba8);
    GXSetTevOrder(DAT_80398ba8,0xff,0xff,5);
    GXSetTevColorIn(DAT_80398ba8,0xf,0xb,10,0);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,7);
    GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
    GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
    DAT_80398ba8 = DAT_80398ba8 + 1;
    numTevStages = numTevStages + '\x01';
  }
  return;
}


/* Library Function - Single Match
    shaderFn_800a30a0
   
   Library: KioskDefault 0 0 */

void shaderFn_800a30a0(void) { //800A30A0
  if (0xf < numTevStages) {
                    
    OSPanic("shader.c",0x58b,s_Failed_assertion_numTevStages<16_802f0a08);
  }
  if (DAT_80398bff != '\0') {
    GXSetTevDirect(DAT_80398ba8);
    GXSetTevOrder(DAT_80398ba8,0xff,0xff,0xff);
    GXSetTevColorIn(DAT_80398ba8,0xf,0,4,0xf);
    GXSetTevAlphaIn(DAT_80398ba8,7,7,7,0);
    GXSetTevColorOp(DAT_80398ba8,0,0,0,1,0);
    GXSetTevAlphaOp(DAT_80398ba8,0,0,0,1,0);
    DAT_80398ba8 = DAT_80398ba8 + 1;
    numTevStages = numTevStages + 1;
  }
  return;
}


/* Library Function - Single Match
    shaderGetLayer
   
   Library: KioskDefault 0 0 */

ShaderLayer * shaderGetLayer(Shader *shader,int layerNum) { //800A31F0
  if (shader == (Shader *)0x0) {
                    
    OSPanic("shader.c",0x606,"Failed assertion shader");
  }
  if ((-1 < layerNum) && (layerNum < 2)) {
    return shader->layer + layerNum;
  }
                    
  OSPanic("shader.c",0x607,s_Failed_assertion_layerNum>_0____l_802f0b9c);
}

