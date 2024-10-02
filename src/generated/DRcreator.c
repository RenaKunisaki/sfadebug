
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRcreator_initialise(undefined4 param) { //802B53E4
  return;
}


/* @description Called when DLL is unloaded */

void DRcreator_release(void) { //802B53E8
  return;
}


/* Library Function - Single Match
    dll_2AE_func03
   
   Library: KioskDefault 0 0 */

void DRcreator_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802B53EC
  int iVar1;
  uint *puVar2;
  
  puVar2 = (uint *)this->state;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].bound << 8);
  *(ObjDefEnum *)(puVar2 + 1) = objDef[1].objType;
  *(undefined2 *)((int)puVar2 + 6) = *(undefined2 *)&objDef[1].loadFlags;
  iVar1 = randInt(0,(int)*(short *)((int)puVar2 + 6));
  *(short *)(puVar2 + 2) = (short)iVar1;
  *(short *)((int)puVar2 + 10) = (short)(char)objDef[1].cullDist;
  *puVar2 = (uint)*(byte *)&objDef[1].pos.x;
  return;
}


/* Library Function - Single Match
    dll_2AE_func04
   
   Library: KioskDefault 0 0 */

void DRcreator_update(ObjInstance *this) { //802B5468
  short sVar1;
  ushort uVar2;
  uint uVar3;
  ObjDef *pOVar4;
  int iVar5;
  ObjInstance *pOVar6;
  undefined *puVar7;
  uint local_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  puVar7 = this->state;
  sVar1._0_1_ = this->def[1].allocatedSize;
  sVar1._1_1_ = this->def[1].mapStates1;
  if (sVar1 == 1) {
    uVar3 = mainGetBit((int)*(short *)(puVar7 + 4));
    if ((((uVar3 < 0x28) || (*(short *)(puVar7 + 4) == -1)) &&
        (*(ushort *)(puVar7 + 8) = *(short *)(puVar7 + 8) - (ushort)framesThisStep,
        *(short *)(puVar7 + 8) < 1)) &&
       ((Object_playerGetObject(4,(int *)&local_34), (int)local_34 < 0xb &&
        (local_34 = mainGetBit((int)*(short *)(puVar7 + 4)), (int)local_34 < 0x29)))) {
      pOVar4 = objAlloc(0x38,HoodedZyck);
      iVar5 = randInt(-0x7f,0x7e);
      *(char *)((int)&pOVar4[1].pos.z + 2) = (char)iVar5;
      uStack_2c = randInt(-0x1e,0x1e);
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      (pOVar4->pos).x =
           (this->pos).pos.x + (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0);
      (pOVar4->pos).y = (this->pos).pos.y;
      uStack_24 = randInt(-0x1e,0x1e);
      uStack_24 = uStack_24 ^ 0x80000000;
      local_28 = 0x43300000;
      (pOVar4->pos).z =
           (this->pos).pos.z + (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0);
      pOVar6 = objInstantiateCharacter(pOVar4,5,(int)(char)this->mapId,-1,this->pMatrix);
      if (pOVar6 != (ObjInstance *)0x0) {
        DAT_8039a150 = DAT_8039a150 + 1;
      }
      iVar5 = randInt(0,(int)*(short *)(puVar7 + 10));
      *(short *)(puVar7 + 8) = *(short *)(puVar7 + 6) + (short)iVar5;
    }
  }
  else if (sVar1 < 1) {
    if (-1 < sVar1) {
      if (*(short *)(puVar7 + 0x10) != 0) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))
                  (*(undefined4 *)(puVar7 + 0x14),0x681,0,2,0xffffffff,0);
        sVar1 = *(short *)(puVar7 + 0x10);
        uVar2 = (ushort)framesThisStep;
        *(ushort *)(puVar7 + 0x10) = sVar1 - uVar2;
        if ((short)(sVar1 - uVar2) < 0) {
          *(undefined2 *)(puVar7 + 0x10) = 0;
        }
      }
      uVar3 = mainGetBit((int)*(short *)(puVar7 + 4));
      if ((((uVar3 == 0) || (*(short *)(puVar7 + 4) == -1)) &&
          (*(ushort *)(puVar7 + 8) = *(short *)(puVar7 + 8) - (ushort)framesThisStep,
          *(short *)(puVar7 + 8) < 1)) &&
         (Object_playerGetObject(4,(int *)&local_34), (int)local_34 < 0x15)) {
        audioTryStartSfx((int *)this,0x10,0x107,0x7f,(char *)&PTR_DAT_80323a20,0x85);
        pOVar4 = objAlloc(0x24,DR_BigSkeet);
        iVar5 = randInt(-0x7f,0x7e);
        *(char *)&pOVar4[1].objType = (char)iVar5;
        uStack_24 = randInt(-0x1e,0x1e);
        uStack_24 = uStack_24 ^ 0x80000000;
        local_28 = 0x43300000;
        (pOVar4->pos).x =
             (this->pos).pos.x +
             (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0);
        (pOVar4->pos).y = (this->pos).pos.y;
        uStack_2c = randInt(-0x1e,0x1e);
        uStack_2c = uStack_2c ^ 0x80000000;
        local_30 = 0x43300000;
        (pOVar4->pos).z =
             (this->pos).pos.z +
             (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0);
        pOVar4[1].allocatedSize = 0xb;
        pOVar4[1].mapStates1 = 0xb8;
        pOVar4[1].loadFlags = 0;
        pOVar4[1].mapStates2 = 0x14;
        *(undefined *)((int)&pOVar4[1].objType + 1) = 5;
        pOVar6 = objInstantiateCharacter(pOVar4,5,(int)(char)this->mapId,-1,this->pMatrix);
        if (pOVar6 != (ObjInstance *)0x0) {
          *(ObjInstance **)(puVar7 + 0x14) = pOVar6;
          *(undefined2 *)(puVar7 + 0x10) = 0x78;
          DAT_8039a150 = DAT_8039a150 + 1;
        }
        uVar3 = mainGetBit(0x789);
        iVar5 = randInt(0,(int)*(short *)(puVar7 + 10));
        *(short *)(puVar7 + 8) =
             (short)((int)((int)*(short *)(puVar7 + 6) * (3 - uVar3)) / 3) + (short)iVar5;
      }
    }
  }
  else if (((sVar1 < 3) && (uVar3 = mainGetBit((int)*(short *)(puVar7 + 4)), uVar3 != 0)) &&
          (*(ushort *)(puVar7 + 8) = *(short *)(puVar7 + 8) - (ushort)framesThisStep,
          *(short *)(puVar7 + 8) < 1)) {
    pOVar4 = objAlloc(0x24,DRCollapseP);
    pOVar4->mapStates2 = 1;
    pOVar4->loadFlags = isManualLoad;
    (pOVar4->pos).y = (this->pos).pos.y;
    (pOVar4->pos).x = (this->pos).pos.x;
    (pOVar4->pos).z = (this->pos).pos.z;
    *(undefined2 *)&pOVar4[1].pos.x = 0xffff;
    pOVar4[1].bound = 0xff;
    pOVar4[1].cullDist = 0xff;
    iVar5 = randInt(0,0x7f);
    *(char *)&pOVar4[1].objType = (char)iVar5;
    iVar5 = randInt(800,1000);
    pOVar4[1].allocatedSize = (char)((ushort)(short)iVar5 >> 8);
    pOVar4[1].mapStates1 = (char)(short)iVar5;
    pOVar6 = objInstantiateCharacter(pOVar4,5,(int)(char)this->mapId,-1,this->pMatrix);
    uStack_2c = randInt(-0x32,0x32);
    uStack_2c = uStack_2c ^ 0x80000000;
    local_30 = 0x43300000;
    (pOVar6->vel).x = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 0.005;
    uStack_24 = randInt(-0x32,0x32);
    uStack_24 = uStack_24 ^ 0x80000000;
    local_28 = 0x43300000;
    (pOVar6->vel).z = (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) * 0.005;
    iVar5 = randInt(0,(int)*(short *)(puVar7 + 10));
    *(short *)(puVar7 + 8) = *(short *)(puVar7 + 6) + (short)iVar5;
  }
  return;
}


/* @description Override hit detection */

void DRcreator_hitDetect(ObjInstance *this) { //802B5938
  return;
}


/* Library Function - Single Match
    dll_2AE_func06
   
   Library: KioskDefault 0 0 */

void DRcreator_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802B593C
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int *piVar2;
  
  piVar2 = (int *)this->state;
  bVar1 = checkSomeDebugFlags_8017c4f8();
  if ((bVar1) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (double)(float)((double)CONCAT44(0x43300000,*piVar2 << 4 ^ 0x80000000) -
                                4503601774854144.0),20.0,
                 (Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),0xff,0xff,0xff);
  }
  return;
}


/* @description Free object instance */

void DRcreator_free(ObjInstance *this,int param2) { //802B59FC
  return;
}


undefined4 DRcreator_func08(ObjInstance *this) { //802B5A00
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRcreator_getExtraSize(void) { //802B5A08
  return 0x18;
}

