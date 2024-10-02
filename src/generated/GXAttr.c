
/* Library Function - Single Match
    GXSetVtxDesc
   
   Library: KioskDefault 0 0 */

void GXSetVtxDesc(VtxDescrBit param1,uint param2) { //8001D494
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0xcc,"'GXSetVtxDesc' is not allowed between GXBegin/GXEnd");
  }
  if ((-1 < (int)param1) && ((int)param1 < 0x1a)) {
    if ((-1 < (int)param2) && ((int)param2 < 4)) {
      _GXSetVtxDesc(param1,param2);
      if ((gx->field1018_0x41c == '\0') && (gx->field1019_0x41d == '\0')) {
        gx->field19_0x14 = gx->field19_0x14 & 0xffffe7ff;
      }
      else {
        if ((*(uint *)&gx->field_0x418 & 0xfffffffc) != 0) {
                    
          OSPanic("GXAttr.c",0xd7,"GX Internal: Register field out of range");
        }
        gx->field19_0x14 = gx->field19_0x14 & 0xffffe7ff | *(int *)&gx->field_0x418 << 0xb;
      }
      gx->flags4F0 = gx->flags4F0 | 8;
      return;
    }
                    
    OSPanic("GXAttr.c",0xd1,"GXSetVtxDesc: Invalid vertex attribute type");
  }
                    
  OSPanic("GXAttr.c",0xcf,"GXSetVtxDesc: Invalid vertex attribute name");
}


/* Library Function - Single Match
    _GXSetVtxDesc
   
   Library: KioskDefault 0 0 */

void _GXSetVtxDesc(undefined4 param1,uint param2) { //8001D5CC
  if (true) {
                    /* {@symbol 8001d610} */
    switch(param1) {
    case 0:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xa8,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xfffffffe | param2;
      break;
    case 1:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xa9,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xfffffffd | param2 << 1;
      break;
    case 2:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xaa,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xfffffffb | param2 << 2;
      break;
    case 3:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xab,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xfffffff7 | param2 << 3;
      break;
    case 4:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xac,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xffffffef | param2 << 4;
      break;
    case 5:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xad,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xffffffdf | param2 << 5;
      break;
    case 6:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xae,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xffffffbf | param2 << 6;
      break;
    case 7:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xaf,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xffffff7f | param2 << 7;
      break;
    case 8:
      if ((param2 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0xb0,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xfffffeff | param2 << 8;
      break;
    case 9:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xb1,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xfffff9ff | param2 << 9;
      break;
    case 10:
      gx->field1018_0x41c = '\x01' - (param2 == 0);
      if (param2 != 0) {
        *(uint *)&gx->field_0x418 = param2;
      }
      break;
    case 0xb:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xba,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xffff9fff | param2 << 0xd;
      break;
    case 0xc:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xbb,"GX Internal: Register field out of range");
      }
      gx->field19_0x14 = gx->field19_0x14 & 0xfffe7fff | param2 << 0xf;
      break;
    case 0xd:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xbc,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xfffffffc | param2;
      break;
    case 0xe:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xbd,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xfffffff3 | param2 << 2;
      break;
    case 0xf:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xbe,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xffffffcf | param2 << 4;
      break;
    case 0x10:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xbf,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xffffff3f | param2 << 6;
      break;
    case 0x11:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xc0,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xfffffcff | param2 << 8;
      break;
    case 0x12:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xc1,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xfffff3ff | param2 << 10;
      break;
    case 0x13:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xc2,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xffffcfff | param2 << 0xc;
      break;
    case 0x14:
      if ((param2 & 0xfffffffc) != 0) {
                    
        OSPanic("GXAttr.c",0xc3,"GX Internal: Register field out of range");
      }
      gx->field20_0x18 = gx->field20_0x18 & 0xffff3fff | param2 << 0xe;
      break;
    case 0x19:
      gx->field1019_0x41d = '\x01' - (param2 == 0);
      if (param2 != 0) {
        *(uint *)&gx->field_0x418 = param2;
      }
    }
  }
  return;
}


/* Library Function - Single Match
    GXSetVtxDescv
   
   Library: KioskDefault 0 0 */

void GXSetVtxDescv(int *param1) { //8001DB20
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0xf5,"'GXSetVtxDescv' is not allowed between GXBegin/GXEnd");
  }
  if (param1 == (int *)0x0) {
                    
    OSPanic("GXAttr.c",0xf6,"GXSetVtxDescv: attrPtr is NULL");
  }
  while( true ) {
    if (*param1 == 0xff) {
      if ((gx->field1018_0x41c == '\0') && (gx->field1019_0x41d == '\0')) {
        gx->field19_0x14 = gx->field19_0x14 & 0xffffe7ff;
      }
      else {
        if ((*(uint *)&gx->field_0x418 & 0xfffffffc) != 0) {
                    
          OSPanic("GXAttr.c",0x107,"GX Internal: Register field out of range");
        }
        gx->field19_0x14 = gx->field19_0x14 & 0xffffe7ff | *(int *)&gx->field_0x418 << 0xb;
      }
      gx->flags4F0 = gx->flags4F0 | 8;
      return;
    }
    if ((*param1 < 0) || (0x19 < *param1)) break;
    if ((param1[1] < 0) || (3 < param1[1])) {
                    
      OSPanic("GXAttr.c",0xfe,"GXSetVtxDesc: Invalid vertex attribute type");
    }
    _GXSetVtxDesc(*param1,param1[1]);
    param1 = param1 + 2;
  }
                    
  OSPanic("GXAttr.c",0xfb,"GXSetVtxDesc: Invalid vertex attribute name");
}


/* Library Function - Single Match
    GXGetVtxDesc
   
   Library: KioskDefault 0 0 */

void GXGetVtxDesc(int param1,uint *param2) { //8001DE60
  uint uVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x185,"'GXGetVtxDesc' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 < 0) || (0x19 < param1)) {
                    
    OSPanic("GXAttr.c",0x187,"GXSetVtxDesc: Invalid vertex attribute name");
  }
  if (false) {
switchD_8001dee0_caseD_15:
    uVar1 = 0;
  }
  else {
                    /* {@symbol 8001dee4} */
    switch(param1) {
    case 0:
      uVar1 = gx->field19_0x14 & 1;
      break;
    case 1:
      uVar1 = gx->field19_0x14 >> 1 & 1;
      break;
    case 2:
      uVar1 = gx->field19_0x14 >> 2 & 1;
      break;
    case 3:
      uVar1 = gx->field19_0x14 >> 3 & 1;
      break;
    case 4:
      uVar1 = gx->field19_0x14 >> 4 & 1;
      break;
    case 5:
      uVar1 = gx->field19_0x14 >> 5 & 1;
      break;
    case 6:
      uVar1 = gx->field19_0x14 >> 6 & 1;
      break;
    case 7:
      uVar1 = gx->field19_0x14 >> 7 & 1;
      break;
    case 8:
      uVar1 = gx->field19_0x14 >> 8 & 1;
      break;
    case 9:
      uVar1 = gx->field19_0x14 >> 9 & 3;
      break;
    case 10:
      if (gx->field1018_0x41c == '\0') {
        uVar1 = 0;
      }
      else {
        uVar1 = gx->field19_0x14 >> 0xb & 3;
      }
      break;
    case 0xb:
      uVar1 = gx->field19_0x14 >> 0xd & 3;
      break;
    case 0xc:
      uVar1 = gx->field19_0x14 >> 0xf & 3;
      break;
    case 0xd:
      uVar1 = gx->field20_0x18 & 3;
      break;
    case 0xe:
      uVar1 = gx->field20_0x18 >> 2 & 3;
      break;
    case 0xf:
      uVar1 = gx->field20_0x18 >> 4 & 3;
      break;
    case 0x10:
      uVar1 = gx->field20_0x18 >> 6 & 3;
      break;
    case 0x11:
      uVar1 = gx->field20_0x18 >> 8 & 3;
      break;
    case 0x12:
      uVar1 = gx->field20_0x18 >> 10 & 3;
      break;
    case 0x13:
      uVar1 = gx->field20_0x18 >> 0xc & 3;
      break;
    case 0x14:
      uVar1 = gx->field20_0x18 >> 0xe & 3;
      break;
    default:
      goto switchD_8001dee0_caseD_15;
    case 0x19:
      if (gx->field1019_0x41d == '\0') {
        uVar1 = 0;
      }
      else {
        uVar1 = gx->field19_0x14 >> 0xb & 3;
      }
    }
  }
  *param2 = uVar1;
  return;
}


/* Library Function - Single Match
    GXGetVtxDescv
   
   Library: KioskDefault 0 0 */

void GXGetVtxDescv(int param1) { //8001E094
  int param1_00;
  
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x1ba,"'GXGetVtxDescv' is not allowed between GXBegin/GXEnd");
  }
  if (param1 == 0) {
                    
    OSPanic("GXAttr.c",0x1bc,"GXSetVtxDescv: attrPtr is NULL");
  }
  for (param1_00 = 0; param1_00 < 0x1a; param1_00 = param1_00 + 1) {
    *(int *)(param1 + param1_00 * 8) = param1_00;
    GXGetVtxDesc(param1_00,(uint *)(param1 + param1_00 * 8 + 4));
  }
  *(undefined4 *)(param1 + param1_00 * 8) = 0xff;
  return;
}


/* Library Function - Single Match
    GXClearVtxDesc
   
   Library: KioskDefault 0 0 */

void GXClearVtxDesc(void) { //8001E140
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x1d3,"'GXClearVtxDesc' is not allowed between GXBegin/GXEnd");
  }
  gx->field19_0x14 = 0;
  gx->field19_0x14 = gx->field19_0x14 & 0xfffff9ff | 0x200;
  gx->field20_0x18 = 0;
  gx->field1018_0x41c = '\0';
  gx->field1019_0x41d = '\0';
  gx->flags4F0 = gx->flags4F0 | 8;
  return;
}


/* Library Function - Single Match
    GXSetVtxAttrFmt
   
   Library: KioskDefault 0 0 */

void GXSetVtxAttrFmt(uint param1,int param2,uint param3,uint param4,uint param5) { //8001E1DC
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x252,"'GXSetVtxAttrFmt' is not allowed between GXBegin/GXEnd");
  }
  if (7 < (int)param1) {
                    
    OSPanic("GXAttr.c",0x253,"GXSetVtxAttrFmt: Format Index is out of range");
  }
  if ((8 < param2) && (param2 < 0x1b)) {
    if (0x1f < (param5 & 0xff)) {
                    
      OSPanic("GXAttr.c",0x256,s_GXSetVtxAttrFmt__Frac_value_is_>_802d8288);
    }
    _GXSetVtxAttrFmt(&gx->vtxFmts + param1,(uint *)(&gx->field_0x3c + param1 * 4),
                     (uint *)(&gx->field_0x5c + param1 * 4),param2,param3,param4,param5);
    gx->flags4F0 = gx->flags4F0 | 0x10;
    gx->field_0x4ee = gx->field_0x4ee | (byte)(1 << (param1 & 0xff));
    return;
  }
                    
  OSPanic("GXAttr.c",0x255,"GXSetVtxAttrFmt: Invalid vertex attribute name");
}


/* Library Function - Single Match
    _GXSetVtxAttrFmt
   
   Library: KioskDefault 0 0 */

void _GXSetVtxAttrFmt(uint *param1,uint *param2,uint *param3,undefined4 param4,uint param5,
                     uint param6,uint param7) { //8001E31C
  if (true) {
                    /* {@symbol 8001e378} */
    switch(param4) {
    case 9:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x1ff,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xfffffffe | param5;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x200,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xfffffff1 | param6 << 1;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x201,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xfffffe0f | (param7 & 0xff) << 4;
      break;
    case 10:
    case 0x19:
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x209,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xffffe3ff | param6 << 10;
      if (param5 == 2) {
        *param1 = *param1 & 0xfffffdff | 0x200;
        *param1 = *param1 & 0x7fffffff | 0x80000000;
      }
      else {
        if ((param5 & 0xfffffffe) != 0) {
                    
          OSPanic("GXAttr.c",0x20f,"GX Internal: Register field out of range");
        }
        *param1 = *param1 & 0xfffffdff | param5 << 9;
        *param1 = *param1 & 0x7fffffff;
      }
      break;
    case 0xb:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x215,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xffffdfff | param5 << 0xd;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x216,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xfffe3fff | param6 << 0xe;
      break;
    case 0xc:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x219,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xfffdffff | param5 << 0x11;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x21a,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xffe3ffff | param6 << 0x12;
      break;
    case 0xd:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x21d,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xffdfffff | param5 << 0x15;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x21e,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xfe3fffff | param6 << 0x16;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x21f,"GX Internal: Register field out of range");
      }
      *param1 = *param1 & 0xc1ffffff | param7 << 0x19;
      break;
    case 0xe:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x222,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xfffffffe | param5;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x223,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xfffffff1 | param6 << 1;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x224,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xfffffe0f | (param7 & 0xff) << 4;
      break;
    case 0xf:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x227,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xfffffdff | param5 << 9;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x228,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xffffe3ff | param6 << 10;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x229,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xfffc1fff | (param7 & 0xff) << 0xd;
      break;
    case 0x10:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x22c,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xfffbffff | param5 << 0x12;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x22d,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xffc7ffff | param6 << 0x13;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x22e,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xf83fffff | (param7 & 0xff) << 0x16;
      break;
    case 0x11:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x231,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0xf7ffffff | param5 << 0x1b;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x232,"GX Internal: Register field out of range");
      }
      *param2 = *param2 & 0x8fffffff | param6 << 0x1c;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x233,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xffffffe0 | param7 & 0xff;
      break;
    case 0x12:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x236,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xffffffdf | param5 << 5;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x237,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xfffffe3f | param6 << 6;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x238,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xffffc1ff | (param7 & 0xff) << 9;
      break;
    case 0x13:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x23b,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xffffbfff | param5 << 0xe;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x23c,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xfffc7fff | param6 << 0xf;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x23d,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xff83ffff | (param7 & 0xff) << 0x12;
      break;
    case 0x14:
      if ((param5 & 0xfffffffe) != 0) {
                    
        OSPanic("GXAttr.c",0x240,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xff7fffff | param5 << 0x17;
      if ((param6 & 0xfffffff8) != 0) {
                    
        OSPanic("GXAttr.c",0x241,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0xf8ffffff | param6 << 0x18;
      if ((param7 & 0xe0) != 0) {
                    
        OSPanic("GXAttr.c",0x242,"GX Internal: Register field out of range");
      }
      *param3 = *param3 & 0x7ffffff | param7 << 0x1b;
    }
  }
  return;
}


/* Library Function - Single Match
    GXSetVtxAttrFmtv
   
   Library: KioskDefault 0 0 */

void GXSetVtxAttrFmtv(uint param1,int *param2) { //8001EA14
  u32 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x27b,"'GXSetVtxAttrFmtv' is not allowed between GXBegin/GXEnd");
  }
  if (param2 == (int *)0x0) {
                    
    OSPanic("GXAttr.c",0x27c,"GXSetVtxAttrFmt: list pointer is NULL");
  }
  if (7 < (int)param1) {
                    
    OSPanic("GXAttr.c",0x27d,"GXSetVtxAttrFmt: Format Index is out of range");
  }
  puVar1 = &gx->vtxFmts;
  puVar2 = &gx->field_0x3c;
  puVar3 = &gx->field_0x5c;
  while( true ) {
    if (*param2 == 0xff) {
      gx->flags4F0 = gx->flags4F0 | 0x10;
      gx->field_0x4ee = gx->field_0x4ee | (byte)(1 << (param1 & 0xff));
      return;
    }
    if ((*param2 < 9) || (0x1a < *param2)) break;
    if (0x1f < *(byte *)(param2 + 3)) {
                    
      OSPanic("GXAttr.c",0x287,s_GXSetVtxAttrFmt__Frac_value_is_>_802d8288);
    }
    _GXSetVtxAttrFmt(puVar1 + param1,(uint *)(puVar2 + param1 * 4),(uint *)(puVar3 + param1 * 4),
                     *param2,param2[1],param2[2],(uint)*(byte *)(param2 + 3));
    param2 = param2 + 4;
  }
                    
  OSPanic("GXAttr.c",0x286,"GXSetVtxAttrFmt: Invalid vertex attribute name");
}


/* Library Function - Single Match
    GXGetVtxAttrFmt
   
   Library: KioskDefault 0 0 */

void GXGetVtxAttrFmt(int param1,undefined4 param2,uint *param3,uint *param4,byte *param5) { //8001EC8C
  uint *puVar1;
  uint *puVar2;
  u32 *puVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x2cf,"'GXGetVtxAttrFmt' is not allowed between GXBegin/GXEnd");
  }
  if (7 < param1) {
                    
    OSPanic("GXAttr.c",0x2d0,"GXSetVtxAttrFmt: Format Index is out of range");
  }
  puVar3 = &gx->vtxFmts + param1;
  puVar2 = (uint *)(&gx->field_0x3c + param1 * 4);
  puVar1 = (uint *)(&gx->field_0x5c + param1 * 4);
  if (false) {
switchD_8001ed48_caseD_15:
    *param3 = 1;
    *param4 = 0;
    *param5 = 0;
  }
  else {
                    /* {@symbol 8001ed4c} */
    switch(param2) {
    case 9:
      *param3 = *puVar3 & 1;
      *param4 = *puVar3 >> 1 & 7;
      *param5 = (byte)(*puVar3 >> 4) & 0x1f;
      break;
    case 10:
    case 0x19:
      *param3 = *puVar3 >> 9 & 1;
      if ((*param3 == 1) && ((int)*puVar3 < 0)) {
        *param3 = 2;
      }
      *param4 = *puVar3 >> 10 & 7;
      *param5 = 0;
      break;
    case 0xb:
      *param3 = *puVar3 >> 0xd & 1;
      *param4 = *puVar3 >> 0xe & 7;
      *param5 = 0;
      break;
    case 0xc:
      *param3 = *puVar3 >> 0x11 & 1;
      *param4 = *puVar3 >> 0x12 & 7;
      *param5 = 0;
      break;
    case 0xd:
      *param3 = *puVar3 >> 0x15 & 1;
      *param4 = *puVar3 >> 0x16 & 7;
      *param5 = (byte)(*puVar3 >> 0x19) & 0x1f;
      break;
    case 0xe:
      *param3 = *puVar2 & 1;
      *param4 = *puVar2 >> 1 & 7;
      *param5 = (byte)(*puVar2 >> 4) & 0x1f;
      break;
    case 0xf:
      *param3 = *puVar2 >> 9 & 1;
      *param4 = *puVar2 >> 10 & 7;
      *param5 = (byte)(*puVar2 >> 0xd) & 0x1f;
      break;
    case 0x10:
      *param3 = *puVar2 >> 0x12 & 1;
      *param4 = *puVar2 >> 0x13 & 7;
      *param5 = (byte)(*puVar2 >> 0x16) & 0x1f;
      break;
    case 0x11:
      *param3 = *puVar2 >> 0x1b & 1;
      *param4 = *puVar2 >> 0x1c & 7;
      *param5 = (byte)*puVar1 & 0x1f;
      break;
    case 0x12:
      *param3 = *puVar1 >> 5 & 1;
      *param4 = *puVar1 >> 6 & 7;
      *param5 = (byte)(*puVar1 >> 9) & 0x1f;
      break;
    case 0x13:
      *param3 = *puVar1 >> 0xe & 1;
      *param4 = *puVar1 >> 0xf & 7;
      *param5 = (byte)(*puVar1 >> 0x12) & 0x1f;
      break;
    case 0x14:
      *param3 = *puVar1 >> 0x17 & 1;
      *param4 = *puVar1 >> 0x18 & 7;
      *param5 = (byte)(*puVar1 >> 0x1b);
      break;
    default:
      goto switchD_8001ed48_caseD_15;
    }
  }
  return;
}


/* Library Function - Single Match
    GXGetVtxAttrFmtv
   
   Library: KioskDefault 0 0 */

void GXGetVtxAttrFmtv(int param1,int *param2) { //8001EF6C
  int param2_00;
  
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x330,"'GXGetVtxAttrFmtv' is not allowed between GXBegin/GXEnd");
  }
  if (param2 == (int *)0x0) {
                    
    OSPanic("GXAttr.c",0x331,"GXSetVtxAttrFmt: list pointer is NULL");
  }
  if (7 < param1) {
                    
    OSPanic("GXAttr.c",0x332,"GXSetVtxAttrFmt: Format Index is out of range");
  }
  for (param2_00 = 9; param2_00 < 0x1a; param2_00 = param2_00 + 1) {
    *param2 = param2_00;
    GXGetVtxAttrFmt(param1,param2_00,(uint *)(param2 + 1),(uint *)(param2 + 2),(byte *)(param2 + 3))
    ;
    param2 = param2 + 4;
  }
  *param2 = 0xff;
  return;
}


/* Library Function - Single Match
    GXSetArray
   
   Library: KioskDefault 0 0 */

void GXSetArray(int param1,uint param2,uint param3) { //8001F038
  byte bVar1;
  
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x34f,"'GXSetArray' is not allowed between GXBegin/GXEnd");
  }
  if (param1 == 0x19) {
    param1 = 10;
  }
  if ((8 < param1) && (param1 < 0x19)) {
    bVar1 = (char)param1 - 9;
    GXFIFO._0_1_ = 8;
    GXFIFO._0_1_ = bVar1 | 0xa0;
    GXFIFO = param2 & 0x3fffffff;
    if ((-1 < param1 + -0x15) && (param1 + -0x15 < 4)) {
      *(uint *)(&gx->field_0x34 + param1 * 4) = param2 & 0x3fffffff;
    }
    GXFIFO._0_1_ = 8;
    GXFIFO._0_1_ = bVar1 | 0xb0;
    GXFIFO = param3 & 0xff;
    if ((-1 < param1 + -0x15) && (param1 + -0x15 < 4)) {
      *(uint *)(&gx->field_0x44 + param1 * 4) = param3 & 0xff;
    }
    return;
  }
                    
  OSPanic("GXAttr.c",0x352,"GXSetArray: Invalid vertex attribute name");
}


/* Library Function - Single Match
    GXInvalidateVtxCache
   
   Library: KioskDefault 0 0 */

void GXInvalidateVtxCache(void) { //8001F15C
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x368,"'GXInvalidateVtxCache' is not allowed between GXBegin/GXEnd");
  }
  GXFIFO._0_1_ = 0x48;
  return;
}


/* Library Function - Single Match
    GXSetTexCoordGen
   
   Library: KioskDefault 0 0 */

void GXSetTexCoordGen(int param1,int param2,int param3,uint param4,uint param5,int param6) { //8001F1AC
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x392,"'GXSetTexCoordGen' is not allowed between GXBegin/GXEnd");
  }
  if (7 < param1) {
                    
    OSPanic("GXAttr.c",0x393,"GXSetTexCoordGen: Invalid coordinate Id");
  }
  iVar1 = 0;
  iVar2 = 5;
                    /* {@symbol 8001f244} */
  switch(param3) {
  case 0:
    iVar2 = 0;
    iVar1 = 1;
    break;
  case 1:
    iVar2 = 1;
    iVar1 = 1;
    break;
  case 2:
    iVar2 = 3;
    iVar1 = 1;
    break;
  case 3:
    iVar2 = 4;
    iVar1 = 1;
    break;
  case 4:
    iVar2 = 5;
    break;
  case 5:
    iVar2 = 6;
    break;
  case 6:
    iVar2 = 7;
    break;
  case 7:
    iVar2 = 8;
    break;
  case 8:
    iVar2 = 9;
    break;
  case 9:
    iVar2 = 10;
    break;
  case 10:
    iVar2 = 0xb;
    break;
  case 0xb:
    iVar2 = 0xc;
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    iVar2 = 2;
    break;
  case 0x14:
    iVar2 = 2;
    break;
  default:
                    
    OSPanic("GXAttr.c",0x3af,"GXSetTexCoordGen: Invalid source parameter");
  }
  if (param2 == 1) {
    if (false) {
                    
      OSPanic("GXAttr.c",0x3b9,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXAttr.c",0x3bb,"GX Internal: Register field out of range");
    }
    uVar3 = iVar1 << 2 | iVar2 << 7;
  }
  else if (param2 < 1) {
    if (param2 < 0) {
LAB_8001f510:
                    
      OSPanic("GXAttr.c",0x3e5,"GXSetTexCoordGen:  Invalid function");
    }
    if (false) {
                    
      OSPanic("GXAttr.c",0x3c0,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXAttr.c",0x3c2,"GX Internal: Register field out of range");
    }
    uVar3 = iVar1 << 2 | 2U | iVar2 << 7;
  }
  else if (param2 == 10) {
    if (false) {
                    
      OSPanic("GXAttr.c",0x3da,"GX Internal: Register field out of range");
    }
    if (param3 == 0x13) {
      uVar3 = iVar1 << 2 | 0x20;
    }
    else {
      uVar3 = iVar1 << 2 | 0x30;
    }
    uVar3 = uVar3 | 0x100;
  }
  else {
    if (9 < param2) goto LAB_8001f510;
    if ((param3 < 0xc) || (0x12 < param3)) {
                    
      OSPanic("GXAttr.c",0x3cf,"GXSetTexCoordGen:  Bump source texture value is invalid");
    }
    if (false) {
                    
      OSPanic("GXAttr.c",0x3d1,"GX Internal: Register field out of range");
    }
    if (false) {
                    
      OSPanic("GXAttr.c",0x3d3,"GX Internal: Register field out of range");
    }
    if ((param3 - 0xcU & 0xfffffff8) != 0) {
                    
      OSPanic("GXAttr.c",0x3d4,"GX Internal: Register field out of range");
    }
    if ((param2 - 2U & 0xfffffff8) != 0) {
                    
      OSPanic("GXAttr.c",0x3d5,"GX Internal: Register field out of range");
    }
    uVar3 = iVar1 << 2 | 0x10U | iVar2 << 7 | (param3 + -0xc) * 0x1000 & 0xfffc7000U |
            (param2 + -2) * 0x8000;
  }
  GXFIFO._0_1_ = 0x10;
  GXFIFO = param1 + 0x1040;
  GXFIFO = uVar3;
  if ((-1 < param1 + 0x40) && (param1 + 0x40 < 0x50)) {
    *(uint *)(pGxDebug->isRegInit + param1 * 4 + 0x40) = uVar3;
    (&pGxDebug->field_0x1108)[param1] = 1;
  }
  if ((param6 - 0x40U & 0xffffffc0) != 0) {
                    
    OSPanic("GXAttr.c",0x3f8,"GX Internal: Register field out of range");
  }
  if ((param5 & 0xfe) != 0) {
                    
    OSPanic("GXAttr.c",0x3f9,"GX Internal: Register field out of range");
  }
  uVar3 = param6 - 0x40U & 0xfffffeff | (param5 & 0xff) << 8;
  GXFIFO._0_1_ = 0x10;
  GXFIFO = param1 + 0x1050;
  GXFIFO = uVar3;
  if ((-1 < param1 + 0x50) && (param1 + 0x50 < 0x50)) {
    *(uint *)(pGxDebug->isRegInit + param1 * 4 + 0x80) = uVar3;
    *(undefined *)((int)pGxDebug[1].projMtx + param1 + -0x7b) = 1;
  }
                    /* {@symbol 8001f644} */
  switch(param1) {
  case 0:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x402,"GX Internal: Register field out of range");
    }
    gx->field118_0x80 = gx->field118_0x80 & 0xfffff03f | param4 << 6;
    break;
  case 1:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x403,"GX Internal: Register field out of range");
    }
    gx->field118_0x80 = gx->field118_0x80 & 0xfffc0fff | param4 << 0xc;
    break;
  case 2:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x404,"GX Internal: Register field out of range");
    }
    gx->field118_0x80 = gx->field118_0x80 & 0xff03ffff | param4 << 0x12;
    break;
  case 3:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x405,"GX Internal: Register field out of range");
    }
    gx->field118_0x80 = gx->field118_0x80 & 0xc0ffffff | param4 << 0x18;
    break;
  case 4:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x406,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x84 = *(uint *)&gx->field_0x84 & 0xffffffc0 | param4;
    break;
  case 5:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x407,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x84 = *(uint *)&gx->field_0x84 & 0xfffff03f | param4 << 6;
    break;
  case 6:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x408,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x84 = *(uint *)&gx->field_0x84 & 0xfffc0fff | param4 << 0xc;
    break;
  default:
    if ((param4 & 0xffffffc0) != 0) {
                    
      OSPanic("GXAttr.c",0x409,"GX Internal: Register field out of range");
    }
    *(uint *)&gx->field_0x84 = *(uint *)&gx->field_0x84 & 0xff03ffff | param4 << 0x12;
  }
  __GXSetMatrixIndex(param1 + 1);
  return;
}


/* Library Function - Single Match
    GXSetNumTexGens
   
   Library: KioskDefault 0 0 */

void GXSetNumTexGens(uint param1) { //8001F83C
  if (isInGxBegin) {
                    
    OSPanic("GXAttr.c",0x41b,"'GXSetNumTexGens' is not allowed between GXBegin/GXEnd");
  }
  if ((param1 & 0xf0) != 0) {
                    
    OSPanic("GXAttr.c",0x41d,"GX Internal: Register field out of range");
  }
  gx->field491_0x204 = gx->field491_0x204 & 0xfffffff0 | param1 & 0xff;
  GXFIFO._0_1_ = 0x10;
  GXFIFO = 0x103f;
  GXFIFO = param1 & 0xff;
  if ((true) && (true)) {
    *(uint *)(pGxDebug->isRegInit + 0x3c) = param1 & 0xff;
    pGxDebug->field_0x1107 = 1;
  }
  gx->flags4F0 = gx->flags4F0 | 4;
  return;
}

