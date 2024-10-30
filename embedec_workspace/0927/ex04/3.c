#include <stdio.h>
#include <stdint.h>
#include <string.h>

int abc(int n) {
	printf("ABC %d\n", n);
	return 321;
}
int bbq(int n) {
	printf("BBQ %d\n", n);
	return 123;
}
int main() {

	int (*p[2])(int) = { abc, bbq };

	printf("%d %d\n", (*p[0])(100), (*p[1])(200));

	return 0;
}
