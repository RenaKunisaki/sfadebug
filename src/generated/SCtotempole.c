
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCtotempole_initialise(undefined4 param) { //8025A534
  return;
}


/* @description Called when DLL is unloaded */

void SCtotempole_release(void) { //8025A538
  return;
}


/* Library Function - Single Match
    SCtotempole_func03
   
   Library: KioskDefault 0 0 */

void SCtotempole_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8025A53C
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  puVar1[2] = (short)(int)(*(float *)&objDef[1].loadFlags * 400.0);
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  this->curModel = objDef[1].mapStates1;
  if (((char)this->curModel < '\0') || ('\x03' < (char)this->curModel)) {
    this->curModel = 0;
  }
  *puVar1 = 0xffff;
  puVar1[1] = 0xffff;
  *(undefined4 *)(puVar1 + 4) = 0;
  return;
}


/* Library Function - Single Match
    SCtotempole_func04
   
   Library: KioskDefault 0 0 */

void SCtotempole_update(ObjInstance *this) { //8025A5C4
  float fVar1;
  float fVar2;
  ObjInstance *pOVar3;
  char cVar5;
  int iVar4;
  ObjDef *pOVar6;
  ushort *puVar7;
  double dVar8;
  undefined auStack_44 [4];
  undefined4 uStack_40;
  uint uStack_3c;
  int aiStack_38 [2];
  longlong local_30;
  
  _savefpr_30();
  puVar7 = (ushort *)this->state;
  pOVar6 = this->def;
  if (*(int *)(puVar7 + 4) == 0) {
    pOVar3 = SCTotemPoleFn_8025a904(this);
    *(ObjInstance **)(puVar7 + 4) = pOVar3;
  }
  pOVar3 = Object_objGetMain();
  fVar1 = (this->pos).pos.x - (pOVar3->pos).pos.x;
  fVar2 = (this->pos).pos.z - (pOVar3->pos).pos.z;
  dVar8 = sqrt((double)(fVar1 * fVar1 + fVar2 * fVar2));
  local_30 = (longlong)(int)dVar8;
  *puVar7 = (ushort)(int)dVar8;
  if (*puVar7 < puVar7[2]) {
    if (puVar7[2] <= puVar7[1]) {
      cVar5 = (**(code **)(**(int **)(*(int *)(puVar7 + 4) + 0x68) + 0x24))
                        (*(undefined4 *)(puVar7 + 4));
      if (cVar5 == '\0') {
                    /* {@symbol 8011bc64} */
        (**(code **)(*(int *)pDll05_2 + 4))
                  (this,0xb4,&PTR_DAT_8031b818,0x6c,"AMMUSICACTION_SC_TotemFade");
      }
      if (pOVar6->id == 0x30c5a) {
        audioTryStartSfx((int *)this,1,0x82,0x7f,(char *)&PTR_DAT_8031b818,0x6e);
      }
    }
  }
  else if (puVar7[1] < puVar7[2]) {
    cVar5 = (**(code **)(**(int **)(*(int *)(puVar7 + 4) + 0x68) + 0x24))
                      (*(undefined4 *)(puVar7 + 4));
    if (cVar5 == '\0') {
                    /* {@symbol 800d2604} */
      iVar4 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_44);
      if (iVar4 == 0) {
                    /* {@symbol 8011bc64} */
        (**(code **)(*(int *)pDll05_2 + 4))
                  (this,0x12,&PTR_DAT_8031b818,0x7a,"AMMUSICACTION_SC_MainTuneDay");
      }
      else {
                    /* {@symbol 8011bc64} */
        (**(code **)(*(int *)pDll05_2 + 4))
                  (this,0xec,&PTR_DAT_8031b818,0x78,"AMMUSICACTION_SC_MainTuneNight");
      }
    }
    FUN_80068a9c((uint)this,1);
  }
  if (pOVar6->id == 0x30c5a) {
    iVar4 = FUN_800883e4((int)this,&uStack_40,aiStack_38,&uStack_3c);
    if (iVar4 != 0) {
      (**(code **)(**(int **)(*(int *)(puVar7 + 4) + 0x68) + 0x20))(*(undefined4 *)(puVar7 + 4),1);
    }
    (this->pos).rotation.x = (this->pos).rotation.x + 0xb6;
  }
  puVar7[1] = *puVar7;
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void SCtotempole_hitDetect(ObjInstance *this) { //8025A81C
  return;
}


/* Library Function - Single Match
    SCtotempole_func06
   
   Library: KioskDefault 0 0 */

void SCtotempole_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //8025A820
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this->state + 4)) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    return;
  }
  return;
}


/* @description Free object instance */

void SCtotempole_free(ObjInstance *this,int param2) { //8025A8F0
  return;
}


undefined4 SCtotempole_func08(ObjInstance *this) { //8025A8F4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SCtotempole_getExtraSize(void) { //8025A8FC
  return 0xc;
}

