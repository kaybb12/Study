#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define NOD_NAME "/dev/deviceFile"

char buf[30];
int main(){
    int fd = open(NOD_NAME, O_RDWR);
    if( fd<0 ){
        printf("ERROR\n");
        exit(1);
    }

    ioctl(fd, _IO(0,3), buf);
    printf("kernel Data : %s\n", buf);

    close(fd);
    return 0;
}
