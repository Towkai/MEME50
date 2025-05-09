#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>

int main(int argc , char *argv[])
{
  int fh, cnt=0;
  char bfr[64];
  struct termios original_t, new_t;

#ifndef __LINE_BUF__
  // Disable line buffering
  tcgetattr(fileno(stdin), &original_t);
  memcpy(&new_t, &original_t, sizeof(new_t));
  new_t.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(fileno(stdin), TCSAFLUSH, &new_t);
  fflush(stdin);
#endif
 
  printf("I/O test for UART driver \n");
  printf("Press Ctrl C to exit\n");
  fh = open("/dev/uart", O_RDWR);
  while(1) {  
    printf("Input char:");
    memset(bfr, 0, sizeof(bfr) );
    bfr[0]=getchar();
    cnt=1;
    cnt = write(fh, bfr, cnt);
    if(cnt > 0) {
      printf("write %d characters: %c\n", cnt, bfr[0]);
    }
  }
  close(fh);

#ifndef __LINE_BUF__
  // Restore line buffering
  tcsetattr(fileno(stdin), TCSANOW, &original_t);
#endif

  return 0;
}
