
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void scarab_initialise(undefined4 param) { //801E79DC
  return;
}


/* @description Called when DLL is unloaded */

void scarab_release(void) { //801E79E0
  return;
}


/* Library Function - Single Match
    dll_10F_func03
   
   Library: KioskDefault 0 0 */

void scarab_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //801E79E4
  ObjDefEnum OVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  puVar3[0x22] = 0;
  *(undefined2 *)(puVar3 + 0x14) = *(undefined2 *)&objDef[1].allocatedSize;
  iVar2 = randInt(1000,4000);
  *(short *)(puVar3 + 0x16) = (short)iVar2;
  iVar2 = randInt(0x32,100);
  *(short *)(puVar3 + 0x1c) = (short)iVar2;
  *(float *)(puVar3 + 0xc) = (objDef->pos).y;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  OVar1 = this->romdefno;
  if (OVar1 == GoldScarab) {
    *(undefined2 *)(puVar3 + 0x1e) = 0x166;
    *(undefined2 *)(puVar3 + 0x20) = 0x1fe;
    puVar3[0x25] = 2;
    goto LAB_801e7adc;
  }
  if ((short)OVar1 < 0x3d5) {
    if (OVar1 == GreenScarab) {
      *(undefined2 *)(puVar3 + 0x1e) = 0x167;
      *(undefined2 *)(puVar3 + 0x20) = 0x1ff;
      puVar3[0x25] = 0;
      goto LAB_801e7adc;
    }
    if (0x3d2 < (short)OVar1) {
      *(undefined2 *)(puVar3 + 0x1e) = 0x168;
      *(undefined2 *)(puVar3 + 0x20) = 0x79;
      puVar3[0x25] = 1;
      goto LAB_801e7adc;
    }
  }
  *(undefined2 *)(puVar3 + 0x1e) = 0x165;
  *(undefined2 *)(puVar3 + 0x20) = 0x7b;
  puVar3[0x25] = 3;
LAB_801e7adc:
  objAllocMsgQueue(this,2);
  return;
}


/* Library Function - Single Match
    dll_10F_func04
   
   Library: KioskDefault 0 0 */

void scarab_update(ObjInstance *this) { //801E7AFC
  ObjInstance *param1;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  double dVar6;
  double dVar7;
  float afStack_104 [16];
  float local_c4 [4];
  undefined local_b4;
  undefined local_b0;
  uint auStack_98 [6];
  undefined *local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  int local_64;
  short local_60;
  undefined2 local_5e;
  undefined2 local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack_44;
  
  _savefpr_30();
  local_64 = 0;
  iVar3 = 0;
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_7c = 0.0;
  local_78 = 0.0;
  local_74 = 0.0;
  pfVar5 = (float *)this->state;
  param1 = Object_objGetMain();
  if ((*(byte *)((int)pfVar5 + 0x26) & 1) != 0) {
    while (iVar1 = FUN_80091100((int)this,(uint *)&local_80,(uint *)0x0,(uint *)0x0), iVar1 != 0) {
      if (local_80 == &DAT_0007000b) {
        FUN_801e87f4(this,(int)param1,(int)pfVar5);
        *(byte *)((int)pfVar5 + 0x26) = *(byte *)((int)pfVar5 + 0x26) & 0xfe;
      }
    }
    if ((*(byte *)((int)pfVar5 + 0x26) & 1) != 0) goto LAB_801e8734;
  }
  if (*(short *)(pfVar5 + 5) == 0) {
    *(ushort *)(pfVar5 + 4) = *(short *)(pfVar5 + 4) - (ushort)framesThisStep;
    if (*(short *)(pfVar5 + 4) < 1) {
      *(undefined2 *)(pfVar5 + 4) = 0;
      Object_objFreeObject(this);
    }
  }
  else if (*(char *)((int)pfVar5 + 0x22) == '\0') {
    if (this->hitstate != (HitState *)0x0) {
      FUN_80088d3c((int)this);
    }
    (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
    (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
    (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
    if (-15.0 < (this->vel).y) {
      (this->vel).y = timeDelta * -0.06 + (this->vel).y;
    }
    (this->pos).rotation.z =
         (this->pos).rotation.z + *(short *)((int)pfVar5 + 0x16) * (ushort)framesThisStep;
    iVar3 = FUN_801e8a48((int)this);
    if (iVar3 != 0) {
      (this->pos).rotation.z = 0;
      *(undefined *)((int)pfVar5 + 0x22) = 1;
      *(short *)(pfVar5 + 6) = (this->pos).rotation.x;
      if (this->romdefno == GreenScarab) {
        *pfVar5 = (this->vel).x * 0.15;
        pfVar5[1] = (this->vel).z * 0.15;
      }
      else if (this->romdefno == RedScarab) {
        *pfVar5 = (this->vel).x * 0.65;
        pfVar5[1] = (this->vel).z * 0.65;
      }
      else if (this->romdefno == GoldScarab) {
        *pfVar5 = (this->vel).x * 1.2;
        pfVar5[1] = (this->vel).z * 1.2;
      }
      else if (this->romdefno == RainScarab) {
        *pfVar5 = (this->vel).x * 0.45;
        pfVar5[1] = (this->vel).z * 0.45;
      }
      else if (this->romdefno == Blue_bean) {
        *pfVar5 = 0.0;
        pfVar5[1] = 0.0;
      }
    }
    iVar3 = randInt(0,2);
    if (iVar3 == 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x519,0,1,0xffffffff,0);
    }
  }
  else if ((*(char *)((int)pfVar5 + 0x22) == '\x02') && (*(short *)(pfVar5 + 5) != 0)) {
    uStack_44 = (int)*(short *)(pfVar5 + 7) ^ 0x80000000;
    local_48 = 0x43300000;
    if (pfVar5[2] < (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0)) {
      (this->pos).pos.y = timeDelta * 0.2 + (this->pos).pos.y;
      pfVar5[2] = timeDelta * 0.2 + pfVar5[2];
    }
    iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if (iVar3 == 0xe) {
      *(undefined2 *)((int)pfVar5 + 0x1a) = 0xfa;
      audioTryStartSfx((int *)this,1,199,0x7f,"scarab.c",0x120);
      (this->vel).x = (param1->pos).pos.x - (this->pos).pos.x;
      (this->vel).z = (param1->pos).pos.z - (this->pos).pos.z;
      (this->pos).rotation.x = 0;
      dVar6 = (double)((this->vel).x * (this->vel).x + (this->vel).z * (this->vel).z);
      if (dVar6 != 0.0) {
        dVar6 = sqrt(dVar6);
      }
      (this->vel).x = (this->vel).x / (float)(dVar6 * 2.0);
      (this->vel).z = (this->vel).z / (float)(dVar6 * 2.0);
      (this->pos).rotation.y = 0;
      (this->vel).y = 2.2;
      local_54 = 0.0;
      local_50 = 0.0;
      local_4c = 0.0;
      local_58 = 1.0;
      local_5c = 0;
      local_5e = 0;
      iVar3 = randInt(-10000,10000);
      local_60 = (short)iVar3;
      FUN_8007a878(&local_60,&(this->vel).x);
      uVar2 = getAngle();
      iVar3 = (int)(this->pos).rotation.x - (uVar2 & 0xffff);
      if (0x8000 < iVar3) {
        iVar3 = iVar3 + -0xffff;
      }
      if (iVar3 < -0x8000) {
        iVar3 = iVar3 + 0xffff;
      }
      (this->pos).rotation.x = (short)iVar3;
      *(undefined *)((int)pfVar5 + 0x22) = 0;
      pfVar5[2] = 0.0;
    }
  }
  else if ((*(char *)((int)pfVar5 + 0x22) == '\x01') && (*(short *)(pfVar5 + 5) != 0)) {
    if (*(short *)((int)pfVar5 + 0x1a) == 0) {
      dVar6 = 10000.0;
      iVar1 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                           (double)(this->pos).pos.z,(int)this,&local_64,1,0);
      for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        dVar7 = (double)(**(float **)(local_64 + iVar4 * 4) - (this->pos).pos.y);
        if (dVar7 < 0.0) {
          dVar7 = (double)(float)(dVar7 * -1.0);
        }
        if (dVar7 < dVar6) {
          iVar3 = iVar4;
          dVar6 = dVar7;
        }
      }
      if (local_64 == 0) {
        (this->pos).pos.y = pfVar5[3];
      }
      else {
        (this->pos).pos.y = **(float **)(local_64 + iVar3 * 4);
        FUN_801e884c((short *)this,*(int *)(local_64 + iVar3 * 4),'\x01',afStack_104);
      }
      if (this->romdefno == RainScarab) {
        iVar3 = getAngle();
        (this->pos).rotation.x = (short)iVar3 + 0x7fff;
        iVar3 = randInt(-0x5b4,0x5b4);
        (this->pos).rotation.x = (this->pos).rotation.x + (short)iVar3;
      }
      else {
        iVar3 = randInt(-0x5b4,0x5b4);
        (this->pos).rotation.x = (this->pos).rotation.x + (short)iVar3;
      }
      iVar3 = randInt(-1000,1000);
      (this->pos).rotation.z = (this->pos).rotation.z + (short)iVar3;
      (this->vel).x = *pfVar5;
      (this->vel).y = 0.0;
      (this->vel).z = pfVar5[1];
      local_54 = 0.0;
      local_50 = 0.0;
      local_4c = 0.0;
      local_58 = 1.0;
      local_5c = 0;
      local_5e = 0;
      local_60 = (this->pos).rotation.x - *(short *)(pfVar5 + 6);
      FUN_8007a878(&local_60,&(this->vel).x);
      *(ushort *)(pfVar5 + 5) = *(short *)(pfVar5 + 5) - (ushort)framesThisStep;
      if (*(short *)(pfVar5 + 5) < 1) {
        *(undefined2 *)(pfVar5 + 5) = 0;
      }
      local_7c = (this->vel).x * timeDelta * 1.5 + (this->pos).pos.x;
      local_78 = (this->pos).pos.y + 30.0;
      local_74 = (this->vel).z * timeDelta * 1.5 + (this->pos).pos.z;
      local_70 = (this->pos).pos.x;
      local_6c = (this->pos).pos.y + 30.0;
      local_68 = (this->pos).pos.z;
      local_c4[0] = 0.0;
      local_b4 = 0xff;
      local_b0 = 0;
      mathFn_8006961c(auStack_98,&local_70,&local_7c,local_c4,1);
      pListFn_800b50cc((int)this,(int *)auStack_98,0);
      uVar2 = FUN_800b6f6c((int)this,(int)&local_70,(int)&local_7c,1,(int)afStack_104,0);
      if ((uVar2 != 0) && (this->romdefno == GoldScarab)) {
        *(undefined *)((int)pfVar5 + 0x22) = 2;
        pfVar5[2] = 0.0;
        FUN_801e884c((short *)this,0,'\0',afStack_104);
      }
      if (uVar2 == 0) {
        (this->pos).pos.x = (this->vel).x * timeDelta + (this->pos).pos.x;
        (this->pos).pos.z = (this->vel).z * timeDelta + (this->pos).pos.z;
      }
    }
    else {
      dVar6 = 10000.0;
      iVar1 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                           (double)(this->pos).pos.z,(int)this,&local_64,1,0);
      for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        dVar7 = (double)(**(float **)(local_64 + iVar4 * 4) - (this->pos).pos.y);
        if (dVar7 < 0.0) {
          dVar7 = (double)(float)(dVar7 * -1.0);
        }
        if (dVar7 < dVar6) {
          iVar3 = iVar4;
          dVar6 = dVar7;
        }
      }
      if (local_64 == 0) {
        (this->pos).pos.y = pfVar5[3];
      }
      else {
        (this->pos).pos.y = **(float **)(local_64 + iVar3 * 4);
        FUN_801e884c((short *)this,*(int *)(local_64 + iVar3 * 4),'\x01',afStack_104);
      }
      *(ushort *)((int)pfVar5 + 0x1a) = *(short *)((int)pfVar5 + 0x1a) - (ushort)framesThisStep;
      if (*(short *)((int)pfVar5 + 0x1a) < 1) {
        *(undefined2 *)((int)pfVar5 + 0x1a) = 0;
      }
    }
    if (((*(short *)((int)pfVar5 + 0x1a) != 0) || (this->romdefno != RainScarab)) &&
       (dVar6 = (double)objDistObj2ObjXZ(param1,this), dVar6 < 25.0)) {
      uVar2 = mainGetBit(0x910);
      if (uVar2 == 0) {
                    /* {@symbol 800d1668} */
        (**(code **)(*(int *)pDll_checkpoint + 0x7c))
                  ((int)*(short *)(&DAT_80397bf0 + (uint)*(byte *)((int)pfVar5 + 0x25) * 2),0,0);
        *(undefined2 *)(pfVar5 + 10) = 0xffff;
        *(undefined2 *)((int)pfVar5 + 0x2a) = 0;
        pfVar5[0xb] = 1.0;
        objSendMsg((int)param1,0x7000a,(uint)this,(uint)(pfVar5 + 10));
        mainSetBits(0x910,1);
        *(byte *)((int)pfVar5 + 0x26) = *(byte *)((int)pfVar5 + 0x26) | 1;
      }
      else {
        FUN_801e87f4(this,(int)param1,(int)pfVar5);
      }
      if (this->hitstate != (HitState *)0x0) {
        FUN_80088da4((int)this);
      }
      audioTryStartSfx((int *)this,1,*(ushort *)((int)pfVar5 + 0x1e),0x7f,"scarab.c",0x1b2)
      ;
      uStack_44 = (int)*(short *)(pfVar5 + 8) ^ 0x80000000;
      local_48 = 0x43300000;
      local_58 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,&local_60,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,&local_60,1,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,&local_60,1,0xffffffff,0);
    }
    if ((*(short *)((int)pfVar5 + 0x1a) == 0) && (this->romdefno == RainScarab)) {
      dVar6 = (double)objDistObj2ObjXZ(param1,this);
      if (dVar6 < 20.0) {
        uVar2 = mainGetBit(0x1d9);
        if (uVar2 == 0) {
          objSendMsg((int)param1,0x60004,(uint)this,1);
        }
        (this->pos).pos.x = -(this->vel).x * 26.0 + (this->pos).pos.x;
        (this->pos).pos.z = -(this->vel).z * 26.0 + (this->pos).pos.z;
        audioTryStartSfx((int *)this,1,0xc5,0x7f,"scarab.c",0x1c3);
      }
      iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
      if (iVar3 == 0xe) {
        *(undefined2 *)((int)pfVar5 + 0x1a) = 0xfa;
        audioTryStartSfx((int *)this,1,199,0x7f,"scarab.c",0x1c9);
      }
    }
    else if ((*(short *)((int)pfVar5 + 0x1a) != 0) &&
            ((this->romdefno == RainScarab &&
             (iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0), iVar3 == 0xe
             )))) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51a,0,1,0xffffffff,0);
      audioTryStartSfx((int *)this,1,0xc6,0x7f,"scarab.c",0x1d0);
      FUN_801e87f4(this,(int)param1,(int)pfVar5);
    }
  }
LAB_801e8734:
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void scarab_hitDetect(ObjInstance *this) { //801E8750
  return;
}


/* Library Function - Single Match
    dll_10F_func06
   
   Library: KioskDefault 0 0 */

void scarab_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //801E8754
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (*(short *)(this->state + 0x10) == 0) {
    if (this->flags_0xf8 == 0) {
      if (!shouldRender) {
        return;
      }
    }
    else if (shouldRender != true) {
      return;
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void scarab_free(ObjInstance *this,int param2) { //801E87E0
  return;
}


undefined4 scarab_func08(ObjInstance *this) { //801E87E4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int scarab_getExtraSize(void) { //801E87EC
  return 0x30;
}

