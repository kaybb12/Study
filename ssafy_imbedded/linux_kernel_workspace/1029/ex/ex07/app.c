#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct Node{
	int a;
	int b;
	int c;
	int d;
};

int main(){
    int fd = open("/dev/deviceFile", O_RDWR);
    if( fd<0 ){
        printf("ERROR\n");
        exit(1);
    }
	
	while(1){
    	int readData;
		int a, b, c, d;
		printf("input 4 number : ");
		scanf("%d %d %d %d",&a, &b, &c, &d);
    	struct Node writeData = {a, b, c, d};

    	int ret1 = ioctl(fd, _IO(0,3), &writeData);
		int ret2 = ioctl(fd, _IO(0,4), &readData);
		int i;
		for (i = 0; i < readData; ++i) {
			printf("hi faker\n");
		}

		if (ret1 < 0 || ret2 < 0) {
			printf("cmd Error\n");
			break;
		}
	}
	
	close(fd);
	return 0;
}
