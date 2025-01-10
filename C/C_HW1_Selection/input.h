int setchar(int *x);    //傳入位址修改變數
int setchar(int *x)
{
    int input = getchar();
    *x = input;
	getchar();
    return input;
}