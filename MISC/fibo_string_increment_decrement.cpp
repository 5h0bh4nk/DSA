//OWN to be WON  -  Sort out the Sorts
#include<iostream>
#include<strings.h>
using namespace std;

int getnumber(string s)
{
	int n=0;
	for(int i=0 ;i<s.length() ;i++)
    {
        if(s[i]=='0')
        continue;
        else
        n+=f[s.length()-i];
    }
    return n;
}

string answer(int n,int fib[])
{
	string ans="";
	int i;
	for(i=0 ;fib[i]<n ;i++)
	{continue;}
	ans+="1";
	if(fib[i]>n)
	i--;
	int dif=n-fib[i];
	
		for(int j=i-1;j>0;j--)
		{
			if(fib[j]<dif)
			{
				dif-=fib[i];
				ans+="1";
			}
			else
			ans+="0";
		}
	return ans;
	
}

int main()
{
    int f[32],n;
    string s;
    cin>>s;
    f[0]=0;f[1]=1;
    
    //creating array of series
    for(int i=2 ;i<32 ;i++)
    f[i]=f[i-1]+f[i-2];
    
    int size=s.length();
	n=getnumber(s);
	
    int dec=n-1,inc=n+1;
    string decr,incr;
    bool deceasy;
    if(s[size-1]=='0')
    deceasy=0;
    else
    deceasy=1;
    
    if(deceasy)
    {
    	string g=s;
		g[size-1]='0';
    	cout<<"decremented : "<<g<<endl;
    	string sec=answer(n+1,f);
    	cout<<"incremented : "<<sec;
    	
	}
	else{
		string g=s;
		g[size-1]='1';
    	cout<<"incremented : "<<g<<endl;
    	string sec=answer(n-1,f);
    	cout<<"decremented : "<<sec;
    	
	}
	
    
}
