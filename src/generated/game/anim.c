
/* Library Function - Single Match
    ObjSeq_startObjSequence
   
   Library: KioskDefault 0 0 */

void ObjSeq_startObjSequence(int seqNo,ObjInstance *obj,uint flags) { //800D022C
  float fVar1;
  float fVar2;
  float fVar3;
  ObjDefEnum OVar4;
  ushort uVar5;
  ushort uVar6;
  bool bVar7;
  short *dest;
  ObjDef *def;
  ObjInstance *pOVar8;
  short sVar9;
  ObjInstance *heldBy;
  int iVar10;
  int unaff_r23;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  uint local_78;
  
  _savefpr_29();
  bVar7 = false;
  if (seqNo != -1) {
    if ((seqNo < 0) || (*(short *)&obj->data->field_0x7a <= seqNo)) {
      printf("game/anim.c: startObjSequence() seqno out of range [%d][%d]",(int)(short)obj->romdefno,seqNo);
    }
    else {
      iVar12 = 0x19;
      while (iVar12 < 0x2d) {
        iVar13 = iVar12;
        if ((&DAT_80382f40)[iVar12] == 0) {
          (&DAT_80382f40)[iVar12] = 1;
          FUN_800d13d8(iVar12);
          iVar13 = 0x2e;
          unaff_r23 = iVar12;
        }
        iVar12 = iVar13 + 1;
      }
      if (iVar12 == 0x2d) {
        printf("game/anim.c: startObjSequence() couldn't find seqno free (ABORTED)!!");
      }
      else {
        if (obj->data->pSeq != (u16 *)0x0) {
          seqNo = (int)(short)obj->data->pSeq[seqNo];
        }
        if ((obj->curSeq != -1) && (seqOverrideObj == (ObjInstance *)0x0)) {
          endObjSequence((int)obj->curSeq);
        }
        (&DAT_80382f40)[unaff_r23] = (short)seqNo + 1;
        dest = (short *)mmAlloc(0x80,ANIMSEQ_COL,"anim:table");
        loadAsset_fileWithOffsetLength(dest,OBJSEQ.tab,seqNo << 1,8);
        iVar12 = (int)dest[1] - (int)*dest;
        loadAsset_fileWithOffsetLength(dest,OBJSEQ.bin,(int)*dest << 3,iVar12 * 8);
        if (seqOverrideObj != (ObjInstance *)0x0) {
          obj = seqOverrideObj;
        }
        obj->curSeq = (short)unaff_r23;
        heldBy = obj->pMatrix;
        fVar1 = (obj->pos).pos.x;
        fVar2 = (obj->pos).pos.y;
        fVar3 = (obj->pos).pos.z;
        if ((char)DAT_80398f80 < '\0') {
          heldBy = (ObjInstance *)0x0;
          fVar1 = (obj->prevPos).x;
          fVar2 = (obj->prevPos).y;
          fVar3 = (obj->prevPos).z;
        }
        dVar17 = (double)fVar1;
        dVar16 = (double)fVar3;
        dVar15 = (double)fVar2;
        sVar9 = (obj->pos).rotation.x;
        if (DAT_80398f35 != '\0') {
          dVar14 = (double)distanceFn_80293e80((double)(((float)((double)CONCAT44(0x43300000,
                                                                                  (int)(obj->pos).
                                                                                       rotation.x ^
                                                                                  0x80000000) -
                                                                4503601774854144.0) * 3.141593) /
                                                       32767.0));
          dVar17 = -(double)(float)((double)obj->cullDistance * dVar14 - dVar17);
          dVar14 = (double)mathFn_80294204((double)(((float)((double)CONCAT44(0x43300000,
                                                                              (int)(obj->pos).
                                                                                   rotation.x ^
                                                                              0x80000000) -
                                                            4503601774854144.0) * 3.141593) /
                                                   32767.0));
          dVar16 = -(double)(float)((double)obj->cullDistance * dVar14 - dVar16);
        }
        (&DAT_8038319c)[obj->curSeq] = 0;
        (&DAT_803832b0)[obj->curSeq] = 0;
        (&DAT_803831cc)[obj->curSeq] = (int)(short)obj->romdefno;
        for (iVar13 = 0; iVar13 < iVar12; iVar13 = iVar13 + 1) {
          if ((flags & 1 << iVar13) != 0) {
            def = objAlloc(0x28,Override);
            OVar4 = dest[iVar13 * 4 + 3];
            if (OVar4 == None) {
              def->objType = Override;
              *(ObjDefEnum *)&def[1].loadFlags = obj->romdefno + 4;
              if ((obj->romdefno == VariableObj) && (DAT_80396f04 != -1)) {
                *(short *)&def[1].loadFlags = (short)DAT_80396f04 + 4;
              }
              dest[iVar13 * 4 + 2] = dest[iVar13 * 4 + 2] | 0x8000;
            }
            else if (OVar4 == 0xfffe) {
              def->objType = AnimCamera;
              def[1].loadFlags = 0;
              def[1].mapStates2 = 3;
            }
            else if ((dest[iVar13 * 4 + 2] & 0x4000U) == 0) {
              def->objType = OVar4;
              def[1].loadFlags = 0;
              def[1].mapStates2 = 0;
            }
            else {
              def->objType = Override;
              *(ObjDefEnum *)&def[1].loadFlags = OVar4 + 4;
            }
            if ((dest[iVar13 * 4 + 2] & 0x8000U) == 0) {
              *(undefined *)&def[1].pos.x = 1;
              *(undefined *)((int)&def[1].pos.x + 1) = 1;
            }
            else {
              *(undefined *)&def[1].pos.x = 0;
              *(undefined *)((int)&def[1].pos.x + 1) = 0;
            }
            def[1].objType = (ushort)iVar13 & 0xf | (ushort)(seqNo << 4) & 0x7ff0 | 0x8000;
            def[1].allocatedSize = 0xff;
            def[1].mapStates1 = 0xff;
            if (iVar13 == 0) {
              (def->pos).x = (obj->pos).pos.x;
              (def->pos).y = (obj->pos).pos.y;
              (def->pos).z = (obj->pos).pos.z;
            }
            else if ((DAT_80398f3c == '\0') || (def->objType != AnimCamera)) {
              (def->pos).x = (float)dVar17;
              (def->pos).y = (float)dVar15;
              (def->pos).z = (float)dVar16;
            }
            else {
              (def->pos).x = (float)(dVar17 + (double)DAT_80383394);
              (def->pos).y = (float)(dVar15 + (double)DAT_80383398);
              (def->pos).z = (float)(dVar16 + (double)DAT_8038339c);
              DAT_80398f3c = '\0';
            }
            def[1].cullDist = (byte)unaff_r23;
            *(undefined *)((int)&def[1].pos.x + 2) = 1;
            *(byte *)&def[1].pos.y = (byte)dest[iVar13 * 4 + 2] & 0x7f;
            def->loadFlags = isManualLoad;
            def->mapStates2 = 1;
            if (def->objType == AnimCamera) {
              def->loadFlags = isLevelObject;
            }
            if ((def->objType == VariableObj) && (DAT_80396f04 != -1)) {
              def->objType = (ObjDefEnum)DAT_80396f04;
            }
            pOVar8 = objInstantiateCharacter(def,5,-1,-1,heldBy);
            pOVar8->curSeq = -2;
            puVar11 = pOVar8->state;
            *(short *)(puVar11 + 0x1a) = sVar9;
            *(undefined2 *)(puVar11 + 0x66) = 0xffff;
            *(ushort *)(puVar11 + 0x66) = *(ushort *)(puVar11 + 0x66) & 0xfbff;
            for (iVar10 = 0; iVar10 < 4; iVar10 = iVar10 + 1) {
              puVar11[iVar10 + 0x124] = 0;
            }
            if ((dest[iVar13 * 4 + 2] & 0x80U) == 0) {
              puVar11[0x4e] = 0xff;
            }
            else {
              puVar11[0x4e] = 4;
              if ((dest[iVar13 * 4 + 2] & 0x7fU) == 0) {
                local_78 = 0;
              }
              else {
                local_78 = (ushort)dest[iVar13 * 4 + 2] & 0x7f;
              }
              bVar7 = true;
            }
            *(undefined4 *)(puVar11 + 0x104) = *(undefined4 *)(dest + iVar13 * 4);
            uVar5 = dest[iVar13 * 4 + 2];
            uVar6 = uVar5 >> 8;
            if ((uVar6 & 1) != 0) {
              *(ushort *)(puVar11 + 0x66) = *(ushort *)(puVar11 + 0x66) & 0xfffe;
            }
            if ((uVar6 & 2) != 0) {
              *(ushort *)(puVar11 + 0x66) = *(ushort *)(puVar11 + 0x66) & 0xfffd;
            }
            if ((uVar6 & 4) != 0) {
              *(undefined2 *)(puVar11 + 0x1a) = 0;
            }
            if ((uVar6 & 8) != 0) {
              *(ushort *)(puVar11 + 0x66) = *(ushort *)(puVar11 + 0x66) & 0xfeff;
            }
            if ((uVar6 & 0x20) != 0) {
              puVar11[0x78] = puVar11[0x78] | 2;
            }
            *(undefined2 *)(puVar11 + 0x68) = *(undefined2 *)(puVar11 + 0x66);
            if (iVar13 == 0) {
              (&DAT_8038319c)[obj->curSeq] = (byte)(uVar5 >> 8) & 0x3f;
              (&DAT_803831cc)[obj->curSeq] = pOVar8->def->id;
              if (((obj->data->flags & IsWorldObj) != 0) && ((obj->data->flags & 0x8000) == 0)) {
                dVar17 = 0.0;
                dVar15 = 0.0;
                dVar16 = 0.0;
                sVar9 = 0;
                heldBy = obj;
              }
            }
          }
        }
        *(short *)(&DAT_80383110 + obj->curSeq * 2) = sVar9;
        (&DAT_8038316c)[obj->curSeq] = 0;
        (&DAT_80383280)[obj->curSeq] = 0;
        iVar13 = FUN_800d0b04((int)obj);
        if (iVar13 != 0) {
          (&DAT_8038319c)[obj->curSeq] = (&DAT_8038319c)[obj->curSeq] | 0x10;
        }
        activate(unaff_r23,(short)iVar13,(short)iVar12);
        if (bVar7) {
          FUN_800d1520(local_78);
        }
        mm_free(dest);
        DAT_80398f35 = '\0';
        DAT_80398f80 = DAT_80398f80 & 0x7f;
      }
    }
  }
  _restfpr_29();
  return;
}

