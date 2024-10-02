
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void pickup_initialise(undefined4 param) { //8012F578
  return;
}


/* @description Called when DLL is unloaded */

void pickup_release(void) { //8012F57C
  return;
}


/* Library Function - Single Match
    dll_33_func03
   
   Library: KioskDefault 0 0 */

void pickup_func03(ObjInstance *param1,int param2) { //8012F580
  Object_objAddObjectType(param1,0x12);
  *(undefined2 *)(param2 + 2) = 0;
  return;
}


/* Library Function - Single Match
    dll_33_func04
   
   Library: KioskDefault 0 0 */

int pickup_func04(ObjInstance *this) { //8012F5BC
  char cVar1;
  float fVar2;
  ObjInstance *player;
  BOOL BVar3;
  int iVar4;
  u16 buttons;
  uint uVar5;
  int iVar6;
  int iVar7;
  ObjState_Pickup *state;
  int local_28 [2];
  
  state = (ObjState_Pickup *)this->state;
  state->field6_0x8 = 0;
  state->flags07 = state->flags07 & 0xfe;
  player = Object_objGetMain();
  if (state->field3_0x5 == '\0') {
    BVar3 = FUN_8012faf4(this,player,state);
    state->field3_0x5 = (char)BVar3;
    if (state->field3_0x5 != '\0') {
      state->flags07 = state->flags07 | 1;
      state->field4_0x6 = '\x01';
    }
    if (this->flags_0xf8 == 0) {
      objHitUpdatePos(this);
      this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      if ((state->flags07 & 2) == 0) {
        (this->vel).y = -(timeDelta * 0.1 - (this->vel).y);
        (this->pos).pos.y = (this->vel).y * timeDelta + (this->pos).pos.y;
      }
      iVar4 = FUN_800b9dcc((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                           (double)(this->pos).pos.z,(int)this,local_28,0,1);
      iVar6 = 0;
      for (iVar7 = 0; iVar7 < iVar4; iVar7 = iVar7 + 1) {
        if (((*(char *)(*(int *)(local_28[0] + iVar7 * 4) + 0x14) != '\x0e') &&
            ((this->pos).pos.y < **(float **)(local_28[0] + iVar7 * 4))) &&
           (**(float **)(local_28[0] + iVar7 * 4) - 40.0 < (this->pos).pos.y)) {
          iVar6 = *(int *)(*(int *)(local_28[0] + iVar7 * 4) + 0x10);
          (this->pos).pos.y = **(float **)(local_28[0] + iVar7 * 4);
          (this->vel).y = 0.0;
          break;
        }
      }
      for (iVar7 = 0; iVar7 < iVar4; iVar7 = iVar7 + 1) {
        fVar2 = (this->pos).pos.y - **(float **)(local_28[0] + iVar7 * 4);
        if (fVar2 < 0.0) {
          fVar2 = -fVar2;
        }
        if ((fVar2 < 5.0) &&
           ((int)(uint)state->field6_0x8 < (int)*(char *)(*(int *)(local_28[0] + iVar7 * 4) + 0x14))
           ) {
          state->field6_0x8 = *(byte *)(*(int *)(local_28[0] + iVar7 * 4) + 0x14);
        }
      }
      if (iVar6 != 0) {
        iVar4 = *(int *)(iVar6 + 0x58);
        cVar1 = *(char *)(*(int *)(iVar6 + 0x58) + 0x10f);
        *(char *)(*(int *)(iVar6 + 0x58) + 0x10f) = cVar1 + '\x01';
        *(ObjInstance **)(iVar4 + cVar1 * 4 + 0x100) = this;
      }
    }
  }
  else {
    objSetHitNeedsPosUpdate(this);
    this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
    buttons = getEnabledButtonsPressed(0);
    if ((buttons & 0x100) != 0) {
      disableButtons(0,PAD_BUTTON_A);
      if (((state->flags07 & 4) == 0) && (uVar5 = FUN_801a8944((int)player), uVar5 != 0)) {
        state->field4_0x6 = '\0';
      }
      else {
        audioStartSfx((int **)0x0,0x16b,0x7f,0x40,"pickup.c",0x89);
      }
    }
    if (this->flags_0xf8 == 1) {
      state->field3_0x5 = '\x02';
    }
    if (state->field3_0x5 == '\x02') {
      if (this->flags_0xf8 == 0) {
        state->field3_0x5 = '\0';
        state->field4_0x6 = '\0';
        if ((state->flags07 & 8) == 0) {
          objRomDefMove_800af9d8
                    ((double)(this->pos).pos.x,(double)((this->pos).pos.y + 10.0),
                     (double)(this->pos).pos.z,this->def,(short)(char)this->mapId);
        }
      }
    }
    if (state->field4_0x6 != '\0') {
      objSendMsg((int)player,0x100008,(uint)this,CONCAT22(state->field1_0x2,state->field0_0x0));
    }
  }
  return (int)state->field3_0x5;
}


/* Library Function - Single Match
    dll_33_func05
   
   Library: KioskDefault 0 0 */

undefined4 pickup_func05(int param1,int param2) { //8012F938
  if (*(short *)(*(int *)(param1 + 0x50) + 0x48) == 2) {
    if (*(short *)(param1 + 0xb4) == -1) {
      *(uint *)(*(int *)(param1 + 100) + 0x30) =
           *(uint *)(*(int *)(param1 + 100) + 0x30) & 0xffffefff;
    }
    else {
      *(uint *)(*(int *)(param1 + 100) + 0x30) = *(uint *)(*(int *)(param1 + 100) + 0x30) | 0x1000;
    }
  }
  if (*(int *)(param1 + 0xf8) == 0) {
    if (param2 == 0) {
      return 0;
    }
  }
  else if (param2 != -1) {
    return 0;
  }
  return 1;
}


/* Library Function - Single Match
    dll_33_func06
   
   Library: KioskDefault 0 0 */

void pickup_func06(ObjInstance *param1) { //8012F9AC
  Object_removePlayerObj(param1,0x12);
  return;
}


int pickup_func07(int param1) { //8012F9D8
  return (int)*(char *)(param1 + 5);
}


byte pickup_func08(int param1) { //8012F9E4
  return *(byte *)(param1 + 7) & 1;
}


undefined pickup_func09(int param1) { //8012F9F0
  return *(undefined *)(param1 + 8);
}


/* Library Function - Single Match
    dll_33_func0A
   
   Library: KioskDefault 0 0 */

void pickup_func0A(int param1,char param2) { //8012F9F8
  if (param2 != '\0') {
    *(byte *)(param1 + 7) = *(byte *)(param1 + 7) & 0xfd;
    return;
  }
  *(byte *)(param1 + 7) = *(byte *)(param1 + 7) | 2;
  return;
}


/* Library Function - Single Match
    dll_33_func0B
   
   Library: KioskDefault 0 0 */

void pickup_func0B(int param1,char param2) { //8012FA20
  if (param2 != '\0') {
    *(byte *)(param1 + 7) = *(byte *)(param1 + 7) | 4;
    return;
  }
  *(byte *)(param1 + 7) = *(byte *)(param1 + 7) & 0xfb;
  return;
}


undefined4 pickup_func0C(int param1) { //8012FA48
  if ((*(byte *)(param1 + 7) & 4) != 0) {
    return 1;
  }
  return 0;
}


/* Library Function - Single Match
    dll_33_func0D
   
   Library: KioskDefault 0 0 */

void pickup_func0D(int param1,char param2) { //8012FA64
  if (param2 != '\0') {
    *(byte *)(param1 + 7) = *(byte *)(param1 + 7) | 8;
    return;
  }
  *(byte *)(param1 + 7) = *(byte *)(param1 + 7) & 0xf7;
  return;
}


/* Library Function - Single Match
    dll_33_func0E
   
   Library: KioskDefault 0 0 */

uint pickup_func0E(uint param1,int param2) { //8012FA8C
  ObjInstance *param1_00;
  bool bVar1;
  uint local_10 [3];
  
  param1_00 = Object_objGetMain();
  *(undefined *)(param2 + 5) = 0;
  FUN_801a7f44((int)param1_00,local_10);
  if (local_10[0] == param1) {
    bVar1 = krystalCarryFn_801a7fd8((int)param1_00,0);
    local_10[0] = (uint)bVar1;
  }
  return local_10[0];
}

