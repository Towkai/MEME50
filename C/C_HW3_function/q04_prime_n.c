#include<stdio.h>
#include"myfunc.h"


/*
寫一函數 int prime(int n)用來找出第 n 個質數。
*/
int find_prime(int x)
{
    int result = 0;
    if (x > 0)
    {
        for (int i = 1, counter = 0; counter < x; i++)
        {
            if (is_prime(i) == 1)
            {
                counter++;
                result = i;
                printf("%d: %d\n", counter, i);
            }
        }
    }
    return result;
}

void main()
{
    int input;
    
    printf("輸入一個自然數：");
    scanf("%d", &input);
    if (input == 0)
    {
        printf("第 %d 個質數為：\n", input);
    }
    else if (input > 0)
    {
        printf("第 %d 個質數為：%d\n", input, find_prime(input));
    }
    else
    {
        printf("invalid\n");
    }
}

