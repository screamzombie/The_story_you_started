#include <iostream>
using namespace std;

int Fish[200]{0};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Fish[i]; //��ȡÿһ������
    }
    cout << "0"
         << " ";
    for (int l = 1; l < n; l++) //�ӵڶ����㿪ʼ����Ϊ��һ������ԶΪ0
    {
        int ugly_num = 0;
        for (int r = 0; r < l; r++)
        {
            if (Fish[r] < Fish[l])
            {
                ugly_num++;
            }
        }
        cout << ugly_num << " ";
    }
    return 0;
}