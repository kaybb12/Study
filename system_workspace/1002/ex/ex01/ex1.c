#include <stdio.h>      // 표준 입출력 라이브러리 포함
#include <pthread.h>    // POSIX 스레드 라이브러리 포함

pthread_t tid[4];       // 스레드 ID를 저장할 배열 선언

// 스레드가 실행할 함수
void *run(void *arg) {
    int a = *(int*)arg; // 전달받은 인자를 정수형으로 변환하여 변수 'a'에 저장
    printf("%d", a);    // 'a' 값을 출력
}

int main() {
    int id[4];          // 각 스레드에 전달할 인자를 저장할 배열 선언

    // 4개의 스레드 생성
    for (int i = 0; i < 4; i++) {
        id[i] = i;  // 각 스레드에 고유한 ID 값을 할당
        pthread_create(&tid[i], NULL, run, &id[i]);
		}
    // 생성된 4개의 스레드가 종료될 때까지 대기
    for (int i = 0; i < 4; i++) 
				pthread_join(tid[i], NULL);  
    
    return 0;           // 프로그램 종료
}
