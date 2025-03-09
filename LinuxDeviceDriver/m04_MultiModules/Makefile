EXTRA_CFLAGS += -D__TEST__
obj-m += hello.o
hello-objs := start.o stop.o

all:
	make -C /lib/modules/`uname -r`/build M=`pwd` modules
clean:
	make -C /lib/modules/`uname -r`/build M=`pwd` clean
