#include<stdio.h>

/*
輸入一西元年，如 2015。判斷此年份是否為閏年。
提示：每四年一閏，每百年不閏，每四百年一閏。
*/


void main() {
	int year = 0;
	printf("輸入西元年：");	
	scanf("%d", &year);
	
	int is_leap = 0;
	if (year > 4 && year % 4 == 0)
	{
		is_leap = 1;
	}
	if (year > 100 && year % 100 == 0)
	{
		is_leap = 0;
	}
	if (year > 400 && year % 400 == 0)
	{
		is_leap = 1;
	}
	if (year > 4000 && year % 4000 == 0)
	{
		is_leap = 0;
	}
	printf("此為%s閏年", is_leap > 0 ? "" : "非");
}