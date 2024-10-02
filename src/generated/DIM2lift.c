
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIM2lift_initialise(undefined4 param) { //8022D588
  return;
}


/* @description Called when DLL is unloaded */

void DIM2lift_release(void) { //8022D58C
  return;
}


/* Library Function - Single Match
    dll_21B_func03
   
   Library: KioskDefault 0 0 */

void DIM2lift_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8022D590
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 == 0) {
    puVar3[4] = 1;
  }
  else {
    puVar3[4] = 2;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_21B_func04
   
   Library: KioskDefault 0 0 */

void DIM2lift_update(ObjInstance *this) { //8022D604
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  bool bVar6;
  ObjInstance *pOVar7;
  uint uVar8;
  int iVar9;
  ObjDef *pOVar10;
  float *pfVar11;
  
  pfVar11 = (float *)this->state;
  pOVar7 = Object_objGetMain();
  pOVar10 = this->def;
  bVar6 = false;
  iVar9 = 0;
  do {
    if ((char)this->field18_0x58->field144_0x10f <= iVar9) {
LAB_8022d674:
      bVar1 = *(byte *)(pfVar11 + 1);
      if (bVar1 == 3) {
        *pfVar11 = timeDelta * 0.02 + *pfVar11;
        if (1.5 < *pfVar11) {
          *pfVar11 = 1.5;
        }
        (this->pos).pos.y = *pfVar11 * timeDelta + (this->pos).pos.y;
        if ((pOVar10->pos).y < (this->pos).pos.y) {
          audioTryStartSfx((int *)this,8,0x47,0x7f,"DIM2lift.c",0x9e);
          (this->pos).pos.y = (pOVar10->pos).y;
          *(undefined *)(pfVar11 + 1) = 1;
          if (bVar6) {
            *(undefined *)((int)pfVar11 + 5) = 1;
            *(undefined *)((int)pfVar11 + 6) = 0;
          }
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 1) {
          FUN_80068a9c((uint)this,8);
          if (bVar6) {
            if ((*(char *)((int)pfVar11 + 6) != '\0') && (*(char *)((int)pfVar11 + 5) != '\0')) {
              audioTryStartSfx((int *)this,0x88,0x127,0x7f,"DIM2lift.c",0x73);
              *(undefined *)(pfVar11 + 1) = 4;
              *pfVar11 = 0.0;
            }
          }
          else {
            *(undefined *)((int)pfVar11 + 6) = 1;
          }
          uVar8 = mainGetBit((int)*(short *)&pOVar10[1].pos.x);
          if (uVar8 != 0) {
            audioTryStartSfx((int *)this,0x88,0x127,0x7f,"DIM2lift.c",0x7a);
            *(undefined *)(pfVar11 + 1) = 4;
            *pfVar11 = 0.0;
          }
        }
        else if (bVar1 != 0) {
          FUN_80068a9c((uint)this,8);
          if (*(char *)((int)pfVar11 + 5) == '\0') {
            uVar8 = mainGetBit((int)*(short *)&pOVar10[1].pos.x);
            if (uVar8 == 0) {
              audioTryStartSfx((int *)this,0x88,0x127,0x7f,"DIM2lift.c",0x8c);
              *(undefined *)(pfVar11 + 1) = 3;
              *pfVar11 = 0.0;
              *(undefined *)((int)pfVar11 + 5) = 0;
              sVar3._0_1_ = pOVar10[1].bound;
              sVar3._1_1_ = pOVar10[1].cullDist;
              mainSetBits((int)sVar3,0);
            }
          }
          else if (!bVar6) {
            audioTryStartSfx((int *)this,0x88,0x127,0x7f,"DIM2lift.c",0x85);
            *(undefined *)(pfVar11 + 1) = 3;
            *pfVar11 = 0.0;
            *(undefined *)((int)pfVar11 + 5) = 0;
            sVar2._0_1_ = pOVar10[1].bound;
            sVar2._1_1_ = pOVar10[1].cullDist;
            mainSetBits((int)sVar2,0);
          }
        }
      }
      else if (bVar1 < 5) {
        *pfVar11 = timeDelta * -0.02 + *pfVar11;
        if (*pfVar11 < -1.5) {
          *pfVar11 = -1.5;
        }
        (this->pos).pos.y = *pfVar11 * timeDelta + (this->pos).pos.y;
        if ((this->pos).pos.y < (pOVar10->pos).y - 235.5) {
          audioTryStartSfx((int *)this,8,0x47,0x7f,"DIM2lift.c",0xb2);
          (this->pos).pos.y = (pOVar10->pos).y - 235.5;
          *(undefined *)(pfVar11 + 1) = 2;
          sVar4._0_1_ = pOVar10[1].bound;
          sVar4._1_1_ = pOVar10[1].cullDist;
          mainSetBits((int)sVar4,1);
        }
        if ((*(char *)((int)pfVar11 + 5) == '\0') &&
           (uVar8 = mainGetBit((int)*(short *)&pOVar10[1].pos.x), uVar8 == 0)) {
          *(undefined *)(pfVar11 + 1) = 3;
          sVar5._0_1_ = pOVar10[1].bound;
          sVar5._1_1_ = pOVar10[1].cullDist;
          mainSetBits((int)sVar5,0);
        }
      }
      return;
    }
    if (*(ObjInstance **)((int)(this->field18_0x58->mtx + 2) + iVar9 * 4) == pOVar7) {
      bVar6 = true;
      goto LAB_8022d674;
    }
    iVar9 = iVar9 + 1;
  } while( true );
}


/* @description Override hit detection */

void DIM2lift_hitDetect(ObjInstance *this) { //8022D998
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIM2lift_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8022D99C
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

void DIM2lift_free(ObjInstance *this,int param2) { //8022D9F8
  return;
}


undefined4 DIM2lift_func08(ObjInstance *this) { //8022D9FC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DIM2lift_getExtraSize(void) { //8022DA04
  return 8;
}

