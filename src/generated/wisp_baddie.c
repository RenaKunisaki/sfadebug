
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void wispBaddie_initialise(undefined4 param) { //801B5720
  return;
}


/* @description Called when DLL is unloaded */

void wispBaddie_release(void) { //801B5724
  return;
}


/* Library Function - Single Match
    wispBaddie_func03
   
   Library: KioskDefault 0 0 */

void wispBaddie_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //801B5728
  short sVar1;
  void *pvVar2;
  char cVar3;
  void **ppvVar4;
  
  ppvVar4 = (void **)this->state;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  pvVar2 = (void *)((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                           4503601774854144.0) / 25.0);
  ppvVar4[3] = pvVar2;
  ppvVar4[2] = pvVar2;
  ppvVar4[6] = (void *)((float)((double)CONCAT44(0x43300000,
                                                 (int)*(char *)((int)&objDef[1].objType + 1) ^
                                                 0x80000000) - 4503601774854144.0) * 4.0);
  ppvVar4[8] = (void *)0x337;
  if (obj2 == (ObjInstance *)0x0) {
    pvVar2 = mmAlloc(0x108,TEST_COL,(char *)&PTR_DAT_8030fcb0);
    *ppvVar4 = pvVar2;
    if (*ppvVar4 != (void *)0x0) {
      memclr(*ppvVar4,0x108);
    }
                    /* {@symbol 80128bb8} */
    cVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x8c))
                      ((double)(float)ppvVar4[6],*ppvVar4,this,&DAT_80397b48,0xffffffff);
    if (cVar3 == '\0') {
      *(byte *)(ppvVar4 + 9) = *(byte *)(ppvVar4 + 9) | 1;
    }
    else {
      printf("Error wisp Baddie MUST have a baddie curve network!");
    }
    audioTryStartSfx((int *)this,1,0xe1,0x7f,"wisp_baddie.c",0x8a);
    audioTryStartSfx((int *)this,2,0xe1,100,"wisp_baddie.c",0x8b);
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    wispBaddie_func04
   
   Library: KioskDefault 0 0 */

void wispBaddie_update(ObjInstance *this) { //801B589C
  ushort param3;
  int iVar1;
  ObjInstance *pOVar2;
  float *pfVar3;
  float **ppfVar4;
  double dVar5;
  undefined4 local_54;
  uint uStack_50;
  int iStack_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 auStack_30 [2];
  undefined4 local_28;
  uint uStack_24;
  undefined4 local_20;
  uint uStack_1c;
  
  ppfVar4 = (float **)this->state;
  pfVar3 = *ppfVar4;
  iVar1 = FUN_800884c8((int)this,auStack_30,&iStack_4c,&uStack_50,&local_40,&local_44,&local_48);
  if (iVar1 != 0) {
    ppfVar4[2] = (float *)0.01;
    if ((*(byte *)(ppfVar4 + 9) & 2) != 0) {
      *(byte *)(ppfVar4 + 9) = *(byte *)(ppfVar4 + 9) & 0xfd;
      *(byte *)(ppfVar4 + 9) = *(byte *)(ppfVar4 + 9) | 4;
    }
    audioSfxFn_800688bc((double)local_40,(double)local_44,(double)local_48,0x20c,0x7f,
                        "wisp_baddie.c",(int *)0xac);
  }
  local_54 = 4;
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,ppfVar4[8],0,1,0xffffffff,&local_54);
  local_54 = 3;
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,ppfVar4[8],0,2,0xffffffff,&local_54);
  if ((float)ppfVar4[3] <= (float)ppfVar4[2]) {
    ppfVar4[2] = ppfVar4[3];
    local_54 = 2;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,ppfVar4[8],0,2,0xffffffff,&local_54);
    local_54 = 0;
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,ppfVar4[8],0,2,0xffffffff,&local_54);
    objHitFn_80089074(this,10,1,0);
    FUN_80088d3c((int)this);
  }
  else {
    ppfVar4[2] = (float *)((float)ppfVar4[2] + 0.005);
    FUN_80088da4((int)this);
  }
  local_54 = 1;
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,ppfVar4[8],0,2,0xffffffff,&local_54);
  pOVar2 = Object_objGetMain();
  ppfVar4[1] = (float *)pOVar2;
  if (ppfVar4[1] != (float *)0x0) {
    local_3c = ppfVar4[1][6] - (this->prevPos).x;
    local_38 = ppfVar4[1][7] - (this->prevPos).y;
    local_34 = ppfVar4[1][8] - (this->prevPos).z;
    dVar5 = sqrt((double)(local_34 * local_34 + local_3c * local_3c + local_38 * local_38));
    ppfVar4[4] = (float *)(float)dVar5;
  }
  if (pfVar3 != (float *)0x0) {
    local_3c = pfVar3[0x1a] - (this->prevPos).x;
    local_38 = pfVar3[0x1b] - (this->prevPos).y;
    local_34 = pfVar3[0x1c] - (this->prevPos).z;
    dVar5 = sqrt((double)(local_34 * local_34 + local_3c * local_3c + local_38 * local_38));
    ppfVar4[5] = (float *)(float)dVar5;
  }
  if ((*(byte *)(ppfVar4 + 9) & 2) != 0) {
    if (250.0 < (float)ppfVar4[5]) {
      *(byte *)(ppfVar4 + 9) = *(byte *)(ppfVar4 + 9) & 0xfd;
      *(byte *)(ppfVar4 + 9) = *(byte *)(ppfVar4 + 9) | 4;
    }
    ppfVar4[7] = (float *)((float)ppfVar4[7] - timeDelta);
    if ((float)ppfVar4[7] < 0.0) {
      uStack_1c = randInt(0x50,0x78);
      uStack_1c = uStack_1c ^ 0x80000000;
      local_20 = 0x43300000;
      iVar1 = randInt(0,1);
      if (iVar1 == 0) {
        param3 = 0x1fa;
      }
      else {
        param3 = 0x1f9;
      }
      audioTryStartSfx((int *)this,4,param3,0x7f,"wisp_baddie.c",0xe6);
      uStack_24 = randInt(0x3c,0x78);
      uStack_24 = uStack_24 ^ 0x80000000;
      local_28 = 0x43300000;
      ppfVar4[7] = (float *)(float)((double)CONCAT44(0x43300000,uStack_24) - 4503601774854144.0);
    }
    ppfVar4[8] = (float *)0x338;
  }
  if ((*(byte *)(ppfVar4 + 9) & 4) != 0) {
    if ((float)ppfVar4[5] < 60.0) {
      *(byte *)(ppfVar4 + 9) = *(byte *)(ppfVar4 + 9) & 0xfb;
    }
    ppfVar4[8] = (float *)0x337;
  }
  if ((*(byte *)(ppfVar4 + 9) & 6) == 0) {
    if ((((float)ppfVar4[3] <= (float)ppfVar4[2]) && (ppfVar4[1] != (float *)0x0)) &&
       ((float)ppfVar4[4] < (float)ppfVar4[6])) {
      *(byte *)(ppfVar4 + 9) = *(byte *)(ppfVar4 + 9) | 2;
    }
    ppfVar4[8] = (float *)0x337;
  }
  FUN_801b5e2c(this,ppfVar4);
  return;
}


/* @description Override hit detection */

void wispBaddie_hitDetect(ObjInstance *this) { //801B5D10
  return;
}


/* Library Function - Single Match
    wispBaddie_func06
   
   Library: KioskDefault 0 0 */

void wispBaddie_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //801B5D14
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    iVar1 = FUN_8018d744();
    if ((iVar1 == 0) && (bVar2 = checkSomeDebugFlags_8017c4f8(), !bVar2)) {
      return;
    }
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80095aec((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(*(float *)(this->state + 0x18) / 79.0),
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),1);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    balloonBaddie_func07
    swarmBaddie_func07
    wispBaddie_func07
   
   Library: KioskDefault 0 0 */

void wispBaddie_free(ObjInstance *this,int param2) { //801B5DC8
  void **ppvVar1;
  
  ppvVar1 = (void **)this->state;
  Object_removePlayerObj(this,4);
  if (*ppvVar1 != (void *)0x0) {
    mm_free(*ppvVar1);
    *ppvVar1 = (void *)0x0;
  }
  return;
}


undefined4 wispBaddie_func08(ObjInstance *this) { //801B5E1C
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int wispBaddie_getExtraSize(void) { //801B5E24
  return 0x2c;
}

