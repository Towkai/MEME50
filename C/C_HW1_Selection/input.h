int setchar(int *x);    //傳入位址修改變數
int is_input_t();
int setchar(int *x)
{
    int input = getchar();
    *x = input;
	getchar();
    return input;
}
int is_input_t()
{
    int input;
    setchar(&input);
	if (input == 89 || input == 121)
		return 1;
	else
		return 0;
}
