
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void MMP_moonrock_initialise(undefined4 param) { //8021B650
  return;
}


/* @description Called when DLL is unloaded */

void MMP_moonrock_release(void) { //8021B654
  return;
}


/* Library Function - Single Match
    dll_1A8_func03
   
   Library: KioskDefault 0 0 */

void MMP_moonrock_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //8021B658
  float fVar1;
  short sVar2;
  uint uVar3;
  undefined *puVar4;
  
  puVar4 = this->state;
  this->flags_0xb0 = this->flags_0xb0 | DontMove;
  puVar4[10] = 0;
  sVar2._0_1_ = objDef[1].allocatedSize;
  sVar2._1_1_ = objDef[1].mapStates1;
  uVar3 = mainGetBit((int)sVar2);
  puVar4[0xb] = (char)uVar3;
  if (puVar4[0xb] == '\0') {
                    /* {@symbol 8012f9f8} */
    (**(code **)(*(int *)pDll_projLib + 0x20))(puVar4,1);
  }
  else {
                    /* {@symbol 8012f9f8} */
    (**(code **)(*(int *)pDll_projLib + 0x20))(puVar4,0);
  }
  fVar1 = (this->pos).pos.y;
  *(float *)(puVar4 + 0x10) = fVar1;
  *(float *)(puVar4 + 0x14) = fVar1;
                    /* {@symbol 8012f580} */
  (**(code **)(*(int *)pDll_projLib + 4))(this,this->state,0x32);
  return;
}


/* Library Function - Single Match
    dll_1A8_func04
   
   Library: KioskDefault 0 0 */

void MMP_moonrock_update(ObjInstance *this) { //8021B720
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  double extraout_f1;
  double dVar4;
  int local_4c;
  longlong local_48;
  longlong local_40;
  undefined4 local_38;
  uint uStack_34;
  longlong local_30;
  undefined4 local_28;
  uint uStack_24;
  
  _savefpr_30();
  puVar3 = this->state;
                    /* {@symbol 8012f5bc} */
  iVar1 = (**(code **)(*(int *)pDll_projLib + 8))(this,this->state);
  if (iVar1 == 0) {
    if ((puVar3[10] & 1) != 0) {
      FUN_8021bb64(extraout_f1,this,'\x01');
      puVar3[10] = puVar3[10] & 0xfe;
    }
    puVar3[10] = puVar3[10] | 2;
    if (puVar3[0xb] != '\0') {
      if (((puVar3[0xb] == '\x03') || (puVar3[0xb] == '\x04')) || (puVar3[0xb] == '\x06')) {
        uVar2 = mainGetBit(0x894);
        puVar3[0xc] = (char)uVar2;
      }
      else {
        puVar3[0xc] = 0;
      }
      if (puVar3[0xc] == '\0') {
        this->flags_0xaf = this->flags_0xaf & ~ModelDisableFlag08;
      }
      else {
        this->flags_0xaf = this->flags_0xaf | ModelDisableFlag08;
      }
      audioTryStartSfx((int *)this,0xc0,0x78,puVar3[0xc] * ' ' + 0x20,"MMP_moonrock.c",0xa2
                      );
      uStack_24 = (uint)(byte)puVar3[0xc];
      local_28 = 0x43300000;
      if ((((float)((double)CONCAT44(0x43300000,uStack_24) - 4503599627370496.0) * 20.0 +
           *(float *)(puVar3 + 0x10)) - (this->pos).pos.y) * 0.1 <= (this->vel).y) {
        (this->vel).y = (this->vel).y - 0.051;
      }
      else {
        (this->vel).y = (this->vel).y + 0.03;
      }
      *(short *)(puVar3 + 0x18) = *(short *)(puVar3 + 0x18) + 0x1000;
      *(short *)(puVar3 + 0x1a) = *(short *)(puVar3 + 0x1a) + 0xdac;
      *(short *)(puVar3 + 0x1c) = *(short *)(puVar3 + 0x1c) + 0x800;
      objMove(0.0,(double)((this->vel).y * timeDelta),0.0,this);
      uStack_24 = (uint)*(ushort *)(puVar3 + 0x18);
      local_28 = 0x43300000;
      dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_24) -
                                                           4503599627370496.0) * 3.141593) / 32767.0
                                                  ));
      (this->pos).pos.y = (float)((double)(this->pos).pos.y + dVar4);
      if ((this->pos).pos.y < *(float *)(puVar3 + 0x10)) {
        (this->pos).pos.y = *(float *)(puVar3 + 0x10);
      }
      uStack_24 = (uint)*(ushort *)(puVar3 + 0x1a);
      local_28 = 0x43300000;
      dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_24) -
                                                           4503599627370496.0) * 3.141593) / 32767.0
                                                  ));
      local_30 = (longlong)(int)(dVar4 * 182.0);
      (this->pos).rotation.z = (this->pos).rotation.z + (short)(int)(dVar4 * 182.0);
      uStack_34 = (uint)*(ushort *)(puVar3 + 0x1c);
      local_38 = 0x43300000;
      dVar4 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,uStack_34) -
                                                           4503599627370496.0) * 3.141593) / 32767.0
                                                  ));
      local_40 = (longlong)(int)(dVar4 * 182.0);
      (this->pos).rotation.y = (this->pos).rotation.y + (short)(int)(dVar4 * 182.0);
      DAT_80395d38 = 1.0;
      DAT_80395d3c = (this->pos).pos.x;
      DAT_80395d40 = *(undefined4 *)(puVar3 + 0x10);
      DAT_80395d44 = (this->pos).pos.z;
      local_4c = (int)((this->pos).pos.y - *(float *)(puVar3 + 0x10));
      local_48 = (longlong)local_4c;
                    /* {@symbol 800ed30c} */
      (**(code **)(*(int *)pDll_objfsa + 8))
                (this,0x723,&DAT_80395d30,&DAT_00200001,0xffffffff,&local_4c);
    }
  }
  else {
    dVar4 = (double)FUN_8021be70(this);
    if ((puVar3[10] & 2) != 0) {
      FUN_8021bb64(dVar4,this,'\0');
      puVar3[10] = puVar3[10] & 0xfd;
    }
    puVar3[10] = puVar3[10] | 1;
  }
  _restfpr_30();
  return;
}


/* @description Override hit detection */

void MMP_moonrock_hitDetect(ObjInstance *this) { //8021BA98
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_11F_func06
    dll_1A8_func06
   
   Library: KioskDefault 0 0 */

void MMP_moonrock_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8021BA9C
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
                    /* {@symbol 8012f938} */
  iVar1 = (**(code **)(*(int *)pDll_projLib + 0xc))(this,(int)shouldRender);
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

void MMP_moonrock_free(ObjInstance *this,int param2) { //8021BB1C
                    /* {@symbol 8012f9ac} */
  (**(code **)(*(int *)pDll_projLib + 0x10))(this);
  return;
}


undefined4 MMP_moonrock_func08(ObjInstance *this) { //8021BB54
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int MMP_moonrock_getExtraSize(void) { //8021BB5C
  return 0x20;
}

