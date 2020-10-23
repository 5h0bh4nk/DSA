#include<iostream>
using namespace std;

union u{
char c;
int n;
};

struct stack{
	int size=50;
	int top=-1;
	int tag[50]={0};
	union u el[50];
};

void pushi(struct stack &s,int x)
{
	if(s.top==s.size-1)
	cout<<"stack full ";
	else
	s.el[++s.top].n=x;

}

void pushc(struct stack &s,char x)
{
	if(s.top==s.size-1)
	cout<<"stack full ";
	else
	s.el[++s.top].c=x;

}


int popi(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	{
		s.tag[s.top]=-1;
		return s.el[s.top--].n;
	}
	
}

char popc(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	{
		s.tag[s.top]=-1;
		return s.el[s.top--].c;
	}
	
}

int peeki(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	return s.el[s.top].n;
}

char peekc(struct stack &s)
{
	if(s.size==-1)
	cout<<"stack empty";
	else
	return s.el[s.top].c;
}

bool empty(struct stack s)
{
	return (s.top>=0)?0:1;
}

int eval(int opd1,int opd2,char oprt)
{
    int oprnd1=opd1;
    int oprnd2=opd2;
   
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
	//infix to postfix
	string infix,pfix="";
	cin>>infix;
	struct stack s;
	int k;
	for(int i=0 ;i<infix.length() ;i++)
	{
		if(infix[i]<='9' && infix[i]>'0')
		pfix+=infix[i];
		//3+4*5-2
		else{
			if(empty(s))
			pushc(s,infix[i]);
			else
			{
				if(infix[i]=='/')
					while(peekc(s)=='%' )
						pfix+=popc(s);
					
				
				else if(infix[i]=='%')
					while(peekc(s)=='(' || !empty(s))
					pfix+=popc(s);
					
				else if(infix[i]=='(' )
					pushc(s,infix[i]);
						
				else if(infix[i]=='+')
				{
					while(peekc(s)=='*' || peekc(s)=='/' || peekc(s)=='%' )
					{
						pfix+=popc(s);
					}
					pushc(s,infix[i]);
				}
				else if(infix[i]=='-')
				{
					while(peekc(s)!='(' && !empty(s))
					{
						pfix+=popc(s);
					}
					pushc(s,infix[i]);
				}
	
				else if(infix[i]==')')
				{
					while(peekc(s)!='(')
					{
						pfix+=popc(s);
					}
					popc(s);
				}
				else if(infix[i]=='*')
				{
					while(peekc(s)=='%' || peekc(s)=='/' )
					{
						pfix+=popc(s);
					}
					pushc(s,infix[i]);
				}
			}
		}
	}
	while(!empty(s))
	pfix+=popc(s);
	cout<<"postfix is "<<pfix<<endl;
	
	//postfix evaluation
	string str=pfix;

	for(int i=0 ;i<str.length() ;i++)
	{
		if(isdigit(str[i]))
		{

			pushi(s,str[i]-'0');
		
		}
		
		else{
			int op1=popi(s);
			int op2=popi(s);
			
			pushi(s,eval(op2,op1,str[i]));
		
		}	
	}
	cout<<"Ans is "<<popi(s)<<" ";
	
}
