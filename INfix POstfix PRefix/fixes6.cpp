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


void reverseStr(string& str) 
{ 
    int n = str.length(); 
  
    for (int i=0; i<n/2; i++) 
        swap(str[i], str[n-i-1]); 
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
			push(s,string(1,infix[i]));
			else
			{
				if(infix[i]=='/')
				while(peek(s)=="%")
					pfix+=pop(s);
					
				
				else if(infix[i]=='%')
					while(peek(s)=="(" || !empty(s))
					pfix+=pop(s);
					
				else if(infix[i]=='(' )
					push(s,string(1,infix[i]));
						
				else if(infix[i]=='+')
				{
					while(peek(s)=="*" || peek(s)=="/" || peek(s)=="%" )
					{
						pfix+=pop(s);
					}
					push(s,string(1,infix[i]));
				}
				else if(infix[i]=='-')
				{
					while(peek(s)!="(" && !empty(s))
					{
						pfix+=pop(s);
					}
					push(s,string(1,infix[i]));
				}
	
				else if(infix[i]==')')
				{
					while(peek(s)!="(")
					{
						pfix+=pop(s);
					}
					pop(s);
				}
				else if(infix[i]=='*')
				{
					while(peek(s)=="%" || peek(s)=="/" )
					{
						pfix+=pop(s);
					}
					push(s,string(1,infix[i]));
				}
			}
		}
	}
	while(!empty(s))
	pfix+=pop(s);
	return pfix;
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
	//postfix to infix
	struct stack s;
	string postfix;
	cin>>postfix;
	string infix=posttoinfi(s,postfix);
//	cout<<infix<<endl;
	
	
	//infix to prefix
	
	string prefix;
	reverseStr(infix);
	for(int i=0 ; i<infix.length() ;i++)
	{
		if(infix[i]=='(')
		infix[i]=')';
		else if(infix[i]==')')
		infix[i]='(';
	}
//	cout<<infix<<endl;
	prefix=infitopost(s,infix);
	reverseStr(prefix);
	cout<<prefix;
}
