obj-m += chardev.o
NAME=hello
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo insmod $(PWD)/chardev.ko
	cat /proc/devices | grep $(NAME)
	sudo mknod /dev/$(NAME) c `cat /proc/devices | grep $(NAME) | cut -d' ' -f1` 0
	sudo chmod 660 /dev/$(NAME)
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	sudo rmmod chardev
	sudo rm /dev/hello
