#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 구조체 정의: 함수 포인터를 멤버로 가지는 구조체
struct ssafy_opeartions{
    void (*levelup1)(int); // 함수 포인터 멤버
    void (*levelup2)(int); // 함수 포인터 멤버
};

// 함수 선언
void BBQ(int x) {
    printf("BBQ : %d\n", x);
}

void ABC(int x) {
    printf("ABC : %d\n", x);
}

int main() {
    // 구조체 변수 선언 및 선택적 초기화
    struct ssafy_opeartions fops = {
        .levelup1 = BBQ,
        .levelup2 = ABC,
    };

    // 함수 포인터를 멤버로 갖는 구조체의 함수 호출
    fops.levelup1(10); // BBQ 호출
    fops.levelup2(20); // ABC 호출

    return 0;
}
