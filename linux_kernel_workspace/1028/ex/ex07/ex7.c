#include<stdio.h>
#include <stdint.h>
int main() {

    uint32_t GPIO2_CTRL = 0x000FFFFF;
    uint32_t GPIO2_STATUS = 0xFF7FFFFF;
    uint32_t GPIO20_CTRL = 0xFFFF0FFF;
    uint32_t PADBANK0_GPIO20 = 0x00FFFF00;
    uint32_t PADBANK0_GPIO2 = 0xFF00FF00;

    GPIO2_CTRL &= ~(0x3 << 16);
    uint32_t INOVER = GPIO2_CTRL;

    GPIO2_CTRL &= ~(0x1F);
    uint32_t FUNCSEL = GPIO2_CTRL;

    GPIO2_CTRL |= (0x7);
    uint32_t EVENT_LEVEL_HIGH = (GPIO2_STATUS >> 23) & 0x1;

    GPIO20_CTRL &= ~(0x3 << 14);
    GPIO20_CTRL |= (0x3 << 14);
    uint32_t OEOVER = GPIO20_CTRL;

    GPIO20_CTRL &= ~(0x3 << 12);
    GPIO20_CTRL |= (0x2 << 12);
    uint32_t OUTOVER = GPIO20_CTRL;

    PADBANK0_GPIO20 &= ~(0x3 << 4);
    PADBANK0_GPIO20 |= (0x1 << 4);
    uint32_t DRIVE = PADBANK0_GPIO20;

    PADBANK0_GPIO2 |= (0x1 << 6);
    uint32_t IE = PADBANK0_GPIO2;

    return 0;
}
