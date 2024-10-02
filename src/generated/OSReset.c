
/* Library Function - Single Match
    osResetFn_8000be68
   
   Library: KioskDefault 0 0 */

void osResetFn_8000be68(os_reset_info *info) { //8000BE68
  os_reset_info *poVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)PTR_o"-m-";
  if (info->func != (undefined *)0x0) {
    for (; (piVar3 != (int *)0x0 && ((uint)piVar3[1] <= info->field1_0x4));
        piVar3 = (int *)piVar3[2]) {
    }
    if (piVar3 == (int *)0x0) {
      poVar1 = info;
      if (PTR_PTR_cardCb_80398284 != (undefined *)0x0) {
        *(os_reset_info **)(PTR_PTR_cardCb_80398284 + 8) = info;
        poVar1 = (os_reset_info *)PTR_o"-m-";
      }
      PTR_o"-m-" = (undefined *)poVar1;
      info->field3_0xc = (int *)PTR_PTR_cardCb_80398284;
      info->field2_0x8 = (int *)0x0;
      poVar1 = (os_reset_info *)PTR_o"-m-";
      PTR_PTR_cardCb_80398284 = (undefined *)info;
    }
    else {
      info->field2_0x8 = piVar3;
      piVar2 = (int *)piVar3[3];
      piVar3[3] = (int)info;
      info->field3_0xc = piVar2;
      poVar1 = info;
      if (piVar2 != (int *)0x0) {
        piVar2[2] = (int)info;
        poVar1 = (os_reset_info *)PTR_o"-m-";
      }
    }
    PTR_o"-m-" = (undefined *)poVar1;
    return;
  }
                    
  OSPanic("OSReset.c",0x76,s_Failed_assertion_info_>func_802d30bc);
}

