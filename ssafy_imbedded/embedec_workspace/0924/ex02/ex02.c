#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return strcmp(*(const char**)a, *(const char**)b);
}

int main(){

	const char* p[7] = { "BTS", "BTS", "BBQ", "BTS", "BBQ", "ABCD", "AS" };
	int size = sizeof(p) / sizeof(p[0]);

	qsort(p, size, sizeof(const char*), compare);

	for (int i = 0; i < size; ++i) {
		if (i == 0 || strcmp(p[i], p[i - 1]) != 0) {
			printf("%s\n", p[i]);
		}
	}

	return 0;
}
