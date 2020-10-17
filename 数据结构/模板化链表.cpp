#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class List
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
    List()
        : length(0), rear(&head) {}
    ~List()
    {
        clear();
    }

public:
    int size() const
    {
        return length;
    }

    bool empty() const
    {
        return length == 0;
    }

    void push(T item)
    {
        rear->next = new Node(item);
        length++;
        rear = rear->next;
    }

    T pop()
    {
        assert(length != 0);
        Node *temp = &head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        rear = temp;
        length--;
    }

    void clear()
    {
        if(length == 0) return;
        Node *prev = head.next;
        while (prev != nullptr)
        {
            Node *temp = prev->next;
            delete prev;
            prev = temp;
        }
        head.next = nullptr; //垂悬指针
        length = 0;
    }

    template <typename Functor>
    void foreach (Functor f)
    {
        Node *iter = head.next;
        while (iter != nullptr)
        {
            f(iter->data);
            iter = iter->next;
        }
    }

private:
    int length;
    Node *rear;
    Node head;
};

int main()
{
    List<int> hello;
    hello.push(1);
    for (size_t i = 0; i < 10; i++)
    {
        hello.push(i);
    }
    cout << hello.size() << endl;
    hello.foreach ([](int t) {
        cout << t << endl;
    });
    hello.clear();
    cout << hello.size() << endl;

    return 0;
}
