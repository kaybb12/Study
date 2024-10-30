#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

	int bbq = 127;
	int kfc = 255;
	int* p = &bbq;
	int* q = &kfc;

	int temp = *p;

	*p = *q;
	*q = temp;

	printf("bbq : %d kfc : %d",bbq, kfc);

	return 0;
}
