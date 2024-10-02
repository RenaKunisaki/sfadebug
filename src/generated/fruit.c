
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void fruit_initialise(undefined4 param) { //801DE030
  return;
}


/* @description Called when DLL is unloaded */

void fruit_release(void) { //801DE034
  return;
}


/* Library Function - Single Match
    fruit_func03
   
   Library: KioskDefault 0 0 */

void fruit_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //801DE038
  ushort uVar1;
  ushort uVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  Shadow *pSVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)this->state;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  if (obj2 == (ObjInstance *)0x0) {
    *puVar7 = *(undefined4 *)(objDef + 1);
    uVar1._0_1_ = objDef[1].loadFlags;
    uVar1._1_1_ = objDef[1].mapStates2;
    puVar7[1] = (float)((double)CONCAT44(0x43300000,(uint)uVar1) - 4503599627370496.0);
    uVar2._0_1_ = objDef[1].bound;
    uVar2._1_1_ = objDef[1].cullDist;
    puVar7[2] = (float)((double)CONCAT44(0x43300000,(uint)uVar2) - 4503599627370496.0);
    puVar7[4] = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].pos.x) -
                       4503599627370496.0) / 100.0;
    puVar7[5] = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)&objDef[1].pos.x + 1)) -
                       4503599627370496.0) / 100.0 + (float)puVar7[4];
    puVar7[6] = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)&objDef[1].pos.x + 2)) -
                       4503599627370496.0) / 100.0 + (float)puVar7[5];
    puVar7[7] = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)((int)&objDef[1].pos.x + 3)) -
                       4503599627370496.0) / 100.0 + (float)puVar7[6];
    puVar7[8] = (float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].pos.y) -
                       4503599627370496.0) / 100.0;
    puVar7[10] = (float)((double)CONCAT44(0x43300000,
                                          (int)*(char *)((int)&objDef[1].pos.y + 1) ^ 0x80000000) -
                        4503601774854144.0) / 100.0;
    puVar7[10] = (float)puVar7[10] * 2.0;
    puVar7[9] = 1.0;
    *(undefined2 *)(puVar7 + 0xe) = 0;
    puVar7[0xf] = 0.0;
    puVar7[0x10] = -0.04;
    puVar7[0x11] = 0.0;
    puVar7[0x14] = (float)puVar7[1] * (float)puVar7[6] * (float)puVar7[1] * (float)puVar7[6] *
                   (float)puVar7[1] * (float)puVar7[6] * (float)puVar7[1] * (float)puVar7[6] *
                   (float)puVar7[1] * (float)puVar7[6] * (float)puVar7[1] * (float)puVar7[6] *
                   (float)puVar7[1] * (float)puVar7[6] * (float)puVar7[1] * (float)puVar7[6] *
                   0.00390625;
    iVar4 = randInt(-0x8000,0x7fff);
    (this->pos).rotation.x = (short)iVar4;
    (this->pos).scale = 0.001;
    objSetModelNo(this,0);
    if ((*(short *)((int)&objDef[1].pos.y + 2) == -1) ||
       (uVar5 = mainGetBit((int)*(short *)((int)&objDef[1].pos.y + 2)), uVar5 == 0)) {
      fVar3 = (float)puVar7[2] / (float)puVar7[1];
      if ((float)puVar7[4] <= fVar3) {
        if ((float)puVar7[5] <= fVar3) {
          if ((float)puVar7[6] <= fVar3) {
            FUN_801df374(this);
            *(undefined *)((int)puVar7 + 0x3a) = 3;
          }
          else {
            *(undefined *)((int)puVar7 + 0x3a) = 2;
          }
        }
        else {
          FUN_801df24c((int)this);
          *(undefined *)((int)puVar7 + 0x3a) = 1;
        }
      }
      else {
        *(undefined *)((int)puVar7 + 0x3a) = 0;
      }
    }
    else {
      puVar7[2] = 61.0;
      *(undefined *)((int)puVar7 + 0x3a) = 6;
    }
    pSVar6 = this->shadow;
    if (pSVar6 != (Shadow *)0x0) {
      if ((*(byte *)&objDef[1].pos.z & 1) == 0) {
        iVar4 = FUN_800ba780((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                             (double)(this->pos).pos.z,(int)this,(float *)(puVar7 + 0xc),0);
        if (iVar4 == 0) {
          *(byte *)((int)puVar7 + 0x56) = *(byte *)((int)puVar7 + 0x56) | 1;
        }
        pSVar6->flags = pSVar6->flags | 0x30;
        pSVar6->flags = pSVar6->flags | 0xc00;
        (pSVar6->pos).x = (this->pos).pos.x;
        (pSVar6->pos).y = (this->pos).pos.y - (float)puVar7[0xc];
        (pSVar6->pos).z = (this->pos).pos.z;
        pSVar6->opacity = 0;
      }
      else {
        pSVar6->flags = 0x1000;
      }
    }
  }
  else {
    (this->pos).scale = this->data->scale;
    objSetModelNo(this,0);
    puVar7[1] = 100.0;
    puVar7[2] = 99.0;
    *(undefined *)((int)puVar7 + 0x3a) = 2;
  }
  objAllocMsgQueue(this,2);
  return;
}


/* Library Function - Single Match
    fruit_func04
   
   Library: KioskDefault 0 0 */

void fruit_update(ObjInstance *this) { //801DE43C
  float fVar1;
  ObjInstance *pOVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  ObjDef *pOVar7;
  undefined *puVar8;
  double extraout_f1;
  double extraout_f1_00;
  double param1;
  double param2;
  double param3;
  double param4;
  double in_f5;
  double in_f6;
  double dVar9;
  undefined *local_60;
  undefined auStack_5c [4];
  longlong local_58;
  undefined4 local_50;
  uint uStack_4c;
  longlong local_48;
  undefined4 local_40;
  uint uStack_3c;
  longlong local_38;
  undefined4 local_30;
  uint uStack_2c;
  
  _savefpr_30();
  puVar8 = this->state;
  pOVar7 = this->def;
  local_60 = (undefined *)0x0;
  if ((puVar8[0x56] & 4) != 0) {
    while (iVar3 = FUN_80091100((int)this,(uint *)&local_60,(uint *)0x0,(uint *)0x0), iVar3 != 0) {
      if (local_60 == &DAT_0007000b) {
        pOVar2 = Object_objGetMain();
        FUN_801deff0(this,(int)pOVar2,(int)puVar8);
        puVar8[0x56] = puVar8[0x56] & 0xfb;
      }
    }
    if ((puVar8[0x56] & 4) != 0) goto switchD_801de564_caseD_7;
  }
  if ((puVar8[0x56] & 2) == 0) {
    if ((puVar8[0x56] & 1) == 0) {
      if ((*(byte *)&pOVar7[1].pos.z & 1) == 0) {
        FUN_801df3f0((int)this,(int)this->shadow,(int)puVar8);
      }
      *(float *)(puVar8 + 8) = *(float *)(puVar8 + 8) + timeDelta;
      *(float *)(puVar8 + 0xc) = *(float *)(puVar8 + 0xc) + timeDelta;
      dVar9 = (double)(*(float *)(puVar8 + 8) / *(float *)(puVar8 + 4));
                    /* {@symbol 801de568} */
      switch(puVar8[0x3a]) {
      case 0:
        iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
        if ((iVar3 == 0) &&
           ((*(short *)((int)&pOVar7[1].pos.y + 2) == -1 ||
            (uVar4 = mainGetBit((int)*(short *)((int)&pOVar7[1].pos.y + 2)), uVar4 == 0)))) {
          if (dVar9 <= (double)*(float *)(puVar8 + 0x10)) {
            FUN_801df200((int)this);
          }
          else {
            FUN_801df24c((int)this);
            puVar8[0x3a] = 1;
          }
        }
        else {
          FUN_801df650((int)this);
        }
        break;
      case 1:
        iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
        if ((iVar3 == 0) &&
           ((*(short *)((int)&pOVar7[1].pos.y + 2) == -1 ||
            (uVar4 = mainGetBit((int)*(short *)((int)&pOVar7[1].pos.y + 2)), uVar4 == 0)))) {
          if (dVar9 <= (double)*(float *)(puVar8 + 0x14)) {
                    /* {@symbol 800d2604} */
            iVar3 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_5c);
            if (iVar3 == 0) {
              objRunAnimation(0.006000000052154064,(double)timeDelta,(int)this,(float *)0x0);
            }
            else {
              objRunAnimation(-0.006000000052154064,(double)timeDelta,(int)this,(float *)0x0);
            }
          }
          else {
            FUN_801df6b4(this);
            puVar8[0x3a] = 2;
          }
        }
        else {
          FUN_801df650((int)this);
        }
        break;
      case 2:
        if (dVar9 <= (double)*(float *)(puVar8 + 0x18)) {
          FUN_801df25c(this);
        }
        else {
          FUN_801df374(this);
          puVar8[0x3a] = 3;
        }
        iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
        if ((iVar3 != 0) ||
           ((*(short *)((int)&pOVar7[1].pos.y + 2) != -1 &&
            (uVar4 = mainGetBit((int)*(short *)((int)&pOVar7[1].pos.y + 2)), uVar4 != 0)))) {
          FUN_801df030(this,1);
        }
        break;
      case 3:
        if (dVar9 <= (double)*(float *)(puVar8 + 0x1c)) {
          iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
          if ((iVar3 != 0) ||
             ((*(short *)((int)&pOVar7[1].pos.y + 2) != -1 &&
              (uVar4 = mainGetBit((int)*(short *)((int)&pOVar7[1].pos.y + 2)), uVar4 != 0)))) {
            FUN_801df030(this,2);
          }
        }
        else {
          FUN_801df030(this,0);
        }
        break;
      case 4:
        if (dVar9 <= (double)*(float *)(puVar8 + 0x20)) {
          iVar3 = 0;
          iVar6 = 0;
          do {
            while( true ) {
              if (iVar3 != 0) goto LAB_801de858;
              param4 = (double)*(float *)(puVar8 + 0xc);
              param3 = (double)(*(float *)(puVar8 + 0xc) *
                               (*(float *)(puVar8 + 0x40) + *(float *)(puVar8 + 0x3c)));
              param2 = (double)*(float *)(puVar8 + 0x44);
              fVar1 = (float)(param4 * param3 +
                             (double)(float)(param2 * (double)*(float *)(puVar8 + 0xc) +
                                            (double)*(float *)(puVar8 + 0x2c)));
              if (*(float *)(puVar8 + 0x28) <= 0.0) {
                iVar3 = FUN_801deaf0((double)fVar1,(undefined2 *)this,(int)puVar8);
                param1 = extraout_f1_00;
              }
              else {
                iVar3 = FUN_801de9d4((double)fVar1,(undefined2 *)this,(int)puVar8);
                param1 = extraout_f1;
              }
              iVar6 = iVar6 + 1;
              if (iVar6 != 100) break;
              printf("Fruit info: nextY %f, acc %f, water acc %f, startHeight %f, yStart %f, obj->fy %f",param1,param2,param3,param4,in_f5,
                     in_f6);
              printf("Fruit upwardsBounceVelocity %f movementFdt %f",param1,param2);
            }
          } while (iVar6 != 0x66);
LAB_801de858:
          if (*(float *)(puVar8 + 0x30) != 0.0) {
            fVar1 = (*(float *)(puVar8 + 0x2c) - (this->pos).pos.y) / *(float *)(puVar8 + 0x30);
            uStack_2c = (int)*(short *)(puVar8 + 0x48) ^ 0x80000000;
            local_30 = 0x43300000;
            iVar3 = (int)((float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0) *
                         fVar1);
            local_38 = (longlong)iVar3;
            (this->pos).rotation.x = (short)iVar3;
            uStack_3c = (int)*(short *)(puVar8 + 0x4a) ^ 0x80000000;
            local_40 = 0x43300000;
            iVar3 = (int)((float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) *
                         fVar1);
            local_48 = (longlong)iVar3;
            (this->pos).rotation.y = (short)iVar3;
            uStack_4c = (int)*(short *)(puVar8 + 0x4c) ^ 0x80000000;
            local_50 = 0x43300000;
            iVar3 = (int)((float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0) *
                         fVar1);
            local_58 = (longlong)iVar3;
            (this->pos).rotation.z = (short)iVar3;
          }
          piVar5 = (int *)FUN_80094400((int)this,0);
          local_58 = (longlong)(int)(dVar9 * 64.0);
          *piVar5 = (int)(dVar9 * 64.0);
          FUN_801deef8(this);
        }
        else {
          puVar8[0x3a] = 6;
          *(float *)(puVar8 + 8) = timeDelta;
        }
        break;
      case 5:
        if (180.0 < *(float *)(puVar8 + 8)) {
          FUN_801df554(this);
        }
        break;
      case 6:
        if (*(float *)(puVar8 + 8) <= 60.0) {
          iVar3 = (int)((*(float *)(puVar8 + 8) * 255.0) / 60.0);
          local_58 = (longlong)iVar3;
          this->newOpacity = -(char)iVar3 - 1;
          FUN_801deef8(this);
        }
        else {
          FUN_801df554(this);
        }
      }
    }
    else {
      FUN_801df554(this);
    }
  }
switchD_801de564_caseD_7:
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void fruit_hitDetect(ObjInstance *this) { //801DED8C
  return;
}


/* Library Function - Single Match
    fruit_func06
   
   Library: KioskDefault 0 0 */

void fruit_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //801DED90
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((this->state[0x56] & 2) == 0) {
    if (this->shadow != (Shadow *)0x0) {
      if ((shouldRender) || ((*(byte *)&this->def[1].pos.z & 1) != 0)) {
        (this->pos).flags = (this->pos).flags & 0xefff;
      }
      else {
        (this->pos).flags = (this->pos).flags | 0x1000;
      }
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    fruit_func07
   
   Library: KioskDefault 0 0 */

void fruit_free(ObjInstance *this,int param2) { //801DEE3C
  int *piVar1;
  
  piVar1 = (int *)this->state;
  if (*piVar1 != 0) {
    (**(code **)(**(int **)(*piVar1 + 0x68) + 0x20))(*piVar1,this);
  }
                    /* {@symbol 800dc1d4} */
  (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
  return;
}


undefined4 fruit_func08(ObjInstance *this) { //801DEEAC
  return 2;
}


/* @description Get extra size for object (size of State struct) */

int fruit_getExtraSize(void) { //801DEEB4
  return 0x60;
}


void fruit_setScale(ObjInstance *this,float scale) { //801DEEBC
  *(undefined4 *)this->state = 0;
  return;
}


void fruit_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //801DEEDC
  return;
}


/* Library Function - Single Match
    fruit_func0B
   
   Library: KioskDefault 0 0 */

void fruit_func0B(int param1,undefined4 *param2) { //801DF5B8
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  if (((*(char *)(iVar1 + 0x3a) != '\x04') && (*(char *)(iVar1 + 0x3a) != '\x05')) &&
     (*(char *)(iVar1 + 0x3a) != '\x06')) {
    *(undefined4 *)(param1 + 0xc) = *param2;
    *(undefined4 *)(param1 + 0x10) = param2[1];
    *(undefined4 *)(param1 + 0x14) = param2[2];
  }
  return;
}

