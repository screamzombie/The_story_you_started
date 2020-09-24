#include <iostream>  //iostream是C++中用于数据的流式输入与输出的头文件
using namespace std; //使用标准命名空间
//如果没有它后面的例如cout就得写成 std::cout
//cin 写成 std::cin
/*
    因为学校的数据结构老师太水了，一会C语言一会C++。所以为了应付数据结构考试，不求甚解的
讲一下《数据结构》这门课中会用到的东西。
    因为是极简版，所以不求甚解。想要深究可以看cpp reference
*/
int main()
{
    int a;
    cout << "请输入一个数" << endl;
    cin >> a;          //从键盘中读入输入
    cout << a << endl; //输出变量，endl ≈ 换行
    // cin 和 cout 是C++的流输入输出
    //  <<  和  >> 就把它看作一条小河，不断的运送小河里面的东西
    // 比如先，送个a给cout，于是cout就把它输出出来了，然后又送了个endl
    int *p = new int;         // new 用来向系统申请内存，
    delete p;                 //用来释放掉，指针所指向的那片内存
    int *P_arr = new int[10]; //给一个数组申请一片空间
    delete[] P_arr;           //释放这个数组所用的内存空间，这种情况前面要加[]
    // 这样把连续的一片空间都给释放掉了
    int b = 5;
    int &P_b = b;     //这样P_b就是 b的引用
    int *P_tr_b = &b; //和这样几乎等用
    P_b = 6;
    cout << b << endl;
    *P_tr_b = 7; //可以看代码运行结果
    cout << b << endl;
    return 0;
}