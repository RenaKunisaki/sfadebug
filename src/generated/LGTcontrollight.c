
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void LGTcontrollight_initialise(undefined4 param) { //802CD3F8
  return;
}


/* @description Called when DLL is unloaded */

void LGTcontrollight_release(void) { //802CD3FC
  return;
}


/* Library Function - Single Match
    dll_2F8_func03
   
   Library: KioskDefault 0 0 */

void LGTcontrollight_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //802CD400
  byte bVar1;
  short sVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)this->state;
  *puVar3 = *(undefined2 *)&objDef[1].bound;
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  *(float *)(puVar3 + 2) =
       (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - 4503601774854144.0);
  bVar1 = *(byte *)((int)&objDef[1].objType + 1);
  *(byte *)(puVar3 + 4) =
       bVar1 + (((char)bVar1 >> 1) + ((char)bVar1 < '\0' && (bVar1 & 1) != 0)) * -2;
  *(undefined *)((int)puVar3 + 9) = 0xff;
  return;
}


/* Library Function - Single Match
    dll_2F8_func04
   
   Library: KioskDefault 0 0 */

void LGTcontrollight_update(ObjInstance *this) { //802CD468
  uint uVar1;
  uint uVar2;
  short *psVar3;
  
  psVar3 = (short *)this->state;
  uVar2 = mainGetBit((int)*psVar3);
  if ((uVar2 & 0xff) != (uint)*(byte *)((int)psVar3 + 9)) {
    if (*(char *)(psVar3 + 4) == '\x01') {
      uVar1 = countLeadingZeros(uVar2 & 0xff);
      FUN_802cd56c((double)*(float *)(psVar3 + 2),this,(byte)(uVar1 >> 5));
    }
    else if ((*(char *)(psVar3 + 4) == '\0') && (true)) {
      FUN_802cd56c((double)*(float *)(psVar3 + 2),this,(byte)uVar2);
    }
  }
  *(byte *)((int)psVar3 + 9) = (byte)uVar2;
  return;
}


/* @description Override hit detection */

void LGTcontrollight_hitDetect(ObjInstance *this) { //802CD4FC
  return;
}


/* @description Override render */

void LGTcontrollight_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802CD500
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  iVar1 = isModelAnimDisabled();
  if (iVar1 != 0) {
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* @description Free object instance */

void LGTcontrollight_free(ObjInstance *this,int param2) { //802CD558
  return;
}


undefined4 LGTcontrollight_func08(ObjInstance *this) { //802CD55C
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int LGTcontrollight_getExtraSize(void) { //802CD564
  return 0xc;
}


void FUN_802cd56c(double param_1,ObjInstance *param_2,byte param_3) { //802CD56C
  float fVar1;
  ObjInstance **ppOVar2;
  uint uVar3;
  int iVar4;
  ObjInstance *param2;
  int local_14 [2];
  
  fVar1 = (float)param_1;
  ppOVar2 = Object_playerGetObject(0x37,local_14);
  iVar4 = 0;
  while( true ) {
    if (local_14[0] <= iVar4) {
      return;
    }
    param2 = ppOVar2[iVar4];
    uVar3 = FUN_80090d28(param2,0x37);
    if (uVar3 == 0) break;
    objDistObj2Obj(param_2,param2);
    if (param_1 < (double)fVar1) {
      param_1 = (double)LGTpointlightFn_802cbd5c((int)param2,param_3);
    }
    iVar4 = iVar4 + 1;
  }
                    
  OSPanic("LGTcontrollight.c",0x119,"Failed assertion objCheckType( lightObject, OBTYPE_LIGHTEMIT)");
}

