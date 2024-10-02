
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void snowWorm_initialise(undefined4 param) { //802A0F64
  FUN_802a50ec();
  return;
}


/* @description Called when DLL is unloaded */

void snowWorm_release(void) { //802A0F84
  return;
}


/* Library Function - Single Match
    snowWorm_func03
   
   Library: KioskDefault 0 0 */

void snowWorm_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802A0F88
  uint uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int *param1;
  
  puVar3 = this->state;
  uVar2 = 6;
  if (obj2 != (ObjInstance *)0x0) {
    uVar2 = 7;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))
            (0x4034000000000000,this,objDef,puVar3,0x10,7,0x10a,uVar2);
  Object_objAddObjectType(this,4);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)0x0;
  param1 = *(int **)(puVar3 + 0x3f0);
  memclr(param1,0x48);
  param1[2] = (int)20.0;
  *param1 = *(short *)&objDef[1].pos.y * 8 + -0x7fcddc94;
  uVar1 = randInt(10,300);
  param1[3] = (int)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0);
  *(byte *)(param1 + 0x11) =
       (byte)((*(byte *)((int)&objDef[1].pos.z + 3) & 1) << 5) | *(byte *)(param1 + 0x11) & 0xdf;
  if (obj2 == (ObjInstance *)0x0) {
    FUN_802a4ed0((DtypeStack **)(param1 + 9),(int *)(*(short *)&objDef[1].pos.y * 8 + -0x7fcddc94));
  }
  Object_ObjAnimSetMove(0.0,this,8,0);
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
                    /* {@symbol 8011c3c0} */
  (**(code **)(*(int *)pDll11 + 0x14))(this,puVar3,3);
  *(undefined2 *)(puVar3 + 0x268) = 0;
  puVar3[0x25b] = 1;
  FUN_80088d3c((int)this);
  objAllocMsgQueue(this,4);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x4008;
  }
  return;
}


/* Library Function - Single Match
    snowWorm_func04
   
   Library: KioskDefault 0 0 */

void snowWorm_update(ObjInstance *this) { //802A1130
  uint uVar1;
  int iVar2;
  ObjDef *pOVar3;
  undefined *param2;
  
  param2 = this->state;
  pOVar3 = this->def;
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  if (this->field76_0xf4 == 0) {
    if (this->flags_0xf8 == 0) {
      (this->pos).pos.x = (pOVar3->pos).x;
      (this->pos).pos.y = (pOVar3->pos).y;
      (this->pos).pos.z = (pOVar3->pos).z;
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))
                ((int)*(char *)((int)&pOVar3[1].id + 2),this,0xffffffff);
      this->flags_0xf8 = 1;
    }
    else {
                    /* {@symbol 80162ab0} */
      iVar2 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,param2,0);
      if (iVar2 == 0) {
        *(undefined2 *)(param2 + 0x3b2) = 0;
      }
      else {
        hitByShitFn_802a1734((int)this,(int)param2,(int)param2);
        if (*(short *)(param2 + 0x3b2) == 0) {
          FUN_802a1a5c(this,(int)param2,(int)param2);
        }
        else {
          FUN_802a197c(this,(int)param2,param2);
        }
      }
    }
  }
  else {
    uVar1 = mainGetBit((int)*(short *)(param2 + 0x3a0));
                    /* {@symbol 8012dc1c} */
    if (((uVar1 == 0) && ((param2[0x3ac] & 4) == 0)) &&
       (iVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(pOVar3->id), iVar2 != 0)) {
                    /* {@symbol 8016386c} */
      (**(code **)(*(int *)pDll_partfx1F + 0x58))
                (0x4034000000000000,this,pOVar3,param2,0x10,7,0x10a,0x26);
      Object_objAddObjectType(this,4);
      *(undefined2 *)(param2 + 0x3b2) = 0;
      Object_ObjAnimSetMove(0.0,this,8,0x10);
      param2[0x33a] = 0;
      this->newOpacity = 0xff;
      this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    }
  }
  return;
}


/* Library Function - Single Match
    snowWorm_func05
   
   Library: KioskDefault 0 0 */

void snowWorm_hitDetect(ObjInstance *this) { //802A1304
                    /* {@symbol 8011c220} */
  (**(code **)(*(int *)pDll11 + 0xc))(this,this->state,&DAT_80396528);
  return;
}


/* Library Function - Single Match
    snowWorm_func06
   
   Library: KioskDefault 0 0 */

void snowWorm_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802A1350
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int iVar3;
  undefined *puVar4;
  double local_28;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar4 = this->state;
  iVar3 = *(int *)(puVar4 + 0x3f0);
  if (*(int *)(iVar3 + 0x18) != 0) {
    *(float *)(*(int *)(iVar3 + 0x18) + 0xc) = (this->pos).pos.x;
    *(float *)(*(int *)(iVar3 + 0x18) + 0x10) = (this->pos).pos.y;
    *(float *)(*(int *)(iVar3 + 0x18) + 0x14) = (this->pos).pos.z;
    *(float *)(*(int *)(iVar3 + 0x18) + 0x10) = *(float *)(*(int *)(iVar3 + 0x18) + 0x10) + 30.0;
  }
  iVar1 = FUN_8018d744();
  if ((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) {
    if (((this->pos).flags & 0x100) != 0) {
      local_28 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(puVar4 + 0x3de));
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)(local_28 - 4503599627370496.0),32.0,param2_00,param3_00,0,0xc0,
                   0x20);
    }
  }
  else {
    if (!shouldRender) {
      return;
    }
    if (this->field76_0xf4 != 0) {
      return;
    }
    if (*(short *)(puVar4 + 0x3b2) == 0) {
      return;
    }
  }
  if (*(float *)(puVar4 + 0x3e4) != 0.0) {
    FUN_80096b14(200,0,0,(char)(int)*(float *)(puVar4 + 0x3e4));
  }
  objRenderCurrentModel
            (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  if ((*(ushort *)(puVar4 + 0x3ae) & 0x60) != 0) {
    if ((*(ushort *)(puVar4 + 0x3ae) & 0x20) != 0) {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar4 + 0x3e4);
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,puVar4 + 0x3e4);
    }
                    /* {@symbol 800ea278} */
    (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x32f,puVar4 + 0x3e4);
  }
  if ((*(int *)(iVar3 + 0x18) != 0) &&
     (iVar1 = *(int *)(iVar3 + 0x18), (*(ushort *)(iVar1 + 0xb0) & 0x40) == 0)) {
    objGetAttachPointWorldPos
              (this,3,(float *)(iVar1 + 0xc),(float *)(iVar1 + 0x10),(float *)(iVar1 + 0x14),FALSE);
    objRenderCurrentModel
              (*(ObjInstance **)(iVar3 + 0x18),(Gfx **)param2_00,param3_00,
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    snowWorm_func07
   
   Library: KioskDefault 0 0 */

void snowWorm_free(ObjInstance *this,int param2) { //802A1584
  int iVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  iVar1 = *(int *)(puVar2 + 0x3f0);
  Object_removePlayerObj(this,4);
  FUN_80070394(*(void **)(iVar1 + 0x24));
  if (this->child[0] != (ObjInstance *)0x0) {
    Object_objFreeObject(this->child[0]);
    this->child[0] = (ObjInstance *)0x0;
  }
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar2,3);
  return;
}


undefined4 snowWorm_func08(ObjInstance *this) { //802A1604
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int snowWorm_getExtraSize(void) { //802A160C
  return 0x440;
}


void snowWorm_setScale(ObjInstance *this,float scale) { //802A1614
  return;
}


/* Library Function - Single Match
    snowWorm_func0B
   
   Library: KioskDefault 0 0 */

undefined4 snowWorm_func0B(uint param1,byte param2,undefined4 *param3) { //802A1634
  int iVar1;
  
  iVar1 = *(int *)(param1 + 0xb8);
  if (param2 == 0x82) {
    if (*(short *)(iVar1 + 0x26c) != 0xb) {
      printf(" IN STATE: %i %x ",(int)*(short *)(iVar1 + 0x26c),param1);
      return 0;
    }
    if (param3 == (undefined4 *)0x0) {
      return 0;
    }
    *(undefined4 **)(*(int *)(iVar1 + 0x3f0) + 0x3c) = param3;
    return 1;
  }
  if (param2 < 0x82) {
    if (param2 == 0x80) {
      return 0;
    }
    if (0x7f < param2) {
      if ((*(byte *)(iVar1 + 0x3ac) & 2) == 0) {
        return 0;
      }
      *(byte *)(iVar1 + 0x3ac) = *(byte *)(iVar1 + 0x3ac) & 0xfd;
      if (param3 != (undefined4 *)0x0) {
        *param3 = 1;
      }
      return 1;
    }
  }
  else if (param2 < 0x84) {
    return *(undefined4 *)(*(int *)(iVar1 + 0x3f0) + 0x3c);
  }
  printf("BADDIE:SnowWorm Unknown message [%d]",(uint)param2);
  return 0;
}

