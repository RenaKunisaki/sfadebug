
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void crate2_initialise(undefined4 param) { //801D19CC
  return;
}


/* @description Called when DLL is unloaded */

void crate2_release(void) { //801D19D0
  return;
}


/* Library Function - Single Match
    dll_126_func03
   
   Library: KioskDefault 0 0 */

void crate2_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801D19D4
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  double dVar4;
  
  puVar3 = this->state;
  (this->pos).rotation.x = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.z = (ushort)objDef[1].allocatedSize << 8;
  this->curModel = objDef[1].mapStates1;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  dVar4 = (double)((float)((double)CONCAT44(0x43300000,(uint)objDef[1].bound) - 4503599627370496.0)
                  * 0.015625);
  if (dVar4 < 0.05000000074505806) {
    dVar4 = 0.05000000074505806;
  }
  DAT_80399d58 = runlinkDownloadCode(0x1003,1);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
    this->shadow->field0_0x0 = (float)((double)this->data->field0_0x0 * dVar4);
  }
  puVar3[1] = 2;
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  uVar2 = mainGetBit((int)sVar1);
  *puVar3 = (char)uVar2;
  (this->pos).scale = (float)((double)this->data->scale * dVar4);
  this->hitstate->field16_0x52 =
       (ushort)(int)((double)(float)((double)CONCAT44(0x43300000,
                                                      (int)(short)this->hitstate->field16_0x52 ^
                                                      0x80000000) - 4503601774854144.0) * dVar4);
  return;
}


/* Library Function - Single Match
    dll_126_func04
   
   Library: KioskDefault 0 0 */

void crate2_update(ObjInstance *this) { //801D1B24
  char cVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  ObjInstance *pOVar6;
  ObjDef *pOVar7;
  char *pcVar8;
  float local_1c [2];
  
  pcVar8 = this->state;
  if (*pcVar8 == '\0') {
    iVar5 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if (iVar5 != 0) {
      cVar1 = pcVar8[1];
      pcVar8[1] = cVar1 + -1;
      if ('\0' < (char)(cVar1 + -1)) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,499,0x7f,(char *)&PTR_DAT_803111a0,(int *)0x7e
                           );
        objSetModelNo(this,2 - pcVar8[1]);
      }
    }
    if (pcVar8[1] < '\x01') {
      pOVar7 = this->def;
      *pcVar8 = '\x01';
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,500,0x7f,(char *)&PTR_DAT_803111a0,(int *)0x89);
      sVar3._0_1_ = pOVar7[1].loadFlags;
      sVar3._1_1_ = pOVar7[1].mapStates2;
      if (sVar3 != -1) {
        sVar4._0_1_ = pOVar7[1].loadFlags;
        sVar4._1_1_ = pOVar7[1].mapStates2;
        mainSetBits((int)sVar4,1);
      }
      local_1c[0] = 50.0;
      pOVar6 = getSeqObj(5,this,local_1c);
      if (pOVar6 != (ObjInstance *)0x0) {
        fVar2 = (this->pos).pos.x;
        (pOVar6->prevPos).x = fVar2;
        (pOVar6->pos).pos.x = fVar2;
        fVar2 = (this->pos).pos.y + 15.0;
        (pOVar6->prevPos).y = fVar2;
        (pOVar6->pos).pos.y = fVar2;
        fVar2 = (this->pos).pos.z;
        (pOVar6->prevPos).z = fVar2;
        (pOVar6->pos).pos.z = fVar2;
        (pOVar6->pos).rotation.x = (this->pos).rotation.x;
      }
      (**(code **)(*DAT_80399d58 + 4))(this,1,0,2,0xffffffff,0);
    }
  }
  else {
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  }
  return;
}


/* @description Override hit detection */

void crate2_hitDetect(ObjInstance *this) { //801D1CC8
  return;
}


/* Library Function - Single Match
    dll_126_func06
   
   Library: KioskDefault 0 0 */

void crate2_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801D1CCC
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar2;
  
  if ((*this->state != '\0') && (bVar1 = checkSomeDebugFlags_8017c4f8(), !bVar1)) {
    return;
  }
  if (shouldRender) {
    pOVar2 = this->def;
    if ((pOVar2[1].cullDist & 1) != 0) {
      FUN_80096afc((ushort)*(byte *)&pOVar2[1].pos.x,(ushort)*(byte *)((int)&pOVar2[1].pos.x + 1),
                   (ushort)*(byte *)((int)&pOVar2[1].pos.x + 2));
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_126_func07
   
   Library: KioskDefault 0 0 */

void crate2_free(ObjInstance *this,int param2) { //801D1D6C
  DLL_free(DAT_80399d58);
  DAT_80399d58 = (LoadedDll *)0x0;
  return;
}


undefined4 crate2_func08(ObjInstance *this) { //801D1D98
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int crate2_getExtraSize(void) { //801D1DA0
  return 2;
}

