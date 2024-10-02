
/* Library Function - Single Match
    perfViewerCreateMeter_8018f42c
   
   Library: KioskDefault 0 0 */

void * perfAlloc(uint size) { //8018F42C
  void *pvVar1;
  
  pvVar1 = mmAlloc2(size,0xff0000ff,"PERF_VIEWER");
  if (pvVar1 == (void *)0x0) {
                    
    OSPanic("perform_viewer.c",0x87," No Memory for Perf Viewer  ");
  }
  return pvVar1;
}

