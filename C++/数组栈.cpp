#include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct
{
    int Data[MAXSIZE]{0}; //存储元素的数组
    int topIdx = 0;       //栈顶指针
} Stack;

void Push(Stack &L, int e) //将元素压入栈中
{
    if (L.topIdx == MAXSIZE) //因为下表是从0开始计数的
    {
        cout << "该栈已经满了" << endl;
        cout << "L.topIdx == " << L.topIdx << endl;
    }
    else
    {
        int v = L.topIdx++;
        cout << "元素放在" << v << endl;
        L.Data[v] = e; //放入数据
    }
}

int Pop(Stack &L) //将元素弹出
{
    if (L.topIdx == 0)
        cout << "弹出失败，该栈为空！" << endl;
    else
    {
        int val = L.Data[--L.topIdx];
        cout << "弹出的元素是： " << val << endl;
        return (val);
    }
}

bool IsEmpty(Stack &L) //判断栈是否空
{
    if (L.topIdx == 0)
        return true;
    else
        return false;
}

bool IsFull(Stack &L) //判断是否满
{
    if (L.topIdx == MAXSIZE - 1)
        return true;
    else
        return false;
}

int main()
{
    Stack L;
    Stack &T = L;
    cout << IsEmpty(L) << endl;
    for (int i = 0; i < MAXSIZE; i++)
    {
        Push(T, i);
    }
    for (int i = 0; i < MAXSIZE; i++)
    {
        cout << L.Data[i] << endl;
    }
    return 0;
}