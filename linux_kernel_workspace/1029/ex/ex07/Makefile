KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build
CC = gcc

TARGET := app
obj-m += devicedriver.o

PWD := $(CURDIR)

#make 시 make all 실행
all: driver app

#driver build
driver:
	make -C $(KERNEL_HEADERS) M=$(PWD) modules

#app build
app:
	$(CC) -o $@ $@.c

#driver, app clean
clean:
	make -C $(KERNEL_HEADERS) M=$(PWD) clean
	rm -f *.o $(TARGET)
