#include <stdio.h>
#include <stdint.h>

void printToBinary(unsigned char val) {
	printf("0b");
	for (int i = 7; i >= 0; i--) {
		printf("%d", (val >> i) & 1);
	}
	printf("\n");
}

int main(){

	unsigned char a = 0b10000000;

	a &= ~(1 << 7);

	printToBinary(a);

	a |= (1 << 0);

	printToBinary(a);

	a |= 0b11111100;

	printToBinary(a);

	a &= ~(0b11 << 5);

	printToBinary(a);

	a &= ~(1 << 3);

	printToBinary(a);

	return 0;

}


