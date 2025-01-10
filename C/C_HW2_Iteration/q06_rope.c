#include<stdio.h>

/*
若有一條繩子長 3000 公尺，每天剪去一半的長度，需多少天繩子的長度會短於 5 公尺。(10 天)
*/

float half(float *n); 

void main()
{
    float input = 0;
    float limit = 0;
    printf("每次去掉一半，需要幾次才會比他小\n");
    printf("輸入初始值/小於值：");
    scanf("%f/%f", &input, &limit);
    int counter = 0;
    while (input >= limit)
    {
        half(&input);
        counter++;
    }
    printf("需要 %d 次", counter);
}

float half(float *n)
{
    return (*n /= 2);
}