
/* Library Function - Single Match
    modelRenderFn_80096b30
   
   Library: KioskDefault 0 0 */

void objprintDrawGCModel(ObjInstance *obj) { //80096B30
  Model *pMVar1;
  ObjInstance *obj2;
  int iVar2;
  
  pMVar1 = objGetModelInstance(obj);
  if (pMVar1->field26_0x4c != (HitSpherePos *)pMVar1->dataSize) {
                    
    OSPanic("objprint_dolphin.c",0x106,s_Failed_assertion_modelInstance_>_802ee5a4);
  }
  obj2 = obj;
  if (obj->parent != (ObjInstance *)0x0) {
    obj2 = obj->parent;
  }
  modelExecRenderStream(obj,obj2,*(Model **)pMVar1,false);
  if (('\0' < bDisableSky) && (bDisableSky < '\x04')) {
    iVar2._0_1_ = pMVar1->usage;
    iVar2._1_1_ = pMVar1->field_0x1;
    iVar2._2_2_ = pMVar1->flags;
    FUN_80098a00((int)obj,(ModelInstance *)pMVar1,iVar2,(ModelInstance *)0x0,0,(int)obj);
  }
  for (iVar2 = 0; iVar2 < (int)(uint)obj->nChildren; iVar2 = iVar2 + 1) {
    if (((obj->child[iVar2]->pos).flags & Invisible) == 0) {
      objprintDrawGCChildModel(obj->child[iVar2],obj);
    }
  }
  if (pMVar1->field26_0x4c == (HitSpherePos *)pMVar1->dataSize) {
    modelGxSetupFn_800bfc98();
    return;
  }
                    
  OSPanic("objprint_dolphin.c",0x11b,s_Failed_assertion_modelInstance_>_802ee5a4);
}


/* Library Function - Single Match
    modelRenderFn_80096c74
   
   Library: KioskDefault 0 0 */

void objprintDrawGCChildModel(ObjInstance *param1,ObjInstance *param2) { //80096C74
  char cVar1;
  Model *pMVar2;
  Model *modelInstance;
  Mtx43 *a;
  int iVar3;
  uint uVar4;
  ObjPos local_b8;
  Mtx44 MStack_a0;
  Mtx44 MStack_60;
  
  pMVar2 = objGetModelInstance(param1);
  modelInstance = objGetModelInstance(param2);
  uVar4 = param1->flags_0xb0 & 3;
  if ((true) && (uVar4 < param2->data->noplacements)) {
    cVar1 = (&param2->data->pAttachPoints[uVar4].bone)[(char)param2->curModel];
    local_b8.pos.x = param2->data->pAttachPoints[uVar4].pos.x;
    local_b8.pos.y = param2->data->pAttachPoints[uVar4].pos.y;
    local_b8.pos.z = param2->data->pAttachPoints[uVar4].pos.z;
    local_b8.rotation.x = param2->data->pAttachPoints[uVar4].rot.x;
    local_b8.rotation.y = param2->data->pAttachPoints[uVar4].rot.y;
    local_b8.rotation.z = param2->data->pAttachPoints[uVar4].rot.z;
    local_b8.scale = 1.0;
    mtxSetFromObjPos(&MStack_a0,&local_b8);
    mtx44Transpose(&MStack_a0,&MStack_60);
    a = (Mtx43 *)modelInstGetjMtx((ModelInstance *)modelInstance,(int)cVar1);
    MTXConcat(a,(Mtx43 *)&MStack_60,(Mtx43 *)&MStack_60);
    FUN_80096e8c((Mtx43 *)&MStack_60);
    param1->opacity = (u8)((param1->newOpacity + 1) * (uint)param2->opacity >> 8);
    objprintDrawGCModel(param1);
    if (('\0' < bDisableSky) && (bDisableSky < '\x04')) {
      iVar3._0_1_ = pMVar2->usage;
      iVar3._1_1_ = pMVar2->field_0x1;
      iVar3._2_2_ = pMVar2->flags;
      FUN_80098a00((int)param1,(ModelInstance *)pMVar2,iVar3,(ModelInstance *)0x0,0,(int)param2);
    }
    return;
  }
                    
  OSPanic("objprint_dolphin.c",0x14a,s_Failed_assertion_childPosition>__802ee648);
}


/* Library Function - Single Match
    modelExecRenderStream
   
   Library: KioskDefault 0 0 */

void modelExecRenderStream(ObjInstance *object,ObjInstance *obj2,Model *model,bool param4) { //800972D8
  bool bVar1;
  ModelInstance *pBVar2;
  Mtx44 *a;
  Mtx43 *dst;
  uint uVar2;
  ModelInstance *param3;
  ModelInstance *unaff_r22;
  vec3s *param3_00;
  Shader *unaff_r26;
  double param1;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  Mtx44 afStack436;
  Mtx43 MStack_174;
  Mtx43 aMStack_134 [3];
  Mtx43 MStack_90;
  BitStream stream;
  
  if (object == (ObjInstance *)0x0) {
                    
    OSPanic("objprint_dolphin.c",0x280,"Failed assertion object");
  }
  if (model != (Model *)0x0) {
    if (object->pMatrix == (ObjInstance *)0x0) {
      pBVar2 = (ModelInstance *)objGetModelInstance(object);
      if (pBVar2 == (ModelInstance *)0x0) {
                    
        OSPanic("objprint_dolphin.c",0x286,"Failed assertion modelInstance");
      }
      a = getCameraMtxs();
      if (pMtx_80398b04 == (Mtx43 *)0x0) {
        objModelMtxFn_800859e8(object,&MStack_174);
      }
      else {
        MTXCopy(pMtx_80398b04,&MStack_174);
      }
      if ((pBVar2->flags & MtxsLoaded) == 0) {
        bVar1 = false;
        pBVar2->field22_0x50 = 0;
        if ((model->animBufSize == 0) || ((model->flags & NoAnimations) != 0)) {
          modelInstance_toggleFlag18_1(pBVar2);
          dst = (Mtx43 *)modelInstGetjMtx(pBVar2,0);
          MTXCopy(&MStack_174,dst);
        }
        else if (model->skin2Matrices == (void *)0x0) {
          modelAnimFn_8007e974(pBVar2,(int)model,(int)object,&MStack_174.m11);
        }
        else {
          MtxIdentity((Mtx43 *)&afStack436);
          modelAnimFn_8007e974(pBVar2,(int)model,(int)object,&afStack436.m11);
          FUN_8008102c(pBVar2,&MStack_174,-0x7fca6658);
          bVar1 = true;
        }
        if (model->bCopyVtxsToModelInst != 0) {
          FUN_80080d04((int *)pBVar2);
        }
        if (bVar1) {
          if (pBVar2->field22_0x50 == 0) {
            param3_00 = model->vertexPositions;
          }
          else {
            param3_00 = pBVar2->vertexPositions[0];
          }
          skinFn_800816b4(-0x7fca6658,(int)&model->field_0x70,(int)param3_00,pBVar2->field15_0x34);
        }
        FUN_80080734(pBVar2,(int)model,object,(Mtx43 *)0x0,obj2);
        pBVar2->flags = pBVar2->flags | MtxsLoaded;
      }
      if ((model->skin2Matrices != (void *)0x0) || (object->data->shadowType == Crash)) {
        MTXConcat((Mtx43 *)a,&MStack_174,&MStack_90);
        GXLoadPosMtxImm(&MStack_90,(uint)DAT_802ee551);
        if (object->data->shadowType == Crash) {
          FUN_800b3b38((int)object,(int)pBVar2);
        }
        MStack_90.m14 = 0.0;
        MStack_90.m24 = 0.0;
        MStack_90.m34 = 0.0;
        GXLoadNrmMtxImm(&MStack_90.m11,(uint)DAT_802ee551);
      }
      if (param4) {
        GXSetNumTexGens(0);
        GXSetNumTevStages(1);
        GXSetNumIndStages(0);
        GXSetTevOrder(0,0xff,0xff,4);
        local_1bc = DAT_80396d38;
        GXSetTevColor(3,(byte *)&local_1bc);
        GXSetTevDirect(0);
        GXSetTevColorIn(0,0xf,0xf,0xf,6);
        GXSetTevAlphaIn(0,7,7,7,3);
        GXSetTevColorOp(0,0,0,0,1,0);
        GXSetTevAlphaOp(0,0,0,0,1,0);
        local_1c0 = DAT_80396d38;
        GXSetFog(0.0,0.0,0.0,0.0,0,(undefined *)&local_1c0);
        GXSetZMode(false,GX_ALWAYS,false);
        GXSetChanCtrl(4,0,0,1,0,0,2);
        GXSetNumChans(1);
      }
      else {
        resetPerspectiveMtxs();
        objPrintLightFn_8009846c((int)model,object);
        if ((model->flags & FogRelated) == 0) {
          fogFn_800c6a1c();
        }
        else {
          local_1b8 = DAT_80396d38;
          GXSetFog(0.0,0.0,0.0,0.0,0,(undefined *)&local_1b8);
        }
      }
      GXSetArray(9,(uint)pBVar2->vertexPositions[0],6);
      if ((*(byte *)&model->normals & 8) == 0) {
        GXSetArray(10,(uint)model->vertexNormals,6);
      }
      else {
        GXSetArray(10,(uint)model->vertexNormals,0x12);
      }
      GXSetArray(0xb,(uint)model->vertexColours,2);
      GXSetArray(0xd,(uint)model->vertexTexCoords,4);
      GXSetArray(0xe,(uint)model->vertexTexCoords,4);
      param3 = (ModelInstance *)((uint)*(ushort *)&model->field_0x9c << 3);
      bitStreamInit(&stream,(byte *)model->renderStream,(uint)param3,
                    (uint)*(ushort *)&model->field_0x9c << 3);
      bVar1 = false;
      while (!bVar1) {
        uVar2 = bitStream_read(&stream,4);
        if (uVar2 == 3) {
          param3 = unaff_r22;
          FUN_80098124((int)model,(int)unaff_r26,(int *)unaff_r22,&stream);
        }
        else if ((int)uVar2 < 3) {
          if (uVar2 == 1) {
            if ((param4) || (DAT_80398b00 != '\0')) {
              uVar2 = bitStream_read(&stream,6);
              unaff_r26 = modelGetShader(model,uVar2);
            }
            else {
              param3 = pBVar2;
              uVar2 = renderOpTexture((int)object,(int)model,pBVar2,&stream);
              unaff_r26 = modelGetShader(model,uVar2);
              param1 = (double)(1.0 / (object->pos).scale);
              MTXScale(param1,param1,param1,&aMStack_134[0].m11);
            }
            unaff_r22 = (ModelInstance *)Model_getShaderTexture(pBVar2,uVar2);
          }
          else if (0 < (int)uVar2) {
            renderOpCallDlist(model,&stream,(char *)param3);
          }
        }
        else if (uVar2 == 5) {
          bVar1 = true;
        }
        else if ((int)uVar2 < 5) {
          param3 = (ModelInstance *)&stream;
          renderOpMatrix(model,pBVar2,(BitStream *)param3,aMStack_134,(Mtx43 *)a);
        }
      }
      pMtx_80398b04 = (Mtx43 *)0x0;
    }
    return;
  }
                    
  OSPanic("objprint_dolphin.c",0x281,"Failed assertion model");
}


/* Library Function - Single Match
    objModelRenderFn_800978c4
   
   Library: KioskDefault 0 0 */

uint renderOpTexture(int param1,int param2,ModelInstance *param3,BitStream *param4) { //800978C4
  uint shaderNum;
  code *pcVar1;
  Shader *param2_00;
  int *param3_00;
  int param1_00;
  Mtx43 *param2_01;
  uint uVar2;
  int iVar3;
  undefined4 local_48;
  undefined local_44;
  undefined local_43;
  undefined local_42;
  undefined local_41;
  int local_40;
  int local_3c;
  
  if (param3 == (ModelInstance *)0x0) {
                    
    OSPanic("objprint_dolphin.c",0x3ae,"Failed assertion modelInstance");
  }
  if (param4 == (BitStream *)0x0) {
                    
    OSPanic("objprint_dolphin.c",0x3af,"Failed assertion renderStream");
  }
  shaderNum = bitStream_read(param4,6);
  pcVar1 = (code *)modelInstanceGetCallback30(param3);
  if (pcVar1 == (code *)0x0) {
    DAT_80398b0c = shaderNum;
    param2_00 = modelGetShader(param3->model,shaderNum);
    param3_00 = (int *)Model_getShaderTexture(param3,shaderNum);
    FUN_800a11d4();
    if (((*param3_00 != 0) || (param3_00[1] != 0)) && (param2_00->tex34 != (Texture *)0x0)) {
      if ((param2_00->field_0x3a & 1) == 0) {
                    
        OSPanic("objprint_dolphin.c",0x3d1,s_Failed_assertion_shader_>inputFo_802ee7dc);
      }
      iVar3 = DAT_80398b1c + 1;
      if (*param3_00 != 0) {
        iVar3 = DAT_80398b1c + 2;
      }
      if (param3_00[1] != 0) {
        iVar3 = iVar3 + 1;
      }
      if (param2_00->tex18 != (undefined4 *********)0x0) {
        iVar3 = iVar3 + 1;
      }
      if (param2_00->layer[0].texture == (Texture *)0x0) {
        uVar2 = 1;
      }
      else {
        uVar2 = (uint)(param2_00->layer[0].texture)->width / (uint)param2_00->tex34->width;
      }
      shaderFn_800a2634((int)param2_00->tex34,iVar3,uVar2);
    }
    if (*param3_00 != 0) {
      shaderFn_800a2168(*param3_00);
    }
    if (param3_00[1] == 0) {
      local_48 = DAT_80396d3c;
      GXSetTevColor(3,(byte *)&local_48);
    }
    else {
      shaderFn_800a2344(param3_00[1],*param3_00 != 0);
    }
    for (iVar3 = 0; iVar3 < DAT_80398b1c; iVar3 = iVar3 + 1) {
      param1_00 = FUN_800769c0((&DAT_80398b10)[iVar3]);
      if (param1_00 == 0) {
                    
        OSPanic("objprint_dolphin.c",0x405,"Failed assertion texture");
      }
      FUN_80076cc8((&DAT_80398b10)[iVar3],&local_3c,&local_40);
      param2_01 = (Mtx43 *)lightFn_80076c6c((Light *)(&DAT_80398b10)[iVar3]);
      shaderFn_800a28c8(param1_00,param2_01,local_3c,local_40,(uint)(byte)(&DAT_80398b18)[iVar3]);
    }
    uVar2 = shaderTevColorFn_80097cd4
                      (param1,param2_00,param3_00,0x80,*(ushort *)(param2 + 0xa6) & 2);
    if ((uVar2 & 0xff) == 0) {
      shaderFn_800a2554();
    }
    shaderTevColorFn_80097cd4(param1,param2_00,param3_00,0,*(ushort *)(param2 + 0xa6) & 2);
    if ((*(byte *)(param1 + 0xe5) & 2) != 0) {
      local_44 = *(undefined *)(param1 + 0xec);
      local_43 = *(undefined *)(param1 + 0xed);
      local_42 = *(undefined *)(param1 + 0xee);
      local_41 = *(undefined *)(param1 + 0xef);
      shaderTevStageColorFn_800a1504((undefined4 *)&local_44);
    }
    _gxSetupTexGens();
    if ((*(char *)(param1 + 0x37) == -1) && ((param2_00->attributes & BlendModeFlag40) == 0)) {
      if ((param2_00->attributes & BlendModeFlag10) == 0) {
        GXSetBlendMode(0,1,0,5);
        GXSetZMode(true,GX_LEQUAL,true);
        GXSetZCompLoc(1);
        GXSetAlphaCompare(7,0,0,7,0);
      }
      else {
        GXSetBlendMode(0,1,0,5);
        GXSetZMode(true,GX_LEQUAL,true);
        GXSetZCompLoc(0);
        GXSetAlphaCompare(4,10,0,4,10);
      }
    }
    else {
      GXSetBlendMode(1,4,5,5);
      GXSetZMode(true,GX_LEQUAL,false);
      GXSetZCompLoc(1);
      GXSetAlphaCompare(7,0,0,7,0);
    }
    if ((param2_00->attributes & BackfaceCulling) == 0) {
      GXSetCullMode(GX_CULL_NONE);
    }
    else {
      GXSetCullMode(GX_CULL_BACK);
    }
  }
  else {
    (*pcVar1)(param1,param3,shaderNum);
  }
  return shaderNum;
}


/* WARNING: Type propagation algorithm not settling */
/* Library Function - Single Match
    shaderTevColorFn_80097cd4
   
   Library: KioskDefault 0 0 */

int shaderTevColorFn_80097cd4(int param1,Shader *param2,int *param3,uint param4,int param5) { //80097CD4
  undefined uVar1;
  ShaderLayer *pSVar2;
  ShaderLayer *unaff_r20;
  byte bVar3;
  int iVar4;
  Mtx43 *param2_00;
  uint param3_00;
  int iVar5;
  undefined4 local_7c;
  float local_78;
  float local_74;
  Mtx43 MStack_70;
  Texture *local_40 [3];
  
  iVar4 = 1;
  if ((*param3 != 0) || (param3[1] != 0)) {
    bVar3 = 0;
    for (iVar5 = 0; iVar5 < (int)(uint)param2->numLayers; iVar5 = iVar5 + 1) {
      pSVar2 = shaderGetLayer(param2,iVar5);
      if ((pSVar2->field_0x4 & 0x80) != 0) {
        bVar3 = bVar3 + 1;
      }
    }
    if (1 < bVar3) {
      iVar4 = 0;
    }
  }
  iVar5 = 0;
  do {
    if ((int)(uint)param2->numLayers <= iVar5) {
      return iVar4;
    }
    pSVar2 = shaderGetLayer(param2,iVar5);
    if (((byte)pSVar2->field_0x4 & 0x80) == param4) {
      uVar1 = (undefined)((*(byte *)(param1 + 0x37) + 1) * (uint)(byte)param2->field_0xc >> 8);
      if (pSVar2->texture == (Texture *)0x0) {
        local_7c._0_1_ = param2->field_0x4;
        local_7c._1_1_ = param2->field_0x5;
        local_7c._2_1_ = param2->field_0x6;
        if (*param3 == 0) {
          if (param5 == 0) {
            if ((param2->field_0x3a & 0x10) == 0) {
              local_7c._3_1_ = uVar1;
              gxAddTevStageWithColor(&local_7c);
            }
            else {
              local_7c._3_1_ = uVar1;
              gxAddTevStage();
            }
          }
          else {
            if ((param2->field_0x3a & 2) != 0) {
              local_7c._3_1_ = uVar1;
                    
              OSPanic("objprint_dolphin.c",0x4f2,
                      s_Failed_assertion___shader_>input_802ee854);
            }
            if (param2->numLayers != 1) {
              local_7c._3_1_ = uVar1;
                    
              OSPanic("objprint_dolphin.c",0x4f3,
                      s_Failed_assertion_shader_>numMate_802ee894);
            }
            local_7c._3_1_ = uVar1;
            FUN_800d568c((undefined *)&local_7c,(undefined *)((int)&local_7c + 1),
                         (undefined *)((int)&local_7c + 2));
            gxAddTevStage_800a138c(&local_7c);
          }
        }
        else {
          local_7c._3_1_ = uVar1;
          gxAddTevStage_800a138c(&local_7c);
        }
      }
      else {
        if (pSVar2->field_0x5 == '\0') {
          local_40[0] = pSVar2->texture;
          param2_00 = (Mtx43 *)0x0;
        }
        else {
          shaderTexFrameFn_80098814
                    (param1,(uint)(byte)pSVar2->field_0x5,(int)pSVar2->texture,(int *)local_40);
          FUN_80098748(param1,(uint)(byte)pSVar2->field_0x5,&local_74,&local_78);
          MTXTrans((double)local_74,(double)local_78,0.0,&MStack_70.m11);
          param2_00 = &MStack_70;
        }
        if (iVar5 == 0) {
          if (((*param3 == 0) && (param3[1] == 0)) || (iVar4 == 0)) {
            param3_00 = 0;
            local_7c._3_1_ = uVar1;
          }
          else {
            param3_00 = 8;
            local_7c._3_1_ = uVar1;
          }
        }
        else {
          param3_00 = (byte)unaff_r20->field_0x4 & 0x7f;
          local_7c._3_1_ = 0xff;
        }
        local_7c._0_1_ = 0xff;
        local_7c._1_1_ = 0xff;
        local_7c._2_1_ = 0xff;
        if (*param3 == 0) {
          if (param5 == 0) {
            if ((param2->field_0x3a & 0x10) == 0) {
              gxAddTevStageTexGenColor((int)local_40[0],param2_00,param3_00,&local_7c);
            }
            else {
              shaderFn_800a1e28((int)local_40[0],param2_00,param3_00);
            }
          }
          else {
            if ((param2->field_0x3a & 2) != 0) {
                    
              OSPanic("objprint_dolphin.c",0x4d1,
                      s_Failed_assertion___shader_>input_802ee854);
            }
            if (param2->numLayers != 1) {
                    
              OSPanic("objprint_dolphin.c",0x4d2,
                      s_Failed_assertion_shader_>numMate_802ee894);
            }
            FUN_800d568c((undefined *)&local_7c,(undefined *)((int)&local_7c + 1),
                         (undefined *)((int)&local_7c + 2));
            gxAddTevStageTexGen_800a190c((int)local_40[0],param2_00,param3_00,&local_7c);
          }
        }
        else {
          gxAddTevStageTexGen_800a190c((int)local_40[0],param2_00,param3_00,&local_7c);
        }
      }
    }
    iVar5 = iVar5 + 1;
    unaff_r20 = pSVar2;
  } while( true );
}


/* Library Function - Single Match
    renderOpCallDlist
   
   Library: KioskDefault 0 0 */

void renderOpCallDlist(Model *model,BitStream *stream,char *param3) { //80098024
  uint listNum;
  DisplayList *pDVar1;
  
  if (model == (Model *)0x0) {
                    
    OSPanic("objprint_dolphin.c",0x521,"Failed assertion model");
  }
  if (stream == (BitStream *)0x0) {
                    
    OSPanic("objprint_dolphin.c",0x522,"Failed assertion renderStream");
  }
  listNum = bitStream_read(stream,6);
  pDVar1 = modelGetDisplayList(model,listNum);
  if ((pDVar1->length != 0) && ((pDVar1->length & 0x1f) == 0)) {
    if (((bDisableSky != '\x06') || (DAT_80398b08 == DAT_80398b0c)) &&
       ((bDisableSky != '\x02' && (bDisableSky != '\x04')))) {
      GXCallDisplayList(pDVar1->displayList,(uint)pDVar1->length);
    }
    return;
  }
                    
  OSPanic("objprint_dolphin.c",0x527,s_Failed_assertion_displayList_>di_802ee8f4);
}


/* Library Function - Single Match
    objPrintLightFn_8009846c
   
   Library: KioskDefault 0 0 */

void objPrintLightFn_8009846c(int param1,ObjInstance *param2) { //8009846C
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint param5;
  int iVar4;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44 [8];
  int local_24;
  
  bVar1 = *(byte *)(param1 + 0x24);
  if ((*(ushort *)(param1 + 0xa6) & 2) == 0) {
    FUN_80075654(0);
    lightFn_800757ec(0,0,(uint)((bVar1 & 2) != 0));
    if ((*(ushort *)(param1 + 0xa6) & 9) == 0) {
      if ((*(ushort *)(param1 + 0xa6) & 0xc) == 0) {
        param5 = 6;
        FUN_8007534c((undefined *)&local_48,(undefined *)((int)&local_48 + 1),
                     (undefined *)((int)&local_48 + 2));
        local_50 = local_48;
        GXSetChanAmbColor(0,(byte *)&local_50);
      }
      else {
        param5 = 2;
        local_4c = DAT_80396d3c;
        GXSetChanAmbColor(0,(byte *)&local_4c);
      }
      lightControlGetLightsNearObject((int)param2,(int)local_44,8,&local_24,param5);
      if (8 < local_24) {
                    
        OSPanic("objprint_dolphin.c",0x63f,s_Failed_assertion_numLights<_MAX__802ee9f8);
      }
      if (local_24 == 0) {
        local_54 = DAT_80396d3c;
        GXSetChanMatColor(0,(byte *)&local_54);
      }
      else {
        local_58 = DAT_80396d38;
        GXSetChanMatColor(0,(byte *)&local_58);
      }
      for (iVar4 = 0; iVar4 < local_24; iVar4 = iVar4 + 1) {
        lightFn_800759b8(0,local_44[iVar4],param2);
      }
    }
    else if ((*(ushort *)(param1 + 0xa6) & 1) == 0) {
      local_60 = DAT_80396d3c;
      GXSetChanMatColor(0,(byte *)&local_60);
    }
    else {
      local_5c = DAT_80396d38;
      GXSetChanMatColor(0,(byte *)&local_5c);
    }
    DAT_80398b1c = 0;
    if (*(char *)(param1 + 0xbc) != '\0') {
      lightControlGetLightsNearObject
                ((int)param2,-0x7fc674f0,(uint)*(byte *)(param1 + 0xbc),&DAT_80398b1c,8);
      if (2 < DAT_80398b1c) {
                    
        OSPanic("objprint_dolphin.c",0x663,"Failed assertion numProjectedTextureLights<=2");
      }
      bVar2 = false;
      for (iVar4 = 0; iVar4 < DAT_80398b1c; iVar4 = iVar4 + 1) {
        iVar3 = FUN_800763dc((&DAT_80398b10)[iVar4]);
        if ((bVar2) || (iVar3 != 1)) {
          if (iVar4 == 0) {
            DAT_80398b18 = 2;
          }
          else {
            (&DAT_80398b18)[iVar4] = 3;
          }
        }
        else {
          (&DAT_80398b18)[iVar4] = 1;
          bVar2 = true;
        }
        lightFn_800757ec((uint)(byte)(&DAT_80398b18)[iVar4],0,0);
        lightFn_800759b8((uint)(byte)(&DAT_80398b18)[iVar4],(&DAT_80398b10)[iVar4],param2);
        local_64 = DAT_80396d40;
        GXSetChanAmbColor((uint)(byte)(&DAT_80398b18)[iVar4],(byte *)&local_64);
        local_68 = DAT_80396d38;
        GXSetChanMatColor((uint)(byte)(&DAT_80398b18)[iVar4],(byte *)&local_68);
      }
    }
    lightFn_800756a0();
  }
  else {
    GXSetNumChans(0);
  }
  return;
}


/* Library Function - Single Match
    shaderTexFrameFn_80098814
   
   Library: KioskDefault 0 0 */

void shaderTexFrameFn_80098814(int param1,uint param2,int param3,int *param4) { //80098814
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(*(int *)(param1 + 0x50) + 0x71) <= iVar1) {
      *param4 = param3;
      return;
    }
    if (param2 == *(byte *)(*(int *)(*(int *)(param1 + 0x50) + 0xc) + iVar1 * 2 + 1)) break;
    iVar1 = iVar1 + 1;
  }
  iVar1 = FUN_800a48ec(param3,*(int *)(*(int *)(param1 + 0x70) + iVar1 * 0x10));
  *param4 = iVar1;
  if (*param4 != 0) {
    return;
  }
                    
  OSPanic("objprint_dolphin.c",0x6d6,"Failed assertion *textureFrame");
}

