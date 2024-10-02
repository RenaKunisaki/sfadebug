
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void groundAnimator_initialise(undefined4 param) { //801F7FE0
  return;
}


/* @description Called when DLL is unloaded */

void groundAnimator_release(void) { //801F7FE4
  return;
}


/* Library Function - Single Match
    groundAnimator_func03
   
   Library: KioskDefault 0 0 */

void groundAnimator_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801F7FE8
  undefined2 uVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  uVar1._0_1_ = objDef[1].bound;
  uVar1._1_1_ = objDef[1].cullDist;
  puVar3[0x28] = (char)uVar1;
  if (2 < (byte)puVar3[0x28]) {
    puVar3[0x2a] = puVar3[0x2a] | 8;
    puVar3[0x28] = puVar3[0x28] + -2;
  }
  *(float *)(puVar3 + 0x14) =
       (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)&objDef[1].pos.y + 3)) -
              4503599627370496.0);
  puVar3[0x27] = 0xff;
  *(float *)(puVar3 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)&objDef[1].pos.y + 2)) -
              4503599627370496.0);
  if (*(char *)((int)&objDef[1].pos.y + 1) != '\0') {
    uVar2 = mainGetBit((int)(short)objDef[1].objType);
    if (uVar2 != 0) {
      *(uint *)(puVar3 + 0xc) = (uint)*(byte *)&objDef[1].pos.x * 100;
      puVar3[0x2a] = puVar3[0x2a] | 2;
      if ((puVar3[0x2a] & 8) != 0) {
        puVar3[0x2a] = puVar3[0x2a] | 0x20;
      }
    }
    Object_objAddObjectType(this,0x33);
    if (1 < *(byte *)((int)&objDef[1].pos.x + 1)) {
      *(undefined *)((int)&objDef[1].pos.x + 1) = 0;
    }
  }
  return;
}


/* Library Function - Single Match
    groundAnimator_func04
   
   Library: KioskDefault 0 0 */

void groundAnimator_update(ObjInstance *this) { //801F80F8
  byte bVar1;
  ObjInstance *player;
  uint uVar2;
  LoadedDll *dll;
  int iVar3;
  char cVar5;
  MapBlock *block;
  void *pvVar4;
  PolygonGroup *group;
  vec3s *pos;
  ObjInstance *tricky;
  int iVar6;
  uint iPoly;
  ObjDef *def;
  ObjState_GroundAnimator *state;
  double dist;
  float local_7c;
  vec3f vStack_78;
  GCPolygon *poly;
  int local_60 [2];
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  
  player = Object_objGetMain();
  state = (ObjState_GroundAnimator *)this->state;
  def = this->def;
  dist = (double)objDistSqObj2ObjXZ(this,player);
  if ((2500.0 <= dist) || (uVar2 = mainGetBit(0x931), uVar2 != 0)) {
    if ((state->flags2A & 8) != 0) {
      if (((state->flags2A & 0x20) != 0) && ((state->flags2A & 0x10) == 0)) {
        dll = (LoadedDll *)runlinkDownloadCode(0x1050,1);
        (**(code **)(dll->id + 4))(this,0,0,0,0xffffffff,0);
        (**(code **)(dll->id + 4))(this,0,0,0,0xffffffff,local_60);
        DLL_free(dll);
        state->flags2A = state->flags2A | 0x10;
      }
      if (((state->flags2A & 2) != 0) && (dist = (double)objDistObj2ObjXZ(this,player), dist < 10.0)
         ) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
      }
    }
    if (*(char *)((int)&def[1].pos.y + 1) != '\0') {
      iVar3 = getBlockIdxAtCoords((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                                  (double)(this->pos).pos.z);
      cVar5 = (char)iVar3;
      bVar1 = state->flags2A;
      if (cVar5 < '\0') {
        state->flags2A = state->flags2A & 0xfe;
      }
      else {
        state->flags2A = state->flags2A | 1;
      }
      if ((state->flags2A & 1) != (bVar1 & 1)) {
        state->field22_0x29 = '\x02';
      }
      if ((state->flags2A & 1) != 0) {
        if (((state->flags2A & 1) != 0) && (state->field0_0x0 == (void *)0x0)) {
          block = mapGetBlockByIdx((int)cVar5);
          iVar3 = mapBlockFindPolyGroupFn_800b1238(block,(uint)*(byte *)((int)&def[1].pos.y + 1));
          state->polyGroupCount = (short)iVar3 * 3;
          if (0 < state->polyGroupCount) {
            pvVar4 = mmAlloc(state->polyGroupCount * 6,TRACK_COL,"groundanim");
            state->field0_0x0 = pvVar4;
            state->field1_0x4 = (void *)((int)pvVar4 + state->polyGroupCount * 4);
            GroundAnimator_fn801932c8((int)this,(int *)state,(int)def);
          }
        }
        if (state->polyGroupCount != 0) {
          if (state->field2_0x8 == (void *)0x0) {
            local_7c = 100.0;
            tricky = getSeqObj(5,this,&local_7c);
            state->field2_0x8 = tricky;
            pvVar4 = state->field2_0x8;
            if (pvVar4 != (void *)0x0) {
              if ((state->flags2A & 2) == 0) {
                (**(code **)(**(int **)((int)pvVar4 + 0x68) + 0x24))(pvVar4,1);
              }
              (**(code **)(**(int **)((int)pvVar4 + 0x68) + 0x38))
                        ((double)(this->pos).pos.x,
                         (double)((this->pos).pos.y - (float)state->field5_0x14),
                         (double)(this->pos).pos.z,pvVar4);
            }
          }
          else if ((*(ushort *)((int)state->field2_0x8 + 0xb0) & 0x40) != 0) {
            state->field2_0x8 = (void *)0x0;
          }
          block = mapGetBlockByIdx((int)cVar5);
          if ((block != (MapBlock *)0x0) && ((block->flags & 8) != 0)) {
            if (state->field3_0xc != (void *)0x0) {
              if (state->field3_0xc != (void *)(int)state->field20_0x27) {
                state->field22_0x29 = '\x02';
                state->field20_0x27 = (char)state->field3_0xc;
              }
              if (state->field22_0x29 != '\0') {
                state->field22_0x29 = state->field22_0x29 + -1;
                if ((int)((uint)*(byte *)&def[1].pos.x * 100) < (int)state->field3_0xc) {
                  state->field3_0xc = (void *)((uint)*(byte *)&def[1].pos.x * 100);
                  if ((state->field2_0x8 != (void *)0x0) &&
                     (*(int *)((int)state->field2_0x8 + 0xb8) != 0)) {
                    (**(code **)(**(int **)((int)state->field2_0x8 + 0x68) + 0x24))
                              (state->field2_0x8,0);
                  }
                  mainSetBits((int)(short)def[1].objType,1);
                  state->flags2A = state->flags2A | 2;
                  audioTryStartSfx((int *)this,1,
                                   *(ushort *)
                                    ((int)&PTR_DAT_80397c40 +
                                    (uint)*(byte *)((int)&def[1].pos.x + 1) * 2),0x7f,
                                   "groundanim.c",0x104);
                }
                iVar3 = 0;
                for (local_60[0] = 0; local_60[0] < (int)(uint)state->field19_0x26;
                    local_60[0] = local_60[0] + 1) {
                  group = mapBlockGetGroup(block,(int)*(short *)(&state->field_0x18 +
                                                                local_60[0] * 2));
                  for (iPoly = (uint)*(ushort *)&group->firstPolygon;
                      (int)iPoly < (int)(uint)*(ushort *)&group[1].firstPolygon; iPoly = iPoly + 1)
                  {
                    poly = mapBlockGetPolygon(block,iPoly);
                    for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {
                      if (0.0 < *(float *)((int)state->field0_0x0 + iVar3 * 4)) {
                        pos = mapBlockGetVtxPos(block,(uint)*(ushort *)
                                                             (&poly->field_0x0 + iVar6 * 2));
                        vec3s_to_vec3f(pos,&vStack_78);
                        uStack_4c = (int)state->field3_0xc / 100 ^ 0x80000000;
                        local_50 = 0x43300000;
                        uStack_54 = (int)*(short *)((int)state->field1_0x4 + iVar3 * 2) ^ 0x80000000
                        ;
                        local_58 = 0x43300000;
                        vStack_78.y = (float)((double)CONCAT44(0x43300000,uStack_54) -
                                             4503601774854144.0) -
                                      (float)((double)CONCAT44(0x43300000,uStack_4c) -
                                             4503601774854144.0) *
                                      *(float *)((int)state->field0_0x0 + iVar3 * 4);
                        vec3f_to_vec3s(pos,&vStack_78);
                      }
                      iVar3 = iVar3 + 1;
                    }
                  }
                }
                DCStoreRangeNoSync(block->vertexPositions,(uint)block->numPositions * 6);
              }
            }
            if (((state->flags2A & 2) == 0) &&
               (tricky = Object_getSidekicksLoaded(), tricky != (ObjInstance *)0x0)) {
              dist = (double)objDistSqObj2Obj(this,player);
              local_7c = (float)dist;
              uStack_54 = (uint)*(byte *)((int)&def[1].pos.x + 3) *
                          (uint)*(byte *)((int)&def[1].pos.x + 3) ^ 0x80000000;
              local_58 = 0x43300000;
              if (local_7c <= (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0))
              {
                (*tricky->dll->ptrs2[1].hitDetect)(tricky);
              }
            }
          }
        }
      }
    }
  }
  else {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
    mainSetBits(0x931,1);
  }
  return;
}


/* @description Override hit detection */

void groundAnimator_hitDetect(ObjInstance *this) { //801F86FC
  return;
}


/* @description Override render */

void groundAnimator_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801F8700
  return;
}


/* Library Function - Single Match
    groundAnimator_func07
   
   Library: KioskDefault 0 0 */

void groundAnimator_free(ObjInstance *this,int param2) { //801F8704
  if (*(void **)this->state != (void *)0x0) {
    mm_free(*(void **)this->state);
  }
  Object_removePlayerObj(this,0x33);
                    /* {@symbol 800e29b8} */
  (**(code **)(*(int *)pDll_projgfx + 0x14))(this);
  return;
}


undefined4 groundAnimator_func08(ObjInstance *this) { //801F8768
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int groundAnimator_getExtraSize(void) { //801F8770
  return 0x2c;
}


/* Library Function - Single Match
    groundAnimator_func0A
   
   Library: KioskDefault 0 0 */

void groundAnimator_setScale(ObjInstance *this,float scale) { //801F89E4
  float fVar1;
  float fVar2;
  int in_r4;
  undefined *puVar3;
  
  _savefpr_27();
  puVar3 = this->state;
  fVar1 = *(float *)(in_r4 + 0x10) - (this->pos).pos.y;
  if (((-20.0 <= fVar1) && (fVar1 <= 20.0)) &&
     (fVar1 = *(float *)(in_r4 + 0xc) - (this->pos).pos.x,
     fVar2 = *(float *)(in_r4 + 0x14) - (this->pos).pos.z,
     fVar1 * fVar1 + fVar2 * fVar2 <=
     (*(float *)(puVar3 + 0x10) + 10.0) * (*(float *)(puVar3 + 0x10) + 10.0))) {
    if ((*(int *)(puVar3 + 0xc) == 0) && (*(int *)(puVar3 + 8) != 0)) {
      (**(code **)(**(int **)(*(int *)(puVar3 + 8) + 0x68) + 0x24))(*(undefined4 *)(puVar3 + 8),0);
    }
    *(int *)(puVar3 + 0xc) = *(int *)(puVar3 + 0xc) + 5;
  }
  _restfpr_27();
  return;
}


/* Library Function - Single Match
    groundAnimator_func0B
   
   Library: KioskDefault 0 0 */

uint groundAnimator_func0B(int param1) { //801F8B28
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param1 + 0xb8) + 0xc);
  return ((int)uVar1 >> 0x1f) +
         (uint)((uint)*(byte *)(*(int *)(param1 + 0x4c) + 0x20) * 100 <= uVar1) & 0xff;
}


void groundAnimator_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //801F8B64
  return;
}

