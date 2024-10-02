
/* Library Function - Single Match
    GXInit
   
   Library: KioskDefault 0 0 */

undefined ** GXInit(uint param1,uint param2) { //8001B144
  int iVar1;
  uint uVar2;
  GXRenderModeObj *pGVar3;
  uint uVar4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  Mtx43 local_70;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  
  local_74 = 0x404040ff;
  local_78 = 0;
  local_7c = 0xffffffff;
  gx->isDlistInProgress = false;
  gx->field_0x4ed = 1;
  isInGxBegin = false;
  *(undefined4 *)&gx->field_0x4dc = 0;
  *(undefined2 *)gx = 0;
  PTR_pi_INTSR_8039846c = (undefined *)OSPhysicalToUncached(0xc003000);
  PTR_CP_SR_80398470 = (undefined *)OSPhysicalToUncached(0xc000000);
  PTR_pe_Z_80398474 = (undefined *)OSPhysicalToUncached(0xc001000);
  PTR_mi_PROT1_80398478 = (undefined *)OSPhysicalToUncached(0xc004000);
  FUN_8001cff4();
  GXInitFifoBase((uint *)&PTR_DAT_8032716c,param1,param2);
  _gxFifoSubmitDlist((uint *)&PTR_DAT_8032716c);
  GXSetGPFifo(&PTR_DAT_8032716c);
  FUN_80020440();
  EnableWriteGatherPipe();
  gx->field491_0x204 = 0;
  gx->field491_0x204 = gx->field491_0x204 & 0xffffff;
  *(undefined4 *)&gx->field_0x124 = 0xff;
  *(uint *)&gx->field_0x124 = *(uint *)&gx->field_0x124 & 0xffffff | 0xf000000;
  *(undefined4 *)&gx->field_0x7c = 0;
  *(uint *)&gx->field_0x7c = *(uint *)&gx->field_0x7c & 0xffffff | 0x22000000;
  for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1) {
    *(undefined4 *)(&gx->field_0x130 + uVar4 * 4) = 0;
    *(undefined4 *)(&gx->field_0x170 + uVar4 * 4) = 0;
    *(undefined4 *)(&gx->field_0x100 + (uVar4 >> 1) * 4) = 0;
    gx->field1083_0x47c[uVar4 + 8] = 0xff;
    if ((uVar4 * 2 + 0xc0 & 0xffffff00) != 0) {
                    
      OSPanic("GXInit.c",0x2f2,"GX Internal: Register field out of range");
    }
    *(uint *)(&gx->field_0x130 + uVar4 * 4) =
         *(uint *)(&gx->field_0x130 + uVar4 * 4) & 0xffffff | (uVar4 * 2 + 0xc0) * 0x1000000;
    if ((uVar4 * 2 + 0xc1 & 0xffffff00) != 0) {
                    
      OSPanic("GXInit.c",0x2f3,"GX Internal: Register field out of range");
    }
    *(uint *)(&gx->field_0x170 + uVar4 * 4) =
         *(uint *)(&gx->field_0x170 + uVar4 * 4) & 0xffffff | (uVar4 * 2 + 0xc1) * 0x1000000;
    if (((uVar4 >> 1) + 0xf6 & 0xffffff00) != 0) {
                    
      OSPanic("GXInit.c",0x2f5,"GX Internal: Register field out of range");
    }
    *(uint *)(&gx->field_0x1b0 + (uVar4 >> 1) * 4) =
         *(uint *)(&gx->field_0x1b0 + (uVar4 >> 1) * 4) & 0xffffff |
         ((uVar4 >> 1) + 0xf6) * 0x1000000;
    if (((uVar4 >> 1) + 0x28 & 0xffffff00) != 0) {
                    
      OSPanic("GXInit.c",0x2f7,"GX Internal: Register field out of range");
    }
    *(uint *)(&gx->field_0x100 + (uVar4 >> 1) * 4) =
         *(uint *)(&gx->field_0x100 + (uVar4 >> 1) * 4) & 0xffffff |
         ((uVar4 >> 1) + 0x28) * 0x1000000;
  }
  *(undefined4 *)&gx->field_0x120 = 0;
  *(uint *)&gx->field_0x120 = *(uint *)&gx->field_0x120 & 0xffffff | 0x27000000;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
    *(undefined4 *)(&gx->field_0xb8 + uVar4 * 4) = 0;
    *(undefined4 *)(&gx->field_0xd8 + uVar4 * 4) = 0;
    if ((uVar4 * 2 + 0x30 & 0xffffff00) != 0) {
                    
      OSPanic("GXInit.c",0x300,"GX Internal: Register field out of range");
    }
    *(uint *)(&gx->field_0xb8 + uVar4 * 4) =
         *(uint *)(&gx->field_0xb8 + uVar4 * 4) & 0xffffff | (uVar4 * 2 + 0x30) * 0x1000000;
    if ((uVar4 * 2 + 0x31 & 0xffffff00) != 0) {
                    
      OSPanic("GXInit.c",0x301,"GX Internal: Register field out of range");
    }
    *(uint *)(&gx->field_0xd8 + uVar4 * 4) =
         *(uint *)(&gx->field_0xd8 + uVar4 * 4) & 0xffffff | (uVar4 * 2 + 0x31) * 0x1000000;
  }
  gx->field235_0xf8 = gx->field235_0xf8 & 0xffffff | 0x20000000;
  gx->field236_0xfc = gx->field236_0xfc & 0xffffff | 0x21000000;
  *(uint *)&gx->field_0x1d0 = *(uint *)&gx->field_0x1d0 & 0xffffff | 0x41000000;
  *(uint *)&gx->field_0x1d4 = *(uint *)&gx->field_0x1d4 & 0xffffff | 0x42000000;
  gx->field453_0x1d8 = gx->field453_0x1d8 & 0xffffff | 0x40000000;
  gx->field454_0x1dc = gx->field454_0x1dc & 0xffffff | 0x43000000;
  *(uint *)&gx->field_0x1fc = *(uint *)&gx->field_0x1fc & 0xfffffe7f;
  gx->flags4F0 = 0;
  gx->field_0x4ee = 0;
  pGxDebug->debugLevel = 3;
  gxSetDebugPrintFunc(__GXDefaultVerifyCallback);
  for (uVar4 = 0; uVar4 < 0x100; uVar4 = uVar4 + 1) {
    *(uint *)(pGxDebug->isRegInit + uVar4 * 4 + 0xc00) =
         *(uint *)(pGxDebug->isRegInit + uVar4 * 4 + 0xc00) & 0xffffff | 0xff000000;
  }
  memset_(pGxDebug->isRegInit + 0x1000,0,0x50);
  memset_(&pGxDebug[1].field_0xd,0,0x100);
  memset_(pGxDebug[1].isRegInit + 0x45,0,0x60);
  memset_(pGxDebug[1].isRegInit + 0x1a5,0,0x80);
  uVar4 = busClockMhz / 500;
  gxFn_80028f60();
  uVar2 = uVar4 >> 0xb | 0x69000400;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar2;
  *(uint *)(pGxDebug->isRegInit + 0xda4) = uVar2;
  gxFn_80028f60();
  uVar4 = uVar4 / 0x1080 | 0x46000200;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = uVar4;
  *(uint *)(pGxDebug->isRegInit + 0xd18) = uVar4;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
    (&gx->vtxFmts)[uVar4] = (&gx->vtxFmts)[uVar4] & 0xbfffffff | 0x40000000;
    *(uint *)(&gx->field_0x3c + uVar4 * 4) =
         *(uint *)(&gx->field_0x3c + uVar4 * 4) & 0x7fffffff | 0x80000000;
    GXFIFO._0_1_ = 8;
    GXFIFO._0_1_ = (byte)uVar4 | 0x80;
    GXFIFO = *(undefined4 *)(&gx->field_0x3c + uVar4 * 4);
    local_80 = uVar4 - 0xc;
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x1000;
  GXFIFO = 0x3f;
  if ((true) && (true)) {
    *(undefined4 *)&pGxDebug->field_0x8 = 0x3f;
    pGxDebug->isRegInit[0x1000] = 1;
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x1012;
  GXFIFO = 1;
  if ((true) && (true)) {
    *(undefined4 *)&pGxDebug->field_0x50 = 1;
    pGxDebug->isRegInit[0x1012] = 1;
  }
  pGxDebug->isRegInit[0x1000] = 0;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0x5800000f;
  *(undefined4 *)(pGxDebug->isRegInit + 0xd60) = 0x5800000f;
  iVar1 = VIGetTvFormat();
  if (iVar1 == 1) {
    pGVar3 = (GXRenderModeObj *)0x802d9148;
  }
  else if (iVar1 < 1) {
    if (iVar1 < 0) {
LAB_8001ba28:
                    
      OSPanic("GXInit.c",0x38b,"GXInit: invalid TV format");
    }
    pGVar3 = &tvParamsNotProgScan;
  }
  else {
    if (2 < iVar1) goto LAB_8001ba28;
    pGVar3 = (GXRenderModeObj *)0x802d8fa4;
  }
  local_84 = local_74;
  GXSetCopyClear((undefined *)&local_84,0xffffff);
  FUN_8001c2ec(0,1,4,0x3c);
  FUN_8001c2ec(1,1,5,0x3c);
  FUN_8001c2ec(2,1,6,0x3c);
  FUN_8001c2ec(3,1,7,0x3c);
  FUN_8001c2ec(4,1,8,0x3c);
  FUN_8001c2ec(5,1,9,0x3c);
  FUN_8001c2ec(6,1,10,0x3c);
  FUN_8001c2ec(7,1,0xb,0x3c);
  GXSetNumTexGens(1);
  GXClearVtxDesc();
  GXInvalidateVtxCache();
  GXSetLineWidth(6,0);
  GXSetPointSize(6,0);
  GXEnableTexOffsets(0,0,0);
  GXEnableTexOffsets(1,0,0);
  GXEnableTexOffsets(2,0,0);
  GXEnableTexOffsets(3,0,0);
  GXEnableTexOffsets(4,0,0);
  GXEnableTexOffsets(5,0,0);
  GXEnableTexOffsets(6,0,0);
  GXEnableTexOffsets(7,0,0);
  local_70.m11 = 1.0;
  local_70.m12 = 0.0;
  local_70.m13 = 0.0;
  local_70.m14 = 0.0;
  local_70.m21 = 0.0;
  local_70.m22 = 1.0;
  local_70.m23 = 0.0;
  local_70.m24 = 0.0;
  local_70.m31 = 0.0;
  local_70.m32 = 0.0;
  local_70.m33 = 1.0;
  local_70.m34 = 0.0;
  GXLoadPosMtxImm(&local_70,0);
  GXLoadNrmMtxImm(&local_70.m11,0);
  GXSetCurrentMtx(0);
  GXLoadTexMtxImm(&local_70,0x3c,0);
  GXLoadTexMtxImm(&local_70,0x7d,0);
  uStack_34 = (uint)pGVar3->fbWidth;
  local_38 = 0x43300000;
  uStack_3c = (uint)pGVar3->xfbHeight;
  local_40 = 0x43300000;
  GXSetViewport_(0.0,0.0,(double)(float)((double)CONCAT44(0x43300000,uStack_34) - 4503599627370496.0
                                        ),
                 (double)(float)((double)CONCAT44(0x43300000,uStack_3c) - 4503599627370496.0),0.0,
                 1.0);
  GXSetCoPlanar(0);
  GXSetCullMode(GX_CULL_BACK);
  GXSetClipMode(0);
  GXSetScissor(0,0,(uint)pGVar3->fbWidth,(uint)pGVar3->efbHeight);
  GXSetScissorBoxOffset(0,0);
  GXSetNumChans(0);
  GXSetChanCtrl(4,0,0,1,0,0,2);
  local_88 = local_78;
  GXSetChanAmbColor(4,(byte *)&local_88);
  local_8c = local_7c;
  GXSetChanMatColor(4,(byte *)&local_8c);
  GXSetChanCtrl(5,0,0,1,0,0,2);
  local_90 = local_78;
  GXSetChanAmbColor(5,(byte *)&local_90);
  local_94 = local_7c;
  GXSetChanMatColor(5,(byte *)&local_94);
  GXInvalidateTexAll();
  *(undefined4 *)&gx->TexRegionsCI = 0;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
    GXInitTexCacheRegion
              ((uint *)(&gx->field_0x208 + uVar4 * 0x10),0,uVar4 << 0xf,0,uVar4 * 0x8000 + 0x80000,0
              );
  }
  *(undefined4 *)&gx->TexRegions = 0;
  for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
    GXInitTexCacheRegion
              ((uint *)(&gx->field_0x288 + uVar4 * 0x10),0,(uVar4 * 2 + 8) * 0x8000,0,
               (uVar4 * 2 + 9) * 0x8000,0);
  }
  for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1) {
    GXInitTlutRegion((uint *)(&gx->field_0x2d0 + uVar4 * 0x10),uVar4 * 0x2000 + 0xc0000,0x10);
  }
  for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
    GXInitTlutRegion((uint *)(&gx->field_0x3d0 + uVar4 * 0x10),uVar4 * 0x8000 + 0xe0000,0x40);
  }
  FUN_800273a0(__GXDefaultTexRegionCallback);
  FUN_800273c8(__GXDefaultTlutRegionCallback);
  GXSetTevOrder(0,0,0,4);
  GXSetTevOrder(1,1,1,4);
  GXSetTevOrder(2,2,2,4);
  GXSetTevOrder(3,3,3,4);
  GXSetTevOrder(4,4,4,4);
  GXSetTevOrder(5,5,5,4);
  GXSetTevOrder(6,6,6,4);
  GXSetTevOrder(7,7,7,4);
  GXSetTevOrder(8,0xff,0xff,0xff);
  GXSetTevOrder(9,0xff,0xff,0xff);
  GXSetTevOrder(10,0xff,0xff,0xff);
  GXSetTevOrder(0xb,0xff,0xff,0xff);
  GXSetTevOrder(0xc,0xff,0xff,0xff);
  GXSetTevOrder(0xd,0xff,0xff,0xff);
  GXSetTevOrder(0xe,0xff,0xff,0xff);
  GXSetTevOrder(0xf,0xff,0xff,0xff);
  GXSetNumTevStages(1);
  GXSetTevOp(0,3);
  GXSetAlphaCompare(7,0,0,7,0);
  GXSetZTexture(0,0x11,0);
  for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1) {
    GXSetTevKColorSel(uVar4,6);
    GXSetTevKAlphaSel(uVar4,0);
    GXSetTevSwapMode(uVar4,0,0);
  }
  GXSetTevSwapModeTable(0,0,1,2,3);
  GXSetTevSwapModeTable(1,0,0,0,3);
  GXSetTevSwapModeTable(2,1,1,1,3);
  GXSetTevSwapModeTable(3,2,2,2,3);
  for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1) {
    GXSetTevDirect(uVar4);
  }
  GXSetNumIndStages(0);
  GXSetIndTexScale(0,0,0);
  GXSetIndTexScale(1,0,0);
  GXSetIndTexScale(2,0,0);
  GXSetIndTexScale(3,0,0);
  local_98 = local_78;
  GXSetFog(0.0,1.0,0.1000000014901161,1.0,0,(undefined *)&local_98);
  GXSetFogRangeAdj(0,0,0);
  GXSetBlendMode(0,4,5,0);
  GXSetColorUpdate(1);
  GXSetAlphaUpdate(1);
  GXSetZMode(true,GX_LEQUAL,true);
  GXSetZCompLoc(1);
  GXSetDither(1);
  GXSetDstAlpha(0,0);
  GXSetPixelFmt(0,0);
  GXSetFieldMask(1,1);
  GXSetFieldMode(pGVar3->field_rendering,
                 (uint)((uint)pGVar3->viHeight == (uint)pGVar3->xfbHeight << 1));
  GXSetDispCopySrc(0,0,(uint)pGVar3->fbWidth,(uint)pGVar3->efbHeight);
  GXSetDispCopyDst((uint)pGVar3->fbWidth);
  uStack_3c = (uint)pGVar3->xfbHeight;
  local_40 = 0x43300000;
  uStack_34 = (uint)pGVar3->efbHeight;
  local_38 = 0x43300000;
  GXSetDispCopyYScale((double)((float)((double)CONCAT44(0x43300000,uStack_3c) - 4503599627370496.0)
                              / (float)((double)CONCAT44(0x43300000,uStack_34) - 4503599627370496.0)
                              ));
  GXSetCopyClamp(3);
  GXSetCopyFilter(pGVar3->aa,pGVar3->sample_pattern[0],'\x01',pGVar3->vfilter);
  GXSetDispCopyGamma(0);
  GXSetDispCopyFrame2Field(0);
  GXClearBoundingBox();
  GXPokeColorUpdate(1);
  GXPokeAlphaUpdate(1);
  GXPokeDither(0);
  GXPokeBlendUpdate(0,0,1,0xf);
  GXPokeAlphaMode(7,0);
  GXPokeAlphaRead(1);
  GXPokeDstAlpha(0,0);
  GXPokeZMode(1,7,1);
  return &PTR_DAT_8032716c;
}

