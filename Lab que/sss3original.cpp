#include<iostream>
#include<string>
using namespace std;

int partition(int a[],int l,int h,int pivot)
{
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
	return l;
}

void qsort(int a[],int n)
{
	for(int i=0 ;i<9 ;i++)
	{
		int index=partition(a,i+1);
	}
}

int main()
{
	int c[9]={8,44,7,2,10,3,7,3,882};
	qsort(c,9);
	for(int i=0 ;i<9 ;i++)
	cout<<c[i]<<" ";
}
