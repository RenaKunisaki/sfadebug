
/* Library Function - Single Match
    OSSetErrorHandler
   
   Library: KioskDefault 0 0 */

OSErrorHandler OSSetErrorHandler(OSError error,OSErrorHandler handler) { //80009B0C
  OSErrorHandler pOVar1;
  
  if (0xe < error) {
                    
    OSPanic("OSError.c",0x8f,"OSSetErrorHandler(): unknown error.");
  }
  pOVar1 = (OSErrorHandler)osErrorHandlers[error];
  osErrorHandlers[error] = handler;
  return pOVar1;
}

