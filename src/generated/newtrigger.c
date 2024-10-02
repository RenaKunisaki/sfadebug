
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void trigger_initialise(undefined4 param) { //801FDD40
  return;
}


/* @description Called when DLL is unloaded */

void trigger_release(void) { //801FDD44
  return;
}


/* Library Function - Single Match
    trigger_func03
   
   Library: KioskDefault 0 0 */

void trigger_init(ObjInstance *this,ObjDef_Trigger *def,int param3,DllInitFlags flags,float x,
                  float y,float z) { //801FDD48
  ObjDefEnum OVar1;
  uint uVar2;
  DLL *pDVar3;
  ObjSeqCmd *pOVar4;
  ObjState_Trigger *state;
  int iVar5;
  
  Object_objAddObjectType(this,2);
  Object_setPriority(this,0x28);
  state = (ObjState_Trigger *)this->state;
  OVar1 = (def->def).objType;
  if (OVar1 == TrigBits) {
                    /* TrigBits */
    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
      (&state->field25_0x5a)[iVar5] = *(GameBit16 *)((int)(def->seq + 0xc) + iVar5 * 2);
    }
    goto LAB_801fde70;
  }
  if ((short)OVar1 < 0x54) {
    if (OVar1 == TrigArea) {
      trigAreaInit(this,def);
      goto LAB_801fde70;
    }
    if ((short)OVar1 < 0x4d) {
      if (OVar1 == TrigPnt) {
        trigPntInit(this,def);
        goto LAB_801fde70;
      }
      if (0x4a < (short)OVar1) {
        state->field25_0x5a = def->trigBits1;
        trigPlnInit(this,def);
        goto LAB_801fde70;
      }
    }
    else if ((short)OVar1 < 0x51) goto LAB_801fde70;
  }
  else {
    if (OVar1 == TrigCyl) {
      trigCylInit(this,def);
      goto LAB_801fde70;
    }
    if (((short)OVar1 < 0x230) && (OVar1 == TrigCrve)) {
      trigCrveInit(this,def);
      goto LAB_801fde70;
    }
  }
  printf("triggers: unknown trigger object %d.",(int)(short)this->data->objId);
LAB_801fde70:
  state->bitActivate = def->bitActivate;
  uVar2 = mainGetBit((int)(short)state->bitActivate);
  pOVar4 = def->seq;
  for (iVar5 = 0; iVar5 < 8; iVar5 = iVar5 + 1) {
    (&state->subscriptDlls)[iVar5] = (DLL *)0x0;
    if (pOVar4->cmd == 0x19) {
      uVar2 = pOVar4->param1 + 0x4d;
      if (uVar2 < 0x50) {
        if (param3 == 0) {
          pDVar3 = (DLL *)runlinkDownloadCode((ushort)uVar2,0);
          (&state->subscriptDlls)[iVar5] = pDVar3;
        }
      }
      else {
        printf("TRIGGER: warning Script overflow");
      }
    }
    pOVar4 = pOVar4 + 1;
  }
  if (uVar2 == 1) {
    state->field0_0x0 = state->field0_0x0 | 4;
  }
  state->field0_0x0 = state->field0_0x0 | 0x40;
  return;
}


/* Library Function - Single Match
    trigger_func04
   
   Library: KioskDefault 0 0 */

void trigger_update(ObjInstance *this) { //801FDF38
  byte bVar1;
  ObjDefEnum OVar2;
  bool bVar3;
  ObjInstance *player;
  ObjInstance *tricky;
  uint uVar4;
  int iVar5;
  ObjDef *seq;
  ObjInstance *unaff_r30;
  ObjState_Trigger *state;
  float distance;
  bool haveObj;
  
  state = (ObjState_Trigger *)this->state;
  seq = this->def;
  distance = 200.0;
  player = Object_objGetMain();
  if ((player != (ObjInstance *)0x0) &&
     (tricky = playerGetRidingObj(player), tricky != (ObjInstance *)0x0)) {
    player = tricky;
  }
  tricky = Object_getSidekicksLoaded();
  if ((player != (ObjInstance *)0x0) || (tricky != (ObjInstance *)0x0)) {
    if ((state->field0_0x0 & 4) == 0) {
      haveObj = true;
      if (*(byte *)((int)&seq[2].pos.z + 3) < 3) {
        bVar1 = *(byte *)((int)&seq[2].pos.z + 3);
        if (bVar1 == 1) {
          unaff_r30 = tricky;
          if (tricky == (ObjInstance *)0x0) {
            haveObj = false;
          }
        }
        else if (bVar1 == 0) {
          if ((true) && (unaff_r30 = player, player == (ObjInstance *)0x0)) {
            haveObj = false;
          }
        }
        else if (bVar1 < 3) {
                    /* {@symbol 80153970} */
          unaff_r30 = (ObjInstance *)(**(code **)(*(int *)pDll_ObjSeq + 0xc))();
        }
      }
      else {
        unaff_r30 = getSeqObj((uint)*(byte *)((int)&seq[2].pos.z + 3),this,&distance);
        if (unaff_r30 == (ObjInstance *)0x0) {
          haveObj = false;
        }
      }
      if (haveObj) {
        if ((state->field0_0x0 & 0x40) == 0) {
          (state->objPos).x = (state->field13_0x2c).x;
          (state->objPos).y = (state->field13_0x2c).y;
          (state->objPos).z = (state->field13_0x2c).z;
        }
        else {
          bVar1 = *(byte *)((int)&seq[2].pos.z + 3);
          if (bVar1 == 2) {
            (state->objPos).x = (unaff_r30->pos).pos.x;
            (state->objPos).y = (unaff_r30->pos).pos.y;
            (state->objPos).z = (unaff_r30->pos).pos.z;
          }
          else if ((1 < bVar1) || (false)) {
            (state->objPos).x = (unaff_r30->oldPos).x;
            (state->objPos).y = (unaff_r30->oldPos).y;
            (state->objPos).z = (unaff_r30->oldPos).z;
          }
          else {
            (state->objPos).x = (unaff_r30->pos_0x8c).x;
            (state->objPos).y = (unaff_r30->pos_0x8c).y;
            (state->objPos).z = (unaff_r30->pos_0x8c).z;
          }
          state->field0_0x0 = state->field0_0x0 & 0xbf;
        }
        bVar1 = *(byte *)((int)&seq[2].pos.z + 3);
        if (((bVar1 == 2) || (1 < bVar1)) || (false)) {
          (state->field13_0x2c).x = (unaff_r30->pos).pos.x;
          (state->field13_0x2c).y = (unaff_r30->pos).pos.y;
          (state->field13_0x2c).z = (unaff_r30->pos).pos.z;
        }
        else {
          (state->field13_0x2c).x = (unaff_r30->prevPos).x;
          (state->field13_0x2c).y = (unaff_r30->prevPos).y;
          (state->field13_0x2c).z = (unaff_r30->prevPos).z;
        }
      }
      OVar2 = seq->objType;
      if (OVar2 == TriggSetp) {
        objInterpretSeq(this,player,'\x01',0);
        iVar5 = ret0_800794DC();
        if (iVar5 != 0) {
          Object_objFreeObject(this);
        }
      }
      else if ((short)OVar2 < 0x50) {
        if (OVar2 == TrigArea) {
          if (haveObj) {
            trigArea_run(this,unaff_r30);
          }
        }
        else if ((short)OVar2 < 0x4d) {
          if (OVar2 == TrigPnt) {
            if (haveObj) {
              trigPnt_checkTrigger(this,unaff_r30);
            }
          }
          else if (0x4a < (short)OVar2) {
            bVar3 = true;
            if ((-1 < (short)state->field25_0x5a) &&
               (uVar4 = mainGetBit((int)(short)state->field25_0x5a), uVar4 == 0)) {
              bVar3 = false;
            }
            if ((seq->id == 0x323a9) || (seq->id == 0x418c7)) {
              triggerFn_80200074(this,unaff_r30);
            }
            else if ((bVar3) && (haveObj)) {
              triggerFn_80200074(this,unaff_r30);
            }
          }
        }
        else if (((short)OVar2 < 0x4f) &&
                (state->field9_0xc = state->field9_0xc + (uint)framesThisStep,
                (uint)*(ushort *)((int)&seq[2].id + 2) <= state->field9_0xc)) {
          objInterpretSeq(this,(ObjInstance *)0x0,'\x01',0);
        }
      }
      else if (OVar2 == TrigCrve) {
        if (haveObj) {
          trigCurve_checkTrigger(this,unaff_r30);
        }
      }
      else if ((short)OVar2 < 0xf4) {
        if (OVar2 == TrigBits) {
          haveObj = true;
          iVar5 = 0;
          while ((iVar5 < 4 && (haveObj))) {
            if ((-1 < (short)(&state->field25_0x5a)[iVar5]) &&
               (uVar4 = mainGetBit((int)(short)(&state->field25_0x5a)[iVar5]), uVar4 == 0)) {
              haveObj = false;
            }
            iVar5 = iVar5 + 1;
          }
          if (haveObj) {
            objInterpretSeq(this,player,'\x01',0);
          }
        }
      }
      else if ((OVar2 == TrigCyl) && (haveObj)) {
        objSeqMoveFn_80199188(this,unaff_r30);
      }
    }
    else {
      objInterpretSeq(this,player,'\x01',0);
      state->field0_0x0 = state->field0_0x0 & 0xfb;
      state->field0_0x0 = state->field0_0x0 | 1;
    }
  }
  return;
}


/* @description Override hit detection */

void trigger_hitDetect(ObjInstance *this) { //801FE380
  return;
}


/* Library Function - Single Match
    trigger_func06
   
   Library: KioskDefault 0 0 */

void trigger_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //801FE384
  ObjDefEnum OVar1;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  int *param4_00;
  undefined3 in_register_0000001c;
  astruct_4 **param5_00;
  undefined4 *puVar2;
  ObjDef *pOVar3;
  undefined b;
  undefined g;
  undefined r;
  double in_f31;
  bool show;
  
  param5_00 = (astruct_4 **)CONCAT31(in_register_0000001c,param5);
  param4_00 = (int *)CONCAT31(in_register_00000018,param4);
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  pOVar3 = this->def;
  r = 0;
  g = 0;
  b = 0xff;
  show = false;
  puVar2 = (undefined4 *)param2_00->cmd;
  *puVar2 = 0xd9000000;
  puVar2[1] = &DAT_00210005;
  FUN_800a6a0c((int *)param2_00);
  if (pOVar3->objType == TrigPnt) {
    in_f31 = (double)(this->pos).scale;
    (this->pos).scale = 1.0;
  }
  DAT_80399ddc = DAT_80399ddc + (uint)framesThisStep;
  if (0x640 < DAT_80399ddc) {
    DAT_80399ddc = DAT_80399ddc + -0x640;
  }
  if (true) {
                    /* {@symbol 801fe530} */
    switch(*(undefined *)((int)&pOVar3[1].objType + (DAT_80399ddc / 200) * 4 + 1)) {
    case 3:
      r = 0xff;
      g = 0;
      b = 0;
      show = true;
      break;
    case 6:
      r = 0;
      g = 0xff;
      b = 0;
      show = true;
      break;
    case 10:
      r = 0;
      g = 0;
      b = 0;
      show = true;
      break;
    case 0xd:
      r = 0xff;
      g = 0xff;
      b = 0xff;
      show = true;
      break;
    case 0x11:
    case 0x1c:
    case 0x1d:
    case 0x26:
      r = 0xff;
      g = 0;
      b = 0xff;
      show = true;
      break;
    case 0x12:
    case 0x21:
      r = 0xff;
      g = 0xff;
      b = 0;
      show = true;
      break;
    case 0x13:
    case 0x14:
    case 0x1a:
    case 0x1b:
    case 0x22:
    case 0x27:
    case 0x28:
      r = 0;
      g = 0xff;
      b = 0xff;
      show = true;
      break;
    case 0x18:
    case 0x1e:
      r = 0xc4;
      g = 0xc4;
      b = 0xc4;
      show = true;
      break;
    case 0x1f:
      r = 0x40;
      g = 0xff;
      b = 0x80;
      show = true;
      break;
    case 0x23:
      r = 0xff;
      g = 0x80;
      b = 0x40;
      show = true;
    }
  }
  if (show) {
    FUN_80096b14(r,g,b,0xc4);
  }
  objRenderCurrentModel(this,(Gfx **)param2_00,param3_00,param4_00,param5_00);
  if (pOVar3->objType == TrigPnt) {
    (this->pos).scale = (float)in_f31;
  }
  if (((this->pos).flags & 0x100) != 0) {
    OVar1 = pOVar3->objType;
    if (OVar1 != TrigTime) {
      if ((short)OVar1 < 0x4e) {
        if (OVar1 == TrigPln) {
          FUN_800964d4((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z
                       ,(double)((this->pos).scale * 100.0),param2_00,param3_00,
                       (this->pos).rotation.z,(this->pos).rotation.y,(this->pos).rotation.x,0xff,0,0
                      );
          return;
        }
        if (0x4b < (short)OVar1) {
          FUN_802007cc((int)this,param2_00,param4_00,param5_00,param3_00);
          return;
        }
        if ((short)OVar1 < 0x4b) {
          return;
        }
      }
      else {
        if (OVar1 == TrigCyl) {
          FUN_80200348((int)this,param2_00,param4_00,param5_00,param3_00);
          return;
        }
        if (0x22f < (short)OVar1) {
          return;
        }
        if (0x4f < (short)OVar1) {
          return;
        }
      }
      FUN_80095aec((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)((this->pos).scale * 100.0),param2_00,param3_00,1);
    }
  }
  return;
}


/* Library Function - Single Match
    trigger_func07
   
   Library: KioskDefault 0 0 */

void trigger_free(ObjInstance *this,int param2) { //801FE67C
  ObjDefEnum OVar1;
  ObjDef *pOVar2;
  undefined *puVar3;
  byte bVar4;
  
  pOVar2 = this->def;
  puVar3 = this->state;
  for (bVar4 = 0; bVar4 < 8; bVar4 = bVar4 + 1) {
    if (*(int *)(puVar3 + (uint)bVar4 * 4 + 100) != 0) {
      DLL_free(*(LoadedDll **)(puVar3 + (uint)bVar4 * 4 + 100));
    }
    *(undefined4 *)(puVar3 + (uint)bVar4 * 4 + 100) = 0;
  }
  OVar1 = pOVar2->objType;
  if (OVar1 == TrigPln) {
    if ((modelInstance4E != (undefined *)0x0) &&
       (modelInstance4ErefCnt = modelInstance4ErefCnt + -1, modelInstance4ErefCnt == 0)) {
      modelInstanceFree((ModelInstance *)modelInstance4E);
      modelInstance4E = (undefined *)0x0;
    }
  }
  else {
    if ((short)OVar1 < 0x4c) {
      if ((short)OVar1 < 0x4b) goto LAB_801fe778;
    }
    else if (OVar1 != TrigButt) goto LAB_801fe778;
    if ((modelInstance55 != (undefined *)0x0) &&
       (modelInstance55refCnt = modelInstance55refCnt + -1, modelInstance55refCnt == 0)) {
      modelInstanceFree((ModelInstance *)modelInstance55);
      modelInstance55 = (undefined *)0x0;
    }
  }
LAB_801fe778:
  Object_removePlayerObj(this,2);
  return;
}


undefined4 trigger_func08(ObjInstance *this) { //801FE798
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int trigger_getExtraSize(void) { //801FE7A0
  return 0x84;
}

