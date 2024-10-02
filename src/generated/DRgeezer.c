
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRgeezer_initialise(undefined4 param) { //802B618C
  return;
}


/* @description Called when DLL is unloaded */

void DRgeezer_release(void) { //802B6190
  return;
}


/* Library Function - Single Match
    DRgeezer_func03
   
   Library: KioskDefault 0 0 */

void DRgeezer_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802B6194
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)this->state;
  uVar3 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  *(byte *)(puVar4 + 3) = (byte)((uVar3 & 1) << 7) | *(byte *)(puVar4 + 3) & 0x7f;
  if ((uVar3 & 1) != 0) {
    audioTryStartSfx((int *)this,1,0x72,0x7f,(char *)&PTR_DAT_80323b08,0x57);
    audioTryStartSfx((int *)this,2,0x106,0x7f,(char *)&PTR_DAT_80323b08,0x58);
  }
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  puVar4[2] = (int)sVar1;
  sVar2._0_1_ = objDef[1].loadFlags;
  sVar2._1_1_ = objDef[1].mapStates2;
  puVar4[1] = (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0) /
              10.0;
  *puVar4 = 0;
  *(byte *)(puVar4 + 3) = *(byte *)(puVar4 + 3) & 0xbf;
  return;
}


/* Library Function - Single Match
    DRgeezer_func04
   
   Library: KioskDefault 0 0 */

void DRgeezer_update(ObjInstance *this) { //802B6274
  int iVar1;
  uint uVar2;
  ObjInstance *pOVar3;
  ObjInstance *pOVar4;
  int *piVar5;
  float local_34;
  int local_30;
  float local_2c;
  float local_28 [3];
  
  piVar5 = (int *)this->state;
  local_28[0] = 40.0;
  local_34 = 0.0;
  local_30 = 0;
  local_2c = 0.0;
  if (*(char *)(piVar5 + 3) < '\0') {
    uVar2 = (uint)framesThisStep;
    iVar1 = *piVar5;
    *piVar5 = iVar1 - uVar2;
    if ((int)(iVar1 - uVar2) < 0) {
      audioTryStartSfx((int *)this,4,0x3f,0x7f,(char *)&PTR_DAT_80323b08,0x72);
      pOVar3 = getSeqObj(0x1b,this,local_28);
      if (pOVar3 == (ObjInstance *)0x0) {
        *(byte *)(piVar5 + 3) = *(byte *)(piVar5 + 3) & 0xbf;
      }
      else {
        audioTryStartSfx((int *)this,8,0x1fb,0x7f,(char *)&PTR_DAT_80323b08,0x75);
        local_28[0] = 1000.0;
        pOVar4 = getSeqObj(0x20,this,local_28);
        if (pOVar4 != (ObjInstance *)0x0) {
          local_34 = ((pOVar4->pos).pos.x - (this->pos).pos.x) / 200.0;
          local_2c = ((pOVar4->pos).pos.z - (this->pos).pos.z) / 200.0;
        }
        local_30 = piVar5[1];
        (*(code *)pOVar3->dll->ptrs2->setScale)(pOVar3,&local_34);
        *(byte *)(piVar5 + 3) = *(byte *)(piVar5 + 3) & 0xbf | 0x40;
      }
      printf(" firing ");
      *piVar5 = piVar5[2];
    }
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x5c,0,0,0xffffffff,0);
    if (piVar5[2] - *piVar5 < 0x3c) {
      for (iVar1 = 0; iVar1 < (int)(uint)framesThisStep >> 1; iVar1 = iVar1 + 1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x5a,0,0,0xffffffff,0);
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x5b,0,0,0xffffffff,0);
        if ((*(byte *)(piVar5 + 3) >> 6 & 1) != 0) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x679,0,0,0xffffffff,0);
        }
      }
    }
  }
  else {
    uVar2 = mainGetBit((int)*(short *)&this->def[1].pos.x);
    *(byte *)(piVar5 + 3) = (byte)((uVar2 & 1) << 7) | *(byte *)(piVar5 + 3) & 0x7f;
    if ((uVar2 & 1) != 0) {
      audioTryStartSfx((int *)this,1,0x72,0x7f,(char *)&PTR_DAT_80323b08,0x93);
      audioTryStartSfx((int *)this,2,0x106,0x7f,(char *)&PTR_DAT_80323b08,0x94);
    }
  }
  return;
}


/* @description Override hit detection */

void DRgeezer_hitDetect(ObjInstance *this) { //802B656C
  return;
}


/* @description Override render */

void DRgeezer_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802B6570
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (bVar1 = checkSomeDebugFlags_8017c4f8(), bVar1)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DRgeezer_free(ObjInstance *this,int param2) { //802B65D8
  return;
}


undefined4 DRgeezer_func08(ObjInstance *this) { //802B65DC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRgeezer_getExtraSize(void) { //802B65E4
  return 0x10;
}

