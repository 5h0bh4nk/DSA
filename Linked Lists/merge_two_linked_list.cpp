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

lptr mergelist(lptr P,lptr Q)
{
	lptr S=NULL;
	int i=0;
	while(P && Q)
	{
		if(i%2==0)
		{
			insert(S,P->data);
			P=P->next;
		}
		else{
			insert(S,Q->data);
			Q=Q->next;
		}
		i++;
	}
	while(P)
	{
		insert(S,P->data);
		P=P->next;
	}
	while(Q)
	{
		insert(S,Q->data);
		Q=Q->next;
	}
	return S;
}

int main()
{
	lptr L1,L2,L3;
	createlist(L1);
	createlist(L2);
	L3=mergelist(L1,L2);
	printlist(L3);
}
