#include <stdio.h>      // 표준 입출력 라이브러리 포함
#include <pthread.h>    // POSIX 스레드 라이브러리 포함
#include <unistd.h>     // 유닉스 표준 기능 포함 (sleep 함수 사용을 위해 포함)

// 첫 번째 스레드가 실행할 함수
void *abc(void *arg) {
    char str = 'A';
    
    while (1) {
        if (str >= 'D')
          str = 'A';
                      
        printf("[DD1] %c\n", str);
        str++;
        usleep(300000);              // 1초 동안 대기
    }
}

// 두 번째 스레드가 실행할 함수
void *ZeroToFive(void *arg) {
    int num = 0;

    while (1) {
				if (num >= 6)
					num = 0;	
        printf("[DD2] %d\n", num);    
        num++;               
        usleep(200000);
    }
}

void *AToZ(void *arg) {
  char str = 'A';
  
  while(1) {
    if (str > 'Z') {
      str = 'A';
    }
      
    printf("[DD3] %c\n", str);
    str++;
    usleep(300000);
  }
}

int main() {
    setbuf(stdout, NULL);  // 표준 출력 버퍼를 비활성화하여 즉시 출력되도록 설정
    pthread_t t1, t2, t3;      //스레드 ID를 저장할 변수 선언

    // 첫 번째 스레드 생성
    pthread_create(&t1, NULL, abc, NULL);

    // 두 번째 스레드 생성
    pthread_create(&t2, NULL, ZeroToFive, NULL);

    // 세 번째
    pthread_create(&t3, NULL, AToZ, NULL);

    // 생성된 스레드들이 종료될 때까지 메인 스레드가 대기
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;  // 프로그램 종료
}
