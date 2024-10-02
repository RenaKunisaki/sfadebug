
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void gfxEmit_initialise(undefined4 param) { //801F1E60
  return;
}


/* @description Called when DLL is unloaded */

void gfxEmit_release(void) { //801F1E64
  return;
}


/* Library Function - Single Match
    gfxEmit_func03
   
   Library: KioskDefault 0 0 */

void gfxEmit_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //801F1E68
  uint uVar1;
  int iVar2;
  float *pfVar3;
  
  (this->pos).rotation.x = 0;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801f259c;
  pfVar3 = (float *)this->state;
  *pfVar3 = (float)((double)CONCAT44(0x43300000,(int)*(char *)&objDef[1].objType << 2 ^ 0x80000000)
                   - 4503601774854144.0);
  *(short *)(pfVar3 + 2) = (short)*(char *)((int)&objDef[1].objType + 1);
  *(undefined2 *)((int)pfVar3 + 10) = *(undefined2 *)&objDef[1].allocatedSize;
  *(undefined2 *)((int)pfVar3 + 0xe) = *(undefined2 *)&objDef[1].loadFlags;
  (this->pos).scale = 0.1;
  *(undefined2 *)(pfVar3 + 5) = *(undefined2 *)&objDef[1].bound;
  *(undefined2 *)((int)pfVar3 + 0x16) = *(undefined2 *)&objDef[1].pos.x;
  *(undefined2 *)(pfVar3 + 6) = 0;
  if (*(short *)((int)pfVar3 + 0xe) < 1) {
    this->field76_0xf4 = (int)*(short *)((int)pfVar3 + 0xe);
  }
  else {
    this->field76_0xf4 = 0;
  }
  if ((*(short *)((int)pfVar3 + 0x16) != -1) &&
     (uVar1 = mainGetBit((int)*(short *)((int)pfVar3 + 0x16)), uVar1 != 0)) {
    *(undefined2 *)(pfVar3 + 6) = 1;
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].pos.y << 8);
  (this->pos).rotation.y = (short)((int)*(char *)((int)&objDef[1].pos.x + 3) << 8);
  (this->pos).rotation.z = (short)((int)*(char *)((int)&objDef[1].pos.x + 2) << 8);
  *(ushort *)((int)pfVar3 + 0x1a) = (ushort)*(byte *)((int)&objDef[1].pos.z + 1) * 100;
  pfVar3[1] = (this->pos).pos.x;
  iVar2 = randInt(0,10);
  *(short *)((int)pfVar3 + 0x12) = (short)iVar2;
  *(undefined2 *)(pfVar3 + 3) = 0;
  return;
}


/* Library Function - Single Match
    gfxEmit_func04
   
   Library: KioskDefault 0 0 */

void gfxEmit_update(ObjInstance *this) { //801F1FC4
  float fVar1;
  float fVar2;
  float fVar3;
  N64Button NVar7;
  s8 sVar8;
  N64Button32 NVar4;
  ObjInstance *pOVar5;
  uint uVar6;
  ObjDef *pOVar9;
  float *pfVar10;
  double dVar11;
  
  _savefpr_30();
  pfVar10 = (float *)this->state;
  pOVar9 = this->def;
  dVar11 = 0.0;
  if (*(short *)((int)pfVar10 + 0x12) == 0) {
    (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
    (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
    (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
    (this->prevPos).x = (this->pos).pos.x;
    (this->prevPos).y = (this->pos).pos.y;
    (this->prevPos).z = (this->pos).pos.z;
    NVar7 = n64GetEnabledButtonsHeld(1);
    if ((NVar7 & N64_BUTTON_Z) == 0) {
      NVar7 = n64GetEnabledButtonsHeld(3);
      if ((NVar7 & N64_BUTTON_DOWN) != 0) {
        sVar8 = getStickX(3);
        dVar11 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000) -
                                4503601774854144.0);
        NVar4 = n64GetEnabledButtonsPressed(3);
        if ((NVar4 & N64_BUTTON_C_RIGHT) != 0) {
          *(short *)(pfVar10 + 3) = *(short *)(pfVar10 + 3) + 0x32;
        }
        NVar4 = n64GetEnabledButtonsPressed(3);
        if ((NVar4 & N64_BUTTON_C_LEFT) != 0) {
          *(short *)(pfVar10 + 3) = *(short *)(pfVar10 + 3) + -0x32;
        }
        diPrintf("PFX_PREVIEW %d",(int)*(short *)(pfVar10 + 3));
      }
      DAT_80399da0 = (float)(dVar11 * 30.0 + (double)DAT_80399da0);
      if ((1000.0 < DAT_80399da0) || (DAT_80399da0 < -1000.0)) {
        if (DAT_80399da0 <= 1000.0) {
          *(short *)(pfVar10 + 3) = *(short *)(pfVar10 + 3) + -1;
        }
        else {
          *(short *)(pfVar10 + 3) = *(short *)(pfVar10 + 3) + 1;
        }
        if (*(short *)(pfVar10 + 3) < 0) {
          *(undefined2 *)(pfVar10 + 3) = 0;
        }
        DAT_80399da0 = 0.0;
      }
      pOVar5 = Object_objGetMain();
      if ((pOVar5 != (ObjInstance *)0x0) && (pOVar9 != (ObjDef *)0x0)) {
        if ((*(char *)((int)&pOVar9[1].pos.z + 1) != '\0') &&
           (*(char *)((int)&pOVar9[1].pos.z + 1) != -1)) {
          if (*(short *)((int)pfVar10 + 0x1a) < 1) {
            *(undefined2 *)(pfVar10 + 6) = 0;
            *(ushort *)((int)pfVar10 + 0x1a) = (ushort)*(byte *)((int)&pOVar9[1].pos.z + 1) * 100;
            if (*(short *)((int)&pOVar9[1].pos.z + 2) != 0) {
              audioTryStartSfx((int *)this,1,*(ushort *)((int)&pOVar9[1].pos.z + 2),0x7f,
                               "gfxemit.c",0xa5);
            }
          }
          else {
            *(undefined2 *)(pfVar10 + 6) = 1;
          }
          *(ushort *)((int)pfVar10 + 0x1a) =
               *(short *)((int)pfVar10 + 0x1a) - (ushort)framesThisStep;
        }
        if (*(char *)((int)&pOVar9[1].pos.y + 3) == '\x7f') {
          (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * 10;
        }
        else {
          (this->pos).rotation.x =
               (this->pos).rotation.x +
               (short)*(char *)((int)&pOVar9[1].pos.y + 3) * (ushort)framesThisStep * 100;
        }
        if (*(char *)((int)&pOVar9[1].pos.y + 2) == '\x7f') {
          (this->pos).rotation.y = (this->pos).rotation.y + (ushort)framesThisStep * 10;
        }
        else {
          (this->pos).rotation.y =
               (this->pos).rotation.y +
               (short)*(char *)((int)&pOVar9[1].pos.y + 2) * (ushort)framesThisStep * 100;
        }
        if (*(char *)((int)&pOVar9[1].pos.y + 1) == '\x7f') {
          (this->pos).rotation.z = (this->pos).rotation.z + (ushort)framesThisStep * 10;
        }
        else {
          (this->pos).rotation.z =
               (this->pos).rotation.z +
               (short)*(char *)((int)&pOVar9[1].pos.y + 1) * (ushort)framesThisStep * 100;
        }
        if (((*(short *)(pfVar10 + 5) == -1) ||
            (uVar6 = mainGetBit((int)*(short *)(pfVar10 + 5)), uVar6 != 0)) &&
           (*(short *)(pfVar10 + 6) == 0)) {
          if ((*(short *)((int)pfVar10 + 0x16) != -1) &&
             (uVar6 = mainGetBit((int)*(short *)((int)pfVar10 + 0x16)), uVar6 != 0)) {
            *(undefined2 *)(pfVar10 + 6) = 1;
          }
          if (*(char *)((int)&pOVar9[1].pos.z + 1) == -1) {
            *(undefined2 *)(pfVar10 + 6) = 1;
          }
          if ((*(short *)((int)pfVar10 + 0xe) < 0) &&
             ((-1 < *(short *)((int)pfVar10 + 0xe) || (0 < (int)this->field76_0xf4)))) {
            if ((*(short *)((int)pfVar10 + 0xe) < 0) && (0 < (int)this->field76_0xf4)) {
              this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
            }
          }
          else {
            fVar1 = (this->prevPos).x - (pOVar5->prevPos).x;
            fVar2 = (this->prevPos).y - (pOVar5->prevPos).y;
            fVar3 = (this->prevPos).z - (pOVar5->prevPos).z;
            if (*(short *)((int)pfVar10 + 0xe) == 0) {
              *(undefined2 *)(pfVar10 + 6) = 1;
            }
            dVar11 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
            if ((dVar11 <= (double)*pfVar10) || (*pfVar10 == 0.0)) {
              fxEmitFn_8018e6c4((undefined2 *)this);
            }
            this->field76_0xf4 = -(int)*(short *)((int)pfVar10 + 0xe);
          }
        }
      }
    }
  }
  else {
    *(short *)((int)pfVar10 + 0x12) = *(short *)((int)pfVar10 + 0x12) - (short)(int)timeDelta;
    if (*(short *)((int)pfVar10 + 0x12) < 0) {
      *(undefined2 *)((int)pfVar10 + 0x12) = 0;
    }
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void gfxEmit_hitDetect(ObjInstance *this) { //801F2484
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1C7_func06
    dll_1D0_func06
    gfxEmit_func06
   
   Library: KioskDefault 0 0 */

void gfxEmit_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //801F2488
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  if (shouldRender) {
    bVar1 = checkSomeDebugFlags_8017c4f8();
    if (bVar1) {
      objRenderCurrentModel
                (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
      if (((this->pos).flags & 0x100) != 0) {
        FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                     (double)*pfVar2,25.0,(Gfx *)CONCAT31(in_register_00000010,param2),
                     (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
      }
    }
  }
  return;
}


/* @description Free object instance */

void gfxEmit_free(ObjInstance *this,int param2) { //801F2534
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
                    /* {@symbol 800e29b8} */
  (**(code **)(*(int *)pDll_projgfx + 0x14))(this);
  return;
}


undefined4 gfxEmit_func08(ObjInstance *this) { //801F258C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int gfxEmit_getExtraSize(void) { //801F2594
  return 0x20;
}

