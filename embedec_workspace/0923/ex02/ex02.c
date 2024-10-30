#include <stdio.h>
#include <stdint.h>

void check(uint16_t val) {
	for (int i = 15; i >= 0; i--) {
		printf("%d", (val >> i) & 1);
	}
	printf("\n");
}

int main(){

	uint16_t val = 0;
	val |= (1 << 15);

	check(val);

	val |= (0xF << 2);

	check(val);

	val |=  (0x3F << 8);

	check(val);

	val ^= (0x1F << 3);

	check(val);

	val &= 0x1FFF;

	check(val);

	printf("0x%04x\n", val);

	return 0;

}


