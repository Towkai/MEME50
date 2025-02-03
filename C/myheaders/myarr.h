#include<stdlib.h>
#include<string.h>
#include<time.h>
#define LENGTH(X) (sizeof(X)/sizeof(X[0])) //只能用在宣告當下，經傳遞後失效

void print_array(int arr[], int n) 
{
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf(n == 0 ? "]" : "\b\b]");
}

void random_arr(int arr[], int len) //產生一個長度為len的亂數陣列
{
    /* 設定亂數種子 */
    srand( time(NULL) );
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand();
        // printf("[%d] = %d, \n", i, arr[i]);
        // getch();
    }
    printf("\b\b \b\n");
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubble_sort(int arr[], int len)
{
    for (int times = 0; times < len - 1; times++)
    {
        // printf("times = %d\n", times);
        int is_clear = 1;
        for (int i = 0; i < len -1 - times; i++)\
        {
            if (arr[i] > arr[i + 1])
            {
                is_clear = 0;
                break;
            }
        }
        if (is_clear)
            return;
        for (int i = 0; i < len -1 - times; i++)
            if (arr[i] > arr[i + 1])
                swap(arr, i, i + 1);
        // print_array(arr, len);
    }
}