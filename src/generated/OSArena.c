
/* Library Function - Single Match
    OSGetArenaHi
   
   Library: KioskDefault 0 0 */

void * OSGetArenaHi(void) { //800087C4
  if (osArenaLo == (undefined *)0xffffffff) {
                    
    OSPanic("OSArena.c",0x37,"OSGetArenaHi(): OSInit() must be called in advance.");
  }
  if (osArenaHi < osArenaLo) {
                    
    OSPanic("OSArena.c",0x39,"OSGetArenaHi(): invalid arena (hi < lo).");
  }
  return osArenaHi;
}


/* Library Function - Single Match
    OSGetArenaLo
   
   Library: KioskDefault 0 0 */

void * OSGetArenaLo(void) { //8000883C
  if (osArenaLo == (undefined *)0xffffffff) {
                    
    OSPanic("OSArena.c",0x49,"OSGetArenaLo(): OSInit() must be called in advance.");
  }
  if (osArenaHi < osArenaLo) {
                    
    OSPanic("OSArena.c",0x4b,"OSGetArenaLo(): invalid arena (hi < lo).");
  }
  return osArenaLo;
}


void osSetArenaHi(void *param1) { //800088B4
  osArenaHi = (undefined *)param1;
  return;
}


void osSetArenaLo(void *param1) { //800088BC
  osArenaLo = (undefined *)param1;
  return;
}

