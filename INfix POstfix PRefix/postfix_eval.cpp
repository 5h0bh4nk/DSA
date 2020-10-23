#include<iostream>
#include<string>
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
	if(s.top==-1)
	cout<<"stack empty";
	else
	return s.el[s.top];
}

bool empty(struct stack s)
{
	return (s.top>=0)?0:1;
}

bool isnumber(string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 

int eval(int oprnd1,int oprnd2,char oprt)
{
	switch(oprt)
	{
		case '+':
			return oprnd1+oprnd2;
		case '-':
			return oprnd1-oprnd2;
		case '/':
			return oprnd1/oprnd2;
		case '*':
			return oprnd1*oprnd2;
		case '%':
			return oprnd1%oprnd2;
	}
}

int main()
{
	struct stack s;
	string str;
	getline(cin,str);
//	cout<<str[0]<<endl;
	for(int i=0 ;i<str.length() ;i++)
	{
		string current="";
		while(str[i]!=' ')
		{
			current+=str[i];
			i++;
		}
		
		
		if(isnumber(current))
		{
//			cout<<i<<" "<<str[i]-48<<endl;
			push(s,stoi(current));
			
		}
		
		else{
			int op1=pop(s);
			int op2=pop(s);
			push(s,eval(op2,op1,str[i]));
//			cout<<op1<<str[i]<<op2<<endl;
		}
		
	}
		cout<<pop(s)<<" ";
}
