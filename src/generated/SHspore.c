
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SHspore_initialise(undefined4 param) { //80251258
  return;
}


/* @description Called when DLL is unloaded */

void SHspore_release(void) { //8025125C
  return;
}


/* Library Function - Single Match
    dll_1E6_func03
   
   Library: KioskDefault 0 0 */

void SHspore_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //80251260
  int iVar1;
  undefined *puVar2;
  undefined local_1c [4];
  undefined4 local_18;
  uint uStack_14;
  
  puVar2 = this->state;
  local_1c[0] = 5;
  *(float *)(puVar2 + 0x260) = 1500.0;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  (this->vel).y = 2.0;
  FUN_80088da4((int)this);
  iVar1 = randInt(0,0xffff);
  *(short *)(puVar2 + 0x298) = (short)iVar1;
  uStack_14 = randInt(0,1000);
  uStack_14 = uStack_14 ^ 0x80000000;
  local_18 = 0x43300000;
  *(float *)(puVar2 + 0x26c) =
       (float)((double)CONCAT44(0x43300000,uStack_14) - 4503601774854144.0) / 1000.0;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(puVar2,0,&DAT_00040002,1);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(puVar2,1,&PTR_8031a948,&DAT_80397e58,local_1c);
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3f1,0,4,0xffffffff,0);
  return;
}


/* Library Function - Single Match
    dll_1E6_func04
   
   Library: KioskDefault 0 0 */

void SHspore_update(ObjInstance *this) { //80251388
  float fVar1;
  int iVar2;
  ObjInstance *pOVar3;
  ObjInstance *pOVar4;
  int iVar5;
  undefined *puVar6;
  
  puVar6 = this->state;
  if (*(float *)(puVar6 + 0x290) == 0.0) {
    *(float *)(puVar6 + 0x270) = *(float *)(puVar6 + 0x270) - timeDelta;
    if (*(float *)(puVar6 + 0x270) < 0.0) {
      *(float *)(puVar6 + 0x270) = 0.0;
    }
    *(float *)(puVar6 + 0x28c) = *(float *)(puVar6 + 0x28c) - timeDelta;
    if (*(float *)(puVar6 + 0x28c) < 0.0) {
      *(float *)(puVar6 + 0x28c) = 0.0;
    }
    (this->vel).y = timeDelta * -0.009 + (this->vel).y;
    if ((this->vel).y < -0.2) {
      (this->vel).y = -0.2;
    }
    if (0.0 < (this->vel).y) {
      (this->vel).y = (this->vel).y * 0.97;
    }
    if ((this->vel).y < 0.0) {
      FUN_80088d3c((int)this);
    }
    FUN_802517e4((int)this,(int)puVar6);
    iVar2 = randInt(0,100);
    if (iVar2 < 5) {
      if (*(float *)(puVar6 + 0x270) <= 0.0) {
        FUN_80251a8c((int)this,(int)puVar6);
      }
    }
    fVar1 = *(float *)(puVar6 + 0x284) - timeDelta;
    *(float *)(puVar6 + 0x284) = fVar1;
    if (0.0 < fVar1) {
      *(float *)(puVar6 + 0x268) =
           (*(float *)(puVar6 + 0x288) - *(float *)(puVar6 + 0x268)) * 0.01 * timeDelta +
           *(float *)(puVar6 + 0x268);
    }
    else {
      *(float *)(puVar6 + 0x27c) = *(float *)(puVar6 + 0x27c) * 0.97;
      *(float *)(puVar6 + 0x280) = *(float *)(puVar6 + 0x280) * 0.97;
      *(float *)(puVar6 + 0x284) = 0.0;
    }
    (this->vel).x =
         *(float *)(puVar6 + 0x27c) * *(float *)(puVar6 + 0x268) + *(float *)(puVar6 + 0x274);
    (this->vel).z =
         *(float *)(puVar6 + 0x280) * *(float *)(puVar6 + 0x268) + *(float *)(puVar6 + 0x278);
    objMove((double)((this->vel).x * timeDelta),(double)((this->vel).y * timeDelta),
            (double)((this->vel).z * timeDelta),this);
                    /* {@symbol 8012ac30} */
    (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,puVar6);
                    /* {@symbol 8012b0e4} */
    (**(code **)(*(int *)pDll1A + 0x14))(this,puVar6);
                    /* {@symbol 8012b170} */
    (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,puVar6);
    objHitFn_80089074(this,10,0,0);
    pOVar4 = (ObjInstance *)this->hitstate->field13_0x48;
    if (pOVar4 == (ObjInstance *)0x0) {
      fVar1 = *(float *)(puVar6 + 0x260) - timeDelta;
      *(float *)(puVar6 + 0x260) = fVar1;
      if ((fVar1 <= 0.0) || ((puVar6[0x25c] & 0x11) != 0)) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x4c,0x7f,"SHspore.c",(int *)0xda);
                    /* {@symbol 800dc1d4} */
        (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        for (iVar2 = 0; iVar2 < 0x14; iVar2 = iVar2 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3f3,0,4,0xffffffff,0);
        }
        *(float *)(puVar6 + 0x290) = 200.0;
        (this->pos).flags = (this->pos).flags | Invisible;
        FUN_80088da4((int)this);
      }
    }
    else {
      iVar2 = 0x14;
      pOVar3 = Object_objGetMain();
      if (pOVar4 == pOVar3) {
        mainIncBit(0x66c);
        iVar2 = 0;
      }
      if ((pOVar4->romdefno != BombPlant) && (pOVar4->romdefno != BombPlantSp)) {
        audioTryStartSfx((int *)this,1,0x4d,0x7f,"SHspore.c",0xc9);
                    /* {@symbol 800dc1d4} */
        (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3f3,0,4,0xffffffff,0);
        }
        *(float *)(puVar6 + 0x290) = 200.0;
        (this->pos).flags = (this->pos).flags | Invisible;
        FUN_80088da4((int)this);
      }
    }
  }
  else {
    (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * 0x40;
    *(float *)(puVar6 + 0x290) = *(float *)(puVar6 + 0x290) - timeDelta;
    if (*(float *)(puVar6 + 0x290) <= 0.0) {
      Object_objFreeObject(this);
    }
  }
  return;
}


/* @description Override hit detection */

void SHspore_hitDetect(ObjInstance *this) { //80251C50
  return;
}


/* @description Override render */

void SHspore_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //80251C54
  return;
}


/* @description Free object instance */

void SHspore_free(ObjInstance *this,int param2) { //80251C58
                    /* {@symbol 800dc1d4} */
  (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
  return;
}


undefined4 SHspore_func08(ObjInstance *this) { //80251C90
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SHspore_getExtraSize(void) { //80251C98
  return 0x29c;
}

