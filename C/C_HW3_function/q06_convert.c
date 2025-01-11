#include<stdio.h>
#include<string.h>


/*
輸入一整數，寫兩個函數分別為toBinary(int n)和toHexadecimal(int n)用來將n轉換成二進制和十六進
制的值。
*/

int convert(char bin[], int n, int carry);
int toBinary(int n);
int toHexadecimal(int n);
char to_hexc(int n);

void main()
{
    int input;
    printf("輸入一個自然數：");
    scanf("%d", &input);
    toBinary(input);
    toHexadecimal(input);
}

int convert(char ref[], int n, int carry)
{
    char bin[32] = {};
    int index = 0;
    while (n >= carry)
    {
        bin[index] = to_hexc(n % carry);
        n /= carry;
        index++;
    }
    bin[index] = to_hexc(n);
    strcpy(ref, strrev(bin));
    return index;
}

int toBinary(int n)
{
    char c[sizeof(n)] = {};
    int length = convert(c, n, 2);
    printf("轉換為二進制為：%s\n", c);
    return length;
}

int toHexadecimal(int n)
{
    char c[sizeof(n)] = {};
    int length = convert(c, n, 16);
    printf("轉換為十六進制為：%s\n", c);
    return length;
}

char to_hexc(int x)
{
    if (x < 0)
    {
        return 0;
    }
    else if (x >= 16)
    {
        return 'F';
    }
    else
    {
        switch (x)
        {
            case 10:
                return 'A';
            case 11:
                return 'B';
            case 12:
                return 'C';
            case 13:
                return 'D';
            case 14:
                return 'E';
            case 15:
                return 'F';
            default:
                return x + '0';
        }
    }
}