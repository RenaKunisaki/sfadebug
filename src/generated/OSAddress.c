
/* Library Function - Single Match
    OSPhysicalToCached
   
   Library: KioskDefault 0 0 */

void * OSPhysicalToCached(u32 paddr) { //800075AC
  if (0xfffffff < paddr) {
                    
    OSPanic("OSAddress.c",0x2c,"OSPhysicalToCached(): illegal address.");
  }
  return (void *)(paddr + 0x80000000);
}


/* Library Function - Single Match
    OSPhysicalToUncached
   
   Library: KioskDefault 0 0 */

void * OSPhysicalToUncached(u32 paddr) { //80007600
  if (0xfffffff < paddr) {
                    
    OSPanic("OSAddress.c",0x3b,"OSPhysicalToUncached(): illegal address.");
  }
  return (void *)(paddr + 0xc0000000);
}


/* Library Function - Single Match
    OSCachedToPhysical
   
   Library: KioskDefault 0 0 */

u32 OSCachedToPhysical(void *caddr) { //80007654
  if (((void *)0x7fffffff < caddr) && (caddr < (void *)0x90000000)) {
    return (int)caddr + 0x80000000;
  }
                    
  OSPanic("OSAddress.c",0x4a,"OSCachedToPhysical(): illegal address.");
}


/* Library Function - Single Match
    OSUncachedToPhysical
   
   Library: KioskDefault 0 0 */

u32 OSUncachedToPhysical(void *ucaddr) { //800076B4
  if (((void *)0xbfffffff < ucaddr) && (ucaddr < (void *)0xd0000000)) {
    return (int)ucaddr + 0x40000000;
  }
                    
  OSPanic("OSAddress.c",0x59,"OSUncachedToPhysical(): illegal address.");
}

