#include <cstddef>
#include <cassert>
using namespace std;

class LinkedList   //创建一个li
{
    class Node
    {
        friend class LinkedList;

    public:
        Node() = default;
        Node(int data_, Node *next_ = nullptr)
            : data(data_), next(next_) {}

    private:
        int data;
        Node *next;
    };
    friend class Node;

public:
    LinkedList()
    {
        head = tail = nullptr;
        length = 0;
    }
    LinkedList(const LinkedList &other)
        : LinkedList()
    {
        // HW2: ***
        // put your code here.
    }

    void push_back(int);
    void pop_back();
    size_t size() const
    {
        return this->length;
    }
    bool empty() const
    {
        return size() == 0;
    }

    // HW3: front and back **
    // front 返回首元素，back 返回尾元素
    int front() const
    {
    }
    int back() const
    {
    }

    // HW4: explore template   ****
    // Pred: unary predicate
    template <typename Pred>
    void travel(Pred pred)
    {
    }

    // HW5: clear  ****
    void clear()
    {
    }

    // HW6: destructor **
    ~LinkedList()
    {
    }

private:
    Node *head;
    Node *tail;
    size_t length;
};

void LinkedList::push_back(int elem) // O(1)
{
    if (head == nullptr)
    {
        head = tail = new Node(elem);
    }
    else
    {
        tail->next = new Node(elem);
        tail = tail->next;
    }
    ++length;
}

void LinkedList::pop_back() // O(N)=
{
    // HW1: ***
    // tips: null
    // put your code here.
}

int main()
{
    LinkedList lst;
    for (int i = 1; i < 5; ++i)
    {
        lst.push_back(i);
    }
    lst.pop_back();
    assert(lst.front() == 1);
    assert(lst.back() == 3);

    auto lst_copied(lst);
    lst_copied.travel([](const auto &item) {
        assert(item > 0);
    });

    lst.clear();
    assert(lst.empty());
    return 0;
}