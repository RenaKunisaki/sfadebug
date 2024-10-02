
/* @description Set up object instance */

void magicPlant_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //801E2E1C
  int iVar1;
  undefined *puVar2;
  double dVar3;
  
  puVar2 = this->state;
  Object_objAddObjectType(this,0x36);
  Object_objAddObjectType(this,0x40);
                    /* {@symbol 8012dc1c} */
  iVar1 = (**(code **)(*(int *)pDll_SaveGame + 0x68))(objDef->id);
  if (iVar1 == 0) {
    dVar3 = (double)FUN_801e3a3c((int)objDef);
    *(float *)(puVar2 + 4) = (float)dVar3;
  }
  else {
    *(float *)(puVar2 + 4) = 1.0;
  }
  puVar2[0xf] = 0;
  *(float *)(puVar2 + 8) = 0.0;
  FUN_80086488((double)*(float *)(puVar2 + 4),(int)this);
  (this->pos).rotation.x = (ushort)objDef[1].mapStates2 << 8;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  this->curModel = objDef[1].loadFlags;
  if (this->data->nModels <= (char)this->curModel) {
    printf("MAGICPLANT: modelno error");
    this->curModel = 0;
  }
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0x810;
  }
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801e31c4;
  return;
}


/* @description Update object instance */

void magicPlant_update(ObjInstance *this) { //801E2F38
  char cVar1;
  byte bVar3;
  uint uVar2;
  ObjDef *pOVar4;
  ObjInstance **ppOVar5;
  double in_f1;
  
  pOVar4 = this->def;
  ppOVar5 = (ObjInstance **)this->state;
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  bVar3 = FUN_80085d5c((int)this);
  if (bVar3 == 0) {
    if (((this->flags_0xaf & FieldB8TimeCanBeNegative) == 0) ||
       (uVar2 = mainGetBit(0x914), uVar2 != 0)) {
      cVar1 = *(char *)((int)ppOVar5 + 0xf);
      if (cVar1 == '\x02') {
        FUN_801e38f8(this,pOVar4,(int)ppOVar5);
      }
      else if (cVar1 < '\x02') {
        if (cVar1 == '\0') {
          FUN_801e32cc(this,(int)pOVar4,(int)ppOVar5);
        }
        else if (-1 < cVar1) {
          FUN_801e338c(in_f1,this,pOVar4,(int)ppOVar5);
        }
      }
      else if (cVar1 == '\x04') {
        MagicPlant_dropGem(this,pOVar4,ppOVar5);
      }
      else if (cVar1 < '\x04') {
        FUN_801e39a0((int)this,(int)pOVar4,(int)ppOVar5);
      }
      objRunAnimation((double)(float)ppOVar5[2],(double)timeDelta,(int)this,(float *)0x0);
    }
    else {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
      mainSetBits(0x914,1);
    }
  }
  return;
}


/* @description Override render */

void magicPlant_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //801E3078
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int *piVar1;
  
  piVar1 = (int *)this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((*piVar1 != 0) && (*(int *)(*piVar1 + 0xc4) != 0)) {
      objGetAttachPointWorldPos
                (this,0,(float *)(*piVar1 + 0xc),(float *)(*piVar1 + 0x10),(float *)(*piVar1 + 0x14)
                 ,FALSE);
    }
  }
  return;
}


/* @description Free object instance */

void magicPlant_free(ObjInstance *this,int param2) { //801E3124
  ObjInstance **ppOVar1;
  
  ppOVar1 = (ObjInstance **)this->state;
  Object_removePlayerObj(this,0x36);
  Object_removePlayerObj(this,0x40);
  if (*ppOVar1 != (ObjInstance *)0x0) {
    if (param2 == 0) {
      Object_objFreeObject(*ppOVar1);
    }
    Object_objRemoveChild(this,*ppOVar1);
  }
  return;
}


/* Library Function - Single Match
    magicPlant_func08
   
   Library: KioskDefault 0 0 */

uint magicPlant_func08(ObjInstance *this) { //801E3198
  return (uint)this->def[1].loadFlags << 0xb | 0x400;
}


/* @description Get extra size for object (size of State struct) */

int magicPlant_getExtraSize(void) { //801E31BC
  return 0x10;
}

