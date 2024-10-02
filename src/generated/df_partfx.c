
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void partfx_dfnning_initialise(undefined4 param) { //801154FC
  return;
}


/* @description Called when DLL is unloaded */

void partfx_dfnning_release(void) { //80115500
  return;
}


void partfx_dfnning_func03(void) { //80115504
  return;
}


void partfx_dfnning_func05(void) { //80115508
  return;
}


/* Library Function - Single Match
    partfx_dfnning_func04
   
   Library: KioskDefault 0 0 */

undefined4
partfx_dfnning_func04(int *param1,int param2,undefined2 *param3,uint param4,undefined param5) { //8011550C
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined2 local_94;
  undefined2 local_92;
  undefined2 local_90;
  undefined4 local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined2 local_5e;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined *local_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined local_42;
  undefined local_40;
  undefined local_3f;
  undefined local_3e;
  undefined4 local_38;
  undefined *puStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  if (param1 == (int *)0x0) {
    printf("PARTFX dfning NULL no longer allowed for object...returning type %d",param2);
    return 0xffffffff;
  }
  if ((param4 & 0x200000) != 0) {
    if (param3 == (undefined2 *)0x0) {
      printf("ERROR partfx EXF_NOOWNER & no attrib %d",param2);
      return 0xffffffff;
    }
    local_88 = *(float *)(param3 + 6);
    local_84 = *(float *)(param3 + 8);
    local_80 = *(float *)(param3 + 10);
    local_8c = *(undefined4 *)(param3 + 4);
    local_90 = param3[2];
    local_92 = param3[1];
    local_94 = *param3;
    local_3e = param5;
  }
  local_5c = 0;
  local_58 = 0;
  local_42 = (undefined)param2;
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_7c = 0.0;
  local_78 = 0.0;
  local_74 = 0.0;
  local_64 = 0.0;
  local_98 = 0;
  local_9c = 0xffffffff;
  local_40 = 0xff;
  local_3f = 0;
  local_5e = 0;
  local_48 = 0xffff;
  local_46 = 0xffff;
  local_44 = 0xffff;
  local_54 = 0xffff;
  local_50 = (undefined *)0xffff;
  local_4c = 0xffff;
  local_a0 = param1;
  if (param2 == 0x44f) {
    if (param3 == (undefined2 *)0x0) {
      DAT_80385e64 = 0.0;
      DAT_80385e68 = 0.0;
      DAT_80385e6c = 0.0;
      DAT_80385e60 = 1.0;
      DAT_80385e58 = 0;
      DAT_80385e5a = 0;
      DAT_80385e5c = 0;
      param3 = &DAT_80385e58;
    }
                    /* {@symbol 800dac04} */
    (**(code **)(*(int *)pDll_TrickyWalk + 0x10))
              ((double)*(float *)(param3 + 6),(double)*(float *)(param3 + 8),
               (double)*(float *)(param3 + 10),0x4010000000000000);
    iVar2 = randInt(0x34,0x35);
    audioTryStartSfx(param1,1,(ushort)iVar2,0x7f,"df_partfx.c",0xba);
    local_98 = 1;
    local_64 = 0.0001;
    local_5c = 0xa000001;
    local_5e = 0x56;
  }
  else if (param2 < 0x44f) {
    if (param2 == 0x44d) {
      uVar1 = randInt(-10,10);
      puStack_34 = (undefined *)(uVar1 ^ 0x80000000);
      local_38 = 0x43300000;
      local_7c = (float)((double)CONCAT44(0x43300000,puStack_34) - 4503601774854144.0) * 0.01;
      uStack_2c = randInt(-10,10);
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      local_74 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 0.01;
      local_64 = 0.08;
      local_98 = 600;
      local_40 = 0x7f;
      local_5c = 0xa100100;
      local_58 = 0x20;
      local_5e = 0x62;
      local_48 = 0x400;
      local_46 = 60000;
      local_44 = 0x1000;
      local_54 = 0;
      local_50 = &DAT_0000c350;
      local_4c = 0;
    }
    else if (param2 < 0x44d) {
      if (param2 < 0x44c) goto LAB_80115a48;
      uStack_24 = randInt(-10,10);
      uStack_24 = uStack_24 ^ 0x80000000;
      local_28 = 0x43300000;
      local_7c = (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) * 0.025;
      uStack_2c = randInt(10,0x14);
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      local_78 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 0.02;
      uVar1 = randInt(-10,10);
      puStack_34 = (undefined *)(uVar1 ^ 0x80000000);
      local_38 = 0x43300000;
      local_74 = (float)((double)CONCAT44(0x43300000,puStack_34) - 4503601774854144.0) * 0.025;
      local_64 = 0.01;
      local_98 = 0x6e;
      local_5c = 0x8a100208;
      local_58 = 0x20;
      local_5e = 0x5f;
      local_48 = 0xffff;
      local_46 = 0xffff;
      local_44 = 0xffff;
      local_54 = 0x400;
      local_50 = &DAT_0000ea60;
      local_4c = 0x1000;
    }
    else {
      local_6c = 610.0;
      local_64 = 0.0023;
      local_98 = 200;
      local_5c = 0x11000004;
      local_5e = 0x151;
      local_9c = 0x44f;
    }
  }
  else if (param2 == 0x451) {
    iVar2 = randInt(0x34,0x35);
    audioTryStartSfx(param1,1,(ushort)iVar2,0x7f,"df_partfx.c",0xcb);
    local_98 = 100;
    puStack_34 = &DAT_80000064;
    local_38 = 0x43300000;
    local_64 = 0.0;
    local_5c = 0xa100201;
    local_5e = 0x56;
  }
  else {
    if (0x450 < param2) {
LAB_80115a48:
      printf(s_PARTFX_dfalls_type_<__d_>_not_fo_802f8c00,param2);
      return 0xffffffff;
    }
    local_6c = 110.0;
    local_64 = 0.0023;
    local_98 = 200;
    local_5c = 0x11000004;
    local_5e = 0x151;
    local_9c = 0x451;
  }
  local_5c = local_5c | param4;
  if (((local_5c & 1) != 0) && ((param4 & 2) != 0)) {
    printf("error in partfx ABS and REL %d",param2);
    local_5c = local_5c ^ 2;
  }
  if ((local_5c & 1) != 0) {
    if ((param4 & 0x200000) == 0) {
      if (local_a0 != (int *)0x0) {
        local_70 = local_70 + (float)local_a0[6];
        local_6c = local_6c + (float)local_a0[7];
        local_68 = local_68 + (float)local_a0[8];
      }
    }
    else {
      local_70 = local_70 + local_88;
      local_6c = local_6c + local_84;
      local_68 = local_68 + local_80;
    }
  }
                    /* {@symbol 800db60c} */
  uVar3 = (**(code **)(*(int *)pDll_modgfx + 8))(&local_a0,0xffffffff);
  return uVar3;
}

