
/* Library Function - Single Match
    osThreadFn_8000d228
   
   Library: KioskDefault 0 0 */

void osThreadFn_8000d228(void) { //8000D228
  u32 uVar1;
  int iVar2;
  
  OSThread_803263a8.suspend._0_2_ = 2;
  OSThread_803263a8.suspend._2_2_ = 1;
  OSThread_803263a8.val = &DAT_00000010;
  OSThread_803263a8.base = 0x10;
  OSThread_803263a8.priority = 0;
  OSThread_803263a8.queue = (OSThreadQueue *)0xffffffff;
  OSThread_803263a8.queueMutex.head = (OSMutex *)0x0;
  OSInitThreadQueue((OSThreadQueue *)&OSThread_803263a8.queueJoin.tail);
  butt2(&OSThread_803263a8.queueMutex.tail);
  uVar1 = get_msr();
  if ((uVar1 & 0x2000) == 0) {
                    
    OSPanic("OSThread.c",0x11a,"Failed assertion PPCMfmsr() & MSR_FP");
  }
  osDefaultThread = &OSThread_803263a8;
  OSClearContext(&OSThread_803263a8.context);
  OSSetCurrentContext(&OSThread_803263a8.context);
  OSThread_803263a8.stackEnd = (u32 *)&DAT_803b4178;
  PTR_DAT_803266b0 = (undefined *)&DAT_803a4174;
  DAT_803a4174 = 0xdeadbabe;
  osCurThread = &OSThread_803263a8;
  DAT_80398290 = 0;
  osSchedulerFlag_80398294 = 0;
  for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {
    OSInitThreadQueue(&OSThreadQueue_80325f98 + iVar2);
  }
  OSInitThreadQueue((OSThreadQueue *)&osCurThreadQueueHead);
  if (osCurThreadQueueTail == (OSThread *)0x0) {
    osCurThreadQueueHead = &OSThread_803263a8;
  }
  else {
    (osCurThreadQueueTail->linkActive).prev = &OSThread_803263a8;
  }
  OSThread_803263a8.stackBase = (u8 *)osCurThreadQueueTail;
  OSThread_803263a8.linkActive.prev = (OSThread *)0x0;
  osCurThreadQueueTail = &OSThread_803263a8;
  OSClearContext((OSContext *)&DAT_803266b8);
  osAlarmCount_80398298 = 0;
  return;
}


/* Library Function - Single Match
    osThreadFn_8000d4d8
   
   Library: KioskDefault 0 0 */

void osThreadFn_8000d4d8(int param1) { //8000D4D8
  int iVar1;
  
  if (0 < *(int *)(param1 + 0x2cc)) {
                    
    OSPanic("OSThread.c",0x1d5,"Failed assertion !IsSuspended(thread->suspend)");
  }
  if (*(short *)(param1 + 0x2c8) != 1) {
                    
    OSPanic("OSThread.c",0x1d6,s_Failed_assertion_thread_>state___802d3494);
  }
  if ((-1 < *(int *)(param1 + 0x2d0)) && (*(int *)(param1 + 0x2d0) < 0x20)) {
    *(OSThreadQueue **)(param1 + 0x2dc) = &OSThreadQueue_80325f98 + *(int *)(param1 + 0x2d0);
    iVar1 = *(int *)(*(int *)(param1 + 0x2dc) + 4);
    if (iVar1 == 0) {
      **(int **)(param1 + 0x2dc) = param1;
    }
    else {
      *(int *)(iVar1 + 0x2e0) = param1;
    }
    *(int *)(param1 + 0x2e4) = iVar1;
    *(undefined4 *)(param1 + 0x2e0) = 0;
    *(int *)(*(int *)(param1 + 0x2dc) + 4) = param1;
    DAT_80398290 = DAT_80398290 | 1 << 0x1f - *(int *)(param1 + 0x2d0);
    osSchedulerFlag_80398294 = 1;
    return;
  }
                    
  OSPanic("OSThread.c",0x1d8,"Failed assertion OS_PRIORITY_MIN <= thread->priority && thread->priority <= OS_PRIORITY_MAX");
}


/* Library Function - Single Match
    osThreadFn_8000d5e8
   
   Library: KioskDefault 0 0 */

void osThreadFn_8000d5e8(int param1) { //8000D5E8
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(short *)(param1 + 0x2c8) != 1) {
                    
    OSPanic("OSThread.c",0x1ed,s_Failed_assertion_thread_>state___802d3494);
  }
  if ((-1 < *(int *)(param1 + 0x2d0)) && (*(int *)(param1 + 0x2d0) < 0x20)) {
    if (*(OSThreadQueue **)(param1 + 0x2dc) != &OSThreadQueue_80325f98 + *(int *)(param1 + 0x2d0)) {
                    
      OSPanic("OSThread.c",0x1f0,s_Failed_assertion_thread_>queue___802d3528);
    }
    piVar1 = *(int **)(param1 + 0x2dc);
    iVar3 = *(int *)(param1 + 0x2e0);
    iVar2 = *(int *)(param1 + 0x2e4);
    if (iVar3 == 0) {
      piVar1[1] = iVar2;
    }
    else {
      *(int *)(iVar3 + 0x2e4) = iVar2;
    }
    if (iVar2 == 0) {
      *piVar1 = iVar3;
    }
    else {
      *(int *)(iVar2 + 0x2e0) = iVar3;
    }
    if (*piVar1 == 0) {
      DAT_80398290 = DAT_80398290 & ~(1 << 0x1f - *(int *)(param1 + 0x2d0));
    }
    *(undefined4 *)(param1 + 0x2dc) = 0;
    return;
  }
                    
  OSPanic("OSThread.c",0x1ef,"Failed assertion OS_PRIORITY_MIN <= thread->priority && thread->priority <= OS_PRIORITY_MAX");
}


int __OSGetEffectivePriority(OSThread *thread) { //8000D704
  OSThread *pOVar1;
  void *pvVar2;
  OSMutex *pOVar3;
  
  pvVar2 = thread->val;
  for (pOVar3 = (thread->queueMutex).tail; pOVar3 != (OSMutex *)0x0; pOVar3 = (pOVar3->link).next) {
    pOVar1 = (pOVar3->queue).head;
    if ((pOVar1 != (OSThread *)0x0) && (pOVar1->base < (int)pvVar2)) {
      pvVar2 = (void *)pOVar1->base;
    }
  }
  return (int)pvVar2;
}


/* Library Function - Single Match
    osThreadFn_8000d750
   
   Library: KioskDefault 0 0 */

undefined4 SetEffectivePriority(int param1,undefined4 param2) { //8000D750
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param1 + 0x2cc)) {
                    
    OSPanic("OSThread.c",0x223,"Failed assertion !IsSuspended(thread->suspend)");
  }
  uVar1 = *(ushort *)(param1 + 0x2c8);
  if (uVar1 != 3) {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        osThreadFn_8000d5e8(param1);
        *(undefined4 *)(param1 + 0x2d0) = param2;
        osThreadFn_8000d4d8(param1);
      }
      else if (uVar1 != 0) {
        osSchedulerFlag_80398294 = 1;
        *(undefined4 *)(param1 + 0x2d0) = param2;
      }
    }
    else if (uVar1 < 5) {
      iVar3 = *(int *)(param1 + 0x2e0);
      iVar2 = *(int *)(param1 + 0x2e4);
      if (iVar3 == 0) {
        *(int *)(*(int *)(param1 + 0x2dc) + 4) = iVar2;
      }
      else {
        *(int *)(iVar3 + 0x2e4) = iVar2;
      }
      if (iVar2 == 0) {
        **(int **)(param1 + 0x2dc) = iVar3;
      }
      else {
        *(int *)(iVar2 + 0x2e0) = iVar3;
      }
      *(undefined4 *)(param1 + 0x2d0) = param2;
      for (iVar2 = **(int **)(param1 + 0x2dc);
          (iVar2 != 0 && (*(int *)(iVar2 + 0x2d0) <= *(int *)(param1 + 0x2d0)));
          iVar2 = *(int *)(iVar2 + 0x2e0)) {
      }
      if (iVar2 == 0) {
        iVar2 = *(int *)(*(int *)(param1 + 0x2dc) + 4);
        if (iVar2 == 0) {
          **(int **)(param1 + 0x2dc) = param1;
        }
        else {
          *(int *)(iVar2 + 0x2e0) = param1;
        }
        *(int *)(param1 + 0x2e4) = iVar2;
        *(undefined4 *)(param1 + 0x2e0) = 0;
        *(int *)(*(int *)(param1 + 0x2dc) + 4) = param1;
      }
      else {
        *(int *)(param1 + 0x2e0) = iVar2;
        iVar3 = *(int *)(iVar2 + 0x2e4);
        *(int *)(iVar2 + 0x2e4) = param1;
        *(int *)(param1 + 0x2e4) = iVar3;
        if (iVar3 == 0) {
          **(int **)(param1 + 0x2dc) = param1;
        }
        else {
          *(int *)(iVar3 + 0x2e0) = param1;
        }
      }
      if (*(int *)(param1 + 0x2f0) != 0) {
        if (*(int *)(*(int *)(param1 + 0x2f0) + 8) != 0) {
          return *(undefined4 *)(*(int *)(param1 + 0x2f0) + 8);
        }
                    
        OSPanic("OSThread.c",0x232,s_Failed_assertion_thread_>mutex_>_802d3568);
      }
    }
  }
  return 0;
}


void osThreadFn_8000d914(OSThread *thread) { //8000D914
  int param2;
  
  while( true ) {
    if (0 < thread->priority) {
      return;
    }
    param2 = __OSGetEffectivePriority(thread);
    if (thread->base == param2) break;
    thread = (OSThread *)SetEffectivePriority((int)thread,param2);
    if (thread == (OSThread *)0x0) {
      return;
    }
  }
  return;
}


/* Library Function - Single Match
    osThreadFn_8000d978
   
   Library: KioskDefault 0 0 */

OSThread * osThreadFn_8000d978(int param1) { //8000D978
  OSThread *pOVar1;
  OSThread *pOVar2;
  u32 uVar3;
  OSThreadQueue *pOVar4;
  int iVar5;
  
  if (osAlarmCount_80398298 < 1) {
    pOVar1 = (OSThread *)osGetCurContext();
    pOVar2 = osGetCurrentThread();
    if (pOVar1 == pOVar2) {
      if (pOVar2 != (OSThread *)0x0) {
        if (*(short *)&pOVar2->suspend == 2) {
          if ((param1 == 0) && (iVar5 = countLeadingZeros(DAT_80398290), pOVar2->base <= iVar5)) {
            return (OSThread *)0x0;
          }
          *(undefined2 *)&pOVar2->suspend = 1;
          osThreadFn_8000d4d8((int)pOVar2);
        }
        if ((((pOVar2->context).state & 2) == 0) &&
           (uVar3 = OSSaveContext(&pOVar2->context), uVar3 != 0)) {
          return (OSThread *)0x0;
        }
      }
      osCurThread = (OSThread *)0x0;
      if (DAT_80398290 == 0) {
        OSSetCurrentContext((OSContext *)&DAT_803266b8);
        do {
          OSEnableInterrupts();
          do {
          } while (DAT_80398290 == 0);
          OSDisableInterrupts();
        } while (DAT_80398290 == 0);
        OSClearContext((OSContext *)&DAT_803266b8);
      }
      osSchedulerFlag_80398294 = 0;
      iVar5 = countLeadingZeros(DAT_80398290);
      if ((iVar5 < 0) || (0x1f < iVar5)) {
                    
        OSPanic("OSThread.c",0x2c6,"Failed assertion OS_PRIORITY_MIN <= priority && priority <= OS_PRIORITY_MAX");
      }
      pOVar4 = &OSThreadQueue_80325f98 + iVar5;
      pOVar1 = pOVar4->head;
      pOVar2 = (pOVar1->link).prev;
      if (pOVar2 == (OSThread *)0x0) {
        (&OSThreadQueue_80325f98)[iVar5].tail = (OSThread *)0x0;
      }
      else {
        (pOVar2->queueJoin).head = (OSThread *)0x0;
      }
      pOVar4->head = pOVar2;
      if (pOVar1->base != iVar5) {
                    
        OSPanic("OSThread.c",0x2c9,s_Failed_assertion_nextThread_>pri_802d35dc);
      }
      if (pOVar4->head == (OSThread *)0x0) {
        DAT_80398290 = DAT_80398290 & ~(1 << 0x1f - iVar5);
      }
      (pOVar1->link).next = (OSThread *)0x0;
      *(undefined2 *)&pOVar1->suspend = 2;
      FUN_8000d3bc(pOVar1);
    }
    else {
      pOVar1 = (OSThread *)0x0;
    }
  }
  else {
    pOVar1 = (OSThread *)0x0;
  }
  return pOVar1;
}


/* Library Function - Single Match
    OSCreateThread
   
   Library: KioskDefault 0 0 */

BOOL_ OSCreateThread(OSThread *thread,func *func,void *arg,void *stack,u32 stackSize,
                    OSPriority priority,u16 attr) { //8000DB94
  OSThread *pOVar1;
  BOOL_ BVar2;
  int iVar3;
  undefined4 *sp;
  
  if ((-1 < priority) && (priority < 0x20)) {
    if ((priority < 0) || (0x1f < priority)) {
      BVar2 = 0;
    }
    else {
      *(undefined2 *)&thread->suspend = 1;
      *(u16 *)((int)&thread->suspend + 2) = attr & 1;
      thread->val = (void *)priority;
      thread->base = priority;
      thread->priority = 1;
      thread->queue = (OSThreadQueue *)0xffffffff;
      (thread->queueMutex).head = (OSMutex *)0x0;
      OSInitThreadQueue((OSThreadQueue *)&(thread->queueJoin).tail);
      butt2(&(thread->queueMutex).tail);
      sp = (undefined4 *)(((uint)stack & 0xfffffff8) - 8);
      *sp = 0;
      *(undefined4 *)(((uint)stack & 0xfffffff8) - 4) = 0;
      OSInitContext(&thread->context,(u32)func,(u32)sp);
      (thread->context).lr = (u32)OSExitThread;
      (thread->context).gpr[3] = (u32)arg;
      thread->stackEnd = (u32 *)stack;
      thread[1].context.gpr[0] = (int)stack - stackSize;
      *(undefined4 *)thread[1].context.gpr[0] = 0xdeadbabe;
      BVar2 = OSDisableInterrupts();
      iVar3 = __OSIsThreadActive(thread);
      if (iVar3 != 0) {
                    
        OSPanic("OSThread.c",0x33b,"OSCreateThread(): thread %p is still active.",thread);
      }
      pOVar1 = thread;
      if (osCurThreadQueueTail != (OSThread *)0x0) {
        (osCurThreadQueueTail->linkActive).prev = thread;
        pOVar1 = osCurThreadQueueHead;
      }
      osCurThreadQueueHead = pOVar1;
      thread->stackBase = (u8 *)osCurThreadQueueTail;
      (thread->linkActive).prev = (OSThread *)0x0;
      osCurThreadQueueTail = thread;
      OSRestoreInterrupts(BVar2);
      BVar2 = 1;
    }
    return BVar2;
  }
                    
  OSPanic("OSThread.c",0x31c,"OSCreateThread(): priority out of range (0 <= priority <= 31).");
}


/* Library Function - Single Match
    OSExitThread
   
   Library: KioskDefault 0 0 */

void OSExitThread(OSThreadQueue *queue) { //8000DD30
  OSThread *pOVar1;
  BOOL_ level;
  OSThread *param1;
  int iVar2;
  OSThread *pOVar3;
  OSThread *pOVar4;
  
  level = OSDisableInterrupts();
  param1 = osGetCurrentThread();
  if (param1 == (OSThread *)0x0) {
                    
    OSPanic("OSThread.c",0x354,"OSExitThread(): current thread does not exist.");
  }
  if (*(short *)&param1->suspend == 2) {
    iVar2 = __OSIsThreadActive(param1);
    if (iVar2 != 0) {
      OSClearContext(&param1->context);
      if ((*(ushort *)((int)&param1->suspend + 2) & 1) == 0) {
        *(undefined2 *)&param1->suspend = 8;
        param1->queue = queue;
      }
      else {
        pOVar4 = (param1->linkActive).prev;
        pOVar3 = (OSThread *)param1->stackBase;
        pOVar1 = pOVar3;
        if (pOVar4 != (OSThread *)0x0) {
          pOVar4->stackBase = (u8 *)pOVar3;
          pOVar1 = osCurThreadQueueTail;
        }
        osCurThreadQueueTail = pOVar1;
        if (pOVar3 != (OSThread *)0x0) {
          (pOVar3->linkActive).prev = pOVar4;
          pOVar4 = osCurThreadQueueHead;
        }
        osCurThreadQueueHead = pOVar4;
        *(undefined2 *)&param1->suspend = 0;
      }
      osMutexFn_8000bdc4((OSMutex *)param1);
      osThreadFn_8000e3a0((OSThread *)&(param1->queueJoin).tail);
      osSchedulerFlag_80398294 = 1;
      __OSReschedule();
      OSRestoreInterrupts(level);
      return;
    }
                    
    OSPanic("OSThread.c",0x358,"OSExitThread(): current thread is not active.");
  }
                    
  OSPanic("OSThread.c",0x356,"OSExitThread(): current thread is not running.");
}


/* Library Function - Single Match
    OSResumeThread
   
   Library: KioskDefault 0 0 */

s32 OSResumeThread(OSThread *thread) { //8000DE64
  ushort uVar1;
  BOOL_ level;
  int iVar2;
  int iVar3;
  OSThread *pOVar4;
  OSThread *pOVar5;
  
  level = OSDisableInterrupts();
  iVar2 = __OSIsThreadActive(thread);
  if (iVar2 == 0) {
                    
    OSPanic("OSThread.c",0x419,"OSResumeThread(): thread %p is not active.",thread);
  }
  if (*(short *)&thread->suspend != 8) {
    iVar2 = thread->priority;
    thread->priority = iVar2 + -1;
    if (thread->priority < 0) {
      thread->priority = 0;
    }
    else if (thread->priority == 0) {
      uVar1 = *(ushort *)&thread->suspend;
      if (uVar1 == 4) {
        if ((thread->link).next == (OSThread *)0x0) {
                    
          OSPanic("OSThread.c",0x42a,s_Failed_assertion_thread_>queue_802d37ec);
        }
        pOVar5 = (thread->link).prev;
        pOVar4 = (thread->queueJoin).head;
        if (pOVar5 == (OSThread *)0x0) {
          (((thread->link).next)->context).gpr[1] = (u32)pOVar4;
        }
        else {
          (pOVar5->queueJoin).head = pOVar4;
        }
        if (pOVar4 == (OSThread *)0x0) {
          (((thread->link).next)->context).gpr[0] = (u32)pOVar5;
        }
        else {
          (pOVar4->link).prev = pOVar5;
        }
        iVar3 = __OSGetEffectivePriority(thread);
        thread->base = iVar3;
        for (pOVar4 = (OSThread *)(((thread->link).next)->context).gpr[0];
            (pOVar4 != (OSThread *)0x0 && (pOVar4->base <= thread->base));
            pOVar4 = (pOVar4->link).prev) {
        }
        if (pOVar4 == (OSThread *)0x0) {
          pOVar4 = (OSThread *)(((thread->link).next)->context).gpr[1];
          if (pOVar4 == (OSThread *)0x0) {
            (((thread->link).next)->context).gpr[0] = (u32)thread;
          }
          else {
            (pOVar4->link).prev = thread;
          }
          (thread->queueJoin).head = pOVar4;
          (thread->link).prev = (OSThread *)0x0;
          (((thread->link).next)->context).gpr[1] = (u32)thread;
        }
        else {
          (thread->link).prev = pOVar4;
          pOVar5 = (pOVar4->queueJoin).head;
          (pOVar4->queueJoin).head = thread;
          (thread->queueJoin).head = pOVar5;
          if (pOVar5 == (OSThread *)0x0) {
            (((thread->link).next)->context).gpr[0] = (u32)thread;
          }
          else {
            (pOVar5->link).prev = thread;
          }
        }
        if ((thread->queueMutex).head != (OSMutex *)0x0) {
          osThreadFn_8000d914(((thread->queueMutex).head)->thread);
        }
      }
      else if ((uVar1 < 4) && (uVar1 == 1)) {
        iVar3 = __OSGetEffectivePriority(thread);
        thread->base = iVar3;
        osThreadFn_8000d4d8((int)thread);
      }
      __OSReschedule();
    }
    OSRestoreInterrupts(level);
    return iVar2;
  }
                    
  OSPanic("OSThread.c",0x41b,"OSResumeThread(): thread %p is terminated.",thread);
}


/* Library Function - Single Match
    OSSuspendThread
   
   Library: KioskDefault 0 0 */

s32 OSSuspendThread(OSThread *thread) { //8000E07C
  ushort uVar1;
  BOOL_ level;
  int iVar2;
  OSThread *pOVar3;
  OSThread *pOVar4;
  
  level = OSDisableInterrupts();
  iVar2 = __OSIsThreadActive(thread);
  if (iVar2 == 0) {
                    
    OSPanic("OSThread.c",0x44c,"OSSuspendThread(): thread %p is not active.",thread);
  }
  if (*(short *)&thread->suspend != 8) {
    iVar2 = thread->priority;
    thread->priority = iVar2 + 1;
    if (iVar2 == 0) {
      uVar1 = *(ushort *)&thread->suspend;
      if (uVar1 != 3) {
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            osThreadFn_8000d5e8((int)thread);
          }
          else if (uVar1 != 0) {
            osSchedulerFlag_80398294 = 1;
            *(undefined2 *)&thread->suspend = 1;
          }
        }
        else if (uVar1 < 5) {
          pOVar4 = (thread->link).prev;
          pOVar3 = (thread->queueJoin).head;
          if (pOVar4 == (OSThread *)0x0) {
            (((thread->link).next)->context).gpr[1] = (u32)pOVar3;
          }
          else {
            (pOVar4->queueJoin).head = pOVar3;
          }
          if (pOVar3 == (OSThread *)0x0) {
            (((thread->link).next)->context).gpr[0] = (u32)pOVar4;
          }
          else {
            (pOVar3->link).prev = pOVar4;
          }
          thread->base = 0x20;
          pOVar3 = (OSThread *)(((thread->link).next)->context).gpr[1];
          if (pOVar3 == (OSThread *)0x0) {
            (((thread->link).next)->context).gpr[0] = (u32)thread;
          }
          else {
            (pOVar3->link).prev = thread;
          }
          (thread->queueJoin).head = pOVar3;
          (thread->link).prev = (OSThread *)0x0;
          (((thread->link).next)->context).gpr[1] = (u32)thread;
          if ((thread->queueMutex).head != (OSMutex *)0x0) {
            if (((thread->queueMutex).head)->thread == (OSThread *)0x0) {
                    
              OSPanic("OSThread.c",0x463,s_Failed_assertion_thread_>mutex_>_802d3568);
            }
            osThreadFn_8000d914(((thread->queueMutex).head)->thread);
          }
        }
      }
      __OSReschedule();
    }
    OSRestoreInterrupts(level);
    return iVar2;
  }
                    
  OSPanic("OSThread.c",0x44e,"OSSuspendThread(): thread %p is terminated.",thread);
}


/* Library Function - Single Match
    OSSleepThread
   
   Library: KioskDefault 0 0 */

void OSSleepThread(OSThreadQueue *queue) { //8000E22C
  BOOL_ level;
  OSThread *thread;
  int iVar1;
  OSThread *pOVar2;
  OSThread *pOVar3;
  
  level = OSDisableInterrupts();
  thread = osGetCurrentThread();
  if (thread == (OSThread *)0x0) {
                    
    OSPanic("OSThread.c",0x484,"OSSleepThread(): current thread does not exist.");
  }
  iVar1 = __OSIsThreadActive(thread);
  if (iVar1 == 0) {
                    
    OSPanic("OSThread.c",0x486,"OSSleepThread(): current thread %p is not active.",thread);
  }
  if (*(short *)&thread->suspend != 2) {
                    
    OSPanic("OSThread.c",0x488,"OSSleepThread(): current thread %p is not running.",thread);
  }
  if (0 < thread->priority) {
                    
    OSPanic("OSThread.c",0x48a,"OSSleepThread(): current thread %p is suspended.",thread);
  }
  *(undefined2 *)&thread->suspend = 4;
  (thread->link).next = (OSThread *)queue;
  for (pOVar3 = queue->head; (pOVar3 != (OSThread *)0x0 && (pOVar3->base <= thread->base));
      pOVar3 = (pOVar3->link).prev) {
  }
  if (pOVar3 == (OSThread *)0x0) {
    pOVar3 = queue->tail;
    if (pOVar3 == (OSThread *)0x0) {
      queue->head = thread;
    }
    else {
      (pOVar3->link).prev = thread;
    }
    (thread->queueJoin).head = pOVar3;
    (thread->link).prev = (OSThread *)0x0;
    queue->tail = thread;
  }
  else {
    (thread->link).prev = pOVar3;
    pOVar2 = (pOVar3->queueJoin).head;
    (pOVar3->queueJoin).head = thread;
    (thread->queueJoin).head = pOVar2;
    if (pOVar2 == (OSThread *)0x0) {
      queue->head = thread;
    }
    else {
      (pOVar2->link).prev = thread;
    }
  }
  osSchedulerFlag_80398294 = 1;
  __OSReschedule();
  OSRestoreInterrupts(level);
  return;
}


/* Library Function - Single Match
    osThreadFn_8000e3a0
   
   Library: KioskDefault 0 0 */

void osThreadFn_8000e3a0(OSThread *param1) { //8000E3A0
  BOOL_ level;
  int iVar1;
  OSThread *pOVar2;
  OSThread *param1_00;
  
  level = OSDisableInterrupts();
  while( true ) {
    if ((param1->context).gpr[0] == 0) {
      __OSReschedule();
      OSRestoreInterrupts(level);
      return;
    }
    param1_00 = (OSThread *)(param1->context).gpr[0];
    pOVar2 = (param1_00->link).prev;
    if (pOVar2 == (OSThread *)0x0) {
      (param1->context).gpr[1] = 0;
    }
    else {
      (pOVar2->queueJoin).head = (OSThread *)0x0;
    }
    (param1->context).gpr[0] = (u32)pOVar2;
    iVar1 = __OSIsThreadActive(param1_00);
    if (iVar1 == 0) {
                    
      OSPanic("OSThread.c",0x4a7,"Failed assertion __OSIsThreadActive(thread)");
    }
    if (*(short *)&param1_00->suspend == 8) {
                    
      OSPanic("OSThread.c",0x4a8,s_Failed_assertion_thread_>state___802d395c);
    }
    if ((param1_00->link).next != param1) break;
    *(undefined2 *)&param1_00->suspend = 1;
    if (param1_00->priority < 1) {
      osThreadFn_8000d4d8((int)param1_00);
    }
  }
                    
  OSPanic("OSThread.c",0x4a9,s_Failed_assertion_thread_>queue___802d3998);
}

