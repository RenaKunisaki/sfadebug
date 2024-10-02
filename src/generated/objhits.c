
/* Library Function - Single Match
    objHitGetFlag1
   
   Library: KioskDefault 0 0 */

ushort objHitGetFlag1(ObjInstance *object) { //80088CE0
  if (object->hitstate == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x2b4,"Failed assertion ht");
  }
  return object->hitstate->flags & 1;
}


/* Library Function - Single Match
    objHitUpdatePos
   
   Library: KioskDefault 0 0 */

void objHitUpdatePos(ObjInstance *object) { //80088DD0
  HitState *pHVar1;
  
  pHVar1 = object->hitstate;
  if (object->hitstate == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x302,s_Failed_assertion_object_>hits_802ed424);
  }
  if ((pHVar1 != (HitState *)0x0) && ((pHVar1->flags & 0x40) != 0)) {
    pHVar1->flags = pHVar1->flags & 0xffbf;
    (pHVar1->pos).x = (object->pos).pos.x;
    (pHVar1->pos).y = (object->pos).pos.y;
    (pHVar1->pos).z = (object->pos).pos.z;
    (pHVar1->prevPos).y = (object->prevPos).x;
    (pHVar1->prevPos).z = (object->prevPos).y;
    pHVar1->size = (object->prevPos).z;
  }
  return;
}


/* Library Function - Single Match
    objSetHitNeedsPosUpdate
   
   Library: KioskDefault 0 0 */

void objSetHitNeedsPosUpdate(ObjInstance *object) { //80088E74
  if (object->hitstate == (HitState *)0x0) {
                    
    OSPanic("objhits.c",799,s_Failed_assertion_object_>hits_802ed424);
  }
  object->hitstate->flags = object->hitstate->flags | 0x40;
  return;
}


/* Library Function - Single Match
    objHitSetFlags
   
   Library: KioskDefault 0 0 */

void objHitSetFlags(ObjInstance *object,ushort param2) { //80088ED4
  if (object->hitstate == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x333,s_Failed_assertion_object_>hits_802ed424);
  }
  object->hitstate->flags = object->hitstate->flags | param2;
  return;
}


/* Library Function - Single Match
    objHitClearFlags
   
   Library: KioskDefault 0 0 */

void objHitClearFlags(ObjInstance *object,ushort param2) { //80088F3C
  if (object->hitstate == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x347,s_Failed_assertion_object_>hits_802ed424);
  }
  object->hitstate->flags = object->hitstate->flags & ~param2;
  return;
}


/* Library Function - Single Match
    objHitSetFlagsA2
   
   Library: KioskDefault 0 0 */

void objHitSetFlagsA2(ObjInstance *object,byte param2) { //80088FA4
  if (object->hitstate == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x35b,s_Failed_assertion_object_>hits_802ed424);
  }
  object->hitstate->field_0xa2 = object->hitstate->field_0xa2 | param2;
  return;
}


/* Library Function - Single Match
    objHitClearFlagsA2
   
   Library: KioskDefault 0 0 */

void objHitClearFlagsA2(ObjInstance *object,byte param2) { //8008900C
  if (object->hitstate == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x370,s_Failed_assertion_object_>hits_802ed424);
  }
  object->hitstate->field_0xa2 = object->hitstate->field_0xa2 & ~param2;
  return;
}


/* Library Function - Single Match
    objHitFn_80089074
   
   Library: KioskDefault 0 0 */

void objHitFn_80089074(ObjInstance *param1,undefined param2,undefined param3,int param4) { //80089074
  HitState *ht;
  
  ht = param1->hitstate;
  if (ht == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x389,"Failed assertion ht");
  }
  *(undefined *)((int)&ht->sizeX2 + 1) = param2;
  *(undefined *)&ht->flags_0x60 = param3;
  if (param4 != -1) {
    (ht->field12_0x3c).y = (float)(1 << param4 + 4);
    (ht->field12_0x3c).z = (float)(1 << param4 + 4);
  }
  return;
}


/* Library Function - Single Match
    objHitFn_80089114
   
   Library: KioskDefault 0 0 */

void objHitFn_80089114(ObjInstance *object) { //80089114
  HitState *pHVar1;
  
  pHVar1 = object->hitstate;
  if (pHVar1 == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x3a5,"Failed assertion ht");
  }
  *(undefined *)((int)&pHVar1->sizeX2 + 1) = 0;
  *(undefined *)&pHVar1->flags_0x60 = 0;
  (pHVar1->field12_0x3c).y = 0.0;
  (pHVar1->field12_0x3c).z = 0.0;
  return;
}


/* Library Function - Single Match
    objHitFn_80089188
   
   Library: KioskDefault 0 0 */

void objHitFn_80089188(ObjInstance *object,ushort param2,short param3,short param4) { //80089188
  HitState *ht;
  
  ht = object->hitstate;
  if (ht != (HitState *)0x0) {
    if ((ht != (HitState *)0x0) && ((ht->flags5A & 2) != 0)) {
      ht->field17_0x54 = param3;
      ht->field18_0x56 = param4;
      ht->field16_0x52 = param2;
      ht->sizeXY_0C =
           (float)((double)CONCAT44(0x43300000,(int)(short)ht->field16_0x52 ^ 0x80000000) -
                  4503601774854144.0) *
           (float)((double)CONCAT44(0x43300000,(int)(short)ht->field16_0x52 ^ 0x80000000) -
                  4503601774854144.0);
      ht->field15_0x50 = 0x400;
      ht->cullDist = object->cullDistance;
      if (param3 < 0) {
        param3 = -param3;
      }
      if (param4 < 0) {
        param4 = -param4;
      }
      if (param4 < param3) {
        param4 = param3;
      }
      if (ht->cullDist <
          (float)((double)CONCAT44(0x43300000,(int)param4 ^ 0x80000000) - 4503601774854144.0)) {
        ht->cullDist = (float)((double)CONCAT44(0x43300000,(int)param4 ^ 0x80000000) -
                              4503601774854144.0);
      }
      ht->cullDist2 = object->cullDistance;
      if (ht->cullDist2 <
          (float)((double)CONCAT44(0x43300000,(int)(short)ht->field16_0x52 ^ 0x80000000) -
                 4503601774854144.0)) {
        ht->cullDist2 =
             (float)((double)CONCAT44(0x43300000,(int)(short)ht->field16_0x52 ^ 0x80000000) -
                    4503601774854144.0);
      }
    }
    return;
  }
                    
  OSPanic("objhits.c",0x3c0,"Failed assertion ht");
}


/* Library Function - Single Match
    objHitFn_80089354
   
   Library: KioskDefault 0 0 */

void objHitFn_80089354(ObjInstance *object,ushort param2) { //80089354
  HitState *pHVar1;
  
  pHVar1 = object->hitstate;
  if (pHVar1 == (HitState *)0x0) {
                    
    OSPanic("objhits.c",0x3f0,"Failed assertion ht");
  }
  if ((pHVar1 != (HitState *)0x0) && ((pHVar1->flags5A & 1) != 0)) {
    pHVar1->field16_0x52 = param2;
    pHVar1->sizeXY_0C =
         (float)((double)CONCAT44(0x43300000,(int)(short)pHVar1->field16_0x52 ^ 0x80000000) -
                4503601774854144.0) *
         (float)((double)CONCAT44(0x43300000,(int)(short)pHVar1->field16_0x52 ^ 0x80000000) -
                4503601774854144.0);
    pHVar1->cullDist = object->cullDistance;
    if (pHVar1->cullDist <
        (float)((double)CONCAT44(0x43300000,(int)(short)pHVar1->field16_0x52 ^ 0x80000000) -
               4503601774854144.0)) {
      pHVar1->cullDist =
           (float)((double)CONCAT44(0x43300000,(int)(short)pHVar1->field16_0x52 ^ 0x80000000) -
                  4503601774854144.0);
    }
    pHVar1->cullDist2 = object->cullDistance;
    if (pHVar1->cullDist2 <
        (float)((double)CONCAT44(0x43300000,(int)(short)pHVar1->field16_0x52 ^ 0x80000000) -
               4503601774854144.0)) {
      pHVar1->cullDist2 =
           (float)((double)CONCAT44(0x43300000,(int)(short)pHVar1->field16_0x52 ^ 0x80000000) -
                  4503601774854144.0);
    }
  }
  return;
}


/* Library Function - Single Match
    objLoadHits
   
   Library: KioskDefault 0 0 */

void Object_objLoadHits(ObjInstance *this,ModelInstance *minst,int romdefno,HitState *hitState,
                        int animId,BOOL bImmediate) { //800895D8
  ObjHitsEntry *hits;
  int iVar1;
  short offset;
  
  hits = (ObjHitsEntry *)this->data->pHits;
  hitState->objHitsSize = 0;
  if (hits != (ObjHitsEntry *)0x0) {
    for (iVar1 = 0; (&hits->animId)[iVar1] != -1; iVar1 = iVar1 + 3) {
      if (animId == (&hits->animId)[iVar1]) {
        offset = (&hits->offset)[iVar1];
        hitState->objHitsSize = (&hits->length)[iVar1];
        if (hitState->maxHitsSize < hitState->objHitsSize) {
          printf("objhits.c: keysize overflow error");
          hitState->objHitsSize = hitState->maxHitsSize;
        }
        if (bImmediate == FALSE) {
          loadAsset_fileWithOffsetLength
                    (hitState->objHits,OBJHITS.bin,(int)offset,(int)hitState->objHitsSize);
          return;
        }
        loadDataFileWithLength(OBJHITS.bin,hitState->objHits,(int)offset,(int)hitState->objHitsSize)
        ;
        return;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    objHitStoreFn_8008bbcc
   
   Library: KioskDefault 0 0 */

void objHitStoreFn_8008bbcc
               (ObjInstance *param1,ObjInstance *param2,ObjInstance *param3,char param4,char param5,
               uint param6,uint param7) { //8008BBCC
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  Texture *pTVar5;
  ushort uVar6;
  ushort uVar8;
  uint uVar7;
  undefined *puVar9;
  HitState *pHVar10;
  Texture **ppTVar11;
  uint uVar12;
  Mtx44 *pMVar13;
  Model *pMVar14;
  HitState *pHVar15;
  HitState *pHVar16;
  uint unaff_r25;
  HitSpherePos **ppHVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  double dVar21;
  double in_f18;
  double dVar22;
  double in_f20;
  double in_f21;
  double in_f22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double in_f31;
  uint local_1a0;
  uint local_19c;
  uint local_198;
  uint local_194;
  uint local_190;
  uint local_18c;
  uint local_17c;
  uint local_178;
  uint local_174;
  undefined *local_170;
  undefined auStack_16c [20];
  undefined2 local_158;
  undefined local_156;
  undefined local_155;
  undefined auStack_154 [20];
  undefined2 local_140;
  undefined local_13e;
  undefined local_13d;
  Texture *local_13c;
  float local_138;
  float local_134;
  float local_130;
  HitSpherePos *local_12c;
  float local_128;
  float local_124;
  float local_120;
  Texture *local_11c;
  float local_118;
  float local_114;
  float local_110;
  Texture *local_10c;
  float local_108;
  float local_104;
  float local_100;
  Texture **local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_d8;
  Texture *local_d4;
  HitSpherePos *local_d0;
  Texture *local_cc;
  Texture *local_c8;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  uint uStack_b4;
  
  _savefpr_18();
  pHVar16 = param1->hitstate;
  pHVar15 = param2->hitstate;
  pHVar10 = param3->hitstate;
  if ((((pHVar15->field55_0x9e == 0) && (pHVar10->field55_0x9e == 0)) &&
      (pHVar15->field56_0x9f == 0)) && (pHVar10->field56_0x9f == 0)) {
    bVar1 = false;
    bVar2 = false;
    if (((param4 == '\0') || ((pHVar16->flags5A & 0x10) == 0)) &&
       ((param5 == '\0' || (pHVar16->flags5A != 0x10)))) {
      local_178 = 1;
      ppTVar11 = &local_13c;
      local_fc = &local_11c;
      puVar9 = auStack_16c;
      bVar1 = (pHVar16->flags5A & 2) != 0;
      uStack_b4 = (int)(short)pHVar16->field16_0x52 ^ 0x80000000;
      local_13c = (Texture *)(float)((double)CONCAT44(0x43300000,uStack_b4) - 4503601774854144.0);
      local_138 = (param1->prevPos).x - playerMapOffsetX;
      local_134 = (param1->prevPos).y;
      local_130 = (param1->prevPos).z - playerMapOffsetZ;
      local_118 = (pHVar16->prevPos).y - playerMapOffsetX;
      local_114 = (pHVar16->prevPos).z;
      local_110 = pHVar16->size - playerMapOffsetZ;
      local_156 = 0;
      local_155 = 0;
      local_158 = 0;
      local_11c = local_13c;
      local_d4 = local_13c;
    }
    else {
      pMVar13 = param1->modelInstances->mtxs[(char)param1->curModel + -3];
      pMVar14 = (Model *)pMVar13->m11;
      local_178 = (uint)pMVar14->nHitSpheres;
      ppTVar11 = (Texture **)pMVar13[1].m11;
      local_fc = (Texture **)(&pMVar13->m43)[*(ushort *)&pMVar13->m23 >> 2 & 1 ^ 1];
      puVar9 = (undefined *)pMVar14->sphereHits;
      if (param3 == param1) {
        uVar8 = modelGetFieldA4(pMVar14);
        uStack_b4 = (uint)uVar8;
        local_d4 = (Texture *)
                   ((param1->pos).scale *
                   (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503599627370496.0));
      }
      else {
        uVar8 = modelGetFieldA4(pMVar14);
        uStack_b4 = (uint)uVar8;
        local_d4 = (Texture *)
                   ((param3->pos).scale *
                   (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503599627370496.0));
      }
      local_b8 = 0x43300000;
      if (((param1->pos).flags & Invisible) != 0) goto LAB_8008cb1c;
    }
    local_b8 = 0x43300000;
    if (((param4 == '\0') || ((pHVar15->flags5A & 0x10) == 0)) &&
       ((param5 == '\0' || (pHVar15->flags5A != 0x10)))) {
      local_174 = 1;
      ppHVar17 = &local_12c;
      local_170 = auStack_154;
      bVar2 = (pHVar15->flags5A & 2) != 0;
      uStack_b4 = (int)(short)pHVar15->field16_0x52 ^ 0x80000000;
      local_12c = (HitSpherePos *)
                  (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503601774854144.0);
      local_128 = (param2->prevPos).x - playerMapOffsetX;
      local_124 = (param2->prevPos).y;
      local_120 = (param2->prevPos).z - playerMapOffsetZ;
      local_10c = local_13c;
      local_108 = (pHVar16->prevPos).y - playerMapOffsetX;
      local_104 = (pHVar16->prevPos).z;
      local_100 = pHVar16->size - playerMapOffsetZ;
      local_13e = 0;
      local_13d = 0;
      local_140 = 0;
      local_d0 = local_12c;
    }
    else {
      pMVar13 = param2->modelInstances->mtxs[(char)param2->curModel + -3];
      pMVar14 = (Model *)pMVar13->m11;
      local_174 = (uint)pMVar14->nHitSpheres;
      ppHVar17 = (HitSpherePos **)pMVar13[1].m11;
      local_170 = (undefined *)pMVar14->sphereHits;
      uVar8 = modelGetFieldA4(pMVar14);
      uStack_b4 = (uint)uVar8;
      local_b8 = 0x43300000;
      local_d0 = (HitSpherePos *)
                 ((param2->pos).scale *
                 (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503599627370496.0));
      if (((param2->pos).flags & Invisible) != 0) goto LAB_8008cb1c;
    }
    local_b8 = 0x43300000;
    if ((0x40 < local_178) || (0x40 < local_174)) {
      debugPrint("HIT VOLUMES: an object has too many hit spheres");
    }
    dVar28 = (double)((param1->prevPos).x - (param2->prevPos).x);
    dVar26 = (double)((param1->prevPos).y - (param2->prevPos).y);
    dVar27 = (double)((param1->prevPos).z - (param2->prevPos).z);
    dVar21 = sqrt((double)(float)(dVar27 * dVar27 +
                                 (double)(float)(dVar28 * dVar28 + (double)(float)(dVar26 * dVar26))
                                 ));
    if (dVar21 <= (double)((float)local_d4 + (float)local_d0 + 100.0)) {
      local_18c = 0;
      local_190 = 0;
      local_194 = 0;
      local_198 = 0;
      local_19c = 0;
      local_1a0 = 0;
      for (iVar19 = 0; iVar19 < (int)local_178; iVar19 = iVar19 + 1) {
        if (iVar19 == (char)puVar9[iVar19 * 0x18 + 0x16]) {
          if ((param6 & 1 << (int)(char)puVar9[iVar19 * 0x18 + 0x17]) != 0) {
            local_18c = local_18c | 1 << iVar19;
            local_190 = local_190 | (1 << iVar19) >> 0x1f;
          }
          if ((param7 & 1 << (int)(char)puVar9[iVar19 * 0x18 + 0x17]) != 0) {
            local_19c = local_19c | 1 << iVar19;
            local_1a0 = local_1a0 | (1 << iVar19) >> 0x1f;
          }
        }
      }
      for (iVar19 = 0; iVar19 < (int)local_174; iVar19 = iVar19 + 1) {
        if (iVar19 == (char)local_170[iVar19 * 0x18 + 0x16]) {
          local_194 = local_194 | 1 << iVar19;
          local_198 = local_198 | (1 << iVar19) >> 0x1f;
        }
      }
      local_f4 = -1.0;
      iVar19 = 1;
      while (iVar19 != 0) {
        iVar19 = 0;
        for (iVar20 = 0; iVar20 < (int)local_178; iVar20 = iVar20 + 1) {
          if ((local_18c & 1 << iVar20 | local_190 & (1 << iVar20) >> 0x1f) != 0) {
            dVar22 = (double)(float)ppTVar11[iVar20 * 4];
            dVar24 = (double)(float)ppTVar11[iVar20 * 4 + 1];
            dVar25 = (double)(float)ppTVar11[iVar20 * 4 + 2];
            dVar23 = (double)(float)ppTVar11[iVar20 * 4 + 3];
            bVar3 = (local_19c & 1 << iVar20 | local_1a0 & (1 << iVar20) >> 0x1f) == 0;
            if (!bVar3) {
              in_f18 = (double)(float)local_fc[iVar20 * 4 + 1];
              local_c8 = local_fc[iVar20 * 4 + 2];
              local_cc = local_fc[iVar20 * 4 + 3];
              in_f22 = (double)(float)(dVar24 - in_f18);
              in_f21 = (double)(float)(dVar25 - (double)(float)local_fc[iVar20 * 4 + 2]);
              in_f20 = (double)(float)(dVar23 - (double)(float)local_fc[iVar20 * 4 + 3]);
              local_f8 = (float)(in_f20 * in_f20 +
                                (double)(float)(in_f22 * in_f22 + (double)(float)(in_f21 * in_f21)))
              ;
              if (local_f8 <= 0.0) {
                bVar3 = true;
              }
              else {
                local_f8 = 1.0 / local_f8;
              }
            }
            for (iVar18 = 0; iVar18 < (int)local_174; iVar18 = iVar18 + 1) {
              if ((local_194 & 1 << iVar18 | local_198 & (1 << iVar18) >> 0x1f) != 0) {
                unaff_r25 = 0;
                if (((iVar20 == 0) && (bVar1)) || ((iVar18 == 0 && (bVar2)))) {
                  if (bVar1) {
                    uStack_b4 = (int)pHVar16->field17_0x54 ^ 0x80000000;
                    local_b8 = 0x43300000;
                    local_e4 = (float)(dVar25 + (double)(float)((double)CONCAT44(0x43300000,
                                                                                 uStack_b4) -
                                                               4503601774854144.0));
                    uStack_bc = (int)pHVar16->field18_0x56 ^ 0x80000000;
                    local_c0 = 0x43300000;
                    local_e8 = (float)(dVar25 + (double)(float)((double)CONCAT44(0x43300000,
                                                                                 uStack_bc) -
                                                               4503601774854144.0));
                    local_ec = (float)ppHVar17[iVar18 * 4 + 2] - (float)ppHVar17[iVar18 * 4];
                    local_f0 = (float)ppHVar17[iVar18 * 4 + 2] + (float)ppHVar17[iVar18 * 4];
                  }
                  else {
                    local_e4 = (float)(dVar25 - dVar22);
                    local_e8 = (float)(dVar25 + dVar22);
                    uStack_bc = (int)pHVar15->field17_0x54 ^ 0x80000000;
                    local_c0 = 0x43300000;
                    local_ec = (float)((double)CONCAT44(0x43300000,uStack_bc) - 4503601774854144.0)
                               + (float)ppHVar17[iVar18 * 4 + 2];
                    uStack_b4 = (int)pHVar15->field18_0x56 ^ 0x80000000;
                    local_b8 = 0x43300000;
                    local_f0 = (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503601774854144.0)
                               + (float)ppHVar17[iVar18 * 4 + 2];
                  }
                  local_b8 = 0x43300000;
                  local_c0 = 0x43300000;
                  if (((local_e4 <= local_ec) || (local_e4 <= local_f0)) &&
                     ((local_ec <= local_e8 || (local_f0 <= local_e8)))) {
                    in_f31 = (double)((float)(dVar22 + (double)(float)ppHVar17[iVar18 * 4]) *
                                     (float)(dVar22 + (double)(float)ppHVar17[iVar18 * 4]));
                    dVar28 = (double)(float)(dVar24 - (double)(float)ppHVar17[iVar18 * 4 + 1]);
                    dVar21 = (double)(float)(dVar28 * dVar28);
                    if (dVar21 < in_f31) {
                      dVar27 = (double)(float)(dVar23 - (double)(float)ppHVar17[iVar18 * 4 + 3]);
                      dVar21 = (double)(float)(dVar27 * dVar27 + dVar21);
                      if (dVar21 < in_f31) {
                        dVar26 = 0.0;
                        unaff_r25 = 1;
                      }
                    }
                  }
                }
                else {
                  in_f31 = (double)((float)(dVar22 + (double)(float)ppHVar17[iVar18 * 4]) *
                                   (float)(dVar22 + (double)(float)ppHVar17[iVar18 * 4]));
                  if (bVar3) {
                    dVar28 = (double)(float)(dVar24 - (double)(float)ppHVar17[iVar18 * 4 + 1]);
                    dVar21 = (double)(float)(dVar28 * dVar28);
                    if (dVar21 < in_f31) {
                      dVar26 = (double)(float)(dVar25 - (double)(float)ppHVar17[iVar18 * 4 + 2]);
                      dVar21 = (double)(float)(dVar26 * dVar26 + dVar21);
                      if (dVar21 < in_f31) {
                        dVar27 = (double)(float)(dVar23 - (double)(float)ppHVar17[iVar18 * 4 + 3]);
                        dVar21 = (double)(float)(dVar27 * dVar27 + dVar21);
                        if (dVar21 < in_f31) {
                          unaff_r25 = 1;
                        }
                      }
                    }
                  }
                  else {
                    dVar21 = (double)(local_f8 *
                                     -(-(float)(in_f20 * (double)(float)ppHVar17[iVar18 * 4 + 3] +
                                               (double)(float)(in_f22 * (double)(float)ppHVar17[
                                                  iVar18 * 4 + 1] +
                                                  (double)(float)(in_f21 * (double)(float)ppHVar17[
                                                  iVar18 * 4 + 2]))) +
                                      (float)((double)(float)local_cc * in_f20 +
                                             (double)(float)(in_f18 * in_f22 +
                                                            (double)(float)((double)(float)local_c8
                                                                           * in_f21)))));
                    if (0.0 < dVar21) {
                      if (dVar21 < 1.0) {
                        dVar28 = (double)((float)(dVar21 * in_f22 + in_f18) -
                                         (float)ppHVar17[iVar18 * 4 + 1]);
                        dVar26 = (double)((float)(dVar21 * in_f21 + (double)(float)local_c8) -
                                         (float)ppHVar17[iVar18 * 4 + 2]);
                        dVar27 = (double)((float)(dVar21 * in_f20 + (double)(float)local_cc) -
                                         (float)ppHVar17[iVar18 * 4 + 3]);
                      }
                      else {
                        dVar28 = (double)(float)(dVar24 - (double)(float)ppHVar17[iVar18 * 4 + 1]);
                        dVar26 = (double)(float)(dVar25 - (double)(float)ppHVar17[iVar18 * 4 + 2]);
                        dVar27 = (double)(float)(dVar23 - (double)(float)ppHVar17[iVar18 * 4 + 3]);
                      }
                    }
                    else {
                      dVar28 = (double)(float)(in_f18 - (double)(float)ppHVar17[iVar18 * 4 + 1]);
                      dVar26 = (double)((float)local_c8 - (float)ppHVar17[iVar18 * 4 + 2]);
                      dVar27 = (double)((float)local_cc - (float)ppHVar17[iVar18 * 4 + 3]);
                    }
                    dVar21 = (double)(float)(dVar27 * dVar27 +
                                            (double)(float)(dVar28 * dVar28 +
                                                           (double)(float)(dVar26 * dVar26)));
                    if (dVar21 < in_f31) {
                      unaff_r25 = 1;
                    }
                  }
                }
                if (unaff_r25 != 0) {
                  if (iVar19 < 0x40) {
                    if (param5 == '\0') {
                      in_f31 = sqrt((double)(float)(dVar27 * dVar27 +
                                                   (double)(float)(dVar28 * dVar28 +
                                                                  (double)(float)(dVar26 * dVar26)))
                                   );
                      if (0.0 < in_f31) {
                        dVar28 = (double)(float)(dVar28 / in_f31);
                        dVar26 = (double)(float)(dVar26 / in_f31);
                        dVar27 = (double)(float)(dVar27 / in_f31);
                      }
                      (&DAT_80357778)[iVar19 * 7] =
                           (float)(dVar28 * (double)(float)ppHVar17[iVar18 * 4]);
                      (&DAT_8035777c)[iVar19 * 7] =
                           (float)(dVar26 * (double)(float)ppHVar17[iVar18 * 4]);
                      (&DAT_80357780)[iVar19 * 7] =
                           (float)(dVar27 * (double)(float)ppHVar17[iVar18 * 4]);
                    }
                    else if (0.0 < dVar21) {
                      fVar4 = (float)((double)(float)(in_f31 - dVar21) / in_f31);
                      in_f31 = (double)fVar4;
                      (&DAT_80357784)[iVar19 * 7] = fVar4;
                      (&DAT_80357770)[iVar19 * 7] = (float)(dVar28 * in_f31);
                      (&DAT_80357774)[iVar19 * 7] = (float)(dVar27 * in_f31);
                    }
                    (&DAT_80357788)[iVar19 * 0x1c] = (char)iVar20;
                    (&DAT_80357789)[iVar19 * 0x1c] = (char)iVar18;
                    iVar19 = iVar19 + 1;
                  }
                  else {
                    printf("objhits.c: MAX_HITSTORE overflow");
                  }
                }
              }
            }
          }
        }
        local_18c = 0;
        local_190 = 0;
        local_194 = 0;
        local_198 = 0;
        for (iVar20 = 0; iVar20 < iVar19; iVar20 = iVar20 + 1) {
          local_17c = (uint)(byte)(&DAT_80357788)[iVar20 * 0x1c];
          unaff_r25 = (uint)(byte)(&DAT_80357789)[iVar20 * 0x1c];
          uVar8 = *(ushort *)(puVar9 + local_17c * 0x18 + 0x14);
          uVar6 = *(ushort *)(local_170 + unaff_r25 * 0x18 + 0x14);
          for (uVar12 = (uint)uVar8; uVar12 != 0; uVar12 = (uVar12 & 0xfff) << 4) {
            uVar7 = 1 << local_17c + (uVar12 >> 0xc);
            local_18c = local_18c | uVar7;
            local_190 = local_190 | (int)uVar7 >> 0x1f;
          }
          for (uVar12 = (uint)uVar6; uVar12 != 0; uVar12 = (uVar12 & 0xfff) << 4) {
            uVar7 = 1 << unaff_r25 + (uVar12 >> 0xc);
            local_194 = local_194 | uVar7;
            local_198 = local_198 | (int)uVar7 >> 0x1f;
          }
          if ((uVar8 == 0) && (uVar6 == 0)) {
            if (param4 == '\0') {
              if ((param5 != '\0') && (local_f4 < (float)(&DAT_80357784)[iVar20 * 7])) {
                local_f4 = (float)(&DAT_80357784)[iVar20 * 7];
                local_d8 = (float)(&DAT_80357770)[iVar20 * 7];
                local_e0 = (float)(&DAT_80357774)[iVar20 * 7];
              }
            }
            else {
              if (bVar2) {
                pTVar5 = ppTVar11[local_17c * 4 + 2];
              }
              else {
                pTVar5 = (Texture *)
                         ((float)ppHVar17[unaff_r25 * 4 + 2] + (float)(&DAT_8035777c)[iVar20 * 7]);
              }
              FUN_80088680((double)((float)ppHVar17[unaff_r25 * 4 + 1] +
                                   (float)(&DAT_80357778)[iVar20 * 7]),(double)(float)pTVar5,
                           (double)((float)ppHVar17[unaff_r25 * 4 + 3] +
                                   (float)(&DAT_80357780)[iVar20 * 7]),(int)param2,(int)param1,
                           *(char *)((int)&pHVar10->sizeX2 + 1),*(undefined *)&pHVar10->flags_0x60,
                           (&DAT_80357789)[iVar20 * 0x1c]);
            }
          }
          else if (uVar8 == 0) {
            local_18c = local_18c | 1 << local_17c;
            local_190 = local_190 | (1 << local_17c) >> 0x1f;
          }
          else if (uVar6 == 0) {
            local_194 = local_194 | 1 << unaff_r25;
            local_198 = local_198 | (1 << unaff_r25) >> 0x1f;
          }
        }
      }
      if ((param4 == '\0') || (pHVar15->flags_0x62 == 0)) {
        if ((param5 != '\0') && ((0.0 < local_f4 && (param1 == param3)))) {
          FUN_80088818((int)param2,(int)param1,pHVar10->field_0x5d,*(undefined *)&pHVar10->sizeX2,
                       (char)unaff_r25);
          FUN_80088818((int)param1,(int)param2,pHVar15->field_0x5d,*(undefined *)&pHVar15->sizeX2,
                       (char)local_17c);
          playerGuardFn_8008b0f8(-(double)local_d8,0.0,-(double)local_e0,param1,param2,FALSE);
        }
      }
      else {
        if ((pHVar16->flags & 0x80) != 0) {
          FUN_80088da4((int)param1);
        }
        if ((pHVar15->flags & 0x80) != 0) {
          FUN_80088da4((int)param2);
        }
      }
    }
  }
LAB_8008cb1c:
  _restfpr_18();
  return;
}


/* Library Function - Single Match
    objHitsModRadiFn_8008ece4
   
   Library: KioskDefault 0 0 */

void objHitsModRadiFn_8008ece4
               (double param1,float *param2,int param3,int *param4,vec3f **param5,int **param6,
               float *param7) { //8008ECE4
  double dVar1;
  float fVar2;
  vec3f *pvVar3;
  uint uVar4;
  int iVar5;
  int rad1;
  int mod;
  vec3f *param3_00;
  vec3f *param3_01;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  vec3f *local_cc;
  float local_c8;
  vec3f *local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  vec3f *local_9c;
  vec3f *local_98;
  vec3f *local_94;
  vec3f local_90;
  vec3f local_84 [2];
  
  _savefpr_25();
  iVar5 = 0;
  if (param3 != 0) {
    mod = *param4;
    if (mod == 0) {
                    
      OSPanic("objhits.c",0x1082,"Failed assertion mod");
    }
    rad1 = *(int *)(param3 + 4);
    if (rad1 == 0) {
                    
      OSPanic("objhits.c",0x1085,"Failed assertion rad1");
    }
    dVar7 = (double)(float)(param1 + param1);
    *param6 = (int *)param5;
    *param7 = 0.0;
    objhits_modelInstanceGetJMtxTranslation(local_84,param4,0);
    dVar6 = sqrt((double)(local_b8 * local_b8 + local_c0 * local_c0 + local_bc * local_bc));
    dVar6 = (double)(float)(dVar6 - param1);
    local_b4 = *param2 + *param2;
    local_b0 = param2[1] + param2[1];
    local_ac = param2[2] + param2[2];
    param3_01 = (vec3f *)(uint)*(byte *)(mod + 0xb7);
    while (param3_01 = (vec3f *)((int)&param3_01[-1].z + 3), param3_01 != (vec3f *)0x0) {
      if (dVar6 < (double)*(float *)(*(int *)(param3 + 0x10) + (int)param3_01 * 4)) {
        param3_00 = (vec3f *)(int)*(char *)(*(int *)(mod + 0x3c) + (int)param3_01 * 0x1c);
        objhits_modelInstanceGetJMtxTranslation(local_84,param4,(int)param3_01);
        objhits_modelInstanceGetJMtxTranslation(&local_90,param4,(int)param3_00);
        dVar9 = (double)*(float *)(rad1 + (int)param3_01 * 4);
        dVar8 = (double)*(float *)(rad1 + (int)param3_00 * 4);
        *(undefined *)((int)&param3_01->x + *(int *)(param3 + 0x18)) = 1;
        *(undefined *)((int)&param3_00->x + *(int *)(param3 + 0x18)) = 1;
        local_a8 = (local_90.x + local_84[0].x) - local_b4;
        local_a4 = 0.0;
        local_a0 = (local_90.z + local_84[0].z) - local_ac;
        if (dVar9 <= dVar8) {
          dVar1 = dVar8 + dVar8;
        }
        else {
          dVar1 = dVar9 + dVar9;
        }
        fVar2 = (float)(dVar7 + (double)(*(float *)(*(int *)(param3 + 0xc) + (int)param3_01 * 4) +
                                        (float)dVar1));
        if (local_a0 * local_a0 + local_a8 * local_a8 + 0.0 < fVar2 * fVar2) {
          fVar2 = 1.0 / *(float *)(*(int *)(param3 + 0xc) + (int)param3_01 * 4);
          local_9c = (vec3f *)((local_90.x - local_84[0].x) * fVar2);
          local_98 = (vec3f *)((local_90.y - local_84[0].y) * fVar2);
          local_94 = (vec3f *)((local_90.z - local_84[0].z) * fVar2);
          uVar4 = FUN_8008d554(param1,dVar9,dVar8,
                               (double)*(float *)(*(int *)(param3 + 0xc) + (int)param3_01 * 4),
                               param2,&local_84[0].x,(float *)&local_9c,&local_90.x,
                               (float *)&local_c4,&local_c8,(float *)&local_cc);
          if (uVar4 != 0) {
            *(undefined *)((int)&param3_01->x + *(int *)(param3 + 0x18)) = 1;
            *(undefined *)((int)&param3_00->x + *(int *)(param3 + 0x18)) = 1;
            dVar8 = sqrt((double)local_c8);
            param5[0xc] = (vec3f *)(float)(param1 + (double)(float)(dVar8 - (double)(float)local_cc)
                                          );
            if ((float)param5[0xc] <= 0.0) {
              pvVar3 = (vec3f *)-(float)param5[0xc];
            }
            else {
              pvVar3 = param5[0xc];
            }
            param5[0xf] = (vec3f *)(1.0 / (float)pvVar3);
            *param7 = *param7 + (float)param5[0xf];
            if ((float)param5[0xc] < (float)(*param6)[0xc]) {
              *param6 = (int *)param5;
            }
            *param5 = local_84;
            param5[1] = &local_90;
            param5[2] = (vec3f *)local_84[0].x;
            param5[3] = (vec3f *)local_84[0].y;
            param5[4] = (vec3f *)local_84[0].z;
            param5[5] = (vec3f *)local_90.x;
            param5[6] = (vec3f *)local_90.y;
            param5[7] = (vec3f *)local_90.z;
            param5[0xb] = local_c4;
            param5[0xe] = local_cc;
            dVar8 = sqrt((double)local_c8);
            param5[0xd] = (vec3f *)(float)dVar8;
            param5[8] = local_9c;
            param5[9] = local_98;
            param5[10] = local_94;
            param5[0x10] = param3_01;
            param5[0x11] = param3_00;
            if (iVar5 < 0x14) {
              iVar5 = iVar5 + 1;
              param5 = param5 + 0x12;
            }
          }
        }
      }
    }
    param5[0x10] = (vec3f *)0xffffffff;
  }
  _restfpr_25();
  return;
}


/* Library Function - Single Match
    objHitsModRadiFn_8008f0e8
   
   Library: KioskDefault 0 0 */

void objHitsModRadiFn_8008f0e8
               (double param1,double param2,double param3,float *param4,int param5,int *param6,
               vec3f **param7,int **param8,float *param9) { //8008F0E8
  double dVar1;
  float fVar2;
  vec3f *pvVar3;
  uint uVar4;
  int iVar5;
  int mod;
  int rad1;
  vec3f *param3_00;
  vec3f *param3_01;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  vec3f *local_dc;
  float local_d8;
  vec3f *local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  vec3f *local_ac;
  vec3f *local_a8;
  vec3f *local_a4;
  vec3f local_a0;
  vec3f local_94 [2];
  
  _savefpr_23();
  iVar5 = 0;
  if (param5 != 0) {
    mod = *param6;
    if (mod == 0) {
                    
      OSPanic("objhits.c",0x10da,"Failed assertion mod");
    }
    rad1 = *(int *)(param5 + 4);
    if (rad1 == 0) {
                    
      OSPanic("objhits.c",0x10dd,"Failed assertion rad1");
    }
    dVar7 = (double)(float)(param1 + param1);
    *param8 = (int *)param7;
    *param9 = 0.0;
    objhits_modelInstanceGetJMtxTranslation(local_94,param6,0);
    local_d0 = local_94[0].x - *param4;
    local_cc = 0.0;
    local_c8 = local_94[0].z - param4[2];
    dVar6 = sqrt((double)(local_c8 * local_c8 + local_d0 * local_d0 + 0.0));
    dVar6 = (double)(float)(dVar6 - param1);
    local_c4 = *param4 + *param4;
    local_c0 = param4[1] + param4[1];
    local_bc = param4[2] + param4[2];
    param3_01 = (vec3f *)(uint)*(byte *)(mod + 0xb7);
    while (param3_01 = (vec3f *)((int)&param3_01[-1].z + 3), param3_01 != (vec3f *)0x0) {
      if (dVar6 < (double)*(float *)(*(int *)(param5 + 0x10) + (int)param3_01 * 4)) {
        param3_00 = (vec3f *)(int)*(char *)(*(int *)(mod + 0x3c) + (int)param3_01 * 0x1c);
        objhits_modelInstanceGetJMtxTranslation(local_94,param6,(int)param3_01);
        objhits_modelInstanceGetJMtxTranslation(&local_a0,param6,(int)param3_00);
        dVar9 = (double)*(float *)(rad1 + (int)param3_01 * 4);
        dVar8 = (double)*(float *)(rad1 + (int)param3_00 * 4);
        if ((((double)(float)((double)local_94[0].y - dVar9) <= param2) ||
            ((double)(float)((double)local_a0.y - dVar8) <= param2)) &&
           ((param3 <= (double)(float)((double)local_94[0].y + dVar9) ||
            (param3 <= (double)(float)((double)local_a0.y + dVar8))))) {
          local_b8 = (local_a0.x + local_94[0].x) - local_c4;
          local_b4 = 0.0;
          local_b0 = (local_a0.z + local_94[0].z) - local_bc;
          if (dVar9 <= dVar8) {
            dVar1 = dVar8 + dVar8;
          }
          else {
            dVar1 = dVar9 + dVar9;
          }
          fVar2 = (float)(dVar7 + (double)(*(float *)(*(int *)(param5 + 0xc) + (int)param3_01 * 4) +
                                          (float)dVar1));
          if (local_b0 * local_b0 + local_b8 * local_b8 + 0.0 < fVar2 * fVar2) {
            local_ac = (vec3f *)(local_a0.x - local_94[0].x);
            local_a8 = (vec3f *)(local_a0.y - local_94[0].y);
            local_a4 = (vec3f *)(local_a0.z - local_94[0].z);
            if (*(float *)(*(int *)(param5 + 0xc) + (int)param3_01 * 4) != 0.0) {
              fVar2 = 1.0 / *(float *)(*(int *)(param5 + 0xc) + (int)param3_01 * 4);
              local_ac = (vec3f *)((float)local_ac * fVar2);
              local_a8 = (vec3f *)((float)local_a8 * fVar2);
              local_a4 = (vec3f *)((float)local_a4 * fVar2);
            }
            *(undefined *)((int)&param3_01->x + *(int *)(param5 + 0x18)) = 0;
            *(undefined *)((int)&param3_00->x + *(int *)(param5 + 0x18)) = 0;
            uVar4 = FUN_8008d744(param1,dVar9,dVar8,
                                 (double)*(float *)(*(int *)(param5 + 0xc) + (int)param3_01 * 4),
                                 param4,&local_94[0].x,(float *)&local_ac,&local_a0.x,
                                 (float *)&local_d4,&local_d8,(float *)&local_dc);
            if (uVar4 != 0) {
              *(undefined *)((int)&param3_01->x + *(int *)(param5 + 0x18)) = 1;
              *(undefined *)((int)&param3_00->x + *(int *)(param5 + 0x18)) = 1;
              dVar8 = sqrt((double)local_d8);
              param7[0xc] = (vec3f *)(float)(param1 + (double)(float)(dVar8 - (double)(float)
                                                  local_dc));
              if ((float)param7[0xc] <= 0.0) {
                pvVar3 = (vec3f *)-(float)param7[0xc];
              }
              else {
                pvVar3 = param7[0xc];
              }
              param7[0xf] = (vec3f *)(1.0 / (float)pvVar3);
              *param9 = *param9 + (float)param7[0xf];
              if ((float)param7[0xc] < (float)(*param8)[0xc]) {
                *param8 = (int *)param7;
              }
              *param7 = local_94;
              param7[1] = &local_a0;
              param7[2] = (vec3f *)local_94[0].x;
              param7[3] = (vec3f *)local_94[0].y;
              param7[4] = (vec3f *)local_94[0].z;
              param7[5] = (vec3f *)local_a0.x;
              param7[6] = (vec3f *)local_a0.y;
              param7[7] = (vec3f *)local_a0.z;
              param7[0xb] = local_d4;
              param7[0xe] = local_dc;
              dVar8 = sqrt((double)local_d8);
              param7[0xd] = (vec3f *)(float)dVar8;
              param7[8] = local_ac;
              param7[9] = local_a8;
              param7[10] = local_a4;
              param7[0x10] = param3_01;
              param7[0x11] = param3_00;
              if (iVar5 < 0x14) {
                param7 = param7 + 0x12;
                iVar5 = iVar5 + 1;
              }
            }
          }
        }
      }
    }
    param7[0x10] = (vec3f *)0xffffffff;
  }
  _restfpr_23();
  return;
}


/* Library Function - Single Match
    modelInstanceGetJMtxTranslation
   
   Library: KioskDefault 0 0 */

void objhits_modelInstanceGetJMtxTranslation(vec3f *out,int *param2,int param3) { //800905C0
  int jMtx;
  
  jMtx = modelInstGetjMtx((ModelInstance *)param2,param3);
  if (jMtx == 0) {
                    
    OSPanic("objhits.c",0x134b,"Failed assertion jMtx");
  }
  out->x = *(float *)(jMtx + 0xc);
  out->y = *(float *)(jMtx + 0x1c);
  out->z = *(float *)(jMtx + 0x2c);
  return;
}

