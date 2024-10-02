
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void grenade_initialise(undefined4 param) { //801CC6A4
  return;
}


/* @description Called when DLL is unloaded */

void grenade_release(void) { //801CC6A8
  return;
}


/* Library Function - Single Match
    dll_ED_func03
   
   Library: KioskDefault 0 0 */

void grenade_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //801CC6AC
  short sVar1;
  int iVar2;
  undefined param3;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  pOVar3 = this->def;
  if (*(char *)((int)&pOVar3[1].objType + 1) == '\0') {
    param3 = 1;
  }
  else {
    param3 = 3;
  }
  objHitFn_80089074(this,0xe,param3,0);
  *(float *)(puVar4 + 0x274) =
       (float)((double)CONCAT44(0x43300000,(int)(short)this->hitstate->field16_0x52 ^ 0x80000000) -
              4503601774854144.0);
  iVar2 = randInt(600,900);
  *(short *)(puVar4 + 0x294) = (short)iVar2;
  iVar2 = randInt(-600,600);
  *(short *)(puVar4 + 0x296) = (short)iVar2;
  if (*(char *)((int)&pOVar3[1].objType + 1) == '\x01') {
    loadLfxAction(this,this,0x203);
  }
  else if (*(char *)((int)&pOVar3[1].objType + 1) == '\x02') {
    loadLfxAction(this,this,0x204);
  }
  else {
    loadLfxAction(this,this,0x201);
  }
  sVar1._0_1_ = pOVar3[1].allocatedSize;
  sVar1._1_1_ = pOVar3[1].mapStates1;
  if (sVar1 != 0) {
    puVar4[0x2a0] = puVar4[0x2a0] | 4;
  }
  objHitFn_80089354(this,2);
  return;
}


/* Library Function - Single Match
    dll_ED_func04
   
   Library: KioskDefault 0 0 */

void grenade_update(ObjInstance *this) { //801CC7EC
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float local_5c;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  longlong local_40;
  double local_38;
  
  _savefpr_29();
  puVar5 = this->state;
  if (*(short *)(puVar5 + 0x29c) == 0) {
    local_4c = 0.0;
    local_48 = 0.0;
    local_44 = 0.0;
    local_38 = (double)CONCAT44(0x43300000,
                                (int)*(char *)((int)&this->def[1].objType + 1) ^ 0x80000000);
    local_50 = (float)(local_38 - 4503601774854144.0);
    if ((puVar5[0x2a0] & 1) == 0) {
      *(float *)(puVar5 + 0x268) = (this->pos).pos.x;
      *(float *)(puVar5 + 0x26c) = (this->pos).pos.y;
      *(float *)(puVar5 + 0x270) = (this->pos).pos.z;
      puVar5[0x2a0] = puVar5[0x2a0] | 1;
    }
    if (*(short *)(puVar5 + 0x29a) == 0) {
      if (this->hitstate->field54_0x9d != 0) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x5d,0x7f,"grenade.c",(int *)0xd9);
        *(undefined2 *)(puVar5 + 0x29c) = 400;
        (this->vel).x = 0.0;
        (this->vel).y = 0.0;
        (this->vel).z = 0.0;
      }
      (this->oldPos).x = (this->pos).pos.x;
      (this->oldPos).y = (this->pos).pos.y;
      (this->oldPos).z = (this->pos).pos.z;
      (this->pos).rotation.x =
           (this->pos).rotation.x + *(short *)(puVar5 + 0x296) * (ushort)framesThisStep;
      (this->pos).rotation.z =
           (this->pos).rotation.z + *(short *)(puVar5 + 0x294) * (ushort)framesThisStep;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x521,0,1,0xffffffff,0);
      iVar4 = randInt(0,1);
      if (iVar4 != 0) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x522,0,&DAT_00080001,0xffffffff,0);
      }
      sVar1 = *(short *)(puVar5 + 0x298);
      uVar2 = (ushort)framesThisStep;
      *(ushort *)(puVar5 + 0x298) = sVar1 - uVar2;
      if ((short)(sVar1 - uVar2) < 1) {
        *(undefined2 *)(puVar5 + 0x298) = 0x32;
      }
      *(float *)(puVar5 + 0x268) = (this->vel).x * timeDelta + *(float *)(puVar5 + 0x268);
      *(float *)(puVar5 + 0x26c) = (this->vel).y * timeDelta + *(float *)(puVar5 + 0x26c);
      *(float *)(puVar5 + 0x270) = (this->vel).z * timeDelta + *(float *)(puVar5 + 0x270);
      local_50 = 1.0;
      dVar8 = (double)(((this->oldPos).x - *(float *)(puVar5 + 0x268)) / 5.0);
      dVar7 = (double)(((this->oldPos).y - *(float *)(puVar5 + 0x26c)) / 5.0);
      dVar6 = (double)(((this->oldPos).z - *(float *)(puVar5 + 0x270)) / 5.0);
      local_58 = 1;
      local_56 = 0;
      local_54 = 0;
      for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
        local_4c = (float)((double)local_4c + dVar8);
        local_48 = (float)((double)local_48 + dVar7);
        local_44 = (float)((double)local_44 + dVar6);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x521,&local_58,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x523,&local_58,1,0xffffffff,0);
      }
      if (-10.0 < (this->vel).y) {
        (this->vel).y = timeDelta * -0.03 + (this->vel).y;
      }
      *(ushort *)(puVar5 + 0x29e) = *(short *)(puVar5 + 0x29e) + (ushort)framesThisStep * 0x5dc;
      if ((puVar5[0x2a0] & 4) != 0) {
        *(float *)(puVar5 + 0x26c) = -(timeDelta * 2.0 - *(float *)(puVar5 + 0x26c));
        iVar4 = FUN_800ba478((double)*(float *)(puVar5 + 0x268),(double)*(float *)(puVar5 + 0x26c),
                             (double)*(float *)(puVar5 + 0x270),(int)this,&local_5c,0);
        if (((iVar4 == 0) && (local_5c = local_5c - 10.0, local_5c < 0.0)) && (-15.0 < local_5c)) {
          *(float *)(puVar5 + 0x26c) = *(float *)(puVar5 + 0x26c) - local_5c;
        }
      }
      (this->pos).pos.x = *(float *)(puVar5 + 0x268);
      (this->pos).pos.y = *(float *)(puVar5 + 0x26c);
      (this->pos).pos.z = *(float *)(puVar5 + 0x270);
      if (*(short *)(puVar5 + 0x29a) == 0) {
        iVar4 = this->field76_0xf4 - (uint)framesThisStep;
        this->field76_0xf4 = iVar4;
        if (iVar4 < 0) {
          *(undefined2 *)(puVar5 + 0x29c) = 10;
        }
      }
    }
    else {
      if ((puVar5[0x2a0] & 2) == 0) {
        loadLfxAction(this,this,1);
        puVar5[0x2a0] = puVar5[0x2a0] | 2;
      }
      (this->vel).x = 0.0;
      (this->vel).y = 0.0;
      (this->vel).z = 0.0;
      *(float *)(puVar5 + 0x274) = *(float *)(puVar5 + 0x274) + timeDelta;
      local_38 = (double)(longlong)(int)*(float *)(puVar5 + 0x274);
      objHitFn_80089354(this,(short)(int)*(float *)(puVar5 + 0x274));
      local_40 = (longlong)(int)(timeDelta * 2.0);
      *(short *)(puVar5 + 0x29a) = *(short *)(puVar5 + 0x29a) - (short)(int)(timeDelta * 2.0);
      if (*(short *)(puVar5 + 0x29a) < 1) {
        Object_objFreeObject(this);
      }
      enableCameraYOffset();
    }
  }
  else {
    local_38 = (double)(longlong)(int)timeDelta;
    *(short *)(puVar5 + 0x29c) = *(short *)(puVar5 + 0x29c) - (short)(int)timeDelta;
    uVar3 = (uint)*(short *)(puVar5 + 0x29c);
    if (uVar3 == (((int)uVar3 >> 2) + (uint)((int)uVar3 < 0 && (uVar3 & 3) != 0)) * 4) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x527,0,2,0xffffffff,0);
    }
    local_38 = (double)CONCAT44(0x43300000,400U - (int)*(short *)(puVar5 + 0x29c) ^ 0x80000000);
    *(float *)(puVar5 + 0x278) = (float)(local_38 - 4503601774854144.0) / 600.0 + 0.25;
    if (1.0 <= *(float *)(puVar5 + 0x278)) {
      *(float *)(puVar5 + 0x278) = 1.0;
    }
    audioTryStartSfx((int *)this,0xc0,0x79,0x7f,"grenade.c",0xa2);
    if (*(short *)(puVar5 + 0x29c) < 1) {
      FUN_80068a9c((uint)this,0x7f);
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x163,0x7f,"grenade.c",(int *)0xa6);
      *(undefined2 *)(puVar5 + 0x29a) = 0x28;
      *(undefined2 *)(puVar5 + 0x29c) = 0;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x528,0,2,0xffffffff,0);
      FUN_8006ae50(2.0);
    }
  }
  _restfpr_29();
  return;
}


/* Library Function - Single Match
    dll_ED_func05
   
   Library: KioskDefault 0 0 */

void grenade_hitDetect(ObjInstance *this) { //801CCE20
  undefined *puVar1;
  
  puVar1 = this->state;
  if (((*(short *)(puVar1 + 0x29a) == 0) && (*(short *)(puVar1 + 0x29c) == 0)) &&
     (this->hitstate->field13_0x48 != 0)) {
    *(undefined2 *)(puVar1 + 0x29a) = 0x32;
    FUN_80068a9c((uint)this,0x7f);
  }
  return;
}


/* Library Function - Single Match
    dll_ED_func06
   
   Library: KioskDefault 0 0 */

void grenade_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //801CCED8
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (*(short *)(this->state + 0x29a) == 0) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_ED_func07
   
   Library: KioskDefault 0 0 */

void grenade_free(ObjInstance *this,int param2) { //801CCF3C
  ObjInstance *pOVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  if ((puVar2[0x2a0] & 2) == 0) {
    loadLfxAction(this,this,1);
    puVar2[0x2a0] = puVar2[0x2a0] | 2;
  }
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  mainSetBits(0x77a,0);
  mainSetBits(0x77b,0);
  mainSetBits(0x77c,0);
  mainSetBits(0x77d,0);
  pOVar1 = Object_objGetMain();
  FUN_801a7b7c((int)pOVar1,0x14);
  return;
}


undefined4 grenade_func08(ObjInstance *this) { //801CD008
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int grenade_getExtraSize(void) { //801CD010
  return 0x2a4;
}

