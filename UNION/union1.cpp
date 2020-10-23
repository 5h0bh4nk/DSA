#include<iostream>
using namespace std;

union u{
	int a;
	char b;
};

int main(){
	cout<<"How many entries : ";
	int n;
	cin>>n;
	union u ar[n];
	bool tag[n];
	for(int i=0 ;i<n ;i++)
	{
		cout<<"type 0 for int and 1 for char : ";
		cin>>tag[i];
		cout<<"enter value : ";
		if(!tag[i])
		cin>>ar[i].a;
		else
		cin>>ar[i].b;
	}
	for(int i=0 ;i<n ;i++)
	{
		if(!tag[i])
		cout<<ar[i].a<<" ";
		else
		cout<<ar[i].b<<" ";
	}
}
