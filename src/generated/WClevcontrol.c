
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void WClevcontrol_initialise(undefined4 param) { //802C1984
  return;
}


/* @description Called when DLL is unloaded */

void WClevcontrol_release(void) { //802C1988
  return;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func03
   
   Library: KioskDefault 0 0 */

void WClevcontrol_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //802C198C
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802c28a4;
  FUN_802c2fd4();
  FUN_802c3014();
  uVar1 = mainGetBit(0x7fa);
  if (uVar1 != 0) {
    puVar2[5] = puVar2[5] | 8;
  }
  uVar1 = mainGetBit(0x7f9);
  if (uVar1 != 0) {
    puVar2[5] = puVar2[5] | 4;
  }
  uVar1 = mainGetBit(0x813);
  if (uVar1 != 0) {
    puVar2[5] = puVar2[5] | 0x20;
  }
  uVar1 = mainGetBit(0x812);
  if (uVar1 != 0) {
    puVar2[5] = puVar2[5] | 0x10;
  }
  uVar1 = mainGetBit(0x2a5);
  if (uVar1 != 0) {
    puVar2[5] = puVar2[5] | 0x40;
  }
  Object_objAddObjectType(this,10);
  mainSetBits(0x226,1);
  mainSetBits(0x2a6,1);
  mainSetBits(0x206,1);
  mainSetBits(0x25f,1);
  return;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func04
   
   Library: KioskDefault 0 0 */

void WClevcontrol_update(ObjInstance *this) { //802C1A94
  char cVar2;
  int iVar1;
  float *pfVar3;
  undefined auStack_c [4];
  
  pfVar3 = (float *)this->state;
  if (this->field76_0xf4 == 0) {
    loadEnvfxAction(this,this,0x1fb,0);
    loadEnvfxAction(this,this,0x1fc,0);
    loadEnvfxAction(this,this,0x149,0);
    loadLfxAction(this,this,0x97);
    loadLfxAction(this,this,0x24f);
    this->field76_0xf4 = 1;
  }
                    /* {@symbol 8012dfa8} */
  cVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)this->mapId);
  if (cVar2 == '\x02') {
    FUN_802c2d44(this,(int)pfVar3);
  }
  else {
    FUN_802c299c(this,pfVar3);
  }
                    /* {@symbol 800d2604} */
  iVar1 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_c);
  if (iVar1 == 0) {
    mainSetBits(0x7f3,0);
    mainSetBits(0x7f1,1);
  }
  else {
    mainSetBits(0x7f3,1);
    mainSetBits(0x7f1,0);
  }
  return;
}


/* @description Override hit detection */

void WClevcontrol_hitDetect(ObjInstance *this) { //802C1BE0
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void WClevcontrol_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802C1BE4
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
    VFlevcontrol_func07
    dll_2CC_func07
    dll_2E7_func07
    sunMoonBlockPuzzle_func07
   
   Library: KioskDefault 0 0 */

void WClevcontrol_free(ObjInstance *this,int param2) { //802C1C40
  Object_removePlayerObj(this,10);
  return;
}


undefined4 WClevcontrol_func08(ObjInstance *this) { //802C1C6C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int WClevcontrol_getExtraSize(void) { //802C1C74
  return 8;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func0A
   
   Library: KioskDefault 0 0 */

void WClevcontrol_setScale(ObjInstance *this,float scale) { //802C1C7C
  short in_r4;
  short in_r5;
  float *in_r6;
  float *in_r7;
  float local_20;
  float local_1c [6];
  
  FUN_800a8f5c((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
               local_1c,&local_20);
  *in_r6 = local_1c[0] + 32.0 +
           (float)((double)CONCAT44(0x43300000,in_r4 * 0x30 ^ 0x80000000) - 4503601774854144.0) +
           24.0;
  *in_r7 = local_20 + 129.0 +
           (float)((double)CONCAT44(0x43300000,in_r5 * 0x30 ^ 0x80000000) - 4503601774854144.0) +
           24.0;
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    sunMoonBlockPuzzle_func0B
    sunMoonBlockPuzzle_func12
   
   Library: KioskDefault 0 0 */

void WClevcontrol_func0B(double param1,double param2,int param3,short *param4,short *param5) { //802C1D54
  float local_24;
  float local_20 [7];
  
  FUN_800a8f5c((double)*(float *)(param3 + 0xc),(double)*(float *)(param3 + 0x10),
               (double)*(float *)(param3 + 0x14),local_20,&local_24);
  *param4 = (short)(int)(((float)param1 - local_20[0]) - 32.0) / 0x30;
  *param5 = (short)(int)(((float)param2 - local_24) - 129.0) / 0x30;
  return;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func0C
   
   Library: KioskDefault 0 0 */

void WClevcontrol_modelMtxFn(ObjInstance *this,undefined4 param2,vec3f *param3) { //802C1E14
  short sVar1;
  
  if ((((-1 < param2._2_2_) && (param2._2_2_ < 8)) && (sVar1 = (short)param3, -1 < sVar1)) &&
     (sVar1 < 8)) {
    (&DAT_80396668)[(int)sVar1 + param2._2_2_ * 8] = (char)this;
    return;
  }
  printf("SUNBLOCK: invalid grid position");
  return;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func0D
   
   Library: KioskDefault 0 0 */

undefined WClevcontrol_render2(ObjInstance *this) { //802C1EA4
  short in_r4;
  short sVar1;
  
  sVar1 = (short)this;
  if ((((-1 < sVar1) && (sVar1 < 8)) && (-1 < in_r4)) && (in_r4 < 8)) {
    return (&DAT_80396668)[(int)in_r4 + sVar1 * 8];
  }
  printf("SUNBLOCK: invalid grid position");
  return 0;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func0E
   
   Library: KioskDefault 0 0 */

void WClevcontrol_func0E(ushort id,undefined2 *param2,undefined2 *param3) { //802C1F30
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (7 < iVar2) {
      printf("SUN GRID PUZZLE: Error cannot find given id");
      return;
    }
    for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
      if (id == (byte)(&DAT_80324728)[iVar1 + iVar2 * 8]) {
        *param2 = (short)iVar2;
        *param3 = (short)iVar1;
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func0F
   
   Library: KioskDefault 0 0 */

void WClevcontrol_func0F(ushort id,undefined2 *param2,undefined2 *param3) { //802C1FD8
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (7 < iVar2) {
      printf("SUN GRID PUZZLE: Error cannot find given id");
      return;
    }
    for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
      if (id == (byte)(&DAT_80324768)[iVar1 + iVar2 * 8]) {
        *param2 = (short)iVar2;
        *param3 = (short)iVar1;
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func10
   
   Library: KioskDefault 0 0 */

undefined4
WClevcontrol_func10
          (float param_1,ObjInstance *param1,short param2,short param3,undefined4 param_5,
          undefined4 param_6,int param6,int param7) { //802C2080
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (param6 == 0) {
    if (param7 == -1) {
      setScale(param1,param_1);
      sVar1 = 1;
      iVar2 = 8;
    }
    else {
      setScale(param1,param_1);
      sVar1 = -1;
      iVar2 = -1;
    }
    for (iVar3 = (int)(short)(param3 + sVar1); iVar3 != iVar2; iVar3 = iVar3 - param7) {
      if ((&DAT_80396668)[param2 * 8 + iVar3] != '\0') {
        if ((byte)(&DAT_80396668)[param2 * 8 + iVar3] < 5) {
          setScale(param1,param_1);
          return 1;
        }
        setScale(param1,param_1);
        return 2;
      }
    }
  }
  else {
    if (param6 == -1) {
      setScale(param1,param_1);
      sVar1 = 1;
      iVar2 = 8;
    }
    else {
      setScale(param1,param_1);
      sVar1 = -1;
      iVar2 = -1;
    }
    for (iVar3 = (int)(short)(param2 + sVar1); iVar3 != iVar2; iVar3 = iVar3 - param6) {
      if ((&DAT_80396668)[iVar3 * 8 + (int)param3] != '\0') {
        if ((byte)(&DAT_80396668)[iVar3 * 8 + (int)param3] < 5) {
          setScale(param1,param_1);
          return 1;
        }
        setScale(param1,param_1);
        return 2;
      }
    }
  }
  return 4;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func11
   
   Library: KioskDefault 0 0 */

void WCLevelCont_setScale(int param1,short param2,short param3,float *param4,float *param5) { //802C2288
  float local_20;
  float local_1c [6];
  
  FUN_800a8f5c((double)*(float *)(param1 + 0xc),(double)*(float *)(param1 + 0x10),
               (double)*(float *)(param1 + 0x14),local_1c,&local_20);
  *param4 = local_1c[0] + 224.0 +
            (float)((double)CONCAT44(0x43300000,param2 * 0x30 ^ 0x80000000) - 4503601774854144.0) +
            24.0;
  *param5 = local_20 + 128.0 +
            (float)((double)CONCAT44(0x43300000,param3 * 0x30 ^ 0x80000000) - 4503601774854144.0) +
            24.0;
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    sunMoonBlockPuzzle_func0B
    sunMoonBlockPuzzle_func12
   
   Library: KioskDefault 0 0 */

void WClevcontrol_func12(double param1,double param2,int param3,short *param4,short *param5) { //802C2360
  float local_24;
  float local_20 [7];
  
  FUN_800a8f5c((double)*(float *)(param3 + 0xc),(double)*(float *)(param3 + 0x10),
               (double)*(float *)(param3 + 0x14),local_20,&local_24);
  *param4 = (short)(int)(((float)param1 - local_20[0]) - 224.0) / 0x30;
  *param5 = (short)(int)(((float)param2 - local_24) - 128.0) / 0x30;
  return;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func13
   
   Library: KioskDefault 0 0 */

void WClevcontrol_func13(undefined param1,short param2,short param3) { //802C2420
  if ((((-1 < param2) && (param2 < 8)) && (-1 < param3)) && (param3 < 8)) {
    (&DAT_803966a8)[(int)param3 + param2 * 8] = param1;
    return;
  }
  printf("MOONBLOCK: invalid grid position");
  return;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func14
   
   Library: KioskDefault 0 0 */

undefined WClevcontrol_func14(short param1,short param2) { //802C24B0
  if ((((-1 < param1) && (param1 < 8)) && (-1 < param2)) && (param2 < 8)) {
    return (&DAT_803966a8)[(int)param2 + param1 * 8];
  }
  printf("MOONBLOCK: invalid grid position");
  return 0;
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func15
   
   Library: KioskDefault 0 0 */

void WClevcontrol_func15(ushort param1,undefined2 *param2,undefined2 *param3) { //802C253C
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (7 < iVar2) {
      printf("MOON GRID PUZZLE: Error cannot find given id");
      return;
    }
    for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
      if (param1 == (byte)(&DAT_803247a8)[iVar1 + iVar2 * 8]) {
        *param2 = (short)iVar2;
        *param3 = (short)iVar1;
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func16
   
   Library: KioskDefault 0 0 */

void WClevcontrol_func16(ushort param1,undefined2 *param2,undefined2 *param3) { //802C25E4
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (7 < iVar2) {
      printf("MOON GRID PUZZLE: Error cannot find given id");
      return;
    }
    for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
      if (param1 == (byte)(&DAT_803247e8)[iVar1 + iVar2 * 8]) {
        *param2 = (short)iVar2;
        *param3 = (short)iVar1;
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


/* Library Function - Single Match
    sunMoonBlockPuzzle_func17
   
   Library: KioskDefault 0 0 */

undefined4
WClevcontrol_func17
          (int param1,short param2,short param3,float *param4,float *param5,int param6,int param7) { //802C268C
  short sVar1;
  int iVar2;
  int iVar3;
  float afStack_38 [3];
  
  if (param6 == 0) {
    if (param7 == -1) {
      WCLevelCont_setScale(param1,param2,7,param4,param5);
      sVar1 = 1;
      iVar2 = 8;
    }
    else {
      WCLevelCont_setScale(param1,param2,0,param4,param5);
      sVar1 = -1;
      iVar2 = -1;
    }
    for (iVar3 = (int)(short)(param3 + sVar1); iVar3 != iVar2; iVar3 = iVar3 - param7) {
      if ((&DAT_803966a8)[param2 * 8 + iVar3] != '\0') {
        if ((byte)(&DAT_803966a8)[param2 * 8 + iVar3] < 5) {
          WCLevelCont_setScale(param1,param2,(short)iVar3 + (short)param7,afStack_38,param5);
          return 1;
        }
        WCLevelCont_setScale(param1,param2,(short)iVar3,afStack_38,param5);
        return 2;
      }
    }
  }
  else {
    if (param6 == -1) {
      WCLevelCont_setScale(param1,7,param3,param4,param5);
      sVar1 = 1;
      iVar2 = 8;
    }
    else {
      WCLevelCont_setScale(param1,0,param3,param4,param5);
      sVar1 = -1;
      iVar2 = -1;
    }
    for (iVar3 = (int)(short)(param2 + sVar1); iVar3 != iVar2; iVar3 = iVar3 - param6) {
      if ((&DAT_803966a8)[iVar3 * 8 + (int)param3] != '\0') {
        if ((byte)(&DAT_803966a8)[iVar3 * 8 + (int)param3] < 5) {
          WCLevelCont_setScale(param1,(short)iVar3 + (short)param6,param3,param4,afStack_38);
          return 1;
        }
        WCLevelCont_setScale(param1,(short)iVar3,param3,param4,afStack_38);
        return 2;
      }
    }
  }
  return 4;
}

