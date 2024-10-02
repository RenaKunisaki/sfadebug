
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void crawler253_initialise(undefined4 param) { //80288FC8
  return;
}


/* @description Called when DLL is unloaded */

void crawler253_release(void) { //80288FCC
  return;
}


/* Library Function - Single Match
    dll_253_func03
   
   Library: KioskDefault 0 0 */

void WM_WallCrawler_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //80288FD0
  short sVar1;
  int iVar2;
  bool bVar3;
  uint *puVar4;
  
  puVar4 = (uint *)this->state;
  Object_objAddObjectType(this,4);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  objAllocMsgQueue(this,2);
  puVar4[0x9a] = (uint)(objDef->pos).x;
  puVar4[0x9b] = (uint)(objDef->pos).y;
  puVar4[0x9c] = (uint)(objDef->pos).z;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  puVar4[0x98] = (uint)(float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                              4503601774854144.0);
  *(undefined *)(puVar4 + 0xa4) = *(undefined *)((int)&objDef[1].objType + 1);
  *(undefined2 *)(puVar4 + 0xa3) =
       *(undefined2 *)((int)&PTR_DAT_8031e0a8 + (uint)*(byte *)(puVar4 + 0xa4) * 2);
  *(undefined2 *)((int)puVar4 + 0x282) = 0;
  *(undefined2 *)(puVar4 + 0xa1) = 0;
  if ((*(ushort *)(puVar4 + 0xa3) & 1) == 0) {
    if ((*(ushort *)(puVar4 + 0xa3) & 8) == 0) {
      *(undefined2 *)(puVar4 + 0xa0) = 400;
      (this->pos).rotation.z = -0x7fff;
      *(undefined *)((int)puVar4 + 0x28e) = 0;
    }
    else {
      *(undefined2 *)(puVar4 + 0xa0) = 0;
      *(undefined2 *)((int)puVar4 + 0x282) = 0x4b0;
      puVar4[0x98] = (uint)100.0;
      (this->pos).rotation.z = 0;
      *(undefined *)((int)puVar4 + 0x28e) = 1;
    }
  }
  else {
    *(undefined2 *)(puVar4 + 0xa0) = 0;
    (this->pos).rotation.z = 0;
    *(undefined *)((int)puVar4 + 0x28e) = 1;
  }
  if ((*(ushort *)(puVar4 + 0xa3) & 0x40) != 0) {
    this->newOpacity = 0;
  }
  puVar4[0x9f] = (uint)0.0;
  *(undefined2 *)((int)puVar4 + 0x286) = *(undefined2 *)&objDef[1].loadFlags;
  (this->pos).pos.y =
       (objDef->pos).y +
       (float)((double)CONCAT44(0x43300000,(int)*(short *)((int)puVar4 + 0x286) ^ 0x80000000) -
              4503601774854144.0);
  iVar2 = randInt(0,0x50);
  *(short *)(puVar4 + 0xa2) = (short)iVar2 + 400;
  puVar4[0x99] = (uint)80.0;
  *(undefined2 *)((int)puVar4 + 0x28a) = *(undefined2 *)&objDef[1].bound;
  bVar3 = checkSomeDebugFlags_8017c4f8();
  if ((!bVar3) && ((*(ushort *)(puVar4 + 0xa3) & 2) != 0)) {
    *(undefined *)((int)puVar4 + 599) = 1;
                    /* {@symbol 8012ab10} */
    (**(code **)(*(int *)pDll1A + 4))(puVar4,0,0,1);
                    /* {@symbol 8012ab74} */
    (**(code **)(*(int *)pDll1A + 8))(puVar4,1,&DAT_8031e0b8,&DAT_80398004,4);
    *puVar4 = *puVar4 | 0x40008;
  }
  this->fptr_0xbc = FUN_8028a3ec;
  FUN_80088d3c((int)this);
  objHitUpdatePos(this);
  return;
}


/* Library Function - Single Match
    dll_253_func04
   
   Library: KioskDefault 0 0 */

void crawler253_update(ObjInstance *this) { //80289224
  word wVar1;
  float fVar2;
  ObjInstance *param1;
  int iVar3;
  uint uVar4;
  ObjInstance *param2;
  char cVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  float local_6c;
  int local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  uint uStack_54;
  
  _savefpr_27();
  puVar9 = this->state;
  iVar7 = 0;
  dVar12 = 1.0;
  dVar11 = 1000.0;
  uVar6 = 0;
  local_68 = 0;
  local_6c = 10000.0;
  if ((*(ushort *)(puVar9 + 0x28c) & 0x10) == 0) {
    param1 = Object_objGetMain();
  }
  else {
    param1 = getSeqObj(0xb,this,&local_6c);
  }
  if (param1 != (ObjInstance *)0x0) {
    uStack_54 = mainGetBit(0x789);
    local_58 = 0x43300000;
    dVar10 = 0.1000000014901161;
    FLOAT_80398000 =
         (float)((double)CONCAT44(0x43300000,uStack_54) - 4503599627370496.0) * 0.1 + 0.1;
    if (puVar9[0x28e] == '\x06') {
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      if (this->animId != 1) {
        Object_ObjAnimSetMove(0.0,this,1,0);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0xcc,0x7f,"crawler.c",(int *)0xe7);
      }
      if (0.4 < this->animTimer) {
        (this->pos).scale = (this->pos).scale * 0.95;
      }
      uStack_54 = (uint)framesThisStep;
      local_58 = 0x43300000;
      iVar7 = objRunAnimation(0.009999999776482582,
                              (double)(float)((double)CONCAT44(0x43300000,uStack_54) -
                                             4503599627370496.0),(int)this,(float *)0x0);
      if (iVar7 != 0) {
        if ((*(short *)(puVar9 + 0x28a) != 0) && (*(short *)(puVar9 + 0x28a) != -1)) {
          uVar6 = mainGetBit((int)*(short *)(puVar9 + 0x28a));
          mainSetBits((int)*(short *)(puVar9 + 0x28a),uVar6 + 1);
        }
        FUN_8028a410(this);
      }
    }
    else {
      if ((*(ushort *)(puVar9 + 0x28c) & 8) != 0) {
        if (*(short *)(puVar9 + 0x282) == 0) {
          if (*(short *)(puVar9 + 0x284) != 0) {
            this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
            *(ushort *)(puVar9 + 0x284) = *(short *)(puVar9 + 0x284) - (ushort)framesThisStep;
            if (*(short *)(puVar9 + 0x284) < 1) {
              *(undefined2 *)(puVar9 + 0x284) = 0;
              FUN_8028a410(this);
            }
            goto LAB_8028a13c;
          }
        }
        else {
          *(ushort *)(puVar9 + 0x282) = *(short *)(puVar9 + 0x282) - (ushort)framesThisStep;
          if (*(short *)(puVar9 + 0x282) < 1) {
            *(undefined2 *)(puVar9 + 0x282) = 0;
            for (iVar7 = 0; iVar7 < 0x1e; iVar7 = iVar7 + 1) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x1a3,0,0,0xffffffff,0);
            }
            *(undefined2 *)(puVar9 + 0x284) = 100;
            goto LAB_8028a13c;
          }
        }
      }
      iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
      if (iVar3 == 0) {
        for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
          uVar4 = mainGetBit(iVar3 + 0x2aa);
          uVar6 = uVar6 + uVar4;
        }
        if ((uVar6 & 0xff) < 6) {
          FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
          if (*(short *)(puVar9 + 0x280) == 0) {
            if ((((puVar9[0x28e] == '\x03') || (puVar9[0x28e] == '\x01')) ||
                (puVar9[0x28e] == '\x05')) && ((*(ushort *)(puVar9 + 0x28c) & 0x80) == 0)) {
              if (puVar9[0x28e] == '\x05') {
                if ((dVar11 < 0.0) ||
                   (dVar10 = 30.0, (double)(*(float *)(puVar9 + 0x264) + 30.0) < dVar11)) {
                  puVar9[0x28e] = 3;
                  *(undefined2 *)(puVar9 + 0x280) = 0x14;
                }
              }
              else if ((0.0 <= dVar11) && (dVar11 < (double)*(float *)(puVar9 + 0x264))) {
                iVar3 = randInt(0,0x32);
                if (iVar3 == 0) {
                  dVar10 = 127.0;
                  audioTryStartSfx((int *)this,0x10,0xce,0x7f,"crawler.c",0x13e);
                }
                if (*(short *)(puVar9 + 0x288) < 1) {
                  if ((*(ushort *)(puVar9 + 0x28c) & 0x100) == 0) {
                    FUN_8028a410(this);
                  }
                  else {
                    puVar9[0x28e] = 6;
                  }
                  goto LAB_8028a13c;
                }
                if (puVar9[0x28e] != '\x05') {
                  FUN_80068a9c((uint)this,0x10);
                  puVar9[0x28e] = 5;
                  (this->vel).x = -(this->vel).x * 0.25;
                  dVar10 = -(double)(this->vel).z;
                  (this->vel).z = (float)(dVar10 * 0.25);
                }
              }
            }
            if (((((*(ushort *)(puVar9 + 0x28c) & 0x200) != 0) && (puVar9[0x28e] != '\x05')) &&
                (param2 = Object_getSidekicksLoaded(), param2 != (ObjInstance *)0x0)) &&
               ((objDistObj2Obj(this,param2), dVar10 < 30.0 &&
                (cVar5 = (*param2->dll->ptrs2[2].update)(param2), cVar5 != '\0')))) {
              puVar9[0x28e] = 5;
              audioTryStartSfx((int *)this,0x10,0xce,0x7f,"crawler.c",0x159);
            }
            if (puVar9[0x28e] == '\x05') {
              if ((*(ushort *)(puVar9 + 0x28c) & 2) != 0) {
                    /* {@symbol 8012ac30} */
                (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,puVar9);
                    /* {@symbol 8012b0e4} */
                (**(code **)(*(int *)pDll1A + 0x14))(this,puVar9);
                    /* {@symbol 8012b170} */
                (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,puVar9);
              }
              dVar11 = (double)((this->vel).x * (this->vel).x + (this->vel).z * (this->vel).z);
              if (dVar11 != 0.0) {
                dVar12 = sqrt(dVar11);
              }
              *(float *)(puVar9 + 0x27c) = (float)(dVar12 * -0.06499999761581421);
              uStack_54 = (uint)framesThisStep;
              local_58 = 0x43300000;
              objRunAnimation((double)*(float *)(puVar9 + 0x27c),
                              (double)(float)((double)CONCAT44(0x43300000,uStack_54) -
                                             4503599627370496.0),(int)this,(float *)0x0);
              (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
              (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
              *(ushort *)(puVar9 + 0x288) = *(short *)(puVar9 + 0x288) - (ushort)framesThisStep;
              if ((*(ushort *)(puVar9 + 0x28c) & 4) == 0) {
                (this->pos).pos.y = *(float *)(puVar9 + 0x26c);
              }
              else {
                local_6c = 10000.0;
                iVar3 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                                     (double)(this->pos).pos.z,(int)this,&local_68,0,0);
                for (iVar8 = 0; iVar8 < iVar3; iVar8 = iVar8 + 1) {
                  fVar2 = **(float **)(local_68 + iVar8 * 4) - (this->pos).pos.y;
                  if (fVar2 < 0.0) {
                    fVar2 = fVar2 * -1.0;
                  }
                  if (fVar2 < local_6c) {
                    iVar7 = iVar8;
                    local_6c = fVar2;
                  }
                }
                if (local_68 == 0) {
                  (this->pos).pos.y = *(float *)(puVar9 + 0x26c);
                }
                else {
                  (this->pos).pos.y = **(float **)(local_68 + iVar7 * 4);
                  FUN_8028a334((short *)this,*(int *)(local_68 + iVar7 * 4));
                }
              }
              if (((*(ushort *)(puVar9 + 0x28c) & 0x80) == 0) && (*(short *)(puVar9 + 0x288) < 1)) {
                if ((*(ushort *)(puVar9 + 0x28c) & 0x100) == 0) {
                  puVar9[0x28e] = 0;
                  FUN_80068a9c((uint)this,0x18);
                  (this->pos).pos.x = *(float *)(puVar9 + 0x268);
                  uStack_54 = (int)*(short *)(puVar9 + 0x286) ^ 0x80000000;
                  local_58 = 0x43300000;
                  (this->pos).pos.y =
                       *(float *)(puVar9 + 0x26c) +
                       (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
                  (this->pos).pos.z = *(float *)(puVar9 + 0x270);
                }
                else {
                  puVar9[0x28e] = 6;
                }
              }
              else if (((*(ushort *)(puVar9 + 0x28c) & 0x200) != 0) &&
                      (iVar7 = randInt(0,0x14), iVar7 == 0)) {
                puVar9[0x28e] = 3;
                iVar7 = randInt(0,0x14);
                *(short *)(puVar9 + 0x280) = (short)iVar7 + 0x32;
              }
            }
            else {
              dVar11 = (double)objDistObj2ObjXZ(param1,this);
              if ((dVar11 < (double)*(float *)(puVar9 + 0x260)) ||
                 (uVar6 = mainGetBit(0x1d9), uVar6 != 0)) {
                if (puVar9[0x28e] == '\0') {
                  puVar9[0x28e] = 1;
                  *(undefined2 *)(puVar9 + 0x280) = 1;
                  (this->pos).rotation.z = 0;
                }
                else if (puVar9[0x28e] == '\x01') {
                  if (-10.0 < (this->vel).y) {
                    (this->vel).y = timeDelta * -0.1 + (this->vel).y;
                  }
                  if ((this->pos).pos.y < *(float *)(puVar9 + 0x26c)) {
                    (this->pos).pos.y = *(float *)(puVar9 + 0x26c);
                    (this->vel).y = 0.0;
                    puVar9[0x28e] = 3;
                    iVar7 = randInt(0,0x14);
                    *(short *)(puVar9 + 0x280) = (short)iVar7 + 0x32;
                    *(float *)(puVar9 + 0x260) = *(float *)(puVar9 + 0x260) * 2.0;
                    Object_ObjAnimSetMove(0.0,this,0,0);
                  }
                }
                else if (puVar9[0x28e] == '\x03') {
                  audioTryStartSfx((int *)this,8,0x12a,0x39,"crawler.c",0x1b3);
                  if ((*(ushort *)(puVar9 + 0x28c) & 2) != 0) {
                    /* {@symbol 8012ac30} */
                    (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,puVar9);
                    /* {@symbol 8012b0e4} */
                    (**(code **)(*(int *)pDll1A + 0x14))(this,puVar9);
                    /* {@symbol 8012b170} */
                    (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,puVar9);
                  }
                  if ((*(ushort *)(puVar9 + 0x28c) & 4) == 0) {
                    (this->pos).pos.y = *(float *)(puVar9 + 0x26c);
                  }
                  else {
                    local_6c = 10000.0;
                    iVar3 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                                         (double)(this->pos).pos.z,(int)this,&local_68,0,0);
                    for (iVar8 = 0; iVar8 < iVar3; iVar8 = iVar8 + 1) {
                      fVar2 = **(float **)(local_68 + iVar8 * 4) - (this->pos).pos.y;
                      if (fVar2 < 0.0) {
                        fVar2 = fVar2 * -1.0;
                      }
                      if (fVar2 < local_6c) {
                        iVar7 = iVar8;
                        local_6c = fVar2;
                      }
                    }
                    if (local_68 == 0) {
                      (this->pos).pos.y = *(float *)(puVar9 + 0x26c);
                    }
                    else {
                      (this->pos).pos.y = **(float **)(local_68 + iVar7 * 4);
                      FUN_8028a334((short *)this,*(int *)(local_68 + iVar7 * 4));
                    }
                  }
                  local_64 = (param1->pos).pos.x - (this->pos).pos.x;
                  local_60 = (param1->pos).pos.y - (this->pos).pos.y;
                  local_5c = (param1->pos).pos.z - (this->pos).pos.z;
                  (this->vel).x = (local_64 / 300.0) * timeDelta;
                  (this->vel).y = (local_60 / 300.0) * timeDelta;
                  (this->vel).z = (local_5c / 300.0) * timeDelta;
                  if (((*(ushort *)(puVar9 + 0x28c) & 0x20) != 0) &&
                     (dVar10 = sqrt((double)((this->vel).z * (this->vel).z +
                                            (this->vel).x * (this->vel).x +
                                            (this->vel).y * (this->vel).y)),
                     (double)FLOAT_80398000 < dVar10)) {
                    vec3f_normalize_8002282c(&(this->vel).x);
                    (this->vel).x = (this->vel).x * timeDelta * FLOAT_80398000;
                    (this->vel).y = (this->vel).y * timeDelta * FLOAT_80398000;
                    (this->vel).z = (this->vel).z * timeDelta * FLOAT_80398000;
                  }
                  if (((this->animId == 0) && ((*(ushort *)(puVar9 + 0x28c) & 0x400) != 0)) &&
                     (dVar11 < 15.0)) {
                    Object_ObjAnimSetMove(0.0,this,2,0);
                  }
                  if ((dVar11 < 13.0) ||
                     ((((*(ushort *)(puVar9 + 0x28c) & 0x10) != 0 &&
                       ((this->hitstate->flags & 8) != 0)) && (dVar11 < 50.0)))) {
                    DAT_8039a098 = DAT_8039a098 + 1;
                    if (((this->animId == 2) && (0.3 < this->animTimer)) && (this->animTimer < 0.7))
                    {
                      objSendMsg((int)param1,0x60004,(uint)this,1);
                      DAT_8039a098 = 0;
                    }
                    uVar6 = mainGetBit(0x1d9);
                    if (uVar6 == 0) {
                      if ((2 < DAT_8039a098) ||
                         (((*(ushort *)(puVar9 + 0x28c) & 0x10) != 0 && (2 < DAT_8039a098)))) {
                        audioTryStartSfx((int *)this,0x20,200,0x7f,"crawler.c",0x1f2);
                        if ((*(ushort *)(puVar9 + 0x28c) & 0x10) == 0) {
                          objSendMsg((int)param1,0x60004,(uint)this,1);
                        }
                        else {
                          puVar9[0x291] = puVar9[0x291] & 0x7f | 0x80;
                        }
                        DAT_8039a098 = 0;
                      }
                    }
                    else {
                      DAT_8039a098 = 0;
                    }
                    if ((*(ushort *)(puVar9 + 0x28c) & 0x10) == 0) {
                      (this->pos).pos.x = -(this->vel).x * 26.0 + (this->pos).pos.x;
                      (this->pos).pos.z = -(this->vel).z * 26.0 + (this->pos).pos.z;
                    }
                    else {
                      (this->pos).pos.x = -(this->vel).x * 8.0 + (this->pos).pos.x;
                      (this->pos).pos.z = -(this->vel).z * 8.0 + (this->pos).pos.z;
                    }
                    iVar7 = randInt(0,0x14);
                    *(short *)(puVar9 + 0x280) = (short)iVar7 + 100;
                  }
                  iVar7 = getAngle();
                  (this->pos).rotation.x = (short)iVar7 + 0x7fff;
                  dVar11 = (double)((this->vel).x * (this->vel).x + (this->vel).z * (this->vel).z);
                  if (dVar11 != 0.0) {
                    dVar12 = sqrt(dVar11);
                  }
                  wVar1 = this->animId;
                  if (wVar1 == 1) {
                    *(float *)(puVar9 + 0x27c) = 0.01;
                  }
                  else if ((short)wVar1 < 1) {
                    if (-1 < (short)wVar1) {
                      *(float *)(puVar9 + 0x27c) = (float)(dVar12 * 0.06499999761581421);
                    }
                  }
                  else if ((short)wVar1 < 3) {
                    *(float *)(puVar9 + 0x27c) = 0.03;
                  }
                  uStack_54 = (uint)framesThisStep;
                  local_58 = 0x43300000;
                  iVar7 = objRunAnimation((double)*(float *)(puVar9 + 0x27c),
                                          (double)(float)((double)CONCAT44(0x43300000,uStack_54) -
                                                         4503599627370496.0),(int)this,(float *)0x0)
                  ;
                  if ((iVar7 != 0) && (this->animId != 0)) {
                    Object_ObjAnimSetMove(0.0,this,0,0);
                  }
                  (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
                  (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
                }
              }
              else if (puVar9[0x28e] == '\x01') {
                if (-1.0 < (this->vel).y) {
                  (this->vel).y = timeDelta * -0.01 + (this->vel).y;
                }
                if ((this->pos).pos.y < *(float *)(puVar9 + 0x26c)) {
                  (this->pos).pos.y = *(float *)(puVar9 + 0x26c);
                  (this->vel).y = 0.0;
                  puVar9[0x28e] = 3;
                  iVar7 = randInt(0,0x14);
                  *(short *)(puVar9 + 0x280) = (short)iVar7 + 0x32;
                  *(float *)(puVar9 + 0x260) = *(float *)(puVar9 + 0x260) * 2.0;
                  Object_ObjAnimSetMove(0.0,this,0,0);
                }
                (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
              }
              if (puVar9[0x28e] == '\x01') {
                (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
              }
              iVar7 = randInt(0,0x32);
              if (iVar7 == 0) {
                iVar7 = randInt(0,2);
                audioTryStartSfx((int *)this,0x10,*(ushort *)((int)&PTR_DAT_80397ff8 + iVar7 * 2),
                                 0x7f,"crawler.c",0x237);
              }
            }
          }
          else {
            *(ushort *)(puVar9 + 0x280) = *(short *)(puVar9 + 0x280) - (ushort)framesThisStep;
            if (*(short *)(puVar9 + 0x280) < 0) {
              *(undefined2 *)(puVar9 + 0x280) = 0;
            }
          }
        }
        else {
          FUN_8028a410(this);
        }
      }
      else if ((*(ushort *)(puVar9 + 0x28c) & 0x100) == 0) {
        FUN_8028a410(this);
      }
      else {
        puVar9[0x28e] = 6;
      }
    }
  }
LAB_8028a13c:
  _restfpr_27();
  return;
}


/* Library Function - Single Match
    dll_253_func05
   
   Library: KioskDefault 0 0 */

void crawler253_hitDetect(ObjInstance *this) { //8028A158
  ObjInstance *pOVar1;
  undefined *puVar2;
  float local_14 [2];
  
  puVar2 = this->state;
  local_14[0] = 100000.0;
  if ((char)puVar2[0x291] < '\0') {
    if ((*(ushort *)(puVar2 + 0x28c) & 0x10) == 0) {
      pOVar1 = Object_objGetMain();
    }
    else {
      pOVar1 = getSeqObj(0xb,this,local_14);
    }
    FUN_80088818((int)pOVar1,(int)this,'\v',1,0);
    puVar2[0x28e] = 6;
    puVar2[0x291] = puVar2[0x291] & 0x7f;
  }
  return;
}


/* Library Function - Single Match
    dll_253_func06
   
   Library: KioskDefault 0 0 */

void crawler253_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8028A1F0
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if ((*(ushort *)(puVar1 + 0x28c) & 0x40) != 0) {
    if (this->newOpacity != 0xff) {
      if ((int)(0xff - (uint)framesThisStep) < (int)(uint)this->newOpacity) {
        this->newOpacity = 0xff;
        *(ushort *)(puVar1 + 0x28c) = *(ushort *)(puVar1 + 0x28c) & 0xffbf;
      }
      else {
        this->newOpacity = this->newOpacity + framesThisStep;
      }
    }
  }
  if ((shouldRender) && (*(short *)(puVar1 + 0x284) == 0)) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((this != (ObjInstance *)0x0) && (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)*(float *)(puVar1 + 0x260),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_22B_func07
    dll_253_func07
    dll_294_func07
    dll_2D3_func07
   
   Library: KioskDefault 0 0 */

void crawler253_free(ObjInstance *this,int param2) { //8028A2F8
  Object_removePlayerObj(this,4);
  return;
}


undefined4 crawler253_func08(ObjInstance *this) { //8028A324
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int crawler253_getExtraSize(void) { //8028A32C
  return 0x294;
}

