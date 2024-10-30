#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {

	int arr[2][3] = {
			{ 50, 50, 50 },
			{ 70, 70, 70 }
	};

	int* a[3] = { arr[0], arr[0] + 1, arr[1] + 2 };
	int* b[3] = { arr[1], arr[1] + 1, arr[0] + 2 };

	for (int i = 0; i < 3; i++) {
		printf("%d ", *a[i]);
	}

	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%d ", *b[i]);
	}

	return 0;
}
