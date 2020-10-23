#include<iostream>
using namespace std;

struct stack{
	int size=50;
	int top=-1;
	int el[50];
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

int main(){

	struct stack s;
	s.size=10;
	cout<<"enter number : ";
	int n;
	cin>>n;
	
	while(n>0)
	{
		push(s,n%10);
		n/=10;
	}
	while(s.top>=0)
	{
		cout<<pop(s)<<" ";
	}
}
