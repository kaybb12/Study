#include <stdio.h>
#include <stdint.h>

struct KFC {
	int m1;
	char m2;
	int m3[5];
};

int main(){
	struct KFC k = { 10, 'A', { 1, 2, 3, 4, 5 } };
}
