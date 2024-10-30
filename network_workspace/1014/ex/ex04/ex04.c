#include <stdio.h>
#include <time.h>

static char* days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main(){
  time_t t = time(0);
  struct tm *tmm = localtime(&t);
 
	printf("%d/%d/%d %s\n", tmm->tm_year + 1900, tmm->tm_mon + 1, tmm->tm_mday, days[tmm->tm_wday - 1]);
	printf("%d : %d : %d\n", tmm->tm_hour, tmm->tm_min, tmm->tm_sec);
     
  return 0;
}
