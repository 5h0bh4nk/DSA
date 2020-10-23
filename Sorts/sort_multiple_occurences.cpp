//OWN to be WON  -  Sort out the Sorts
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
    
    
}

int main()
{
	solveq1();
}
	
