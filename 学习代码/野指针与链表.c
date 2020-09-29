/*
 *      Auther: ScreamZombie
 *      Time: 2020/9/29
 *      Email: SuduRainbowCat@gmail.com
 *      System: Ubuntu 18.04
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Link //�ṹ�嶨��
{
    int data;
    struct Link *next;
} Node, *Node_P;

int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //�����������

void MakeLink(Node_P *l)
{
    (*l) = (Node_P)malloc(sizeof(Node)); //�����һ��ͷ�ڵ���
    (*l)->data = 0;
    Node_P *tmp = &((*l)->next);
    for (int i = 0; i < 10; i++)
    {
        (*tmp) = (Node_P)malloc(sizeof(Node));
        (*tmp)->data = test[i];
        tmp = &((*tmp)->next); //����ָ����
    }
    *tmp = NULL; //��һ������Ҫ����ֵʮ�򣬾�����ôһ�仰������������Сʱ
}

void PrintLink(Node_P l) //��ӡ����
{
    printf("ͷ�ڵ��ֵ��%d\n", l->data);
    while (l->next != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("%d\n", l->data);
}

Node_P SearchNode(Node_P l, int obj) // ����Ԫ�أ����ص���һ���ṹ��ָ��
{
    int len = 0;
    while (l->next != NULL) // һ·����β�ڵ�
    {
        if (l->data == obj)
        {
            printf("�ҵ�����λ����%d\n", len);
            return l;
        }
        l = l->next;
        len++;
    }
    if (l->data == obj)
    {
        printf("�ҵ�����λ����%d\n", len);
        return l;
    }
    else //Ҫ�ǻ�û���ҵ�
    {
        printf("û���ҵ���Ԫ��\n");
        return NULL;
    }
}

void RemoveNode(Node_P *l, int n) //ɾ���ڵ�
{
    Node_P tmp = (*l);
    for (int i = 0; i < n - 1; i++)
        tmp = tmp->next;        //����ڵ�ǰ��,�ҵ����������ʵ��Ҫɾ���Ľڵ��ǰһ���ڵ�
    l = &tmp;                   //���¶�λ��
    Node_P A = tmp->next->next; //��һ����Ҫɾ�Ľڵ㣬����һ������Ҫ����ȥ�Ľڵ�
    free((*l)->next);
    (*l)->next = A;
}

void InstertNode(Node_P *l, int n, int number) //����Ԫ��
{
    Node_P tmp = (*l);
    for (int i = 0; i < n; i++)
        tmp = tmp->next;
    l = &tmp;                                  //���¶�λ��
    Node_P mid = (Node_P)malloc(sizeof(Node)); //�Ȱ��м�Ҫ����Ľڵ㴴����
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