//OWN to be WON
#include<iostream>
using namespace std;

void solveq1()
{
    //sizes can be varied
    int a[11]={ 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 };
    int count[1000]={0};
    for(int i=0 ;i<11 ;i++)
    count[a[i]]++;
    int ind=0;
    for(int i=0 ;i<1000 ;i++)
    if(count[i]!=0)
    while(count[i]--)
    a[ind++]=i;
    
    for(int i=0 ;i<11 ;i++)
    cout<<a[i]<<" ";
    
    //maps would be more efficient in this case map<int,int> count;
    // map<int,int> m1;
    // for(int i=0 ;i<11 ;i++)
    // m1[a[i]]++;
    // for(auto it=m1.begin() ;it!=m1.end() ;it++)
    // for(int i=0 ;i<it->second ;i++)
    // cout<<it->first<<" ";
    
    
    
}

//end of q1

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
		        j=l;
		
		        if(j!=-1)
		        if(a[l]>a[j])
		        k=l;
		
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
//end of q2

void solveq3()
{
    int a[8]={ 1, 3, 2, 7, 5, 6, 4, 8 } ;
    int n=8;
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

//end of q3

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

void solveq4()
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
//end of q4

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

//end of q5

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

void qsort(int a[],int l,int h)
{
	if(l>=h)
	return;
	
	int pivot=a[(l+h)/2];
	int index=partition(a,l,h,pivot);
	qsort(a,l,index-1);
	qsort(a,index,h);

}

void solveq6()
{
    int a[15]={5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4};
	int b[4]={3,5,7,2};
	int n1=15,n2=4;
	int j=0;
	for(int i=0 ;i<n2 ;i++)
	{
		for(int k=0 ;k<n1 ;k++)
		if(b[i]==a[k])
		swap(a[k],a[j++]);
	}
	qsort(a,j,n1-1);
	for(int i=0 ;i<15 ;i++)
	cout<<a[i]<<" ";
}

//end of q6

void solveq7()
{
    int a[6]={3, 5, 7, 6, 8, 9};
    int n=6;
	int i=0, j=6-1,start=-1,end=-1;
	while(start==-1 || end==-1)
	{
		int min=a[i];
		for(int k=i;k<6 ;k++)
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
	swap(a[start],a[end]);
	for(int i=0 ;i<6 ;i++)
	cout<<a[i]<<" ";
}

//end of q7

int main()
{
    cout<<"question no.: ";
    int o;
    cin>>o;
    switch(o)
    {
        case 1:
        {
            solveq1();
            break;
        }
        case 2:
        {
            solveq2();
            break;
        }
        case 3:
        {
            solveq3();
            break;
        }
        case 4:
        {
            solveq4();
            break;
        }
        case 5:
        {
    	    int X[9] = { 0, 2, 0, 3, 0, 5, 6, 0, 0};
	        int Y[5] = { 1, 8, 9, 10, 15 } ;
	        solveq5(X,Y,9,5);
            break;
        }
        case 6:
        {
            solveq6();
            break;
        }
        case 7:
        {
            solveq7();
            break;
        }
    }
}








