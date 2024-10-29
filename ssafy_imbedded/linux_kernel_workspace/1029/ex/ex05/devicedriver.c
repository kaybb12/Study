#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>   //device file 관리용 header

#define NOD_NAME "deviceFile"
//#define BUF_LEN 100

MODULE_LICENSE("GPL");

static int NOD_MAJOR;       //device file 의 major num 를 담을 변수
static struct class *cls;   //device file 생성을 위한 class
static dev_t dev;
//static char message[BUF_LEN] = {0};

static int deviceFile_open(struct inode *inode, struct file *filp){
    pr_info("I’m beginner!\n");
    return 0;
}

static int deviceFile_release(struct inode *inode, struct file *filp){
    pr_info("I'm Master!\n");
    return 0;
}
/*
// 장치 파일 읽기 처리 함수
static ssize_t deviceFile_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset){
    int bytes_read = 0;
    if (*offset >= BUF_LEN) {
        return 0;
    }
    if (length > BUF_LEN - *offset) {
        length = BUF_LEN - *offset;
    }

    if (copy_to_user(buffer, message + *offset, length) != 0) {
        return -EFAULT;
    }

    *offset += length;
    bytes_read = length;
    pr_info("Read %d bytes from device\n", bytes_read);
    return bytes_read;
}

// 장치 파일 쓰기 처리 함수
static ssize_t deviceFile_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset){
    if (length > BUF_LEN - 1) {
        length = BUF_LEN - 1;
    }

    if (copy_from_user(message, buffer, length) != 0) {
        return -EFAULT;
    }

    message[length] = '\0';
    pr_info("Received %zu bytes from user: %s\n", length, message);
    return length;
}
*/
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = deviceFile_open,
    .release = deviceFile_release,
//	.read = deviceFile_read,
//  .write = deviceFile_write,
};

static int __init deviceFile_init(void)
{
    NOD_MAJOR = register_chrdev(0, NOD_NAME, &fops);  
    if( NOD_MAJOR < 0 ){
        pr_alert("Register File\n");
        return NOD_MAJOR;
    }

    pr_info("hello ssafy\n");

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
    pr_info("goodbye ssafy\n");
}

module_init(deviceFile_init);
module_exit(deviceFile_exit);
