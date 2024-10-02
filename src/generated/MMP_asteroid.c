
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void MMP_asteroid_initialise(undefined4 param) { //8021AC88
  return;
}


/* @description Called when DLL is unloaded */

void MMP_asteroid_release(void) { //8021AC8C
  return;
}


/* Library Function - Single Match
    dll_1A6_func03
   
   Library: KioskDefault 0 0 */

void MMP_asteroid_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8021AC90
  byte bVar1;
  float fVar2;
  uint uVar3;
  ObjInstance *pOVar4;
  byte *pbVar5;
  
  pbVar5 = this->state;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8021b488;
  *pbVar5 = 0;
  uVar3 = mainGetBit(0x88c);
  pbVar5[2] = (byte)uVar3;
  uVar3 = mainGetBit(0x87b);
  pbVar5[1] = (byte)uVar3;
  bVar1 = pbVar5[1];
  if (bVar1 == 2) {
    this->newOpacity = 0xff;
    *pbVar5 = 4;
    this->curModel = 1;
    pOVar4 = Object_objGetMain();
    loadLfxAction(this,pOVar4,0x274);
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      this->newOpacity = 0;
      this->curModel = 0;
    }
    else if (true) {
      this->newOpacity = 0xff;
      *pbVar5 = 4;
      this->curModel = 1;
      *pbVar5 = *pbVar5 | 0x40;
      pOVar4 = Object_objGetMain();
      loadLfxAction(this,pOVar4,0x274);
    }
  }
  else if (bVar1 < 4) {
    this->newOpacity = 0xff;
    *pbVar5 = 4;
    this->curModel = 1;
    pOVar4 = Object_objGetMain();
    loadLfxAction(this,pOVar4,0x274);
  }
  fVar2 = (this->pos).pos.y;
  *(float *)(pbVar5 + 0xc) = fVar2;
  *(float *)(pbVar5 + 0x10) = fVar2;
  return;
}


/* Library Function - Single Match
    dll_1A6_func04
   
   Library: KioskDefault 0 0 */

void MMP_asteroid_update(ObjInstance *this) { //8021ADFC
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  double dVar4;
  double local_48;
  
  _savefpr_30();
  pbVar3 = this->state;
  if ((*pbVar3 & 0x80) == 0) {
    uVar1 = mainGetBit(0x88c);
    pbVar3[2] = (byte)uVar1;
    pbVar3[1] = 2;
    audioTryStartSfx((int *)this,0xc0,0x7f,pbVar3[2] * ' ' + 0x20,"MMP_asteroid.c",0x9d);
    if ((((float)((double)CONCAT44(0x43300000,(uint)pbVar3[2]) - 4503599627370496.0) * 13.0 +
         *(float *)(pbVar3 + 0xc)) - (this->pos).pos.y) * 0.1 <= (this->vel).y) {
      (this->vel).y = (this->vel).y - 0.051;
    }
    else {
      (this->vel).y = (this->vel).y + 0.03;
    }
    *(short *)(pbVar3 + 0x14) = *(short *)(pbVar3 + 0x14) + 0x1000;
    *(short *)(pbVar3 + 0x16) = *(short *)(pbVar3 + 0x16) + 0xdac;
    *(short *)(pbVar3 + 0x18) = *(short *)(pbVar3 + 0x18) + 0x800;
    objMove(0.0,(double)((this->vel).y * timeDelta),0.0,this);
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (uint)*(ushort *)
                                                                                  (pbVar3 + 0x14)) -
                                                         4503599627370496.0) * 3.141593) / 32767.0))
    ;
    (this->pos).pos.y = (float)((double)(this->pos).pos.y + dVar4);
    if ((this->pos).pos.y < *(float *)(pbVar3 + 0xc)) {
      (this->pos).pos.y = *(float *)(pbVar3 + 0xc);
    }
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (uint)*(ushort *)
                                                                                  (pbVar3 + 0x16)) -
                                                         4503599627370496.0) * 3.141593) / 32767.0))
    ;
    (this->pos).rotation.z = (this->pos).rotation.z + (short)(int)(dVar4 * 182.0);
    dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                           (uint)*(ushort *)
                                                                                  (pbVar3 + 0x18)) -
                                                         4503599627370496.0) * 3.141593) / 32767.0))
    ;
    (this->pos).rotation.y = (this->pos).rotation.y + (short)(int)(dVar4 * 182.0);
    DAT_80395d20 = 1.0;
    DAT_80395d24 = (this->pos).pos.x;
    DAT_80395d28 = *(float *)(pbVar3 + 0xc) - 55.0;
    DAT_80395d2c = (this->pos).pos.z;
    FLOAT_80399e60 = (float)(int)((this->pos).pos.y - *(float *)(pbVar3 + 0xc));
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x722,0,2,0xffffffff,&FLOAT_80399e60);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))
              (this,0x723,&DAT_80395d18,&DAT_00200001,0xffffffff,&FLOAT_80399e60);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))
              (this,0x723,&DAT_80395d18,&DAT_00200001,0xffffffff,&FLOAT_80399e60);
  }
  if (*pbVar3 != 0) {
    if ((*pbVar3 & 1) != 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x716,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x716,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x716,0,1,0xffffffff,0);
    }
    if ((*pbVar3 & 2) != 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x719,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x719,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x719,0,1,0xffffffff,0);
    }
    if ((*pbVar3 & 8) != 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x71a,0,2,0xffffffff,0);
    }
    if ((*pbVar3 & 0x10) != 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x71b,0,1,0xffffffff,0);
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x71c,0,1,0xffffffff,0);
      }
      *pbVar3 = *pbVar3 & 0xef;
    }
    if ((*pbVar3 & 0x20) != 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x71d,0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x71d,0,1,0xffffffff,0);
    }
    if (((*pbVar3 & 0x40) != 0) &&
       (*(float *)(pbVar3 + 8) = *(float *)(pbVar3 + 8) - timeDelta, *(float *)(pbVar3 + 8) < 0.0))
    {
      uVar1 = randInt(10,0x3c);
      local_48 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
      *(float *)(pbVar3 + 8) = (float)(local_48 - 4503601774854144.0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x71e,0,1,0xffffffff,0);
    }
  }
  if (0.0 < *(float *)(pbVar3 + 4)) {
    *(float *)(pbVar3 + 4) = *(float *)(pbVar3 + 4) - timeDelta;
    if (*(float *)(pbVar3 + 4) <= 0.0) {
      mainSetBits(0x88b,0);
    }
  }
  *pbVar3 = *pbVar3 & 0x7f;
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void MMP_asteroid_hitDetect(ObjInstance *this) { //8021B414
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void MMP_asteroid_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8021B418
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

void MMP_asteroid_free(ObjInstance *this,int param2) { //8021B474
  return;
}


undefined4 MMP_asteroid_func08(ObjInstance *this) { //8021B478
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int MMP_asteroid_getExtraSize(void) { //8021B480
  return 0x1c;
}

