#include<iostream>
#define f(i,a,n) for(int i=a ;i<n ;i++)
using namespace std;
int dayofweek(int y)  
{  
	int d=1,m=1;
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}

bool checkYear(int year)  
{  

    if (year % 400 == 0)  
        return true;  
  
    if (year % 100 == 0)  
        return false;  
  
    if (year % 4 == 0)
        return true;  
        
    return false;  
}  

int main()
{
	int y;
	cout<<"Enter year : ";
	cin>>y;
	
	int n = dayofweek(y);
//	cout<<n<<endl<<endl;
	n%=7;
	if(!n)
	n=7;
	int m=1,d=31,febday;
	string month[12]={"January", "February" ,"March" , "April" , "May" ,"June" ,"July" , "August" ,"September" ,"October" ,"November" ,"December"};
	int i=1;
	if(checkYear(y))
	febday=29;
	else
	febday=28;
	string day[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
	
	while(i<=12)
	{
		cout<<month[i-1]<<" "<<y<<endl;
		int j=1;
//		cout<<"Mon \t"<<"Tue \t"<<"Wed \t"<<"Thu \t"<<"Fri \t"<<"Sat \t"<<"Sun \t"<<endl;
		
		
		if(i==2)
		d=febday;
		
		int date=1;
		int n1=n;
		f(k,0,7)
		{
			cout<<day[k]<<" ";
			if(n>k+1)
			{
				cout<<"\t";
			}
			
			int tmp;
			if(n>k+1)
			tmp=8-n+k;
			else
			tmp=k+1-n+1;
			
			while(tmp<=d)
			{
				if(tmp<10)
				cout<<tmp<<"   ";
				else
				cout<<tmp<<"  ";
				
				tmp+=7;
				
				if(tmp==d)
				n1=k+1;
			}
			cout<<endl;
			
		}
		n=n1+1;
//		cout<<"n1 is "<<n1<<endl;
		if(d==31 && i!=7)
		d=30;
		else
		d=31;
		
		cout<<endl<<endl;
		i++;
		
	}
	
}
