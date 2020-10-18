#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
typedef int EleType;


// 原文链接 https://blog.csdn.net/qq_29542611/article/details/79029540

/*
循环链表的结构和单链表结构一样，不过对于单链表，每个结点只存储了向后的指针，
到了尾标志就停止了向后链的操作，这样知道某个结点却无法找到它的前驱结点。
将单链表中的终端点的指针由空指针改为指向头结点，就使整个单链表形成一个环，
这种头尾相接的单链表称为循环单链表，简称循环链表。
*/
typedef struct CLinkNode
{
    EleType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

/*
初始化循环链表
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
    printf("请输入结点数据，0代表结束初始化:\n");
    //这里采用用户控制台输入数据，你也可以随机生成数据进行初始化
    while (1)
    {
        scanf("%d", &data);
        //fflush(stdin);
        if (data == 0)
        {
            //退出循环标志，用户输入0 表示结束输入数据
            break;
        }

        /*
		判断初始化的链表有没有结点
		没有结点 先创建头结点 然后插入数据
		有结点 将结点用尾插法插入到链表中
		最后 尾结点的 指针域 指向头结点 这样形成一个环
		*/
        if (*list == NULL)
        {
            CLinkNode *head = (CLinkNode *)malloc(sizeof(CLinkNode));
            //分配结点空间失败
            if (head == NULL)
            {
                exit(0);
            }

            *list = head; //链表指向头结点

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
            //如果循环链表不为空 链尾部插入数据
            //通过循环 找到尾结点，怎样判断是否是尾结点？当结点的指针域指向头结点时为尾结点，这样才能形成环嘛
            //循环结束后target 指向尾结点
            //for 循环下好好理解下！target初始化为第一个结点指针
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

            target->next = node; //将新结点插入尾部
        }
    }
    return OK;
}
/*
往链表指定位置插入数据
list 循环链表
loc 第loc位置插入元素，loc 从1 开始计数
data 插入元素的数据域
*/
int InsertCLinkNode(CLinkList list, int loc, EleType data)
{
    if (list == NULL || loc < 1)
        return ERROR;
    /*
	循环目的：找到第loc-1位置结点
	*/
    int i = 1;              // 按人类的读法 i表示第i个位置 和 loc 表达意思一致
    CLinkNode *node = list; //刚开始node指向头结点
    while (node->next != list && i < loc)
    {
        node = node->next;
        i++;
    }
    /*
	这里while循环比较难理解，我们拿 3个元素循环链表 来讲解
	loc = 1 时 往第1个位置插入元素
	不进入循环 node 指向头结点 i == loc == 1 插入合法
	loc = 2 时
	node 指向 第1个结点，i = 2 跳出循环
	
	loc = 3 时
	node 指向 第1个结点，i = 2 循环继续
	node 指向 第2个结点，i = 3 跳出循环
	loc = 4 时 注意：如果有3个元素 往第4位置插入元素 是合法！等于往链表尾部插入元素。 
	node 指向 第1个结点，i = 2 循环继续
	node 指向 第2个结点，i = 3 循环继续
	node 指向 第3个结点，i = 4 跳出继续
	
	循环结束时 i==loc 才合法！ 此时node 指向 第 loc-1 位置的结点
	将 新结点的指针域 指向 第loc-1位置的后继结点
	将 第loc-1位置的指针域 指向 新结点，这样新结点就插入到 循环链表的 第loc位置了！
	*/

    /*
	循环结束时 i==loc 才合法！ 此时node 指向 第 loc-1 位置的结点
	将 新结点的指针域 指向 第loc-1位置的后继结点
	将 第loc-1位置的指针域 指向 新结点，这样新结点就插入到 循环链表的 第loc位置了！
	*/
    if (i == loc)
    {
        CLinkNode *new_node = (CLinkNode *)malloc(sizeof(CLinkNode));
        if (new_node == NULL)
        {
            exit(0);
        }
        new_node->data = data;
        new_node->next = node->next; //新结点指针域 指向前驱结点的后继结点
        node->next = new_node;       //将新结点加入链表
    }
    else
    {
        return ERROR;
    }

    return OK;
}
/*
删除指定结点，通过指针返回删除结点的数据
*/
int DelCLinkNode(CLinkList list, int loc, EleType *data)
{
    if (list == NULL || loc < 1)
        return ERROR;
    /*
	循环目的：找到第loc-1位置结点
	*/
    int i = 1;              // 按人类的读法 i表示第i个位置 和 loc 表达意思一致
    CLinkNode *node = list; //刚开始node指向头结点
    while (node->next != list && i < loc)
    {
        node = node->next;
        i++;
    }
    //循环结束 node 指向 loc-1 位置 且 node 不能为尾结点,为什么不能为尾结点？因为不能删除 位置上没有元素的结点！
    if (i == loc && node->next != list)
    {
        CLinkNode *del_node = node->next; //第loc 位置结点
        *data = del_node->data;           //返回删除结点的数据域

        node->next = del_node->next; // 删除结点的 前驱结点 指向删除结点的 后继结点，这样删除位置的结点就不在链表中了
        free(del_node);              //释放空间
    }
    return OK;
}
/*
展示循环链表元素
*/
int ShowCLinkList(CLinkList list)
{
    if (list == NULL)
    {
        return ERROR;
    }
    CLinkNode *target = NULL;
    printf("--------循环链表元素------\n");
    for (target = list->next; target != list; target = target->next)
        printf("%d \t", target->data);
    printf("\n");
    return OK;
}
/*
获取链表元素个数
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
    printf("循环链表元素个数:%d\n", length);
    return OK;
}
/*
获取根据数据获取结点的位置
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
        printf("数据%d在循环链表中不存在\n", data);
    }
    else
    {
        printf("数据%d在第%d个位置\n", data, index);
    }
    return index;
}
/*
获取第i个结点的数据内容
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
        printf("第%d个位置结点不存在\n", index);
    }
    else
    {
        printf("第%d个位置的数据:%d\n", index, data);
    }
    return data;
}
int main(int argc, char *argv[])
{
    int flag = 0;
    CLinkList list = NULL;
    while (1)
    {
        printf("===============循环链表功能菜单===========\n");
        printf("===============1、初始化循环链表==========\n");
        printf("===============2、插入元素================\n");
        printf("===============3、删除元素================\n");
        printf("===============4、展示元素================\n");
        printf("===============5、循环链表元素个数========\n");
        printf("===============6、根据数据查询结点位置====\n");
        printf("===============7、根据位置查询结点数据====\n");
        printf("===============0、退出菜单================\n");
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
            printf("请输入插入元素的位置和数据:\n");
            scanf("%d", &loc);
            scanf("%d", &data);
            InsertCLinkNode(list, loc, data);
            ShowCLinkList(list);
        }
        else if (flag == 3)
        {
            int loc = 0;
            int data = 0;
            printf("请输入删除元素的位置:\n");
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
            printf("请输入查找元素的位置:\n");
            scanf("%d", &loc);
            IndexOfCLinkList(list, loc);
        }
        else if (flag == 7)
        {
            int data = 0;
            printf("请输入查找元素的数据:\n");
            scanf("%d", &data);
            IndexCLinkList(list, data);
        }
    }
    return 0;
}