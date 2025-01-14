#include<stdio.h>
#include<math.h>
#include"../myheaders/myfunc.h"

/*
輸入一正整數，找出所有小於或等於的質數。
*/

int bool_prime(int n); 

void main()
{
    int input = 0;
    printf("找出所有小於或等於的質數\n");
    printf("輸入一個自然數：");
    scanf("%d", &input);
    if (input >= 0)
    {
        printf("不大於其的質數有：");
        int root = sqrt(input);
        for (int i = 1; i <= input; i++)
        {
            if (bool_prime(i))
                printf("%d, ", i);
        }
        printf("\b\b \b");
    }
    else
        printf("輸入錯誤");
}

int bool_prime(int n)
{
    int root = sqrt(n);
    for (int i = 2; i <= root; i++)
    {
        if (n % i == 0)
            return FALSE;
    }
    return TRUE;
}