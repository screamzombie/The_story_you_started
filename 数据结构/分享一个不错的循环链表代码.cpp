#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
typedef int EleType;


// ԭ������ https://blog.csdn.net/qq_29542611/article/details/79029540

/*
ѭ������Ľṹ�͵�����ṹһ�����������ڵ�����ÿ�����ֻ�洢������ָ�룬
����β��־��ֹͣ��������Ĳ���������֪��ĳ�����ȴ�޷��ҵ�����ǰ����㡣
���������е��ն˵��ָ���ɿ�ָ���Ϊָ��ͷ��㣬��ʹ�����������γ�һ������
����ͷβ��ӵĵ������Ϊѭ�����������ѭ������
*/
typedef struct CLinkNode
{
    EleType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

/*
��ʼ��ѭ������
*/
int InitCLinkList(CLinkList *list)
{
    if (list == NULL)
    {
        return ERROR;
    }

    int data = 0;
    CLinkNode *target = NULL;
    CLinkNode *head_node = NULL;
    printf("�����������ݣ�0���������ʼ��:\n");
    //��������û�����̨�������ݣ���Ҳ��������������ݽ��г�ʼ��
    while (1)
    {
        scanf("%d", &data);
        //fflush(stdin);
        if (data == 0)
        {
            //�˳�ѭ����־���û�����0 ��ʾ������������
            break;
        }

        /*
		�жϳ�ʼ����������û�н��
		û�н�� �ȴ���ͷ��� Ȼ���������
		�н�� �������β�巨���뵽������
		��� β���� ָ���� ָ��ͷ��� �����γ�һ����
		*/
        if (*list == NULL)
        {
            CLinkNode *head = (CLinkNode *)malloc(sizeof(CLinkNode));
            //������ռ�ʧ��
            if (head == NULL)
            {
                exit(0);
            }

            *list = head; //����ָ��ͷ���

            CLinkNode *node = (CLinkNode *)malloc(sizeof(CLinkNode));
            if (node == NULL)
            {
                exit(0);
            }
            node->data = data;
            node->next = head;
            head->next = node;
        }
        else
        {
            //���ѭ������Ϊ�� ��β����������
            //ͨ��ѭ�� �ҵ�β��㣬�����ж��Ƿ���β��㣿������ָ����ָ��ͷ���ʱΪβ��㣬���������γɻ���
            //ѭ��������target ָ��β���
            //for ѭ���ºú�����£�target��ʼ��Ϊ��һ�����ָ��
            for (target = (*list)->next; target->next != *list; target = target->next)
                ;
            head_node = target->next;

            CLinkNode *node = (CLinkNode *)malloc(sizeof(CLinkNode));
            if (node == NULL)
            {
                exit(0);
            }
            node->data = data;
            node->next = head_node;

            target->next = node; //���½�����β��
        }
    }
    return OK;
}
/*
������ָ��λ�ò�������
list ѭ������
loc ��locλ�ò���Ԫ�أ�loc ��1 ��ʼ����
data ����Ԫ�ص�������
*/
int InsertCLinkNode(CLinkList list, int loc, EleType data)
{
    if (list == NULL || loc < 1)
        return ERROR;
    /*
	ѭ��Ŀ�ģ��ҵ���loc-1λ�ý��
	*/
    int i = 1;              // ������Ķ��� i��ʾ��i��λ�� �� loc �����˼һ��
    CLinkNode *node = list; //�տ�ʼnodeָ��ͷ���
    while (node->next != list && i < loc)
    {
        node = node->next;
        i++;
    }
    /*
	����whileѭ���Ƚ�����⣬������ 3��Ԫ��ѭ������ ������
	loc = 1 ʱ ����1��λ�ò���Ԫ��
	������ѭ�� node ָ��ͷ��� i == loc == 1 ����Ϸ�
	loc = 2 ʱ
	node ָ�� ��1����㣬i = 2 ����ѭ��
	
	loc = 3 ʱ
	node ָ�� ��1����㣬i = 2 ѭ������
	node ָ�� ��2����㣬i = 3 ����ѭ��
	loc = 4 ʱ ע�⣺�����3��Ԫ�� ����4λ�ò���Ԫ�� �ǺϷ�������������β������Ԫ�ء� 
	node ָ�� ��1����㣬i = 2 ѭ������
	node ָ�� ��2����㣬i = 3 ѭ������
	node ָ�� ��3����㣬i = 4 ��������
	
	ѭ������ʱ i==loc �źϷ��� ��ʱnode ָ�� �� loc-1 λ�õĽ��
	�� �½���ָ���� ָ�� ��loc-1λ�õĺ�̽��
	�� ��loc-1λ�õ�ָ���� ָ�� �½�㣬�����½��Ͳ��뵽 ѭ������� ��locλ���ˣ�
	*/

    /*
	ѭ������ʱ i==loc �źϷ��� ��ʱnode ָ�� �� loc-1 λ�õĽ��
	�� �½���ָ���� ָ�� ��loc-1λ�õĺ�̽��
	�� ��loc-1λ�õ�ָ���� ָ�� �½�㣬�����½��Ͳ��뵽 ѭ������� ��locλ���ˣ�
	*/
    if (i == loc)
    {
        CLinkNode *new_node = (CLinkNode *)malloc(sizeof(CLinkNode));
        if (new_node == NULL)
        {
            exit(0);
        }
        new_node->data = data;
        new_node->next = node->next; //�½��ָ���� ָ��ǰ�����ĺ�̽��
        node->next = new_node;       //���½���������
    }
    else
    {
        return ERROR;
    }

    return OK;
}
/*
ɾ��ָ����㣬ͨ��ָ�뷵��ɾ����������
*/
int DelCLinkNode(CLinkList list, int loc, EleType *data)
{
    if (list == NULL || loc < 1)
        return ERROR;
    /*
	ѭ��Ŀ�ģ��ҵ���loc-1λ�ý��
	*/
    int i = 1;              // ������Ķ��� i��ʾ��i��λ�� �� loc �����˼һ��
    CLinkNode *node = list; //�տ�ʼnodeָ��ͷ���
    while (node->next != list && i < loc)
    {
        node = node->next;
        i++;
    }
    //ѭ������ node ָ�� loc-1 λ�� �� node ����Ϊβ���,Ϊʲô����Ϊβ��㣿��Ϊ����ɾ�� λ����û��Ԫ�صĽ�㣡
    if (i == loc && node->next != list)
    {
        CLinkNode *del_node = node->next; //��loc λ�ý��
        *data = del_node->data;           //����ɾ������������

        node->next = del_node->next; // ɾ������ ǰ����� ָ��ɾ������ ��̽�㣬����ɾ��λ�õĽ��Ͳ�����������
        free(del_node);              //�ͷſռ�
    }
    return OK;
}
/*
չʾѭ������Ԫ��
*/
int ShowCLinkList(CLinkList list)
{
    if (list == NULL)
    {
        return ERROR;
    }
    CLinkNode *target = NULL;
    printf("--------ѭ������Ԫ��------\n");
    for (target = list->next; target != list; target = target->next)
        printf("%d \t", target->data);
    printf("\n");
    return OK;
}
/*
��ȡ����Ԫ�ظ���
*/
int LengthCLinkList(CLinkList list)
{
    if (list == NULL)
    {
        return ERROR;
    }
    CLinkNode *target = NULL;
    int length = 0;
    for (target = list->next; target != list; target = target->next)
        length++;
    printf("ѭ������Ԫ�ظ���:%d\n", length);
    return OK;
}
/*
��ȡ�������ݻ�ȡ����λ��
*/
int IndexCLinkList(CLinkList list, int data)
{
    if (list == NULL)
    {
        return ERROR;
    }
    CLinkNode *target = NULL;
    int length = 0;
    int index = -1;
    for (target = list->next; target != list; target = target->next)
    {
        length++;
        if (target->data == data)
        {
            index = length;
        }
    }
    if (index == -1)
    {
        printf("����%d��ѭ�������в�����\n", data);
    }
    else
    {
        printf("����%d�ڵ�%d��λ��\n", data, index);
    }
    return index;
}
/*
��ȡ��i��������������
*/
int IndexOfCLinkList(CLinkList list, int index)
{
    if (list == NULL || index < 1)
    {
        return ERROR;
    }
    CLinkNode *target = NULL;
    int length = 0;
    int data = -1;
    for (target = list->next; target != list; target = target->next)
    {
        length++;
        if (length == index)
        {
            data = target->data;
        }
    }
    if (index > length)
    {
        printf("��%d��λ�ý�㲻����\n", index);
    }
    else
    {
        printf("��%d��λ�õ�����:%d\n", index, data);
    }
    return data;
}
int main(int argc, char *argv[])
{
    int flag = 0;
    CLinkList list = NULL;
    while (1)
    {
        printf("===============ѭ�������ܲ˵�===========\n");
        printf("===============1����ʼ��ѭ������==========\n");
        printf("===============2������Ԫ��================\n");
        printf("===============3��ɾ��Ԫ��================\n");
        printf("===============4��չʾԪ��================\n");
        printf("===============5��ѭ������Ԫ�ظ���========\n");
        printf("===============6���������ݲ�ѯ���λ��====\n");
        printf("===============7������λ�ò�ѯ�������====\n");
        printf("===============0���˳��˵�================\n");
        scanf("%d", &flag);
        //fflush(stdin);
        if (flag == 0)
            break;
        if (flag == 1)
        {
            list = NULL;
            InitCLinkList(&list);
            ShowCLinkList(list);
        }
        else if (flag == 2)
        {
            int loc = 0;
            int data = 0;
            printf("���������Ԫ�ص�λ�ú�����:\n");
            scanf("%d", &loc);
            scanf("%d", &data);
            InsertCLinkNode(list, loc, data);
            ShowCLinkList(list);
        }
        else if (flag == 3)
        {
            int loc = 0;
            int data = 0;
            printf("������ɾ��Ԫ�ص�λ��:\n");
            scanf("%d", &loc);
            DelCLinkNode(list, loc, &data);
            ShowCLinkList(list);
        }
        else if (flag == 4)
        {
            ShowCLinkList(list);
        }
        else if (flag == 5)
        {
            LengthCLinkList(list);
        }
        else if (flag == 6)
        {
            int loc = 0;
            printf("���������Ԫ�ص�λ��:\n");
            scanf("%d", &loc);
            IndexOfCLinkList(list, loc);
        }
        else if (flag == 7)
        {
            int data = 0;
            printf("���������Ԫ�ص�����:\n");
            scanf("%d", &data);
            IndexCLinkList(list, data);
        }
    }
    return 0;
}