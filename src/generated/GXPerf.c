
/* Library Function - Single Match
    GXClearGPMetric
   
   Library: KioskDefault 0 0 */

void GXClearGPMetric(void) { //800379DC
  if (gx->isDlistInProgress != false) {
                    
    OSPanic("GXPerf.c",0x322,"GXClearGPMetric: don't use in a display list");
  }
  *(undefined2 *)(PTR_CP_SR_80398470 + 4) = 4;
  return;
}


/* Library Function - Single Match
    GXInitXfRasMetric
   
   Library: KioskDefault 0 0 */

void GXInitXfRasMetric(void) { //80037A38
  if (isInGxBegin) {
                    
    OSPanic("GXPerf.c",0x489,"'GXInitXfRasMetric' is not allowed between GXBegin/GXEnd");
  }
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0x2402c022;
  *(undefined4 *)(pGxDebug->isRegInit + 0xc90) = 0x2402c022;
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x1006;
  GXFIFO = 0x31000;
  if ((true) && (true)) {
    *(undefined **)&pGxDebug->field_0x20 = &DAT_00031000;
    pGxDebug->isRegInit[0x1006] = 1;
  }
  gx->field2_0x2 = 0;
  return;
}

