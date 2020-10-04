#include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct
{
    int Data[MAXSIZE]{0}; //�洢Ԫ�ص�����
    int topIdx = 0;       //ջ��ָ��
} Stack;

void Push(Stack &L, int e) //��Ԫ��ѹ��ջ��
{
    if (L.topIdx == MAXSIZE) //��Ϊ�±��Ǵ�0��ʼ������
    {
        cout << "��ջ�Ѿ�����" << endl;
        cout << "L.topIdx == " << L.topIdx << endl;
    }
    else
    {
        int v = L.topIdx++;
        cout << "Ԫ�ط���" << v << endl;
        L.Data[v] = e; //��������
    }
}

int Pop(Stack &L) //��Ԫ�ص���
{
    if (L.topIdx == 0)
        cout << "����ʧ�ܣ���ջΪ�գ�" << endl;
    else
    {
        int val = L.Data[--L.topIdx];
        cout << "������Ԫ���ǣ� " << val << endl;
        return (val);
    }
}

bool IsEmpty(Stack &L) //�ж�ջ�Ƿ��
{
    if (L.topIdx == 0)
        return true;
    else
        return false;
}

bool IsFull(Stack &L) //�ж��Ƿ���
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