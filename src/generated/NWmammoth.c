
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void NWmammoth_initialise(undefined4 param) { //8024BFD4
  return;
}


/* @description Called when DLL is unloaded */

void NWmammoth_release(void) { //8024BFD8
  return;
}


/* Library Function - Single Match
    dll_1DD_func03
   
   Library: KioskDefault 0 0 */

void NWmammoth_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //8024BFDC
  byte bVar1;
  undefined *puVar2;
  undefined *local_14;
  
  puVar2 = this->state;
  local_14 = &DAT_01010101;
  (this->pos).rotation.x = (short)((int)(char)objDef[1].loadFlags << 8);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8024c718;
  if (obj2 != (ObjInstance *)0x0) {
    return;
  }
  Object_objAddObjectType(this,0xc);
  *(float *)(puVar2 + 0x50) = 0.005;
  *(ObjDefEnum *)(puVar2 + 4) = objDef[1].objType;
  *(short *)(puVar2 + 6) = *(short *)&objDef[1].allocatedSize * 0x3c;
  this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
  bVar1 = objDef[1].mapStates2;
  if (bVar1 != 3) {
    if ('\x02' < (char)bVar1) {
      if (bVar1 == 5) {
        FUN_8024dbe0(this,(int)puVar2);
      }
      else if ((char)bVar1 < '\x05') {
        FUN_8024d77c(this,(int)puVar2);
      }
      goto LAB_8024c100;
    }
    if (bVar1 != 1) {
      if ((char)bVar1 < '\x01') {
        if (-1 < (char)bVar1) {
          FUN_8024caf4(this,(int)puVar2,(int)objDef);
        }
      }
      else {
        FUN_8024cdd4(this,(int)puVar2);
      }
      goto LAB_8024c100;
    }
  }
  FUN_8024d340((int)this,(int)puVar2,(int)objDef);
LAB_8024c100:
  if ((puVar2[0x424] & 1) != 0) {
    puVar2 = puVar2 + 0x170;
                    /* {@symbol 8012ab10} */
    (**(code **)(*(int *)pDll1A + 4))(puVar2,0x6000000,0,1);
                    /* {@symbol 8012abb0} */
    (**(code **)(*(int *)pDll1A + 0xc))(puVar2,4,&DAT_8031a4c8,&DAT_8031a4f8,&local_14);
                    /* {@symbol 8012b80c} */
    (**(code **)(*(int *)pDll1A + 0x20))(this,puVar2);
  }
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa10;
  }
  return;
}


/* Library Function - Single Match
    dll_1DD_func04
   
   Library: KioskDefault 0 0 */

void NWmammoth_update(ObjInstance *this) { //8024C1B0
  byte bVar1;
  ObjInstance *param2;
  uint uVar2;
  undefined uVar4;
  int iVar3;
  ObjDef *pOVar5;
  undefined *puVar6;
  double dVar7;
  double extraout_f1;
  float afStack_44 [7];
  undefined auStack_28 [8];
  undefined4 local_20;
  uint uStack_1c;
  
  puVar6 = this->state;
  pOVar5 = this->def;
  param2 = Object_objGetMain();
  dVar7 = (double)objDistSqObj2ObjXZ(this,param2);
  uStack_1c = (int)*(short *)(puVar6 + 4) * (int)*(short *)(puVar6 + 4) ^ 0x80000000;
  local_20 = 0x43300000;
  if ((double)((float)((double)CONCAT44(0x43300000,uStack_1c) - 4503601774854144.0) * 2.0) <= dVar7)
  {
    if ((puVar6[0x424] & 0x80) != 0) {
      puVar6[0x424] = puVar6[0x424] & 0x7f;
    }
  }
  else if ((puVar6[0x424] & 0x80) == 0) {
    puVar6[0x424] = puVar6[0x424] | 0x80;
  }
  if ((puVar6[0x424] & 0x40) != 0) {
    FUN_8024ca68((int)this,(byte)puVar6[0x424] & 4);
    FUN_800927d4((short *)this,puVar6 + 0x400);
  }
  FUN_800928ac((int)this,(int)(puVar6 + 0x400));
  uVar2 = objHitReactFn_80089890
                    (this,-0x7fce5d68,0x1c,(uint)((*(ushort *)(puVar6 + 0xc) & 0x4000) != 0),
                     (float *)(puVar6 + 0x54));
  if ((uVar2 & 0xff) != 0) {
    *(ushort *)(puVar6 + 0xc) = *(ushort *)(puVar6 + 0xc) | 0x4000;
    return;
  }
  *(ushort *)(puVar6 + 0xc) = *(ushort *)(puVar6 + 0xc) & 0xbfff;
                    /* {@symbol 8012dfa8} */
  uVar4 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  puVar6[0x427] = uVar4;
                    /* {@symbol 800d2604} */
  DAT_80399f78 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_28);
  dVar7 = extraout_f1;
  if (((*(ushort *)(puVar6 + 0xc) & 0x8000) != 0) && (iVar3 = FUN_8024c7ec(this), iVar3 != 0)) {
    return;
  }
  objDistObj2Obj(this,param2);
  *(float *)(puVar6 + 0x20) = (float)dVar7;
  bVar1 = pOVar5[1].mapStates2;
  if (bVar1 != 3) {
    if ('\x02' < (char)bVar1) {
      if (bVar1 == 5) {
        nop_8024DBF4();
      }
      else if ((char)bVar1 < '\x05') {
        FUN_8024d808(this,(int)puVar6);
      }
      goto LAB_8024c3e0;
    }
    if (bVar1 != 1) {
      if ((char)bVar1 < '\x01') {
        if (-1 < (char)bVar1) {
          FUN_8024cb14(this,(int)puVar6);
        }
      }
      else {
        FUN_8024cde4(this);
      }
      goto LAB_8024c3e0;
    }
  }
  FUN_8024d504((short *)this,(int)puVar6);
LAB_8024c3e0:
  if ((puVar6[0x424] & 1) != 0) {
                    /* {@symbol 8012ac30} */
    (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,this,puVar6 + 0x170);
                    /* {@symbol 8012b0e4} */
    (**(code **)(*(int *)pDll1A + 0x14))(this,puVar6 + 0x170);
                    /* {@symbol 8012b170} */
    (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,this,puVar6 + 0x170);
  }
  if (*(int *)(puVar6 + 0x44) != 0) {
    uVar2 = *(ushort *)(puVar6 + 0xc) & 0xffff7fff;
    if (this->animId != *(word *)(*(int *)(puVar6 + 0x44) + uVar2 * 2)) {
      Object_ObjAnimSetMove(0.0,this,(int)*(short *)(*(int *)(puVar6 + 0x44) + uVar2 * 2),0);
      if (0.0 <= *(float *)(*(int *)(puVar6 + 0x48) + uVar2 * 4)) {
        *(undefined4 *)(puVar6 + 0x50) = *(undefined4 *)(*(int *)(puVar6 + 0x48) + uVar2 * 4);
      }
      puVar6[0x424] = puVar6[0x424] & 0xf7;
    }
    iVar3 = objRunAnimation((double)*(float *)(puVar6 + 0x50),(double)timeDelta,(int)this,afStack_44
                           );
    if (iVar3 == 0) {
      puVar6[0x424] = puVar6[0x424] & 0xf7;
    }
    else {
      puVar6[0x424] = puVar6[0x424] | 8;
    }
    objAnimFn_80087d88(this,(int)afStack_44);
  }
  if ((*(int *)(puVar6 + 0x4c) != 0) && ((this->flags_0xaf & CanPressAToTalk) != 0)) {
    if ((puVar6[0x424] & 0x20) == 0) {
      uVar2 = (uint)(byte)puVar6[0x425];
    }
    else {
      uVar2 = randInt(0,(byte)puVar6[0x426] - 1);
    }
    puVar6[0x425] = puVar6[0x425] + '\x01';
    if ((byte)puVar6[0x426] <= (byte)puVar6[0x425]) {
      puVar6[0x425] = 0;
    }
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))
              (*(undefined4 *)(*(int *)(puVar6 + 0x4c) + uVar2 * 4),this,0xffffffff);
    disableButtons(0,PAD_BUTTON_A);
  }
  return;
}


/* @description Override hit detection */

void NWmammoth_hitDetect(ObjInstance *this) { //8024C5BC
  return;
}


/* Library Function - Single Match
    dll_1DD_func06
   
   Library: KioskDefault 0 0 */

void NWmammoth_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //8024C5C0
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  ObjDef *pOVar1;
  undefined *puVar2;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  puVar2 = this->state;
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    objGetAttachPointWorldPos
              (this,1,(float *)(puVar2 + 0x14),(float *)(puVar2 + 0x18),(float *)(puVar2 + 0x1c),
               FALSE);
    if (((this->pos).flags & 0x100) != 0) {
      pOVar1 = this->def;
      FUN_80096374((double)(this->pos).pos.x,(double)((this->pos).pos.y - 4.0),
                   (double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)(short)pOVar1[1].objType ^ 0x80000000) -
                                  4503601774854144.0),124.0,param2_00,param3_00,0xff,0,0xff);
      FUN_80096374((double)(this->pos).pos.x,(double)((this->pos).pos.y - 4.0),
                   (double)(this->pos).pos.z,
                   (double)((float)((double)CONCAT44(0x43300000,
                                                     (int)(short)pOVar1[1].objType ^ 0x80000000) -
                                   4503601774854144.0) * 2.0),124.0,param2_00,param3_00,0,0xff,0xff)
      ;
    }
  }
  return;
}


/* @description Free object instance */

void NWmammoth_free(ObjInstance *this,int param2) { //8024C6FC
  DAT_80399f79 = 0;
  return;
}


undefined4 NWmammoth_func08(ObjInstance *this) { //8024C708
  return 0xcb;
}


/* @description Get extra size for object (size of State struct) */

int NWmammoth_getExtraSize(void) { //8024C710
  return 0x42c;
}

