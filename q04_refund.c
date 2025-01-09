#include<stdio.h>

/*
輸入在某商店購物應付金額與實付金額。
實付金額小於應付金額，則印出”金額不足”。
實付金額等於應付金額，則印出”不必找錢”。
實付金額大於應付金額，則輸出找回金額最少的鈔票數和錢幣數。
假設幣值只有 1000, 500, 100 元紙鈔和 50, 10, 5, 1 元硬幣。
*/

void main()
{
    int coin1 = 0, coin5 = 0, coin10 = 0, coin50 = 0, coin100 = 0, coin500 = 0, coin1000 = 0;
        
	int need, real;
    printf("輸入應付金額/實付金額：");
    scanf("%d/%d", &need, &real);

	if (real > need)
	{
		int change = real - need;
    	printf("應找%d元\n", change);
		coin1000 = change > 1000 ? (change / 1000) : 0;
        change -= coin1000 * 1000;
        coin500 = change > 500 ? (change / 500) : 0;
        change -= coin500 * 500;
        coin100 = change > 100 ? (change / 100) : 0;
        change -= coin100 * 100;
        coin50 = change > 50 ? (change / 50) : 0;
        change -= coin50 * 50;
        coin10 = change > 10 ? (change / 10) : 0;
        change -= coin10 * 10;
		coin5 = change > 5 ? (change / 5) : 0;
        change -= coin5 * 5;
		coin1 = change > 1 ? (change / 1) : 0;
        change -= coin1 * 1;
    	printf("1000元\t * %d\n", coin1000);
    	printf("500元\t * %d\n", coin500);
    	printf("100元\t * %d\n", coin100);
    	printf("50元\t * %d\n", coin50);
    	printf("10元\t * %d\n", coin10);
    	printf("5元\t * %d\n", coin5);
    	printf("1元\t * %d\n", coin1);
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