#define FALSE (0)
#define TRUE (1)
#define BOOLEAN(X) (X == 0 ? "FALSE" : "TRUE")


int factorial(int x) //計算皆乘
{
    int result = 1;
    for (int i = 1; i <= x; i++)
    {
        result *= i;
    }
    return result;
}
int power(int x, int n) //計算x^n
{
    if (n == 0)
        return 1;
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= x;
    return result;
}
int is_prime(int x) //檢查是否為質數
{
    if (x > 0)
    {
        if (x == 1)
            return 0;
        int i = 2;
        while(power(i, 2) <= x && i < x)
        {
            if (x % i == 0)
                return 0;
            else
                i++;
        }
        return 1;
    }
    else
    {
        printf("invalid\n");
        return 0;
    }
}

int get_number_of_digit(int n, int x) //回傳 n 的第 x 位數，個位數為0
{
    int _10x = 1;
    for (int i = 0; i < x ; i++)
        _10x *= 10;
    n %= _10x * 10;
    return n / _10x;
}