/*
 *      Auther: ScreamZombie
 *      Time: 2020/9/30
 *      Email: SuduRainbowCat@gmail.com
 *      System: Windows 10
 */
#include <stdio.h>
#define MAXSIZE 20 //因为数组不能改变大小，所以用宏定义了数组的极限大小

void PrintArray(int t[], int size) //打印数组
{
    printf("数组的元素有\n");
    for (int i = 0; i < MAXSIZE; i++)
        printf("%4d", t[i]);
    printf("\n");
}

void Insert(int t[], int number, int place) //数组中插入元素
{
    for (int i = MAXSIZE - 2; i >= place; i--)
        t[i + 1] = t[i]; //每一个元素前移
    t[place] = number;
}

void Remove(int t[], int place) //删除指定位置的元素
{
    for (int i = place; i < MAXSIZE - 1; i++)
        t[i] = t[i + 1];
}

int Find(int t[], int number) //查找元素在数组中的位置
{
    for (int i = 0; i < MAXSIZE; i++)
        if (t[i] == number)
            return i;
    printf("对不起，此元素不存在\n");
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
    int a[MAXSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //老师说可以自定义数据的，所以就用这个了
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