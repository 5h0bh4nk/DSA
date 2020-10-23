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

void delnextnode(lptr P)
{
	P->next=P->next->next; 
}

void s_remduplicate(lptr P)
{
	if(P->next==NULL)
	return;
	
	else{
		if(P->next->data==P->data)
		{
			delnextnode(P);
			s_remduplicate(P);
		}
		else
		s_remduplicate(P->next);	
	}
}

int main()
{
	lptr L;
	createlist(L);
	s_remduplicate(L);
	printlist(L);
	
}
