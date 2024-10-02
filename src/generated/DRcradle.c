
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRcradle_initialise(undefined4 param) { //802BB668
  return;
}


/* @description Called when DLL is unloaded */

void DRcradle_release(void) { //802BB66C
  return;
}


/* Library Function - Single Match
    dll_2BD_func03
   
   Library: KioskDefault 0 0 */

void DRcradle_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802BB670
  undefined4 uVar1;
  void *pvVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  Curve *param1;
  undefined4 in_register_00004008;
  undefined8 uVar6;
  undefined8 extraout_f1;
  undefined4 local_1c;
  
  uVar6 = CONCAT44(in_register_00004008,x);
  param1 = (Curve *)this->state;
  local_1c = 1;
  iVar5 = 0;
  (this->pos).rotation.z = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  if (obj2 == (ObjInstance *)0x0) {
                    /* {@symbol 80124500} */
    iVar5 = (**(code **)(*(int *)pDll_RomCurve + 0x14))
                      ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z
                       ,&local_1c,1,0xffffffff);
    uVar6 = extraout_f1;
  }
  if (iVar5 != 0) {
                    /* {@symbol 8012464c} */
    uVar1 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))(uVar6,iVar5);
                    /* {@symbol 80124f78} */
    iVar5 = (**(code **)(*(int *)pDll_RomCurve + 0x74))(uVar1);
    iVar5 = iVar5 + -1;
    pvVar2 = mmAlloc(iVar5 * 0x30,0xff,"curves");
    param1[1].field1_0x4 = (float)pvVar2;
    param1[1].field2_0x8 = (float)((int)param1[1].field1_0x4 + iVar5 * 0x10);
    param1[1].field3_0xc = (float)((int)param1[1].field2_0x8 + iVar5 * 0x10);
    param1->field94_0x94 = FUN_8006bba0;
    param1->field95_0x98 = curveFn_80010d54;
    param1->field90_0x84 = param1[1].field1_0x4;
    param1->field91_0x88 = param1[1].field2_0x8;
    param1->field92_0x8c = param1[1].field3_0xc;
    param1->field89_0x80 = 0.0;
                    /* {@symbol 80124fe4} */
    fVar3 = (float)(**(code **)(*(int *)pDll_RomCurve + 0x78))
                             (uVar1,param1[1].field1_0x4,param1[1].field2_0x8,param1[1].field3_0xc,0
                             );
    param1->field93_0x90 = fVar3;
    curvesMove(param1);
  }
  uVar4 = mainGetBit(0x65f);
  param1[1].field_0x18 = (char)uVar4;
  param1[1].field0_0x0 = 0.0;
  param1[1].field_0x19 = 1;
  param1[1].field_0x1a = 0;
  param1[1].field_0x1c = 0;
  return;
}


/* Library Function - Single Match
    dll_2BD_func04
   
   Library: KioskDefault 0 0 */

void DRcradle_update(ObjInstance *this) { //802BB838
  int iVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  ObjInstance *pOVar7;
  ObjInstance **ppOVar8;
  uint uVar9;
  byte bVar10;
  int iVar11;
  float *pfVar12;
  double dVar13;
  double dVar14;
  int local_74;
  double local_70;
  double local_68;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  
  _savefpr_28();
  pfVar12 = (float *)this->state;
  if (*(char *)(pfVar12 + 0x2d) == '\0') {
    uVar9 = mainGetBit(0x65f);
    *(char *)(pfVar12 + 0x2d) = (char)uVar9;
    if (((((char)uVar9 != '\0') && (uVar9 = mainGetBit(0x690), uVar9 != 0)) &&
        (*(char *)(pfVar12 + 0x2d) != '\0')) &&
       ((pOVar7 = Object_objGetMain(), pOVar7 != (ObjInstance *)0x0 && (pOVar7->pMatrix != this))))
    {
      *(undefined *)(pfVar12 + 0x2d) = 0;
    }
    if (pfVar12[0x27] <= 0.0) {
      pfVar12[0x27] = 0.0;
    }
    else {
      pfVar12[0x27] = pfVar12[0x27] - 0.02;
    }
  }
  else {
    cVar3 = *(char *)(pfVar12 + 0x2e);
    *(char *)(pfVar12 + 0x2e) = cVar3 + -1;
    if (cVar3 < '\0') {
      iVar6 = randInt(0,2);
      audioTryStartSfx((int *)this,8,*(ushort *)(&DAT_803981e0 + iVar6 * 2),0x7f,
                       "DRcradle.c",0x89);
      iVar6 = randInt(0x28,0x3c);
      *(char *)(pfVar12 + 0x2e) = (char)iVar6;
    }
    if (*(char *)((int)pfVar12 + 0xb6) != '\0') {
      *(char *)((int)pfVar12 + 0xb6) = *(char *)((int)pfVar12 + 0xb6) + -1;
    }
    pOVar7 = Object_objGetMain();
    if (pOVar7 != (ObjInstance *)0x0) {
      fVar4 = (this->prevPos).x - (pOVar7->prevPos).x;
      fVar5 = (this->prevPos).y - (pOVar7->prevPos).y;
      dVar13 = (double)(this->prevPos).z;
      fVar2 = (float)(dVar13 - (double)(pOVar7->prevPos).z);
      dVar14 = (double)(fVar2 * fVar2 + fVar4 * fVar4 + fVar5 * fVar5);
      if (*(byte *)((int)pfVar12 + 0xb6) < 0xb) {
        ppOVar8 = Object_playerGetObject(0x1a,&local_74);
        iVar6 = 0;
        for (iVar11 = 0; iVar11 < local_74; iVar11 = iVar11 + 1) {
          if ((iVar6 == 0) && (objDistObj2Obj(this,ppOVar8[iVar11]), dVar13 < 120.0)) {
            iVar6 = 1;
          }
          if ((iVar6 != 2) && (objDistObj2Obj(this,ppOVar8[iVar11]), dVar13 < 40.0)) {
            iVar6 = 2;
          }
          uStack_54 = (int)*(char *)((int)pfVar12 + 0xb5) ^ 0x80000000;
          local_58 = 0x43300000;
          uStack_5c = (ppOVar8[iVar11]->flags_0xb0 & 1) * 2 - 1 ^ 0x80000000;
          local_60 = 0x43300000;
          dVar13 = 4503601774854144.0;
          local_68 = (double)CONCAT44(0x43300000,(int)(ppOVar8[iVar11]->pos).rotation.x ^ 0x80000000
                                     );
          iVar1 = (int)-(timeDelta *
                         pfVar12[0x27] * 500.0 *
                         (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0) *
                         (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0) -
                        (float)(local_68 - 4503601774854144.0));
          local_70 = (double)(longlong)iVar1;
          (ppOVar8[iVar11]->pos).rotation.x = (short)iVar1;
        }
        uVar9 = mainGetBit(0x65d);
        uVar9 = uVar9 & 0xff;
        if ((uVar9 == 0) && (*(char *)((int)pfVar12 + 0xb5) == '\0')) {
          uVar9 = 0;
        }
        if ((uVar9 != 0) && (*(char *)((int)pfVar12 + 0xb5) == -1)) {
          uVar9 = 0;
        }
        if (uVar9 == 0) {
          fVar2 = (float)(&DAT_80323f28)[iVar6];
        }
        else {
          fVar2 = 0.0;
          if (pfVar12[0x27] < 0.02) {
            pfVar12[0x27] = 0.0;
            *(char *)((int)pfVar12 + 0xb5) = -*(char *)((int)pfVar12 + 0xb5);
          }
        }
        if (pfVar12[0x27] <= fVar2) {
          if (pfVar12[0x27] < fVar2) {
            pfVar12[0x27] = pfVar12[0x27] + 0.01;
          }
        }
        else {
          pfVar12[0x27] = pfVar12[0x27] - 0.03;
        }
        local_70 = (double)CONCAT44(0x43300000,(int)*(char *)((int)pfVar12 + 0xb5) ^ 0x80000000);
        iVar6 = (int)(pfVar12[0x27] * -53.0 * (float)(local_70 - 4503601774854144.0));
        local_68 = (double)(longlong)iVar6;
        uStack_5c = -(int)(char)iVar6 ^ 0x80000000;
        local_60 = 0x43300000;
        iVar11 = FUN_8006c2c8((double)((float)((double)CONCAT44(0x43300000,uStack_5c) -
                                              4503601774854144.0) / 53.0),pfVar12);
        if (iVar11 == 0) {
          if ((pfVar12[0x1d] != 0.0) || (pfVar12[0x1f] != 0.0)) {
            iVar11 = getAngle();
            (this->pos).rotation.x = (short)iVar11 + -0x8000;
          }
        }
        else {
          pfVar12[0x27] = 0.0;
          *(char *)((int)pfVar12 + 0xb5) = -*(char *)((int)pfVar12 + 0xb5);
          if (40000.0 <= dVar14) {
            *(undefined *)((int)pfVar12 + 0xb6) = 0x14;
          }
          else {
            *(undefined *)((int)pfVar12 + 0xb6) = 0x3c;
          }
          if (*(char *)((int)pfVar12 + 0xb5) < '\x01') {
            mainSetBits(0x65d,1);
          }
          else {
            mainSetBits(0x65d,0);
          }
        }
        (this->pos).pos.x = pfVar12[0x1a];
        (this->pos).pos.y = pfVar12[0x1b];
        (this->pos).pos.z = pfVar12[0x1c];
      }
      else {
        iVar6 = 0;
      }
      for (bVar10 = 0; bVar10 < 4; bVar10 = bVar10 + 1) {
        pOVar7 = Object_findByUniqueId((int)(&PTR_DAT_80323f34)[bVar10]);
        if (pOVar7 != (ObjInstance *)0x0) {
          (*(code *)pOVar7->dll->ptrs2->setScale)(pOVar7,iVar6);
        }
      }
    }
  }
  _restfpr_28();
  return;
}


/* @description Override hit detection */

void DRcradle_hitDetect(ObjInstance *this) { //802BBD30
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DRcradle_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802BBD34
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

void DRcradle_free(ObjInstance *this,int param2) { //802BBD90
  return;
}


undefined4 DRcradle_func08(ObjInstance *this) { //802BBD94
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRcradle_getExtraSize(void) { //802BBD9C
  return 0xbc;
}

