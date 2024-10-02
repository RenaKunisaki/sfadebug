
void sharpClawFn_801b69e4
               (ObjInstance *param1,int param2,undefined4 param_3,int param4,undefined4 param_5,
               int param6) { //801B69E4
  uint uVar1;
  int iVar2;
  
  uVar1 = randInt(0,3);
  FUN_801b2a10((double)*(float *)(&DAT_8030ff3c + (uVar1 & 0xff) * 0x10),param1,param2,
               (&DAT_8030ff38)[(uVar1 & 0xff) * 0x10],0,3);
  iVar2 = randInt(0,2);
  audioSfxFn_800688bc((double)(param1->prevPos).x,(double)(param1->prevPos).y,
                      (double)(param1->prevPos).z,(ushort)*(undefined4 *)(&DAT_8030ff84 + iVar2 * 4)
                      ,0x7f,"sharpClaw.c",(int *)0x201);
  iVar2 = randInt(0,2);
  audioSfxFn_800688bc((double)(param1->prevPos).x,(double)(param1->prevPos).y,
                      (double)(param1->prevPos).z,(ushort)*(undefined4 *)(&DAT_8030ff78 + iVar2 * 4)
                      ,0x7f,"sharpClaw.c",(int *)0x202);
  if ((int)(uint)*(ushort *)(param2 + 0x29c) < param6) {
    *(undefined2 *)(param2 + 0x29c) = 0;
  }
  else {
    *(short *)(param2 + 0x29c) = *(short *)(param2 + 0x29c) - (short)param6;
  }
  *(uint *)(param2 + 0x2cc) = *(uint *)(param2 + 0x2cc) | 8;
  if (param4 == 0x10) {
    *(uint *)(param2 + 0x2cc) = *(uint *)(param2 + 0x2cc) | 0x20;
  }
  return;
}

