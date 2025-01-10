#include <stdio.h>

/*
利用 for 迴圏計算 1^2 - 2^2 + 3^2 - 4^2 +…+ 49^2 - 50^2 的值。(-1275)
*/
int expression(int n);

void main()
{
    printf("計算 1^2 - 2^2 + 3^2 - 4^2 + … ，輸入終止值：");    
    int input = 0;
    scanf("%d", &input);
    if (input > 0)
    {
        if (input % 2 == 0)
            printf("1^2 - 2^2 + 3^2 - 4^2 + … - %d^2 = %d", input, expression(input));
        else
            printf("1^2 - 2^2 + 3^2 - 4^2 + … + %d^2 = %d", input, expression(input));
    }
    else
    {
        printf("輸入錯誤");
    }
}

int expression(int n)
{
    int result;
    for (int i = 1; i <= n; i++)
    {
        int square = i * i;
        result += square * ((i % 2 == 0) ? -1 : 1);
    }
    return result;
}