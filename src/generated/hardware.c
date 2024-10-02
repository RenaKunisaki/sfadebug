
/* Library Function - Single Match
    musyxInitAramHandler
   
   Library: KioskDefault 0 0 */

void musyxInitAramHandler(int baseAddr,uint aramSize) { //80058774
  if (baseAddr != 0) {
                    
    OSPanic("hardware.c",0x39c,"Failed assertion baseAddr==0x00000000");
  }
  musyxInitAramHandler_(aramSize);
  return;
}

