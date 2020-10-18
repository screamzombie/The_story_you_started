#include <iostream>
using namespace std;
int main()
{
    int *p = new int;
    *p = 3;
    int *p_ = p;
    *p_ = -1;
    cout << *p << endl;
    return 0;
}