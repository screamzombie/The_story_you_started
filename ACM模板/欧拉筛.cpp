// 欧拉筛法求素数
#include<iostream>
#include<cstdio>
using namespace std;
#define N 1000010
int vi[N],su[N],cnt=0,n;
void print(int n){
	for(int i=2;i<=n;i++)
	{
		if(vi[i]==0)
			printf("%d ",i);
	}
}
int main() {
  	scanf("%d",&n);
  	for(int i=2;i<=n;i++)
  	{
  		if(vi[i]==0)
  			su[cnt++]=i;
  		for(int j=0;j<cnt&&i*su[j]<=n;j++)
  		{
  			vi[i*su[j]]=1;
  			if(i%su[j]==0)
  				break;
  		}
  	}
  	print(n);
    printf("\n");
  	return 0;
}