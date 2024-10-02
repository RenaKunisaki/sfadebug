
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void swarmBaddie_initialise(undefined4 param) { //801B4E5C
  return;
}


/* @description Called when DLL is unloaded */

void swarmBaddie_release(void) { //801B4E60
  return;
}


/* Library Function - Single Match
    swarmBaddie_func03
   
   Library: KioskDefault 0 0 */

void swarmBaddie_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //801B4E64
  short sVar1;
  void *pvVar2;
  char cVar3;
  void **ppvVar4;
  
  ppvVar4 = (void **)this->state;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  ppvVar4[2] = (void *)((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                               4503601774854144.0) / 50.0);
  ppvVar4[5] = (void *)((float)((double)CONCAT44(0x43300000,
                                                 (int)*(char *)((int)&objDef[1].objType + 1) ^
                                                 0x80000000) - 4503601774854144.0) * 4.0);
  ppvVar4[6] = (void *)1.0;
  if (obj2 == (ObjInstance *)0x0) {
    pvVar2 = mmAlloc(0x108,TEST_COL,(char *)&PTR_DAT_8030fc20);
    *ppvVar4 = pvVar2;
    if (*ppvVar4 != (void *)0x0) {
      memclr(*ppvVar4,0x108);
    }
                    /* {@symbol 80128bb8} */
    cVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x8c))
                      ((double)(float)ppvVar4[5],*ppvVar4,this,&DAT_80397b40,0xffffffff);
    if (cVar3 == '\0') {
      *(byte *)(ppvVar4 + 7) = *(byte *)(ppvVar4 + 7) | 1;
    }
    else {
      printf("Error swarm Baddie MUST have a baddie curve network!");
    }
    audioTryStartSfx((int *)this,1,0x7c,0x7f,"swarm_baddie.c",0x87);
    audioTryStartSfx((int *)this,2,0x7c,0x40,"swarm_baddie.c",0x88);
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    swarmBaddie_func04
   
   Library: KioskDefault 0 0 */

void swarmBaddie_update(ObjInstance *this) { //801B4FD4
  int iVar1;
  ObjInstance *pOVar2;
  float *pfVar3;
  float **ppfVar4;
  double dVar5;
  uint uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 uStack_24;
  longlong local_20;
  undefined4 local_18;
  uint uStack_14;
  
  ppfVar4 = (float **)this->state;
  pfVar3 = *ppfVar4;
  iVar1 = FUN_800884c8((int)this,&uStack_24,&iStack_40,&uStack_44,&uStack_34,&uStack_38,&uStack_3c);
  if (iVar1 != 0) {
    ppfVar4[6] = (float *)2.0;
  }
  objHitFn_80089074(this,10,1,0);
  FUN_80088d3c((int)this);
  if (1.0 < (float)ppfVar4[6]) {
    ppfVar4[6] = (float *)((float)ppfVar4[6] - 0.005);
  }
  uStack_14 = (int)*(short *)((int)ppfVar4 + 0x1e) + (int)*(short *)(ppfVar4 + 8) ^ 0x80000000;
  local_18 = 0x43300000;
  dVar5 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_14) -
                                                       4503601774854144.0) * 3.141593) / 32767.0));
  local_20 = (longlong)(int)((float)ppfVar4[6] * 63.0);
  FUN_800689dc((double)(float)(dVar5 * 0.05000000074505806 + (double)(float)ppfVar4[6]),(int)this,1,
               (byte)(int)((float)ppfVar4[6] * 63.0));
                    /* {@symbol 800ed30c} */
  (**(code **)(*(int *)pDll_objfsa + 8))(this,0x336,0,2,0xffffffff,ppfVar4 + 6);
  pOVar2 = Object_objGetMain();
  ppfVar4[1] = (float *)pOVar2;
  if (ppfVar4[1] != (float *)0x0) {
    local_30 = ppfVar4[1][6] - (this->prevPos).x;
    local_2c = ppfVar4[1][7] - (this->prevPos).y;
    local_28 = ppfVar4[1][8] - (this->prevPos).z;
    dVar5 = sqrt((double)(local_28 * local_28 + local_30 * local_30 + local_2c * local_2c));
    ppfVar4[3] = (float *)(float)dVar5;
  }
  if (pfVar3 != (float *)0x0) {
    local_30 = pfVar3[0x1a] - (this->prevPos).x;
    local_2c = pfVar3[0x1b] - (this->prevPos).y;
    local_28 = pfVar3[0x1c] - (this->prevPos).z;
    dVar5 = sqrt((double)(local_28 * local_28 + local_30 * local_30 + local_2c * local_2c));
    ppfVar4[4] = (float *)(float)dVar5;
  }
  if ((*(byte *)(ppfVar4 + 7) & 2) != 0) {
    if (250.0 < (float)ppfVar4[4]) {
      *(byte *)(ppfVar4 + 7) = *(byte *)(ppfVar4 + 7) & 0xfd;
      *(byte *)(ppfVar4 + 7) = *(byte *)(ppfVar4 + 7) | 4;
    }
  }
  if ((*(byte *)(ppfVar4 + 7) & 4) != 0) {
    if ((float)ppfVar4[4] < 60.0) {
      *(byte *)(ppfVar4 + 7) = *(byte *)(ppfVar4 + 7) & 0xfb;
    }
  }
  if ((((*(byte *)(ppfVar4 + 7) & 6) == 0) && (ppfVar4[1] != (float *)0x0)) &&
     ((float)ppfVar4[3] < (float)ppfVar4[5])) {
    *(byte *)(ppfVar4 + 7) = *(byte *)(ppfVar4 + 7) | 2;
  }
  FUN_801b53b0(this,ppfVar4);
  return;
}


/* @description Override hit detection */

void swarmBaddie_hitDetect(ObjInstance *this) { //801B5294
  return;
}


/* Library Function - Single Match
    swarmBaddie_func06
   
   Library: KioskDefault 0 0 */

void swarmBaddie_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //801B5298
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
                   (double)(*(float *)(this->state + 0x14) / 79.0),
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

void swarmBaddie_free(ObjInstance *this,int param2) { //801B534C
  void **ppvVar1;
  
  ppvVar1 = (void **)this->state;
  Object_removePlayerObj(this,4);
  if (*ppvVar1 != (void *)0x0) {
    mm_free(*ppvVar1);
    *ppvVar1 = (void *)0x0;
  }
  return;
}


undefined4 swarmBaddie_func08(ObjInstance *this) { //801B53A0
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int swarmBaddie_getExtraSize(void) { //801B53A8
  return 0x24;
}

