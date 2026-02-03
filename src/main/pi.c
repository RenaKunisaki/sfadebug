#include "dolphin.h"
#include "types.h"
#include "debug/debug.h"
#include "sys/alloc.h"
#include "sys/n64.h"
#include "gfx/gbi.h"
#include "gfx/render.h"
#include "gfx/textures.h"
#include "sys/dll.h"
#include "obj/ObjDef.h"
#include "obj/ObjInstance.h"
#include "maps/Map.h"
#include "save/GameBits.h"
#include "save/SaveGame.h"
#include "sys/pi.h"

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

void* loadDataFile(DataFileId32 file, int);
u32 loadDataFileToBuf(DataFileId32 file,void *buf);
Texture* textureLoad(int id, int);
ObjInstance* Object_objSetupObjectActual(ObjDef *objDef,
    objSetupObjectActual_flags flags,
    MapId mapId,
    s32 romDefNo,
    ObjInstance *pMatrix,
    void *unused);
DLL_func** DLL_setup(uint dllId, ushort exportCount, BOOL bDontCallInit);
void *loadModelInstance(int id, uint flags);
Animation * loadAnimation (Model * model, short id, short id2, void * dest);

typedef struct {
    struct {
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

static struct {
    u8 unk[0x18];
    AssetDef adef;
} AssetDef_80352f00;

int loadAsset(AssetDef *load);

//this buffer is only passed to some functions
//that don't do anything with it
u8 DAT_80352f30[0x7EF];

//XXX where does this go? not here.
/* int retM1_afterLoadAsset(void *param_1,undefined *param_2,int param_3) {
    return -1;
} */

void loadAsset_file(void **dest, DataFileId32 file) { //800777F0
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_FILE;
    AssetDef_80352f00.adef.header.id = file;
    AssetDef_80352f00.adef.header.dest = dest;
    loadAsset(&AssetDef_80352f00.adef);
}

void loadAsset_fileWithOffset(void **dest, DataFileId32 file) { //8007784C
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_FILE_WITH_OFFSET;
    AssetDef_80352f00.adef.header.id = file;
    AssetDef_80352f00.adef.header.dest = dest;
    loadAsset(&AssetDef_80352f00.adef);
}

void loadAsset_fileWithOffsetLength(
    void *dest,DataFileId32 file,int offset,int length) { //800778A8
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_FILE_WITH_ID_SIZE;
    AssetDef_80352f00.adef.header.id = file;
    AssetDef_80352f00.adef.header.dest = dest;
    AssetDef_80352f00.adef.file.offset = offset;
    AssetDef_80352f00.adef.file.size = length;
    loadAsset(&AssetDef_80352f00.adef);
}

void loadAsset_Character(ObjInstance **result,ObjDef *def,uint flags,
int mapId,int objNo,ObjInstance *pMatrix,void *param7) { //8007791C
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_CHARACTER;
    AssetDef_80352f00.adef.character.objDef = def;
    AssetDef_80352f00.adef.character.objFlags = flags;
    AssetDef_80352f00.adef.character.mapId = mapId;
    AssetDef_80352f00.adef.character.objNo = objNo;
    AssetDef_80352f00.adef.character.pMatrix = pMatrix;
    AssetDef_80352f00.adef.character.param7 = param7;
    AssetDef_80352f00.adef.header.dest = result;
    loadAsset(&AssetDef_80352f00.adef);
}

void loadAsset_Texture(void *param1,DataFileId32 param2) { //800779B4
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_TEXTURE;
    AssetDef_80352f00.adef.header.id = param2;
    AssetDef_80352f00.adef.header.dest = param1;
    loadAsset(&AssetDef_80352f00.adef);
}

void loadAsset_DLL(DLL_func **dll,u32 /*DLL_ID*/ dllId,int *param3) { //80077A10
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_DLL;
    AssetDef_80352f00.adef.header.id = dllId;
    AssetDef_80352f00.adef.header.dest = dll;
    AssetDef_80352f00.adef.dll.buffer = param3;
    loadAsset(&AssetDef_80352f00.adef);
}

void loadAsset_modelInstance(void *dest,DataFileId32 id,void *param3) { //80077A78
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_MODEL_INSTANCE;
    AssetDef_80352f00.adef.header.id = id;
    AssetDef_80352f00.adef.header.dest = dest;
    AssetDef_80352f00.adef.modelInstance.buffer = param3;
    loadAsset(&AssetDef_80352f00.adef);
}

void loadAsset_Animation(int *param1,
short param2,short param3,uint param4,Model *model) { //80077AE0
    AssetDef_80352f00.adef.header.unk00 = true;
    AssetDef_80352f00.adef.header.type = ASSET_TYPE_ANIMATION;
    AssetDef_80352f00.adef.header.id = param2;
    AssetDef_80352f00.adef.header.dest = param1; //stores return code
    AssetDef_80352f00.adef.anim.unk0C = param3;
    AssetDef_80352f00.adef.anim.objFlags = param4;
    AssetDef_80352f00.adef.anim.model = model;
    loadAsset(&AssetDef_80352f00.adef);
}

void nop_80077B60(void) { //80077B60
}

void nop_onUnloadMap(void) { //80077B64
}

int loadAsset(AssetDef *load) { //80077B68
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
            piRomLoadAddr(load->header.id,load->header.dest,
                load->file.offset, load->file.size);
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
    return retM1_afterLoadAsset(&AssetDef_80352f00, NULL, 0);
}

