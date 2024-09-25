#include <stdio.h>
#include <stdint.h>
#include <string.h>

union BUF {
	uint8_t buf[7];

	struct {
		uint8_t header[3];
		uint8_t body[2];
		uint8_t tail[2];
	};

};

int main(){

	uint8_t data[7] = {0xab, 0xcd, 0xef, 0x12, 0x09, 0xAF, 0xAF};

    union BUF bu;
    memcpy(bu.buf, data, sizeof(data));

    return 0;
}
