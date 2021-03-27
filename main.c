#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for use boolean type


//Task 1
#define SZ 10

typedef struct
{
    int pr;
    int dat;
} Node;

Node *arr[SZ];
int head;
int tail;
int items;

// Инициализация очереди с приоритетным включением
void init()
{
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

// Вставка с приоритетным включением
void ins(int pr, int dat)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (items == 0)
    {
        arr[tail++] = node;
        items++;
    }
    else if (items == SZ)
    {
        printf("Queue is full");
        free(node);
        return;
    }
    else
    {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i)
        {
            idx = i % SZ;
            if (arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx % SZ;
        i++;
        while (i <= tail)
        {
            idx = i % SZ;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}

// Удаление с приоритетным включением
Node *rem()
{
    if (items == 0)
        return NULL;
    else
    {
        int idx = head++ % SZ;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}

// Вывод очереди
void printQueue()
{
    printf("[ ");
    for (int i = 0; i < SZ; ++i)
    {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

// Инициализация очереди с приоритетным исключениями
void init1()
{
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    items = 0;
}

// Вставка с приоритетным исключением
void ins1(int pr, int dat)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == SZ)
    {
        printf("Queue is full");
        free(node);
        return;
    }
    else
    {
        arr[items++] = node;
    }
}

// Удаление с приоритетным исключением
Node *rem1()
{
    if (items == 0)
        return NULL;
    else
    {
        int pr_min=arr[0]->pr;
        int idx=0;
        for (int i = 1; i < SZ; ++i) {
            if (arr[i]==NULL) {break;}
            if (arr[i]->pr < pr_min) {
                idx=i; pr_min=arr[i]->pr;
            }
        }
        Node *tmp = arr[idx];
        for (int i=idx;i<items;++i) {
            arr[i]=arr[i+1];
        }
        free(arr[items--]);
        return tmp;
    }
}

//Task 2

#define T char
#define SIZE 1000

int cursor = -1;
T Stack[SIZE];

bool push(T data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = ((char)'0'+data);
        return true;
    }
    else
    {
        printf("Stack overflow\n");
        return false;
    }
}

T pop()
{
    if (cursor != -1)
        return Stack[cursor--];
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

void DecToBin(int a) {
    printf("%d=",a);
    do {
        push(a%2);
    } while ((a/=2)!=0);

    while (cursor != -1)
        printf("%c", pop());
    printf("\n");
}

int main()
{
    printf("Task 1\n");
    init1();
    ins1(1, 11);
    ins1(3, 22);
    ins1(4, 33);
    ins1(2, 44);
    ins1(3, 55);
    ins1(4, 66);
    ins1(5, 77);
    ins1(1, 88);
    ins1(2, 99);
    ins1(6, 100);

    printQueue();

    for (int i = 0; i < 7; ++i)
    {
        Node *n = rem1();
        printf("pr = %d, dat = %d\n", n->pr, n->dat);
    }

    printQueue();
    printf("\n");

    ins1(1, 110);
    ins1(3, 120);
    ins1(6, 130);

    printQueue();

    for (int i = 0; i < 5; ++i)
    {
        Node *n = rem1();
        printf("pr = %d, dat = %d\n", n->pr, n->dat);
    }

    printQueue();
    printf("\n");

    printf("Task 2\n");

    DecToBin(13);
    DecToBin(125);

    printf("\n");

    return 0;
}
