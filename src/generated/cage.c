
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void cage_initialise(undefined4 param) { //8021CB7C
  return;
}


/* @description Called when DLL is unloaded */

void cage_release(void) { //8021CB80
  return;
}


/* Library Function - Single Match
    lightfootRelated01AB_func03
   
   Library: KioskDefault 0 0 */

void cage_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8021CB84
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  puVar2[2] = 2;
  *(float *)(puVar2 + 4) = 6.0;
  *(float *)(puVar2 + 0xc) = 0.0;
  puVar2[3] = 2;
  *(float *)(puVar2 + 8) = 7.0;
  *(float *)(puVar2 + 0x10) = 0.0;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  uVar1 = mainGetBit(0x3c3);
  if (uVar1 == 0) {
    puVar2[1] = 0;
  }
  else {
    puVar2[1] = 1;
  }
  *(float *)(puVar2 + 0x3c) = 0.0;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    lightfootRelated01AB_func04
   
   Library: KioskDefault 0 0 */

void cage_update(ObjInstance *param1) { //8021CC30
  byte bVar1;
  float fVar2;
  float fVar3;
  ObjInstance *pOVar4;
  uint uVar5;
  int iVar6;
  ObjDef *pOVar7;
  short sVar8;
  char *pcVar9;
  float local_34;
  double local_30;
  double local_28;
  
  local_34 = 100.0;
  pcVar9 = param1->state;
  pOVar7 = param1->def;
  if (*(int *)(pcVar9 + 0x14) == 0) {
    pOVar4 = getSeqObj(0x28,param1,&local_34);
    *(ObjInstance **)(pcVar9 + 0x14) = pOVar4;
    if (*(int *)(pcVar9 + 0x14) == 0) {
      printf("can't find lightfoot");
      return;
    }
    *(float *)(pcVar9 + 0x1c) = *(float *)(*(int *)(pcVar9 + 0x14) + 0xc) - (param1->pos).pos.x;
    *(float *)(pcVar9 + 0x20) = *(float *)(*(int *)(pcVar9 + 0x14) + 0x10) - (param1->pos).pos.y;
    *(float *)(pcVar9 + 0x24) = *(float *)(*(int *)(pcVar9 + 0x14) + 0x14) - (param1->pos).pos.z;
  }
  if (*(int *)(pcVar9 + 0x18) == 0) {
    pOVar4 = getSeqObj(5,param1,&local_34);
    *(ObjInstance **)(pcVar9 + 0x18) = pOVar4;
    if (*(int *)(pcVar9 + 0x18) == 0) {
      printf("can't find lightfoot");
      return;
    }
    *(float *)(pcVar9 + 0x28) = *(float *)(*(int *)(pcVar9 + 0x18) + 0xc) - (param1->pos).pos.x;
    *(float *)(pcVar9 + 0x2c) = *(float *)(*(int *)(pcVar9 + 0x18) + 0x10) - (param1->pos).pos.y;
    *(float *)(pcVar9 + 0x30) = *(float *)(*(int *)(pcVar9 + 0x18) + 0x14) - (param1->pos).pos.z;
  }
  bVar1 = pcVar9[1];
  if (bVar1 == 2) {
    *(float *)(pcVar9 + 0x34) = *(float *)(pcVar9 + 0x34) + timeDelta;
    if (*(float *)(pcVar9 + 0x34) < *(float *)(pcVar9 + 0x38)) {
      fVar2 = *(float *)(pcVar9 + 0x34);
      fVar3 = *(float *)(pcVar9 + 0x38);
      (param1->pos).pos.y =
           *(float *)(pcVar9 + 0x34) * -0.04 * *(float *)(pcVar9 + 0x34) + (pOVar7->pos).y;
      iVar6 = (int)-(*(float *)(pcVar9 + 0xc) * (fVar2 / fVar3) - *(float *)(pcVar9 + 0xc));
      local_30 = (double)(longlong)iVar6;
      (param1->pos).rotation.y = (short)iVar6;
      iVar6 = (int)-(*(float *)(pcVar9 + 0x10) * (fVar2 / fVar3) - *(float *)(pcVar9 + 0x10));
      local_28 = (double)(longlong)iVar6;
      (param1->pos).rotation.z = (short)iVar6;
      for (sVar8 = 0; sVar8 < 2; sVar8 = sVar8 + 1) {
        FUN_8021d400((int)param1,(int)sVar8);
      }
    }
    else {
      FUN_8021d508((int)param1);
      audioSfxFn_800688bc((double)(param1->prevPos).x,(double)(param1->prevPos).y,
                          (double)(param1->prevPos).z,0x5c,0x7f,"cage.c",(int *)0xf4);
      for (sVar8 = 0; sVar8 < 2; sVar8 = sVar8 + 1) {
        FUN_8021d400((int)param1,(int)sVar8);
      }
      *(float *)(pcVar9 + 0x34) = 0.0;
      *(float *)(pcVar9 + 0x3c) = 0.03;
      pcVar9[1] = '\x03';
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      if ((param1->pos).rotation.y < 1) {
        local_28 = (double)CONCAT44(0x43300000,(uint)(byte)pcVar9[2]);
        *(float *)(pcVar9 + 4) =
             *(float *)(pcVar9 + 4) + ((float)(local_28 - 4503599627370496.0) * timeDelta) / 10.0;
      }
      else {
        local_28 = (double)CONCAT44(0x43300000,(uint)(byte)pcVar9[2]);
        *(float *)(pcVar9 + 4) =
             *(float *)(pcVar9 + 4) - ((float)(local_28 - 4503599627370496.0) * timeDelta) / 10.0;
      }
      local_28 = (double)CONCAT44(0x43300000,(int)(param1->pos).rotation.y ^ 0x80000000);
      (param1->pos).rotation.y =
           (short)(int)(*(float *)(pcVar9 + 4) * timeDelta + (float)(local_28 - 4503601774854144.0))
      ;
      if ((param1->pos).rotation.z < 1) {
        local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pcVar9[3]);
        *(float *)(pcVar9 + 8) =
             *(float *)(pcVar9 + 8) + ((float)(local_30 - 4503599627370496.0) * timeDelta) / 10.0;
      }
      else {
        local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pcVar9[3]);
        *(float *)(pcVar9 + 8) =
             *(float *)(pcVar9 + 8) - ((float)(local_30 - 4503599627370496.0) * timeDelta) / 10.0;
      }
      local_30 = (double)CONCAT44(0x43300000,(int)(param1->pos).rotation.z ^ 0x80000000);
      iVar6 = (int)(*(float *)(pcVar9 + 8) * timeDelta + (float)(local_30 - 4503601774854144.0));
      local_28 = (double)(longlong)iVar6;
      (param1->pos).rotation.z = (short)iVar6;
      if ((0.0 <= *(float *)(pcVar9 + 0xc)) || ((param1->pos).rotation.y < 0)) {
        if ((0.0 < *(float *)(pcVar9 + 0xc)) && ((param1->pos).rotation.y < 1)) {
          if ((byte)pcVar9[2] < 3) {
            (param1->pos).rotation.y = (short)(int)-*(float *)(pcVar9 + 0xc);
            *(float *)(pcVar9 + 4) = -6.0;
          }
          else {
            pcVar9[2] = pcVar9[2] + -2;
            *(float *)(pcVar9 + 4) = (*(float *)(pcVar9 + 4) * 82.0) / 100.0;
          }
        }
      }
      else if ((byte)pcVar9[2] < 3) {
        (param1->pos).rotation.y = (short)(int)-*(float *)(pcVar9 + 0xc);
        *(float *)(pcVar9 + 4) = 6.0;
      }
      else {
        pcVar9[2] = pcVar9[2] + -2;
        *(float *)(pcVar9 + 4) = (*(float *)(pcVar9 + 4) * 83.0) / 100.0;
      }
      local_30 = (double)CONCAT44(0x43300000,(int)(param1->pos).rotation.y ^ 0x80000000);
      *(float *)(pcVar9 + 0xc) = (float)(local_30 - 4503601774854144.0);
      if ((0.0 <= *(float *)(pcVar9 + 0x10)) || ((param1->pos).rotation.z < 0)) {
        if ((0.0 < *(float *)(pcVar9 + 0x10)) && ((param1->pos).rotation.z < 1)) {
          if ((byte)pcVar9[3] < 3) {
            (param1->pos).rotation.z = (short)(int)-*(float *)(pcVar9 + 0x10);
            *(float *)(pcVar9 + 8) = -7.0;
          }
          else {
            pcVar9[3] = pcVar9[3] + -2;
            *(float *)(pcVar9 + 8) = (*(float *)(pcVar9 + 8) * 81.0) / 100.0;
          }
        }
      }
      else if ((byte)pcVar9[3] < 3) {
        (param1->pos).rotation.z = (short)(int)-*(float *)(pcVar9 + 0x10);
        *(float *)(pcVar9 + 8) = 7.0;
      }
      else {
        pcVar9[3] = pcVar9[3] + -2;
        *(float *)(pcVar9 + 8) = (*(float *)(pcVar9 + 8) * 82.0) / 100.0;
      }
      local_30 = (double)CONCAT44(0x43300000,(int)(param1->pos).rotation.z ^ 0x80000000);
      *(float *)(pcVar9 + 0x10) = (float)(local_30 - 4503601774854144.0);
      iVar6 = FUN_800883e4((int)param1,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
      if (iVar6 == 0xe) {
        if (*pcVar9 == '\0') {
          *pcVar9 = '\x01';
          FUN_8021d610((int)param1);
        }
        else {
          *(float *)(pcVar9 + 0x38) = 35.355;
          *(float *)(pcVar9 + 0x34) = 0.0;
          pcVar9[1] = '\x02';
        }
      }
      for (sVar8 = 0; sVar8 < 2; sVar8 = sVar8 + 1) {
        FUN_8021d400((int)param1,(int)sVar8);
      }
    }
    else if (true) {
      FUN_8021d508((int)param1);
      *(float *)(pcVar9 + 0x3c) = 1.0;
      uVar5 = mainGetBit(0x3b0);
      if (uVar5 == 0) {
        for (sVar8 = 0; sVar8 < 2; sVar8 = sVar8 + 1) {
          FUN_8021d400((int)param1,(int)sVar8);
        }
                    /* {@symbol 800d022c} */
        (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,*(undefined4 *)(pcVar9 + 0x14),0xffffffff);
      }
      pcVar9[1] = '\x04';
    }
  }
  else if ((bVar1 < 4) &&
          (*(float *)(pcVar9 + 0x34) = *(float *)(pcVar9 + 0x34) + timeDelta,
          30.0 < *(float *)(pcVar9 + 0x34))) {
    mainSetBits(0x3c3,1);
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,*(undefined4 *)(pcVar9 + 0x14),0xffffffff);
    pcVar9[1] = '\x04';
  }
  objRunAnimation((double)*(float *)(pcVar9 + 0x3c),(double)timeDelta,(int)param1,(float *)0x0);
  return;
}


/* @description Override hit detection */

void cage_hitDetect(ObjInstance *this) { //8021D38C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void cage_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                 undefined param5,bool shouldRender) { //8021D390
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

void cage_free(ObjInstance *this,int param2) { //8021D3EC
  return;
}


undefined4 cage_func08(ObjInstance *this) { //8021D3F0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int cage_getExtraSize(void) { //8021D3F8
  return 0x40;
}

