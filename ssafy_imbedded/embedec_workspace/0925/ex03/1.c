#include <stdio.h>
#include <stdint.h>

union UN {
	uint64_t g;
	uint8_t buf[8];
};

int main(){


	union UN u = {.g =  0xABCD12345678CD01};
	for (int i = 0; i < 8; i++) {
		printf("%02X", u.buf[i]);
	}

	return 0;
}
