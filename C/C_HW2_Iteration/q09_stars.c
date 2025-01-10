#include<stdio.h>

/*
畫出星星圖形。
*/

void draw_star_1(int x);
void draw_star_2(int x);
void draw_star_3(int x);

void main()
{
    draw_star_1(5);
    draw_star_2(5);
    draw_star_3(5);
}

void draw_star_1(int x) 
{
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}
void draw_star_2(int x) 
{
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            printf(j < i ? " " : "*");
        }
        printf("\n");
    }
    printf("\n");
}
void draw_star_3(int x) 
{
    int count = 2 * x - 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= i + count / 2; j++)
        {
            printf(j <= count / 2 - (i - 1) ? " " : "*");
        }
        printf("\n");
    }
    printf("\n");
}