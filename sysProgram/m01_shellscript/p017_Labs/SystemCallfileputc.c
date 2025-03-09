#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    char c;
    int file;
    file = open(argv[1], O_RDONLY);
    int count = 0;
    while (read(file, &c, 1) == 1) {
        count++;
    }
    printf("count: %d\n", count);
    close(file);
    return 0;
}