#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    int sum = 0, num = atoi(argv[1]);
    if (num > 0) {
        for (int i = 1; i <= num; i++)
            sum += i;
    }
    printf("sum = %d\n", sum);
    return sum;
}