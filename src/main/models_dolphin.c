#include "dolphin.h"
#include "dolphin/mtx.h"
#include "gfx/models/shaders.h"
#include "types.h"
#include "debug/debug.h"
#include "sys/alloc.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "gfx/models/models.h"
#include "sys/dll.h"
#include "obj/ObjDef.h"
#include "obj/ObjInstance.h"
#include "sys/files.h"

int DAT_80398a10;
int DWORD_80398a14;
int DWORD_80398a18;

void *loadModelInstance(undefined4 id, undefined4 param2) { // 8007C57C
	void *result;

	loadAsset_modelInstance(&result, id, param2);
	return result;
}

//flags: CreateModelInstanceFlags
ModelInstance *createModelInstance(Model *model, int flags, BOOL bIsNew) { // 8007C5B4
	ModelInstance *minst;
	uint size;
    uint resultSize;
	int ii;
	AnimInstance *anim;
	ModelInstanceField20 *unk20;
	void *next;
    AnimUnk animUnk;

	if(!model) {
		printf("WARNING :: createModelInstance called with NULL pointer\n");
		return NULL;
	}
	size = Model_setupAnimInstance(model, flags, &animUnk, 0);
	minst = (ModelInstance *)mmAlloc(
	    size, ALLOC_TAG_MODEL_INSTANCE, (volatile u32) "minst");
	if(!minst) return NULL;

	memclr(minst, size);
	next = (void*)&minst->field54;
    next = (void*)alignTo16(next);
	minst->jMtxs[0] = next; ADVANCE_PTR(next,animUnk.mtxSize >> 1);
	minst->jMtxs[1] = next; ADVANCE_PTR(next,animUnk.mtxSize >> 1);
	minst->jMtxs4C = minst->jMtxs[0];

	if(model->bCopyVtxsToModelInst
    || model->posFineSkinningConfig) {
		next = (void *)((int)next + 0x1f & ~0x1f);
		minst->vertexPositions  = next; ADVANCE_PTR_BY(next,model->numPositions,S16Vec);
		minst->vertexPositions2 = next; ADVANCE_PTR_BY(next,model->numPositions,S16Vec);
		memcpy(minst->vertexPositions,
		    model->vertexPositions,
		    (uint)model->numPositions * sizeof(S16Vec));
		DCFlushRange(minst->vertexPositions,
            (uint)model->numPositions * sizeof(S16Vec));
	} else {
		minst->vertexPositions  = model->vertexPositions;
		minst->vertexPositions2 = model->vertexPositions;
	}

	next = (void*)alignTo4((uint)next);
	minst->animInstances[0] = next; ADVANCE_PTR_BY(next,1,AnimInstance);

	if(flags & CreateModelInstanceFlags_DoubleBufferAnims) {
		minst->animInstances[1] = next; ADVANCE_PTR_BY(next,1,AnimInstance);
	}

	if(model->flags & ModelDataFlags2_UseLocalModAnimTab) {
		next = (void *)alignTo64((uint)next);
		anim = minst->animInstances[0];
		anim->animData[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
        anim->animData[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		anim->animData[2] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		anim->animData[3] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		if(minst->animInstances[1]) {
			anim = minst->animInstances[1];
			anim->animData[0] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->animData[1] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->animData[2] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
			anim->animData[3] = next; ADVANCE_PTR(next,animUnk.animCacheSize);
		}
	}

	if(model->bCopyVtxsToModelInst) {
		next = (void*)alignTo4((uint)next);
		minst->unk20 = next; ADVANCE_PTR_BY(next,3,ModelInstanceField20);
		for(ii = 0; ii < 3; ii = ii + 1) {
			unk20 = &minst->unk20[ii];
			unk20->animsIdx1 = -1;
            unk20->animsIdx2 = -1;
            unk20->pos       = 0.0f;
            unk20->prevPos   = 0.0f;
            unk20->speed     = 0.0f;
		}
	}

	if(animUnk.hitSphereDataSize > 0) {
		next = (void*)alignTo4((uint)next);
		minst->hitSpheres[0] = next; ADVANCE_PTR_BY(next,model->numHitSpheres,HitSphere);
		minst->hitSpheres[1] = next; ADVANCE_PTR_BY(next,model->numHitSpheres,HitSphere);
		minst->activeHitSphere = minst->hitSpheres[0];
	}

	if(model->joints && model->numJoints && model->radi && model->exT) {
		next = (void*)alignTo4((uint)next);
		minst->skeleton            = next; ADVANCE_PTR_BY(next,1,ModelSkeletonStruct);
		minst->skeleton->joints    = next; ADVANCE_PTR_BY(next,model->numJoints,Vec);
		minst->skeleton->scale     = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->unk08     = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->jointDist = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->totalDist = next; ADVANCE_PTR_BY(next,model->numJoints,float);
		minst->skeleton->unk18     = next; ADVANCE_PTR_BY(next,model->numJoints,u8);
	} else {
        minst->skeleton = NULL;
	}

	if(model->posFineSkinningConfig) {
		next = (void*)alignTo4((uint)next);
		minst->skinVtxs = next; ADVANCE_PTR_BY(next,model->skin.numPieces,VertexPosition*);
	}

	next = (void *)alignTo4((uint)next);
	minst->shaderDefs = next; ADVANCE_PTR_BY(next,model->numShaders,ShaderDef);

	if(flags & CreateModelInstanceFlags_TexturedShadow) {
		next = (void*)alignTo2((uint)next);
		minst->shadow = next; ADVANCE_PTR_BY(next,1,TexturedShadow);
		minst->shadow->state = 0;
	}

    resultSize = (int)next - (int)minst;
	if((int)resultSize >= (int)size) {
		printf("DANGER: createModelInstance: Actual size exceeded totalsize!!!\n");
	}

	minst->unk48 = NULL;
	minst->mod = model;
	minst->bUseVertexPositions1C = 0;
	return minst;
}

#if 0
int Model_setupAnimInstance(Model *model,uint flags,AnimInstance *anim,int param4) { //8007C9C0
  int iVar1;
  s8 *result;

  if (model->animBufSize == 0) {
    anim->mtxSize = 0x80;
  }
  else {
                    /* final: mtxSize = (model->nBones + model->nVtxGroups) * 0x80 */
    anim->mtxSize = (uint)model->numJoints << 7;
  }
  if ((model->bCopyVtxsToModelInst == 0) && (model->skin2Matrices == NULL)) {
    anim->model = (Model *)0x0;
  }
  else {
                    /* final: +0x20 => +0x60 */
    anim->model = (Model *)((uint)model->numPositions * 0xc + 0x20);
  }
  anim->hitboxSize = (float)((uint)model->nHitSpheres << 5);
  anim->unkc = 0;
  if ((model->flags & UseLocalModAnimTab) != 0) {
    anim->unk14 = (float)(int)model->animCacheSize;
    while (((uint)anim->unk14 & 7) != 0) {
      anim->unk14 = (float)((int)anim->unk14 + 1);
    }
    anim->unkc = (int)anim->unk14 << 2;
  }
  anim->unk10 = 0x68;
  if ((flags & 0x80) != 0) {
    anim->unk10 = anim->unk10 << 1;
    anim->unkc = anim->unkc << 1;
  }
  if ((((flags & 1) == 0) && (model->bCopyVtxsToModelInst == 0)) && (param4 == 0)) {
    iVar1 = anim->unkc + anim->mtxSize + (int)anim->hitboxSize + anim->unk10 + 0x5c;
  }
  else {
    anim->unk10 = anim->unk10 + 0x30;
    iVar1 = anim->mtxSize + (int)anim->hitboxSize + anim->unkc + anim->unk10 + 0x5c;
  }
  result = &anim->model->usage + iVar1;
  if (((model->joints != (Bone *)0x0) && (model->numJoints != 0)) && (model->radi != (float *)0x0))
  {
    result = result + (uint)model->numJoints * 2 + (uint)model->numJoints * 0x1c + 0x1c;
  }
  if (model->skin2Matrices != NULL) {
    result = result + (model->unk72 + 1) * 4;
  }
  result = result + (uint)model->nShaders * 8;
  if ((flags & 0x8000) != 0) {
    result = result + 0x1a;
  }
  return ((uint)(result + 0x2f) & 0xfffffff0) + 0x10;
}


uint modelGetAmapSize(uint id,int noAmap,int nAnimations) { //8007CBD0
  uint uVar1;

  if (noAmap == 0) {
    for (uVar1 = nAnimations << 2; (uVar1 & 7) != 0; uVar1 = uVar1 + 1) {
    }
    loadDataFileWithLength(AMAP.TAB,(void *)pAmapTab,(id & 0xfffffffc) << 2,0x20);
    uVar1 = uVar1 + (*(int *)(pAmapTab + ((id & 3) + 1) * 4) - *(int *)(pAmapTab + (id & 3) * 4));
  }
  else {
    for (uVar1 = nAnimations * 2 + 8; (uVar1 & 7) != 0; uVar1 = uVar1 + 1) {
    }
  }
  return uVar1;
}


/* Library Function - Single Match
    makeModelAnimation

   Library: KioskDefault 0 0 */

undefined4 Model_makeModelAnimation(Model *model,uint animId,HitSpherePos *hits) { //8007CC94
  uint uVar1;
  int iVar2;
  Animation *pAVar3;
  int iVar4;
  uint offset;
  int iVar5;
  int animBank;
  int iVar6;
  uint uVar7;
  HitSpherePos *pHVar8;
  uint size;
  dword amap;

  amap = pAmapTab;
  uVar7 = 0;
  loadDataFileWithLength(MODANIM.TAB,(void *)pAmapTab,animId << 1,0x10);
  offset = (uint)*(short *)amap;
  size = (int)((int)*(short *)(amap + 2) - offset) >> 1;
  if (size != model->animBufSize) {
    printf("makeModelAnimation() size mismatch!! (%d,%d)",(uint)model->animBufSize,size);
    model->animBufSize = (ushort)size;
  }
  if (model->animBufSize != 0) {
    size = (uint)model->animBufSize * 2 + 8;
    if (0x800 < size) {
      debugPrint("Warning: Model animation buffer overflow!! size=%d",size);
    }
    loadDataFileWithLength(AMAP.TAB,(void *)pAmapTab,(animId & 0xfffffffc) << 2,0x20);
    uVar1 = animId & 3;
    model->animOffset = *(u32 *)(pAmapTab + uVar1 * 4);
    iVar4 = *(int *)(pAmapTab + uVar1 * 4);
    iVar2 = *(int *)(pAmapTab + (uVar1 + 1) * 4);
    if ((model->flags & UseLocalModAnimTab) == 0) {
      loadDataFileWithLength(MODANIM.BIN,(void *)globalModAnimBuffer,offset,size);
      model->animIds = (HitSpherePos *)globalModAnimBuffer;
    }
    else {
      model->animIds = hits;
      for (uVar7 = size; (uVar7 & 7) != 0; uVar7 = uVar7 + 1) {
      }
      hits = (HitSpherePos *)((int)&hits->radius + uVar7);
      loadDataFileWithLength(MODANIM.BIN,model->animIds,offset,uVar7);
    }
    *(undefined2 *)&model->unk58 = 0;
    animBank = 1;
    for (iVar6 = 0; iVar6 < (int)(uint)model->animBufSize; iVar6 = iVar6 + 1) {
      iVar5 = animBank;
      if (*(short *)((int)&model->animIds->radius + iVar6 * 2) == -1) {
        iVar5 = animBank + 1;
        *(short *)((int)&model->unk58 + animBank * 2) = (short)iVar6 + 1;
      }
      animBank = iVar5;
    }
    if (8 < animBank) {
      printf("ANIMBANK overflow");
    }
    if ((model->flags & UseLocalModAnimTab) == 0) {
      model->animIds = (HitSpherePos *)0x0;
      model->unk4c = hits;
      pHVar8 = (HitSpherePos *)(&hits->radius + model->animBufSize);
      for (uVar7 = uVar7 + (uint)model->animBufSize * 4; (uVar7 & 7) != 0; uVar7 = uVar7 + 1) {
        pHVar8 = (HitSpherePos *)((int)&pHVar8->radius + 1);
      }
      model->curHitSpherePos = pHVar8;
      loadDataFileWithLength(AMAP.BIN,model->curHitSpherePos,model->animOffset,iVar2 - iVar4);
      iVar2 = 0;
      do {
        if (*(short *)(globalModAnimBuffer + iVar2 * 2) == -1) {
          (&model->unk4c->radius)[iVar2] = 0.0;
        }
        else {
          pAVar3 = loadAnimation(model,*(short *)(globalModAnimBuffer + iVar2 * 2),(short)iVar2,
                                 NULL);
          (&model->unk4c->radius)[iVar2] = (float)pAVar3;
          if ((&model->unk4c->radius)[iVar2] == 0.0) {
            for (iVar4 = 0; iVar4 < iVar2; iVar4 = iVar4 + 1) {
              unloadAnimation((s8 *)(&model->unk4c->radius)[iVar4]);
            }
            model->unk4c = (HitSpherePos *)0x0;
            return 1;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)model->animBufSize);
    }
    else {
      model->unk4c = (HitSpherePos *)0x0;
    }
  }
  return 0;
}


void modelSetupAnims(ModelInstance *minst,AnimInstance *param2) { //8007CFA4
  float fVar1;
  Model *model;

  param2->unk44 = 0;
  param2->unk5e = 0;
  param2->unk58 = 0;
  param2->unk5a = 0;
  param2->unk5c = 0;
  param2->unkc = 0.0;
  param2->hitboxSize = 0.0;
  param2->unk14 = 0.0;
  param2->unk60 = 0;
  model = minst->model;
  if (model->animBufSize != 0) {
    if ((model->flags & UseLocalModAnimTab) == 0) {
      fVar1 = (&model->unk4c->radius)[param2->unk44];
    }
    else {
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->unk1c);
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->unk20);
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->unk24);
      loadAnimation(model,*(short *)&model->animIds->radius,0,param2->unk28);
      param2->unk44 = 0;
      fVar1 = (float)((int)(&param2->unk1c)[param2->unk44] + 0x80);
    }
    param2->y = (int)fVar1 + 6;
    param2->unk60 = *(s8 *)((int)fVar1 + 1) & 0xf0;
    param2->unk14 =
         (float)((double)CONCAT44(0x43300000,(uint)*(s8 *)(param2->y + 1)) - 4503599627370496.0);
    if (param2->unk60 == 0) {
      param2->unk14 = param2->unk14 - 1.0;
    }
    param2->unk61 = param2->unk60;
    param2->z = param2->y;
    param2->unk46 = param2->unk44;
    param2->unk8 = param2->hitboxSize;
    param2->mtxSize = (uint)param2->unk14;
    param2->unk10 = param2->unkc;
    param2->unk3c = param2->y;
    param2->unk48 = param2->unk44;
    param2->unk40 = param2->y;
    param2->unk4a = param2->unk44;
  }
  return;
}


undefined4 fn_8007D174(short param_1,short param_2,undefined4 param_3,undefined4 param_4) { //8007D174
  undefined4 local_4;

  local_4 = 0;
  loadAsset_Animation(&local_4,param_1,param_2,param_3,param_4);
  return local_4;
}


void LAB_8007d540(double animTimer,float *modelMatrix,ModelInstance *modelInstance,
                 AnimInstance *animInstance,uint param_5) { //8007D1C4
  uint uVar1;
  uint uVar2;
  Model *pMVar3;
  int iVar4;
  int iVar5;
  undefined auStack_9c [4];
  float local_98 [4];
  void *local_88;
  float local_84;
  void *local_80;
  void *local_7c;
  void *local_78;
  void *local_74;
  int local_68 [4];
  ushort local_58 [10];
  short local_44;
  s8 local_3c [8];
  Mtx44 *local_34 [2];

  pMVar3 = modelInstance->model;
  local_34[0] = modelInstance->mtxs[modelInstance->flags & 1];
  animInstance->hitboxSize = (float)animTimer * animInstance->unk14;
  uVar2 = 0;
  if ((pMVar3->flags & 8) == 0) {
    for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
      if (iVar4 == 0) {
        local_44 = animInstance->unk5a;
      }
      else {
        local_44 = animInstance->unk5c;
      }
      if (local_44 != 0) {
        if (animInstance->unk58 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = 4 << iVar4;
        }
        local_3c[0] = (&animInstance->unk60)[iVar4];
        local_88 = (void *)(&animInstance->unk14)[iVar4];
        local_98[0] = (&animInstance->hitboxSize)[iVar4];
        local_68[0] = (&animInstance->y)[iVar4];
        local_3c[1] = (&animInstance->unk60)[iVar4];
        local_84 = (&animInstance->unk14)[iVar4];
        local_98[1] = (&animInstance->hitboxSize)[iVar4];
        local_68[1] = (&animInstance->unk3c)[iVar4];
        if ((pMVar3->flags & UseLocalModAnimTab) == 0) {
          local_58[0] = (&animInstance->unk44)[iVar4];
          local_58[1] = (&animInstance->unk48)[iVar4];
        }
        else {
          local_58[0] = 0;
          local_58[1] = 1;
          local_80 = (&animInstance->unk1c)[(&animInstance->unk44)[iVar4]];
          local_7c = (&animInstance->unk24)[(ushort)(&animInstance->unk48)[iVar4]];
        }
        LAB_8007da34((int)pMVar3,(int)auStack_9c,2);
        LAB_80066094((dword *)local_34,modelMatrix,(int)auStack_9c,(dword)pMVar3->joints,
                     (uint)pMVar3->numJoints,&lbl_80357698,param_5,uVar1);
        if (uVar1 != 0) {
          uVar2 = uVar2 | 1 << iVar4;
        }
      }
    }
    if (((animInstance->unk5a == 0) && (animInstance->unk5c == 0)) || (uVar2 != 0)) {
      iVar4 = 1;
      if (animInstance->unk58 != 0) {
        iVar4 = 2;
      }
      local_80 = animInstance->unk1c;
      local_7c = animInstance->unk20;
      local_78 = animInstance->unk24;
      local_74 = animInstance->unk28;
      for (iVar5 = 0; iVar5 < iVar4; iVar5 = iVar5 + 1) {
        local_58[iVar5] = (&animInstance->unk44)[iVar5];
        local_3c[iVar5] = (&animInstance->unk60)[iVar5];
        (&local_88)[iVar5] = (void *)(&animInstance->unk14)[iVar5];
        local_98[iVar5] = (&animInstance->hitboxSize)[iVar5];
        local_68[iVar5] = (&animInstance->y)[iVar5];
      }
      local_44 = animInstance->unk58;
      LAB_8007da34((int)pMVar3,(int)auStack_9c,iVar4);
      if ((animInstance->unk63 & 1) != 0) {
        uVar2 = uVar2 | 0x10;
      }
      if ((animInstance->unk63 & 4) != 0) {
        uVar2 = uVar2 | 0x20;
      }
      LAB_80066094((dword *)local_34,modelMatrix,(int)auStack_9c,(dword)pMVar3->joints,
                   (uint)pMVar3->numJoints,&lbl_80357698,param_5,uVar2);
    }
  }
  else {
    local_80 = animInstance->unk1c;
    local_7c = animInstance->unk20;
    local_78 = animInstance->unk24;
    local_74 = animInstance->unk28;
    for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
      iVar5 = iVar4;
      if (animInstance->unk58 == 0) {
        iVar5 = 0;
      }
      local_58[iVar4] = (&animInstance->unk44)[iVar5];
      local_3c[iVar4] = (&animInstance->unk60)[iVar5];
      (&local_88)[iVar4] = (void *)(&animInstance->unk14)[iVar5];
      local_98[iVar4] = (&animInstance->hitboxSize)[iVar5];
      local_68[iVar4] = (&animInstance->y)[iVar5];
    }
    local_44 = animInstance->unk58;
    LAB_8007da34((int)pMVar3,(int)auStack_9c,2);
    if ((animInstance->unk63 & 1) != 0) {
      uVar2 = 0x10;
    }
    if ((animInstance->unk63 & 4) != 0) {
      uVar2 = uVar2 | 0x20;
    }
    LAB_80066094((dword *)local_34,modelMatrix,(int)auStack_9c,(dword)pMVar3->joints,
                 (uint)pMVar3->numJoints,&lbl_80357698,param_5,uVar2 | 0x40);
  }
  return;
}


void LAB_8007d6ec(double param_1,undefined4 param_2,int *param_3,int param_4,uint param_5,
                 uint param_6,uint param_7,s8 param_8,uint param_9,short param_10) { //8007D678
  int iVar1;
  uint uVar2;
  undefined auStack_90 [4];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_4c;
  undefined2 local_4a;
  short local_38;
  undefined local_30;
  undefined local_2f;
  dword local_28 [2];

  iVar1 = *param_3;
  local_28[0] = param_3[(*(ushort *)(param_3 + 6) & 1) + 3];
  if ((param_9 & 0x10) != 0) {
    *(float *)(param_4 + 4) = (float)param_1 * *(float *)(param_4 + 0x14);
  }
  local_30 = *(undefined *)(param_4 + (param_6 & 0xff) + 0x60);
  local_7c = *(undefined4 *)(param_4 + (param_6 & 0xff) * 4 + 0x14);
  local_8c = *(undefined4 *)(param_4 + (param_6 & 0xff) * 4 + 4);
  local_5c = *(undefined4 *)(param_4 + (param_6 & 0xff) * 4 + 0x34);
  local_2f = *(undefined *)(param_4 + (param_7 & 0xff) + 0x60);
  local_78 = *(undefined4 *)(param_4 + (param_7 & 0xff) * 4 + 0x14);
  local_88 = *(undefined4 *)(param_4 + (param_7 & 0xff) * 4 + 4);
  local_58 = *(undefined4 *)(param_4 + (uint)param_8 * 4 + 0x34);
  if ((*(ushort *)(iVar1 + 2) & 0x40) == 0) {
    local_4c = *(undefined2 *)(param_4 + (param_6 & 0xff) * 2 + 0x44);
    local_4a = *(undefined2 *)(param_4 + (uint)param_8 * 2 + 0x44);
  }
  else {
    local_4c = 0;
    local_4a = 1;
    local_74 = *(undefined4 *)
                (param_4 + (uint)*(ushort *)(param_4 + (param_6 & 0xff) * 2 + 0x44) * 4 + 0x1c);
    if (param_8 < 2) {
      local_70 = *(undefined4 *)
                  (param_4 + (uint)*(ushort *)(param_4 + (uint)param_8 * 2 + 0x44) * 4 + 0x1c);
    }
    else {
      local_70 = *(undefined4 *)
                  (param_4 + (uint)*(ushort *)(param_4 + (uint)param_8 * 2 + 0x44) * 4 + 0x24);
    }
  }
  if (param_10 == 0) {
    param_10 = 1;
  }
  local_38 = param_10;
  LAB_8007da34(iVar1,(int)auStack_90,2);
  uVar2 = param_9 & 0xf;
  if ((param_9 & 0xc) == 0) {
    if ((*(s8 *)(param_4 + 99) & 1) != 0) {
      uVar2 = uVar2 | 0x10;
    }
    if ((*(s8 *)(param_4 + 99) & 4) != 0) {
      uVar2 = uVar2 | 0x20;
    }
  }
  LAB_80066094(local_28,param_2,(int)auStack_90,*(dword *)(iVar1 + 0x3c),
               (uint)*(s8 *)(iVar1 + 0xb7),&lbl_80357698,param_5,uVar2);
  return;
}


void LAB_8007da34(int param_1,int param_2,int param_3) { //8007D8E4
  uint uVar1;
  float fVar2;
  s8 bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;

  for (iVar6 = 0; iVar6 < param_3; iVar6 = iVar6 + 1) {
    if ((*(ushort *)(param_1 + 2) & 0x40) == 0) {
      iVar4 = *(int *)(param_1 + 0x50) +
              (uint)*(ushort *)(param_2 + iVar6 * 2 + 0x44) *
              ((*(s8 *)(param_1 + 0xb7) - 1 & 0xfffffff8) + 8);
      iVar5 = *(int *)(*(int *)(param_1 + 0x4c) + (uint)*(ushort *)(param_2 + iVar6 * 2 + 0x44) * 4)
      ;
    }
    else {
      iVar4 = *(int *)(param_2 + (uint)*(ushort *)(param_2 + iVar6 * 2 + 0x44) * 4 + 0x1c);
      iVar5 = *(int *)(param_2 + (uint)*(ushort *)(param_2 + iVar6 * 2 + 0x44) * 4 + 0x1c) + 0x80;
    }
    for (iVar7 = 0; iVar7 < (int)(uint)*(s8 *)(param_1 + 0xb7); iVar7 = iVar7 + 1) {
      *(undefined *)(*(int *)(param_1 + 0x3c) + iVar7 * 0x1c + iVar6 + 2) =
           *(undefined *)(iVar4 + iVar7);
    }
    bVar3 = *(s8 *)(*(int *)(param_2 + iVar6 * 4 + 0x34) + 2);
    uVar1 = (uint)*(float *)(param_2 + iVar6 * 4 + 4);
    fVar2 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - 4503601774854144.0);
    if (fVar2 == *(float *)(param_2 + iVar6 * 4 + 4)) {
      *(undefined2 *)(param_2 + iVar6 * 2 + 0x4c) = 0;
    }
    else {
      *(ushort *)(param_2 + iVar6 * 2 + 0x4c) = (ushort)bVar3;
    }
    if ((*(char *)(param_2 + iVar6 + 0x60) != '\0') &&
       (fVar2 == *(float *)(param_2 + iVar6 * 4 + 0x14) - 1.0)) {
      *(ushort *)(param_2 + iVar6 * 2 + 0x4c) = -(ushort)bVar3 * (short)uVar1;
    }
    *(uint *)(param_2 + iVar6 * 4 + 0x2c) = iVar5 + (int)*(short *)(iVar5 + 2) + bVar3 * uVar1;
  }
  return;
}


/* Library Function - Single Match
    allocModelGlobalAnimBuffer

   Library: KioskDefault 0 0 */

void initModels(void) { //8007DAB0
  void *pvVar1;

  modelsLoadedTable = (dword)SparseArray_SparseArray_create(0x8c,4);
  if ((SparseArray *)modelsLoadedTable == (SparseArray *)0x0) {

    OSPanic("models_dolphin.c",0xa4,"Failed assertion modelsLoadedTable");
  }
  animsLoadedTable = (dword)SparseArray_SparseArray_create(0xc4,4);
  if ((SparseArray *)animsLoadedTable == (SparseArray *)0x0) {

    OSPanic("models_dolphin.c",0xa9,"Failed assertion animsLoadedTable");
  }
  pvVar1 = mmAlloc(0x830,ANIMS_COL,"mod:globalAnimBuffer");
  if (pvVar1 == NULL) {

    OSPanic("models_dolphin.c",0xae,"Failed assertion mem");
  }
  pAmapTab = (int)pvVar1 + 0x800;
  globalModAnimBufferPlus0x810 = (int)pvVar1 + 0x810;
  globalModAnimBuffer = (dword)pvVar1;
  countModels();
  return;
}


/* Library Function - Single Match
    getModelInstance

   Library: KioskDefault 0 0 */

ModelInstance * loadModelInstance(int id,uint flags) { //8007DB84
  uint modelNum;
  BOOL BVar1;
  dword dVar2;
  ModelInstance *minst;
  int iVar3;
  Model *model;

  modelNum = Model_lookupModelInd(id);
  if (((int)modelNum < 0) || ((int)maxModelNum <= (int)modelNum)) {

    OSPanic("models_dolphin.c",0xd2,s_Failed_assertion_modelNum>_0____m_802eb71c);
  }
  BVar1 = SparseArray_SparseArray_get((SparseArray *)modelsLoadedTable,modelNum,&model);
  if (BVar1 == FALSE) {
    model = Model_load(modelNum);
    if (model == (Model *)0x0) {

      OSPanic("models_dolphin.c",0xda,"Failed assertion model");
    }
    dVar2 = isModelAnimDisabled();
    if (dVar2 != 0) {
      model->flags = model->flags | NoAnimations;
    }
    Model_initPtrs(model);
    Model_loadTextures(model);
    Model_loadShaderTextures(model);
    Model_makeModelAnimation
              (model,modelNum,(HitSpherePos *)(&model->usage + model->dataSize));
    SpareArray_SpareArray_set((SparseArray *)modelsLoadedTable,(short)modelNum,&model);
  }
  else {
    model->usage = model->usage + 1;
    if (model->usage == 0xff) {

      OSPanic("models_dolphin.c",0xed,s_Failed_assertion_model_>usage<UC_802eb76c);
    }
  }
  countLeadingZeros(1 - (uint)model->usage);
  minst = ModelInstance_createModelInstance(model,flags);
  if (minst == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0xf3,"Failed assertion modelInstance");
  }
  modelSetupAnims(minst,minst->animInstances[0]);
  if (minst->animInstances[1] != (AnimInstance *)0x0) {
    modelSetupAnims(minst,minst->animInstances[1]);
  }
  LAB_8007e7f8(model,minst);
  iVar3 = Model_checksumHeader(model);
  model->headerCksum = iVar3;
  DCStoreRange(model,model->dataSize);
  return minst;
}


/* Library Function - Single Match
    modelFn_8007dd68

   Library: KioskDefault 0 0 */

void modelInstanceFree(ModelInstance *modelInstance) { //8007DD68
  s8 bVar1;
  Model *model;

  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x11d,"Failed assertion modelInstance");
  }
  ModelInstance_ModelInstance_unloadShaders((Model *)modelInstance);
                    /* XXX this should be Model* but seems to be BitStream? */
  model = modelInstance->model;
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x124,"Failed assertion model");
  }
  if (modelInstance->unk48 != NULL) {
    mmFree(modelInstance->unk48);
  }
  mmFree(modelInstance);
  bVar1 = model->usage - 1;
  model->usage = bVar1;
  if (bVar1 == 0) {
    sparseArrayRemove((short **)modelsLoadedTable,(uint)(ushort)model->cacheModNo);
    texFreeFn_8007e0a8((int)model);
    animUnloadFn_8007e0f8((int)model);
    mmFree(model);
  }
  return;
}


int Model_checksumHeader(Model *model) { //8007DE30
  s8 *pbVar1;
  int iVar2;
  int *end;

  iVar2 = 0;
  end = &model->dataSize;
  pbVar1 = &model->usage;
  for (; model < (Model *)(pbVar1 + *end); model = (Model *)&model->field_0x1) {
    iVar2 = iVar2 + (uint)model->usage;
  }
  return iVar2;
}


/* Library Function - Single Match
    modelFn_8007de70

   Library: KioskDefault 0 0 */

Model * Model_load(uint id) { //8007DE70
  uint *modelsTab;
  uint amapSize;
  uint offset;
  int noAmap;
  uint animCacheSize;
  undefined4 nAnimations;
  size_t size;
  Model *model;

  modelsTab = (uint *)getTable(MODELS.tab);
  offset = modelsTab[id];
  loadModelsBin(offset,&nAnimations,&animCacheSize,&noAmap,(int *)&size);
  animCacheSize = alignTo64(animCacheSize);
  animCacheSize = animCacheSize + 0xb0;
  amapSize = modelGetAmapSize(id,noAmap,nAnimations);
  model = (Model *)mmAlloc(size + amapSize + 500,MODELS_COL,"mod");
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x1eb,"Failed assertion model");
  }
  model = (Model *)alignTo16(model);
  loadAndDecompressDataFile(MODELS.bin,(s8 *)model,offset,size,(uint *)0x0,id,0);
  model->animCacheSize = (short)animCacheSize;
  model->cacheModNo = (short)id;
  model->animBufSize = nAnimations._2_2_;
  model->flags = model->flags & ~UseLocalModAnimTab;
  model->usage = 1;
  if (model->animBufSize == 0) {
    model->flags = model->flags | NoAnimations;
  }
  if (noAmap != 0) {
    model->flags = model->flags | UseLocalModAnimTab;
  }
  return model;
}


/* Library Function - Single Match
    modelFn_8007dff4

   Library: KioskDefault 0 0 */

void Model_loadTextures(Model *model) { //8007DFF4
  Texture *tex;
  int iTex;

  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x21d,"Failed assertion model");
  }
  iTex = 0;
  while( true ) {
    if ((int)(uint)model->numTextures <= iTex) {
      return;
    }
    tex = textureLoad(-((uint)(&model->GCtextures->next)[iTex] | 0x8000));
    (&model->GCtextures->next)[iTex] = tex;
    if ((&model->GCtextures->next)[iTex] == (Texture *)0x0) break;
    iTex = iTex + 1;
  }

  OSPanic("models_dolphin.c",0x222,s_Failed_assertion_model_>GCtextur_802ebb1c);
}


void texFreeFn_8007e0a8(int param1) { //8007E0A8
  int iVar1;

  for (iVar1 = 0; iVar1 < (int)(uint)*(s8 *)(param1 + 0xb6); iVar1 = iVar1 + 1) {
    texFreeTexture(*(Texture **)(*(int *)(param1 + 0x20) + iVar1 * 4));
  }
  return;
}


void animUnloadFn_8007e0f8(int param1) { //8007E0F8
  int iVar1;

  if ((*(int *)(param1 + 0x4c) != 0) && (*(short *)(param1 + 0xb0) != 0)) {
    for (iVar1 = 0; iVar1 < (int)(uint)*(ushort *)(param1 + 0xb0); iVar1 = iVar1 + 1) {
      unloadAnimation(*(s8 **)(*(int *)(param1 + 0x4c) + iVar1 * 4));
    }
  }
  return;
}


/* Library Function - Single Match
    getModelNum_8007e160

   Library: KioskDefault 0 0 */

int Model_lookupModelInd(int id) { //8007E160
  int iVar1;

  if (id < 0) {
    iVar1 = -id;
  }
  else {
    loadDataFileWithLength(MODELIND.bin,(void *)globalModAnimBuffer,id << 1,8);
    iVar1 = (int)*(short *)globalModAnimBuffer;
  }
  return iVar1;
}


/* Library Function - Single Match
    modelInitPtrs

   Library: KioskDefault 0 0 */

void Model_initPtrs(Model *model) { //8007E1B8
  int iVar1;
  void *modelEnd;

  modelEnd = &model->usage + model->dataSize;
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x28a,"Failed assertion model");
  }
  if ((model->sphereHits != NULL) &&
     ((model->sphereHits = &model->usage + (int)model->sphereHits,
      (Model *)model->sphereHits < model || (modelEnd <= model->sphereHits)))) {

    OSPanic("models_dolphin.c",0x28f,s_Failed_assertion_model_>sphereHi_802ebb44);
  }
  if (model->joints != (Bone *)0x0) {
    model->joints = (Bone *)(model->joints->idx + (int)&model->usage + -1);
    if (((Model *)model->joints < model) || (modelEnd <= model->joints)) {

      OSPanic("models_dolphin.c",0x2a3,s_Failed_assertion_model_>joints>__802ebb90);
    }
    if ((model->radi != (float *)0x0) &&
       ((model->radi = (float *)(&model->usage + (int)model->radi), (Model *)model->radi < model ||
        (modelEnd <= model->radi)))) {

      OSPanic("models_dolphin.c",0x2a7,s_Failed_assertion_model_>radi>_mo_802ebbd4);
    }
    if ((model->exT != (u32 *)0x0) &&
       ((model->exT = (u32 *)(&model->usage + (int)model->exT), (Model *)model->exT < model ||
        (modelEnd <= model->exT)))) {

      OSPanic("models_dolphin.c",0x2ac,s_Failed_assertion_model_>exT>_mod_802ebc14);
    }
  }
  if ((model->GCtextures != (Texture *)0x0) &&
     ((model->GCtextures = (Texture *)((int)&model->GCtextures->next + (int)&model->usage),
      (Model *)model->GCtextures < model || (modelEnd <= model->GCtextures)))) {

    OSPanic("models_dolphin.c",0x2b3,s_Failed_assertion_model_>GCtextur_802ebc54);
  }
  model->vertexPositions = (S16Vec *)((int)&model->vertexPositions->x + (int)&model->usage);
  if (((Model *)model->vertexPositions < model) || (modelEnd <= model->vertexPositions)) {

    OSPanic("models_dolphin.c",0x2b6,s_Failed_assertion_model_>vertexPo_802ebca0);
  }
  if ((model->vertexNormals != (S16Vec *)0x0) &&
     ((model->vertexNormals = (S16Vec *)((int)&model->vertexNormals->x + (int)&model->usage),
      (Model *)model->vertexNormals < model || (modelEnd <= model->vertexNormals)))) {

    OSPanic("models_dolphin.c",699,s_Failed_assertion_model_>vertexNo_802ebcf8);
  }
  if ((model->vertexColours != (u16 *)0x0) &&
     ((model->vertexColours = (u16 *)(&model->usage + (int)model->vertexColours),
      (Model *)model->vertexColours < model || (modelEnd <= model->vertexColours)))) {

    OSPanic("models_dolphin.c",0x2c1,s_Failed_assertion_model_>vertexCo_802ebd4c);
  }
  model->vertexTexCoords = (S16Vec *)((int)&model->vertexTexCoords->x + (int)&model->usage);
  if (((Model *)model->vertexTexCoords < model) || (modelEnd <= model->vertexTexCoords)) {

    OSPanic("models_dolphin.c",0x2c5,s_Failed_assertion_model_>vertexTe_802ebda0);
  }
  model->renderStream = (BitStream *)((int)&model->renderStream->data + (int)&model->usage);
  if (((Model *)model->renderStream < model) || (modelEnd <= model->renderStream)) {

    OSPanic("models_dolphin.c",0x2c7,s_Failed_assertion_model_>renderSt_802ebdf8);
  }
  model->displayLists = (DisplayList *)((int)&model->displayLists->displayList + (int)&model->usage)
  ;
  if (((Model *)model->displayLists < model) || (modelEnd <= model->displayLists)) {

    OSPanic("models_dolphin.c",0x2c9,s_Failed_assertion_model_>displayL_802ebe48);
  }
  if ((model->vertexAnims != (undefined4 *)0x0) &&
     ((model->vertexAnims = (undefined4 *)(&model->usage + (int)model->vertexAnims),
      (Model *)model->vertexAnims < model || (modelEnd <= model->vertexAnims)))) {

    OSPanic("models_dolphin.c",0x2ce,s_Failed_assertion_model_>vertexAn_802ebe98);
  }
  if ((model->skin2Matrices != NULL) &&
     ((model->skin2Matrices = &model->usage + (int)model->skin2Matrices,
      (Model *)model->skin2Matrices < model || (modelEnd <= model->skin2Matrices)))) {

    OSPanic("models_dolphin.c",0x2d3,s_Failed_assertion_model_>skin2Mat_802ebee8);
  }
  if ((model->skinWeights != (undefined *)0x0) &&
     ((model->skinWeights = model->skinWeights + (int)&model->usage,
      (Model *)model->skinWeights < model || (modelEnd <= model->skinWeights)))) {

    OSPanic("models_dolphin.c",0x2d8,s_Failed_assertion_model_>skinWeig_802ebf3c);
  }
  if ((model->shaders != (Shader *)0x0) &&
     ((model->shaders = (Shader *)((int)model->shaders->layer + (int)&model->usage + -0x24),
      (Model *)model->shaders < model || (modelEnd <= model->shaders)))) {

    OSPanic("models_dolphin.c",0x2dd,s_Failed_assertion_model_>shaders>_802ebf8c);
  }
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)model->unkb8 <= iVar1) {
      for (iVar1 = 0; iVar1 < (int)(uint)model->bCopyVtxsToModelInst; iVar1 = iVar1 + 1) {
        model->vertexAnims[iVar1] = &model->usage + model->vertexAnims[iVar1];
        if (((Model *)model->vertexAnims[iVar1] < model) ||
           (modelEnd <= (void *)model->vertexAnims[iVar1])) {

          OSPanic("models_dolphin.c",0x2e9,s_Failed_assertion_model_>vertexAn_802ec088);
        }
      }
      if ((model->GCpolygons != (undefined *)0x0) &&
         ((model->GCpolygons = model->GCpolygons + (int)&model->usage,
          (Model *)model->GCpolygons < model || (modelEnd <= model->GCpolygons)))) {

        OSPanic("models_dolphin.c",0x2ef,s_Failed_assertion_model_>GCpolygo_802ec0dc);
      }
      if ((model->polygonGroups != (PolygonGroup *)0x0) &&
         ((model->polygonGroups =
                (PolygonGroup *)((int)&model->polygonGroups->firstPolygon + (int)&model->usage),
          (Model *)model->polygonGroups < model || (modelEnd <= model->polygonGroups)))) {

        OSPanic("models_dolphin.c",0x2f5,s_Failed_assertion_model_>polygonG_802ec128);
      }
      return;
    }
    model->displayLists[iVar1].displayList =
         &model->usage + (int)model->displayLists[iVar1].displayList;
    if ((Model *)model->displayLists[iVar1].displayList < model) break;
    if (modelEnd <= model->displayLists[iVar1].displayList) break;
    if (((uint)model->displayLists[iVar1].displayList & 0x1f) != 0) {

      OSPanic("models_dolphin.c",0x2e4,s_Failed_assertion___int_model_>di_802ec044);
    }
    iVar1 = iVar1 + 1;
  }

  OSPanic("models_dolphin.c",0x2e3,s_Failed_assertion_model_>displayL_802ebfd4);
}


void LAB_8007e7f8(Model *model,ModelInstance *minst) { //8007E76C
  int iVar1;

  if ((model->flags & CopyVtxsOnLoad) != 0) {
    model->unk7c = (int)model->skin2Matrices;
    for (iVar1 = 0; iVar1 < (int)(uint)model->unk72; iVar1 = iVar1 + 1) {
      *(int *)(minst->unk34 + iVar1 * 4) =
           (int)&minst->vertexPositions[0]->x +
           *(int *)((int)model->skin2Matrices + iVar1 * 0x74 + 0x60);
      if (*(undefined **)((int)model->skin2Matrices + iVar1 * 0x74 + 100) < model->skinWeights) {
        *(undefined **)((int)model->skin2Matrices + iVar1 * 0x74 + 100) =
             model->skinWeights + *(int *)((int)model->skin2Matrices + iVar1 * 0x74 + 100);
      }
    }
  }
  return;
}


void Model_loadShaderTextures(Model *model) { //8007E814
  Shader *pSVar1;
  int iVar2;
  int iVar3;
  Shader *shader;

  for (iVar2 = 0; iVar2 < (int)(uint)model->nShaders; iVar2 = iVar2 + 1) {
    pSVar1 = model->shaders;
    for (iVar3 = 0; iVar3 < (int)(uint)pSVar1[iVar2].numLayers; iVar3 = iVar3 + 1) {
      if (pSVar1[iVar2].layer[iVar3].texture == (Texture *)0xffffffff) {
        pSVar1[iVar2].layer[iVar3].texture = (Texture *)0x0;
      }
      else {
        pSVar1[iVar2].layer[iVar3].texture =
             (&model->GCtextures->next)[(int)pSVar1[iVar2].layer[iVar3].texture];
      }
    }
    if (pSVar1[iVar2].tex34 == (Texture *)0xffffffff) {
      pSVar1[iVar2].tex34 = (Texture *)0x0;
    }
    else {
      pSVar1[iVar2].tex34 = (&model->GCtextures->next)[(int)pSVar1[iVar2].tex34];
    }
    if (pSVar1[iVar2].tex1C == (undefined4 *********)0xffffffff) {
      pSVar1[iVar2].tex1C = (undefined4 *********)0x0;
    }
    else if (pSVar1[iVar2].tex1C == (undefined4 *********)0xfffffffe) {
      pSVar1[iVar2].tex1C = (undefined4 *********)0x0;
    }
    else {
      pSVar1[iVar2].tex1C =
           (undefined4 *********)(&model->GCtextures->next)[(int)pSVar1[iVar2].tex1C];
    }
    if (pSVar1[iVar2].tex18 == (undefined4 *********)0xffffffff) {
      pSVar1[iVar2].tex18 = (undefined4 *********)0x0;
    }
    else {
      pSVar1[iVar2].tex18 =
           (undefined4 *********)(&model->GCtextures->next)[(int)pSVar1[iVar2].tex18];
    }
    if ((model->flagsA6 & 0xc) == 0) {
      pSVar1[iVar2].unk8 = 0;
    }
    if ((model->flagsA6 & 0xe00) == 0) {
      pSVar1[iVar2].unk14 = 0;
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    modelAnimFn_8007e974

   Library: KioskDefault 0 0 */

void modelAnimFn_8007e974(ModelInstance *modelInstance,int model,int object,float *modelMatrix) { //8007E974
  AnimInstance *pAVar1;
  AnimInstance *anim;
  S16Vec local_38;
  vec3f vStack_30;

  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x393,"Failed assertion modelInstance");
  }
  if (model == 0) {

    OSPanic("models_dolphin.c",0x394,"Failed assertion model");
  }
  if (modelMatrix == (float *)0x0) {

    OSPanic("models_dolphin.c",0x395,"Failed assertion modelMatrix");
  }
  if (object == 0) {

    OSPanic("models_dolphin.c",0x396,"Failed assertion object");
  }
  tiltListFn_8007ebe8(object,(int)modelInstance,model);
  modelInstance_toggleFlag18_1(modelInstance);
  anim = modelInstance->animInstances[0];
  if (anim == (AnimInstance *)0x0) {

    OSPanic("models_dolphin.c",0x39c,"Failed assertion animInstance");
  }
  if ((anim->unk63 & 4) != 0) {
    objAnimFn_8008045c((double)*(float *)(object + 0x98),(double)*(float *)(object + 8),
                       modelInstance,0,0,&vStack_30,&local_38);
    WORD_8039872c = local_38.x;
    WORD_8039872e = local_38.y;
    _WORD_ARRAY_80398730 = local_38.z;
  }
  if ((modelInstance->model->flags & 8) == 0) {
    if ((modelInstance->animInstances[0]->unk63 & 8) == 0) {
      LAB_8007d540((double)*(float *)(object + 0x98),modelMatrix,modelInstance,
                   modelInstance->animInstances[0],0x7f);
      if ((modelInstance->animInstances[1] != (AnimInstance *)0x0) &&
         (-1 < *(short *)(object + 0xa2))) {
        LAB_8007d540((double)*(float *)(object + 0x9c),modelMatrix,modelInstance,
                     modelInstance->animInstances[1],0xffffffff);
      }
    }
    else {
      pAVar1 = modelInstance->animInstances[1];
      LAB_8007d6ec((double)*(float *)(object + 0x98),modelMatrix,(int *)modelInstance,(int)anim,0x7f
                   ,0,0,2,0x14,anim->unk5a);
      LAB_8007d6ec((double)*(float *)(object + 0x9c),modelMatrix,(int *)modelInstance,(int)pAVar1,
                   0x7f,0,0,2,0x18,pAVar1->unk5a);
      LAB_8007d6ec((double)*(float *)(object + 0x98),modelMatrix,(int *)modelInstance,(int)anim,0x7f
                   ,0,0,0,7,pAVar1->unk58);
      LAB_8007d6ec((double)*(float *)(object + 0x98),modelMatrix,(int *)modelInstance,(int)anim,0x7f
                   ,0,1,1,1,anim->unk58);
    }
  }
  else {
    LAB_8007d540((double)*(float *)(object + 0x98),modelMatrix,modelInstance,
                 modelInstance->animInstances[0],0x7f);
  }
  return;
}


/* Library Function - Single Match
    tiltListFn_8007ebe8

   Library: KioskDefault 0 0 */

void tiltListFn_8007ebe8(int param1,int param2,int param3) { //8007EBE8
  s8 bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short *psVar7;
  int iVar8;

  if ((*(ushort *)(param3 + 2) & 0x40) == 0) {
    iVar2 = *(int *)(param3 + 0x50) +
            (uint)*(ushort *)(*(int *)(param2 + 0x24) + 0x44) *
            ((*(s8 *)(param3 + 0xb7) - 1 & 0xfffffff8) + 8);
  }
  else {
    iVar2 = *(int *)(*(int *)(param2 + 0x24) +
                    (uint)*(ushort *)(*(int *)(param2 + 0x24) + 0x44) * 4 + 0x1c);
  }
  iVar5 = *(int *)(param1 + 0x50);
  iVar3 = 0;
  iVar8 = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)*(s8 *)(iVar5 + 0x72); iVar4 = iVar4 + 1) {
    bVar1 = *(s8 *)(iVar3 + *(char *)(param1 + 0xad) + 1 + *(int *)(iVar5 + 0x10));
    if (bVar1 != 0xff) {
      psVar7 = (short *)(*(int *)(param1 + 0x6c) + iVar4 * 0x12);
      sVar6 = (short)((int)*(char *)(iVar2 + (uint)bVar1) << 6);
      if (*psVar7 != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = *psVar7;
        iVar8 = iVar8 + 2;
      }
      if (psVar7[1] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 2;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[1];
        iVar8 = iVar8 + 2;
      }
      if (psVar7[2] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 4;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[2];
        iVar8 = iVar8 + 2;
      }
      if (psVar7[3] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 0xc;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[3];
        iVar8 = iVar8 + 2;
      }
      if (psVar7[4] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 0xe;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[4];
        iVar8 = iVar8 + 2;
      }
      if (psVar7[5] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 0x10;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[5];
        iVar8 = iVar8 + 2;
      }
      if (psVar7[6] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 0x18;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[6];
        iVar8 = iVar8 + 2;
      }
      if (psVar7[7] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 0x1a;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[7];
        iVar8 = iVar8 + 2;
      }
      if (psVar7[8] != 0) {
        *(short *)(&lbl_80357698 + iVar8 * 2) = sVar6 + 0x1c;
        *(short *)(&lbl_80357698 + (iVar8 + 1) * 2) = psVar7[8];
        iVar8 = iVar8 + 2;
      }
    }
    iVar3 = *(char *)(iVar5 + 0x5d) + iVar3 + 1;
  }
  *(undefined2 *)(&lbl_80357698 + iVar8 * 2) = 0x1000;
  if (0x2c < iVar8) {
    printf("Warning! Tiltlist overflow!!");
  }
  return;
}


void ModelInstance_ModelInstance_loadShaders(ModelInstance *minst,ObjInstance *obj) { //8007EE90
  Model *model;
  int iShader;

  model = minst->model;
  if ((minst->flags & ShadersLoaded) == 0) {
    minst->flags = minst->flags | ShadersLoaded;
    for (iShader = 0; iShader < (int)(uint)minst->model->nShaders; iShader = iShader + 1) {
      shaderInit(model->shaders + iShader,(int *)(&minst->shaderDefs->texture + iShader * 2),
                 (int)obj,model->flagsA6);
    }
  }
  return;
}


void ModelInstance_ModelInstance_unloadShaders(Model *model) { //8007EF18
  int iVar1;

  if ((*(ushort *)&model->radi & 0x40) != 0) {
    *(ushort *)&model->radi = *(ushort *)&model->radi & 0xffbf;
    for (iVar1 = 0; iVar1 < (int)(uint)*(s8 *)(*(int *)model + 0xba); iVar1 = iVar1 + 1) {
      shaderFree((Shader **)((int)model->vertexNormals + iVar1 * 8));
    }
  }
  return;
}


/* Library Function - Single Match
    modelShaderFn_8007ef84

   Library: KioskDefault 0 0 */

int Model_getShaderTexture(ModelInstance *param1,int shaderNum) { //8007EF84
  if ((-1 < shaderNum) && (shaderNum < (int)(uint)param1->model->nShaders)) {
    return (int)(&param1->shaderDefs->texture + shaderNum * 2);
  }

  OSPanic("models_dolphin.c",0x47a,s_Failed_assertion_shaderNum>_0____802ec1f4);
}


/* Library Function - Single Match
    modelInstGetjMtx

   Library: KioskDefault 0 0 */

int modelInstGetjMtx(ModelInstance *modelInstance,int param2) { //8007EFF0
  uint uVar1;

  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x491,"Failed assertion modelInstance");
  }
  if (modelInstance->model->numJoints == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)modelInstance->model->numJoints;
  }
  if ((int)uVar1 <= param2) {
    param2 = 0;
  }
  return (int)(modelInstance->mtxs[modelInstance->flags & 1] + param2);
}


/* Library Function - Single Match
    modelInstFn_8007f084

   Library: KioskDefault 0 0 */

void modelInstance_toggleFlag18_1(ModelInstance *modelInstance) { //8007F084
  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x4b3,"Failed assertion modelInstance");
  }
  modelInstance->flags = modelInstance->flags ^ UseOtherMtxs;
  return;
}


/* Library Function - Single Match
    modelInstFn_8007f0dc

   Library: KioskDefault 0 0 */

void ModelInstance_ModelInstance_setField30(ModelInstance *modelInstance,undefined4 cb) { //8007F0DC
  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x4c8,"Failed assertion modelInstance");
  }
  modelInstance->texFuncPtr = cb;
  return;
}


/* Library Function - Single Match
    modelInstFn_8007f134

   Library: KioskDefault 0 0 */

undefined4 modelInstanceGetCallback30(ModelInstance *modelInstance) { //8007F134
  if (modelInstance == (ModelInstance *)0x0) {

    OSPanic("models_dolphin.c",0x4db,"Failed assertion modelInstance");
  }
  return modelInstance->texFuncPtr;
}


void freezeModelFn_8007f184(undefined4 param_1,undefined4 param_2,char param3) { //8007F184
  float fVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ModelInstance *modelInstance;
  void *freezemodel;
  uint jointNum;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  uint uVar10;
  Model *param1;
  ushort *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  double dVar17;
  undefined8 uVar18;
  short local_414 [256];
  int local_214;
  vec3f local_210;
  vec3f local_204;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  float local_1e8;
  float local_1e4;
  vec3f vStack_1e0;
  vec3f local_1d4;
  Mtx43 MStack_1c8;
  Mtx43 MStack_188;
  Mtx43 MStack_148;
  Mtx43 MStack_108;
  Mtx43 *local_c8;
  Mtx43 *local_c4;
  int local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  double local_70;
  double local_68;
  double local_60;

  uVar18 = _savefpr_29();
  modelInstance = (ModelInstance *)((ulonglong)uVar18 >> 0x20);
  if ((modelInstance->unk48 == NULL) &&
     (param1 = modelInstance->model, 1 < param1->numJoints)) {
    iVar7 = param1->numJoints - 1;
    freezemodel = mmAlloc(iVar7 * 0x46c + 0x10,ANIMS_COL,"mod:freezemodel");
    modelInstance->unk48 = freezemodel;
    if (modelInstance->unk48 != NULL) {
      piVar16 = (int *)modelInstance->unk48;
      *(short *)(piVar16 + 2) = (short)iVar7 * 0x58;
      *(short *)((int)piVar16 + 10) = (short)iVar7 * 0x2a;
      *piVar16 = (int)(piVar16 + 4);
      piVar16[1] = *piVar16 + iVar7 * 0x370;
      local_210.x = 0.0;
      local_210.y = 0.0;
      local_210.z = 0.0;
      iVar7 = 0;
      iVar12 = 0;
      for (iVar14 = 0; iVar14 < (int)(uint)param1->numJoints; iVar14 = iVar14 + 1) {
        local_414[iVar14] = -1;
      }
      MTXInverse((Mtx43 *)uVar18,&MStack_188);
      jointNum = (uint)param1->numJoints;
      while (jointNum = jointNum - 1, -1 < (int)jointNum) {
        pcVar5 = (char *)modelGetJoint((int)param1,jointNum);
        if (*pcVar5 != -1) {
          local_c0 = modelGetJoint((int)param1,(int)*pcVar5);
          local_c4 = (Mtx43 *)modelInstGetjMtx(modelInstance,jointNum);
          local_c8 = (Mtx43 *)modelInstGetjMtx(modelInstance,(int)*pcVar5);
          MTXConcat(&MStack_188,local_c4,&MStack_108);
          MTXConcat(&MStack_188,local_c8,&MStack_148);
          MTXMultVec(&MStack_108,&local_210,&local_1d4);
          MTXMultVec(&MStack_148,&local_210,&vStack_1e0);
          VECSubtract(&vStack_1e0.x,&local_1d4.x,&local_1ec);
          if (((param1->radi == (float *)0x0) || (0.0 < param1->radi[jointNum])) &&
             ((local_1ec != 0.0 || ((local_1e8 != 0.0 || (local_1e4 != 0.0)))))) {
            VECNormalize(&local_1ec,&local_1f8);
            local_204.x = 1.0;
            local_204.y = 0.0;
            local_204.z = 0.0;
            dVar17 = VECDotProduct(&local_1f8,&local_204.x);
            if ((0.8999999761581421 < dVar17) || (dVar17 < -0.8999999761581421)) {
              local_204.x = 0.0;
              local_204.y = 1.0;
              local_204.z = 0.0;
            }
            VECCrossProduct(&local_1f8,&local_204.x,&local_1f8);
            VECNormalize(&local_1f8,&local_1f8);
            sVar9 = (short)(iVar7 / 3);
            if (local_414[*pcVar5] == -1) {
              local_414[*pcVar5] = sVar9;
            }
            else {
              local_414[*pcVar5] = -2;
            }
            for (uVar15 = 0; (int)uVar15 < 8; uVar15 = uVar15 + 1) {
              local_60 = (double)CONCAT44(0x43300000,uVar15 ^ 0x80000000);
              MTXRotAxisRad();
              for (uVar10 = 0; (int)uVar10 < 5; uVar10 = uVar10 + 1) {
                local_60 = (double)CONCAT44(0x43300000,uVar10 ^ 0x80000000);
                local_204.z = (float)(local_60 - 4503601774854144.0) * 0.25;
                local_204.x = local_1ec * local_204.z;
                local_204.y = local_1e8 * local_204.z;
                local_204.z = local_1e4 * local_204.z;
                uVar6 = randInt(10,0x3c);
                local_68 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
                if (param1->radi == (float *)0x0) {
                  fVar1 = 0.04;
                }
                else if (param1->radi[jointNum] <= param1->radi[*pcVar5]) {
                  fVar1 = param1->radi[*pcVar5];
                }
                else {
                  fVar1 = param1->radi[jointNum];
                }
                fVar1 = ((float)(local_68 - 4503601774854144.0) * 0.01 + 1.0) * fVar1;
                local_204.x = local_1f8 * fVar1 + local_204.x;
                local_204.y = local_1f4 * fVar1 + local_204.y;
                local_204.z = local_1f0 * fVar1 + local_204.z;
                MTXMultVec(&MStack_1c8,&local_204,&local_204);
                local_204.x = local_204.x + local_1d4.x;
                local_204.y = local_204.y + local_1d4.y;
                local_204.z = local_204.z + local_1d4.z;
                iVar14 = (int)(local_204.x * 256.0);
                local_68 = (double)(longlong)iVar14;
                *(short *)(piVar16[1] + iVar7 * 2) = (short)iVar14;
                iVar14 = (int)(local_204.y * 256.0);
                local_60 = (double)(longlong)iVar14;
                *(short *)(piVar16[1] + (iVar7 + 1) * 2) = (short)iVar14;
                iVar14 = (int)(local_204.z * 256.0);
                local_70 = (double)(longlong)iVar14;
                *(short *)(piVar16[1] + (iVar7 + 2) * 2) = (short)iVar14;
                iVar7 = iVar7 + 3;
              }
            }
            local_214 = iVar7 / 3;
            local_1d4.x = local_1d4.x - local_1ec;
            local_1d4.y = local_1d4.y - local_1e8;
            local_1d4.z = local_1d4.z - local_1e4;
            if (local_414[jointNum] == -1) {
              iVar14 = (int)(local_1d4.x * 256.0);
              local_70 = (double)(longlong)iVar14;
              *(short *)(piVar16[1] + iVar7 * 2) = (short)iVar14;
              iVar14 = (int)(local_1d4.y * 256.0);
              local_68 = (double)(longlong)iVar14;
              *(short *)(piVar16[1] + (iVar7 + 1) * 2) = (short)iVar14;
              iVar14 = (int)(local_1d4.z * 256.0);
              local_60 = (double)(longlong)iVar14;
              *(short *)(piVar16[1] + (iVar7 + 2) * 2) = (short)iVar14;
              iVar7 = iVar7 + 3;
            }
            for (iVar14 = 0; iVar14 < 8; iVar14 = iVar14 + 1) {
              iVar8 = iVar14 + 1;
              if (iVar8 == 8) {
                iVar8 = 0;
              }
              sVar2 = (short)iVar14;
              sVar3 = (short)iVar8;
              if (-1 < local_414[jointNum]) {
                *(short *)(*piVar16 + iVar12 * 10) = local_414[jointNum] + sVar2 * 5 + 4;
                *(short *)(*piVar16 + iVar12 * 10 + 2) = sVar9 + sVar2 * 5;
                *(short *)(*piVar16 + iVar12 * 10 + 4) = sVar9 + sVar3 * 5;
                iVar8 = iVar12 + 1;
                *(short *)(*piVar16 + iVar8 * 10) = local_414[jointNum] + sVar2 * 5 + 4;
                *(short *)(*piVar16 + iVar8 * 10 + 2) = sVar9 + sVar3 * 5;
                *(short *)(*piVar16 + iVar8 * 10 + 4) = local_414[jointNum] + sVar3 * 5 + 4;
                iVar12 = iVar12 + 2;
              }
              for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {
                sVar4 = (short)iVar8;
                *(short *)(*piVar16 + iVar12 * 10) = sVar9 + sVar2 * 5 + sVar4;
                *(short *)(*piVar16 + iVar12 * 10 + 2) = sVar9 + sVar2 * 5 + sVar4 + 1;
                *(short *)(*piVar16 + iVar12 * 10 + 4) = sVar9 + sVar3 * 5 + sVar4 + 1;
                iVar13 = iVar12 + 1;
                *(short *)(*piVar16 + iVar13 * 10) = sVar9 + sVar2 * 5 + sVar4;
                *(short *)(*piVar16 + iVar13 * 10 + 2) = sVar9 + sVar3 * 5 + sVar4 + 1;
                *(short *)(*piVar16 + iVar13 * 10 + 4) = sVar9 + sVar3 * 5 + sVar4;
                iVar12 = iVar12 + 2;
              }
              if (local_414[jointNum] < 0) {
                *(short *)(*piVar16 + iVar12 * 10) = sVar9 + sVar2 * 5;
                *(short *)(*piVar16 + iVar12 * 10 + 2) = sVar9 + sVar3 * 5;
                *(short *)(*piVar16 + iVar12 * 10 + 4) = (short)local_214;
                iVar12 = iVar12 + 1;
              }
            }
          }
        }
      }
      *(short *)(piVar16 + 2) = (short)iVar12;
      for (iVar7 = 0; iVar7 < (int)(uint)*(ushort *)(piVar16 + 2); iVar7 = iVar7 + 1) {
        puVar11 = (ushort *)(*piVar16 + iVar7 * 10);
        local_70 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(piVar16[1] + (uint)puVar11[1] * 6))
        ;
        local_68 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(piVar16[1] + (uint)*puVar11 * 6));
        local_1ec = (float)(local_70 - 4503599627370496.0) - (float)(local_68 - 4503599627370496.0);
        local_60 = (double)CONCAT44(0x43300000,
                                    (uint)*(ushort *)(piVar16[1] + ((uint)puVar11[1] * 3 + 1) * 2));
        uStack_74 = (uint)*(ushort *)(piVar16[1] + ((uint)*puVar11 * 3 + 1) * 2);
        local_78 = 0x43300000;
        local_1e8 = (float)(local_60 - 4503599627370496.0) -
                    (float)((double)CONCAT44(0x43300000,uStack_74) - 4503599627370496.0);
        uStack_7c = (uint)*(ushort *)(piVar16[1] + ((uint)puVar11[1] * 3 + 2) * 2);
        local_80 = 0x43300000;
        uStack_84 = (uint)*(ushort *)(piVar16[1] + ((uint)*puVar11 * 3 + 2) * 2);
        local_88 = 0x43300000;
        local_1e4 = (float)((double)CONCAT44(0x43300000,uStack_7c) - 4503599627370496.0) -
                    (float)((double)CONCAT44(0x43300000,uStack_84) - 4503599627370496.0);
        uStack_8c = (uint)*(ushort *)(piVar16[1] + (uint)puVar11[2] * 6);
        local_90 = 0x43300000;
        uStack_94 = (uint)*(ushort *)(piVar16[1] + (uint)*puVar11 * 6);
        local_98 = 0x43300000;
        local_1f8 = (float)((double)CONCAT44(0x43300000,uStack_8c) - 4503599627370496.0) -
                    (float)((double)CONCAT44(0x43300000,uStack_94) - 4503599627370496.0);
        uStack_9c = (uint)*(ushort *)(piVar16[1] + ((uint)puVar11[2] * 3 + 1) * 2);
        local_a0 = 0x43300000;
        local_a8 = (double)CONCAT44(0x43300000,
                                    (uint)*(ushort *)(piVar16[1] + ((uint)*puVar11 * 3 + 1) * 2));
        local_1f4 = (float)((double)CONCAT44(0x43300000,uStack_9c) - 4503599627370496.0) -
                    (float)(local_a8 - 4503599627370496.0);
        local_b0 = (double)CONCAT44(0x43300000,
                                    (uint)*(ushort *)(piVar16[1] + ((uint)puVar11[2] * 3 + 2) * 2));
        local_b8 = (double)CONCAT44(0x43300000,
                                    (uint)*(ushort *)(piVar16[1] + ((uint)*puVar11 * 3 + 2) * 2));
        local_1f0 = (float)(local_b0 - 4503599627370496.0) - (float)(local_b8 - 4503599627370496.0);
        VECCrossProduct(&local_1ec,&local_1f8,&local_204.x);
        dVar17 = (double)vecFn_80010194(&local_204.x);
        if (dVar17 == 0.0) {
          local_204.x = 0.0;
          local_204.y = 1.0;
          local_204.z = 0.0;
        }
        else {
          VECNormalize(&local_204.x,&local_204.x);
        }
        local_b8 = (double)(longlong)(int)(local_204.x * 127.0);
        *(char *)(puVar11 + 3) = (char)(int)(local_204.x * 127.0);
        local_b0 = (double)(longlong)(int)(local_204.y * 127.0);
        *(char *)((int)puVar11 + 7) = (char)(int)(local_204.y * 127.0);
        local_a8 = (double)(longlong)(int)(local_204.z * 127.0);
        *(char *)(puVar11 + 4) = (char)(int)(local_204.z * 127.0);
      }
      if (param3 == '\0') {
        *(undefined2 *)(piVar16 + 3) = 0;
      }
      else {
        *(undefined2 *)(piVar16 + 3) = 0xffff;
      }
    }
  }
  __restfpr_29();
  return;
}


void LAB_8007fd28(int param_1) { //8007FCF8
  if (*(int *)(param_1 + 0x48) != 0) {
    mmFree(*(void **)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  return;
}


/* Library Function - Single Match
    modelFn_8007fd3c

   Library: KioskDefault 0 0 */

undefined2 modelGetFieldA4(Model *model) { //8007FD3C
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x65b,"Failed assertion model");
  }
  return model->unka4;
}


/* Library Function - Single Match
    modelGetShader

   Library: KioskDefault 0 0 */

Shader * modelGetShader(Model *model,int shaderNum) { //8007FD8C
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x670,"Failed assertion model");
  }
  if ((-1 < shaderNum) && (shaderNum < (int)(uint)model->nShaders)) {
    return model->shaders + shaderNum;
  }

  OSPanic("models_dolphin.c",0x671,s_Failed_assertion_shaderNum>_0____802ec2a0);
}


/* Library Function - Single Match
    modelGetVtxPos

   Library: KioskDefault 0 0 */

S16Vec * modelGetVtxPos(Model *model,int positionNum) { //8007FE10
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x687,"Failed assertion model");
  }
  if ((-1 < positionNum) && (positionNum < (int)(uint)model->numPositions)) {
    return model->vertexPositions + positionNum;
  }

  OSPanic("models_dolphin.c",0x688,s_Failed_assertion_positionNum>_0___802ec2e0);
}


/* Library Function - Single Match
    modelGetGCTexture

   Library: KioskDefault 0 0 */

undefined4 modelGetGCTexture(int param1,int textureNum) { //8007FE94
  if (param1 == 0) {

    OSPanic("models_dolphin.c",0x6e8,"Failed assertion model");
  }
  if ((-1 < textureNum) && (textureNum < (int)(uint)*(s8 *)(param1 + 0xb6))) {
    return *(undefined4 *)(*(int *)(param1 + 0x20) + textureNum * 4);
  }

  OSPanic("models_dolphin.c",0x6e9,s_Failed_assertion_textureNum>_0___802ec3e0);
}


/* Library Function - Single Match
    modelGetJoint

   Library: KioskDefault 0 0 */

int modelGetJoint(int param1,int jointNum) { //8007FF18
  if (param1 == 0) {

    OSPanic("models_dolphin.c",0x6ff,"Failed assertion model");
  }
  if ((-1 < jointNum) && (jointNum < (int)(uint)*(s8 *)(param1 + 0xb7))) {
    return *(int *)(param1 + 0x3c) + jointNum * 0x1c;
  }

  OSPanic("models_dolphin.c",0x700,s_Failed_assertion_jointNum>_0____j_802ec420);
}


/* Library Function - Single Match
    modelGetDisplayList

   Library: KioskDefault 0 0 */

DisplayList * modelGetDisplayList(Model *model,int listNum) { //8007FF9C
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x716,"Failed assertion model");
  }
  if ((-1 < listNum) && (listNum < (int)(uint)model->unkb8)) {
    return model->displayLists + listNum;
  }

  OSPanic("models_dolphin.c",0x717,s_Failed_assertion_listNum>_0____l_802ec45c);
}


/* Library Function - Single Match
    modelGetPolyGroup

   Library: KioskDefault 0 0 */

PolygonGroup * modelGetPolyGroup(Model *model,int groupNum) { //80080020
  if (model == (Model *)0x0) {

    OSPanic("models_dolphin.c",0x772,"Failed assertion model");
  }
  if ((-1 < groupNum) && (groupNum < (int)(uint)(ushort)model->numPolyGroups)) {
    return model->polygonGroups + groupNum;
  }

  OSPanic("models_dolphin.c",0x773,s_Failed_assertion_groupNum>_0____g_802ec58c);
}


/* Library Function - Single Match
    modelGetGCPoly

   Library: KioskDefault 0 0 */

int modelGetGCPoly(Model *model,int polygonNum) { //800800A4
  if ((-1 < polygonNum) && (polygonNum < (int)(uint)(ushort)model->numGcPolygons)) {
    return (int)(model->GCpolygons + polygonNum * 8);
  }

  OSPanic("models_dolphin.c",0x787,s_Failed_assertion_polygonNum>_0___802ec5c8);
}


Animation * loadAnimation(Model *model,short id,short id2,void *dest) { //8008010C
  Animation *pAVar1;

  if (dest == NULL) {
    pAVar1 = getAnimation(id);
  }
  else {
    pAVar1 = modelLoadAnimation(model,(int)id,(int)id2,dest);
  }
  return pAVar1;
}


/* Library Function - Single Match
    modelFn_80080168

   Library: KioskDefault 0 0 */

Animation * modelLoadAnimation(Model *model,int index,int id,void *dest) { //80080168
  uint offset;
  u32 len;
  Animation *result;
  size_t size;

  offset = *(uint *)(animOffsetTbl + index * 4);
  loadAndDecompressDataFile(ANIM.BIN,(s8 *)0x0,offset,0,&size,index,1);
  if (model->animCacheSize + -0x80 <= (int)size) {

    OSPanic("models_dolphin.c",0x866,s_Failed_assertion_animSize<model__802ec6e4);
  }
  result = (Animation *)((int)dest + 0x80);
  if (result == (Animation *)0x0) {

    OSPanic("models_dolphin.c",0x86b,"Failed assertion anim");
  }
  loadAndDecompressDataFile(ANIM.BIN,(s8 *)result,offset,size,(uint *)0x0,index,0);
  len = (model->numJoints - 1 & 0xfffffff8) + 8;
  loadDataFileWithLength(AMAP.BIN,dest,model->animOffset + id * len,len);
  return result;
}


/* Library Function - Single Match
    modAnimFn_80080270

   Library: KioskDefault 0 0 */

Animation * getAnimation(short id) { //80080270
  BOOL found;
  uint offset;
  uint size;
  Animation *result;

  found = SparseArray_SparseArray_get((SparseArray *)animsLoadedTable,(int)id,&result);
  if (found == FALSE) {
    offset = *(uint *)(animOffsetTbl + id * 4);
    loadAndDecompressDataFile(ANIM.BIN,(s8 *)0x0,offset,0,&size,(int)id,1);
    result = (Animation *)mmAlloc(size,ANIMS_COL,"mod:anim");
    if (result == (Animation *)0x0) {

      OSPanic("models_dolphin.c",0x89b,"Failed assertion anim");
    }
    loadAndDecompressDataFile(ANIM.BIN,(s8 *)result,offset,size,(uint *)0x0,(int)id,0);
    result->usage = 1;
    SpareArray_SpareArray_set((SparseArray *)animsLoadedTable,id,&result);
  }
  else {
    result->usage = result->usage + 1;
    if (0xfe < (uint)(int)(char)result->usage) {

      OSPanic("models_dolphin.c",0x8a8,s_Failed_assertion_anim_>usage<UCH_802ec744);
    }
  }
  return result;
}


/* Library Function - Single Match
    modelFn_8008039c

   Library: KioskDefault 0 0 */

void unloadAnimation(s8 *anim) { //8008039C
  s8 sVar1;
  BOOL BVar2;
  s8 *val;
  SparseArrayItem local_14;

  if (anim != (s8 *)0x0) {
    val = anim;
    if (anim == (s8 *)0x0) {

      OSPanic("models_dolphin.c",0x8c8,"Failed assertion anim");
    }
    sVar1 = *anim;
    *anim = sVar1 + -1;
    if ((char)(sVar1 + -1) < 1) {
      BVar2 = sparseArrayFindElem((SparseArray *)animsLoadedTable,&val,(int *)&local_14);
      if ((BVar2 & 0xff) == 0) {

        OSPanic("models_dolphin.c",0x8d2,"Failed assertion success");
      }
      sparseArrayRemove((short **)animsLoadedTable,_local_14);
      mmFree(val);
    }
  }
  return;
}


void objAnimFn_8008045c(double param_1,double scale,ModelInstance *mInst,int whichBuf,int animIdx,
                       vec3f *outPos,S16Vec *outRot) { //8008045C
  uint uVar1;
  float fVar2;
  s8 bVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int anim;
  double extraout_f1;
  undefined8 uVar7;
  short local_5c;
  short local_5a;
  short local_58;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  double local_40;

  uVar7 = _savefpr_30();
  piVar4 = (int *)((ulonglong)uVar7 >> 0x20);
  if (*(short *)(*piVar4 + 0xb0) == 0) {
    outPos->x = 0.0;
    outPos->y = 0.0;
    outPos->z = 0.0;
    outRot->x = 0;
    outRot->y = 0;
    outRot->z = 0;
  }
  if ((int)uVar7 == 0) {
    anim = piVar4[9];
  }
  else {
    anim = piVar4[10];
  }
  uVar5 = *(undefined4 *)(anim + 0x34);
  *(undefined4 *)(anim + 0x34) = *(undefined4 *)(anim + animIdx * 4 + 0x34);
  if ((*(ushort *)(*piVar4 + 2) & 0x40) == 0) {
    iVar6 = *(int *)(*(int *)(*piVar4 + 0x4c) + (uint)*(ushort *)(anim + animIdx * 2 + 0x44) * 4);
  }
  else if (animIdx < 2) {
    iVar6 = *(int *)(anim + (uint)*(ushort *)(anim + animIdx * 2 + 0x44) * 4 + 0x1c) + 0x80;
  }
  else {
    iVar6 = *(int *)(anim + (uint)*(ushort *)(anim + animIdx * 2 + 0x44) * 4 + 0x24) + 0x80;
  }
  *(float *)(anim + 4) = (float)extraout_f1 * *(float *)(anim + 0x14);
  bVar3 = *(s8 *)(*(int *)(anim + 0x34) + 2);
  uVar1 = (uint)*(float *)(anim + 4);
  local_40 = (double)(longlong)(int)uVar1;
  uStack_44 = uVar1 ^ 0x80000000;
  local_48 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  if (fVar2 == *(float *)(anim + 4)) {
    *(undefined2 *)(anim + 0x4c) = 0;
  }
  else {
    *(ushort *)(anim + 0x4c) = (ushort)bVar3;
  }
  if ((*(char *)(anim + 0x60) != '\0') && (fVar2 == *(float *)(anim + 0x14) - 1.0)) {
    *(ushort *)(anim + 0x4c) = -(ushort)bVar3 * (short)uVar1;
  }
  *(uint *)(anim + 0x2c) = iVar6 + (int)*(short *)(iVar6 + 2) + bVar3 * uVar1;
  LAB_800658d0(anim,&local_5c,&outRot->x);
  *(undefined4 *)(anim + 0x34) = uVar5;
  uStack_44 = (int)local_5c ^ 0x80000000;
  local_48 = 0x43300000;
  outPos->x = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0) * 0.001953125;
  local_40 = (double)CONCAT44(0x43300000,(int)local_5a ^ 0x80000000);
  outPos->y = (float)(local_40 - 4503601774854144.0) * 0.001953125;
  uStack_4c = (int)local_58 ^ 0x80000000;
  local_50 = 0x43300000;
  outPos->z = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0) * 0.001953125;
  outPos->x = outPos->x + *(float *)(*(int *)(*piVar4 + 0x3c) + 4);
  outPos->y = outPos->y + *(float *)(*(int *)(*piVar4 + 0x3c) + 8);
  outPos->z = outPos->z + *(float *)(*(int *)(*piVar4 + 0x3c) + 0xc);
  outPos->x = (float)((double)outPos->x * scale);
  outPos->y = (float)((double)outPos->y * scale);
  outPos->z = (float)((double)outPos->z * scale);
  _restfpr_30();
  return;
}


void LAB_8008086c(ModelInstance *param_1,int param_2,ObjInstance *param_3,Mtx43 *param_4,
                 ObjInstance *param_5) { //80080734
  int iVar1;
  Mtx43 *m;
  float fVar2;
  uint uVar3;
  int iVar4;
  vec3f local_5c;
  uint local_50;
  longlong local_48;
  undefined4 local_40;
  uint uStack_3c;

  fVar2 = 0.0;
  if (((param_5->hitstate != (HitState *)0x0) && (param_5->data->bDisableHits != false)) &&
     (uVar3 = (int)param_5->hitstate->objHitsSize >> 2, 0 < (int)uVar3)) {
    uStack_3c = uVar3 ^ 0x80000000;
    local_40 = 0x43300000;
    iVar4 = (int)(param_5->animTimer *
                 (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0));
    local_48 = (longlong)iVar4;
    if ((int)uVar3 <= iVar4) {
      iVar4 = uVar3 - 1;
    }
    fVar2 = *(float *)(&param_5->hitstate->objHits->animId + iVar4 * 2);
  }
  if (param_3->hitstate != (HitState *)0x0) {
    param_3->hitstate->unk9f = param_3->hitstate->unk9f - 1;
    if ((char)param_3->hitstate->unk9f < '\0') {
      param_3->hitstate->unk9f = 0;
    }
    (param_3->hitstate->unk3c).z = (param_3->hitstate->unk3c).y;
    (param_3->hitstate->unk3c).y = fVar2;
  }
  param_1->flags = param_1->flags ^ UseOtherHitboxes;
  local_50 = param_1->flags & 1;
  param_1->unk40 = param_1->animInstances[(param_1->flags >> 2 & 1) + 5];
  m = param_4;
  for (iVar4 = 0; iVar4 < (int)(uint)*(s8 *)(param_2 + 0xb9); iVar4 = iVar4 + 1) {
    if (param_4 == (Mtx43 *)0x0) {
      m = (Mtx43 *)modelInstGetjMtx(param_1,(int)*(short *)(*(int *)(param_2 + 0x40) + iVar4 * 0x18)
                                   );
    }
    if ((iVar4 == 0) && (param_5 != param_3)) {
      local_5c.x = 0.0;
      local_5c.y = 0.0;
      local_5c.z = 0.0;
      MTXMultVec(m,&local_5c,&local_5c);
      (param_3->pos).pos.x = local_5c.x + playerMapOffsetX;
      (param_3->pos).pos.y = local_5c.y;
      (param_3->pos).pos.z = local_5c.z + playerMapOffsetZ;
      objMultPosByMtx(param_3,&(param_3->prevPos).x,&(param_3->prevPos).y,&(param_3->prevPos).z);
    }
    local_5c.x = *(float *)(*(int *)(param_2 + 0x40) + iVar4 * 0x18 + 8);
    local_5c.y = *(float *)(*(int *)(param_2 + 0x40) + iVar4 * 0x18 + 0xc);
    local_5c.z = *(float *)(*(int *)(param_2 + 0x40) + iVar4 * 0x18 + 0x10);
    *(float *)(param_1->unk40 + iVar4 * 0x10) =
         *(float *)(*(int *)(param_2 + 0x40) + iVar4 * 0x18 + 4) * (param_5->pos).scale;
    MTXMultVec(m,&local_5c,(vec3f *)(param_1->unk40 + iVar4 * 0x10 + 4));
    if (param_5->pMatrix != (ObjInstance *)0x0) {
      multVectorByObjMtx((double)*(float *)(param_1->unk40 + iVar4 * 0x10 + 4),
                         (double)*(float *)(param_1->unk40 + iVar4 * 0x10 + 8),
                         (double)*(float *)(param_1->unk40 + iVar4 * 0x10 + 0xc),
                         (float *)(param_1->unk40 + iVar4 * 0x10 + 4),
                         (float *)(param_1->unk40 + iVar4 * 0x10 + 8),
                         (float *)(param_1->unk40 + iVar4 * 0x10 + 0xc),param_5->pMatrix);
      iVar1 = iVar4 * 0x10 + 4;
      *(float *)(param_1->unk40 + iVar1) =
           *(float *)(param_1->unk40 + iVar1) - playerMapOffsetX;
      iVar1 = iVar4 * 0x10 + 0xc;
      *(float *)(param_1->unk40 + iVar1) =
           *(float *)(param_1->unk40 + iVar1) - playerMapOffsetZ;
    }
  }
  return;
}


void LAB_80080ac8(int *param_1) { //80080A50
  if (*(int *)(*param_1 + 0xa0) != 0) {
    vtxAnimFn_800279cc(0.0,param_1,0,-1,-1,7);
    vtxAnimFn_800279cc(0.0,param_1,1,-1,-1,7);
    vtxAnimFn_800279cc(0.0,param_1,2,-1,-1,7);
  }
  return;
}


void vtxAnimFn_800279cc(double param_1,int *param_2,int param_3,int param_4,int param_5,s8 param_6
                       ) { //80080ADC
  float *pfVar1;

  if (((((param_3 < 3) && (*(int *)(*param_2 + 0xa0) != 0)) && (-2 < param_4)) &&
      ((-2 < param_5 && (param_4 < (int)(uint)*(s8 *)(*param_2 + 0xbb))))) &&
     (param_5 < (int)(uint)*(s8 *)(*param_2 + 0xbb))) {
    pfVar1 = (float *)(param_2[8] + param_3 * 0x10);
    if ((param_4 == -1) && (param_5 == -1)) {
      if ((*(char *)(pfVar1 + 3) == -1) && (*(char *)((int)pfVar1 + 0xd) == -1)) {
        return;
      }
      param_6 = param_6 | 6;
    }
    if ((*(char *)(pfVar1 + 3) != param_4) || (*(char *)((int)pfVar1 + 0xd) != param_5)) {
      *(char *)(pfVar1 + 3) = (char)param_4;
      *(char *)((int)pfVar1 + 0xd) = (char)param_5;
      if ((param_6 & 0x10) == 0) {
        *pfVar1 = 0.0;
      }
      pfVar1[1] = -1.0;
      pfVar1[2] = (float)param_1;
      *(s8 *)((int)pfVar1 + 0xe) = param_6 | 4;
    }
  }
  return;
}


void LAB_80080c00(double param_1,int *param_2,int param_3) { //80080BDC
  float *pfVar1;

  if ((param_3 < 3) && (*(int *)(*param_2 + 0xa0) != 0)) {
    pfVar1 = (float *)(param_2[8] + param_3 * 0x10);
    *pfVar1 = (float)param_1;
    *(s8 *)((int)pfVar1 + 0xe) = *(s8 *)((int)pfVar1 + 0xe) | 4;
  }
  return;
}


void modelFn_80080c28(double param1,Model *model) { //80080C28
  int iVar1;
  Texture **ppTVar2;

  if (*(int *)(*(int *)model + 0xa0) != 0) {
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      ppTVar2 = &model->GCtextures->next + iVar1 * 4;
      if (*(char *)(ppTVar2 + 3) == -1) {
        if (*(char *)((int)ppTVar2 + 0xd) != -1) goto LAB_80080c74;
      }
      else {
LAB_80080c74:
        if ((*(s8 *)((int)ppTVar2 + 0xe) & 1) == 0) {
          *ppTVar2 = (Texture *)
                     (float)((double)(float)ppTVar2[2] * param1 + (double)(float)*ppTVar2);
          if ((float)*ppTVar2 <= 1.0) {
            if ((float)*ppTVar2 < 0.0) {
              *ppTVar2 = (Texture *)0.002;
              ppTVar2[2] = (Texture *)0.001;
              *(s8 *)((int)ppTVar2 + 0xe) = *(s8 *)((int)ppTVar2 + 0xe) & 0xfb;
            }
          }
          else {
            *ppTVar2 = (Texture *)0.99;
            ppTVar2[2] = (Texture *)0.001;
            *(s8 *)((int)ppTVar2 + 0xe) = *(s8 *)((int)ppTVar2 + 0xe) & 0xfb;
          }
        }
      }
    }
  }
  return;
}


void LAB_80081008(int *param_1) { //80080D04
  undefined4 in_r9;
  int in_r10;
  short *psVar1;
  short *psVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  dword local_44 [4];
  dword local_34;
  dword local_30;
  short local_2c [2];
  longlong local_28;

  local_44[3] = 0;
  local_34 = 0;
  local_30 = 0;
  local_44[0] = 0;
  local_44[1] = 0;
  local_44[2] = 0;
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0xa0) != 0) {
    local_2c[0] = *(short *)(iVar4 + 0xa8) + 1;
    for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
      pfVar6 = (float *)(param_1[8] + iVar5 * 0x10);
      if (*pfVar6 != pfVar6[1]) {
        *(s8 *)((int)pfVar6 + 0xe) = *(s8 *)((int)pfVar6 + 0xe) & 0xf3;
        *(s8 *)((int)pfVar6 + 0xe) = *(s8 *)((int)pfVar6 + 0xe) | 4;
      }
      local_44[iVar5] = *(s8 *)((int)pfVar6 + 0xe) & 0xc;
      if (*(char *)(pfVar6 + 3) == -1) {
        if ((*(char *)((int)pfVar6 + 0xd) != -1) || ((*(s8 *)((int)pfVar6 + 0xe) & 0xc) != 0))
        goto LAB_80080df0;
      }
      else {
LAB_80080df0:
        local_44[iVar5 + 3] = 1;
      }
      if ((local_44[iVar5] & 4) == 0) {
        if ((local_44[iVar5] & 8) != 0) {
          *(s8 *)((int)pfVar6 + 0xe) = *(s8 *)((int)pfVar6 + 0xe) & 0xf7;
        }
      }
      else {
        *(s8 *)((int)pfVar6 + 0xe) = *(s8 *)((int)pfVar6 + 0xe) & 0xfb;
        *(s8 *)((int)pfVar6 + 0xe) = *(s8 *)((int)pfVar6 + 0xe) | 8;
      }
    }
    if (((local_44[3] != 0) || (local_34 != 0)) || (local_30 != 0)) {
      if (local_34 != 0) {
        local_44[3] = 0;
      }
      if (local_44[2] != 0) {
        local_44[0] = 1;
        local_44[1] = 1;
      }
      iVar5 = 0;
      while( true ) {
        if (2 < iVar5) break;
        pfVar6 = (float *)(param_1[8] + iVar5 * 0x10);
        if ((*(s8 *)((int)pfVar6 + 0xe) & 2) != 0) {
          *(s8 *)((int)pfVar6 + 0xe) = *(s8 *)((int)pfVar6 + 0xe) & 0xfd;
          *pfVar6 = 0.0;
        }
        if ((local_44[iVar5 + 3] != 0) && (local_44[iVar5] != 0)) {
          if (*(char *)(pfVar6 + 3) < '\0') {
            psVar2 = local_2c;
          }
          else {
            psVar2 = *(short **)(*(int *)(iVar4 + 0xa0) + *(char *)(pfVar6 + 3) * 4);
          }
          if (*(char *)((int)pfVar6 + 0xd) < '\0') {
            psVar1 = local_2c;
          }
          else {
            psVar1 = *(short **)(*(int *)(iVar4 + 0xa0) + *(char *)((int)pfVar6 + 0xd) * 4);
          }
          if (iVar5 == 2) {
            if ((local_44[3] == 0) && (local_34 == 0)) {
              pvVar3 = *(void **)(iVar4 + 0x28);
            }
            else {
              pvVar3 = (void *)param_1[7];
            }
          }
          else {
            pvVar3 = *(void **)(iVar4 + 0x28);
          }
          if (*pfVar6 <= 1.0) {
            if (*pfVar6 < 0.0) {
              *pfVar6 = 0.0;
            }
          }
          else {
            *pfVar6 = 1.0;
          }
          local_28 = (longlong)(int)(*pfVar6 * 65536.0);
          modelApplyBoneTransforms
                    (pvVar3,param_1[7],(uint)*(ushort *)(iVar4 + 0xa8),psVar2,psVar1,
                     (int)(*pfVar6 * 65536.0),in_r9,in_r10);
        }
        pfVar6[1] = *pfVar6;
        iVar5 = iVar5 + 1;
      }
      *(undefined *)(param_1 + 0x14) = 1;
    }
  }
  return;
}


void LAB_80081084(ModelInstance *param_1,Mtx43 *param_2,int param_3) { //8008102C
  Mtx43 *pMVar1;
  Model *pMVar2;
  uint param2;
  Mtx43 MStack_4c;

  pMVar2 = param_1->model;
  if (pMVar2->numJoints == 0) {
    pMVar1 = (Mtx43 *)modelInstGetjMtx(param_1,0);
    MTXConcat(param_2,pMVar1,pMVar1);
  }
  else {
    for (param2 = 0; param2 < pMVar2->numJoints; param2 = param2 + 1) {
      pMVar1 = (Mtx43 *)modelInstGetjMtx(param_1,param2);
      MTXTrans(-(double)pMVar2->joints[param2].bindTranslation.x,
               -(double)pMVar2->joints[param2].bindTranslation.y,
               -(double)pMVar2->joints[param2].bindTranslation.z,&MStack_4c.m11);
      MTXConcat(pMVar1,&MStack_4c,&MStack_4c);
      mtxTranspose43(&MStack_4c.m11,(float *)(param_3 + param2 * 0x30));
      MTXConcat(param_2,pMVar1,pMVar1);
    }
  }
  return;
}


void modelApplyBoneTransforms
               (void *param_1,int param_2,uint param_3,short *param_4,short *param_5,int param_6,
               undefined4 param_7,int param_8) { //80081134
  uint unaff_r23;
  u32 len;
  uint unaff_r25;
  uint numBlocks;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  short *local_34;
  short *local_30;
  int local_2c;

  uVar1 = 0;
  uVar2 = param_3;
  if ((uint)WORD_80396cfc < (param_3 & 0xffff)) {
    uVar2 = (uint)WORD_80396cfc;
  }
  numBlocks = (uVar2 & 0xffff) * 6 + 0x1f >> 5 & 0x7ff;
  local_34 = param_4;
  local_30 = param_5;
  local_2c = param_6;
  LCLoadBlocks(&DAT_e0000000,param_1,numBlocks);
  uVar3 = 0;
  len = 0;
  while ((param_3 & 0xffff) != 0) {
    param_3 = param_3 - uVar2;
    if ((param_3 & 0xffff) != 0) {
      unaff_r25 = param_3;
      if ((uint)WORD_80396cfc < (param_3 & 0xffff)) {
        unaff_r25 = (uint)WORD_80396cfc;
      }
      unaff_r23 = (unaff_r25 & 0xffff) * 6 + 0x1f >> 5 & 0x7ff;
      LCLoadBlocks((void *)((uVar3 ^ 1) * 0x2000 + -0x20000000),
                   (void *)((int)param_1 + ((uVar1 & 0xffff) + (uint)WORD_80396cfc) * 6),unaff_r23);
      len = 1;
    }
    LCQueueWait(len);
    modelApplyBoneTransform
              ((undefined4 *)(uVar3 * 0x2000 + -0x20000000),
               (undefined4 *)(uVar3 * 0x2000 + -0x1ffff000),uVar2,&local_34,&local_30,local_2c,
               param_7,param_8);
    LCStoreBlocks((void *)(param_2 + (uVar1 & 0xffff) * 6),(void *)(uVar3 * 0x2000 + -0x1ffff000),
                  numBlocks & 0xffff);
    uVar1 = uVar1 + uVar2;
    len = 1;
    uVar3 = uVar3 ^ 1;
    numBlocks = unaff_r23;
    uVar2 = unaff_r25;
  }
  LCQueueWait(0);
  return;
}


/* Library Function - Single Match
    setMaxModelNum

   Library: KioskDefault 0 0 */

BOOL countModels(void) { //800812A0
  void *pvVar1;
  BOOL uVar2;

  pvVar1 = getTable(MODELS.tab);
  if (pvVar1 == NULL) {
    uVar2 = FALSE;
  }
  else {
    for (maxModelNum = 0; *(int *)((int)pvVar1 + maxModelNum * 4) != -1;
        maxModelNum = maxModelNum + 1) {
    }
    maxModelNum = maxModelNum - 1;
    if (0x7fff < (int)maxModelNum) {

      OSPanic("models_dolphin.c",0xce5,s_Failed_assertion_maxModelNum<_SH_802ec81c);
    }
    animOffsetTbl = (dword)getTable(ANIM.TAB);
    if ((void *)animOffsetTbl == NULL) {
      uVar2 = FALSE;
    }
    else {
      bHaveAnimTab = 0;
      uVar2 = TRUE;
    }
  }
  return uVar2;
}


void modelApplyBoneTransform
               (undefined4 *param_1,undefined4 *param_2,int param_3,short **param_4,short **param_5,
               int param_6,undefined4 param_7,int param_8) { //8008136C
  short sVar1;
  short sVar2;
  short *psVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  int in_r12;
  int iVar7;
  int unaff_r15;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  short *psVar11;
  short *psVar12;
  undefined8 uVar13;

  psVar11 = *param_4;
  psVar12 = *param_5;
  uVar5 = 0;
  iVar8 = 0x10000 - param_6;
LAB_80081390:
  do {
    sVar1 = *psVar11;
    uVar9 = (int)*psVar12 & 0x1fff;
    for (; (int)uVar5 < (int)((int)sVar1 & 0x1fffU); uVar5 = uVar5 + 1) {
      if ((int)uVar9 <= (int)uVar5) {
        uVar13 = LAB_80081578();
        psVar3 = (short *)((ulonglong)uVar13 >> 0x20);
        puVar4 = (undefined2 *)uVar13;
        param_8 = ((uint)(param_8 * param_6) >> 0x10) + (int)*psVar3;
        in_r12 = ((uint)(in_r12 * param_6) >> 0x10) + (int)psVar3[1];
        unaff_r15 = ((uint)(unaff_r15 * param_6) >> 0x10) + (int)psVar3[2];
        *puVar4 = (short)param_8;
        param_1 = (undefined4 *)(psVar3 + 3);
        puVar4[1] = (short)in_r12;
        uVar5 = uVar5 + 1;
        puVar4[2] = (short)unaff_r15;
        param_2 = (undefined4 *)(puVar4 + 3);
        goto LAB_80081390;
      }
      if (param_3 <= (int)uVar5) {
        *param_4 = psVar11;
        *param_5 = psVar12;
        return;
      }
      uVar10 = *param_1;
      sVar2 = *(short *)(param_1 + 1);
      param_1 = (undefined4 *)((int)param_1 + 6);
      *param_2 = uVar10;
      *(short *)(param_2 + 1) = sVar2;
      param_2 = (undefined4 *)((int)param_2 + 6);
    }
    if (uVar5 == uVar9) {
      LAB_80081578();
      iVar6 = param_8;
      iVar7 = in_r12;
      uVar13 = LAB_80081578();
      psVar3 = (short *)((ulonglong)uVar13 >> 0x20);
      puVar4 = (undefined2 *)uVar13;
      param_8 = ((uint)(param_8 * iVar8 + iVar6 * param_6) >> 0x10) + (int)*psVar3;
      in_r12 = ((uint)(iVar7 * iVar8 + in_r12 * param_6) >> 0x10) + (int)psVar3[1];
      unaff_r15 = ((uint)(unaff_r15 * iVar8 + unaff_r15 * param_6) >> 0x10) + (int)psVar3[2];
      *puVar4 = (short)param_8;
      puVar4[1] = (short)in_r12;
      puVar4[2] = (short)unaff_r15;
      param_1 = (undefined4 *)(psVar3 + 3);
      param_2 = (undefined4 *)(puVar4 + 3);
      uVar5 = uVar5 + 1;
    }
    else {
      uVar13 = LAB_80081578();
      psVar3 = (short *)((ulonglong)uVar13 >> 0x20);
      puVar4 = (undefined2 *)uVar13;
      param_8 = ((uint)(param_8 * iVar8) >> 0x10) + (int)*psVar3;
      in_r12 = ((uint)(in_r12 * iVar8) >> 0x10) + (int)psVar3[1];
      unaff_r15 = ((uint)(unaff_r15 * iVar8) >> 0x10) + (int)psVar3[2];
      *puVar4 = (short)param_8;
      puVar4[1] = (short)in_r12;
      puVar4[2] = (short)unaff_r15;
      param_1 = (undefined4 *)(psVar3 + 3);
      param_2 = (undefined4 *)(puVar4 + 3);
      uVar5 = uVar5 + 1;
    }
  } while( true );
}


void LAB_80081578(void) { //80081534
  return;
}


/* Library Function - Single Match
    modelGetVtxPosFloat

   Library: KioskDefault 0 0 */

void modelGetVtxPosFloat(Model *model,int positionNum,vec3f *posVec) { //8008157C
  S16Vec *vp;

  if (posVec == (vec3f *)0x0) {

    OSPanic("models_dolphin.c",0xe3a,"Failed assertion posVec");
  }
  if ((-1 < positionNum) && (positionNum < (int)(uint)model->numPositions)) {
    vp = modelGetVtxPos(model,positionNum);
    posVec->x = (float)((double)CONCAT44(0x43300000,(int)vp->x ^ 0x80000000) - 4503601774854144.0) *
                0.00390625;
    posVec->y = (float)((double)CONCAT44(0x43300000,(int)vp->y ^ 0x80000000) - 4503601774854144.0) *
                0.00390625;
    posVec->z = (float)((double)CONCAT44(0x43300000,(int)vp->z ^ 0x80000000) - 4503601774854144.0) *
                0.00390625;
    return;
  }

  OSPanic("models_dolphin.c",0xe3b,s_Failed_assertion_positionNum>_0___802ec2e0);
}
#endif
