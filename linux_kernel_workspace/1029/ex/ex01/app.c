#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h> //ioctl 사용을 위한 header

#define NOD_NAME "/dev/deviceFile"

int main(){
    // /dev/deviceFile 을 read/write 로 열기, fops의 .open 실행
    int fd = open(NOD_NAME, O_RDWR);
    if( fd<0 ){
        printf("ERROR\n");
        exit(1);
    }

    //ioctl로 /dev/deviceFile 에 _IO() 매크로로 arg 값 전달
    ioctl(fd, _IO(0,3), 16);        //16 decimal
    ioctl(fd, _IO(0,4), 0xf);       //15 hex
    ioctl(fd, _IO(0,5), 0b1111);    //15 binary
    int ret = ioctl(fd, _IO(0,6), 0);

    //ioctl 의 return 값으로 error 검출
    if(ret < 0){
        printf("%d command invalid!\n", ret);
    }

    close(fd);
    return 0;
}
