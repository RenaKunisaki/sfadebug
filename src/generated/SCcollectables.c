
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCcollectables_initialise(undefined4 param) { //8025B0CC
  return;
}


/* @description Called when DLL is unloaded */

void SCcollectables_release(void) { //8025B0D0
  return;
}


/* Library Function - Single Match
    dll_1F9_func03
   
   Library: KioskDefault 0 0 */

void SCcollectables_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8025B0D4
  uint uVar1;
  AButtonInteraction *pAVar2;
  ObjSeqCmd *pOVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  Object_objAddObjectType(this,5);
  objAllocMsgQueue(this,2);
  (this->pos).rotation.x = (ushort)objDef[1].mapStates1 << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].pos.x + 2) << 8;
  (this->pos).rotation.z = (ushort)*(byte *)((int)&objDef[1].pos.x + 3) << 8;
  (this->pos).scale = this->data->scale;
  this->curModel = *(byte *)((int)&objDef[1].pos.y + 2);
  (this->vel).y = 0.0;
  if (this->hitstate != (HitState *)0x0) {
    this->hitstate->field16_0x52 = (ushort)objDef[1].allocatedSize;
  }
  *(undefined2 *)(puVar4 + 10) = *(undefined2 *)&objDef[1].id;
  puVar4[0xf] = 0x3c;
  *(undefined2 *)(puVar4 + 0xc) = *(undefined2 *)&objDef[1].pos.y;
  if (*(short *)(puVar4 + 0xc) == -1) {
    FUN_8025b674(this,'\x01');
  }
  else {
    uVar1 = mainGetBit((int)*(short *)(puVar4 + 0xc));
    if (uVar1 != 0) {
      FUN_8025b674(this,'\x01');
    }
  }
  *(undefined2 *)(puVar4 + 8) = *(undefined2 *)&objDef[1].loadFlags;
  if (*(short *)(puVar4 + 8) == -1) {
    this->field76_0xf4 = 0;
  }
  else {
    uVar1 = mainGetBit((int)*(short *)(puVar4 + 8));
    this->field76_0xf4 = uVar1;
  }
  if (this->field76_0xf4 == 0) {
    pOVar3 = this->data->offset_0x18;
    if (pOVar3 == (ObjSeqCmd *)0x0) {
      *(float *)(puVar4 + 4) = 50.0;
    }
    else {
      *(float *)(puVar4 + 4) =
           (float)((double)CONCAT44(0x43300000,(int)(char)pOVar3[2].flags ^ 0x80000000) -
                  4503601774854144.0);
    }
    pAVar2 = this->data->aButtonInteraction;
    if (pAVar2 != (AButtonInteraction *)0x0) {
      *(float *)(puVar4 + 4) =
           (float)((double)CONCAT44(0x43300000,(uint)(byte)pAVar2->field_0xc << 2 ^ 0x80000000) -
                  4503601774854144.0);
    }
    if (this->shadow != (Shadow *)0x0) {
      this->shadow->flags = this->shadow->flags | 0x810;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1F9_func04
   
   Library: KioskDefault 0 0 */

void SCcollectables_update(ObjInstance *this) { //8025B2A0
  uint uVar1;
  int iVar2;
  ObjInstance *param2;
  float *pfVar3;
  double in_f1;
  undefined *local_34;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  int aiStack_24 [2];
  
  pfVar3 = (float *)this->state;
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  if ((*(short *)(pfVar3 + 3) != -1) &&
     (uVar1 = mainGetBit((int)*(short *)(pfVar3 + 3)), uVar1 != 0)) {
    *(byte *)((int)pfVar3 + 0xe) = *(byte *)((int)pfVar3 + 0xe) | 1;
  }
  *(u8 *)((int)pfVar3 + 0xf) = *(char *)((int)pfVar3 + 0xf) - framesThisStep;
  if (*(char *)((int)pfVar3 + 0xf) < '\0') {
    *(undefined *)((int)pfVar3 + 0xf) = 0;
  }
  while (iVar2 = FUN_80091100((int)this,(uint *)&local_34,&uStack_2c,(uint *)0x0), iVar2 != 0) {
    if (local_34 == &DAT_0007000b) {
      in_f1 = (double)FUN_8025b8b8((int)this);
    }
  }
  if (((this->pos).flags & Invisible) == 0) {
    if (this->field76_0xf4 == 0) {
      if ((*(byte *)((int)pfVar3 + 0xe) & 2) == 0) {
        this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      }
      else {
        this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      }
      if (((*(byte *)((int)pfVar3 + 0xe) & 1) != 0) && ((*(byte *)((int)pfVar3 + 0xe) & 2) == 0)) {
        in_f1 = (double)FUN_8025b674(this,'\0');
      }
      param2 = Object_objGetMain();
      if (param2 != (ObjInstance *)0x0) {
        if (this->data->offset_0x18 == (ObjSeqCmd *)0x0) {
          return;
        }
        objDistObj2Obj(this,param2);
        if (((in_f1 < (double)pfVar3[1]) && (*(char *)((int)pfVar3 + 0xf) == '\0')) &&
           ((this->flags_0xaf & CanPressAToTalk) != 0)) {
          *(undefined2 *)(pfVar3 + 4) = 0xffff;
          *(undefined2 *)((int)pfVar3 + 0x12) = 0;
          pfVar3[5] = 1.0;
          objSendMsg((int)param2,0x7000a,(uint)this,(uint)(pfVar3 + 4));
        }
        *pfVar3 = (float)in_f1;
      }
      iVar2 = FUN_800883e4((int)this,&uStack_30,aiStack_24,&uStack_28);
      if (iVar2 != 0) {
        for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
                    /* {@symbol 800ed30c} */
          (**(code **)(*(int *)pDll_objfsa + 8))(this,0x424,0,2,0xffffffff,0);
        }
        audioTryStartSfx((int *)this,1,0x33,0x7f,"SCcollectables.c",0xda);
      }
    }
    else {
      if (this->hitstate != (HitState *)0x0) {
        this->hitstate->flags = this->hitstate->flags | 0x100;
      }
      if ((*(short *)(pfVar3 + 2) != -1) &&
         (uVar1 = mainGetBit((int)*(short *)(pfVar3 + 2)), uVar1 == 0)) {
        this->field76_0xf4 = 0;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void SCcollectables_hitDetect(ObjInstance *this) { //8025B524
  return;
}


/* Library Function - Single Match
    dll_1F9_func06
   
   Library: KioskDefault 0 0 */

void SCcollectables_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8025B528
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  float *pfVar2;
  
  pfVar2 = (float *)this->state;
  if (((('\0' < shouldRender) && (this->field76_0xf4 == 0)) &&
      (objRenderCurrentModel
                 (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                  (undefined4 *)CONCAT31(in_register_00000014,param3),
                  (undefined4 *)CONCAT31(in_register_00000018,param4),
                  (undefined4 *)CONCAT31(in_register_0000001c,param5)),
      this->data->offset_0x18 != (ObjSeqCmd *)0x0)) &&
     ((this->romdefno == 0x27f && (*pfVar2 < 250.0)))) {
    iVar1 = randInt(0,10);
    if (iVar1 == 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x423,0,2,0xffffffff,0);
    }
    (this->pos).rotation.x = (this->pos).rotation.x + (short)(int)(timeDelta * 182.0);
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1AD_func07
    dll_1F9_func07
   
   Library: KioskDefault 0 0 */

void SCcollectables_free(ObjInstance *this,int param2) { //8025B638
  Object_removePlayerObj(this,5);
  return;
}


undefined4 SCcollectables_func08(ObjInstance *this) { //8025B664
  return 0x10;
}


/* @description Get extra size for object (size of State struct) */

int SCcollectables_getExtraSize(void) { //8025B66C
  return 0x18;
}


void SCcollectables_setScale(ObjInstance *this,float scale) { //8025B948
  this->state[0xe] = this->state[0xe] | 1;
  return;
}


/* Library Function - Single Match
    dll_1F9_func0B
   
   Library: KioskDefault 0 0 */

void SCcollectables_func0B(int param1,int param2) { //8025B96C
  *(undefined4 *)(param1 + 0xc) = *(undefined4 *)(param2 + 0xc);
  *(undefined4 *)(param1 + 0x10) = *(undefined4 *)(param2 + 0x10);
  *(undefined4 *)(param1 + 0x14) = *(undefined4 *)(param2 + 0x14);
  *(undefined4 *)(param1 + 0x18) = *(undefined4 *)(param2 + 0x18);
  *(undefined4 *)(param1 + 0x1c) = *(undefined4 *)(param2 + 0x1c);
  *(undefined4 *)(param1 + 0x20) = *(undefined4 *)(param2 + 0x20);
  return;
}

