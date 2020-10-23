#include<bits/stdc++.h>
using namespace std;



int maxar(int a[],int n)
{
	if(n==0)
	return a[n];
	
	else
	return max(a[n],maxar(a,n-1));
}

int main()
{
	int a[7]={-99,2,3,100,5,6,9};
	int n=7;
	cout<<maxar(a,n);
}
