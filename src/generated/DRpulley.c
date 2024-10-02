
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DRpulley_initialise(undefined4 param) { //802BBDA4
  return;
}


/* @description Called when DLL is unloaded */

void DRpulley_release(void) { //802BBDA8
  return;
}


/* Library Function - Single Match
    dll_2BC_func03
   
   Library: KioskDefault 0 0 */

void DRpulley_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                   float y,float z) { //802BBDAC
  uint uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)this->state;
  Object_objAddObjectType(this,0x1a);
  (this->pos).rotation.z = (ushort)*(byte *)&objDef[1].objType << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  (this->pos).scale = (this->pos).scale * *(float *)&objDef[1].loadFlags;
  this->flags_0xb0 = (ushort)objDef[1].mapStates1;
  uVar1 = mainGetBit(0x65f);
  *(char *)(puVar3 + 1) = (char)uVar1;
  if (*(char *)(puVar3 + 1) == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x15e;
  }
  *puVar3 = uVar2;
  return;
}


/* Library Function - Single Match
    dll_2BC_func04
   
   Library: KioskDefault 0 0 */

void DRpulley_update(ObjInstance *this) { //802BBE58
  int iVar1;
  byte bVar2;
  uint uVar3;
  ObjInstance *param2;
  undefined *puVar4;
  ushort *puVar5;
  double in_f1;
  double dVar6;
  float local_4c;
  longlong local_48;
  undefined4 local_40;
  uint uStack_3c;
  double local_38;
  
  _savefpr_29();
  puVar5 = (ushort *)this->state;
  local_4c = 2000.0;
  dVar6 = 0.0;
  bVar2 = *(byte *)(puVar5 + 1);
  if (bVar2 == 1) {
    if (this->romdefno == 0xad) {
      *(undefined *)(puVar5 + 1) = 2;
      audioTryStartSfx((int *)this,8,0x85,0x7f,"DRpulley.c",0x57);
    }
    else if ((this->flags_0xb0 & 2) == 0) {
      param2 = getSeqObj(7,this,&local_4c);
      puVar4 = param2->state;
      objDistObj2Obj(this,param2);
      if (120.0 <= in_f1) {
        FUN_80068a9c((uint)this,8);
      }
      else {
        if (puVar4[0xb6] != '\0') {
          dVar6 = 0.0;
        }
        local_38 = (double)(longlong)(int)dVar6;
        audioTryStartSfx((int *)this,0x88,0x1e4,(byte)(int)dVar6,"DRpulley.c",0x6a);
      }
    }
  }
  else if (bVar2 == 0) {
    if (true) {
      uVar3 = mainGetBit(0x65f);
      *(char *)(puVar5 + 1) = (char)uVar3;
    }
  }
  else if (bVar2 < 3) {
    if (*puVar5 < 0x15e) {
      *puVar5 = *puVar5 + 0x1e;
    }
    local_38 = (double)CONCAT44(0x43300000,(uint)*puVar5);
    uStack_3c = (int)(this->pos).rotation.y ^ 0x80000000;
    local_40 = 0x43300000;
    iVar1 = (int)-((float)(local_38 - 4503599627370496.0) * timeDelta -
                  (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0));
    local_48 = (longlong)iVar1;
    (this->pos).rotation.y = (short)iVar1;
  }
  _restfpr_29();
  return;
}


/* @description Override hit detection */

void DRpulley_hitDetect(ObjInstance *this) { //802BC07C
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void DRpulley_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                     undefined param5,bool shouldRender) { //802BC080
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


/* Library Function - Single Match
    dll_2BC_func07
   
   Library: KioskDefault 0 0 */

void DRpulley_free(ObjInstance *this,int param2) { //802BC0DC
  Object_removePlayerObj(this,0x1a);
  return;
}


undefined4 DRpulley_func08(ObjInstance *this) { //802BC118
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DRpulley_getExtraSize(void) { //802BC120
  return 4;
}

