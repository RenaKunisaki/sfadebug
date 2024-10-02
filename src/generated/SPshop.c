
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SPshop_initialise(undefined4 param) { //80267348
  return;
}


/* @description Called when DLL is unloaded */

void SPshop_release(void) { //8026734C
  return;
}


/* Library Function - Single Match
    dll_2CC_func03
   
   Library: KioskDefault 0 0 */

void SPshop_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //80267350
  Object_objAddObjectType(this,10);
  mainSetBits(0x29,0);
  FUN_80267a60();
  return;
}


/* Library Function - Single Match
    dll_2CC_func04
   
   Library: KioskDefault 0 0 */

void SPshop_update(ObjInstance *this) { //8026738C
  ObjInstance *pOVar1;
  uint uVar2;
  
  pOVar1 = Object_objGetMain();
  if (this->field76_0xf4 == 0) {
                    /* {@symbol 8012e228} */
    (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,0,1);
                    /* {@symbol 8012e228} */
    (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,5,1);
    if (pOVar1->romdefno == Krystal) {
                    /* {@symbol 8012e228} */
      (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,6,1);
    }
    else {
                    /* {@symbol 8012e228} */
      (**(code **)(*(int *)pDll_SaveGame + 0x50))((int)(char)this->mapId,7,1);
    }
    loadEnvfxAction(this,this,0x1c8,0);
    loadEnvfxAction(this,this,0x1cb,0);
    loadLfxAction(this,this,0x22f);
    loadLfxAction(this,this,0x231);
    mainSetBits(0x617,1);
                    /* {@symbol 8011bc64} */
    (**(code **)(*(int *)pDll05_2 + 4))(0,0xf3,"SPshop.c",0x14c,"243");
    this->field76_0xf4 = 1;
  }
  uVar2 = mainGetBit(0x29);
  if (uVar2 != 0) {
    if (pOVar1->romdefno == Sabre) {
      warpToMap(0xf,false);
    }
    else {
      warpToMap(0xe,false);
    }
  }
  return;
}


/* @description Override hit detection */

void SPshop_hitDetect(ObjInstance *this) { //80267540
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SPshop_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //80267544
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


/* Library Function - Multiple Matches With Different Base Names
    VFlevcontrol_func07
    dll_2CC_func07
    dll_2E7_func07
    sunMoonBlockPuzzle_func07
   
   Library: KioskDefault 0 0 */

void SPshop_free(ObjInstance *this,int param2) { //802675A0
  Object_removePlayerObj(this,10);
  return;
}


undefined4 SPshop_func08(ObjInstance *this) { //802675CC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SPshop_getExtraSize(void) { //802675D4
  return 5;
}


void SPshop_setScale(ObjInstance *this,float scale) { //802675DC
  return;
}


/* Library Function - Single Match
    dll_2CC_func0B
   
   Library: KioskDefault 0 0 */

void SPshop_func0B(int param1,int param2,undefined4 param3) { //802675F8
  **(undefined **)(param1 + 0xb8) = (char)param2;
  if (param2 != 0) {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(param3,param1,0xffffffff);
  }
  return;
}


/* Library Function - Single Match
    dll_2CC_func0C
   
   Library: KioskDefault 0 0 */

void SPshop_modelMtxFn(ObjInstance *this,int param2,vec3f *param3) { //80267658
  int iVar1;
  ObjInstance *pOVar2;
  
  pOVar2 = Object_objGetMain();
  iVar1 = param2 * 0x10;
  if (pOVar2->romdefno == Sabre) {
    if (*(short *)(&DAT_8031c13e + iVar1) != -1) {
      mainGetBit((int)*(short *)(&DAT_8031c13e + iVar1));
    }
  }
  else if (*(short *)(&DAT_8031c142 + iVar1) != -1) {
    mainGetBit((int)*(short *)(&DAT_8031c142 + iVar1));
  }
  return;
}


/* Library Function - Single Match
    dll_2CC_func0D
   
   Library: KioskDefault 0 0 */

undefined4 SPshop_render2(ObjInstance *this) { //802676FC
  int iVar1;
  ObjInstance *pOVar2;
  uint uVar3;
  int in_r4;
  undefined4 uVar4;
  
  pOVar2 = Object_objGetMain();
  iVar1 = in_r4 * 0x10;
  if (pOVar2->romdefno == Sabre) {
    uVar4 = 0;
    if ((*(short *)(&DAT_8031c140 + iVar1) != -1) &&
       (uVar3 = mainGetBit((int)*(short *)(&DAT_8031c140 + iVar1)), uVar3 != 0)) {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0;
    if ((*(short *)(&DAT_8031c144 + iVar1) != -1) &&
       (uVar3 = mainGetBit((int)*(short *)(&DAT_8031c144 + iVar1)), uVar3 != 0)) {
      uVar4 = 1;
    }
  }
  return uVar4;
}


/* Library Function - Single Match
    dll_2CC_func0E
   
   Library: KioskDefault 0 0 */

undefined SPshop_func0E(undefined4 param_1,int param2) { //802677A0
  if ((-1 < param2) && (param2 < 0x3c)) {
    return *(undefined *)(&PTR_DAT_8031c138 + param2 * 4);
  }
  return 0;
}


/* Library Function - Single Match
    dll_2CC_func0F
   
   Library: KioskDefault 0 0 */

undefined SPshop_func0F(undefined4 param_1,int param2) { //802677D0
  if ((-1 < param2) && (param2 < 0x3c)) {
    return (&DAT_8031c13c)[param2 * 0x10];
  }
  return 0;
}


/* Library Function - Single Match
    dll_2CC_func10
   
   Library: KioskDefault 0 0 */

undefined SPshop_func10(undefined4 param_1,int param2) { //80267800
  if ((-1 < param2) && (param2 < 0x3c)) {
    return (&DAT_8031c13d)[param2 * 0x10];
  }
  return 0;
}


/* Library Function - Single Match
    dll_2CC_func11
   
   Library: KioskDefault 0 0 */

int SPshop_func11(undefined4 param_1,int param2) { //80267830
  if ((-1 < param2) && (param2 < 0x3c)) {
    return (int)*(short *)(&PTR_DAT_8031c146 + param2 * 4);
  }
  return 0;
}


void SPshop_func12(int param1,undefined param2) { //80267860
  *(undefined *)(*(int *)(param1 + 0xb8) + 1) = param2;
  return;
}


undefined SPshop_func13(int param1) { //8026787C
  return *(undefined *)(*(int *)(param1 + 0xb8) + 1);
}


/* Library Function - Single Match
    dll_2CC_func14
   
   Library: KioskDefault 0 0 */

void SPshop_func14(int param1,int param2) { //80267898
  byte bVar1;
  ObjInstance *pOVar2;
  short sVar3;
  int iVar4;
  
  pOVar2 = Object_objGetMain();
  iVar4 = *(int *)(param1 + 0xb8);
  FUN_801a7d18((int)pOVar2,-param2);
  bVar1 = *(byte *)(iVar4 + 1);
  if (bVar1 == 5) {
    FUN_801a7b7c((int)pOVar2,10);
  }
  else if (bVar1 < 5) {
    if (bVar1 == 1) {
      FUN_801a7a44((int)pOVar2,2);
    }
    else if (bVar1 == 0) {
      if (true) {
        FUN_801a7a44((int)pOVar2,1);
      }
    }
    else if (3 < bVar1) {
      FUN_801a7b7c((int)pOVar2,5);
    }
  }
  if (pOVar2->romdefno == Sabre) {
    sVar3 = *(short *)(&DAT_8031c140 + (uint)*(byte *)(iVar4 + 1) * 0x10);
  }
  else {
    sVar3 = *(short *)(&DAT_8031c144 + (uint)*(byte *)(iVar4 + 1) * 0x10);
  }
  if (sVar3 != -1) {
    mainSetBits((int)sVar3,1);
  }
  return;
}


/* Library Function - Single Match
    dll_2CC_func15
   
   Library: KioskDefault 0 0 */

void SPshop_func15(int param1,undefined param2) { //802679C4
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *(undefined *)(iVar1 + 2) = 0;
  *(undefined *)(iVar1 + 3) = 0;
  *(undefined *)(iVar1 + 4) = param2;
  return;
}


/* Library Function - Single Match
    dll_2CC_func16
   
   Library: KioskDefault 0 0 */

void SPshop_func16(int param1,char param2,char param3) { //802679F4
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *(char *)(iVar1 + 2) = *(char *)(iVar1 + 2) + param3;
  *(char *)(iVar1 + 3) = *(char *)(iVar1 + 3) + param2;
  return;
}


/* Library Function - Single Match
    dll_2CC_func17
   
   Library: KioskDefault 0 0 */

void SPshop_func17(int param1,int *param2,int *param3,int *param4) { //80267A24
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  *param3 = (int)*(char *)(iVar1 + 2);
  *param2 = (int)*(char *)(iVar1 + 3);
  *param4 = (int)*(char *)(iVar1 + 4);
  return;
}

