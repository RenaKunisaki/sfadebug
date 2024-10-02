
/* Library Function - Single Match
    trkBlkFn_800b04dc
   
   Library: KioskDefault 0 0 */

void trackBlockLoad(int iBlock,int yx,int layer) { //800B04DC
  MapBlock *block;
  
  block = trackBlockLoadFromFile(iBlock);
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0xde,"Failed assertion block");
  }
  trackBlockSetPointers(block);
  trackBlockLoadTextures(block);
  trackBlockGetLineHits(block,iBlock);
  trackBlockInitShaders(block);
  trackLoadBlockEnd(block,(s16)iBlock,yx,layer);
  DCStoreRange(block,block->size);
  return;
}


void FUN_800b0580(int param_1) { //800B0580
  MapBlock *__ptr;
  
  if ((-1 < param_1) &&
     (trk_blkusage[param_1] = trk_blkusage[param_1] + -1, trk_blkusage[param_1] == '\0')) {
    __ptr = trk_cblocks[param_1];
    (&trk_blknos->id)[param_1] = -1;
    trk_cblocks[param_1] = (MapBlock *)0x0;
    FUN_800b0a60(__ptr);
    FUN_800b081c((int)__ptr);
    FUN_800b0a0c((int)__ptr);
    mm_free(__ptr);
  }
  return;
}


/* Library Function - Single Match
    trackBlockFn_800b061c
   
   Library: KioskDefault 0 0 */

MapBlock * trackBlockLoadFromFile(int iBlock) { //800B061C
  MapBlock *block;
  uint offset;
  uint blockSize;
  
  if (blocksTabLen < iBlock) {
    block = (MapBlock *)0x0;
  }
  else {
    if (((pBlocksTab != (int *)0x0) && (pBlocksTab[iBlock] != -1)) &&
       ((pBlocksTab[iBlock] != 0 || (pBlocksTab[iBlock + 1] != 0)))) {
      offset = pBlocksTab[iBlock];
      loadAndDecompressDataFile(BLOCKS.bin,(byte *)0x0,offset,0x10,&blockSize,iBlock,1);
    }
    block = (MapBlock *)mmAlloc(blockSize,TRACK_COL,"trk:blk");
    if (block == (MapBlock *)0x0) {
                    
      OSPanic("track_dolphin.c",0x150,"Failed assertion block");
    }
    loadAndDecompressDataFile(BLOCKS.bin,(byte *)block,offset,blockSize,(uint *)0x0,iBlock,0);
    if (blockSize != block->size) {
                    
      OSPanic("track_dolphin.c",0x154,"Failed assertion blockSize==block->size");
    }
  }
  return block;
}


/* Library Function - Single Match
    mapBlockFn_800b0768
   
   Library: KioskDefault 0 0 */

void trackBlockLoadTextures(MapBlock *block) { //800B0768
  Texture *pTVar1;
  int i;
  
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x16a,"Failed assertion block");
  }
  i = 0;
  while( true ) {
    if ((int)(uint)block->numTextures <= i) {
      return;
    }
    pTVar1 = textureLoad(-((uint)block->GCtextures[i] | 0x8000));
    block->GCtextures[i] = pTVar1;
    if (block->GCtextures[i] == (Texture *)0x0) break;
    i = i + 1;
  }
                    
  OSPanic("track_dolphin.c",0x16f,s_Failed_assertion_block_>GCtextur_802f2288);
}


void FUN_800b081c(int param_1) { //800B081C
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 0x9e); iVar1 = iVar1 + 1) {
    texFreeTexture(*(Texture **)(*(int *)(param_1 + 0x54) + iVar1 * 4));
  }
  return;
}


void trackBlockGetLineHits(MapBlock *block,int blockNo) { //800B086C
  LineHit *pLVar1;
  uint offset;
  uint size;
  int i;
  
  offset = pHitsTab[blockNo];
  size = pHitsTab[blockNo + 1] - offset;
  if (0 < (int)size) {
    pLVar1 = (LineHit *)mmAlloc(size,TRACK_COL,"linehits");
    block->linehits = pLVar1;
    loadDataFileWithLength(HITS.bin,block->linehits,offset,size);
  }
  block->numLineHits = (ushort)(size / 0x14);
  for (i = 0; i < (int)(uint)block->numLineHits; i = i + 1) {
    if ((((block->linehits[i].field0_0x0 < 0) || (block->linehits[i].field1_0x2 < 0)) ||
        (0x280 < block->linehits[i].field0_0x0)) || (0x280 < block->linehits[i].field1_0x2)) {
      block->linehits[i].field11_0xf = 0x40;
    }
    if (((block->linehits[i].field6_0x8 < 0) || (block->linehits[i].field7_0xa < 0)) ||
       ((0x280 < block->linehits[i].field6_0x8 || (0x280 < block->linehits[i].field7_0xa)))) {
      block->linehits[i].field11_0xf = 0x40;
    }
  }
  block->field34_0x70 = 0;
  block->field57_0x9c = 0;
  block->flags = block->flags & 0xffbf;
  return;
}


void FUN_800b0a0c(int param_1) { //800B0A0C
  if (*(int *)(param_1 + 0x70) != 0) {
    mm_free(*(void **)(param_1 + 0x70));
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    mm_free(*(void **)(param_1 + 0x6c));
  }
  setModLinesNeedUpdate();
  return;
}


void FUN_800b0a60(MapBlock *param_1) { //800B0A60
  Shader *pSVar1;
  int shaderNum;
  int iVar2;
  
  for (shaderNum = 0; shaderNum < (int)(uint)param_1->numShaders; shaderNum = shaderNum + 1) {
    pSVar1 = MapBlock_getShader(param_1,shaderNum);
    for (iVar2 = 0; iVar2 < (int)(uint)pSVar1->numLayers; iVar2 = iVar2 + 1) {
      if (pSVar1->layer[iVar2].texScrollIdx != 0xff) {
        texScrollGlobalFree((uint)pSVar1->layer[iVar2].texScrollIdx);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    trackLoadBlockFn_800b0aec
   
   Library: KioskDefault 0 0 */

void trackBlockSetPointers(MapBlock *block) { //800B0AEC
  int i;
  Shader *blockBase;
  
  blockBase = (Shader *)(&block->field_0x0 + block->size);
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x217,"Failed assertion block");
  }
  if ((block->GCtextures != (Texture **)0x0) &&
     ((block->GCtextures = (Texture **)(&block->field_0x0 + (int)block->GCtextures),
      (MapBlock *)block->GCtextures < block || (blockBase <= (Shader *)block->GCtextures)))) {
                    
    OSPanic("track_dolphin.c",0x21c,s_Failed_assertion_block_>GCtextur_802f22bc);
  }
  if ((block->GCpolygons != (GCPolygon *)0x0) &&
     ((block->GCpolygons = (GCPolygon *)(&block->GCpolygons->field_0x0 + (int)&block->field_0x0),
      (MapBlock *)block->GCpolygons < block || (blockBase <= (Shader *)block->GCpolygons)))) {
                    
    OSPanic("track_dolphin.c",0x222,s_Failed_assertion_block_>GCpolygo_802f2308);
  }
  if ((block->polygonGroups != (PolygonGroup *)0x0) &&
     ((block->polygonGroups =
            (PolygonGroup *)((int)&block->polygonGroups->firstPolygon + (int)&block->field_0x0),
      (MapBlock *)block->polygonGroups < block || (blockBase <= (Shader *)block->polygonGroups)))) {
                    
    OSPanic("track_dolphin.c",0x228,s_Failed_assertion_block_>polygonG_802f2354);
  }
  block->vertexPositions = (vec3s *)((int)&block->vertexPositions->x + (int)&block->field_0x0);
  if (((MapBlock *)block->vertexPositions < block) ||
     (blockBase <= (Shader *)block->vertexPositions)) {
                    
    OSPanic("track_dolphin.c",0x22c,s_Failed_assertion_block_>vertexPo_802f23a8);
  }
  block->vertexColours = block->vertexColours + (int)&block->field_0x0;
  if (((MapBlock *)block->vertexColours < block) || (blockBase <= (Shader *)block->vertexColours)) {
                    
    OSPanic("track_dolphin.c",0x22e,s_Failed_assertion_block_>vertexCo_802f2400);
  }
  block->vertexTexCoords = block->vertexTexCoords + (int)&block->field_0x0;
  if (((MapBlock *)block->vertexTexCoords < block) ||
     (blockBase <= (Shader *)block->vertexTexCoords)) {
                    
    OSPanic("track_dolphin.c",0x230,s_Failed_assertion_block_>vertexTe_802f2454);
  }
  if ((block->renderStream != (BitStream *)0x0) &&
     ((block->renderStream = (BitStream *)((int)&block->renderStream->data + (int)&block->field_0x0)
      , (MapBlock *)block->renderStream < block || (blockBase <= (Shader *)block->renderStream)))) {
                    
    OSPanic("track_dolphin.c",0x234,s_Failed_assertion_block_>renderSt_802f24ac);
  }
  if ((block->transparentRenderStream != (BitStream *)0x0) &&
     ((block->transparentRenderStream =
            (BitStream *)((int)&block->transparentRenderStream->data + (int)&block->field_0x0),
      (MapBlock *)block->transparentRenderStream < block ||
      (blockBase <= (Shader *)block->transparentRenderStream)))) {
                    
    OSPanic("track_dolphin.c",0x239,s_Failed_assertion_block_>transpar_802f24fc);
  }
  if ((block->waterRenderStream != (BitStream *)0x0) &&
     ((block->waterRenderStream =
            (BitStream *)((int)&block->waterRenderStream->data + (int)&block->field_0x0),
      (MapBlock *)block->waterRenderStream < block ||
      (blockBase <= (Shader *)block->waterRenderStream)))) {
                    
    OSPanic("track_dolphin.c",0x23e,s_Failed_assertion_block_>waterRen_802f2564);
  }
  block->displayLists =
       (DisplayListPtr *)
       (&block->field_0x0 + (int)&((DisplayListPtr *)(block->displayLists->bbox + -1))->list);
  if (((MapBlock *)block->displayLists < block) || (blockBase <= (Shader *)block->displayLists)) {
                    
    OSPanic("track_dolphin.c",0x241,s_Failed_assertion_block_>displayL_802f25c0);
  }
  if ((block->shaders != (Shader *)0x0) &&
     ((block->shaders = (Shader *)((int)block->shaders->layer + (int)&block->field_0x0 + -0x24),
      (MapBlock *)block->shaders < block || (blockBase <= block->shaders)))) {
                    
    OSPanic("track_dolphin.c",0x246,s_Failed_assertion_block_>shaders>_802f2610);
  }
  i = 0;
  while( true ) {
    if ((int)(uint)block->numDisplayLists <= i) {
      return;
    }
    *(undefined **)((int)block->displayLists + i * 0x34) =
         &block->field_0x0 + *(int *)((int)block->displayLists + i * 0x34);
    if (*(MapBlock **)((int)block->displayLists + i * 0x34) < block) break;
    if (blockBase <= *(Shader **)((int)block->displayLists + i * 0x34)) break;
    if ((*(uint *)((int)block->displayLists + i * 0x34) & 0x1f) != 0) {
                    
      OSPanic("track_dolphin.c",0x24d,s_Failed_assertion___int_block_>di_802f26c8);
    }
    i = i + 1;
  }
                    
  OSPanic("track_dolphin.c",0x24c,s_Failed_assertion_block_>displayL_802f2658);
}


void trackBlockInitShaders(MapBlock *block) { //800B0E98
  Shader *pSVar1;
  int i;
  int j;
  Shader *shader;
  
  for (i = 0; i < (int)(uint)block->numShaders; i = i + 1) {
    pSVar1 = block->shaders;
    for (j = 0; j < (int)(uint)pSVar1[i].numLayers; j = j + 1) {
      if (pSVar1[i].layer[j].texture == (Texture *)0xffffffff) {
        pSVar1[i].layer[j].texture = (Texture *)0x0;
      }
      else {
        pSVar1[i].layer[j].texture = block->GCtextures[(int)pSVar1[i].layer[j].texture];
      }
      pSVar1[i].layer[j].texScrollIdx = 0xff;
    }
    if (pSVar1[i].tex34 == (Texture *)0xffffffff) {
      pSVar1[i].tex34 = (Texture *)0x0;
    }
    else {
      pSVar1[i].tex34 = block->GCtextures[(int)pSVar1[i].tex34];
    }
  }
  return;
}


/* Library Function - Single Match
    trackBlockShaderFn_800b0f70
   
   Library: KioskDefault 0 0 */

Shader * MapBlock_getShader(MapBlock *block,int shaderNum) { //800B0F70
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x294,"Failed assertion block");
  }
  if ((-1 < shaderNum) && (shaderNum < (int)(uint)block->numShaders)) {
    return block->shaders + shaderNum;
  }
                    
  OSPanic("track_dolphin.c",0x295,s_Failed_assertion_shaderNum>_0____802f270c);
}


/* Library Function - Single Match
    mapBlockGetDisplayList
   
   Library: KioskDefault 0 0 */

DisplayListPtr * mapBlockGetDisplayList(MapBlock *block,int listNum) { //800B0FF4
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x2ab,"Failed assertion block");
  }
  if ((-1 < listNum) && (listNum < (int)(uint)block->numDisplayLists)) {
    return (DisplayListPtr *)((int)block->displayLists + listNum * 0x34);
  }
                    
  OSPanic("track_dolphin.c",0x2ac,s_Failed_assertion_listNum>_0____l_802f274c);
}


/* Library Function - Single Match
    mapBlockGetVtxPos
   
   Library: KioskDefault 0 0 */

vec3s * mapBlockGetVtxPos(MapBlock *block,int positionNum) { //800B1078
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x2da,"Failed assertion block");
  }
  if ((-1 < positionNum) && (positionNum < (int)(uint)block->numPositions)) {
    return block->vertexPositions + positionNum;
  }
                    
  OSPanic("track_dolphin.c",0x2db,s_Failed_assertion_positionNum>_0___802f2804);
}


/* Library Function - Single Match
    mapBlockGetGroup
   
   Library: KioskDefault 0 0 */

PolygonGroup * mapBlockGetGroup(MapBlock *block,int groupNum) { //800B10FC
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x336,"Failed assertion block");
  }
  if ((-1 < groupNum) && (groupNum < (int)(uint)block->numGroups)) {
    return block->polygonGroups + groupNum;
  }
                    
  OSPanic("track_dolphin.c",0x337,s_Failed_assertion_groupNum>_0____g_802f2904);
}


/* Library Function - Single Match
    mapBlockGetPolygon
   
   Library: KioskDefault 0 0 */

GCPolygon * mapBlockGetPolygon(MapBlock *block,int polygonNum) { //800B1180
  if ((-1 < polygonNum) && (polygonNum < (int)(uint)block->numPolygons)) {
    return block->GCpolygons + polygonNum;
  }
                    
  OSPanic("track_dolphin.c",0x34d,s_Failed_assertion_polygonNum>_0___802f2940);
}


/* Library Function - Single Match
    modelFn_8007fd3c
   
   Library: KioskDefault 0 0 */

ushort mapBlockGetNumPositions(MapBlock *block) { //800B11E8
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x361,"Failed assertion block");
  }
  return block->numPositions;
}


int mapBlockFindPolyGroupFn_800b1238(MapBlock *block,uint param2) { //800B1238
  PolygonGroup *group;
  uint uVar1;
  int iVar2;
  int groupNum;
  
  iVar2 = 0;
  for (groupNum = 0; groupNum < (int)(uint)block->numGroups; groupNum = groupNum + 1) {
    group = mapBlockGetGroup(block,groupNum);
    uVar1 = FUN_800b12b8(group);
    if (param2 == uVar1) {
      iVar2 = iVar2 + ((uint)*(ushort *)&group[1].firstPolygon -
                      (uint)*(ushort *)&group->firstPolygon);
    }
  }
  return iVar2;
}


uint FUN_800b12b8(PolygonGroup *group) { //800B12B8
  return group->flags >> 0x18;
}


uint FUN_800b12c4(int param_1) { //800B12C4
  return *(uint *)(param_1 + 0x10) >> 0x10 & 0xff;
}


/* Library Function - Single Match
    vec3f_to_vec3s
   
   Library: KioskDefault 0 0 */

void vec3f_to_vec3s(vec3s *dst,vec3f *src) { //800B1348
  int x;
  int y;
  int z;
  
  x = (int)src->x;
  y = (int)src->y;
  z = (int)src->z;
  if ((x < -0x8000) || (0x7fff < x)) {
                    
    OSPanic("track_dolphin.c",0x3e6,s_Failed_assertion_x>_SHRT_MIN____x_802f2980);
  }
  if ((-0x8001 < y) && (y < 0x8000)) {
    if ((-0x8001 < z) && (z < 0x8000)) {
      dst->x = (short)x;
      dst->y = (short)y;
      dst->z = (short)z;
      return;
    }
                    
    OSPanic("track_dolphin.c",1000,s_Failed_assertion_z>_SHRT_MIN____z_802f29d8);
  }
                    
  OSPanic("track_dolphin.c",999,s_Failed_assertion_y>_SHRT_MIN____y_802f29ac);
}


/* Library Function - Single Match
    mapBlockFn_800b1824
   
   Library: KioskDefault 0 0 */

void MapBlock_doRenderStream(MapBlock *block,s8 which) { //800B1824
  bool bVar1;
  Mtx44 *a;
  uint op;
  BitStream *stream;
  Shader *shader;
  u16 count;
  Mtx43 local_d8;
  Mtx43 MStack_a8;
  BitStream BStack_78;
  Mtx43 MStack_64;
  
  shader = (Shader *)0x0;
  if (block != (MapBlock *)0x0) {
    if (which == '\x01') {
      stream = block->transparentRenderStream;
      count = block->transparentRenderStreamSize;
    }
    else if (which == '\x02') {
      stream = block->waterRenderStream;
      count = block->waterRenderStreamSize;
    }
    else {
      stream = block->renderStream;
      count = block->renderStreamSize;
    }
    if (count != 0) {
      a = getCameraMtxs();
      MTXConcat((Mtx43 *)a,&block->mtx,&MStack_64);
      GXLoadPosMtxImm(&MStack_64,0);
      if (which == '\x02') {
        MTXConcat(&Mtx43_80382d40,&MStack_64,&MStack_a8);
        GXLoadTexMtxImm(&MStack_a8,0x1e,0);
        MTXConcat(&Mtx43_80382d70,&MStack_64,&MStack_a8);
        GXLoadTexMtxImm(&MStack_a8,0x21,0);
        local_d8.m11 = 0.0;
        local_d8.m12 = 0.0;
        local_d8.m13 = 0.0;
        local_d8.m14 = 0.0;
        local_d8.m21 = 0.0;
        local_d8.m22 = 0.0;
        local_d8.m23 = -0.001;
        local_d8.m24 = 0.0;
        MTXConcat(&local_d8,&MStack_64,&MStack_a8);
        GXLoadTexMtxImm(&MStack_a8,0x24,1);
      }
      GXSetArray(9,(uint)block->vertexPositions,6);
      GXSetArray(0xb,(uint)block->vertexColours,2);
      GXSetArray(0xd,(uint)block->vertexTexCoords,4);
      GXSetArray(0xe,(uint)block->vertexTexCoords,4);
      bitStreamInit(&BStack_78,(byte *)stream,(uint)count << 3,(uint)count << 3);
      bVar1 = false;
      while (!bVar1) {
        op = bitStream_read(&BStack_78,4);
        if (op == 3) {
          renderOpFmt(block,(int)shader,&BStack_78);
        }
        else if ((int)op < 3) {
          if (op == 1) {
            shader = renderOpShader(block,&BStack_78);
          }
          else if (0 < (int)op) {
            renderOpCallList(block,shader,&BStack_78);
          }
        }
        else if (op == 5) {
          bVar1 = true;
        }
        else if ((int)op < 5) {
          bitStream_skipLen(&BStack_78);
        }
      }
    }
    return;
  }
                    
  OSPanic("track_dolphin.c",0x52d,"Failed assertion block");
}


void renderOpFmt(MapBlock *param_1,int param_2,BitStream *stream) { //800B1A7C
  uint uVar1;
  uint param2;
  int iVar2;
  
  GXClearVtxDesc();
  uVar1 = bitStream_read(stream,1);
  if (uVar1 == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 3;
  }
  GXSetVtxDesc(POS,uVar1);
  uVar1 = bitStream_read(stream,1);
  if (uVar1 == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 3;
  }
  GXSetVtxDesc(COL0,uVar1);
  uVar1 = bitStream_read(stream,1);
  if (param_2 == 0) {
    if (uVar1 == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 3;
    }
    GXSetVtxDesc(TEX0,uVar1);
  }
  else {
    for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(param_2 + 0x3b); iVar2 = iVar2 + 1) {
      if (uVar1 == 0) {
        param2 = 2;
      }
      else {
        param2 = 3;
      }
      GXSetVtxDesc(iVar2 + TEX0,param2);
    }
  }
  return;
}


/* Library Function - Single Match
    mapBlockRender
   
   Library: KioskDefault 0 0 */

Shader * MapBlock_renderOpShader(MapBlock *block,BitStream *renderStream) { //800B1B70
  uint shaderNum;
  Shader *shader;
  undefined4 local_20 [3];
  undefined4 local_14;
  
  local_14 = 0;
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x5d1,"Failed assertion block");
  }
  if (renderStream == (BitStream *)0x0) {
                    
    OSPanic("track_dolphin.c",0x5d2,"Failed assertion renderStream");
  }
  shaderNum = bitStream_read(renderStream,6);
  shader = getShader(block,shaderNum);
  if ((shader != (Shader *)0x0) && ((shader->attributes & GC_SHADERATTRIBUTE_WATER) != 0)) {
                    
    OSPanic("track_dolphin.c",0x5d9,s_Failed_assertion___shader_>attri_802f2b00);
  }
  FUN_800a11d4();
  shaderLayerFn_800b1d98(shader,0x80);
  if ((shader->attributes & BlendModeFlag40) == 0) {
    if ((shader->attributes & BlendModeFlag20) == 0) {
      if ((shader->attributes & BlendModeFlag10) == 0) {
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
      goto LAB_800b1d28;
    }
  }
  GXSetBlendMode(1,4,5,5);
  GXSetZMode(true,GX_LEQUAL,false);
  GXSetZCompLoc(1);
  GXSetAlphaCompare(7,0,0,7,0);
LAB_800b1d28:
  if ((shader->attributes & BackfaceCulling) == 0) {
    GXSetCullMode(GX_CULL_NONE);
  }
  else {
    GXSetCullMode(GX_CULL_BACK);
  }
  if ((shader->attributes & HasFog) == 0) {
    local_20[0] = local_14;
    GXSetFog(0.0,0.0,0.0,0.0,0,(undefined *)local_20);
  }
  else {
    fogFn_800c6a1c();
  }
  return shader;
}


void shaderLayerFn_800b1d98(Shader *shader,uint param_2) { //800B1D98
  ShaderLayer *layer;
  int layerNum;
  Mtx43 *pMVar1;
  float local_58;
  float local_54;
  Mtx43 MStack_50;
  undefined4 local_20 [3];
  
  local_20[0] = 0xffffffff;
  if ((shader->numLayers == 2) && (layer = shaderGetLayer(shader,1), (layer->field_0x4 & 0x7f) == 9)
     ) {
    layer = shaderGetLayer(shader,0);
    if (layer->texScrollIdx == 0xff) {
      pMVar1 = (Mtx43 *)0x0;
    }
    else {
      texScrollGetPos((uint)layer->texScrollIdx,&local_54,&local_58);
      MTXTrans((double)local_54,(double)local_58,0.0,&MStack_50.m11);
      pMVar1 = &MStack_50;
    }
    gxAddTevStageTexGen_800a190c((int)layer->texture,pMVar1,0,local_20);
    layer = shaderGetLayer(shader,1);
    if (layer->texScrollIdx == 0xff) {
      pMVar1 = (Mtx43 *)0x0;
    }
    else {
      texScrollGetPos((uint)layer->texScrollIdx,&local_54,&local_58);
      MTXTrans((double)local_54,(double)local_58,0.0,&MStack_50.m11);
      pMVar1 = &MStack_50;
    }
    shaderFn_800a1e28((int)layer->texture,pMVar1,9);
    gxAddTevStageWithColor(local_20);
  }
  else {
    for (layerNum = 0; layerNum < (int)(uint)shader->numLayers; layerNum = layerNum + 1) {
      layer = shaderGetLayer(shader,layerNum);
      if (((byte)layer->field_0x4 & 0x80) == param_2) {
        if (layer->texture == (Texture *)0x0) {
          gxAddTevStage();
        }
        else {
          if (layer->texScrollIdx == 0xff) {
            pMVar1 = (Mtx43 *)0x0;
          }
          else {
            texScrollGetPos((uint)layer->texScrollIdx,&local_54,&local_58);
            MTXTrans((double)local_54,(double)local_58,0.0,&MStack_50.m11);
            pMVar1 = &MStack_50;
          }
          shaderFn_800a1e28((int)layer->texture,pMVar1,(byte)layer->field_0x4 & 0x7f);
        }
      }
    }
  }
  return;
}


/* Library Function - Single Match
    mapBlockRenderFn_800b1f68
   
   Library: KioskDefault 0 0 */

void MapBlock_renderOpCallList(MapBlock *block,Shader *shader,BitStream *renderStream) { //800B1F68
  uint uVar1;
  DisplayListPtr *dlist;
  int iVar2;
  Mtx43 MStack_4c;
  
  if (block == (MapBlock *)0x0) {
                    
    OSPanic("track_dolphin.c",0x69e,"Failed assertion block");
  }
  if (renderStream == (BitStream *)0x0) {
                    
    OSPanic("track_dolphin.c",0x69f,"Failed assertion renderStream");
  }
  uVar1 = bitStream_read(renderStream,6);
  dlist = mapBlockGetDisplayList(block,uVar1);
  if (((shader == (Shader *)0x0) || ((shader->attributes & 1) == 0)) &&
     (uVar1 = dlistBboxFn_800b2138(dlist,block), (uVar1 & 0xff) != 0)) {
    if (((shader == (Shader *)0x0) || ((shader->attributes & 8) == 0)) ||
       (dlist->field_0x12 == '\0')) {
      if (shader != (Shader *)0x0) {
        _gxSetupTexGens();
      }
      GXCallDisplayList(dlist->list,(uint)dlist->size);
    }
    else {
      FUN_800a12a4();
      for (iVar2 = 0; iVar2 < (int)(uint)(byte)dlist->field_0x12; iVar2 = iVar2 + 1) {
        MTXConcat(*(Mtx43 **)((int)(dlist->bbox + 2) + iVar2 * 4 + 2),&block->mtx,&MStack_4c);
        FUN_800a2ea4(*(int *)(*(int *)((int)(dlist->bbox + 2) + iVar2 * 4 + 2) + 0x60),&MStack_4c,
                     *(undefined *)(*(int *)((int)(dlist->bbox + 2) + iVar2 * 4 + 2) + 100));
      }
      shaderFn_800a30a0();
      _gxSetupTexGens();
      GXCallDisplayList(dlist->list,(uint)dlist->size);
      FUN_800a1318();
    }
  }
  return;
}

