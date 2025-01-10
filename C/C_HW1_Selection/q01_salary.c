#include<stdio.h>

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
	float mul1 = 1.25;
	float mul2 = 1.5;
	int limit1 = 60;
	int limit2 = 80;
	
	float hour = 0;
	int slary = 0;
	
	
	printf("60 小時以內，時薪 150 元。\n61~80 小時，以時薪 1.25 倍計算。\n81 小時以上，以時薪 1.5 倍計算。\n");
    printf("輸入工作時數：");
	scanf("%f", &hour);
//	printf("hour = %.1f", hour);

	if (hour > 0)
	{
		int overwork1 = hour - limit1;
		int overwork2 = hour - limit2;
		
		if (hour <= limit1)
		{
			//基本時薪
			slary += base_rate * hour;
		    printf("基本薪資 薪資為：%d", slary);
		}
		else
		{
			//基本時薪
			slary += base_rate * limit1;
            printf("基本薪資為：%d\n", slary);
			if (hour <= limit2)
			{
				//第一階段加班費
                int bonus1 = base_rate * mul1 * overwork1;
		        printf("一階加班費：%d\n", bonus1);
                slary += bonus1;
		        printf("小計：%d\n", slary);
			}
			else
			{
                int bonus1 = base_rate * mul1 * (limit2 - limit1);
                slary += bonus1;
		        printf("一階加班費：%d\n", bonus1);
                int bonus2 = base_rate * mul2 * (hour - limit2);
		        printf("二階加班費：%d\n", bonus2);
				slary += bonus2;
				//第二階段加班費
                printf("小計：%d\n", slary);
			}
		}
	}
	else
	{
		printf("輸入錯誤");
	}
}