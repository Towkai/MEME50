CFLAGS = -g -Wall
CC = gcc
LIBS = -lm
INCLUDE = 
OBJS = a.o b.o c.o
SRCS = a.c b.c c.c prog1.c prog2.c
HDRS = abc.h
all: prog1 prog2
#The variable $@ has the value of the yarget. In this case $@ = psort
prog1: prog1.o ${OBJS}
	$(CC) ${CFLAGS} ${INCLUDE} -o $@ prog1.o ${OBJS} ${LIBS}
prog2: prog2.o ${OBJS}
	$(CC) ${CFLAGS} -o $@ prog2.o ${OBJS} ${LIBS}
.c .o:
	$(CC) ${CFLAGS} ${INCLUDE} -c $<
depend:
	makedepend ${SRCS}
clean: 
	rm *.o core *~
tar:
	tar cf code.tar Makefile *.c *.h testfile1
print:
	more Makefile $(HDRS) $(SRCS) | enscript -2r -p listing.ps

