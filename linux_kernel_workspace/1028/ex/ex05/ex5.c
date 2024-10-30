#include<stdio.h>
#include <stdint.h>
int main() {

	uint32_t* IOBANK0 = 0x400d0000;
	uint32_t* PADBANK0 = 0x400f0000;

	uint32_t* GPIO2_CTRL;
    uint32_t* GPIO2_STATUS;
    uint32_t* GPIO20_CTRL;
    uint32_t* PADBANK0_GPIO2;
    uint32_t* PADBANK0_GPIO20;
    //+1을 하면 32비트 씩 이동하기 때문에 /4를 통해 4바이트 단위로 변환하기 위해
    GPIO2_CTRL = IOBANK0 + 0x014/4;
    GPIO2_STATUS = IOBANK0 + 0x010/4;
    GPIO20_CTRL = IOBANK0 + 0x0a4/4;
    PADBANK0_GPIO2 = PADBANK0 + 0x0c/4;
    PADBANK0_GPIO20 = PADBANK0 + 0x54/4;
    int debug = -1;
    return 0;
}
