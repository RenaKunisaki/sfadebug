
/* Library Function - Single Match
    osMutexFn_8000bdc4
   
   Library: KioskDefault 0 0 */

void osMutexFn_8000bdc4(OSMutex *mutex) { //8000BDC4
  u32 uVar1;
  OSThread *param1;
  
  while( true ) {
    if (mutex[0x1f].count == 0) {
      return;
    }
    param1 = (OSThread *)mutex[0x1f].count;
    uVar1 = (param1->context).gpr[4];
    if (uVar1 == 0) {
      mutex[0x1f].link.next = (OSMutex *)0x0;
    }
    else {
      *(undefined4 *)(uVar1 + 0x14) = 0;
    }
    mutex[0x1f].count = uVar1;
    if ((OSMutex *)(param1->context).gpr[2] != mutex) break;
    (param1->context).gpr[3] = 0;
    (param1->context).gpr[2] = 0;
    osThreadFn_8000e3a0(param1);
  }
                    
  OSPanic("OSMutex.c",0xe5,s_Failed_assertion_mutex_>thread___802d3084);
}

