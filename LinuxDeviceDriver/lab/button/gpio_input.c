#include <string.h>
#include <stdio.h> 
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/gpio.h>
int main(int argc, char **argv) {
    int fd, ret;
    struct gpiohandle_request req;
    req.lineoffsets[0] = 4;
#ifdef __TWO_INPUT__
    req.lineoffsets[1] = 17;
#endif
    req.flags = GPIOHANDLE_REQUEST_INPUT;
    strcpy(req.consumer_label, "Input test");
#ifdef __TWO_INPUT__
    req.lines = 2;
#else
    req.lines = 1;
#endif
    fd = open("/dev/gpiochip0", O_RDONLY);
    ret = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &req);
    close(fd);
    struct gpiohandle_data data;
    ret = ioctl(req.fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, &data);
    printf("%hhu\n",data.values[0]);
#ifdef __TWO_INPUT__
    printf("%hhu\n",data.values[1]);
#endif
    close(req.fd);
    return 0;
}
