
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void robot_initialise(undefined4 param) { //8020FA50
  return;
}


/* @description Called when DLL is unloaded */

void robot_release(void) { //8020FA54
  return;
}


/* Library Function - Single Match
    robot_func03
   
   Library: KioskDefault 0 0 */

void robot_init(ObjInstance *param1,int param2,ObjInstance *obj2,DllInitFlags flags,float x,float y
                ,float z) { //8020FA58
  undefined *puVar1;
  
  printf(" ROBOT  ROBOT  CREATED ");
  puVar1 = param1->state;
  puVar1[0x19c] = 0;
  *(undefined4 *)(puVar1 + 0x14c) = 0;
  *(undefined2 *)(puVar1 + 0x19a) = 0;
  puVar1[0x19e] = 0;
  puVar1[0x1a0] = 0;
  puVar1[0x1a2] = 4;
  puVar1[0x1a3] = 0;
  Object_objAddObjectType(param1,0x35);
  param1->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80210834;
  if (*(char *)(param2 + 0x18) != '\0') {
    puVar1[0x19c] = 0xe;
    puVar1[0x19e] = 2;
    puVar1[0x1a0] = 2;
  }
  FUN_80210d8c((int)(puVar1 + 0x158));
  *(undefined4 *)(puVar1 + 0x154) = 0;
  *(undefined4 *)(puVar1 + 0x150) = 0;
  (param1->pos).pos.x = *(float *)(param2 + 8);
  (param1->pos).pos.y = *(float *)(param2 + 0xc);
  (param1->pos).pos.z = *(float *)(param2 + 0x10);
  return;
}


/* Library Function - Single Match
    robot_func04
   
   Library: KioskDefault 0 0 */

void robot_update(ObjInstance *this) { //8020FB3C
  float fVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  short sVar6;
  short sVar7;
  float *pfVar8;
  double dVar9;
  int local_58 [6];
  longlong local_40;
  undefined4 local_38;
  uint uStack_34;
  double local_30;
  double local_28;
  
  pfVar8 = (float *)this->state;
  local_58[0] = 1;
  local_58[1] = 3;
  local_58[2] = 7;
  local_58[3] = 0xf;
  if (*(char *)(pfVar8 + 0x67) == '\x0e') {
    uVar3 = mainGetBit(0x334);
    if (uVar3 != 0) {
      printf(" First Robot Activated ");
      *(undefined *)(pfVar8 + 0x67) = 0;
    }
  }
  else {
    iVar4 = FUN_80210bac((int)this);
    if (iVar4 == 3) {
      mainSetBits(0x8c9,1);
    }
    iVar4 = FUN_80210bac((int)this);
    if (iVar4 == 2) {
      mainSetBits(0x8ca,1);
    }
    uVar3 = mainGetBit(0x945);
    if (uVar3 != 0) {
      FUN_80073dcc();
      FUN_80210aac((int)this,local_58[*(byte *)(pfVar8 + 0x68) + 1],pfVar8 + 0x4f,1);
      *(undefined *)(pfVar8 + 0x67) = 2;
      *(char *)((int)pfVar8 + 0x1a1) = (char)local_58[*(byte *)(pfVar8 + 0x68) + 1];
    }
    if (*(char *)((int)pfVar8 + 0x19f) == '\0') {
      if (true) {
                    /* {@symbol 8020fccc} */
        switch(*(undefined *)(pfVar8 + 0x67)) {
        case 0:
          printf(" Get Treasure");
          FUN_80210c4c(2000.0,this,(int)pfVar8,0,local_58[*(byte *)(pfVar8 + 0x68)]);
          *(undefined *)((int)pfVar8 + 0x19f) = 1;
          *(undefined *)(pfVar8 + 0x67) = 1;
          break;
        case 1:
          iVar4 = FUN_802108c8(this);
          if (iVar4 != 0) {
            FUN_80210aac((int)this,local_58[*(byte *)(pfVar8 + 0x68) + 1],pfVar8 + 0x4f,0);
            *(undefined *)(pfVar8 + 0x67) = 2;
            *(char *)((int)pfVar8 + 0x1a1) = (char)local_58[*(byte *)(pfVar8 + 0x68) + 1];
          }
          break;
        case 2:
          iVar4 = FUN_80210954((double)pfVar8[0x4f],(double)(pfVar8[0x50] + 70.0),
                               (double)pfVar8[0x51],(int)this);
          if (iVar4 != 0) {
            *(undefined *)(pfVar8 + 0x67) = 3;
          }
          break;
        case 3:
          FUN_80210c4c(2000.0,this,(int)pfVar8,(uint)*(byte *)((int)pfVar8 + 0x1a3),
                       (uint)*(byte *)((int)pfVar8 + 0x1a1));
          *(undefined *)((int)pfVar8 + 0x19f) = 1;
          *(undefined *)(pfVar8 + 0x67) = 8;
          break;
        case 8:
          if (pfVar8[0x53] != 0.0) {
            *(undefined *)(pfVar8 + 0x67) = 9;
            cVar2 = *(char *)((int)pfVar8 + 0x19e) + '\x01';
            *(char *)((int)pfVar8 + 0x19e) = cVar2;
                    /* {@symbol 8017305c} */
            (**(code **)(*pdll_camcontrol + 0x58))
                      ((uint)*(byte *)((int)pfVar8 + 0x1a2) - (int)cVar2);
            (**(code **)(**(int **)((int)pfVar8[0x53] + 0x68) + 0x28))
                      ((double)pfVar8[0x52],pfVar8[0x53],this);
            pfVar8[0x53] = 0.0;
          }
          printf(" Hello ");
          if (*(char *)((int)pfVar8 + 0x19e) == '\x02') {
            *(undefined *)(pfVar8 + 0x68) = 2;
            printf(" On next Nodes ");
          }
          if (*(byte *)((int)pfVar8 + 0x1a2) == 0xffffffff) {
            *(undefined *)(pfVar8 + 0x67) = 0xf;
          }
          else if ((int)(uint)*(byte *)((int)pfVar8 + 0x1a2) <= (int)*(char *)((int)pfVar8 + 0x19e))
          {
                    /* {@symbol 80173318} */
            (**(code **)(*pdll_camcontrol + 0x5c))();
            FUN_80073dcc();
            *(undefined *)(pfVar8 + 0x67) = 10;
          }
          FUN_80210aac((int)this,local_58[*(byte *)(pfVar8 + 0x68)],pfVar8 + 0x4f,0);
          *(float *)((int)pfVar8[0x27] + 0x10) = *(float *)((int)pfVar8[0x27] + 0x10) - 40.0;
          break;
        case 9:
          iVar4 = FUN_80210954((double)pfVar8[0x4f],(double)(pfVar8[0x50] + 70.0),
                               (double)pfVar8[0x51],(int)this);
          if (iVar4 != 0) {
            *(undefined *)(pfVar8 + 0x67) = 0;
          }
          break;
        case 10:
          mainSetBits(0x8f7,0);
          mainSetBits(0x529,1);
          mainSetBits(0x590,1);
          mainSetBits(0x591,0);
                    /* {@symbol 8012e228} */
          (**(code **)(*(int *)pDll_SaveGame + 0x50))(0xc,0x1e,1);
                    /* {@symbol 8012e228} */
          (**(code **)(*(int *)pDll_SaveGame + 0x50))(0xc,9,1);
          printf(" Picked Up Treasure ");
          printf(" Sorry You Have Failed ");
          *(undefined *)(pfVar8 + 0x67) = 0xf;
          break;
        case 0xb:
          iVar4 = FUN_80210954((double)pfVar8[0x4f],(double)(pfVar8[0x50] + 70.0),
                               (double)pfVar8[0x51],(int)this);
          if (iVar4 != 0) {
            FUN_80210c4c(2000.0,this,(int)pfVar8,1,(uint)*(byte *)((int)pfVar8 + 0x1a1));
            *(undefined *)((int)pfVar8 + 0x19f) = 1;
            *(undefined *)(pfVar8 + 0x67) = 1;
            printf(" Tunnel is collapsing ");
            *(undefined *)(pfVar8 + 0x68) = 2;
            *(undefined *)((int)pfVar8 + 0x1a1) = 0xf;
            *(undefined *)((int)pfVar8 + 0x19e) = 2;
          }
          break;
        case 0xc:
          printf(" TP");
          mainSetBits(0x334,1);
          if ((this->pos).pos.y <= pfVar8[0x52]) {
            (this->pos).pos.y = pfVar8[0x52];
            local_28 = (double)CONCAT44(0x43300000,(int)*(short *)((int)pfVar8 + 0x19a) ^ 0x80000000
                                       );
            dVar9 = (double)distanceFn_80293e80((double)(((float)(local_28 - 4503601774854144.0) *
                                                         3.141593) / 32767.0));
            (this->pos).pos.y = (float)(dVar9 * 0.2000000029802322 + (double)(this->pos).pos.y);
          }
          else {
            (this->vel).y = (this->vel).y - 0.05;
            (this->pos).pos.y = (this->pos).pos.y + (this->vel).y;
          }
          break;
        case 0xd:
          if ((this->pos).pos.y <= pfVar8[0x52]) {
            (this->pos).pos.y = pfVar8[0x52];
          }
          else {
            (this->vel).y = (this->vel).y - 0.05;
            (this->pos).pos.y = (this->pos).pos.y + (this->vel).y;
          }
          local_28 = (double)CONCAT44(0x43300000,(int)*(short *)((int)pfVar8 + 0x19a) ^ 0x80000000);
          dVar9 = (double)distanceFn_80293e80((double)(((float)(local_28 - 4503601774854144.0) *
                                                       3.141593) / 32767.0));
          (this->pos).pos.y = (float)(dVar9 * 0.2000000029802322 + (double)(this->pos).pos.y);
        }
      }
    }
    else {
      iVar4 = FUN_80210cfc((int)this,pfVar8);
      if (iVar4 != 0) {
        *(undefined *)((int)pfVar8 + 0x19f) = 0;
        pfVar8[0x4f] = pfVar8[0x1a];
        pfVar8[0x52] = pfVar8[0x1b];
        pfVar8[0x51] = pfVar8[0x1c];
      }
    }
    if (pfVar8[0x53] != 0.0) {
      (**(code **)(**(int **)((int)pfVar8[0x53] + 0x68) + 0x24))(pfVar8[0x53],this);
    }
    dVar9 = sqrt((double)(((this->pos).pos.x - (this->oldPos).x) *
                          ((this->pos).pos.x - (this->oldPos).x) +
                         ((this->pos).pos.z - (this->oldPos).z) *
                         ((this->pos).pos.z - (this->oldPos).z)));
    fVar1 = (float)(dVar9 / 15.0);
    if (-1.0 <= fVar1) {
      if (1.0 < fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = -1.0;
    }
    local_28 = (double)(longlong)(int)(fVar1 * 5461.0);
    sVar6 = (short)(int)(fVar1 * 5461.0);
    (this->pos).rotation.y =
         (this->pos).rotation.y + (short)((int)sVar6 - (int)(this->pos).rotation.y >> 3);
    fVar1 = (this->pos).pos.x - (this->oldPos).x;
    if ((fVar1 != 0.0) || ((this->pos).pos.y - (this->oldPos).y != 0.0)) {
      local_28 = (double)(longlong)(int)fVar1;
      local_30 = (double)(longlong)(int)((this->pos).pos.z - (this->oldPos).z);
      iVar4 = FUN_8007ad14();
      sVar7 = (short)iVar4 - (this->pos).rotation.x;
      if (0x8000 < sVar7) {
        sVar7 = sVar7 + 1;
      }
      if (sVar7 < -0x8000) {
        sVar7 = sVar7 + -1;
      }
      (this->pos).rotation.x = (this->pos).rotation.x + (sVar7 >> 2);
    }
    puVar5 = (undefined2 *)objGetJoint((int)this,0);
    if (puVar5 != (undefined2 *)0x0) {
      local_30 = (double)CONCAT44(0x43300000,(int)*(short *)((int)pfVar8 + 0x19a) ^ 0x80000000);
      dVar9 = (double)distanceFn_80293e80((double)(((float)(local_30 - 4503601774854144.0) *
                                                   3.141593) / 32767.0));
      local_28 = (double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000);
      uStack_34 = sVar6 * -2 ^ 0x80000000;
      local_38 = 0x43300000;
      iVar4 = (int)((double)((float)(local_28 - 4503601774854144.0) * 0.0625) * dVar9 +
                   (double)(float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0));
      local_40 = (longlong)iVar4;
      *puVar5 = (short)iVar4;
    }
    iVar4 = FUN_80210ef8(this,pfVar8 + 0x56);
    if (iVar4 != 0) {
      FUN_80068a9c((uint)this,0x40);
    }
  }
  return;
}


/* Library Function - Single Match
    robot_func05
   
   Library: KioskDefault 0 0 */

void robot_hitDetect(ObjInstance *this) { //802103B0
  int iVar1;
  undefined *puVar2;
  int local_14 [2];
  
  puVar2 = this->state;
  iVar1 = FUN_800883e4((int)this,local_14,(int *)0x0,(uint *)0x0);
  if ((iVar1 == 0xe) || (iVar1 == 5)) {
    FUN_80210da0((double)(*(float *)(local_14[0] + 0xc) - (this->pos).pos.x),
                 (double)(*(float *)(local_14[0] + 0x10) - (this->pos).pos.y),
                 (double)(*(float *)(local_14[0] + 0x14) - (this->pos).pos.z),15.0,this,
                 (float *)(puVar2 + 0x158));
    audioTryStartSfx((int *)this,1,0x231,0x7f,"CFtreasRobo.c",0x210);
  }
  return;
}


/* Library Function - Single Match
    robot_func06
   
   Library: KioskDefault 0 0 */

void robot_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //80210468
  int iVar1;
  uint uVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjInstance *obj;
  undefined *puVar3;
  double dVar4;
  undefined auStack_58 [4];
  undefined2 local_54;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  longlong local_30;
  undefined4 local_28;
  uint uStack_24;
  
  puVar3 = this->state;
  obj = *(ObjInstance **)(puVar3 + 0x154);
  *(short *)(puVar3 + 0x19a) = *(short *)(puVar3 + 0x19a) + 0x800;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (puVar3[0x19c] != '\f') {
      if ((puVar3[0x19c] != '\r') &&
         ((int)*(short *)(puVar3 + 0x19a) == ((int)*(short *)(puVar3 + 0x19a) / 0x1600) * 0x1600)) {
        local_54 = 0xff;
        objGetAttachPointWorldPos(this,0,&local_4c,&local_48,&local_44,FALSE);
        local_4c = local_4c - (this->pos).pos.x;
        local_48 = local_48 - (this->pos).pos.y;
        local_44 = local_44 - (this->pos).pos.z;
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x35e,auStack_58,0,0xffffffff,0);
      }
    }
    if ((obj != (ObjInstance *)0x0) && (*(int *)(puVar3 + 0x14c) != 0)) {
      if (*(int *)(puVar3 + 0x14c) != 0) {
        local_40 = (this->pos).pos.x - *(float *)(*(int *)(puVar3 + 0x14c) + 0xc);
        local_3c = (this->pos).pos.y - *(float *)(*(int *)(puVar3 + 0x14c) + 0x10);
        local_38 = (this->pos).pos.z - *(float *)(*(int *)(puVar3 + 0x14c) + 0x14);
        FUN_802106dc(&local_40,(undefined2 *)obj,&(obj->pos).rotation.y);
      }
      iVar1 = FUN_80094400((int)obj,0);
      if (iVar1 != 0) {
        uVar2 = (int)*(short *)(iVar1 + 10) + 0x40;
        *(short *)(iVar1 + 10) =
             (short)uVar2 +
             (short)(((int)uVar2 >> 0xb) + (uint)((int)uVar2 < 0 && (uVar2 & 0x7ff) != 0)) * -0x800;
        uVar2 = (int)*(short *)(iVar1 + 8) + 8;
        *(short *)(iVar1 + 8) =
             (short)uVar2 +
             (short)(((int)uVar2 >> 0xb) + (uint)((int)uVar2 < 0 && (uVar2 & 0x7ff) != 0)) * -0x800;
      }
      uStack_24 = (int)*(short *)(puVar3 + 0x19a) ^ 0x80000000;
      local_28 = 0x43300000;
      dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_24) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      local_30 = (longlong)(int)(dVar4 * 64.0);
      obj->newOpacity = (char)(int)(dVar4 * 64.0) + 0xbf;
      (obj->pos).pos.x = (this->pos).pos.x;
      (obj->pos).pos.y = (this->pos).pos.y;
      (obj->pos).pos.z = (this->pos).pos.z;
      objRenderCurrentModel
                (obj,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
    }
  }
  return;
}


/* Library Function - Single Match
    robot_kill
   
   Library: KioskDefault 0 0 */

void robot_kill(ObjInstance *param1,int param2) { //80210788
  undefined *puVar1;
  
  puVar1 = param1->state;
  if ((param2 == 0) && (*(int *)(puVar1 + 0x154) != 0)) {
    Object_objFreeObject(*(ObjInstance **)(puVar1 + 0x154));
  }
  if ((*(int *)(puVar1 + 0x150) != 0) && (param2 == 0)) {
    Object_objFreeObject(*(ObjInstance **)(puVar1 + 0x150));
  }
  Object_removePlayerObj(param1,0x35);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(param1);
  printf("ROBOT KILLED ");
  return;
}


undefined4 robot_func08(ObjInstance *this) { //80210824
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int robot_getExtraSize(void) { //8021082C
  return 0x1a8;
}

