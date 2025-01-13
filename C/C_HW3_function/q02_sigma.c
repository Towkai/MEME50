#include<stdio.h>
#include"../myheaders/myfunc.h"


/*
函數 double my_fun(double x, int n)如下：
x^1 / 1 + x^2 / 2 + x^3 / 3 ......
*/

double my_fun(int x, int n);

void main()
{
    int x, n;
    
    printf("函數 double my_fun(double x, int n)如下：\n");
    printf("x^1 / 1! + x^2 / 2! + x^3 / 3! ...... + x^n / n!\n");
    printf("輸入x n(皆需為自然數)：");
    scanf("%d %d", &x, &n);
    printf("result: %.2lf", my_fun(x, n));
}

double my_fun(int x, int n)
{
    if (n == 0)
        return 0;
    
    double result = 0;
    for(int i = 1; i <= n; i++)
    {
        result += ((double)power(x, i) / factorial(i));
    }
    return  result;
}