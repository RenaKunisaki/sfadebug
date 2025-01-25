#include "dolphin.h"
#include "types.h"
#include "debug.h"
#include "alloc.h"
#include "gbi.h"
#include "n64pad.h"
#include "render.h"
#include "dll.h"
#include "ObjDef.h"
#include "ObjInstance.h"
#include "Map.h"
#include "GameBits.h"
#include "SaveGame.h"
#include "files.h"

enum AssetTypeEnum {
    ASSET_TYPE_FILE = 0,
    ASSET_TYPE_FILE_WITH_OFFSET = 1,
    ASSET_TYPE_FILE_WITH_ID_SIZE = 2,
    ASSET_TYPE_TEXTURE = 3,
    ASSET_TYPE_CHARACTER = 4,
    ASSET_TYPE_DLL = 5,
    ASSET_TYPE_MODEL_INSTANCE = 6,
    ASSET_TYPE_ANIMATION = 7,
};

typedef struct { //XXX move, populate
    /* 0x00 */ s8 usage; //reference count
    //...more...
} Animation;
typedef struct {
    int TODO;
} Texture;

void* loadDataFile(DataFileId32 file, int);
Texture* textureLoad(int id, int);
ObjInstance* Object_objSetupObjectActual(ObjDef *objDef,
    u8 /*objSetupObjectActual_flags*/ flags,
    u8 /*MapId8*/ mapId,
    s32 romDefNo,
    ObjInstance *pMatrix,
    void *unused);
DLL_func** DLL_setup(uint dllId, ushort exportCount, BOOL bDontCallInit);
char * loadModelInstance (int id, uint flags);
Animation * loadAnimation (Model * model, short id, short id2, void * dest);

typedef struct {
    struct {
        u8 unk[0x18];
        bool unk00;
        u8 type; //AssetTypeEnum
        int id;
        void *dest;
    } header;
    union {
        struct {
            uint size;
            int offset;
        } file;
        struct {
            int unk0C;
            u8 unk[0x10];
            uint objFlags;
            Model *model;
        } anim;
        struct {
            int *buffer;
            uint size;
            ObjInstance *pMatrix;
            ObjDef *objDef;
            uint objFlags;
            int objNo;
            u32 mapId;
            void *param7;
        } character;
        struct {
            u8 dummy;
        } tex;
        struct {
            int *buffer;
        } dll;
        struct {
            int *buffer;
            uint size;
            uint offset;
            int gameObj;
            ObjDef *object;
            uint objFlags;
            u32 dest;
            void *buffer2;
        } modelInstance;
    };
} AssetDef;

AssetDef AssetDef_80352f00;

void loadAsset_file(void **dest, DataFileId32 file) { //800777F0
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_FILE;
    AssetDef_80352f00.header.id = file;
    AssetDef_80352f00.header.dest = dest;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void loadAsset_fileWithOffset(void **dest, DataFileId32 file) { //8007784C
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_FILE_WITH_OFFSET;
    AssetDef_80352f00.header.id = file;
    AssetDef_80352f00.header.dest = dest;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void loadAsset_fileWithOffsetLength(
    void *dest,DataFileId32 file,int offset,int length) { //800778A8
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_FILE_WITH_ID_SIZE;
    AssetDef_80352f00.header.id = file;
    AssetDef_80352f00.header.dest = dest;
    AssetDef_80352f00.file.offset = offset;
    AssetDef_80352f00.file.size = length;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void loadAsset_Character(ObjInstance **result,ObjDef *def,uint flags,
int mapId,int objNo,ObjInstance *pMatrix,void *param7) { //8007791C
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_CHARACTER;
    AssetDef_80352f00.character.objDef = def;
    AssetDef_80352f00.character.objFlags = flags;
    AssetDef_80352f00.character.mapId = mapId;
    AssetDef_80352f00.character.objNo = objNo;
    AssetDef_80352f00.character.pMatrix = pMatrix;
    AssetDef_80352f00.character.param7 = param7;
    AssetDef_80352f00.header.dest = result;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void loadAsset_Texture(void *param1,DataFileId32 param2) { //800779B4
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_TEXTURE;
    AssetDef_80352f00.header.id = param2;
    AssetDef_80352f00.header.dest = param1;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void loadAsset_DLL(DLL_func **dll,u32 /*DLL_ID*/ dllId,int *param3) { //80077A10
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_DLL;
    AssetDef_80352f00.header.id = dllId;
    AssetDef_80352f00.header.dest = dll;
    AssetDef_80352f00.dll.buffer = param3;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void loadAsset_modelInstance(void *dest,DataFileId32 id,int *param3) { //80077A78
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_MODEL_INSTANCE;
    AssetDef_80352f00.header.id = id;
    AssetDef_80352f00.header.dest = dest;
    AssetDef_80352f00.modelInstance.buffer = param3;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void loadAsset_Animation(int *param1,
short param2,short param3,uint param4,Model *model) { //80077AE0
    AssetDef_80352f00.header.unk00 = true;
    AssetDef_80352f00.header.type = ASSET_TYPE_ANIMATION;
    AssetDef_80352f00.header.id = param2;
    AssetDef_80352f00.header.dest = param1; //stores return code
    AssetDef_80352f00.anim.unk0C = param3;
    AssetDef_80352f00.anim.objFlags = param4;
    AssetDef_80352f00.anim.model = model;
    loadAsset(&AssetDef_80352f00.header.unk00);
}

void nop_80077B60(void) { //80077B60
}

void nop_onUnloadMap(void) { //80077B64
}

int loadAsset(AssetDef *load) { //80077B68
    void *pvVar1;
    ObjInstance *pOVar2;
    Texture *pTVar3;
    DLL_func **ppDVar4;
    char *pcVar5;
    Animation *pAVar6;
    int iVar7;

    switch(load->header.type) {
        case ASSET_TYPE_FILE:
            *(void **)load->header.dest = loadDataFile(
                load->header.id, 0);
            break;

        case ASSET_TYPE_FILE_WITH_OFFSET:
            loadDataFileToBuf(load->header.id,load->header.dest);
            break;

        case ASSET_TYPE_FILE_WITH_ID_SIZE:
            loadDataFileWithLength(load->header.id,load->header.dest,
                load->file.size,(u32)load->file.offset);
            break;

        case ASSET_TYPE_CHARACTER:
            *(ObjInstance **)load->header.dest =
            Object_objSetupObjectActual(
                load->character.objDef,
                (objSetupObjectActual_flags)load->character.objFlags, //objSetupObjectActual_flags
                load->character.mapId, //MapId
                load->character.objNo,
                load->character.pMatrix,
                load->character.param7);
            break;

        case ASSET_TYPE_TEXTURE:
            *(Texture **)load->header.dest = textureLoad(
                load->header.id, 0);
            break;

        case ASSET_TYPE_DLL:
            *(DLL_func ***)load->header.dest = DLL_setup(
                load->header.id & 0xffff,
                (ushort)load->dll.buffer,
                FALSE);
            break;

        case ASSET_TYPE_MODEL_INSTANCE:
            *(char **)load->header.dest = loadModelInstance(
                load->header.id,
                (uint)load->modelInstance.buffer);
            break;

        case ASSET_TYPE_ANIMATION:
            *(Animation **)load->header.dest = loadAnimation(
                (Model*)load->anim.model,
                (short)load->header.id,
                load->anim.unk0C,
                (void *)load->anim.objFlags);
            break;
    }
    return retM1_afterLoadAsset_ret0xFFFF(&AssetDef_80352f00, 0, 0);
}

