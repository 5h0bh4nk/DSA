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

int pop(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	return s.el[s.top--];
}

int peek(struct stack &s)
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
	char OSA[3]={'{','[','('},CSA[3]={'}',']',')'};
	string s;
	cin>>s;
	struct stack stck;
	bool ans=1;
	
	for(int i=0; i<s.length() ;i++)
	{
		if(s[i]==OSA[0] ||s[i]==OSA[1] || s[i]==OSA[2] )
		{
			push(stck,s[i]);
		}
		
		else if(empty(stck))
		ans=0;
		
		else
		{
			if(s[i]==CSA[0] && peek(stck)==OSA[0])
			pop(stck);
			
			else if(s[i]==CSA[1] && peek(stck)==OSA[1])
			pop(stck);
			
			else if(s[i]==CSA[2] && peek(stck)==OSA[2])
			pop(stck);
			
			else
			ans=0;
			
		}
		if(!ans)
		break;
	}
	
	if(ans)
	cout<<"YES";
	else cout<<"NO";
	
}
