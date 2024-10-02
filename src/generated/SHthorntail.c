
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SHthorntail_initialise(undefined4 param) { //80252548
  return;
}


/* @description Called when DLL is unloaded */

void SHthorntail_release(void) { //8025254C
  return;
}


/* Library Function - Single Match
    dll_1E9_func03
   
   Library: KioskDefault 0 0 */

void SHthorntail_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x
                      ,float y,float z) { //80252550
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *local_18 [2];
  
  puVar3 = this->state;
  local_18[0] = &DAT_01010101;
  bVar1 = *(byte *)&objDef[1].objType;
  if (bVar1 == 2) {
    x = (float)FUN_80253a28((undefined2 *)this,(int)puVar3);
  }
  else if (bVar1 < 2) {
    if (bVar1 != 0) {
      x = (float)FUN_80252a84((undefined2 *)this,(int)puVar3);
    }
  }
  else if (bVar1 < 4) {
    x = (float)FUN_80253cf8((undefined2 *)this,(int)puVar3);
  }
  puVar2 = puVar3 + 0x4e0;
                    /* {@symbol 8012ab10} */
  (**(code **)(*(int *)pDll1A + 4))(x,puVar2,0x6000000,0x400,1);
                    /* {@symbol 8012abb0} */
  (**(code **)(*(int *)pDll1A + 0xc))(puVar2,4,&DAT_8031aa80,&DAT_8031aab0,local_18);
                    /* {@symbol 8012b80c} */
  (**(code **)(*(int *)pDll1A + 0x20))(this,puVar2);
  if (this->shadow != (Shadow *)0x0) {
    this->shadow->flags = this->shadow->flags | 0xa30;
    (this->shadow->color).b = 0x80;
    (this->shadow->color).a = 0x5a;
  }
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_802529f0;
  puVar3[0x4b8] = 0xff;
  return;
}


/* Library Function - Single Match
    dll_1E9_func04
   
   Library: KioskDefault 0 0 */

void SHthorntail_update(ObjInstance *param1) { //802526A4
  byte bVar1;
  ObjInstance *param2;
  uint uVar2;
  undefined uVar3;
  undefined *param2_00;
  ObjDef *pOVar4;
  undefined *puVar5;
  double in_f1;
  double extraout_f1;
  double dVar6;
  
  puVar5 = param1->state;
  pOVar4 = param1->def;
  param2 = Object_objGetMain();
  param1->flags_0xaf = param1->flags_0xaf & ~ModelDisableFlag08;
  objDistObj2Obj(param1,param2);
  puVar5[0x871] = in_f1 < 200.0;
  if ((puVar5[0x4b8] == '\x0e') || (puVar5[0x4b8] == '\r')) {
    param2_00 = &DAT_8031acb4;
  }
  else {
    param2_00 = &DAT_8031aac0;
  }
  uVar2 = objHitReactFn_80089890
                    (param1,(int)param2_00,0x19,(uint)(byte)puVar5[0x870],(float *)(puVar5 + 0x848))
  ;
  puVar5[0x870] = (char)uVar2;
  if ((uVar2 & 0xff) == 0) {
    puVar5[0x870] = 0;
                    /* {@symbol 8012dfa8} */
    uVar3 = (**(code **)(*(int *)pDll_SaveGame + 0x40))((int)(char)param1->mapId);
    puVar5[0x4bb] = uVar3;
    dVar6 = extraout_f1;
    objDistObj2Obj(param1,param2);
    *(float *)(puVar5 + 0x83c) = (float)dVar6;
    bVar1 = *(byte *)&pOVar4[1].objType;
    if (bVar1 == 2) {
      FUN_80253b74(dVar6,param1,(int)puVar5);
    }
    else if (bVar1 < 2) {
      if (bVar1 != 0) {
        FUN_80252bd8(dVar6,param1,(int)puVar5);
      }
    }
    else if (bVar1 < 4) {
      FUN_80253da4(dVar6,param1,(int)puVar5);
    }
                    /* {@symbol 8012ac30} */
    (**(code **)(*(int *)pDll1A + 0x10))((double)timeDelta,param1,puVar5 + 0x4e0);
                    /* {@symbol 8012b0e4} */
    (**(code **)(*(int *)pDll1A + 0x14))(param1,puVar5 + 0x4e0);
                    /* {@symbol 8012b170} */
    (**(code **)(*(int *)pDll1A + 0x18))((double)timeDelta,param1,puVar5 + 0x4e0);
    if (((&DAT_8031aee4)[(char)puVar5[0x4b8]] & 2) == 0) {
      FUN_800928ac((int)param1,(int)(puVar5 + 0x84c));
    }
  }
  else {
    OSReport("HIT dframe=%f",(double)*(float *)(puVar5 + 0x848));
  }
  return;
}


/* @description Override hit detection */

void SHthorntail_hitDetect(ObjInstance *this) { //80252884
  return;
}


/* Library Function - Single Match
    dll_1E9_func06
   
   Library: KioskDefault 0 0 */

void SHthorntail_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                        undefined param5,bool shouldRender) { //80252888
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void SHthorntail_free(ObjInstance *this,int param2) { //802528F4
  return;
}


undefined4 SHthorntail_func08(ObjInstance *this) { //802528F8
  return 0x49;
}


/* @description Get extra size for object (size of State struct) */

int SHthorntail_getExtraSize(void) { //80252900
  return 0x874;
}


/* Library Function - Single Match
    thornTailNetworkFn_80252c80
   
   Library: KioskDefault 0 0 */

void thornTailNetworkFn_80252c80(double param_1,ObjInstance *param1,int param2) { //80252C80
  char cVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  N64Button32 NVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  double extraout_f1;
  double extraout_f1_00;
  float afStack_9c [7];
  undefined auStack_80 [4];
  int local_7c [4];
  undefined4 local_6c [5];
  longlong local_58;
  double local_50;
  undefined4 local_48;
  uint uStack_44;
  
  _savefpr_30();
  *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) & 0xfb;
  if ((param1->flags_0xaf & CanPressAToTalk) != 0) {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))
              (*(undefined *)(*(int *)(param2 + 0x4c0) + (uint)*(byte *)(param2 + 0x4bd)),param1,
               0xffffffff);
    if (((*(byte *)(param2 + 0x4ba) & 0x40) != 0) &&
       (*(char *)(param2 + 0x4bd) = *(char *)(param2 + 0x4bd) + '\x01',
       *(byte *)(param2 + 0x4c4) <= *(byte *)(param2 + 0x4bd))) {
      *(undefined *)(param2 + 0x4bd) = 0;
    }
    goto LAB_80253a00;
  }
  if ((*(byte *)(param2 + 0x4ba) & 0x10) != 0) {
    if ((*(int *)(param2 + 0x758) == 0) || (*(char *)(*(int *)(param2 + 0x75c) + 0x34) == '\x04')) {
      uVar11 = 0xffffffff;
    }
    else {
      uVar11 = *(undefined4 *)(*(int *)(param2 + 0x758) + 0x14);
    }
                    /* {@symbol 801247b0} */
    iVar5 = (**(code **)(*(int *)pDll_RomCurve + 0x58))
                      (*(undefined4 *)(param2 + 0x75c),uVar11,local_6c);
    iVar13 = 0;
    param_1 = extraout_f1;
    for (iVar12 = 0; iVar12 < iVar5; iVar12 = iVar12 + 1) {
                    /* {@symbol 8012464c} */
      iVar6 = (**(code **)(*(int *)pDll_RomCurve + 0x1c))(local_6c[iVar12]);
      if (iVar6 != 0) {
        bVar4 = false;
        if (*(int *)(param2 + 0x4dc) == 9) {
          if (((*(char *)(iVar6 + 0x34) == '\t') || (*(char *)(iVar6 + 0x34) == '\x04')) ||
             (*(char *)(iVar6 + 0x34) == '\0')) {
            bVar4 = true;
          }
        }
        else if (((*(char *)(iVar6 + 0x34) == '\b') || (*(char *)(iVar6 + 0x34) == '\t')) ||
                (*(char *)(iVar6 + 0x34) == '\0')) {
          bVar4 = true;
        }
        if (bVar4) {
          local_7c[iVar13] = iVar6;
          iVar13 = iVar13 + 1;
        }
      }
      param_1 = extraout_f1_00;
    }
    if (iVar13 == 0) {
      OSReport("Thorntail %d, is on a network with a deadend",param1->def->id);
                    
      OSPanic("SHthorntail.c",0x308,"Thorntail deadend");
    }
    iVar5 = randInt(0,iVar13 + -1);
    *(int *)(param2 + 0x760) = local_7c[iVar5];
    *(undefined4 *)(param2 + 0x758) = *(undefined4 *)(param2 + 0x75c);
    *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) & 0xfd;
    *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) & 0xef;
  }
  if ((*(byte *)(param2 + 0x4ba) & 2) == 0) {
    objDistSqObj2Def(param1,*(ObjDef **)(param2 + 0x760));
    *(float *)(param2 + 0x840) = (float)param_1;
    if ((30.0 <= *(float *)(param2 + 0x840)) || ((*(byte *)(param2 + 0x4ba) & 1) == 0)) {
      cVar1 = *(char *)(param2 + 0x4b8);
      if (cVar1 == '\x03') {
        if ((*(int *)(param2 + 0x4dc) == 8) && (*(char *)(*(int *)(param2 + 0x760) + 0x34) != '\0'))
        {
          *(float *)(param2 + 0x844) = (*(float *)(param2 + 0x840) - 35.0) / 45.0;
          if (0.0 <= *(float *)(param2 + 0x844)) {
            if (1.0 < *(float *)(param2 + 0x844)) {
              *(float *)(param2 + 0x844) = 1.0;
            }
          }
          else {
            *(float *)(param2 + 0x844) = 0.0;
          }
        }
        else {
          *(float *)(param2 + 0x844) = 1.0;
        }
        fVar2 = *(float *)(*(int *)(param2 + 0x760) + 8) - (param1->pos).pos.x;
        fVar3 = *(float *)(*(int *)(param2 + 0x760) + 0x10) - (param1->pos).pos.z;
        if (*(float *)(param2 + 0x840) != 0.0) {
          fVar2 = fVar2 / *(float *)(param2 + 0x840);
          fVar3 = fVar3 / *(float *)(param2 + 0x840);
        }
        *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 4;
        *(float *)(param2 + 0x804) = 0.28;
        (param1->vel).x = *(float *)(param2 + 0x804) * fVar2;
        (param1->vel).z = *(float *)(param2 + 0x804) * fVar3;
        objMove((double)((param1->vel).x * timeDelta),0.0,(double)((param1->vel).z * timeDelta),
                param1);
        objGetAnimChange((double)*(float *)(param2 + 0x804),(int)param1,(float *)(param2 + 0x800));
      }
      else if ((cVar1 < '\x03') || ('\x05' < cVar1)) {
        iVar5 = getAngle();
        *(short *)(param2 + 0x4d2) = (short)iVar5;
        *(short *)(param2 + 0x4d6) = (param1->pos).rotation.x;
        *(short *)(param2 + 0x4d4) = (param1->pos).rotation.x - *(short *)(param2 + 0x4d2);
        if (0x8000 < *(short *)(param2 + 0x4d4)) {
          *(short *)(param2 + 0x4d4) = *(short *)(param2 + 0x4d4) + 1;
        }
        if (*(short *)(param2 + 0x4d4) < -0x8000) {
          *(short *)(param2 + 0x4d4) = *(short *)(param2 + 0x4d4) + -1;
        }
        if ((*(short *)(param2 + 0x4d4) < 500) && (-500 < *(short *)(param2 + 0x4d4))) {
          *(undefined *)(param2 + 0x4b8) = 3;
        }
        else {
          if (*(short *)(param2 + 0x4d4) < 0x4001) {
            if (*(short *)(param2 + 0x4d4) < -0x4000) {
              *(undefined2 *)(param2 + 0x4d4) = 0xc000;
            }
          }
          else {
            *(undefined2 *)(param2 + 0x4d4) = 0x4000;
          }
          if (*(short *)(param2 + 0x4d4) < 0) {
            *(undefined *)(param2 + 0x4b8) = 4;
            local_50 = (double)CONCAT44(0x43300000,-(int)*(short *)(param2 + 0x4d4) ^ 0x80000000);
            *(float *)(param2 + 0x844) = (float)(local_50 - 4503601774854144.0);
          }
          else {
            *(undefined *)(param2 + 0x4b8) = 5;
            local_50 = (double)CONCAT44(0x43300000,(int)*(short *)(param2 + 0x4d4) ^ 0x80000000);
            *(float *)(param2 + 0x844) = (float)(local_50 - 4503601774854144.0);
          }
          *(float *)(param2 + 0x844) = *(float *)(param2 + 0x844) / 16384.0;
          if (*(float *)(param2 + 0x844) <= 1.0) {
            if (*(float *)(param2 + 0x844) < 0.0) {
              *(float *)(param2 + 0x844) = 0.0;
            }
          }
          else {
            *(float *)(param2 + 0x844) = 1.0;
          }
        }
      }
      else if ((*(byte *)(param2 + 0x4ba) & 1) == 0) {
        local_50 = (double)CONCAT44(0x43300000,(int)*(short *)(param2 + 0x4d4) ^ 0x80000000);
        uStack_44 = (int)*(short *)(param2 + 0x4d6) ^ 0x80000000;
        local_48 = 0x43300000;
        iVar5 = (int)-(param1->animTimer * (float)(local_50 - 4503601774854144.0) -
                      (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0));
        local_58 = (longlong)iVar5;
        (param1->pos).rotation.x = (short)iVar5;
      }
      else {
        *(short *)(param2 + 0x4d6) = (param1->pos).rotation.x;
        *(short *)(param2 + 0x4d4) = (param1->pos).rotation.x - *(short *)(param2 + 0x4d2);
        if (0x8000 < *(short *)(param2 + 0x4d4)) {
          *(short *)(param2 + 0x4d4) = *(short *)(param2 + 0x4d4) + 1;
        }
        if (*(short *)(param2 + 0x4d4) < -0x8000) {
          *(short *)(param2 + 0x4d4) = *(short *)(param2 + 0x4d4) + -1;
        }
        if ((*(short *)(param2 + 0x4d4) < 500) && (-500 < *(short *)(param2 + 0x4d4))) {
          *(undefined *)(param2 + 0x4b8) = 3;
          *(float *)(param2 + 0x844) = 1.0;
        }
        else {
          if (*(short *)(param2 + 0x4d4) < 0x4001) {
            if (*(short *)(param2 + 0x4d4) < -0x4000) {
              *(undefined2 *)(param2 + 0x4d4) = 0x4000;
            }
          }
          else {
            *(undefined2 *)(param2 + 0x4d4) = 0x4000;
          }
          if (*(short *)(param2 + 0x4d4) < 0) {
            local_50 = (double)CONCAT44(0x43300000,-(int)*(short *)(param2 + 0x4d4) ^ 0x80000000);
            *(float *)(param2 + 0x844) = (float)(local_50 - 4503601774854144.0);
          }
          else {
            local_50 = (double)CONCAT44(0x43300000,(int)*(short *)(param2 + 0x4d4) ^ 0x80000000);
            *(float *)(param2 + 0x844) = (float)(local_50 - 4503601774854144.0);
          }
          *(float *)(param2 + 0x844) = *(float *)(param2 + 0x844) / 16384.0;
          if (*(float *)(param2 + 0x844) <= 1.0) {
            if (*(float *)(param2 + 0x844) < 0.0) {
              *(float *)(param2 + 0x844) = 0.0;
            }
          }
          else {
            *(float *)(param2 + 0x844) = 1.0;
          }
          *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 8;
        }
      }
    }
    else {
      *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 2;
      *(undefined4 *)(param2 + 0x75c) = *(undefined4 *)(param2 + 0x760);
      if (((*(int *)(param2 + 0x4dc) == 9) && (*(char *)(*(int *)(param2 + 0x75c) + 0x34) != '\x04')
          ) || (*(char *)(*(int *)(param2 + 0x75c) + 0x34) == '\0')) {
        *(undefined *)(param2 + 0x4b8) = 0xff;
        *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 0x10;
      }
    }
    goto LAB_80253848;
  }
  *(ushort *)(param2 + 0x4ce) = *(short *)(param2 + 0x4ce) - (ushort)framesThisStep;
  if (*(short *)(param2 + 0x4ce) < 0) {
    *(undefined2 *)(param2 + 0x4ce) = 0;
  }
                    /* {@symbol 800d2604} */
  if ((((&DAT_8031aee4)[*(char *)(param2 + 0x4b8)] & 2) == 0) &&
     (iVar5 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_80), iVar5 != 0)) {
    *(undefined *)(param2 + 0x4b8) = 0xe;
  }
  if (false) {
switchD_80252f44_caseD_3:
    if ((*(byte *)(param2 + 0x4ba) & 0x20) == 0) {
      if (*(char *)(*(int *)(param2 + 0x75c) + 0x34) == '\x04') {
        *(undefined *)(param2 + 0x4b8) = 6;
      }
      else {
                    /* {@symbol 800d2604} */
        iVar5 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_80);
        if (iVar5 == 0) {
          *(undefined *)(param2 + 0x4b8) = 0;
          iVar5 = randInt(500,800);
          *(short *)(param2 + 0x4cc) = (short)iVar5;
          iVar5 = randInt(2000,3000);
          *(short *)(param2 + 0x4ce) = (short)iVar5;
        }
        else {
          *(undefined *)(param2 + 0x4b8) = 0xe;
        }
      }
    }
    else {
      *(undefined *)(param2 + 0x4b8) = 10;
    }
  }
  else {
                    /* {@symbol 80252f48} */
    switch(*(undefined *)(param2 + 0x4b8)) {
    case 0:
      *(ushort *)(param2 + 0x4cc) = *(short *)(param2 + 0x4cc) - (ushort)framesThisStep;
      if (*(short *)(param2 + 0x4cc) < 0) {
        *(undefined2 *)(param2 + 0x4cc) = 0;
      }
      if (((*(byte *)(param2 + 0x4ba) & 1) != 0) && (*(short *)(param2 + 0x4cc) < 1)) {
        if (*(char *)(param2 + 0x4bc) < '\x01') {
          *(undefined *)(param2 + 0x4b8) = 2;
        }
        else {
          *(undefined *)(param2 + 0x4b8) = 1;
        }
      }
      if (*(short *)(param2 + 0x4ce) < 1) {
        if (*(int *)(param2 + 0x4dc) == 9) {
          *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 0x10;
        }
        else {
          *(undefined *)(param2 + 0x4b8) = 0xc;
        }
      }
      else {
        NVar7 = n64GetEnabledButtonsPressed(0);
        if ((NVar7 & N64_BUTTON_DOWN) != 0) {
          *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 0x10;
          *(undefined4 *)(param2 + 0x4dc) = 9;
        }
      }
      break;
    case 1:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined *)(param2 + 0x4b8) = 0;
        *(char *)(param2 + 0x4bc) = *(char *)(param2 + 0x4bc) + -1;
        iVar5 = randInt(500,800);
        *(short *)(param2 + 0x4cc) = (short)iVar5;
      }
      break;
    case 2:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined *)(param2 + 0x4b8) = 0;
        iVar5 = randInt(1,2);
        *(char *)(param2 + 0x4bc) = (char)iVar5;
        iVar5 = randInt(500,800);
        *(short *)(param2 + 0x4cc) = (short)iVar5;
      }
      break;
    default:
      goto switchD_80252f44_caseD_3;
    case 6:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined *)(param2 + 0x4b8) = 7;
        iVar5 = randInt(1000,2000);
        *(short *)(param2 + 0x4d0) = (short)iVar5;
      }
      break;
    case 7:
      *(ushort *)(param2 + 0x4d0) = *(short *)(param2 + 0x4d0) - (ushort)framesThisStep;
      if (*(short *)(param2 + 0x4d0) < 0) {
        *(undefined2 *)(param2 + 0x4d0) = 0;
      }
      if (((*(byte *)(param2 + 0x4ba) & 1) != 0) && (*(short *)(param2 + 0x4d0) < 1)) {
        *(undefined *)(param2 + 0x4b8) = 8;
      }
      break;
    case 8:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined *)(param2 + 0x4b8) = 9;
      }
      break;
    case 9:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined4 *)(param2 + 0x4dc) = 8;
        *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 0x10;
      }
      break;
    case 10:
      uVar8 = mainGetBit((int)*(short *)(param2 + 0x4d8));
      if (uVar8 != 0) {
        *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) & 0xdf;
        *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 8;
        *(undefined *)(param2 + 0x4b8) = 0xb;
      }
      break;
    case 0xb:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined4 *)(param2 + 0x4dc) = 8;
        *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 0x10;
      }
      break;
    case 0xc:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined4 *)(param2 + 0x4dc) = 8;
        *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 0x10;
      }
      break;
    case 0xd:
      uStack_44 = (int)*(short *)(param2 + 0x872) ^ 0x80000000;
      local_48 = 0x43300000;
      iVar5 = (int)((float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0) - timeDelta
                   );
      local_50 = (double)(longlong)iVar5;
      *(short *)(param2 + 0x872) = (short)iVar5;
      if ((*(short *)(param2 + 0x872) < 1) &&
         (*(undefined2 *)(param2 + 0x872) = 0x78, *(char *)(param2 + 0x871) != '\0')) {
        audioTryStartSfx((int *)param1,1,(ushort)*(undefined4 *)(param2 + 0x4c8),0x7f,
                         "SHthorntail.c",0x382);
        if (*(int *)(param2 + 0x4c8) == 0x266) {
          *(undefined4 *)(param2 + 0x4c8) = 0x267;
        }
        else {
          *(undefined4 *)(param2 + 0x4c8) = 0x266;
        }
      }
                    /* {@symbol 800d2604} */
      iVar5 = (**(code **)(*(int *)pDll_newfog + 0x24))(auStack_80);
      if (iVar5 == 0) {
        *(undefined *)(param2 + 0x4b8) = 0xb;
      }
      break;
    case 0xe:
      if ((*(byte *)(param2 + 0x4ba) & 1) != 0) {
        *(undefined2 *)(param2 + 0x872) = 0x78;
        *(undefined *)(param2 + 0x4b8) = 0xd;
      }
    }
  }
LAB_80253848:
  if (*(char *)(param2 + 0x4b8) != -1) {
    iVar5 = (int)*(char *)(param2 + 0x4b8);
    if ((param1->animId != *(word *)(&DAT_8031aea8 + iVar5 * 4)) ||
       ((*(byte *)(param2 + 0x4ba) & 8) != 0)) {
      Object_ObjAnimSetMove(0.0,param1,(int)*(short *)(&DAT_8031aea8 + iVar5 * 4),0);
      if ((*(byte *)(param2 + 0x4ba) & 4) == 0) {
        *(undefined4 *)(param2 + 0x800) =
             *(undefined4 *)(&DAT_8031aef4 + *(char *)(param2 + 0x4b8) * 4);
      }
      *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) & 0xf6;
    }
    if (*(short *)(&DAT_8031aea8 + (iVar5 * 2 + 1) * 2) != -1) {
      iVar12 = (int)(*(float *)(param2 + 0x844) * 16384.0);
      local_58 = (longlong)iVar12;
      FUN_80087afc((int)param1,(int)*(short *)(&DAT_8031aea8 + (iVar5 * 2 + 1) * 2),(short)iVar12);
    }
  }
  if (((&DAT_8031aee4)[*(char *)(param2 + 0x4b8)] & 1) != 0) {
    param1->flags_0xaf = param1->flags_0xaf | ModelDisableFlag08;
  }
  puVar9 = (undefined4 *)FUN_80094400((int)param1,5);
  puVar10 = (undefined4 *)FUN_80094400((int)param1,4);
  if (((&DAT_8031aee4)[*(char *)(param2 + 0x4b8)] & 2) == 0) {
    if (puVar9 != (undefined4 *)0x0) {
      *puVar9 = 0;
    }
    if (puVar10 != (undefined4 *)0x0) {
      *puVar10 = 0;
    }
  }
  else {
    if (puVar9 != (undefined4 *)0x0) {
      *puVar9 = 0x200;
    }
    if (puVar10 != (undefined4 *)0x0) {
      *puVar10 = 0x200;
    }
  }
  iVar5 = objRunAnimation((double)*(float *)(param2 + 0x800),(double)timeDelta,(int)param1,
                          afStack_9c);
  if (iVar5 == 0) {
    *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) & 0xfe;
  }
  else {
    *(byte *)(param2 + 0x4ba) = *(byte *)(param2 + 0x4ba) | 1;
  }
LAB_80253a00:
  _restfpr_30();
  return;
}

