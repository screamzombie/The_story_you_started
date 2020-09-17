#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool isPrime[10100];
//isPrime[i] == 1��ʾ��i������
int Prime[10100], cnt = 0;
//Prime������

void GetPrime(int n) //ɸ��n
{
    memset(isPrime, 1, sizeof(isPrime));
    //�ԡ�ÿ��������������Ϊ��ʼ״̬�����ɾȥ
    isPrime[1] = 0; //1��������

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])       //ûɸ��
            Prime[++cnt] = i; //i��Ϊ��һ������

        for (int j = 1; j <= cnt && i * Prime[j] <= n /*��������*/; j++)
        {
            //��Prime[1]������С����2��ʼ�����ö����֪��������������Prime[j]��(i*Prime[j])����С������
            //��Ȼ��i�϶���Prime[j]����ΪPrime[j]����i֮ǰ�ó���
            isPrime[i * Prime[j]] = 0;

            if (i % Prime[j] == 0) //i��Ҳ����Prime[j]�������
                break;             //��Ҫ���衣��ԭ��
        }
    }
}

int main()
{
    int n, q;
    n = 10000;
    int all_total;
    int total = 0;
    int num_total = 0;
    cin >> all_total;
    GetPrime(n);
    for (int i = 1; i < n; i++)
    {
        if (Prime[i])
        {
            total++;
            num_total += Prime[i];
            if (num_total <= all_total) // ˵���Ѿ������������������
            {
                cout << Prime[i] << endl;
            }
            else
            {
                cout << total - 1 << endl;
                return 0;
            }
        }
    }
}