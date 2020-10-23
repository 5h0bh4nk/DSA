#include<iostream>
#include<string>
using namespace std;

struct dualstack{
	int size=50;
	int top1=-1;
	int top2=50;
	char el[50];
};

void push(struct dualstack &s,int x,int num)
{
	if(num==1)
	{
		if(s.top2-s.top1==1)
		cout<<"dualstack full ";
		else
		s.el[++s.top1]=x;
	}
	else{
		if(s.top2-s.top1==1)
		cout<<"dualstack full ";
		else
		s.el[--s.top2]=x;	
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
		if(s.top2==50)
		cout<<"dualstack 2 empty";
		else
		return s.el[s.top2++];
	}
	
}

int peek(struct dualstack &s,int num)
{
	if(num==1)
	{
		if(s.top1==-1)
		cout<<"dualstack 1 empty";
		else
		return s.el[s.top1];
	}
	else
	{
		if(s.top2==50)
		cout<<"dualstack 2 empty";
		else
		return s.el[s.top2];
	}
}


int main()
{
	struct dualstack s;
	push(s,12,1);
	push(s,10,2);

}
