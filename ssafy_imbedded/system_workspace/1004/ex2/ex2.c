#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *printf_num(void* arg) {
  int num = *(int*)arg;
  printf("%d ", num);
}

int main() {
  setbuf(stdout, NULL);
  pthread_t t[37];
  int id[37];
  for (int i = 0; i < 37; ++i) {
    id[i] = i + 1;
    pthread_create(&t[i], NULL, printf_num, &id[i]);  
  }
  
  for (int i = 0; i < 37; ++i) {
    pthread_join(t[i], NULL);  
  }
  
  printf("VVCC END\n");
  
  return 0;
}
