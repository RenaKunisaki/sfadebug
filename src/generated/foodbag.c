
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void foodbag_initialise(undefined4 param) { //8012E6F8
  return;
}


/* @description Called when DLL is unloaded */

void foodbag_release(void) { //8012E6FC
  return;
}


/* Library Function - Single Match
    foodbag_placeObject
   
   Library: KioskDefault 0 0 */

undefined4 foodbag_placeObject(int param1,int param2,byte *param3,int param4) { //8012E700
  int iVar1;
  ObjInstance *pOVar2;
  ObjDef *def;
  undefined4 uVar3;
  
  iVar1 = func0C(param2);
  printf("about to place object %d",(int)*(short *)(param4 + iVar1 * 10 + 8));
  if (*(short *)(param4 + iVar1 * 10 + 8) == -1) {
    uVar3 = 0;
  }
  else {
    pOVar2 = Object_objGetMain();
    *param3 = (char)(*param3 + 1) + (char)((*param3 + 1) / 0x14) * -0x14;
    if (*(int *)(param3 + (uint)*param3 * 4 + 4) != 0) {
      Object_objFreeObject(*(ObjInstance **)(param3 + (uint)*param3 * 4 + 4));
    }
    def = objAlloc(0x20,*(ObjDefEnum *)(param4 + iVar1 * 10 + 8));
    def->cullDist = 0xff;
    def->loadFlags = isManualLoad;
    (def->pos).x = (pOVar2->pos).pos.x;
    (def->pos).y = (pOVar2->pos).pos.y;
    (def->pos).z = (pOVar2->pos).pos.z;
    def[1].allocatedSize = (byte)(pOVar2->pos).rotation.x;
    *(undefined *)((int)&def[1].objType + 1) = 0;
    *(undefined *)&def[1].objType = 0;
    pOVar2 = objInstantiateCharacter(def,5,-1,-1,*(ObjInstance **)(param1 + 0x30));
    *(ObjInstance **)(param3 + (uint)*param3 * 4 + 4) = pOVar2;
    *(short *)(param3 + (uint)*param3 * 2 + 0x54) = (short)param2;
    uVar3 = 1;
  }
  return uVar3;
}


/* Library Function - Single Match
    foodbag_func04
   
   Library: KioskDefault 0 0 */

void foodbag_func04(ObjInstance *param1,ObjInstance *param2,uint param3,int param4) { //8012E864
  float fVar1;
  char cVar2;
  float *pfVar3;
  float *pfVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  float local_80;
  float local_7c;
  undefined4 local_78;
  ObjInstance *local_74;
  float local_70 [20];
  
  _savefpr_30();
  iVar7 = 10;
  pfVar3 = newGameStartCoords + 2;
  pfVar4 = &local_7c;
  do {
    fVar1 = pfVar3[3];
    pfVar4[2] = pfVar3[2];
    pfVar4[3] = fVar1;
    iVar7 = iVar7 + -1;
    pfVar3 = pfVar3 + 2;
    pfVar4 = pfVar4 + 2;
  } while (iVar7 != 0);
  for (sVar5 = 0; sVar5 < 0x14; sVar5 = sVar5 + 1) {
    if ((*(ushort *)(param4 + sVar5 * 2 + 0x54) & param3) != 0) {
      local_80 = *(float *)(*(int *)(param4 + sVar5 * 4 + 4) + 0xc);
      local_7c = *(float *)(*(int *)(param4 + sVar5 * 4 + 4) + 0x10);
      local_78 = *(undefined4 *)(*(int *)(param4 + sVar5 * 4 + 4) + 0x14);
      iVar7 = FUN_800bb7e0(0.1000000014901161,&(param2->pos).pos.x,&local_80,0,(ObjInstance **)0x0,
                           param1,8,-1,0xff,'\0');
      if ((iVar7 == 0) &&
         (cVar2 = (**(code **)(**(int **)(*(int *)(param4 + sVar5 * 4 + 4) + 0x68) + 0x20))
                            (*(undefined4 *)(param4 + sVar5 * 4 + 4)), cVar2 == '\0')) {
        (&local_74)[sVar5] = *(ObjInstance **)(param4 + sVar5 * 4 + 4);
      }
    }
  }
  sVar5 = -1;
  dVar9 = 10000.0;
  for (sVar6 = 0; sVar6 < 0x14; sVar6 = sVar6 + 1) {
    if (((&local_74)[sVar6] != (ObjInstance *)0x0) &&
       ((dVar8 = (double)objDistSqObj2Obj(param2,(&local_74)[sVar6]), sVar5 == -1 ||
        (dVar8 <= dVar9)))) {
      dVar9 = dVar8;
      sVar5 = sVar6;
    }
  }
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    foodbag_func05
   
   Library: KioskDefault 0 0 */

undefined4 foodbag_func05(ObjInstance *param1,int param2) { //8012EA7C
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (0x13 < iVar1) {
      return 0;
    }
    if (*(ObjInstance **)(param2 + iVar1 * 4 + 4) == param1) break;
    iVar1 = iVar1 + 1;
  }
  Object_objFreeObject(param1);
  *(undefined4 *)(param2 + iVar1 * 4 + 4) = 0;
  *(undefined2 *)(param2 + iVar1 * 2 + 0x54) = 0;
  return 1;
}


/* Library Function - Single Match
    foodbag_func06
   
   Library: KioskDefault 0 0 */

undefined2 foodbag_func06(int param1,int param2) { //8012EB04
  undefined2 uVar1;
  uint uVar2;
  ushort uVar3;
  
  for (uVar3 = 0; uVar3 < 0xc; uVar3 = uVar3 + 1) {
    *(float *)(param1 + (uint)uVar3 * 4) = *(float *)(param1 + (uint)uVar3 * 4) + timeDelta;
  }
  uVar3 = 0;
  while( true ) {
    if (0xb < uVar3) {
      return 0;
    }
    if ((*(short *)(param1 + (uint)uVar3 * 2 + 0x78) != 0) &&
       (uVar2 = func0C((uint)*(ushort *)(param1 + (uint)uVar3 * 2 + 0x78)),
       (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + (uVar2 & 0xff) * 10)) -
              4503599627370496.0) < *(float *)(param1 + (uint)uVar3 * 4))) break;
    uVar3 = uVar3 + 1;
  }
  uVar2 = func0C((uint)*(ushort *)(param1 + (uint)uVar3 * 2 + 0x78));
  uVar1 = *(undefined2 *)(param2 + (uVar2 & 0xff) * 10 + 4);
  func09((byte)uVar3,*(ushort *)(param1 + (uint)uVar3 * 2 + 0x78),param1,param2);
  return uVar1;
}


/* Library Function - Single Match
    foodbag_func07
   
   Library: KioskDefault 0 0 */

undefined4 foodbag_func07(int param1,int param2,int param3,int param4) { //8012EC1C
  int iVar1;
  char cVar2;
  char cVar3;
  
  cVar3 = '\0';
  iVar1 = func0C(param1);
  do {
    if (*(short *)(param3 + cVar3 * 2 + 0x78) == 0) {
      if ((int)(char)((char)param2 - cVar3) < (int)(uint)*(byte *)(param4 + iVar1 * 10 + 3)) {
        return 0;
      }
      for (cVar2 = '\0'; (int)cVar2 < (int)(uint)*(byte *)(param4 + iVar1 * 10 + 3);
          cVar2 = cVar2 + '\x01') {
        *(short *)(param3 + ((int)cVar3 + (int)cVar2) * 2 + 0x78) = (short)param1;
      }
      *(float *)(param3 + cVar3 * 4) = 0.0;
      func0B(param3,param4);
      return 1;
    }
    cVar3 = cVar3 + '\x01';
  } while (cVar3 != param2);
  return 0;
}


/* Library Function - Single Match
    foodbag_removeFood
   
   Library: KioskDefault 0 0 */

void foodbag_removeFood(short param1,int param2,int param3) { //8012ED14
  uint uVar1;
  ushort unaff_r30;
  byte param1_00;
  
  for (param1_00 = 0; param1_00 < 0x1e; param1_00 = param1_00 + 1) {
    unaff_r30 = *(ushort *)(param2 + (uint)param1_00 * 2 + 0x78);
    uVar1 = func0C((uint)unaff_r30);
    if (param1 == *(short *)(param3 + (uVar1 & 0xff) * 10 + 6)) break;
    if (param1_00 == 0x1d) {
      printf("Foodbag error: can't find food to remove");
      return;
    }
  }
  func09(param1_00,unaff_r30,param2,param3);
  return;
}


/* Library Function - Single Match
    foodbag_func09
   
   Library: KioskDefault 0 0 */

void foodbag_func09(byte param1,ushort param2,int param3,int param4) { //8012EDC4
  int iVar1;
  byte bVar2;
  
  iVar1 = func0C((uint)param2);
  for (bVar2 = param1 + *(char *)(param4 + iVar1 * 10 + 3); bVar2 < 0x1e; bVar2 = bVar2 + 1) {
    *(undefined4 *)(param3 + (uint)param1 * 4) = *(undefined4 *)(param3 + (uint)bVar2 * 4);
    *(undefined2 *)(param3 + (uint)param1 * 2 + 0x78) =
         *(undefined2 *)(param3 + (uint)bVar2 * 2 + 0x78);
    param1 = param1 + 1;
  }
  func0B(param3,param4);
  return;
}


/* Library Function - Single Match
    foodbag_func0A
   
   Library: KioskDefault 0 0 */

undefined4 foodbag_func0A(ushort *param1) { //8012EE64
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = mainGetBit((uint)param1[2]);
  if (uVar1 == 0) {
    uVar1 = mainGetBit((uint)param1[1]);
    if (uVar1 == 0) {
      uVar1 = mainGetBit((uint)*param1);
      if (uVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 10;
      }
    }
    else {
      mainSetBits((uint)*param1,1);
      uVar2 = 0x14;
    }
  }
  else {
    mainSetBits((uint)param1[1],1);
    mainSetBits((uint)*param1,1);
    uVar2 = 0x1e;
  }
  return uVar2;
}


/* Library Function - Single Match
    foodbag_func0B
   
   Library: KioskDefault 0 0 */

void foodbag_func0B(int param1,int param2) { //8012EEFC
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  uVar2 = 0;
  while (*(short *)(param1 + (uVar2 & 0xff) * 2 + 0x78) != 0) {
    iVar1 = func0C((uint)*(ushort *)(param1 + (uVar2 & 0xff) * 2 + 0x78));
    *(char *)((int)&local_20 + iVar1) = *(char *)((int)&local_20 + iVar1) + '\x01';
    uVar2 = uVar2 + 1;
  }
  for (bVar3 = 1; bVar3 < 0xc; bVar3 = bVar3 + 1) {
    if (0 < *(short *)(param2 + (uint)bVar3 * 10 + 6)) {
      mainSetBits((int)*(short *)(param2 + (uint)bVar3 * 10 + 6),
                  (uint)*(byte *)((int)&local_20 + (uint)bVar3));
    }
  }
  return;
}


/* Library Function - Single Match
    foodbag_func0C
   
   Library: KioskDefault 0 0 */

int foodbag_func0C(int param1) { //8012EFDC
  int iVar1;
  
  iVar1 = 0;
  for (; param1 != 0; param1 = param1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

