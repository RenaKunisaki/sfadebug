
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SBpropeller_initialise(undefined4 param) { //80261E44
  return;
}


/* @description Called when DLL is unloaded */

void SBpropeller_release(void) { //80261E48
  return;
}


/* Library Function - Single Match
    dll_22A_func03
   
   Library: KioskDefault 0 0 */

void SBpropeller_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80261E4C
  float *pfVar1;
  
  pfVar1 = (float *)this->state;
  *pfVar1 = 1.0;
  pfVar1[1] = 2.242078e-42;
  return;
}


/* Library Function - Single Match
    dll_22A_func04
   
   Library: KioskDefault 0 0 */

void SBpropeller_update(ObjInstance *this) { //80261E74
  bool bVar3;
  int iVar1;
  ObjInstance *pOVar2;
  int iVar4;
  float *pfVar5;
  ObjInstance *local_3c;
  undefined4 local_38;
  uint uStack_34;
  
  pfVar5 = (float *)this->state;
  if (this->pMatrix != (ObjInstance *)0x0) {
    iVar4 = this->pMatrix->field76_0xf4;
    if (this->pMatrix->romdefno == WM_Galleon) {
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
      bVar3 = FUN_80068b20((int)this,0x40);
      if (bVar3) {
        *(char *)((int)pfVar5 + 0xb) = *(char *)((int)pfVar5 + 0xb) + '\x01';
        if (0x50 < *(byte *)((int)pfVar5 + 0xb)) {
          *(undefined *)((int)pfVar5 + 0xb) = 0x50;
        }
        FUN_800689dc(127.0,(int)this,0x40,*(byte *)((int)pfVar5 + 0xb));
      }
      else if (10 < iVar4) {
        audioTryStartSfx((int *)this,0x40,0x129,1,"propeller.c",0x74);
        *(undefined *)((int)pfVar5 + 0xb) = 1;
      }
    }
    else {
      iVar1 = (*(code *)this->pMatrix->dll->ptrs2->field9_0x24)(this->pMatrix);
      if (iVar4 < 4) {
        iVar4 = 0x708 - (int)pfVar5[1] >> 3;
        if (2 < iVar4) {
          iVar4 = 2;
        }
        if (iVar4 < -2) {
          iVar4 = -2;
        }
        pfVar5[1] = (float)((int)pfVar5[1] + iVar4 * (uint)framesThisStep);
        uStack_34 = (uint)pfVar5[1] ^ 0x80000000;
        local_38 = 0x43300000;
        *pfVar5 = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0) / 1600.0;
        if (*pfVar5 < 0.0) {
          *pfVar5 = -*pfVar5;
        }
        if (*pfVar5 < 0.2) {
          *pfVar5 = 0.2;
        }
      }
      else {
        FUN_80068a9c((uint)this,0x40);
      }
      this->field76_0xf4 = this->field76_0xf4 - (uint)framesThisStep;
      if ((int)this->field76_0xf4 < 0) {
        this->field76_0xf4 = 0;
      }
      iVar4 = FUN_800883e4((int)this,&local_3c,(int *)0x0,(uint *)0x0);
      if ((iVar4 == 0) && (this->hitstate->field13_0x48 != 0)) {
        iVar4 = 1;
        local_3c = (ObjInstance *)this->hitstate->field13_0x48;
      }
      if (((iVar4 != 0) && (this->field76_0xf4 == 0)) && (local_3c != (ObjInstance *)0x0)) {
        pOVar2 = Object_objGetMain();
        if (local_3c == pOVar2) {
          this->field76_0xf4 = 0x3c;
        }
        else {
          this->field76_0xf4 = 0x14;
          if ((this->pMatrix != (ObjInstance *)0x0) && ((iVar1 == 2 || (iVar1 == 5)))) {
            audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                                (double)(this->prevPos).z,0x1f7,0x7f,"propeller.c",
                                (int *)0xa4);
            pfVar5[1] = (float)((int)pfVar5[1] / 3);
            (*(code *)this->pMatrix->dll->ptrs2->setScale)(this->pMatrix);
            for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0xab,0,2,0xffffffff,0);
            }
          }
        }
      }
      if (this->field76_0xf4 == 0) {
        *(undefined *)((int)&this->hitstate->sizeX2 + 1) = 6;
        *(undefined *)&this->hitstate->flags_0x60 = 1;
        (this->hitstate->field12_0x3c).y = 2.242078e-44;
        (this->hitstate->field12_0x3c).z = 2.242078e-44;
      }
      else {
        this->hitstate->field_0x5d = 0;
      }
    }
    (this->pos).rotation.z = (this->pos).rotation.z + SUB42(pfVar5[1],0) * (ushort)framesThisStep;
  }
  return;
}


/* Library Function - Single Match
    dll_22A_func05
   
   Library: KioskDefault 0 0 */

void SBpropeller_hitDetect(ObjInstance *this) { //80262200
  *(ushort *)(this->state + 8) = *(short *)(this->state + 8) + (ushort)framesThisStep * 0x4b0;
  return;
}


/* Library Function - Single Match
    dll_22A_func06
   
   Library: KioskDefault 0 0 */

void SBpropeller_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //8026222C
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  ObjDef *pOVar3;
  ObjInstance *pOVar4;
  double dVar5;
  double local_28;
  
  pOVar3 = this->def;
  puVar2 = this->state;
  (this->pos).pos.x = (pOVar3->pos).x;
  (this->pos).pos.y = (pOVar3->pos).y;
  (this->pos).pos.z = (pOVar3->pos).z;
  if ((shouldRender) &&
     ((this->pMatrix == (ObjInstance *)0x0 || (this->pMatrix->field76_0xf4 != 10)))) {
    if ((this->pMatrix != (ObjInstance *)0x0) &&
       ((this->pMatrix->romdefno == SB_Galleon &&
        (pOVar4 = this->pMatrix, pOVar4 != (ObjInstance *)0x0)))) {
      local_28 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar2 + 8) ^ 0x80000000);
      dVar5 = (double)distanceFn_80293e80((double)(((float)(local_28 - 4503601774854144.0) *
                                                   3.141593) / 32767.0));
      dVar5 = (double)((float)(1.0 - dVar5) * 255.0);
      if (0.0 <= dVar5) {
        if (255.0 < dVar5) {
          dVar5 = 255.0;
        }
      }
      else {
        dVar5 = 0.0;
      }
      iVar1 = (*(code *)pOVar4->dll->ptrs2->field9_0x24)(pOVar4);
      if (iVar1 == 2) {
        FUN_80096afc(0xff,(ushort)(int)dVar5 & 0xff,(ushort)(int)dVar5 & 0xff);
      }
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void SBpropeller_free(ObjInstance *this,int param2) { //802623B0
  return;
}


undefined4 SBpropeller_func08(ObjInstance *this) { //802623B4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SBpropeller_getExtraSize(void) { //802623BC
  return 0xc;
}

