
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void LGTprojectedlight_initialise(undefined4 param) { //802CC938
  return;
}


/* @description Called when DLL is unloaded */

void LGTprojectedlight_release(void) { //802CC93C
  return;
}


/* Library Function - Single Match
    dll_2F7_func03
   
   Library: KioskDefault 0 0 */

void LGTprojectedlight_init
               (ObjInstance *param1,int param2,ObjInstance *obj2,DllInitFlags flags,float x,float y,
               float z) { //802CC940
  float fVar1;
  float fVar2;
  Light *pLVar3;
  Light **ppLVar4;
  double param4;
  double param1_00;
  
  _savefpr_30();
  ppLVar4 = (Light **)param1->state;
  (param1->pos).rotation.x = (ushort)*(byte *)(param2 + 0x18) << 8;
  (param1->pos).rotation.y = (ushort)*(byte *)(param2 + 0x19) << 8;
  (param1->pos).rotation.z = (ushort)*(byte *)(param2 + 0x34) << 8;
  if (*ppLVar4 == (Light *)0x0) {
    pLVar3 = lightCreateAndAdd(param1,true);
    *ppLVar4 = pLVar3;
    if (*ppLVar4 == (Light *)0x0) {
                    
      OSPanic("LGTprojectedlight.c",0x76,s_Failed_assertion_lightData_>ligh_80325b4c);
    }
    lightSetType(*ppLVar4,8);
  }
  lightFn_80075f4c(0.0,0.0,0.0,*ppLVar4);
  lightFn_80076074(0.0,0.0,1.0,*ppLVar4);
  lightFn_80076438(*ppLVar4,*(byte *)(param2 + 0x2d),*(byte *)(param2 + 0x2e),
                   *(byte *)(param2 + 0x2f),*(byte *)(param2 + 0x37));
  lightFn_800761b4((double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + 0x1a)) -
                                  4503599627370496.0),
                   (double)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param2 + 0x1c)) -
                                   4503599627370496.0) / 255.0),*ppLVar4,
                   (uint)*(byte *)(param2 + 0x1d));
  FUN_800763d4((int)*ppLVar4,(uint)*(byte *)(param2 + 0x39));
  lightFn_80076324(*ppLVar4,*(byte *)(param2 + 0x3a));
  if (ppLVar4[1] == (Light *)0x0) {
    if (*(short *)(param2 + 0x24) == 0) {
      pLVar3 = (Light *)textureLoadAsset(0x5a8);
      ppLVar4[1] = pLVar3;
    }
    else {
      pLVar3 = (Light *)textureLoadAsset((uint)*(ushort *)(param2 + 0x24));
      ppLVar4[1] = pLVar3;
    }
    lightSetTexture(*ppLVar4,(Texture *)ppLVar4[1]);
  }
  if (*(char *)(param2 + 0x26) == '\0') {
    param4 = (double)((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + 0x28)) -
                             4503599627370496.0) / 10.0);
    if (param4 < 1.0) {
      param4 = 1.0;
    }
    param1_00 = (double)((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + 0x2a)) -
                                4503599627370496.0) / 10.0);
    if (param1_00 < 1.0) {
      param1_00 = 1.0;
    }
    lightFn_800769c8(param1_00,-param1_00,-param4,param4,*ppLVar4);
  }
  else {
    fVar1 = (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + 0x28)) -
                   4503599627370496.0) / 10.0;
    if (fVar1 < 1.0) {
      fVar1 = 1.0;
    }
    fVar2 = (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + 0x2a)) -
                   4503599627370496.0) / 10.0;
    if (fVar2 < 1.0) {
      fVar2 = 1.0;
    }
    lightSetAspect((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param2 + 0x27)) -
                                  4503599627370496.0),(double)(fVar1 / fVar2),*ppLVar4);
  }
  FUN_80076cbc((int)*ppLVar4,(uint)*(byte *)(param2 + 0x36),(uint)*(byte *)(param2 + 0x3e));
  FUN_80076c04((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param2 + 0x3b)) -
                              4503599627370496.0),(int)*ppLVar4);
  FUN_80076c38((double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param2 + 0x3c)) -
                              4503599627370496.0),(int)*ppLVar4);
  lightAnimFn_80076cdc(*ppLVar4,(uint)*(byte *)(param2 + 0x33),*(short *)(param2 + 0x1e));
  lightFn_80076548(*ppLVar4,*(undefined *)(param2 + 0x30),*(undefined *)(param2 + 0x31),
                   *(undefined *)(param2 + 0x32),*(undefined *)(param2 + 0x38));
  _restfpr_30();
  return;
}


/* Library Function - Single Match
    dll_2F7_func04
   
   Library: KioskDefault 0 0 */

void LGTprojectedlight_update(ObjInstance *this) { //802CCCA4
  ObjDef *pOVar1;
  
  pOVar1 = this->def;
  (this->pos).rotation.x =
       (short)(int)((float)((double)CONCAT44(0x43300000,(int)*(short *)&pOVar1[1].pos.x ^ 0x80000000
                                            ) - 4503601774854144.0) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.x ^ 0x80000000) -
                          4503601774854144.0));
  (this->pos).rotation.y =
       (short)(int)((float)((double)CONCAT44(0x43300000,
                                             (int)*(short *)((int)&pOVar1[1].pos.x + 2) ^ 0x80000000
                                            ) - 4503601774854144.0) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.y ^ 0x80000000) -
                          4503601774854144.0));
  (this->pos).rotation.z =
       (short)(int)((float)((double)CONCAT44(0x43300000,
                                             (int)(char)pOVar1[2].mapStates2 << 8 ^ 0x80000000) -
                           4503601774854144.0) * timeDelta +
                   (float)((double)CONCAT44(0x43300000,(int)(this->pos).rotation.z ^ 0x80000000) -
                          4503601774854144.0));
  return;
}


/* @description Override hit detection */

void LGTprojectedlight_hitDetect(ObjInstance *this) { //802CCDD4
  return;
}


/* Library Function - Single Match
    dll_2F7_func06
   
   Library: KioskDefault 0 0 */

void LGTprojectedlight_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //802CCDD8
  ObjInstance *param2_00;
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  param2_00 = Object_objGetMain();
  objDistObj2ObjXZ(this,param2_00);
  iVar1 = isModelAnimDisabled();
  if (iVar1 != 0) {
    if (((this->pos).flags & 0x100) != 0) {
      FUN_802ccec4(this);
    }
    objRenderCurrentModel
              (this,(Gfx **)CONCAT31(in_register_00000010,param2),
               (undefined4 *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Single Match
    dll_2F7_func07
   
   Library: KioskDefault 0 0 */

void LGTprojectedlight_free(ObjInstance *this,int param2) { //802CCE68
  Light **ppLVar1;
  
  ppLVar1 = (Light **)this->state;
  lightFreeAndRemove(*ppLVar1);
  if (ppLVar1[1] != (Light *)0x0) {
    texFreeTexture((Texture *)ppLVar1[1]);
  }
  return;
}


undefined4 LGTprojectedlight_func08(ObjInstance *this) { //802CCEB4
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int LGTprojectedlight_getExtraSize(void) { //802CCEBC
  return 8;
}

