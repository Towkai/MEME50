#include<stdio.h>
#include<math.h>

/*
Amstrong 數是指一個三位數的整數，其各位數之立方和等於該數本身。
找出所有的 Amstrong 數。(153, 370, 371, 407)
*/

int digit_sum(int n, int x); //取位數冪次和
int digit(int n, int digit); //取位數

void main()
{
    printf("Amstrong 數是指一個三位數的整數，其各位數之立方和等於該數本身。\n");
    printf("Amstrong 數有：");
    for (int i = 100; i < 1000; i++)
    {
        if (i == digit_sum(i, 3))
            printf("%d, ", i);
    }
}

int digit_sum(int n, int x)
{
    int pow10 = 0;
    int result = 0;
    while (n > powf(10, pow10))
    {
        result += pow(digit(n, pow10), x);
        pow10 ++;
    }
    return result;
}

int digit(int n, int digit) 
{
    n /= powf(10, digit);
    return n % 10;
}
