
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void exploder_initialise(undefined4 param) { //801FB290
  return;
}


/* @description Called when DLL is unloaded */

void exploder_release(void) { //801FB294
  return;
}


/* Library Function - Single Match
    exploder_func03
   
   Library: KioskDefault 0 0 */

void exploder_init(ObjInstance *param1,short *param2,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //801FB298
  uint uVar1;
  undefined uVar2;
  undefined *puVar3;
  undefined local_34 [36];
  
  local_34[0] = 5;
  param1->curModel = *(byte *)(param2 + 0xc);
  if (param1->data->nModels <= (char)param1->curModel) {
    param1->curModel = 0;
    printf("EXPLODER.c: modelno out of range romdefno=%d",(int)*param2);
  }
  puVar3 = param1->state;
  *(float *)(puVar3 + 0x264) = 0.0;
  *(float *)(puVar3 + 0x268) = 0.0;
  *(float *)(puVar3 + 0x26c) = 0.0;
  FUN_801fbbb0((undefined2 *)param1,(int)puVar3,(int)param2);
  uVar1 = mainGetBit((int)param2[0x1f]);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  puVar3[0x296] = uVar2;
  DAT_80399dc8 = 0;
  if ((*(byte *)(param2 + 0x1e) & 2) != 0) {
                    /* {@symbol 8012ab10} */
    (**(code **)(*(int *)pDll1A + 4))(puVar3,0,&DAT_00040002,1);
                    /* {@symbol 8012abb0} */
    (**(code **)(*(int *)pDll1A + 0xc))(puVar3,1,&PTR_80313768,&DAT_80397c50,local_34);
  }
  return;
}


/* Library Function - Single Match
    exploder_func04
   
   Library: KioskDefault 0 0 */

void exploder_update(ObjInstance *this) { //801FB3C4
  float fVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  ObjDef *pOVar6;
  undefined *puVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined auStack_bc [12];
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  double local_88;
  undefined4 local_80;
  uint uStack_7c;
  longlong local_78;
  double local_70;
  double local_68;
  undefined4 local_60;
  uint uStack_5c;
  
  _savefpr_24();
  puVar7 = this->state;
  if ((puVar7[0x296] & 2) == 0) {
    pOVar6 = this->def;
    if ((puVar7[0x296] & 1) == 0) {
      if (this->curModel == 0) {
        uVar4 = mainGetBit((int)*(short *)&pOVar6[2].pos.z);
        if ((uVar4 != 0) || (*(short *)&pOVar6[2].pos.z == -1)) {
          puVar7[0x296] = puVar7[0x296] | 1;
          mainSetBits((int)*(short *)((int)&pOVar6[2].pos.y + 2),1);
          DAT_80399dc8 = '\x01';
        }
      }
      else if (DAT_80399dc8 != '\0') {
        puVar7[0x296] = puVar7[0x296] | 1;
      }
      this->newOpacity = 0;
    }
    else {
      this->newOpacity = 0xff;
      sVar2 = *(short *)(puVar7 + 0x294);
      uVar3 = (ushort)framesThisStep;
      *(ushort *)(puVar7 + 0x294) = sVar2 + uVar3;
      if ((int)(uint)*(ushort *)&pOVar6[2].pos.x <= (int)(short)(sVar2 + uVar3)) {
        puVar7[0x296] = puVar7[0x296] | 2;
      }
      if (((int)(uint)*(ushort *)((int)&pOVar6[2].pos.x + 2) < (int)*(short *)(puVar7 + 0x294)) &&
         (*(short *)&pOVar6[2].pos.x != *(short *)((int)&pOVar6[2].pos.x + 2))) {
        local_68 = (double)CONCAT44(0x43300000,
                                    (uint)*(ushort *)&pOVar6[2].pos.x -
                                    (uint)*(ushort *)((int)&pOVar6[2].pos.x + 2) ^ 0x80000000);
        iVar5 = (int)((1.0 - (float)((double)CONCAT44(0x43300000,
                                                      (int)*(short *)(puVar7 + 0x294) -
                                                      (uint)*(ushort *)((int)&pOVar6[2].pos.x + 2) ^
                                                      0x80000000) - 4503601774854144.0) /
                             (float)(local_68 - 4503601774854144.0)) * 255.0);
        if (iVar5 < 0x100) {
          if (iVar5 < 0) {
            iVar5 = 0;
          }
        }
        else {
          iVar5 = 0xff;
        }
        this->newOpacity = (u8)iVar5;
      }
      (this->vel).x = timeDelta * *(float *)(puVar7 + 0x288) + (this->vel).x;
      (this->vel).y = timeDelta * *(float *)(puVar7 + 0x28c) + (this->vel).y;
      (this->vel).z = timeDelta * *(float *)(puVar7 + 0x290) + (this->vel).z;
      *(float *)(puVar7 + 0x270) =
           timeDelta * *(float *)(puVar7 + 0x27c) + *(float *)(puVar7 + 0x270);
      *(float *)(puVar7 + 0x274) =
           timeDelta * *(float *)(puVar7 + 0x280) + *(float *)(puVar7 + 0x274);
      *(float *)(puVar7 + 0x278) =
           timeDelta * *(float *)(puVar7 + 0x284) + *(float *)(puVar7 + 0x278);
      if ((puVar7[0x297] & 1) == 0) {
        if (0.0 < (this->vel).x) {
          (this->vel).x = 0.0;
        }
      }
      else if ((this->vel).x < 0.0) {
        (this->vel).x = 0.0;
      }
      if ((puVar7[0x297] & 2) == 0) {
        if (0.0 < (this->vel).z) {
          (this->vel).z = 0.0;
        }
      }
      else if ((this->vel).z < 0.0) {
        (this->vel).z = 0.0;
      }
      if ((puVar7[0x297] & 4) == 0) {
        if (0.0 < *(float *)(puVar7 + 0x270)) {
          *(float *)(puVar7 + 0x270) = 0.0;
        }
      }
      else if (*(float *)(puVar7 + 0x270) < 0.0) {
        *(float *)(puVar7 + 0x270) = 0.0;
      }
      if ((puVar7[0x297] & 8) == 0) {
        if (0.0 < *(float *)(puVar7 + 0x274)) {
          *(float *)(puVar7 + 0x274) = 0.0;
        }
      }
      else if (*(float *)(puVar7 + 0x274) < 0.0) {
        *(float *)(puVar7 + 0x274) = 0.0;
      }
      if ((puVar7[0x297] & 0x10) == 0) {
        if (0.0 < *(float *)(puVar7 + 0x278)) {
          *(float *)(puVar7 + 0x278) = 0.0;
        }
      }
      else if (*(float *)(puVar7 + 0x278) < 0.0) {
        *(float *)(puVar7 + 0x278) = 0.0;
      }
      (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
      (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
      (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
      local_70 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
      iVar5 = (int)(*(float *)(puVar7 + 0x270) * timeDelta + (float)(local_70 - 4503601774854144.0))
      ;
      local_68 = (double)(longlong)iVar5;
      (this->pos).rotation.x = (short)iVar5;
      uStack_5c = (int)(this->pos).rotation.y ^ 0x80000000;
      local_60 = 0x43300000;
      iVar5 = (int)(*(float *)(puVar7 + 0x274) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0));
      local_78 = (longlong)iVar5;
      (this->pos).rotation.y = (short)iVar5;
      uStack_7c = (int)(this->pos).rotation.z ^ 0x80000000;
      local_80 = 0x43300000;
      iVar5 = (int)(*(float *)(puVar7 + 0x278) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,uStack_7c) - 4503601774854144.0));
      local_88 = (double)(longlong)iVar5;
      (this->pos).rotation.z = (short)iVar5;
      if ((*(byte *)&pOVar6[2].pos.y & 2) != 0) {
                    /* {@symbol 8012ac30} */
        (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,puVar7);
                    /* {@symbol 8012b0e4} */
        (**(code **)(*(int *)pDll1A + 0x14))(this,puVar7);
                    /* {@symbol 8012b170} */
        (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,puVar7);
        if (puVar7[0x25d] != '\0') {
          local_98 = -(this->vel).x;
          local_94 = -(this->vel).y;
          local_90 = -(this->vel).z;
          dVar8 = sqrt((double)(local_90 * local_90 + local_98 * local_98 + local_94 * local_94));
          if (dVar8 != 0.0) {
            fVar1 = (float)(1.0 / dVar8);
            local_98 = local_98 * fVar1;
            local_94 = local_94 * fVar1;
            local_90 = local_90 * fVar1;
          }
          local_a4 = *(float *)(puVar7 + 0x68);
          local_a0 = *(float *)(puVar7 + 0x6c);
          local_9c = *(float *)(puVar7 + 0x70);
          fVar1 = (local_90 * local_9c + local_98 * local_a4 + local_94 * local_a0) * 2.0;
          (this->vel).x = local_a4 * fVar1;
          (this->vel).y = local_a0 * fVar1;
          (this->vel).z = local_9c * fVar1;
          (this->vel).x = (this->vel).x - local_98;
          (this->vel).y = (this->vel).y - local_94;
          (this->vel).z = (this->vel).z - local_90;
          (this->vel).y = (float)((double)(this->vel).y * dVar8);
          (this->vel).y = (this->vel).y * 0.75;
          (this->vel).x = (float)((double)(this->vel).x * dVar8);
          (this->vel).z = (float)((double)(this->vel).z * dVar8);
          (this->vel).x = (this->vel).x * 0.9;
          (this->vel).z = (this->vel).z * 0.9;
        }
      }
      if (((*(byte *)&pOVar6[2].pos.y & 4) != 0) && (this->newOpacity == 0xff)) {
        dVar10 = (double)((this->pos).pos.x - (this->oldPos).x);
        dVar9 = (double)((this->pos).pos.y - (this->oldPos).y);
        dVar8 = (double)((this->pos).pos.z - (this->oldPos).z);
        for (uVar4 = 0; (int)uVar4 < 2; uVar4 = uVar4 + 1) {
          local_88 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
          dVar11 = (double)((float)(local_88 - 4503601774854144.0) * 0.5);
          local_b0 = (float)(dVar10 * dVar11 + (double)(this->oldPos).x);
          local_ac = (float)(dVar9 * dVar11 + (double)(this->oldPos).y);
          local_a8 = (float)(dVar8 * dVar11 + (double)(this->oldPos).z);
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,1000,auStack_bc,&DAT_00200001,0xffffffff,0);
        }
      }
    }
  }
  else {
    if (((this->pos).flags & DontSave) != 0) {
      Object_objFreeObject(this);
    }
    this->newOpacity = 0;
  }
  _restfpr_24();
  return;
}


/* @description Override hit detection */

void exploder_hitDetect(ObjInstance *this) { //801FBAEC
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void exploder_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //801FBAF0
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

void exploder_free(ObjInstance *this,int param2) { //801FBB4C
                    /* {@symbol 800dc1d4} */
  (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
  return;
}


uint exploder_func08(ObjInstance *this) { //801FBB84
  return (uint)*(byte *)&this->def[1].objType << 0xb | 0x400;
}


/* @description Get extra size for object (size of State struct) */

int exploder_getExtraSize(void) { //801FBBA8
  return 0x298;
}

