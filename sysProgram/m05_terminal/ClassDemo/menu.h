#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define DEVTTY "/dev/tty"

FILE * ttyopen(char* mode) {
    return fopen(DEVTTY, mode);
}

char* menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL
};

int getchoice(char* greet, char* choices[]);
