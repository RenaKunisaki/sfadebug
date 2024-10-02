
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WCdial_initialise(undefined4 param) { //802C5578
  return;
}


/* @description Called when DLL is unloaded */

void WCdial_release(void) { //802C557C
  return;
}


/* Library Function - Single Match
    dll_2E1_func03
   
   Library: KioskDefault 0 0 */

void WCdial_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //802C5580
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->curModel = *(byte *)((int)&objDef[1].objType + 1);
  if (this->data->nModels <= (char)this->curModel) {
    this->curModel = 0;
  }
  if (this->curModel == 0) {
    puVar4[4] = &DAT_803981f8;
    puVar4[3] = &PTR_DAT_80324be8;
  }
  else {
    puVar4[4] = &DAT_80398200;
    puVar4[3] = &DAT_80324bf4;
  }
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    uVar2 = mainGetBit((int)*(short *)(puVar4[4] + iVar3 * 2));
    if (uVar2 != 0) {
      *(byte *)(puVar4 + 2) = *(byte *)(puVar4 + 2) | (byte)(1 << iVar3);
    }
  }
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    *(undefined *)(puVar4 + 2) = 7;
    *(byte *)((int)puVar4 + 9) = *(byte *)((int)puVar4 + 9) | 1;
  }
  if ((*(byte *)(puVar4 + 2) & 2) == 0) {
    if ((*(byte *)(puVar4 + 2) & 1) == 0) {
      *puVar4 = *(undefined4 *)puVar4[3];
    }
    else {
      *puVar4 = *(undefined4 *)(puVar4[3] + 4);
    }
  }
  else {
    *puVar4 = *(undefined4 *)(puVar4[3] + 8);
  }
  puVar4[1] = *puVar4;
  FUN_802c5978((int)this,*(byte *)(puVar4 + 2));
  return;
}


/* Library Function - Single Match
    dll_2E1_func04
   
   Library: KioskDefault 0 0 */

void WCdial_update(ObjInstance *this) { //802C56E4
  short sVar1;
  bool bVar2;
  uint uVar3;
  ObjDef *pOVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  
  pfVar7 = (float *)this->state;
  pOVar4 = this->def;
  if ((*(byte *)((int)pfVar7 + 9) & 1) != 0) {
    FUN_802c5978((int)this,*(byte *)(pfVar7 + 2));
    return;
  }
  *pfVar7 = timeDelta * (pfVar7[1] - *pfVar7) * 0.01 + *pfVar7;
  (this->pos).rotation.z =
       (short)(int)(timeDelta * *pfVar7 +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.z ^ 0x80000000) -
                          4503601774854144.0));
  iVar6 = 0;
  do {
    if (2 < iVar6) goto LAB_802c58c0;
    if ((((uint)*(byte *)(pfVar7 + 2) & 1 << iVar6) == 0) &&
       (uVar3 = mainGetBit((int)*(short *)((int)pfVar7[4] + iVar6 * 2)), uVar3 != 0)) {
      bVar2 = false;
      for (iVar5 = 0; iVar5 < iVar6; iVar5 = iVar5 + 1) {
        if (((uint)*(byte *)(pfVar7 + 2) & 1 << iVar5) == 0) {
          bVar2 = true;
          break;
        }
      }
      if (bVar2) {
        for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {
          mainSetBits((int)*(short *)((int)pfVar7[4] + iVar6 * 2),0);
        }
        audioStartSfx((int **)0x0,0x16b,0x7f,0x40,"WCdial.c",0x8d);
        *(undefined *)(pfVar7 + 2) = 0;
        pfVar7[1] = *(float *)pfVar7[3];
LAB_802c58c0:
        FUN_802c5978((int)this,*(byte *)(pfVar7 + 2));
        if (*(char *)(pfVar7 + 2) != '\a') {
          return;
        }
        sVar1._0_1_ = pOVar4[1].bound;
        sVar1._1_1_ = pOVar4[1].cullDist;
        mainSetBits((int)sVar1,1);
        *(byte *)((int)pfVar7 + 9) = *(byte *)((int)pfVar7 + 9) | 1;
        return;
      }
      audioStartSfx((int **)0x0,0x161,0x7f,0x40,"WCdial.c",0x92);
      *(byte *)(pfVar7 + 2) = *(byte *)(pfVar7 + 2) | (byte)(1 << iVar6);
      if (iVar6 == 0) {
        pfVar7[1] = *(float *)((int)pfVar7[3] + 4);
      }
      else if (iVar6 == 1) {
        pfVar7[1] = *(float *)((int)pfVar7[3] + 8);
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}


/* @description Override hit detection */

void WCdial_hitDetect(ObjInstance *this) { //802C5904
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void WCdial_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //802C5908
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

void WCdial_free(ObjInstance *this,int param2) { //802C5964
  return;
}


undefined4 WCdial_func08(ObjInstance *this) { //802C5968
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WCdial_getExtraSize(void) { //802C5970
  return 0x14;
}

