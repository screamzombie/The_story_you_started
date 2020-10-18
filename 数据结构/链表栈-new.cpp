#include <iostream>
using namespace std;

class MyStack
{
public:
    int data;
    MyStack *next;
    MyStack(int data_ = 0, MyStack *next_ = nullptr) : data(data_), next(next_) {}
    ~MyStack() {}
};

using MyStack_P = MyStack *;
MyStack *push(MyStack_P t, int item)
{
    MyStack *p = new MyStack(item, nullptr);
    p->next = t;
    return p;
}

int pop(MyStack_P &t)
{
    if (t != nullptr) //如果t != nullptr
    {
        int temp = t->data; //说明有问题
        t = t->next;
        return temp;
    }
    else
    {
        return -1;
    }
}

void Transform()
{
    int a = 16, b = 2;
    cout << "please input a number" << endl;
    cin >> a;
    cout << "please input a k" << endl;
    cin >> b;
    MyStack_P head = nullptr;
    while (a)
    {
        int z = a % b;
        head = push(head, a % b);
        a /= b;
    }
    int temp = 1;
    while ((temp = pop(head)) != -1)
        cout << temp << " ";
    cout << endl;
}

int main()
{
    Transform();
    return 0;
}
