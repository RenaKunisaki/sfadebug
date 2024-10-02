
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRpickup_initialise(undefined4 param) { //802BA504
  return;
}


/* @description Called when DLL is unloaded */

void DRpickup_release(void) { //802BA508
  return;
}


/* Library Function - Single Match
    dll_2B9_func03
   
   Library: KioskDefault 0 0 */

void DRpickup_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802BA50C
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar4 = mainGetBit((int)sVar1);
  puVar5[0x14] = (byte)(uVar4 << 5) & 0x20 | puVar5[0x14] & 0xdf;
  *(short *)(puVar5 + 0x10) = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  *(short *)(puVar5 + 0x12) = (short)((int)sVar2 << 8);
  sVar3._0_1_ = objDef[1].loadFlags;
  sVar3._1_1_ = objDef[1].mapStates2;
  *(float *)(puVar5 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802baca4;
  Object_objAddObjectType(this,0x3a);
  if (obj2 == (ObjInstance *)0x0) {
    (this->pos).pos.y = (this->pos).pos.y + 20.0;
  }
  puVar5[0x14] = puVar5[0x14] & 0xbf | 0x40;
  return;
}


/* Library Function - Single Match
    dll_2B9_func04
   
   Library: KioskDefault 0 0 */

void DRpickup_update(ObjInstance *this) { //802BA5E0
  char cVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ushort param3;
  uint uVar6;
  int iVar7;
  ObjDef *pOVar8;
  int iVar9;
  float *pfVar10;
  double dVar11;
  int local_30 [2];
  longlong local_28;
  
  pfVar10 = (float *)this->state;
  pOVar8 = this->def;
  if ((*(byte *)(pfVar10 + 5) >> 5 & 1) != 0) {
    sVar2._0_1_ = pOVar8[1].bound;
    sVar2._1_1_ = pOVar8[1].cullDist;
    uVar6 = mainGetBit((int)sVar2);
    *(byte *)(pfVar10 + 5) = (byte)(uVar6 << 5) & 0x20 | *(byte *)(pfVar10 + 5) & 0xdf;
  }
  cVar1 = *(char *)((int)&pOVar8[1].objType + 1);
  if (cVar1 == '\x01') {
    fVar3 = (this->pos).pos.x - *pfVar10;
    fVar4 = (this->pos).pos.y - pfVar10[1];
    fVar5 = (this->pos).pos.z - pfVar10[2];
    dVar11 = sqrt((double)(fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4));
    iVar7 = (int)((float)(dVar11 / (double)timeDelta) * 30.0);
    local_28 = (longlong)iVar7;
    iVar7 = 0x78 - iVar7;
    if (iVar7 < 1) {
      iVar7 = 1;
    }
    else if (0x78 < iVar7) {
      iVar7 = 0x78;
    }
    iVar7 = randInt(0,iVar7);
    if (iVar7 == 0) {
      iVar7 = randInt(0,1);
      if (iVar7 == 0) {
        param3 = 0x1e6;
      }
      else {
        param3 = 0x1e5;
      }
      audioTryStartSfx((int *)this,1,param3,0x7f,"DRpickup.c",0xa3);
    }
  }
  else if (((cVar1 < '\x01') && (-1 < cVar1)) && ((*(byte *)(pfVar10 + 5) >> 6 & 1) != 0)) {
    if ((*(byte *)(pfVar10 + 5) >> 5 & 1) == 0) {
      (this->vel).y = (this->vel).y - 0.3;
      (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
      iVar7 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                           (double)(this->pos).pos.z,(int)this,local_30,0,1);
      for (iVar9 = 0; iVar9 < iVar7; iVar9 = iVar9 + 1) {
        if ((this->pos).pos.y < **(float **)(local_30[0] + iVar9 * 4) + 3.0) {
          if ((this->pos).pos.y - **(float **)(local_30[0] + iVar9 * 4) < 0.0) {
            fVar3 = -((this->pos).pos.y - **(float **)(local_30[0] + iVar9 * 4));
          }
          else {
            fVar3 = (this->pos).pos.y - **(float **)(local_30[0] + iVar9 * 4);
          }
          if (fVar3 < 50.0) {
            if (-1 < *(char *)(pfVar10 + 5)) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x675,0,0,0xffffffff,0);
            }
            *(byte *)(pfVar10 + 5) = *(byte *)(pfVar10 + 5) & 0x7f | 0x80;
            (this->pos).pos.y = **(float **)(local_30[0] + iVar9 * 4);
            (this->vel).y = 0.0;
            if (*(int *)(*(int *)(local_30[0] + iVar9 * 4) + 0x10) != 0) {
              FUN_800885f0(*(int *)(*(int *)(local_30[0] + iVar9 * 4) + 0x10),(int)this);
            }
            break;
          }
        }
      }
      objRomDefMove_800af9d8
                ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 this->def,(short)(char)this->mapId);
    }
    else {
      (this->vel).y = 0.0;
    }
  }
  return;
}


/* @description Override hit detection */

void DRpickup_hitDetect(ObjInstance *this) { //802BA910
  return;
}


/* Library Function - Single Match
    dll_2B9_func06
   
   Library: KioskDefault 0 0 */

void DRpickup_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802BA914
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((((byte)this->state[0x14] >> 5 & 1) == 0) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_2B9_func07
   
   Library: KioskDefault 0 0 */

void DRpickup_free(ObjInstance *this,int param2) { //802BA988
  Object_removePlayerObj(this,0x3a);
  return;
}


undefined4 DRpickup_func08(ObjInstance *this) { //802BA9B4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRpickup_getExtraSize(void) { //802BA9BC
  return 0x18;
}


/* Library Function - Single Match
    dll_2B9_func0A
   
   Library: KioskDefault 0 0 */

void DRpickup_setScale(ObjInstance *this,float scale) { //802BA9C4
  float fVar1;
  short sVar2;
  ObjInstance *in_r4;
  int in_r5;
  Gfx **in_r6;
  undefined4 *in_r7;
  undefined4 *in_r8;
  undefined4 *in_r9;
  ObjDef *pOVar3;
  int iVar4;
  float fVar5;
  float *pfVar6;
  Mtx44 *pMVar7;
  int iVar8;
  
  pfVar6 = (float *)this->state;
  pOVar3 = this->def;
  if ((*(byte *)(pfVar6 + 5) >> 5 & 1) != 0) {
    *pfVar6 = (this->pos).pos.x;
    pfVar6[1] = (this->pos).pos.y;
    pfVar6[2] = (this->pos).pos.z;
    iVar4 = (int)(&in_r4->data->pAttachPoints[in_r5].bone)[(char)this->curModel];
    pMVar7 = in_r4->modelInstances->mtxs[(char)in_r4->curModel + -3];
    fVar5 = pMVar7->m11;
    (this->pos).rotation.z = 0;
    (this->pos).rotation.x = *(short *)(pfVar6 + 4);
    (this->pos).rotation.y = *(short *)((int)pfVar6 + 0x12);
    iVar8 = (int)(&pMVar7->m14)[*(ushort *)&pMVar7->m23 & 1] + iVar4 * 0x100;
    if (*(char *)((int)&pOVar3[1].objType + 1) == '\0') {
      iVar4 = (int)(&pMVar7->m14)[*(ushort *)&pMVar7->m23 & 1] +
              *(char *)(*(int *)((int)fVar5 + 0x3c) +
                       *(char *)(*(int *)((int)fVar5 + 0x3c) + iVar4 * 0x1c) * 0x1c) * 0x100;
    }
    else {
      iVar4 = (int)(&pMVar7->m14)[*(ushort *)&pMVar7->m23 & 1] +
              *(char *)(*(int *)((int)fVar5 + 0x3c) + iVar4 * 0x1c) * 0x100;
    }
    fVar5 = *(float *)(iVar4 + 0x30) - *(float *)(iVar8 + 0x30);
    fVar1 = *(float *)(iVar4 + 0x38) - *(float *)(iVar8 + 0x38);
    iVar4 = getAngle();
    (this->pos).rotation.x = (this->pos).rotation.x + (short)iVar4;
    sqrt((double)(fVar5 * fVar5 + fVar1 * fVar1));
    iVar4 = getAngle();
    (this->pos).rotation.y = (this->pos).rotation.y + (short)iVar4;
    if (*(char *)((int)&pOVar3[1].objType + 1) == '\x01') {
      if ((this->pos).rotation.y < -0x32) {
        sVar2 = -0x32;
      }
      else if ((this->pos).rotation.y < 0x33) {
        sVar2 = (this->pos).rotation.y;
      }
      else {
        sVar2 = 0x32;
      }
      (this->pos).rotation.y = sVar2;
    }
    objGetAttachPointWorldPos
              (in_r4,in_r5,&(this->pos).pos.x,&(this->pos).pos.y,&(this->pos).pos.z,FALSE);
    (this->pos).pos.y = (this->pos).pos.y + pfVar6[3];
    objRenderCurrentModel(this,in_r6,in_r7,in_r8,in_r9);
  }
  return;
}


/* Library Function - Single Match
    dll_2B9_func0B
   
   Library: KioskDefault 0 0 */

int DRpickup_func0B(int param1) { //802BAC40
  int iVar1;
  
  if ((*(byte *)(*(int *)(param1 + 0xb8) + 0x14) >> 5 & 1) == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (int)*(char *)(*(int *)(param1 + 0x4c) + 0x19);
  }
  return iVar1;
}


/* Library Function - Single Match
    dll_2B9_func0C
   
   Library: KioskDefault 0 0 */

void DRpickup_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //802BAC78
  this->state[0x14] = this->state[0x14] & 0xdf;
  return;
}

