#include<stdio.h>
#include<math.h>

/*
錢精打以 10%單利投資 100,000 元，郝細算則以 5%複利投資 100,000 元。計算多少年後郝細算的投資
可以超過錢精打，並將此時兩人錢數印出。
提示：單利公式：P(1+r*n) 複利公式：P(1+r)^n
P：本金，r：利率，n：多少
*/

double simple_interest(double p, double r, int n);
double compound_interest(double p, double r, int n);

void main()
{
    double simple = 0.1;
    double compound = 0.05;
    double cjd = 100000;
    double hcs = 100000;
    int year = 0;
    cjd = 100000;
    hcs = 100000;
    while (compound_interest(hcs, compound, year) <= simple_interest(cjd, simple, year))
    {
        year++;
    }

    printf("%d 年過後郝細算超過錢精打，此時兩人資產為：\n", year);
    printf("錢精打 %.lf：\n", simple_interest(cjd, simple, year));
    printf("郝細算 %.lf：\n", compound_interest(hcs, compound, year));
}

double simple_interest(double p, double r, int n)
{
    return p * (1 + r * n);
}
double compound_interest(double p, double r, int n)
{
    return p * pow((1 + r), n);
}