#include <iostream>

using namespace std;

struct Node //结构体 分子
{
    int data = 0;         //data 原子
    Node* next = nullptr; //指针 原子
};

using Node_P = Node*; //int *

int test[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


void Makelist(Node& qw) //制造一个列表   //稳定版，But why?!
{          
    Node_P Ptr = &qw;        //你操纵的是每个节点,这根指针是公用的，下面的写法公用指针是头节点的一部分当然不行了
    for (int i = 0; i < 10; i++)
    {
        Ptr->next = new (Node);         //申请空间
        Ptr->data = test[i];            //此时Ptr所指向的节点的数据域等于这个数字
        Ptr = Ptr->next;                //Ptr 指向Ptr所指向的节点的指针域所指向的那片内存空间
    }
}

/*
void Makelist(Node& qw) //这俩种写法有什么区别呢？！
{
    Node_P Ptr = qw.next; 
    for (int i = 0; i < 10; i++)
    {
        Ptr = new Node;
        Ptr->data = test[i];
        Ptr->next ;    //似乎好像没有问题吧，But?why
    }
}

*/
void Printlist(Node_P qw)
{
    while (qw->next != nullptr)
    {
        cout << qw->data << " ";
        qw = qw->next;
    }
    cout << qw->data << endl;
}

int main()
{
    Node head;
    Node& head_R = head;
    Node_P head_P = &head;
    Makelist(head_R);
    Printlist(head_P);
    return 0;
}