//OWN to be WON  -  Sort out the Sorts
#include<iostream>
using namespace std;

void solveq3(int a[],int n)
{
	int i=0, j=n-1,start=-1,end=-1;
	while(start==-1 || end==-1)
	{
		int min=a[i];
		for(int k=i;k<n ;k++)
		{
			if(a[k]<min)
			{
				start=i;
			}
			if(k==n-1 && start==-1)
			i++;
		}
		int max=a[j];
		for(int k=j;k>=0;k--)
		{
			if(a[k]>max)
			{
				end=j;
			}
			if(k==0 && end==-1)
			j--;
		}
	}
	cout<<i<<" "<<j;
	
}
int main()
{
	int a[8]={ 1, 3, 2, 7, 5, 6, 4, 8 } ;
	solveq3(a,8);
}
