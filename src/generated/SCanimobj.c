
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCanimobj_initialise(undefined4 param) { //8025B9A0
  return;
}


/* @description Called when DLL is unloaded */

void SCanimobj_release(void) { //8025B9A4
  return;
}


/* Library Function - Single Match
    dll_1FA_func03
   
   Library: KioskDefault 0 0 */

void SCanimobj_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8025B9A8
  undefined *puVar1;
  
  Object_setPriority(this,100);
  puVar1 = this->state;
  *(undefined2 *)(puVar1 + 0x62) = *(undefined2 *)&objDef[1].allocatedSize;
  *(undefined2 *)(puVar1 + 0x66) = 0xffff;
  *(float *)(puVar1 + 0x24) =
       1.0 / ((float)((double)CONCAT44(0x43300000,(uint)*(byte *)&objDef[1].pos.y) -
                     4503599627370496.0) + 1.0);
  *(undefined4 *)(puVar1 + 0x28) = 0xffffffff;
  this->flags_0xf8 = 0;
  if ((this->field76_0xf4 == 0) && (objDef[1].objType != 1)) {
                    /* {@symbol 800cf6cc} */
    (**(code **)(*(int *)pDll_checkpoint + 0x1c))(puVar1,objDef);
    this->field76_0xf4 = (short)objDef[1].objType + 1;
  }
  else if ((this->field76_0xf4 != 0) && ((int)(short)objDef[1].objType != this->field76_0xf4 + -1))
  {
                    /* {@symbol 800cf980} */
    (**(code **)(*(int *)pDll_checkpoint + 0x24))(puVar1);
    if (objDef[1].objType != None) {
                    /* {@symbol 800cf6cc} */
      (**(code **)(*(int *)pDll_checkpoint + 0x1c))(puVar1,objDef);
    }
    this->field76_0xf4 = (short)objDef[1].objType + 1;
  }
  if (this->shadow != (Shadow *)0x0) {
    (this->shadow->color).b = 100;
    (this->shadow->color).a = 0x96;
  }
  return;
}


/* Library Function - Single Match
    dll_1FA_func04
   
   Library: KioskDefault 0 0 */

void SCanimobj_update(ObjInstance *this) { //8025BB08
  char cVar1;
  byte bVar2;
  int iVar3;
  ObjInstance **ppOVar4;
  ObjInstance *pOVar5;
  undefined *puVar6;
  ObjInstance *pOVar7;
  int local_34;
  int local_30 [3];
  
  puVar6 = this->state;
  if ((this->def != (ObjDef *)0x0) && (this->def[1].objType != None)) {
                    /* {@symbol 800c8b14} */
    local_30[0] = (**(code **)(*(int *)pDll_checkpoint + 0x14))(this,framesLastStep);
    if ((local_30[0] != 0) && ((iVar3 = isModelAnimDisabled(), iVar3 == 0 && (this->curSeq == -2))))
    {
      cVar1 = puVar6[0x4f];
      pOVar5 = (ObjInstance *)0x0;
      ppOVar4 = Object_getObjects(local_30,&local_34);
      iVar3 = 0;
      for (local_30[0] = 0; local_30[0] < local_34; local_30[0] = local_30[0] + 1) {
        pOVar7 = ppOVar4[local_30[0]];
        if (pOVar7->curSeq == (short)cVar1) {
          pOVar5 = pOVar7;
        }
        if (((pOVar7->curSeq == -2) && (pOVar7->objId == 0x10)) &&
           (puVar6 = pOVar7->state, (int)(short)cVar1 == (int)(char)puVar6[0x4f])) {
          iVar3 = iVar3 + 1;
        }
      }
      if (((iVar3 < 2) && (pOVar5 != (ObjInstance *)0x0)) && (pOVar5->curSeq != -1)) {
        pOVar5->curSeq = -1;
                    /* {@symbol 800d0958} */
        (**(code **)(*(int *)pDll_checkpoint + 0x4c))((int)(short)cVar1);
      }
      this->curSeq = -1;
    }
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)puVar6[0x84]; iVar3 = iVar3 + 1) {
      bVar2 = puVar6[iVar3 + 0x7a];
      if (bVar2 == 2) {
        this->flags_0xf8 = this->flags_0xf8 | 2;
      }
      else if (bVar2 < 2) {
        if (bVar2 == 0) {
          this->flags_0xf8 = this->flags_0xf8 | 1;
        }
        else if (true) {
          this->flags_0xf8 = this->flags_0xf8 & 0xfffffffe;
        }
      }
      else if (bVar2 == 4) {
        this->flags_0xf8 = this->flags_0xf8 | 4;
      }
      else if (bVar2 < 4) {
        this->flags_0xf8 = this->flags_0xf8 & 0xfffffffd;
      }
    }
  }
  return;
}


/* @description Override hit detection */

void SCanimobj_hitDetect(ObjInstance *this) { //8025BD08
  return;
}


/* Library Function - Single Match
    dll_1FA_func06
   
   Library: KioskDefault 0 0 */

void SCanimobj_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8025BD0C
  uint uVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  int iVar2;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if ((this->flags_0xf8 & 7) != 0) {
      objGetAttachPointWorldPos(this,0,&FLOAT_80396394,&FLOAT_80396398,&FLOAT_8039639c,FALSE);
    }
    if ((this->flags_0xf8 & 1) != 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x425,&DAT_80396388,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x425,&DAT_80396388,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x425,&DAT_80396388,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x426,&DAT_80396388,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x426,&DAT_80396388,&DAT_00200001,0xffffffff,0);
    }
    if ((this->flags_0xf8 & 2) != 0) {
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x427,&DAT_80396388,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x427,&DAT_80396388,&DAT_00200001,0xffffffff,0);
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))(this,0x427,&DAT_80396388,&DAT_00200001,0xffffffff,0);
    }
    if ((this->flags_0xf8 & 4) != 0) {
      for (iVar2 = 0; iVar2 < 0x14; iVar2 = iVar2 + 1) {
                    /* {@symbol 800ed30c} */
        (**(code **)(*(int *)pDll_objfsa + 8))(this,0x427,&DAT_80396388,&DAT_00200001,0xffffffff,0);
      }
      for (iVar2 = 0; iVar2 < 7; iVar2 = iVar2 + 1) {
        uVar1 = randInt(-0x32,0x32);
        FLOAT_80396394 =
             FLOAT_80396394 +
             (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0) / 10.0;
        uVar1 = randInt(-0x32,0x32);
        FLOAT_8039639c =
             FLOAT_8039639c +
             (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0) / 10.0;
                    /* {@symbol 800dac04} */
        (**(code **)(*(int *)pDll_TrickyWalk + 0x10))
                  ((double)FLOAT_80396394,(double)(this->pos).pos.y,(double)FLOAT_8039639c,
                   0x4010000000000000);
                    /* {@symbol 800db230} */
        (**(code **)(*(int *)pDll_TrickyWalk + 0x14))
                  ((double)FLOAT_80396394,(double)(this->pos).pos.y,(double)FLOAT_8039639c,0,0,3);
      }
      audioSfxFn_800688bc((double)FLOAT_80396394,(double)(this->pos).pos.y,(double)FLOAT_8039639c,
                          0x3d8,0x7f,"SCanimobj.c",(int *)0xe5);
      this->flags_0xf8 = this->flags_0xf8 & 0xfffffffb;
    }
  }
  return;
}


/* Library Function - Single Match
    dll_1FA_func07
   
   Library: KioskDefault 0 0 */

void SCanimobj_free(ObjInstance *this,int param2) { //8025C098
                    /* {@symbol 800cf980} */
  (**(code **)(*(int *)pDll_checkpoint + 0x24))(this->state);
                    /* {@symbol 8011bc6c} */
  (**(code **)(*(int *)pDll05_2 + 8))(this,0xffff,"SCanimobj.c",0xf3,"-1");
  return;
}


undefined4 SCanimobj_func08(ObjInstance *this) { //8025C10C
  return 0xb;
}


/* @description Get extra size for object (size of State struct) */

int SCanimobj_getExtraSize(void) { //8025C114
  return 0x130;
}

