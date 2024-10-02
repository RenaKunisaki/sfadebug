
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRsimplehuman_initialise(undefined4 param) { //802B4538
  return;
}


/* @description Called when DLL is unloaded */

void DRsimplehuman_release(void) { //802B453C
  return;
}


/* Library Function - Single Match
    foodRelated02AF_func03
   
   Library: KioskDefault 0 0 */

void DRsimplehuman_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //802B4540
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *local_24;
  undefined2 local_20;
  undefined *local_1c;
  undefined2 local_18;
  
  puVar5 = this->state;
  local_1c = &DAT_001e0000;
  local_18 = 0;
  local_24 = &DAT_00190019;
  local_20 = 0x19;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar2._0_1_ = objDef[1].bound;
  sVar2._1_1_ = objDef[1].cullDist;
  uVar3 = mainGetBit((int)sVar2);
  if (uVar3 != 0) {
    puVar5[0x556] = 1;
  }
  cVar1 = *(char *)((int)&objDef[1].objType + 1);
  if (cVar1 == '\x02') {
    *(undefined ***)(puVar5 + 0x54c) = &PTR_DAT_80323954;
    *(undefined **)(puVar5 + 0x544) = &LAB_802b4e40;
    *(undefined **)(puVar5 + 0x548) = &DAT_80398198;
    *(undefined **)(puVar5 + 0x540) = &DAT_803981a0;
    Object_objAddObjectType(this,4);
    if (puVar5[0x556] != '\0') {
      objFreeFn_80083b54(this);
      (this->pos).flags = (this->pos).flags | Invisible;
    }
    FUN_8008b5f8((undefined *)this);
    this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802b4bbc;
  }
  else {
    if (cVar1 < '\x02') {
      if (cVar1 != '\0') {
        if (-1 < cVar1) {
          *(undefined ***)(puVar5 + 0x54c) = &PTR_DAT_80323948;
          *(undefined **)(puVar5 + 0x544) = &LAB_802b4d44;
          *(undefined4 *)(puVar5 + 0x548) = 0;
          *(undefined **)(puVar5 + 0x540) = &DAT_803981a8;
          this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802b4bbc;
        }
        goto LAB_802b46c0;
      }
    }
    else if ('\x03' < cVar1) goto LAB_802b46c0;
    mainSetBits(0x934,0);
    mainSetBits(0x933,0);
    *(undefined **)(puVar5 + 0x54c) = &DAT_80323960;
    *(undefined **)(puVar5 + 0x544) = &LAB_802b510c;
    *(undefined4 *)(puVar5 + 0x548) = 0;
    *(undefined **)(puVar5 + 0x540) = &DAT_803981a8;
    this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802b5340;
  }
LAB_802b46c0:
  *(float *)(puVar5 + 0x550) = 0.01;
  iVar4 = randInt(0,1);
  Object_ObjAnimSetMove(0.0,this,(int)*(short *)(*(int *)(puVar5 + 0x54c) + iVar4 * 2),0);
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  DLL_createTempDll(0x33);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0xc))
            (this,puVar5,0xffffee39,0x3554,3);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x18))(puVar5,300,0x78);
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x1c))
            (puVar5,&local_24,&local_1c,3);
  puVar5[0x4a9] = puVar5[0x4a9] | 10;
  return;
}


/* Library Function - Single Match
    foodRelated02AF_func04
   
   Library: KioskDefault 0 0 */

void DRsimplehuman_update(ObjInstance *this) { //802B47A8
  float fVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  ObjInstance *this_00;
  ObjDef *pOVar5;
  short sVar6;
  undefined *puVar7;
  float local_24;
  undefined4 local_20;
  uint uStack_1c;
  
  puVar7 = this->state;
  pOVar5 = this->def;
  local_24 = 200.0;
  if ((puVar7[0x556] == '\0') && (iVar4 = (**(code **)(puVar7 + 0x544))(this), iVar4 != 0)) {
    sVar6._0_1_ = pOVar5[1].bound;
    sVar6._1_1_ = pOVar5[1].cullDist;
    mainSetBits((int)sVar6,1);
    puVar7[0x556] = 1;
  }
  sVar6 = (short)((int)*(char *)&pOVar5[1].objType << 8) - (this->pos).rotation.x;
  if (0x8000 < sVar6) {
    sVar6 = sVar6 + 1;
  }
  if (sVar6 < -0x8000) {
    sVar6 = sVar6 + -1;
  }
  if (sVar6 != 0) {
    diPrintf(" YAW DIFF ");
    if (this->animId != *(word *)(*(int *)(puVar7 + 0x54c) + 4)) {
      Object_ObjAnimSetMove(0.0,this,(int)*(short *)(*(int *)(puVar7 + 0x54c) + 4),0);
    }
    (this->pos).rotation.x = (this->pos).rotation.x + (short)(sVar6 + 1 >> 4);
    uVar3 = (uint)sVar6;
    uStack_1c = ((int)uVar3 >> 10) + (uint)((int)uVar3 < 0 && (uVar3 & 0x3ff) != 0) ^ 0x80000000;
    local_20 = 0x43300000;
    *(float *)(puVar7 + 0x550) =
         (float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0) * 0.01;
    if (sVar6 < 0) {
      iVar4 = -(int)sVar6;
    }
    else {
      iVar4 = (int)sVar6;
    }
    if (iVar4 < 0x400) {
      (this->pos).rotation.x = (short)((int)*(char *)&pOVar5[1].objType << 8);
      iVar4 = randInt(0,1);
      Object_ObjAnimSetMove(0.0,this,(int)*(short *)(*(int *)(puVar7 + 0x54c) + iVar4 * 2),0);
      *(float *)(puVar7 + 0x550) = 0.01;
    }
  }
  sVar6 = *(short *)(puVar7 + 0x554);
  uVar2 = (ushort)framesThisStep;
  *(ushort *)(puVar7 + 0x554) = sVar6 - uVar2;
  if ((short)(sVar6 - uVar2) < 0) {
    iVar4 = randInt(0x32,500);
    *(short *)(puVar7 + 0x554) = (short)iVar4;
    iVar4 = randInt(0,1);
    FUN_8009452c((int *)this,puVar7 + 0x500,(ushort *)(*(int *)(puVar7 + 0x540) + iVar4 * 4),'\0');
  }
  iVar4 = objRunAnimation((double)*(float *)(puVar7 + 0x550),(double)timeDelta,(int)this,
                          (float *)(puVar7 + 0x524));
  if (iVar4 != 0) {
    iVar4 = randInt(0,7);
    if (iVar4 == 0) {
      iVar4 = randInt(0,1);
      if (iVar4 == 0) {
        sVar6 = 4;
      }
      else {
        sVar6 = 1;
      }
    }
    else {
      sVar6 = 0;
    }
    Object_ObjAnimSetMove(0.0,this,(int)*(short *)(*(int *)(puVar7 + 0x54c) + sVar6 * 2),0);
    if (sVar6 == 0) {
      fVar1 = 0.01;
    }
    else {
      fVar1 = 0.005;
    }
    *(float *)(puVar7 + 0x550) = fVar1;
  }
  FUN_802b4fdc((int *)this,(int)(puVar7 + 0x524),*(ushort **)(puVar7 + 0x548));
  (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 4))(this,puVar7);
  FUN_800928ac((int)this,(int)(puVar7 + 0x4dc));
  exprFn_800945c0((uint)this,puVar7 + 0x500);
  this_00 = getSeqObj(1,this,&local_24);
  if (this_00 != (ObjInstance *)0x0) {
    (*this_00->dll->ptrs2[1].hitDetect)(this_00);
  }
  return;
}


/* @description Override hit detection */

void DRsimplehuman_hitDetect(ObjInstance *this) { //802B4AC4
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_2D2_func06
    foodRelated02AF_func06
    guardian_func06
   
   Library: KioskDefault 0 0 */

void DRsimplehuman_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802B4AC8
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[1]->headerSize + 0x10))(this,puVar1,0);
  }
  return;
}


/* Library Function - Single Match
    foodRelated02AF_func07
   
   Library: KioskDefault 0 0 */

void DRsimplehuman_free(ObjInstance *this,int param2) { //802B4B58
  ObjDef *pOVar1;
  
  pOVar1 = this->def;
  DLL_removeTempDll(0x33);
  if (*(char *)((int)&pOVar1[1].objType + 1) != '\0') {
    Object_removePlayerObj(this,4);
  }
  return;
}


undefined4 DRsimplehuman_func08(ObjInstance *this) { //802B4BAC
  return 0x43;
}


/* @description Get extra size for object (size of State struct) */

int DRsimplehuman_getExtraSize(void) { //802B4BB4
  return 0x55c;
}

