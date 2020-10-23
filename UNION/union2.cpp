#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"no. of eements : ";
	cin>>n;
	int i=0 ,j=n-1,a[n],s;
	
	
	while(i<=j)
	{
		cout<<"0 for front and 1 for back : ";
		cin>>s;
		if(!s)
		{
			cin>>a[i];
			i++;
		}
		
		else
		{
			cin>>a[j];
			j--;
		}
		
	}
	cout<<"The elements are :\n";
	for(int i=0 ;i<n ;i++)
	cout<<a[i]<<" ";
}
