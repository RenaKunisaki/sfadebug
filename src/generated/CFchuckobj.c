
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void CFchuckobj_initialise(undefined4 param) { //80214060
  return;
}


/* @description Called when DLL is unloaded */

void CFchuckobj_release(void) { //80214064
  return;
}


/* Library Function - Single Match
    dll_17D_func03
   
   Library: KioskDefault 0 0 */

void CFchuckobj_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80214068
  short sVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  Object_objAddObjectType(this,0x24);
  objAllocMsgQueue(this,5);
  puVar2[0x16] = 0;
  sVar1._0_1_ = objDef[1].loadFlags;
  sVar1._1_1_ = objDef[1].mapStates2;
  *(float *)(puVar2 + 0xc) =
       (this->pos).pos.y -
       (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  DAT_80399e38 = runlinkDownloadCode(0x1003,1);
  if (*(char *)((int)&objDef[1].objType + 1) < '\x02') {
    puVar2[0x17] = *(undefined *)
                    ((int)&PTR_DAT_80397d08 + (int)*(char *)((int)&objDef[1].objType + 1));
  }
  DLL_createTempDll(0x35);
  return;
}


/* Library Function - Single Match
    dll_17D_func04
   
   Library: KioskDefault 0 0 */

void CFchuckobj_update(ObjInstance *this) { //8021413C
  byte bVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  ObjDef *pOVar5;
  float *pfVar6;
  double dVar7;
  uint local_58;
  uint local_54;
  uint local_50 [2];
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  uint uStack_2c;
  
  _savefpr_30();
  pfVar6 = (float *)this->state;
  pOVar5 = this->def;
  local_54 = 0;
  bVar1 = *(byte *)((int)pfVar6 + 0x16);
  if (bVar1 == 2) {
    objHitFn_80089074(this,0x13,1,0);
    uStack_2c = (uint)framesThisStep;
    local_30 = 0x43300000;
    pfVar6[1] = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503599627370496.0) * -0.3 +
                pfVar6[1];
    uStack_34 = (uint)framesThisStep;
    local_38 = 0x43300000;
    (this->pos).pos.x =
         *pfVar6 * (float)((double)CONCAT44(0x43300000,uStack_34) - 4503599627370496.0) +
         (this->pos).pos.x;
    uStack_3c = (uint)framesThisStep;
    local_40 = 0x43300000;
    (this->pos).pos.y =
         pfVar6[1] * (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503599627370496.0) +
         (this->pos).pos.y;
    uStack_44 = (uint)framesThisStep;
    local_48 = 0x43300000;
    (this->pos).pos.z =
         pfVar6[2] * (float)((double)CONCAT44(0x43300000,uStack_44) - 4503599627370496.0) +
         (this->pos).pos.z;
    if (this->newOpacity < 0x14) {
      this->newOpacity = 0;
      *(undefined *)((int)pfVar6 + 0x16) = 3;
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
    }
    else {
      this->newOpacity = this->newOpacity + framesThisStep * -8;
    }
    dVar7 = FUN_80214840(-10.0,10.0,0.0,20.0,-10.0,10.0,&this->pos);
    if (dVar7 <= (double)pfVar6[3]) {
      (this->pos).pos.y = (this->pos).pos.y + (float)((double)pfVar6[3] - dVar7);
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      while (iVar4 = FUN_80091100((int)this,&local_58,local_50,&local_54), iVar4 != 0) {
        if (local_58 == 0x11) {
          uStack_2c = local_54;
          local_30 = 0x43300000;
          dVar7 = (double)((float)((double)CONCAT44(0x43300000,local_54) - 4503599627370496.0) /
                          15.0);
          if (0.5 <= dVar7) {
            if (4.0 < dVar7) {
              dVar7 = 4.0;
            }
          }
          else {
            dVar7 = 0.5;
          }
          iVar4 = (**(code **)(UnkStructVersionStuff_802eadc8.tempDlls[2]->headerSize + 4))
                            (dVar7,0x3fd3333340000000,this,local_50[0] + 0xc,0x32,pfVar6);
          if (iVar4 != 0) {
            audioTryStartSfx((int *)this,1,0x1cc,0x7f,"CFchuckobj.c",0xb9);
            Object_removePlayerObj(this,0x24);
            *(undefined *)((int)pfVar6 + 0x16) = 1;
            this->hitstate->flags = this->hitstate->flags | 0x40;
            objHitFn_80089074(this,0x13,1,0);
            *(short *)(pfVar6 + 5) = (this->pos).rotation.y;
            printf(" Pitch inc %i ",(int)(this->pos).rotation.y);
            (this->pos).rotation.y = 0;
          }
        }
      }
    }
    else if (true) {
      (this->oldPos).x = (this->pos).pos.x;
      (this->oldPos).y = (this->pos).pos.y;
      (this->oldPos).z = (this->pos).pos.z;
      objHitFn_80089074(this,0x13,1,0);
      (this->pos).pos.x = *pfVar6 * timeDelta + (this->pos).pos.x;
      (this->pos).pos.y = pfVar6[1] * timeDelta + (this->pos).pos.y;
      (this->pos).pos.z = pfVar6[2] * timeDelta + (this->pos).pos.z;
      (this->pos).rotation.y =
           (this->pos).rotation.y + (ushort)framesThisStep * *(short *)(pfVar6 + 5);
      dVar7 = FUN_80214840(-10.0,10.0,0.0,20.0,-10.0,10.0,&this->pos);
      if ((double)pfVar6[3] < dVar7) {
        pfVar6[1] = pfVar6[1] + -0.3;
      }
      else {
        (this->pos).pos.y = (this->pos).pos.y + (float)((double)pfVar6[3] - dVar7);
        pfVar6[1] = -pfVar6[1] * 0.5;
        if (pfVar6[1] < 0.0) {
          fVar2 = -pfVar6[1];
        }
        else {
          fVar2 = pfVar6[1];
        }
        if (0.1 < fVar2) {
          audioTryStartSfx((int *)this,1,0x5c,0x7f,"CFchuckobj.c",0xd9);
        }
        if (pfVar6[1] < 0.0) {
          fVar2 = -pfVar6[1];
        }
        else {
          fVar2 = pfVar6[1];
        }
        if (fVar2 < 0.002) {
          this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
          pfVar6[1] = 0.0;
        }
      }
      iVar4 = FUN_800bb7e0(6.0,&(this->oldPos).x,&(this->pos).pos.x,1,(ObjInstance **)0x0,this,4,-1,
                           0xff,'\0');
      if (iVar4 != 0) {
        sVar3._0_1_ = pOVar5[1].allocatedSize;
        sVar3._1_1_ = pOVar5[1].mapStates1;
        FUN_80214770(this,(int)pfVar6,(int)sVar3);
      }
    }
  }
  else if (bVar1 < 4) {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    dll_17D_func05
   
   Library: KioskDefault 0 0 */

void CFchuckobj_hitDetect(ObjInstance *this) { //80214620
  int iVar1;
  undefined *puVar2;
  uint local_1c;
  undefined4 auStack_18 [3];
  
  puVar2 = this->state;
  iVar1 = FUN_800883e4((int)this,auStack_18,(int *)0x0,&local_1c);
  if (((iVar1 != 0) && (local_1c != 0)) || (this->hitstate->field13_0x48 != 0)) {
    FUN_80214770(this,(int)puVar2,0);
  }
  return;
}


/* Library Function - Single Match
    dll_17D_func06
   
   Library: KioskDefault 0 0 */

void CFchuckobj_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //80214698
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if ((shouldRender) && (this->state[0x16] != '\x03')) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_17D_func07
   
   Library: KioskDefault 0 0 */

void CFchuckobj_free(ObjInstance *this,int param2) { //8021470C
  DLL_removeTempDll(0x35);
  Object_removePlayerObj(this,0x24);
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 CFchuckobj_func08(ObjInstance *this) { //80214760
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int CFchuckobj_getExtraSize(void) { //80214768
  return 0x18;
}

