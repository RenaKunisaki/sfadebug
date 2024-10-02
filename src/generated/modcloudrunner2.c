
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void modcloudrunner2_initialise(undefined4 param) { //8013B838
  return;
}


/* @description Called when DLL is unloaded */

void modcloudrunner2_release(void) { //8013B83C
  return;
}


undefined4 modcloudrunner2_func03(int param1,int param2,int param3,uint param4) { //8013B840
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint local_3bc;
  undefined4 local_3b0;
  float local_3ac;
  float local_3a8;
  float local_3a4;
  undefined *local_3a0;
  undefined2 local_39c;
  undefined local_39a;
  undefined4 local_398;
  float local_394;
  float local_390;
  float local_38c;
  undefined *local_388;
  undefined2 local_384;
  undefined local_382;
  undefined4 local_380;
  float local_37c;
  float local_378;
  float local_374;
  undefined *local_370;
  undefined2 local_36c;
  undefined local_36a;
  undefined4 local_368;
  float local_364;
  float local_360;
  float local_35c;
  undefined4 local_358;
  undefined2 local_354;
  undefined local_352;
  undefined4 local_350;
  float local_34c;
  float local_348;
  float local_344;
  undefined4 local_340;
  undefined2 local_33c;
  undefined local_33a;
  undefined4 local_338;
  float local_334;
  float local_330;
  float local_32c;
  undefined *local_328;
  undefined2 local_324;
  undefined local_322;
  undefined4 local_320;
  float local_31c;
  float local_318;
  float local_314;
  undefined4 local_310;
  undefined2 local_30c;
  undefined local_30a;
  undefined4 auStack_308 [150];
  undefined4 *local_b0;
  int local_ac;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined2 local_6c;
  undefined2 auStack_6a [7];
  uint local_5c;
  undefined local_58;
  undefined local_57;
  undefined local_56;
  undefined local_55;
  undefined local_53;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  uVar1 = 0;
  printf("TRACE: '%s' {Line %d}","modcloudrunner2.c",0x54);
  local_39a = 0;
  local_39c = 8;
  local_3a0 = &DAT_802fd460;
  local_3b0 = 4;
  local_3ac = 0.0;
  local_3a8 = 0.0;
  local_3a4 = 0.0;
  local_382 = 0;
  local_384 = 8;
  local_388 = &DAT_802fd44c;
  local_398 = 2;
  uStack_24 = randInt(10,0xf);
  uStack_24 = uStack_24 ^ 0x80000000;
  local_28 = 0x43300000;
  local_394 = (float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0) * 0.4;
  uStack_2c = randInt(10,0xf);
  uStack_2c = uStack_2c ^ 0x80000000;
  local_30 = 0x43300000;
  local_390 = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) * 0.4;
  uStack_34 = randInt(10,0xf);
  uStack_34 = uStack_34 ^ 0x80000000;
  local_38 = 0x43300000;
  local_38c = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0) * 0.8;
  local_36a = 0;
  local_36c = 9;
  local_370 = &DAT_802fd44c;
  local_380 = 0x80;
  local_37c = 0.0;
  local_378 = 0.0;
  local_374 = -16383.0;
  local_352 = 1;
  local_354 = 0x9c;
  local_358 = 0;
  local_368 = 0x800000;
  local_364 = 2.0;
  local_360 = 1.0;
  local_35c = 0.0;
  local_33a = 1;
  local_33c = 0;
  local_340 = 0;
  local_350 = 0x400000;
  uStack_3c = randInt(-2000,200);
  uStack_3c = uStack_3c ^ 0x80000000;
  local_40 = 0x43300000;
  local_34c = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0);
  uStack_44 = randInt(-200,200);
  uStack_44 = uStack_44 ^ 0x80000000;
  local_48 = 0x43300000;
  local_348 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  uStack_4c = randInt(-200,200);
  uStack_4c = uStack_4c ^ 0x80000000;
  local_50 = 0x43300000;
  local_344 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
  local_322 = 1;
  local_324 = 9;
  local_328 = &DAT_802fd44c;
  local_338 = 4;
  local_334 = 0.0;
  local_330 = 0.0;
  local_32c = 0.0;
  puVar3 = &local_320;
  if (param2 == 0) {
    local_30a = 3;
    local_30c = 0;
    local_310 = 0;
    local_320 = 0x20000000;
    local_31c = 999.0;
    local_318 = 94.0;
    local_314 = 95.0;
    puVar3 = auStack_308;
  }
  local_6c = (undefined2)param2;
  if (param2 == 0) {
    local_80 = 0.0;
  }
  else {
    local_80 = 135.0;
  }
  local_7c = 0.0;
  local_84 = 0.0;
  local_90 = 0.0;
  local_8c = 0.0;
  local_88 = 0.0;
  local_78 = 1.0;
  local_70 = 1;
  local_74 = 0;
  local_57 = 9;
  local_56 = 0;
  local_55 = 0;
  local_53 = (undefined)(((int)puVar3 - (int)&local_3b0) / 0x18);
  iVar2 = 0;
  local_3bc = param4;
  local_ac = param1;
  while( true ) {
    if (6 < iVar2) break;
    auStack_6a[iVar2] = (&DAT_802fd470)[iVar2];
    iVar2 = iVar2 + 1;
  }
  local_b0 = &local_3b0;
  local_5c = local_3bc | 0x4000000;
  if ((local_3bc & 1) != 0) {
    if (local_ac == 0) {
      local_84 = local_84 + *(float *)(param3 + 0xc);
      local_80 = local_80 + *(float *)(param3 + 0x10);
      local_7c = local_7c + *(float *)(param3 + 0x14);
    }
    else {
      local_84 = local_84 + *(float *)(local_ac + 0x18);
      local_80 = local_80 + *(float *)(local_ac + 0x1c);
      local_7c = local_7c + *(float *)(local_ac + 0x20);
    }
  }
  if (param2 == 0) {
    local_58 = 0;
                    /* {@symbol 800e0934} */
    uVar1 = (**(code **)(*(int *)pDll_projgfx + 8))
                      (&local_b0,0,9,&PTR_DAT_802fd3c0,8,&DAT_802fd41c,0x156,0);
  }
  else if (param2 == 1) {
    local_58 = 0;
                    /* {@symbol 800e0934} */
    uVar1 = (**(code **)(*(int *)pDll_projgfx + 8))
                      (&local_b0,0,9,&PTR_DAT_802fd3c0,8,&DAT_802fd41c,0x47,0);
  }
  return uVar1;
}

