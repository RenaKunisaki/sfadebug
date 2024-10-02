
/* Library Function - Single Match
    __DSPHandler
   
   Library: KioskDefault 0 0 */

void __DSPHandler(undefined4 param_1,OSContext *param2) { //8001A5C8
  ushort uVar2;
  int iVar1;
  OSContext OStack_2e0;
  
  uVar2 = dsp_CSR;
  dsp_CSR = uVar2 & 0xffd7 | 0x80;
  OSClearContext(&OStack_2e0);
  OSSetCurrentContext(&OStack_2e0);
  if (PTR_DAT_80398450 == (undefined *)0x0) {
                    
    OSPanic("dsp_task.c",0x8a,"__DSPHandler(): No current task! Someone set us up the bomb!");
  }
  do {
    uVar2 = dspGetCpuMailHi();
  } while (uVar2 == 0);
  iVar1 = FUN_8001a3f4();
  if (((*(uint *)(PTR_DAT_80398450 + 8) & 2) != 0) && (iVar1 == -0x232efffe)) {
    iVar1 = -0x232efffd;
  }
  if (iVar1 == -0x232efffe) {
    if (DAT_80398460 == 0) {
      if (*(int *)(PTR_DAT_80398450 + 0x38) == 0) {
        if (PTR_DAT_80398450 == PTR_DAT_80398458) {
          dspSendMail(0xcdd10003);
          do {
            uVar2 = dspGetMailHi();
          } while (uVar2 != 0);
          if (*(int *)(PTR_DAT_80398450 + 0x2c) != 0) {
                    /* {@symbol 80058f3c} */
            (**(code **)(PTR_DAT_80398450 + 0x2c))(PTR_DAT_80398450);
          }
        }
        else {
          dspSendMail(0xcdd10001);
          do {
            uVar2 = dspGetMailHi();
          } while (uVar2 != 0);
          __DSP_exec_task((int)PTR_DAT_80398450,(int *)PTR_DAT_80398458);
          *(undefined4 *)PTR_DAT_80398450 = 2;
          PTR_DAT_80398450 = PTR_DAT_80398458;
        }
      }
      else {
        dspSendMail(0xcdd10001);
        do {
          uVar2 = dspGetMailHi();
        } while (uVar2 != 0);
        __DSP_exec_task((int)PTR_DAT_80398450,*(int **)(PTR_DAT_80398450 + 0x38));
        *(undefined4 *)PTR_DAT_80398450 = 2;
        PTR_DAT_80398450 = *(undefined **)(PTR_DAT_80398450 + 0x38);
      }
    }
    else if ((int *)PTR_DAT_80398450 == DAT_80398464) {
      dspSendMail(0xcdd10003);
      do {
        uVar2 = dspGetMailHi();
      } while (uVar2 != 0);
      DAT_80398464 = (int *)0x0;
      DAT_80398460 = 0;
      if (*(int *)(PTR_DAT_80398450 + 0x2c) != 0) {
                    /* {@symbol 80058f3c} */
        (**(code **)(PTR_DAT_80398450 + 0x2c))(PTR_DAT_80398450);
      }
    }
    else {
      dspSendMail(0xcdd10001);
      do {
        uVar2 = dspGetMailHi();
      } while (uVar2 != 0);
      __DSP_exec_task((int)PTR_DAT_80398450,DAT_80398464);
      *(undefined4 *)PTR_DAT_80398450 = 2;
      PTR_DAT_80398450 = (undefined *)DAT_80398464;
      DAT_80398464 = (int *)0x0;
      DAT_80398460 = 0;
    }
  }
  else if (iVar1 < -0x232efffe) {
    if (iVar1 == -0x232f0000) {
      *(undefined4 *)PTR_DAT_80398450 = 1;
      if (*(int *)(PTR_DAT_80398450 + 0x28) != 0) {
                    /* {@symbol 80058f28} */
        (**(code **)(PTR_DAT_80398450 + 0x28))(PTR_DAT_80398450);
      }
    }
    else {
      if (iVar1 < -0x232f0000) {
LAB_8001aa98:
                    
        OSPanic("dsp_task.c",0x202,"__DSPHandler(): Unknown msg from DSP 0x%08X - task sync failed!",iVar1);
      }
      *(undefined4 *)PTR_DAT_80398450 = 1;
      if (*(int *)(PTR_DAT_80398450 + 0x2c) != 0) {
                    /* {@symbol 80058f3c} */
        (**(code **)(PTR_DAT_80398450 + 0x2c))(PTR_DAT_80398450);
      }
    }
  }
  else if (iVar1 == -0x232efffc) {
    if (*(int *)(PTR_DAT_80398450 + 0x34) != 0) {
      (**(code **)(PTR_DAT_80398450 + 0x34))(PTR_DAT_80398450);
    }
  }
  else {
    if (-0x232efffd < iVar1) goto LAB_8001aa98;
    if (DAT_80398460 == 0) {
      if (*(int *)(PTR_DAT_80398450 + 0x38) == 0) {
        if (PTR_DAT_80398450 == PTR_DAT_80398458) {
          if (*(int *)(PTR_DAT_80398450 + 0x30) != 0) {
            (**(code **)(PTR_DAT_80398450 + 0x30))(PTR_DAT_80398450);
          }
          dspSendMail(0xcdd10002);
          do {
            uVar2 = dspGetMailHi();
          } while (uVar2 != 0);
          *(undefined4 *)PTR_DAT_80398450 = 3;
          __DSP_remove_task((undefined4 *)PTR_DAT_80398450);
        }
        else {
          if (*(int *)(PTR_DAT_80398450 + 0x30) != 0) {
            (**(code **)(PTR_DAT_80398450 + 0x30))(PTR_DAT_80398450);
          }
          dspSendMail(0xcdd10001);
          do {
            uVar2 = dspGetMailHi();
          } while (uVar2 != 0);
          *(undefined4 *)PTR_DAT_80398450 = 3;
          __DSP_exec_task(0,(int *)PTR_DAT_80398458);
          PTR_DAT_80398450 = PTR_DAT_80398458;
          __DSP_remove_task((undefined4 *)PTR_DAT_80398454);
        }
      }
      else {
        if (*(int *)(PTR_DAT_80398450 + 0x30) != 0) {
          (**(code **)(PTR_DAT_80398450 + 0x30))(PTR_DAT_80398450);
        }
        dspSendMail(0xcdd10001);
        do {
          uVar2 = dspGetMailHi();
        } while (uVar2 != 0);
        *(undefined4 *)PTR_DAT_80398450 = 3;
        __DSP_exec_task(0,*(int **)(PTR_DAT_80398450 + 0x38));
        PTR_DAT_80398450 = *(undefined **)(PTR_DAT_80398450 + 0x38);
        __DSP_remove_task(*(undefined4 **)(PTR_DAT_80398450 + 0x3c));
      }
    }
    else {
      if (*(int *)(PTR_DAT_80398450 + 0x30) != 0) {
        (**(code **)(PTR_DAT_80398450 + 0x30))(PTR_DAT_80398450);
      }
      dspSendMail(0xcdd10001);
      do {
        uVar2 = dspGetMailHi();
      } while (uVar2 != 0);
      __DSP_exec_task(0,DAT_80398464);
      __DSP_remove_task((undefined4 *)PTR_DAT_80398450);
      PTR_DAT_80398450 = (undefined *)DAT_80398464;
      DAT_80398464 = (int *)0x0;
      DAT_80398460 = 0;
    }
  }
  OSClearContext(&OStack_2e0);
  OSSetCurrentContext(param2);
  return;
}


/* Library Function - Single Match
    DSP_exec_task
   
   Library: KioskDefault 0 0 */

void __DSP_exec_task(int param1,int *param2) { //8001AAD4
  ushort uVar1;
  
  if (param2 != (int *)0x0) {
    if (param1 == 0) {
      dspSendMail(0);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(0);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(0);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
    }
    else {
      dspSendMail(*(undefined4 *)(param1 + 0x18));
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(*(undefined4 *)(param1 + 0x1c));
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(*(undefined4 *)(param1 + 0x20));
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
    }
    dspSendMail(param2[3]);
    do {
      uVar1 = dspGetMailHi();
    } while (uVar1 != 0);
    dspSendMail(param2[4]);
    do {
      uVar1 = dspGetMailHi();
    } while (uVar1 != 0);
    dspSendMail(param2[5]);
    do {
      uVar1 = dspGetMailHi();
    } while (uVar1 != 0);
    if (*param2 == 0) {
      dspSendMail((uint)*(ushort *)(param2 + 9));
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(0);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(0);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(0);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
    }
    else {
      dspSendMail((uint)*(ushort *)((int)param2 + 0x26));
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(param2[6]);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(param2[7]);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
      dspSendMail(param2[8]);
      do {
        uVar1 = dspGetMailHi();
      } while (uVar1 != 0);
    }
    return;
  }
                    
  OSPanic("dsp_task.c",0x223,"__DSP_exec_task(): NULL task. It is to weep.");
}


/* Library Function - Single Match
    __DSP_boot_task
   
   Library: KioskDefault 0 0 */

void __DSP_boot_task(int param1,undefined4 param_2,char *param3) { //8001AC94
  ushort uVar2;
  int iVar1;
  
  if (param1 == 0) {
                    
    OSPanic("dsp_task.c",0x275,"__DSP_boot_task(): NULL task!");
  }
  do {
    uVar2 = dspGetCpuMailHi();
  } while (uVar2 == 0);
  iVar1 = FUN_8001a3f4();
  if (iVar1 != -0x7f8e0113) {
                    
    OSPanic("dsp_task.c",0x27b,"__DSP_boot_task(): Failed to sync DSP on boot! (0x%08X)",iVar1);
  }
  dspSendMail(&DAT_80f3a001);
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(*(undefined4 *)(param1 + 0xc));
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(&DAT_80f3c002);
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(*(uint *)(param1 + 0x14) & 0xffff);
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(&DAT_80f3a002);
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(*(undefined4 *)(param1 + 0x10));
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(&DAT_80f3b002);
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(0);
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail(&DAT_80f3d001);
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspSendMail((uint)*(ushort *)(param1 + 0x24));
  do {
    uVar2 = dspGetMailHi();
  } while (uVar2 != 0);
  dspDebugPrint("DSP is booting task: 0x%08X",param1,param3);
  dspDebugPrint("__DSP_boot_task()  : IRAM MMEM ADDR: 0x%08X",*(int *)(param1 + 0xc),param3);
  dspDebugPrint("__DSP_boot_task()  : IRAM DSP ADDR : 0x%08X",*(int *)(param1 + 0x14),param3);
  dspDebugPrint("__DSP_boot_task()  : IRAM LENGTH   : 0x%08X",*(int *)(param1 + 0x10),param3);
  dspDebugPrint("__DSP_boot_task()  : DRAM MMEM ADDR: 0x%08X",*(int *)(param1 + 0x1c),param3);
  dspDebugPrint("__DSP_boot_task()  : Start Vector  : 0x%08X",(uint)*(ushort *)(param1 + 0x24),param3)
  ;
  return;
}


/* Library Function - Single Match
    __DSP_remove_task
   
   Library: KioskDefault 0 0 */

void __DSP_remove_task(undefined4 *param1) { //8001AF10
  if (param1 == (undefined4 *)0x0) {
                    
    OSPanic("dsp_task.c",0x328,"__DSP_remove_task(): NULL task! Why? WHY?!?!");
  }
  param1[2] = 0;
  *param1 = 3;
  if ((undefined4 *)PTR_DAT_80398458 == param1) {
    if (param1[0xe] == 0) {
      PTR_DAT_80398450 = (undefined *)0x0;
      PTR_DAT_80398454 = (undefined *)0x0;
      PTR_DAT_80398458 = (undefined *)0x0;
    }
    else {
      PTR_DAT_80398458 = (undefined *)param1[0xe];
      *(undefined4 *)(param1[0xe] + 0x3c) = 0;
    }
  }
  else if ((undefined4 *)PTR_DAT_80398454 == param1) {
    PTR_DAT_80398454 = (undefined *)param1[0xf];
    *(undefined4 *)(param1[0xf] + 0x38) = 0;
    PTR_DAT_80398450 = PTR_DAT_80398458;
  }
  else {
    PTR_DAT_80398450 = (undefined *)param1[0xe];
    *(undefined4 *)(param1[0xf] + 0x38) = param1[0xe];
    *(undefined4 *)(param1[0xe] + 0x3c) = param1[0xf];
  }
  return;
}

