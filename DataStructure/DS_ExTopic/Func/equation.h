#include <stdlib.h>
#include <math.h>
typedef struct Polynomial
{
    int coefficient;    //係數
    int exponent;       //指數
} Polynomial;
typedef struct Item     //一個項
{
    Polynomial poly;
    struct Item *next;
} Item;

Polynomial *new_Polynomial(int coefficient, int exponent);
Item *new_Item(int coefficient, int exponent);
Item *new_Item_poly(Polynomial data);
Item *insertPoly(Item **head, Polynomial value);
void del(Item **head, Item *ptr);
Item *find(Item **head, Polynomial value);
void traverse(Item *head);
int length(Item **head);
Item *reverse(Item *head);
int equalItem(Polynomial a, Polynomial b);
Polynomial *mulItem(Polynomial a, Polynomial b);
void freeList(Item **head);
Item *addpolynomial(Item *a, Item *b);

Item *new_Item(int coefficient, int exponent)
{
    Polynomial newPoly = *new_Polynomial(coefficient, exponent);
    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->poly = newPoly;
    newItem->next = NULL;
    return newItem;
}
Item *new_Item_poly(Polynomial data)
{
    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->poly = data;
    newItem->next = NULL;
    return newItem;
}
Polynomial *new_Polynomial(int coefficient, int exponent)
{
    Polynomial *newPolynomial = (Polynomial *)malloc(sizeof(Polynomial));
    newPolynomial->coefficient = coefficient;
    newPolynomial->exponent = exponent;
    return newPolynomial;
}

/* insert a Item with value before ptr Item */
/** return success/failed */
Item *insertPoly(Item **head, Polynomial value)
{
    // 插入到空鏈表
    if (*head == NULL)
    {
        printf("[insertPoly]head == null\n");
        *head = new_Item_poly(value);
        return *head; // 成功
    }
    else
    {
        Item *p = *head;
        Item *prev = NULL;
        int i = 0;

        // 尋找插入位置
        printf("[insertPoly]p != NULL = %d\n", p != NULL);
        printf("[insertPoly]p->poly.exponent = %d, value.exponent = %d, %d\n", p->poly.exponent, value.exponent, p->poly.exponent <= value.exponent);
        while (p != NULL && p->poly.exponent > value.exponent) {
        printf("[insertPoly]while i = %d\n", i);
            if (p->poly.exponent == value.exponent) {
        printf("[insertPoly]p->poly.exponent == value.exponent\n");
                p->poly.coefficient += value.coefficient;
                return *head; // 如果指數相等，則更新係數並返回
            }
            prev = p;
            p = p->next;
            i++;
        }
        printf("[insertPoly]last_i = %d\n", i);
        if (p != NULL && p->poly.exponent == value.exponent)
        {
            p->poly.coefficient += value.coefficient;
        }
        else
        {

            Item *ins = new_Item_poly(value); // 新節點
            // 插入節點
            if (i == 0)
            {
                (*head)->next = ins;
            }
            else
            {
                if (prev->next == NULL) //加在最後面
                    prev->next = ins;
                else                    //插入在中間
                {
                    ins->next = prev->next; // 將新節點的 next 指向插入位置的節點
                    prev->next = ins;       // 更新前一個節點的 next 指向新節點
                    printf("[insertPoly]: ");
                    traverse(*head);
                }
            }
        }
        return *head; // 成功
    }
}
void delete(Item **head, Item *ptr)
{
    if (ptr == NULL)
        return;
    if (ptr == *head)
    { // 第一種情況: 刪除第一個節點
        *head = (*head)->next;
    }
    else
    {
        Item *p = *head;
        while (p->next != ptr) // 找節點ptr的前節點
            p = p->next;
        p->next = ptr->next;
    }
    free(ptr);
}

Item *find(Item **head, Polynomial value)
{
    Item *p = *head;
    while (p != NULL)
    {
        if (equalItem(p->poly, value))
            return p;
        p = p->next;
    }
    return p;
}

void traverse(Item *head)
{
    Item *p = head;
    if(head == NULL)
    {
        printf("[traverse]NULL\n");
    }
    else
    {
        while (p != NULL)
        {
            if (p->poly.coefficient != 0)
            {
                if (p != head)
                    if (p->poly.coefficient < 0)
                        printf(" -");
                    else
                        printf(" +");
                        
                if (p->poly.exponent == 1)  //x的一次方
                    p->poly.coefficient == 1 ? printf(" x") : printf(" %dx", abs(p->poly.coefficient));
                else if (p->poly.exponent == 0) //後面的常數
                    printf(" %d", p->poly.coefficient);
                else
                    p->poly.coefficient == 1 ? printf(" x^%d", p->poly.exponent) : printf(" %dx^%d", abs(p->poly.coefficient), p->poly.exponent);
            }
            else
            {
                printf(" +0");
            }
            p = p->next;
        }
    }
    printf("\n");
}

int count(Item *head)
{
    int count = 0;
    Item *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void freeList(Item **head)
{
    Item *p = *head;
    while (p != NULL)
    {
        Item *next = p->next;
        free(p);
        p = next;
    }
}

Item *reverse(Item *head)
{
    Item *p = head;
    Item *prev = NULL;
    while (p != NULL)
    {
        Item *next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    head->next = NULL;
    return prev;
}
Item *addpolynomial(Item *a, Item *b)
{
    Item *p = b;
    while (p != NULL)
    {
        insertPoly(&a, p->poly);
        p = p->next;
    }
    return a;
}
Item *mulpolynomial(Item *a, Item *b)
{
    Item *p = a;
    printf("[mulpolynomial]a: \n");
    traverse(a);
    Item *q = b;
    printf("[mulpolynomial]b: \n");
    traverse(b);
    Item *temp = NULL;
    printf("[mulpolynomial]temp: \n");
    traverse(temp);
    int i = 0;
    while (p != NULL)
    {
        q = b;
        while (q != NULL)
        {
            Polynomial *temp_poly = mulItem(p->poly, q->poly);
            insertPoly(&temp, *temp_poly);
            printf("[mulpolynomial]temp: %d %d\n", temp_poly->coefficient, temp_poly->exponent);
            traverse(temp);
            q = q->next;
            printf("[mulpolynomial]i = %d\n", i);
            i++;
        }
        p = p->next;
    }
    printf("[mulpolynomial]exit\n");
    return temp;
}
Polynomial *mulItem(Polynomial a, Polynomial b)
{
    printf("[mulItem]%dx^%d * %dx^%d\n", a.coefficient, a.exponent, b.coefficient, b.exponent);
    return new_Polynomial(a.coefficient * b.coefficient, a.exponent + b.exponent);
}
int equalItem(Polynomial a, Polynomial b)
{
    return a.coefficient == b.coefficient && a.exponent == b.exponent;
}