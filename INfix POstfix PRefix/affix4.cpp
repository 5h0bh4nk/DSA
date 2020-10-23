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

void prepost(struct stack &s,string str,int i)
{
	if(i==-1)
	return;
	
	else{
		if(str[i]=='*' || str[i]=='+' || str[i]=='-' || str[i]=='/')
		{
			string op1=pop(s);
			string op2=pop(s);
			string str1=op1+op2+string(1,str[i]);
			push(s,str1);
		}
		else{

			push(s,string(1,str[i]));
		}

		prepost(s,str,i-1);
	}
}

int main()
{
	string prefix;
	cin>>prefix;

	struct stack s;
	prepost(s,prefix,prefix.length()-1);
	cout<<pop(s);
}


