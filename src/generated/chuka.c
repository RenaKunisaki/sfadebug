
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void chuka_initialise(undefined4 param) { //801BDA94
  return;
}


/* @description Called when DLL is unloaded */

void chuka_release(void) { //801BDA98
  return;
}


/* Library Function - Single Match
    chuka_func03
   
   Library: KioskDefault 0 0 */

void chuka_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                float y,float z) { //801BDA9C
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  *(ObjDefEnum *)(puVar2 + 0x10) = objDef[1].objType;
  if ((*(short *)(puVar2 + 0x10) == -1) ||
     (uVar1 = mainGetBit((int)*(short *)(puVar2 + 0x10)), uVar1 == 0)) {
    *(ushort *)(puVar2 + 6) = (ushort)*(byte *)((int)&objDef[1].pos.z + 1) << 3;
    *(undefined2 *)(puVar2 + 10) = *(undefined2 *)((int)&objDef[1].pos.x + 2);
    puVar2[0xc] = objDef[2].allocatedSize;
    *(short *)(puVar2 + 8) = *(char *)&objDef[1].pos.z * 0xb6;
    puVar2[0xd] = *(undefined *)((int)&objDef[1].id + 3);
    puVar2[0xe] = *(undefined *)((int)&objDef[1].pos.y + 3);
    (this->pos).rotation.x = (short)((int)*(char *)((int)&objDef[1].pos.z + 2) << 8);
  }
  else {
    FUN_801be3ec((int)this,(int)puVar2);
  }
  return;
}


/* Library Function - Single Match
    chuka_func04
   
   Library: KioskDefault 0 0 */

void chuka_update(ObjInstance *this) { //801BDB5C
  float fVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  ObjInstance *pOVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  double dVar9;
  uint uStack_48;
  int iStack_44;
  undefined4 auStack_40 [2];
  double local_38;
  
  _savefpr_30();
  pfVar8 = (float *)this->state;
  if ((*(byte *)(pfVar8 + 1) & 2) == 0) {
    piVar3 = (int *)FUN_80094400((int)this,0);
    if (16.0 <= *pfVar8) {
      if (255.0 - *pfVar8 < timeDelta) {
        *pfVar8 = 0.0;
      }
      else {
        *pfVar8 = *pfVar8 + timeDelta;
      }
      *piVar3 = 0;
    }
    else {
      if ((int)*pfVar8 == 10) {
        *(byte *)(pfVar8 + 1) = *(byte *)(pfVar8 + 1) | 1;
      }
      local_38 = (double)(longlong)(int)*pfVar8;
      *piVar3 = (uint)*(byte *)((int)&PTR_DAT_80310440 + (int)*pfVar8) << 8;
      fVar1 = *pfVar8;
      *pfVar8 = fVar1 + 1.0;
      if (fVar1 + 1.0 == 16.0) {
        uVar4 = randInt(0x10,0xf5);
        local_38 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
        *pfVar8 = (float)(local_38 - 4503601774854144.0);
      }
    }
    pOVar5 = Object_objGetMain();
    fVar1 = (pOVar5->pos).pos.x - (this->pos).pos.x;
    fVar2 = (pOVar5->pos).pos.z - (this->pos).pos.z;
    dVar9 = sqrt((double)(fVar1 * fVar1 + fVar2 * fVar2));
    uVar4 = (uint)dVar9;
    local_38 = (double)(longlong)(int)uVar4;
    if ((uVar4 & 0xffff) < (uint)*(ushort *)((int)pfVar8 + 6)) {
      if (*(ushort *)((int)pfVar8 + 6) <= *(ushort *)((int)pfVar8 + 0x12)) {
        *(undefined *)(pfVar8 + 1) = 5;
        *pfVar8 = 0.0;
      }
      if ((*(byte *)(pfVar8 + 1) & 5) != 0) {
        uVar6 = getAngle();
        uVar6 = (uVar6 & 0xffff) - (uint)(ushort)(this->pos).rotation.x;
        if (0x8000 < (int)uVar6) {
          uVar6 = uVar6 - 0xffff;
        }
        if ((int)uVar6 < -0x8000) {
          uVar6 = uVar6 + 0xffff;
        }
        if (((uVar6 & 0xffff) < (uint)*(ushort *)(pfVar8 + 2)) ||
           ((0xffff - *(ushort *)(pfVar8 + 2) & 0xffff) < (uVar6 & 0xffff))) {
          iVar7 = randInt(0,99);
          if ((iVar7 < (int)(uint)*(byte *)((int)pfVar8 + 0xd)) ||
             ((*(byte *)(pfVar8 + 1) & 4) != 0)) {
            audioTryStartSfx((int *)this,0x20,0xa5,0x7f,"chuka.c",0xac);
            FUN_801be2e8(this);
          }
          else {
            audioTryStartSfx((int *)this,0x40,0xc9,0x7f,"chuka.c",0xb0);
          }
        }
        else {
          audioTryStartSfx((int *)this,0x40,0xc9,0x7f,"chuka.c",0xb4);
        }
      }
    }
    else if ((*(byte *)(pfVar8 + 1) & 1) != 0) {
      audioTryStartSfx((int *)this,0x40,0xc9,0x7f,"chuka.c",0xbc);
    }
    *(short *)((int)pfVar8 + 0x12) = (short)uVar4;
    iVar7 = FUN_800883e4((int)this,auStack_40,&iStack_44,&uStack_48);
    if ((iVar7 == 0xe) &&
       (*(char *)(pfVar8 + 3) = *(char *)(pfVar8 + 3) + -1, *(char *)(pfVar8 + 3) == '\0')) {
      FUN_801be3ec((int)this,(int)pfVar8);
                    /* {@symbol 80163050} */
      (**(code **)(*(int *)pDll_partfx1F + 0x4c))
                (this,(int)*(short *)((int)pfVar8 + 10),0xffffffff,1);
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0xd4,0x7f,"chuka.c",(int *)0xca);
      mainSetBits((int)*(short *)(pfVar8 + 4),1);
    }
    *(byte *)(pfVar8 + 1) = *(byte *)(pfVar8 + 1) & 0xfa;
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void chuka_hitDetect(ObjInstance *this) { //801BDF2C
  return;
}


/* Library Function - Single Match
    chuka_func06
   
   Library: KioskDefault 0 0 */

void chuka_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                  undefined param5,bool shouldRender) { //801BDF30
  short sVar1;
  int iVar2;
  bool bVar4;
  undefined4 *puVar3;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined4 *param5_00;
  undefined *puVar5;
  double dVar6;
  double dVar7;
  
  param5_00 = (undefined4 *)CONCAT31(in_register_0000001c,param5);
  puVar3 = (undefined4 *)CONCAT31(in_register_00000018,param4);
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  _savefpr_30();
  puVar5 = this->state;
  if (shouldRender != false) {
    objRenderCurrentModel(this,(Gfx **)param2_00,param3_00,puVar3,param5_00);
    iVar2 = FUN_8018d744();
    if (iVar2 == 0) {
      bVar4 = checkSomeDebugFlags_8017c4f8();
      if (!bVar4) goto LAB_801be244;
    }
    puVar3 = (undefined4 *)FUN_80094400((int)this,0);
    *puVar3 = 0x200;
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar5 + 6)) -
                                  4503599627370496.0),32.0,param2_00,param3_00,0xff,0,0);
      iVar2 = (int)(uint)*(ushort *)(puVar5 + 6) >> 1;
      sVar1 = *(short *)(puVar5 + 8);
      dVar6 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)(this->pos).
                                                                                  rotation.x +
                                                                             (uint)*(ushort *)
                                                                                    (puVar5 + 8) ^
                                                                             0x80000000) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      dVar7 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,iVar2) -
                                             4503599627370496.0) * dVar6 + (double)(this->pos).pos.x
                             );
      dVar6 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(this->pos).rotation.x
                                                                         + (uint)*(ushort *)
                                                                                  (puVar5 + 8) ^
                                                                         0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
      FUN_800964d4(dVar7,(double)(this->pos).pos.y,
                   (double)(float)((double)(float)((double)CONCAT44(0x43300000,iVar2) -
                                                  4503599627370496.0) * dVar6 +
                                  (double)(this->pos).pos.z),
                   (double)(float)((double)CONCAT44(0x43300000,iVar2) - 4503599627370496.0),
                   param2_00,param3_00,0,0,(this->pos).rotation.x + sVar1 + 0x3ffc,0xff,0xff,0);
      dVar6 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                             (int)(this->pos).
                                                                                  rotation.x -
                                                                             (uint)*(ushort *)
                                                                                    (puVar5 + 8) ^
                                                                             0x80000000) -
                                                           4503601774854144.0) * 3.141593) / 32767.0
                                                  ));
      dVar7 = (double)(float)((double)(float)((double)CONCAT44(0x43300000,iVar2) -
                                             4503599627370496.0) * dVar6 + (double)(this->pos).pos.x
                             );
      dVar6 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                         (int)(this->pos).rotation.x
                                                                         - (uint)*(ushort *)
                                                                                  (puVar5 + 8) ^
                                                                         0x80000000) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
      FUN_800964d4(dVar7,(double)(this->pos).pos.y,
                   (double)(float)((double)(float)((double)CONCAT44(0x43300000,iVar2) -
                                                  4503599627370496.0) * dVar6 +
                                  (double)(this->pos).pos.z),
                   (double)(float)((double)CONCAT44(0x43300000,iVar2) - 4503599627370496.0),
                   param2_00,param3_00,0,0,(this->pos).rotation.x - (sVar1 + 0x3ffc),0xff,0xff,0);
    }
  }
LAB_801be244:
  _restfpr_30();
  return;
}


/* @description Free object instance */

void chuka_free(ObjInstance *this,int param2) { //801BE260
  return;
}


undefined4 chuka_func08(ObjInstance *this) { //801BE264
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int chuka_getExtraSize(void) { //801BE26C
  return 0x14;
}


/* Library Function - Single Match
    chuka_handleMsg
   
   Library: KioskDefault 0 0 */

void chuka_handleMsg(ObjInstance *this,float scale) { //801BE274
  byte in_r4;
  
  if (in_r4 == 0x80) {
    audioTryStartSfx((int *)this,0x10,0xcc,0x7f,"chuka.c",0x126);
  }
  else {
    printf("BADDIE:Chuka Unknown message [%d]",(uint)in_r4);
  }
  return;
}

