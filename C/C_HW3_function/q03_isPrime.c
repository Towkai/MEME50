#include<stdio.h>
#include"myfunc.h"


/*
寫一函數 int isPrime(int n)用來判斷 n 是否為質數。
*/


void main()
{
    int input;
    
    printf("輸入一個自然數：");
    scanf("%d", &input);
    printf("%d %s質數", input, is_prime(input) == 1 ? "是" : "不是");

}
