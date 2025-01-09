#include <stdio.h>

int factorial(int x);

void main() {
    int input;
    printf("輸入一個自然數: ");
    scanf("%d", &input);
    if (input < 0)
        printf("輸入錯誤");
    printf("%d! = %d\n", input, factorial(input));
}

int factorial(int x)
{
    for (int i = x; i > 0; i--)
        x *= i;
    return x;
}