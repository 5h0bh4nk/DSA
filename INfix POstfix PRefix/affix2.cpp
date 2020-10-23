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
	cout<<"stack empty no pop";
	else
	return s.el[s.top--];
}

char peek(struct stack &s)
{
	if(s.top==-1)
	cout<<"";
	else
	return s.el[s.top];
}

bool empty(struct stack s)
{
	return (s.top>=0)?0:1;
}

string infitopost(struct stack &s,string infix)
{
	string pfix="";
	for(int i=0 ;i<infix.length() ;i++)
	{
		if(infix[i]<='9' && infix[i]>'0' || isalpha(infix[i]))
		pfix+=infix[i];
		else{
			if(empty(s))
			push(s,infix[i]);
			else
			{
				if(infix[i]=='/')
				while(peek(s)=='%' || peek(s)=='/')
					pfix+=pop(s);
					
				
				else if(infix[i]=='%')
					while(peek(s)=='(' || !empty(s) || peek(s)=='%')
					pfix+=pop(s);
					
				else if(infix[i]=='(' )
					push(s,infix[i]);
						
				else if(infix[i]=='+')
				{
					while(peek(s)=='*' || peek(s)=='/' || peek(s)=='%' || peek(s)=='+')
					{
						pfix+=pop(s);
					}
					push(s,infix[i]);
				}
				else if(infix[i]=='-')
				{
					while(peek(s)!='(' && !empty(s))
					{
						pfix+=pop(s);
					}
					push(s,infix[i]);
				}
	
				else if(infix[i]==')')
				{
					while(peek(s)!='(')
					{
						pfix+=pop(s);
					}
					pop(s);
				}
				else if(infix[i]=='*')
				{
					while(peek(s)=='%' || peek(s)=='/' || peek(s)=='*')
					{
						pfix+=pop(s);
					}
					push(s,infix[i]);
				}
			}
		}
	}
	while(!empty(s))
	pfix+=pop(s);
	return pfix;
}

int main()
{
	string infix;
	cin>>infix;
	struct stack s;
	string postfix=infitopost(s,infix);
	cout<<postfix;
}
