#include <stdio.h>
#include <stdint.h>

int main(){

	int val = 0x8FAA2D;
	int size = 0;

	printf("1. 2진수 : ");
	for (int i = 23; i >= 0; i--) {
		printf("%d", (val >> i) & 1);
		++size;
	}
	printf("\n");

	printf("2. LSB = %d\n", val & 1);

	printf("3. 2번 : %d, 7번 : %d,  10번 : %d\n", (val >> 2) & 1, (val >> 7) & 1, (val >> 10) & 1);

	printf("4. 최소 Byte : %d\nS", size / 3);

	printf("5. 24 bit 기준으로 ~0x8FAA2D 값 : 0x%06x\n", 0xFFFFFF - val);

	return 0;
}


