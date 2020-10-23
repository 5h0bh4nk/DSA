#include<iostream>
#include<string>
using namespace std;

struct stack{
	int size=60;
	int top[50]={-1};
	int el[60];
};
//num parameter provides the partition number num=1,2,3..k
void push(struct stack &s,int x,int num,int k)
{
	if(s.top[num-1]==(s.size*num/k)-1)
	cout<<"stack full ";
	else
	s.el[++s.top[num-1]]=x;
}
//num parameter provides the partition number num=1,2,3..k
int pop(struct stack &s,int num,int k)
{
	if(s.top[num-1]==(s.size*(num-1)/k)-1)
	cout<<"stack empty";
	else
	return s.el[s.top[num-1]--];
}
//num parameter provides the partition number num=1,2,3..k
int peek(struct stack &s,int num,int k)
{
	if(s.top[num-1]==(s.size*(num-1)/k)-1)
	cout<<"stack empty";
	else
	return s.el[s.top[num-1]];
}

bool empty(struct stack s)
{
	return (s.top>=0)?0:1;
}
int main()
{
	struct stack s;
	int k;
	cin>>k;
	s.top[0]=-1,s.top[k-1]=s.size-1;
	for(int i=1 ;i<k-1;i++)
	s.top[i]=s.top[i-1]+s.size/k;
	
	//k partitioned stacks are made
	//use push(s,x,partition,k)
	//pop(s,partition,k)
	//peek(s,partition,k)
	
	push(s,2,1,k);
	push(s,2,1,k);
	cout<<pop(s,1,k);
	
	
}
