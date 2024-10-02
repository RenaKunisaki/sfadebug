
/* Library Function - Single Match
    gplay_func00
   
   Library: KioskDefault 0 0 */

void gplay_initialise(undefined4 param) { //8012CF08
  pCurSaveGame = (undefined *)mmAlloc(0x2000,INTERSECT_POINT,"flash");
  FUN_8012de80();
  pRestartPoint = 0;
  PTR_DAT_803993a0 = (undefined *)mmAlloc(0x2000,INTERSECT_POINT,"flash");
  lastMapWhoseActChanged = ~animtest;
  lastMapWhoseObjGroupChanged = ~animtest;
  return;
}


/* Library Function - Single Match
    gplay_func01
   
   Library: KioskDefault 0 0 */

void gplay_release(void) { //8012CF70
  mm_free(pCurSaveGame);
  if (pRestartPoint != (void *)0x0) {
    mm_free(pRestartPoint);
  }
  mm_free(PTR_DAT_803993a0);
  return;
}


void gplay_func03(void) { //8012CFB0
  return;
}


/* Library Function - Single Match
    gplay_func04
   
   Library: KioskDefault 0 0 */

int gplay_newgame(char *name) { //8012CFB4
  char cVar1;
  N64Button NVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  FUN_8012de80();
  curCharacter = 0;
  for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
    saveData[iVar5].maxHealth = 0xc;
    saveData[iVar5].field_0x2 = 0xc;
    saveData[iVar5].maxMagic = 100;
    saveData[iVar5].curMagic = 0;
    (&DAT_80388340)[iVar5 * 4] = 4;
    (&DAT_80388341)[iVar5 * 4] = 5;
    (&DAT_80388340)[iVar5 * 4] = 0xc;
    (&DAT_80389a1c)[iVar5 * 10] = 0xffff;
    (&DAT_80389a1e)[iVar5 * 10] = 0xffff;
    (&DAT_80389a20)[iVar5 * 10] = 0xffff;
    (&DAT_80389a22)[iVar5 * 10] = 0xffff;
    (&DAT_80389a24)[iVar5 * 10] = 0xffff;
    (&DAT_80389a26)[iVar5 * 10] = 0xffff;
    (&DAT_80389a28)[iVar5 * 10] = 0xffff;
    (&DAT_80389a2a)[iVar5 * 10] = 0xffff;
    (&DAT_80389a2e)[iVar5 * 10] = 0xffff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field0_0x0 = 43000.0;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field1_0x4 = 0xffff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field2_0x6 = 0xffff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field3_0x8 = 0xffff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field4_0xa = 0xffff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field5_0xc = 0xffff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field6_0xe = 0xffff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field_0x3d = 0xff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field_0x3e = 0xff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field_0x3f = 0xff;
    PlayerEnvAction_ARRAY_80389a44[iVar5].field_0x3c = 1;
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
      *(undefined2 *)(pCurSaveGame + iVar5 * 8 + iVar4 * 2 + 0x179c) = 0xffff;
    }
  }
  for (iVar5 = 0; iVar5 < 0x78; iVar5 = iVar5 + 1) {
    if (mapActBitIdx[iVar5] != 0) {
                    /* {@symbol 8012decc} */
      (**(code **)(*(int *)pDll_SaveGame + 0x44))(iVar5,1);
    }
  }
  mainSetBits(0x4e5,1);
  NVar2 = n64GetEnabledButtonsHeld(0);
  if ((NVar2 & N64_BUTTON_Z) == 0) {
    mainSetBits(0x4e4,1);
    mainSetBits(0x25,1);
    mainSetBits(0xdd,1);
    mainSetBits(0x9e,1);
    mainSetBits(0x245,1);
    mainSetBits(0x2c5,1);
    mainSetBits(0x8bb,1);
  }
  (&charPos)[curCharacter].pos.x = 13896.0;
  (&charPos)[curCharacter].pos.y = 211.0;
  (&charPos)[curCharacter].pos.z = 88.0;
  if (name == (char *)0x0) {
    DAT_80388618 = 0x46;
    DAT_80388619 = 0x4f;
    DAT_8038861a = 0x58;
    DAT_8038861b = 0;
    name = (char *)0x0;
  }
  else {
    pcVar3 = &DAT_80388618;
    do {
      cVar1 = *name;
      *pcVar3 = cVar1;
      name = name + 1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  memcpy_src_dst_len(saveData,pCurSaveGame,0x17ac);
  if (name == (char *)0x0) {
    iVar5 = 1;
  }
  else {
    iVar5 = cardFn_800c8144(pCurSaveGame);
  }
  return iVar5;
}


/* Library Function - Single Match
    gplay_func05
   
   Library: KioskDefault 0 0 */

undefined4 gplay_func05(uint *param1,char param2) { //8012D348
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_800c7ce4(param1,pCurSaveGame);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (param2 == '\0') {
      memcpy_src_dst_len(pCurSaveGame,saveData,0x17ac);
    }
    else {
      gotoSavegame();
    }
    uVar2 = 1;
  }
  return uVar2;
}


void gplay_func06(void) { //8012D3B4
  return;
}


/* Library Function - Single Match
    gplay_func07
   
   Library: KioskDefault 0 0 */

void gplay_func07(void) { //8012D3B8
  DAT_80388620 = DAT_80388620 + '\x01';
  memcpy_src_dst_len(saveData,pCurSaveGame,0x13d4);
  cardFn_800c81e8(pCurSaveGame);
  if (pRestartPoint != (void *)0x0) {
    memcpy_src_dst_len(saveData,pRestartPoint,0x15d4);
  }
  return;
}


/* Library Function - Single Match
    gplay_loadOptions
   
   Library: KioskDefault 0 0 */

bool gplay_loadOptions(void) { //8012D424
  int iVar1;
  
  iVar1 = FUN_800c82d4(PTR_DAT_803993a0);
  if (iVar1 == 0) {
    OSReport("gplayLoadOptions error: saveoptions failed to load.");
    memclr(PTR_DAT_803993a0,0x2000);
    PTR_DAT_803993a0[8] = 0x7f;
    PTR_DAT_803993a0[9] = 0x7f;
    PTR_DAT_803993a0[10] = 0x7f;
  }
  *PTR_DAT_803993a0 = 0;
  if ((char)PTR_DAT_803993a0[0xb] < -7) {
    PTR_DAT_803993a0[0xb] = 0xf9;
  }
  if ('\a' < (char)PTR_DAT_803993a0[0xb]) {
    PTR_DAT_803993a0[0xb] = 7;
  }
  if ((char)PTR_DAT_803993a0[0xc] < -7) {
    PTR_DAT_803993a0[0xc] = 0xf9;
  }
  if ('\a' < (char)PTR_DAT_803993a0[0xc]) {
    PTR_DAT_803993a0[0xc] = 7;
  }
  return iVar1 != 0;
}


void gplay_func0F(void) { //8012D534
  cardSADPfn_800c837c(PTR_DAT_803993a0);
  return;
}


undefined * gplay_func11(void) { //8012D558
  return PTR_DAT_803993a0;
}


/* Library Function - Single Match
    gplay_func08
   
   Library: KioskDefault 0 0 */

void gplay_func08(void) { //8012D560
  ObjInstance *pOVar1;
  
  pOVar1 = Object_objGetMain();
  if (pOVar1 != (ObjInstance *)0x0) {
                    /* {@symbol 8012d5d4} */
    (**(code **)(*(int *)pDll_SaveGame + 0x1c))
              (&(pOVar1->pos).pos,(int)((pOVar1->pos).rotation.x >> 8),0,0);
                    /* {@symbol 8012d3b8} */
    (**(code **)(*(int *)pDll_SaveGame + 0x14))();
  }
  return;
}


/* Library Function - Single Match
    gplay_func09
   
   Library: KioskDefault 0 0 */

void gplay_func09(vec3f *pos,undefined2 rotX,uint flags,undefined field0D) { //8012D5D4
  if ((flags & 1) == 0) {
    (&charPos)[curCharacter].pos.x = pos->x;
    (&charPos)[curCharacter].pos.y = pos->y;
    (&charPos)[curCharacter].pos.z = pos->z;
    (&charPos)[curCharacter].rotX = (s8)((ushort)rotX >> 8);
    (&charPos)[curCharacter].field_0xd = field0D;
    memcpy_src_dst_len(saveData,pCurSaveGame,0x17ac);
  }
  else {
    memcpy_src_dst_len(saveData,pCurSaveGame,0x15d4);
  }
  if (pRestartPoint != (void *)0x0) {
    memcpy_src_dst_len(saveData,pRestartPoint,0x15d4);
  }
  return;
}


/* Library Function - Single Match
    gplay_func0A
   
   Library: KioskDefault 0 0 */

void gplay_gotoSavegame(void) { //8012D6CC
  memcpy_src_dst_len(pCurSaveGame,saveData,0x17ac);
  loadMapForCurrentSaveGame();
  return;
}


/* Library Function - Single Match
    gplay_restartPoint
   
   Library: KioskDefault 0 0 */

void gplay_restartPoint(undefined4 *param1,undefined2 param2,undefined param3,int param4) { //8012D700
  if ((pRestartPoint == (void *)0x0) &&
     (pRestartPoint = mmAlloc(0x17ac,INTERSECT_POINT,"flash"), pRestartPoint == (void *)0x0
     )) {
    printf(" WARNING : Not Enough Memort for Restart Point ");
    return;
  }
  if (param4 != 0) {
    mainSetBits(0x970,1);
  }
  memcpy_src_dst_len(saveData,pRestartPoint,0x17ac);
  *(undefined4 *)((int)pRestartPoint + (uint)*(byte *)((int)pRestartPoint + 0x2f7) * 0x10 + 0x16d4)
       = *param1;
  *(undefined4 *)((int)pRestartPoint + (uint)*(byte *)((int)pRestartPoint + 0x2f7) * 0x10 + 0x16d8)
       = param1[1];
  *(undefined4 *)
   ((int)pRestartPoint + (int)(&DAT_000016dc + (uint)*(byte *)((int)pRestartPoint + 0x2f7) * 0x10))
       = param1[2];
  *(char *)((int)pRestartPoint + (uint)*(byte *)((int)pRestartPoint + 0x2f7) * 0x10 + 0x16e0) =
       (char)((ushort)param2 >> 8);
  *(undefined *)((int)pRestartPoint + (uint)curCharacter * 0x10 + 0x16e1) = param3;
  mainSetBits(0x970,0);
  return;
}


/* Library Function - Single Match
    gplay_gotoRestartPoint
   
   Library: KioskDefault 0 0 */

void gplay_gotoRestartPoint(void) { //8012D84C
  if (pRestartPoint == (void *)0x0) {
    printf("WARNING gplay : Restart Point Not Set ");
  }
  else {
    memcpy_src_dst_len(pRestartPoint,saveData,0x17ac);
    loadMapForCurrentSaveGame();
  }
  return;
}


/* Library Function - Single Match
    gplay_func0D
   
   Library: KioskDefault 0 0 */

void gplay_func0D(void) { //8012D8A0
  if (pRestartPoint != (void *)0x0) {
    mm_free(pRestartPoint);
    pRestartPoint = (void *)0x0;
  }
  return;
}


bool gplay_func0E(void) { //8012D8D8
  return (bool)('\x01' - (pRestartPoint == 0));
}


PlayerCharState * gplay_func24(void) { //8012D994
  return saveData;
}


undefined gplay_func1F(void) { //8012D9A0
  return curCharacter;
}


/* Library Function - Single Match
    gplay_setPlayerNo
   
   Library: KioskDefault 0 0 */

void gplay_setPlayerNo(undefined param1) { //8012D9B0
  if (1 < curCharacter) {
    OSReport("playerno set to %d!",(uint)curCharacter);
  }
  curCharacter = param1;
  return;
}


PlayerCharState * gplay_getCurCharacterState(void) { //8012DA08
  return saveData + curCharacter;
}


CharPos * gplay_getCurCharPos(void) { //8012DA28
  return &charPos + curCharacter;
}


undefined1 * gplay_func27(void) { //8012DA4C
  return &DAT_80388340 + (uint)curCharacter * 4;
}


/* Library Function - Single Match
    gplay_getCurrentPlayerLactions
   
   Library: KioskDefault 0 0 */

undefined2 * gplay_getCurrentPlayerLactions(void) { //8012DA70
  undefined2 *puVar1;
  
  if (curCharacter < 2) {
    puVar1 = &DAT_80389a1c + (uint)curCharacter * 10;
  }
  else {
    OSReport("gameplay.c: gplayGetCurrentPlayerLactions: playerno overflow");
    puVar1 = &DAT_80389a1c;
  }
  return puVar1;
}


/* Library Function - Single Match
    gplay_getCurrentPlayerEnvactions
   
   Library: KioskDefault 0 0 */

PlayerEnvAction * gplay_getCurrentPlayerEnvactions(void) { //8012DAD0
  PlayerEnvAction *pPVar1;
  
  if (curCharacter < 2) {
    pPVar1 = PlayerEnvAction_ARRAY_80389a44 + curCharacter;
  }
  else {
    OSReport("gameplay.c: gplayGetCurrentPlayerEnvactions: playerno overflow");
    pPVar1 = PlayerEnvAction_ARRAY_80389a44;
  }
  return pPVar1;
}


int gplay_func2A(void) { //8012DB30
  return (uint)curCharacter * 8 + -0x7fc7653c;
}


void gplay_addTime(double param1,int param2) { //8012DB54
  float fVar1;
  int iVar2;
  
  if (DAT_8038862a == 0x100) {
    debugPrint("gplayAddTime: MAX_TIMESAVES reached");
  }
  else {
    fVar1 = (float)(param1 * 20.0) + DAT_80388624;
    for (iVar2 = 0; (iVar2 < DAT_8038862a && ((&DAT_80388dfc)[iVar2 * 2] != param2));
        iVar2 = iVar2 + 1) {
    }
    if (iVar2 == DAT_8038862a) {
      DAT_8038862a = DAT_8038862a + 1;
    }
    (&DAT_80388dfc)[iVar2 * 2] = param2;
    (&DAT_80388e00)[iVar2 * 2] = fVar1;
  }
  return;
}


/* Library Function - Single Match
    gplay_func1C
   
   Library: KioskDefault 0 0 */

undefined4 gplay_func1C(int param1) { //8012DC1C
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (DAT_8038862a <= iVar1) {
      return 1;
    }
    if ((&DAT_80388dfc)[iVar1 * 2] == param1) break;
    iVar1 = iVar1 + 1;
  }
  return 0;
}


/* Library Function - Single Match
    gplay_func1D
   
   Library: KioskDefault 0 0 */

double gplay_func1D(int param1) { //8012DC78
  float fVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (DAT_8038862a <= iVar2) {
      fVar1 = 0.0;
LAB_8012dcd0:
      return (double)fVar1;
    }
    if ((&DAT_80388dfc)[iVar2 * 2] == param1) {
      fVar1 = (float)(&DAT_80388e00)[iVar2 * 2] - DAT_80388624;
      goto LAB_8012dcd0;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


/* Library Function - Single Match
    gplay_func1E
   
   Library: KioskDefault 0 0 */

void gplay_updateTimes(int param1,int time) { //8012DCDC
  N64Button NVar2;
  BOOL BVar1;
  int extraout_r4;
  int iVar3;
  
  iVar3 = 0;
  NVar2 = n64GetEnabledButtonsHeld(3);
  if (((NVar2 & N64_BUTTON_START) != 0) && (DAT_803993b0 == 0)) {
    DAT_803993b0 = 10;
                    /* {@symbol 8012d3b8} */
    (**(code **)(*(int *)pDll_SaveGame + 0x14))();
    time = extraout_r4;
  }
  DAT_803993b0 = DAT_803993b0 + -1;
  if (DAT_803993b0 < 0) {
    DAT_803993b0 = 0;
  }
  DAT_80388624 = DAT_80388624 + timeDelta;
  while (iVar3 < DAT_8038862a) {
    if (DAT_80388624 <= (float)(&DAT_80388e00)[iVar3 * 2]) {
      iVar3 = iVar3 + 1;
    }
    else {
      DAT_8038862a = DAT_8038862a + -1;
      time = (&DAT_80388dfc)[DAT_8038862a * 2];
      (&DAT_80388dfc)[iVar3 * 2] = time;
      (&DAT_80388e00)[iVar3 * 2] = (&DAT_80388e00)[DAT_8038862a * 2];
    }
  }
  BVar1 = isShowObjTimeTable();
  if (BVar1 != FALSE) {
    diPrintf("time: %d",time);
    for (iVar3 = 0; iVar3 < DAT_8038862a; iVar3 = iVar3 + 1) {
    }
  }
  return;
}


int gplay_func22(void) { //8012DE20
  return (int)DAT_80388628;
}


void gplay_func23(undefined2 param1) { //8012DE30
  DAT_80388628 = param1;
  return;
}


undefined * gplay_func21(void) { //8012DE44
  return &DAT_8038862c;
}


/* Library Function - Single Match
    gplay_func2D
   
   Library: KioskDefault 0 0 */

void gplay_func2D(void) { //8012DE54
  __cvt_fp2unsigned((double)DAT_80388624);
  return;
}


void gplay_func14(u8 param1,int param2) { //8012DEB8
  mapActLut[param2] = param1;
  return;
}


/* Library Function - Single Match
    gplay_setAct
   
   Library: KioskDefault 0 0 */

void gplay_setAct(int mapNo,int actNo) { //8012DECC
  if (0x4f < mapNo) {
    mapNo = (int)mapActLut[mapNo];
  }
  if (mapNo < 0x78) {
    if (mapNo < 0) {
      printf("gplaySetAct error: negative mapno (%d)",mapNo);
    }
    else if ((mapActBitIdx[mapNo] == 0) && (mapNo != 1)) {
      printf("gplaySetAct: mapno(%d) doesn't have an entry in the bitflags",mapNo);
    }
    else {
      mainSetBits((uint)mapActBitIdx[mapNo],actNo);
      lastMapWhoseActChanged = (mapId8)mapNo;
      curMapAct = (undefined)actNo;
      func18(mapNo);
    }
  }
  else {
    printf("gplaySetAct error: mapno (%d) number too high!",mapNo);
  }
  return;
}


/* Library Function - Single Match
    gplay_func12
   
   Library: KioskDefault 0 0 */

s8 gplay_getAct(int mapNo) { //8012DFA8
  uint uVar1;
  
  if (0x4f < mapNo) {
    mapNo = (int)mapActLut[mapNo];
  }
  if (mapNo != (char)lastMapWhoseActChanged) {
    lastMapWhoseActChanged = (mapId8)mapNo;
    if (((mapNo < 0) || (0x77 < mapNo)) || (mapActBitIdx[mapNo] == 0)) {
      curMapAct = '\0';
    }
    else {
      uVar1 = mainGetBit((uint)mapActBitIdx[mapNo]);
      curMapAct = (s8)uVar1;
    }
  }
  return curMapAct;
}


/* Library Function - Single Match
    gplay_getObjGroupStatus
   
   Library: KioskDefault 0 0 */

uint gplay_getObjGroupStatus(mapId32 param1,uint param2) { //8012E068
  uint uVar1;
  
  if (0x4f < (int)param1) {
    param1 = (mapId32)mapActLut[param1];
  }
  if (((int)param1 < 0x78) && ((&DAT_802f9e08)[param1] != 0)) {
    if (param1 != lastMapWhoseObjGroupChanged) {
      lastMapWhoseObjGroupChanged = param1;
      DAT_803993ac = mainGetBit((uint)(ushort)(&DAT_802f9e08)[param1]);
    }
    uVar1 = (int)DAT_803993ac >> (param2 & 0x3f) & 1;
  }
  else {
    printf("Error in gplayGetObjGroupStatus (mapno %d, groupno %d)",param1,param2);
    uVar1 = 0;
  }
  return uVar1;
}


undefined2 gplay_func17(int param1) { //8012E124
  return (&DAT_802f9e08)[param1];
}


/* Library Function - Single Match
    gplay_func18
   
   Library: KioskDefault 0 0 */

void gplay_func18(uint param1) { //8012E13C
  uint uVar1;
  
  if (0x4f < (int)param1) {
    param1 = (uint)mapActLut[param1];
  }
  if ((&DAT_802f9e08)[param1] != 0) {
    uVar1 = mainGetBit((uint)(ushort)(&DAT_802f9e08)[param1]);
    (&DAT_80389b7c)[param1] = uVar1;
  }
  return;
}


/* Library Function - Single Match
    gplay_func19
   
   Library: KioskDefault 0 0 */

undefined4 gplay_func19(uint param1) { //8012E1C4
  if (0x4f < (int)param1) {
    param1 = (uint)mapActLut[param1];
  }
  return (&DAT_80389b7c)[param1];
}


/* Library Function - Single Match
    gplay_func1A
   
   Library: KioskDefault 0 0 */

void gplay_func1A(uint param1) { //8012E1F4
  if (0x4f < (int)param1) {
    param1 = (uint)mapActLut[param1];
  }
  (&DAT_80389b7c)[param1] = 0;
  return;
}


/* Library Function - Single Match
    gplay_setObjGroupStatus
   
   Library: KioskDefault 0 0 */

void gplay_setObjGroupStatus(mapId32 mapNo,int groupNo,int status) { //8012E228
  uint uVar1;
  uint value;
  int iVar2;
  
  if (0x4f < (int)mapNo) {
    mapNo = (mapId32)mapActLut[mapNo];
  }
  if (((int)mapNo < 0x78) && ((&DAT_802f9e08)[mapNo] != 0)) {
    if (status == -1) {
      status = 1;
    }
    if (status == -2) {
      status = 0;
    }
    uVar1 = mainGetBit((uint)(ushort)(&DAT_802f9e08)[mapNo]);
    if (status == 0) {
      value = uVar1 & ~(1 << groupNo);
    }
    else {
      value = uVar1 | 1 << groupNo;
    }
    mainSetBits((uint)(ushort)(&DAT_802f9e08)[mapNo],value);
    lastMapWhoseObjGroupChanged = mapNo;
    DAT_803993ac = value;
    if (status == 0) {
      for (iVar2 = 0; iVar2 < 0x78; iVar2 = iVar2 + 1) {
        if ((&DAT_802f9e08)[iVar2] == (&DAT_802f9e08)[mapNo]) {
          (&DAT_80389b7c)[iVar2] = (&DAT_80389b7c)[iVar2] & ~(1 << groupNo);
        }
      }
    }
    else if ((uVar1 & 1 << groupNo) == 0) {
      for (iVar2 = 0; iVar2 < 0x78; iVar2 = iVar2 + 1) {
        if ((&DAT_802f9e08)[iVar2] == (&DAT_802f9e08)[mapNo]) {
          (&DAT_80389b7c)[iVar2] = (&DAT_80389b7c)[iVar2] | 1 << groupNo;
        }
      }
    }
  }
  else if (-1 < status) {
    printf("Error in gplaySetObjGroupStatus (mapno %d, groupno %d)",mapNo,groupNo);
  }
  return;
}


int gplay_func2B(void) { //8012E3E4
  return (uint)curCharacter * 0xb4 + -0x7fc77cb8;
}


int gplay_func2C(void) { //8012E408
  return (uint)curCharacter * 0xb4 + -0x7fc77b50;
}


/* Library Function - Single Match
    gplay_cheatFn2E
   
   Library: KioskDefault 0 0 */

uint gplay_cheatFn2E(byte param1) { //8012E42C
  uint uVar1;
  
  if (param1 < 0x20) {
    uVar1 = *(uint *)(PTR_DAT_803993a0 + 0x10) & 1 << param1;
  }
  else {
    printf("CHEAT OUT OF RANGE");
    uVar1 = 0;
  }
  return uVar1;
}


/* Library Function - Single Match
    gplay_cheatFn2F
   
   Library: KioskDefault 0 0 */

void gplay_cheatFn2F(byte param1) { //8012E490
  if (param1 < 0x20) {
    *(uint *)(PTR_DAT_803993a0 + 0x10) = *(uint *)(PTR_DAT_803993a0 + 0x10) | 1 << param1;
  }
  else {
    printf("CHEAT OUT OF RANGE");
  }
  return;
}


/* Library Function - Single Match
    gplay_cheatFn30
   
   Library: KioskDefault 0 0 */

undefined4 gplay_cheatFn30(byte param1) { //8012E4F4
  undefined4 uVar1;
  
  if (param1 < 0x20) {
    uVar1 = 0;
    if (((*(uint *)(PTR_DAT_803993a0 + 0x10) & 1 << param1) != 0) &&
       ((*(uint *)(PTR_DAT_803993a0 + 0x14) & 1 << param1) != 0)) {
      uVar1 = 1;
    }
  }
  else {
    printf("CHEAT OUT OF RANGE");
    uVar1 = 0;
  }
  return uVar1;
}


/* Library Function - Single Match
    gplay_cheatFn31
   
   Library: KioskDefault 0 0 */

void gplay_cheatFn31(byte param1,char param2) { //8012E580
  if (param1 < 0x20) {
    if ((*(uint *)(PTR_DAT_803993a0 + 0x10) & 1 << param1) != 0) {
      if (param2 == '\0') {
        *(uint *)(PTR_DAT_803993a0 + 0x14) = *(uint *)(PTR_DAT_803993a0 + 0x14) & ~(1 << param1);
      }
      else {
        *(uint *)(PTR_DAT_803993a0 + 0x14) = *(uint *)(PTR_DAT_803993a0 + 0x14) | 1 << param1;
      }
    }
  }
  else {
    printf("CHEAT OUT OF RANGE");
  }
  return;
}


/* Library Function - Single Match
    gplay_cinemaFn32
   
   Library: KioskDefault 0 0 */

uint gplay_cinemaFn32(byte param1) { //8012E630
  uint uVar1;
  
  if (param1 < 0x20) {
    uVar1 = *(uint *)(PTR_DAT_803993a0 + 0x18) & 1 << param1;
  }
  else {
    printf("CINEMA OUT OF RANGE");
    uVar1 = 0;
  }
  return uVar1;
}


/* Library Function - Single Match
    gplay_cinemaFn33
   
   Library: KioskDefault 0 0 */

void gplay_cinemaFn33(byte param1) { //8012E694
  if (param1 < 0x20) {
    *(uint *)(PTR_DAT_803993a0 + 0x18) = *(uint *)(PTR_DAT_803993a0 + 0x18) | 1 << param1;
  }
  else {
    printf("CINEMA OUT OF RANGE");
  }
  return;
}

