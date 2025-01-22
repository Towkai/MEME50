#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void append(Node **head, int value);
void addList(Node **head, Node *append);
int insert(Node **head, int value, int index);
int insertList(Node **head, Node *list, int index);
void insertNode(Node **head, Node *ptr, int value);
void del(Node **head, Node *ptr);
Node *find(Node **head, int value);
void traverse(Node *head);
int length(Node **head);
void freeList(Node **head);
Node *new_Node(int data);
Node *reverse(Node *head);

Node *new_Node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* append tail Node with value */
void append(Node **head, int value)
{
    Node *node = new_Node(value);

    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        Node *p = *head;
        while (p->next != NULL)
            p = p->next;
        p->next = node;
    }
}
void addList(Node **head, Node *append)
{
    if (*head == NULL)
    {
        *head = append;
    }
    else
    {
        Node *p = *head;
        while (p->next != NULL)
            p = p->next;
        p->next = append;
    }
}

/* insert a Node with value before ptr Node */
/** return success/failed */
int insert(Node **head, int value, int index)
{
    // 插入到空鏈表
    if (*head == NULL)
    {
        append(head, value);
        return 1; // 成功
    }
    else
    {
        Node *p = *head;
        Node *prev = NULL;
        int i = 0;

        // 尋找插入位置
        while (i < index)
        {
            if (p == NULL)
            {
                return 0; // 原始鏈表長度不足
            }
            prev = p;
            p = p->next;
            i++;
        }

        Node *ins = new_Node(value); // 新節點
        // 插入節點
        if (index == 0)
        {
            ins->next = *head; // 在頭部插入
            *head = ins;       // 更新頭指針
        }
        else
        {
            ins->next = prev->next; // 將新節點的 next 指向插入位置的節點
            prev->next = ins;       // 更新前一個節點的 next 指向新節點
        }
        return 1; // 成功
    }
}
/** return success/failed */
int insertList(Node **head, Node *insList, int index)
{
    // 插入到空鏈表
    if (*head == NULL)
    {
        addList(head, insList);
        return 1; // 成功
    }
    else
    {
        Node *p = *head;
        Node *prev = NULL;
        int i = 0;

        // 尋找插入位置
        while (i < index)
        {
            if (p == NULL)
            {
                return 0; // 原始鏈表長度不足
            }
            prev = p;
            p = p->next;
            i++;
        }

        // 插入節點
        if (index == 0)
        {
            insList->next = *head; // 在頭部插入
            *head = insList;       // 更新頭指針
        }
        else
        {
            p->next = prev->next; // 將新節點的 next 指向插入位置的節點
            prev->next = insList; // 更新前一個節點的 next 指向新節點
        }
        return 1; // 成功
    }
}
void insertNode(Node **head, Node *ptr, int value)
{
    Node *node = new_Node(value);

    if (ptr == NULL)
    {
        append(head, value);
    }
    else
    {
        node->next = ptr;
        if (ptr == *head)
            *head = node;
        else
        {
            Node *p = *head;
            while (p->next != ptr)
                p = p->next;
            p->next = node;
        }
    }
}
void delete(Node **head, Node *ptr)
{
    if (ptr == NULL)
        return;
    if (ptr == *head)
    { // 第一種情況: 刪除第一個節點
        *head = (*head)->next;
    }
    else
    {
        Node *p = *head;
        while (p->next != ptr) // 找節點ptr的前節點
            p = p->next;
        p->next = ptr->next;
    }
    free(ptr);
}

Node *find(Node **head, int value)
{
    Node *p = *head;
    while (p != NULL)
    {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return p;
}

void traverse(Node *head)
{
    printf("[");
    Node *p = head;
    while (p != NULL)
    {
        if (p != head)
            printf(",");
        printf("%d", p->data);
        p = p->next;
    }
    printf("]\n");
}

int count(Node *head)
{
    int count = 0;
    Node *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void freeList(Node **head)
{
    Node *p = *head;
    while (p != NULL)
    {
        Node *next = p->next;
        free(p);
        p = next;
    }
}

Node *reverse(Node *head)
{
    Node *p = head;
    Node *last = NULL;
    while (p != NULL)
    {
        Node *next = p->next;
        p->next = last;
        last = p;
        p = next;
    }
    head->next = NULL;
    return last;
}