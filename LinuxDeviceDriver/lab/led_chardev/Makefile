CROSS_COMPILE=aarch64-linux-gnu-
CC=$(CROSS_COMPILE)gcc
obj-m += led_chardev.o
#KDIR=/lib/modules/$(shell uname -r)/build
KDIR=/root/kernel/linux-rpi-6.6.y
#EXTRA_CFLAGS += -D__XOR__

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean


