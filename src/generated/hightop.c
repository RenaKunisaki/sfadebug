
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void hightop_initialise(undefined4 param) { //8021E9F4
  return;
}


/* @description Called when DLL is unloaded */

void hightop_release(void) { //8021E9F8
  return;
}


/* Library Function - Single Match
    dll_1B2_func03
   
   Library: KioskDefault 0 0 */

void hightop_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                  float y,float z) { //8021E9FC
  undefined *puVar1;
  
  puVar1 = this->state;
  (this->pos).rotation.x = (ushort)objDef[1].allocatedSize << 8;
  (this->pos).rotation.y = (ushort)*(byte *)((int)&objDef[1].objType + 1) << 8;
  (this->pos).rotation.z = (ushort)*(byte *)&objDef[1].objType << 8;
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_8021ef50;
  puVar1[0x24] = 0;
  puVar1[0x25] = 0;
  return;
}


/* Library Function - Single Match
    dll_1B2_func04
   
   Library: KioskDefault 0 0 */

void hightop_update(ObjInstance *this) { //8021EA60
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  ObjInstance *pOVar5;
  char *pcVar6;
  
  pcVar6 = this->state;
  puVar2 = (undefined4 *)FUN_80094400((int)this,5);
  puVar3 = (undefined4 *)FUN_80094400((int)this,4);
  if (pcVar6[0x24] == '\x01') {
    return;
  }
  if (pcVar6[0x24] != '\0') {
    return;
  }
  if (false) {
    return;
  }
  bVar1 = pcVar6[0x25];
  if (bVar1 == 2) {
LAB_8021ec6c:
    *(float *)(pcVar6 + 0x2c) = timeDelta * 0.0002 + *(float *)(pcVar6 + 0x2c);
    if (0.005 < *(float *)(pcVar6 + 0x2c)) {
      *(float *)(pcVar6 + 0x2c) = 0.005;
    }
    if (this->animTimer <= 0.95) goto LAB_8021ee88;
    *pcVar6 = '\x01';
    Object_ObjAnimSetMove(0.0,this,0x11,0);
    *(float *)(pcVar6 + 0x2c) = 0.005;
    pcVar6[0x25] = '\x03';
    *(float *)(pcVar6 + 0x30) = 0.0;
LAB_8021ecdc:
    if ((this->flags_0xaf & FieldB8TimeCanBeNegative) == 0) {
      *(float *)(pcVar6 + 0x28) = *(float *)(pcVar6 + 0x28) + timeDelta;
    }
    else {
      *(float *)(pcVar6 + 0x28) = 0.0;
    }
    if (*(float *)(pcVar6 + 0x28) < 300.0) {
      if (*pcVar6 != '\0') {
        pOVar5 = Object_objGetMain();
        *(float *)(pcVar6 + 4) = (pOVar5->pos).pos.x;
        *(float *)(pcVar6 + 8) = (pOVar5->pos).pos.y;
        *(float *)(pcVar6 + 0xc) = (pOVar5->pos).pos.z;
      }
      FUN_800927d4((short *)this,pcVar6);
      FUN_800928ac((int)this,(int)pcVar6);
      *(float *)(pcVar6 + 0x30) = *(float *)(pcVar6 + 0x30) - timeDelta;
      if (*(float *)(pcVar6 + 0x30) <= 0.0) {
        *(float *)(pcVar6 + 0x30) = *(float *)(pcVar6 + 0x30) + 150.0;
        audioTryStartSfx((int *)this,0x10,0,0x7f,"hightop.c",0xb5);
      }
      goto LAB_8021ee88;
    }
    *pcVar6 = '\0';
    Object_ObjAnimSetMove(1.0,this,0x10,0);
    *(float *)(pcVar6 + 0x2c) = -0.004;
    pcVar6[0x25] = '\x04';
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        *puVar2 = 0x200;
        *puVar3 = 0x200;
        *pcVar6 = '\0';
        Object_ObjAnimSetMove(0.0,this,0x12,0);
        *(float *)(pcVar6 + 0x2c) = 0.001;
        pcVar6[0x25] = '\x01';
        *(float *)(pcVar6 + 0x30) = 0.0;
        pcVar6[0x26] = '\0';
        goto LAB_8021ee88;
      }
      if (false) goto LAB_8021ee88;
      if ((this->flags_0xaf & FieldB8TimeCanBeNegative) == 0) {
        *(float *)(pcVar6 + 0x30) = *(float *)(pcVar6 + 0x30) - timeDelta;
        if (*(float *)(pcVar6 + 0x30) <= 0.0) {
          if (pcVar6[0x26] == '\0') {
            pcVar6[0x26] = '\x01';
            audioTryStartSfx((int *)this,0x10,0x1cd,0x7f,"hightop.c",0x87);
          }
          else {
            pcVar6[0x26] = '\0';
            audioTryStartSfx((int *)this,0x10,0x1ce,0x7f,"hightop.c",0x8b);
          }
          uVar4 = randInt(300,400);
          *(float *)(pcVar6 + 0x30) =
               *(float *)(pcVar6 + 0x30) +
               (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - 4503601774854144.0);
        }
        goto LAB_8021ee88;
      }
      *puVar2 = 0;
      *puVar3 = 0;
      *(float *)(pcVar6 + 0x28) = 0.0;
      Object_ObjAnimSetMove(0.0,this,0x10,0);
      *(float *)(pcVar6 + 0x2c) = 0.005;
      pcVar6[0x25] = '\x02';
      audioTryStartSfx((int *)this,0x10,0x1d1,0x7f,"hightop.c",0x80);
      goto LAB_8021ec6c;
    }
    if (bVar1 != 4) {
      if (3 < bVar1) goto LAB_8021ee88;
      goto LAB_8021ecdc;
    }
  }
  if ((this->flags_0xaf & FieldB8TimeCanBeNegative) == 0) {
    if (this->animTimer < 0.05) {
      *puVar2 = 0x200;
      *puVar3 = 0x200;
      pcVar6[0x25] = '\x01';
      Object_ObjAnimSetMove(0.0,this,0x12,0);
      *(float *)(pcVar6 + 0x2c) = 0.001;
      *(float *)(pcVar6 + 0x30) = 0.0;
      pcVar6[0x26] = '\0';
    }
  }
  else {
    *puVar2 = 0;
    *puVar3 = 0;
    *(float *)(pcVar6 + 0x28) = 0.0;
    pcVar6[0x25] = '\x02';
  }
  FUN_800927d4((short *)this,pcVar6);
  FUN_800928ac((int)this,(int)pcVar6);
LAB_8021ee88:
  if ((this->flags_0xaf & CanPressAToTalk) != 0) {
                    /* {@symbol 800d022c} */
    (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
  }
  objRunAnimation((double)*(float *)(pcVar6 + 0x2c),(double)timeDelta,(int)this,(float *)0x0);
  return;
}


/* @description Override hit detection */

void hightop_hitDetect(ObjInstance *this) { //8021EEDC
  return;
}


/* Library Function - Single Match
    treasureRelated0177_func06
   
   Library: KioskDefault 0 0 */

void hightop_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                    undefined param5,bool shouldRender) { //8021EEE0
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

void hightop_free(ObjInstance *this,int param2) { //8021EF3C
  return;
}


undefined4 hightop_func08(ObjInstance *this) { //8021EF40
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int hightop_getExtraSize(void) { //8021EF48
  return 0x34;
}

