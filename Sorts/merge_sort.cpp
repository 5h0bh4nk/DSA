//OWN to be WON  -  Sort out the Sorts
#include<iostream>
using namespace std;

int merge(int a[],int b[],int l,int mid,int r)
{
	int i=l;
	int k=l;
	int j=mid+1;
	while(i<=mid && j<=r)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=mid)
	b[k++]=a[i++];
	
	while(j<=r)
	b[k++]=a[j++];
	
	for(int i=l;i<=r;i++)
	a[i]=b[i];
	
}

void mergesort(int a[],int b[],int l, int r)
{
	if(l>=r)
	return;
	int mid=(l+r)/2;
	mergesort(a,b,l,mid);
	mergesort(a,b,mid+1,r);
	merge(a,b,l,mid,r);
}

int main()
{
	int c[23]={24, 4, 8, 19, 12, 7, 2, 20, 18, 6, 17, 9, 16, 10, 11, 21, 22, 1, 23, 3,13, 15, 14},d[23];
	mergesort(c,d,0,22);
	for(int i=0 ;i<23 ;i++)
	cout<<d[i]<<" ";
}

