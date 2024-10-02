
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRhalolight_initialise(undefined4 param) { //802BE814
  return;
}


/* @description Called when DLL is unloaded */

void DRhalolight_release(void) { //802BE818
  return;
}


/* Library Function - Single Match
    dll_2C7_func03
   
   Library: KioskDefault 0 0 */

void DRhalolight_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802BE81C
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 10);
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  if (sVar2 == 0) {
    fVar1 = 1.0;
  }
  else {
    sVar3._0_1_ = objDef[1].allocatedSize;
    sVar3._1_1_ = objDef[1].mapStates1;
    fVar1 = (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - 4503601774854144.0) *
            0.015625;
  }
  *(float *)(puVar5 + 8) = fVar1;
  (this->pos).scale = this->data->scale * *(float *)(puVar5 + 8);
  puVar5[0xe] = *(undefined *)((int)&objDef[1].objType + 1);
  if (6 < (byte)puVar5[0xe]) {
    puVar5[0xe] = 6;
  }
  *(uint *)(puVar5 + 4) = (uint)(byte)puVar5[0xe] * 0x10 + -0x7fcdbd88;
  sVar4._0_1_ = objDef[1].bound;
  sVar4._1_1_ = objDef[1].cullDist;
  *(int *)(puVar5 + 0x14) = (int)sVar4;
  puVar5[0xf] = 1;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_2C7_func04
   
   Library: KioskDefault 0 0 */

void DRhalolight_update(ObjInstance *this) { //802BE8EC
  uint uVar1;
  ObjInstance *pOVar2;
  bool bVar3;
  int iVar4;
  undefined *puVar5;
  float local_1c [2];
  
  puVar5 = this->state;
  iVar4 = *(int *)(puVar5 + 4);
  if (((*(short *)&this->def[1].pos.x == -1) ||
      (uVar1 = mainGetBit((int)*(short *)&this->def[1].pos.x), uVar1 == 0)) &&
     ((*(int *)(puVar5 + 0x14) == -1 || (uVar1 = mainGetBit(*(int *)(puVar5 + 0x14)), uVar1 != 0))))
  {
    local_1c[0] = *(float *)(iVar4 + 8);
    pOVar2 = getSeqObj(0x38,this,local_1c);
    local_1c[0] = *(float *)(iVar4 + 8);
    if (*(int *)(iVar4 + 0xc) != -1) {
      bVar3 = FUN_80068b20((int)this,0x40);
      if (bVar3) {
        if ((pOVar2 == (ObjInstance *)0x0) && (puVar5[0xf] != '\0')) {
          FUN_80068a9c((uint)this,0x40);
        }
      }
      else if ((pOVar2 != (ObjInstance *)0x0) && (puVar5[0xf] != '\0')) {
        audioTryStartSfx((int *)this,0x40,(ushort)*(undefined4 *)(iVar4 + 0xc),0x7f,
                         "DRhalolight.c",0xb5);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void DRhalolight_hitDetect(ObjInstance *this) { //802BEA08
  return;
}


/* Library Function - Single Match
    dll_2C7_func06
   
   Library: KioskDefault 0 0 */

void DRhalolight_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802BEA0C
  short sVar1;
  uint uVar2;
  u32 uVar3;
  BOOL BVar4;
  int iVar5;
  undefined3 in_register_00000010;
  Gfx **param2_00;
  undefined3 in_register_00000014;
  undefined4 *param3_00;
  undefined3 in_register_00000018;
  undefined4 *param4_00;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  ObjDef *pOVar6;
  undefined *puVar7;
  double dVar8;
  double z;
  double y;
  double x;
  undefined auStack_70 [8];
  undefined4 local_68;
  float local_64;
  float local_60;
  float local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38 [2];
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  param4_00 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (undefined4 *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx **)CONCAT31(in_register_00000010,param2);
  _savefpr_28();
  puVar7 = this->state;
  pOVar6 = this->def;
  if (shouldRender == false) {
    *(undefined2 *)(puVar7 + 0xc) = 0;
  }
  else {
    sVar1._0_1_ = pOVar6[1].loadFlags;
    sVar1._1_1_ = pOVar6[1].mapStates2;
    if (sVar1 == 0) {
      objRenderCurrentModel(this,param2_00,param3_00,param4_00,param5_00);
    }
    if ((((*(short *)&pOVar6[1].pos.x == -1) ||
         (uVar2 = mainGetBit((int)*(short *)&pOVar6[1].pos.x), uVar2 == 0)) &&
        ((*(int *)(puVar7 + 0x14) == -1 || (uVar2 = mainGetBit(*(int *)(puVar7 + 0x14)), uVar2 != 0)
         ))) && (puVar7[0xf] != '\0')) {
      x = (double)((this->pos).pos.x - playerMapOffsetX);
      y = (double)(this->pos).pos.y;
      z = (double)((this->pos).pos.z - playerMapOffsetZ);
      vecMultByPerspectiveMtx(x,y,z,local_38,&local_3c,&local_40);
      viewportCoordsToPixel
                ((double)local_38[0],(double)local_3c,(double)local_40,(int *)&local_50,
                 (int *)&local_54,(int *)0x0);
      uVar3 = gxGetPixel_(local_50,local_54);
      FUN_8006abcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   &local_44,&local_48,&local_4c);
      dVar8 = (double)(-0.75 / local_40);
      vecMultByPerspectiveMtx
                ((double)(float)((double)local_44 * dVar8 + x),
                 (double)(float)((double)local_48 * dVar8 + y),
                 (double)(float)((double)local_4c * dVar8 + z),local_38,&local_3c,&local_40);
      viewportCoordsToPixel
                ((double)local_38[0],(double)local_3c,(double)local_40,(int *)0x0,(int *)0x0,
                 &local_58);
      if (*(short *)(puVar7 + 0xc) < 1) {
        BVar4 = isPixelOnScreen(local_50,local_54);
        if (((BVar4 != FALSE) && (0 < local_58)) && (local_58 < (int)uVar3)) {
          local_64 = 0.0;
          local_60 = 0.0;
          local_5c = 0.0;
          local_68 = *(undefined4 *)(puVar7 + 8);
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))
                    (this,**(undefined4 **)(puVar7 + 4),auStack_70,0x12,0xffffffff,0);
        }
        iVar5 = randInt(-10,10);
        *(short *)(puVar7 + 0xc) = (short)iVar5 + 0x3c;
      }
      else {
        *(ushort *)(puVar7 + 0xc) = *(short *)(puVar7 + 0xc) - (ushort)framesThisStep;
      }
    }
  }
  _restfpr_28();
  return;
}


/* Library Function - Single Match
    dll_2C7_func07
   
   Library: KioskDefault 0 0 */

void DRhalolight_free(ObjInstance *this,int param2) { //802BEC74
  if ((param2 == 0) && (*(ObjInstance **)this->state != (ObjInstance *)0x0)) {
    Object_objFreeObject(*(ObjInstance **)this->state);
  }
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 DRhalolight_func08(ObjInstance *this) { //802BECDC
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int DRhalolight_getExtraSize(void) { //802BECE4
  return 0x18;
}

