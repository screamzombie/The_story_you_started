#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool isPrime[10100];
//isPrime[i] == 1表示：i是素数
int Prime[10100], cnt = 0;
//Prime存质数

void GetPrime(int n) //筛到n
{
    memset(isPrime, 1, sizeof(isPrime));
    //以“每个数都是素数”为初始状态，逐个删去
    isPrime[1] = 0; //1不是素数

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])       //没筛掉
            Prime[++cnt] = i; //i成为下一个素数

        for (int j = 1; j <= cnt && i * Prime[j] <= n /*不超上限*/; j++)
        {
            //从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
            isPrime[i * Prime[j]] = 0;

            if (i % Prime[j] == 0) //i中也含有Prime[j]这个因子
                break;             //重要步骤。见原理
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
            if (num_total <= all_total) // 说明已经存满了甚至溢出来了
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