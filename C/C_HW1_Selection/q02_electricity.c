#include<stdio.h>
#include"input.h"

/*
電力公司使用累計方式來計算電費，分非營業用電及營業用電。
輸入何種用電和度數，計算出需繳之電費。(皆以非夏月來計算)
*/

void main() {
	
	float not_business_less120 = 1.63;
	float not_business_less300 = 2.1;
	float not_business_less500 = 2.89;
	float not_business_less700 = 3.94;
	float not_business_less1000 = 4.6;
	float not_business_over1000 = 5.03;
	
	float business_less300 = 2.12;
	float business_less700 = 2.91;
	float business_less1500 = 3.44;
	float business_over1500 = 5.05;
	
	int is_business = 0;
	
	float consum = 0;
	float electricity = 0;
	
	
	
	printf("電力公司使用累計方式來計算電費，分非營業用電及營業用電。\n");
	printf("是否為營業用電(Y/N)：");
    
	is_business = is_input_t();
	
	printf("設定%s\n", (is_business > 0 ? "營業用電" : "非營業用電"));
	printf("輸入用電度數：");
	scanf("%f", &consum);
	
	if (consum < 0)
	{
		printf("輸入錯誤");
	}
	else
	{
		if (is_business > 0)
		{
			// 營業用電
			if (consum <= 330)
			{
				electricity += consum * business_less300;
			}
			else
			{
				electricity += 330 * business_less300;
				if (consum <= 700)
				{
					electricity += (consum - 330) * business_less700;
				}
				else
				{
					electricity += (700 - 330) * business_less700;
					if (consum <= 1500)
					{
						electricity += (consum - 700) * business_less1500;
					}
					else
					{
						electricity += (1500 - 700) * business_less1500;
						electricity += (consum - 1500) * business_over1500;
					}
				}
			}
		}
		else
		{
			// 非營業用電
			if (consum <= 120)
			{
				electricity += consum * not_business_less120;
			}
			else
			{
				electricity += 120 * not_business_less120;
				if (consum <= 330)
				{
					electricity += (consum - 120) * not_business_less300;
				}
				else
				{
					electricity += (330 - 120) * not_business_less300;
					if (electricity <= 500)
					{
						electricity += (consum - 330) * not_business_less500;
					}
					else
					{
						electricity += (500 - 330) * not_business_less500;
						if (consum <= 700)
						{
							electricity += (consum - 500) * not_business_less700;
						}
						else
						{
							electricity += (700 - 500) * not_business_less700;
							if (consum <= 1000)
							{
								electricity += (consum - 700) * not_business_less1000;
							}
							else
							{
								electricity += (1000 - 700) * not_business_less1000;
								if (consum > 1000)
									electricity += (consum - 1000) * not_business_over1000;
							}
						}
					}
				}
			}
		}
	}
	printf("所繳電費(非夏月)：%g\n", electricity);
}  