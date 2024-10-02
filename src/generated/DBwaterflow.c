
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void DBwaterflow_initialise(undefined4 param) { //8029A678
  return;
}


/* @description Called when DLL is unloaded */

void DBwaterflow_release(void) { //8029A67C
  return;
}


/* Library Function - Single Match
    dll_27A_func03
   
   Library: KioskDefault 0 0 */

void DBwaterflow_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //8029A680
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  float *pfVar6;
  
  (this->pos).rotation.x = (short)((int)*(char *)&objDef[1].objType << 8);
  sVar2._0_1_ = objDef[1].loadFlags;
  sVar2._1_1_ = objDef[1].mapStates2;
  (this->pos).rotation.y = (short)((int)sVar2 << 8);
  pfVar6 = (float *)this->state;
  *(undefined *)(pfVar6 + 2) = 0;
  sVar3._0_1_ = objDef[1].bound;
  sVar3._1_1_ = objDef[1].cullDist;
  uVar5 = mainGetBit((int)sVar3);
  if (uVar5 != 0) {
    *(undefined *)(pfVar6 + 2) = 5;
  }
  pfVar6[1] = -100000.0;
  *pfVar6 = 100000.0;
  sVar4._0_1_ = objDef[1].allocatedSize;
  sVar4._1_1_ = objDef[1].mapStates1;
  if (sVar4 == 0) {
    fVar1 = pfVar6[1];
    pfVar6[1] = *pfVar6;
    *pfVar6 = fVar1;
  }
  return;
}


/* Library Function - Single Match
    dll_27A_func04
   
   Library: KioskDefault 0 0 */

void DBwaterflow_update(ObjInstance *this) { //8029A744
  byte bVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  ObjDef *pOVar13;
  undefined *puVar14;
  double dVar15;
  double local_30;
  
  pOVar13 = this->def;
  puVar14 = this->state;
  sVar3._0_1_ = pOVar13[1].allocatedSize;
  sVar3._1_1_ = pOVar13[1].mapStates1;
  iVar10 = sVar3 * 0x1c;
  if ((((*(short *)(puVar14 + 10) < 1) &&
       (*(ushort *)(puVar14 + 10) =
             (short)*(undefined4 *)(&DAT_80321bf4 + iVar10) + (ushort)framesThisStep,
       puVar14[8] != '\0')) && ((byte)puVar14[8] < 4)) &&
     ((puVar14[8] = puVar14[8] + '\x01', puVar14[8] == '\x02' &&
      (sVar4._0_1_ = pOVar13[1].allocatedSize, sVar4._1_1_ = pOVar13[1].mapStates1, sVar4 == 0)))) {
    mainSetBits(0x412,1);
  }
  *(ushort *)(puVar14 + 10) = *(short *)(puVar14 + 10) - (ushort)framesThisStep;
  if (*(short *)(puVar14 + 10) < 0) {
    *(undefined2 *)(puVar14 + 10) = 0;
  }
  sVar5._0_1_ = pOVar13[1].allocatedSize;
  sVar5._1_1_ = pOVar13[1].mapStates1;
  FUN_8029ac54((int)this,puVar14,(int)sVar5);
  uVar12 = *(uint *)(&DAT_80321bf4 + iVar10);
  bVar1 = puVar14[8];
  if (bVar1 == 3) {
    FUN_8029ad40();
    FUN_800689dc(127.0,(int)this,0x40,
                 (byte)(int)(((float)((double)CONCAT44(0x43300000,
                                                       (int)*(short *)(puVar14 + 10) ^ 0x80000000) -
                                     4503601774854144.0) * 127.0) /
                            (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) -
                                   4503601774854144.0)));
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      audioTryStartSfx((int *)this,0xc0,0x83,0x7f,"DBwaterflow.c",0xca);
      local_30 = (double)CONCAT44(0x43300000,(int)*(short *)(puVar14 + 10) ^ 0x80000000);
      dVar15 = (double)((float)(local_30 - 4503601774854144.0) /
                       (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - 4503601774854144.0
                              ));
      FUN_8029ad40();
      sVar6._0_1_ = pOVar13[1].allocatedSize;
      sVar6._1_1_ = pOVar13[1].mapStates1;
      if (sVar6 != 0) {
        *(short *)(puVar14 + 10) =
             *(short *)(puVar14 + 10) + (short)(int)(timeDelta * (float)(dVar15 * dVar15) * 0.6);
      }
    }
    else if (bVar1 == 0) {
      if ((true) && (uVar11 = mainGetBit((int)*(short *)&pOVar13[1].pos.x), uVar11 != 0)) {
        puVar14[8] = 1;
        audioTryStartSfx((int *)this,1,0x111,0x7f,"DBwaterflow.c",0xbb);
        puVar14[9] = (&DAT_80321bf8)[iVar10];
        *(short *)(puVar14 + 10) = (short)uVar12;
        FUN_8029ad40();
      }
    }
    else {
      sVar7._0_1_ = pOVar13[1].bound;
      sVar7._1_1_ = pOVar13[1].cullDist;
      mainSetBits((int)sVar7,1);
      FUN_8029ad40();
      if ((*(short *)(puVar14 + 10) == 0) &&
         (cVar2 = puVar14[9], puVar14[9] = cVar2 + -1, cVar2 == '\0')) {
        *(short *)(puVar14 + 10) = (short)uVar12;
      }
    }
  }
  else if (bVar1 == 5) {
    this->newOpacity = 0;
  }
  else if (bVar1 < 5) {
    FUN_80068a9c((uint)this,0x40);
    sVar8._0_1_ = pOVar13[1].allocatedSize;
    sVar8._1_1_ = pOVar13[1].mapStates1;
    if (sVar8 == 0) {
      puVar14[8] = 5;
    }
    else {
      mainSetBits((int)*(short *)&pOVar13[1].pos.x,0);
      sVar9._0_1_ = pOVar13[1].bound;
      sVar9._1_1_ = pOVar13[1].cullDist;
      mainSetBits((int)sVar9,0);
      puVar14[8] = 0;
    }
  }
  return;
}


/* @description Override hit detection */

void DBwaterflow_hitDetect(ObjInstance *this) { //8029ABBC
  return;
}


/* Library Function - Single Match
    dll_27A_func06
   
   Library: KioskDefault 0 0 */

void DBwaterflow_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //8029ABC0
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (((shouldRender) && (this->state[8] != '\0')) && ((byte)this->state[8] < 4)) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void DBwaterflow_free(ObjInstance *this,int param2) { //8029AC40
  return;
}


undefined4 DBwaterflow_func08(ObjInstance *this) { //8029AC44
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int DBwaterflow_getExtraSize(void) { //8029AC4C
  return 0xc;
}

