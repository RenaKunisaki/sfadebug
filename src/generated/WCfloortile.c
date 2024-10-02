
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WCfloortile_initialise(undefined4 param) { //802C68F0
  return;
}


/* @description Called when DLL is unloaded */

void WCfloortile_release(void) { //802C68F4
  return;
}


/* Library Function - Single Match
    dll_2E3_func03
   
   Library: KioskDefault 0 0 */

void WCfloortile_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802C68F8
  undefined *puVar1;
  
  puVar1 = this->state;
  (this->pos).rotation.x = -0x4000;
  this->hitstate->flags = this->hitstate->flags | 0x1800;
  puVar1[7] = puVar1[7] | 2;
  return;
}


/* Library Function - Single Match
    dll_2E3_func04
   
   Library: KioskDefault 0 0 */

void WCfloortile_update(ObjInstance *this) { //802C6934
  byte bVar1;
  float fVar2;
  uint uVar3;
  ObjDef *pOVar4;
  int iVar5;
  float *pfVar6;
  double local_30;
  
  _savefpr_30();
  pfVar6 = (float *)this->state;
  pOVar4 = this->def;
  uVar3 = mainGetBit(0x338);
  if (uVar3 != 0) {
    (this->pos).pos.y = (pOVar4->pos).y;
    *(undefined *)((int)pfVar6 + 6) = 3;
  }
  bVar1 = *(byte *)((int)pfVar6 + 6);
  if (bVar1 == 2) {
    this->newOpacity = 0;
    FUN_80088da4((int)this);
    *(byte *)((int)pfVar6 + 7) = *(byte *)((int)pfVar6 + 7) | 3;
  }
  else {
    if (bVar1 < 2) {
      if ((bVar1 != 0) && (true)) {
        *pfVar6 = *pfVar6 + timeDelta;
        if (120.0 < *pfVar6) {
          *(byte *)((int)pfVar6 + 7) = *(byte *)((int)pfVar6 + 7) | 3;
          *pfVar6 = 120.0;
          (this->vel).y = timeDelta * -0.1 + (this->vel).y;
        }
        *(short *)(pfVar6 + 1) = (short)(int)((*pfVar6 / 120.0) * 256.0);
        iVar5 = randInt(-(int)*(short *)(pfVar6 + 1),(int)*(short *)(pfVar6 + 1));
        (this->pos).rotation.y = (short)iVar5;
        iVar5 = randInt(-(int)*(short *)(pfVar6 + 1),(int)*(short *)(pfVar6 + 1));
        (this->pos).rotation.z = (short)iVar5;
        (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
        fVar2 = (pOVar4->pos).y - (this->pos).pos.y;
        if (50.0 <= fVar2) {
          if (fVar2 <= 150.0) {
            fVar2 = 1.0 - (fVar2 - 50.0) / 100.0;
            if (fVar2 <= 1.0) {
              if (fVar2 < 0.0) {
                fVar2 = 0.0;
              }
            }
            else {
              fVar2 = 1.0;
            }
            fVar2 = fVar2 * 255.0;
          }
          else {
            fVar2 = 0.0;
          }
        }
        else {
          fVar2 = 255.0;
        }
        this->newOpacity = (u8)(int)fVar2;
        if (this->newOpacity == 0) {
          *(undefined *)((int)pfVar6 + 6) = 2;
        }
        goto LAB_802c6c1c;
      }
    }
    else if (bVar1 < 4) {
      local_30 = (double)CONCAT44(0x43300000,(uint)this->newOpacity);
      fVar2 = timeDelta * 8.0 + (float)(local_30 - 4503599627370496.0);
      if (255.0 < fVar2) {
        fVar2 = 255.0;
      }
      this->newOpacity = (u8)(int)fVar2;
      FUN_80088d3c((int)this);
      goto LAB_802c6c1c;
    }
    if ((*(byte *)((int)pfVar6 + 7) & 4) == 0) {
      uVar3 = mainGetBit(0x265);
      if (uVar3 != 0) {
        *(byte *)((int)pfVar6 + 7) = *(byte *)((int)pfVar6 + 7) | 4;
      }
    }
    else if ('\0' < (char)this->field18_0x58->field144_0x10f) {
      for (iVar5 = 0; iVar5 < (char)this->field18_0x58->field144_0x10f; iVar5 = iVar5 + 1) {
        if (*(short *)(*(int *)((int)(this->field18_0x58->mtx + 2) + iVar5 * 4) + 0x46) == 0) {
          audioTryStartSfx((int *)this,1,0x57,0x7f,"WCfloortile.c",0x77);
          *(undefined *)((int)pfVar6 + 6) = 1;
          *pfVar6 = 0.0;
          (this->vel).y = 0.0;
        }
      }
    }
  }
LAB_802c6c1c:
  FUN_802c6cb8((int)this,(int)pfVar6);
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void WCfloortile_hitDetect(ObjInstance *this) { //802C6C44
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void WCfloortile_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802C6C48
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

void WCfloortile_free(ObjInstance *this,int param2) { //802C6CA4
  return;
}


undefined4 WCfloortile_func08(ObjInstance *this) { //802C6CA8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WCfloortile_getExtraSize(void) { //802C6CB0
  return 8;
}

