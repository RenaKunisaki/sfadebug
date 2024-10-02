
/* Library Function - Single Match
    gxTexFmtFn_800258ac
   
   Library: KioskDefault 0 0 */

void gxTexFmtFn_800258ac(undefined4 param1,undefined4 *param2,undefined4 *param3) { //800258AC
  if (false) {
switchD_800258e8_caseD_7:
    *param3 = 0;
    *param2 = 0;
                    
    OSPanic("GXTexture.c",0x184,"%s: invalid texture format","GX");
  }
                    /* {@symbol 800258ec} */
  switch(param1) {
  case 0:
  case 8:
  case 0xe:
  case 0x20:
  case 0x30:
    *param2 = 3;
    *param3 = 3;
    break;
  case 1:
  case 2:
  case 9:
  case 0x11:
  case 0x22:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x39:
  case 0x3a:
    *param2 = 3;
    *param3 = 2;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 10:
  case 0x13:
  case 0x16:
  case 0x23:
  case 0x2b:
  case 0x2c:
  case 0x3c:
    *param2 = 2;
    *param3 = 2;
    break;
  default:
    goto switchD_800258e8_caseD_7;
  }
  return;
}


/* Library Function - Single Match
    GXGetTexBufferSize
   
   Library: KioskDefault 0 0 */

int GXGetTexBufferSize(uint param1,uint param2,int param3,char param4,byte param5) { //80025968
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_34;
  uint local_30 [3];
  
  if (0x400 < (param1 & 0xffff)) {
                    
    OSPanic("GXTexture.c",0x194,"%s: width too large",
            "GXGetTexBufferSize");
  }
  if (0x400 < (param2 & 0xffff)) {
                    
    OSPanic("GXTexture.c",0x195,"%s: height too large",
            "GXGetTexBufferSize");
  }
  gxTexFmtFn_800258ac(param3,local_30,&local_34);
  if ((param3 == 6) || (param3 == 0x16)) {
    iVar3 = 0x40;
  }
  else {
    iVar3 = 0x20;
  }
  if (param4 == '\x01') {
    iVar1 = countLeadingZeros(param1 & 0xffff);
    if ((param1 & 0xffff) != 1 << 0x1f - iVar1) {
                    
      OSPanic("GXTexture.c",0x1a7,"%s: width must be a power of 2",
              "GXGetTexBufferSize");
    }
    iVar1 = countLeadingZeros(param2 & 0xffff);
    if ((param2 & 0xffff) != 1 << 0x1f - iVar1) {
                    
      OSPanic("GXTexture.c",0x1aa,"%s: height must be a power of 2",
              "GXGetTexBufferSize");
    }
    iVar1 = 0;
    uVar2 = 0;
    while ((uVar2 < param5 &&
           ((iVar1 = iVar1 + iVar3 * ((int)((param1 & 0xffff) + (1 << local_30[0]) + -1) >>
                                     (local_30[0] & 0x3f)) *
                                     ((int)((param2 & 0xffff) + (1 << local_34) + -1) >>
                                     (local_34 & 0x3f)), (param1 & 0xffff) != 1 ||
            ((param2 & 0xffff) != 1))))) {
      if ((param1 & 0xffff) < 2) {
        param1 = 1;
      }
      else {
        param1 = param1 >> 1 & 0x7fff;
      }
      if ((param2 & 0xffff) < 2) {
        param2 = 1;
      }
      else {
        param2 = param2 >> 1 & 0x7fff;
      }
      uVar2 = uVar2 + 1;
    }
  }
  else {
    iVar1 = iVar3 * ((int)((param1 & 0xffff) + (1 << local_30[0]) + -1) >> (local_30[0] & 0x3f)) *
                    ((int)((param2 & 0xffff) + (1 << local_34) + -1) >> (local_34 & 0x3f));
  }
  return iVar1;
}


/* Library Function - Single Match
    GXInitTexObj
   
   Library: KioskDefault 0 0 */

void GXInitTexObj(uint *param1,uint param2,ushort param3,ushort param4,uint param5,uint param6,
                 uint param7,char param8) { //80025C78
  int iVar1;
  int iVar2;
  
  if (param1 == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x1fd,"Texture Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x1ff,"'GXInitTexObj' is not allowed between GXBegin/GXEnd");
  }
  if (0x400 < param3) {
                    
    OSPanic("GXTexture.c",0x200,"%s: width too large","GXInitTexObj");
  }
  if (0x400 < param4) {
                    
    OSPanic("GXTexture.c",0x201,"%s: height too large","GXInitTexObj");
  }
  if ((param5 & 0x20) != 0) {
                    
    OSPanic("GXTexture.c",0x203,"%s: invalid texture format",
            "GXInitTexObj");
  }
  if (((param6 != 0) || (param8 != '\0')) &&
     (iVar1 = countLeadingZeros((uint)param3), (uint)param3 != 1 << 0x1f - iVar1)) {
                    
    OSPanic("GXTexture.c",0x20d,"%s: width must be a power of 2",
            "GXInitTexObj");
  }
  if (((param7 != 0) || (param8 != '\0')) &&
     (iVar1 = countLeadingZeros((uint)param4), (uint)param4 != 1 << 0x1f - iVar1)) {
                    
    OSPanic("GXTexture.c",0x212,"%s: height must be a power of 2",
            "GXInitTexObj");
  }
  memset_(param1,0,0x20);
  if ((param6 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTexture.c",0x220,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xfffffffc | param6;
  if ((param7 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTexture.c",0x221,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xfffffff3 | param7 << 2;
  *param1 = *param1 & 0xffffffef | 0x10;
  if (param8 == '\0') {
    *param1 = *param1 & 0xffffff1f | 0x80;
  }
  else {
    *(byte *)((int)param1 + 0x1f) = *(byte *)((int)param1 + 0x1f) | 1;
    *param1 = *param1 & 0xffffff1f | 0xc0;
    if (param4 < param3) {
      iVar1 = countLeadingZeros((uint)param3);
    }
    else {
      iVar1 = countLeadingZeros((uint)param4);
    }
    if (false) {
                    
      OSPanic("GXTexture.c",0x234,"GX Internal: Register field out of range");
    }
    param1[1] = ((int)((float)((double)CONCAT44(0x43300000,0x1f - iVar1) - 4503599627370496.0) *
                      16.0) & 0xffU) << 8 | param1[1] & 0xffff00ff;
  }
  param1[5] = param5;
  if ((param3 - 1 & 0xfffffc00) != 0) {
                    
    OSPanic("GXTexture.c",0x240,"GX Internal: Register field out of range");
  }
  param1[2] = param1[2] & 0xfffffc00 | param3 - 1;
  if ((param4 - 1 & 0xfffffc00) != 0) {
                    
    OSPanic("GXTexture.c",0x241,"GX Internal: Register field out of range");
  }
  param1[2] = param1[2] & 0xfff003ff | (param4 - 1) * 0x400;
  if (false) {
                    
    OSPanic("GXTexture.c",0x242,"GX Internal: Register field out of range");
  }
  param1[2] = (param5 & 0xf) << 0x14 | param1[2] & 0xff0fffff;
  if ((param2 & 0x1f) != 0) {
                    
    OSPanic("GXTexture.c",0x248,"%s: %s pointer not aligned to 32B",
            "GXInitTexObj","image");
  }
  if ((param2 >> 5 & 0x1e00000) != 0) {
                    
    OSPanic("GXTexture.c",0x24a,"GX Internal: Register field out of range");
  }
  param1[3] = param1[3] & 0xffe00000 | param2 >> 5 & 0x1ffffff;
  if (false) {
switchD_8002605c_caseD_7:
                    
    OSPanic("GXTexture.c",0x275,"%s: invalid texture format",
            "GXPreLoadEntireTexture");
  }
                    /* {@symbol 80026060} */
  switch(param5 & 0xf) {
  case 0:
  case 8:
    *(undefined *)((int)param1 + 0x1e) = 1;
    iVar2 = 3;
    iVar1 = 3;
    break;
  case 1:
  case 2:
  case 9:
    *(undefined *)((int)param1 + 0x1e) = 2;
    iVar2 = 3;
    iVar1 = 2;
    break;
  case 3:
  case 4:
  case 5:
  case 10:
    *(undefined *)((int)param1 + 0x1e) = 2;
    iVar2 = 2;
    iVar1 = 2;
    break;
  case 6:
    *(undefined *)((int)param1 + 0x1e) = 3;
    iVar2 = 2;
    iVar1 = 2;
    break;
  default:
    goto switchD_8002605c_caseD_7;
  case 0xe:
    *(undefined *)((int)param1 + 0x1e) = 0;
    iVar2 = 3;
    iVar1 = 3;
  }
  *(ushort *)(param1 + 7) =
       (short)((int)((uint)param3 + (1 << iVar2) + -1) >> iVar2) *
       (short)((int)((uint)param4 + (1 << iVar1) + -1) >> iVar1) & 0x7fff;
  *(byte *)((int)param1 + 0x1f) = *(byte *)((int)param1 + 0x1f) | 2;
  return;
}


/* Library Function - Single Match
    GXInitTexObjLOD
   
   Library: KioskDefault 0 0 */

void GXInitTexObjLOD(double param1,double param2,double param3,uint *texObj,uint min_filt,int param6
                    ,uint param7,uint param8,uint param9) { //80026158
  _savefpr_29();
  if (texObj == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x2c2,"Texture Object Pointer is null");
  }
  if (isInGxBegin != false) {
                    
    OSPanic("GXTexture.c",0x2c4,"'GXInitTexObjLOD' is not allowed between GXBegin/GXEnd");
  }
  if (-4.0 <= param3) {
    if (4.0 <= param3) {
      param3 = 3.990000009536743;
    }
  }
  else {
    param3 = -4.0;
  }
  if (false) {
                    
    OSPanic("GXTexture.c",0x2ce,"GX Internal: Register field out of range");
  }
  *texObj = ((int)(param3 * 32.0) & 0xffU) << 9 | *texObj & 0xfffe01ff;
  if (false) {
                    
    OSPanic("GXTexture.c",0x2cf,"GX Internal: Register field out of range");
  }
  *texObj = *texObj & 0xffffffef | (uint)(param6 == 1) << 4;
  if (5 < min_filt) {
                    
    OSPanic("GXTexture.c",0x2d1,"GXInitTexObjLOD: invalid min_filt value");
  }
  if (((&DAT_803968b8)[min_filt] & 0xf8) != 0) {
                    
    OSPanic("GXTexture.c",0x2d2,"GX Internal: Register field out of range");
  }
  *texObj = *texObj & 0xffffff1f | (uint)(byte)(&DAT_803968b8)[min_filt] << 5;
  if (false) {
                    
    OSPanic("GXTexture.c",0x2d3,"GX Internal: Register field out of range");
  }
  *texObj = *texObj & 0xfffffeff | (uint)((param8 & 0xff) == 0) << 8;
  *texObj = *texObj & 0xfffdffff;
  *texObj = *texObj & 0xfffbffff;
  if ((param9 & 0xfffffffc) != 0) {
                    
    OSPanic("GXTexture.c",0x2d6,"GX Internal: Register field out of range");
  }
  *texObj = *texObj & 0xffe7ffff | param9 << 0x13;
  if ((param7 & 0xfe) == 0) {
    *texObj = *texObj & 0xffdfffff | (param7 & 0xff) << 0x15;
    if (0.0 <= param1) {
      if (10.0 < param1) {
        param1 = 10.0;
      }
    }
    else {
      param1 = 0.0;
    }
    if (0.0 <= param2) {
      if (10.0 < param2) {
        param2 = 10.0;
      }
    }
    else {
      param2 = 0.0;
    }
    if (false) {
                    
      OSPanic("GXTexture.c",0x2e5,"GX Internal: Register field out of range");
    }
    texObj[1] = texObj[1] & 0xffffff00 | (int)(param1 * 16.0) & 0xffU;
    if (false) {
                    
      OSPanic("GXTexture.c",0x2e6,"GX Internal: Register field out of range");
    }
    texObj[1] = ((int)(param2 * 16.0) & 0xffU) << 8 | texObj[1] & 0xffff00ff;
    _restfpr_29();
    return;
  }
                    
  OSPanic("GXTexture.c",0x2d7,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXInitTexObjUserData
   
   Library: KioskDefault 0 0 */

void GXInitTexObjUserData(int param1,undefined4 param2) { //800264B8
  if (param1 == 0) {
                    
    OSPanic("GXTexture.c",0x33e,"Texture Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x33f,"'GXInitTexObjUserData' is not allowed between GXBegin/GXEnd");
  }
  *(undefined4 *)(param1 + 0x10) = param2;
  return;
}


/* Library Function - Single Match
    gxTextureFn_80026534
   
   Library: KioskDefault 0 0 */

int textureGetWidth(int param1) { //80026534
  if (param1 == 0) {
                    
    OSPanic("GXTexture.c",0x36c,"Texture Object Pointer is null");
  }
  return (*(uint *)(param1 + 8) & 0x3ff) + 1;
}


/* Library Function - Single Match
    gxTextureFn_80026590
   
   Library: KioskDefault 0 0 */

int textureGetHeight(int param1) { //80026590
  if (param1 == 0) {
                    
    OSPanic("GXTexture.c",0x372,"Texture Object Pointer is null");
  }
  return (*(uint *)(param1 + 8) >> 10 & 0x3ff) + 1;
}


/* Library Function - Single Match
    gxTextureFn_800265ec
   
   Library: KioskDefault 0 0 */

GXTexFmt GXGetTexObjFmt(GXTexObj *param1) { //800265EC
  if (param1 == (GXTexObj *)0x0) {
                    
    OSPanic("GXTexture.c",0x378,"Texture Object Pointer is null");
  }
  return param1->dummy[5];
}


/* Library Function - Single Match
    GXLoadTexObjPreLoaded
   
   Library: KioskDefault 0 0 */

void GXLoadTexObjPreLoaded(GxTexObj *texObj,uint *texRegion,int mapId) { //80026640
  int iVar1;
  
  if (texObj == (GxTexObj *)0x0) {
                    
    OSPanic("GXTexture.c",0x3fe,"Texture Object Pointer is null");
  }
  if (texRegion == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x3fe,"TexRegion Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x400,"'GXLoadTexObjPreLoaded' is not allowed between GXBegin/GXEnd");
  }
  if (7 < mapId) {
                    
    OSPanic("GXTexture.c",0x401,"%s: invalid texture map ID",
            "GXLoadTexObj");
  }
  if (false) {
                    
    OSPanic("GXTexture.c",0x403,"GX Internal: Register field out of range");
  }
  texObj->field0_0x0 = texObj->field0_0x0 & 0xffffff | (uint)u8_ARRAY_80396880[mapId] << 0x18;
  if (false) {
                    
    OSPanic("GXTexture.c",0x404,"GX Internal: Register field out of range");
  }
  texObj->field1_0x4 = texObj->field1_0x4 & 0xffffff | (uint)u8_ARRAY_80396888[mapId] << 0x18;
  if (false) {
                    
    OSPanic("GXTexture.c",0x405,"GX Internal: Register field out of range");
  }
  texObj->field2_0x8 = texObj->field2_0x8 & 0xffffff | (uint)u8_ARRAY_80396890[mapId] << 0x18;
  if (false) {
                    
    OSPanic("GXTexture.c",0x406,"GX Internal: Register field out of range");
  }
  *texRegion = *texRegion & 0xffffff | (uint)u8_ARRAY_80396898[mapId] << 0x18;
  if (false) {
                    
    OSPanic("GXTexture.c",0x407,"GX Internal: Register field out of range");
  }
  texRegion[1] = texRegion[1] & 0xffffff | (uint)u8_ARRAY_803968a0[mapId] << 0x18;
  if (false) {
                    
    OSPanic("GXTexture.c",0x408,"GX Internal: Register field out of range");
  }
  texObj->field3_0xc = texObj->field3_0xc & 0xffffff | (uint)u8_ARRAY_803968a8[mapId] << 0x18;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = texObj->field0_0x0;
  *(uint *)(pGxDebug->isRegInit + (texObj->field0_0x0 >> 0x16 & 0x3fc) + 0xc00) = texObj->field0_0x0
  ;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = texObj->field1_0x4;
  *(uint *)(pGxDebug->isRegInit + (texObj->field1_0x4 >> 0x16 & 0x3fc) + 0xc00) = texObj->field1_0x4
  ;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = texObj->field2_0x8;
  *(uint *)(pGxDebug->isRegInit + (texObj->field2_0x8 >> 0x16 & 0x3fc) + 0xc00) = texObj->field2_0x8
  ;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *texRegion;
  *(uint *)(pGxDebug->isRegInit + (*texRegion >> 0x16 & 0x3fc) + 0xc00) = *texRegion;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = texRegion[1];
  *(uint *)(pGxDebug->isRegInit + (texRegion[1] >> 0x16 & 0x3fc) + 0xc00) = texRegion[1];
  GXFIFO._0_1_ = 0x61;
  GXFIFO = texObj->field3_0xc;
  *(uint *)(pGxDebug->isRegInit + (texObj->field3_0xc >> 0x16 & 0x3fc) + 0xc00) = texObj->field3_0xc
  ;
  if ((texObj->field16_0x1f & 2) == 0) {
    if (gx->field1013_0x414 == (undefined *)0x0) {
                    
      OSPanic("GXTexture.c",0x413,"%s: Tex/Tlut Region Callback not set",
              "GXLoadTexObj/PreLoaded");
    }
                    /* {@symbol 8001b0dc} */
    iVar1 = (*(code *)gx->field1013_0x414)(texObj->field12_0x18);
    if (iVar1 == 0) {
                    
      OSPanic("GXTexture.c",0x415,"%s: Tex/Tlut Region Callback returns NULL",
              "GXLoadTexObj/PreLoaded");
    }
    if (false) {
                    
      OSPanic("GXTexture.c",0x417,"GX Internal: Register field out of range");
    }
    *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xffffff | (uint)u8_ARRAY_803968b0[mapId] << 0x18;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)(iVar1 + 4) >> 0x16 & 0x3fc) + 0xc00) =
         *(undefined4 *)(iVar1 + 4);
  }
  gx->field1082_0x45c[mapId] = texObj->field2_0x8;
  gx->field1083_0x47c[mapId] = texObj->field0_0x0;
  gx->flags4F0 = gx->flags4F0 | 1;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXLoadTexObj
   
   Library: KioskDefault 0 0 */

void GXLoadTexObj(GxTexObj *texObj,int mapId) { //80026A9C
  uint *texRegion;
  
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x432,"'GXLoadTexObj' is not allowed between GXBegin/GXEnd");
  }
  if (7 < mapId) {
                    
    OSPanic("GXTexture.c",0x433,"%s: invalid texture map ID",
            "GXLoadTexObj");
  }
  if (gx->tlutRegionCallback == (undefined *)0x0) {
                    
    OSPanic("GXTexture.c",0x438,"%s: Tex/Tlut Region Callback not set",
            "GXLoadTexObj");
  }
                    /* {@symbol 8001b044} */
  texRegion = (uint *)(*(code *)gx->tlutRegionCallback)(texObj,mapId);
  if (texRegion == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x43a,"%s: Tex/Tlut Region Callback returns NULL",
            "GXLoadTexObj");
  }
  GXLoadTexObjPreLoaded(texObj,texRegion,mapId);
  return;
}


/* Library Function - Single Match
    GXInitTexCacheRegion
   
   Library: KioskDefault 0 0 */

void GXInitTexCacheRegion
               (uint *param1,undefined param2,uint param3,int param4,uint param5,int param6) { //80026B84
  int iVar1;
  
  if (param1 == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x4d8,"TexRegion Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x4da,"'GXInitTexCacheRegion' is not allowed between GXBegin/GXEnd");
  }
  if ((param3 & 0x1f) != 0) {
                    
    OSPanic("GXTexture.c",0x4dc,"%s: %s pointer not aligned to 32B",
            "GXInitTexCacheRegion","tmem even");
  }
  if ((param5 & 0x1f) != 0) {
                    
    OSPanic("GXTexture.c",0x4de,"%s: %s pointer not aligned to 32B",
            "GXInitTexCacheRegion","tmem odd");
  }
  if (param4 == 1) {
    iVar1 = 4;
  }
  else if (param4 < 1) {
    if (param4 < 0) {
LAB_80026c7c:
                    
      OSPanic("GXTexture.c",0x4e6,"%s: Invalid %s size",
              "GXInitTexCacheRegion","tmem even");
    }
    iVar1 = 3;
  }
  else {
    if (2 < param4) goto LAB_80026c7c;
    iVar1 = 5;
  }
  *param1 = 0;
  if ((param3 >> 5 & 0x7ff8000) != 0) {
                    
    OSPanic("GXTexture.c",0x4eb,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xffff8000 | param3 >> 5;
  if (false) {
                    
    OSPanic("GXTexture.c",0x4ec,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xfffc7fff | iVar1 << 0xf;
  if (false) {
                    
    OSPanic("GXTexture.c",0x4ed,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xffe3ffff | iVar1 << 0x12;
  *param1 = *param1 & 0xffdfffff;
  if (param6 == 2) {
    iVar1 = 5;
  }
  else if (param6 < 2) {
    if (param6 == 0) {
      iVar1 = 3;
    }
    else {
      if (param6 < 0) goto LAB_80026d88;
      iVar1 = 4;
    }
  }
  else {
    if (3 < param6) {
LAB_80026d88:
                    
      OSPanic("GXTexture.c",0x4f6,"%s: Invalid %s size",
              "GXInitTexCacheRegion","tmem odd");
    }
    iVar1 = 0;
  }
  param1[1] = 0;
  if ((param5 >> 5 & 0x7ff8000) != 0) {
                    
    OSPanic("GXTexture.c",0x4fb,"GX Internal: Register field out of range");
  }
  param1[1] = param1[1] & 0xffff8000 | param5 >> 5;
  if (true) {
    param1[1] = param1[1] & 0xfffc7fff | iVar1 << 0xf;
    if (true) {
      param1[1] = param1[1] & 0xffe3ffff | iVar1 << 0x12;
      *(undefined *)(param1 + 3) = param2;
      *(undefined *)((int)param1 + 0xd) = 1;
      return;
    }
                    
    OSPanic("GXTexture.c",0x4fd,"GX Internal: Register field out of range");
  }
                    
  OSPanic("GXTexture.c",0x4fc,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXInitTexPreLoadRegion
   
   Library: KioskDefault 0 0 */

void GXInitTexPreLoadRegion(uint *param1,uint param2,uint param3,uint param4,uint param5) { //80026E60
  if (param1 == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x51a,"TexRegion Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x51c,"'GXInitTexPreLoadRegion' is not allowed between GXBegin/GXEnd");
  }
  if ((param2 & 0x1f) != 0) {
                    
    OSPanic("GXTexture.c",0x51e,"%s: %s pointer not aligned to 32B",
            "GXInitTexPreLoadRegion","tmem even");
  }
  if ((param4 & 0x1f) != 0) {
                    
    OSPanic("GXTexture.c",0x520,"%s: %s pointer not aligned to 32B",
            "GXInitTexPreLoadRegion","tmem odd");
  }
  if ((param3 & 0x1f) != 0) {
                    
    OSPanic("GXTexture.c",0x522,"%s: %s pointer not aligned to 32B",
            "GXInitTexPreLoadRegion","size even");
  }
  if ((param5 & 0x1f) != 0) {
                    
    OSPanic("GXTexture.c",0x524,"%s: %s pointer not aligned to 32B",
            "GXInitTexPreLoadRegion","size odd");
  }
  *param1 = 0;
  if ((param2 >> 5 & 0x7ff8000) != 0) {
                    
    OSPanic("GXTexture.c",0x528,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xffff8000 | param2 >> 5;
  *param1 = *param1 & 0xfffc7fff;
  *param1 = *param1 & 0xffe3ffff;
  *param1 = *param1 & 0xffdfffff | 0x200000;
  param1[1] = 0;
  if ((param4 >> 5 & 0x7ff8000) != 0) {
                    
    OSPanic("GXTexture.c",0x52e,"GX Internal: Register field out of range");
  }
  param1[1] = param1[1] & 0xffff8000 | param4 >> 5;
  param1[1] = param1[1] & 0xfffc7fff;
  param1[1] = param1[1] & 0xffe3ffff;
  *(undefined *)(param1 + 3) = 0;
  *(undefined *)((int)param1 + 0xd) = 0;
  *(short *)(param1 + 2) = (short)(param3 >> 5);
  *(short *)((int)param1 + 10) = (short)(param5 >> 5);
  return;
}


/* Library Function - Single Match
    gxTexRegionFn_80027040
   
   Library: KioskDefault 0 0 */

void gxTexRegionFn_80027040
               (uint *param1,undefined *param2,undefined *param3,int *param4,int *param5,int *param6
               ,int *param7) { //80027040
  uint uVar1;
  
  if (param1 == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x54d,"TexRegion Object Pointer is null");
  }
  *param4 = (*param1 & 0x7fff) << 5;
  *param6 = (param1[1] & 0x7fff) << 5;
  if (*(char *)((int)param1 + 0xd) == '\0') {
    *param5 = (uint)*(ushort *)(param1 + 2) << 5;
    *param7 = (uint)*(ushort *)((int)param1 + 10) << 5;
    goto LAB_80027194;
  }
  uVar1 = *param1 >> 0xf & 7;
  if (uVar1 == 4) {
    *param5 = 0x20000;
  }
  else if (uVar1 < 4) {
    if (uVar1 < 3) {
LAB_80027114:
      *param5 = 0;
    }
    else {
      *param5 = 0x8000;
    }
  }
  else {
    if (5 < uVar1) goto LAB_80027114;
    *param5 = 0x80000;
  }
  uVar1 = param1[1] >> 0xf & 7;
  if (uVar1 == 4) {
    *param7 = 0x20000;
  }
  else {
    if (uVar1 < 4) {
      if (2 < uVar1) {
        *param7 = 0x8000;
        goto LAB_80027194;
      }
    }
    else if (uVar1 < 6) {
      *param7 = 0x80000;
      goto LAB_80027194;
    }
    *param7 = 0;
  }
LAB_80027194:
  *param3 = *(undefined *)(param1 + 3);
  *param2 = *(undefined *)((int)param1 + 0xd);
  return;
}


/* Library Function - Single Match
    GXInitTlutRegion
   
   Library: KioskDefault 0 0 */

void GXInitTlutRegion(uint *param1,uint param2,uint param3) { //800271C0
  if (param1 == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x580,"TLutRegion Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x582,"'GXInitTlutRegion' is not allowed between GXBegin/GXEnd");
  }
  if ((param2 & 0x1ff) != 0) {
                    
    OSPanic("GXTexture.c",0x583,"%s: tmem pointer is not aligned to 512B",
            "GXInitTlutRegion");
  }
  if (0x400 < (int)param3) {
                    
    OSPanic("GXTexture.c",0x584,"%s: tlut size exceeds 16K",
            "GXInitTlutRegion");
  }
  *param1 = 0;
  if ((param2 - 0x80000 >> 9 & 0x7ffc00) != 0) {
                    
    OSPanic("GXTexture.c",0x588,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xfffffc00 | param2 - 0x80000 >> 9;
  if ((param3 & 0xfffff800) != 0) {
                    
    OSPanic("GXTexture.c",0x589,"GX Internal: Register field out of range");
  }
  *param1 = *param1 & 0xffe003ff | param3 << 10;
  *param1 = *param1 & 0xffffff | 0x65000000;
  return;
}


/* Library Function - Single Match
    GXInvalidateTexAll
   
   Library: KioskDefault 0 0 */

void GXInvalidateTexAll(void) { //800272F4
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x5e7,"'GXInvalidateTexAll' is not allowed between GXBegin/GXEnd");
  }
  gxFn_80028f60();
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0x66001000;
  *(undefined4 *)(pGxDebug->isRegInit + 0xd98) = 0x66001000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0x66001100;
  *(undefined4 *)(pGxDebug->isRegInit + 0xd98) = 0x66001100;
  gxFn_80028f60();
  return;
}


/* Library Function - Single Match
    GXPreLoadEntireTexture
   
   Library: KioskDefault 0 0 */

void GXPreLoadEntireTexture(int param1,uint *param2) { //800273F0
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uStack_60;
  int local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  char local_44;
  char local_43;
  
  if (param1 == 0) {
                    
    OSPanic("GXTexture.c",0x628,"Texture Object Pointer is null");
  }
  if (param2 == (uint *)0x0) {
                    
    OSPanic("GXTexture.c",0x628,"TexRegion Object Pointer is null");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXTexture.c",0x62a,"'GXPreLoadEntireTexture' is not allowed between GXBegin/GXEnd");
  }
  uVar4 = countLeadingZeros(1 - (*(byte *)(param1 + 0x1f) & 1));
  local_43 = (char)(uVar4 >> 5);
  uVar4 = countLeadingZeros(6 - (*(uint *)(param1 + 8) >> 0x14 & 0xf));
  local_44 = (char)(uVar4 >> 5);
  uVar4 = *(uint *)(param1 + 0xc) & 0x1fffff;
  if (false) {
                    
    OSPanic("GXTexture.c",0x633,"GX Internal: Register field out of range");
  }
  uVar12 = uVar4 | 0x60000000;
  uVar1 = *param2;
  if (false) {
                    
    OSPanic("GXTexture.c",0x639,"GX Internal: Register field out of range");
  }
  uVar11 = uVar1 & 0x7fff | 0x61000000;
  uVar2 = param2[1];
  if (false) {
                    
    OSPanic("GXTexture.c",0x63f,"GX Internal: Register field out of range");
  }
  uVar10 = uVar2 & 0x7fff | 0x62000000;
  if ((*(ushort *)(param1 + 0x1c) & 0x8000) != 0) {
                    
    OSPanic("GXTexture.c",0x644,"GX Internal: Register field out of range");
  }
  if ((*(byte *)(param1 + 0x1e) & 0xfc) == 0) {
    uVar14 = *(ushort *)(param1 + 0x1c) & 0xfffe7fff | 0x63000000 |
             (uint)*(byte *)(param1 + 0x1e) << 0xf;
    uVar6 = 0;
    uVar9 = (uint)*(ushort *)(param1 + 0x1c);
    if (local_43 == '\0') {
      uVar7 = uVar9;
      uVar8 = uVar9;
      if (uVar9 == 0) {
        uVar7 = 1;
        uVar8 = 1;
      }
    }
    else {
      local_48 = (*(uint *)(param1 + 8) & 0x3ff) + 1;
      local_4c = (*(uint *)(param1 + 8) >> 10 & 0x3ff) + 1;
      if (local_4c < local_48) {
        iVar3 = countLeadingZeros(local_48);
      }
      else {
        iVar3 = countLeadingZeros(local_4c);
      }
      uVar6 = 0x1fU - iVar3 & 0xffff;
      uVar8 = 0;
      uVar7 = 0;
      uVar5 = uVar9;
      for (uVar13 = 0; uVar13 < uVar6; uVar13 = uVar13 + 1) {
        if ((uVar13 & 1) == 0) {
          if (uVar5 == 0) {
            uVar5 = 1;
          }
          uVar8 = uVar8 + uVar5;
        }
        else {
          if (uVar5 == 0) {
            uVar5 = 1;
          }
          uVar7 = uVar7 + uVar5;
        }
        FUN_80025ba0(*(int *)(param1 + 0x14),(ushort)(local_48 >> uVar13 + 1),
                     (ushort)(local_4c >> uVar13 + 1),&local_58,&local_5c,&uStack_60);
        uVar5 = local_58 * local_5c;
      }
    }
    if (local_44 == '\0') {
      if (local_43 == '\0') {
        if (*(ushort *)((int)param2 + 10) < *(ushort *)(param2 + 2)) {
          if (*(ushort *)(param2 + 2) < uVar8) {
                    
            OSPanic("GXTexture.c",0x67e,"GXPreLoadEntireTexture: Even tmem size does not match the texture size");
          }
        }
        else if (*(ushort *)((int)param2 + 10) < uVar7) {
                    
          OSPanic("GXTexture.c",0x680,"GXPreLoadEntireTexture: Odd tmem size does not match the texture size");
        }
      }
      else if (*(ushort *)((int)param2 + 10) < *(ushort *)(param2 + 2)) {
        if (*(ushort *)(param2 + 2) < uVar8) {
                    
          OSPanic("GXTexture.c",0x674,"GXPreLoadEntireTexture: Even tmem size does not match the texture size");
        }
        if (*(ushort *)((int)param2 + 10) < uVar7) {
                    
          OSPanic("GXTexture.c",0x675,"GXPreLoadEntireTexture: Odd tmem size does not match the texture size");
        }
      }
      else {
        if (*(ushort *)((int)param2 + 10) < uVar8) {
                    
          OSPanic("GXTexture.c",0x678,"GXPreLoadEntireTexture: Odd tmem size does not match the texture size");
        }
        if (*(ushort *)(param2 + 2) < uVar7) {
                    
          OSPanic("GXTexture.c",0x679,"GXPreLoadEntireTexture: Even tmem size does not match the texture size");
        }
      }
    }
    else {
      if (local_43 == '\0') {
        uVar7 = 0;
      }
      if ((uint)*(ushort *)(param2 + 2) < uVar8 + uVar7) {
                    
        OSPanic("GXTexture.c",0x66e,"GXPreLoadEntireTexture: Even tmem size does not match the texture size");
      }
      if ((uint)*(ushort *)((int)param2 + 10) < uVar8 + uVar7) {
                    
        OSPanic("GXTexture.c",0x66f,"GXPreLoadEntireTexture: Odd tmem size does not match the texture size");
      }
    }
    gxFn_80028f60();
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar12;
    *(uint *)(pGxDebug->isRegInit + 0xd80) = uVar12;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar11;
    *(uint *)(pGxDebug->isRegInit + 0xd84) = uVar11;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar10;
    *(uint *)(pGxDebug->isRegInit + 0xd88) = uVar10;
    GXFIFO._0_1_ = 0x61;
    GXFIFO = uVar14;
    *(uint *)(pGxDebug->isRegInit + 0xd8c) = uVar14;
    if (uVar6 != 0) {
      local_54 = uVar2 & 0x7fff;
      local_50 = uVar1 & 0x7fff;
      for (uVar7 = 0; uVar7 < uVar6; uVar7 = uVar7 + 1) {
        if (local_44 == '\0') {
          uVar4 = uVar4 + uVar9;
          if ((uVar7 & 1) == 0) {
            local_50 = local_50 + uVar9;
          }
          else {
            local_54 = local_54 + uVar9;
          }
        }
        else {
          uVar4 = uVar4 + uVar9 * 2;
          local_50 = local_50 + uVar9;
          local_54 = local_54 + uVar9;
        }
        uVar1 = local_54;
        if ((uVar7 & 1) != 0) {
          uVar1 = local_50;
        }
        uVar2 = local_50;
        if ((uVar7 & 1) != 0) {
          uVar2 = local_54;
        }
        FUN_80025ba0(*(int *)(param1 + 0x14),(ushort)(local_48 >> uVar7 + 1),
                     (ushort)(local_4c >> uVar7 + 1),&local_58,&local_5c,&uStack_60);
        uVar9 = local_58 * local_5c;
        if ((uVar4 & 0xffe00000) != 0) {
                    
          OSPanic("GXTexture.c",0x6b1,"GX Internal: Register field out of range");
        }
        uVar12 = uVar12 & 0xffe00000 | uVar4;
        if ((uVar1 & 0xffff8000) != 0) {
                    
          OSPanic("GXTexture.c",0x6b2,"GX Internal: Register field out of range");
        }
        uVar11 = uVar11 & 0xffff8000 | uVar1;
        if ((uVar2 & 0xffff8000) != 0) {
                    
          OSPanic("GXTexture.c",0x6b3,"GX Internal: Register field out of range");
        }
        uVar10 = uVar10 & 0xffff8000 | uVar2;
        if ((uVar9 & 0xffff8000) != 0) {
                    
          OSPanic("GXTexture.c",0x6b4,"GX Internal: Register field out of range");
        }
        uVar14 = uVar14 & 0xffff8000 | uVar9;
        GXFIFO._0_1_ = 0x61;
        GXFIFO = uVar12;
        *(uint *)(pGxDebug->isRegInit + (uVar12 >> 0x16 & 0x3fc) + 0xc00) = uVar12;
        GXFIFO._0_1_ = 0x61;
        GXFIFO = uVar11;
        *(uint *)(pGxDebug->isRegInit + (uVar11 >> 0x16 & 0x3fc) + 0xc00) = uVar11;
        GXFIFO._0_1_ = 0x61;
        GXFIFO = uVar10;
        *(uint *)(pGxDebug->isRegInit + (uVar10 >> 0x16 & 0x3fc) + 0xc00) = uVar10;
        GXFIFO._0_1_ = 0x61;
        GXFIFO = uVar14;
        *(uint *)(pGxDebug->isRegInit + (uVar14 >> 0x16 & 0x3fc) + 0xc00) = uVar14;
      }
    }
    gxFn_80028f60();
    return;
  }
                    
  OSPanic("GXTexture.c",0x645,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    gxTextureFn_80027ae0
   
   Library: KioskDefault 0 0 */

void gxTextureFn_80027ae0(int param1,int param2) { //80027AE0
  uint uVar1;
  uint uVar2;
  
  uVar1 = gx->field1082_0x45c[param1];
  if (false) {
                    
    OSPanic("GXTexture.c",0x735,"GX Internal: Register field out of range");
  }
  *(uint *)(&gx->field_0xb8 + param2 * 4) =
       *(uint *)(&gx->field_0xb8 + param2 * 4) & 0xffff0000 | gx->field1082_0x45c[param1] & 0x3ff;
  if (false) {
                    
    OSPanic("GXTexture.c",0x736,"GX Internal: Register field out of range");
  }
  *(uint *)(&gx->field_0xd8 + param2 * 4) =
       *(uint *)(&gx->field_0xd8 + param2 * 4) & 0xffff0000 | uVar1 >> 10 & 0x3ff;
  uVar1 = countLeadingZeros(1 - (gx->field1083_0x47c[param1] & 3));
  uVar2 = countLeadingZeros(1 - ((uint)gx->field1083_0x47c[param1] >> 2 & 3));
  if ((uVar1 >> 5 & 0xfe) != 0) {
                    
    OSPanic("GXTexture.c",0x73c,"GX Internal: Register field out of range");
  }
  *(uint *)(&gx->field_0xb8 + param2 * 4) =
       *(uint *)(&gx->field_0xb8 + param2 * 4) & 0xfffeffff | (uVar1 >> 5 & 0xff) << 0x10;
  if ((uVar2 >> 5 & 0xfe) != 0) {
                    
    OSPanic("GXTexture.c",0x73d,"GX Internal: Register field out of range");
  }
  *(uint *)(&gx->field_0xd8 + param2 * 4) =
       *(uint *)(&gx->field_0xd8 + param2 * 4) & 0xfffeffff | (uVar2 >> 5 & 0xff) << 0x10;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)(&gx->field_0xb8 + param2 * 4);
  *(undefined4 *)
   (pGxDebug->isRegInit + (*(uint *)(&gx->field_0xb8 + param2 * 4) >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)(&gx->field_0xb8 + param2 * 4);
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)(&gx->field_0xd8 + param2 * 4);
  *(undefined4 *)
   (pGxDebug->isRegInit + (*(uint *)(&gx->field_0xd8 + param2 * 4) >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)(&gx->field_0xd8 + param2 * 4);
  gx->field2_0x2 = 1;
  return;
}

