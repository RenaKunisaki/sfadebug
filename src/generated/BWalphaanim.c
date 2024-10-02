
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void BWalphaanim_initialise(undefined4 param) { //802BF4DC
  return;
}


/* @description Called when DLL is unloaded */

void BWalphaanim_release(void) { //802BF4E0
  return;
}


/* @description Set up object instance */

void BWalphaanim_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //802BF4E4
  return;
}


/* Library Function - Single Match
    BWalphaanim_func04
   
   Library: KioskDefault 0 0 */

void BWalphaanim_update(ObjInstance *param1) { //802BF4E8
  int iBlock;
  MapBlock *pMVar1;
  ObjDef *pOVar2;
  int *piVar3;
  
  pOVar2 = param1->def;
  piVar3 = (int *)param1->state;
  iBlock = getBlockIdxAtCoords((double)(param1->pos).pos.x,(double)(param1->pos).pos.y,
                               (double)(param1->pos).pos.z);
  pMVar1 = mapGetBlockByIdx(iBlock);
  if (pMVar1 == (MapBlock *)0x0) {
    *(undefined *)((int)piVar3 + 0x22) = 0;
  }
  else if ((pMVar1->flags & 8) != 0) {
    if (*piVar3 == 0) {
      *(undefined *)((int)piVar3 + 0x23) = 1;
      *(byte *)(piVar3 + 8) = pOVar2[1].bound;
      if (100 < *piVar3) {
        printf("Error: BWalphaanim.c : MAX_SPEEDS exceeded!");
        *(undefined *)(piVar3 + 8) = 0;
      }
      if (*piVar3 == 0) {
        *(undefined *)(piVar3 + 8) = 0;
      }
      if (*(char *)(piVar3 + 8) == '\0') {
        return;
      }
      FUN_800a8f5c((double)(param1->pos).pos.x,(double)(param1->pos).pos.y,
                   (double)(param1->pos).pos.z,(float *)(piVar3 + 5),(float *)(piVar3 + 6));
    }
    if (*(char *)(piVar3 + 8) != '\0') {
      nop_802BF5F8();
      *(undefined *)((int)piVar3 + 0x23) = 0;
    }
  }
  return;
}


/* @description Override hit detection */

void BWalphaanim_hitDetect(ObjInstance *this) { //802BF5FC
  return;
}


/* Library Function - Single Match
    BWalphaanim_func06
   
   Library: KioskDefault 0 0 */

void BWalphaanim_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //802BF600
  bool bVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    bVar1 = checkSomeDebugFlags_8017c4f8();
    if (bVar1) {
      objRenderCurrentModel
                (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
                 (int *)CONCAT31(in_register_00000014,param3),
                 (undefined4 *)CONCAT31(in_register_00000018,param4),
                 (undefined4 *)CONCAT31(in_register_0000001c,param5));
      if (((this->pos).flags & 0x100) != 0) {
        FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                     (double)(float)((double)CONCAT44(0x43300000,
                                                      (uint)*(ushort *)
                                                             ((int)&this->def[1].pos.x + 2)) -
                                    4503599627370496.0),8.0,
                     (Gfx *)CONCAT31(in_register_00000010,param2),
                     (int *)CONCAT31(in_register_00000014,param3),0,0xff,0xff);
      }
    }
  }
  return;
}


/* @description Free object instance */

void BWalphaanim_free(ObjInstance *this,int param2) { //802BF6C4
  return;
}


undefined4 BWalphaanim_func08(ObjInstance *this) { //802BF6C8
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int BWalphaanim_getExtraSize(void) { //802BF6D0
  return 0x8c;
}

