
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SimpleExploder_initialise(undefined4 param) { //8020D6AC
  return;
}


/* @description Called when DLL is unloaded */

void SimpleExploder_release(void) { //8020D6B0
  return;
}


/* Library Function - Single Match
    SimpleExploder_func03
   
   Library: KioskDefault 0 0 */

void SimpleExploder_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8020D6B4
  undefined uVar2;
  uint uVar1;
  int iVar3;
  undefined *puVar4;
  
  printf(" Simple Exploder ");
  Object_objAddObjectType(this,0x23);
  puVar4 = this->state;
  if (*(char *)&objDef[1].objType == '\0') {
    uVar2 = 1;
  }
  else {
    uVar2 = *(undefined *)&objDef[1].objType;
  }
  puVar4[0x6d4] = uVar2;
  *(undefined4 *)(puVar4 + 0x6cc) = 0;
  for (iVar3 = 0; iVar3 < 0xf; iVar3 = iVar3 + 1) {
    *(undefined4 *)(puVar4 + iVar3 * 4 + 0x690) = 0;
  }
  (this->pos).rotation.x = *(short *)&objDef[1].allocatedSize;
  (this->pos).rotation.y = *(short *)&objDef[1].loadFlags;
  (this->pos).rotation.z = *(short *)&objDef[1].bound;
  uVar1 = mainGetBit((int)*(short *)((int)&objDef[2].pos.y + 2));
  if (uVar1 != 0) {
    puVar4[0x6e4] = 2;
  }
  return;
}


/* Library Function - Single Match
    SimpleExploder_func04
   
   Library: KioskDefault 0 0 */

void SimpleExploder_update(ObjInstance *this) { //8020D778
  uint uVar1;
  int iVar2;
  ObjDef *pOVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = this->state;
  pOVar3 = this->def;
  if (puVar5[0x6e4] != '\x02') {
    if (puVar5[0x6e4] == '\0') {
      uVar1 = mainGetBit((int)*(short *)&pOVar3[2].pos.z);
      if (uVar1 != 0) {
        FUN_8020df00((int)this,(int)pOVar3,0,(int)puVar5);
        if (*(int *)(puVar5 + 0x6d0) != 0) {
          audioTryStartSfx((int *)this,1,(ushort)*(undefined4 *)(puVar5 + 0x6d0),0x7f,
                           "CFexploder.c",0x10b);
        }
        puVar5[0x6e4] = 1;
        this->newOpacity = 0;
      }
    }
    else {
      for (iVar4 = 0; iVar4 < 0xf; iVar4 = iVar4 + 1) {
        if (*(int *)(puVar5 + iVar4 * 4 + 0x690) != 0) {
          iVar2 = (**(code **)(**(int **)(*(int *)(puVar5 + iVar4 * 4 + 0x690) + 0x68) + 0x20))
                            (*(undefined4 *)(puVar5 + iVar4 * 4 + 0x690));
          if (iVar2 != 1) {
            if (iVar2 < 1) {
              if ((-1 < iVar2) &&
                 (mainSetBits((int)*(short *)((int)&pOVar3[2].pos.y + 2),1),
                 (*(uint *)(puVar5 + 0x6cc) & 1 << iVar4) == 0)) {
                audioTryStartSfx((int *)this,1,0x54,0x7f,"CFexploder.c",0x11c);
                *(uint *)(puVar5 + 0x6cc) = *(uint *)(puVar5 + 0x6cc) | 1 << iVar4;
              }
            }
            else if (iVar2 < 3) {
              mainSetBits((int)*(short *)((int)&pOVar3[2].pos.y + 2),1);
              Object_objFreeObject(*(ObjInstance **)(puVar5 + iVar4 * 4 + 0x690));
              *(undefined4 *)(puVar5 + iVar4 * 4 + 0x690) = 0;
            }
          }
        }
      }
    }
  }
  return;
}


/* @description Override hit detection */

void SimpleExploder_hitDetect(ObjInstance *this) { //8020D934
  return;
}


/* @description Override render */

void SimpleExploder_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8020D938
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  iVar1 = FUN_8018d744();
  if ((iVar1 == 0) && (bVar2 = checkSomeDebugFlags_8017c4f8(), !bVar2)) {
    return;
  }
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    SimpleExploder_func07
   
   Library: KioskDefault 0 0 */

void SimpleExploder_free(ObjInstance *this,int param2) { //8020D9AC
  undefined *puVar1;
  int iVar2;
  
  iVar2 = -1;
  puVar1 = this->state;
  Object_removePlayerObj(this,0x23);
  if (param2 == 0) {
    while (iVar2 = iVar2 + 1, iVar2 < 0xf) {
      if (*(int *)(puVar1 + iVar2 * 4 + 0x690) != 0) {
        Object_objFreeObject(*(ObjInstance **)(puVar1 + iVar2 * 4 + 0x690));
      }
    }
  }
  return;
}


undefined4 SimpleExploder_func08(ObjInstance *this) { //8020DA2C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SimpleExploder_getExtraSize(void) { //8020DA34
  return 0x6e8;
}

