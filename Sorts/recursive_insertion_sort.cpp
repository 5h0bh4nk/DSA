//OWN to be WON  -  Sort out the Sorts
#include<iostream>
using namespace std;

void puta(int a[],int m,int j)
{
	if(j<0 || a[j]<m)
	{
		a[j+1]=m;
		return;
	}
	else{
		a[j+1]=a[j];
		puta(a,m,j-1);
	}
}

void isort(int a[],int n,int i)
{
	if(i==n)
	return;
	
	else{
		int m=a[i];
		puta(a,m,i-1);
		isort(a,n,i+1);
	}
}


int main()
{
   int a[9]={8,44,7,2,10,3,7,3,882};
   isort(a,9,1);
   for(int i=0 ;i<9 ;i++)
   cout<<a[i]<<" ";
}
