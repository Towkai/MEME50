#include<stdio.h>
#include<math.h>
#include"myfunc.h"


/*
寫一函數 int isMersennePrime(int n)用來判斷 n 是否為 Mersenne 質數。撰寫一程式找出前 6 個
Mersenne 質數。(3, 7, 31, 127, 8191, 131071)
提示：若質數滿足 2^p-1=n (p 為正整數)，則 n 為 Mersenne Prime。
*/

int isMersennePrime(int x)
{
    double l = log2(x + 1);
    if (l == (int)l) //判斷是某為整數
        return 1;
    else
        return 0;
}

void main()
{
    int input;    
    printf("輸入一個自然數：");
    scanf("%d", &input);
    printf("前 %d 個 Mersenne 質數為：", input);
    for (int i = 2, counter = 0; counter < input; i++)
    {
        if (is_prime(i) && isMersennePrime(i))
        {
            printf("%d, ", i);
            counter++;
        }
    }
    printf("\b\b \b");
}

