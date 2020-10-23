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

bool empty(struct stack s)
{
	return (s.top>=0)?0:1;
}

int main()
{
	struct stack s1;
	struct stack s2;
	int a[10]={1,91,4,3,22,85,333,56,0,91};
	int i=0 ,n=10;
	while(i<n)
	{
		if(empty(s1))
		push(s1,a[i++]);
		
		else{
			if(a[i]<=peek(s1))
			push(s1,a[i++]);
			
			else{
				while(a[i]>peek(s1) && !empty(s1))
				{
					push(s2,pop(s1));
				}
				
				push(s1,a[i++]);
				
				while(!empty(s2))
				push(s1,pop(s2));
			}
		}
	}
	//stack s1 contains sorted elements and can be copied to array also
	while(!empty(s1))
	cout<<pop(s1)<<" ";
	
}
