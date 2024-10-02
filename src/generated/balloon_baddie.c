
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void balloonBaddie_initialise(undefined4 param) { //801B4054
  return;
}


/* @description Called when DLL is unloaded */

void balloonBaddie_release(void) { //801B4058
  return;
}


/* Library Function - Single Match
    balloonBaddie_func03
   
   Library: KioskDefault 0 0 */

void balloonBaddie_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //801B405C
  short sVar1;
  void *pvVar2;
  char cVar3;
  void **ppvVar4;
  
  ppvVar4 = (void **)this->state;
  sVar1._0_1_ = objDef[1].allocatedSize;
  sVar1._1_1_ = objDef[1].mapStates1;
  ppvVar4[2] = (void *)((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) -
                               4503601774854144.0) / 100.0);
  ppvVar4[3] = (void *)0.005;
  ppvVar4[8] = (void *)((float)((double)CONCAT44(0x43300000,
                                                 (int)*(char *)((int)&objDef[1].objType + 1) ^
                                                 0x80000000) - 4503601774854144.0) * 4.0);
  if (obj2 == (ObjInstance *)0x0) {
    pvVar2 = mmAlloc(0x108,TEST_COL,"BalloonBaddieDLL");
    *ppvVar4 = pvVar2;
    if (*ppvVar4 != (void *)0x0) {
      memclr(*ppvVar4,0x108);
    }
                    /* {@symbol 80128bb8} */
    cVar3 = (**(code **)(*(int *)pDll_RomCurve + 0x8c))
                      ((double)(float)ppvVar4[8],*ppvVar4,this,&DAT_80397b38,0xffffffff);
    if (cVar3 == '\0') {
      *(byte *)((int)ppvVar4 + 0x2e) = *(byte *)((int)ppvVar4 + 0x2e) | 1;
    }
    else {
      printf("Error Balloon Baddie MUST have a baddie curve network!");
    }
    audioTryStartSfx((int *)this,0x40,0xe0,0x7f,"balloon_baddie.c",0xa0);
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    balloonBaddie_func04
   
   Library: KioskDefault 0 0 */

void balloonBaddie_update(ObjInstance *this) { //801B41AC
  short sVar1;
  int iVar2;
  uint uVar3;
  ObjInstance *pOVar4;
  ObjDef *pOVar5;
  float *pfVar6;
  float **ppfVar7;
  double dVar8;
  uint uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  float local_30;
  float local_2c;
  float local_28;
  ObjInstance *local_24;
  double local_20;
  
  ppfVar7 = (float **)this->state;
  pfVar6 = *ppfVar7;
  pOVar5 = this->def;
  if (this->field76_0xf4 == 0) {
    if ((float)ppfVar7[6] <= 0.0) {
      iVar2 = FUN_800884c8((int)this,&local_24,&iStack_40,&uStack_44,&uStack_34,&uStack_38,
                           &uStack_3c);
      if (iVar2 != 0) {
        FUN_80068a9c((uint)this,0x7f);
        ppfVar7[6] = (float *)1.0;
        *(byte *)((int)ppfVar7 + 0x2e) = *(byte *)((int)ppfVar7 + 0x2e) | 0x30;
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x207,0x7f,"balloon_baddie.c",
                            (int *)0xe2);
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,0x86,0x7f,"balloon_baddie.c",
                            (int *)0xe3);
        audioTryStartSfx((int *)this,0x10,0xd5,0x7f,"balloon_baddie.c",0xe4);
        local_24 = Object_objGetMain();
        if (local_24->romdefno == Sabre) {
          iVar2 = randInt(0,2);
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,
                              (ushort)*(undefined4 *)(&DAT_8030fb74 + iVar2 * 4),0x7f,
                              "balloon_baddie.c",(int *)0xec);
        }
        else {
          iVar2 = randInt(0,2);
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,
                              (ushort)*(undefined4 *)(&DAT_8030fb60 + iVar2 * 4),0x7f,
                              "balloon_baddie.c",(int *)0xe8);
        }
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x331,0,2,0xffffffff,0);
                    /* {@symbol 80163050} */
        (**(code **)(*(int *)pDll_partfx1F + 0x4c))
                  (this,(int)*(char *)&pOVar5[1].objType,0xffffffff,0);
        sVar1._0_1_ = pOVar5[1].loadFlags;
        sVar1._1_1_ = pOVar5[1].mapStates2;
        local_20 = (double)CONCAT44(0x43300000,sVar1 * 0x3c ^ 0x80000000);
                    /* {@symbol 8012db54} */
        (**(code **)(*(int *)pDll_SaveGame + 100))
                  ((double)(float)(local_20 - 4503601774854144.0),pOVar5->id);
      }
      objHitFn_80089074(this,10,1,0);
      FUN_80088d3c((int)this);
      ppfVar7[7] = (float *)((float)ppfVar7[7] - timeDelta);
      if ((float)ppfVar7[7] < 0.0) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x335,0,2,0xffffffff,0);
        uVar3 = randInt(0x1e,0x78);
        local_20 = (double)CONCAT44(0x43300000,uVar3 ^ 0x80000000);
        ppfVar7[7] = (float *)(float)(local_20 - 4503601774854144.0);
      }
    }
    else {
      ppfVar7[6] = (float *)(timeDelta * 0.01 + (float)ppfVar7[6]);
      if ((float)ppfVar7[6] <= 3.0) {
        if ((float)ppfVar7[6] <= 2.0) {
          iVar2 = (int)((2.0 - (float)ppfVar7[6]) * 255.0);
          local_20 = (double)(longlong)iVar2;
          this->newOpacity = (u8)iVar2;
        }
        else {
          *(byte *)((int)ppfVar7 + 0x2e) = *(byte *)((int)ppfVar7 + 0x2e) & 0xcf;
        }
      }
      else {
        this->field76_0xf4 = 1;
        ppfVar7[6] = (float *)0.0;
      }
      FUN_80088da4((int)this);
    }
    pOVar4 = Object_objGetMain();
    ppfVar7[1] = (float *)pOVar4;
    if (ppfVar7[1] != (float *)0x0) {
      local_30 = ppfVar7[1][6] - (this->prevPos).x;
      local_2c = ppfVar7[1][7] - (this->prevPos).y;
      local_28 = ppfVar7[1][8] - (this->prevPos).z;
      dVar8 = sqrt((double)(local_28 * local_28 + local_30 * local_30 + local_2c * local_2c));
      ppfVar7[4] = (float *)(float)dVar8;
    }
    if (pfVar6 != (float *)0x0) {
      local_30 = pfVar6[0x1a] - (this->prevPos).x;
      local_2c = pfVar6[0x1b] - (this->prevPos).y;
      local_28 = pfVar6[0x1c] - (this->prevPos).z;
      dVar8 = sqrt((double)(local_28 * local_28 + local_30 * local_30 + local_2c * local_2c));
      ppfVar7[5] = (float *)(float)dVar8;
    }
    if ((*(byte *)((int)ppfVar7 + 0x2e) & 2) != 0) {
      if (250.0 < (float)ppfVar7[5]) {
        *(byte *)((int)ppfVar7 + 0x2e) = *(byte *)((int)ppfVar7 + 0x2e) & 0xfd;
        *(byte *)((int)ppfVar7 + 0x2e) = *(byte *)((int)ppfVar7 + 0x2e) | 4;
      }
    }
    if ((*(byte *)((int)ppfVar7 + 0x2e) & 4) != 0) {
      if ((float)ppfVar7[5] < 30.0) {
        *(byte *)((int)ppfVar7 + 0x2e) = *(byte *)((int)ppfVar7 + 0x2e) & 0xfb;
      }
    }
    if ((((*(byte *)((int)ppfVar7 + 0x2e) & 6) == 0) && (ppfVar7[1] != (float *)0x0)) &&
       ((float)ppfVar7[4] < (float)ppfVar7[8])) {
      *(byte *)((int)ppfVar7 + 0x2e) = *(byte *)((int)ppfVar7 + 0x2e) | 2;
    }
    FUN_801b48e0(this,ppfVar7);
  }
  else {
                    /* {@symbol 8012dc1c} */
    iVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(pOVar5->id);
    if (iVar2 != 0) {
      this->field76_0xf4 = 0;
      this->newOpacity = 0xff;
      *(byte *)((int)ppfVar7 + 0x2e) = *(byte *)((int)ppfVar7 + 0x2e) | 8;
      audioTryStartSfx((int *)this,0x10,0x23,0x7f,"balloon_baddie.c",0xc0);
    }
  }
  return;
}


/* @description Override hit detection */

void balloonBaddie_hitDetect(ObjInstance *this) { //801B46D8
  return;
}


/* Library Function - Single Match
    balloonBaddie_func06
   
   Library: KioskDefault 0 0 */

void balloonBaddie_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801B46DC
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  
  puVar3 = this->state;
  if ((shouldRender) && (this->field76_0xf4 == 0)) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80095aec((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(*(float *)(puVar3 + 0x20) / 79.0),
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),1);
    }
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((puVar3[0x2e] & 0x30) != 0) {
      if ((puVar3[0x2e] & 0x10) != 0) {
                    /* {@symbol 800ea278} */
        (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar3 + 0x18);
                    /* {@symbol 800ea278} */
        (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar3 + 0x18);
        puVar3[0x2e] = puVar3[0x2e] & 0xef;
      }
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x32f,puVar3 + 0x18);
    }
    if ((puVar3[0x2e] & 8) != 0) {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x333,puVar3 + 0x18);
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x334,puVar3 + 0x18);
      puVar3[0x2e] = puVar3[0x2e] & 0xf7;
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    balloonBaddie_func07
    swarmBaddie_func07
    wispBaddie_func07
   
   Library: KioskDefault 0 0 */

void balloonBaddie_free(ObjInstance *this,int param2) { //801B487C
  void **ppvVar1;
  
  ppvVar1 = (void **)this->state;
  Object_removePlayerObj(this,4);
  if (*ppvVar1 != (void *)0x0) {
    mm_free(*ppvVar1);
    *ppvVar1 = (void *)0x0;
  }
  return;
}


undefined4 balloonBaddie_func08(ObjInstance *this) { //801B48D0
  return 9;
}


/* @description Get extra size for object (size of State struct) */

int balloonBaddie_getExtraSize(void) { //801B48D8
  return 0x30;
}

