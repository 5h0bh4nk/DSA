//OWN to be WON  -  Sort out the Sorts
#include<iostream>
using namespace std;

int partition(int a[],int l,int h,int pivot)
{
	while(l<h)
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


void dual_pivot_qsort(int a[],int l,int h)
{
	if(l>=h)
	return;
	
	int lpivot=a[l];
	int rpivot=a[h];

	if(lpivot>rpivot)
	swap(a[l],a[h]);

	int lp=partition(a,l,h,lpivot);
	int rp=partition(a,l,h,rpivot);
	
	dual_pivot_qsort(a,l,lp-1);
	dual_pivot_qsort(a,lp,rp-1);
	dual_pivot_qsort(a,rp,h);
	
}

int main()
{
	int c[9]={882,44,7,2,10,3,7,3,8};
	dual_pivot_qsort(c,0,8);
	for(int i=0 ;i<9 ;i++)
	cout<<c[i]<<" ";
}
