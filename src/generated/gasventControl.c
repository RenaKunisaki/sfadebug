
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void gasventControl_initialise(undefined4 param) { //80222670
  return;
}


/* @description Called when DLL is unloaded */

void gasventControl_release(void) { //80222674
  return;
}


/* Library Function - Single Match
    dll_1BB_func03
   
   Library: KioskDefault 0 0 */

void gasventControl_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //80222678
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  uVar1 = mainGetBit(0xa3);
  if (uVar1 != 0) {
    *puVar2 = 3;
  }
  return;
}


/* Library Function - Single Match
    dll_1BB_func04
   
   Library: KioskDefault 0 0 */

void gasventControl_update(ObjInstance *this) { //802226D4
  byte bVar1;
  ObjInstance *pOVar2;
  uint uVar3;
  ObjInstance **ppOVar4;
  int iVar5;
  byte *pbVar6;
  double dVar7;
  int local_1c [2];
  
  pbVar6 = this->state;
  bVar1 = *pbVar6;
  if (bVar1 == 2) {
    ppOVar4 = Object_playerGetObject(0x41,local_1c);
    local_1c[0] = 0;
    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
      pOVar2 = getSeqObj(6,ppOVar4[iVar5],(float *)0x0);
      dVar7 = (double)objDistSqObj2ObjXZ(ppOVar4[iVar5],pOVar2);
      if (100.0 < dVar7) {
        local_1c[0] = local_1c[0] + 1;
        *(float *)(pbVar6 + 8) = *(float *)(pbVar6 + 8) + timeDelta;
      }
    }
    if (local_1c[0] == 0) {
      audioStartSfx((int **)0x0,0x161,0x7f,0x40,"gasventControl.c",0x6b);
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
      *pbVar6 = 4;
    }
    else if (900.0 < *(float *)(pbVar6 + 8)) {
      *(float *)(pbVar6 + 8) = *(float *)(pbVar6 + 8) - 900.0;
      iVar5 = FUN_801a7998(*(int *)(pbVar6 + 4));
      if (iVar5 != 0x1d7) {
        FUN_80088818(*(int *)(pbVar6 + 4),(int)this,'\x16',1,0);
      }
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      Object_playerGetObject(0x41,local_1c);
      pOVar2 = Object_objGetMain();
      *(ObjInstance **)(pbVar6 + 4) = pOVar2;
      if ((local_1c[0] == 4) && (*(int *)(pbVar6 + 4) != 0)) {
        *pbVar6 = 1;
      }
    }
    else if ((true) && (uVar3 = mainGetBit(0x3ec), uVar3 != 0)) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
      *pbVar6 = 2;
    }
  }
  else if (bVar1 < 4) {
                    /* {@symbol 800d0a70} */
    (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,300);
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xc);
    *pbVar6 = 4;
  }
  return;
}


/* @description Override hit detection */

void gasventControl_hitDetect(ObjInstance *this) { //80222908
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void gasventControl_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8022290C
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

void gasventControl_free(ObjInstance *this,int param2) { //80222968
  return;
}


undefined4 gasventControl_func08(ObjInstance *this) { //8022296C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int gasventControl_getExtraSize(void) { //80222974
  return 0xc;
}

