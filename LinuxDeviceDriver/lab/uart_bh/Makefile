obj-m += uart.o
uart-objs := uart_ring.o ringbuf.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf modules.order
