
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void crate_initialise(undefined4 param) { //801D13C8
  return;
}


/* @description Called when DLL is unloaded */

void crate_release(void) { //801D13CC
  return;
}


/* Library Function - Single Match
    dll_100_func03
   
   Library: KioskDefault 0 0 */

void crate_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //801D13D0
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  Object_objAddObjectType(this,0x40);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  DAT_80399d50 = DLL_setup(0x1003,1,FALSE);
  DAT_80399d54 = DLL_setup(0x1002,1,FALSE);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
  }
  puVar2[10] = 2;
  puVar2[0xb] = *(undefined *)((int)&objDef[1].objType + 1);
                    /* {@symbol 8012dc1c} */
  if ((puVar2[0xb] == '\0') &&
     (iVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(objDef->id), iVar1 == 0)) {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    puVar2[9] = 1;
    puVar2[8] = 0;
  }
  return;
}


/* Library Function - Single Match
    dll_100_func04
   
   Library: KioskDefault 0 0 */

void crate_update(ObjInstance *this) { //801D14CC
  float fVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  ObjInstance *pOVar5;
  ObjDef *pOVar6;
  float *pfVar7;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20 [2];
  
  pfVar7 = (float *)this->state;
  local_34 = 8;
  local_30 = 0xff;
  local_2c = 0xff;
  local_28 = 0x78;
  if (*(char *)((int)pfVar7 + 9) == '\0') {
    iVar4 = FUN_800884c8((int)this,(undefined4 *)0x0,(int *)0x0,&local_24,&local_40,&local_3c,
                         &local_38);
    if (iVar4 != 0) {
      local_24._3_1_ = *(char *)((int)pfVar7 + 10) - (char)local_24;
      *(char *)((int)pfVar7 + 10) = (char)local_24;
      if ('\0' < (char)local_24) {
        audioSfxFn_800688bc((double)local_40,(double)local_3c,(double)local_38,499,0x7f,
                            "crate.c",(int *)0x81);
        objSetModelNo(this,2 - *(char *)((int)pfVar7 + 10));
        *pfVar7 = 1.0;
        pfVar7[1] = 12.0;
        local_40 = local_40 + playerMapOffsetX;
        local_38 = local_38 + playerMapOffsetZ;
        local_44 = 1.0;
        local_48 = 0;
        local_4a = 0;
        local_4c = 0;
        (**(code **)(*DAT_80399d54 + 4))(0,1,&local_4c,0x401,0xffffffff,&local_34);
      }
    }
    if (*(char *)((int)pfVar7 + 10) < '\x01') {
      pOVar6 = this->def;
      if (*(char *)((int)pfVar7 + 0xb) == '\0') {
                    /* {@symbol 8012db54} */
        (**(code **)(*(int *)pDll_SaveGame + 100))(0x4092c00000000000,pOVar6->id);
      }
      *(undefined *)((int)pfVar7 + 9) = 1;
      *(undefined *)(pfVar7 + 2) = 0;
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,500,0x7f,"crate.c",(int *)0x9a);
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
      sVar2._0_1_ = pOVar6[1].bound;
      sVar2._1_1_ = pOVar6[1].cullDist;
      if (sVar2 != -1) {
        sVar3._0_1_ = pOVar6[1].bound;
        sVar3._1_1_ = pOVar6[1].cullDist;
        mainSetBits((int)sVar3,1);
      }
      if (*(char *)((int)pfVar7 + 0xb) == '\0') {
        pOVar6 = objAlloc(0x30,EnergyEgg);
        pOVar6[1].loadFlags = 0xff;
        pOVar6[1].mapStates2 = 0xff;
        (pOVar6->pos).x = (this->pos).pos.x;
        (pOVar6->pos).y = (this->pos).pos.y + 10.0;
        (pOVar6->pos).z = (this->pos).pos.z;
        pOVar6[1].allocatedSize = 3;
        *(undefined2 *)&pOVar6[1].id = 0xffff;
        *(undefined2 *)&pOVar6[1].pos.y = 0xffff;
        objInstantiateCharacter(pOVar6,5,(int)(char)this->mapId,-1,this->pMatrix);
      }
      else {
        local_20[0] = 50.0;
        pOVar5 = getSeqObj(5,this,local_20);
        if (pOVar5 != (ObjInstance *)0x0) {
          fVar1 = (this->pos).pos.x;
          (pOVar5->prevPos).x = fVar1;
          (pOVar5->pos).pos.x = fVar1;
          fVar1 = (this->pos).pos.y + 10.0;
          (pOVar5->prevPos).y = fVar1;
          (pOVar5->pos).pos.y = fVar1;
          fVar1 = (this->pos).pos.z;
          (pOVar5->prevPos).z = fVar1;
          (pOVar5->pos).pos.z = fVar1;
          (pOVar5->pos).rotation.x = (this->pos).rotation.x;
        }
      }
      (**(code **)(*DAT_80399d50 + 4))(this,1,0,2,0xffffffff,0);
    }
    if (0.0 < *pfVar7) {
      *pfVar7 = timeDelta * pfVar7[1] + *pfVar7;
      if (0.0 <= *pfVar7) {
        if (120.0 < *pfVar7) {
          *pfVar7 = 120.0 - (*pfVar7 - 120.0);
          pfVar7[1] = -pfVar7[1];
        }
      }
      else {
        *pfVar7 = 0.0;
      }
    }
  }
  else {
                    /* {@symbol 8012dc1c} */
    if ((*(char *)((int)pfVar7 + 0xb) == '\0') &&
       (iVar4 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(this->def->id), iVar4 != 0)) {
      *(undefined *)((int)pfVar7 + 9) = 0;
      *(undefined *)(pfVar7 + 2) = 1;
      *(undefined *)((int)pfVar7 + 10) = 2;
      this->hitstate->flags = this->hitstate->flags | 1;
      this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    }
    else {
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    }
  }
  return;
}


/* @description Override hit detection */

void crate_hitDetect(ObjInstance *this) { //801D189C
  return;
}


/* Library Function - Single Match
    dll_100_func06
   
   Library: KioskDefault 0 0 */

void crate_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //801D18A0
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  if ((*(char *)((int)pfVar2 + 9) != '\0') && (bVar1 = checkSomeDebugFlags_8017c4f8(), !bVar1)) {
    return;
  }
  if (shouldRender) {
    if (*pfVar2 != 0.0) {
      FUN_80096b14(200,0,0,(char)(int)*pfVar2);
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
    dll_100_func07
   
   Library: KioskDefault 0 0 */

void crate_free(ObjInstance *this,int param2) { //801D1950
                    /* {@symbol 800e2b88} */
  (**(code **)(*(int *)pDll_projgfx + 0x18))(this);
  DLL_free(DAT_80399d50);
  DLL_free(DAT_80399d54);
  DAT_80399d50 = (LoadedDll *)0x0;
  DAT_80399d54 = (LoadedDll *)0x0;
  Object_removePlayerObj(this,0x40);
  return;
}


undefined4 crate_func08(ObjInstance *this) { //801D19BC
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int crate_getExtraSize(void) { //801D19C4
  return 0xc;
}

