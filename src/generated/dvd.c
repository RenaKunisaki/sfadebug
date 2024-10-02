
void dvdRadFst(void) { //80011E40
  PTR_stateBusy_80398334 = dvdRadFst;
  if (((uint)osBootInfo->FSTLocation & 0x1f) != 0) {
                    
    OSPanic("dvd.c",0x219,"Failed assertion ((u32)(bootInfo->FSTLocation) & (32 - 1)) == 0");
  }
  DVDLowRead((uint)osBootInfo->FSTLocation,DAT_80326988 + 0x1fU & 0xffffffe0,DAT_80326984,
             dvdCb_80011ec4);
  return;
}


/* Library Function - Single Match
    dvdReadCb_80011ec4
   
   Library: KioskDefault 0 0 */

void dvdCb_80011ec4(uint param1) { //80011EC4
  undefined *puVar1;
  
  puVar1 = DAT_803982f0;
  if ((param1 & 4) != 0) {
                    
    OSPanic("dvd.c",0x229,"Failed assertion (intType & DVD_INTTYPE_CVR) == 0");
  }
  if ((param1 & 1) == 0) {
    if (param1 != 2) {
                    
      OSPanic("dvd.c",0x246,"Failed assertion intType == DVD_INTTYPE_DE");
    }
    FUN_80011ff0();
  }
  else {
    if ((param1 & 2) != 0) {
                    
      OSPanic("dvd.c",0x22e,"Failed assertion (intType & DVD_INTTYPE_DE) == 0");
    }
    DAT_80398324 = 0;
    DAT_803982f0 = &DAT_80326a00;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    if (*(int *)(puVar1 + 0x28) != 0) {
      (**(code **)(puVar1 + 0x28))(0,puVar1);
    }
    FUN_80012c04();
  }
  return;
}


/* Library Function - Single Match
    dvdFn_800120ac
   
   Library: KioskDefault 0 0 */

void dvdCb_800120ac(uint param1) { //800120AC
  uint uVar1;
  dword dVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  if ((param1 & 2) == 0) {
    if (param1 != 1) {
                    
      OSPanic("dvd.c",0x30f,"Failed assertion intType == DVD_INTTYPE_TC");
    }
    dVar2 = dvd_DIIMMBUF;
    iVar4 = CategorizeError(dVar2);
    puVar3 = DAT_803982f0;
    if (iVar4 == 1) {
      if (DAT_8039830c == 0) {
        *(undefined4 *)(DAT_803982f0 + 0xc) = 0xffffffff;
        FUN_80011f9c();
      }
      else {
        DAT_80398318 = 5;
        DAT_8039830c = 0;
        DAT_803982f0 = &DAT_80326a00;
        DAT_8039831c = dVar2;
        if (*(int *)(puVar3 + 0xc) == 1) {
          *(undefined4 *)(puVar3 + 0xc) = 10;
          if (*(int *)(puVar3 + 0x28) != 0) {
            (**(code **)(puVar3 + 0x28))(0xfffffffa,puVar3);
          }
          if (DAT_80398314 != (code *)0x0) {
            (*DAT_80398314)(0,puVar3);
          }
        }
        FUN_80012c04();
      }
    }
    else if (iVar4 == 2) {
      FUN_800124c4();
    }
    else if (iVar4 == 3) {
      if (DAT_8039830c == 0) {
                    /* {@symbol 80012d48} */
        (*(code *)PTR_stateBusy_80398334)(DAT_803982f0);
      }
      else {
        DAT_80398318 = 0;
        DAT_8039830c = 0;
        DAT_803982f0 = &DAT_80326a00;
        if (*(int *)(puVar3 + 0xc) == 1) {
          *(undefined4 *)(puVar3 + 0xc) = 10;
          if (*(int *)(puVar3 + 0x28) != 0) {
            (**(code **)(puVar3 + 0x28))(0xfffffffa,puVar3);
          }
          if (DAT_80398314 != (code *)0x0) {
            (*DAT_80398314)(0,puVar3);
          }
        }
        FUN_80012c04();
      }
    }
    else {
      uVar1 = dVar2 & 0xff000000;
      if (uVar1 == 0x1000000) {
        *(undefined4 *)(DAT_803982f0 + 0xc) = 5;
      }
      else if (uVar1 == 0x2000000) {
        *(undefined4 *)(DAT_803982f0 + 0xc) = 3;
      }
      else {
        if (uVar1 != 0x3000000) {
                    
          OSPanic("dvd.c",0x37b,"Failed assertion FALSE");
        }
        *(undefined4 *)(DAT_803982f0 + 0xc) = 4;
      }
      puVar3 = DAT_803982f0;
      if ((((DAT_80398308 == 6) || (DAT_80398308 == 7)) || (DAT_80398308 == 8)) ||
         (((DAT_80398308 == 9 || (DAT_80398308 == 10)) ||
          ((DAT_80398308 == 0xb || (DAT_80398308 == 0xc)))))) {
        if (uVar1 == 0x1000000) {
          uVar5 = 0xfffffffd;
        }
        else {
          if (uVar1 != 0x2000000) {
                    
            OSPanic("dvd.c",0x389,"Failed assertion FALSE");
          }
          uVar5 = 0xfffffffe;
        }
        DAT_803982f0 = &DAT_80326a00;
        if (*(int *)(puVar3 + 0x28) != 0) {
          (**(code **)(puVar3 + 0x28))(uVar5,puVar3);
        }
        FUN_80012c04();
      }
      else if (DAT_8039830c == 0) {
        if (uVar1 == 0x1000000) {
          FUN_80012b7c();
        }
        else if (uVar1 == 0x2000000) {
          stateCoverClosed();
        }
        else if (uVar1 == 0x3000000) {
          FUN_80012b7c();
        }
      }
      else {
        if (uVar1 == 0x1000000) {
          DAT_80398318 = 4;
        }
        else if (uVar1 == 0x2000000) {
          DAT_80398318 = 6;
        }
        else if (uVar1 == 0x3000000) {
          DAT_80398318 = 3;
        }
        DAT_803982f0 = &DAT_80326a00;
        if (*(int *)(puVar3 + 0xc) == 1) {
          *(undefined4 *)(puVar3 + 0xc) = 10;
          if (*(int *)(puVar3 + 0x28) != 0) {
            (**(code **)(puVar3 + 0x28))(0xfffffffa,puVar3);
          }
          if (DAT_80398314 != (code *)0x0) {
            (*DAT_80398314)(0,puVar3);
          }
        }
        DAT_8039830c = 0;
        FUN_80012c04();
      }
    }
  }
  else {
    *(undefined4 *)(DAT_803982f0 + 0xc) = 0xffffffff;
    FUN_80011f9c();
  }
  return;
}


/* Library Function - Single Match
    dvdCb_800124ec
   
   Library: KioskDefault 0 0 */

void dvdCb_800124ec(uint param1) { //800124EC
  undefined *puVar1;
  
  puVar1 = DAT_803982f0;
  if ((param1 & 2) == 0) {
    if (param1 != 1) {
                    
      OSPanic("dvd.c",0x3d9,"Failed assertion intType == DVD_INTTYPE_TC");
    }
    DAT_80398324 = 0;
    if ((((DAT_80398308 == 4) || (DAT_80398308 == 5)) || (DAT_80398308 == 0xd)) ||
       (DAT_80398308 == 0xf)) {
      DAT_80398328 = 1;
    }
    if (DAT_8039830c == 0) {
      *(undefined4 *)(DAT_803982f0 + 0xc) = 0xb;
      FUN_80012b7c();
    }
    else {
      DAT_80398318 = 2;
      DAT_8039830c = 0;
      DAT_803982f0 = &DAT_80326a00;
      if (*(int *)(puVar1 + 0xc) == 1) {
        *(undefined4 *)(puVar1 + 0xc) = 10;
        if (*(int *)(puVar1 + 0x28) != 0) {
          (**(code **)(puVar1 + 0x28))(0xfffffffa,puVar1);
        }
        if (DAT_80398314 != (code *)0x0) {
          (*DAT_80398314)(0,puVar1);
        }
      }
      FUN_80012c04();
    }
  }
  else {
    *(undefined4 *)(DAT_803982f0 + 0xc) = 0xffffffff;
    FUN_80011f9c();
  }
  return;
}


/* Library Function - Single Match
    dvdFn_8001262c
   
   Library: KioskDefault 0 0 */

void dvdFn_8001262c(void) { //8001262C
  int iVar1;
  
  if (DAT_80398308 == 3) {
    iVar1 = memcmp(&DAT_80326980,*(void **)(DAT_803982f0 + 0x24),0x1c);
    if (iVar1 == 0) {
      memcpy(PTR_gameCode_803982f4,&DAT_80326980,0x20);
      *(undefined4 *)(DAT_803982f0 + 0xc) = 1;
      DCInvalidateRange(&DAT_80326980,0x20);
      PTR_stateBusy_80398334 = FUN_8001276c;
      FUN_8001276c();
    }
    else {
      FUN_80010d30(dvdCb_800127a4);
    }
  }
  else {
    if ((2 < DAT_80398308) || (DAT_80398308 < 1)) {
                    
      OSPanic("dvd.c",0x452,"Failed assertion FALSE");
    }
    iVar1 = memcmp(&DAT_80326980,PTR_gameCode_803982f4,0x20);
    if (iVar1 == 0) {
      PTR_stateBusy_80398334 = FUN_80012738;
      FUN_80012738();
    }
    else {
      FUN_80010d30(dvdCb_800127a4);
    }
  }
  return;
}


/* Library Function - Single Match
    dvdFn_800127a4
   
   Library: KioskDefault 0 0 */

void dvdCb_800127a4(uint param1) { //800127A4
  if ((param1 & 2) == 0) {
    if (param1 != 1) {
                    
      OSPanic("dvd.c",0x478,"Failed assertion intType == DVD_INTTYPE_TC");
    }
    DAT_80398324 = 0;
    if (DAT_8039830c == 0) {
      *(undefined4 *)(DAT_803982f0 + 0xc) = 6;
      FUN_80012b7c();
    }
    else {
      DAT_80398318 = 1;
      DAT_8039830c = 0;
      FUN_80012c04();
    }
  }
  else {
    *(undefined4 *)(DAT_803982f0 + 0xc) = 0xffffffff;
    FUN_80011f9c();
  }
  return;
}


/* Library Function - Single Match
    dvdCb_80012848
   
   Library: KioskDefault 0 0 */

void dvdCb_80012848(uint param1) { //80012848
  if ((param1 & 4) != 0) {
                    
    OSPanic("dvd.c",0x494,"Failed assertion (intType & DVD_INTTYPE_CVR) == 0");
  }
  if ((param1 & 1) == 0) {
    if (param1 != 2) {
                    
      OSPanic("dvd.c",0x4aa,"Failed assertion intType == DVD_INTTYPE_DE");
    }
    FUN_80011ff0();
  }
  else {
    if ((param1 & 2) != 0) {
                    
      OSPanic("dvd.c",0x499,"Failed assertion (intType & DVD_INTTYPE_DE) == 0");
    }
    DAT_80398324 = 0;
    dvdRadFst();
  }
  return;
}


/* Library Function - Single Match
    dvdCb_800128e8
   
   Library: KioskDefault 0 0 */

void dvdCb_800128e8(uint param1) { //800128E8
  if ((param1 & 4) != 0) {
                    
    OSPanic("dvd.c",0x4b4,"Failed assertion (intType & DVD_INTTYPE_CVR) == 0");
  }
  if ((param1 & 1) == 0) {
    if (param1 != 2) {
                    
      OSPanic("dvd.c",0x4cd,"Failed assertion intType == DVD_INTTYPE_DE");
    }
    FUN_80011ff0();
  }
  else {
    if ((param1 & 2) != 0) {
                    
      OSPanic("dvd.c",0x4b9,"Failed assertion (intType & DVD_INTTYPE_DE) == 0");
    }
    DAT_80398324 = 0;
    if (DAT_8039830c == 0) {
      *(undefined4 *)(DAT_803982f0 + 0xc) = 1;
      stateBusy(DAT_803982f0);
    }
    else {
      DAT_80398318 = 0;
      DAT_8039830c = 0;
      FUN_80012c04();
    }
  }
  return;
}


/* Library Function - Single Match
    dvdCmdFn_80012aa4
   
   Library: KioskDefault 0 0 */

void dvdCb_80012aa4(uint param1) { //80012AA4
  if ((param1 & 4) != 0) {
                    
    OSPanic("dvd.c",0x510,"Failed assertion (intType & DVD_INTTYPE_CVR) == 0");
  }
  if ((param1 & 1) == 0) {
    if (param1 != 2) {
                    
      OSPanic("dvd.c",0x523,"Failed assertion intType == DVD_INTTYPE_DE");
    }
    FUN_80011ff0();
  }
  else {
    if ((param1 & 2) != 0) {
                    
      OSPanic("dvd.c",0x515,"Failed assertion (intType & DVD_INTTYPE_DE) == 0");
    }
    if (((DAT_80398308 != 1) && (DAT_80398308 != 2)) && (DAT_80398308 != 3)) {
                    
      OSPanic("dvd.c",0x519,"Failed assertion (CurrCommand == DVD_COMMAND_READ) || (CurrCommand == DVD_COMMAND_SEEK) || (CurrCommand == DVD_COMMAND_CHANGE_DISK)");
    }
    DAT_80398324 = 0;
    dvdFn_8001262c();
  }
  return;
}


/* Library Function - Single Match
    cbStateForMotorStopped
   
   Library: KioskDefault 0 0 */

void dvdCb_80012ba4(int param1) { //80012BA4
  if (param1 != 4) {
                    
    OSPanic("dvd.c",0x540,"Failed assertion intType == DVD_INTTYPE_CVR");
  }
  dvd_DICVR = 0;
  *(undefined4 *)(DAT_803982f0 + 0xc) = 3;
  stateCoverClosed();
  return;
}


/* Library Function - Single Match
    dvdCb_80013020
   
   Library: KioskDefault 0 0 */

void dvdCb_80013020(uint param1) { //80013020
  undefined *puVar1;
  dword dVar2;
  
  puVar1 = DAT_803982f0;
  if ((DAT_80398308 == 3) || (DAT_80398308 == 0xf)) {
    if ((param1 & 2) == 0) {
      if (param1 != 1) {
                    
        OSPanic("dvd.c",0x64b,"Failed assertion intType == DVD_INTTYPE_TC");
      }
      DAT_80398324 = 0;
      if (DAT_80398308 == 0xf) {
        DAT_80398328 = 1;
      }
      if (DAT_8039830c == 0) {
        *(undefined4 *)(DAT_803982f0 + 0xc) = 7;
        FUN_80012b7c();
      }
      else {
        DAT_8039830c = 0;
        DAT_80398318 = 7;
        DAT_803982f0 = &DAT_80326a00;
        *(undefined4 *)(puVar1 + 0xc) = 10;
        if (*(int *)(puVar1 + 0x28) != 0) {
          (**(code **)(puVar1 + 0x28))(0xfffffffa,puVar1);
        }
        if (DAT_80398314 != (code *)0x0) {
          (*DAT_80398314)(0,puVar1);
        }
        FUN_80012c04();
      }
    }
    else {
      *(undefined4 *)(DAT_803982f0 + 0xc) = 0xffffffff;
      FUN_80011f9c();
    }
    return;
  }
  if ((param1 & 4) != 0) {
                    
    OSPanic("dvd.c",0x671,"Failed assertion (intType & DVD_INTTYPE_CVR) == 0");
  }
  if ((((DAT_80398308 == 1) || (DAT_80398308 == 4)) || (DAT_80398308 == 5)) || (DAT_80398308 == 0xe)
     ) {
    dVar2 = dvd_DILENGTH;
    *(dword *)(DAT_803982f0 + 0x20) =
         *(int *)(DAT_803982f0 + 0x20) + (*(int *)(DAT_803982f0 + 0x1c) - dVar2);
  }
  puVar1 = DAT_803982f0;
  if ((param1 & 8) != 0) {
    DAT_8039830c = 0;
    DAT_803982f0 = &DAT_80326a00;
    *(undefined4 *)(puVar1 + 0xc) = 10;
    if (*(int *)(puVar1 + 0x28) != 0) {
      (**(code **)(puVar1 + 0x28))(0xfffffffa,puVar1);
    }
    if (DAT_80398314 != (code *)0x0) {
      (*DAT_80398314)(0,puVar1);
    }
    FUN_80012c04();
    return;
  }
  if ((param1 & 1) == 0) {
    if (param1 == 2) {
      FUN_80011ff0();
      return;
    }
                    
    OSPanic("dvd.c",0x728,"Failed assertion intType == DVD_INTTYPE_DE");
  }
  if ((param1 & 2) != 0) {
                    
    OSPanic("dvd.c",0x697,"Failed assertion (intType & DVD_INTTYPE_DE) == 0");
  }
  DAT_80398324 = 0;
  if (DAT_8039830c != 0) {
    DAT_8039830c = 0;
    DAT_803982f0 = &DAT_80326a00;
    *(undefined4 *)(puVar1 + 0xc) = 10;
    if (*(int *)(puVar1 + 0x28) != 0) {
      (**(code **)(puVar1 + 0x28))(0xfffffffa,puVar1);
    }
    if (DAT_80398314 != (code *)0x0) {
      (*DAT_80398314)(0,puVar1);
    }
    FUN_80012c04();
    return;
  }
  if (((DAT_80398308 != 1) && (DAT_80398308 != 4)) && ((DAT_80398308 != 5 && (DAT_80398308 != 0xe)))
     ) {
    if (((DAT_80398308 == 9) || (DAT_80398308 == 10)) ||
       ((DAT_80398308 == 0xb || (DAT_80398308 == 0xc)))) {
      if ((DAT_80398308 == 0xb) || (DAT_80398308 == 10)) {
        dVar2 = dvd_DIIMMBUF;
        dVar2 = dVar2 << 2;
      }
      else {
        dVar2 = dvd_DIIMMBUF;
      }
      DAT_803982f0 = &DAT_80326a00;
      *(undefined4 *)(puVar1 + 0xc) = 0;
      if (*(int *)(puVar1 + 0x28) != 0) {
        (**(code **)(puVar1 + 0x28))(dVar2,puVar1);
      }
      FUN_80012c04();
      return;
    }
    if (DAT_80398308 != 6) {
      DAT_803982f0 = &DAT_80326a00;
      *(undefined4 *)(puVar1 + 0xc) = 0;
      if (*(int *)(puVar1 + 0x28) != 0) {
        (**(code **)(puVar1 + 0x28))(0,puVar1);
      }
      FUN_80012c04();
      return;
    }
    if (*(int *)(DAT_803982f0 + 0x1c) == 0) {
      dVar2 = dvd_DIIMMBUF;
      if ((dVar2 & 1) != 0) {
        DAT_803982f0 = &DAT_80326a00;
        *(undefined4 *)(puVar1 + 0xc) = 9;
        if (*(int *)(puVar1 + 0x28) != 0) {
          (**(code **)(puVar1 + 0x28))(0xfffffffb,puVar1);
        }
        FUN_80012c04();
        return;
      }
      DAT_80398304 = 0;
      *(undefined4 *)(DAT_803982f0 + 0x1c) = 1;
      FUN_80010dbc(0,*(dword *)(DAT_803982f0 + 0x14),*(uint *)(DAT_803982f0 + 0x10),dvdCb_80013020);
      return;
    }
    DAT_803982f0 = &DAT_80326a00;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    if (*(int *)(puVar1 + 0x28) != 0) {
      (**(code **)(puVar1 + 0x28))(0,puVar1);
    }
    FUN_80012c04();
    return;
  }
  if (*(int *)(DAT_803982f0 + 0x20) != *(int *)(DAT_803982f0 + 0x14)) {
    stateBusy((int)DAT_803982f0);
    return;
  }
  DAT_803982f0 = &DAT_80326a00;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  if (*(int *)(puVar1 + 0x28) != 0) {
    (**(code **)(puVar1 + 0x28))(*(undefined4 *)(puVar1 + 0x20),puVar1);
  }
  FUN_80012c04();
  return;
}


/* Library Function - Single Match
    _dvdReadFn_80013530
   
   Library: KioskDefault 0 0 */

BOOL _dvdReadFn_80013530(int param1,undefined **param2) { //80013530
  BOOL_ level;
  int iVar1;
  BOOL BVar2;
  
  if ((DAT_80396800 != 0) &&
     ((((param2[2] == &DAT_00000001 || (param2[2] == &DAT_00000004)) || (param2[2] == &DAT_00000005)
       ) || (param2[2] == &DAT_0000000e)))) {
    DCInvalidateRange(param2[6],(int)param2[5]);
  }
  level = OSDisableInterrupts();
  if ((DAT_803982f0 != param2) &&
     ((param2[3] != &DAT_00000002 ||
      (iVar1 = __DVDIsBlockInWaitingQueue((DVDCommandBlock *)param2), iVar1 == 0)))) {
    param2[3] = &DAT_00000002;
    BVar2 = __DVDPushWaitingQueue(param1,(DVDCommandBlock *)param2);
    if ((DAT_803982f0 == (undefined **)0x0) && (DAT_803982fc == 0)) {
      FUN_80012c04();
    }
    OSRestoreInterrupts(level);
    return BVar2;
  }
                    
  OSPanic("dvd.c",0x758,"DVD library: Specified command block (or file info) is already in use");
}


/* Library Function - Single Match
    DVDReadAbsAsync
   
   Library: KioskDefault 0 0 */

int DVDReadAbsAsync(undefined **param1,undefined *param2,undefined *param3,undefined *param4,
                   undefined *param5,int param6) { //80013630
  int iVar1;
  
  if (param1 == (undefined **)0x0) {
                    
    OSPanic("dvd.c",0x780,"DVDReadAbsAsync(): null pointer is specified to command block address.");
  }
  if (param2 == (undefined *)0x0) {
                    
    OSPanic("dvd.c",0x781,"DVDReadAbsAsync(): null pointer is specified to addr.");
  }
  if (((uint)param2 & 0x1f) != 0) {
                    
    OSPanic("dvd.c",0x783,"DVDReadAbsAsync(): address must be aligned with 32 byte boundary.");
  }
  if (((uint)param3 & 0x1f) != 0) {
                    
    OSPanic("dvd.c",0x785,"DVDReadAbsAsync(): length must be a multiple of 32.");
  }
  if (((uint)param4 & 3) != 0) {
                    
    OSPanic("dvd.c",0x787,"DVDReadAbsAsync(): offset must be a multiple of 4.");
  }
  if ((int)param3 < 1) {
                    
    OSPanic("dvd.c",0x789,"DVD read: 0 or negative value was specified to length of the read");
  }
  param1[2] = &DAT_00000001;
  param1[6] = param2;
  param1[5] = param3;
  param1[4] = param4;
  param1[8] = (undefined *)0x0;
  param1[10] = param5;
  iVar1 = _dvdReadFn_80013530(param6,param1);
  if (iVar1 == 0) {
                    
    OSPanic("dvd.c",0x793,"DVDReadAbsAsync(): command block is used for processing previous request.");
  }
  return iVar1;
}


/* Library Function - Single Match
    DVDReadAbsAsyncForBS
   
   Library: KioskDefault 0 0 */

int DVDReadAbsAsyncForBS
              (undefined **param1,undefined *param2,undefined *param3,undefined *param4,
              undefined *param5) { //80013770
  int iVar1;
  
  if (param1 == (undefined **)0x0) {
                    
    OSPanic("dvd.c",0x7d1,"DVDReadAbsAsyncForBS(): null pointer is specified to command block address.");
  }
  if (param2 == (undefined *)0x0) {
                    
    OSPanic("dvd.c",0x7d2,"DVDReadAbsAsyncForBS(): null pointer is specified to addr.");
  }
  if (((uint)param2 & 0x1f) != 0) {
                    
    OSPanic("dvd.c",0x7d4,"DVDReadAbsAsyncForBS(): address must be aligned with 32 byte boundary.");
  }
  if (((uint)param3 & 0x1f) != 0) {
                    
    OSPanic("dvd.c",0x7d6,"DVDReadAbsAsyncForBS(): length must be a multiple of 32.");
  }
  if (((uint)param4 & 3) != 0) {
                    
    OSPanic("dvd.c",0x7d8,"DVDReadAbsAsyncForBS(): offset must be a multiple of 4.");
  }
  param1[2] = &DAT_00000004;
  param1[6] = param2;
  param1[5] = param3;
  param1[4] = param4;
  param1[8] = (undefined *)0x0;
  param1[10] = param5;
  iVar1 = _dvdReadFn_80013530(2,param1);
  if (iVar1 == 0) {
                    
    OSPanic("dvd.c",0x7e2,"DVDReadAbsAsyncForBS(): command block is used for processing previous request.");
  }
  return iVar1;
}


/* Library Function - Single Match
    DVDReadDiskID
   
   Library: KioskDefault 0 0 */

int DVDReadDiskID(undefined **param1,undefined *param2,undefined *param3) { //80013890
  int iVar1;
  
  if (param1 == (undefined **)0x0) {
                    
    OSPanic("dvd.c",0x7f9,"DVDReadDiskID(): null pointer is specified to command block address.");
  }
  if (param2 == (undefined *)0x0) {
                    
    OSPanic("dvd.c",0x7fa,"DVDReadDiskID(): null pointer is specified to id address.");
  }
  if (((uint)param2 & 0x1f) != 0) {
                    
    OSPanic("dvd.c",0x7fc,"DVDReadDiskID(): id must be aligned with 32 byte boundary.");
  }
  param1[2] = &DAT_00000005;
  param1[6] = param2;
  param1[5] = (undefined *)0x20;
  param1[4] = (undefined *)0x0;
  param1[8] = (undefined *)0x0;
  param1[10] = param3;
  iVar1 = _dvdReadFn_80013530(2,param1);
  if (iVar1 == 0) {
                    
    OSPanic("dvd.c",0x806,"DVDReadDiskID(): command block is used for processing previous request.");
  }
  return iVar1;
}


/* Library Function - Single Match
    dvdFn_80013b98
   
   Library: KioskDefault 0 0 */

undefined4 dvdFn_80013b98(int *param1,undefined *param2) { //80013B98
  BOOL_ level;
  code *pcVar1;
  
  level = OSDisableInterrupts();
  DAT_8039830c = 0;
  DAT_80398314 = (undefined *)0x0;
  if (true) {
                    /* {@symbol 80013bf0} */
    switch(param1[3]) {
    case 1:
      if (false) {
        OSRestoreInterrupts(level);
        return 0;
      }
      DAT_8039830c = 1;
      DAT_80398314 = param2;
      if ((param1[2] == 4) || (DAT_80398310 = param1, param1[2] == 1)) {
        DAT_80398310 = param1;
        FUN_80010f94();
      }
      break;
    case 2:
      __DVDDequeueWaitingQueue((DVDCommandBlock *)param1);
      param1[3] = 10;
      if (param1[10] != 0) {
        (*(code *)param1[10])(0xfffffffa,param1);
      }
      if (param2 != (undefined *)0x0) {
        (*(code *)param2)(0,param1);
      }
      break;
    case 3:
      if (true) {
                    /* {@symbol 80013e54} */
        switch(param1[2]) {
        case 1:
          if (false) {
            OSRestoreInterrupts(level);
            return 0;
          }
          DAT_8039830c = 1;
          DAT_80398310 = param1;
          param1[3] = 10;
          if (param1[10] != 0) {
            (*(code *)param1[10])(0xfffffffa,param1);
          }
          if (param2 != (undefined *)0x0) {
            (*(code *)param2)(0,param1);
          }
          break;
        case 4:
        case 5:
        case 0xd:
        case 0xf:
          if (param2 != (undefined *)0x0) {
            (*(code *)param2)(0,param1);
          }
        }
      }
      break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 0xb:
      pcVar1 = (code *)FUN_80010fc8();
      if (pcVar1 != dvdCb_80012ba4) {
                    
        OSPanic("dvd.c",0xbdb,"Failed assertion old == cbForStateMotorStopped");
      }
      if (false) {
        return 0;
      }
      if (param1[3] == 4) {
        DAT_80398318 = 3;
      }
      if (param1[3] == 5) {
        DAT_80398318 = 4;
      }
      if (param1[3] == 6) {
        DAT_80398318 = 1;
      }
      if (param1[3] == 0xb) {
        DAT_80398318 = 2;
      }
      if (param1[3] == 7) {
        DAT_80398318 = 7;
      }
      param1[3] = 10;
      if (param1[10] != 0) {
        (*(code *)param1[10])(0xfffffffa,param1);
      }
      if (param2 != (undefined *)0x0) {
        (*(code *)param2)(0,param1);
      }
      FUN_80012c04();
      break;
    case -1:
    case 0:
    case 10:
      if (param2 != (undefined *)0x0) {
        (*(code *)param2)(0,param1);
      }
    }
  }
  OSRestoreInterrupts(level);
  return 1;
}

