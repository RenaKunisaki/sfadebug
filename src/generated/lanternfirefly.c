
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void fireflyLantern_initialise(undefined4 param) { //801EA574
  return;
}


/* @description Called when DLL is unloaded */

void fireflyLantern_release(void) { //801EA578
  return;
}


/* Library Function - Single Match
    fireflyLantern_func03
   
   Library: KioskDefault 0 0 */

void fireflyLantern_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //801EA57C
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)this->state;
  Object_objAddObjectType(this,0x32);
  puVar2[1] = 0.0;
  puVar2[5] = 0.0;
  puVar2[9] = 0.0;
  puVar2[2] = 0.0;
  puVar2[6] = 0.0;
  puVar2[10] = 0.0;
  puVar2[3] = 0.0;
  puVar2[7] = 0.0;
  puVar2[0xb] = 0.0;
  puVar2[4] = 0.0;
  puVar2[8] = 0.0;
  puVar2[0xc] = 0.0;
  *puVar2 = 0;
  *(undefined *)((int)puVar2 + 0x6e) = 0;
  puVar2[0x11] = 0.08;
  puVar2[0x12] = 0.0275;
  puVar2[0x10] = 1.0;
  *(undefined *)(puVar2 + 0x1b) = 0;
  *(undefined *)((int)puVar2 + 0x6b) = 0;
  iVar1 = randInt(500,0x5dc);
  *(short *)((int)puVar2 + 0x66) = (short)iVar1;
  iVar1 = randInt(0,65000);
  *(short *)(puVar2 + 0x19) = (short)iVar1;
  *(undefined2 *)(puVar2 + 0x1a) = 4;
  *(undefined *)((int)puVar2 + 0x6a) = *(undefined *)((int)&objDef[1].objType + 1);
  puVar2[0x13] = 0.0;
  puVar2[0x14] = 5.0;
  puVar2[0x15] = (objDef->pos).x;
  puVar2[0x16] = (objDef->pos).y;
  puVar2[0x17] = (objDef->pos).z;
  *(undefined *)((int)puVar2 + 0x6f) = 0;
  *(byte *)(puVar2 + 0x1c) = *(byte *)(puVar2 + 0x1c) & 0x3f;
  return;
}


/* Library Function - Single Match
    fireflyLantern_func04
   
   Library: KioskDefault 0 0 */

void fireflyLantern_update(ObjInstance *param1) { //801EA6E4
  ObjInstance *pOVar1;
  ObjDef *def;
  int iVar2;
  bool bVar3;
  undefined4 param2;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  vec3f *in_r5;
  uint uVar4;
  uint uVar5;
  ObjInstance **ppOVar6;
  double dVar7;
  undefined local_74 [4];
  undefined2 local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  longlong local_30;
  
  ppOVar6 = (ObjInstance **)param1->state;
  Object_objGetMain();
  (param1->oldPos).x = (param1->pos).pos.x;
  (param1->oldPos).y = (param1->pos).pos.y;
  (param1->oldPos).z = (param1->pos).pos.z;
  if (1.0 < (float)ppOVar6[0x10]) {
    dVar7 = (double)(float)ppOVar6[0x10];
    ppOVar6[0x10] = (ObjInstance *)(float)(dVar7 - 1.0);
    if (*(byte *)(ppOVar6 + 0x1b) < 4) {
      dVar7 = (double)FUN_801eaf1c((int)param1);
    }
    else if (*(char *)(ppOVar6 + 0x1b) == '\a') {
      *(undefined *)(ppOVar6 + 0x1b) = 0;
    }
    else {
      *(char *)(ppOVar6 + 0x1b) = *(char *)(ppOVar6 + 0x1b) + '\x01';
    }
    FUN_801eae28(dVar7,param1);
  }
  dVar7 = FUN_8006b9dc((double)(float)ppOVar6[0x10],(float *)(ppOVar6 + 1),(float *)0x0);
  (param1->pos).pos.x = (float)((double)(float)ppOVar6[0x15] + dVar7);
  dVar7 = FUN_8006b9dc((double)(float)ppOVar6[0x10],(float *)(ppOVar6 + 5),(float *)0x0);
  (param1->pos).pos.y = (float)((double)(float)ppOVar6[0x16] + dVar7);
  dVar7 = FUN_8006b9dc((double)(float)ppOVar6[0x10],(float *)(ppOVar6 + 9),(float *)0x0);
  (param1->pos).pos.z = (float)((double)(float)ppOVar6[0x17] + dVar7);
  if (*(byte *)(ppOVar6 + 0x1c) >> 6 == 1) {
    pOVar1 = Object_objGetMain();
    objDistObj2Obj(param1,pOVar1);
    ppOVar6[0x11] = (ObjInstance *)(float)(dVar7 * 0.001500000013038516 + 9.999999747378752e-05);
  }
  ppOVar6[0x10] = (ObjInstance *)((float)ppOVar6[0x11] * timeDelta + (float)ppOVar6[0x10]);
  if ((*ppOVar6 != (ObjInstance *)0x0) && (((*ppOVar6)->flags_0xb0 & IsFreed) != 0)) {
    *(undefined *)((int)ppOVar6 + 0x6e) = 0;
    *ppOVar6 = (ObjInstance *)0x0;
  }
  if ((*(char *)((int)ppOVar6 + 0x6a) == '\x01') || (*(char *)((int)ppOVar6 + 0x6a) == '\x04')) {
    if (((*(byte *)(ppOVar6 + 0x1c) >> 6 == 1) && (*(char *)((int)ppOVar6 + 0x6e) == '\0')) ||
       (DAT_80399d78 == '\0')) {
      printf(" Creating Light ");
      *(undefined *)((int)ppOVar6 + 0x6e) = 1;
      def = objAlloc(0x28,LFXEmitter);
      def->loadFlags = isManualLoad;
      (def->pos).x = (param1->pos).pos.x;
      (def->pos).y = (param1->pos).pos.y;
      (def->pos).z = (param1->pos).pos.z;
      iVar2 = randInt(0,1);
      *(short *)&def[1].bound = (short)iVar2 + 0x1aa;
      *(undefined2 *)((int)&def[1].pos.x + 2) = 0xffff;
      in_r5 = (vec3f *)(int)(char)param1->mapId;
      pOVar1 = objInstantiateCharacter(def,5,(int)in_r5,-1,param1->pMatrix);
      *ppOVar6 = pOVar1;
      if (*(byte *)(ppOVar6 + 0x1c) >> 6 != 1) {
        DAT_80399d78 = '\x01';
      }
    }
    if (*ppOVar6 != (ObjInstance *)0x0) {
      ((*ppOVar6)->pos).pos.x = (param1->pos).pos.x;
      ((*ppOVar6)->pos).pos.y = (param1->pos).pos.y;
      ((*ppOVar6)->pos).pos.z = (param1->pos).pos.z;
    }
  }
  local_5c = (param1->pos).pos.x - (param1->oldPos).x;
  local_58 = (param1->pos).pos.y - (param1->oldPos).y;
  local_54 = (param1->pos).pos.z - (param1->oldPos).z;
  dVar7 = sqrt((double)(local_54 * local_54 + local_5c * local_5c + local_58 * local_58));
  local_30 = (longlong)(int)(dVar7 / 2.5);
  uVar5 = (int)(dVar7 / 2.5) + 1;
  uStack_34 = uVar5 ^ 0x80000000;
  local_38 = 0x43300000;
  local_5c = local_5c * (1.0 / (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0))
  ;
  uStack_3c = uVar5 ^ 0x80000000;
  local_40 = 0x43300000;
  local_58 = local_58 * (1.0 / (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0))
  ;
  uStack_44 = uVar5 ^ 0x80000000;
  local_48 = 0x43300000;
  local_54 = local_54 * (1.0 / (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0))
  ;
  local_74._0_2_ = 0;
  local_74._2_2_ = 0;
  local_70 = 0;
  local_6c = 1.0;
  local_68 = (param1->oldPos).x;
  local_64 = (param1->oldPos).y;
  local_60 = (param1->oldPos).z;
  param2 = 0x40;
  bVar3 = FUN_80068b20((int)param1,0x40);
  if (bVar3) {
    uVar4 = uVar5 * 0x1e;
    if ((int)uVar4 < 0x14) {
      uVar4 = 0x14;
    }
    else if (0x7f < (int)uVar4) {
      uVar4 = 0x7f;
    }
    in_r5 = (vec3f *)(uVar4 & 0xff);
    FUN_800689dc(127.0,(int)param1,0x40,(byte)uVar4);
    param2 = extraout_r4;
  }
  if (*(byte *)(ppOVar6 + 0x1c) >> 6 == 1) {
    if ((*(char *)((int)ppOVar6 + 0x6a) == '\x01') || (*(char *)((int)ppOVar6 + 0x6a) == '\x04')) {
      for (iVar2 = 0; iVar2 < (int)uVar5; iVar2 = iVar2 + 1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x1a0,local_74,&DAT_00200001,0xffffffff,0);
        in_r5 = (vec3f *)local_74;
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x19e,in_r5,&DAT_00200001,0xffffffff,0);
        local_68 = local_68 + local_5c;
        local_64 = local_64 + local_58;
        local_60 = local_60 + local_54;
        param2 = extraout_r4_00;
      }
    }
    else {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x1bb,0,1,0xffffffff,0);
      in_r5 = (vec3f *)0x0;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x1bd,0,1,0xffffffff,0);
      param2 = extraout_r4_01;
    }
    uVar5 = (uint)framesThisStep;
    pOVar1 = ppOVar6[0x18];
    ppOVar6[0x18] = (ObjInstance *)((int)pOVar1 - uVar5);
    if ((int)(ObjInstance *)((int)pOVar1 - uVar5) < 0) {
      mainDecBit(0x698);
      Object_objFreeObject(param1);
    }
    modelMtxFn(param1,param2,in_r5);
  }
  return;
}


/* @description Override hit detection */

void fireflyLantern_hitDetect(ObjInstance *this) { //801EAC88
  return;
}


/* Library Function - Single Match
    fireflyLantern_func06
   
   Library: KioskDefault 0 0 */

void fireflyLantern_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801EAC8C
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar1 = this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((this != (ObjInstance *)0x0) && (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)*(float *)(puVar1 + 0x4c),20.0,param2_00,param3_00,0xff,0,0);
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)*(float *)(puVar1 + 0x50),
                   (double)((float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(puVar1 + 0x68) ^ 0x80000000) -
                                   4503601774854144.0) + 4.0),param2_00,param3_00,0xff,0xff,0);
    }
  }
  return;
}


/* Library Function - Single Match
    fireflyLantern_func07
   
   Library: KioskDefault 0 0 */

void fireflyLantern_free(ObjInstance *this,int param2) { //801EAD84
  ObjInstance **ppOVar1;
  
  ppOVar1 = (ObjInstance **)this->state;
  if ((param2 == 0) && (*ppOVar1 != (ObjInstance *)0x0)) {
    Object_objFreeObject(*ppOVar1);
    *ppOVar1 = (ObjInstance *)0x0;
    if (*(byte *)(ppOVar1 + 0x1c) >> 6 != 1) {
      DAT_80399d78 = 0;
    }
  }
  Object_removePlayerObj(this,0x32);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 fireflyLantern_func08(ObjInstance *this) { //801EAE18
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int fireflyLantern_getExtraSize(void) { //801EAE20
  return 0x74;
}


/* Library Function - Single Match
    fireflyLantern_spawnFirefly
   
   Library: KioskDefault 0 0 */

void fireflyLantern_spawnFirefly(ObjInstance *this,float scale) { //801EB044
  float *in_r4;
  undefined *puVar1;
  
  puVar1 = this->state;
  *in_r4 = *in_r4 - *(float *)(puVar1 + 0x54);
  in_r4[1] = in_r4[1] - *(float *)(puVar1 + 0x58);
  in_r4[2] = in_r4[2] - *(float *)(puVar1 + 0x5c);
  *(float *)(puVar1 + 0x34) = *in_r4;
  *(float *)(puVar1 + 0x38) = in_r4[1];
  *(float *)(puVar1 + 0x3c) = in_r4[2];
  puVar1[0x6c] = 4;
  printf(" Sending FireFly ");
  return;
}


/* Library Function - Single Match
    fireflyLantern_func0B
   
   Library: KioskDefault 0 0 */

void fireflyLantern_func0B(ObjInstance *param1) { //801EB0D8
  short sVar1;
  short sVar2;
  ObjInstance *pOVar3;
  undefined4 extraout_r4;
  undefined4 param2;
  vec3f *param3;
  ObjDef *pOVar4;
  undefined *puVar5;
  double dVar6;
  
  puVar5 = param1->state;
  pOVar4 = param1->def;
  *(short *)(puVar5 + 0x68) = (short)*(char *)&pOVar4[1].objType;
  puVar5[0x6a] = *(undefined *)((int)&pOVar4[1].objType + 1);
  *(float *)(puVar5 + 0x4c) = 1.0;
  sVar1._0_1_ = pOVar4[1].loadFlags;
  sVar1._1_1_ = pOVar4[1].mapStates2;
  *(float *)(puVar5 + 0x50) =
       (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  puVar5[0x6f] = 0;
  param3 = (vec3f *)&DAT_00000001;
  objBecomeHeldBy((short *)param1,(ObjInstance *)0x0,1);
  param2 = extraout_r4;
  pOVar3 = Object_objGetMain();
  dVar6 = (double)(pOVar3->prevPos).x;
  modelMtxFn(param1,param2,param3);
  spawnFirefly(param1,SUB84(dVar6,0));
  dVar6 = (double)FUN_801eae28(dVar6,param1);
  dVar6 = (double)FUN_801eae28(dVar6,param1);
  dVar6 = (double)FUN_801eae28(dVar6,param1);
  dVar6 = (double)FUN_801eae28(dVar6,param1);
  dVar6 = (double)FUN_801eae28(dVar6,param1);
  FUN_801eae28(dVar6,param1);
  puVar5[0x70] = puVar5[0x70] & 0x3f | 0x40;
  audioTryStartSfx((int *)param1,0xc0,0x125,0x7f,"lanternfirefly.c",0x1e0);
  sVar2._0_1_ = pOVar4[1].allocatedSize;
  sVar2._1_1_ = pOVar4[1].mapStates1;
  *(int *)(puVar5 + 0x60) = (int)sVar2;
  mainIncBit(0x698);
  return;
}


/* Library Function - Single Match
    fireflyLantern_func0C
   
   Library: KioskDefault 0 0 */

void fireflyLantern_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //801EB22C
  undefined *puVar1;
  double in_f1;
  double in_f2;
  double in_f3;
  
  puVar1 = this->state;
  *(float *)(puVar1 + 0x54) = (float)in_f1;
  *(float *)(puVar1 + 0x58) = (float)in_f2;
  *(float *)(puVar1 + 0x5c) = (float)in_f3;
  return;
}

