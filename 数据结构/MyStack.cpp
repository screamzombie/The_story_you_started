#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class MyStack
{
public:
    struct Node
    {
        T data;
        Node *next;
        Node(T data_ = {}, Node *next_ = nullptr)
            : data(data_), next(next_) {}
    };

public:
    MyStack() : length(0), rear(&head) {}
    ~MyStack()
    {
        clear();
    }

public:
    int size()
    {
        return length;
    }

    bool empty()
    {
        return length;
    }

    void push(T item)
    {
        rear->next = new Node(item); //��Զָ��β�ڵ�,�൱����������д��
        // rear->next = new Node;
        // rear->next->data = item;
        length++;
        rear = rear->next;
    }

    T top() //�������һ��Ԫ��
    {
        assert(length != 0);
        return rear->data;
    }

    void pop()
    {
        assert(length != 0);
        Node *temp = &head;
        while (temp->next->next != nullptr) //�ҵ������ڶ����ڵ�
        {
            temp = temp->next; //����������
        }
        delete temp->next;
        temp->next = nullptr;
        rear = temp;
        length--;
    }

    void clear()
    {
        if (length == 0)
            return;
        Node *prev = head.next; //ɾ����ʵ������prev
        while (prev->next != nullptr)
        {
            Node *temp = prev->next;
            delete prev;
            prev = temp;
        }
        head.next = nullptr; //ͬ�������⣬����ָ��
        length = 0;
    }

    template <typename Functor>
    void foreach (Functor f)
    {
        assert(length != 0);
        Node *iter = head.next;
        while (iter->next != nullptr)
        {
            f(iter->data);
            iter = iter->next;
        }
    }

private:
    int length;
    Node *rear;
    Node head; //һ��ͷ�ڵ�
};

int main()
{
    MyStack<int> hello;
    hello.push(1);
    for (size_t i = 0; i < 10; i++)
    {
        hello.push(i);
    }
    cout << hello.top() << endl;
    hello.pop();
    hello.clear();
    cout << hello.top() << endl;
    return 0;
}