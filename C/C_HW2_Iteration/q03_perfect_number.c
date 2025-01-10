#include<stdio.h>
#include<math.h>

/*
一個數字若等於其所有因數的總和，則此數為 perfect number。
找出 100 以內所有的完美數。(1, 6, 28)
*/

int factor_sum(int n);

void main()
{
    printf("一個數字若等於其所有因數的總和，則此數為 perfect number。\n");
    printf("輸入一個自然數(如果他底下有數的因數超果32個會出錯)：");
    int input;
    scanf("%d", &input);
    printf("%d 以內所有的完美數有：", input);
    for (int i = 1; i < input; i++)
    {
        // printf("%d, 因數和: %d, 位數和：%d\n", i, factor_sum(i), digit_sum(i));
        // if (factor_sum(i) == digit_sum(i))
        if (i == factor_sum(i))
            printf("%d, ", i);
    }
}

int factor_sum(int n)
{
    int factor_sum = 0;
    int root = sqrt(n);
    for (int i = 1; i <= root; i++) //尋找因數
    {
        int factor[32] = {};             //預開32個位置
        int counter = 0;
        if (n % i == 0)             //每找到一個因數相當於找到兩個，除非是平方數
        {
            factor[counter] = i;
            counter++;
            if (i != n / i)
            {
                factor[counter] = n / i;
                counter++;
            }
        }
        for (int i = 0; i < sizeof(factor) / sizeof(factor[0]); i++)    //將每個因數相加
        {   
            if (factor[i] != 0)
                factor_sum += factor[i];
            else
                break;
        }
    }
    return factor_sum - (n > 1 ? n : 0);
}

