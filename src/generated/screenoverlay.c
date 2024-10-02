
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void screenOverlay_initialise(undefined4 param) { //801F6670
  FUN_80068eec((double)FLOAT_80397c38);
  return;
}


/* @description Called when DLL is unloaded */

void screenOverlay_release(void) { //801F6694
  FUN_80068ef4();
  return;
}


/* Library Function - Single Match
    screenOverlay_func03
   
   Library: KioskDefault 0 0 */

void screenOverlay_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //801F66B4
  char **ppcVar1;
  
  ppcVar1 = (char **)this->state;
  this->field76_0xf4 = 0;
  if (1 < *(byte *)((int)&objDef[1].objType + 1)) {
    *(undefined *)((int)&objDef[1].objType + 1) = 1;
  }
  *ppcVar1 = &DAT_803132b0;
  *(short *)(ppcVar1 + 1) = (short)**ppcVar1;
  if (obj2 == (ObjInstance *)0x0) {
    if (*(short *)(*ppcVar1 + 2) != -1) {
      audioTryStartSfx((int *)this,1,*(ushort *)(*ppcVar1 + 2),0x7f,"screenoverlay.c",0x94)
      ;
      printf(" Playing Snd");
    }
    if (*(short *)(*ppcVar1 + 6) != -1) {
      audioTryStartSfx((int *)this,1,*(ushort *)(*ppcVar1 + 6),0x7f,"screenoverlay.c",0x98)
      ;
    }
  }
  (this->pos).pos.x = (objDef->pos).x;
  (this->pos).pos.y = (objDef->pos).y;
  (this->pos).pos.z = (objDef->pos).z;
  this->newOpacity = 0;
  return;
}


/* Library Function - Single Match
    screenOverlay_func04
   
   Library: KioskDefault 0 0 */

void screenOverlay_update(ObjInstance *this) { //801F67C8
  animFn_801f6acc((int)this,1,3);
  return;
}


/* @description Override hit detection */

void screenOverlay_hitDetect(ObjInstance *this) { //801F67F8
  return;
}


/* Library Function - Single Match
    screenOverlay_func06
   
   Library: KioskDefault 0 0 */

void screenOverlay_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801F67FC
  byte bVar1;
  ObjInstance *pOVar2;
  int iVar3;
  bool bVar5;
  Camera *pCVar4;
  undefined3 in_register_00000010;
  Gfx *cmdBuf;
  undefined3 in_register_00000014;
  Mtx44 **mtxBuf;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar6;
  short sVar7;
  float in_f31;
  float fVar8;
  
  mtxBuf = (Mtx44 **)CONCAT31(in_register_00000014,param3);
  cmdBuf = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar6 = this->state;
  pOVar2 = Object_objGetMain();
  if (*(short *)(puVar6 + 4) != 0) {
    bVar1 = this->newOpacity;
    if ((this->newOpacity == 0) && (*(short *)(puVar6 + 4) < 0)) {
      *(undefined2 *)(puVar6 + 4) = 0;
      Object_objFreeObject(this);
    }
    if ((this->newOpacity == 0x80) && (0 < *(short *)(puVar6 + 4))) {
      *(undefined2 *)(puVar6 + 4) = 0;
    }
    sVar7 = (ushort)bVar1 + *(short *)(puVar6 + 4) * (ushort)framesThisStep;
    if (sVar7 < 0) {
      sVar7 = 0;
    }
    else if (0x80 < sVar7) {
      sVar7 = 0x80;
    }
    this->newOpacity = (u8)sVar7;
  }
  if ((pOVar2->flags_0xb0 & SeqActive) == 0) {
    iVar3 = FUN_8018d744();
    if ((iVar3 == 0) && (bVar5 = checkSomeDebugFlags_8017c4f8(), !bVar5)) {
      diPrintf(" DRAWING THE THING ");
      getCurCamera();
      fVar8 = getFovY();
      in_f31 = SUB84((double)fVar8,0);
      Camera_setPlayerNo(2);
      pCVar4 = getCurCamera();
      (pCVar4->pos).x = playerMapOffsetX;
      (pCVar4->pos).y = 0.0;
      (pCVar4->pos).z = playerMapOffsetZ;
      (pCVar4->rot).z = 0;
      (pCVar4->rot).y = 0;
      (pCVar4->rot).x = 0;
      pCVar4->yOffset = 0.0;
      setFovY(0.0);
      (this->pos).scale = this->data->scale;
      (this->pos).rotation.z = 0;
      (this->pos).rotation.x = -0x8000;
      (this->pos).rotation.y = 0;
      (this->pos).pos.x = playerMapOffsetX;
      (this->pos).pos.y = -1.5;
      (this->pos).pos.z = playerMapOffsetZ;
      (this->prevPos).x = playerMapOffsetX;
      (this->prevPos).y = -1.5;
      (this->prevPos).z = playerMapOffsetZ;
      cameraFn_800698b4(cmdBuf,mtxBuf);
    }
    objRenderCurrentModel
              (this,(Gfx **)cmdBuf,mtxBuf,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    iVar3 = FUN_8018d744();
    if ((iVar3 == 0) && (bVar5 = checkSomeDebugFlags_8017c4f8(), !bVar5)) {
      Camera_setPlayerNo(0);
      setFovY(in_f31);
      cameraFn_800698b4(cmdBuf,mtxBuf);
    }
  }
  return;
}


/* @description Free object instance */

void screenOverlay_free(ObjInstance *this,int param2) { //801F6A20
  return;
}


undefined4 screenOverlay_func08(ObjInstance *this) { //801F6A24
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int screenOverlay_getExtraSize(void) { //801F6A2C
  return 0xc;
}


/* Library Function - Single Match
    screenOverlay_func0A
   
   Library: KioskDefault 0 0 */

void screenOverlay_setScale(ObjInstance *this,float scale) { //801F6A34
  int *piVar1;
  
  piVar1 = (int *)this->state;
  if ((-1 < *(short *)(piVar1 + 1)) &&
     (*(short *)(piVar1 + 1) = -(short)*(char *)(*piVar1 + 1), *(short *)(*piVar1 + 4) != -1)) {
    audioStartSfx((int **)0x0,*(ushort *)(*piVar1 + 4),0x7f,0x40,"screenoverlay.c",0x12a);
  }
  return;
}

