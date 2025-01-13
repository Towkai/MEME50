#include<stdio.h>
#include<limits.h>
#include"../myheaders/myarr.h"

/*
1. 選擇性敘述的練習-salary
輸入便利商店工讀生的工作時數，並計算其薪資。
60 小時以內，時薪 150 元。
61~80 小時，以時薪 1.25 倍計算。
81 小時以上，以時薪 1.5 倍計算。
說明：薪資以累計方式計算。若工時為 90 小時，則薪資為 60*150 + 20*150*1.25 + 10*150*1.5 元。
*/

void main() {
	int base_rate = 150;
	float mul_lv[3] = {1, 1.25, 1.5};
	int limit_lv[4] = {0, 60, 80, INT_MAX};

	float hour = 0;
	float slary[3] = {0, 0, 0};
	
	printf("60 小時以內，時薪 150 元。\n61~80 小時，以時薪 1.25 倍計算。\n81 小時以上，以時薪 1.5 倍計算。\n");
    printf("輸入工作時數：");
	scanf("%f", &hour);
	if (hour >= 0)
	{
        int h = 0; // 第幾小時的工作
        int i = 0; // 時數的閾值
        while (h < hour) {
            if (h < limit_lv[i + 1])
            {
                slary[i] += base_rate * mul_lv[i] * (hour - h >= 1 ? 1 : (hour - h));
                h++;
            }
            else
            {
                i++; // 進入下一個閾值
            }
        }
        printf("基本薪資為：%g\n", slary[0]);
        printf("一階加班費：%g\n", slary[1]);
        printf("二階加班費：%g\n", slary[2]);
        int sum = 0;
        for (int i = 0; i < LENGTH(slary); i++)
            sum += slary[i];
        printf("小計：%d\n", sum);

    }
    else
    {
		printf("輸入錯誤");
    }
}
