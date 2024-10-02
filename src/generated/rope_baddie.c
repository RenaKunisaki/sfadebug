
void ropeBaddieFn_801c0548(int param1) { //801C0548
  audioSfxFn_800688bc((double)*(float *)(param1 + 0x18),(double)*(float *)(param1 + 0x1c),
                      (double)*(float *)(param1 + 0x20),0x9b,0x7f,"rope_baddie.c",
                      (int *)0x219);
  return;
}


void FUN_801c0598(int param_1,int param_2) { //801C0598
  if ((*(uint *)(param_2 + 0x308) & 1) != 0) {
    *(uint *)(param_2 + 0x308) = *(uint *)(param_2 + 0x308) & 0xfffffffe;
    audioSfxFn_800688bc((double)*(float *)(param_1 + 0x18),(double)*(float *)(param_1 + 0x1c),
                        (double)*(float *)(param_1 + 0x20),0x10d,0x7f,"rope_baddie.c",
                        (int *)0x220);
  }
  return;
}


undefined4 FUN_801c1004(ObjInstance *param_1,int param_2) { //801C1004
  undefined *puVar1;
  
  puVar1 = param_1->state;
  if (*(char *)(param_2 + 0x272) != '\0') {
    Object_ObjAnimSetMove(0.0,param_1,8,0);
    *(undefined *)(param_2 + 0x33a) = 0;
  }
  *(float *)(param_2 + 0x298) = 0.048;
  if ((*(uint *)(param_2 + 0x308) & 0x200) != 0) {
    audioSfxFn_800688bc((double)(param_1->prevPos).x,(double)(param_1->prevPos).y,
                        (double)(param_1->prevPos).z,0x86,0x7f,"rope_baddie.c",(int *)0x329
                       );
    *(uint *)(param_2 + 0x308) = *(uint *)(param_2 + 0x308) & 0xfffffdff;
                    /* {@symbol 80163050} */
    (**(code **)(*(int *)pDll_partfx1F + 0x4c))
              (param_1,(int)*(short *)(puVar1 + 0x3dc),0xffffffff,1);
  }
  return 0;
}


bool FUN_801c10cc(ObjInstance *param_1,int param_2) { //801C10CC
  undefined *puVar1;
  
  puVar1 = param_1->state;
  *(undefined *)(param_2 + 0x341) = 0;
  *(float *)(param_2 + 0x298) = 0.01;
  *(float *)(param_2 + 0x278) = 0.0;
  *(float *)(param_2 + 0x27c) = 0.0;
  if (*(char *)(param_2 + 0x272) != '\0') {
    audioTryStartSfx((int *)param_1,0x10,0x23,0x7f,"rope_baddie.c",0x33e);
    if (*(char *)(param_2 + 0x272) != '\0') {
      Object_ObjAnimSetMove(0.0,param_1,2,0);
      *(undefined *)(param_2 + 0x33a) = 0;
    }
    *(float *)(param_2 + 0x298) = 0.025;
    *(undefined *)(param_2 + 0x33a) = 0;
    param_1->newOpacity = 0xff;
    *(ushort *)(puVar1 + 0x3ae) = *(ushort *)(puVar1 + 0x3ae) | 0x100;
  }
  return *(char *)(param_2 + 0x33a) != '\0';
}

