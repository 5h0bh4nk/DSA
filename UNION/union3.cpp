#include<iostream>
using namespace std;

union u{
	int a;
	char b;
};

int main()
{
	int n;
	cout<<"no. of eements : ";
	cin>>n;
	union u ar[n];
	int i=0,j=n-1;
	bool tag[n];
	while(i<=j)
	{
		cout<<"Type 0 for int and 1 for char : ";
		cin>>tag[i];
		cout<<"enter value : ";
		if(!tag[i])
		{
			cin>>ar[i].a;
			i++;
		}
		else
		{
			cin>>ar[j].b;
			j--;
		}
	}
	cout<<"The elements are : \n";
	for(int i=0 ;i<n ;i++)
	{
		if(!tag[i])
		cout<<ar[i].a<<" ";
		else
		cout<<ar[i].b<<" ";
	}
	
}
