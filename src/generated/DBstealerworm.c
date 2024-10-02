
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBstealerworm_initialise(undefined4 param) { //80294238
  return;
}


/* @description Called when DLL is unloaded */

void DBstealerworm_release(void) { //8029423C
  return;
}


/* Library Function - Single Match
    DBstealerworm_func03
   
   Library: KioskDefault 0 0 */

void DBstealerworm_func03(ObjInstance *param1) { //80294240
  curveEggFn_802956a4(param1,(float *)param1->state);
  objAllocMsgQueue(param1,4);
  if (param1->shadow != (Shadow *)0x0) {
    param1->shadow->flags = param1->shadow->flags | 0x4008;
  }
  return;
}


/* Library Function - Single Match
    DBstealerworm_func04
   
   Library: KioskDefault 0 0 */

void DB_egg_update(ObjInstance *param1) { //802942A0
  int iVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  ObjInstance *param2;
  int iVar5;
  N64Button32 NVar6;
  char cVar8;
  uint uVar7;
  ObjDef *param2_00;
  float *param2_01;
  double dVar9;
  double y;
  double z;
  undefined4 local_74;
  undefined4 local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  double local_50;
  undefined4 local_48;
  uint uStack_44;
  longlong local_40;
  undefined4 local_38;
  uint uStack_34;
  
  param2_00 = param1->def;
  param2 = Object_objGetMain();
  param2_01 = (float *)param1->state;
  local_74 = 1;
  local_70 = 0;
  dVar9 = (double)(param1->pos).pos.x;
  y = (double)(param1->pos).pos.y;
  z = (double)(param1->pos).pos.z;
  iVar5 = getBlockIdxAtCoords(dVar9,y,z);
  if (iVar5 != -1) {
    dVar9 = (double)dbEggFn_801fe16c(dVar9,y,z,param1);
    param1->hitstate->flags = param1->hitstate->flags & 0xfbff;
    if (true) {
                    /* {@symbol 80294df8} */
      switch(*(undefined *)(param2_01 + 0x46)) {
      case 1:
        if (param1->flags_0xf8 == 0) {
          param1->hitstate->flags = param1->hitstate->flags | 1;
        }
        param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
        break;
      case 2:
        if ((*(byte *)((int)param2_01 + 0x119) & 4) != 0) {
          param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
          (param1->vel).x = (param1->vel).x + ((param2_00->pos).x - (param1->pos).pos.x) / 1000.0;
          (param1->vel).y = (param1->vel).y + ((param2_00->pos).y - (param1->pos).pos.y) / 1000.0;
          (param1->vel).z = (param1->vel).z + ((param2_00->pos).z - (param1->pos).pos.z) / 1000.0;
          uVar7 = mainGetBit(0x44d);
          if (uVar7 != 0) {
            *(undefined *)(param2_01 + 0x46) = 10;
          }
        }
        param1->hitstate->flags = param1->hitstate->flags | 0x400;
        local_60 = 0.0;
        local_5c = 0.0;
        local_58 = 0.0;
        FUN_80295154((int)param1,&local_60);
        (param1->vel).x = (param1->vel).x + local_60;
        (param1->vel).y = (param1->vel).y + local_5c;
        (param1->vel).z = (param1->vel).z + local_58;
        iVar5 = FUN_802953b4((double)((param1->vel).x * timeDelta),
                             (double)((param1->vel).z * timeDelta),(int)param1,&local_54,1);
        if (iVar5 != 0) {
          (param1->vel).x = (param1->vel).x * -0.95;
          (param1->vel).z = (param1->vel).z * -0.95;
          FUN_802953b4((double)((param1->vel).x * timeDelta),(double)((param1->vel).z * timeDelta),
                       (int)param1,&local_54,1);
        }
        local_54 = local_54 + *param2_01;
        if (prevOneOverTimeDelta == 0.0) {
          (param1->vel).y = 0.0;
        }
        else {
          (param1->vel).y = local_54 * prevOneOverTimeDelta * 0.3;
        }
        uStack_34 = randInt(100,5000);
        uStack_34 = uStack_34 ^ 0x80000000;
        local_38 = 0x43300000;
        iVar5 = (int)(local_54 *
                     (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0));
        local_40 = (longlong)iVar5;
        uStack_44 = randInt(100,5000);
        uStack_44 = uStack_44 ^ 0x80000000;
        local_48 = 0x43300000;
        iVar1 = (int)(local_54 *
                     (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0));
        local_50 = (double)(longlong)iVar1;
        (param1->pos).rotation.y =
             (param1->pos).rotation.y +
             (short)((uint)((int)(short)iVar5 - (int)(param1->pos).rotation.y) >> 8);
        (param1->pos).rotation.z =
             (param1->pos).rotation.z +
             (short)((uint)((int)(short)iVar1 - (int)(param1->pos).rotation.z) >> 8);
        objMove((double)((param1->vel).x * timeDelta),(double)((param1->vel).y * timeDelta),
                (double)((param1->vel).z * timeDelta),param1);
        iVar5 = randInt(0,10);
        if (iVar5 == 0) {
          if (false) {
            uVar7 = (int)((uint)(byte)((local_54 < 0.05) << 3) << 0x1c) >> 0x1f;
          }
          else {
            uVar7 = ((uint)(byte)((local_54 < 0.05) << 3) << 0x1c) >> 0x1f;
          }
          if (uVar7 != 0) {
            uVar7 = randInt(1,10);
            local_50 = (double)CONCAT44(0x43300000,uVar7 ^ 0x80000000);
                    /* {@symbol 800db230} */
            (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                      ((double)(param1->pos).pos.x,(double)((param1->pos).pos.y - *param2_01),
                       (double)(param1->pos).pos.z,(double)(float)(local_50 - 4503601774854144.0),
                       (int)(param1->pos).rotation.x,1);
          }
        }
        uVar7 = mainGetBit(0x426);
        if (uVar7 == 0) {
          if ((*(byte *)((int)param2_01 + 0x119) & 2) != 0) {
            param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
          }
        }
        else {
          param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
          *param2_01 = -(timeDelta * 0.1 - *param2_01);
          if (*param2_01 < -7.0) {
            uVar7 = mainGetBit(0x428);
            mainSetBits(0x428,uVar7 + 1);
            *(undefined *)(param2_01 + 0x46) = 7;
            (param1->vel).y = 0.0;
            (param1->vel).x = 0.0;
            (param1->vel).z = 0.0;
            param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
          }
        }
        break;
      case 4:
        param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
        iVar5 = FUN_801a7e68((int)param2);
        iVar5 = (**(code **)(**(int **)(iVar5 + 0x68) + 0x2c))(iVar5,0x10,0);
        if (iVar5 == 4) {
          *(undefined *)(param2_01 + 0x46) = 5;
          (param1->vel).x = 0.0;
          (param1->vel).z = 0.0;
          param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
        }
        break;
      case 5:
        if (param1->flags_0xf8 == 0) {
          param1->hitstate->flags = param1->hitstate->flags | 1;
        }
        iVar5 = FUN_802953b4(0.0,0.0,(int)param1,&local_54,1);
        if (iVar5 == 0) {
          *(undefined *)(param2_01 + 0x46) = 2;
        }
        else {
          fVar3 = local_54;
          if (local_54 < 0.0) {
            fVar3 = -local_54;
          }
          if (0.09 <= fVar3) {
            (param1->vel).y = (param1->vel).y + -0.3;
            if (0.0 < local_54) {
              (param1->vel).y = -(param1->vel).y * 0.65;
              (param1->vel).x = (param1->vel).x * 0.9;
              (param1->vel).z = (param1->vel).z * 0.9;
            }
            objMove((double)((param1->vel).x * timeDelta),(double)((param1->vel).y * timeDelta),
                    (double)((param1->vel).z * timeDelta),param1);
            param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
          }
          else {
            if ((*(byte *)((int)param2_01 + 0x119) & 0x10) == 0) {
              *(undefined *)(param2_01 + 0x46) = 1;
            }
            else {
              *(undefined *)(param2_01 + 0x46) = 0xd;
            }
            (param1->vel).x = 0.0;
            (param1->vel).z = 0.0;
            (param1->vel).y = 0.0;
            (param1->pos).pos.y = (param1->pos).pos.y + local_54;
          }
        }
        break;
      case 6:
        objDistSqObj2Def(param1,param2_00);
        if ((dVar9 <= 150.0) || ((*(byte *)((int)param2_01 + 0x119) & 2) != 0)) {
          NVar6 = n64GetEnabledButtonsPressed(0);
          if ((NVar6 & N64_BUTTON_A) == 0) {
            param1->hitstate->flags = param1->hitstate->flags & 0xfffe;
            objSendMsg((int)param2,0x100008,(uint)param1,0x38000);
            param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
          }
          else {
            *(undefined *)(param2_01 + 0x46) = 5;
            param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
          }
        }
        else {
          FUN_802955f8(param1);
          param1->flags_0xf8 = 0;
        }
        break;
      case 7:
        FUN_802953b4(0.0,0.0,(int)param1,&local_54,0);
        fVar3 = local_54;
        if (local_54 < 0.0) {
          fVar3 = -local_54;
        }
        if (0.09 <= fVar3) {
          (param1->vel).y = (param1->vel).y + -0.006;
          if (0.0 < local_54) {
            (param1->vel).y = -(param1->vel).y * 0.4;
          }
          objMove((double)((param1->vel).x * timeDelta),(double)((param1->vel).y * timeDelta),
                  (double)((param1->vel).z * timeDelta),param1);
        }
        else {
          *(undefined *)(param2_01 + 0x46) = 8;
          (param1->vel).x = 0.0;
          (param1->vel).z = 0.0;
        }
        break;
      case 8:
        uVar7 = mainGetBit(0x42a);
        if (uVar7 == 0) {
          iVar5 = randInt(0,10);
          if (iVar5 == 0) {
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x3be,0,0,0xffffffff,0);
          }
        }
        else {
          curveEggFn_802956a4(param1,param2_01);
        }
        break;
      case 9:
        iVar5 = FUN_8006c2c8(0.6000000238418579,param2_01 + 1);
        if ((iVar5 == 0) && (param2_01[5] == 0.0)) {
          (param1->vel).x = param2_01[0x1b] - (param1->pos).pos.x;
          (param1->vel).y = param2_01[0x1c] - (param1->pos).pos.y;
          (param1->vel).z = param2_01[0x1d] - (param1->pos).pos.z;
          dVar9 = sqrt((double)((param1->vel).z * (param1->vel).z +
                               (param1->vel).x * (param1->vel).x + (param1->vel).y * (param1->vel).y
                               ));
          if ((double)(timeDelta * 4.6) < dVar9) {
            vec3f_normalize_8002282c(&(param1->vel).x);
            (param1->vel).x = (param1->vel).x * timeDelta * 4.6;
            (param1->vel).y = (param1->vel).y * timeDelta * 4.6;
            (param1->vel).z = (param1->vel).z * timeDelta * 4.6;
            diPrintf(" GREATER ");
          }
          (param1->pos).pos.x = (param1->pos).pos.x + (param1->vel).x;
          (param1->pos).pos.y = (param1->pos).pos.y + (param1->vel).y;
          (param1->pos).pos.z = (param1->pos).pos.z + (param1->vel).z;
        }
        else {
                    /* {@symbol 801290d4} */
          cVar8 = (**(code **)(*(int *)pDll_RomCurve + 0x90))(param2_01 + 1);
          if (cVar8 != '\0') {
            *(undefined *)(param2_01 + 0x46) = 5;
          }
        }
        break;
      case 10:
                    /* {@symbol 80128bb8} */
        cVar8 = (**(code **)(*(int *)pDll_RomCurve + 0x8c))
                          (0x4072c00000000000,param2_01 + 1,param1,&local_74,2);
        if (cVar8 == '\0') {
          param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
          *(undefined *)(param2_01 + 0x46) = 9;
          if ((*(byte *)((int)param2_01 + 0x119) & 4) != 0) {
            *(byte *)((int)param2_01 + 0x119) = *(byte *)((int)param2_01 + 0x119) & 0xfb;
          }
        }
        else {
          *(undefined *)(param2_01 + 0x46) = 5;
        }
        break;
      case 0xb:
        diPrintf(" Stolen ");
        param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
        return;
      case 0xc:
        uVar7 = mainGetBit((int)*(short *)&param2_00[1].pos.y);
        if (uVar7 != 0) {
          Object_objAddObjectType(param1,0x26);
          *(undefined *)(param2_01 + 0x46) = 5;
        }
        break;
      case 0xd:
        FUN_80088da4((int)param1);
        (param1->vel).x = (param1->vel).x + ((param2_00->pos).x - (param1->pos).pos.x) / 3000.0;
        (param1->vel).y = (param1->vel).y + ((param2_00->pos).y - (param1->pos).pos.y) / 3000.0;
        (param1->vel).z = (param1->vel).z + ((param2_00->pos).z - (param1->pos).pos.z) / 3000.0;
        local_6c = (param1->pos).pos.x - (param2_00->pos).x;
        local_68 = (param1->pos).pos.y - (param2_00->pos).y;
        local_64 = (param1->pos).pos.z - (param2_00->pos).z;
        fVar3 = local_6c;
        if (local_6c < 0.0) {
          fVar3 = -local_6c;
        }
        fVar4 = local_64;
        if (local_64 < 0.0) {
          fVar4 = -local_64;
        }
        if (fVar3 + fVar4 < 6.0) {
          FUN_80088d3c((int)param1);
          *(undefined *)(param2_01 + 0x46) = 1;
        }
        objMove((double)((param1->vel).x * timeDelta),(double)((param1->vel).y * timeDelta),
                (double)((param1->vel).z * timeDelta),param1);
      }
    }
    if ((*(byte *)((int)param2_01 + 0x119) & 8) == 0) {
      if ((((param1->flags_0xaf & CanPressAToTalk) != 0) && (uVar7 = mainGetBit(0x3c4), uVar7 == 0))
         && (dVar9 = (double)objDistObj2ObjXZ(param1,param2), dVar9 < 25.0)) {
        if ((*(byte *)((int)param2_01 + 0x119) & 1) == 0) {
          FUN_802955f8(param1);
        }
        else {
          if ((param1->pos).pos.y - (param2->pos).pos.y < 0.0) {
            fVar3 = -((param1->pos).pos.y - (param2->pos).pos.y);
          }
          else {
            fVar3 = (param1->pos).pos.y - (param2->pos).pos.y;
          }
          if (fVar3 < 12.0) {
            param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
            *(undefined *)(param2_01 + 0x46) = 6;
            param1->hitstate->flags = param1->hitstate->flags & 0xfffe;
          }
        }
      }
    }
    else {
      param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
      FUN_80088da4((int)param1);
      sVar2._0_1_ = param2_00[1].loadFlags;
      sVar2._1_1_ = param2_00[1].mapStates2;
      uVar7 = mainGetBit((int)sVar2);
      if (uVar7 != 0) {
        *(byte *)((int)param2_01 + 0x119) = *(byte *)((int)param2_01 + 0x119) & 0xf6;
        param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
        FUN_80088d3c((int)param1);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    DBstealerworm_func05
   
   Library: KioskDefault 0 0 */

void DBstealerworm_func05(ObjInstance *param1) { //80294F20
  int iVar1;
  ObjInstance *pOVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar1 = FUN_800883e4((int)param1,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
  puVar4 = param1->state;
  if ((iVar1 == 0x12) && (puVar4[0x118] != '\x04')) {
    pOVar2 = Object_objGetMain();
    iVar1 = FUN_801a7e68((int)pOVar2);
    iVar3 = (**(code **)(**(int **)(iVar1 + 0x68) + 0x2c))(iVar1,0x10,0);
    if (iVar3 != 2) {
      param1->hitstate->flags = param1->hitstate->flags & 0xfffe;
      (**(code **)(**(int **)(iVar1 + 0x68) + 0x2c))(iVar1,2,param1);
      puVar4[0x118] = 4;
      printf("Caught");
    }
  }
  if (puVar4[0x118] != '\t') {
    iVar1 = FUN_800bb7e0(9.0,&(param1->oldPos).x,&(param1->pos).pos.x,1,(ObjInstance **)0x0,param1,8
                         ,-1,0xff,'\0');
    if (iVar1 != 0) {
      (param1->vel).x = -((param1->vel).x * 0.95 - (param1->vel).x);
      (param1->vel).z = -((param1->vel).z * 0.95 - (param1->vel).z);
      printf(" Hit Line ");
    }
  }
  (param1->oldPos).x = (param1->pos).pos.x;
  (param1->oldPos).y = (param1->pos).pos.y;
  (param1->oldPos).z = (param1->pos).pos.z;
  return;
}


/* Library Function - Single Match
    DBstealerworm_func06
   
   Library: KioskDefault 0 0 */

void DBstealerworm_func06
               (ObjInstance *param1,Gfx **param2,undefined4 *param3,undefined4 *param4,
               undefined4 *param5,char param6) { //8029508C
  undefined *puVar1;
  
  puVar1 = param1->state;
  if ((((param6 != '\0') && (puVar1[0x118] != '\f')) && (puVar1[0x118] != '\x04')) &&
     (puVar1[0x118] != '\v')) {
    objRenderCurrentModel(param1,param2,param3,param4,param5);
  }
  return;
}


/* Library Function - Single Match
    DBstealerworm_func07
   
   Library: KioskDefault 0 0 */

void DBstealerworm_func07(ObjInstance *param1) { //80295118
  Object_removePlayerObj(param1,0x26);
  return;
}


undefined4 DBstealerworm_func08(void) { //80295144
  return 0;
}


undefined4 DBstealerworm_func09(void) { //8029514C
  return 0x124;
}


/* Library Function - Single Match
    DBstealerworm_func0A
   
   Library: KioskDefault 0 0 */

bool DBstealerworm_func0A(int param1) { //80295B00
  return (bool)('\x01' - (*(char *)(*(int *)(param1 + 0xb8) + 0x118) == '\x03'));
}


/* Library Function - Single Match
    DBstealerworm_func0B
   
   Library: KioskDefault 0 0 */

bool DBstealerworm_func0B(int param1,undefined4 *param2) { //80295B30
  bool bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param1 + 0xb8);
  bVar1 = *(char *)(iVar2 + 0x118) == '\v';
  if (bVar1) {
    *(undefined4 *)(iVar2 + 0x10c) = *param2;
    *(undefined4 *)(iVar2 + 0x110) = param2[1];
    *(undefined4 *)(iVar2 + 0x114) = param2[2];
  }
  return bVar1;
}

