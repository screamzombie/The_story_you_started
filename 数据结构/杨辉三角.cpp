#include <iostream>
#include <cstdio>
#define MAX 100000

using namespace std;

int maxsize = -1;

struct SQ
{
    int start;
    int end;
    int *space;
};

bool IsFull(SQ &s)
{
    if ((s.end == MAX and s.start == 0) or (s.start - s.end == 1))
        return true;
    return false;
}

bool IsEmpty(SQ &s)
{
    if ((s.end == 0 and s.start == 0) or (s.end == 0 and s.start == MAX) or (s.end - s.start == 0))
        return true;
    return false;
}

void push(SQ &s, int item)
{
    if (!IsFull(s))
    {
        *s.space = item;
        if (s.end - s.start != MAX and s.end == MAX)
        {
            s.space -= s.end;
            s.end = 0;
        }
        else
        {
            s.space++;
            s.end++;
        }
    }
    else
        cout << "error!" << endl;
}

int pop(SQ &s)
{
    if (!IsEmpty(s))
    {
        int temp = *(s.space + s.start - s.end);
        if (s.start != MAX)
            s.start++;
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
    int c[130][130]{0};
    c[1][1] = 1;
    SQ q;
    Init(q);
    for (int i = 2; i <= 10; i++)
    { //这里只生成了五层
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1]; //生成杨辉三角
        }
    }

    for (int l = 0; l < 13; l++)
    {
        int temp = 0;
        for (int r = 0; r < 13; r++)
        {
            if (c[l][r] != 0)
            {
                push(q, c[l][r]); //用队列储存全部元素
                temp++;
            }
        }
        maxsize = max(maxsize, temp);
    }
    int index = 1;
    int blank;
    double BLANK;
    while (!IsEmpty(q)) //当q不是空的
    {
        BLANK = (double(maxsize - index)) / 2;
        blank = int(BLANK);
        for (int i = 0; i < blank; i++)
        {
            cout << "  ";
        }
        if (BLANK - double(blank) != 0)
        {
            cout << " ";
        }
        for (int i = 0; i < index; i++)
        {
            int t = pop(q);
            printf("%-4d", t);
        }
        for (int i = 0; i < blank; i++)
        {
            cout << "  ";
        }
        if (BLANK - double(blank) != 0)
        {
            cout << " ";
        }
        cout << endl;
        index++;
    }
    return 0;
}