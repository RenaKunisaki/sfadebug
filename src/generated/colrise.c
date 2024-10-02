
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void colrise_initialise(undefined4 param) { //80242C00
  return;
}


/* @description Called when DLL is unloaded */

void colrise_release(void) { //80242C04
  return;
}


/* Library Function - Single Match
    dll_1C9_func03
   
   Library: KioskDefault 0 0 */

void colrise_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //80242C08
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80242e78;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *puVar1 = *(undefined2 *)&objDef[1].bound;
  return;
}


/* Library Function - Single Match
    dll_1C9_func04
   
   Library: KioskDefault 0 0 */

void dll_GPSH_Colrise_update(ObjInstance *this) { //80242C48
  float fVar1;
  bool bVar2;
  int iVar3;
  ObjDef *pOVar4;
  undefined *puVar5;
  
  pOVar4 = this->def;
  puVar5 = this->state;
  puVar5[2] = puVar5[2] + -1;
  if ((char)puVar5[2] < '\0') {
    puVar5[2] = 0;
  }
  if ('\0' < (char)this->field18_0x58->field144_0x10f) {
    iVar3 = 0;
    while( true ) {
      if ((char)this->field18_0x58->field144_0x10f <= iVar3) break;
      if (3.0 < *(float *)(*(int *)((int)(this->field18_0x58->mtx + 2) + iVar3 * 4) + 0x10) -
                (this->pos).pos.y) {
        puVar5[2] = 0x3c;
      }
      iVar3 = iVar3 + 1;
    }
  }
  bVar2 = false;
  if (puVar5[2] == '\0') {
    (this->pos).pos.y = -(timeDelta * 0.125 - (this->pos).pos.y);
    if ((pOVar4->pos).y <= (this->pos).pos.y) {
      bVar2 = true;
    }
    else {
      (this->pos).pos.y = (pOVar4->pos).y;
    }
  }
  else {
    fVar1 = (pOVar4->pos).y + 20.0 + 20.0;
    if ((this->pos).pos.y <= fVar1) {
      (this->pos).pos.y = timeDelta * 0.25 + (this->pos).pos.y;
      if ((this->pos).pos.y <= fVar1) {
        bVar2 = true;
      }
      else {
        (this->pos).pos.y = fVar1;
      }
    }
    else {
      (this->pos).pos.y = -(timeDelta * 0.5 - (this->pos).pos.y);
      if (fVar1 < (this->pos).pos.y) {
        (this->pos).pos.y = fVar1;
      }
    }
  }
  if (bVar2) {
    audioTryStartSfx((int *)this,0x88,0x74,0x7f,"colrise.c",0x5d);
  }
  else {
    FUN_80068a9c((uint)this,8);
  }
  return;
}


/* @description Override hit detection */

void colrise_hitDetect(ObjInstance *this) { //80242E04
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void colrise_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //80242E08
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

void colrise_free(ObjInstance *this,int param2) { //80242E64
  return;
}


undefined4 colrise_func08(ObjInstance *this) { //80242E68
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int colrise_getExtraSize(void) { //80242E70
  return 4;
}


/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void colrise243_initialise(undefined4 param) { //80281EE8
  return;
}


/* @description Called when DLL is unloaded */

void colrise243_release(void) { //80281EEC
  return;
}


/* Library Function - Single Match
    dll_243_func03
   
   Library: KioskDefault 0 0 */

void colrise243_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                     float y,float z) { //80281EF0
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_80282230;
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  *puVar1 = *(undefined2 *)&objDef[1].bound;
  if (DAT_8039a058 == (DLL_func **)0x0) {
    DAT_8039a058 = runlinkDownloadCode(0x1024,1);
  }
  return;
}


/* Library Function - Single Match
    dll_243_func04
   
   Library: KioskDefault 0 0 */

void WM_colrise_update(ObjInstance *this) { //80281F64
  float fVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ObjDef *pOVar5;
  short *psVar6;
  
  pOVar5 = this->def;
  psVar6 = (short *)this->state;
  *(char *)(psVar6 + 1) = *(char *)(psVar6 + 1) + -1;
  if (*(char *)(psVar6 + 1) < '\0') {
    *(undefined *)(psVar6 + 1) = 0;
  }
  if ('\0' < (char)this->field18_0x58->field144_0x10f) {
    for (iVar4 = 0; iVar4 < (char)this->field18_0x58->field144_0x10f; iVar4 = iVar4 + 1) {
      if (3.0 < *(float *)(*(int *)((int)(this->field18_0x58->mtx + 2) + iVar4 * 4) + 0x10) -
                (this->pos).pos.y) {
        *(undefined *)(psVar6 + 1) = 0x3c;
      }
    }
  }
  bVar2 = false;
  if (*psVar6 == -1) {
LAB_80282024:
    if (*(char *)(psVar6 + 1) != '\0') {
      fVar1 = (pOVar5->pos).y + 100.0 + 20.0;
      if ((this->pos).pos.y <= fVar1) {
        (this->pos).pos.y = timeDelta * 0.25 + (this->pos).pos.y;
        if ((this->pos).pos.y <= fVar1) {
          bVar2 = true;
        }
        else {
          (this->pos).pos.y = fVar1;
        }
      }
      else {
        (this->pos).pos.y = -(timeDelta * 0.5 - (this->pos).pos.y);
        if (fVar1 < (this->pos).pos.y) {
          (this->pos).pos.y = fVar1;
        }
      }
      goto LAB_802820dc;
    }
  }
  else {
    uVar3 = mainGetBit((int)*psVar6);
    if (uVar3 != 0) goto LAB_80282024;
  }
  (this->pos).pos.y = -(timeDelta * 0.125 - (this->pos).pos.y);
  if ((pOVar5->pos).y <= (this->pos).pos.y) {
    bVar2 = true;
  }
  else {
    (this->pos).pos.y = (pOVar5->pos).y;
  }
LAB_802820dc:
  if (bVar2) {
    audioTryStartSfx((int *)this,8,0x74,0x7f,(char *)&PTR_DAT_8031d6e8,0x6d);
  }
  else {
    iVar4 = randInt(0,0x28);
    if (iVar4 == 0) {
      iVar4 = randInt(0,5);
      (**(code **)(*DAT_8039a058 + 4))(this,iVar4,0,1,0xffffffff,0);
    }
    FUN_80068a9c((uint)this,8);
  }
  return;
}


/* @description Override hit detection */

void colrise243_hitDetect(ObjInstance *this) { //80282188
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void colrise243_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                       undefined param5,bool shouldRender) { //8028218C
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


/* Library Function - Multiple Matches With Different Base Names
    dll_12D_func01
    dll_184_func01
    dll_210_func07
    dll_243_func07
     7 names - too many to list
   
   Library: KioskDefault 0 0 */

ObjInstance * colrise243_free(ObjInstance *this,int param2) { //802821E8
  if (DAT_8039a058 != (LoadedDll *)0x0) {
    this = (ObjInstance *)DLL_free(DAT_8039a058);
  }
  DAT_8039a058 = (LoadedDll *)0x0;
  return this;
}


undefined4 colrise243_func08(ObjInstance *this) { //80282220
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int colrise243_getExtraSize(void) { //80282228
  return 4;
}

