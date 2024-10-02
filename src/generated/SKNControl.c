
/* Library Function - Single Match
    skinFn_800816b4
   
   Library: KioskDefault 0 0 */

void skinFn_800816b4(int param1,int param2,int param3,int param4) { //800816B4
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_28 [6];
  
  if (*(char *)(param2 + 6) == '\0') {
                    
    OSPanic("SKNControl.c",0x87,s_Failed_assertion_hdr_>posNrmShif_802ec998);
  }
  if (0x1f < *(byte *)(param2 + 6)) {
                    
    OSPanic("SKNControl.c",0x88,s_Failed_assertion_hdr_>posNrmShif_802ec9c0);
  }
  FUN_80081d50((uint)*(byte *)(param2 + 6),7,(uint)*(byte *)(param2 + 6),7);
  if (*(short *)(param2 + 2) != 0) {
    if (*(int *)(param2 + 0xc) == 0) {
                    
      OSPanic("SKNControl.c",0xd6,s_Failed_assertion_hdr_>sk2ListArr_802ec9f4);
    }
    if (*(short *)(*(int *)(param2 + 0xc) + 0x70) == 0) {
                    
      OSPanic("SKNControl.c",0xd7,s_Failed_assertion_hdr_>sk2ListArr_802eca18);
    }
    if (*(int *)(*(int *)(param2 + 0xc) + 0x60) == 0) {
                    
      OSPanic("SKNControl.c",0xd8,s_Failed_assertion_hdr_>sk2ListArr_802eca44);
    }
    uVar1 = FUN_80081af8(0,(void *)(param3 + *(int *)(*(int *)(param2 + 0xc) + 0x60)),
                         (uint)*(byte *)(*(int *)(param2 + 0xc) + 0x73) << 5);
    local_28[0] = (undefined2)uVar1;
    FUN_80081af8(1,*(void **)(*(int *)(param2 + 0xc) + 100),
                 (uint)*(byte *)(*(int *)(param2 + 0xc) + 0x6f) << 5);
    for (uVar1 = 0; uVar1 < *(ushort *)(param2 + 2) - 1; uVar1 = uVar1 + 1) {
      iVar3 = *(int *)(param2 + 0xc) + uVar1 * 0x74;
      uVar2 = FUN_80081af8(((char)uVar1 + '\x01') * '\x02' & 2,
                           (void *)(param3 + *(int *)(*(int *)(param2 + 0xc) +
                                                     (uVar1 + 1) * 0x74 + 0x60)),
                           (uint)*(byte *)(*(int *)(param2 + 0xc) + (uVar1 + 1) * 0x74 + 0x73) << 5)
      ;
      *(short *)((int)local_28 + ((uVar1 + 1) * 2 & 2)) = (short)uVar2;
      FUN_80081af8((((char)uVar1 + '\x01') * '\x02' & 2U) + 1,
                   *(void **)(*(int *)(param2 + 0xc) + (uVar1 + 1) * 0x74 + 100),
                   (uint)*(byte *)(*(int *)(param2 + 0xc) + (uVar1 + 1) * 0x74 + 0x6f) << 5);
      if (*(ushort *)(iVar3 + 0x70) < 3) {
                    
        OSPanic("SKNControl.c",0xef,s_Failed_assertion_curr2_>count_>_2_802eca74);
      }
      FUN_80008e08(2);
      FUN_80081a5c((float *)(param1 + (uint)*(byte *)(iVar3 + 0x6c) * 0x30),
                   (float *)(param1 + (uint)*(byte *)(iVar3 + 0x6d) * 0x30),(uVar1 & 1) << 1,
                   *(uint *)(param4 + uVar1 * 4),(uint)*(ushort *)(iVar3 + 0x70),
                   (uint)*(byte *)(iVar3 + 0x72));
    }
    iVar3 = *(int *)(param2 + 0xc) + uVar1 * 0x74;
    if (*(ushort *)(iVar3 + 0x70) < 3) {
                    
      OSPanic("SKNControl.c",0xfc,s_Failed_assertion_curr2_>count_>_2_802eca74);
    }
    FUN_80008e08(0);
    FUN_80081a5c((float *)(param1 + (uint)*(byte *)(iVar3 + 0x6c) * 0x30),
                 (float *)(param1 + (uint)*(byte *)(iVar3 + 0x6d) * 0x30),(uVar1 & 1) << 1,
                 *(uint *)(param4 + uVar1 * 4),(uint)*(ushort *)(iVar3 + 0x70),
                 (uint)*(byte *)(iVar3 + 0x72));
    FUN_80008e08(0);
  }
  return;
}

