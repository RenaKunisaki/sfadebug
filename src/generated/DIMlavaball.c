
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMlavaball_initialise(undefined4 param) { //8022585C
  return;
}


/* @description Called when DLL is unloaded */

void DIMlavaball_release(void) { //80225860
  return;
}


/* Library Function - Single Match
    dll_200_func03
   
   Library: KioskDefault 0 0 */

void DIMlavaball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80225864
  short sVar1;
  short sVar2;
  ObjInstance *pOVar3;
  ObjInstance **ppOVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  _savefpr_30();
  if (this->romdefno == DIMLavaDebr) {
    FUN_80226078((int)this);
  }
  else {
    (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
    ppOVar4 = (ObjInstance **)this->state;
    sVar1._0_1_ = objDef[1].allocatedSize;
    sVar1._1_1_ = objDef[1].mapStates1;
    dVar6 = (double)((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                            4503601774854144.0) * 0.1);
    sVar2._0_1_ = objDef[1].loadFlags;
    sVar2._1_1_ = objDef[1].mapStates2;
    dVar7 = (double)((float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) -
                            4503601774854144.0) * 0.1);
    ppOVar4[1] = (ObjInstance *)(this->pos).pos.y;
    ppOVar4[2] = (ObjInstance *)objDef->id;
    objDef->id = -1;
    dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (int)(this->pos).rotation
                                                                                .x ^ 0x80000000) -
                                                         4503601774854144.0) * 3.141593) / 32767.0))
    ;
    (this->vel).x = (float)(dVar7 * -dVar5);
    (this->vel).y = (float)dVar6;
    dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                       (int)(this->pos).rotation.x ^
                                                                       0x80000000) -
                                                     4503601774854144.0) * 3.141593) / 32767.0));
    (this->vel).z = (float)(dVar7 * -dVar5);
    if (this->hitstate != (HitState *)0x0) {
      this->hitstate->field21_0x5b = 0;
    }
    if (this->shadow != (Shadow *)0x0) {
      this->shadow->flags = this->shadow->flags | 0x810;
    }
    pOVar3 = Object_findByUniqueId((int)ppOVar4[2]);
    *ppOVar4 = pOVar3;
    *(byte *)(ppOVar4 + 3) = *(byte *)(ppOVar4 + 3) | 0x10;
    FUN_80088da4((int)this);
    this->flags_0xb0 = this->flags_0xb0 | DontMove;
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    dll_200_func04
   
   Library: KioskDefault 0 0 */

void DIMlavaball_update(ObjInstance *this) { //80225A18
  u8 uVar1;
  float fVar2;
  int iVar3;
  HitState *pHVar4;
  int *piVar5;
  
  fVar2 = timeDelta;
  uVar1 = framesThisStep;
  if (this->romdefno == DIMLavaDebr) {
    FUN_80226130(this);
  }
  else {
    piVar5 = (int *)this->state;
    if ((*(byte *)(piVar5 + 3) & 0x10) == 0) {
      (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * 0x40;
      (this->pos).rotation.y = (this->pos).rotation.y + (ushort)uVar1 * -0x200;
      (this->vel).y = fVar2 * -0.09 + (this->vel).y;
      objMove((double)((this->vel).x * fVar2),(double)((this->vel).y * fVar2),
              (double)((this->vel).z * fVar2),this);
      pHVar4 = this->hitstate;
      if (pHVar4 != (HitState *)0x0) {
        *(undefined *)((int)&pHVar4->sizeX2 + 1) = 0xb;
        *(undefined *)&pHVar4->flags_0x60 = 1;
        (pHVar4->field12_0x3c).y = 2.242078e-44;
        (pHVar4->field12_0x3c).z = 2.242078e-44;
        if (pHVar4->field13_0x48 != 0) {
          if (*(short *)(pHVar4->field13_0x48 + 0x46) == 0x1ee) {
            *(byte *)(piVar5 + 3) = *(byte *)(piVar5 + 3) | 4;
            FUN_80225fd8((int)this);
          }
        }
      }
      if ((*(byte *)(piVar5 + 3) & 1) != 0) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,500,0,1,0xffffffff,0);
      }
      if ((this->pos).pos.y < (float)piVar5[1]) {
        *(byte *)(piVar5 + 3) = *(byte *)(piVar5 + 3) | 0x10;
      }
      if ((*(byte *)(piVar5 + 3) & 8) == 0) {
        audioTryStartSfx((int *)this,1,0x3a,0x7f,"DIMlavaball.c",0xbb);
        *(byte *)(piVar5 + 3) = *(byte *)(piVar5 + 3) | 8;
      }
      if ((*(byte *)(piVar5 + 3) & 2) == 0) {
        if (*piVar5 != 0) {
          if ((*(float *)(*piVar5 + 0x10) + 105.0 < (this->pos).pos.y) &&
             (iVar3 = (**(code **)(**(int **)(*piVar5 + 0x68) + 0x20))(*piVar5,this), iVar3 != 0)) {
            *(byte *)(piVar5 + 3) = *(byte *)(piVar5 + 3) | 2;
          }
        }
      }
      else if (*piVar5 != 0) {
        if ((this->pos).pos.y < *(float *)(*piVar5 + 0x10) + 100.0) {
          (**(code **)(**(int **)(*piVar5 + 0x68) + 0x24))(*piVar5,this);
          *(byte *)(piVar5 + 3) = *(byte *)(piVar5 + 3) & 0xfd;
        }
      }
    }
    else {
      FUN_80088da4((int)this);
    }
  }
  return;
}


/* @description Override hit detection */

void DIMlavaball_hitDetect(ObjInstance *this) { //80225C80
  return;
}


/* Library Function - Single Match
    dll_200_func06
   
   Library: KioskDefault 0 0 */

void DIMlavaball_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80225C84
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  if (this->romdefno == DIMLavaDebr) {
    if (shouldRender) {
      objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
  }
  else {
    puVar1 = this->state;
    if ((puVar1[0xc] & 4) == 0) {
      if (shouldRender) {
        puVar1[0xc] = puVar1[0xc] | 1;
        objRenderCurrentModel
                  (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                   (undefined4 *)CONCAT31(in_register_00000014,param3),
                   (undefined4 *)CONCAT31(in_register_00000018,param4),
                   (undefined4 *)CONCAT31(in_register_0000001c,param5));
      }
      else {
        puVar1[0xc] = puVar1[0xc] & 0xfe;
      }
    }
    else {
      puVar1[0xc] = puVar1[0xc] & 0xfb;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_200_func07
   
   Library: KioskDefault 0 0 */

void DIMlavaball_free(ObjInstance *this,int param2) { //80225D5C
  ObjInstance *pOVar1;
  undefined *puVar2;
  
  if (this->romdefno != DIMLavaDebr) {
    puVar2 = this->state;
                    /* {@symbol 800dc2d8} */
    (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
    if (((puVar2[0xc] & 2) != 0) &&
       (pOVar1 = Object_findByUniqueId(*(int *)(puVar2 + 8)), pOVar1 != (ObjInstance *)0x0)) {
      (*(code *)pOVar1->dll->ptrs2->field9_0x24)(pOVar1,this);
    }
  }
  return;
}


undefined4 DIMlavaball_func08(ObjInstance *this) { //80225DE8
  if (this->romdefno == DIMLavaDebr) {
    return 0;
  }
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int DIMlavaball_getExtraSize(int param1) { //80225E04
  if (*(short *)(param1 + 0x46) == 0x1fa) {
    return 0;
  }
  return 0x10;
}


byte DIMlavaball_func0B(int param1) { //80225E20
  return *(byte *)(*(int *)(param1 + 0xb8) + 0xc) & 0x10;
}


/* Library Function - Single Match
    dll_200_func0A
   
   Library: KioskDefault 0 0 */

void DIMlavaball_setScale(ObjInstance *this,float scale) { //80225E40
  float fVar1;
  uint in_r4;
  uint in_r5;
  ObjDef *pOVar2;
  int *piVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  _savefpr_30();
  piVar3 = (int *)this->state;
  pOVar2 = this->def;
  dVar5 = (double)((float)((double)CONCAT44(0x43300000,in_r4 ^ 0x80000000) - 4503601774854144.0) *
                  0.1);
  dVar6 = (double)((float)((double)CONCAT44(0x43300000,in_r5 ^ 0x80000000) - 4503601774854144.0) *
                  0.1);
  fVar1 = *(float *)(*piVar3 + 0xc);
  (this->prevPos).x = fVar1;
  (this->pos).pos.x = fVar1;
  fVar1 = *(float *)(*piVar3 + 0x10);
  (this->prevPos).y = fVar1;
  (this->pos).pos.y = fVar1;
  fVar1 = *(float *)(*piVar3 + 0x14);
  (this->prevPos).z = fVar1;
  (this->pos).pos.z = fVar1;
  fVar1 = (this->pos).pos.x;
  (this->pos_0x8c).x = fVar1;
  (this->oldPos).x = fVar1;
  fVar1 = (this->pos).pos.y;
  (this->pos_0x8c).y = fVar1;
  (this->oldPos).y = fVar1;
  fVar1 = (this->pos).pos.z;
  (this->pos_0x8c).z = fVar1;
  (this->oldPos).z = fVar1;
  (this->pos).rotation.x = (short)((int)*(char *)&pOVar2[1].objType << 8);
  dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(this->pos).rotation.x
                                                                         ^ 0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  (this->vel).x = (float)(dVar6 * -dVar4);
  (this->vel).y = (float)dVar5;
  dVar4 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                     (int)(this->pos).rotation.x ^
                                                                     0x80000000) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  (this->vel).z = (float)(dVar6 * -dVar4);
  FUN_80088d3c((int)this);
  *(byte *)(piVar3 + 3) = *(byte *)(piVar3 + 3) & 0xef;
  _restfpr_30();
  return;
}

