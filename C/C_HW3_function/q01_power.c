#include<stdio.h>
#include"myfunc.h"

// int power(int x, int n)
// {
//     if (n == 0)
//         return 1;
//     int result = 1;
//     for (int i = 0; i < n; i++)
//         result *= x;
//     return result;
// }

void main()
{
    int x, n;
    
    printf("輸入底數^指數(皆需為自然數)：");
    scanf("%d^%d", &x, &n);
    printf("%d ^ %d = %d", x, n, power(x, n));
}

