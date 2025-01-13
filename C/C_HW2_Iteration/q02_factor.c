#include<stdio.h>
#include<math.h>

/*
輸入一正整數，求其所有的因數。
*/

void main()
{
    printf("輸入一正整數，求其所有的因數：");
    int input;
    scanf("%d", &input);
    if (input >= 0)
    {
        printf("其因數為：\n");
        int root = sqrt(input);
        for (int i = 1; i <= root; i++)
        {
            if (input % i == 0)
                if (i == input / i)
                    printf("%d\n", i);
                else
                    printf("%d\t%d\n", i, input / i);
        }
    }
    else
        printf("輸入錯誤");
}

