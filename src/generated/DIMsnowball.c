
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DIMsnowball_initialise(undefined4 param) { //80226C8C
  return;
}


/* @description Called when DLL is unloaded */

void DIMsnowball_release(void) { //80226C90
  return;
}


/* Library Function - Single Match
    dll_203_func03
   
   Library: KioskDefault 0 0 */

void DIMsnowball_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80226C94
  ObjInstance *pOVar1;
  ObjInstance **ppOVar2;
  
  ppOVar2 = (ObjInstance **)this->state;
  ppOVar2[1] = (ObjInstance *)objDef->id;
  objDef->id = -1;
  pOVar1 = Object_findByUniqueId((int)ppOVar2[1]);
  *ppOVar2 = pOVar1;
  if (this->hitstate != (HitState *)0x0) {
    this->hitstate->field21_0x5b = 0;
  }
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
  }
  this->flags_0xb0 = this->flags_0xb0 | DontUseRenderCallback;
  return;
}


/* Library Function - Single Match
    dll_203_func04
   
   Library: KioskDefault 0 0 */

void DIMsnowball_update(ObjInstance *this) { //80226D1C
  int iVar1;
  float fVar2;
  u8 uVar3;
  ObjInstance *pOVar4;
  uint uVar5;
  HitState *pHVar6;
  short sVar7;
  int *piVar8;
  double dVar9;
  float local_a4 [4];
  float local_94 [4];
  float local_84 [4];
  short local_74 [6];
  longlong local_68;
  double local_60;
  double local_58;
  undefined4 local_50;
  uint uStack_4c;
  
  _savefpr_28();
  piVar8 = (int *)this->state;
  pOVar4 = Object_objGetMain();
  uVar3 = framesThisStep;
  if (*piVar8 == 0) {
    Object_objFreeObject(this);
  }
  else {
    uVar5 = (uint)framesThisStep;
    local_74[1] = (short)piVar8[2];
    if ((int)local_74[1] < DAT_80397d28 + -1) {
      local_74[0] = local_74[1] + -1;
      if ((short)(local_74[1] + -1) < 0) {
        local_74[0] = 0;
      }
      local_74[2] = local_74[1] + 1;
      if (DAT_80397d28 <= (short)(local_74[1] + 1)) {
        local_74[2] = DAT_80397d28 + -1;
      }
      local_74[3] = local_74[1] + 2;
      if (DAT_80397d28 <= (short)(local_74[1] + 2)) {
        local_74[3] = DAT_80397d28 + -1;
      }
      for (sVar7 = 0; sVar7 < 4; sVar7 = sVar7 + 1) {
        local_74[sVar7] = local_74[sVar7] * 3;
        uStack_4c = (int)*(short *)(&DAT_80316c38 + local_74[sVar7] * 2) ^ 0x80000000U;
        local_50 = 0x43300000;
        local_84[sVar7] =
             (float)((double)CONCAT44(0x43300000,
                                      (int)*(short *)(&DAT_80316c38 + local_74[sVar7] * 2) ^
                                      0x80000000U) - 4503601774854144.0) * 0.0625;
        local_58 = (double)CONCAT44(0x43300000,
                                    (int)*(short *)(&DAT_80316c38 + (local_74[sVar7] + 1) * 2) ^
                                    0x80000000);
        local_94[sVar7] = (float)(local_58 - 4503601774854144.0) * 0.0625;
        local_60 = (double)CONCAT44(0x43300000,
                                    (int)*(short *)(&DAT_80316c38 + (local_74[sVar7] + 2) * 2) ^
                                    0x80000000);
        local_a4[sVar7] = (float)(local_60 - 4503601774854144.0) * 0.0625;
      }
      if (local_94[2] - local_94[3] <= 0.0) {
        if (local_94[1] - local_94[0] <= 0.0) {
          if (*(char *)(piVar8 + 3) < '\x01') {
            dVar9 = sqrt((double)((this->vel).z * (this->vel).z +
                                 (this->vel).x * (this->vel).x + (this->vel).y * (this->vel).y));
            local_60 = (double)(longlong)(int)((float)(dVar9 * 0.5) * 127.0);
            if ((pOVar4->flags_0xb0 & SeqActive) == 0) {
              audioTryStartSfx((int *)this,1,0x40,0x7f,"DIMsnowball.c",0x218);
            }
            *(undefined *)(piVar8 + 3) = 0x1e;
          }
        }
      }
      (this->pos).pos.x = (local_84[2] - local_84[1]) * 0.0 + local_84[1];
      (this->pos).pos.y = (local_94[2] - local_94[1]) * 0.0 + local_94[1];
      (this->pos).pos.z = (local_a4[2] - local_a4[1]) * 0.0 + local_a4[1];
      (this->pos).pos.x = (this->pos).pos.x + *(float *)(*piVar8 + 0xc);
      (this->pos).pos.y = (this->pos).pos.y + *(float *)(*piVar8 + 0x10);
      (this->pos).pos.z = (this->pos).pos.z + *(float *)(*piVar8 + 0x14);
      (this->vel).x = prevOneOverTimeDelta * ((this->pos).pos.x - (this->oldPos).x);
      (this->vel).y = prevOneOverTimeDelta * ((this->pos).pos.y - (this->oldPos).y);
      (this->vel).z = prevOneOverTimeDelta * ((this->pos).pos.z - (this->oldPos).z);
      piVar8[2] = piVar8[2] + uVar5;
      if ('\0' < *(char *)(piVar8 + 3)) {
        *(u8 *)(piVar8 + 3) = *(char *)(piVar8 + 3) - uVar3;
      }
      fVar2 = (this->vel).x;
      local_60 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000);
      iVar1 = (int)-(-(this->vel).z * 1000.0 - (float)(local_60 - 4503601774854144.0));
      local_58 = (double)(longlong)iVar1;
      (this->pos).rotation.y = (short)iVar1;
      uStack_4c = (int)(this->pos).rotation.z ^ 0x80000000;
      local_50 = 0x43300000;
      iVar1 = (int)-(fVar2 * 1000.0 -
                    (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0));
      local_68 = (longlong)iVar1;
      (this->pos).rotation.z = (short)iVar1;
      pHVar6 = this->hitstate;
      if (pHVar6 != (HitState *)0x0) {
        pHVar6->flags = pHVar6->flags | 1;
        *(undefined *)((int)&pHVar6->sizeX2 + 1) = 4;
        *(undefined *)&pHVar6->flags_0x60 = 2;
        (pHVar6->field12_0x3c).y = 2.242078e-44;
        (pHVar6->field12_0x3c).z = 2.242078e-44;
      }
    }
    else {
      Object_objFreeObject(this);
    }
  }
  _restfpr_28();
  return;
}


/* Library Function - Single Match
    dll_203_func05
   
   Library: KioskDefault 0 0 */

void DIMsnowball_hitDetect(ObjInstance *this) { //802271D8
  if ((*(ushort *)(*(int *)this->state + 0xb0) & 0x40) != 0) {
    *(int *)this->state = 0;
  }
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DIMsnowball_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80227208
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

void DIMsnowball_free(ObjInstance *this,int param2) { //80227264
  return;
}


undefined4 DIMsnowball_func08(ObjInstance *this) { //80227268
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int DIMsnowball_getExtraSize(void) { //80227270
  return 0x10;
}

