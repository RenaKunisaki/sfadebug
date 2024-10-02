
/* Library Function - Single Match
    osExiFn_80009e34
   
   Library: KioskDefault 0 0 */

void osExiFn_80009e34(int param1) { //80009E34
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  
  iVar1 = param1 * 0x38;
  if (-1 < param1) {
    if (param1 < 3) {
      if ((*(uint *)((int)_osExiStates + iVar1) & 3) != 0) {
        if (((*(uint *)((int)_osExiStates + iVar1) & 2) != 0) &&
           (iVar2 = *(int *)((int)_osExiStates + iVar1 + 4), iVar2 != 0)) {
          puVar4 = *(undefined **)((int)_osExiStates + iVar1 + 8);
          uVar3 = (&EXI_CHANNEL0)[param1 * 5 + 4];
          for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
            *puVar4 = (char)(uVar3 >> (3 - iVar5) * 8);
            puVar4 = puVar4 + 1;
          }
        }
        *(uint *)((int)_osExiStates + iVar1) = *(uint *)((int)_osExiStates + iVar1) & 0xfffffffc;
      }
      return;
    }
  }
                    
  OSPanic("OSExi.c",0x115,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    osExiFn_80009f08
   
   Library: KioskDefault 0 0 */

undefined4 osExiFn_80009f08(int param1,int param2,int param3,uint param4,undefined4 param5) { //80009F08
  BOOL_ level;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = param1 * 0x38;
  if ((*(uint *)((int)_osExiStates + iVar2) & 4) == 0) {
                    
    OSPanic("OSExi.c",0x13b,s_Failed_assertion_exi_>state___ST_802d2980);
  }
  if ((-1 < param1) && (param1 < 3)) {
    if ((0 < param3) && (param3 < 5)) {
      if (param4 < 3) {
        level = OSDisableInterrupts();
        if (((*(uint *)((int)_osExiStates + iVar2) & 3) == 0) &&
           ((*(uint *)((int)_osExiStates + iVar2) & 4) != 0)) {
          *(undefined4 *)(&DAT_80325d64 + iVar2) = param5;
          if (*(int *)(&DAT_80325d64 + iVar2) != 0) {
            osExiFn_8000a43c(param1,0,1,0);
            __OSUnmaskInterrupts(0x200000 >> param1 * 3);
          }
          *(uint *)((int)_osExiStates + iVar2) = *(uint *)((int)_osExiStates + iVar2) | 2;
          if (param4 != 0) {
            uVar3 = 0;
            for (iVar4 = 0; iVar4 < param3; iVar4 = iVar4 + 1) {
              uVar3 = uVar3 | (uint)*(byte *)(param2 + iVar4) << (3 - iVar4) * 8;
            }
            (&EXI_CHANNEL0)[param1 * 5 + 4] = uVar3;
          }
          *(int *)((int)_osExiStates + iVar2 + 8) = param2;
          iVar4 = param3;
          if (param4 == 1) {
            iVar4 = 0;
          }
          *(int *)((int)_osExiStates + iVar2 + 4) = iVar4;
          (&EXI_CHANNEL0)[param1 * 5 + 3] = param4 << 2 | 1 | (param3 + -1) * 0x10;
          OSRestoreInterrupts(level);
          uVar1 = 1;
        }
        else {
          OSRestoreInterrupts(level);
          uVar1 = 0;
        }
        return uVar1;
      }
                    
      OSPanic("OSExi.c",0x13e,s_Failed_assertion_type_<_MAX_TYPE_802d29dc);
    }
                    
    OSPanic("OSExi.c",0x13d,s_Failed_assertion_0_<_len_&&_len_<_802d29b0);
  }
                    
  OSPanic("OSExi.c",0x13c,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    osExiFn_8000a190
   
   Library: KioskDefault 0 0 */

undefined4 osExiFn_8000a190(int channel,uint offset,uint len,int type,undefined4 param5) { //8000A190
  BOOL_ level;
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = channel * 0x38;
  if ((*(uint *)((int)_osExiStates + iVar2) & 4) == 0) {
                    
    OSPanic("OSExi.c",0x1a4,s_Failed_assertion_exi_>state___ST_802d2980);
  }
  if ((offset & 0x1f) != 0) {
                    
    OSPanic("OSExi.c",0x1a5,"Failed assertion OFFSET(buf, 32) == 0");
  }
  if (0 < (int)len) {
    if ((len & 0x1f) == 0) {
      if ((len & 0xfc00001f) != 0) {
                    
        OSPanic("OSExi.c",0x1a8,"Failed assertion ((u32) len & ~EXI_0LENGTH_EXILENGTH_MASK) == 0");
      }
      if ((type != 0) && (type != 1)) {
                    
        OSPanic("OSExi.c",0x1aa,"Failed assertion type == EXI_READ || type == EXI_WRITE");
      }
      level = OSDisableInterrupts();
      if (((*(uint *)((int)_osExiStates + iVar2) & 3) == 0) &&
         ((*(uint *)((int)_osExiStates + iVar2) & 4) != 0)) {
        *(undefined4 *)(&DAT_80325d64 + iVar2) = param5;
        if (*(int *)(&DAT_80325d64 + iVar2) != 0) {
          osExiFn_8000a43c(channel,0,1,0);
          __OSUnmaskInterrupts(0x200000 >> channel * 3);
        }
        *(uint *)((int)_osExiStates + iVar2) = *(uint *)((int)_osExiStates + iVar2) | 1;
        (&EXI_CHANNEL0)[channel * 5 + 1] = offset & 0x3ffffe0;
        (&EXI_CHANNEL0)[channel * 5 + 2] = len;
        (&EXI_CHANNEL0)[channel * 5 + 3] = type << 2 | 3;
        OSRestoreInterrupts(level);
        uVar1 = 1;
      }
      else {
        OSRestoreInterrupts(level);
        uVar1 = 0;
      }
      return uVar1;
    }
  }
                    
  OSPanic("OSExi.c",0x1a6,s_Failed_assertion_0_<_len_&&_OFFS_802d2a28);
}


/* Library Function - Single Match
    osExiFn_8000a354
   
   Library: KioskDefault 0 0 */

uint osExiFn_8000a354(int chan) { //8000A354
  bool bVar1;
  BOOL_ level;
  int iVar2;
  uint uVar3;
  
  iVar2 = chan * 0x38;
  uVar3 = 0;
  if ((chan < 0) || (2 < chan)) {
                    
    OSPanic("OSExi.c",0x1d7,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
  }
  do {
    if ((*(uint *)((int)_osExiStates + iVar2) & 4) == 0) goto LAB_8000a400;
  } while (((&EXI_CHANNEL0)[chan * 5 + 3] & 1) != 0);
  level = OSDisableInterrupts();
  bVar1 = (*(uint *)((int)_osExiStates + iVar2) & 4) != 0;
  if (bVar1) {
    osExiFn_80009e34(chan);
  }
  uVar3 = (uint)bVar1;
  OSRestoreInterrupts(level);
LAB_8000a400:
  if ((*(uint *)((int)_osExiStates + iVar2) & 3) != 0) {
                    
    OSPanic("OSExi.c",0x1e9,s_Failed_assertion___exi_>state___S_802d2ad4);
  }
  return uVar3;
}


/* Library Function - Single Match
    osExiFn_8000a43c
   
   Library: KioskDefault 0 0 */

uint osExiFn_8000a43c(int chan,int param2,int param3,int param4) { //8000A43C
  uint uVar1;
  dword dVar2;
  
  if ((-1 < chan) && (chan < 3)) {
    uVar1 = (&EXI_CHANNEL0)[chan * 5];
    dVar2 = uVar1 & 0x7f5;
    if (param2 != 0) {
      dVar2 = dVar2 | 2;
    }
    if (param3 != 0) {
      dVar2 = dVar2 | 8;
    }
    if (param4 != 0) {
      dVar2 = dVar2 | 0x800;
    }
    (&EXI_CHANNEL0)[chan * 5] = dVar2;
    return uVar1;
  }
                    
  OSPanic("OSExi.c",0x1fe,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    osExiFn_8000a4fc
   
   Library: KioskDefault 0 0 */

int osExiFn_8000a4fc(int chan,int param2) { //8000A4FC
  BOOL_ level;
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_80325d60 + chan * 0x38);
  if ((-1 < chan) && (chan < 3)) {
    level = OSDisableInterrupts();
    iVar1 = *piVar2;
    *piVar2 = param2;
    if (chan == 2) {
      SetExiInterruptMask(0,(int *)&DAT_80325d60);
    }
    else {
      SetExiInterruptMask(chan,piVar2);
    }
    OSRestoreInterrupts(level);
    return iVar1;
  }
                    
  OSPanic("OSExi.c",0x220,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    osExiFn_8000a5e8
   
   Library: KioskDefault 0 0 */

undefined4 __EXIProbe(int chan) { //8000A5E8
  undefined4 uVar1;
  BOOL_ level;
  int iVar2;
  uint uVar3;
  OSTime time;
  undefined8 uVar4;
  
  if ((-1 < chan) && (chan < 3)) {
    if (chan == 2) {
      uVar1 = 1;
    }
    else {
      uVar1 = 1;
      level = OSDisableInterrupts();
      uVar3 = (&EXI_CHANNEL0)[chan * 5];
      if ((*(uint *)((int)_osExiStates + chan * 0x38) & 8) == 0) {
        if ((uVar3 & 0x800) != 0) {
          osExiFn_8000a43c(chan,0,0,1);
          (&DAT_800030c0)[chan] = 0;
        }
        if ((uVar3 & 0x1000) == 0) {
          (&DAT_800030c0)[chan] = 0;
          uVar1 = 0;
        }
        else {
          uVar3 = busClockMhz / 4000;
          time = OSGetTime();
          uVar4 = __div2i((uint)((ulonglong)time >> 0x20),(uint)time,0,uVar3);
          uVar4 = __div2i((uint)((ulonglong)uVar4 >> 0x20),(uint)uVar4,0,100);
          iVar2 = (int)uVar4 + 1;
          if ((&DAT_800030c0)[chan] == 0) {
            (&DAT_800030c0)[chan] = iVar2;
          }
          if (iVar2 - (&DAT_800030c0)[chan] < 3) {
            uVar1 = 0;
          }
        }
      }
      else if (((uVar3 & 0x1000) == 0) || ((uVar3 & 0x800) != 0)) {
        (&DAT_800030c0)[chan] = 0;
        uVar1 = 0;
      }
      OSRestoreInterrupts(level);
    }
    return uVar1;
  }
                    
  OSPanic("OSExi.c",0x256,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    osExiFn_8000a798
   
   Library: KioskDefault 0 0 */

undefined4 osExiFn_8000a798(int chan,undefined4 param2) { //8000A798
  BOOL_ level;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = chan * 0x38;
  if ((-1 < chan) && (chan < 2)) {
    level = OSDisableInterrupts();
    if ((*(uint *)((int)_osExiStates + iVar3) & 8) == 0) {
      iVar2 = __EXIProbe(chan);
      if (iVar2 == 0) {
        OSRestoreInterrupts(level);
        uVar1 = 0;
      }
      else {
        osExiFn_8000a43c(chan,1,0,0);
        *(undefined4 *)(&DAT_80325d68 + iVar3) = param2;
        __OSUnmaskInterrupts(0x100000 >> chan * 3);
        *(uint *)((int)_osExiStates + iVar3) = *(uint *)((int)_osExiStates + iVar3) | 8;
        OSRestoreInterrupts(level);
        uVar1 = 1;
      }
    }
    else {
      OSRestoreInterrupts(level);
      uVar1 = 0;
    }
    return uVar1;
  }
                    
  OSPanic("OSExi.c",0x2ae,s_Failed_assertion_0_<__chan_&&_ch_802d2b00);
}


/* Library Function - Single Match
    osExiFn_8000a884
   
   Library: KioskDefault 0 0 */

undefined4 EXIDetach(int chan) { //8000A884
  BOOL_ level;
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = chan * 0x38;
  if ((-1 < chan) && (chan < 2)) {
    level = OSDisableInterrupts();
    if ((*(uint *)((int)_osExiStates + iVar2) & 8) == 0) {
      OSRestoreInterrupts(level);
      uVar1 = 1;
    }
    else if (((*(uint *)((int)_osExiStates + iVar2) & 0x10) == 0) ||
            (*(int *)((int)_osExiStates + iVar2 + 0xc) != 0)) {
      *(uint *)((int)_osExiStates + iVar2) = *(uint *)((int)_osExiStates + iVar2) & 0xfffffff7;
      __OSMaskInterrupts(0x700000 >> chan * 3);
      OSRestoreInterrupts(level);
      uVar1 = 1;
    }
    else {
      OSRestoreInterrupts(level);
      uVar1 = 0;
    }
    return uVar1;
  }
                    
  OSPanic("OSExi.c",0x2d7,s_Failed_assertion_0_<__chan_&&_ch_802d2b00);
}


/* Library Function - Single Match
    osExiFn_8000a958
   
   Library: KioskDefault 0 0 */

undefined4 EXISelect(int chan,uint dev,uint freq) { //8000A958
  BOOL_ level;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = chan * 0x38;
  if ((chan < 0) || (2 < chan)) {
                    
    OSPanic("OSExi.c",0x2ff,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
  }
  if (((chan != 0) || (2 < dev)) && (dev != 0)) {
                    
    OSPanic("OSExi.c",0x300,"Failed assertion chan == 0 && dev < MAX_DEV || dev == 0");
  }
  if (5 < freq) {
                    
    OSPanic("OSExi.c",0x301,s_Failed_assertion_freq_<_MAX_FREQ_802d2b60);
  }
  if ((*(uint *)((int)_osExiStates + iVar3) & 4) == 0) {
    level = OSDisableInterrupts();
    if (((*(uint *)((int)_osExiStates + iVar3) & 4) == 0) &&
       ((chan == 2 ||
        ((((dev != 0 || ((*(uint *)((int)_osExiStates + iVar3) & 8) != 0)) ||
          (iVar1 = __EXIProbe(chan), iVar1 != 0)) &&
         (((*(uint *)((int)_osExiStates + iVar3) & 0x10) != 0 &&
          (*(uint *)((int)_osExiStates + iVar3 + 0xc) == dev)))))))) {
      *(uint *)((int)_osExiStates + iVar3) = *(uint *)((int)_osExiStates + iVar3) | 4;
      (&EXI_CHANNEL0)[chan * 5] = (&EXI_CHANNEL0)[chan * 5] & 0x405 | (1 << dev) << 7 | freq << 4;
      if ((*(uint *)((int)_osExiStates + iVar3) & 8) != 0) {
        if (chan == 1) {
          __OSMaskInterrupts(0x20000);
        }
        else if ((chan < 1) && (-1 < chan)) {
          __OSMaskInterrupts(0x100000);
        }
      }
      OSRestoreInterrupts(level);
      uVar2 = 1;
    }
    else {
      OSRestoreInterrupts(level);
      uVar2 = 0;
    }
    return uVar2;
  }
                    
  OSPanic("OSExi.c",0x302,s_Failed_assertion___exi_>state___S_802d2b84);
}


/* Library Function - Single Match
    osExiFn_8000ab28
   
   Library: KioskDefault 0 0 */

undefined4 EXIDeselect(int chan) { //8000AB28
  BOOL_ level;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = chan * 0x38;
  if ((-1 < chan) && (chan < 3)) {
    level = OSDisableInterrupts();
    if ((*(uint *)((int)_osExiStates + iVar2) & 4) == 0) {
      OSRestoreInterrupts(level);
      uVar1 = 0;
    }
    else {
      *(uint *)((int)_osExiStates + iVar2) = *(uint *)((int)_osExiStates + iVar2) & 0xfffffffb;
      uVar3 = (&EXI_CHANNEL0)[chan * 5];
      (&EXI_CHANNEL0)[chan * 5] = uVar3 & 0x405;
      if ((*(uint *)((int)_osExiStates + iVar2) & 8) != 0) {
        if (chan == 1) {
          __OSUnmaskInterrupts(0x20000);
        }
        else if ((chan < 1) && (-1 < chan)) {
          __OSUnmaskInterrupts(0x100000);
        }
      }
      OSRestoreInterrupts(level);
      if ((chan == 0) && ((uVar3 & 0x80) != 0)) {
        iVar2 = __EXIProbe(0);
        if (iVar2 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    return uVar1;
  }
                    
  OSPanic("OSExi.c",0x335,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    exiInterrupt
   
   Library: KioskDefault 0 0 */

void irqHandler9(short param1,undefined4 param2) { //8000AC58
  int chan;
  
  chan = (param1 + -9) / 3;
  if ((-1 < chan) && (chan < 3)) {
    osExiFn_8000a43c(chan,1,0,0);
    if (*(code **)(&DAT_80325d60 + chan * 0x38) != (code *)0x0) {
      (**(code **)(&DAT_80325d60 + chan * 0x38))(chan,param2);
    }
    return;
  }
                    
  OSPanic("OSExi.c",0x368,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    exiInterrupt_8000ad00
   
   Library: KioskDefault 0 0 */

void irqHandler10(short param1,undefined4 param2) { //8000AD00
  code *pcVar1;
  int chan;
  
  chan = (param1 + -10) / 3;
  if ((-1 < chan) && (chan < 3)) {
    __OSMaskInterrupts(0x80000000 >> (int)param1);
    osExiFn_8000a43c(chan,0,1,0);
    pcVar1 = *(code **)(&DAT_80325d64 + chan * 0x38);
    if (pcVar1 != (code *)0x0) {
      *(undefined4 *)(&DAT_80325d64 + chan * 0x38) = 0;
      osExiFn_80009e34(chan);
      (*pcVar1)(chan,param2);
    }
    return;
  }
                    
  OSPanic("OSExi.c",899,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    exiInterrupt_8000adc8
   
   Library: KioskDefault 0 0 */

void irqHandler11(short param1,undefined4 param2) { //8000ADC8
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = (param1 + -0xb) / 3;
  if ((-1 < iVar3) && (iVar3 < 2)) {
    __OSMaskInterrupts(0x700000 >> iVar3 * 3);
    (&EXI_CHANNEL0)[iVar3 * 5] = 0;
    iVar1 = iVar3 * 0x38;
    pcVar2 = *(code **)(&DAT_80325d68 + iVar1);
    *(uint *)((int)_osExiStates + iVar1) = *(uint *)((int)_osExiStates + iVar1) & 0xfffffff7;
    if (pcVar2 != (code *)0x0) {
      *(undefined4 *)(&DAT_80325d68 + iVar1) = 0;
      (*pcVar2)(iVar3,param2);
    }
    return;
  }
                    
  OSPanic("OSExi.c",0x3a2,s_Failed_assertion_0_<__chan_&&_ch_802d2b00);
}


/* Library Function - Single Match
    osExiFn_8000af80
   
   Library: KioskDefault 0 0 */

undefined4 osExiFn_8000af80(int param1,uint param2,int param3) { //8000AF80
  BOOL_ level;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = param1 * 0x38;
  piVar4 = (int *)(&DAT_80325d60 + iVar2);
  if ((param1 < 0) || (2 < param1)) {
                    
    OSPanic("OSExi.c",0x3f2,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
  }
  if (((param1 != 0) || (2 < param2)) && (param2 != 0)) {
                    
    OSPanic("OSExi.c",0x3f3,"Failed assertion chan == 0 && dev < MAX_DEV || dev == 0");
  }
  level = OSDisableInterrupts();
  if ((*(uint *)((int)_osExiStates + iVar2) & 0x10) == 0) {
    if (*(int *)((int)_osExiStates + iVar2 + 0x10) != 0) {
                    
      OSPanic("OSExi.c",0x409,s_Failed_assertion_exi_>item"Failed assertion exi->items == 0");
    }
    *(uint *)((int)_osExiStates + iVar2) = *(uint *)((int)_osExiStates + iVar2) | 0x10;
    *(uint *)((int)_osExiStates + iVar2 + 0xc) = param2;
    SetExiInterruptMask(param1,piVar4);
    OSRestoreInterrupts(level);
    uVar1 = 1;
  }
  else {
    if (param3 != 0) {
      if (((param1 != 0) || (1 < *(int *)((int)_osExiStates + iVar2 + 0x10))) &&
         (*(int *)((int)_osExiStates + iVar2 + 0x10) != 0)) {
                    
        OSPanic("OSExi.c",0x3f9,"Failed assertion chan == 0 && exi->items < (MAX_DEV - 1)|| exi->items == 0");
      }
      for (iVar3 = 0; iVar3 < *(int *)((int)_osExiStates + iVar2 + 0x10); iVar3 = iVar3 + 1) {
        if (piVar4[iVar3 * 2 + 8] == param2) {
          OSRestoreInterrupts(level);
          return 0;
        }
      }
      piVar4[*(int *)((int)_osExiStates + iVar2 + 0x10) * 2 + 9] = param3;
      piVar4[*(int *)((int)_osExiStates + iVar2 + 0x10) * 2 + 8] = param2;
      *(int *)((int)_osExiStates + iVar2 + 0x10) = *(int *)((int)_osExiStates + iVar2 + 0x10) + 1;
    }
    OSRestoreInterrupts(level);
    uVar1 = 0;
  }
  return uVar1;
}


/* Library Function - Single Match
    osExiFn_8000b128
   
   Library: KioskDefault 0 0 */

undefined4 EXIUnlock(int param1) { //8000B128
  int iVar1;
  BOOL_ level;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = param1 * 0x38;
  if ((-1 < param1) && (param1 < 3)) {
    level = OSDisableInterrupts();
    if ((*(uint *)((int)_osExiStates + iVar3) & 0x10) == 0) {
      OSRestoreInterrupts(level);
      uVar2 = 0;
    }
    else {
      *(uint *)((int)_osExiStates + iVar3) = *(uint *)((int)_osExiStates + iVar3) & 0xffffffef;
      SetExiInterruptMask(param1,(int *)(&DAT_80325d60 + iVar3));
      if (0 < *(int *)((int)_osExiStates + iVar3 + 0x10)) {
        pcVar4 = *(code **)((int)_osExiStates + iVar3 + 0x18);
        iVar1 = *(int *)((int)_osExiStates + iVar3 + 0x10) + -1;
        *(int *)((int)_osExiStates + iVar3 + 0x10) = iVar1;
        if (0 < iVar1) {
          memmove(iVar3 + 0x80325d80,iVar3 + 0x80325d88,
                  *(int *)((int)_osExiStates + iVar3 + 0x10) << 3);
        }
        (*pcVar4)(param1,0);
      }
      OSRestoreInterrupts(level);
      uVar2 = 1;
    }
    return uVar2;
  }
                    
  OSPanic("OSExi.c",0x421,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}


/* Library Function - Single Match
    osExiFn_8000b218
   
   Library: KioskDefault 0 0 */

undefined4 osExiFn_8000b218(int param1) { //8000B218
  if ((-1 < param1) && (param1 < 3)) {
    return *(undefined4 *)((int)_osExiStates + param1 * 0x38);
  }
                    
  OSPanic("OSExi.c",0x446,s_Failed_assertion_0_<__chan_&&_ch_802d2950);
}

