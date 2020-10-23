//Week days   are   working  days
//Weekends    are   hard  working  days for 'Winners'

#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

typedef struct node* lptr;

void insert(lptr &P,int n) {
	if(P==NULL)
	{
		P=new(node);
		P->data=n;
		P->next=NULL;
		return;
	}
	lptr S=P;
	while(S->next!=NULL)
		S=S->next;

	S->next=new(node);
	S->next->data=n;
	S->next->next=NULL;
}

void createlist(lptr &P)
{
    P=NULL;
    int x;
    cin>>x;
    while(x!=-1)
    {
        insert(P,x);
        cin>>x;
    }
}

void printlist(lptr P) {
	while(P!=NULL) {
		cout<<P->data<<" ";
		P=P->next;
	}
	cout<<endl;
}

void addfront(lptr &P,int k) {
	lptr T;
	T=new(node);
	T->data=k;
	T->next=P;
	P=T;
}

bool ispalindrome(lptr P)
{
	lptr S=NULL,T=P;
	insert(S,T->data);
	T=T->next;
	while(T)
	{
		addfront(S,T->data);
		T=T->next;
	}
	while(P)
	{
		if(P->data!=S->data)
		return false;
		S=S->next;
		P=P->next;
	}
	return true;
}

int main()
{
	lptr L1;
	createlist(L1);
	cout<<ispalindrome(L1);
}
