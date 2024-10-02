
/* @description Set up object instance */

void SHmushroom_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //8024E94C
  short sVar1;
  ObjInstance *param1;
  uint uVar2;
  undefined *puVar3;
  double dVar4;
  undefined4 local_44;
  float local_40 [2];
  undefined4 local_38;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  puVar3 = this->state;
  local_44 = 0x19;
  param1 = Object_objGetMain();
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  uVar2 = mainGetBit((int)sVar1);
  if (uVar2 != 0) {
    puVar3[0x132] = 8;
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    (this->pos).flags = (this->pos).flags | Invisible;
  }
  this->shadow->flags = this->shadow->flags | 0x810;
  uStack_14 = (uint)objDef[1].mapStates2;
  local_18 = 0x43300000;
  *(float *)(puVar3 + 0x110) =
       (float)((double)CONCAT44(0x43300000,uStack_14) - 4503599627370496.0) / 255.0;
  uStack_1c = (uint)objDef[1].loadFlags;
  local_20 = 0x43300000;
  *(float *)(puVar3 + 0x114) =
       ((float)((double)CONCAT44(0x43300000,uStack_1c) - 4503599627370496.0) / 255.0) * 0.2;
  Object_ObjAnimSetMove(0.0,this,1,0);
  objRunAnimation(1.0,1.0,(int)this,local_40);
  *(float *)(puVar3 + 0x118) = local_40[0];
  if (*(float *)(puVar3 + 0x118) < 0.0) {
    *(float *)(puVar3 + 0x118) = -*(float *)(puVar3 + 0x118);
  }
  *(float *)(puVar3 + 0x118) = *(float *)(puVar3 + 0x118) * *(float *)(puVar3 + 0x110);
  *(float *)(puVar3 + 0x118) = *(float *)(puVar3 + 0x118) + 20.0;
  Object_ObjAnimSetMove(0.0,this,4,0);
  objRunAnimation(1.0,1.0,(int)this,local_40);
  *(undefined4 *)(puVar3 + 0x11c) = local_38;
  if (*(float *)(puVar3 + 0x11c) < 0.0) {
    *(float *)(puVar3 + 0x11c) = -*(float *)(puVar3 + 0x11c);
  }
  dVar4 = (double)*(float *)(puVar3 + 0x11c);
  *(float *)(puVar3 + 0x11c) = (float)(dVar4 + 20.0);
  objAllocMsgQueue(this,1);
  if ((*(byte *)&objDef[1].objType < 6) && (3 < *(byte *)&objDef[1].objType)) {
    puVar3[0x133] = puVar3[0x133] | 2;
                    /* {@symbol 80128bb8} */
    dVar4 = (double)(**(code **)(*(int *)pDll_RomCurve + 0x8c))
                              (0x408f400000000000,puVar3,this,&local_44,0xffffffff);
    (this->pos).pos.x = *(float *)(puVar3 + 0x68);
    (this->pos).pos.z = *(float *)(puVar3 + 0x70);
  }
  *(float *)(puVar3 + 0x120) = 5.0;
  if (param1 == (ObjInstance *)0x0) {
    *(float *)(puVar3 + 0x108) = 200.0;
    *(float *)(puVar3 + 0x10c) = 200.0;
  }
  else {
    objDistObj2Obj(param1,this);
    *(float *)(puVar3 + 0x108) = (float)dVar4;
    *(float *)(puVar3 + 0x10c) = (float)dVar4;
  }
  Object_objAddObjectType(this,0x33);
  if (this->romdefno == BlueMushroo) {
    *(undefined2 *)(puVar3 + 0x130) = 0xc1;
  }
  else {
    *(undefined2 *)(puVar3 + 0x130) = 0x66d;
  }
  return;
}


/* @description Update object instance */

void SHmushroom_update(ObjInstance *this) { //8024EBC4
  ObjInstance *param1;
  ObjInstance *param1_00;
  byte bVar2;
  int iVar1;
  int iVar3;
  ObjDef *pOVar4;
  float *pfVar5;
  double dVar6;
  double __x;
  ObjInstance *apOStack_a4 [20];
  char local_54;
  undefined *local_50;
  int local_4c;
  int local_48 [2];
  undefined4 local_40;
  uint uStack_3c;
  
  _savefpr_30();
  pfVar5 = (float *)this->state;
  pOVar4 = this->def;
  param1 = Object_objGetMain();
  param1_00 = Object_getSidekicksLoaded();
  bVar2 = FUN_80085d5c((int)this);
  if (bVar2 == 0) {
    if (*(char *)((int)pfVar5 + 0x132) == '\b') {
      while (iVar1 = FUN_80091100((int)this,(uint *)&local_50,(uint *)0x0,(uint *)0x0), iVar1 != 0)
      {
        if (local_50 == &DAT_0007000b) {
          mainIncBit((int)*(short *)(pfVar5 + 0x4c));
        }
      }
    }
    else {
      pfVar5[0x43] = pfVar5[0x42];
      dVar6 = (double)objDistSqObj2Obj(param1,this);
      if (param1_00 == (ObjInstance *)0x0) {
        dVar6 = sqrt(dVar6);
        pfVar5[0x42] = (float)dVar6;
      }
      else {
        __x = (double)objDistSqObj2Obj(param1_00,this);
        if (__x <= dVar6) {
          dVar6 = sqrt(__x);
          pfVar5[0x42] = (float)dVar6;
        }
        else {
          dVar6 = sqrt(dVar6);
          pfVar5[0x42] = (float)dVar6;
        }
        uStack_3c = (uint)pOVar4[1].cullDist;
        local_40 = 0x43300000;
        if (pfVar5[0x42] < (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503599627370496.0)) {
          (*param1_00->dll->ptrs2[1].hitDetect)(param1_00);
        }
      }
      iVar1 = FUN_800883e4((int)this,local_48,(int *)0x0,(uint *)0x0);
      if (iVar1 != 0) {
        if (iVar1 == 0x10) {
          FUN_80085c94(this,300);
        }
        else {
          objFreezeFn_80085e2c(this,0xf,200,0,0,1);
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x10c,0x7f,"SHmushroom.c",
                              (int *)0x12c);
          if (*(short *)(local_48[0] + 0x46) == 0x416) {
            *(undefined *)((int)pfVar5 + 0x132) = 8;
            (**(code **)(**(int **)(local_48[0] + 0x68) + 0x54))(local_48[0],1,this);
            (this->pos).flags = (this->pos).flags | Invisible;
            FUN_80088da4((int)this);
          }
          else {
            *(byte *)((int)pfVar5 + 0x133) = *(byte *)((int)pfVar5 + 0x133) | 0x10;
          }
        }
      }
      FUN_8024f2ec(this,pfVar5,(int)pOVar4);
      if ((*(byte *)((int)pfVar5 + 0x133) & 8) != 0) {
        iVar1 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                             (double)(this->pos).pos.z,(int)this,&local_4c,0,0);
        for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
          if (**(float **)(local_4c + iVar3 * 4) < (this->pos).pos.y + 10.0) {
            (this->pos).pos.y = **(float **)(local_4c + iVar3 * 4);
            break;
          }
        }
        iVar1 = FUN_800bb7e0(6.0,&(this->oldPos).x,&(this->pos).pos.x,2,apOStack_a4,this,8,-1,0xff,
                             '\x14');
        if (((*(char *)&pOVar4[1].objType == '\x04') && (iVar1 != 0)) && (local_54 == '\r')) {
          *(byte *)((int)pfVar5 + 0x133) = *(byte *)((int)pfVar5 + 0x133) | 4;
        }
      }
    }
  }
  _restfpr_30();
  return;
}


/* @description Override render */

void SHmushroom_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8024EEEC
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_10A_func07
    dll_10B_func07
    dll_266_func07
    dll_28B_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

void SHmushroom_free(ObjInstance *this,int param2) { //8024EEF0
  Object_removePlayerObj(this,0x33);
  return;
}


/* @description Get extra size for object (size of State struct) */

int SHmushroom_getExtraSize(void) { //8024EF1C
  return 0x140;
}

