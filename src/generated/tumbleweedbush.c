
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void TumbleweedBush_initialise(undefined4 param) { //801C194C
  return;
}


/* @description Called when DLL is unloaded */

void TumbleweedBush_release(void) { //801C1950
  return;
}


/* Library Function - Single Match
    Tumbleweed_func03
   
   Library: KioskDefault 0 0 */

void TumbleweedBush_init
               (ObjInstance *param1,int param2,int param3,DllInitFlags flags,float x,float y,float z
               ) { //801C1954
  ObjDefEnum OVar1;
  int unaff_r27;
  int iVar2;
  float *pfVar3;
  
  pfVar3 = (float *)param1->state;
  *pfVar3 = 0.0;
  *(ushort *)(pfVar3 + 2) = (ushort)*(byte *)(param2 + 0x1b) << 1;
  *(undefined *)(pfVar3 + 0x13) = *(undefined *)(param2 + 0x23);
  (param1->pos).rotation.z = (*(byte *)(param2 + 0x18) - 0x7f) * 0x80;
  (param1->pos).rotation.y = (*(byte *)(param2 + 0x19) - 0x7f) * 0x80;
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0x1a) << 8;
  (param1->pos).scale = *(float *)(param2 + 0x1c);
  objHitFn_80089188(param1,(short)(int)((param1->pos).scale * 15.0),
                    (short)(int)((param1->pos).scale * -5.0),
                    (short)(int)((param1->pos).scale * 100.0));
  OVar1 = param1->romdefno;
  if (OVar1 == TumbleWeedB_03FD) {
    *(undefined *)(pfVar3 + 0x14) = 4;
    unaff_r27 = 1;
    goto LAB_801c1a80;
  }
  if ((short)OVar1 < 0x3fd) {
    if (OVar1 == TumbleWeedB) {
      *(undefined *)(pfVar3 + 0x14) = 3;
LAB_801c1a50:
      *(undefined *)(pfVar3 + 0x14) = 3;
      unaff_r27 = 0;
      goto LAB_801c1a80;
    }
  }
  else if (OVar1 == TumbleWeedB_04B9) goto LAB_801c1a50;
  printf("TumbleWeed cannot determin control type because of an incorrect object number.");
LAB_801c1a80:
  if (param3 == 0) {
    for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(pfVar3 + 0x14); iVar2 = iVar2 + 1) {
      pfVar3[iVar2 + 3] = 0.0;
      memcpy_src_dst_len(&PTR_DAT_80310750 + unaff_r27 * 0xc + iVar2 * 3,pfVar3 + iVar2 * 3 + 7,0xc)
      ;
      pfVar3[iVar2 * 3 + 7] = pfVar3[iVar2 * 3 + 7] * (param1->pos).scale;
      pfVar3[iVar2 * 3 + 8] = pfVar3[iVar2 * 3 + 8] * (param1->pos).scale;
      pfVar3[iVar2 * 3 + 9] = pfVar3[iVar2 * 3 + 9] * (param1->pos).scale;
      FUN_8007a878((short *)param1,pfVar3 + iVar2 * 3 + 7);
    }
  }
  return;
}


/* Library Function - Single Match
    Tumbleweed_func04
   
   Library: KioskDefault 0 0 */

void TumbleweedBush_update(ObjInstance *this) { //801C1B50
  float fVar1;
  float fVar2;
  ObjInstance *pOVar3;
  int iVar4;
  undefined *puVar5;
  byte bVar6;
  double dVar7;
  undefined auStack_44 [4];
  uint uStack_40;
  int iStack_3c;
  undefined4 auStack_38 [2];
  longlong local_30;
  
  _savefpr_30();
  puVar5 = this->state;
  pOVar3 = Object_objGetMain();
  iVar4 = FUN_800883e4((int)this,auStack_38,&iStack_3c,&uStack_40);
  if (iVar4 != 0) {
    for (bVar6 = 0; bVar6 < (byte)puVar5[0x50]; bVar6 = bVar6 + 1) {
                    /* {@symbol 800d2604} */
      if ((*(int *)(puVar5 + (uint)bVar6 * 4 + 0xc) != 0) &&
         ((this->romdefno != TumbleWeedB ||
          (iVar4 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_44), iVar4 != 0)))) {
        (**(code **)(**(int **)(*(int *)(puVar5 + (uint)bVar6 * 4 + 0xc) + 0x68) + 0x28))
                  (*(undefined4 *)(puVar5 + (uint)bVar6 * 4 + 0xc));
      }
    }
    audioSfxFn_800688bc((double)(this->prevPos).x,(double)(this->prevPos).y,
                        (double)(this->prevPos).z,499,0x7f,"tumbleweedbush.c",(int *)0xae);
  }
  fVar1 = (this->pos).pos.x - (pOVar3->pos).pos.x;
  fVar2 = (this->pos).pos.z - (pOVar3->pos).pos.z;
  dVar7 = sqrt((double)(fVar1 * fVar1 + fVar2 * fVar2));
  local_30 = (longlong)(int)dVar7;
  if (((int)dVar7 & 0xffffU) < (uint)*(ushort *)(puVar5 + 8)) {
    do {
      iVar4 = tumbleweedFn_801c2460((int)this);
    } while ((char)iVar4 != -1);
  }
  for (bVar6 = 0; bVar6 < (byte)puVar5[0x50]; bVar6 = bVar6 + 1) {
    if ((*(int *)(puVar5 + (uint)bVar6 * 4 + 0xc) != 0) &&
       (iVar4 = (**(code **)(**(int **)(*(int *)(puVar5 + (uint)bVar6 * 4 + 0xc) + 0x68) + 0x20))
                          (*(undefined4 *)(puVar5 + (uint)bVar6 * 4 + 0xc)), 1 < iVar4)) {
      *(undefined4 *)(puVar5 + (uint)bVar6 * 4 + 0xc) = 0;
    }
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void TumbleweedBush_hitDetect(ObjInstance *this) { //801C1D28
  return;
}


/* Library Function - Single Match
    Tumbleweed_func06
   
   Library: KioskDefault 0 0 */

void TumbleweedBush_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801C1D2C
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar3;
  
  pOVar3 = this->def;
  if (shouldRender) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this->state + 8)) -
                                  4503599627370496.0),32.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0xff,0,0);
    }
    FUN_80096afc((ushort)*(byte *)&pOVar3[1].pos.x,(ushort)*(byte *)((int)&pOVar3[1].pos.x + 1),
                 (ushort)*(byte *)((int)&pOVar3[1].pos.x + 2));
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    return;
  }
  return;
}


/* @description Free object instance */

void TumbleweedBush_free(ObjInstance *this,int param2) { //801C1E10
  return;
}


undefined4 TumbleweedBush_func08(ObjInstance *this) { //801C1E14
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int TumbleweedBush_getExtraSize(void) { //801C1E1C
  return 0x54;
}


/* Library Function - Single Match
    Tumbleweed_func0A
   
   Library: KioskDefault 0 0 */

void TumbleweedBush_setScale(ObjInstance *this,float scale) { //801C1E24
  int in_r4;
  undefined *puVar1;
  int iVar2;
  
  puVar1 = this->state;
  for (iVar2 = 0; iVar2 < (int)(uint)(byte)puVar1[0x50]; iVar2 = iVar2 + 1) {
    if (*(int *)(puVar1 + iVar2 * 4 + 0xc) == in_r4) {
      *(undefined4 *)(puVar1 + iVar2 * 4 + 0xc) = 0;
    }
  }
  return;
}

