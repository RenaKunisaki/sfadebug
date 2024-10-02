
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WORLDplanet_initialise(undefined4 param) { //802A7EF0
  return;
}


/* @description Called when DLL is unloaded */

void WORLDplanet_release(void) { //802A7EF4
  return;
}


/* Library Function - Single Match
    worldMap_func03
   
   Library: KioskDefault 0 0 */

void WORLDplanet_init(ObjInstance *param1,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                      float x,float y,float z) { //802A7EF8
  undefined *puVar1;
  
  puVar1 = param1->state;
  DAT_8039a11c = 0;
  puVar1[4] = 0;
  *(undefined2 *)(puVar1 + 2) = 0;
  *puVar1 = 0;
  if (DAT_803980f8 == -1) {
    puVar1[0xb] = 0;
  }
  else {
    puVar1[0xb] = (char)DAT_803980f8;
    piRomFreeLevel(0x2d,0x10000000);
  }
  puVar1[0xc] = 0xf;
  worldMapWarpCountdown = 0;
  DAT_8039a118 = 0;
  setDrawTrackSky(FALSE);
  audioPlaySong(0,4);
  DAT_8039a110 = 0.0;
  setShowCommandMenu(true);
  OSReport("WORLDMAP INIT");
  return;
}


/* Library Function - Single Match
    worldMap_func04
   
   Library: KioskDefault 0 0 */

void WORLDplanet_update(ObjInstance *this) { //802A81C8
  uint uVar1;
  bool bVar2;
  ObjInstance *obj;
  int iVar3;
  int rand1;
  N64Button32 NVar4;
  ObjInstance *pOVar5;
  short sVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  ObjState_WORLDplanet *state;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  short local_cc;
  undefined auStack_c8 [6];
  undefined2 local_c2;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined uStack_b0;
  char local_af [3];
  undefined *local_ac;
  int local_a8;
  longlong local_a0;
  undefined4 local_98;
  uint uStack_94;
  double local_90;
  
  _savefpr_24();
  state = (ObjState_WORLDplanet *)this->state;
  bVar2 = false;
  FUN_800d5708(1);
  FUN_800d5710(0xff,0xff,0xe6,0,0x5a);
  FUN_800d5730(0.7392640113830566,0.0,0.6734150052070618);
  if (worldMapWarpCountdown == '\0') {
    setE3MenuFrameCount(1);
    if ((state->flags & 4) == 0) {
                    /* {@symbol 801539f0} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x1c))(0x5c,1,0,0,0,0,0xff);
                    /* {@symbol 80153db8} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x28))(this,0);
      state->flags = state->flags | 4;
    }
    else if ((state->flags & 8) == 0) {
      local_ac = (&PTR_DAT_80322f70)[worldMapSpotIdx[state->curSpotIdx]];
                    /* {@symbol 80153b18} */
      (**(code **)(*(int *)pDll_ObjSeq + 0x60))(&local_ac,1);
      state->flags = state->flags | 8;
                    /* WORLDpepper */
      obj = Object_findByUniqueId(0x43077);
      obj->state[0x25c] = *(undefined *)((int)&PTR_DAT_803980f0 + (uint)state->curSpotIdx);
      OSReport(s_spaces);
      stopStream_80068d94();
    }
    if ((state->flags & 1) == 0) {
      state->flags = state->flags | 1;
    }
    if ((state->flags & 2) == 0) {
      for (bVar7 = 0; bVar7 < 0x3c; bVar7 = bVar7 + 1) {
        iVar8 = randInt(-0x7fff,0x7fff);
        iVar3 = randInt(0,0);
        local_a8 = (int)(short)iVar3;
        iVar3 = randInt(0,0);
        rand1 = randInt(200,0xfa);
        WORLDplanet_spawnComet
                  (this,rand1,(int)(short)iVar3,local_a8,(int)(short)iVar8,
                   (uint)bVar7 + ((int)(uint)bVar7 >> 3) * -8 & 0xff);
      }
      state->flags = state->flags | 2;
    }
    NVar4 = n64GetEnabledButtonsPressed(0);
    local_c2 = 100;
    local_bc = 59.3736;
    local_b8 = 39.7452;
    local_b4 = -42.603;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x6f2,auStack_c8,2,0xffffffff,0);
    FUN_802a7fc4((int)this,local_af,&uStack_b0);
    (this->pos).rotation.z = (this->pos).rotation.z + -10;
    (this->pos).rotation.y = 0x3448;
    (this->pos).rotation.x = 0x4000;
    obj = Object_findByUniqueId(0x42ff5);
    (obj->pos).rotation.z = (this->pos).rotation.z;
    (obj->pos).rotation.y = (this->pos).rotation.y;
    (obj->pos).rotation.x = (this->pos).rotation.x;
    obj = Object_findByUniqueId(0x4300d);
    (obj->pos).rotation.x = (obj->pos).rotation.x + -8;
    iVar8 = (obj->pos).rotation.x + 0x4000;
    dVar11 = (double)angleFn_8029374c(3000);
    dVar12 = (double)angleFn_80293234(iVar8);
    (obj->pos).pos.x = (float)((double)(float)(dVar12 * 280.0) * dVar11 + (double)(this->pos).pos.x)
    ;
    dVar11 = (double)angleFn_80293234(3000);
    dVar12 = (double)angleFn_80293234(iVar8);
    (obj->pos).pos.y = (float)((double)(float)(dVar12 * 280.0) * dVar11 + (double)(this->pos).pos.y)
    ;
    dVar11 = (double)angleFn_8029374c(iVar8);
    (obj->pos).pos.z = (float)(dVar11 * 280.0 + (double)(this->pos).pos.z);
    obj = Object_findByUniqueId(0x4300c);
    obj->state[0x25d] = state->field4_0x4;
    bVar7 = state->curSpotIdx;
    if ((DAT_8039a11c == 0) && (state->field4_0x4 == 0)) {
      while (!bVar2) {
        state->curSpotIdx = state->curSpotIdx + local_af[0] & 7;
        if ((state->field12_0xc == 0) ||
           (((int)(uint)state->field12_0xc >> (state->curSpotIdx & 0x3f) & 1U) != 0)) {
          bVar2 = true;
        }
        else if (local_af[0] == '\0') {
          local_af[0] = '\x01';
        }
      }
      state->field12_0xc = 0xf;
      if (bVar7 != state->curSpotIdx) {
        FUN_8016eb9c(state->curSpotIdx,4);
        local_ac = (&PTR_DAT_80322f70)[worldMapSpotIdx[state->curSpotIdx]];
                    /* {@symbol 80153b18} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x60))(&local_ac,1);
        DAT_8039a110 = 0.0;
        audioStartSfx((int **)0x0,0x242,0x7f,0x40,"WORLDMAP_planet.c",0x1bc);
        pOVar5 = Object_findByUniqueId((int)(&PTR_DAT_80322f70)[worldMapSpotIdx[bVar7]]);
        pOVar5->state[0x25d] = 0;
        pOVar5 = Object_findByUniqueId
                           ((int)(&PTR_DAT_80322f70)[worldMapSpotIdx[state->curSpotIdx]]);
        pOVar5->state[0x25d] = 1;
      }
    }
    DAT_8039a110 = DAT_8039a110 + 0.2;
    if (21.0 <= DAT_8039a110) {
      DAT_8039a110 = 0.0;
    }
    for (uVar9 = 0; (uVar9 & 0xff) < 8; uVar9 = uVar9 + 1) {
      pOVar5 = Object_findByUniqueId((int)(&PTR_DAT_80322f90)[uVar9 & 0xff]);
      puVar10 = pOVar5->state;
      (pOVar5->pos).rotation.y = (this->pos).rotation.y;
      (pOVar5->pos).rotation.x = (this->pos).rotation.x;
      if ((state->field4_0x4 == 0) && (((int)(uint)state->field12_0xc >> (uVar9 & 0x3f) & 1U) != 0))
      {
        if ((uVar9 & 0xff) == (uint)state->curSpotIdx) {
          uVar1 = (uint)DAT_8039a110;
          local_90 = (double)(longlong)(int)uVar1;
          uStack_94 = uVar1 & 0xff;
          local_98 = 0x43300000;
          dVar17 = (double)(DAT_8039a110 -
                           (float)((double)CONCAT44(0x43300000,uStack_94) - 4503599627370496.0));
          dVar16 = (double)*(float *)(puVar10 + (uVar1 & 0xff) * 0x18 + 0x10);
          dVar15 = (double)*(float *)(puVar10 + ((uVar1 & 0xff) + 1) * 0x18 + 0x10);
          dVar12 = (double)*(float *)(puVar10 + (uVar1 & 0xff) * 0x18 + 0x14);
          dVar11 = (double)*(float *)(puVar10 + ((uVar1 & 0xff) + 1) * 0x18 + 0x14);
          dVar14 = (double)*(float *)(puVar10 + (uVar1 & 0xff) * 0x18 + 0x18);
          dVar13 = (double)*(float *)(puVar10 + ((uVar1 & 0xff) + 1) * 0x18 + 0x18);
          puVar10[0x25d] = 2;
          iVar8 = getAngle();
          sVar6 = (short)iVar8;
          local_cc = sVar6;
          if ((uVar1 + 2 & 0xff) < 0x16) {
            iVar8 = getAngle();
            local_cc = (short)iVar8;
          }
          local_cc = local_cc - sVar6;
          if (0x8000 < local_cc) {
            local_cc = local_cc + 1;
          }
          if (local_cc < -0x8000) {
            local_cc = local_cc + -1;
          }
          uStack_94 = (int)local_cc ^ 0x80000000;
          local_98 = 0x43300000;
          local_90 = (double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000);
          iVar8 = (int)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack_94) -
                                                4503601774854144.0) +
                       (double)(float)(local_90 - 4503601774854144.0));
          local_a0 = (longlong)iVar8;
          (obj->pos).rotation.x = (short)iVar8;
          (obj->pos).pos.x = (float)(dVar17 * (double)(float)(dVar15 - dVar16) + dVar16);
          (obj->pos).pos.y = (float)(dVar17 * (double)(float)(dVar11 - dVar12) + dVar12);
          (obj->pos).pos.z = (float)(dVar17 * (double)(float)(dVar13 - dVar14) + dVar14);
        }
        else {
          puVar10[0x25d] = 1;
        }
      }
      else {
        puVar10[0x25d] = 0;
      }
    }
    obj = Object_findByUniqueId((int)(&PTR_DAT_80322f70)[worldMapSpotIdx[state->curSpotIdx]]);
    iVar8 = getLoadingFileFlags();
    if (iVar8 == 0) {
      if (state->field4_0x4 == 1) {
        if (DAT_8039a114 == 0.0) {
          DAT_8039a114 = 1.0;
        }
        if ((NVar4 & N64_BUTTON_B) == 0) {
          if ((NVar4 & N64_BUTTON_A) != 0) {
            local_a8 = *(int *)pDll_gplay;
                    /* {@symbol 8011b17c} */
            (**(code **)(local_a8 + 0xc))(4,1);
            audioStopAllSongs();
            stopStream_80068d94();
            audioStartSfx((int **)0x0,0x245,0x7f,0x40,"WORLDMAP_planet.c",0x24f);
            setShowCommandMenu(false);
            worldMapWarpCountdown = '\x05';
            DAT_8039a124 = 0;
          }
        }
        else {
          stopStream_80068d94();
          audioStartSfx((int **)0x0,0x244,0x7f,0x40,"WORLDMAP_planet.c",0x238);
                    /* {@symbol 80153db8} */
          (**(code **)(*(int *)pDll_ObjSeq + 0x28))(this,0x50);
          state->field4_0x4 = 0;
                    /* {@symbol 80153b18} */
          (**(code **)(*(int *)pDll_ObjSeq + 0x60))(&state->field4_0x4,0);
          obj = Object_findByUniqueId(0x43077);
          obj->state[0x25d] = 0;
          FUN_8016ec20('\0');
          piRomFreeLevel((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],0x3ff);
        }
      }
      else if ((state->field4_0x4 == 0) && (true)) {
        if ((DAT_8039a11c == 0) && ((NVar4 & N64_BUTTON_A) != 0)) {
          DAT_8039a11c = 10;
          piRomFreeLevel(0x2d,0x10000000);
        }
        if ((DAT_8039a11c != 0) && (DAT_8039a11c = DAT_8039a11c + -1, DAT_8039a11c < 2)) {
          DAT_8039a11c = 0;
          audioStartSfx((int **)0x0,0x245,0x7f,0x40,"WORLDMAP_planet.c",0x210);
                    /* {@symbol 80153db8} */
          (**(code **)(*(int *)pDll_ObjSeq + 0x28))(obj,0x50);
          state->field4_0x4 = 1;
                    /* {@symbol 80153b18} */
          (**(code **)(*(int *)pDll_ObjSeq + 0x60))(&state->field4_0x4,0);
          obj = Object_findByUniqueId(0x43077);
          obj->state[0x25c] = *(undefined *)((int)&PTR_DAT_803980f0 + (uint)state->curSpotIdx);
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],MODELS.bin
                         );
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],MODELS.tab
                         );
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],ANIM.BIN);
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],ANIM.TAB);
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],TEX0.bin);
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],TEX0.tab);
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],TEX1.bin);
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],TEX1.tab);
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],BLOCKS.bin
                         );
          mapLoadDataFile((uint)(byte)(&DAT_803980e8)[worldMapSpotIdx[state->curSpotIdx]],BLOCKS.tab
                         );
          countModels();
          DAT_8039a114 = 0.0;
          DAT_803980f8 = (uint)state->curSpotIdx;
        }
      }
    }
    DAT_8039a118 = DAT_8039a118 + framesThisStep;
    if (53999 < DAT_8039a118) {
      DAT_8039a118 = 0;
      audioPlaySong(0,4);
    }
    sVar6 = (this->pos).rotation.z;
    iVar8 = -(int)sVar6;
    for (bVar7 = 0; bVar7 < 8; bVar7 = bVar7 + 1) {
      obj = Object_findByUniqueId((int)(&PTR_DAT_80322f90)[bVar7]);
      (obj->pos).rotation.z = sVar6;
    }
    for (bVar7 = 0; bVar7 < 4; bVar7 = bVar7 + 1) {
      obj = Object_findByUniqueId((int)(&PTR_DAT_80322f70)[bVar7]);
      (obj->pos).rotation.x = (obj->pos).rotation.x + 0x3c;
      dVar11 = (double)angleFn_8029374c(3000);
      dVar12 = (double)angleFn_80293234(iVar8 + (&DAT_80322f80)[bVar7]);
      (obj->pos).pos.x =
           (float)((double)(float)(dVar12 * 220.0) * dVar11 + (double)(this->pos).pos.x);
      dVar11 = (double)angleFn_80293234(3000);
      dVar12 = (double)angleFn_80293234(iVar8 + (&DAT_80322f80)[bVar7]);
      (obj->pos).pos.y =
           (float)((double)(float)(dVar12 * 220.0) * dVar11 + (double)(this->pos).pos.y);
      dVar11 = (double)angleFn_8029374c(iVar8 + (&DAT_80322f80)[bVar7]);
      (obj->pos).pos.z = (float)(dVar11 * 220.0 + (double)(this->pos).pos.z);
    }
  }
  else {
    worldMapWarpCountdown = worldMapWarpCountdown + -1;
    if (worldMapWarpCountdown == '\0') {
      setDrawTrackSky(TRUE);
                    /* {@symbol 8012cfb4} */
      (**(code **)(*(int *)pDll_SaveGame + 8))(0);
      warpToMap((uint)worldMapWarpIdx[worldMapSpotIdx[state->curSpotIdx]],false);
    }
  }
  _restfpr_24();
  return;
}


/* @description Override hit detection */

void WORLDplanet_hitDetect(ObjInstance *this) { //802A8E0C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void WORLDplanet_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802A8E10
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void WORLDplanet_free(ObjInstance *this,int param2) { //802A8E6C
  return;
}


undefined4 WORLDplanet_func08(ObjInstance *this) { //802A8E70
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WORLDplanet_getExtraSize(void) { //802A8E78
  return 0xe;
}

