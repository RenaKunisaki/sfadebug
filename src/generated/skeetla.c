
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void skeetla_initialise(undefined4 param) { //801C3C98
  FUN_801c6318();
  return;
}


/* @description Called when DLL is unloaded */

void skeetla_release(void) { //801C3CB8
  return;
}


/* Library Function - Single Match
    dll_DE_func03
   
   Library: KioskDefault 0 0 */

void skeetla_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //801C3D0C
  undefined4 uVar1;
  undefined *puVar2;
  void *param1;
  
  puVar2 = this->state;
  uVar1 = 6;
  printAssertFail("(sizeof(hittab)/sizeof(int)) == BADDIE_HITTAB_SIZE","skeetla.c",0x100);
  printAssertFail("(sizeof(damagetab)/sizeof(s8)) == BADDIE_HITTAB_SIZE","skeetla.c",0x101);
  if (obj2 != (ObjInstance *)0x0) {
    uVar1 = 7;
  }
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar2,5,1,0x108,uVar1)
  ;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)0x0;
  param1 = *(void **)(puVar2 + 0x3f0);
  memclr(param1,0x94);
  *(undefined *)((int)param1 + 0x90) = 5;
  *(byte *)((int)param1 + 0x92) = *(byte *)((int)param1 + 0x92) & 0xf | 0x30;
  *(float *)((int)param1 + 0x7c) = 0.0;
  *(float *)((int)param1 + 0x80) = 1.0;
  *(float *)((int)param1 + 0x84) = 0.0;
  *(float *)((int)param1 + 0x88) = -(this->pos).pos.y;
  *(float *)((int)param1 + 0x70) = (this->pos).pos.x;
  *(float *)((int)param1 + 0x74) = (this->pos).pos.y;
  *(float *)((int)param1 + 0x78) = (this->pos).pos.z;
  Object_ObjAnimSetMove(0.0,this,0,0);
  *(ushort *)(puVar2 + 0x26c) = (ushort)(*(char *)((int)&objDef[1].pos.z + 3) != '\0');
  *(undefined2 *)(puVar2 + 0x268) = 0;
  *(undefined2 *)(puVar2 + 0x3b2) = 0;
  puVar2[0x3b0] = 0;
  puVar2[0x25b] = 0;
  FUN_80088da4((int)this);
  *(float *)((int)param1 + 4) = 1.0;
  *(float *)((int)param1 + 0x18) = 1.0;
  *(float *)((int)param1 + 0x2c) = 1.0;
  *(float *)((int)param1 + 0x40) = 1.0;
  return;
}


/* Library Function - Single Match
    dll_DE_func04
   
   Library: KioskDefault 0 0 */

void skeetla_update(ObjInstance *this) { //801C3EA4
  bool bVar1;
  char cVar2;
  ObjInstance *param2;
  ObjInstance *pOVar3;
  int iVar4;
  ObjDef *pOVar5;
  ObjInstance **ppOVar6;
  undefined *puVar7;
  double dVar8;
  ObjInstance *apOStack_a4 [20];
  char local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  uint uStack_2c;
  
  local_40 = 0x2060167;
  local_3c = &DAT_01650206;
  pOVar5 = this->def;
  puVar7 = this->state;
  ppOVar6 = *(ObjInstance ***)(puVar7 + 0x3f0);
  param2 = Object_objGetMain();
  local_44 = 1000000.0;
  if ((*ppOVar6 == (ObjInstance *)0x0) &&
     (*(undefined *)(ppOVar6 + 0x24) = 6, *(byte *)((int)ppOVar6 + 0x92) >> 4 != 0)) {
    pOVar3 = objDistFn_800920b4(this,0x4ad,&local_44);
    *ppOVar6 = pOVar3;
    if (pOVar3 != (ObjInstance *)0x0) {
      (*(code *)(*ppOVar6)->dll->ptrs2->setScale)(*ppOVar6,ppOVar6 + 0x12,(int)ppOVar6 + 0x91);
      *(undefined *)(ppOVar6 + 0x24) = 5;
    }
    *(byte *)((int)ppOVar6 + 0x92) =
         ((*(byte *)((int)ppOVar6 + 0x92) >> 4) - 1) * '\x10' | *(byte *)((int)ppOVar6 + 0x92) & 0xf
    ;
  }
  if (this->field76_0xf4 == 0) {
    if (this->flags_0xf8 == 0) {
      (this->pos).pos.x = (pOVar5->pos).x;
      (this->pos).pos.y = (pOVar5->pos).y;
      (this->pos).pos.z = (pOVar5->pos).z;
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))
                ((int)*(char *)((int)&pOVar5[1].id + 2),this,0xffffffff);
      this->flags_0xf8 = 1;
    }
    else {
                    /* {@symbol 80162ab0} */
      iVar4 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,puVar7,0);
      if (iVar4 != 0) {
        if (((*(byte *)((int)ppOVar6 + 0x92) >> 1 & 1) == 0) &&
           (iVar4 = touchCallbackRegister(this,param2,-0x7fe3c344), iVar4 != 0)) {
          *(byte *)((int)ppOVar6 + 0x92) = *(byte *)((int)ppOVar6 + 0x92) & 0xfd | 2;
        }
        objRunAnimation((double)(float)ppOVar6[0x11],(double)timeDelta,(int)this,(float *)0x0);
        if (*(short *)(puVar7 + 0x3b2) != 1) {
          uStack_2c = (uint)*(ushort *)(puVar7 + 0x3de);
          local_30 = 0x43300000;
                    /* {@symbol 80162c64} */
          iVar4 = (**(code **)(*(int *)pDll_partfx1F + 0x48))
                            ((double)(float)((double)CONCAT44(0x43300000,uStack_2c) -
                                            4503599627370496.0),this,puVar7,0x8000);
          if (iVar4 != 0) {
                    /* {@symbol 80162f2c} */
            (**(code **)(*(int *)pDll_partfx1F + 0x28))
                      (this,puVar7,puVar7 + 0x34c,(int)*(short *)(puVar7 + 0x39e),0,0,1,0,0xffffffff
                      );
            *(int *)(puVar7 + 0x2c8) = iVar4;
            puVar7[0x33d] = 0;
            *(undefined2 *)(puVar7 + 0x3b2) = 1;
            puVar7[0x3b0] = 2;
          }
          if ((*(int *)(puVar7 + 0x2c8) != 0) && (*(short *)(puVar7 + 0x3b2) == 2)) {
            uStack_2c = (uint)*(ushort *)(puVar7 + 0x3de);
            local_30 = 0x43300000;
            if (*(float *)(puVar7 + 0x2b8) <=
                (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503599627370496.0)) {
              *(undefined2 *)(puVar7 + 0x3b2) = 1;
            }
          }
        }
        if (*(int *)(puVar7 + 0x2c8) != 0) {
          local_50 = *(float *)(*(int *)(puVar7 + 0x2c8) + 0x18) - (this->prevPos).x;
          local_4c = *(float *)(*(int *)(puVar7 + 0x2c8) + 0x1c) - (this->prevPos).y;
          local_48 = *(float *)(*(int *)(puVar7 + 0x2c8) + 0x20) - (this->prevPos).z;
          dVar8 = sqrt((double)(local_48 * local_48 + local_50 * local_50 + local_4c * local_4c));
          *(float *)(puVar7 + 0x2b8) = (float)dVar8;
        }
                    /* {@symbol 80163660} */
        (**(code **)(*(int *)pDll_partfx1F + 0x54))
                  (this,puVar7,puVar7 + 0x34c,(int)*(short *)(puVar7 + 0x39e),0,0,0,0);
        cVar2 = puVar7[0x348];
        if ('\0' < cVar2) {
                    /* {@symbol 801632d4} */
          (**(code **)(*(int *)pDll_partfx1F + 0x50))
                    (this,puVar7,puVar7 + 0x34c,(int)*(short *)(puVar7 + 0x39e),&DAT_803108c0,
                     &DAT_80310928,0,&DAT_80395974);
          if ((char)puVar7[0x348] < cVar2) {
            iVar4 = (*(code *)param2->child[0]->dll->ptrs2[1].setScale)(param2->child[0]);
            if (3 < iVar4) {
              iVar4 = 3;
            }
            uStack_2c = (int)*(short *)((int)&local_40 + iVar4 * 2) ^ 0x80000000;
            local_30 = 0x43300000;
            DAT_8039597c = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503601774854144.0);
                    /* {@symbol 800ed30c} */
            (**(code **)(*(int *)pDll_objfsa + 8))
                      (this,0x323,&DAT_80395974,&DAT_00200001,0xffffffff,0);
            DAT_80395980 = DAT_80395980 - (this->pos).pos.x;
            DAT_80395984 = DAT_80395984 - (this->pos).pos.y;
            DAT_80395988 = DAT_80395988 - (this->pos).pos.z;
            uStack_34 = (int)*(short *)((int)&local_40 + iVar4 * 2) ^ 0x80000000;
            local_38 = 0x43300000;
            DAT_8039597c = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503601774854144.0);
            iVar4 = 4;
            while( true ) {
              bVar1 = iVar4 == 0;
              iVar4 = iVar4 + -1;
              if (bVar1) break;
                    /* {@symbol 800ed30c} */
              (**(code **)(*(int *)pDll_objfsa + 8))(this,0x324,&DAT_80395974,2,0xffffffff,0);
            }
          }
        }
                    /* {@symbol 8016296c} */
        (**(code **)(*(int *)pDll_partfx1F + 0x2c))(0,this,puVar7,0xffffffff);
        *(ObjInstance **)(puVar7 + 0x3a8) = this->pObj_0xc0;
        this->pObj_0xc0 = (ObjInstance *)0x0;
                    /* {@symbol 8011bdb4} */
        (**(code **)(*(int *)pDll11 + 8))
                  ((double)timeDelta,(double)timeDelta,this,puVar7,&DAT_80395960,&DAT_80399d18);
        this->pObj_0xc0 = *(ObjInstance **)(puVar7 + 0x3a8);
        if (((*(byte *)((int)ppOVar6 + 0x92) & 1) == 0) && (*(char *)(ppOVar6 + 0x24) == '\x06')) {
          iVar4 = FUN_800bb7e0(6.0,&(this->oldPos).x,&(this->pos).pos.x,0,apOStack_a4,this,0x84,-1,
                               0xff,'\0');
          if ((iVar4 != 0) && (local_54 == '\r')) {
            *(byte *)((int)ppOVar6 + 0x92) = *(byte *)((int)ppOVar6 + 0x92) & 0xfe | 1;
            iVar4 = randInt(10,0xf);
            *(short *)((int)ppOVar6 + 0x8e) = (short)iVar4 * 0x3c;
          }
        }
      }
    }
  }
  return;
}


/* @description Override hit detection */

void skeetla_hitDetect(ObjInstance *this) { //801C4460
  return;
}


/* Library Function - Single Match
    dll_DE_func06
   
   Library: KioskDefault 0 0 */

void skeetla_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //801C4550
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar3;
  int iVar4;
  float afStack_68 [12];
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_28;
  uint uStack_24;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar3 = this->state;
  iVar4 = *(int *)(puVar3 + 0x3f0);
  iVar1 = FUN_8018d744();
  if ((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) {
    if (((this->pos).flags & 0x100) != 0) {
      uStack_24 = (uint)*(ushort *)(puVar3 + 0x3de);
      local_28 = 0x43300000;
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,uStack_24) - 4503599627370496.0),32.0
                   ,param2_00,param3_00,0,0xc0,0x20);
    }
  }
  else {
    if (!shouldRender) {
      return;
    }
    if (this->field76_0xf4 != 0) {
      return;
    }
  }
  if ((*(char *)(iVar4 + 0x90) == '\x06') && ((*(byte *)(iVar4 + 0x92) >> 3 & 1) != 0)) {
    if ((*(byte *)(iVar4 + 0x92) >> 2 & 1) == 0) {
      mtxFn_80166e38((float *)(iVar4 + 4),&(this->vel).x,(float *)(iVar4 + 0x7c));
    }
    FUN_8007acd4((double)(this->pos).scale,(double)(this->pos).scale,(double)(this->pos).scale,
                 afStack_68);
    Mtx44VecMult(afStack_68,(float *)(iVar4 + 4),afStack_68);
    local_38 = (this->pos).pos.x - playerMapOffsetX;
    local_34 = (this->pos).pos.y;
    local_30 = (this->pos).pos.z - playerMapOffsetZ;
    FUN_80094b08(afStack_68);
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    FUN_80094b08(0);
  }
  else {
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_DE_func07
   
   Library: KioskDefault 0 0 */

void skeetla_free(ObjInstance *this,int param2) { //801C46E8
  undefined *puVar1;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
  if (this->child[0] != (ObjInstance *)0x0) {
    Object_objFreeObject(this->child[0]);
    this->child[0] = (ObjInstance *)0x0;
  }
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar1,0);
  return;
}


undefined4 skeetla_func08(ObjInstance *this) { //801C475C
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int skeetla_getExtraSize(void) { //801C4764
  return 0x48c;
}

