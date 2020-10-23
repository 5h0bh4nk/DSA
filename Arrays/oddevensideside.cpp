#include<iostream>
using namespace std;

void swap( int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0 ;i< n ;i++)
	cin>>a[i];
	
	int i=0 ,j=n-1;
	while(i<j)
	{
		if(a[i]%2==0 && a[j]%2==0)
		i++;
		else if(a[i]%2!=0 && a[j]%2!=0)
		j--;
		else
		{
			i++;
			j--;
		}
		if(a[i]%2!=0 && a[j]%2==0)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	for(int i=0 ;i<n ;i++)
	cout<<a[i]<<" ";
		
}
