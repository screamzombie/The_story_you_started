#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int, Node *);
};
using Node_p = Node *;
Node::Node(int data_ = -1, Node_p next_ = NULL) : data(data_), next(next_) {}
int main()
{
    Node head;
    Node_p tmp = &head; // 一个指向头节点的指针
    Node_p h = tmp;
    for (int i = 0; i < 10; i++)
    {
        tmp->data = i;
        tmp->next = new Node; //分配空间
        tmp = tmp->next;      //链接器前进
    }
    // 现在的情况应该是这样的
    // 0 1 2 3 4 5 6 7 8 9 -1
    Node_p test = h;
    while (test->next != NULL)
    {
        cout << test->data << " ";
        test = test->next;
    }
    cout << test->data << endl;
    test->next = h; //让最后一个节点的next指向手节点
    cout << test->next->data << endl;
    cout << "现在我们可以愉快的跑10圈了" << endl;
    int T = 110;
    while (T--)
    {
        if (test->data >= 0)
            cout << test->data << " ";
        test = test->next;
    }
    return 0;
}
