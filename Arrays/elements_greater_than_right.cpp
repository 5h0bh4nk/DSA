//OWN to be WON
#include <iostream>
using namespace std;

int main()
{
    int a[5];
    for(int i=0 ;i<5 ;i++)
    cin>>a[i];
    cout<<"The elements greater than all elements to its right are ";
    
    bool b[5];
    for(int i=0 ;i<5 ;i++)
    for(int j=i;j<5;j++)
    if(a[j]<=a[i])
    b[i]=0;
    
    for(int j=0;j<5;j++)
    if(b[j]!=0)
    b[j]=1;
    
    for(int i=0 ;i<5 ;i++)
    if(b[i])
    cout<<a[i]<<", ";

    

    return 0;
}

