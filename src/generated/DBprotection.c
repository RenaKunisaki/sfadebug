
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBprotection_initialise(undefined4 param) { //8029E810
  return;
}


/* @description Called when DLL is unloaded */

void DBprotection_release(void) { //8029E814
  return;
}


/* Library Function - Single Match
    dll_283_func03
   
   Library: KioskDefault 0 0 */

void DBprotection_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8029E818
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  uVar2 = mainGetBit((int)sVar1);
  *puVar3 = uVar2 != 0;
  puVar3[1] = 0;
  objHitFn_80089188(this,(short)(int)*(float *)(&DAT_80321f90 + (uint)(byte)puVar3[1] * 4),-5,0x28);
  this->hitstate->flags = this->hitstate->flags | 1;
  Object_ObjAnimSetMove(0.0,this,0,0);
  return;
}


/* @description Update object instance */

void DBprotection_update(ObjInstance *this) { //8029E8CC
  return;
}


/* Library Function - Single Match
    dll_283_func05
   
   Library: KioskDefault 0 0 */

void DBprotection_hitDetect(ObjInstance *this) { //8029E8D0
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  LoadedDll *dll;
  ObjDef *pOVar6;
  undefined *puVar7;
  undefined auStack_54 [8];
  float local_4c;
  float local_44;
  undefined *local_3c;
  undefined2 local_38;
  int local_34;
  longlong local_30;
  undefined4 local_28;
  uint uStack_24;
  
  puVar7 = this->state;
  pOVar6 = this->def;
  local_3c = &DAT_000a000f;
  local_38 = 0;
  iVar5 = FUN_800883e4((int)this,&local_34,(int *)0x0,(uint *)0x0);
  if (iVar5 == 0x13) {
    *(undefined2 *)(local_34 + 0x46) = 0x34d;
    if (true) {
      (**(code **)(**(int **)(local_34 + 0x68) + 0x2c))(local_34);
    }
    bVar1 = puVar7[1];
    puVar7[1] = bVar1 + 1;
    if ((uint)bVar1 == (bVar1 / 3) * 3) {
      sVar2._0_1_ = pOVar6[1].allocatedSize;
      sVar2._1_1_ = pOVar6[1].mapStates1;
      uStack_24 = (int)sVar2 ^ 0x80000000;
      local_28 = 0x43300000;
      objRunAnimation((double)((0.95 / (float)((double)CONCAT44(0x43300000,uStack_24) -
                                              4503601774854144.0)) / timeDelta),(double)timeDelta,
                      (int)this,(float *)0x0);
      local_4c = 0.8;
      local_44 = 20.0;
      dll = (LoadedDll *)runlinkDownloadCode(0x104c,1);
      (**(code **)(dll->id + 4))(this,0,auStack_54,2,0xffffffff,&local_3c);
      DLL_free(dll);
      audioTryStartSfx((int *)this,1,0x51,0x7f,"DBprotection.c",0x74);
      bVar1 = puVar7[1];
      local_30 = (longlong)(int)*(float *)(&DAT_80321f90 + (bVar1 / 3) * 4);
      objHitFn_80089188(this,(short)(int)*(float *)(&DAT_80321f90 + (bVar1 / 3) * 4),-5,0x28);
      sVar3._0_1_ = pOVar6[1].allocatedSize;
      sVar3._1_1_ = pOVar6[1].mapStates1;
      if (bVar1 / 3 == (int)sVar3) {
        *puVar7 = 1;
        this->hitstate->flags = this->hitstate->flags & 0xfffe;
        (this->pos).flags = (this->pos).flags | Invisible;
        sVar4._0_1_ = pOVar6[1].bound;
        sVar4._1_1_ = pOVar6[1].cullDist;
        mainSetBits((int)sVar4,1);
        objFreeFn_80083b54(this);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_283_func06
   
   Library: KioskDefault 0 0 */

void DBprotection_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8029EAC4
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (*this->state != '\x01')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DBprotection_free(ObjInstance *this,int param2) { //8029EB38
  return;
}


undefined4 DBprotection_func08(ObjInstance *this) { //8029EB3C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBprotection_getExtraSize(void) { //8029EB44
  return 2;
}

