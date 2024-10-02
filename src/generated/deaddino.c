
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void deaddino_initialise(undefined4 param) { //8027F0F0
  return;
}


/* @description Called when DLL is unloaded */

void deaddino_release(void) { //8027F0F4
  return;
}


/* Library Function - Single Match
    dll_23D_func03
   
   Library: KioskDefault 0 0 */

void deaddino_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //8027F0F8
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  objAllocMsgQueue(this,4);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8027f6cc;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  (this->pos).rotation.y = *(short *)&objDef[1].loadFlags;
  uVar1 = mainGetBit(0xbd);
  if (uVar1 != 0) {
    this->hitstate->flags = this->hitstate->flags & 0xfffe;
    puVar2[0xd] = 1;
  }
  *(float *)(puVar2 + 4) = 0.0;
  return;
}


/* Library Function - Single Match
    dll_23D_func04
   
   Library: KioskDefault 0 0 */

void deaddino_update(ObjInstance *this) { //8027F18C
  char cVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  ObjInstance *param2;
  int *piVar6;
  int *piVar7;
  word unaff_r28;
  ObjDef *pOVar8;
  float *param5;
  double in_f31;
  float local_3c;
  uint auStack_38 [3];
  
  pOVar8 = this->def;
  param5 = (float *)this->state;
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  if (((this->flags_0xaf & FieldB8TimeCanBeNegative) == 0) ||
     (uVar4 = mainGetBit(0x915), uVar4 != 0)) {
    if (*(char *)((int)param5 + 0xd) == '\0') {
      uVar4 = objHitReactFn_80089890
                        (this,-0x7fce2e70,0x1c,(uint)((*(byte *)((int)param5 + 0xe) & 1) != 0),
                         param5);
      if ((uVar4 & 0xff) == 0) {
        *(byte *)((int)param5 + 0xe) = *(byte *)((int)param5 + 0xe) & 0xfe;
        do {
          iVar5 = FUN_80091100((int)this,auStack_38,(uint *)0x0,(uint *)0x0);
        } while (iVar5 != 0);
        bVar3 = true;
        uVar4 = mainGetBit(0xbd);
        if (uVar4 == 0) {
          if (*(char *)((int)&pOVar8[1].objType + 1) == '\0') {
            uVar2._0_1_ = pOVar8[1].allocatedSize;
            uVar2._1_1_ = pOVar8[1].mapStates1;
            unaff_r28 = uVar2 | 0x100;
            in_f31 = 0.0;
          }
          else {
            this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
            in_f31 = 0.004999999888241291;
            param2 = Object_objGetMain();
            if (param2 != (ObjInstance *)0x0) {
              objDistFn_80091a84((int)this,(int)param2,&local_3c);
              if (*(char *)(param5 + 4) == '\x01') {
                if ((140.0 < local_3c) || (*(short *)((int)param5 + 10) < 1)) {
                  *(undefined *)(param5 + 4) = 0;
                }
                *(ushort *)((int)param5 + 10) =
                     *(short *)((int)param5 + 10) - (ushort)framesThisStep;
                if ((this->flags_0xaf & CanPressAToTalk) != 0) {
                    /* {@symbol 800d022c} */
                  (**(code **)(*(int *)pDll_checkpoint + 0x48))(1,this,0xffffffff);
                  *(undefined *)(param5 + 4) = 2;
                  disableButtons(0,PAD_BUTTON_A);
                }
              }
              else if (*(char *)(param5 + 4) == '\0') {
                if (local_3c < 120.0) {
                  *(undefined *)(param5 + 4) = 1;
                  iVar5 = randInt(400,600);
                  *(short *)((int)param5 + 10) = (short)iVar5;
                }
              }
              else {
                in_f31 = 0.0;
              }
            }
            unaff_r28 = 0x102;
          }
        }
        else if ((param5[1] == 0.0) && (uVar4 = mainGetBit(0xbd), uVar4 != 0)) {
          param5[1] = 1.0;
          audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                              (double)(this->prevPos).z,0x207,0x7f,"deaddino.c",(int *)0xc9
                             );
          bVar3 = false;
        }
        if ((bVar3) && (*(char *)((int)param5 + 0xd) == '\0')) {
          if (this->animId != unaff_r28) {
            Object_ObjAnimSetMove(0.0,this,(int)(short)unaff_r28,0);
          }
          objRunAnimation(in_f31,(double)timeDelta,(int)this,(float *)0x0);
        }
        if (param5[1] != 0.0) {
          cVar1 = *(char *)((int)param5 + 0xf);
          if ((*(char *)((int)&pOVar8[1].objType + 1) == '\0') || (1 < *(byte *)(param5 + 4))) {
            *(undefined *)((int)param5 + 0xf) = 1;
          }
          else {
            *(ushort *)(param5 + 2) = *(short *)(param5 + 2) - (ushort)framesThisStep;
            if (*(short *)(param5 + 2) < 0) {
              if (*(char *)((int)param5 + 0xf) == '\0') {
                *(undefined *)((int)param5 + 0xf) = 1;
                *(undefined2 *)(param5 + 2) = 10;
              }
              else {
                *(undefined *)((int)param5 + 0xf) = 0;
                iVar5 = randInt(0x3c,300);
                *(short *)(param5 + 2) = (short)iVar5;
              }
            }
          }
          if (*(char *)((int)param5 + 0xf) != cVar1) {
            piVar6 = (int *)FUN_80094400((int)this,5);
            piVar7 = (int *)FUN_80094400((int)this,4);
            if ((piVar6 != (int *)0x0) && (piVar7 != (int *)0x0)) {
              *piVar6 = (uint)*(byte *)((int)param5 + 0xf) << 8;
              *piVar7 = (uint)*(byte *)((int)param5 + 0xf) << 8;
            }
          }
        }
      }
      else {
        *(byte *)((int)param5 + 0xe) = *(byte *)((int)param5 + 0xe) | 1;
      }
    }
    else {
      this->hitstate->flags = this->hitstate->flags & 0xfffe;
    }
  }
  else {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(2,this,0xffffffff);
    mainSetBits(0x915,1);
  }
  return;
}


/* @description Override hit detection */

void deaddino_hitDetect(ObjInstance *this) { //8027F56C
  return;
}


/* Library Function - Single Match
    dll_23D_func06
   
   Library: KioskDefault 0 0 */

void deaddino_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //8027F570
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar1;
  
  puVar1 = this->state;
  if (((shouldRender) && (puVar1[0xd] == '\0')) &&
     (objRenderCurrentModel
                (this,(Gfx **)CONCAT31(in_register_00000010,param2),
                 (undefined4 *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5)), *(float *)(puVar1 + 4) != 0.0
     )) {
    if (*(float *)(puVar1 + 4) < 1.8) {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x32f,puVar1 + 4);
    }
    else {
                    /* {@symbol 800ea278} */
      (**(code **)(*(int *)pDll_baddieControl + 0xc))(this,0x330,0);
    }
    *(float *)(puVar1 + 4) = timeDelta * 0.01 + *(float *)(puVar1 + 4);
    if (2.0 <= *(float *)(puVar1 + 4)) {
      audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                          (double)(this->prevPos).z,0x86,0x7f,"deaddino.c",(int *)0x108);
      puVar1[0xd] = 1;
      *(float *)(puVar1 + 4) = 0.0;
      FUN_8027f780((int)this);
    }
  }
  return;
}


/* @description Free object instance */

void deaddino_free(ObjInstance *this,int param2) { //8027F6B8
  return;
}


undefined4 deaddino_func08(ObjInstance *this) { //8027F6BC
  return 1;
}


/* @description Get extra size for object (size of State struct) */

int deaddino_getExtraSize(void) { //8027F6C4
  return 0x14;
}

