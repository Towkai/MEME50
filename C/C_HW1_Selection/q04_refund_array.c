#include<stdio.h>
#include"../myheaders/myarr.h"

/*
輸入在某商店購物應付金額與實付金額。
實付金額小於應付金額，則印出"金額不足"。
實付金額等於應付金額，則印出"不必找錢"。
實付金額大於應付金額，則輸出找回金額最少的鈔票數和錢幣數。
假設幣值只有 1000, 500, 100 元紙鈔和 50, 10, 5, 1 元硬幣。
*/

void main()
{
    int coin[2][7] = {{ 1000, 500, 100, 50, 10, 5, 1}, {}};
	int need, real;
    printf("輸入應付金額/實付金額：");
    scanf("%d/%d", &need, &real);

	if (real > need)
	{
		int change = real - need;
    	printf("應找%d元\n", change);
		for (int i = 0; i < LENGTH(coin[0]); i++)
		{
			if (change > coin[0][i])
			{
				coin[1][i] = change / coin[0][i];
				change -= coin[0][i] * coin[1][i];
    			printf("%d元\t * %d\n", coin[0][i], coin[1][i]);
			}
		}
	}
    else if (real < need)
    {
    	printf("金額不足");
	}
	else
	{
    	printf("不必找錢");
	}
}