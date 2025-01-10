#include<stdio.h>
#include<stdlib.h>

/*
出現"請輸入密碼"的提示，使用者有最多三次輸入的機會。
若輸入正確，則印出"密碼輸入正確，歡迎使用本系統！"。
若輸入不正確，再次出現"請輸入密碼"的提示。
若三次輸入不正確，則印出"密碼輸入超過三次！"，並結束程式的執行。
*/

void login();

void main()
{
    printf("出現\"請輸入密碼\"的提示，使用者有最多三次輸入的機會。\n");
    printf("若輸入正確，則印出\"密碼輸入正確，歡迎使用本系統！\"。\n");
    printf("若輸入不正確，再次出現\"請輸入密碼\"的提示。\n");
    printf("若三次輸入不正確，則印出\"密碼輸入超過三次！\"，並結束程式的執行。\n");

    char password[] = "password";
    login(password);
}

void login(char p[])
{
    char input[21];
    int counter = 0;
    int retry = 2;
    do 
    {
        // input[0] = '\0';
        printf("請輸入密碼：");
        scanf("%s", &input);
        if (*p == *input)
        {
            printf("歡迎使用本系統！");
            return;
        }
        else
        {
            printf("\n密碼錯誤，還剩 %d 次機會\n", retry - counter);
            counter++;
        }
    }while (counter <= retry);
    printf("密碼輸入超過三次！\n");
    system("pause");
}
