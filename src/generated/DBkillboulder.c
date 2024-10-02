
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBkillboulder_initialise(undefined4 param) { //802A0394
  return;
}


/* @description Called when DLL is unloaded */

void DBkillboulder_release(void) { //802A0398
  return;
}


/* Library Function - Single Match
    dll_288_func03
   
   Library: KioskDefault 0 0 */

void DBkillboulder_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //802A039C
  float *pfVar1;
  
  pfVar1 = (float *)this->state;
  Object_objAddObjectType(this,0x2d);
  *(undefined *)((int)&this->hitstate->sizeX2 + 1) = 0x13;
  *(undefined *)&this->hitstate->flags_0x60 = 1;
  this->hitstate->flags = this->hitstate->flags & 0xfffe;
  (this->pos).pos.x = (objDef->pos).x;
  (this->pos).pos.y = (objDef->pos).y;
  (this->pos).pos.z = (objDef->pos).z;
  (this->pos).scale =
       this->data->scale *
       ((float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].objType) - 4503599627370496.0)
       / 120.0);
  pfVar1[2] = this->data->scale *
              ((float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].objType) -
                      4503599627370496.0) / 120.0);
  *pfVar1 = *(float *)&objDef[1].loadFlags * 20.0;
  pfVar1[3] = (float)((uint)*(byte *)((int)&objDef[1].objType + 1) << 2);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa30;
    this->shadow->flags = this->shadow->flags | 0x8000;
  }
  *(undefined *)(pfVar1 + 4) = 0;
  *(undefined *)((int)pfVar1 + 0x11) = 0;
  this->shadow->flags = this->shadow->flags | 0x1000;
  return;
}


/* Library Function - Single Match
    dll_288_func04
   
   Library: KioskDefault 0 0 */

void DBkillboulder_update(ObjInstance *this) { //802A04E8
  ObjInstance *pOVar1;
  ObjInstance **ppOVar2;
  int iVar3;
  int iVar4;
  ObjDef *pOVar5;
  Shadow *pSVar6;
  float *pfVar7;
  double dVar8;
  float local_64 [2];
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  int local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  
  _savefpr_29();
  pfVar7 = (float *)this->state;
  pOVar5 = this->def;
  pOVar1 = Object_objGetMain();
                    /* {@symbol 802a0538} */
  switch(*(undefined *)(pfVar7 + 4)) {
  case 0:
    (this->pos).scale = pfVar7[2];
    this->shadow->field0_0x0 = this->data->field0_0x0;
    break;
  case 1:
    audioTryStartSfx((int *)this,1,0x213,0x7f,(char *)&PTR_DAT_80322158,0x88);
    *(byte *)((int)pfVar7 + 0x11) = *(byte *)((int)pfVar7 + 0x11) | 2;
    (this->vel).x = 0.0;
    (this->vel).z = 0.0;
    (this->vel).y = *pfVar7;
    this->shadow->field0_0x0 = 10.0;
    *(undefined *)(pfVar7 + 4) = 2;
  case 2:
    objMove((double)(this->vel).x,(double)(this->vel).y,(double)(this->vel).z,this);
    if (400.0 < (this->pos).pos.y - (pOVar5->pos).y) {
      *(undefined *)(pfVar7 + 4) = 3;
    }
    (this->pos).scale = (this->pos).scale * -(timeDelta * 0.01 - 1.0);
    break;
  case 3:
    this->shadow->flags = this->shadow->flags & 0xffffefff;
    (this->pos).scale = pfVar7[2];
    uStack_3c = randInt(-(int)pfVar7[3],(int)pfVar7[3]);
    uStack_3c = uStack_3c ^ 0x80000000;
    local_40 = 0x43300000;
    (this->pos).pos.x =
         (pOVar1->pos).pos.x + (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0);
    uStack_44 = randInt(-(int)pfVar7[3],(int)pfVar7[3]);
    uStack_44 = uStack_44 ^ 0x80000000;
    local_48 = 0x43300000;
    (this->pos).pos.z =
         (pOVar1->pos).pos.z + (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
    if (15180.0 < (this->pos).pos.z) {
      uStack_44 = randInt(300,400);
      uStack_44 = uStack_44 ^ 0x80000000;
      (this->pos).pos.z =
           (this->pos).pos.z - (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
    }
    local_48 = 0x43300000;
    ppOVar2 = Object_playerGetObject(0x2d,&local_4c);
    dVar8 = 0.0;
    local_58 = 0.0;
    local_50 = 0.0;
    local_54 = 0.0;
    for (iVar4 = 0; iVar4 < local_4c; iVar4 = iVar4 + 1) {
      if (((ppOVar2[iVar4] != this) &&
          (iVar3 = (*(code *)ppOVar2[iVar4]->dll->ptrs2->setScale)(ppOVar2[iVar4]), iVar3 == 1)) &&
         (iVar3 = (*(code *)ppOVar2[iVar4]->dll->ptrs2[1].field0_0x0)
                            (0x4069000000000000,ppOVar2[iVar4],this,local_64), iVar3 != 0)) {
        dVar8 = (double)(float)(dVar8 + 1.0);
        local_58 = local_58 + local_64[0];
        local_50 = local_50 + local_5c;
      }
    }
    if (dVar8 != 0.0) {
      local_58 = (float)((double)local_58 / dVar8);
      local_50 = (float)((double)local_50 / dVar8);
      (this->pos).pos.x = local_58;
      (this->pos).pos.z = local_50;
    }
    (this->vel).x = 0.0;
    (this->vel).z = 0.0;
    (this->vel).y = -0.4;
    FUN_800ba478((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                 (int)this,pfVar7 + 1,0);
    pfVar7[1] = (this->pos).pos.y - pfVar7[1];
    this->hitstate->flags = this->hitstate->flags | 1;
    *(undefined *)(pfVar7 + 4) = 4;
  case 4:
    (this->vel).y = (this->vel).y * 0.99999;
    (this->vel).y = (this->vel).y + -0.4;
    objMove((double)(this->vel).x,(double)(this->vel).y,(double)(this->vel).z,this);
    if ((this->pos).pos.y < pfVar7[1]) {
      if ((*(byte *)((int)pfVar7 + 0x11) & 1) != 0) {
        Object_objFreeObject(this);
      }
      *(undefined *)(pfVar7 + 4) = 5;
    }
    (this->hitstate->field12_0x3c).z = 2.242078e-44;
    (this->hitstate->field12_0x3c).y = 2.242078e-44;
    break;
  case 5:
    audioTryStartSfx((int *)this,1,0x213,0x7f,(char *)&PTR_DAT_80322158,0xd4);
    this->shadow->flags = this->shadow->flags | 0x1000;
    (this->pos).rotation.y = 0x4000;
    objSetModelNo(this,1);
    (this->pos).scale = this->data->scale * 3.0;
    pfVar7[5] = 8.407791e-44;
    *(undefined *)(pfVar7 + 4) = 6;
    break;
  case 6:
    this->shadow->flags = this->shadow->flags | 0x1000;
    (this->hitstate->field12_0x3c).z = 2.242078e-44;
    (this->hitstate->field12_0x3c).y = 2.242078e-44;
    this->hitstate->flags = this->hitstate->flags | 1;
    uStack_44 = (uint)framesThisStep;
    local_48 = 0x43300000;
    (this->pos).scale =
         (this->pos).scale *
         ((float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0) * 0.01 + 1.0);
    if ((int)pfVar7[5] < 0) {
      *(undefined *)(pfVar7 + 4) = 7;
    }
    pfVar7[5] = (float)((int)pfVar7[5] - (uint)framesThisStep);
    break;
  case 7:
    this->shadow->flags = this->shadow->flags | 0x1000;
    objSetModelNo(this,0);
    (this->pos).scale = pfVar7[2];
    *(byte *)((int)pfVar7 + 0x11) = *(byte *)((int)pfVar7 + 0x11) & 0xfd;
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    *(undefined *)(pfVar7 + 4) = 0;
    (this->pos).rotation.y = 0;
  }
  pSVar6 = this->shadow;
  iVar4 = (*(code *)this->dll->ptrs2->setScale)(this);
  if (iVar4 == 1) {
    pSVar6->flags = pSVar6->flags & 0xffffefff;
    (pSVar6->pos).x = (this->pos).pos.x;
    (pSVar6->pos).z = (this->pos).pos.z;
    (pSVar6->pos).y = (pOVar1->pos).pos.y;
  }
  else {
    pSVar6->flags = pSVar6->flags | 0x1000;
  }
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void DBkillboulder_hitDetect(ObjInstance *this) { //802A0AC0
  return;
}


/* Library Function - Single Match
    dll_288_func06
   
   Library: KioskDefault 0 0 */

void DBkillboulder_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802A0AC4
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (this->state[0x10] != '\0') {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_288_func07
   
   Library: KioskDefault 0 0 */

void DBkillboulder_free(ObjInstance *this,int param2) { //802A0B28
  Object_removePlayerObj(this,0x2d);
  return;
}


undefined4 DBkillboulder_func08(ObjInstance *this) { //802A0B54
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBkillboulder_getExtraSize(void) { //802A0B5C
  return 0x18;
}


/* Library Function - Single Match
    dll_288_func0A
   
   Library: KioskDefault 0 0 */

void DBkillboulder_setScale(ObjInstance *this,float scale) { //802A0B64
  return;
}


/* Library Function - Single Match
    dll_288_func0B
   
   Library: KioskDefault 0 0 */

void DBkillboulder_func0B(int param1,int param2) { //802A0BD4
  *(undefined4 *)(param1 + 0xc) = *(undefined4 *)(param2 + 0xc);
  *(undefined4 *)(param1 + 0x10) = *(undefined4 *)(param2 + 0x10);
  *(undefined4 *)(param1 + 0x14) = *(undefined4 *)(param2 + 0x14);
  *(undefined *)(*(int *)(param1 + 0xb8) + 0x10) = 1;
  return;
}


void DBkillboulder_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //802A0C0C
  this->state[0x11] = this->state[0x11] | 1;
  return;
}


/* Library Function - Single Match
    dll_288_func0D
   
   Library: KioskDefault 0 0 */

void DBkillboulder_render2(ObjInstance *this) { //802A0C30
  if ((this->state[0x11] & 2) != 0) {
    this->state[0x10] = 5;
  }
  return;
}


/* Library Function - Single Match
    dll_288_func0E
   
   Library: KioskDefault 0 0 */

void DBkillboulder_func0E(double param1,ObjInstance *param2,ObjInstance *param3,float *param4) { //802A0C5C
  double dVar1;
  float local_30;
  float local_2c;
  float local_28 [3];
  
  _savefpr_30();
  dVar1 = (double)objDistObj2ObjXZ(param2,param3);
  if (dVar1 < (double)(float)(param1 + 200.0)) {
    dVar1 = (double)(float)(param1 + 200.0);
    local_28[0] = (param3->pos).pos.x - (param2->pos).pos.x;
    local_2c = (param3->pos).pos.y - (param2->pos).pos.y;
    local_30 = (param3->pos).pos.z - (param2->pos).pos.z;
    if (((local_28[0] != 0.0) || (local_2c != 0.0)) || (local_30 != 0.0)) {
      normalize(local_28,&local_2c,&local_30);
    }
    *param4 = (float)((double)local_28[0] * dVar1 + (double)(param2->pos).pos.x);
    param4[1] = (float)((double)local_2c * dVar1 + (double)(param2->pos).pos.y);
    param4[2] = (float)((double)local_30 * dVar1 + (double)(param2->pos).pos.z);
  }
  _restfpr_30();
  return;
}

