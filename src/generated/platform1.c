
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void platform1_initialise(undefined4 param) { //8028E04C
  return;
}


/* @description Called when DLL is unloaded */

void platform1_release(void) { //8028E050
  return;
}


/* Library Function - Single Match
    dll_260_func03
   
   Library: KioskDefault 0 0 */

void platform1_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8028E054
  short *psVar1;
  
  psVar1 = (short *)this->state;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *psVar1 = *(short *)&objDef[1].pos.x;
  *(undefined *)(psVar1 + 1) = 0;
  *(undefined *)((int)psVar1 + 3) = *(undefined *)((int)&objDef[1].objType + 1);
  if (this->romdefno == VFPLavaBloc) {
    mainSetBits((int)*psVar1,1);
  }
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  return;
}


/* Library Function - Single Match
    dll_260_func04
   
   Library: KioskDefault 0 0 */

void platform1_update(ObjInstance *this) { //8028E0D4
  byte bVar1;
  uint uVar2;
  ObjDef *pOVar3;
  short *psVar4;
  
  pOVar3 = this->def;
  psVar4 = (short *)this->state;
  if (*(char *)((int)psVar4 + 3) != 'c') {
    if (this->romdefno == VFPLavaBloc) {
      FUN_8028e708((int)this);
    }
    else {
      bVar1 = *(byte *)(psVar4 + 1);
      if (bVar1 == 3) {
        if ((*(char *)((int)psVar4 + 3) != '\x03') || ((this->pos).pos.x <= (pOVar3->pos).x - 60.0))
        {
          if (((pOVar3->pos).z - 60.0 < (this->pos).pos.z) &&
             ((this->pos).pos.z = (this->pos).pos.z - timeDelta,
             (this->pos).pos.z <= (pOVar3->pos).z - 60.0)) {
            (this->pos).pos.z = (pOVar3->pos).z - 60.0;
            *(undefined *)(psVar4 + 1) = 1;
            psVar4[2] = 200;
          }
        }
        else {
          (this->pos).pos.x = (this->pos).pos.x - timeDelta;
          if ((this->pos).pos.x <= (pOVar3->pos).x - 60.0) {
            (this->pos).pos.x = (pOVar3->pos).x - 60.0;
            *(undefined *)(psVar4 + 1) = 1;
            psVar4[2] = 200;
          }
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 1) {
          if (psVar4[2] == 0) {
            if (*(char *)((int)psVar4 + 3) == '\0') {
              if ((this->pos).pos.z == (pOVar3->pos).z - 60.0) {
                *(undefined *)(psVar4 + 1) = 2;
                audioTryStartSfx((int *)this,1,0x53,0x7f,"platform1.c",0x68);
              }
              if ((this->pos).pos.z == (pOVar3->pos).z) {
                *(undefined *)(psVar4 + 1) = 3;
                audioTryStartSfx((int *)this,1,0x53,0x7f,"platform1.c",0x6c);
              }
            }
            else if (*(char *)((int)psVar4 + 3) == '\x03') {
              if ((this->pos).pos.x == (pOVar3->pos).x - 60.0) {
                *(undefined *)(psVar4 + 1) = 2;
                audioTryStartSfx((int *)this,1,0x53,0x7f,"platform1.c",0x72);
              }
              if ((this->pos).pos.x == (pOVar3->pos).x) {
                *(undefined *)(psVar4 + 1) = 3;
                audioTryStartSfx((int *)this,1,0x53,0x7f,"platform1.c",0x76);
              }
            }
            else {
              if ((this->pos).pos.z == (pOVar3->pos).z + 60.0) {
                *(undefined *)(psVar4 + 1) = 4;
                audioTryStartSfx((int *)this,1,0x53,0x7f,"platform1.c",0x7c);
              }
              if ((this->pos).pos.z == (pOVar3->pos).z) {
                *(undefined *)(psVar4 + 1) = 5;
                audioTryStartSfx((int *)this,1,0x53,0x7f,"platform1.c",0x80);
              }
            }
          }
          else {
            psVar4[2] = psVar4[2] - (short)(int)timeDelta;
            if (psVar4[2] < 1) {
              psVar4[2] = 0;
            }
          }
        }
        else if (bVar1 == 0) {
          if ((true) && (uVar2 = mainGetBit((int)*psVar4), uVar2 != 0)) {
            *(undefined *)(psVar4 + 1) = 1;
          }
        }
        else if ((*(char *)((int)psVar4 + 3) != '\x03') || ((pOVar3->pos).x <= (this->pos).pos.x)) {
          if (((this->pos).pos.z < (pOVar3->pos).z) &&
             ((this->pos).pos.z = (this->pos).pos.z + timeDelta,
             (pOVar3->pos).z <= (this->pos).pos.z)) {
            (this->pos).pos.z = (pOVar3->pos).z;
            *(undefined *)(psVar4 + 1) = 1;
          }
        }
        else {
          (this->pos).pos.x = (this->pos).pos.x + timeDelta;
          if ((pOVar3->pos).x <= (this->pos).pos.x) {
            (this->pos).pos.x = (pOVar3->pos).x;
            *(undefined *)(psVar4 + 1) = 1;
          }
        }
      }
      else if (bVar1 == 5) {
        if ((*(char *)((int)psVar4 + 3) != '\x03') || ((pOVar3->pos).x + 60.0 <= (this->pos).pos.x))
        {
          if (((this->pos).pos.z < (pOVar3->pos).z + 60.0) &&
             ((this->pos).pos.z = (this->pos).pos.z + timeDelta,
             (pOVar3->pos).z + 60.0 <= (this->pos).pos.z)) {
            (this->pos).pos.z = (pOVar3->pos).z + 60.0;
            *(undefined *)(psVar4 + 1) = 1;
            psVar4[2] = 200;
          }
        }
        else {
          (this->pos).pos.x = (this->pos).pos.x + timeDelta;
          if ((pOVar3->pos).x + 60.0 <= (this->pos).pos.x) {
            (this->pos).pos.x = (pOVar3->pos).x + 60.0;
            *(undefined *)(psVar4 + 1) = 1;
            psVar4[2] = 200;
          }
        }
      }
      else if (bVar1 < 5) {
        if ((*(char *)((int)psVar4 + 3) != '\x03') || ((this->pos).pos.x <= (pOVar3->pos).x)) {
          if (((pOVar3->pos).z < (this->pos).pos.z) &&
             ((this->pos).pos.z = (this->pos).pos.z - timeDelta,
             (this->pos).pos.z <= (pOVar3->pos).z)) {
            (this->pos).pos.z = (pOVar3->pos).z;
            *(undefined *)(psVar4 + 1) = 1;
          }
        }
        else {
          (this->pos).pos.x = (this->pos).pos.x - timeDelta;
          if ((this->pos).pos.x <= (pOVar3->pos).x) {
            (this->pos).pos.x = (pOVar3->pos).x;
            *(undefined *)(psVar4 + 1) = 1;
          }
        }
      }
    }
  }
  return;
}


/* @description Override hit detection */

void platform1_hitDetect(ObjInstance *this) { //8028E63C
  return;
}


/* Library Function - Single Match
    dll_260_func06
   
   Library: KioskDefault 0 0 */

void platform1_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8028E640
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  undefined *puVar2;
  
  puVar2 = this->state;
  if ((shouldRender) && ((bVar1 = checkSomeDebugFlags_8017c4f8(), bVar1 || (puVar2[3] != 'c')))) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void platform1_free(ObjInstance *this,int param2) { //8028E6C0
                    /* {@symbol 800dc2d8} */
  (**(code **)(*(int *)pDll_modgfx + 0x18))(this);
  return;
}


undefined4 platform1_func08(ObjInstance *this) { //8028E6F8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int platform1_getExtraSize(void) { //8028E700
  return 6;
}

