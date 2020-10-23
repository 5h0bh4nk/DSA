//Sloution 3 done
#include<iostream>
#include<string>
using namespace std;

struct stack{
	int size=50;
	int top=-1;
	char el[50];
};

void push(struct stack &s,int x)
{
	if(s.top==s.size-1)
	cout<<"stack full ";
	else
	s.el[++s.top]=x;
}

char pop(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	return s.el[s.top--];
}

char peek(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	return s.el[s.top];
}

bool empty(struct stack s)
{
	return (s.top>=0)?0:1;
}

int main()
{
	string s;
	cin>>s;
	struct stack stck;
	int ans=0;
	
	for(int i=0; i<s.length() ;i++)
	{
		if(s[i]=='(')
		push(stck,s[i]);
		
		else if(!empty(stck))
		{
			if(peek(stck)=='(')
			pop(stck);
			
			else
			push(stck,')');
		}
		else
		push(stck,s[i]);
		
	}
	int c1=0,c2=0;
	while(!empty(stck))
	{
		if(pop(stck)=='(')
		c1++;
		else
		c2++;
	}
	
	if(c1%2==0 && c2%2==0)
	cout<<c1/2+c2/2;
	else if(c1%2==0 && c2%2!=0)
	cout<<c1/2+c2/2+1;
	else if(c1%2!=0 && c2%2==0)
	cout<<c1/2+c2/2+1;
	else
	cout<<c1/2+c2/2+2;
	
	
}
