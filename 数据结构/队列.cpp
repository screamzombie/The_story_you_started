//循环队列的C++实现
#include <iostream>
#define MAX 10 //这个队列的最大长度
using namespace std;

int test[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

struct SQ
{
    int start;
    int end;
    int *space; //用来申请内存的指针
};

bool IsFull(SQ &s)
{
    if ((s.end == MAX and s.start == 0) or (s.start - s.end == 1)) //俩种情况都是满的
        return true;
    return false;
}
//这个地方值得思考
bool IsEmpty(SQ &s) //有三种情况说明这个队列是空的
{
    if ((s.end == 0 and s.start == 0) or (s.end == 0 and s.start == MAX) or (s.end - s.start == 0)) //也就是俩者都是0才算空
        return true;                                                                                //俩者相等不能说明空吧
    return false;
}

void push(SQ &s, int item) //先进去的肯定是放在前面
{
    if (!IsFull(s))
    {
        *s.space = item;                             //那么问题来了，s.space 是不能不限的增加下去的，有时候会需要它到前面去
        if (s.end - s.start != MAX and s.end == MAX) //说明前面还有空余,并且后面的也用掉了
        {
            s.space -= s.end; //把space移到前面去
            s.end = 0;        //重新赋值为0
        }
        else
        {
            s.space++; //指针++
            s.end++;   //结尾索引++
        }
    }
    else
        cout << "error!" << endl;
}

int pop(SQ &s)
{
    if (!IsEmpty(s)) //首先肯定是不能空的
    {
        int temp = *(s.space + s.start - s.end); //不需要讨论
        if (s.start != MAX)                      //不在尾部才可以加，否则的话你要跑到前面去
            s.start++;                           //在这里你不能直接加
        else
            s.start = 0;
        return temp;
    }
    else
        cout << "error!" << endl;
}

void Init(SQ &s)
{
    s.end = s.start = 0;
    s.space = new int[MAX];
}

int main()
{
    SQ q;
    Init(q);
    for (auto &&i : test)
        push(q, i);
    int cnt = 5;
    while (cnt--) //当队列不是空的时候
    {
        int t = pop(q);
        cout << t << endl;
    }
    for (auto &&i : test)
    {
        push(q, i);
        if (IsFull(q))
            break;
    };
    while (!IsEmpty(q)) //当队列不是空的时候
    {
        int t = pop(q);
        cout << t << endl;
    }
    cout << "代码正常结束" << endl;
    return 0;
}