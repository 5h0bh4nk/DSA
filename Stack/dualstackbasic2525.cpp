#include<iostream>
#include<string>
using namespace std;

struct dualstack{
	int size;
	int top1=-1;
	int top2;
	char el[50];
};

void push(struct dualstack &s,int x,int ,int num)
{
	if(num==1)
	{
		if(s.top1==(s.size/2)-1)
		cout<<"dualstack 1 full ";
		else
		s.el[++s.top1]=x;
	}
	else{
		if(s.top2==s.size-1)
		cout<<"dualstack 2 full ";
		else
		s.el[++s.top2]=x;	
	}
}

int pop(struct dualstack &s,int num)
{
	if(num==1)
	{
		if(s.top1==-1)
		cout<<"dualstack 1 empty";
		else
		return s.el[s.top1--];
	}
	else
	{
		if(s.top2==s.size-(s.size/2)-1)
		cout<<"dualstack 2 empty";
		else
		return s.el[s.top2--];
	}
	
}

int peek(struct dualstack &s,int num)
{
	if(num==1)
	{
		if(s.size==-1)
		cout<<"dualstack 1 empty";
		else
		return s.el[s.top1];
	}
	else
	{
		if(s.size==s.size-(s.size/2)-1)
		cout<<"dualstack 2 empty";
		else
		return s.el[s.top];
	}
}


int main()
{
	struct dualstack s;
	cout<<"enter size : ";
	cin>>s.size;
	s.top2=s.size-(s.size/2)-1;
	
	
}
