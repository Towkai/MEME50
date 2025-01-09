#include<stdio.h>
#include<math.h>

/*
一元二次方程式 ax2+bx+c=0。輸入 a, b, c 三值，並計算方程式的根
*/

void main() {
	float a, b, c;
	float ans1, ans2;
    printf("ax^2 + bx + c = 0，輸入a b c\n");
    scanf("%f %f %f", &a, &b, &c);
	if (a == 0)
	{
		printf("a 不能為 0\n");
		return;
	}

    printf("%gx^2 + %gx + %g = 0，其根為：\n", a, b, c);
    
    float b2_4ac = b * b - 4 * a * c;

    if (b2_4ac > 0)
    {
		float sqrt_b2_4ac = sqrt(b2_4ac);
    	ans1 = (-b + sqrt_b2_4ac) / 2 * a;
    	ans2 = (-b - sqrt_b2_4ac) / 2 * a;
    	printf("%g或%g\n", ans1, ans2);
	}
	else if (b2_4ac == 0)
	{
    	ans1 = -b / 2 * a;
//    	ans2 = -b / 2 * a;
    	printf("%g，重根\n", ans1);
	}
	else
	{
    	printf("沒有實根");
	}
}