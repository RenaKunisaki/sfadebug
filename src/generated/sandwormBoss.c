
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void sandwormBoss_initialise(undefined4 param) { //8022077C
  return;
}


/* @description Called when DLL is unloaded */

void sandwormBoss_release(void) { //80220780
  return;
}


/* Library Function - Single Match
    dll_1B8_func03
   
   Library: KioskDefault 0 0 */

void sandwormBoss_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //80220784
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  (this->pos).flags = (this->pos).flags | Invisible;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  FUN_80088da4((int)this);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80221a64;
  Object_objAddObjectType(this,4);
  uVar1 = mainGetBit(0x3fb);
  if (uVar1 == 0) {
    uVar1 = mainGetBit(0x1eb);
    if (uVar1 == 0) {
      *puVar2 = 0;
                    /* {@symbol 8012e228} */
      (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,0xc,1);
    }
    else {
      uVar1 = mainGetBit(0x1ec);
      if (uVar1 == 0) {
        uVar1 = mainGetBit(0x22a);
        if (uVar1 == 0) {
          mainSetBits(0x1eb,0);
          mainSetBits(0x22a,1);
          *puVar2 = 0;
                    /* {@symbol 8012e228} */
          (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,0xc,1);
        }
        else {
          mainSetBits(0x1eb,0);
          mainSetBits(0x1ec,1);
          *puVar2 = 0;
                    /* {@symbol 8012e228} */
          (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,0xc,1);
        }
      }
      else {
        uVar1 = mainGetBit(0x22a);
        if (uVar1 == 0) {
          mainSetBits(0x1eb,0);
          mainSetBits(0x22a,1);
          *puVar2 = 0;
                    /* {@symbol 8012e228} */
          (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,0xc,1);
        }
        else {
          *puVar2 = 2;
        }
      }
    }
  }
  else {
    uVar1 = mainGetBit(0x3d4);
    if (uVar1 == 0) {
      *puVar2 = 3;
    }
    else {
      *puVar2 = 0xf;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1B8_func04
   
   Library: KioskDefault 0 0 */

void sandwormBoss_update(ObjInstance *this) { //80220970
  byte *pbVar1;
  
  pbVar1 = this->state;
  if (*pbVar1 < 3) {
    FUN_802209c4(this,pbVar1);
  }
  else {
    FUN_80220bc8(this,pbVar1);
  }
  return;
}


/* @description Override hit detection */

void sandwormBoss_hitDetect(ObjInstance *this) { //802216D8
  return;
}


/* Library Function - Single Match
    dll_1B8_func06
   
   Library: KioskDefault 0 0 */

void sandwormBoss_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802216DC
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined a;
  char *pcVar2;
  double dVar3;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined2 local_28;
  undefined local_26;
  undefined4 local_20;
  uint uStack_1c;
  double local_18;
  
  pcVar2 = this->state;
  local_28 = 0xffc0;
  local_26 = 0x96;
  if (shouldRender) {
    if (*pcVar2 == '\r') {
      *(float *)(pcVar2 + 0x1c) = timeDelta * 5.0 + *(float *)(pcVar2 + 0x1c);
      if (382.0 < *(float *)(pcVar2 + 0x1c)) {
        *(float *)(pcVar2 + 0x1c) = *(float *)(pcVar2 + 0x1c) - 382.0;
      }
      if (*(float *)(pcVar2 + 0x1c) < 191.5) {
        iVar1 = (int)*(float *)(pcVar2 + 0x1c);
        a = (undefined)iVar1;
      }
      else {
        iVar1 = (int)(382.0 - *(float *)(pcVar2 + 0x1c));
        a = (undefined)iVar1;
      }
      local_18 = (double)(longlong)iVar1;
      FUN_80096b14(200,0,0,a);
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (pcVar2[2] == '\0') {
      if (*pcVar2 == '\v') {
        objGetAttachPointWorldPos(this,2,&local_34,&local_30,&local_2c,FALSE);
      }
      else {
        objGetAttachPointWorldPos(this,0,&local_34,&local_30,&local_2c,FALSE);
      }
      local_40 = 0;
      local_3e = 0;
      local_3c = 0;
      local_3a = 0;
      local_30 = (this->pos).pos.y + 15.0;
      local_18 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
      dVar3 = (double)distanceFn_80293e80((double)(((float)(local_18 - 4503601774854144.0) *
                                                   3.141593) / 32767.0));
      local_34 = -(float)(dVar3 * 10.0 - (double)local_34);
      uStack_1c = (int)(this->pos).rotation.x ^ 0x80000000;
      local_20 = 0x43300000;
      dVar3 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,uStack_1c) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
      local_2c = -(float)(dVar3 * 10.0 - (double)local_2c);
      local_38 = 1.7;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x56,&local_40,&DAT_00200001,0xffffffff,&local_28)
      ;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x56,&local_40,&DAT_00200001,0xffffffff,&local_28)
      ;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x57,&local_40,&DAT_00200001,0xffffffff,&local_28)
      ;
      if (pcVar2[1] != '\0') {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))
                  (this,0x58,&local_40,&DAT_00200001,0xffffffff,&local_28);
        pcVar2[1] = pcVar2[1] + -1;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1B8_func07
   
   Library: KioskDefault 0 0 */

void sandwormBoss_free(ObjInstance *this,int param2) { //802219D8
                    /* {@symbol 8012e228} */
  (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,0xb,0);
                    /* {@symbol 8012e228} */
  (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,0xc,0);
  Object_removePlayerObj(this,4);
  return;
}


undefined4 sandwormBoss_func08(ObjInstance *this) { //80221A54
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int sandwormBoss_getExtraSize(void) { //80221A5C
  return 0x20;
}

