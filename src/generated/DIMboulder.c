
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMboulder_initialise(undefined4 param) { //80227958
  return;
}


/* @description Called when DLL is unloaded */

void DIMboulder_release(void) { //8022795C
  return;
}


/* Library Function - Single Match
    dll_207_func03
   
   Library: KioskDefault 0 0 */

void DIMboulder_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80227960
  uint uVar1;
  float *pfVar2;
  
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  pfVar2 = (float *)this->state;
  if (this->hitstate != (HitState *)0x0) {
    this->hitstate->field21_0x5b = 0;
  }
  *pfVar2 = 1.0;
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
  }
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  uVar1 = mainGetBit(0x4ce);
  *(char *)((int)pfVar2 + 7) = (char)uVar1;
  if (*(char *)((int)pfVar2 + 7) == '\x03') {
    *(undefined *)((int)pfVar2 + 6) = 2;
  }
  return;
}


/* Library Function - Single Match
    dll_207_func04
   
   Library: KioskDefault 0 0 */

void DIMboulder_update(ObjInstance *this) { //80227A0C
  float fVar1;
  u8 uVar2;
  int iVar3;
  N64Button NVar5;
  uint uVar4;
  undefined uVar6;
  float *pfVar7;
  double dVar8;
  uint auStack_11c [6];
  float local_104;
  float local_100;
  float local_fc;
  float local_c4 [4];
  undefined local_b4;
  undefined local_b0;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  longlong local_68;
  undefined4 local_60;
  uint uStack_5c;
  longlong local_58;
  double local_50;
  
  _savefpr_26();
  fVar1 = timeDelta;
  uVar2 = framesThisStep;
  pfVar7 = (float *)this->state;
  if (*(char *)((int)pfVar7 + 6) == '\0') {
    iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if ((iVar3 == 5) || (NVar5 = n64GetEnabledButtonsHeld(1), (NVar5 & N64_BUTTON_A) != 0)) {
      *(undefined *)((int)pfVar7 + 6) = 1;
      (this->vel).x = *(float *)(&DAT_803185b8 + (uint)*(byte *)((int)pfVar7 + 7) * 0xc);
      (this->vel).y = *(float *)(&DAT_803185bc + (uint)*(byte *)((int)pfVar7 + 7) * 0xc);
      (this->vel).z = *(float *)(&DAT_803185c0 + (uint)*(byte *)((int)pfVar7 + 7) * 0xc);
      *(char *)((int)pfVar7 + 7) = *(char *)((int)pfVar7 + 7) + '\x01';
      mainSetBits(0x4ce,(uint)*(byte *)((int)pfVar7 + 7));
    }
  }
  else if (*(char *)((int)pfVar7 + 6) != '\x02') {
    (this->vel).y = -(timeDelta * 0.09 - (this->vel).y);
    objMove((double)((this->vel).x * fVar1),(double)((this->vel).y * fVar1),
            (double)((this->vel).z * fVar1),this);
    local_74 = (this->oldPos).x - 80.0;
    local_70 = (this->oldPos).y - 80.0;
    local_6c = (this->oldPos).z - 80.0;
    local_80 = (this->pos).pos.x + 80.0;
    local_7c = (this->pos).pos.y + 80.0;
    local_78 = (this->pos).pos.z + 80.0;
    local_c4[0] = 55.0;
    local_b4 = 0xff;
    local_b0 = 5;
    mathFn_8006961c(auStack_11c,&local_74,&local_80,local_c4,1);
    pListFn_800b50cc((int)this,(int *)auStack_11c,0);
    uVar4 = FUN_800b6f6c((int)this,(int)&this->oldPos,(int)&(this->pos).pos,1,(int)&local_104,0);
    if (uVar4 != 0) {
      local_8c = -(this->vel).x;
      local_88 = -(this->vel).y;
      local_84 = -(this->vel).z;
      dVar8 = sqrt((double)(local_84 * local_84 + local_8c * local_8c + local_88 * local_88));
      if (dVar8 < 0.300000011920929) {
        dVar8 = 0.0;
        local_8c = 0.0;
        local_88 = 0.0;
        local_84 = 0.0;
        if (*(char *)((int)pfVar7 + 7) == '\x03') {
          uVar6 = 2;
        }
        else {
          uVar6 = 0;
        }
        *(undefined *)((int)pfVar7 + 6) = uVar6;
      }
      if (*(short *)(pfVar7 + 1) < 1) {
        local_50 = (double)(longlong)(int)((float)(dVar8 * 0.5) * 127.0);
        audioTryStartSfx((int *)this,1,0x40,0x7f,"DIMboulder.c",0xae);
        *(undefined2 *)(pfVar7 + 1) = 0x1e;
      }
      if (dVar8 != 0.0) {
        fVar1 = (float)(1.0 / dVar8);
        local_8c = local_8c * fVar1;
        local_88 = local_88 * fVar1;
        local_84 = local_84 * fVar1;
      }
      local_98 = local_104;
      local_94 = local_100;
      local_90 = local_fc;
      fVar1 = (local_84 * local_fc + local_8c * local_104 + local_88 * local_100) * 2.0;
      (this->vel).x = local_104 * fVar1;
      (this->vel).y = local_100 * fVar1;
      (this->vel).z = local_fc * fVar1;
      (this->vel).x = (this->vel).x - local_8c;
      (this->vel).y = (this->vel).y - local_88;
      (this->vel).z = (this->vel).z - local_84;
      (this->vel).x = (this->vel).x * (float)(dVar8 * 0.699999988079071);
      (this->vel).y = (this->vel).y * (float)(dVar8 * 0.5);
      (this->vel).z = (this->vel).z * (float)(dVar8 * 0.699999988079071);
    }
    if (0 < *(short *)(pfVar7 + 1)) {
      *(ushort *)(pfVar7 + 1) = *(short *)(pfVar7 + 1) - (ushort)uVar2;
    }
    fVar1 = (this->vel).x;
    local_50 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000);
    iVar3 = (int)-(-(this->vel).z * 1000.0 - (float)(local_50 - 4503601774854144.0));
    local_58 = (longlong)iVar3;
    (this->pos).rotation.y = (short)iVar3;
    uStack_5c = (int)(this->pos).rotation.z ^ 0x80000000;
    local_60 = 0x43300000;
    iVar3 = (int)-(fVar1 * 1000.0 -
                  (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0));
    local_68 = (longlong)iVar3;
    (this->pos).rotation.z = (short)iVar3;
    (this->pos).scale = this->data->scale * *pfVar7;
  }
  _restfpr_26();
  return;
}


/* @description Override hit detection */

void DIMboulder_hitDetect(ObjInstance *this) { //80227E8C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIMboulder_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80227E90
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

void DIMboulder_free(ObjInstance *this,int param2) { //80227EEC
  return;
}


undefined4 DIMboulder_func08(ObjInstance *this) { //80227EF0
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int DIMboulder_getExtraSize(void) { //80227EF8
  return 8;
}

