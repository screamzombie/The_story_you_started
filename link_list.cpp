#include <iostream>
using namespace std;
struct link_list
{
    int data = 0;           //数据域
    link_list *next = NULL; //指针域
};
using link_list_p = link_list *; //这就是C++嘛！！！

int main()
{
    int number = 10;
    int test[10]{0};
    for (int i = 0; i < 10; i++)
        test[i] = i;
    link_list head;
    link_list_p Ptr = &head; //作为公共的指针,并且在这里先指向一个头节点
    int t = 0;
    while (number--)
    {
        int temp = test[t];
        t++;
        if (Ptr->next == NULL) //说明要需要分配内存了
        {
            Ptr->next = new (link_list); //申请空间
            Ptr->data = temp;            //此时Ptr所指向的节点的数据域等于这个数字
            Ptr = Ptr->next;             //Ptr 指向Ptr所指向的节点的指针域所指向的那片内存空间
        }
    }
    /*
        链表的创建工作就是这样的，利用一个公共指针，当作工具，就像你早上在床上拿遥控器一样
        伸手去抓住每一个子节点，然后再把自己拖一下，往前拖一格。之后继续重复上诉步骤
        下面我们来看链表如何查看数据
    */
    link_list_p L_Ptr = &head; //创建一个名为查看指针的指针，它现在指向头节点
    if (L_Ptr->next == NULL)
    {
        cout << Ptr->data << endl; //说明这就一个头节点，虽然就一个点但你还得说这玩意是一个链表
    }
    else //也就是不是只有一个头节点的情况
    {
        while (L_Ptr->next != NULL) //如果，这个指针所指向的节点的指针域不是NULL的话，说明后面还有其他节点
        {
            cout << L_Ptr->data << endl; //输出指针所指向的节点的数据域的数据
            L_Ptr = L_Ptr->next;         //指针沿着节点前进
        }
    }

    /*
        假设我们要在第三和第四个节点之间在加一个新的节点进去，那我们应该怎么做呢？
    */
    cout << "下面是链表的增加删除节点" << endl;
    link_list_p C_Ptr = &head;
    int cnt = 0; //记个数哦
    while (C_Ptr->next != NULL)
    {
        if (cnt == 2) //现在说明，指针指向我们想要的那个节点了，为什么不是3，因为指针前移俩次，就从1到3了
        {
            link_list_p T_Ptr = C_Ptr->next; //先记录一下，不然等下断了就找不到后面的东西了
           // cout << "hello?" << endl;
            C_Ptr->next = new (link_list); //然后3节点的指针域就不指向4节点了，而是指向新申请来的节点
            C_Ptr->next->data = -1;        //因为是新增的，所以为了表示特殊我们将这个节点的数据域赋值为-1
            C_Ptr->next->next = T_Ptr;     //把节点再给接上
            cnt++;
        }
        else
        {
            cout << C_Ptr->data << endl; //输出作用域和上面是一样的
            C_Ptr = C_Ptr->next;         //指针前移哦
            cnt++;
        }
        //计数器加1
    }
    //复制上面的代码再次查看这个链表，不要吐槽我为什么不用函数

    L_Ptr = &head; //创建一个名为查看指针的指针，它现在指向头节点
    if (L_Ptr->next == NULL)
    {
        cout << Ptr->data << endl; //说明这就一个头节点，虽然就一个点但你还得说这玩意是一个链表
    }
    else //也就是不是只有一个头节点的情况
    {
        while (L_Ptr->next != NULL) //如果，这个指针所指向的节点的指针域不是NULL的话，说明后面还有其他节点
        {
            cout << L_Ptr->data << endl; //输出指针所指向的节点的数据域的数据
            L_Ptr = L_Ptr->next;         //指针沿着节点前进
        }
    }
    //第一遍编码有问题
    return 0;
}
