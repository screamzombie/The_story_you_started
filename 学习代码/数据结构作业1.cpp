#include <iostream>    //不要吐槽，毕竟环境是C++89版本
#include <vector>
#include <algorithm>
using namespace std;
vector<int>::iterator ins;
void MakeVector(vector<int> &T)  //create vector
{
	int nums[7] = {23,56,12,45,32,9,78};
	int temp=0;
	while(temp<7)
	{
		int a = nums[temp];
		T.push_back(a);
		temp++;
	}
}

void InsertItem(vector<int> &T)
{
	ins = find(T.begin(),T.end(),12);
	ins--;
	T.insert(ins,40);
	for(int i =0;i<T.size();i++)
		cout<<T[i]<<" ";
	cout<<endl;
	cout<<"v is over secondly!"<<endl;
}

void WatchVector(vector<int> &T)
{
	for(int i =0;i<T.size();i++)
		cout<<T[i]<<" ";
	cout<<endl;
}

void DivideVector(vector<int> &T,vector<int> &T1,vector<int> &T2)
{
	ins = find(T.begin(),T.end(),32);
	for(vector<int>::iterator it=T.begin();it<ins;it++)
	{
		T1.push_back(*it);
	}
	for(vector<int>::iterator it=ins;it<T.end();it++)
	{
		T2.push_back(*it);
	}
}

int main()
{

	vector<int> v;   // a vector push numbers
	vector<int> &t = v;
	MakeVector(t);
	WatchVector(t);
	InsertItem(t);
	remove(v.begin(),v.end(),45);
	for(int i =0;i<v.size()-1;i++)
		cout<<v[i]<<" ";
	cout<<endl;
	cout<<"v is over thirdly!"<<endl;	
	vector<int>v1;
	vector<int>v2;
	vector<int> &t1=v1;
	vector<int> &t2=v2;
	DivideVector(t,t1,t2);
	return 0;
}
