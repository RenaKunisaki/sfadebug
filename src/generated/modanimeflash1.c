
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void modanimeflash1_initialise(undefined4 param) { //8012FB7C
  return;
}


/* @description Called when DLL is unloaded */

void modanimeflash1_release(void) { //8012FB80
  return;
}


undefined4 modanimeflash1_func03(int param1,undefined4 param2,int param3,uint param4) { //8012FB84
  undefined4 uVar1;
  int iVar2;
  uint local_384;
  undefined4 local_378;
  float local_374;
  float local_370;
  float local_36c;
  undefined *local_368;
  undefined2 local_364;
  undefined local_362;
  undefined4 local_360;
  float local_35c;
  float local_358;
  float local_354;
  undefined **local_350;
  undefined2 local_34c;
  undefined local_34a;
  undefined4 local_348;
  float local_344;
  float local_340;
  float local_33c;
  undefined *local_338;
  undefined2 local_334;
  undefined local_332;
  undefined4 local_330;
  float local_32c;
  float local_328;
  float local_324;
  undefined4 local_320;
  undefined2 local_31c;
  undefined local_31a;
  undefined4 local_318;
  float local_314;
  float local_310;
  float local_30c;
  undefined4 local_308;
  undefined2 local_304;
  undefined local_302;
  undefined4 local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  undefined *local_2f0;
  undefined2 local_2ec;
  undefined local_2ea;
  undefined4 local_2e8;
  float local_2e4;
  float local_2e0;
  float local_2dc;
  undefined *local_2d8;
  undefined2 local_2d4;
  undefined local_2d2;
  undefined4 local_2d0;
  float local_2cc;
  float local_2c8;
  float local_2c4;
  undefined *local_2c0;
  undefined2 local_2bc;
  undefined local_2ba;
  undefined4 local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  undefined **local_2a8;
  undefined2 local_2a4;
  undefined local_2a2;
  undefined4 *local_78;
  int local_74;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 auStack_32 [7];
  uint local_24;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_1d;
  undefined local_1b;
  
  printf("TRACE: '%s' {Line %d}","modanimeflash1.c",0x53);
  local_362 = 1;
  local_364 = 0x11;
  local_368 = &DAT_802fa4f4;
  local_378 = 0x4000;
  local_374 = 0.0;
  local_370 = -3.0;
  local_36c = 0.0;
  local_34a = 1;
  local_34c = 0x10;
  local_350 = &PTR_DAT_802fa518;
  local_360 = 2;
  local_35c = 35.0;
  local_358 = 35.0;
  local_354 = 35.0;
  local_332 = 1;
  local_334 = 0x11;
  local_338 = &DAT_802fa4f4;
  local_348 = 0x100;
  local_344 = 0.0;
  local_340 = 0.0;
  local_33c = 1500.0;
  local_31a = 1;
  local_31c = 2;
  local_320 = 0;
  local_330 = 0x4000000;
  local_32c = 1.0;
  local_328 = 0.0;
  local_324 = 0.0;
  local_302 = 2;
  local_304 = 2;
  local_308 = 0;
  local_318 = 0x4000000;
  local_314 = 1.0;
  local_310 = 0.0;
  local_30c = 0.0;
  local_2ea = 2;
  local_2ec = 0x11;
  local_2f0 = &DAT_802fa4f4;
  local_300 = 0x4000;
  local_2fc = 0.0;
  local_2f8 = -3.0;
  local_2f4 = 0.0;
  local_2d2 = 2;
  local_2d4 = 0x11;
  local_2d8 = &DAT_802fa4f4;
  local_2e8 = 4;
  local_2e4 = 0.0;
  local_2e0 = 0.0;
  local_2dc = 0.0;
  local_2ba = 2;
  local_2bc = 0x11;
  local_2c0 = &DAT_802fa4f4;
  local_2d0 = 0x100;
  local_2cc = 0.0;
  local_2c8 = 0.0;
  local_2c4 = -1000.0;
  local_2a2 = 2;
  local_2a4 = 0x10;
  local_2a8 = &PTR_DAT_802fa518;
  local_2b8 = 2;
  local_2b4 = 2.0;
  local_2b0 = 2.0;
  local_2ac = 2.0;
  local_20 = 0;
  local_34 = (undefined2)param2;
  local_4c = 0.0;
  local_48 = 135.0;
  local_44 = 0.0;
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_40 = 1.0;
  local_38 = 1;
  local_3c = 0;
  local_1f = 0x11;
  local_1e = 0;
  local_1d = 0x10;
  local_1b = 9;
  iVar2 = 0;
  local_384 = param4;
  local_74 = param1;
  while( true ) {
    if (6 < iVar2) break;
    auStack_32[iVar2] = (&DAT_802fa538)[iVar2];
    iVar2 = iVar2 + 1;
  }
  local_78 = &local_378;
  local_24 = local_384 | 0x4000000;
  if ((local_384 & 1) != 0) {
    if (local_74 == 0) {
      local_4c = local_4c + *(float *)(param3 + 0xc);
      local_48 = local_48 + *(float *)(param3 + 0x10);
      local_44 = local_44 + *(float *)(param3 + 0x14);
    }
    else {
      local_4c = local_4c + *(float *)(local_74 + 0x18);
      local_48 = local_48 + *(float *)(local_74 + 0x1c);
      local_44 = local_44 + *(float *)(local_74 + 0x20);
    }
  }
                    /* {@symbol 800e0934} */
  uVar1 = (**(code **)(*(int *)pDll_projgfx + 8))
                    (&local_78,0,0x11,&PTR_802fa418,8,&DAT_802fa4c4,0x47,0,param1,param2);
  return uVar1;
}

