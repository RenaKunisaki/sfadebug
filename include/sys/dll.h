#ifndef _SYS_DLL_H_
#define _SYS_DLL_H_
//XXX file here is DLL*
typedef int (*DLL_func)(void *file);

typedef struct {
    /* 0x0 */ union {
        //possibly the onLoad signature is only newer game versions?
        int (*onLoad)(void *thisdll);
        void (*func0)(void);
    } _0;
    /* 0x4 */ union {
        int (*onUnload)(void *thisdll);
        void (*func1)(void);
        void(*Object_onLoad)(struct ObjInstance *object); //XXX does this really exist?
    } _4;
    /* 0x8 */ //int (*func[0])(); //func 0 is a model callback
    /* 0x8 */ union {
        struct {
            /* 0x08 */ void(*update)(struct ObjInstance *object);
            /* 0x0c */ void(*hitDetect)(struct ObjInstance *object);
            /* 0x10 */ void(*render)(struct ObjInstance *object, undefined4 param2, undefined4 param3, undefined4 param4, undefined4 param5, BOOL shouldRender);
            /* 0x14 */ void(*onFreeObjDef)(struct ObjInstance *object, undefined4);
            /* 0x18 */ u32 (*getModelFlags)(struct ObjInstance *object); //in final, this is done inline
            /* 0x1c */ int (*getExtraSize)(struct ObjInstance *object, int size); //returns sizeof(this obj's State)
            /* 0x20 */ UNKTYPE *setScale;
            /* 0x24 */ UNKTYPE *unk24;
            /* 0x28 */ void (*modelMtxFn_0x28)(struct ObjInstance *object, undefined4, Vec * );
            /* 0x2c */ UNKTYPE *render2C; //called for child of player object with ID 0x2d
        } Object;
    };
} DLL_funcs;

typedef struct DLL {
    /* 0x0 */ struct DLL *prev;
    /* 0x4 */ struct DLL *next;
    /* 0x8 */ int (*_08)(void *thisdll);
    /* 0xc */ ushort nFuncs; //includes onUnload but not onLoad
    /* 0xe */ ushort _0E;
    /* 0x10 */ DLL_funcs funcs;
} DLL;

typedef struct {
    /* 0x0 */ DLL_funcs *funcs;
    /* 0x4 */ UNKTYPE *_0C; //maybe rodata? seems to be set by uninitialized var
    /* 0x8 */ int id;
    /* 0xc */ int refCount;
} LoadedDLL;

BOOL DLL_free(LoadedDLL *dll);
LoadedDLL* runlinkDownloadCode(ushort id, ushort param);

#endif //_SYS_DLL_H_
