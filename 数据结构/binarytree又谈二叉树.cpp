#include <iostream>
#include <string>
using namespace std;

template <class T>
class test
{
public:
    T data;
    test *t;
    test(T data_ = {}, test *t_ = nullptr) : data(data_), t(t_) {}
    ~test()
    {
        cout << "the test be killed!" << endl;
        if (t != nullptr && t != this)
            delete t;
    }
    void setdata(T);
};

template <class T>
void test<T>::setdata(T t)
{
    data = t;
}

int main()
{
    test<string> l({"hello world"}, &l);
    cout << l.data << endl;
    return 0;
}