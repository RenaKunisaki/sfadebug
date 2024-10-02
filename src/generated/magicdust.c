
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void magicGem_initialise(undefined4 param) { //801D3CF0
  return;
}


/* @description Called when DLL is unloaded */

void magicGem_release(void) { //801D3CF4
  return;
}


/* Library Function - Single Match
    magicGem_func03
   
   Library: KioskDefault 0 0 */

void magicGem_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //801D3CF8
  ObjDefEnum OVar1;
  uint uVar2;
  ObjInstance *pOVar3;
  undefined *puVar4;
  double dVar5;
  double dVar6;
  undefined local_44 [4];
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  puVar4 = this->state;
  local_44[0] = 3;
  uVar2 = randInt(0,0xffff);
  uStack_24 = randInt(0x27,0x2c);
  uStack_24 = uStack_24 ^ 0x80000000;
  local_28 = 0x43300000;
  dVar6 = (double)((float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) / 100.0);
  uStack_2c = uVar2 ^ 0x80000000;
  local_30 = 0x43300000;
  dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_2c) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  (this->vel).x = (float)(dVar6 * dVar5);
  uStack_34 = uVar2 ^ 0x80000000;
  local_38 = 0x43300000;
  dVar5 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_34) -
                                                   4503601774854144.0) * 3.141593) / 32767.0));
  (this->vel).z = (float)(dVar6 * dVar5);
  uStack_3c = randInt(0x28,0x32);
  uStack_3c = uStack_3c ^ 0x80000000;
  local_40 = 0x43300000;
  (this->vel).y = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) / 50.0;
  if (*(short *)((int)&objDef[1].id + 2) == 1) {
    puVar4[0x272] = puVar4[0x272] | 1;
    this->newOpacity = 1;
  }
  else if (*(short *)((int)&objDef[1].id + 2) == 2) {
    puVar4[0x272] = puVar4[0x272] | 1;
    this->newOpacity = 1;
    if (this->hitstate != (HitState *)0x0) {
      FUN_80088da4((int)this);
    }
    dVar5 = 120.0;
    if (true) {
      pOVar3 = Object_objGetMain();
      (this->vel).x = (float)((double)((pOVar3->pos).pos.x - (this->pos).pos.x) / dVar5);
      (this->vel).y = (float)((double)((pOVar3->pos).pos.y - (this->pos).pos.y) / dVar5);
      (this->vel).z = (float)((double)((pOVar3->pos).pos.z - (this->pos).pos.z) / dVar5);
    }
  }
  this->curModel = *(byte *)((int)&objDef[1].pos.y + 2);
  if (this->data->nModels <= (char)this->curModel) {
    this->curModel = 0;
  }
  if (this->shadow != (Shadow *)0x0) {
    (this->shadow->color).b = 100;
    (this->shadow->color).a = 0x96;
  }
  OVar1 = this->romdefno;
  if (OVar1 == MagicDustMi) {
    *(undefined2 *)(puVar4 + 0x26a) = 0x54e;
    *(undefined2 *)(puVar4 + 0x268) = 0x54a;
    *(undefined2 *)(puVar4 + 0x26c) = 0x150;
    *(undefined2 *)(puVar4 + 0x26e) = 0x5b1;
  }
  else {
    if ((short)OVar1 < 0x2cd) {
      if (OVar1 == MagicDustSm) {
        *(undefined2 *)(puVar4 + 0x26a) = 0x54d;
        *(undefined2 *)(puVar4 + 0x268) = 0x549;
        *(undefined2 *)(puVar4 + 0x26c) = 0x14f;
        *(undefined2 *)(puVar4 + 0x26e) = 0x5b0;
        goto LAB_801d3fc0;
      }
    }
    else if ((OVar1 != MagicDustHu) && ((short)OVar1 < 0x2cf)) {
      *(undefined2 *)(puVar4 + 0x26a) = 0x54f;
      *(undefined2 *)(puVar4 + 0x268) = 0x54b;
      *(undefined2 *)(puVar4 + 0x26c) = 0x151;
      *(undefined2 *)(puVar4 + 0x26e) = 0x5b2;
      goto LAB_801d3fc0;
    }
    *(undefined2 *)(puVar4 + 0x26a) = 0x550;
    *(undefined2 *)(puVar4 + 0x268) = 0x54c;
    *(undefined2 *)(puVar4 + 0x26c) = 0x152;
    *(undefined2 *)(puVar4 + 0x26e) = 0x5b3;
  }
LAB_801d3fc0:
  *(float *)(puVar4 + 0x260) = 7.0;
  if (((this->pos).flags & DontSave) != 0) {
                    /* {@symbol 8012ab10} */
    (**(code **)(*(int *)pDll1A + 4))(puVar4,0,&DAT_00040007,0);
                    /* {@symbol 8012abb0} */
    (**(code **)(*(int *)pDll1A + 0xc))(puVar4,1,&DAT_803113b0,puVar4 + 0x260,local_44);
                    /* {@symbol 8012b80c} */
    (**(code **)(*(int *)pDll1A + 0x20))(this,puVar4);
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  if ((puVar4[0x272] & 1) == 0) {
    *(float *)(puVar4 + 0x264) = 1800.0;
    puVar4[0x272] = puVar4[0x272] | 4;
  }
  else {
    *(float *)(puVar4 + 0x264) = 60.0;
  }
  return;
}


/* Library Function - Single Match
    magicGem_collect
   
   Library: KioskDefault 0 0 */

void magicGem_collect(ObjInstance *this) { //801D4094
  float fVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  ObjInstance *param2;
  int iVar5;
  uint uVar6;
  undefined *param3;
  double dVar7;
  double dVar8;
  undefined *local_6c;
  undefined local_68;
  char local_67 [3];
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  longlong local_40;
  
  _savefpr_28();
  param2 = Object_objGetMain();
  param3 = this->state;
  if ((param3[0x272] & 0x20) != 0) {
    while (iVar5 = FUN_80091100((int)this,(uint *)&local_6c,(uint *)0x0,(uint *)0x0), iVar5 != 0) {
      if (local_6c == &DAT_0007000b) {
        onMagicCollect((int)this,(int)param2,(int)param3);
        param3[0x272] = param3[0x272] & 0xdf;
      }
    }
    if ((param3[0x272] & 0x20) != 0) goto LAB_801d4974;
  }
  if ((param3[0x272] & 0x10) == 0) {
    dVar7 = (double)objDistSqObj2ObjXZ(this,param2);
    if (dVar7 < 250000.0) {
      param3[0x272] = param3[0x272] | 0x10;
      local_68 = 0;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))
                (this,*(undefined2 *)(param3 + 0x26a),0,&DAT_00010002,0xffffffff,&local_68);
      local_68 = 1;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))
                (this,*(undefined2 *)(param3 + 0x26a),0,&DAT_00010002,0xffffffff,&local_68);
      local_68 = 2;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))
                (this,*(undefined2 *)(param3 + 0x26a),0,&DAT_00010002,0xffffffff,&local_68);
    }
  }
  else {
    dVar7 = (double)objDistSqObj2ObjXZ(this,param2);
    if (250000.0 <= dVar7) {
      param3[0x272] = param3[0x272] & 0xef;
                    /* {@symbol 800dc2d8} */
      (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
    }
  }
  if ((param3[0x272] & 2) != 0) {
    (this->pos).rotation.x = (this->pos).rotation.x + (ushort)framesThisStep * 0x100;
    sVar3 = *(short *)(param3 + 0x270);
    uVar4 = (ushort)framesThisStep;
    *(ushort *)(param3 + 0x270) = sVar3 - uVar4;
    if ((short)(sVar3 - uVar4) < 0) {
      audioTryStartSfx((int *)this,1,0x86,0x7f,"magicdust.c",0x11c);
      iVar5 = randInt(0xf0,300);
      *(short *)(param3 + 0x270) = (short)iVar5;
    }
  }
  if (((this->pos).flags & DontSave) != 0) {
    if (this->parent != (ObjInstance *)0x0) {
      this->shadow->flags = this->shadow->flags | 0x1000;
                    /* {@symbol 8012b80c} */
      (**(code **)(*(int *)pDll1A + 0x20))(this,param3);
      goto LAB_801d4974;
    }
    this->shadow->flags = this->shadow->flags & 0xffffefff;
    param3[599] = 1;
    if ((param3[0x272] & 3) == 0) {
      (this->vel).x = (this->vel).x * 0.99;
      (this->vel).z = (this->vel).z * 0.99;
      (this->vel).y = -(timeDelta * 0.1 - (this->vel).y);
    }
    *(float *)(param3 + 0x264) = *(float *)(param3 + 0x264) - timeDelta;
    if ((param3[0x272] & 1) == 0) {
      if ((param3[0x272] & 4) == 0) {
        if (*(float *)(param3 + 0x264) <= 0.0) {
          if (((this->pos).flags & DontSave) == 0) {
            objFreeFn_80083b54(this);
            (this->pos).flags = (this->pos).flags | Invisible;
          }
          else {
            Object_objFreeObject(this);
          }
        }
        goto LAB_801d4974;
      }
      if (*(float *)(param3 + 0x264) <= 0.0) {
        param3[0x272] = param3[0x272] & 0xfb;
        param3[0x272] = param3[0x272] | 8;
        *(float *)(param3 + 0x264) = 180.0;
                    /* {@symbol 800dc2d8} */
        (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
        if (this->pMatrix == (ObjInstance *)0x0) {
          for (local_67[0] = '\x1e'; local_67[0] != '\0'; local_67[0] = local_67[0] + -1) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))
                      (this,*(undefined2 *)(param3 + 0x268),0,1,0xffffffff,local_67);
          }
        }
        this->newOpacity = 1;
        audioTryStartSfx((int *)this,1,0x49,0x7f,"magicdust.c",0x168);
      }
      objMove((double)((this->vel).x * timeDelta),(double)((this->vel).y * timeDelta),
              (double)((this->vel).z * timeDelta),this);
    }
    else {
      if (*(float *)(param3 + 0x264) <= 0.0) {
        param3[0x272] = param3[0x272] & 0xfe;
        param3[0x272] = param3[0x272] | 4;
        *(float *)(param3 + 0x264) = 1800.0;
        this->newOpacity = 0xff;
      }
      if (this->pMatrix == (ObjInstance *)0x0) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))
                  (this,*(undefined2 *)(param3 + 0x268),0,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))
                  (this,*(undefined2 *)(param3 + 0x268),0,1,0xffffffff,0);
      }
    }
    if ((param3[0x272] & 3) == 0) {
                    /* {@symbol 8012ac30} */
      (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,param3);
                    /* {@symbol 8012b0e4} */
      (**(code **)(*(int *)pDll1A + 0x14))(this,param3);
                    /* {@symbol 8012b170} */
      (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,param3);
      if (param3[0x25d] != '\0') {
        local_4c = -(this->vel).x;
        local_48 = -(this->vel).y;
        local_44 = -(this->vel).z;
        dVar7 = sqrt((double)(local_44 * local_44 + local_4c * local_4c + local_48 * local_48));
        if (0.5 < dVar7) {
          dVar8 = dVar7;
          if (2.0 < dVar7) {
            dVar8 = 2.0;
          }
          local_40 = (longlong)(int)(dVar8 * 32.0);
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x48,(byte)(int)(dVar8 * 32.0),
                              "magicdust.c",(int *)0x193);
        }
        if (dVar7 != 0.0) {
          fVar1 = (float)(1.0 / dVar7);
          local_4c = local_4c * fVar1;
          local_48 = local_48 * fVar1;
          local_44 = local_44 * fVar1;
        }
        local_64 = *(float *)(param3 + 0x68);
        local_60 = *(float *)(param3 + 0x6c);
        local_5c = *(float *)(param3 + 0x70);
        fVar1 = (local_44 * local_5c + local_4c * local_64 + local_48 * local_60) * 2.0;
        local_58 = local_64 * fVar1 - local_4c;
        local_54 = local_60 * fVar1 - local_48;
        local_50 = local_5c * fVar1 - local_44;
        if (local_60 < 0.707) {
          (this->vel).x = -(this->vel).x;
          (this->vel).z = -(this->vel).z;
          (this->vel).x = (this->vel).x * 0.85;
          (this->vel).z = (this->vel).z * 0.85;
        }
        else {
          (this->vel).y = -(this->vel).y;
          (this->vel).y = (this->vel).y * 0.85;
          cVar2 = param3[0x273];
          param3[0x273] = cVar2 + 1U;
          if (5 < (byte)(cVar2 + 1U)) {
            param3[0x272] = param3[0x272] | 2;
            (this->vel).x = 0.0;
            (this->vel).y = 0.0;
            (this->vel).z = 0.0;
          }
        }
      }
    }
  }
  fVar1 = (this->pos).pos.y - (param2->pos).pos.y;
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
  }
  if ((fVar1 < 20.0) &&
     (dVar7 = (double)objDistSqObj2ObjXZ(this,param2),
     dVar7 < (double)((*(float *)(param3 + 0x260) + 8.0) * (*(float *)(param3 + 0x260) + 8.0)))) {
    uVar6 = mainGetBit(0x90d);
    if (uVar6 == 0) {
                    /* {@symbol 800d1668} */
      (**(code **)(*(int *)pDll_checkpoint + 0x7c))((int)*(short *)(param3 + 0x26e),0,0);
      *(undefined2 *)(param3 + 0x274) = 0xffff;
      *(undefined2 *)(param3 + 0x276) = 0;
      *(float *)(param3 + 0x278) = 1.0;
      objSendMsg((int)param2,0x7000a,(uint)this,(uint)(param3 + 0x274));
      mainSetBits(0x90d,1);
      param3[0x272] = param3[0x272] | 0x20;
    }
    else {
      onMagicCollect((int)this,(int)param2,(int)param3);
    }
    this->newOpacity = 1;
                    /* {@symbol 800dc2d8} */
    (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
    for (local_67[0] = '\n'; local_67[0] != '\0'; local_67[0] = local_67[0] + -1) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,*(undefined2 *)(param3 + 0x268),0,1,0xffffffff,0);
    }
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,*(ushort *)(param3 + 0x26c),0x7f,
                        "magicdust.c",(int *)0x1d8);
  }
LAB_801d4974:
  _restfpr_28();
  return;
}


/* @description Override hit detection */

void magicGem_hitDetect(ObjInstance *this) { //801D4990
  return;
}


/* Library Function - Single Match
    magicGem_func06
   
   Library: KioskDefault 0 0 */

void magicGem_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //801D4994
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->parent == (ObjInstance *)0x0)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void magicGem_free(ObjInstance *this,int param2) { //801D4A04
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 magicGem_func08(ObjInstance *this) { //801D4A3C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int magicGem_getExtraSize(void) { //801D4A44
  return 0x27c;
}

