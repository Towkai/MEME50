#include<stdio.h>
#include<limits.h>
#include"input.h"

/*
電力公司使用累計方式來計算電費，分非營業用電及營業用電。
輸入何種用電和度數，計算出需繳之電費。(皆以非夏月來計算)
*/

void main() {
	double price_lv[2][6] = {{1.63, 2.1, 2.89, 3.94, 4.6, 5.03}, {2.12, 2.91, 3.44, 5.05}};
	int limit_lv[2][7] = {{0, 120, 330, 500, 700, 1000, INT_MAX}, {0, 330, 700, 1500, INT_MAX, 0, 0}};
	
	int business_type = 0;
	
	double consum = 0;
	double electricity = 0;
	
	
	
	printf("電力公司使用累計方式來計算電費，分非營業用電及營業用電。\n");
	printf("是否為營業用電(Y/N)：");
	int input;
    setchar(&input); // 傳址給DEFINE設定輸入的字元
	
	if (input == 89 || input == 121)
		business_type = 1;
	else
		business_type = 0;
	
	printf("設定%s\n", (business_type > 0 ? "營業用電" : "非營業用電"));
	printf("輸入用電度數：");
	scanf("%lf", &consum);
	
	if (consum >= 0)
	{
		int c = 0; //用到第幾度電
		int i = 0; //度數的閾值
		while (c < consum)
		{
			if (c < limit_lv[business_type][i + 1])
			{
				electricity += price_lv[business_type][i];
				c++;
			}
            else
            {
                i++; // 進入下一個閾值
            }
		}
		printf("所繳電費(非夏月)：%g\n", electricity);
	}
	else
	{
		printf("輸入錯誤");
	}
}  