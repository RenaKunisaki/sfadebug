
/* Library Function - Single Match
    rcpQueueAddFn_8009fc44
   
   Library: KioskDefault 0 0 */

void rcpQueueAddFn_8009fc44(int param1,undefined4 *param2) { //8009FC44
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (*(short *)(param1 + 0x78) == 10) {
    *(undefined2 *)(param1 + 0x7a) = 0;
    *(undefined2 *)(param1 + 0x78) = 0;
  }
  else {
    uVar2 = *(ushort *)(param1 + 0x78) + 1;
    *(short *)(param1 + 0x78) = (short)uVar2 + (short)(uVar2 / 10) * -10;
    if (*(short *)(param1 + 0x78) == *(short *)(param1 + 0x7a)) {
                    
      OSPanic("rcp_dolphin.c",0x539,"queue overflow");
    }
  }
  puVar3 = (undefined4 *)(param1 + (uint)*(ushort *)(param1 + 0x78) * 0xc);
  uVar1 = param2[1];
  *puVar3 = *param2;
  puVar3[1] = uVar1;
  puVar3[2] = param2[2];
  return;
}


/* Library Function - Single Match
    rcpQueueRemoveFn_8009fcfc
   
   Library: KioskDefault 0 0 */

void rcpQueueRemoveFn_8009fcfc(undefined4 *out,int queue) { //8009FCFC
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar1 = *(ushort *)(queue + 0x7a);
  if (*(short *)(queue + 0x78) == 10) {
                    
    OSPanic("rcp_dolphin.c",0x546,"queue underflow");
  }
  if (*(short *)(queue + 0x7a) == *(short *)(queue + 0x78)) {
    *(undefined2 *)(queue + 0x78) = 10;
  }
  else {
    uVar3 = *(ushort *)(queue + 0x7a) + 1;
    *(short *)(queue + 0x7a) = (short)uVar3 + (short)(uVar3 / 10) * -10;
  }
  puVar4 = (undefined4 *)(queue + (uint)uVar1 * 0xc);
  uVar2 = puVar4[1];
  *out = *puVar4;
  out[1] = uVar2;
  out[2] = puVar4[2];
  return;
}


/* Library Function - Single Match
    rcpQueueFn_8009fdb4
   
   Library: KioskDefault 0 0 */

void rcpQueueFn_8009fdb4(undefined4 *param1,int param2) { //8009FDB4
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(short *)(param2 + 0x78) == 10) {
                    
    OSPanic("rcp_dolphin.c",0x559,"queue_top: queue empty");
  }
  puVar2 = (undefined4 *)(param2 + (uint)*(ushort *)(param2 + 0x7a) * 0xc);
  uVar1 = puVar2[1];
  *param1 = *puVar2;
  param1[1] = uVar1;
  param1[2] = puVar2[2];
  return;
}

