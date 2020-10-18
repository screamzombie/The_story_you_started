#include <iostream>
using namespace std;

class MyStack
{
private:
    int data;
    MyStack *next;

public:
    MyStack() : data(0), next(nullptr) {}
    MyStack(int data_ = 0, MyStack *next_ = nullptr) : data(data_), next(next_) {}
    ~MyStack()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
    bool exam()
    {
        if (next == nullptr)
        {
            return false;
        }
        return true;
    }
    int getData()
    {
        return data;
    }
    void flash(MyStack *q)
    {
        delete this->next;
        next = q; //将这个节点指向next
    }
    MyStack_P getNext()
    {
        return next;
    }
};
using MyStack_P = MyStack *;

MyStack_P Push(MyStack_P &p, int item)
{
    MyStack_P temp = new MyStack(item, p); //省时省力
    return temp;
}

int Pop(MyStack_P &p)
{
    
}

int main()
{
    MyStack_P head;
    Push(head, 12);
    cout << (*head).getData() << endl;
    return 0;
}