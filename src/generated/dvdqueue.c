
/* Library Function - Single Match
    dvdQueueFn_80013ff8
   
   Library: KioskDefault 0 0 */

DVDCommandBlock * PopWaitingQueuePrio(int prio) { //80013FF8
  BOOL_ level;
  DVDCommandBlock *pDVar1;
  DVDCommandBlock *pDVar2;
  
  level = OSDisableInterrupts();
  pDVar1 = (DVDCommandBlock *)(WaitingQueue + prio);
  if (pDVar1->next == pDVar1) {
                    
    OSPanic("dvdqueue.c",0x54,s_Failed_assertion_q_>next____q_802d674c);
  }
  pDVar2 = pDVar1->next;
  pDVar1->next = pDVar2->next;
  pDVar2->next->prev = pDVar1;
  OSRestoreInterrupts(level);
  pDVar2->next = (DVDCommandBlock *)0x0;
  pDVar2->prev = (DVDCommandBlock *)0x0;
  return pDVar2;
}

