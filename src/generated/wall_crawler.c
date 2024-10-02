
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void wall_crawler_initialise(undefined4 param) { //801BEA4C
  FUN_801bf9f8();
  return;
}


/* @description Called when DLL is unloaded */

void wall_crawler_release(void) { //801BEA6C
  return;
}


/* Library Function - Single Match
    dll_D6_func03
   
   Library: KioskDefault 0 0 */

void wall_crawler_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,
                       float x,float y,float z) { //801BEA70
  uint uVar1;
  undefined *puVar2;
  
  puVar2 = this->state;
  printAssertFail("(sizeof(hittab)/sizeof(int)) == BADDIE_HITTAB_SIZE","wall_crawler.c",0xad);
  printAssertFail("(sizeof(damagetab)/sizeof(s8)) == BADDIE_HITTAB_SIZE","wall_crawler.c",0xae);
  uVar1 = 0x16;
  if (obj2 != (ObjInstance *)0x0) {
    uVar1 = 0x17;
  }
  if ((*(byte *)((int)&objDef[1].pos.z + 3) & 1) == 0) {
    uVar1 = uVar1 | 8;
  }
  (this->pos).rotation.y = (short)((int)*(char *)&objDef[1].pos.z << 8);
  (this->pos).rotation.z = (short)((int)*(char *)((int)&objDef[1].pos.y + 3) << 8);
                    /* {@symbol 8016386c} */
  (**(code **)(*(int *)pDll_partfx1F + 0x58))(0x4034000000000000,this,objDef,puVar2,4,6,0x82,uVar1);
  this->fptr_0xbc = (objFieldBC_func_conflict1 *)&LAB_801beea4;
                    /* {@symbol 8011c3c0} */
  (**(code **)(*(int *)pDll11 + 0x14))(this,puVar2,0);
  *(undefined2 *)(puVar2 + 0x268) = 0;
  if (*(ushort *)(puVar2 + 0x3de) < 0x32) {
    *(undefined2 *)(puVar2 + 0x3de) = 0x32;
  }
  return;
}


/* Library Function - Single Match
    dll_D6_func04
   
   Library: KioskDefault 0 0 */

void wall_crawler_update(ObjInstance *this) { //801BEB98
  int iVar1;
  ObjDef *pOVar2;
  undefined *puVar3;
  
  puVar3 = this->state;
  pOVar2 = this->def;
  if (this->field76_0xf4 == 0) {
    if (this->flags_0xf8 == 0) {
      (this->pos).pos.x = (pOVar2->pos).x;
      (this->pos).pos.y = (pOVar2->pos).y;
      (this->pos).pos.z = (pOVar2->pos).z;
      this->flags_0xf8 = 1;
    }
    else {
      if ((*(ushort *)(puVar3 + 0x3ae) & 2) != 0) {
                    /* {@symbol 80162f2c} */
        (**(code **)(*(int *)pDll_partfx1F + 0x28))
                  (this,puVar3,puVar3 + 0x34c,(int)*(short *)(puVar3 + 0x39e),puVar3 + 0x3b0,0,0,0,1
                  );
        *(ushort *)(puVar3 + 0x3ae) = *(ushort *)(puVar3 + 0x3ae) & 0xfffd;
      }
                    /* {@symbol 80162ab0} */
      iVar1 = (**(code **)(*(int *)pDll_partfx1F + 0x30))(this,puVar3,1);
      if (iVar1 != 0) {
        FUN_801bf0c0((int)this,(int)puVar3,(int)puVar3);
        FUN_801bf39c((short *)this,(int)puVar3,(int)puVar3);
      }
    }
  }
  return;
}


/* Library Function - Single Match
    dll_D6_func05
   
   Library: KioskDefault 0 0 */

void wall_crawler_hitDetect(ObjInstance *this) { //801BECA4
                    /* {@symbol 8011c220} */
  (**(code **)(*(int *)pDll11 + 0xc))(this,this->state,&DAT_803958f8);
  return;
}


/* Library Function - Single Match
    dll_D6_func06
   
   Library: KioskDefault 0 0 */

void wall_crawler_render
               (ObjInstance *this,undefined param2,undefined param3,undefined param4,
               undefined param5,bool shouldRender) { //801BECF0
  int iVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  Gfx *param2_00;
  undefined3 in_register_00000014;
  int *param3_00;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  param3_00 = (int *)CONCAT31(in_register_00000014,param3);
  param2_00 = (Gfx *)CONCAT31(in_register_00000010,param2);
  if ((shouldRender) && (this->field76_0xf4 == 0)) {
    iVar1 = FUN_8018d744();
    if (((iVar1 != 0) || (bVar2 = checkSomeDebugFlags_8017c4f8(), bVar2)) &&
       (((this->pos).flags & 0x100) != 0)) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,
                                                    (uint)*(ushort *)(this->state + 0x3de)) -
                                  4503599627370496.0),32.0,param2_00,param3_00,0xc0,0xc0,0x20);
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   50.0,32.0,param2_00,param3_00,0xc0,0,0);
    }
    objRenderCurrentModel
              (this,(Gfx **)param2_00,param3_00,(undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_197_func07
    dll_222_func07
    dll_D6_func07
   
   Library: KioskDefault 0 0 */

void wall_crawler_free(ObjInstance *this,int param2) { //801BEDFC
  undefined *puVar1;
  
  puVar1 = this->state;
  Object_removePlayerObj(this,4);
  if (this->child[0] != (ObjInstance *)0x0) {
    Object_objFreeObject(this->child[0]);
    this->child[0] = (ObjInstance *)0x0;
  }
                    /* {@symbol 80163ca0} */
  (**(code **)(*(int *)pDll_partfx1F + 0x40))(this,puVar1,1);
  return;
}


undefined4 wall_crawler_func08(ObjInstance *this) { //801BEE70
  return 0x14b;
}


/* @description Get extra size for object (size of State struct) */

int wall_crawler_getExtraSize(void) { //801BEE78
  return 0x3f8;
}


void wall_crawler_setScale(ObjInstance *this,float scale) { //801BEE80
  return;
}


void wall_crawler_func0B(void) { //801BEEA0
  return;
}

