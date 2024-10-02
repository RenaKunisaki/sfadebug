
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WCbeacon_initialise(undefined4 param) { //802C3054
  return;
}


/* @description Called when DLL is unloaded */

void WCbeacon_release(void) { //802C3058
  return;
}


/* Library Function - Single Match
    dll_2D8_func03
   
   Library: KioskDefault 0 0 */

void WCbeacon_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802C305C
  short sVar1;
  short sVar2;
  char cVar5;
  uint uVar3;
  undefined4 *puVar4;
  undefined *puVar6;
  
  puVar6 = this->state;
                    /* {@symbol 8012dfa8} */
  cVar5 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  if (cVar5 == '\x02') {
    mainSetBits((int)*(short *)&objDef[1].pos.x,1);
    sVar1._0_1_ = objDef[1].bound;
    sVar1._1_1_ = objDef[1].cullDist;
    mainSetBits((int)sVar1,1);
  }
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  this->curModel = *(byte *)((int)&objDef[1].objType + 1);
  if (this->data->nModels <= (char)this->curModel) {
    this->curModel = 0;
  }
  uVar3 = mainGetBit((int)*(short *)&objDef[1].pos.x);
  if (uVar3 != 0) {
    sVar2._0_1_ = objDef[1].bound;
    sVar2._1_1_ = objDef[1].cullDist;
    uVar3 = mainGetBit((int)sVar2);
    if (uVar3 == 0) {
      puVar6[4] = 1;
    }
    else {
      puVar6[4] = 3;
    }
  }
  puVar4 = (undefined4 *)FUN_80094400((int)this,0);
  if ((puVar4 != (undefined4 *)0x0) && (puVar6[4] == '\x03')) {
    *puVar4 = 0x100;
  }
  return;
}


/* Library Function - Single Match
    dll_2D8_func04
   
   Library: KioskDefault 0 0 */

void WCbeacon_update(ObjInstance *this) { //802C3170
  float fVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  short sVar6;
  ObjDef *pOVar7;
  float *pfVar8;
  
  pOVar7 = this->def;
  pfVar8 = (float *)this->state;
  if (*(char *)(pfVar8 + 1) == '\x01') {
    uVar2 = mainGetBit((int)*(short *)&pOVar7[1].pos.x);
    if (uVar2 == 0) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
      *(undefined *)(pfVar8 + 1) = 0;
    }
    iVar3 = FUN_800883e4((int)this,(undefined4 *)0x0,(int *)0x0,(uint *)0x0);
    if (iVar3 != 0) {
      audioTryStartSfx((int *)this,1,0x6e,0x7f,"WCbeacon.c",0x7f);
      audioTryStartSfx((int *)this,2,0x7a,0x7f,"WCbeacon.c",0x80);
      *(undefined *)(pfVar8 + 1) = 2;
      *pfVar8 = 0.0;
    }
  }
  else if (*(char *)(pfVar8 + 1) == '\0') {
    uVar2 = mainGetBit((int)*(short *)&pOVar7[1].pos.x);
    if (uVar2 != 0) {
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
      *(undefined *)(pfVar8 + 1) = 1;
    }
  }
  else if (*(char *)(pfVar8 + 1) == '\x02') {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x73a,0,2,0xffffffff,0);
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x73b,0,2,0xffffffff,0);
    fVar1 = *pfVar8 + timeDelta;
    *pfVar8 = fVar1;
    if (90.0 <= fVar1) {
      *(undefined *)(pfVar8 + 1) = 3;
    }
    sVar6 = (short)(int)((*pfVar8 / 45.0) * 256.0);
    if (0x100 < sVar6) {
      sVar6 = 0x100;
    }
    piVar4 = (int *)FUN_80094400((int)this,0);
    if (piVar4 != (int *)0x0) {
      *piVar4 = (int)sVar6;
    }
  }
  else if (*(char *)(pfVar8 + 1) == '\x03') {
                    /* {@symbol 800ed30c} */
    (**(code **)(*(int *)pDll_objfsa + 8))(this,0x73a,0,2,0xffffffff,0);
    sVar6._0_1_ = pOVar7[1].bound;
    sVar6._1_1_ = pOVar7[1].cullDist;
    mainSetBits((int)sVar6,1);
    puVar5 = (undefined4 *)FUN_80094400((int)this,0);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = 0x100;
    }
    if (this->field76_0xf4 == 0) {
                    /* {@symbol 800d0a70} */
      (**(code **)(*(int *)pDll_checkpoint + 0x54))(this,0x69);
                    /* {@symbol 800d022c} */
      (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,1);
    }
  }
  this->field76_0xf4 = 1;
  return;
}


/* @description Override hit detection */

void WCbeacon_hitDetect(ObjInstance *this) { //802C3440
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void WCbeacon_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802C3444
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

void WCbeacon_free(ObjInstance *this,int param2) { //802C34A0
  return;
}


undefined4 WCbeacon_func08(ObjInstance *this) { //802C34A4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WCbeacon_getExtraSize(void) { //802C34AC
  return 8;
}

