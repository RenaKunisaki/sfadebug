
/* Library Function - Single Match
    OSCheckAlarmQueue
   
   Library: KioskDefault 0 0 */

BOOL_ OSCheckAlarmQueue(void) { //80007714
  BOOL_ BVar1;
  int iVar2;
  
  if (((DAT_80398250 == 0) && (DAT_80398254 == 0)) || ((DAT_80398250 != 0 && (DAT_80398254 != 0))))
  {
    if ((DAT_80398250 == 0) || (*(int *)(DAT_80398250 + 0x10) == 0)) {
      iVar2 = DAT_80398250;
      if ((DAT_80398254 == 0) || (*(int *)(DAT_80398254 + 0x14) == 0)) {
        for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
          if ((*(int *)(iVar2 + 0x14) != 0) && (*(int *)(*(int *)(iVar2 + 0x14) + 0x10) != iVar2)) {
            OSReport("OSCheckAlarmQueue: Failed alarm->next == NULL || alarm->next->prev == alarm in %d",0x75);
            return 0;
          }
          if ((*(int *)(iVar2 + 0x14) == 0) && (DAT_80398254 != iVar2)) {
            OSReport("OSCheckAlarmQueue: Failed alarm->next != NULL || AlarmQueue.tail == alarm in %d",0x76);
            return 0;
          }
        }
        BVar1 = 1;
      }
      else {
        OSReport("OSCheckAlarmQueue: Failed AlarmQueue.tail == NULL || AlarmQueue.tail->next == NULL in %d",0x72);
        BVar1 = 0;
      }
    }
    else {
      OSReport("OSCheckAlarmQueue: Failed AlarmQueue.head == NULL || AlarmQueue.head->prev == NULL in %d",0x71);
      BVar1 = 0;
    }
  }
  else {
    OSReport("OSCheckAlarmQueue: Failed AlarmQueue.head == NULL && AlarmQueue.tail == NULL || AlarmQueue.head != NULL && AlarmQueue.tail != NULL in %d",0x70);
    BVar1 = 0;
  }
  return BVar1;
}


void FUN_800078a8(OSAlarm *param_1) { //800078A8
  uint uVar1;
  uint dec;
  OSTime OVar2;
  
  OVar2 = OSGetTime();
  dec = (int)param_1->prev - (int)(OSAlarm *)OVar2;
  uVar1 = *(int *)((int)&param_1->fire + 4) -
          ((uint)(param_1->prev < (OSAlarm *)OVar2) + (int)((ulonglong)OVar2 >> 0x20));
  if ((uVar1 ^ 0x80000000) < 0x80000000) {
    set_DEC(0);
  }
  else if ((uVar1 ^ 0x80000000) < (dec < 0x80000000) + 0x80000000) {
    set_DEC(dec);
  }
  else {
    set_DEC(0x7fffffff);
  }
  return;
}


void FUN_80007954(void) { //80007954
  __OSExceptionHandler p_Var1;
  
  p_Var1 = __OSGetExceptionHandler(8);
  if (p_Var1 != alarmCb_8000806c) {
    DAT_80398254 = 0;
    DAT_80398250 = 0;
    __OSSetExceptionHandler(8,alarmCb_8000806c);
  }
  return;
}


void store0toParam(undefined4 *param1) { //800079A8
  *param1 = 0;
  return;
}


/* Library Function - Single Match
    osAlarmFn_800079b4
   
   Library: KioskDefault 0 0 */

void InsertAlarm(OSAlarm *alarm,undefined4 param2,uint param3,uint param4,int param5) { //800079B4
  ulonglong uVar1;
  OSAlarm *pOVar2;
  uint uVar3;
  uint uVar4;
  OSAlarm *pOVar5;
  bool bVar6;
  OSTime OVar7;
  longlong lVar8;
  
  if (0x80000000 <
      (uint)(*(int *)&alarm->start != 0) + (*(uint *)((int)&alarm->period + 4) ^ 0x80000000)) {
    OVar7 = OSGetTime();
    uVar3 = (uint)((ulonglong)OVar7 >> 0x20);
    uVar4 = (uint)OVar7;
    param3 = *(uint *)((int)&alarm->start + 4);
    param4 = *(uint *)((int)alarm + 0x24);
    if ((*(uint *)((int)&alarm->start + 4) ^ 0x80000000) <
        (uint)(*(uint *)((int)alarm + 0x24) < uVar4) + (uVar3 ^ 0x80000000)) {
      lVar8 = __div2i(uVar3 - ((uint)(uVar4 < *(uint *)((int)alarm + 0x24)) +
                              *(int *)((int)&alarm->start + 4)),uVar4 - *(uint *)((int)alarm + 0x24)
                      ,*(uint *)((int)&alarm->period + 4),*(uint *)&alarm->start);
      uVar1 = lVar8 + 1;
      uVar3 = *(uint *)&alarm->start;
      uVar4 = uVar3 * (int)uVar1;
      bVar6 = CARRY4(param4,uVar4);
      param4 = (int)(OSAlarmHandler *)param4 + uVar4;
      param3 = param3 + *(int *)((int)&alarm->period + 4) * (int)uVar1 +
                        (int)((ulonglong)uVar3 * (uVar1 & 0xffffffff) >> 0x20) +
                        uVar3 * (int)(uVar1 >> 0x20) + (uint)bVar6;
    }
  }
  if (alarm->handler != (OSAlarmHandler)0x0) {
                    
    OSPanic("OSAlarm.c",0xd6,s_Failed_assertion_alarm_>handler___802d1334);
  }
  alarm->handler = (OSAlarmHandler)param5;
  alarm->prev = (OSAlarm *)param4;
  *(uint *)((int)&alarm->fire + 4) = param3;
  pOVar5 = DAT_80398250;
  while( true ) {
    if (pOVar5 == (OSAlarm *)0x0) {
      if (true) {
        *(undefined4 *)&alarm->period = 0;
        pOVar5 = DAT_80398254;
        pOVar2 = alarm;
        alarm->next = DAT_80398254;
        DAT_80398254 = pOVar2;
        if (pOVar5 == (OSAlarm *)0x0) {
          DAT_80398250 = alarm;
          DAT_80398254 = alarm;
          FUN_800078a8(alarm);
        }
        else {
          *(OSAlarm **)&pOVar5->period = alarm;
        }
        return;
      }
                    
      OSPanic("OSAlarm.c",0xf3,"Failed assertion next == 0");
    }
    if ((param3 ^ 0x80000000) <
        (uint)(param4 < pOVar5->prev) + (*(uint *)((int)&pOVar5->fire + 4) ^ 0x80000000)) break;
    pOVar5 = *(OSAlarm **)&pOVar5->period;
  }
  alarm->next = pOVar5->next;
  pOVar5->next = alarm;
  *(OSAlarm **)&alarm->period = pOVar5;
  if (alarm->next != (OSAlarm *)0x0) {
    *(OSAlarm **)&alarm->next->period = alarm;
    return;
  }
  DAT_80398250 = alarm;
  FUN_800078a8(alarm);
  return;
}


/* Library Function - Single Match
    OSSetAlarm
   
   Library: KioskDefault 0 0 */

void OSSetAlarm(OSAlarm *alarm,OSTime tick,OSAlarmHandler handler) { //80007BA0
  longlong lVar1;
  BOOL_ level;
  BOOL_ BVar2;
  uint in_r5;
  int in_r6;
  int in_r7;
  OSTime OVar3;
  
  if ((uint)(in_r6 != 0) + (in_r5 ^ 0x80000000) < 0x80000001) {
                    
    OSPanic("OSAlarm.c",0x114,"OSSetAlarm(): tick was less than zero.");
  }
  if (in_r7 == 0) {
                    
    OSPanic("OSAlarm.c",0x115,"OSSetAlarm(): null handler was specified.");
  }
  level = OSDisableInterrupts();
  *(undefined4 *)&alarm->start = 0;
  *(undefined4 *)((int)&alarm->period + 4) = 0;
  OVar3 = OSGetTime();
  lVar1 = OVar3 + CONCAT44(in_r5,in_r6);
  InsertAlarm(alarm,(int)OVar3,(uint)((ulonglong)lVar1 >> 0x20),(uint)lVar1,in_r7);
  BVar2 = OSCheckAlarmQueue();
  if (BVar2 == 0) {
                    
    OSPanic("OSAlarm.c",0x11c,"Failed assertion OSCheckAlarmQueue()");
  }
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    OSSetAbsAlarm
   
   Library: KioskDefault 0 0 */

void OSSetAbsAlarm(OSAlarm *param1,undefined4 param2,uint param3,uint param4,int param5) { //80007C88
  BOOL_ level;
  BOOL_ BVar1;
  
  if (param5 == 0) {
                    
    OSPanic("OSAlarm.c",0x130,"OSSetAbsAlarm(): null handler was specified.");
  }
  level = OSDisableInterrupts();
  *(undefined4 *)&param1->start = 0;
  *(undefined4 *)((int)&param1->period + 4) = 0;
  InsertAlarm(param1,param2,param3,param4,param5);
  BVar1 = OSCheckAlarmQueue();
  if (BVar1 == 0) {
                    
    OSPanic("OSAlarm.c",0x137,"Failed assertion OSCheckAlarmQueue()");
  }
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    OSSetPeriodicAlarm
   
   Library: KioskDefault 0 0 */

void OSSetPeriodicAlarm(OSAlarm *alarm,OSTime start,OSTime period,OSAlarmHandler handler) { //80007D34
  BOOL_ level;
  BOOL_ BVar1;
  undefined4 param2;
  undefined4 in_r5;
  undefined4 in_r6;
  uint in_r7;
  int in_r8;
  int in_r9;
  
  param2 = 0x80000000;
  if ((uint)(in_r8 != 0) + (in_r7 ^ 0x80000000) < 0x80000001) {
                    
    OSPanic("OSAlarm.c",0x14d,"OSSetPeriodicAlarm(): period was less than zero.");
  }
  if (in_r9 == 0) {
                    
    OSPanic("OSAlarm.c",0x14e,"OSSetPeriodicAlarm(): null handler was specified.");
  }
  level = OSDisableInterrupts();
  *(int *)&alarm->start = in_r8;
  *(uint *)((int)&alarm->period + 4) = in_r7;
  *(undefined4 *)((int)alarm + 0x24) = in_r6;
  *(undefined4 *)((int)&alarm->start + 4) = in_r5;
  InsertAlarm(alarm,param2,0,0,in_r9);
  BVar1 = OSCheckAlarmQueue();
  if (BVar1 == 0) {
                    
    OSPanic("OSAlarm.c",0x156,"Failed assertion OSCheckAlarmQueue()");
  }
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    osAlarmFn_80007e28
   
   Library: KioskDefault 0 0 */

void osAlarmFn_80007e28(int *param1) { //80007E28
  BOOL_ level;
  BOOL_ BVar1;
  OSAlarm *pOVar2;
  
  level = OSDisableInterrupts();
  if (*param1 == 0) {
    OSRestoreInterrupts(level);
  }
  else {
    pOVar2 = (OSAlarm *)param1[5];
    if (pOVar2 == (OSAlarm *)0x0) {
      DAT_80398254 = param1[4];
    }
    else {
      pOVar2->next = (OSAlarm *)param1[4];
    }
    if (param1[4] == 0) {
      DAT_80398250 = pOVar2;
      if (pOVar2 != (OSAlarm *)0x0) {
        FUN_800078a8(pOVar2);
      }
    }
    else {
      *(OSAlarm **)(param1[4] + 0x14) = pOVar2;
    }
    *param1 = 0;
    BVar1 = OSCheckAlarmQueue();
    if (BVar1 == 0) {
                    
      OSPanic("OSAlarm.c",0x189,"Failed assertion OSCheckAlarmQueue()");
    }
    OSRestoreInterrupts(level);
  }
  return;
}


void alarmCb_8000806c(undefined4 param_1,OSContext *ctx,undefined4 param_3,u32 param_4,u32 param_5,
                     u32 param_6,u32 param_7,u32 param_8) { //8000806C
  u32 in_r0;
  u32 in_r11;
  u32 in_r12;
  u32 unaff_r14;
  u32 unaff_r15;
  u32 unaff_r16;
  u32 unaff_r17;
  u32 unaff_r18;
  u32 unaff_r19;
  u32 unaff_r20;
  u32 unaff_r21;
  u32 unaff_r22;
  u32 unaff_r23;
  u32 unaff_r24;
  u32 unaff_r25;
  u32 unaff_r26;
  u32 unaff_r27;
  u32 unaff_r28;
  u32 unaff_r29;
  u32 unaff_r30;
  u32 unaff_r31;
  u32 unaff_GQR1;
  u32 unaff_GQR6;
  u32 unaff_GQR7;
  
  ctx->gpr[0] = in_r0;
  ctx->gpr[1] = (u32)register0x00000004;
  ctx->gpr[2] = (u32)&r2base;
  ctx->gpr[6] = param_4;
  ctx->gpr[7] = param_5;
  ctx->gpr[8] = param_6;
  ctx->gpr[9] = param_7;
  ctx->gpr[10] = param_8;
  ctx->gpr[0xb] = in_r11;
  ctx->gpr[0xc] = in_r12;
  ctx->gpr[0xd] = (u32)&f_127;
  ctx->gpr[0xe] = unaff_r14;
  ctx->gpr[0xf] = unaff_r15;
  ctx->gpr[0x10] = unaff_r16;
  ctx->gpr[0x11] = unaff_r17;
  ctx->gpr[0x12] = unaff_r18;
  ctx->gpr[0x13] = unaff_r19;
  ctx->gpr[0x14] = unaff_r20;
  ctx->gpr[0x15] = unaff_r21;
  ctx->gpr[0x16] = unaff_r22;
  ctx->gpr[0x17] = unaff_r23;
  ctx->gpr[0x18] = unaff_r24;
  ctx->gpr[0x19] = unaff_r25;
  ctx->gpr[0x1a] = unaff_r26;
  ctx->gpr[0x1b] = unaff_r27;
  ctx->gpr[0x1c] = unaff_r28;
  ctx->gpr[0x1d] = unaff_r29;
  ctx->gpr[0x1e] = unaff_r30;
  ctx->gpr[0x1f] = unaff_r31;
  ctx->gqr[1] = unaff_GQR1;
  ctx->gqr[2] = (u32)&DAT_00040004;
  ctx->gqr[3] = (u32)&DAT_00050005;
  ctx->gqr[4] = (u32)&DAT_00060006;
  ctx->gqr[5] = (u32)&DAT_00070007;
  ctx->gqr[6] = unaff_GQR6;
  ctx->gqr[7] = unaff_GQR7;
  alarmCb_8000806c(param_1,ctx);
  return;
}

