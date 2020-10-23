#include<iostream>
using namespace std;

void solveq2()
{
	int a[7]={5,4,3,7,6,1,9};
	int i,j=-1,k=-1;
	i=0;
	int n=7;
	while(i==-1 || j==-1 || k==-1)
	for(int l=i+1 ;l<n ;l++)
	{
		if(j==-1)
		if(a[l]>a[i])
		j=a[l];
		
		if(j!=-1)
		if(a[l]>a[j])
		k=a[l];
		
		if(l==n-1 && k==-1)
		{
			i++;
			j=-1;
			k=-1;
			break;
		}
	}
	cout<<a[i]<<" "<<a[j]<<" "<<a[k];
}

int main()
{
	solveq2();
}
