#include<iostream>
using namespace std;

void swap(int *a,int &b)
{
	int *t=b;//t ko b ka address dia
	
	
	
}

int main()
{
	int a,b;
	cin>>a>>b;
	swap(&a,b);
	cout<<a<<" "<<b;
}
