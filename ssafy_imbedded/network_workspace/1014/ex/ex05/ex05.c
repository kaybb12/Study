#include <stdio.h>
#include <time.h>

int main(){
    clock_t start,end;
    int sum = 1;
  
    start = clock();
    for(int i=0; i<100000000; i++){
        sum = sum << 2;
    }
    end = clock();

    printf("[<< time : %lfs]\n", (float)(end-start)/CLOCKS_PER_SEC);
   
	 	start = clock();
    for(int i=0; i<100000000; i++){
			 	sum = sum % 2;
    }
    end = clock();
 
    printf("[%% time : %lfs]\n", (float)(end-start)/CLOCKS_PER_SEC);


		return 0;
}
