#include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int *A = &a;
    int b = 4;
    int *B = &b;
    a = *B;
    //A = &(*B); //the answer is 4 5
    A = &a; //the answer is 5 4
    (*A)++;
    cout << a << " " << b << endl;
    return 0;
}
