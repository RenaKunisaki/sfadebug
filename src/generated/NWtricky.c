
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void NWtricky_initialise(undefined4 param) { //8024DBF8
  return;
}


/* @description Called when DLL is unloaded */

void NWtricky_release(void) { //8024DBFC
  return;
}


/* Library Function - Single Match
    dll_1DE_func03
   
   Library: KioskDefault 0 0 */

void NWtricky_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8024DC00
  undefined4 uVar1;
  uint uVar2;
  ObjInstance *pOVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
                    /* {@symbol 8012da4c} */
  uVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x94))();
  *(undefined4 *)(puVar4 + 8) = uVar1;
  puVar4[1] = 0;
  puVar4[2] = 0;
  uVar2 = mainGetBit(0xd3);
  if (uVar2 == 0) {
    mainSetBits(0x4e3,0xff);
    *puVar4 = 0;
  }
  else {
    *puVar4 = 2;
  }
  uVar2 = mainGetBit(0x4d4);
  if ((uVar2 == 0) && (pOVar3 = Object_getSidekicksLoaded(), pOVar3 != (ObjInstance *)0x0)) {
    (*(code *)pOVar3->dll->ptrs2[1].render2C)(pOVar3,this);
    mainSetBits(0x4d4,1);
  }
  this->fptr_0xbc = NWtricky_debugFn;
  return;
}


/* Library Function - Single Match
    dll_1DE_func04
   
   Library: KioskDefault 0 0 */

void NWtricky_update(ObjInstance *this) { //8024DCD8
  byte bVar1;
  ObjInstance *this_00;
  uint uVar2;
  char cVar3;
  byte *pbVar4;
  
  pbVar4 = this->state;
  this_00 = Object_getSidekicksLoaded();
  if (this_00 != (ObjInstance *)0x0) {
    bVar1 = *pbVar4;
    if (bVar1 == 1) {
      uVar2 = mainGetBit(0xd3);
      if (uVar2 == 0) {
        *(float *)(pbVar4 + 4) = *(float *)(pbVar4 + 4) + timeDelta;
        if (600.0 <= *(float *)(pbVar4 + 4)) {
          *(float *)(pbVar4 + 4) = *(float *)(pbVar4 + 4) - 600.0;
          audioTryStartSfx((int *)this_00,0x10,0x1d0,0x7f,"NWtricky.c",0x9e);
        }
      }
      else {
        (*this_00->dll->ptrs2[1].modelMtxFn_0x28)(this_00,0,(vec3f *)0x0);
        FUN_80068a9c((uint)this_00,0x7f);
        mainSetBits(0x4e3,0);
        *pbVar4 = 2;
      }
    }
    else if (bVar1 == 0) {
      if (true) {
        uVar2 = mainGetBit(0xd3);
        if (uVar2 == 0) {
          cVar3 = (*this_00->dll->ptrs2[2].onLoad)(this_00);
          if (cVar3 != '\0') {
            *(float *)(pbVar4 + 4) = 0.0;
            *pbVar4 = 1;
          }
        }
        else {
          mainSetBits(8,1);
          mainSetBits(0x4e4,1);
          *pbVar4 = 2;
        }
      }
    }
    else if (bVar1 < 3) {
      *(float *)(pbVar4 + 4) = *(float *)(pbVar4 + 4) + timeDelta;
      if (((2000.0 <= *(float *)(pbVar4 + 4)) && (uVar2 = mainGetBit(0x4e3), uVar2 == 0xff)) &&
         (*(float *)(pbVar4 + 4) = 0.0, **(byte **)(pbVar4 + 8) < 4)) {
        mainSetBits(0x4e3,1);
      }
      uVar2 = mainGetBit(0x25);
      if (uVar2 != 0) {
        mainSetBits(0x3f8,1);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void NWtricky_hitDetect(ObjInstance *this) { //8024DED8
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void NWtricky_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8024DEDC
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


/* Library Function - Single Match
    dll_1DE_func07
   
   Library: KioskDefault 0 0 */

void NWtricky_free(ObjInstance *this,int param2) { //8024DF38
  uint uVar1;
  
  uVar1 = mainGetBit(0xd3);
  if ((uVar1 != 0) && (uVar1 = mainGetBit(0x4e3), uVar1 == 0)) {
    mainSetBits(0x4e3,0xff);
    mainSetBits(0x4e4,1);
  }
  return;
}


undefined4 NWtricky_func08(ObjInstance *this) { //8024DF8C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int NWtricky_getExtraSize(void) { //8024DF94
  return 0xc;
}

