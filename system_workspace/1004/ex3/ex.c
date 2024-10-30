#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *abc(void* arg) {
  int id = *(int*)arg;
  if (id == 1) {
    printf("%d ABC\n", id);
  }
  else if (id == 2){
    printf("%d MINMIN\n", id);
  }
  else if (id == 3){
    printf("%d COCO\n", id);
  }
  else if (id == 4){
    printf("%d KFCKFC\n", id);
  }
}

int main() {
  setbuf(stdout, NULL);
  pthread_t t[4];
  int id[4];
  for (int i = 0; i < 4; ++i) {
    id[i] = i + 1;
    pthread_create(&t[i], NULL, abc, &id[i]);
  }

  
  for (int i = 0; i < 4; ++i) {
    pthread_join(t[i], NULL);
  }
  
  return 0;
}
