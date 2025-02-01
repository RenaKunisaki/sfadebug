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

extern u32 n64RamSize; //main.c
#define N64_RAM_SIZE 0x8000000

u32 n64DisableInterrupts(void);
void n64EnableInterrupts(u32);
