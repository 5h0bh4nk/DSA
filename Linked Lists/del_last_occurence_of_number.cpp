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

void delloccurence(lptr P)
{
	while(P)
	{
		lptr lastoc=P,S=P;
		while(S->next)
		{
			if(S->next->data==P->data)
			lastoc=S;
			S=S->next;
		}
		
		if(lastoc!=P)
		lastoc->next=lastoc->next->next;
		
		P=P->next;
	}
}

int main()
{
	lptr L;
	createlist(L);
	delloccurence(L);
	printlist(L);
}
