
void mutatedEbaFn_801b86c0(ObjInstance *param1,int param2) { //801B86C0
  int iVar1;
  
  if ((((param1->animId == 0) || (param1->animId == 1)) || (param1->animId == 3)) ||
     (param1->animId == 4)) {
    iVar1 = randInt(2,4);
    audioSfxFn_800688bc((double)(param1->prevPos).x,(double)(param1->prevPos).y,
                        (double)(param1->prevPos).z,
                        (ushort)*(undefined4 *)(&DAT_80310058 + iVar1 * 4),0x7f,
                        "mutatedeba.c",(int *)0x117);
    *(uint *)(param2 + 0x2cc) = *(uint *)(param2 + 0x2cc) | 0x10;
  }
  else {
    FUN_801b2a10(1.0,param1,param2,4,0,0);
    *(undefined *)(param2 + 0x308) = 0;
    iVar1 = randInt(0,1);
    audioSfxFn_800688bc((double)(param1->prevPos).x,(double)(param1->prevPos).y,
                        (double)(param1->prevPos).z,
                        (ushort)*(undefined4 *)(&DAT_80310058 + iVar1 * 4),0x7f,
                        "mutatedeba.c",(int *)0x123);
    *(uint *)(param2 + 0x2cc) = *(uint *)(param2 + 0x2cc) | 8;
  }
  return;
}

