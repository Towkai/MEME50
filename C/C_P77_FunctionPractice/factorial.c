#include <stdio.h>

/*
延伸：輸入一個自然數計算皆乘
*/

int factorial(int x);

void main() {
    int input;
    printf("輸入一個自然數: ");
    scanf("%d", &input);
    if (input >= 0)
        printf("%d! = %d\n", input, factorial(input));
    else
        printf("輸入錯誤");
}

int factorial(int x)
{
    if (x == 0)
        return 1;
    for (int i = x; i > 0; i--)
        x *= i;
    return x;
}