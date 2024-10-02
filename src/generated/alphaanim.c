
/* @description Called when DLL is loaded
   @param param Parameter passed to dll_load */

void alphaanim_initialise(undefined4 param) { //801F781C
  return;
}


/* @description Called when DLL is unloaded */

void alphaanim_release(void) { //801F7820
  return;
}


/* @description Set up object instance */

void alphaanim_init(ObjInstance *this,ObjDef *objDef,ObjInstance *obj2,DllInitFlags flags,float x,
                    float y,float z) { //801F7824
  this->state[0x19] = 0xff;
  return;
}


/* Library Function - Single Match
    dll_149_func04
   
   Library: KioskDefault 0 0 */

void AlphaAnimator_update(ObjInstance *this) { //801F7844
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  int iBlock;
  MapBlock *pMVar17;
  uint uVar18;
  void *pvVar19;
  byte bVar20;
  ObjDef *pOVar21;
  int *piVar22;
  
  pOVar21 = this->def;
  piVar22 = (int *)this->state;
  bVar1 = *(byte *)&pOVar21[1].pos.x;
  bVar20 = bVar1 & 3;
  iBlock = getBlockIdxAtCoords((double)(this->pos).pos.x,(double)(this->pos).pos.y,
                               (double)(this->pos).pos.z);
  pMVar17 = mapGetBlockByIdx(iBlock);
  if (pMVar17 == (MapBlock *)0x0) {
    *(undefined *)(piVar22 + 6) = 0;
  }
  else if ((pMVar17->flags & 8) != 0) {
    if (*piVar22 == 0) {
      *(byte *)((int)piVar22 + 0x16) = pOVar21[1].bound;
      if (*piVar22 == 0) {
        *(undefined *)((int)piVar22 + 0x16) = 0;
      }
      if (*(char *)((int)piVar22 + 0x16) == '\0') {
        return;
      }
      piVar22[1] = (int)0.0;
      piVar22[2] = (int)0.0;
      piVar22[3] = (int)(float)((double)CONCAT44(0x43300000,
                                                 (uint)*(ushort *)((int)&pOVar21[1].pos.x + 2)) -
                               4503599627370496.0);
      if (pOVar21[1].objType == None) {
        *(undefined *)((int)piVar22 + 0x17) = 1;
      }
      else {
        uVar18 = mainGetBit((int)(short)pOVar21[1].objType);
        *(char *)((int)piVar22 + 0x17) = (char)uVar18;
      }
      *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].loadFlags;
      sVar2._0_1_ = pOVar21[1].allocatedSize;
      sVar2._1_1_ = pOVar21[1].mapStates1;
      if ((sVar2 != -1) &&
         (sVar3._0_1_ = pOVar21[1].allocatedSize, sVar3._1_1_ = pOVar21[1].mapStates1,
         uVar18 = mainGetBit((int)sVar3), uVar18 != 0)) {
        *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].mapStates2;
        piVar22[1] = (int)((float)piVar22[3] + 1.0);
        *(undefined *)((int)piVar22 + 0x17) = 1;
      }
      if (bVar20 == 3) {
        pvVar19 = mmAlloc(*piVar22 << 2,TRACK_COL,"alphaanim");
        piVar22[4] = (int)pvVar19;
        nop_801F7FDC();
      }
      nop_801F7EC8();
      pMVar17->flags = pMVar17->flags ^ 1;
      nop_801F7EC8();
      pMVar17->flags = pMVar17->flags ^ 1;
    }
    if (*(char *)((int)piVar22 + 0x16) != '\0') {
      if (bVar20 == 2) {
        uVar18 = mainGetBit((int)(short)pOVar21[1].objType);
        *(char *)((int)piVar22 + 0x17) = (char)uVar18;
        if (('\x02' < *(char *)(piVar22 + 6)) &&
           (*(char *)((int)piVar22 + 0x17) != *(char *)((int)piVar22 + 0x19))) {
          if ((int)(uint)*(byte *)&pOVar21[1].pos.x >> 2 != 0) {
            audioTryStartSfx((int *)this,1,*(ushort *)&pOVar21[1].pos.y,0x7f,"alphaanim.c",
                             0x9e);
          }
          *(undefined *)(piVar22 + 6) = 0;
          *(undefined *)((int)piVar22 + 0x19) = *(undefined *)((int)piVar22 + 0x17);
        }
        if ('\x02' < *(char *)(piVar22 + 6)) {
          return;
        }
      }
      else {
        if ('\x02' < *(char *)(piVar22 + 6)) {
          return;
        }
        if (*(char *)((int)piVar22 + 0x17) == '\0') {
          uVar18 = mainGetBit((int)(short)pOVar21[1].objType);
          *(char *)((int)piVar22 + 0x17) = (char)uVar18;
          if (*(char *)((int)piVar22 + 0x17) == '\0') {
            return;
          }
          if ((int)(uint)*(byte *)&pOVar21[1].pos.x >> 2 != 0) {
            audioTryStartSfx((int *)this,1,*(ushort *)&pOVar21[1].pos.y,0x7f,"alphaanim.c",
                             0xb5);
          }
        }
      }
      if (bVar20 == 2) {
        if (*(char *)((int)piVar22 + 0x17) == '\0') {
          if (pOVar21[1].mapStates2 < pOVar21[1].loadFlags) {
            *(ushort *)(piVar22 + 5) =
                 *(short *)(piVar22 + 5) + (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep
            ;
            if ((short)(ushort)pOVar21[1].loadFlags <= *(short *)(piVar22 + 5)) {
              *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].loadFlags;
              sVar12._0_1_ = pOVar21[1].allocatedSize;
              sVar12._1_1_ = pOVar21[1].mapStates1;
              if (sVar12 != -1) {
                sVar13._0_1_ = pOVar21[1].allocatedSize;
                sVar13._1_1_ = pOVar21[1].mapStates1;
                mainSetBits((int)sVar13,0);
              }
              *(char *)(piVar22 + 6) = *(char *)(piVar22 + 6) + '\x01';
            }
          }
          else {
            *(ushort *)(piVar22 + 5) =
                 *(short *)(piVar22 + 5) - (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep
            ;
            if (*(short *)(piVar22 + 5) <= (short)(ushort)pOVar21[1].loadFlags) {
              *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].loadFlags;
              sVar14._0_1_ = pOVar21[1].allocatedSize;
              sVar14._1_1_ = pOVar21[1].mapStates1;
              if (sVar14 != -1) {
                sVar15._0_1_ = pOVar21[1].allocatedSize;
                sVar15._1_1_ = pOVar21[1].mapStates1;
                mainSetBits((int)sVar15,0);
              }
              *(char *)(piVar22 + 6) = *(char *)(piVar22 + 6) + '\x01';
            }
          }
        }
        else if (pOVar21[1].mapStates2 < pOVar21[1].loadFlags) {
          *(ushort *)(piVar22 + 5) =
               *(short *)(piVar22 + 5) - (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep;
          if (*(short *)(piVar22 + 5) <= (short)(ushort)pOVar21[1].mapStates2) {
            *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].mapStates2;
            sVar8._0_1_ = pOVar21[1].allocatedSize;
            sVar8._1_1_ = pOVar21[1].mapStates1;
            if (sVar8 != -1) {
              sVar9._0_1_ = pOVar21[1].allocatedSize;
              sVar9._1_1_ = pOVar21[1].mapStates1;
              mainSetBits((int)sVar9,1);
            }
            *(char *)(piVar22 + 6) = *(char *)(piVar22 + 6) + '\x01';
          }
        }
        else {
          *(ushort *)(piVar22 + 5) =
               *(short *)(piVar22 + 5) + (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep;
          if ((short)(ushort)pOVar21[1].mapStates2 <= *(short *)(piVar22 + 5)) {
            *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].mapStates2;
            sVar10._0_1_ = pOVar21[1].allocatedSize;
            sVar10._1_1_ = pOVar21[1].mapStates1;
            if (sVar10 != -1) {
              sVar11._0_1_ = pOVar21[1].allocatedSize;
              sVar11._1_1_ = pOVar21[1].mapStates1;
              mainSetBits((int)sVar11,1);
            }
            *(char *)(piVar22 + 6) = *(char *)(piVar22 + 6) + '\x01';
          }
        }
      }
      else if (bVar20 < 2) {
        if ((bVar1 & 3) == 0) {
          if (pOVar21[1].mapStates2 < pOVar21[1].loadFlags) {
            *(ushort *)(piVar22 + 5) =
                 *(short *)(piVar22 + 5) - (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep
            ;
            if (*(short *)(piVar22 + 5) <= (short)(ushort)pOVar21[1].mapStates2) {
              *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].mapStates2;
              sVar4._0_1_ = pOVar21[1].allocatedSize;
              sVar4._1_1_ = pOVar21[1].mapStates1;
              if (sVar4 != -1) {
                sVar5._0_1_ = pOVar21[1].allocatedSize;
                sVar5._1_1_ = pOVar21[1].mapStates1;
                mainSetBits((int)sVar5,1);
              }
              *(char *)(piVar22 + 6) = *(char *)(piVar22 + 6) + '\x01';
            }
          }
          else {
            *(ushort *)(piVar22 + 5) =
                 *(short *)(piVar22 + 5) + (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep
            ;
            if ((short)(ushort)pOVar21[1].mapStates2 <= *(short *)(piVar22 + 5)) {
              *(ushort *)(piVar22 + 5) = (ushort)pOVar21[1].mapStates2;
              sVar6._0_1_ = pOVar21[1].allocatedSize;
              sVar6._1_1_ = pOVar21[1].mapStates1;
              if (sVar6 != -1) {
                sVar7._0_1_ = pOVar21[1].allocatedSize;
                sVar7._1_1_ = pOVar21[1].mapStates1;
                mainSetBits((int)sVar7,1);
              }
              *(char *)(piVar22 + 6) = *(char *)(piVar22 + 6) + '\x01';
            }
          }
        }
        else if (true) {
          if (pOVar21[1].mapStates2 < pOVar21[1].loadFlags) {
            *(ushort *)(piVar22 + 5) =
                 *(short *)(piVar22 + 5) - (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep
            ;
            if (*(short *)(piVar22 + 5) < (short)(ushort)pOVar21[1].mapStates2) {
              *(ushort *)(piVar22 + 5) =
                   (ushort)pOVar21[1].loadFlags -
                   ((ushort)pOVar21[1].mapStates2 - *(short *)(piVar22 + 5));
            }
          }
          else {
            *(ushort *)(piVar22 + 5) =
                 *(short *)(piVar22 + 5) + (short)(char)pOVar21[1].cullDist * (ushort)framesThisStep
            ;
            if ((short)(ushort)pOVar21[1].loadFlags < *(short *)(piVar22 + 5)) {
              *(ushort *)(piVar22 + 5) =
                   (ushort)pOVar21[1].mapStates2 +
                   (*(short *)(piVar22 + 5) - (ushort)pOVar21[1].mapStates2);
            }
          }
        }
      }
      else if (bVar20 < 4) {
        if ((char)pOVar21[1].cullDist < '\0') {
          uVar18 = -(int)(char)pOVar21[1].cullDist;
        }
        else {
          uVar18 = (uint)(char)pOVar21[1].cullDist;
        }
        piVar22[1] = (int)(((float)((double)CONCAT44(0x43300000,uVar18 ^ 0x80000000) -
                                   4503601774854144.0) / 10.0) * timeDelta + (float)piVar22[1]);
        if ((float)piVar22[3] < (float)piVar22[1]) {
          piVar22[1] = piVar22[3];
          sVar16._0_1_ = pOVar21[1].allocatedSize;
          sVar16._1_1_ = pOVar21[1].mapStates1;
          mainSetBits((int)sVar16,1);
          *(char *)(piVar22 + 6) = *(char *)(piVar22 + 6) + '\x01';
        }
        piVar22[2] = (int)((float)piVar22[1] - 50.0);
      }
      nop_801F7EC8();
    }
  }
  return;
}


/* @description Override hit detection */

void alphaanim_hitDetect(ObjInstance *this) { //801F7ECC
  return;
}


/* Library Function - Single Match
    dll_149_func06
   
   Library: KioskDefault 0 0 */

void alphaanim_render(ObjInstance *this,undefined param2,undefined param3,undefined param4,
                      undefined param5,bool shouldRender) { //801F7ED0
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  undefined3 in_register_00000018;
  undefined3 in_register_0000001c;
  
  if (shouldRender) {
    objRenderCurrentModel
              (this,(Gfx **)(Gfx *)CONCAT31(in_register_00000010,param2),
               (int *)CONCAT31(in_register_00000014,param3),
               (undefined4 *)CONCAT31(in_register_00000018,param4),
               (undefined4 *)CONCAT31(in_register_0000001c,param5));
    if (((this->pos).flags & 0x100) != 0) {
      FUN_80096374((double)(this->pos).pos.x,(double)(this->pos).pos.y,(double)(this->pos).pos.z,
                   (double)(float)((double)CONCAT44(0x43300000,
                                                    (uint)*(ushort *)((int)&this->def[1].pos.x + 2))
                                  - 4503599627370496.0),8.0,
                   (Gfx *)CONCAT31(in_register_00000010,param2),
                   (int *)CONCAT31(in_register_00000014,param3),0,0xff,0xff);
    }
  }
  return;
}


/* Library Function - Multiple Matches With Different Base Names
    dll_149_func07
    dll_155_func07
   
   Library: KioskDefault 0 0 */

void alphaanim_free(ObjInstance *this,int param2) { //801F7F88
  if (*(int *)(this->state + 0x10) != 0) {
    mm_free(*(void **)(this->state + 0x10));
  }
  return;
}


undefined4 alphaanim_func08(ObjInstance *this) { //801F7FCC
  return 0;
}


/* @description Get extra size for object (size of State struct) */

int alphaanim_getExtraSize(void) { //801F7FD4
  return 0x1c;
}

