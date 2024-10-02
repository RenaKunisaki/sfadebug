
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBrockfall_initialise(undefined4 param) { //80290CEC
  return;
}


/* @description Called when DLL is unloaded */

void DBrockfall_release(void) { //80290CF0
  return;
}


/* Library Function - Single Match
    dll_26A_func03
   
   Library: KioskDefault 0 0 */

void DBrockfall_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80290CF4
  short sVar1;
  int iVar2;
  ObjInstance *pOVar3;
  undefined *puVar4;
  float *pfVar5;
  
  iVar2 = randInt(0,1);
  pfVar5 = (float *)this->state;
  sVar1._0_1_ = objDef[1].bound;
  sVar1._1_1_ = objDef[1].cullDist;
  puVar4 = (&PTR_PTR_DAT_80320cd4)[sVar1];
  pfVar5[3] = *(float *)(puVar4 + (short)iVar2 * 8 + 4);
  *(undefined2 *)(pfVar5 + 4) = *(undefined2 *)(puVar4 + (short)iVar2 * 8);
  pfVar5[6] = 0.0;
  *(undefined *)(pfVar5 + 7) = 0xff;
  pfVar5[5] = (float)objDef->id;
  objDef->id = -1;
  pOVar3 = Object_findByUniqueId((int)pfVar5[5]);
  if (pOVar3 != (ObjInstance *)0x0) {
    *pfVar5 = (pOVar3->pos).pos.x;
    pfVar5[1] = (pOVar3->pos).pos.y;
    pfVar5[2] = (pOVar3->pos).pos.z;
  }
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
  }
  DAT_8039a0c8 = runlinkDownloadCode(0x1020,1);
  this->newOpacity = 0;
  return;
}


/* Library Function - Single Match
    dll_26A_func04
   
   Library: KioskDefault 0 0 */

void DBrockfall_update(ObjInstance *this) { //80290DF0
  float fVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  ObjDef *pOVar8;
  uint uVar9;
  HitState *pHVar10;
  short sVar11;
  float *pfVar12;
  float local_ac [4];
  float local_9c [4];
  float local_8c [4];
  short local_7c [6];
  longlong local_70;
  double local_68;
  double local_60;
  undefined4 local_58;
  uint uStack_54;
  
  _savefpr_27();
  pOVar8 = this->def;
  pfVar12 = (float *)this->state;
  uVar9 = (uint)framesThisStep;
  cVar4 = (char)((int)uVar9 >> 1);
  if (*(char *)(pfVar12 + 7) < '\x01') {
    if (((int)pfVar12[6] < 0x3c) && (0x1e < (int)pfVar12[6])) {
      sVar11._0_1_ = pOVar8[1].bound;
      sVar11._1_1_ = pOVar8[1].cullDist;
      mainSetBits((int)(&PTR_DAT_8031e720)[sVar11],1);
    }
    this->newOpacity = 0xff;
    if ((int)pfVar12[6] < 0x19) {
      this->newOpacity = SUB41(pfVar12[6],0) * '\n';
    }
    else if ((int)*(short *)(pfVar12 + 4) - (int)pfVar12[6] < 0x19) {
      this->newOpacity = ((char)*(undefined2 *)(pfVar12 + 4) - SUB41(pfVar12[6],0)) * '\n';
    }
    else {
      this->newOpacity = 0xff;
    }
    local_7c[1] = SUB42(pfVar12[6],0);
    if (((int)*(short *)(pfVar12 + 4) - (int)pfVar12[6] < 0x14) &&
       (0x11 < (int)*(short *)(pfVar12 + 4) - (int)pfVar12[6])) {
      (**(code **)(*DAT_8039a0c8 + 4))(this,0x20,0,1,0xffffffff,0);
                    /* {@symbol 800dac04} */
      (**(code **)(*(int *)pDll_TrickyWalk + 0x10))
                ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 0x4039000000000000);
      uStack_54 = randInt(1,10);
      uStack_54 = uStack_54 ^ 0x80000000;
      local_58 = 0x43300000;
                    /* {@symbol 800db230} */
      (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                ((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (double)(float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0),
                 (int)(this->pos).rotation.x,1);
    }
    if ((int)local_7c[1] < *(short *)(pfVar12 + 4) + -1) {
      local_7c[0] = local_7c[1] + -1;
      if ((short)(local_7c[1] + -1) < 0) {
        local_7c[0] = 0;
      }
      local_7c[2] = local_7c[1] + 1;
      if (*(short *)(pfVar12 + 4) <= (short)(local_7c[1] + 1)) {
        local_7c[2] = *(short *)(pfVar12 + 4) + -1;
      }
      local_7c[3] = local_7c[1] + 2;
      if (*(short *)(pfVar12 + 4) <= (short)(local_7c[1] + 2)) {
        local_7c[3] = *(short *)(pfVar12 + 4) + -1;
      }
      for (sVar11 = 0; sVar11 < 4; sVar11 = sVar11 + 1) {
        local_7c[sVar11] = local_7c[sVar11] * 3;
        uStack_54 = (int)*(short *)((int)pfVar12[3] + local_7c[sVar11] * 2) ^ 0x80000000;
        local_58 = 0x43300000;
        local_8c[sVar11] =
             (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0) * 0.0625;
        local_60 = (double)CONCAT44(0x43300000,
                                    (int)*(short *)((int)pfVar12[3] + (local_7c[sVar11] + 1) * 2) ^
                                    0x80000000);
        local_9c[sVar11] = (float)(local_60 - 4503601774854144.0) * 0.0625;
        local_68 = (double)CONCAT44(0x43300000,
                                    (int)*(short *)((int)pfVar12[3] + (local_7c[sVar11] + 2) * 2) ^
                                    0x80000000);
        local_ac[sVar11] = (float)(local_68 - 4503601774854144.0) * 0.0625;
      }
      fVar1 = local_9c[2] - local_9c[3];
      fVar5 = local_9c[1] - local_9c[0];
      fVar6 = (local_8c[2] - local_8c[3]) * (local_8c[2] - local_8c[3]) +
              (local_ac[2] - local_ac[3]) * (local_ac[2] - local_ac[3]);
      if (((fVar6 != 0.0) &&
          (1.2 < ((local_8c[1] - local_8c[0]) * (local_8c[1] - local_8c[0]) +
                 (local_ac[1] - local_ac[0]) * (local_ac[1] - local_ac[0])) / fVar6)) &&
         (0x14 < (int)*(short *)(pfVar12 + 4) - (int)pfVar12[6])) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x35f,0,0,0xffffffff,0);
        iVar7 = randInt(0,1);
        audioTryStartSfx((int *)this,8,*(ushort *)((int)&PTR_DAT_80398018 + iVar7 * 2),0x7f,
                         "DBrockfall.c",0x31b);
      }
      if (fVar1 <= 0.0) {
        if (fVar5 <= 0.0) {
          if (*(char *)((int)pfVar12 + 0x1d) < '\x01') {
            sqrt((double)((this->vel).z * (this->vel).z +
                         (this->vel).x * (this->vel).x + (this->vel).y * (this->vel).y));
            *(undefined *)((int)pfVar12 + 0x1d) = 0x1e;
          }
        }
      }
      (this->pos).pos.x = (local_8c[2] - local_8c[1]) * 0.0 + local_8c[1];
      (this->pos).pos.y = (local_9c[2] - local_9c[1]) * 0.0 + local_9c[1];
      (this->pos).pos.z = (local_ac[2] - local_ac[1]) * 0.0 + local_ac[1];
      (this->pos).pos.x = (this->pos).pos.x + *pfVar12;
      (this->pos).pos.y = (this->pos).pos.y + pfVar12[1];
      (this->pos).pos.z = (this->pos).pos.z + pfVar12[2];
      (this->vel).x = prevOneOverTimeDelta * ((this->pos).pos.x - (this->oldPos).x);
      (this->vel).y = prevOneOverTimeDelta * ((this->pos).pos.x - (this->oldPos).x);
      (this->vel).z = prevOneOverTimeDelta * ((this->pos).pos.x - (this->oldPos).x);
      pfVar12[6] = (float)((int)pfVar12[6] + ((int)uVar9 >> 1));
      if ('\0' < *(char *)((int)pfVar12 + 0x1d)) {
        *(char *)((int)pfVar12 + 0x1d) = *(char *)((int)pfVar12 + 0x1d) - cVar4;
      }
      fVar1 = (this->vel).x;
      local_68 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000);
      iVar7 = (int)-(-(this->vel).z * 10.0 * 1000.0 - (float)(local_68 - 4503601774854144.0));
      local_60 = (double)(longlong)iVar7;
      (this->pos).rotation.y = (short)iVar7;
      uStack_54 = (int)(this->pos).rotation.z ^ 0x80000000;
      local_58 = 0x43300000;
      iVar7 = (int)-(fVar1 * 10.0 * 1000.0 -
                    (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0));
      local_70 = (longlong)iVar7;
      (this->pos).rotation.z = (short)iVar7;
      pHVar10 = this->hitstate;
      if (pHVar10 != (HitState *)0x0) {
        pHVar10->flags = pHVar10->flags | 1;
        *(undefined *)((int)&pHVar10->sizeX2 + 1) = 0x15;
        *(undefined *)&pHVar10->flags_0x60 = 1;
        (pHVar10->field12_0x3c).y = 2.242078e-44;
        (pHVar10->field12_0x3c).z = 2.242078e-44;
      }
    }
    else {
      iVar7 = randInt(10,100);
      *(char *)(pfVar12 + 7) = (char)iVar7;
      *(undefined *)((int)pfVar12 + 0x1e) = 1;
    }
  }
  else {
    sVar2._0_1_ = pOVar8[1].bound;
    sVar2._1_1_ = pOVar8[1].cullDist;
    uVar9 = mainGetBit((int)(&PTR_DAT_8031e720)[sVar2]);
    if (uVar9 != 0) {
      sVar3._0_1_ = pOVar8[1].bound;
      sVar3._1_1_ = pOVar8[1].cullDist;
      mainSetBits((int)(&PTR_DAT_8031e720)[sVar3],0);
    }
    *(char *)(pfVar12 + 7) = *(char *)(pfVar12 + 7) - cVar4;
    pfVar12[6] = 0.0;
  }
  _restfpr_27();
  return;
}


/* @description Override hit detection */

void DBrockfall_hitDetect(ObjInstance *this) { //80291544
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DBrockfall_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80291548
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


/* Library Function - Single Match
    dll_26A_func07
   
   Library: KioskDefault 0 0 */

void DBrockfall_free(ObjInstance *this,int param2) { //802915A4
  DLL_free(DAT_8039a0c8);
  DAT_8039a0c8 = (LoadedDll *)0x0;
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 DBrockfall_func08(ObjInstance *this) { //802915EC
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int DBrockfall_getExtraSize(void) { //802915F4
  return 0x20;
}

