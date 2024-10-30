KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build

obj-m += devicedriver.o

PWD := $(CURDIR)

driver:
	make -C $(KERNEL_HEADERS) M=$(PWD) modules

clean:
	make -C $(KERNEL_HEADERS) M=$(PWD) clean
