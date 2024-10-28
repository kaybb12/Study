#include <linux/module.h> //모듈용
#include <linux/printk.h> // 커널 로고용
#include <linux/init.h> // 매크로용

MODULE_LICENSE("GPL"); // 모듈 라이센스용

static int __init ex4_init(void) //초기화
{
	pr_info("JEONG JAE HO\n");
	return 0;
}

static void __exit ex4_exit(void) // 커널 해제시동작
{
	pr_info("SSAFY embedded\n");
}

module_init(ex4_init);
module_exit(ex4_exit);
