#ifndef _SYS_N64_H_
#define _SYS_N64_H_
#define N64_BUTTON_C_RIGHT	1
#define N64_BUTTON_C_LEFT	2
#define N64_BUTTON_C_DOWN	4
#define N64_BUTTON_C_UP	8
#define N64_BUTTON_R	16
#define N64_BUTTON_L	32
#define N64_BUTTON_RIGHT	256
#define N64_BUTTON_LEFT	512
#define N64_BUTTON_DOWN	1024
#define N64_BUTTON_UP	2048
#define N64_BUTTON_START	4096
#define N64_BUTTON_Z	8192
#define N64_BUTTON_B	16384
#define N64_BUTTON_A	32768

typedef u32 N64Button32;
typedef u16 N64Button;

typedef struct {
    /* 0x0 */ undefined4 unk00;
    /* 0x4 */ undefined4 unk04;
    /* 0x8 */ void *frameBuffer;
} RcpQueueItem;

#define RCP_QUEUE_MAX_ITEMS 10
typedef struct {
    /* 0x00 */ RcpQueueItem items[RCP_QUEUE_MAX_ITEMS];
    /* 0x78 */ ushort queue_top;
    /* 0x7a */ ushort count;
} RcpQueue;

#define RSP_NUM_SEGMENTS 16
extern void *rspSegmentBase[RSP_NUM_SEGMENTS];

extern u32 n64RamSize; //main.c
#define N64_RAM_SIZE 0x800000

u32 n64DisableInterrupts(void);
void n64EnableInterrupts(u32);

#endif //_SYS_N64_H_
