#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct Node{
	char n;
	char buf[30];
};
int main(){
    int fd = open("/dev/deviceFile", O_RDWR);
    if( fd<0 ){
        printf("ERROR\n");
        exit(1);
    }
	
    struct Node readData;
    struct Node writeData = {'a', "App Struct Data"};

    ioctl(fd, _IO(0,3), &readData);
    printf("Read Struct Data : %d %s\n", (int)readData.n, readData.buf);

    ioctl(fd, _IO(0,4), &writeData);
    printf("Transfer Struct Data!\n");

  close(fd);
  return 0;
}
