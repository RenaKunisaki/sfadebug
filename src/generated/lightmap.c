
/* Library Function - Single Match
    lightMapFn_800a32dc
   
   Library: KioskDefault 0 0 */

void lightMapFn_800a32dc(void) { //800A32DC
  Texture *tex_created;
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (4 < iVar1) {
      DAT_80398c02 = 0;
      DAT_80398c00 = 0;
      DAT_80398c01 = 0;
      return;
    }
    tex_created = gxTextureFn_800a47fc(0x20,0x20,4,'\0',0);
    (&DAT_8036d060)[iVar1 * 7] = tex_created;
    if ((&DAT_8036d060)[iVar1 * 7] == 0) break;
    (&DAT_8036d077)[iVar1 * 0x1c] = 0;
    makeTexFn_800bde64((Texture *)(&DAT_8036d060)[iVar1 * 7]);
    iVar1 = iVar1 + 1;
  }
                    
  OSPanic("lightmap.c",0x9d,"Failed assertion lightMaps[i].texture");
}


/* Library Function - Single Match
    lightMapFn_800a339c
   
   Library: KioskDefault 0 0 */

void shaderInit(void *param1,int *param2,int param3,ushort param4) { //800A339C
  int *piVar1;
  
  if (param1 == (void *)0x0) {
                    
    OSPanic("lightmap.c",0xd2,"Failed assertion shader");
  }
  if (*(int *)((int)param1 + 8) != 0) {
    piVar1 = FUN_800a434c(param1,param3,param4 & 8);
    if (piVar1 == (int *)0x0) {
      if ((param4 & 8) != 0) {
        OSReport(s_LIGHTMAP__Error_>Unique_light_ma_802f0c8c);
      }
      piVar1 = FUN_800a427c();
    }
    if (piVar1 == (int *)0x0) {
                    
      OSPanic("lightmap.c",0xe3,"Failed assertion lightMap");
    }
    if (*(short *)(*piVar1 + 0xe) == -1) {
                    
      OSPanic("lightmap.c",0xe4,s_Failed_assertion_lightMap_>textu_802f0ce4);
    }
    *(short *)(*piVar1 + 0xe) = *(short *)(*piVar1 + 0xe) + 1;
    *param2 = *piVar1;
  }
  if (*(int *)((int)param1 + 0x14) != 0) {
    piVar1 = FUN_800a4468((byte *)((int)param1 + 0x10),param3,param4 & 0x800);
    if (piVar1 == (int *)0x0) {
      if ((param4 & 0x800) != 0) {
        OSReport(s_LIGHTMAP__Error_>Unique_light_ma_802f0c8c);
      }
      piVar1 = FUN_800a42e4();
    }
    if (piVar1 == (int *)0x0) {
                    
      OSPanic("lightmap.c",0xf9,"Failed assertion lightMap");
    }
    if (*(short *)(*piVar1 + 0xe) == -1) {
                    
      OSPanic("lightmap.c",0xfa,s_Failed_assertion_lightMap_>textu_802f0ce4);
    }
    *(short *)(*piVar1 + 0xe) = *(short *)(*piVar1 + 0xe) + 1;
    param2[1] = *piVar1;
  }
  return;
}


/* Library Function - Single Match
    lightMapFn_800a3544
   
   Library: KioskDefault 0 0 */

void shaderFree(Shader **param1) { //800A3544
  int iVar1;
  
  if (*param1 != (Shader *)0x0) {
    for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
      if ((*(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) != 0) &&
         ((Shader *)(&DAT_8036d060)[iVar1 * 7] == *param1)) {
        *(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) =
             *(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) + -1;
        if (*(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) == 0) {
          DAT_80398c00 = DAT_80398c00 + -1;
          DAT_80398c02 = DAT_80398c02 + -1;
        }
        break;
      }
    }
    if (4 < iVar1) {
                    
      OSPanic("lightmap.c",0x129,s_Failed_assertion_i<MAX_LIGHTMAPS_802f0d7c);
    }
  }
  if (param1[1] != (Shader *)0x0) {
    for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
      if ((*(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) != 0) &&
         ((Shader *)(&DAT_8036d060)[iVar1 * 7] == param1[1])) {
        *(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) =
             *(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) + -1;
        if (*(short *)((&DAT_8036d060)[iVar1 * 7] + 0xe) == 0) {
          DAT_80398c01 = DAT_80398c01 + -1;
          DAT_80398c02 = DAT_80398c02 + -1;
        }
        break;
      }
    }
    if (4 < iVar1) {
                    
      OSPanic("lightmap.c",0x13f,s_Failed_assertion_i<MAX_LIGHTMAPS_802f0d7c);
    }
  }
  return;
}


/* Library Function - Single Match
    lightMapFn_800a3d54
   
   Library: KioskDefault 0 0 */

void lightMapFn_800a3d54(ObjInstance *param1) { //800A3D54
  uint param5;
  int iVar1;
  int local_34 [8];
  int local_14 [2];
  
  if (param1 == (ObjInstance *)0x0) {
    param5 = 4;
  }
  else {
    param5 = 6;
  }
  lightControlGetLightsNearObject((int)param1,(int)local_34,8,local_14,param5);
  if (8 < local_14[0]) {
                    
    OSPanic("lightmap.c",0x25a,s_Failed_assertion_numLights<_MAX__802f0da0);
  }
  FUN_80075654(1);
  lightFn_800757ec(0,0,0);
  for (iVar1 = 0; iVar1 < local_14[0]; iVar1 = iVar1 + 1) {
    lightFn_800759b8(0,local_34[iVar1],param1);
  }
  lightFn_800756a0();
  return;
}


/* Library Function - Single Match
    lightMapFn_800a3e1c
   
   Library: KioskDefault 0 0 */

uint lightMapFn_800a3e1c(ObjInstance *param1,uint param2) { //800A3E1C
  int iVar1;
  uint param5;
  uint uVar2;
  int iVar3;
  undefined4 local_50;
  undefined4 local_4c;
  Light *local_48 [8];
  int local_28 [2];
  undefined4 local_20;
  uint uStack_1c;
  
  uVar2 = 0;
  param5 = 4;
  if (param1 != (ObjInstance *)0x0) {
    param5 = 6;
  }
  lightControlGetLightsNearObject((int)param1,(int)local_48,6,local_28,param5);
  if (8 < local_28[0]) {
                    
    OSPanic("lightmap.c",0x284,s_Failed_assertion_numLights<_MAX__802f0da0);
  }
  FUN_80075654(1);
  lightFn_800757ec(0,1,0);
  for (iVar3 = 0; iVar3 < local_28[0]; iVar3 = iVar3 + 1) {
    iVar1 = FUN_800763cc((int)local_48[iVar3]);
    if (iVar1 == 2) {
      if ((param1 != (ObjInstance *)0x0) && ((int)uVar2 < 1)) {
        uStack_1c = param2 & 0xff;
        local_20 = 0x43300000;
        lightSetEccentricityAndRollOff
                  ((double)(float)((double)CONCAT44(0x43300000,uStack_1c) - 4503599627370496.0),0.0,
                   local_48[iVar3]);
        lightFn_800757ec(1,1,0);
        lightFn_800759b8(1,(int)local_48[iVar3],param1);
        lightFn_800757ec(3,0,0);
        lightFn_800759b8(3,(int)local_48[iVar3],param1);
        local_4c = DAT_80396e08;
        GXSetChanAmbColor(3,(byte *)&local_4c);
        local_50 = DAT_80396e0c;
        GXSetChanMatColor(3,(byte *)&local_50);
        uVar2 = uVar2 + 1;
      }
    }
    else {
      uStack_1c = param2 & 0xff;
      local_20 = 0x43300000;
      lightSetEccentricityAndRollOff
                ((double)(float)((double)CONCAT44(0x43300000,uStack_1c) - 4503599627370496.0),0.0,
                 local_48[iVar3]);
      lightFn_800759b8(0,(int)local_48[iVar3],param1);
    }
  }
  lightFn_800756a0();
  return uVar2 & 0xff;
}

