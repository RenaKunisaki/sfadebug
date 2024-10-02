
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DFcradle_initialise(undefined4 param) { //80237154
  return;
}


/* @description Called when DLL is unloaded */

void DFcradle_release(void) { //80237158
  return;
}


/* Library Function - Single Match
    dll_190_func03
   
   Library: KioskDefault 0 0 */

void DFcradle_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8023715C
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  float fVar4;
  uint uVar5;
  ObjInstance *pOVar6;
  Curve *param1;
  undefined4 local_24 [2];
  
  param1 = (Curve *)this->state;
  local_24[0] = 1;
  (this->pos).rotation.z = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
                    /* {@symbol 80124500} */
  iVar1 = (**(code **)(*(int *)pDll_RomCurve + 0x14))
                    ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                     local_24,1,0xffffffff);
  if (iVar1 != 0) {
                    /* {@symbol 8012464c} */
    uVar2 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))(iVar1);
                    /* {@symbol 80124f78} */
    iVar1 = (**(code **)(*(int *)pDll_RomCurve + 0x74))(uVar2);
    iVar1 = iVar1 + -1;
    pvVar3 = mmAlloc(iVar1 * 0x30,0xff,"curves");
    param1[1].field1_0x4 = (float)pvVar3;
    param1[1].field2_0x8 = (float)((int)param1[1].field1_0x4 + iVar1 * 0x10);
    param1[1].field3_0xc = (float)((int)param1[1].field2_0x8 + iVar1 * 0x10);
    param1->field94_0x94 = FUN_8006bba0;
    param1->field95_0x98 = curveFn_80010d54;
    param1->field90_0x84 = param1[1].field1_0x4;
    param1->field91_0x88 = param1[1].field2_0x8;
    param1->field92_0x8c = param1[1].field3_0xc;
    param1->field89_0x80 = 0.0;
                    /* {@symbol 80124fe4} */
    fVar4 = (float)(**(code **)(*(int *)pDll_RomCurve + 0x78))
                             (uVar2,param1[1].field1_0x4,param1[1].field2_0x8,param1[1].field3_0xc,0
                             );
    param1->field93_0x90 = fVar4;
    curvesMove(param1);
  }
  uVar5 = mainGetBit(0x19);
  param1[1].field_0x18 = (char)uVar5;
  param1[1].field0_0x0 = 0.0;
  param1[1].field_0x19 = 1;
  param1[1].field_0x1a = 0;
  param1[1].field_0x1c = 0;
  pOVar6 = Object_findByUniqueId(0x208e);
  param1[1].field4_0x10 = (pOVar6->prevPos).z * 0.4 + (pOVar6->prevPos).x;
  pOVar6 = Object_findByUniqueId(0x208f);
  param1[1].field5_0x14 = (pOVar6->prevPos).z * 0.4 + (pOVar6->prevPos).x;
  return;
}


/* Library Function - Single Match
    dll_190_func04
   
   Library: KioskDefault 0 0 */

void DFcradle_update(ObjInstance *this) { //80237350
  undefined *puVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  ObjInstance *pOVar8;
  uint uVar9;
  uint uVar10;
  ObjInstance **ppOVar11;
  int iVar12;
  byte bVar13;
  undefined *puVar14;
  float *pfVar15;
  double dVar16;
  double dVar17;
  int local_74;
  double local_70;
  double local_68;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  
  _savefpr_29();
  pfVar15 = (float *)this->state;
  if (*(char *)(pfVar15 + 0x2d) == '\0') {
    uVar9 = mainGetBit(0x19);
    *(char *)(pfVar15 + 0x2d) = (char)uVar9;
    if (pfVar15[0x27] <= 0.0) {
      pfVar15[0x27] = 0.0;
    }
    else {
      pfVar15[0x27] = pfVar15[0x27] - 0.02;
    }
  }
  else {
    cVar3 = *(char *)(pfVar15 + 0x2e);
    *(char *)(pfVar15 + 0x2e) = cVar3 + -1;
    if (cVar3 < '\0') {
      iVar7 = randInt(0,2);
      audioTryStartSfx((int *)this,1,*(ushort *)(&DAT_80397d70 + iVar7 * 2),0x7f,
                       "DFcradle.c",0x87);
      iVar7 = randInt(0x28,0x3c);
      *(char *)(pfVar15 + 0x2e) = (char)iVar7;
    }
    if (*(char *)((int)pfVar15 + 0xb6) != '\0') {
      *(char *)((int)pfVar15 + 0xb6) = *(char *)((int)pfVar15 + 0xb6) + -1;
    }
    pOVar8 = Object_objGetMain();
    if (pOVar8 != (ObjInstance *)0x0) {
      uVar9 = FUN_80237988((double)(pOVar8->prevPos).x,(double)(pOVar8->prevPos).z,(int)this,1);
      uVar10 = FUN_80237988((double)(this->prevPos).x,(double)(this->prevPos).z,(int)this,0);
      bVar6 = false;
      if ((((uVar9 & 0xff) < (uVar10 & 0xff)) && ('\0' < *(char *)((int)pfVar15 + 0xb5))) ||
         (((uVar10 & 0xff) < (uVar9 & 0xff) && (*(char *)((int)pfVar15 + 0xb5) < '\0')))) {
        bVar6 = true;
      }
      fVar4 = (this->prevPos).x - (pOVar8->prevPos).x;
      fVar5 = (this->prevPos).y - (pOVar8->prevPos).y;
      dVar16 = (double)(this->prevPos).z;
      fVar2 = (float)(dVar16 - (double)(pOVar8->prevPos).z);
      dVar17 = (double)(fVar2 * fVar2 + fVar4 * fVar4 + fVar5 * fVar5);
      if ((*(char *)((int)pfVar15 + 0xb6) == '\0') &&
         ((uVar10 & 0xff) != (uint)*(byte *)((int)pfVar15 + 0xb7))) {
        if (40000.0 <= dVar17) {
          *(undefined *)((int)pfVar15 + 0xb6) = 10;
        }
        else {
          *(undefined *)((int)pfVar15 + 0xb6) = 0x28;
        }
      }
      *(char *)((int)pfVar15 + 0xb7) = (char)uVar10;
      if (((*(char *)((int)pfVar15 + 0xb6) == '\n') && (pOVar8->pMatrix != this)) && (bVar6)) {
        *(char *)((int)pfVar15 + 0xb5) = -*(char *)((int)pfVar15 + 0xb5);
        if (*(char *)((int)pfVar15 + 0xb5) < '\x01') {
          mainSetBits(0x1c,1);
        }
        else {
          mainSetBits(0x1c,0);
        }
      }
      if (*(byte *)((int)pfVar15 + 0xb6) < 0xb) {
        ppOVar11 = Object_playerGetObject(0x1a,&local_74);
        for (iVar7 = 0; iVar7 < local_74; iVar7 = iVar7 + 1) {
          uStack_54 = (int)*(char *)((int)pfVar15 + 0xb5) ^ 0x80000000;
          local_58 = 0x43300000;
          uStack_5c = (ppOVar11[iVar7]->flags_0xb0 & 1) * 2 - 1 ^ 0x80000000;
          local_60 = 0x43300000;
          dVar16 = 4503601774854144.0;
          local_68 = (double)CONCAT44(0x43300000,(int)(ppOVar11[iVar7]->pos).rotation.x ^ 0x80000000
                                     );
          iVar12 = (int)-(timeDelta *
                          pfVar15[0x27] * 500.0 *
                          (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0) *
                          (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0) -
                         (float)(local_68 - 4503601774854144.0));
          local_70 = (double)(longlong)iVar12;
          (ppOVar11[iVar7]->pos).rotation.x = (short)iVar12;
        }
        uVar9 = mainGetBit(0x1c);
        uVar9 = uVar9 & 0xff;
        if ((uVar9 == 0) && (*(char *)((int)pfVar15 + 0xb5) == '\0')) {
          uVar9 = 0;
        }
        if ((uVar9 != 0) && (*(char *)((int)pfVar15 + 0xb5) == -1)) {
          uVar9 = 0;
        }
        if (uVar9 == 0) {
          puVar14 = &DAT_00002710;
          for (iVar7 = 0; iVar7 < local_74; iVar7 = iVar7 + 1) {
            objDistObj2Obj(this,ppOVar11[iVar7]);
            puVar1 = (undefined *)(int)dVar16;
            local_70 = (double)(longlong)(int)puVar1;
            if ((int)puVar1 < (int)puVar14) {
              puVar14 = puVar1;
            }
          }
          if ((int)puVar14 < 0x15) {
            puVar14 = (undefined *)0x14;
          }
          if (0x77 < (int)puVar14) {
            puVar14 = (undefined *)0x78;
          }
          local_70 = (double)CONCAT44(0x43300000,(uint)puVar14 ^ 0x80000000);
          pfVar15[0x27] = (((float)(local_70 - 4503601774854144.0) - 20.0) * 1.8) / 100.0 + 0.2;
        }
        else if (pfVar15[0x27] < 0.02) {
          pfVar15[0x27] = 0.0;
          *(char *)((int)pfVar15 + 0xb5) = -*(char *)((int)pfVar15 + 0xb5);
        }
        local_70 = (double)CONCAT44(0x43300000,(int)*(char *)((int)pfVar15 + 0xb5) ^ 0x80000000);
        iVar7 = (int)(pfVar15[0x27] * -53.0 * (float)(local_70 - 4503601774854144.0));
        local_68 = (double)(longlong)iVar7;
        uStack_5c = -(int)(char)iVar7 ^ 0x80000000;
        local_60 = 0x43300000;
        iVar12 = FUN_8006c2c8((double)((float)((double)CONCAT44(0x43300000,uStack_5c) -
                                              4503601774854144.0) / 53.0),pfVar15);
        if (iVar12 == 0) {
          if ((pfVar15[0x1d] != 0.0) || (pfVar15[0x1f] != 0.0)) {
            iVar12 = getAngle();
            (this->pos).rotation.x = (short)iVar12 + -0x8000;
          }
        }
        else {
          pfVar15[0x27] = 0.0;
          *(char *)((int)pfVar15 + 0xb5) = -*(char *)((int)pfVar15 + 0xb5);
          if (40000.0 <= dVar17) {
            *(undefined *)((int)pfVar15 + 0xb6) = 0x14;
          }
          else {
            *(undefined *)((int)pfVar15 + 0xb6) = 0x3c;
          }
          if (*(char *)((int)pfVar15 + 0xb5) < '\x01') {
            mainSetBits(0x1c,1);
          }
          else {
            mainSetBits(0x1c,0);
          }
        }
        (this->pos).pos.x = pfVar15[0x1a];
        (this->pos).pos.y = pfVar15[0x1b];
        (this->pos).pos.z = pfVar15[0x1c];
      }
      else {
        iVar7 = 0;
      }
      for (bVar13 = 0; bVar13 < 4; bVar13 = bVar13 + 1) {
        pOVar8 = Object_findByUniqueId((&DAT_80319300)[bVar13]);
        if (pOVar8 != (ObjInstance *)0x0) {
          (*(code *)pOVar8->dll->ptrs2->setScale)(pOVar8,iVar7);
        }
      }
    }
  }
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void DFcradle_hitDetect(ObjInstance *this) { //80237914
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DFcradle_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //80237918
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DFcradle_free(ObjInstance *this,int param2) { //80237974
  return;
}


undefined4 DFcradle_func08(ObjInstance *this) { //80237978
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DFcradle_getExtraSize(void) { //80237980
  return 0xbc;
}

