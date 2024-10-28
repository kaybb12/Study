//커널 모듈 형식으로 제작한 디바이스 드라이버 코드
//가장 단순한 기능만 구현, insmod / rmmod 로 커널에 모듈을 적재 / 제거할 수 있다.
//__init : 초기화 함수 앞에 붙이는 매크로, 호출 된 뒤에 메모리에서 해제된다.
//__exit : 모듈 제거 시 메모리에서 해제된다.

#include <linux/module.h>   //모듈용 헤더
#include <linux/printk.h>   //커널 로그용 헤더
#include <linux/init.h>     //매크로용 헤더

MODULE_LICENSE("GPL");      //모듈 라이센스용 매크로

static int __init hi_init(void) //초기화 함수
{
    pr_info("Hello BBQ\n");
    return 0;
}

static void __exit hi_exit(void) //커널 해제시 동작하는 함수
{
    pr_info("Goodbye BBQ\n");
}

module_init(hi_init);
module_exit(hi_exit);
