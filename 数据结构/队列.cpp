//ѭ�����е�C++ʵ��
#include <iostream>
#define MAX 10 //������е���󳤶�
using namespace std;

int test[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

struct SQ
{
    int start;
    int end;
    int *space; //���������ڴ��ָ��?
};

bool IsFull(SQ &s)
{
    if ((s.end == MAX and s.start == 0) or (s.start - s.end == 1)) //���������������?
        return true;
    return false;
}
//����ط�ֵ��˼��?
bool IsEmpty(SQ &s) //���������˵����������ǿյ�
{
    if ((s.end == 0 and s.start == 0) or (s.end == 0 and s.start == MAX) or (s.end - s.start == 0)) //Ҳ�������߶���0�����?
        return true;                                                                                //������Ȳ���˵���հ�?
    return false;
}

void push(SQ &s, int item) //�Ƚ�ȥ�Ŀ϶��Ƿ���ǰ��
{
    if (!IsFull(s))
    {
        *s.space = item;                             //��ô�������ˣ�s.space �ǲ��ܲ��޵�������ȥ�ģ���ʱ������?����ǰ��ȥ
        if (s.end - s.start != MAX and s.end == MAX) //˵��ǰ�滹�п���,���Һ����Ҳ�õ���?
        {
            s.space -= s.end; //��space�Ƶ�ǰ��ȥ
            s.end = 0;        //���¸�ֵΪ0
        }
        else
        {
            s.space++; //ָ��++
            s.end++;   //��β����++
        }
    }
    else
        cout << "error!" << endl;
}

int pop(SQ &s)
{
    if (!IsEmpty(s)) //���ȿ϶��ǲ��ܿյ�
    {
        int temp = *(s.space + s.start - s.end); //����Ҫ����
        if (s.start != MAX)                      //����β���ſ��Լӣ�����Ļ����?�ܵ�ǰ��ȥ
            s.start++;                           //�������㲻��ֱ�Ӽ�
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
    while (cnt--) //�����в��ǿյ�ʱ��
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
    while (!IsEmpty(q)) //�����в��ǿյ�ʱ��
    {
        int t = pop(q);
        cout << t << endl;
    }
    cout << "������������" << endl;
    return 0;
}