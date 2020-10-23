#include<iostream>
using namespace std;
int main()
{
	int a[8]={1, 3, -1, -3, 5, 3, 6, 7},b;
	cin>>b;
	int c[8-b+1];
	if(b>=8)
	{
		int maxa=a[0];
		for(int i=0 ;i<8 ;i++)
		{
			maxa=max(a[i],maxa);
		}
		cout<<maxa;
	}
	else{
		for(int i=0 ;i<8-b+1;i++)
		{
		int maxa=a[i];
		for(int j=i ;j<i+b ;j++)
		{
			maxa=max(a[j],maxa);
		}
		c[i]=maxa;
		}
	}
	for(int i=0 ;i<8-b+1 ;i++)
	cout<<c[i]<<" ";
}
