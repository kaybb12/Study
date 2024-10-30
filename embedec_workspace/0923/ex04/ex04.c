#include <stdio.h>
#include <stdint.h>

void check(uint16_t val) {
	for (int i = 15; i >= 0; i--) {
		printf("%d", (val >> i) & 1);
	}
	printf("\n");
}

int main(){

	unsigned char a = 0b11110101;

	unsigned char msb_lsb = 0;

	unsigned char msb = (a >> 7) & 1;
	unsigned char lsb = a & 1;

	msb_lsb = (msb << 1) | lsb;

	printf("MSB_LSB : ");
	for (int i = 1; i >= 0; i--) {
		printf("%d", (msb_lsb >> i) & 1);
	}

	return 0;

}


