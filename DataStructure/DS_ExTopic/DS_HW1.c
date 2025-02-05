#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Func/intlist.h"

void main() {
    Node *head = NULL;
    printf("將單向鏈串列反轉。\n");
    printf("輸入一串數字，用逗號或空格隔開\n");

    char str[20];
    gets(str);

    const char* d = "  ,";
    char *p;
    p = strtok(str, d);
    
    while (p != NULL) {
        append(&head, atoi(p));
        p = strtok(NULL, d);		   
    }
    traverse(reverse(head));
}

