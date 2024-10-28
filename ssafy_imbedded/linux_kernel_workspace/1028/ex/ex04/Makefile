KERNEL_HEADRS=/lib/modules/$(shell uname -r)/build

obj-m += ex4.o

PWD := $(CURDIR)

driver:
	make -C $(KERNEL_HEADRS) M=$(PWD) modules

clean:
	make -C $(KERNEL_HEADRS) M=$(PWD) clean
