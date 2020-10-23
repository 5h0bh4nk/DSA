//OWN to be WON  -  Sort out the Sorts
#include<iostream>
using namespace std;

void merge(int a[],int b[],int n1,int n2)
{
	
	for(int i=0 ;i<n2 ;i++)
	{
		for(int j=0 ;j<n1;j++)
		{
			if(b[i]<a[j])
			swap(a[j],b[i]);
		}
	}
	for (int i = 0; i < n2-1; i++)      
    for (int j = 0; j < n2-i-1; j++)  
        if (b[j] > b[j+1])  
            swap(b[j], b[j+1]);
	
}

int main()
{
	int x[5]={1,4,7,8,10};
	int y[3]={2,3,9};
	 merge(x,y,5,3);
	 int n1=5,n2=3;
	for(int i=0 ;i<n1;i++)
	cout<<x[i]<<" ";
	cout<<endl;
	for(int i=0 ;i<n2 ;i++)
	cout<<y[i]<<" ";
}
