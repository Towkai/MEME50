#CROSS_COMPILE=aarch64-linux-gnu-
#CC=$(CROSS_COMPILE)gcc
CFLAGS=-D__RIOXOR__
#
PROG1=rpi5_memio_xor


all: $(PROG1)
	$(CC) -static $(CFLAGS) $(PROG1).c -o $(PROG1)

clean:
	rm -rf $(PROG1)