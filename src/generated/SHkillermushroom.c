
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SHkillermushroom_initialise(undefined4 param) { //8024FBD0
  return;
}


/* @description Called when DLL is unloaded */

void SHkillermushroom_release(void) { //8024FBD4
  return;
}


/* Library Function - Single Match
    dll_1E4_func03
   
   Library: KioskDefault 0 0 */

void SHkillermushroom_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8024FBD8
  float *pfVar1;
  
  pfVar1 = (float *)this->state;
  *pfVar1 = 0.0;
  pfVar1[0xb] = 0.0;
  pfVar1[3] = (this->pos).scale;
  *(undefined2 *)(pfVar1 + 0xd) = *(undefined2 *)&objDef[1].allocatedSize;
  if (*(short *)(pfVar1 + 0xd) < 0x708) {
    *(undefined2 *)(pfVar1 + 0xd) = 0x708;
  }
  (this->pos).pos.y = (objDef->pos).y - 2.0;
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
  }
  if (obj2 == (ObjInstance *)0x0) {
    objDoSpawnAnim(this,pfVar1,0);
  }
  return;
}


/* Library Function - Single Match
    dll_1E4_func04
   
   Library: KioskDefault 0 0 */

void SHkillermushroom_update(ObjInstance *this) { //8024FC88
  short sVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ObjInstance *param2;
  uint uVar6;
  int iVar7;
  ObjDef *pOVar8;
  char cVar9;
  float *pfVar10;
  double dVar11;
  undefined auStack_6c [12];
  float local_60;
  float local_5c;
  float local_58;
  uint uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  double local_48;
  
  _savefpr_28();
  pfVar10 = (float *)this->state;
  param2 = Object_objGetMain();
  pOVar8 = this->def;
  objHitFn_80089114(this);
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) | 4;
  if (false) {
switchD_8024fcfc_caseD_0:
    this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
    fVar3 = (param2->pos).pos.x - (this->pos).pos.x;
    fVar4 = (param2->pos).pos.y - (this->pos).pos.y;
    fVar5 = (param2->pos).pos.z - (this->pos).pos.z;
    dVar11 = sqrt((double)(fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4));
    local_48 = (double)(longlong)(int)dVar11;
    if ((((int)dVar11 & 0xffffU) < (uint)pOVar8[1].bound) &&
       (dVar11 = FUN_801a84a8((int)param2), 0.5400000214576721 <= dVar11)) {
      *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) & 0xfe;
      *(undefined *)((int)pfVar10 + 0x36) = 3;
      *pfVar10 = 0.0;
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x207,0x7f,"SHkillermushroom.c",
                          (int *)0x194);
    }
  }
  else {
                    /* {@symbol 8025031c} */
    switch(*(undefined *)((int)pfVar10 + 0x36)) {
    default:
      goto switchD_8024fcfc_caseD_0;
    case 1:
      *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) & 0xfb;
      if (pfVar10[1] < (this->pos).scale) {
        pfVar10[4] = pfVar10[4] / 1.1;
      }
      if (pfVar10[4] < 1e-05) {
        pfVar10[4] = 0.0;
      }
      *pfVar10 = *pfVar10 + timeDelta;
      (this->pos).scale = pfVar10[4] * timeDelta + (this->pos).scale;
      if (pfVar10[2] < *pfVar10) {
        *(undefined *)((int)pfVar10 + 0x36) = 0;
      }
      break;
    case 2:
      *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) & 0xfb;
      if ((*(byte *)((int)pfVar10 + 0x37) & 2) != 0) {
        iVar7 = (uint)this->newOpacity + (uint)framesThisStep * -4;
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        this->newOpacity = (u8)iVar7;
        *pfVar10 = *pfVar10 + timeDelta;
        local_48 = (double)CONCAT44(0x43300000,(int)*(short *)(pfVar10 + 0xd) ^ 0x80000000);
        if ((float)(local_48 - 4503601774854144.0) < *pfVar10) {
          objDoSpawnAnim(this,pfVar10,1);
          *(undefined *)((int)pfVar10 + 0x36) = 1;
        }
      }
      break;
    case 3:
      this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      if ((*(byte *)((int)pfVar10 + 0x37) & 2) != 0) {
        audioTryStartSfx((int *)this,0xa0,0x71,0x7f,"SHkillermushroom.c",0x115);
        *(undefined *)((int)pfVar10 + 0x36) = 4;
      }
      break;
    case 4:
      this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      dVar11 = (double)timeDelta;
      pfVar10[0xb] = (float)(dVar11 * 2.5 + (double)pfVar10[0xb]);
      if ((((*(byte *)((int)pfVar10 + 0x37) & 1) == 0) &&
          (objDistObj2Obj(this,param2), dVar11 <= (double)pfVar10[0xb])) &&
         ((iVar7 = FUN_801a82bc((int)param2), iVar7 == 0 &&
          (iVar7 = FUN_801a82d8((int)param2), iVar7 == 0)))) {
        FUN_80088818((int)param2,(int)this,'\x16',1,0);
        *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) | 1;
      }
      if (40.0 < pfVar10[0xb]) {
        pfVar10[0xb] = 40.0;
      }
      *pfVar10 = *pfVar10 + timeDelta;
      if (120.0 < *pfVar10) {
        *pfVar10 = 0.0;
        *(undefined *)((int)pfVar10 + 0x36) = 5;
        FUN_80068a9c((uint)this,0x7f);
      }
      local_60 = pfVar10[8];
      local_5c = pfVar10[9];
      local_58 = pfVar10[10];
      for (cVar9 = '\x05'; cVar9 != '\0'; cVar9 = cVar9 + -1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3eb,auStack_6c,&DAT_00200001,0xffffffff,0);
      }
      break;
    case 5:
      this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      *pfVar10 = *pfVar10 + timeDelta;
      local_48 = (double)CONCAT44(0x43300000,(uint)pOVar8[1].objType);
      if (((float)(local_48 - 4503599627370496.0) < *pfVar10) &&
         ((*(byte *)((int)pfVar10 + 0x37) & 2) != 0)) {
        *(undefined *)((int)pfVar10 + 0x36) = 0;
        pfVar10[0xb] = 0.0;
        *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) & 0xfe;
      }
      break;
    case 6:
      audioTryStartSfx((int *)this,0xa0,0x71,0x7f,"SHkillermushroom.c",0xe1);
      *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) & 0xfb;
      pfVar10[0xb] = timeDelta * 2.5 + pfVar10[0xb];
      dVar11 = (double)pfVar10[0xb];
      if (40.0 < dVar11) {
        pfVar10[0xb] = 40.0;
      }
      if (((((*(byte *)((int)pfVar10 + 0x37) & 1) == 0) &&
           (objDistObj2Obj(this,param2), dVar11 <= (double)pfVar10[0xb])) &&
          (iVar7 = FUN_801a82bc((int)param2), iVar7 == 0)) &&
         (iVar7 = FUN_801a82d8((int)param2), iVar7 == 0)) {
        FUN_80088818((int)param2,(int)this,'\x16',1,0);
        *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) | 1;
      }
      if ((*(byte *)((int)pfVar10 + 0x37) & 2) != 0) {
        *pfVar10 = 0.0;
        *(undefined *)((int)pfVar10 + 0x36) = 2;
        FUN_80068a9c((uint)this,0x7f);
      }
      local_60 = pfVar10[8];
      local_5c = pfVar10[9];
      local_58 = pfVar10[10];
      for (cVar9 = '\x05'; cVar9 != '\0'; cVar9 = cVar9 + -1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x3eb,auStack_6c,&DAT_00200001,0xffffffff,0);
      }
      break;
    case 9:
      if (*pfVar10 <= 0.0) {
        objTargetFn_8002b6d8((int)this,0x19,0,0,'\0','\x06');
        audioTryStartSfx((int *)this,1,0x128,0x7f,"SHkillermushroom.c",0x156);
        uVar6 = randInt(0xf0,300);
        local_48 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
        *pfVar10 = (float)(local_48 - 4503601774854144.0);
      }
      fVar3 = *pfVar10 - timeDelta;
      *pfVar10 = fVar3;
      if (0.0 < fVar3) {
        fVar3 = pfVar10[0xc] - timeDelta;
        pfVar10[0xc] = fVar3;
        if (fVar3 <= 0.0) {
          local_60 = 14.0;
          local_5c = 25.0;
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x51d,auStack_6c,2,0xffffffff,0);
          pfVar10[0xc] = 20.0;
        }
        this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      }
      else {
                    /* {@symbol 800dc1d4} */
        (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
        *(undefined *)((int)pfVar10 + 0x36) = 0;
        objFn_8002b67c((int)this);
        FUN_80068a9c((uint)this,0x7f);
      }
      break;
    case 10:
      FUN_80088da4((int)this);
      *pfVar10 = *pfVar10 + timeDelta;
      local_48 = (double)CONCAT44(0x43300000,(int)*(short *)(pfVar10 + 0xd) ^ 0x80000000);
      if ((float)(local_48 - 4503601774854144.0) < *pfVar10) {
        objDoSpawnAnim(this,pfVar10,1);
        *(undefined *)((int)pfVar10 + 0x36) = 1;
        objFn_8002b67c((int)this);
      }
    }
  }
  iVar7 = FUN_800883e4((int)this,&uStack_4c,&iStack_50,&uStack_54);
  if ((iVar7 != 0) && ((*(byte *)((int)pfVar10 + 0x37) & 4) != 0)) {
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,0x10c,0x7f,"SHkillermushroom.c",
                        (int *)0x19e);
    *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) & 0xfe;
    sVar1._0_1_ = pOVar8[1].loadFlags;
    sVar1._1_1_ = pOVar8[1].mapStates2;
    if (sVar1 != -1) {
      sVar2._0_1_ = pOVar8[1].loadFlags;
      sVar2._1_1_ = pOVar8[1].mapStates2;
      mainSetBits((int)sVar2,1);
    }
    *(undefined *)((int)pfVar10 + 0x36) = 9;
    *pfVar10 = 0.0;
    FUN_80068a9c((uint)this,0x7f);
  }
  if (this->animId != *(word *)((int)&PTR_8031a800 + (uint)*(byte *)((int)pfVar10 + 0x36) * 2)) {
    Object_ObjAnimSetMove
              (0.0,this,(int)*(short *)((int)&PTR_8031a800 +
                                       (uint)*(byte *)((int)pfVar10 + 0x36) * 2),0);
  }
  iVar7 = objRunAnimation((double)*(float *)(&DAT_8031a818 +
                                            (uint)*(byte *)((int)pfVar10 + 0x36) * 4),
                          (double)timeDelta,(int)this,(float *)0x0);
  if (iVar7 == 0) {
    *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) & 0xfd;
  }
  else {
    *(byte *)((int)pfVar10 + 0x37) = *(byte *)((int)pfVar10 + 0x37) | 2;
  }
  _restfpr_28();
  return;
}


/* @description Override hit detection */

void SHkillermushroom_hitDetect(ObjInstance *this) { //802504FC
  return;
}


/* Library Function - Single Match
    dll_1E4_func06
   
   Library: KioskDefault 0 0 */

void SHkillermushroom_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //80250500
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  pOVar3 = this->def;
  if (shouldRender) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)pOVar3[1].bound) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    objGetAttachPointWorldPos
              (this,0,(float *)(puVar4 + 0x20),(float *)(puVar4 + 0x24),(float *)(puVar4 + 0x28),
               FALSE);
    return;
  }
  return;
}


/* @description Free object instance */

void SHkillermushroom_free(ObjInstance *this,int param2) { //802505F0
                    /* {@symbol 800dc1d4} */
  (**(code **)(*(int *)pDll_modgfx + 0x14))(this);
  return;
}


/* Library Function - Single Match
    dll_1E4_func08
   
   Library: KioskDefault 0 0 */

uint SHkillermushroom_func08(ObjInstance *this) { //80250628
  return (uint)this->def[1].cullDist << 0xb | 0x400;
}


/* @description Get extra size for object (size of State struct) */

int SHkillermushroom_getExtraSize(void) { //8025064C
  return 0x3c;
}

