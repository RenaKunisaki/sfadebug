
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIM2icicle_initialise(undefined4 param) { //8022DE48
  return;
}


/* @description Called when DLL is unloaded */

void DIM2icicle_release(void) { //8022DE4C
  return;
}


/* Library Function - Single Match
    dll_21D_func03
   
   Library: KioskDefault 0 0 */

void DIM2icicle_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //8022DE50
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 == 0) {
    puVar3[6] = 0;
    this->newOpacity = 0xff;
  }
  else {
    puVar3[6] = 2;
    this->newOpacity = 0;
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  (this->vel).y = 0.0;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_21D_func04
   
   Library: KioskDefault 0 0 */

void DIM2icicle_update(ObjInstance *this) { //8022DEDC
  byte bVar1;
  short sVar2;
  int iVar3;
  ObjDef *pOVar4;
  int iVar5;
  float *pfVar6;
  int local_34 [5];
  
  pOVar4 = this->def;
  pfVar6 = (float *)this->state;
  bVar1 = *(byte *)((int)pfVar6 + 6);
  if (bVar1 != 2) {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        iVar5 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
        if (iVar5 != 0xe) {
          return;
        }
        iVar5 = randInt(800,0x4b0);
        *(short *)(pfVar6 + 1) = (short)iVar5;
        *(undefined *)((int)pfVar6 + 6) = 3;
        this->hitstate->flags = this->hitstate->flags & 0xfffe;
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x58,0x7f,"DIM2icicle.c",(int *)0x6c)
        ;
        return;
      }
      if (true) {
        if (*(char *)((int)pfVar6 + 7) == '\0') {
          iVar3 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                               (double)(this->pos).pos.z,(int)this,local_34,0,0);
          *pfVar6 = -100000.0;
          for (iVar5 = 0; iVar5 < iVar3; iVar5 = iVar5 + 1) {
            if (*(char *)(*(int *)(local_34[0] + iVar5 * 4) + 0x14) == '\x0e') {
              *pfVar6 = **(float **)(local_34[0] + iVar5 * 4);
              iVar5 = iVar3;
            }
          }
          if (*pfVar6 != -100000.0) {
            *(undefined *)((int)pfVar6 + 7) = 1;
          }
        }
        if ((0 < *(short *)(pfVar6 + 2)) &&
           (*(ushort *)(pfVar6 + 2) = *(short *)(pfVar6 + 2) - (ushort)framesThisStep,
           *(short *)(pfVar6 + 2) < 1)) {
          audioTryStartSfx((int *)this,1,0x22e,0x7f,"DIM2icicle.c",0x93);
        }
        (this->vel).y = -(timeDelta * 0.1 - (this->vel).y);
        if ((this->vel).y < -10.0) {
          (this->vel).y = -10.0;
        }
        (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
        if (*pfVar6 <= (this->pos).pos.y) {
          return;
        }
        sVar2._0_1_ = pOVar4[1].bound;
        sVar2._1_1_ = pOVar4[1].cullDist;
        mainSetBits((int)sVar2,1);
        *(undefined *)((int)pfVar6 + 6) = 2;
                    /* {@symbol 800dac04} */
        (**(code **)(*(int *)pDll_TrickyWalk + 0x10))
                  ((double)(this->pos).pos.x,(double)*pfVar6,(double)(this->pos).pos.z,
                   0x4024000000000000);
                    /* {@symbol 800db230} */
        (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                  ((double)(this->pos).pos.x,(double)*pfVar6,(double)(this->pos).pos.z,0,0,2);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0xf9,0x7f,"DIM2icicle.c",(int *)0xa5)
        ;
        *(undefined2 *)(pfVar6 + 2) = 0x96;
        return;
      }
    }
    else if (bVar1 < 4) {
      (this->pos).rotation.y = *(short *)(pfVar6 + 1);
      *(short *)(pfVar6 + 1) =
           (short)(int)((float)((double)CONCAT44(0x43300000,(int)*(short *)(pfVar6 + 1) ^ 0x80000000
                                                ) - 4503601774854144.0) * 0.333);
      if (9 < (this->pos).rotation.y) {
        return;
      }
      (this->pos).rotation.y = 0;
      *(undefined *)((int)pfVar6 + 6) = 1;
      *(undefined2 *)(pfVar6 + 2) = 0x3c;
      return;
    }
  }
  if ((0 < *(short *)(pfVar6 + 2)) &&
     (*(ushort *)(pfVar6 + 2) = *(short *)(pfVar6 + 2) - (ushort)framesThisStep,
     *(short *)(pfVar6 + 2) < 1)) {
    audioTryStartSfx((int *)this,1,0x42,0x7f,"DIM2icicle.c",0xb0);
  }
  iVar5 = (uint)this->newOpacity + (uint)framesThisStep * -8;
  if (iVar5 < 0) {
    iVar5 = 0;
    (this->pos).pos.y = (pOVar4->pos).y;
    (this->vel).y = 0.0;
  }
  this->newOpacity = (u8)iVar5;
  (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
  return;
}


/* @description Override hit detection */

void DIM2icicle_hitDetect(ObjInstance *this) { //8022E268
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIM2icicle_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8022E26C
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

void DIM2icicle_free(ObjInstance *this,int param2) { //8022E2C8
  return;
}


undefined4 DIM2icicle_func08(ObjInstance *this) { //8022E2CC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIM2icicle_getExtraSize(void) { //8022E2D4
  return 0xc;
}

