#include <stdio.h>      // 표준 입출력 라이브러리 포함
#include <sys/types.h>  // 시스템 데이터 타입 정의 (pid_t 포함)
#include <unistd.h>     // 유닉스 표준 기능 포함 (fork, getpid 함수 사용을 위해 포함)

int main() {
    pid_t child_pid = fork();  // 첫 번째 fork() 호출

    if (child_pid > 0) {
        // 부모 프로세스
        printf("I'm Parent! I'm Busy!!\n");
        while (1);  // 부모는 무한 루프에 들어간다.
    } 
    else if (child_pid == 0) {
        // 자식 프로세스
        printf("HI! I'm baby! ByeBye\n");

        // 자식 프로세스 내에서 손자 프로세스를 생성
        pid_t grand_child_pid = fork();

        if (grand_child_pid > 0) {
            printf("Grow up!\n");
            while(1);
        } else if (grand_child_pid == 0) {
            // 손자 프로세스
            printf("I'm Groot!\n");
        }
    }

    return 0;
}
