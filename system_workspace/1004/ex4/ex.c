#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

pthread_t t[100];

int coin_cnt;
int first_machine;
int last_machine;
pthread_mutex_t mu;

void *coin(void* arg) {
  while(1){
		pthread_mutex_lock(&mu);
    coin_cnt++;
		pthread_mutex_unlock(&mu);
		usleep(100000);
  }
}

void show(){
  printf("%d\n", coin_cnt);
}

void add(){
  last_machine++;
  pthread_create(&t[last_machine], NULL, coin, NULL);
	printf("add mine, now mine : %d\n", last_machine - first_machine + 1);
}

void del(){
  pthread_cancel(t[first_machine]);
  printf("del mine, now mine : %d\n", last_machine - first_machine);
  first_machine++;
}

int main() {
  setbuf(stdout, NULL);
	pthread_mutex_init(&mu, NULL);

  first_machine = 0;
  last_machine = 0;
  pthread_create(&t[0], NULL, coin, NULL); 
   
  while(1) {
		if (last_machine >= 100 || last_machine < first_machine)
				break;

    char str[100];
    printf("ssafy>> ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    
    if (strcmp(str, "show") == 0) {
      show();
    } 
    else if (strcmp(str, "add") == 0) {
      add();
    }   
    else if (strcmp(str, "del") == 0) {
      del();
    }
  }
	  
	for (int i = 0; i <= last_machine; ++i) {
		pthread_join(t[i], NULL);
	}

	pthread_mutex_destroy(&mu);

  return 0;
}
