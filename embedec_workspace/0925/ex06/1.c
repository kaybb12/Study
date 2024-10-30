#include <stdio.h>
#include <stdint.h>
#include <string.h>

union BUF {
	uint8_t buf;

	struct {
		uint8_t a : 2;
		uint8_t b : 2;
		uint8_t c : 2;
		uint8_t d : 2;
	};
};

int main(){

    union BUF bu = {.buf = 0b11100001};

    return 0;
}
