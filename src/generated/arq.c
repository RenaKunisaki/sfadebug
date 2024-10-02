
/* Library Function - Single Match
    arqFn_8001a228
   
   Library: KioskDefault 0 0 */

void arqFn_8001a228(undefined4 *request,undefined4 param2,int type,int priority,undefined4 param5,
                   undefined4 param6,uint length,int param8) { //8001A228
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  BOOL_ level;
  
  if (request == (undefined4 *)0x0) {
                    
    OSPanic("arq.c",0x1a9,"Failed assertion request");
  }
  if ((type != 0) && (type != 1)) {
                    
    OSPanic("arq.c",0x1aa,"Failed assertion (type == ARQ_TYPE_MRAM_TO_ARAM) || (type == ARQ_TYPE_ARAM_TO_MRAM)");
  }
  if ((priority != 0) && (priority != 1)) {
                    
    OSPanic("arq.c",0x1ab,"Failed assertion (priority == ARQ_PRIORITY_LOW) || (priority == ARQ_PRIORITY_HIGH)");
  }
  if ((length & 0x1f) == 0) {
    *request = 0;
    request[1] = param2;
    request[2] = type;
    request[4] = param5;
    request[5] = param6;
    request[6] = length;
    if (param8 == 0) {
      request[7] = &DAT_8001a128;
    }
    else {
      request[7] = param8;
    }
    level = OSDisableInterrupts();
    puVar3 = DAT_80398428;
    puVar4 = (undefined4 *)PTR_DAT_8039842c;
    if (priority == 1) {
      puVar1 = request;
      puVar2 = request;
      if (DAT_80398420 != (undefined4 *)0x0) {
        *DAT_80398424 = request;
        puVar1 = DAT_80398420;
        puVar2 = request;
        puVar3 = DAT_80398428;
        puVar4 = (undefined4 *)PTR_DAT_8039842c;
      }
    }
    else {
      puVar1 = DAT_80398420;
      puVar2 = DAT_80398424;
      if (((priority < 1) && (-1 < priority)) &&
         (puVar3 = request, puVar4 = request, DAT_80398428 != (undefined4 *)0x0)) {
        *(undefined4 **)PTR_DAT_8039842c = request;
        puVar1 = DAT_80398420;
        puVar2 = DAT_80398424;
        puVar3 = DAT_80398428;
        puVar4 = request;
      }
    }
    PTR_DAT_8039842c = (undefined *)puVar4;
    DAT_80398428 = puVar3;
    DAT_80398424 = puVar2;
    DAT_80398420 = puVar1;
    if (((DAT_80398430 == 0) && (DAT_80398434 == 0)) && (FUN_80019f20(), DAT_80398430 == 0)) {
      __ARQServiceQueueLo();
    }
    OSRestoreInterrupts(level);
    return;
  }
                    
  OSPanic("arq.c",0x1ae,"Failed assertion (length % ARQ_DMA_ALIGNMENT) == 0");
}

