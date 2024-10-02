
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SHroot_initialise(undefined4 param) { //80253E6C
  return;
}


/* @description Called when DLL is unloaded */

void SHroot_release(void) { //80253E70
  return;
}


/* Library Function - Single Match
    dll_1EB_func03
   
   Library: KioskDefault 0 0 */

void SHroot_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                 float y,float z) { //80253E74
  short sVar1;
  short sVar2;
  uint uVar3;
  float *pfVar4;
  
  pfVar4 = (float *)this->state;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  *pfVar4 = (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0) /
            255.0;
  (this->pos).scale = -(*pfVar4 * 0.5 - this->data->scale);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  (this->vel).y = 0.0;
  sVar2._0_1_ = objDef[1].bound;
  sVar2._1_1_ = objDef[1].cullDist;
  uVar3 = mainGetBit((int)sVar2);
  if (uVar3 != 0) {
    *(undefined *)((int)pfVar4 + 0xe) = 4;
  }
  return;
}


/* Library Function - Single Match
    dll_1EB_func04
   
   Library: KioskDefault 0 0 */

void SHroot_update(ObjInstance *this) { //80253F1C
  byte bVar1;
  short sVar2;
  int iVar3;
  ObjDef *pOVar4;
  int iVar5;
  undefined *puVar6;
  int local_34 [6];
  
  puVar6 = this->state;
  pOVar4 = this->def;
  bVar1 = puVar6[0xe];
  if (bVar1 != 2) {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
        if (iVar3 == 0xe) {
          iVar3 = randInt(800,0x4b0);
          *(short *)(puVar6 + 0xc) = (short)iVar3;
          puVar6[0xe] = 3;
          audioTryStartSfx((int *)this,1,0x58,0x7f,"SHroot.c",0x65);
        }
      }
      else if (true) {
        if ((puVar6[0xf] & 2) == 0) {
          iVar3 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                               (double)(this->pos).pos.z,(int)this,local_34,0,0);
          *(float *)(puVar6 + 4) = -100000.0;
          for (iVar5 = 0; iVar5 < iVar3; iVar5 = iVar5 + 1) {
            if (**(float **)(local_34[0] + iVar5 * 4) < (this->pos).pos.y) {
              if (((puVar6[0xf] & 4) == 0) &&
                 (*(char *)(*(int *)(local_34[0] + iVar5 * 4) + 0x14) == '\x0e')) {
                *(undefined4 *)(puVar6 + 8) = **(undefined4 **)(local_34[0] + iVar5 * 4);
                puVar6[0xf] = puVar6[0xf] | 4;
              }
              else if ((puVar6[0xf] & 2) == 0) {
                *(undefined4 *)(puVar6 + 4) = **(undefined4 **)(local_34[0] + iVar5 * 4);
                puVar6[0xf] = puVar6[0xf] | 2;
              }
            }
          }
          puVar6[0xf] = puVar6[0xf] & 0xfe;
        }
        if ((0 < *(short *)(puVar6 + 0x10)) &&
           (*(ushort *)(puVar6 + 0x10) = *(short *)(puVar6 + 0x10) - (ushort)framesThisStep,
           *(short *)(puVar6 + 0x10) < 1)) {
          audioTryStartSfx((int *)this,2,0x22e,0x7f,"SHroot.c",0x91);
        }
        (this->vel).y = -(timeDelta * 0.1 - (this->vel).y);
        if ((this->vel).y < -10.0) {
          (this->vel).y = -10.0;
        }
        (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
        if ((((puVar6[0xf] & 1) == 0) && ((puVar6[0xf] & 4) != 0)) &&
           ((this->pos).pos.y < *(float *)(puVar6 + 8) + 10.0)) {
                    /* {@symbol 800dac04} */
          (**(code **)(*(int *)pDll_TrickyWalk + 0x10))
                    ((double)(this->pos).pos.x,(double)*(float *)(puVar6 + 8),
                     (double)(this->pos).pos.z,0x4024000000000000);
                    /* {@symbol 800db230} */
          (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                    ((double)(this->pos).pos.x,(double)*(float *)(puVar6 + 8),
                     (double)(this->pos).pos.z,0,0,2);
          audioTryStartSfx((int *)this,4,0xf9,0x7f,"SHroot.c",0xa0);
          puVar6[0xf] = puVar6[0xf] | 1;
        }
        if (((puVar6[0xf] & 2) != 0) && ((this->pos).pos.y < *(float *)(puVar6 + 4) + 40.0)) {
          sVar2._0_1_ = pOVar4[1].bound;
          sVar2._1_1_ = pOVar4[1].cullDist;
          mainSetBits((int)sVar2,1);
          puVar6[0xe] = 2;
        }
      }
    }
    else if (bVar1 == 4) {
      if ((puVar6[0xf] & 2) == 0) {
        iVar3 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                             (double)(this->pos).pos.z,(int)this,local_34,0,0);
        *(float *)(puVar6 + 4) = -100000.0;
        for (iVar5 = 0; iVar5 < iVar3; iVar5 = iVar5 + 1) {
          if ((**(float **)(local_34[0] + iVar5 * 4) < (this->pos).pos.y) &&
             ((puVar6[0xf] & 2) == 0)) {
            *(undefined4 *)(puVar6 + 4) = **(undefined4 **)(local_34[0] + iVar5 * 4);
            puVar6[0xf] = puVar6[0xf] | 2;
          }
        }
      }
      if ((puVar6[0xf] & 2) != 0) {
        puVar6[0xe] = 2;
        (this->pos).pos.y = *(float *)(puVar6 + 4) + 40.0;
      }
    }
    else if (bVar1 < 4) {
      (this->pos).rotation.y = *(short *)(puVar6 + 0xc);
      *(short *)(puVar6 + 0xc) =
           (short)(int)((float)((double)CONCAT44(0x43300000,
                                                 (int)*(short *)(puVar6 + 0xc) ^ 0x80000000) -
                               4503601774854144.0) * 0.333);
      if ((this->pos).rotation.y < 10) {
        (this->pos).rotation.y = 0;
        puVar6[0xe] = 1;
        *(undefined2 *)(puVar6 + 0x10) = 0x1e;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void SHroot_hitDetect(ObjInstance *this) { //8025435C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SHroot_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                   undefined param5,bool shouldRender) { //80254360
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

void SHroot_free(ObjInstance *this,int param2) { //802543BC
  return;
}


undefined4 SHroot_func08(ObjInstance *this) { //802543C0
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SHroot_getExtraSize(void) { //802543C8
  return 0x14;
}

