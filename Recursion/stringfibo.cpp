#include<iostream>
#include<string>
using namespace std;

string fibo(int n)
{
	if(n==0)
	return "a";
	
	else if(n==1)
	return "bc";
	
	else
	return (fibo(n-1)+fibo(n-2));	
}

int main()
{
	int k;
	cin>>K;
	cout<<fibo(4)[k];
}
