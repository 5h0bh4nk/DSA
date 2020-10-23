//OWN to be WON  -  Sort out the Sorts
#include<iostream>
using namespace std;

int partition(int a[],int l,int h,int pivot)
{
	int t=l;
	while(l<=h)
	{
		while(a[l]<pivot)
		l++;
		while(a[h]>pivot)
		h--;
		
		if(l<=h)
		{
			swap(a[l],a[h]);
			l++;
			h--;
		}
	}
	int k=t;
	while(k<l)
	{
		a[k-1]=a[k];
	}
	a[l-1]=pivot;
	
	return l-1;
}

void qsort(int a[],int n)
{	
//	int pivot=a[(l+h)/2];
//	int index=partition(a,l,h,pivot);
//	qsort(a,l,index-1);
//	qsort(a,index,h);
	int j=0;
	while(j<n)
	{
		for(int i=0 ;i<9 ;i++)
	cout<<a[i]<<" ";
		int p=partition(a,j+1,n-1,a[j]);
		if(a[j]<a[p])
		j++;
		
			for(int i=0 ;i<9 ;i++)
	cout<<a[i]<<" ";
	cout<<endl;	
	}

}

int main()
{
	int c[9]={8,44,7,2,10,3,7,3,882};
	qsort(c,9);
	for(int i=0 ;i<9 ;i++)
	cout<<c[i]<<" ";
}
