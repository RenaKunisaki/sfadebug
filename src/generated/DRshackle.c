
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRshackle_initialise(undefined4 param) { //802B7E4C
  return;
}


/* @description Called when DLL is unloaded */

void DRshackle_release(void) { //802B7E50
  return;
}


/* Library Function - Single Match
    dll_2B7_func03
   
   Library: KioskDefault 0 0 */

void DRshackle_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //802B7E54
  byte bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  Object_objAddObjectType(this,0x39);
  sVar2._0_1_ = objDef[1].bound;
  sVar2._1_1_ = objDef[1].cullDist;
  uVar4 = mainGetBit((int)sVar2);
  uVar4 = countLeadingZeros(uVar4);
  puVar5[0x1a] = (byte)((uVar4 >> 5 & 0xff) << 7) | puVar5[0x1a] & 0x7f;
  bVar1 = *(byte *)&objDef[1].objType;
  puVar5[0x1b] = bVar1 + (((char)bVar1 >> 1) + ((char)bVar1 < '\0' && (bVar1 & 1) != 0)) * -2;
  this->fptr_0xbc = DR_Shackle_seqFn;
  sVar3._0_1_ = objDef[1].loadFlags;
  sVar3._1_1_ = objDef[1].mapStates2;
  if (sVar3 == 1) {
    *(undefined4 *)(puVar5 + 0x14) = 2;
    puVar5[0x1c] = '\x01' - puVar5[0x1b];
  }
  else {
    *(undefined4 *)(puVar5 + 0x14) = 1;
  }
  return;
}


/* Library Function - Single Match
    dll_2B7_func04
   
   Library: KioskDefault 0 0 */

void DRshackle_update(ObjInstance *this) { //802B7F00
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  ObjInstance **ppOVar6;
  uint uVar7;
  ObjDef *pOVar8;
  ObjDef *pOVar9;
  int *piVar10;
  int local_1c;
  
  piVar10 = (int *)this->state;
  pOVar9 = this->def;
  sVar2._0_1_ = pOVar9[1].allocatedSize;
  sVar2._1_1_ = pOVar9[1].mapStates1;
  if ((sVar2 != 0) && (*piVar10 == 0)) {
    ppOVar6 = Object_playerGetObject(0x19,&local_1c);
    while( true ) {
      iVar5 = local_1c + -1;
      bVar1 = local_1c == 0;
      local_1c = iVar5;
      if (bVar1) break;
      pOVar8 = (*ppOVar6)->def;
      printf(" Rope id %i ",(uint)*(byte *)&pOVar8[1].objType);
      for (iVar5 = 0; iVar5 < piVar10[5]; iVar5 = iVar5 + 1) {
        sVar3._0_1_ = pOVar9[1].allocatedSize;
        sVar3._1_1_ = pOVar9[1].mapStates1;
        if ((uint)*(byte *)&pOVar8[1].objType == (int)sVar3 + iVar5 * 4) {
          piVar10[iVar5] = (int)*ppOVar6;
          (**(code **)(**(int **)(piVar10[iVar5] + 0x68) + 0x38))(piVar10[iVar5],0);
                    /* {@symbol 800d022c} */
          (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,piVar10[iVar5],0xffffffff);
        }
      }
      ppOVar6 = ppOVar6 + 1;
    }
  }
  if (*(char *)((int)piVar10 + 0x1a) < '\0') {
    sVar4._0_1_ = pOVar9[1].bound;
    sVar4._1_1_ = pOVar9[1].cullDist;
    uVar7 = mainGetBit((int)sVar4);
    uVar7 = countLeadingZeros(uVar7);
    *(byte *)((int)piVar10 + 0x1a) =
         (byte)((uVar7 >> 5 & 0xff) << 7) | *(byte *)((int)piVar10 + 0x1a) & 0x7f;
  }
  return;
}


/* Library Function - Single Match
    dll_2B7_func05
   
   Library: KioskDefault 0 0 */

void DRshackle_hitDetect(ObjInstance *this) { //802B8040
  float fVar1;
  float fVar2;
  float fVar3;
  ushort param3;
  bool bVar4;
  undefined *puVar5;
  int iVar6;
  double dVar7;
  
  puVar5 = this->state;
  bVar4 = FUN_80068b20((int)this,0x10);
  if ((!bVar4) && ((char)puVar5[0x1a] < '\0')) {
    fVar1 = (this->pos).pos.x - *(float *)(puVar5 + 8);
    fVar2 = (this->pos).pos.y - *(float *)(puVar5 + 0xc);
    fVar3 = (this->pos).pos.z - *(float *)(puVar5 + 0x10);
    dVar7 = sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2));
    iVar6 = 200 - (int)(dVar7 * 30.0);
    if (iVar6 < 1) {
      iVar6 = 1;
    }
    else if (200 < iVar6) {
      iVar6 = 200;
    }
    iVar6 = randInt(0,iVar6);
    if (iVar6 == 0) {
      iVar6 = randInt(0,1);
      if (iVar6 == 0) {
        param3 = 0x1dc;
      }
      else {
        param3 = 0x1dd;
      }
      audioTryStartSfx((int *)this,0x10,param3,0x50,"DRshackle.c",0xa2);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2B7_func06
   
   Library: KioskDefault 0 0 */

void DRshackle_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //802B817C
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  if ((-1 < (char)puVar3[0x1a]) && (shouldRender)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    for (iVar2 = 0; iVar2 < *(int *)(puVar3 + 0x14); iVar2 = iVar2 + 1) {
      iVar1 = *(int *)(puVar3 + iVar2 * 4);
      if (iVar1 != 0) {
        objGetAttachPointWorldPos
                  (this,(uint)(byte)puVar3[iVar2 + 0x1b],(float *)(iVar1 + 0xc),
                   (float *)(iVar1 + 0x10),(float *)(iVar1 + 0x14),FALSE);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_2B7_func07
   
   Library: KioskDefault 0 0 */

void DRshackle_free(ObjInstance *this,int param2) { //802B8238
  Object_removePlayerObj(this,0x39);
  return;
}


undefined4 DRshackle_func08(ObjInstance *this) { //802B8264
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRshackle_getExtraSize(void) { //802B826C
  return 0x20;
}


/* Library Function - Single Match
    dll_2B7_func0A
   
   Library: KioskDefault 0 0 */

void DRshackle_setScale(ObjInstance *this,float scale) { //802B8274
  short sVar1;
  int iVar2;
  ObjInstance *in_r4;
  int in_r5;
  Gfx **in_r6;
  undefined4 *in_r7;
  undefined4 *in_r8;
  undefined4 *in_r9;
  ObjDef *pOVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  pOVar3 = this->def;
  if ((char)puVar5[0x1a] < '\0') {
    *(float *)(puVar5 + 8) = (this->pos).pos.x;
    *(float *)(puVar5 + 0xc) = (this->pos).pos.y;
    *(float *)(puVar5 + 0x10) = (this->pos).pos.z;
    (this->pos).rotation.z = 0;
    (this->pos).rotation.y = 0;
    iVar2 = getAngle();
    sVar1._0_1_ = pOVar3[1].loadFlags;
    sVar1._1_1_ = pOVar3[1].mapStates2;
    (this->pos).rotation.z = (short)((int)sVar1 << 0xe) + (short)iVar2;
    iVar2 = getAngle();
    (this->pos).rotation.y = (short)iVar2;
    objGetAttachPointWorldPos
              (in_r4,in_r5,&(this->pos).pos.x,&(this->pos).pos.y,&(this->pos).pos.z,FALSE);
    objRenderCurrentModel(this,in_r6,in_r7,in_r8,in_r9);
    for (iVar2 = 0; iVar2 < *(int *)(puVar5 + 0x14); iVar2 = iVar2 + 1) {
      iVar4 = *(int *)(puVar5 + iVar2 * 4);
      if (iVar4 != 0) {
        objGetAttachPointWorldPos
                  (this,(uint)(byte)puVar5[iVar2 + 0x1b],(float *)(iVar4 + 0xc),
                   (float *)(iVar4 + 0x10),(float *)(iVar4 + 0x14),FALSE);
      }
    }
  }
  return;
}


int DRshackle_func0B(int param1) { //802B846C
  return (int)*(char *)(*(int *)(param1 + 0x4c) + 0x19);
}

