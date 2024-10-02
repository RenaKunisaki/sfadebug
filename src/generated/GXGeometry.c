
/* Library Function - Single Match
    GXBegin
   
   Library: KioskDefault 0 0 */

void GXBegin(GXOpcode op,int format,u16 nVtxs) { //80020558
  int iVar1;
  
  if (7 < format) {
                    
    OSPanic("GXGeometry.c",0x157,"GXBegin: Format Index is out of range");
  }
  if (isInGxBegin) {
                    
    OSPanic("GXGeometry.c",0x158,"GXBegin: called inside another GXBegin/GXEnd");
  }
  if (gx->flags4F0 != 0) {
    __GXSetDirtyState();
  }
  if (gx->isDlistInProgress == false) {
    _gxValidateState(format);
  }
  isInGxBegin = true;
  iVar1._0_1_ = gx->needBegin;
  iVar1._1_1_ = gx->field_0x1;
  iVar1._2_2_ = gx->field2_0x2;
  if (iVar1 != 0) {
    _gxBegin();
  }
  GXFIFO._0_1_ = (byte)format | op;
  GXFIFO._0_2_ = nVtxs;
  return;
}


/* Library Function - Single Match
    GXSetLineWidth
   
   Library: KioskDefault 0 0 */

void GXSetLineWidth(uint param1,uint param2) { //800206A0
  if (isInGxBegin) {
                    
    OSPanic("GXGeometry.c",0x1a8,"'GXSetLineWidth' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXGeometry.c",0x1a9,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x7c = *(uint *)&gx->field_0x7c & 0xffffff00 | param1 & 0xff;
  if ((param2 & 0xfffffff8) != 0) {
                    
    OSPanic("GXGeometry.c",0x1aa,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x7c = *(uint *)&gx->field_0x7c & 0xfff8ffff | param2 << 0x10;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x7c;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x7c >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x7c;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetPointSize
   
   Library: KioskDefault 0 0 */

void GXSetPointSize(uint param1,uint param2) { //800207AC
  if (isInGxBegin) {
                    
    OSPanic("GXGeometry.c",0x1d4,"'GXSetPointSize' is not allowed between GXBegin/GXEnd");
  }
  if (false) {
                    
    OSPanic("GXGeometry.c",0x1d5,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x7c = (param1 & 0xff) << 8 | *(uint *)&gx->field_0x7c & 0xffff00ff;
  if ((param2 & 0xfffffff8) != 0) {
                    
    OSPanic("GXGeometry.c",0x1d6,"GX Internal: Register field out of range");
  }
  *(uint *)&gx->field_0x7c = *(uint *)&gx->field_0x7c & 0xffc7ffff | param2 << 0x13;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)&gx->field_0x7c;
  *(undefined4 *)(pGxDebug->isRegInit + (*(uint *)&gx->field_0x7c >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)&gx->field_0x7c;
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXEnableTexOffsets
   
   Library: KioskDefault 0 0 */

void GXEnableTexOffsets(int param1,uint param2,uint param3) { //800208B8
  if (isInGxBegin) {
                    
    OSPanic("GXGeometry.c",0x201,"'GXEnableTexOffsets' is not allowed between GXBegin/GXEnd");
  }
  if (7 < param1) {
                    
    OSPanic("GXGeometry.c",0x203,"GXEnableTexOffsets: Invalid coordinate Id");
  }
  if ((param2 & 0xfe) != 0) {
                    
    OSPanic("GXGeometry.c",0x205,"GX Internal: Register field out of range");
  }
  *(uint *)(&gx->field_0xb8 + param1 * 4) =
       *(uint *)(&gx->field_0xb8 + param1 * 4) & 0xfffbffff | (param2 & 0xff) << 0x12;
  if ((param3 & 0xfe) != 0) {
                    
    OSPanic("GXGeometry.c",0x206,"GX Internal: Register field out of range");
  }
  *(uint *)(&gx->field_0xb8 + param1 * 4) =
       *(uint *)(&gx->field_0xb8 + param1 * 4) & 0xfff7ffff | (param3 & 0xff) << 0x13;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = *(undefined4 *)(&gx->field_0xb8 + param1 * 4);
  *(undefined4 *)
   (pGxDebug->isRegInit + (*(uint *)(&gx->field_0xb8 + param1 * 4) >> 0x16 & 0x3fc) + 0xc00) =
       *(undefined4 *)(&gx->field_0xb8 + param1 * 4);
  gx->field2_0x2 = 1;
  return;
}


/* Library Function - Single Match
    GXSetCullMode
   
   Library: KioskDefault 0 0 */

void GXSetCullMode(GXCullMode mode) { //80020A1C
  if (isInGxBegin) {
                    
    OSPanic("GXGeometry.c",0x21d,"'GXSetCullMode' is not allowed between GXBegin/GXEnd");
  }
  if (mode == GX_CULL_BACK) {
    mode = GX_CULL_FRONT;
  }
  else if (((int)mode < 2) && (0 < (int)mode)) {
    mode = GX_CULL_BACK;
  }
  if ((mode & 0xfffffffc) == 0) {
    gx->field491_0x204 = gx->field491_0x204 & 0xffff3fff | mode << 0xe;
    gx->flags4F0 = gx->flags4F0 | 4;
    return;
  }
                    
  OSPanic("GXGeometry.c",0x225,"GX Internal: Register field out of range");
}


/* Library Function - Single Match
    GXSetCoPlanar
   
   Library: KioskDefault 0 0 */

void GXSetCoPlanar(uint param1) { //80020AE0
  if (isInGxBegin) {
                    
    OSPanic("GXGeometry.c",0x24a,"'GXSetCoPlanar' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xfe) != 0) {
                    
    OSPanic("GXGeometry.c",0x24c,"GX Internal: Register field out of range");
  }
  gx->field491_0x204 = gx->field491_0x204 & 0xfff7ffff | (param1 & 0xff) << 0x13;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = 0xfe080000;
  *(undefined4 *)(pGxDebug->isRegInit + 0xff8) = 0xfe080000;
  GXFIFO._0_1_ = 0x61;
  GXFIFO = gx->field491_0x204;
  *(uint *)(pGxDebug->isRegInit + (gx->field491_0x204 >> 0x16 & 0x3fc) + 0xc00) = gx->field491_0x204
  ;
  return;
}

