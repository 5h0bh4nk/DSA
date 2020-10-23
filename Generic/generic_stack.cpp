#include<iostream>
using namespace std;

union u{
	int n;
	char c;
};

struct stack{
	int size=50;
	int top=-1;
	int tag[50]={-1};
	union u el[50];
};

void push(struct stack &s,union u x,int tag)
{
	if(s.top==s.size-1)
	cout<<"stack full ";
	else
	if(tag==0)
	{
		s.tag[s.top+1]=tag;
		s.el[++s.top].n=x.n;
	}
	else
	{
		s.tag[s.top+1]=tag;
		s.el[++s.top].c=x.c;
	}
}

union u pop(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	{
		s.tag[s.top]=-1;
		return s.el[s.top--];
	}
	
}

union u peek(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	return s.el[s.top];
}
int main()
{
	struct stack s;
	cout<<"0 for int and 1 for char as input :";
	int t;
	cin>>t;
	union u k;
	cout<<"element to push :";
	if(!t)
	{
		cin>>k.n;
	}
	else{
		cin>>k.c;
	}
	push(s,k,t);
	cout<<s.el[s.top].n<<endl;
	k.n=pop(s).n;
	cout<<k.n<<endl;
	
	
}

