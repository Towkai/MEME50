#include<stdio.h>
#include<limits.h>
#include"../myheaders/myinput.h"

/*
電力公司使用累計方式來計算電費，分非營業用電及營業用電。
輸入何種用電和度數，計算出需繳之電費。(皆以非夏月來計算)
*/

void main() {
	// double price_lv[2][6] = {{{1.63, 2.1, 2.89, 3.94, 4.6, 5.03}, {2.12, 2.91, 3.44, 5.05}};
	//[是否為商業用][是否為夏月][電費]
	double price_lv[2][2][6] = {{{1.63, 2.1, 2.89, 3.94, 4.6, 5.03}, { 1.63, 2.38, 3.52, 4.8, 5.66, 6.41}}, {{2.12, 2.91, 3.44, 5.05}, {2.53, 3.55, 4.25, 6.43}}};
	int limit_lv[2][7] = {{0, 120, 330, 500, 700, 1000, INT_MAX}, {0, 330, 700, 1500, INT_MAX, 0, 0}};
	
	int is_business = 0;
	int is_summer = 0;
	
	double consum = 0;
	double electricity = 0;
	
	
	
	printf("電力公司使用累計方式來計算電費，分非營業用電及營業用電。\n");
	printf("是否為營業用電(Y/N)：");
	is_business = is_input_t();
	printf("設定%s\n用電", (is_business > 0 ? "營業" : "非營業"));

	printf("是否為夏月用電(Y/N)：");
	is_summer = is_input_t();
	printf("設定%s\n用電", (is_summer > 0 ? "夏月" : "非夏月"));
	
	printf("輸入用電度數：");
	scanf("%lf", &consum);
	
	if (consum >= 0)
	{
		int c = 0; //用到第幾度電
		int i = 0; //度數的閾值
		while (c < consum)
		{
			if (c < limit_lv[is_business][i + 1])
			{
				electricity += price_lv[is_business][is_summer][i];
				c++;
			}
			else
			{
				i++; // 進入下一個閾值
			}
		}
		printf("所繳電費(%s%s用電)：%g\n", (is_summer > 0 ? "夏月" : "非夏月"), (is_business > 0 ? "營業" : "非營業"),  electricity);
	}
	else
	{
		printf("輸入錯誤");
	}
}  