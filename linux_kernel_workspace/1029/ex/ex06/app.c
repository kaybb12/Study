#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define NOD_NAME "/dev/deviceFile"

int main(){
	int fd = open(NOD_NAME, O_RDWR);
	if ( fd < 0 ) {
		printf("ERROR\n");
		exit(1);
	}
	while(1){
	int cmd, cs;
	printf("command : 3~6, Age, birth, phone number\n");
	scanf("%d %d",&cmd, &cs);

	int ret = ioctl(fd, _IO(0, cmd), cs);
	/*
	int ret = ioctl(fd, _IO(0, 7), 0);
	*/
	if (ret < 0) {
		printf("%d command invailid!\n", ret);
		break;
	}
	
	}

	close(fd);

	return 0;	
}
