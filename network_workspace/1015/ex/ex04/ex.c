#include <stdio.h>
#include <pthread.h>
#include <string.h>

char vect[4][21] =
{
    "ABCDEFGHIJKLMNOPQRST",
    "HIFAKERHIFAKERHIFAKE",
    "BBQBBQBBQBBQBBQBBQBB",
    "MACMACMACMACMACMACMA",
};

char c_vect[4][21]; 

void *run(void* arg) {
	int idx = *(int*) arg;
	memset(c_vect[idx], 0, sizeof(c_vect[idx]));

	for (int i = 0; i < 20; ++i) {
		c_vect[idx][i] = ((vect[idx][i] -'A' + 3 + 26) % 26) + 'A';
	}
 
  return NULL;
}

int main() {
	pthread_t t[4];
	int id[4];
 
	for (int i = 0; i < 4; ++i) {
		id[i] = i;
		pthread_create(&t[i], NULL, run, &id[i]);
	}

	for (int i = 0; i < 4; ++i) {
		pthread_join(t[i], NULL);
	}

	for (int i = 0; i < 4; ++i) {
		printf("%s\n", c_vect[i]);
	}

	return 0;
}
