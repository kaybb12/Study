#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define NOD_NAME "/dev/deviceFile"

int main(){
	int fd = open(NOD_NAME, O_RDWR);
	if( fd<0 ){
		printf("ERROR\n");
		exit(1);
	}
	
	printf("Read DeviceFile!\n");

	close(fd);
		
	return 0;
}
