
/* Library Function - Single Match
    ObjAnimSetMove
   
   Library: KioskDefault 0 0 */

undefined4 Object_ObjAnimSetMove(double animTimer,ObjInstance *this,uint animId,byte flags) { //800860E0
  byte bVar1;
  word wVar2;
  undefined *puVar3;
  ModelInstance *minst;
  float fVar4;
  Model *model;
  int iVar5;
  AnimInstance *animBuf;
  
  if (animTimer <= 1.0) {
    if (animTimer < 0.0) {
      animTimer = 0.0;
    }
  }
  else {
    animTimer = 1.0;
  }
  this->animTimer = (float)animTimer;
  minst = (ModelInstance *)this->modelInstances->mtxs[(char)this->curModel + -3];
  if (minst == (ModelInstance *)0x0) {
    printf("Error in loading Model Inst in ObjAnimSetMove ");
  }
  else {
    model = minst->model;
    if (model->animBufSize != 0) {
      animBuf = minst->animInstances[0];
      animBuf->field43_0x63 = flags;
      animBuf->field21_0x46 = animBuf->field20_0x44;
      animBuf->field2_0x8 = animBuf->hitboxSize;
      animBuf->mtxSize = (uint)animBuf->field5_0x14;
      animBuf->field4_0x10 = animBuf->field3_0xc;
      animBuf->z = animBuf->y;
      animBuf->field41_0x61 = animBuf->field40_0x60;
      animBuf->field23_0x4a = animBuf->field22_0x48;
      animBuf->field19_0x40 = animBuf->field18_0x3c;
      animBuf->field38_0x5c = animBuf->field37_0x5a;
      animBuf->field37_0x5a = 0;
      animBuf->field44_0x64 = 0xffff;
      if ((this->hitstate != (HitState *)0x0) && (this->hitstate->objHits != (ObjHitsEntry *)0x0)) {
        objLoadHits(this,minst,(int)(short)this->romdefno,this->hitstate,animId,FALSE);
      }
      if (this->pEventName != (ObjEventData *)0x0) {
        objLoadEventData(this,(int)(short)this->romdefno,this->pEventName,animId,false);
      }
      wVar2 = this->animId;
      this->animId = (word)animId;
      iVar5 = (int)*(short *)((int)&model->field29_0x58 + ((int)animId >> 8) * 2) + (animId & 0xff);
      if ((int)(uint)model->animBufSize <= iVar5) {
        iVar5 = model->animBufSize - 1;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if ((model->flags & UseLocalModAnimTab) == 0) {
        animBuf->field20_0x44 = (ushort)iVar5;
        fVar4 = (&model->field26_0x4c->radius)[animBuf->field20_0x44];
        if (fVar4 == 0.0) {
                    
          OSPanic("objanim.c",0x88,"Failed assertion anim");
        }
      }
      else {
        if (animId != (int)(short)wVar2) {
          animBuf->field42_0x62 = '\x01' - animBuf->field42_0x62;
          animBuf->field20_0x44 = (short)animBuf->field42_0x62;
          if (*(short *)((int)&model->animIds->radius + iVar5 * 2) == -1) {
            OSReport(s_<objanim_c____setBlendMove>_WARN_802ed2bc,(uint)(ushort)model->cacheModNo);
            iVar5 = 0;
          }
          FUN_8007d174(*(short *)((int)&model->animIds->radius + iVar5 * 2),(short)iVar5,
                       (&animBuf->field7_0x1c)[animBuf->field20_0x44],model);
        }
        fVar4 = (float)((int)(&animBuf->field7_0x1c)[animBuf->field20_0x44] + 0x80);
        if (fVar4 == 0.0) {
                    
          OSPanic("objanim.c",0x83,"Failed assertion anim");
        }
      }
      animBuf->y = (int)fVar4 + 6;
      animBuf->field40_0x60 = *(byte *)((int)fVar4 + 1) & 0xf0;
      animBuf->field5_0x14 =
           (float)((double)CONCAT44(0x43300000,(uint)*(byte *)(animBuf->y + 1)) - 4503599627370496.0
                  );
      if (animBuf->field40_0x60 == 0) {
        animBuf->field5_0x14 = animBuf->field5_0x14 - 1.0;
      }
      bVar1 = *(byte *)((int)fVar4 + 1);
      if (((bVar1 & 0xf) == 0) || ((flags & 0x10) != 0)) {
        animBuf->field36_0x58 = 0;
      }
      else {
        animBuf->field4_0x10 = animBuf->field3_0xc;
        animBuf->field39_0x5e =
             (short)(int)(16384.0 /
                         (float)((double)CONCAT44(0x43300000,bVar1 & 0xf ^ 0x80000000) -
                                4503601774854144.0));
        animBuf->field36_0x58 = 0x4000;
      }
      animBuf->field3_0xc = 0.0;
      animBuf->hitboxSize = (float)(animTimer * (double)animBuf->field5_0x14);
      if ((this->child[0] != (ObjInstance *)0x0) && (this->child[0]->objId == 0x2f)) {
        puVar3 = this->child[0]->state;
        puVar3[0x80] = puVar3[0x80] & 0xfe;
      }
    }
  }
  return 0;
}


/* Library Function - Single Match
    objSetBlendMove
   
   Library: KioskDefault 0 0 */

undefined4 objSetBlendMove(double param1,int param2,uint param3,undefined param4) { //80087404
  byte bVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param1 <= 1.0) {
    if (param1 < 0.0) {
      param1 = 0.0;
    }
  }
  else {
    param1 = 1.0;
  }
  *(float *)(param2 + 0x9c) = (float)param1;
  piVar3 = *(int **)(*(int *)(param2 + 0x7c) + *(char *)(param2 + 0xad) * 4);
  iVar4 = *piVar3;
  if (*(short *)(iVar4 + 0xb0) != 0) {
    iVar6 = piVar3[10];
    *(undefined *)(iVar6 + 99) = param4;
    *(undefined2 *)(iVar6 + 0x46) = *(undefined2 *)(iVar6 + 0x44);
    *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar6 + 0x14);
    *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
    *(undefined4 *)(iVar6 + 0x38) = *(undefined4 *)(iVar6 + 0x34);
    *(undefined *)(iVar6 + 0x61) = *(undefined *)(iVar6 + 0x60);
    *(undefined2 *)(iVar6 + 0x4a) = *(undefined2 *)(iVar6 + 0x48);
    *(undefined4 *)(iVar6 + 0x40) = *(undefined4 *)(iVar6 + 0x3c);
    *(undefined2 *)(iVar6 + 0x5c) = *(undefined2 *)(iVar6 + 0x5a);
    *(undefined2 *)(iVar6 + 0x5a) = 0;
    *(undefined2 *)(iVar6 + 100) = 0xffff;
    sVar2 = *(short *)(param2 + 0xa2);
    *(short *)(param2 + 0xa2) = (short)param3;
    iVar5 = (int)*(short *)(iVar4 + ((int)param3 >> 8) * 2 + 0x58) + (param3 & 0xff);
    if ((int)(uint)*(ushort *)(iVar4 + 0xb0) <= iVar5) {
      iVar5 = *(ushort *)(iVar4 + 0xb0) - 1;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if ((*(ushort *)(iVar4 + 2) & 0x40) == 0) {
      *(short *)(iVar6 + 0x44) = (short)iVar5;
      iVar4 = *(int *)(*(int *)(iVar4 + 0x4c) + (uint)*(ushort *)(iVar6 + 0x44) * 4);
    }
    else {
      if (param3 != (int)sVar2) {
        *(char *)(iVar6 + 0x62) = '\x01' - *(char *)(iVar6 + 0x62);
        *(short *)(iVar6 + 0x44) = (short)*(char *)(iVar6 + 0x62);
        if (*(short *)(*(int *)(iVar4 + 0x54) + iVar5 * 2) == -1) {
          OSReport(s_<objanim_c____setBlendMove>_WARN_802ed2bc,(uint)*(ushort *)(iVar4 + 4));
          iVar5 = 0;
        }
        FUN_8007d174(*(short *)(*(int *)(iVar4 + 0x54) + iVar5 * 2),(short)iVar5,
                     *(undefined4 *)(iVar6 + (uint)*(ushort *)(iVar6 + 0x44) * 4 + 0x1c),iVar4);
      }
      iVar4 = *(int *)(iVar6 + (uint)*(ushort *)(iVar6 + 0x44) * 4 + 0x1c) + 0x80;
    }
    *(int *)(iVar6 + 0x34) = iVar4 + 6;
    *(byte *)(iVar6 + 0x60) = *(byte *)(iVar4 + 1) & 0xf0;
    *(float *)(iVar6 + 0x14) =
         (float)((double)CONCAT44(0x43300000,(uint)*(byte *)(*(int *)(iVar6 + 0x34) + 1)) -
                4503599627370496.0);
    if (*(char *)(iVar6 + 0x60) == '\0') {
      *(float *)(iVar6 + 0x14) = *(float *)(iVar6 + 0x14) - 1.0;
    }
    bVar1 = *(byte *)(iVar4 + 1);
    if ((bVar1 & 0xf) != 0) {
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
      *(short *)(iVar6 + 0x5e) =
           (short)(int)(16384.0 /
                       (float)((double)CONCAT44(0x43300000,bVar1 & 0xf ^ 0x80000000) -
                              4503601774854144.0));
      *(undefined2 *)(iVar6 + 0x58) = 0x4000;
    }
    *(float *)(iVar6 + 0xc) = 0.0;
    *(float *)(iVar6 + 4) = (float)(param1 * (double)*(float *)(iVar6 + 0x14));
  }
  return 0;
}


/* Library Function - Single Match
    objSetBlendMove_80087bdc
   
   Library: KioskDefault 0 0 */

void setBlendMove(int param1,int param2,uint param3,undefined2 param4) { //80087BDC
  float fVar1;
  int iVar2;
  
  iVar2 = (int)*(short *)(param1 + ((int)param3 >> 8) * 2 + 0x58) + (param3 & 0xff);
  if ((int)(uint)*(ushort *)(param1 + 0xb0) <= iVar2) {
    iVar2 = *(ushort *)(param1 + 0xb0) - 1;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if ((*(ushort *)(param1 + 2) & 0x40) == 0) {
    *(short *)(param2 + 0x48) = (short)iVar2;
    iVar2 = *(int *)(*(int *)(param1 + 0x4c) + (uint)*(ushort *)(param2 + 0x48) * 4);
  }
  else {
    if (*(short *)(param2 + 100) != iVar2) {
      *(short *)(param2 + 0x48) = (short)*(char *)(param2 + 0x62);
      *(short *)(param2 + 0x4a) = 1 - *(char *)(param2 + 0x62);
      if (*(short *)(*(int *)(param1 + 0x54) + iVar2 * 2) == -1) {
        OSReport(s_<objanim_c____setBlendMove>_WARN_802ed2bc,(uint)*(ushort *)(param1 + 4));
        iVar2 = 0;
      }
      FUN_8007d174(*(short *)(*(int *)(param1 + 0x54) + iVar2 * 2),(short)iVar2,
                   *(undefined4 *)(param2 + (uint)*(ushort *)(param2 + 0x48) * 4 + 0x24),param1);
      *(short *)(param2 + 100) = (short)iVar2;
    }
    iVar2 = *(int *)(param2 + (uint)*(ushort *)(param2 + 0x48) * 4 + 0x24) + 0x80;
  }
  *(int *)(param2 + 0x3c) = iVar2 + 6;
  if ((*(byte *)(iVar2 + 1) & 0xf0) == (int)*(char *)(param2 + 0x60)) {
    fVar1 = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)(*(int *)(param2 + 0x3c) + 1)) -
                   4503599627370496.0);
    if ((*(byte *)(iVar2 + 1) & 0xf0) == 0) {
      fVar1 = fVar1 - 1.0;
    }
    if (fVar1 == *(float *)(param2 + 0x14)) {
      *(undefined2 *)(param2 + 0x5a) = param4;
    }
    else {
      *(undefined2 *)(param2 + 0x5a) = 0;
    }
  }
  else {
    *(undefined2 *)(param2 + 0x5a) = 0;
  }
  return;
}


void objAnimFn_80087d88(ObjInstance *obj,int param2) { //80087D88
  char cVar1;
  word wVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  double dVar9;
  undefined2 local_5c;
  undefined2 local_5a;
  undefined2 local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  byte local_44 [4];
  int local_40;
  undefined4 local_3c;
  float local_38;
  undefined4 local_34;
  int local_30 [3];
  
  local_30[0] = 0;
  wVar2 = obj->objId;
  if (wVar2 == 2) {
    (*(code *)obj->dll->ptrs2->render2C)(obj,&local_40,local_44,local_30);
    puVar3 = (uint *)(*obj->dll->ptrs2[1].onLoad)(obj);
    dVar9 = (double)(*(code *)obj->dll->ptrs2[1].field0_0x0)(obj);
  }
  else {
    if (1 < (short)wVar2) {
      return;
    }
    if ((short)wVar2 < 1) {
      return;
    }
    FUN_801a84c4((int)obj,&local_40,local_44,local_30);
    puVar3 = (uint *)FUN_801a84f4((int)obj);
    dVar9 = FUN_801a84a8((int)obj);
  }
  uVar6 = 0;
  for (uVar7 = 0; (int)(uVar7 & 0xff) < (int)*(char *)(param2 + 0x1b); uVar7 = uVar7 + 1) {
    cVar1 = *(char *)(param2 + (uVar7 & 0xff) + 0x13);
    if (cVar1 == '\x03') {
      uVar6 = uVar6 | 4;
    }
    else if (cVar1 < '\x03') {
      if (cVar1 == '\x01') {
        uVar6 = uVar6 | 1;
      }
      else if ('\0' < cVar1) {
        uVar6 = uVar6 | 2;
      }
    }
    else if (cVar1 < '\x05') {
      uVar6 = uVar6 | 8;
    }
  }
  if ((uVar6 != 0) && (local_30[0] != 0)) {
    local_50 = 0.0;
    local_4c = 0.0;
    local_48 = 0.0;
    local_54 = 1.0;
    local_5c = 0;
    local_58 = 0;
    local_5a = 0;
    if (((puVar3 != (uint *)0x0) && ((*(byte *)(puVar3 + 0x97) & 0x10) != 0)) ||
       ((*puVar3 & 0x400000) == 0)) {
      if (*(byte *)(puVar3 + 0x2e) < 0x21) {
        bVar8 = *(byte *)((int)&PTR_DAT_802ed268 + (uint)*(byte *)(puVar3 + 0x2e));
      }
      else {
        bVar8 = 0;
      }
      if ((float)puVar3[0x6c] != 0.0) {
                    /* {@symbol 800d9dec} */
        (**(code **)(*(int *)pDll_TrickyWalk + 8))(dVar9,obj,uVar6,local_30[0],puVar3);
        bVar8 = 5;
      }
      if (local_40 != 0) {
        if ((uVar6 & 5) != 0) {
          iVar4 = randInt(0,1);
          audioSfxFn_800688bc((double)(obj->pos).pos.x,(double)(obj->pos).pos.y,
                              (double)(obj->pos).pos.z,
                              *(ushort *)(local_40 + ((uint)bVar8 * 4 + iVar4 * 2) * 2),local_44[0],
                              "objanim.c",(int *)0x3a4);
        }
        if ((uVar6 & 10) != 0) {
          iVar4 = randInt(0,1);
          audioSfxFn_800688bc((double)(obj->pos).pos.x,(double)(obj->pos).pos.y,
                              (double)(obj->pos).pos.z,
                              *(ushort *)(local_40 + ((uint)bVar8 * 4 + iVar4 * 2) * 2),local_44[0],
                              "objanim.c",(int *)0x3a8);
        }
      }
      if ((local_30[0] != 0) && (bVar8 != 5)) {
        uVar7 = 0;
        for (; uVar6 != 0; uVar6 = (int)uVar6 >> 1) {
          if ((uVar6 & 1) != 0) {
            local_50 = *(float *)(local_30[0] + (uVar7 & 0xff) * 0xc);
            local_38 = 0.0;
            local_48 = *(float *)(local_30[0] + (uVar7 & 0xff) * 0xc + 8);
            if (obj->objId == 1) {
              local_3c = local_50;
              local_34 = local_48;
              if ((*(char *)(puVar3 + 0x2e) == '\x12') || (*(char *)(puVar3 + 0x2e) == '\x19')) {
                local_4c = 0.0;
                uVar5 = randInt(2,4);
                for (uVar5 = uVar5 & 0xff; (uVar5 & 0xff) != 0; uVar5 = uVar5 - 1) {
                    /* {@symbol 800ed30c} */
                  (**(code **)(*(int *)pDll_objfsa + 8))
                            (obj,0x259,&local_5c,&DAT_00010001,0xffffffff,0);
                }
              }
              else if (*(char *)(puVar3 + 0x2e) == '\x03') {
                local_4c = 0.0;
                local_54 = 0.00045;
                uVar5 = randInt(2,4);
                for (uVar5 = uVar5 & 0xff; (uVar5 & 0xff) != 0; uVar5 = uVar5 - 1) {
                  iVar4 = randInt(0,1);
                    /* {@symbol 800ed30c} */
                  (**(code **)(*(int *)pDll_objfsa + 8))
                            (obj,iVar4 + 0x1f9,&local_5c,&DAT_00010001,0xffffffff,0);
                }
              }
            }
          }
          uVar7 = uVar7 + 1;
        }
      }
    }
  }
  return;
}

