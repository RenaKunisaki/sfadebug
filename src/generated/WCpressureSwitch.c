
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WCpressureSwitch_initialise(undefined4 param) { //802C399C
  return;
}


/* @description Called when DLL is unloaded */

void WCpressureSwitch_release(void) { //802C39A0
  return;
}


/* Library Function - Single Match
    pressureSwitch02D9_func03
   
   Library: KioskDefault 0 0 */

void WCpressureSwitch_init
               (ObjInstance *param1,short *param2,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802C39A4
  char cVar2;
  uint uVar1;
  int iVar3;
  undefined *puVar4;
  undefined4 in_register_00004008;
  undefined4 in_register_00004010;
  
                    /* {@symbol 8012dfa8} */
  cVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x40))
                    (CONCAT44(in_register_00004008,x),CONCAT44(in_register_00004010,y),
                     (int)(char)param1->mapId);
  if (cVar2 == '\x02') {
    mainSetBits((int)param2[0xd],1);
  }
  puVar4 = param1->state;
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0xc) << 8;
  param1->flags_0xb0 = param1->flags_0xb0 | (DontMove|DontUseRenderCallback);
  param1->curModel = *(byte *)((int)param2 + 0x19);
  if (param1->data->nModels <= (char)param1->curModel) {
    param1->curModel = 0;
    printf("PRESSURESWITCH.c: modelno out of range romdefno=%d",(int)*param2);
  }
  uVar1 = mainGetBit((int)param2[0xd]);
  if (uVar1 != 0) {
    (param1->pos).pos.y =
         *(float *)(param2 + 6) -
         (float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param2 + 0xe)) - 4503599627370496.0);
    *puVar4 = 0x1e;
    puVar4[1] = 2;
  }
  Object_objAddObjectType(param1,0x33);
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    *(undefined4 *)(puVar4 + iVar3 * 4 + 4) = 0;
  }
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802c3fb8;
  return;
}


/* Library Function - Single Match
    pressureSwitch02D9_func04
   
   Library: KioskDefault 0 0 */

void WCpressureSwitch_update(ObjInstance *this) { //802C3AE8
  char cVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  ObjDef *pOVar9;
  double dVar10;
  
  pOVar9 = this->def;
  pcVar8 = this->state;
  if ((*(short *)&pOVar9[1].pos.x < 1) ||
     (uVar4 = mainGetBit((int)*(short *)&pOVar9[1].pos.x), uVar4 != 0)) {
    cVar1 = *pcVar8;
    *pcVar8 = cVar1 + -1;
    if ((char)(cVar1 + -1) < '\0') {
      *pcVar8 = '\0';
    }
    if ('\0' < (char)this->field18_0x58->field144_0x10f) {
      for (iVar7 = 0; iVar7 < (char)this->field18_0x58->field144_0x10f; iVar7 = iVar7 + 1) {
        iVar6 = *(int *)((int)(this->field18_0x58->mtx + 2) + iVar7 * 4);
        if ((float)((double)CONCAT44(0x43300000,(uint)pOVar9[1].mapStates2) - 4503599627370496.0) <
            *(float *)(iVar6 + 0x10) - (this->pos).pos.y) {
          FUN_802c3e9c((int)this,iVar6);
        }
      }
    }
    iVar7 = FUN_802c3f0c((int)this);
    if (iVar7 != 0) {
      *pcVar8 = '\x05';
    }
    dVar10 = (double)((pOVar9->pos).y -
                     (float)((double)CONCAT44(0x43300000,(uint)pOVar9[1].loadFlags) -
                            4503599627370496.0));
    cVar1 = pcVar8[1];
    if (cVar1 == '\x02') {
      sVar3._0_1_ = pOVar9[1].allocatedSize;
      sVar3._1_1_ = pOVar9[1].mapStates1;
      uVar4 = mainGetBit((int)sVar3);
      if (uVar4 == 0) {
        audioTryStartSfx((int *)this,1,0x4f,0x7f,"WCpressureswitch.c",0xc4);
        pcVar8[1] = '\x01';
      }
    }
    else if (cVar1 < '\x02') {
      if (cVar1 == '\0') {
        if ((*pcVar8 != '\0') && (dVar10 <= (double)(this->pos).pos.y)) {
          audioTryStartSfx((int *)this,1,0x4f,0x7f,"WCpressureswitch.c",0xb5);
          pcVar8[1] = '\x03';
        }
      }
      else if ((-1 < cVar1) &&
              ((this->pos).pos.y = timeDelta * 0.05 + (this->pos).pos.y,
              (pOVar9->pos).y < (this->pos).pos.y)) {
        (this->pos).pos.y = (pOVar9->pos).y;
        pcVar8[1] = '\0';
      }
    }
    else if ((cVar1 < '\x04') &&
            ((this->pos).pos.y = -(timeDelta * 0.05 - (this->pos).pos.y),
            (double)(this->pos).pos.y < dVar10)) {
      sVar2._0_1_ = pOVar9[1].allocatedSize;
      sVar2._1_1_ = pOVar9[1].mapStates1;
      mainSetBits((int)sVar2,1);
      pcVar8[1] = '\x02';
      (this->pos).pos.y = (float)dVar10;
    }
    puVar5 = (uint *)FUN_80094400((int)this,0);
    if (puVar5 != (uint *)0x0) {
      *puVar5 = (uint)(pcVar8[1] == '\x02');
      *puVar5 = *puVar5 << 8;
    }
  }
  else {
    diPrintf(" Avitvate %i ",(int)*(short *)&pOVar9[1].pos.x);
  }
  return;
}


/* @description Override hit detection */

void WCpressureSwitch_hitDetect(ObjInstance *this) { //802C3D94
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    pressureSwitch02D9_func06
    pressureSwitch_func06
   
   Library: KioskDefault 0 0 */

void WCpressureSwitch_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802C3D98
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((((this->pos).flags & 0x100) != 0) && (this->def != (ObjDef *)0x0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)((this->pos).pos.y + 25.0),
                   (double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)this->def[1].bound) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_10A_func07
    dll_10B_func07
    dll_266_func07
    dll_28B_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void WCpressureSwitch_free(ObjInstance *this,int param2) { //802C3E60
  Object_removePlayerObj(this,0x33);
  return;
}


undefined4 WCpressureSwitch_func08(ObjInstance *this) { //802C3E8C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WCpressureSwitch_getExtraSize(void) { //802C3E94
  return 0x7c;
}

