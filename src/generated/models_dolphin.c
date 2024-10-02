
/* Library Function - Single Match
    createModelInstance
   
   Library: KioskDefault 0 0 */

ModelInstance * ModelInstance_createModelInstance(Model *model,uint flags) { //8007C5B4
  byte bVar1;
  ModelInstance *minst;
  uint size;
  Mtx44 *buf;
  AnimInstance *anim;
  uint buf3;
  uint uVar2;
  float *pfVar3;
  ShaderDef *pSVar4;
  int iVar5;
  AnimInstance *buf4;
  AnimInstance *pAVar6;
  short *psVar7;
  void *pvVar8;
  vec3s *pvVar9;
  undefined **param1;
  float local_40;
  float local_30;
  uint local_2c;
  
  if (model == (Model *)0x0) {
    printf("WARNING _ createModelInstance called with NULL pointer");
    minst = (ModelInstance *)0x0;
  }
  else {
    size = Model_setupAnimInstance(model,flags,(AnimInstance *)&stack0xffffffbc,0);
    minst = (ModelInstance *)mmAlloc(size,ModelInstance,"minst");
    if (minst == (ModelInstance *)0x0) {
      minst = (ModelInstance *)0x0;
    }
    else {
      memclr(minst,size);
      buf = (Mtx44 *)alignTo16(&minst->field26_0x54);
      minst->mtxs[0] = buf;
      buf = (Mtx44 *)((int)&buf->m11 + ((int)local_2c >> 1));
      minst->mtxs[1] = buf;
      psVar7 = (short *)((int)&buf->m11 + ((int)local_2c >> 1));
      minst->field21_0x4c = (byte *)minst->mtxs[0];
      if ((model->bCopyVtxsToModelInst == 0) && (model->skin2Matrices == (void *)0x0)) {
        minst->vertexPositions[0] = model->vertexPositions;
        minst->vertexPositions2 = (int)model->vertexPositions;
      }
      else {
        pvVar9 = (vec3s *)((int)psVar7 + 0x1fU & 0xffffffe0);
        minst->vertexPositions[0] = pvVar9;
        psVar7 = &pvVar9->x + (uint)model->numPositions * 3;
        minst->vertexPositions2 = (int)psVar7;
        psVar7 = psVar7 + (uint)model->numPositions * 3;
        memcpy(minst->vertexPositions[0],model->vertexPositions,(uint)model->numPositions * 6);
        DCFlushRange(minst->vertexPositions[0],(uint)model->numPositions * 6);
      }
      anim = (AnimInstance *)alignTo4((uint)psVar7);
      minst->animInstances[0] = anim;
      pvVar9 = (vec3s *)&anim->field_0x68;
      if ((flags & 0x80) != 0) {
        minst->animInstances[1] = (AnimInstance *)pvVar9;
        pvVar9 = (vec3s *)&anim->field151_0xd0;
      }
      if ((model->flags & UseLocalModAnimTab) != 0) {
        buf3 = alignTo64((uint)pvVar9);
        buf4 = minst->animInstances[0];
        buf4->field7_0x1c = (void *)buf3;
        buf4->field8_0x20 = (void *)(buf3 + (int)local_30);
        pvVar8 = (void *)((int)(void *)(buf3 + (int)local_30) + (int)local_30);
        buf4->field9_0x24 = pvVar8;
        pvVar8 = (void *)((int)pvVar8 + (int)local_30);
        buf4->field10_0x28 = pvVar8;
        pvVar9 = (vec3s *)((int)pvVar8 + (int)local_30);
        if (minst->animInstances[1] != (AnimInstance *)0x0) {
          pAVar6 = minst->animInstances[1];
          pAVar6->field7_0x1c = pvVar9;
          pvVar8 = (void *)((int)&pvVar9->x + (int)local_30);
          pAVar6->field8_0x20 = pvVar8;
          pvVar8 = (void *)((int)pvVar8 + (int)local_30);
          pAVar6->field9_0x24 = pvVar8;
          pvVar8 = (void *)((int)pvVar8 + (int)local_30);
          pAVar6->field10_0x28 = pvVar8;
          pvVar9 = (vec3s *)((int)pvVar8 + (int)local_30);
        }
      }
      if (model->bCopyVtxsToModelInst != 0) {
        pvVar9 = (vec3s *)alignTo4((uint)pvVar9);
        minst->vertexPositions[1] = pvVar9;
        pvVar9 = pvVar9 + 8;
        for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
          psVar7 = &minst->vertexPositions[1]->x + iVar5 * 8;
          *(undefined *)(psVar7 + 6) = 0xff;
          *(undefined *)((int)psVar7 + 0xd) = 0xff;
          *(float *)psVar7 = 0.0;
          *(float *)(psVar7 + 2) = 0.0;
          *(float *)(psVar7 + 4) = 0.0;
        }
      }
      if (0 < (int)local_40) {
        uVar2 = alignTo4((uint)pvVar9);
        minst->field16_0x38 = uVar2;
        iVar5 = uVar2 + (uint)model->nHitSpheres * 0x10;
        minst->field17_0x3c = iVar5;
        pvVar9 = (vec3s *)(iVar5 + (uint)model->nHitSpheres * 0x10);
        minst->field18_0x40 = minst->field16_0x38;
      }
      if ((((model->joints == (Bone *)0x0) || (model->animLength == 0)) ||
          (model->radi == (float *)0x0)) || (model->exT == (u32 *)0x0)) {
        minst->field7_0x14 = (float *)0x0;
      }
      else {
        pfVar3 = (float *)alignTo4((uint)pvVar9);
        minst->field7_0x14 = pfVar3;
        pfVar3 = pfVar3 + 7;
        *minst->field7_0x14 = (float)pfVar3;
        pfVar3 = pfVar3 + (uint)model->animLength * 3;
        minst->field7_0x14[1] = (float)pfVar3;
        pfVar3 = pfVar3 + model->animLength;
        minst->field7_0x14[2] = (float)pfVar3;
        pfVar3 = pfVar3 + model->animLength;
        minst->field7_0x14[3] = (float)pfVar3;
        pfVar3 = pfVar3 + model->animLength;
        minst->field7_0x14[4] = (float)pfVar3;
        bVar1 = model->animLength;
        minst->field7_0x14[6] = (float)(pfVar3 + bVar1);
        pvVar9 = (vec3s *)((int)(pfVar3 + bVar1) + (uint)model->animLength);
      }
      if (model->skin2Matrices != (void *)0x0) {
        uVar2 = alignTo4((uint)pvVar9);
        minst->field15_0x34 = uVar2;
        pvVar9 = (vec3s *)(uVar2 + (uint)model->field48_0x72 * 4);
      }
      pSVar4 = (ShaderDef *)alignTo4((uint)pvVar9);
      minst->shaderDefs = pSVar4;
      param1 = &pSVar4->texture + (uint)model->nShaders * 2;
      if ((flags & 0x8000) != 0) {
        uVar2 = aignTo2((uint)param1);
        minst->field19_0x44 = uVar2;
        param1 = (undefined **)(uVar2 + 0x1a);
        *(undefined *)(minst->field19_0x44 + 0x18) = 0;
      }
      if ((int)size <= (int)param1 - (int)minst) {
        printf("DANGER: createModelInstance: Actual size exceeded totalsize!!!");
      }
      minst->field20_0x48 = (void *)0x0;
      minst->model = model;
      minst->field22_0x50 = 0;
    }
  }
  return minst;
}


uint modelGetAmapSize(uint id,int noAmap,int nAnimations) { //8007CBD0
  uint uVar1;
  
  if (noAmap == 0) {
    for (uVar1 = nAnimations << 2; (uVar1 & 7) != 0; uVar1 = uVar1 + 1) {
    }
    loadDataFileWithLength(AMAP.TAB,pAmapTab,(id & 0xfffffffc) << 2,0x20);
    uVar1 = uVar1 + (pAmapTab[(id & 3) + 1] - pAmapTab[id & 3]);
  }
  else {
    for (uVar1 = nAnimations * 2 + 8; (uVar1 & 7) != 0; uVar1 = uVar1 + 1) {
    }
  }
  return uVar1;
}


/* Library Function - Single Match
    makeModelAnimation
   
   Library: KioskDefault 0 0 */

undefined4 Model_makeModelAnimation(Model *model,uint animId,HitSpherePos *hits) { //8007CC94
  uint uVar1;
  u32 uVar2;
  Animation *pAVar3;
  u32 uVar4;
  uint offset;
  int iVar5;
  int animBank;
  int iVar6;
  uint uVar7;
  HitSpherePos *pHVar8;
  uint size;
  u32 *amap;
  
  amap = pAmapTab;
  uVar7 = 0;
  loadDataFileWithLength(MODANIM.TAB,pAmapTab,animId << 1,0x10);
  offset = (uint)*(short *)amap;
  size = (int)((int)*(short *)((int)amap + 2) - offset) >> 1;
  if (size != model->animBufSize) {
    printf("makeModelAnimation() size mismatch!! (%d,%d)",(uint)model->animBufSize,size);
    model->animBufSize = (ushort)size;
  }
  if (model->animBufSize != 0) {
    size = (uint)model->animBufSize * 2 + 8;
    if (0x800 < size) {
      debugPrint("Warning: Model animation buffer overflow!! size=%d",size);
    }
    loadDataFileWithLength(AMAP.TAB,pAmapTab,(animId & 0xfffffffc) << 2,0x20);
    uVar1 = animId & 3;
    model->animOffset = pAmapTab[uVar1];
    uVar4 = pAmapTab[uVar1];
    uVar2 = pAmapTab[uVar1 + 1];
    if ((model->flags & UseLocalModAnimTab) == 0) {
      loadDataFileWithLength(MODANIM.BIN,globalModAnimBuffer,offset,size);
      model->animIds = (HitSpherePos *)globalModAnimBuffer;
    }
    else {
      model->animIds = hits;
      for (uVar7 = size; (uVar7 & 7) != 0; uVar7 = uVar7 + 1) {
      }
      hits = (HitSpherePos *)((int)&hits->radius + uVar7);
      loadDataFileWithLength(MODANIM.BIN,model->animIds,offset,uVar7);
    }
    *(undefined2 *)&model->field29_0x58 = 0;
    animBank = 1;
    for (iVar6 = 0; iVar6 < (int)(uint)model->animBufSize; iVar6 = iVar6 + 1) {
      iVar5 = animBank;
      if (*(short *)((int)&model->animIds->radius + iVar6 * 2) == -1) {
        iVar5 = animBank + 1;
        *(short *)((int)&model->field29_0x58 + animBank * 2) = (short)iVar6 + 1;
      }
      animBank = iVar5;
    }
    if (8 < animBank) {
      printf("ANIMBANK overflow");
    }
    if ((model->flags & UseLocalModAnimTab) == 0) {
      model->animIds = (HitSpherePos *)0x0;
      model->field26_0x4c = hits;
      pHVar8 = (HitSpherePos *)(&hits->radius + model->animBufSize);
      for (uVar7 = uVar7 + (uint)model->animBufSize * 4; (uVar7 & 7) != 0; uVar7 = uVar7 + 1) {
        pHVar8 = (HitSpherePos *)((int)&pHVar8->radius + 1);
      }
      model->curHitSpherePos = pHVar8;
      loadDataFileWithLength(AMAP.BIN,model->curHitSpherePos,model->animOffset,uVar2 - uVar4);
      animBank = 0;
      do {
        if (globalModAnimBuffer[animBank] == 0xffff) {
          (&model->field26_0x4c->radius)[animBank] = 0.0;
        }
        else {
          pAVar3 = loadAnimation(model,globalModAnimBuffer[animBank],(short)animBank,(void *)0x0);
          (&model->field26_0x4c->radius)[animBank] = (float)pAVar3;
          if ((&model->field26_0x4c->radius)[animBank] == 0.0) {
            for (iVar6 = 0; iVar6 < animBank; iVar6 = iVar6 + 1) {
              unloadAnimation((s8 *)(&model->field26_0x4c->radius)[iVar6]);
            }
            model->field26_0x4c = (HitSpherePos *)0x0;
            return 1;
          }
        }
        animBank = animBank + 1;
      } while (animBank < (int)(uint)model->animBufSize);
    }
    else {
      model->field26_0x4c = (HitSpherePos *)0x0;
    }
  }
  return 0;
}


void modelSetupAnims(ModelInstance *minst,AnimInstance *param2) { //8007CFA4
  float fVar1;
  Model *model;
  
  param2->field20_0x44 = 0;
  param2->field39_0x5e = 0;
  param2->field36_0x58 = 0;
  param2->field37_0x5a = 0;
  param2->field38_0x5c = 0;
  param2->field3_0xc = 0.0;
  param2->hitboxSize = 0.0;
  param2->field5_0x14 = 0.0;
  param2->field40_0x60 = 0;
  model = minst->model;
  if (model->animBufSize != 0) {
    if ((model->flags & UseLocalModAnimTab) == 0) {
      fVar1 = (&model->field26_0x4c->radius)[param2->field20_0x44];
    }
    else {
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->field7_0x1c);
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->field8_0x20);
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->field9_0x24);
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->field10_0x28);
      param2->field20_0x44 = 0;
      fVar1 = (float)((int)(&param2->field7_0x1c)[param2->field20_0x44] + 0x80);
    }
    param2->y = (int)fVar1 + 6;
    param2->field40_0x60 = *(byte *)((int)fVar1 + 1) & 0xf0;
    param2->field5_0x14 =
         (float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param2->y + 1)) - 4503599627370496.0);
    if (param2->field40_0x60 == 0) {
      param2->field5_0x14 = param2->field5_0x14 - 1.0;
    }
    param2->field41_0x61 = param2->field40_0x60;
    param2->z = param2->y;
    param2->field21_0x46 = param2->field20_0x44;
    param2->field2_0x8 = param2->hitboxSize;
    param2->mtxSize = (uint)param2->field5_0x14;
    param2->field4_0x10 = param2->field3_0xc;
    param2->field18_0x3c = param2->y;
    param2->field22_0x48 = param2->field20_0x44;
    param2->field19_0x40 = param2->y;
    param2->field23_0x4a = param2->field20_0x44;
  }
  return;
}


/* Library Function - Single Match
    allocModelGlobalAnimBuffer
   
   Library: KioskDefault 0 0 */

void initModels(void) { //8007DAB0
  u16 *puVar1;
  
  modelsLoadedTable = SparseArray_create(0x8c,4);
  if (modelsLoadedTable == (SparseArray *)0x0) {
                    
    OSPanic("models_dolphin.c",0xa4,"Failed assertion modelsLoadedTable");
  }
  animsLoadedTable = SparseArray_create(0xc4,4);
  if (animsLoadedTable == (SparseArray *)0x0) {
                    
    OSPanic("models_dolphin.c",0xa9,"Failed assertion animsLoadedTable");
  }
  puVar1 = (u16 *)mmAlloc(0x830,ANIMS_COL,"mod:globalAnimBuffer");
  if (puVar1 == (u16 *)0x0) {
                    
    OSPanic("models_dolphin.c",0xae,"Failed assertion mem");
  }
  pAmapTab = (u32 *)(puVar1 + 0x400);
  globalModAnimBufferPlus0x810 = (undefined *)(puVar1 + 0x408);
  globalModAnimBuffer = puVar1;
  countModels();
  return;
}


/* Library Function - Single Match
    getModelInstance
   
   Library: KioskDefault 0 0 */

ModelInstance * loadModelInstance(int id,uint flags) { //8007DB84
  uint modelNum;
  BOOL BVar1;
  int iVar2;
  ModelInstance *minst;
  Model *model;
  
  modelNum = Model_lookupModelInd(id);
  if (((int)modelNum < 0) || (maxModelNum <= (int)modelNum)) {
                    
    OSPanic("models_dolphin.c",0xd2,s_Failed_assertion_modelNum>_0____m_802eb71c);
  }
  BVar1 = SparseArray_get(modelsLoadedTable,modelNum,&model);
  if (BVar1 == FALSE) {
    model = Model_load(modelNum);
    if (model == (Model *)0x0) {
                    
      OSPanic("models_dolphin.c",0xda,"Failed assertion model");
    }
    iVar2 = isModelAnimDisabled();
    if (iVar2 != 0) {
      model->flags = model->flags | NoAnimations;
    }
    Model_initPtrs(model);
    Model_loadTextures(model);
    Model_loadShaderTextures(model);
    Model_makeModelAnimation(model,modelNum,(HitSpherePos *)(&model->usage + model->dataSize));
    SpareArray_set(modelsLoadedTable,(short)modelNum,&model);
  }
  else {
    model->usage = model->usage + 1;
    if (model->usage == 0xff) {
                    
      OSPanic("models_dolphin.c",0xed,s_Failed_assertion_model_>usage<UC_802eb76c);
    }
  }
  countLeadingZeros(1 - (uint)model->usage);
  minst = ModelInstance_createModelInstance(model,flags);
  if (minst == (ModelInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0xf3,"Failed assertion modelInstance");
  }
  modelSetupAnims(minst,minst->animInstances[0]);
  if (minst->animInstances[1] != (AnimInstance *)0x0) {
    modelSetupAnims(minst,minst->animInstances[1]);
  }
  FUN_8007e76c(model,minst);
  iVar2 = Model_checksumHeader(model);
  model->headerCksum = iVar2;
  DCStoreRange(model,model->dataSize);
  return minst;
}


/* Library Function - Single Match
    modelFn_8007dd68
   
   Library: KioskDefault 0 0 */

void modelInstanceFree(ModelInstance *modelInstance) { //8007DD68
  byte bVar1;
  Model *model;
  
  if (modelInstance == (ModelInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0x11d,"Failed assertion modelInstance");
  }
  ModelInstance_unloadShaders((Model *)modelInstance);
                    /* XXX this should be Model* but seems to be BitStream? */
  model = modelInstance->model;
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x124,"Failed assertion model");
  }
  if (modelInstance->field20_0x48 != (void *)0x0) {
    mm_free(modelInstance->field20_0x48);
  }
  mm_free(modelInstance);
  bVar1 = model->usage - 1;
  model->usage = bVar1;
  if (bVar1 == 0) {
    sparseArrayRemove((short **)modelsLoadedTable,(uint)(ushort)model->cacheModNo);
    texFreeFn_8007e0a8((int)model);
    animUnloadFn_8007e0f8((int)model);
    mm_free(model);
  }
  return;
}


int Model_checksumHeader(Model *model) { //8007DE30
  byte *pbVar1;
  int iVar2;
  int *end;
  
  iVar2 = 0;
  end = &model->dataSize;
  pbVar1 = &model->usage;
  for (; model < (Model *)(pbVar1 + *end); model = (Model *)&model->field_0x1) {
    iVar2 = iVar2 + (uint)model->usage;
  }
  return iVar2;
}


/* Library Function - Single Match
    modelFn_8007de70
   
   Library: KioskDefault 0 0 */

Model * Model_load(uint id) { //8007DE70
  uint *modelsTab;
  uint amapSize;
  uint offset;
  int noAmap;
  uint animCacheSize;
  undefined4 nAnimations;
  size_t size;
  Model *model;
  
  modelsTab = (uint *)getTable(MODELS.tab);
  offset = modelsTab[id];
  loadModelsBin(offset,&nAnimations,&animCacheSize,&noAmap,(int *)&size);
  animCacheSize = alignTo64(animCacheSize);
  animCacheSize = animCacheSize + 0xb0;
  amapSize = modelGetAmapSize(id,noAmap,nAnimations);
  model = (Model *)mmAlloc(size + amapSize + 500,MODELS_COL,"mod");
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x1eb,"Failed assertion model");
  }
  model = (Model *)alignTo16(model);
  loadAndDecompressDataFile(MODELS.bin,(byte *)model,offset,size,(uint *)0x0,id,0);
  model->animCacheSize = (short)animCacheSize;
  model->cacheModNo = (short)id;
  model->animBufSize = nAnimations._2_2_;
  model->flags = model->flags & ~UseLocalModAnimTab;
  model->usage = 1;
  if (model->animBufSize == 0) {
    model->flags = model->flags | NoAnimations;
  }
  if (noAmap != 0) {
    model->flags = model->flags | UseLocalModAnimTab;
  }
  return model;
}


/* Library Function - Single Match
    modelFn_8007dff4
   
   Library: KioskDefault 0 0 */

void Model_loadTextures(Model *model) { //8007DFF4
  Texture *tex;
  int iTex;
  
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x21d,"Failed assertion model");
  }
  iTex = 0;
  while( true ) {
    if ((int)(uint)model->numTextures <= iTex) {
      return;
    }
    tex = textureLoad(-((uint)(&model->GCtextures->next)[iTex] | 0x8000));
    (&model->GCtextures->next)[iTex] = tex;
    if ((&model->GCtextures->next)[iTex] == (Texture *)0x0) break;
    iTex = iTex + 1;
  }
                    
  OSPanic("models_dolphin.c",0x222,s_Failed_assertion_model_>GCtextur_802ebb1c);
}


/* Library Function - Single Match
    modelInitPtrs
   
   Library: KioskDefault 0 0 */

void Model_initPtrs(Model *model) { //8007E1B8
  int iVar1;
  void *modelEnd;
  
  modelEnd = &model->usage + model->dataSize;
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x28a,"Failed assertion model");
  }
  if ((model->sphereHits != (void *)0x0) &&
     ((model->sphereHits = &model->usage + (int)model->sphereHits,
      (Model *)model->sphereHits < model || (modelEnd <= model->sphereHits)))) {
                    
    OSPanic("models_dolphin.c",0x28f,s_Failed_assertion_model_>sphereHi_802ebb44);
  }
  if (model->joints != (Bone *)0x0) {
    model->joints = (Bone *)(model->joints->idx + (int)&model->usage + -1);
    if (((Model *)model->joints < model) || (modelEnd <= model->joints)) {
                    
      OSPanic("models_dolphin.c",0x2a3,s_Failed_assertion_model_>joints>__802ebb90);
    }
    if ((model->radi != (float *)0x0) &&
       ((model->radi = (float *)(&model->usage + (int)model->radi), (Model *)model->radi < model ||
        (modelEnd <= model->radi)))) {
                    
      OSPanic("models_dolphin.c",0x2a7,s_Failed_assertion_model_>radi>_mo_802ebbd4);
    }
    if ((model->exT != (u32 *)0x0) &&
       ((model->exT = (u32 *)(&model->usage + (int)model->exT), (Model *)model->exT < model ||
        (modelEnd <= model->exT)))) {
                    
      OSPanic("models_dolphin.c",0x2ac,s_Failed_assertion_model_>exT>_mod_802ebc14);
    }
  }
  if ((model->GCtextures != (Texture *)0x0) &&
     ((model->GCtextures = (Texture *)((int)&model->GCtextures->next + (int)&model->usage),
      (Model *)model->GCtextures < model || (modelEnd <= model->GCtextures)))) {
                    
    OSPanic("models_dolphin.c",0x2b3,s_Failed_assertion_model_>GCtextur_802ebc54);
  }
  model->vertexPositions = (vec3s *)((int)&model->vertexPositions->x + (int)&model->usage);
  if (((Model *)model->vertexPositions < model) || (modelEnd <= model->vertexPositions)) {
                    
    OSPanic("models_dolphin.c",0x2b6,s_Failed_assertion_model_>vertexPo_802ebca0);
  }
  if ((model->vertexNormals != (vec3s *)0x0) &&
     ((model->vertexNormals = (vec3s *)((int)&model->vertexNormals->x + (int)&model->usage),
      (Model *)model->vertexNormals < model || (modelEnd <= model->vertexNormals)))) {
                    
    OSPanic("models_dolphin.c",699,s_Failed_assertion_model_>vertexNo_802ebcf8);
  }
  if ((model->vertexColours != (u16 *)0x0) &&
     ((model->vertexColours = (u16 *)(&model->usage + (int)model->vertexColours),
      (Model *)model->vertexColours < model || (modelEnd <= model->vertexColours)))) {
                    
    OSPanic("models_dolphin.c",0x2c1,s_Failed_assertion_model_>vertexCo_802ebd4c);
  }
  model->vertexTexCoords = (vec3s *)((int)&model->vertexTexCoords->x + (int)&model->usage);
  if (((Model *)model->vertexTexCoords < model) || (modelEnd <= model->vertexTexCoords)) {
                    
    OSPanic("models_dolphin.c",0x2c5,s_Failed_assertion_model_>vertexTe_802ebda0);
  }
  model->renderStream = (BitStream *)((int)&model->renderStream->data + (int)&model->usage);
  if (((Model *)model->renderStream < model) || (modelEnd <= model->renderStream)) {
                    
    OSPanic("models_dolphin.c",0x2c7,s_Failed_assertion_model_>renderSt_802ebdf8);
  }
  model->displayLists = (DisplayList *)((int)&model->displayLists->displayList + (int)&model->usage)
  ;
  if (((Model *)model->displayLists < model) || (modelEnd <= model->displayLists)) {
                    
    OSPanic("models_dolphin.c",0x2c9,s_Failed_assertion_model_>displayL_802ebe48);
  }
  if ((model->vertexAnims != (undefined4 *)0x0) &&
     ((model->vertexAnims = (undefined4 *)(&model->usage + (int)model->vertexAnims),
      (Model *)model->vertexAnims < model || (modelEnd <= model->vertexAnims)))) {
                    
    OSPanic("models_dolphin.c",0x2ce,s_Failed_assertion_model_>vertexAn_802ebe98);
  }
  if ((model->skin2Matrices != (void *)0x0) &&
     ((model->skin2Matrices = &model->usage + (int)model->skin2Matrices,
      (Model *)model->skin2Matrices < model || (modelEnd <= model->skin2Matrices)))) {
                    
    OSPanic("models_dolphin.c",0x2d3,s_Failed_assertion_model_>skin2Mat_802ebee8);
  }
  if ((model->skinWeights != (undefined *)0x0) &&
     ((model->skinWeights = model->skinWeights + (int)&model->usage,
      (Model *)model->skinWeights < model || (modelEnd <= model->skinWeights)))) {
                    
    OSPanic("models_dolphin.c",0x2d8,s_Failed_assertion_model_>skinWeig_802ebf3c);
  }
  if ((model->shaders != (Shader *)0x0) &&
     ((model->shaders = (Shader *)((int)model->shaders->layer + (int)&model->usage + -0x24),
      (Model *)model->shaders < model || (modelEnd <= model->shaders)))) {
                    
    OSPanic("models_dolphin.c",0x2dd,s_Failed_assertion_model_>shaders>_802ebf8c);
  }
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)model->field93_0xb8 <= iVar1) {
      for (iVar1 = 0; iVar1 < (int)(uint)model->bCopyVtxsToModelInst; iVar1 = iVar1 + 1) {
        model->vertexAnims[iVar1] = &model->usage + model->vertexAnims[iVar1];
        if (((Model *)model->vertexAnims[iVar1] < model) ||
           (modelEnd <= (void *)model->vertexAnims[iVar1])) {
                    
          OSPanic("models_dolphin.c",0x2e9,s_Failed_assertion_model_>vertexAn_802ec088);
        }
      }
      if ((model->GCpolygons != (undefined *)0x0) &&
         ((model->GCpolygons = model->GCpolygons + (int)&model->usage,
          (Model *)model->GCpolygons < model || (modelEnd <= model->GCpolygons)))) {
                    
        OSPanic("models_dolphin.c",0x2ef,s_Failed_assertion_model_>GCpolygo_802ec0dc);
      }
      if ((model->polygonGroups != (PolygonGroup *)0x0) &&
         ((model->polygonGroups =
                (PolygonGroup *)((int)&model->polygonGroups->firstPolygon + (int)&model->usage),
          (Model *)model->polygonGroups < model || (modelEnd <= model->polygonGroups)))) {
                    
        OSPanic("models_dolphin.c",0x2f5,s_Failed_assertion_model_>polygonG_802ec128);
      }
      return;
    }
    model->displayLists[iVar1].displayList =
         &model->usage + (int)model->displayLists[iVar1].displayList;
    if ((Model *)model->displayLists[iVar1].displayList < model) break;
    if (modelEnd <= model->displayLists[iVar1].displayList) break;
    if (((uint)model->displayLists[iVar1].displayList & 0x1f) != 0) {
                    
      OSPanic("models_dolphin.c",0x2e4,s_Failed_assertion___int_model_>di_802ec044);
    }
    iVar1 = iVar1 + 1;
  }
                    
  OSPanic("models_dolphin.c",0x2e3,s_Failed_assertion_model_>displayL_802ebfd4);
}


void Model_loadShaderTextures(Model *model) { //8007E814
  Shader *pSVar1;
  int iVar2;
  int iVar3;
  Shader *shader;
  
  for (iVar2 = 0; iVar2 < (int)(uint)model->nShaders; iVar2 = iVar2 + 1) {
    pSVar1 = model->shaders;
    for (iVar3 = 0; iVar3 < (int)(uint)pSVar1[iVar2].numLayers; iVar3 = iVar3 + 1) {
      if (pSVar1[iVar2].layer[iVar3].texture == (Texture *)0xffffffff) {
        pSVar1[iVar2].layer[iVar3].texture = (Texture *)0x0;
      }
      else {
        pSVar1[iVar2].layer[iVar3].texture =
             (&model->GCtextures->next)[(int)pSVar1[iVar2].layer[iVar3].texture];
      }
    }
    if (pSVar1[iVar2].tex34 == (Texture *)0xffffffff) {
      pSVar1[iVar2].tex34 = (Texture *)0x0;
    }
    else {
      pSVar1[iVar2].tex34 = (&model->GCtextures->next)[(int)pSVar1[iVar2].tex34];
    }
    if (pSVar1[iVar2].tex1C == (undefined4 *********)0xffffffff) {
      pSVar1[iVar2].tex1C = (undefined4 *********)0x0;
    }
    else if (pSVar1[iVar2].tex1C == (undefined4 *********)0xfffffffe) {
      pSVar1[iVar2].tex1C = (undefined4 *********)0x0;
    }
    else {
      pSVar1[iVar2].tex1C =
           (undefined4 *********)(&model->GCtextures->next)[(int)pSVar1[iVar2].tex1C];
    }
    if (pSVar1[iVar2].tex18 == (undefined4 *********)0xffffffff) {
      pSVar1[iVar2].tex18 = (undefined4 *********)0x0;
    }
    else {
      pSVar1[iVar2].tex18 =
           (undefined4 *********)(&model->GCtextures->next)[(int)pSVar1[iVar2].tex18];
    }
    if ((model->flagsA6 & 0xc) == 0) {
      pSVar1[iVar2].field8_0x8 = 0;
    }
    if ((model->flagsA6 & 0xe00) == 0) {
      pSVar1[iVar2].field17_0x14 = 0;
    }
  }
  return;
}


/* Library Function - Single Match
    modelAnimFn_8007e974
   
   Library: KioskDefault 0 0 */

void modelAnimFn_8007e974(ModelInstance *modelInstance,int model,int object,float *modelMatrix) { //8007E974
  AnimInstance *pAVar1;
  AnimInstance *anim;
  vec3s local_38;
  vec3f vStack_30;
  
  if (modelInstance == (ModelInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0x393,"Failed assertion modelInstance");
  }
  if (model == 0) {
                    
    OSPanic("models_dolphin.c",0x394,"Failed assertion model");
  }
  if (modelMatrix == (float *)0x0) {
                    
    OSPanic("models_dolphin.c",0x395,"Failed assertion modelMatrix");
  }
  if (object == 0) {
                    
    OSPanic("models_dolphin.c",0x396,"Failed assertion object");
  }
  tiltListFn_8007ebe8(object,(int)modelInstance,model);
  modelInstance_toggleFlag18_1(modelInstance);
  anim = modelInstance->animInstances[0];
  if (anim == (AnimInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0x39c,"Failed assertion animInstance");
  }
  if ((anim->field43_0x63 & 4) != 0) {
    objAnimFn_8008045c((double)*(float *)(object + 0x98),(double)*(float *)(object + 8),
                       modelInstance,0,0,&vStack_30,&local_38);
    DAT_8039872c = local_38.x;
    DAT_8039872e = local_38.y;
    DAT_80398730 = local_38.z;
  }
  if ((modelInstance->model->flags & 8) == 0) {
    if ((modelInstance->animInstances[0]->field43_0x63 & 8) == 0) {
      FUN_8007d1c4((double)*(float *)(object + 0x98),modelMatrix,modelInstance,
                   modelInstance->animInstances[0],0x7f);
      if ((modelInstance->animInstances[1] != (AnimInstance *)0x0) &&
         (-1 < *(short *)(object + 0xa2))) {
        FUN_8007d1c4((double)*(float *)(object + 0x9c),modelMatrix,modelInstance,
                     modelInstance->animInstances[1],0xffffffff);
      }
    }
    else {
      pAVar1 = modelInstance->animInstances[1];
      FUN_8007d678((double)*(float *)(object + 0x98),modelMatrix,(int *)modelInstance,(int)anim,0x7f
                   ,0,0,2,0x14,anim->field37_0x5a);
      FUN_8007d678((double)*(float *)(object + 0x9c),modelMatrix,(int *)modelInstance,(int)pAVar1,
                   0x7f,0,0,2,0x18,pAVar1->field37_0x5a);
      FUN_8007d678((double)*(float *)(object + 0x98),modelMatrix,(int *)modelInstance,(int)anim,0x7f
                   ,0,0,0,7,pAVar1->field36_0x58);
      FUN_8007d678((double)*(float *)(object + 0x98),modelMatrix,(int *)modelInstance,(int)anim,0x7f
                   ,0,1,1,1,anim->field36_0x58);
    }
  }
  else {
    FUN_8007d1c4((double)*(float *)(object + 0x98),modelMatrix,modelInstance,
                 modelInstance->animInstances[0],0x7f);
  }
  return;
}


/* Library Function - Single Match
    modelShaderFn_8007ef84
   
   Library: KioskDefault 0 0 */

int Model_getShaderTexture(ModelInstance *param1,int shaderNum) { //8007EF84
  if ((-1 < shaderNum) && (shaderNum < (int)(uint)param1->model->nShaders)) {
    return (int)(&param1->shaderDefs->texture + shaderNum * 2);
  }
                    
  OSPanic("models_dolphin.c",0x47a,s_Failed_assertion_shaderNum>_0____802ec1f4);
}


/* Library Function - Single Match
    modelInstGetjMtx
   
   Library: KioskDefault 0 0 */

int modelInstGetjMtx(ModelInstance *modelInstance,int param2) { //8007EFF0
  uint uVar1;
  
  if (modelInstance == (ModelInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0x491,"Failed assertion modelInstance");
  }
  if (modelInstance->model->animLength == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)modelInstance->model->animLength;
  }
  if ((int)uVar1 <= param2) {
    param2 = 0;
  }
  return (int)(modelInstance->mtxs[modelInstance->flags & 1] + param2);
}


/* Library Function - Single Match
    modelInstFn_8007f084
   
   Library: KioskDefault 0 0 */

void modelInstance_toggleFlag18_1(ModelInstance *modelInstance) { //8007F084
  if (modelInstance == (ModelInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0x4b3,"Failed assertion modelInstance");
  }
  modelInstance->flags = modelInstance->flags ^ UseOtherMtxs;
  return;
}


/* Library Function - Single Match
    modelInstFn_8007f0dc
   
   Library: KioskDefault 0 0 */

void ModelInstance_setField30(ModelInstance *modelInstance,undefined4 cb) { //8007F0DC
  if (modelInstance == (ModelInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0x4c8,"Failed assertion modelInstance");
  }
  modelInstance->texFuncPtr = cb;
  return;
}


/* Library Function - Single Match
    modelInstFn_8007f134
   
   Library: KioskDefault 0 0 */

undefined4 modelInstanceGetCallback30(ModelInstance *modelInstance) { //8007F134
  if (modelInstance == (ModelInstance *)0x0) {
                    
    OSPanic("models_dolphin.c",0x4db,"Failed assertion modelInstance");
  }
  return modelInstance->texFuncPtr;
}


/* Library Function - Single Match
    modelFn_8007fd3c
   
   Library: KioskDefault 0 0 */

undefined2 modelGetFieldA4(Model *model) { //8007FD3C
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x65b,"Failed assertion model");
  }
  return model->field79_0xa4;
}


/* Library Function - Single Match
    modelGetShader
   
   Library: KioskDefault 0 0 */

Shader * modelGetShader(Model *model,int shaderNum) { //8007FD8C
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x670,"Failed assertion model");
  }
  if ((-1 < shaderNum) && (shaderNum < (int)(uint)model->nShaders)) {
    return model->shaders + shaderNum;
  }
                    
  OSPanic("models_dolphin.c",0x671,s_Failed_assertion_shaderNum>_0____802ec2a0);
}


/* Library Function - Single Match
    modelGetVtxPos
   
   Library: KioskDefault 0 0 */

vec3s * modelGetVtxPos(Model *model,int positionNum) { //8007FE10
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x687,"Failed assertion model");
  }
  if ((-1 < positionNum) && (positionNum < (int)(uint)model->numPositions)) {
    return model->vertexPositions + positionNum;
  }
                    
  OSPanic("models_dolphin.c",0x688,s_Failed_assertion_positionNum>_0___802ec2e0);
}


/* Library Function - Single Match
    modelGetGCTexture
   
   Library: KioskDefault 0 0 */

undefined4 modelGetGCTexture(int param1,int textureNum) { //8007FE94
  if (param1 == 0) {
                    
    OSPanic("models_dolphin.c",0x6e8,"Failed assertion model");
  }
  if ((-1 < textureNum) && (textureNum < (int)(uint)*(byte *)(param1 + 0xb6))) {
    return *(undefined4 *)(*(int *)(param1 + 0x20) + textureNum * 4);
  }
                    
  OSPanic("models_dolphin.c",0x6e9,s_Failed_assertion_textureNum>_0___802ec3e0);
}


/* Library Function - Single Match
    modelGetJoint
   
   Library: KioskDefault 0 0 */

int modelGetJoint(int param1,int jointNum) { //8007FF18
  if (param1 == 0) {
                    
    OSPanic("models_dolphin.c",0x6ff,"Failed assertion model");
  }
  if ((-1 < jointNum) && (jointNum < (int)(uint)*(byte *)(param1 + 0xb7))) {
    return *(int *)(param1 + 0x3c) + jointNum * 0x1c;
  }
                    
  OSPanic("models_dolphin.c",0x700,s_Failed_assertion_jointNum>_0____j_802ec420);
}


/* Library Function - Single Match
    modelGetDisplayList
   
   Library: KioskDefault 0 0 */

DisplayList * modelGetDisplayList(Model *model,int listNum) { //8007FF9C
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x716,"Failed assertion model");
  }
  if ((-1 < listNum) && (listNum < (int)(uint)model->field93_0xb8)) {
    return model->displayLists + listNum;
  }
                    
  OSPanic("models_dolphin.c",0x717,s_Failed_assertion_listNum>_0____l_802ec45c);
}


/* Library Function - Single Match
    modelGetPolyGroup
   
   Library: KioskDefault 0 0 */

PolygonGroup * modelGetPolyGroup(Model *model,int groupNum) { //80080020
  if (model == (Model *)0x0) {
                    
    OSPanic("models_dolphin.c",0x772,"Failed assertion model");
  }
  if ((-1 < groupNum) && (groupNum < (int)(uint)(ushort)model->numPolyGroups)) {
    return model->polygonGroups + groupNum;
  }
                    
  OSPanic("models_dolphin.c",0x773,s_Failed_assertion_groupNum>_0____g_802ec58c);
}


/* Library Function - Single Match
    modelGetGCPoly
   
   Library: KioskDefault 0 0 */

int modelGetGCPoly(Model *model,int polygonNum) { //800800A4
  if ((-1 < polygonNum) && (polygonNum < (int)(uint)(ushort)model->numGcPolygons)) {
    return (int)(model->GCpolygons + polygonNum * 8);
  }
                    
  OSPanic("models_dolphin.c",0x787,s_Failed_assertion_polygonNum>_0___802ec5c8);
}


/* Library Function - Single Match
    modelFn_80080168
   
   Library: KioskDefault 0 0 */

Animation * modelLoadAnimation(Model *model,int index,int id,void *dest) { //80080168
  uint offset;
  u32 len;
  Animation *result;
  size_t size;
  
  offset = animOffsetTbl[index];
  loadAndDecompressDataFile(ANIM.BIN,(byte *)0x0,offset,0,&size,index,1);
  if (model->animCacheSize + -0x80 <= (int)size) {
                    
    OSPanic("models_dolphin.c",0x866,s_Failed_assertion_animSize<model__802ec6e4);
  }
  result = (Animation *)((int)dest + 0x80);
  if (result == (Animation *)0x0) {
                    
    OSPanic("models_dolphin.c",0x86b,"Failed assertion anim");
  }
  loadAndDecompressDataFile(ANIM.BIN,(byte *)result,offset,size,(uint *)0x0,index,0);
  len = (model->animLength - 1 & 0xfffffff8) + 8;
  loadDataFileWithLength(AMAP.BIN,dest,model->animOffset + id * len,len);
  return result;
}


/* Library Function - Single Match
    modAnimFn_80080270
   
   Library: KioskDefault 0 0 */

Animation * getAnimation(short id) { //80080270
  BOOL found;
  uint offset;
  uint size;
  Animation *result;
  
  found = SparseArray_get(animsLoadedTable,(int)id,&result);
  if (found == FALSE) {
    offset = animOffsetTbl[id];
    loadAndDecompressDataFile(ANIM.BIN,(byte *)0x0,offset,0,&size,(int)id,1);
    result = (Animation *)mmAlloc(size,ANIMS_COL,"mod:anim");
    if (result == (Animation *)0x0) {
                    
      OSPanic("models_dolphin.c",0x89b,"Failed assertion anim");
    }
    loadAndDecompressDataFile(ANIM.BIN,(byte *)result,offset,size,(uint *)0x0,(int)id,0);
    result->usage = 1;
    SpareArray_set(animsLoadedTable,id,&result);
  }
  else {
    result->usage = result->usage + 1;
    if (0xfe < (uint)(int)(char)result->usage) {
                    
      OSPanic("models_dolphin.c",0x8a8,s_Failed_assertion_anim_>usage<UCH_802ec744);
    }
  }
  return result;
}


/* Library Function - Single Match
    modelFn_8008039c
   
   Library: KioskDefault 0 0 */

void unloadAnimation(s8 *anim) { //8008039C
  s8 sVar1;
  BOOL BVar2;
  s8 *val;
  SparseArrayItem local_14;
  
  if (anim != (s8 *)0x0) {
    val = anim;
    if (anim == (s8 *)0x0) {
                    
      OSPanic("models_dolphin.c",0x8c8,"Failed assertion anim");
    }
    sVar1 = *anim;
    *anim = sVar1 + -1;
    if ((char)(sVar1 + -1) < 1) {
      BVar2 = sparseArrayFindElem(animsLoadedTable,&val,(int *)&local_14);
      if ((BVar2 & 0xff) == 0) {
                    
        OSPanic("models_dolphin.c",0x8d2,"Failed assertion success");
      }
      sparseArrayRemove((short **)animsLoadedTable,_local_14);
      mm_free(val);
    }
  }
  return;
}


/* Library Function - Single Match
    setMaxModelNum
   
   Library: KioskDefault 0 0 */

BOOL countModels(void) { //800812A0
  void *pvVar1;
  BOOL uVar2;
  
  pvVar1 = getTable(MODELS.tab);
  if (pvVar1 == (void *)0x0) {
    uVar2 = FALSE;
  }
  else {
    for (maxModelNum = 0; *(int *)((int)pvVar1 + maxModelNum * 4) != -1;
        maxModelNum = maxModelNum + 1) {
    }
    maxModelNum = maxModelNum + -1;
    if (0x7fff < maxModelNum) {
                    
      OSPanic("models_dolphin.c",0xce5,s_Failed_assertion_maxModelNum<_SH_802ec81c);
    }
    animOffsetTbl = (int *)getTable(ANIM.TAB);
    if (animOffsetTbl == (int *)0x0) {
      uVar2 = FALSE;
    }
    else {
      bHaveAnimTab = 0;
      uVar2 = TRUE;
    }
  }
  return uVar2;
}


/* Library Function - Single Match
    modelGetVtxPosFloat
   
   Library: KioskDefault 0 0 */

void modelGetVtxPosFloat(Model *model,int positionNum,vec3f *posVec) { //8008157C
  vec3s *vp;
  
  if (posVec == (vec3f *)0x0) {
                    
    OSPanic("models_dolphin.c",0xe3a,"Failed assertion posVec");
  }
  if ((-1 < positionNum) && (positionNum < (int)(uint)model->numPositions)) {
    vp = modelGetVtxPos(model,positionNum);
    posVec->x = (float)((double)CONCAT44(0x43300000,(int)vp->x ^ 0x80000000) - 4503601774854144.0) *
                0.00390625;
    posVec->y = (float)((double)CONCAT44(0x43300000,(int)vp->y ^ 0x80000000) - 4503601774854144.0) *
                0.00390625;
    posVec->z = (float)((double)CONCAT44(0x43300000,(int)vp->z ^ 0x80000000) - 4503601774854144.0) *
                0.00390625;
    return;
  }
                    
  OSPanic("models_dolphin.c",0xe3b,s_Failed_assertion_positionNum>_0___802ec2e0);
}


void loadModelsBin(uint offset,undefined4 *outNAnimations,undefined4 *outAnimCacheSize,
                  undefined4 *outNoAmap,int *outSize) { //80099974
  ModelsBinEntry *entry;
  DataFileEnum32 file;
  
  if ((dataFilePtrs[43] != (void *)0x0) || (dataFilePtrs[70] != (void *)0x0)) {
    if ((offset & 0x20000000) == 0) {
      if ((offset & 0x10000000) == 0) {
        if (dataFilePtrs[42] == (void *)0x0) {
          file = (DataFileEnum32)"models_dolphin.c";
          if (dataFilePtrs[69] != (void *)0x0) {
            file = MODELS.bin_46;
          }
        }
        else {
          file = MODELS.bin;
        }
      }
      else {
        file = MODELS.bin;
      }
    }
    else {
      file = MODELS.bin_46;
    }
    entry = (ModelsBinEntry *)((int)dataFilePtrs[file] + (offset & 0xfffffff));
    *outNoAmap = entry->noAmap;
    *outNAnimations = entry->nAnimations;
    *outAnimCacheSize = entry->animCacheSize;
    *outSize = entry->size;
  }
  return;
}

