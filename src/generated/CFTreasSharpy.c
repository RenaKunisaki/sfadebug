
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFTreasSharpy_initialise(undefined4 param) { //80212D48
  return;
}


/* @description Called when DLL is unloaded */

void CFTreasSharpy_release(void) { //80212D4C
  return;
}


/* Library Function - Single Match
    dll_17C_func03
   
   Library: KioskDefault 0 0 */

void CFTreasSharpy_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //80212D50
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  undefined *puVar7;
  
  puVar7 = this->state;
  objAllocMsgQueue(this,4);
  this->fptr_0xbc = objNearFn_8021338c;
  sVar2._0_1_ = objDef[1].bound;
  sVar2._1_1_ = objDef[1].cullDist;
  if ((sVar2 == -1) ||
     (sVar3._0_1_ = objDef[1].bound, sVar3._1_1_ = objDef[1].cullDist,
     uVar6 = mainGetBit((int)sVar3), uVar6 == 0)) {
    puVar7[0x13a] = 0;
  }
  else {
    puVar7[0x13a] = 4;
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  puVar7[0x13c] = *(undefined *)((int)&objDef[1].objType + 1);
  puVar7[0x13b] = 0;
  sVar4._0_1_ = objDef[1].loadFlags;
  sVar4._1_1_ = objDef[1].mapStates2;
  if (sVar4 == 0) {
    fVar1 = 50.0;
  }
  else {
    sVar5._0_1_ = objDef[1].loadFlags;
    sVar5._1_1_ = objDef[1].mapStates2;
    fVar1 = (float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - 4503601774854144.0);
  }
  *(float *)(puVar7 + 8) = fVar1;
  *(float *)(puVar7 + 0x2c) = *(float *)(puVar7 + 8) * 0.0001;
  return;
}


/* Library Function - Single Match
    dll_17C_func04
   
   Library: KioskDefault 0 0 */

void CFTreasSharpy_update(ObjInstance *this) { //80212E34
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  ObjInstance *param2;
  uint uVar8;
  int iVar9;
  undefined uVar10;
  ObjDef *pOVar11;
  undefined *puVar12;
  double in_f1;
  double in_f2;
  double in_f3;
  double dVar13;
  
  pOVar11 = this->def;
  puVar12 = this->state;
  param2 = Object_objGetMain();
  bVar1 = puVar12[0x13a];
  if (bVar1 == 3) {
    iVar9 = FUN_80213f58((double)(*(float *)(puVar12 + 8) * 0.01),(short *)this,
                         (float *)(puVar12 + 0x30),puVar12[0x13c],puVar12 + 0x18,
                         (float *)(puVar12 + 0x2c));
    if ((iVar9 != 0) &&
       (puVar12[0x13a] = 4, sVar3._0_1_ = pOVar11[1].bound, sVar3._1_1_ = pOVar11[1].cullDist,
       sVar3 != -1)) {
      sVar4._0_1_ = pOVar11[1].bound;
      sVar4._1_1_ = pOVar11[1].cullDist;
      mainSetBits((int)sVar4,1);
    }
    if ((*(int *)(puVar12 + 0xcc) != 0) && (*(char *)(*(int *)(puVar12 + 0xcc) + 0x31) != '\0')) {
      sVar5._0_1_ = pOVar11[1].bound;
      sVar5._1_1_ = pOVar11[1].cullDist;
      mainSetBits((int)sVar5,1);
    }
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      objDistObj2Obj(this,param2);
      dVar13 = 200.0;
      sVar2._0_1_ = pOVar11[1].allocatedSize;
      sVar2._1_1_ = pOVar11[1].mapStates1;
      if (((double)((float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) -
                           4503601774854144.0) + 200.0) < in_f1) ||
         (uVar8 = mainGetBit((int)*(short *)&pOVar11[1].pos.x), uVar8 != 0)) {
        printf(" HELLO ");
        puVar12[0x13a] = 0;
      }
      else {
        objDistObj2Obj(this,param2);
        if (100.0 <= in_f1) {
          iVar9 = FUN_80213424(400.0,(double)(*(float *)(puVar12 + 8) * 0.01),dVar13,this);
          if (iVar9 != 0) {
            puVar12[0x13a] = 2;
            *(short *)(puVar12 + 0x138) = (this->pos).rotation.x;
          }
        }
        else {
          printf(" GOODBYE ");
          FUN_80213e58((int)this,(uint)(byte)puVar12[0x13c],(undefined4 *)(puVar12 + 0x18),2);
          puVar12[0x13a] = 3;
        }
      }
    }
    else if (bVar1 == 0) {
      if (true) {
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
        puVar12[0x13a] = 1;
      }
    }
    else {
      iVar9 = FUN_80213504(in_f1,in_f2,in_f3,this);
      if (iVar9 != 0) {
        puVar12[0x13a] = 1;
      }
    }
  }
  else if (bVar1 == 5) {
    FUN_80088da4((int)this);
    *(float *)(puVar12 + 4) = timeDelta * 0.02 + *(float *)(puVar12 + 4);
    *(float *)(puVar12 + 0x2c) = 0.008;
    if ((puVar12[0x13b] != '\0') &&
       (puVar12[0x13a] = 4, sVar6._0_1_ = pOVar11[1].bound, sVar6._1_1_ = pOVar11[1].cullDist,
       sVar6 != -1)) {
      sVar7._0_1_ = pOVar11[1].bound;
      sVar7._1_1_ = pOVar11[1].cullDist;
      mainSetBits((int)sVar7,1);
    }
  }
  else if (bVar1 < 5) {
    *(float *)(puVar12 + 4) = 0.0;
    objFreeFn_80083b54(this);
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    (this->pos).flags = (this->pos).flags | Invisible;
  }
  uVar10 = objRunAnimation((double)*(float *)(puVar12 + 0x2c),
                           (double)(float)((double)CONCAT44(0x43300000,(uint)framesThisStep) -
                                          4503599627370496.0),(int)this,(float *)0x0);
  puVar12[0x13b] = uVar10;
  return;
}


/* Library Function - Single Match
    dll_17C_func05
   
   Library: KioskDefault 0 0 */

void CFTreasSharpy_hitDetect(ObjInstance *this) { //80213100
  int iVar1;
  uint *puVar2;
  undefined4 uStack_1c;
  longlong local_18;
  
  puVar2 = (uint *)this->state;
  iVar1 = FUN_800883e4((int)this,&uStack_1c,(int *)0x0,(uint *)0x0);
  if ((iVar1 != 0) &&
     (*(byte *)((int)puVar2 + 0x13d) = *(byte *)((int)puVar2 + 0x13d) & 0x7f, iVar1 != 0x13)) {
    this->flags_0xaf = this->flags_0xaf & ModelDisableFlag08;
    *(undefined *)((int)puVar2 + 0x13a) = 5;
    audioTryStartSfx((int *)this,1,0x1ca,0x7f,"CFTreasSharpy.c",0x129);
    Object_ObjAnimSetMove(0.0,this,0x23,0);
    if (*puVar2 != 0) {
      local_18 = (longlong)(int)(float)puVar2[2];
      objSendMsg(*puVar2,0x11,*puVar2,(int)(float)puVar2[2]);
    }
  }
  return;
}


/* Library Function - Single Match
    dll_17C_func06
   
   Library: KioskDefault 0 0 */

void CFTreasSharpy_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802131E4
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  float local_18;
  float local_14;
  float local_10 [2];
  
  puVar1 = this->state;
  if ((shouldRender) && (puVar1[0x13a] != '\x04')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (this->data->noplacements != 0) {
      objGetAttachPointWorldPos(this,0,local_10,&local_14,&local_18,FALSE);
      objGetAttachPointWorldPos
                (this,1,(float *)(puVar1 + 0xc),(float *)(puVar1 + 0x10),(float *)(puVar1 + 0x14),
                 FALSE);
      *(float *)(puVar1 + 0xc) = (*(float *)(puVar1 + 0xc) + local_10[0]) * 0.5;
      *(float *)(puVar1 + 0x10) = (*(float *)(puVar1 + 0x10) + local_14) * 0.5;
      *(float *)(puVar1 + 0x14) = (*(float *)(puVar1 + 0x14) + local_18) * 0.5;
    }
    if (0.0 < *(float *)(puVar1 + 4)) {
      if (*(float *)(puVar1 + 4) < 2.3) {
                    /* {@symbol 800ea278} */
        (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x32f,puVar1 + 4);
      }
      if (1.2 < *(float *)(puVar1 + 4)) {
                    /* {@symbol 800ea278} */
        (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar1 + 4);
                    /* {@symbol 800ea278} */
        (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar1 + 4);
      }
    }
  }
  return;
}


/* @description Free object instance */

void CFTreasSharpy_free(ObjInstance *this,int param2) { //80213378
  return;
}


undefined4 CFTreasSharpy_func08(ObjInstance *this) { //8021337C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int CFTreasSharpy_getExtraSize(void) { //80213384
  return 0x140;
}

