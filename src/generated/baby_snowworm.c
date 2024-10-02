
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void babySnowWorm_initialise(undefined4 param) { //801BBB50
  FUN_801bd9dc();
  return;
}


/* @description Called when DLL is unloaded */

void babySnowWorm_release(void) { //801BBB70
  return;
}


/* Library Function - Single Match
    babySnowWorm_func03
   
   Library: KioskDefault 0 0 */

void babySnowWorm_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //801BBB74
  float *pfVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  uVar2 = 6;
  if (obj2 != (ObjInstance *)0x0) {
    uVar2 = 7;
  }
  if ((*(byte *)((int)&objDef[1].pos.z + 3) & 0x20) == 0) {
    uVar2 = uVar2 | 8;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar3,7,6,0x102,uVar2)
  ;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)0x0;
  pfVar1 = *(float **)(puVar3 + 0x3f0);
  uVar2 = randInt(10,300);
  *pfVar1 = (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - 4503601774854144.0);
  Object_ObjAnimSetMove(0.0,this,8,0);
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
                    /* {@symbol 8011c3c0} */
  (**(code **)(*(int *)pDll11 + 0x14))(this,puVar3,0);
  *(undefined2 *)(puVar3 + 0x268) = 0;
  puVar3[0x25b] = 0;
  FUN_80088da4((int)this);
  return;
}


/* Library Function - Single Match
    babySnowWorm_func04
   
   Library: KioskDefault 0 0 */

void babySnowWorm_update(ObjInstance *this) { //801BBC98
  int iVar1;
  ObjDef *pOVar2;
  undefined *puVar3;
  undefined auStack_14 [4];
  
  puVar3 = this->state;
  pOVar2 = this->def;
  if (this->field76_0xf4 == 0) {
    if (this->flags_0xf8 == 0) {
      (this->pos).pos.x = (pOVar2->pos).x;
      (this->pos).pos.y = (pOVar2->pos).y;
      (this->pos).pos.z = (pOVar2->pos).z;
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))
                ((int)*(char *)((int)&pOVar2[1].id + 2),this,0xffffffff);
      this->flags_0xf8 = 1;
    }
    else {
                    /* {@symbol 80162ab0} */
      iVar1 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,puVar3,0);
      if (iVar1 == 0) {
        *(undefined2 *)(puVar3 + 0x3b2) = 0;
      }
      else {
                    /* {@symbol 800d2604} */
        if (((puVar3[0x3ac] & 0x10) == 0) ||
           (iVar1 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_14), iVar1 != 0)) {
          FUN_801bc1d4((int)this,(int)puVar3,(int)puVar3);
          if (*(short *)(puVar3 + 0x3b2) == 0) {
            FUN_801bc550((int *)this,(int)puVar3,(int)puVar3);
          }
          else {
            FUN_801bc480(this,(int)puVar3,puVar3);
          }
          (this->pos).pos.y = (pOVar2->pos).y - 2.0;
        }
        else {
          *(undefined2 *)(puVar3 + 0x3b2) = 0;
        }
      }
    }
  }
  else {
                    /* {@symbol 8012dc1c} */
    if (((*(short *)(puVar3 + 0x268) != 3) || ((puVar3[0x3ac] & 1) != 0)) &&
       (iVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(pOVar2->id), iVar1 != 0)) {
                    /* {@symbol 8016386c} */
      (**(code **)(*(int *)pDll_partfx1F + 0x58))
                (0x4034000000000000,this,pOVar2,puVar3,7,6,0x102,0x26);
      *(undefined2 *)(puVar3 + 0x3b2) = 0;
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x23,0x7f,"baby_snowworm.c",
                          (int *)0x140);
      Object_ObjAnimSetMove(0.0,this,8,0x10);
      puVar3[0x33a] = 0;
      this->newOpacity = 0xff;
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    }
  }
  return;
}


/* @description Override hit detection */

void babySnowWorm_hitDetect(ObjInstance *this) { //801BBEB8
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    babySnowWorm_func06
    dll_E0_func06
   
   Library: KioskDefault 0 0 */

void babySnowWorm_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801BBEBC
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  double local_18;
  
  puVar3 = this->state;
  iVar1 = FUN_8018d744();
  if ((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) {
    if (((this->pos).flags & 0x100) != 0) {
      local_18 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar3 + 0x3de));
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)(local_18 - 4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0,0xc0,0x20);
    }
  }
  else {
    if (!shouldRender) {
      return;
    }
    if (this->field76_0xf4 != 0) {
      return;
    }
    if (*(short *)(puVar3 + 0x3b2) == 0) {
      return;
    }
  }
  if (*(float *)(puVar3 + 0x3e4) != 0.0) {
    FUN_80096b14(200,0,0,(char)(int)*(float *)(puVar3 + 0x3e4));
  }
  objRenderCurrentModel
            (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
             (int *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  if ((*(ushort *)(puVar3 + 0x3ae) & 0x60) != 0) {
    if ((*(ushort *)(puVar3 + 0x3ae) & 0x20) != 0) {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar3 + 0x3e4);
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar3 + 0x3e4);
    }
                    /* {@symbol 800ea278} */
    (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x32f,puVar3 + 0x3e4);
  }
  return;
}


/* Library Function - Single Match
    babySnowWorm_func07
   
   Library: KioskDefault 0 0 */

void babySnowWorm_free(ObjInstance *this,int param2) { //801BC050
  undefined *puVar1;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
  if (this->child[0] != (ObjInstance *)0x0) {
    Object_objFreeObject(this->child[0]);
    this->child[0] = (ObjInstance *)0x0;
  }
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar1,0x20);
  return;
}


undefined4 babySnowWorm_func08(ObjInstance *this) { //801BC0C4
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int babySnowWorm_getExtraSize(void) { //801BC0CC
  return 0x404;
}


void babySnowWorm_setScale(ObjInstance *this,float scale) { //801BC0D4
  return;
}


/* Library Function - Single Match
    babySnowWorm_handleMsg
   
   Library: KioskDefault 0 0 */

void babySnowWorm_handleMsg(ObjInstance *param1,byte param2) { //801BC0F4
  undefined *puVar1;
  
  puVar1 = param1->state;
  if (param2 == 0x81) {
    puVar1[0x3ac] = puVar1[0x3ac] & 0xfb;
  }
  else if ((param2 < 0x81) && (0x7f < param2)) {
    *(byte *)(*(int *)(puVar1 + 0x3f0) + 9) = *(byte *)(*(int *)(puVar1 + 0x3f0) + 9) | 2;
    audioTryStartSfx((int *)param1,0x10,(ushort)DAT_80310308,0x7f,"baby_snowworm.c",0x1ef);
                    /* {@symbol 8011c3c0} */
    (**(code **)(*(int *)pDll11 + 0x14))(param1,puVar1,1);
    *(undefined2 *)(puVar1 + 0x268) = 4;
    puVar1[0x273] = 1;
  }
  else {
    printf("BADDIE:SnowWorm Unknown message [%d]",(uint)param2);
  }
  return;
}

