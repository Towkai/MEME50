#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
#include"../myheaders/myarr.h"

/*
事先將 10 個數字置於一維陣列中，分別找出 10 個數字中最大的值和最小的值。
*/

void main()
{
    int length;
    
    printf("輸入一個自然數：");
    scanf("%d", &length);
    
    printf("產生長度為 %d 的陣列：\n", length);
    // 使用 malloc 分配內存

    int *arr = (int*)malloc(length * sizeof(int)); // 分配 n 個整數的內存

    // 檢查 malloc 是否成功
    if (arr == NULL) {
        printf("內存分配失敗！\n");
        return; // 返回錯誤碼
    }
    random_arr(arr, length);
    printf("original_arr: ");
    print_array(arr, length);
    bubble_sort(arr, length);
    printf("sorted_arr: ");
    print_array(arr, length);
    printf("此陣列最小值為：%d，最大值為：%d\n", arr[0], arr[length - 1]);
    
    free(arr);
}

