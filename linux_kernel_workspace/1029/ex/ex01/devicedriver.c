#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>

#define NOD_NAME "deviceFile"

MODULE_LICENSE("GPL");

static int NOD_MAJOR;
static struct class *cls;
static dev_t dev;

static int deviceFile_open(struct inode *inode, struct file *filp){
    pr_info("Open Device\n");
    return 0;
}

static int deviceFile_release(struct inode *inode, struct file *filp){
    pr_info("Close Device\n");
    return 0;
}

static ssize_t deviceFile_ioctl(struct file *filp, unsigned int cmd, unsigned long arg){
    //입력된 cmd 값 출력
    pr_alert("command number : %d\n", cmd);
    
    //ioctl의 _IO 매크로의 값에 따라 switch문 동작
    switch(cmd){
        case _IO(0,3):
            pr_info("3 - %lu\n", arg);
            break;
        case _IO(0,4):
            pr_info("4 - %lu\n", arg);
            break;
        case _IO(0,5):
            pr_info("5 - %lu\n", arg);
            break;
        default :
            //3~5 이외의 값 입력시, -EINVAL ERROR를 app으로 전송
            return -EINVAL;
    }
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = deviceFile_open,
    .release = deviceFile_release,
    //ioctl 사용 시 kernel에 lock이 걸리는 현상 방지 ( semaphore )
    .unlocked_ioctl = deviceFile_ioctl,
};

static int __init deviceFile_init(void)
{
    NOD_MAJOR = register_chrdev(NOD_MAJOR, NOD_NAME, &fops);
    if( NOD_MAJOR < 0 ){
        pr_alert("Register File\n");
        return NOD_MAJOR;
    }

    pr_info("Insmod Module\n");
    
    dev = MKDEV(NOD_MAJOR, 0);
    cls = class_create(NOD_NAME);
    device_create(cls, NULL, dev, NULL, NOD_NAME);

    pr_info("Major number %d\n", NOD_MAJOR);
    pr_info("Device file : /dev/%s\n", NOD_NAME);

    return 0;
}

static void __exit deviceFile_exit(void)
{
    device_destroy(cls, dev);
    class_destroy(cls);

    unregister_chrdev(NOD_MAJOR, NOD_NAME);
    pr_info("Unload Module\n");
}

module_init(deviceFile_init);
module_exit(deviceFile_exit);
