/*
 *      Auther: ScreamZombie
 *      Time: 2020/9/30
 *      Email: SuduRainbowCat@gmail.com
 *      System: Windows 10
 */
#include <stdio.h>
#define MAXSIZE 20 //��Ϊ���鲻�ܸı��С�������ú궨��������ļ��޴�С

void PrintArray(int t[], int size) //��ӡ����
{
    printf("�����Ԫ����\n");
    for (int i = 0; i < MAXSIZE; i++)
        printf("%4d", t[i]);
    printf("\n");
}

void Insert(int t[], int number, int place) //�����в���Ԫ��
{
    for (int i = MAXSIZE - 2; i >= place; i--)
        t[i + 1] = t[i]; //ÿһ��Ԫ��ǰ��
    t[place] = number;
}

void Remove(int t[], int place) //ɾ��ָ��λ�õ�Ԫ��
{
    for (int i = place; i < MAXSIZE - 1; i++)
        t[i] = t[i + 1];
}

int Find(int t[], int number) //����Ԫ���������е�λ��
{
    for (int i = 0; i < MAXSIZE; i++)
        if (t[i] == number)
            return i;
    printf("�Բ��𣬴�Ԫ�ز�����\n");
    return -1;
}

void Divide(int t[], int a[], int b[], int place)
{
    for (int i = 0; i < place; i++)
        a[i] = t[i];
    for (int i = 0; i < MAXSIZE - place - 1; i++)
        b[i] = t[i + place];
}
int main(void)
{
    int a[MAXSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //��ʦ˵�����Զ������ݵģ����Ծ��������
    PrintArray(a, MAXSIZE);
    Insert(a, -1, 4);
    PrintArray(a, MAXSIZE);
    Remove(a, 5);
    PrintArray(a, MAXSIZE);
    int z = Find(a, 8);
    PrintArray(a, MAXSIZE);
    Remove(a, z);
    PrintArray(a, MAXSIZE);
    int b[MAXSIZE] = {0}, c[MAXSIZE] = {0};
    Divide(a, b, c, 4);
    PrintArray(a, MAXSIZE);
    PrintArray(b, MAXSIZE);
    PrintArray(c, MAXSIZE);
    return 0;
}