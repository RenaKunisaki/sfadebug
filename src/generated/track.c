
/* Library Function - Single Match
    checkMap
   
   Library: KioskDefault 0 0 */

void checkMap(MapsBinEntry *block,double x,double y,double z) { //800AA7F4
  byte *pbVar1;
  undefined *item;
  short iItem;
  uint offs;
  int type;
  uint newSize;
  uint nItems;
  ObjDef *romList;
  int size;
  
  if (true) {
    type = 0;
    while( true ) {
      if (0x27 < type) break;
      if (((&DAT_802f2108)[type] & 3) != 0) {
        printf("ERROR:track.c/checkMap() size not word aligned for %d, %d",type,(&DAT_802f2108)[type]);
      }
      type = type + 1;
    }
    romList = block->romList;
    nItems = (uint)block->romListSize;
    if (nItems != 0) {
      item = (undefined *)((int)&romList->objType + nItems);
      iItem = 0;
      for (offs = 0; (int)offs < (int)nItems; offs = offs + (uint)*pbVar1 * 4) {
        type = (int)(short)romList->objType;
        if (0 < type) {
          if (type == 0x6e) {
            newSize = (int)(&DAT_802f2108)[*(char *)((int)&romList[1].objType + 1)] >> 2;
            if (*(char *)((int)&romList[1].objType + 1) == '$') {
              romList[1].mapStates1 = romList[1].mapStates1 & 0xf;
            }
          }
          else {
            newSize = objGetRomlistSize(type);
          }
          if ((newSize != 0xffffffff) && (newSize != romList->allocatedSize)) {
            printf("Correcting Size: %d(%f,%f,%f) (%d->%d)",type,x,y,z,(int)&romList->pos,
                   (int)&(romList->pos).y);
            size = (newSize - romList->allocatedSize) * 4;
            x = (double)adjustRomListEntry((undefined *)
                                           (&romList->objType + (uint)romList->allocatedSize * 2),
                                           item,size);
            nItems = nItems + size;
            item = item + size;
            romList->allocatedSize = (byte)newSize;
            block->isInit = 1;
          }
        }
        iItem = iItem + 1;
        if (romList->allocatedSize == 0) {
          printf(" WARNING : zero romlist object ");
          nItems = offs;
        }
        pbVar1 = &romList->allocatedSize;
        romList = (ObjDef *)(&romList->objType + (uint)romList->allocatedSize * 2);
      }
      block->romListSize = (ushort)nItems;
      block->idx = iItem;
      initTrkMap(block->romList,nItems);
    }
  }
  else {
    printf("ERROR:track.c/checkMap() missing node size MAX=%d i=%d",0x28,0x28);
  }
  return;
}


/* Library Function - Single Match
    mapBlockLoadFn_800aad6c
   
   Library: KioskDefault 0 0 */

void mapBlockLoadFn_800aad6c(int param1,int param2,EntryMap *entry,int layer) { //800AAD6C
  char mapId1;
  char mapId2;
  mapId32 mapId;
  int iVar1;
  short *psVar2;
  uint uVar3;
  
  mapId = mapCoordsToId(param1,param2,layer);
  if (mapId == ~animtest) {
    entry->mapId = -1;
    entry->mapId02 = -1;
    entry->mapId04 = -1;
    entry->block = -2;
    entry->gamno = 0xff;
    entry->field4_0x8 = 0;
  }
  else {
    iVar1 = mapIdFn_800aa5e4(mapId);
    if (iVar1 == -1) {
      iVar1 = mapLoadFn_800aa468(mapId);
    }
    mapVar_8037a582[iVar1].field0_0x0 = 1;
    psVar2 = (short *)(&DAT_8037a57c)[iVar1 * 2];
    mapId1 = (char)childMapIds_8037a5c4[mapId * 2];
    mapId2 = (char)childMapIds_8037a5c4[mapId * 2 + 1];
    entry->mapId = (short)mapId;
    entry->mapId02 = (short)mapId1;
    entry->mapId04 = (short)mapId2;
    if (mapId1 != -1) {
      iVar1 = mapIdFn_800aa5e4((int)mapId1);
      if (iVar1 == -1) {
        iVar1 = mapLoadFn_800aa468((int)mapId1);
      }
      mapVar_8037a582[iVar1].field0_0x0 = 1;
    }
    if (mapId2 != -1) {
      iVar1 = mapIdFn_800aa5e4((int)mapId2);
      if (iVar1 == -1) {
        iVar1 = mapLoadFn_800aa468((int)mapId2);
      }
      mapVar_8037a582[iVar1].field0_0x0 = 1;
    }
    uVar3 = *(uint *)(*(int *)(psVar2 + 6) +
                     ((param1 - *(short *)(pMapRects + mapId * 10)) +
                     (param2 - *(short *)((int)(pMapRects + mapId * 10) + 4)) * (int)*psVar2) * 4);
    entry->field4_0x8 = (byte)(uVar3 >> 0x11) & 0x3f;
    entry->gamno = (byte)(uVar3 >> 0x17) & 0x3f;
    if (entry->gamno == 0x3f) {
      entry->gamno = 0xff;
    }
    if (entry->gamno == 0xff) {
      entry->block = -1;
    }
    else {
      if ((int)trkBlkTabCount <= (int)(char)entry->gamno) {
        entry->gamno = (char)trkBlkTabCount - 1;
        printf(s_WARNING_track_c________entry_>ga_802f2f88);
      }
      entry->block = (short)(char)entry->field4_0x8 + pTrkBlkTab[(char)entry->gamno];
      if ((int)(uint)(ushort)pTrkBlkTab[trkBlkTabCount] <= (int)entry->block) {
        entry->block = pTrkBlkTab[trkBlkTabCount] + -1;
        printf(s_entry_>block_>_max_gam_802f2fb8);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    track_getdim
   
   Library: KioskDefault 0 0 */

void track_getdim(MapRectStruct *rect,s8 *out,short x,short z,int mapId) { //800ABE80
  undefined *dest;
  u32 uVar1;
  u32 uVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  
  dest = trk_tempbuf;
  uVar2 = pMapsTab[mapId * 7];
  uVar1 = pMapsTab[mapId * 7 + 2];
  if (700 < (int)(uVar1 - uVar2)) {
    printf("track.c: getdim(): TEMP_BUFFER_SIZE overflow");
  }
  loadAsset_fileWithOffsetLength(dest,MAPS.bin,pMapsTab[mapId * 7],uVar1 - uVar2);
  *(undefined **)(dest + 0xc) = dest + (pMapsTab[mapId * 7 + 1] - pMapsTab[mapId * 7]);
  rect->xMin = x - *(short *)(dest + 4);
  rect->zMin = z - *(short *)(dest + 6);
  rect->xMax = rect->xMin + *(short *)dest + -1;
  rect->zMax = rect->zMin + *(short *)(dest + 2) + -1;
  *(char *)&rect->idx = (char)*(undefined2 *)(dest + 4);
  *(char *)((int)&rect->idx + 1) = (char)*(undefined2 *)(dest + 6);
  for (sVar5 = 0; sVar5 < *(short *)(dest + 2); sVar5 = sVar5 + 1) {
    for (sVar4 = 0; sVar4 < *(short *)dest; sVar4 = sVar4 + 1) {
      uVar3 = (int)sVar4 + (int)sVar5 * (int)*(short *)dest;
      if ((*(uint *)(*(int *)(dest + 0xc) + uVar3 * 4) >> 0x17 & 0x3f) != 0x3f) {
        out[(int)uVar3 >> 3] = out[(int)uVar3 >> 3] | (byte)(1 << (uVar3 & 7));
      }
    }
  }
  return;
}


void beginLoadingMap(void) { //800ACE18
  char cVar2;
  vec3f *pos;
  Camera *pCVar1;
  ObjInstance *player;
  ushort *lfxAct;
  s16 *envAct;
  EntryMap *pEVar3;
  s8 (*paasVar4) [16] [16];
  int iVar5;
  int iVar6;
  float fVar7;
  undefined auStack_150 [12];
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  undefined4 local_120;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  double local_40;
  longlong local_38;
  
  if (warpIdx_80398d24 == -1) {
    warpIdx_80398d24 = -2;
    warpTimer_80398c70 = '\b';
  }
                    /* {@symbol 800c87bc} */
  (**(code **)(*(int *)pDll_checkpoint + 4))();
  initModLines();
  for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {
    paasVar4 = trk_blkmaps[iVar5];
    pEVar3 = trk_entrymaps[iVar5];
    for (iVar6 = 0; iVar6 < 0x100; iVar6 = iVar6 + 1) {
      (*paasVar4)[0][iVar6] = -1;
      *(undefined *)((int)pEVar3 + iVar6 * 0xc + 9) = 0xff;
    }
  }
  for (iVar5 = 0; iVar5 < 0x28; iVar5 = iVar5 + 1) {
    (&trk_blknos->id)[iVar5] = -1;
    trk_cblocks[iVar5] = (MapBlock *)0x0;
  }
  trackBlockCount = 0;
  DAT_80398cc8 = 0;
                    /* {@symbol 8012d9a0} */
  cVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x74))();
                    /* {@symbol 8012da28} */
  pos = (vec3f *)(**(code **)(*(int *)pDll_SaveGame + 0x90))();
  fVar7 = maybeDoubleToFloat((double)(pos->x / 640.0));
  DAT_80398c60 = (int)fVar7;
  local_38 = (longlong)DAT_80398c60;
  fVar7 = maybeDoubleToFloat((double)(pos->z / 640.0));
  DAT_80398c64 = (int)fVar7;
  local_40 = (double)(longlong)DAT_80398c64;
  CamStruct1_ARRAY_80376080[0].pos.x = pos->x;
  CamStruct1_ARRAY_80376080[0].pos.y = pos->y;
  CamStruct1_ARRAY_80376080[0].pos.z = pos->z;
  CamStruct1_ARRAY_80376080[0].field1_0xc = 1;
  playerStartMapOffsetX = (float)(DAT_80398c60 * 0x280);
  playerStartMapOffsetZ = DAT_80398c64 * 0x280;
  uStack_44 = (uint)playerStartMapOffsetX ^ 0x80000000;
  local_48 = 0x43300000;
  playerMapOffsetX = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  uStack_4c = playerStartMapOffsetZ ^ 0x80000000;
  local_50 = 0x43300000;
  playerMapOffsetZ = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
  curMapId = ~animtest;
  DAT_80398d2c = 0xffffffff;
  curMapLayer = *(s8 *)((int)&pos[1].x + 1);
  renderFlags = renderFlags & 0x2000 | 0x89f4;
  loadMapForCameraPos((double)pos->x,(double)pos->y,(double)pos->z);
  renderFlags = renderFlags & 0xfffffffb;
  trackIntersect();
  mapSetupPlayer();
  if (warpIdx_80398d24 < 0) {
                    /* {@symbol 8011b1f0} */
    (**(code **)(*(int *)pDll_gplay + 0x10))(0x28,1);
  }
  warpIsPending = false;
  pCVar1 = getCurCamera();
  (pCVar1->pos).x = pos->x;
  (pCVar1->pos).y = pos->y;
  (pCVar1->pos).z = pos->z;
                    /* {@symbol 800d9b74} */
  (**(code **)(*(int *)pDll_TrickyWalk + 0x1c))();
                    /* {@symbol 800e5fd8} */
  (**(code **)(*(int *)pDll_0E + 4))();
                    /* {@symbol 800e08d8} */
  (**(code **)(*(int *)pDll_projgfx + 4))();
                    /* {@symbol 800db51c} */
  (**(code **)(*(int *)pDll_modgfx + 4))();
                    /* {@symbol 800eb000} */
  (**(code **)(*(int *)pDll_objfsa + 4))();
                    /* {@symbol 800d9944} */
  (**(code **)(*(int *)pDll_expgfx + 0x14))();
                    /* {@symbol 800d9658} */
  (**(code **)(*(int *)pDll_expgfx + 8))();
                    /* {@symbol 800d60d4} */
  (**(code **)(*(int *)pDll08 + 8))();
                    /* {@symbol 800d2014} */
  (**(code **)(*(int *)pDll_newfog + 8))();
                    /* {@symbol 800d82a0} */
  (**(code **)(*(int *)pDll_newstars + 8))();
                    /* {@symbol 800d8378} */
  (**(code **)(*(int *)pDll0A + 4))();
  initFootVol();
  player = Object_objGetMain();
  if (((warpIdx_80398d24 == -2) && (player != (ObjInstance *)0x0)) &&
     ((cVar2 == '\0' || (cVar2 == '\x01')))) {
                    /* {@symbol 8012da70} */
    lfxAct = (ushort *)(**(code **)(*(int *)pDll_SaveGame + 0x98))();
                    /* {@symbol 8012dad0} */
    envAct = (s16 *)(**(code **)(*(int *)pDll_SaveGame + 0x9c))();
                    /* {@symbol 8012db30} */
    iVar5 = (**(code **)(*(int *)pDll_SaveGame + 0xa0))();
    if (warpIdx_80398d24 == -2) {
      if (*lfxAct != 0xffff) {
        loadLfxAction1(player,player,*lfxAct);
      }
      if (lfxAct[1] != 0xffff) {
        loadLfxAction1(player,player,lfxAct[1]);
      }
      if (lfxAct[2] != 0xffff) {
        loadLfxAction1(player,player,lfxAct[2]);
      }
      if (lfxAct[3] != 0xffff) {
        loadLfxAction1(player,player,lfxAct[3]);
      }
      if (lfxAct[4] != 0xffff) {
        loadLfxAction1(player,player,lfxAct[4]);
      }
      if (lfxAct[5] != 0xffff) {
        loadLfxAction1(player,player,lfxAct[5]);
      }
      if (lfxAct[6] != 0xffff) {
        loadLfxAction1(player,player,lfxAct[6]);
      }
      if (lfxAct[7] != 0xffff) {
        loadLfxAction1(player,player,lfxAct[7]);
      }
      if (envAct[2] != -1) {
        loadEnvfxAction1(player,player,(uint)(ushort)envAct[2],0);
      }
      if (envAct[3] != -1) {
        loadEnvfxAction1(player,player,(uint)(ushort)envAct[3],0);
      }
      if (envAct[4] != -1) {
        loadEnvfxAction1(player,player,(uint)(ushort)envAct[4],0);
      }
                    /* {@symbol 800d9994} */
      (**(code **)(*(int *)pDll_expgfx + 0x1c))(*(byte *)(envAct + 0x1e) & 1);
      for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
        if (*(short *)(iVar5 + iVar6 * 2) != -1) {
                    /* {@symbol 8011bc64} */
          (**(code **)(*(int *)pDll05_2 + 4))
                    (0,*(undefined2 *)(iVar5 + iVar6 * 2),"track.c",0x17b8,
                     s_plMusicactions_>action"plMusicactions->actions[i]");
        }
      }
      if (lfxAct[9] != 0xffff) {
                    /* {@symbol 80153bd4} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x24))(0,(int)(short)lfxAct[9]);
      }
      local_120 = 0;
      local_144 = 0.0;
      local_140 = 0.0;
      local_13c = 0.0;
      local_138 = 0.0;
      local_134 = 0.0;
      local_130 = 0.0;
      if (envAct[5] != -1) {
        uStack_4c = *(uint *)(envAct + 8) ^ 0x80000000;
        local_50 = 0x43300000;
        local_144 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
        uStack_44 = *(uint *)(envAct + 10) ^ 0x80000000;
        local_48 = 0x43300000;
        local_140 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
        local_40 = (double)CONCAT44(0x43300000,*(uint *)(envAct + 0xc) ^ 0x80000000);
        local_13c = (float)(local_40 - 4503601774854144.0);
        loadEnvfxAction(auStack_150,player,(uint)(ushort)envAct[5],0);
      }
      if (envAct[6] != -1) {
        uStack_4c = *(uint *)(envAct + 0xe) ^ 0x80000000;
        local_50 = 0x43300000;
        local_144 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
        uStack_44 = *(uint *)(envAct + 0x10) ^ 0x80000000;
        local_48 = 0x43300000;
        local_140 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
        local_40 = (double)CONCAT44(0x43300000,*(uint *)(envAct + 0x12) ^ 0x80000000);
        local_13c = (float)(local_40 - 4503601774854144.0);
        loadEnvfxAction(auStack_150,player,(uint)(ushort)envAct[6],0);
      }
      if (envAct[7] != -1) {
        uStack_4c = *(uint *)(envAct + 0x14) ^ 0x80000000;
        local_50 = 0x43300000;
        local_144 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
        uStack_44 = *(uint *)(envAct + 0x16) ^ 0x80000000;
        local_48 = 0x43300000;
        local_140 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
        local_40 = (double)CONCAT44(0x43300000,*(uint *)(envAct + 0x18) ^ 0x80000000);
        local_13c = (float)(local_40 - 4503601774854144.0);
        loadEnvfxAction(auStack_150,player,(uint)(ushort)envAct[7],0);
      }
                    /* {@symbol 800d26a8} */
      (**(code **)(*(int *)pDll_newfog + 0x28))((double)*(float *)envAct);
    }
  }
  else {
                    /* {@symbol 800d26a8} */
    (**(code **)(*(int *)pDll_newfog + 0x28))(0x40e4ff0000000000);
                    /* {@symbol 800d9994} */
    (**(code **)(*(int *)pDll_expgfx + 0x1c))(1);
  }
  return;
}

