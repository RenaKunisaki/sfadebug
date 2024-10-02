
/* Library Function - Single Match
    timerTickDown
   
   Library: KioskDefault 0 0 */

undefined4 timerTickDown(short *param1) { //800C8510
  undefined4 uVar1;
  
  if (param1 == (short *)0x0) {
                    
    OSPanic("timer.c",0x26,"Failed assertion timer");
  }
  if (*param1 < 0) {
                    
    OSPanic("timer.c",0x27,s_Failed_assertion__timer_>__0_802f3d48);
  }
  if ((*param1 == 0) || (*param1 = *param1 - (ushort)framesThisStep, 0 < *param1)) {
    uVar1 = 0;
  }
  else {
    timerReset(param1);
    uVar1 = 1;
  }
  return uVar1;
}


/* Library Function - Single Match
    timerSet
   
   Library: KioskDefault 0 0 */

void timerSet(short *param1,short param2) { //800C85B8
  if (param1 == (short *)0x0) {
                    
    OSPanic("timer.c",0x41,"Failed assertion timer");
  }
  if (param2 < 1) {
                    
    OSPanic("timer.c",0x42,s_Failed_assertion_initialVal_>_0_802f3d68);
  }
  if (*param1 != 0) {
                    
    OSPanic("timer.c",0x43,"Failed assertion *timer == 0");
  }
  *param1 = (short)((param2 * 0x3c) / 0x3c);
  return;
}


/* Library Function - Single Match
    timerReset
   
   Library: KioskDefault 0 0 */

void timerReset(undefined2 *param1) { //800C865C
  if (param1 == (undefined2 *)0x0) {
                    
    OSPanic("timer.c",0x51,"Failed assertion timer");
  }
  *param1 = 0;
  return;
}


/* Library Function - Single Match
    timerGetTime
   
   Library: KioskDefault 0 0 */

int timerGetTime(short *param1) { //800C86AC
  if (*param1 < 0) {
                    
    OSPanic("timer.c",0x5f,s_Failed_assertion__timer_>__0_802f3d48);
  }
  return (int)*param1;
}


/* Library Function - Single Match
    timerRand
   
   Library: KioskDefault 0 0 */

uint timerRand(int param1) { //800C86FC
  uint uVar1;
  int iVar2;
  
  if (param1 < 1) {
                    
    OSPanic("timer.c",0x76,s_Failed_assertion_chance_>_0_802f3da8);
  }
  iVar2 = randInt(0,(param1 * 0x3c) / 0x3c);
  uVar1 = countLeadingZeros(iVar2);
  return uVar1 >> 5;
}

