#include<iostream>
using namespace std;

void swap(int *a,int &b)
{
	int t;
	t=*a;
	*a=b;
	b=t;
}

int main()
{
	int a,b;
	cin>>a>>b;
	swap(&a,b);
	cout<<a<<" "<<b;
}
