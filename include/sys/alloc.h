#ifndef _SYS_ALLOC_H_
#define _SYS_ALLOC_H_
typedef enum {
    ALLOC_TAG_ZERO               = 0x00000000,
    ALLOC_TAG_LISTS_COL          = 0x00000001,
    ALLOC_TAG_SCREEN_COL         = 0x00000002,
    ALLOC_TAG_CODE_COL           = 0x00000003,
    ALLOC_TAG_DLL_COL            = 0x00000004,
    ALLOC_TAG_TRACK_COL          = 0x00000005,
    ALLOC_TAG_TEX_COL            = 0x00000006,
    ALLOC_TAG_TRACKTEX_COL       = 0x00000007,
    ALLOC_TAG_SPRITETEX_COL      = 0x00000008,
    ALLOC_TAG_MODELS_COL         = 0x00000009,
    ALLOC_TAG_ANIMS_COL          = 0x0000000A,
    ALLOC_TAG_AUDIO_COL          = 0x0000000B,
    ALLOC_TAG_SEQ_COL            = 0x0000000C,
    ALLOC_TAG_SFX_COL            = 0x0000000D,
    ALLOC_TAG_OBJECTS_COL        = 0x0000000E,
    ALLOC_TAG_CAM_COL            = 0x0000000F,
    ALLOC_TAG_VOX_COL            = 0x00000010,
    ALLOC_TAG_ANIMSEQ_COL        = 0x00000011,
    ALLOC_TAG_LFX_COL            = 0x00000012,
    ALLOC_TAG_GFX_COL            = 0x00000013,
    ALLOC_TAG_EXPGFX_COL         = 0x00000014,
    ALLOC_TAG_MODGFX_COL         = 0x00000015,
    ALLOC_TAG_PROJGFX_COL        = 0x00000016,
    ALLOC_TAG_SKY_COL            = 0x00000017,
    ALLOC_TAG_SHAD_COL           = 0x00000018,
    ALLOC_TAG_GAME_COL           = 0x00000019,
    ALLOC_TAG_TEST_COL           = 0x0000001A,
    ALLOC_TAG_BLACK              = 0x0000001B,
    ALLOC_TAG_RED                = 0x0000001C,
    ALLOC_TAG_GREEN              = 0x0000001D,
    ALLOC_TAG_BLUE               = 0x0000001E,
    ALLOC_TAG_CYAN               = 0x0000001F,
    ALLOC_TAG_MAGENTA            = 0x00000020,
    ALLOC_TAG_YELLOW             = 0x00000021,
    ALLOC_TAG_WHITE              = 0x00000022,
    ALLOC_TAG_GREY               = 0x00000023,
    ALLOC_TAG_ORANGE             = 0x00000024,
    ALLOC_TAG_MODEL_INSTANCE     = 0x00000089,
    ALLOC_TAG_OBJECTS            = 0x0000EEFF,
    ALLOC_TAG_VOX                = 0x00880099,
    ALLOC_TAG_ANIMS              = 0x008888FF,
    ALLOC_TAG_TRACK              = 0x00EE00FF,
    ALLOC_TAG_MODELS             = 0x00EEEEFF,
    ALLOC_TAG_GAME               = 0x12345678,
    ALLOC_TAG_ANIMSEQ            = 0x4050FFFF,
    ALLOC_TAG_FILE               = 0x7D7D7D7D,
    ALLOC_TAG_CODE               = 0x7E7E7EFE,
    ALLOC_TAG_SHAD               = 0x7F7F7F99,
    ALLOC_TAG_COMPRESSED_FILE    = 0x7F7F7FFF,
    ALLOC_TAG_CAM                = 0x88000099,
    ALLOC_TAG_DLL                = 0x8E8E8EFE,
    ALLOC_TAG_LISTS              = 0xCECECEFE,
    ALLOC_TAG_SFX                = 0xEE0000BB,
    ALLOC_TAG_SEQ                = 0xEE0000DD,
    ALLOC_TAG_AUDIO              = 0xEE0000FF,
    ALLOC_TAG_SPRITETEX          = 0xEE00EE99,
    ALLOC_TAG_TRACKTEX           = 0xEE00EECC,
    ALLOC_TAG_TEX                = 0xEE00EEFF,
    ALLOC_TAG_SCREEN             = 0xEEEEEEFE,
    ALLOC_TAG_FACEFEED           = 0xFACEFEED,
    ALLOC_TAG_SKY                = 0xFF3300FF,
    ALLOC_TAG_PROJGFX            = 0xFF5500FF,
    ALLOC_TAG_MODGFX             = 0xFF7700FF,
    ALLOC_TAG_EXPGFX             = 0xFF9900FF,
    ALLOC_TAG_GFX                = 0xFFAA00FF,
    ALLOC_TAG_LFX                = 0xFFCC00FF,
    ALLOC_TAG_TEST               = 0xFFDD00FF,
    ALLOC_TAG_INTERSECT_POINT    = 0xFFFF00FF,
    ALLOC_TAG_SAVEGAME           = 0xFFFFFFFF,
} AllocTag;

//in final this is 3 (XXX double check)
#define MAX_HEAPS 8

typedef struct {
  /* 0x0 */ uint mode;
  /* 0x4 */ ushort width;
  /* 0x6 */ ushort height;
  /* 0x8 */ short height2;
  /* 0xa */ short unkA;
  /* 0xc */ short unkC;
  /* 0xe */ ushort width2;
  /* 0x10 */ ushort height3;
  /* 0x12 */ u8 unk12;
  /* 0x13 */ u8 unk13;
  /* 0x14 */ uint unk14;
} TVParams; //XXX should be part of dolphin?

typedef struct {
  /* 0x0 */ void *loc;
  /* 0x4 */ u32 size;
} HeapEntryStruct80355698;

typedef struct {
  //IIRC in final this field is just void* and this
  //sub-struct doesn't exist
  /* 0x0 */ HeapEntryStruct80355698 entry;
  /* 0x8 */ s16 type;
  /* 0xa */ s16 prev;
  /* 0xc */ s16 next;
  /* 0xe */ s16 stack;
  /* 0x10 */ u32 tag;
} HeapEntry;

typedef struct {
  /* 0x0 */ int avail;
  /* 0x4 */ int used;
  /* 0x8 */ HeapEntry *data;
  /* 0xc */ int size;
  /* 0x10 */ int used2;
} Heap;

typedef struct {
    /* 0x0 */ void *ptr;
    /* 0x4 */ u8 delay;
} FreeListEntry;
#define MAX_FREELIST_SIZE 1024

void initHeaps(void);
void *heapInit(HeapEntry *addr, int size, int nSlots);
//XXX fake match, name should be const char*
void *mmAlloc(volatile int size, volatile u32 tag, volatile u32 name);
void *realloc(void *volatile offset, volatile int size, const char *name);
void *mmAlloc2(volatile int size, u32 tag, const char *name);
void *heapAlloc(volatile int heap, volatile int size, u32 tag, const char *name);
void mmSetDelay(int delay);
void mmFree(void *__ptr);
void checkHeaps(void);
int heapSetEntry(int iHeap, int iEntry, int size, int type, int type2, u32 tag,
    const char *name);
int getTotalHeapUsed(int unused);

#endif //_SYS_ALLOC_H_
