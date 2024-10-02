
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void projswitch_initialise(undefined4 param) { //801D9E34
  return;
}


/* @description Called when DLL is unloaded */

void projswitch_release(void) { //801D9E38
  return;
}


/* Library Function - Single Match
    dll_103_func03
   
   Library: KioskDefault 0 0 */

void projswitch_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //801D9E3C
  uint uVar1;
  char *pcVar2;
  
  pcVar2 = this->state;
  (this->pos).rotation.x = (ushort)objDef[1].cullDist << 8;
  (this->pos).rotation.y = (ushort)objDef[1].loadFlags << 8;
  if (objDef[1].mapStates2 == 0) {
    (this->pos).scale = this->data->scale;
  }
  else {
    (this->pos).scale =
         (float)((double)CONCAT44(0x43300000,(uint)objDef[1].mapStates2) - 4503599627370496.0) *
         this->data->scale * 0.015625;
  }
  this->hitstate->field16_0x52 =
       (ushort)((int)((uint)objDef[1].mapStates2 * (uint)this->data->hitbox_flagsB6) >> 6);
  this->curModel = (byte)((int)(uint)objDef[1].bound >> 2);
  if (this->data->nModels <= (char)this->curModel) {
    this->curModel = 0;
  }
  uVar1 = mainGetBit((int)(short)objDef[1].objType);
  *pcVar2 = (char)uVar1;
  if (*pcVar2 == '\0') {
    projswitchFn_801da1b0((int *)this,0,0);
  }
  else {
    projswitchFn_801da1b0((int *)this,1,0);
  }
  if (*(char *)((int)&objDef[1].pos.x + 3) == '\0') {
    this->flags_0xb0 = this->flags_0xb0 | DontUseRenderCallback;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_103_func04
   
   Library: KioskDefault 0 0 */

void projswitch_update(ObjInstance *this) { //801D9F94
  short sVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  ObjDef *pOVar5;
  
  pOVar5 = this->def;
  pcVar4 = this->state;
  if ((*pcVar4 != '\0') && (uVar2 = mainGetBit((int)(short)pOVar5[1].objType), uVar2 == 0)) {
    projswitchFn_801da1b0((int *)this,0,1);
  }
  if (0.0 < *(float *)(pcVar4 + 4)) {
    *(float *)(pcVar4 + 4) =
         *(float *)(pcVar4 + 4) -
         (float)((double)CONCAT44(0x43300000,(uint)framesThisStep) - 4503599627370496.0);
    if (0.0 < *(float *)(pcVar4 + 4)) {
      return;
    }
    *(float *)(pcVar4 + 4) = 0.0;
    mainSetBits((int)(short)pOVar5[1].objType,0);
  }
  iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  if (iVar3 == 0xe) {
    if (*pcVar4 == '\0') {
      projswitchFn_801da1b0((int *)this,1,1);
      mainSetBits((int)(short)pOVar5[1].objType,1);
      if ((pOVar5[1].bound & 3) == 2) {
        sVar1._0_1_ = pOVar5[1].allocatedSize;
        sVar1._1_1_ = pOVar5[1].mapStates1;
        *(float *)(pcVar4 + 4) =
             (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0) *
             0.1 * 60.0;
      }
    }
    else if ((pOVar5[1].bound & 3) == 1) {
      projswitchFn_801da1b0((int *)this,0,1);
      mainSetBits((int)(short)pOVar5[1].objType,0);
    }
  }
  return;
}


/* @description Override hit detection */

void projswitch_hitDetect(ObjInstance *this) { //801DA114
  return;
}


/* Library Function - Single Match
    dll_103_func06
   
   Library: KioskDefault 0 0 */

void projswitch_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //801DA118
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar1;
  
  pOVar1 = this->def;
  if (shouldRender) {
    if (*(char *)((int)&pOVar1[1].pos.x + 3) != '\0') {
      FUN_80096afc((ushort)*(byte *)&pOVar1[1].pos.x,(ushort)*(byte *)((int)&pOVar1[1].pos.x + 1),
                   (ushort)*(byte *)((int)&pOVar1[1].pos.x + 2));
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void projswitch_free(ObjInstance *this,int param2) { //801DA19C
  return;
}


undefined4 projswitch_func08(ObjInstance *this) { //801DA1A0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int projswitch_getExtraSize(void) { //801DA1A8
  return 8;
}

