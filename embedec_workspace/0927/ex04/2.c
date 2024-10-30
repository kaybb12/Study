#include <stdio.h>
#include <stdint.h>
#include <string.h>

void abc(int a) {
	printf("ABC %d\n", a);
}
int bbq() {
	printf("BBQ\n");
	return 10;
}
int main() {

	void (*p)(int);
	p = abc;
	(*p)(10);

	int (*q)();
	q = bbq;
	printf("%d", (*q)()+100);

	return 0;
}
