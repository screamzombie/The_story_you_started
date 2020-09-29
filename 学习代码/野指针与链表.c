/*
 *      Auther: ScreamZombie
 *      Time: 2020/9/29
 *      Email: SuduRainbowCat@gmail.com
 *      System: Ubuntu 18.04
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Link //结构体定义
{
    int data;
    struct Link *next;
} Node, *Node_P;

int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //定义测试数据

void MakeLink(Node_P *l)
{
    (*l) = (Node_P)malloc(sizeof(Node)); //创造出一个头节点来
    (*l)->data = 0;
    Node_P *tmp = &((*l)->next);
    for (int i = 0; i < 10; i++)
    {
        (*tmp) = (Node_P)malloc(sizeof(Node));
        (*tmp)->data = test[i];
        tmp = &((*tmp)->next); //重新指向了
    }
    *tmp = NULL; //这一步很重要，价值十万，就是这么一句话困扰了我数个小时
}

void PrintLink(Node_P l) //打印链表
{
    printf("头节点的值是%d\n", l->data);
    while (l->next != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("%d\n", l->data);
}

Node_P SearchNode(Node_P l, int obj) // 查找元素，返回的是一个结构体指针
{
    int len = 0;
    while (l->next != NULL) // 一路摸到尾节点
    {
        if (l->data == obj)
        {
            printf("找到啦！位置在%d\n", len);
            return l;
        }
        l = l->next;
        len++;
    }
    if (l->data == obj)
    {
        printf("找到啦！位置在%d\n", len);
        return l;
    }
    else //要是还没有找到
    {
        printf("没有找到此元素\n");
        return NULL;
    }
}

void RemoveNode(Node_P *l, int n) //删除节点
{
    Node_P tmp = (*l);
    for (int i = 0; i < n - 1; i++)
        tmp = tmp->next;        //这个节点前移,找到的是这个其实是要删除的节点的前一个节点
    l = &tmp;                   //重新定位！
    Node_P A = tmp->next->next; //下一个是要删的节点，再下一个则是要接上去的节点
    free((*l)->next);
    (*l)->next = A;
}

void InstertNode(Node_P *l, int n, int number) //插入元素
{
    Node_P tmp = (*l);
    for (int i = 0; i < n; i++)
        tmp = tmp->next;
    l = &tmp;                                  //重新定位！
    Node_P mid = (Node_P)malloc(sizeof(Node)); //先把中间要插入的节点创建好
    mid->data = number;
    mid->next = tmp->next;
    (*l)->next = mid;
}

int main()
{
    Node_P head;
    Node_P *head_Ptr = &head;
    MakeLink(head_Ptr);
    PrintLink(head);
    Node_P ser = SearchNode(head, 7);
    RemoveNode(head_Ptr, 5);
    PrintLink(head);
    InstertNode(head_Ptr, 3, -1);
    PrintLink(head);
    return 0;
}