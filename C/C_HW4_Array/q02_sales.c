#include<stdio.h>
#include"../myheaders/myarr.h"

/*
某一公司有五種產品 A、B、C、D 與 E，其單價分別為 12、16、10、14 與 15 元；而該公司共有三
位銷售員...
試計算：
a. 每一個銷售員的銷售總金額
b. 有最好業績（銷售總金額最多者）的銷售員
c. 每一項產品的銷售總金額
d. 銷售總金額最多的產品
*/

void a(int arr[]); //每一個銷售員的銷售總金額
void b(int arr[]); //有最好業績（銷售總金額最多者）的銷售員
void c(int arr[]); //每一項產品的銷售總金額
void d(int arr[]); //銷售總金額最多的產品

char names[][5][10] = {{"Jean", "Tom", "Tina"}, {"product.A", "product.B", "product.C", "product.D", "product.E"}};
int form[][5] = {{33, 32, 56, 45, 33}, {77, 33, 68, 45, 23}, {43, 55, 43, 67, 65}};

void main()
{
    int *sales_by_men = (int*)malloc(LENGTH(form) * sizeof(int)); // 分配 n 個字元的內存
    int *sales_by_products = (int*)malloc(LENGTH(form[0]) * sizeof(int)); // 分配 n 個字元的內存

    a(sales_by_men);
    b(sales_by_men);
    c(sales_by_products);
    d(sales_by_products);
    free(sales_by_men);
    free(sales_by_products);
}

void a(int arr[]) 
{
    printf("a. 每一個銷售員的銷售總金額\n");
    for (int i = 0; i < LENGTH(form); i++)
    {
        int sales = 0;
        for (int j = 0; j < LENGTH(form[0]); j++)
        {
            sales += form[i][j];
        }
        arr[i] = sales;
        printf("%s 的銷售額為：%d\n", names[0][i], sales);
    }
}

void b(int arr[])
{
    int men_num = LENGTH(form);
    int *arr_clone = (int*)malloc(men_num * sizeof(int)); // 分配 n 個整數的內存
    for (int i = 0; i < men_num; i++)
        arr_clone[i] = arr[i];

    bubble_sort(arr_clone, men_num);
    
    int best_man = 0;
    while (arr[best_man] < arr_clone[men_num - 1])
    {
        best_man++;
    }
    
    free(arr_clone);
    printf("b. 有最好業績（銷售總金額最多者）的銷售員為：%s\n", names[0][best_man]);
}

void c(int arr[]) 
{
    printf("c. 每一項產品的銷售總金額\n");
    for (int i = 0; i < LENGTH(form[0]); i++)
    {
        int sales = 0;
        for (int j = 0; j < LENGTH(form); j++)
        {
            sales += form[j][i];
        }
        arr[i] = sales;
        printf("%s 的銷售額為：%d\n", names[1][i], sales);
    }
}

void d(int arr[])
{
    int products_num = LENGTH(form[0]);
    int *arr_clone = (int*)malloc(products_num * sizeof(int)); // 分配 n 個整數的內存
    for (int i = 0; i < products_num; i++)
        arr_clone[i] = arr[i];

    bubble_sort(arr_clone, products_num);
    
    int best_product = 0;
    while (arr[best_product] < arr_clone[products_num - 1])
    {
        best_product++;
    }
    
    free(arr_clone);
    printf("d. 銷售總金額最多的產品為：%s\n", names[1][best_product]);
}