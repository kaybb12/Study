#include <stdio.h>
#include <time.h>
#include <sys/time.h>

static char* days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main(){
  time_t t = time(0);
  struct timeval time;
  gettimeofday(&time, NULL);
  struct tm *tmm = localtime(&t);
 
	printf("%d-%d-%d %d:%d:%d.%d\n", tmm->tm_year + 1900, tmm->tm_mon + 1, tmm->tm_mday, tmm->tm_hour, tmm->tm_min, tmm->tm_sec, time.tv_usec % 1000000);
     
  return 0;
}
