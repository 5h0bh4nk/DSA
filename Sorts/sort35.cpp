//OWN to be WON  -  Sort out the Sorts
#include<iostream>
using namespace std;

void solveq5(int a[],int b[],int m,int n)
{
	int c[m];
	int i=0,j=0,ind=0;
	while(i<m && j<n)
	{
		while(a[i]==0)
		i++;
		
		if(a[i]>b[j])
		c[ind++]=b[j++];
		
		else
		c[ind++]=a[i++];
	}
	while(i<m)
	{
		while(a[i]==0)
		i++;
		c[ind++]=a[i++];
	}
	while(j<n)
	{
		c[ind++]=b[j++];
	}
	
	for(int i=0 ;i<m ;i++)
	a[i]=c[i];
	for(int i=0 ;i<9 ;i++)
	cout<<a[i]<<" ";
}
int main()
{
	int X[9] = { 0, 2, 0, 3, 0, 5, 6, 0, 0};
	int Y[5] = { 1, 8, 9, 10, 15 } ;
	solveq5(X,Y,9,5);
	
	
}
