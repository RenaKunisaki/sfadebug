
/* Library Function - Single Match
    objHitReactFn_80089890
   
   Library: KioskDefault 0 0 */

uint objHitReactFn_80089890(ObjInstance *param1,int param2,byte param3,uint param4,float *param5) { //80089890
  int iVar1;
  LoadedDll *dll;
  ushort *puVar2;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  int local_44;
  int local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [2];
  
  local_58 = 8;
  local_54 = 0xb4;
  local_50 = 0xf0;
  local_4c = 0xff;
  dll = (LoadedDll *)0x0;
  if ((param4 & 0xff) != 0) {
    OSReport("hitstate frame=%f",(double)param1->animTimer);
    iVar1 = objRunAnimation((double)*param5,(double)timeDelta,(int)param1,(float *)0x0);
    if (iVar1 != 0) {
      OSReport("reset");
      param4 = 0;
    }
  }
  local_40 = FUN_800884c8((int)param1,(undefined4 *)0x0,&local_44,(uint *)0x0,&local_30,&local_2c,
                          local_28);
  if (local_40 != 0) {
    local_30 = local_30 + playerMapOffsetX;
    local_28[0] = local_28[0] + playerMapOffsetZ;
    local_34 = 1.0;
    local_38 = 0;
    local_3a = 0;
    local_3c = 0;
    local_44 = (int)*(char *)(*(int *)((int)param1->modelInstances->mtxs
                                            [(char)param1->curModel + -3]->m11 + 0x40) +
                             local_44 * 0x18 + 0x16);
    if ((int)(uint)param3 <= local_44) {
      OSReport("objHitReact.c: sphere overflow! %d",local_44);
      local_44 = 0;
    }
    puVar2 = (ushort *)(param2 + local_44 * 0x14);
    if (-1 < (short)*puVar2) {
      audioTryStartSfx((int *)param1,1,*puVar2,0x7f,"objhits.c",0x4c6);
    }
    if (-1 < (short)puVar2[1]) {
      audioTryStartSfx((int *)param1,0x10,puVar2[1],0x7f,"objhits.c",0x4c9);
    }
    if (*(char *)(puVar2 + 4) == '\x01') {
      if (true) {
        dll = (LoadedDll *)DLL_setup(0x1002,1,FALSE);
      }
      (**(code **)(dll->id + 4))(0,1,&local_3c,0x401,0xffffffff,&local_58);
      if (dll != (LoadedDll *)0x0) {
        DLL_free(dll);
      }
    }
    else {
      local_48 = 0.014;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))
                (param1,0x325,&local_3c,&DAT_00200001,0xffffffff,&local_48);
      local_34 = 92.0;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x323,&local_3c,&DAT_00200001,0xffffffff,0);
      local_48 = 0.015;
      local_34 = 231.0;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))
                (param1,0x323,&local_3c,&DAT_00200001,0xffffffff,&local_48);
      local_30 = local_30 - (param1->prevPos).x;
      local_2c = local_2c - (param1->prevPos).y;
      local_28[0] = local_28[0] - (param1->prevPos).z;
      local_34 = 123.0;
      for (iVar1 = 0; iVar1 < 0xf; iVar1 = iVar1 + 1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(param1,0x324,&local_3c,2,0xffffffff,0);
      }
    }
    if (((param4 & 0xff) == 0) && (-1 < (short)puVar2[2])) {
      Object_ObjAnimSetMove(0.0,param1,(int)(short)puVar2[2],0);
      *param5 = *(float *)(puVar2 + 6);
      param4 = 1;
    }
  }
  return param4;
}

