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
    Node_p tmp = &head; // һ��ָ��ͷ�ڵ��ָ��
    Node_p h = tmp;
    for (int i = 0; i < 10; i++)
    {
        tmp->data = i;
        tmp->next = new Node; //����ռ�
        tmp = tmp->next;      //������ǰ��
    }
    // ���ڵ����Ӧ����������
    // 0 1 2 3 4 5 6 7 8 9 -1
    Node_p test = h;
    while (test->next != NULL)
    {
        cout << test->data << " ";
        test = test->next;
    }
    cout << test->data << endl;
    test->next = h; //�����һ���ڵ��nextָ���ֽڵ�
    cout << test->next->data << endl;
    cout << "�������ǿ���������10Ȧ��" << endl;
    int T = 110;
    while (T--)
    {
        if (test->data >= 0)
            cout << test->data << " ";
        test = test->next;
    }
    return 0;
}
