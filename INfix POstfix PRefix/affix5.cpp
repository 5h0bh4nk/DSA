#include<iostream>
#include<string>
using namespace std;

struct stack{
	int size=50;
	int top=-1;
	string el[50];
};

void push(struct stack &s,string x)
{
	if(s.top==s.size-1)
	cout<<"stack full ";
	else
	s.el[++s.top]=x;
}

string pop(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	
	else
	return s.el[s.top--];
}

string peek(struct stack &s)
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

string posttoinfi(struct stack &s,string ptfix)
{
	for(int i=0 ; i<ptfix.length() ; i++)
	{
		if(isalpha(ptfix[i]) || isdigit(ptfix[i]))
		push(s,string(1,ptfix[i]));
		else{
			push(s,"("+pop(s)+ptfix[i]+pop(s)+")");
		}
		
	}
	return pop(s);
}

int main()
{
	struct stack s;
	string postfix;
	cin>>postfix;
	string infix=posttoinfi(s,postfix);
	cout<<infix;
}
