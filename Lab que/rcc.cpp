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

lptr revlist(lptr P,lptr X) {
	if(P->next==X)
		return P;
	else {
		lptr S=revlist(P->next,X);
		P->next->next=P;
		P->next=NULL;
		return S;
	}
}

int main()
{
    lptr L,P,S;
    int i,j;
    createlist(L);
    cin>>i>>j;
    i--;j--;
    P=L;S=L;
    printlist(L);
    while(i--)
    P=P->next;
    while(j--)
    S=S->next;
    
    revlist(P,S);
    printlist(L);
}

