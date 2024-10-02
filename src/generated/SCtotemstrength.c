
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void SCtotemstrength_initialise(undefined4 param) { //8025D34C
  return;
}


/* @description Called when DLL is unloaded */

void SCtotemstrength_release(void) { //8025D350
  return;
}


/* Library Function - Single Match
    dll_1FE_func03
   
   Library: KioskDefault 0 0 */

void SCtotemstrength_init
               (ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
               float y,float z) { //8025D354
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)this->state;
  this->fptr_0xbc = SCtotemstrength_enableMusicChange_8025d698;
  this->flags_0xb0 = this->flags_0xb0 | (DontMove|DontUseRenderCallback);
  (this->pos).rotation.x = -0x2900;
  puVar1[3] = 0xffffd700;
  *(undefined2 *)((int)puVar1 + 0x16) = 0;
  *puVar1 = 0;
  puVar1[7] = (this->pos).pos.x;
  puVar1[8] = (this->pos).pos.y;
  puVar1[9] = (this->pos).pos.z;
  mainSetBits(0x780,1);
  return;
}


/* Library Function - Single Match
    dll_1FE_func04
   
   Library: KioskDefault 0 0 */

void SCtotemstrength_update(ObjInstance *this) { //8025D3DC
  char cVar2;
  undefined4 uVar1;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)this->state;
                    /* {@symbol 8012dfa8} */
  cVar2 = (**(code **)(*(int *)pDll_SaveGame + 0x40))(0xe);
  if (cVar2 == '\x06') {
    if ((*(byte *)(puVar3 + 6) & 4) != 0) {
      *(byte *)(puVar3 + 6) = *(byte *)(puVar3 + 6) & 0xfb;
      (this->pos).pos.x = (float)puVar3[7];
      (this->pos).pos.y = (float)puVar3[8];
      (this->pos).pos.z = (float)puVar3[9];
      (this->pos).rotation.x = -0x2900;
      puVar3[3] = 0xffffd700;
      *puVar3 = 0;
      mainSetBits(0x780,1);
    }
    if ((*(byte *)(puVar3 + 6) & 2) != 0) {
      if (*(short *)((int)puVar3 + 0x16) == 0) {
        (this->pos).rotation.x = -0x2900;
        puVar3[3] = 0xffffd700;
        puVar3[1] = 0.0;
        puVar3[2] = 0.0;
        *(undefined2 *)((int)puVar3 + 0x16) = 1;
        *(byte *)(puVar3 + 6) = *(byte *)(puVar3 + 6) & 0xfe;
      }
      else if (*(short *)((int)puVar3 + 0x16) == 1) {
                    /* {@symbol 800d022c} */
        uVar1 = (**(code **)(*(int *)pDll_checkpoint + 0x48))(0,this,0xffffffff);
        puVar3[4] = uVar1;
      }
      else if (*(short *)((int)puVar3 + 0x16) == 2) {
        *(byte *)(puVar3 + 6) = *(byte *)(puVar3 + 6) & 0xfc;
        *(undefined2 *)((int)puVar3 + 0x16) = 0;
        puVar3[3] = 0xffffb924;
        audioStartSfx((int **)0x0,0x161,0x7f,0x40,"SCtotemstrength.c",0xc1);
                    /* {@symbol 800c89e0} */
        (**(code **)(*(int *)pDll_checkpoint + 0x74))(puVar3[4],puVar3[3]);
        mainSetBits(0x784,1);
        FUN_80068a9c((uint)this,8);
      }
      else if (*(short *)((int)puVar3 + 0x16) == 3) {
        *(byte *)(puVar3 + 6) = *(byte *)(puVar3 + 6) & 0xfc;
        *(undefined2 *)((int)puVar3 + 0x16) = 0;
        puVar3[3] = 0xfffff4dc;
        audioStartSfx((int **)0x0,0x16b,0x7f,0x40,"SCtotemstrength.c",0xcb);
                    /* {@symbol 80153bd4} */
        (**(code **)(*(int *)pDll_ObjSeq + 0x24))(3,0);
                    /* {@symbol 800c89e0} */
        (**(code **)(*(int *)pDll_checkpoint + 0x74))(puVar3[4],puVar3[3]);
        mainSetBits(0x786,1);
        FUN_80068a9c((uint)this,8);
      }
    }
  }
  return;
}


/* @description Override hit detection */

void SCtotemstrength_hitDetect(ObjInstance *this) { //8025D634
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_1FE_func06
    waterfallControl_func06
   
   Library: KioskDefault 0 0 */

void SCtotemstrength_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //8025D638
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  objRenderCurrentModel
            (this,(Gfx **)CONCAT31(in_register_00000010,param2),
             (undefined4 *)CONCAT31(in_register_00000014,param3),
             (undefined4 *)CONCAT31(in_register_00000018,param4),
             (undefined4 *)CONCAT31(in_register_0000001c,param5));
  return;
}


/* @description Free object instance */

void SCtotemstrength_free(ObjInstance *this,int param2) { //8025D684
  return;
}


undefined4 SCtotemstrength_func08(ObjInstance *this) { //8025D688
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int SCtotemstrength_getExtraSize(void) { //8025D690
  return 0x30;
}

