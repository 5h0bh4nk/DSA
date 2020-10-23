#include<iostream>
#include<stack>
using namespace std;

struct btnode{
	btnode* lchild=NULL;
	char data;
	btnode* rchild=NULL;
};

typedef btnode* btptr;

void createbt(btptr &T,char ch)
{
	if(T==NULL)
	{
		T=new btnode;
		T->data=ch;
	}
//	cout<<"enter lc of tree node "<<T->data<<" : ";
	cin>>ch;
	if(ch!='.')
	createbt(T->lchild,ch);
//	cout<<"enter rc of tree node "<<T->data<<" : ";
	cin>>ch;
	if(ch!='.')
	createbt(T->rchild,ch);
}

void leafcount(btptr T,int &c)
{
	if(T==NULL)
	return;
	
	if(T->lchild==NULL && T->rchild==NULL)
	c++;
	
	leafcount(T->lchild,c);
	leafcount(T->rchild,c);
}

void nodecount(btptr T,int &c)
{
	if(T==NULL)
	return;
	c++;
	nodecount(T->lchild,c);
	nodecount(T->rchild,c);
}

void serialisation(btptr T,string &s)
{
	if(T==NULL)
	{
		s+=".";
		return;
	}
	s+=T->data;
	serialisation(T->lchild,s);
	serialisation(T->rchild,s);
}

void itpreoder(btptr T)
{
	stack <btptr> st;
	st.push(T);
	while(!st.empty())
	{
		btptr P=st.top();
		cout<<P->data<<" ";
		st.pop();
		if(P->rchild)
		st.push(P->rchild);
		if(P->lchild)
		st.push(P->lchild);
	}
}

//MB..DF...J.RH..K..
int main()
{
	btptr T=NULL;
	createbt(T,'A');
	int c=0;
	leafcount(T,c);
	cout<<c<<endl;c=0;
	nodecount(T,c);
	cout<<c<<endl;
	string s="";
	serialisation(T,s);
	cout<<s<<endl;
	itpreoder(T);
}

