
void robotPatrolFn_801b7368(int param1,int param2) { //801B7368
  ushort uVar1;
  int iVar2;
  ObjDef *def;
  int iVar3;
  
  iVar3 = *(int *)(param1 + 0x4c);
  iVar2 = randInt(0,2);
  audioSfxFn_800688bc((double)*(float *)(param1 + 0x18),(double)*(float *)(param1 + 0x1c),
                      (double)*(float *)(param1 + 0x20),
                      (ushort)*(undefined4 *)(&DAT_80310020 + iVar2 * 4),0x7f,
                      "robotPatrol.c",(int *)0x141);
  *(uint *)(param2 + 0x2cc) = *(uint *)(param2 + 0x2cc) | 8;
  if (*(float *)(param2 + 0x314) <= 0.0) {
    uVar1 = *(ushort *)(iVar3 + 0x2c);
    def = objAlloc(0x24,GCbaddieShi);
    def->loadFlags = *(RomListObjLoadFlags *)(iVar3 + 4);
    def->bound = *(byte *)(iVar3 + 6);
    def->mapStates2 = *(byte *)(iVar3 + 5);
    def->cullDist = *(byte *)(iVar3 + 7);
    (def->pos).x = *(float *)(param1 + 0xc);
    (def->pos).y = *(float *)(param1 + 0x10) + 5.0;
    (def->pos).z = *(float *)(param1 + 0x14);
    *(float *)(param2 + 0x314) =
         (float)((double)CONCAT44(0x43300000,(uint)uVar1) - 4503599627370496.0);
    def[1].allocatedSize = (char)(uVar1 >> 8);
    def[1].mapStates1 = (char)uVar1;
    DAT_80399d08 = objInstantiateCharacter
                             (def,5,(int)*(char *)(param1 + 0xac),-1,
                              *(ObjInstance **)(param1 + 0x30));
    *(uint *)(param2 + 0x2c8) = *(uint *)(param2 + 0x2c8) & 0xffffffdf;
    *(float *)(param1 + 0x2c) = 0.0;
    *(float *)(param1 + 0x28) = 0.0;
    *(float *)(param1 + 0x24) = 0.0;
  }
  return;
}

