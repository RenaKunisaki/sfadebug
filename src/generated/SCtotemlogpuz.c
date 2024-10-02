
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCtotemlogpuz_initialise(undefined4 param) { //8025C11C
  return;
}


/* @description Called when DLL is unloaded */

void SCtotemlogpuz_release(void) { //8025C120
  return;
}


/* Library Function - Single Match
    dll_1FB_func03
   
   Library: KioskDefault 0 0 */

void SCtotemlogpuz_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                        float x,float y,float z) { //8025C124
  short sVar1;
  int iVar2;
  short *psVar3;
  
  psVar3 = (short *)this->state;
  this->curModel = objDef[1].mapStates1;
  if (((char)this->curModel < '\0') || ('\x05' < (char)this->curModel)) {
    this->curModel = 0;
  }
  (this->pos).rotation.x = -0x7fff;
  psVar3[4] = (short)((int)(uint)(ushort)(this->pos).rotation.x >> 0xd);
  iVar2 = randInt(7,10);
  sVar1 = (short)iVar2 * 10;
  *psVar3 = sVar1;
  *(float *)(psVar3 + 2) =
       (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - 4503601774854144.0);
  iVar2 = randInt(0,1);
  if (iVar2 != 0) {
    psVar3[5] = 1;
  }
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8025c738;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  return;
}


/* Library Function - Single Match
    dll_1FB_func04
   
   Library: KioskDefault 0 0 */

void SCtotemlogpuz_update(ObjInstance *this) { //8025C20C
  short sVar1;
  uint uVar2;
  ObjInstance *pOVar3;
  int iVar4;
  bool bVar5;
  short *psVar6;
  ObjInstance *local_34;
  uint uStack_30;
  int iStack_2c;
  double local_28;
  double local_20;
  
  psVar6 = (short *)this->state;
  if (this->curModel == 5) {
    uVar2 = mainGetBit(0x639);
    if (uVar2 == 0) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
    }
    else {
      local_34 = Object_objGetMain();
      pOVar3 = playerGetRidingObj(local_34);
      if (pOVar3 == (ObjInstance *)0x0) {
        mainSetBits(0x63b,0);
      }
      else {
        mainSetBits(0x63b,1);
      }
    }
  }
  else {
    uVar2 = mainGetBit(0x639);
    if (uVar2 == 0) {
      *(float *)(psVar6 + 2) = *(float *)(psVar6 + 2) - timeDelta;
      iVar4 = FUN_800883e4((int)this,&local_34,&iStack_2c,&uStack_30);
      if (iVar4 != 0) {
        audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                            (double)(this->prevPos).z,499,0x7f,"SCtotemlogpuz.c",
                            (int *)0x78);
        psVar6[5] = psVar6[5] ^ 2;
        if ((psVar6[5] & 2U) != 0) {
          bVar5 = FUN_8025c5f4(this);
          mainSetBits(0x639,(uint)bVar5);
        }
      }
      if ((psVar6[5] & 2U) == 0) {
        if ((psVar6[5] & 1U) == 0) {
          if (*(float *)(psVar6 + 2) < 0.0) {
            local_28 = (double)CONCAT44(0x43300000,(int)*psVar6 ^ 0x80000000);
            *(float *)(psVar6 + 2) = (float)(local_28 - 4503601774854144.0);
            sVar1 = psVar6[4];
            psVar6[4] = sVar1 + -1;
            if ((short)(sVar1 + -1) < 0) {
              psVar6[4] = 7;
            }
            uVar2 = randInt(-0x32,0x32);
            local_28 = (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000);
            iVar4 = randInt(0x40,0x7f);
            audioTryStartSfx((int *)this,1,0xf2,(byte)iVar4,"SCtotemlogpuz.c",0x9b);
          }
          if ((int)(uint)(ushort)(this->pos).rotation.x >> 0xd != (int)psVar6[4]) {
            local_28 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
            (this->pos).rotation.x =
                 (short)(int)-(timeDelta * 512.0 - (float)(local_28 - 4503601774854144.0));
          }
        }
        else {
          if (*(float *)(psVar6 + 2) < 0.0) {
            local_20 = (double)CONCAT44(0x43300000,(int)*psVar6 ^ 0x80000000);
            *(float *)(psVar6 + 2) = (float)(local_20 - 4503601774854144.0);
            sVar1 = psVar6[4];
            psVar6[4] = sVar1 + 1;
            if (7 < (short)(sVar1 + 1)) {
              psVar6[4] = 0;
            }
            uVar2 = randInt(-0x32,0x32);
            local_20 = (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000);
            iVar4 = randInt(0x40,0x7f);
            audioTryStartSfx((int *)this,1,0xf2,(byte)iVar4,"SCtotemlogpuz.c",0x8b);
          }
          if ((int)(uint)(ushort)(this->pos).rotation.x >> 0xd != (int)psVar6[4]) {
            local_20 = (double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000);
            (this->pos).rotation.x =
                 (short)(int)(timeDelta * 512.0 + (float)(local_20 - 4503601774854144.0));
          }
        }
      }
    }
  }
  return;
}


/* @description Override hit detection */

void SCtotemlogpuz_hitDetect(ObjInstance *this) { //8025C580
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void SCtotemlogpuz_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8025C584
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

void SCtotemlogpuz_free(ObjInstance *this,int param2) { //8025C5E0
  return;
}


undefined4 SCtotemlogpuz_func08(ObjInstance *this) { //8025C5E4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SCtotemlogpuz_getExtraSize(void) { //8025C5EC
  return 0xc;
}

