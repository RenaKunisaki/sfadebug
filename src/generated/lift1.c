
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void lift1_initialise(undefined4 param) { //8028CC88
  return;
}


/* @description Called when DLL is unloaded */

void lift1_release(void) { //8028CC8C
  return;
}


/* Library Function - Single Match
    lift1_func03
   
   Library: KioskDefault 0 0 */

void lift1_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //8028CC90
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  float *pfVar4;
  
  pfVar4 = (float *)this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8028dde4;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *(undefined2 *)((int)pfVar4 + 10) = 0;
  *(undefined2 *)(pfVar4 + 3) = *(undefined2 *)&objDef[1].pos.x;
  *(undefined2 *)((int)pfVar4 + 0xe) = *(undefined2 *)&objDef[1].bound;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  *pfVar4 = (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  uVar2._0_1_ = objDef[1].loadFlags;
  uVar2._1_1_ = objDef[1].mapStates2;
  *(char *)((int)pfVar4 + 0x12) = (char)uVar2;
  if ((this->romdefno == 0x3c7) && (uVar3 = mainGetBit((int)*(short *)(pfVar4 + 3)), uVar3 != 0)) {
    if ((this->pos).pos.y <= (objDef->pos).y - 370.0) {
      (this->pos).pos.y = (objDef->pos).y - 370.0;
    }
  }
  loadLfxAction(this,this,0x175);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    lift1_func04
   
   Library: KioskDefault 0 0 */

void lift1_update(ObjInstance *this) { //8028CD94
  short sVar1;
  ObjInstance *param2;
  uint uVar2;
  ObjDef *pOVar3;
  undefined *puVar4;
  double in_f1;
  double dVar5;
  
  pOVar3 = this->def;
  puVar4 = this->state;
  param2 = Object_objGetMain();
  if (this->romdefno == VFPLift1) {
    FUN_8028d4a0(this);
  }
  else if (this->romdefno == VFPLift2) {
    FUN_8028d934(this);
  }
  else if (this->romdefno == 0x3c7) {
    FUN_8028dd20(in_f1,this);
  }
  else if (this->romdefno == VFPLift3) {
    FUN_8028d934(this);
  }
  else if (param2 != (ObjInstance *)0x0) {
    sVar1 = *(short *)(puVar4 + 10);
    if (sVar1 == 2) {
      if (*(short *)(puVar4 + 0x10) == 0) {
        dVar5 = (double)objDistObj2ObjXZ(this,param2);
        if (50.0 <= dVar5) {
          if ((pOVar3->pos).y <= (param2->pos).pos.y) {
            if (((pOVar3->pos).y < (param2->pos).pos.y) &&
               (*(undefined2 *)(puVar4 + 10) = 4, puVar4[0x13] == '\x01')) {
              puVar4[0x13] = 0;
            }
          }
          else {
            *(undefined2 *)(puVar4 + 10) = 3;
            if (puVar4[0x13] == '\x01') {
              puVar4[0x13] = 0;
            }
          }
        }
        else if ((this->pos).pos.y == (pOVar3->pos).y + 60.0) {
          *(undefined2 *)(puVar4 + 10) = 3;
          audioTryStartSfx((int *)this,0xc0,299,0x43,"lift1.c",0xba);
          puVar4[0x13] = 1;
        }
        else if ((this->pos).pos.y == (pOVar3->pos).y - 260.0) {
          *(undefined2 *)(puVar4 + 10) = 4;
          audioTryStartSfx((int *)this,0xc0,299,0x43,"lift1.c",0xc1);
          puVar4[0x13] = 1;
        }
      }
      else {
        *(short *)(puVar4 + 0x10) = *(short *)(puVar4 + 0x10) - (short)(int)timeDelta;
        if (*(short *)(puVar4 + 0x10) < 1) {
          *(undefined2 *)(puVar4 + 0x10) = 0;
        }
      }
    }
    else if (sVar1 < 2) {
      if (sVar1 == 0) {
        if ((puVar4[0x12] == '\x01') ||
           (dVar5 = (double)objDistObj2ObjXZ(this,param2), 230.0 <= dVar5)) {
          if ((puVar4[0x12] == '\x01') &&
             (dVar5 = (double)objDistObj2ObjXZ(this,param2), dVar5 < 230.0)) {
            uVar2 = mainGetBit(0x4eb);
            if (uVar2 == 0) {
              if (((this->pos).pos.y < (pOVar3->pos).y + 60.0) &&
                 ((this->pos).pos.y = timeDelta * 0.5 + (this->pos).pos.y,
                 (pOVar3->pos).y + 60.0 <= (this->pos).pos.y)) {
                (this->pos).pos.y = (pOVar3->pos).y + 60.0;
                *(undefined2 *)(puVar4 + 10) = 1;
              }
            }
            else if ((this->pos).pos.y != (pOVar3->pos).y - 260.0) {
              *(undefined2 *)(puVar4 + 10) = 1;
            }
          }
        }
        else if (((this->pos).pos.y < (pOVar3->pos).y + 60.0) &&
                ((this->pos).pos.y = timeDelta * 0.5 + (this->pos).pos.y,
                (pOVar3->pos).y + 60.0 <= (this->pos).pos.y)) {
          (this->pos).pos.y = (pOVar3->pos).y + 60.0;
          *(undefined2 *)(puVar4 + 10) = 1;
        }
      }
      else if (-1 < sVar1) {
        uVar2 = mainGetBit(0x507);
        if ((((uVar2 == 0) || (uVar2 = mainGetBit(0x508), uVar2 == 0)) ||
            (uVar2 = mainGetBit(0x509), uVar2 == 0)) || (uVar2 = mainGetBit(0x50a), uVar2 == 0)) {
          uVar2 = mainGetBit(0x4eb);
          if (uVar2 != 0) {
            *(undefined2 *)(puVar4 + 10) = 2;
            *(undefined2 *)(puVar4 + 0x10) = 100;
          }
        }
        else {
          uVar2 = mainGetBit(0x4ee);
          if (uVar2 == 0) {
                    /* {@symbol 800d022c} */
            (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
            mainSetBits(0x4ee,1);
          }
          loadLfxAction(this,this,0x176);
          loadLfxAction(this,this,0x177);
          *(undefined2 *)(puVar4 + 10) = 2;
          *(undefined2 *)(puVar4 + 0x10) = 100;
        }
      }
    }
    else if (sVar1 == 4) {
      if ((pOVar3->pos).y + 60.0 <= (this->pos).pos.y) {
        *(undefined2 *)(puVar4 + 10) = 2;
        *(undefined2 *)(puVar4 + 0x10) = 100;
        FUN_80068a9c((uint)this,8);
        objDistObj2ObjXZ(this,param2);
      }
      else {
        (this->pos).pos.y = (this->pos).pos.y + timeDelta;
        if ((pOVar3->pos).y + 60.0 <= (this->pos).pos.y) {
          (this->pos).pos.y = (pOVar3->pos).y + 60.0;
          *(undefined2 *)(puVar4 + 10) = 2;
          *(undefined2 *)(puVar4 + 0x10) = 100;
          FUN_80068a9c((uint)this,8);
        }
        objDistObj2ObjXZ(this,param2);
      }
    }
    else if (sVar1 < 4) {
      if ((this->pos).pos.y <= (pOVar3->pos).y - 260.0) {
        FUN_80068a9c((uint)this,8);
        objDistObj2ObjXZ(this,param2);
        *(undefined2 *)(puVar4 + 10) = 2;
        *(undefined2 *)(puVar4 + 0x10) = 100;
      }
      else {
        (this->pos).pos.y = (this->pos).pos.y - timeDelta;
        if ((this->pos).pos.y <= (pOVar3->pos).y - 260.0) {
          (this->pos).pos.y = (pOVar3->pos).y - 260.0;
          *(undefined2 *)(puVar4 + 10) = 2;
          FUN_80068a9c((uint)this,8);
          *(undefined2 *)(puVar4 + 0x10) = 100;
        }
        objDistObj2ObjXZ(this,param2);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void lift1_hitDetect(ObjInstance *this) { //8028D384
  return;
}


/* Library Function - Single Match
    lift1_func06
   
   Library: KioskDefault 0 0 */

void lift1_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //8028D388
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    bVar1 = checkSomeDebugFlags_8017c4f8();
    if ((bVar1) && (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)*pfVar2,25.0,(Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
    }
  }
  return;
}


/* Library Function - Single Match
    lift1_func07
   
   Library: KioskDefault 0 0 */

void lift1_free(ObjInstance *this,int param2) { //8028D434
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  loadLfxAction(this,this,0);
  return;
}


undefined4 lift1_func08(ObjInstance *this) { //8028D490
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int lift1_getExtraSize(void) { //8028D498
  return 0x14;
}

