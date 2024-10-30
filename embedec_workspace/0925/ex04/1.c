#include <stdio.h>
#include <stdint.h>
#include <string.h>

union BUF {
	uint8_t buf[11];

	struct {
		uint8_t header[5];
		uint8_t body[4];
		uint8_t tail[2];
	};

};

int main(){
    uint8_t data[11] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef, 0x98, 0x76, 0x54};

    union BUF bu;
    memcpy(bu.buf, data, sizeof(data));

    return 0;
}
