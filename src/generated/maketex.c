
/* Library Function - Single Match
    makeTexFn_800bde64
   
   Library: KioskDefault 0 0 */

void makeTexFn_800bde64(Texture *tex) { //800BDE64
  int iVar1;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  uint local_20;
  char local_1c;
  undefined auStack_1b [7];
  
  for (iVar1 = 0; iVar1 < 0x21; iVar1 = iVar1 + 1) {
    if (((&DAT_80380ea8)[iVar1 * 0x14] == '\0') && ((&DAT_80380ea9)[iVar1 * 0x14] == '\0')) {
      gxTexRegionFn_80027040
                ((uint *)(&DAT_80380e98 + iVar1 * 0x14),auStack_1b,&local_1c,(int *)&local_20,
                 &iStack_24,&iStack_28,&iStack_2c);
      if (local_1c == '\0') {
        tex->field51_0x40 = &DAT_80380e98 + iVar1 * 0x14;
        tex->field53_0x48 = 1;
        (&DAT_80380ea8)[iVar1 * 0x14] = 1;
        return;
      }
                    
      OSPanic("maketex.c",0x209,"Failed assertion !is32bMipmap");
    }
  }
  for (iVar1 = 0; iVar1 < 0x21; iVar1 = iVar1 + 1) {
    if ((&DAT_80380ea9)[iVar1 * 0x14] != '\0') {
      if (PTR_DAT_80396e78 + tex->field52_0x44 < &DAT_00080000) {
        GXInitTexPreLoadRegion
                  ((uint *)(&DAT_80380e98 + iVar1 * 0x14),(uint)PTR_DAT_80396e78,tex->field52_0x44,0
                   ,0);
        tex->field51_0x40 = &DAT_80380e98 + iVar1 * 0x14;
        tex->field53_0x48 = 1;
        (&DAT_80380ea8)[iVar1 * 0x14] = 1;
        (&DAT_80380ea9)[iVar1 * 0x14] = 0;
        PTR_DAT_80396e78 = PTR_DAT_80396e78 + tex->field52_0x44;
        return;
      }
      if (PTR_DAT_80396e7c + tex->field52_0x44 < &DAT_00100000) {
        GXInitTexPreLoadRegion
                  ((uint *)(&DAT_80380e98 + iVar1 * 0x14),(uint)PTR_DAT_80396e7c,tex->field52_0x44,0
                   ,0);
        tex->field51_0x40 = &DAT_80380e98 + iVar1 * 0x14;
        tex->field53_0x48 = 1;
        (&DAT_80380ea8)[iVar1 * 0x14] = 1;
        (&DAT_80380ea9)[iVar1 * 0x14] = 0;
        PTR_DAT_80396e7c = PTR_DAT_80396e7c + tex->field52_0x44;
        return;
      }
    }
  }
  iVar1 = 0;
  while( true ) {
    if (0x20 < iVar1) {
      return;
    }
    if (((&DAT_80380ea8)[iVar1 * 0x14] == '\0') && ((&DAT_80380ea9)[iVar1 * 0x14] == '\0')) break;
    iVar1 = iVar1 + 1;
  }
  gxTexRegionFn_80027040
            ((uint *)(&DAT_80380e98 + iVar1 * 0x14),auStack_1b,&local_1c,(int *)&local_20,&iStack_24
             ,&iStack_28,&iStack_2c);
  if (local_1c == '\0') {
    GXInitTexPreLoadRegion((uint *)(&DAT_80380e98 + iVar1 * 0x14),local_20,tex->field52_0x44,0,0);
    tex->field51_0x40 = &DAT_80380e98 + iVar1 * 0x14;
    tex->field53_0x48 = 1;
    (&DAT_80380ea8)[iVar1 * 0x14] = 1;
    return;
  }
                    
  OSPanic("maketex.c",0x24c,"Failed assertion !is32bMipmap");
}


/* Library Function - Single Match
    makeTexFn_800be590
   
   Library: KioskDefault 0 0 */

void shadowFn_800be590(Mtx44 **param1) { //800BE590
  uint uVar1;
  F3DEXcommand *pFVar2;
  uint uVar3;
  Camera *pCVar4;
  uint uVar5;
  RenderFlagsEnum RVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  byte bVar11;
  Mtx43 *ab;
  Shadow *pSVar12;
  uint uVar13;
  ObjInstance *obj;
  double prevFovY;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double b;
  double t;
  float fVar19;
  Mtx44 MStack_27c;
  Mtx43 local_23c;
  Mtx43 MStack524;
  undefined *cBlocks;
  undefined *blkMaps;
  undefined auStack_1bc [96];
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  vec3s local_144;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  Mtx44 local_128;
  Mtx44 *local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  uint uStack_b4;
  Gfx *cmdBuf;
  
  _savefpr_18();
  if (DAT_80398df8 != 0) {
    FUN_80069038();
    FUN_800bef64(-0x7fc7ff78,(uint)DAT_80398df8);
    local_e8 = *param1;
    Camera_setPlayerNo(1);
    pCVar4 = getCurCamera();
    fVar19 = getFovY();
    prevFovY = (double)fVar19;
    setFovY(0.0);
    setViewportAspect(0.0);
    dVar17 = (double)(pCVar4->pos).x;
    dVar16 = (double)(pCVar4->pos).y;
    dVar15 = (double)(pCVar4->pos).z;
    local_c4 = (int)(pCVar4->rot).y;
    local_c8 = (int)(pCVar4->rot).x;
    local_cc = (int)(pCVar4->rot).z;
    (pCVar4->rot).y = 0;
    local_15c = 0.0;
    local_158 = 1.0;
    local_154 = 0.0;
    FUN_800b432c(2.0,&local_15c,(int)auStack_1bc);
    FUN_800d56cc(&local_150,&local_14c,&local_148);
    if (-0.707 < local_14c) {
      local_14c = -0.707;
      VECNormalize(&local_150,&local_150);
    }
    local_d8 = -local_150;
    local_d4 = -local_14c;
    local_d0 = -local_148;
    local_e4 = local_150;
    local_e0 = local_14c;
    local_dc = local_148;
    uVar5 = getAngle();
    DAT_80398e30 = uVar5 & 0xffff;
    local_e4 = local_e4 * local_e4;
    local_dc = local_dc * local_dc;
    sqrt((double)(local_e4 + local_dc));
    uVar5 = getAngle();
    DAT_80398e34 = (uVar5 & 0xffff) - 0x3fc8;
    (pCVar4->rot).y = (short)DAT_80398e34;
    (pCVar4->rot).x = (short)DAT_80398e30;
    dVar14 = sqrt((double)(local_d0 * local_d0 + local_d8 * local_d8 + local_d4 * local_d4));
    if (0.0 < dVar14) {
      fVar19 = (float)(100.0 / dVar14);
      local_d8 = local_d8 * fVar19;
      local_d4 = local_d4 * fVar19;
      local_d0 = local_d0 * fVar19;
    }
    pCVar4->obj40 = (ObjInstance *)0x0;
    trackGetBlocks(&blkMaps,&cBlocks);
    bVar11 = 0;
    uVar5 = 0;
    bVar10 = 0;
    while( true ) {
      fVar19 = SUB84(prevFovY,0);
      if (DAT_80398df8 <= bVar10) break;
      obj = (ObjInstance *)(&DAT_80380088)[(uint)bVar10 * 3];
      obj->shadow->field6_0xc = 0;
      pSVar12 = obj->shadow;
      Camera_setPlayerNo(0);
      uVar7 = objShadowFn_800626c8((int)obj,(uint)framesThisStep);
      Camera_setPlayerNo(1);
      if ((uVar7 & 0xff) != 0) {
        uVar1 = uVar5 & 0xff;
        ab = (Mtx43 *)(&FLOAT_8037d7e8 + uVar1 * 0x1a);
        (&DAT_8037d84c)[uVar1 * 0x68] = (char)uVar7;
        if ((bVar11 < 0x16) && ((&DAT_80380090)[(uint)bVar10 * 0xc] != '\0')) {
          if (bVar11 < 2) {
            uVar13 = 0x100;
          }
          else if (bVar11 < 6) {
            uVar13 = 0x80;
          }
          else {
            uVar13 = 0x40;
          }
          (pSVar12->field8_0x14).x = -local_150;
          (pSVar12->field8_0x14).y = -local_14c;
          (pSVar12->field8_0x14).z = -local_148;
          FUN_800bf4c4(uVar13 << 1);
          shadDisplayList = shadDisplayList_80398df4;
          if (obj->hitstate == (HitState *)0x0) {
            fVar19 = 0.0;
          }
          else if (obj->hitstate->flags5A == 0) {
            uStack_b4 = (int)(short)obj->hitstate->field16_0x52 ^ 0x80000000;
            local_b8 = 0x43300000;
            fVar19 = (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503601774854144.0);
          }
          else {
            uStack_b4 = (int)obj->hitstate->field18_0x56 ^ 0x80000000;
            local_b8 = 0x43300000;
            fVar19 = (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503601774854144.0) * 0.5;
          }
          (pCVar4->pos).x = local_d8 + (obj->pos).pos.x;
          (pCVar4->pos).y = fVar19 + local_d4 + (obj->pos).pos.y;
          (pCVar4->pos).z = local_d0 + (obj->pos).pos.z;
          t = -(double)pSVar12->field0_0x0;
          b = (double)pSVar12->field0_0x0;
          dVar18 = -(double)pSVar12->field0_0x0;
          dVar14 = (double)pSVar12->field0_0x0;
          if (obj->pMatrix != (ObjInstance *)0x0) {
            (pCVar4->pos).x = (pCVar4->pos).x + playerMapOffsetX;
            (pCVar4->pos).z = (pCVar4->pos).z + playerMapOffsetZ;
          }
          local_138 = -((pCVar4->pos).x - playerMapOffsetX);
          local_134 = -(pCVar4->pos).y;
          local_130 = -((pCVar4->pos).z - playerMapOffsetZ);
          local_144.x = (pCVar4->rot).x + -0x8000;
          local_144.y = (pCVar4->rot).y;
          local_144.z = (pCVar4->rot).z;
          local_13c = 1.0;
          mtxRotateByVec3s(&local_128,&local_144);
          cmdBuf = shadDisplayList;
          for (iVar9 = 0; iVar9 < 3; iVar9 = iVar9 + 1) {
            for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
              (&MStack524.m11)[iVar8 + iVar9 * 4] = (&local_128.m11)[iVar9 + iVar8 * 4];
            }
          }
          MStack524.m14 = local_128.m41;
          MStack524.m24 = local_128.m42;
          MStack524.m34 = local_128.m43;
          pFVar2 = &shadDisplayList->cmd;
          shadDisplayList = shadDisplayList + 1;
          *pFVar2 = X_SYNC;
          cmdBuf->param = 0;
          uVar3 = (int)shadDisplayList - (int)shadDisplayList_80398df4;
          if (3999 < ((int)uVar3 >> 3) + (uint)((int)uVar3 < 0 && (uVar3 & 7) != 0)) {
                    
            OSPanic("maketex.c",0x3ec,"Failed assertion GCShadowDPPtr - GCShadowDP < MAX_SHADOW_GFX * sizeof(Gfx)");
          }
          RSP_interpret(shadDisplayList_80398df4);
          shadDisplayList = shadDisplayList_80398df4;
          GXSetScissor(2,2,uVar13 * 2 + -4,uVar13 * 2 + -4);
          uStack_b4 = uVar13 ^ 0x80000000;
          local_b8 = 0x43300000;
          uStack_bc = uVar13 ^ 0x80000000;
          local_c0 = 0x43300000;
          GXSetViewport_(0.0,0.0,(double)((float)((double)CONCAT44(0x43300000,uStack_b4) -
                                                 4503601774854144.0) * 2.0),
                         (double)((float)((double)CONCAT44(0x43300000,uStack_bc) -
                                         4503601774854144.0) * 2.0),0.0,1.0);
          C_MTXOrtho(t,b,dVar18,dVar14,4.0,10000.0,&MStack_27c);
          GXSetProjection(&MStack_27c.m11,1);
          updateViewMatrix();
          objRenderCurrentModel(obj);
          MTXLightOrtho(b,t,dVar18,dVar14,0.5,0.5,0.5,0.5,(float *)ab);
          MTXConcat(ab,&MStack524,ab);
          GXSetZMode(true,GX_LEQUAL,true);
          GXSetTexCopySrc(0,0,uVar13 << 1,uVar13 << 1);
          GXSetTexCopyDst((ushort)uVar13,(ushort)uVar13,0x20,1);
          GXCopyTex((uint)(shadowTextures[bVar11] + 1),1);
          (&DAT_8037d848)[uVar1 * 0x1a] = shadowTextures[bVar11];
          bVar11 = bVar11 + 1;
          obj->shadow->field6_0xc = (int)ab;
        }
        else {
          (&DAT_8037d848)[uVar1 * 0x1a] = obj->shadow->texture;
          dVar18 = (double)(obj->pos).pos.x;
          dVar14 = (double)(obj->pos).pos.z;
          if (obj->pMatrix == (ObjInstance *)0x0) {
            dVar18 = (double)(float)(dVar18 - (double)playerMapOffsetX);
            dVar14 = (double)(float)(dVar14 - (double)playerMapOffsetZ);
          }
          MTXTrans(-dVar18,-(double)(obj->pos).pos.y,-dVar14,&MStack524.m11);
          local_23c.m11 = 0.5 / pSVar12->field0_0x0;
          local_23c.m12 = 0.0;
          local_23c.m13 = 0.0;
          local_23c.m14 = 0.5;
          local_23c.m21 = 0.0;
          local_23c.m22 = 0.0;
          local_23c.m24 = 0.5;
          local_23c.m31 = 0.0;
          local_23c.m32 = 0.0;
          local_23c.m33 = 0.0;
          local_23c.m34 = 1.0;
          local_23c.m23 = local_23c.m11;
          MTXConcat(&local_23c,&MStack524,ab);
          (pSVar12->field8_0x14).x = local_15c;
          (pSVar12->field8_0x14).y = local_158;
          (pSVar12->field8_0x14).z = local_154;
          obj->shadow->field6_0xc = (int)ab;
        }
        uVar5 = uVar5 + 1;
      }
      bVar10 = bVar10 + 1;
    }
    GXPixModeSync();
    FUN_800bf4b8();
    (pCVar4->pos).x = (float)dVar17;
    (pCVar4->pos).y = (float)dVar16;
    (pCVar4->pos).z = (float)dVar15;
    (pCVar4->rot).y = (short)local_c4;
    (pCVar4->rot).x = (short)local_c8;
    (pCVar4->rot).z = (short)local_cc;
    RVar6 = FUN_800a706c();
    if (RVar6 == 0) {
      RVar6 = isWidescreen();
      if (RVar6 == 0) {
        Camera_setPlayerNo(0);
        setFovY(fVar19);
        setViewportAspect(SUB84((double)f_1p3333,0));
        cameraFn_800698b4((Gfx *)&shadDisplayList,&local_e8);
      }
      else {
        Camera_setPlayerNo(0);
        setFovY(fVar19);
        setViewportAspect(1.084202e-19);
        cameraFn_800698b4((Gfx *)&shadDisplayList,&local_e8);
      }
    }
    else {
      Camera_setPlayerNo(0);
      setFovY(fVar19);
      RVar6 = isWidescreen();
      if (RVar6 == 0) {
        setViewportAspect(1.084202e-19);
      }
      else {
        setViewportAspect(0.0);
      }
      cameraFn_800698b4((Gfx *)&shadDisplayList,&local_e8);
    }
    cmdBuf = shadDisplayList;
    pFVar2 = &shadDisplayList->cmd;
    shadDisplayList = shadDisplayList + 1;
    *pFVar2 = X_SYNC;
    cmdBuf->param = 0;
    uVar5 = (int)shadDisplayList - (int)shadDisplayList_80398df4;
    if (3999 < ((int)uVar5 >> 3) + (uint)((int)uVar5 < 0 && (uVar5 & 7) != 0)) {
                    
      OSPanic("maketex.c",0x45d,"Failed assertion GCShadowDPPtr - GCShadowDP < MAX_SHADOW_GFX * sizeof(Gfx)");
    }
    RSP_interpret(shadDisplayList_80398df4);
    shadDisplayList = shadDisplayList_80398df4;
    updateViewMatrix();
    resetPerspectiveMtxs();
    *param1 = local_e8;
    if (curTvParams->field_rendering == '\0') {
      uStack_bc = (uint)curTvParams->fbWidth;
      local_c0 = 0x43300000;
      uStack_b4 = (uint)curTvParams->xfbHeight;
      local_b8 = 0x43300000;
      GXSetViewport_(0.0,0.0,(double)(float)((double)CONCAT44(0x43300000,uStack_bc) -
                                            4503599627370496.0),
                     (double)(float)((double)CONCAT44(0x43300000,uStack_b4) - 4503599627370496.0),
                     0.0,1.0);
    }
    else {
      uVar7 = FUN_8001617c();
      uStack_bc = (uint)curTvParams->fbWidth;
      local_c0 = 0x43300000;
      uStack_b4 = (uint)curTvParams->xfbHeight;
      local_b8 = 0x43300000;
      GXSetViewport(0.0,0.0,(double)(float)((double)CONCAT44(0x43300000,uStack_bc) -
                                           4503599627370496.0),
                    (double)(float)((double)CONCAT44(0x43300000,uStack_b4) - 4503599627370496.0),0.0
                    ,1.0,(uint)uVar7);
    }
    modelGxSetupFn_800bfc98();
    enableCameraYOffset();
  }
  _restfpr_18();
  return;
}

