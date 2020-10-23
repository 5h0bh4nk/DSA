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

int countnodes(lptr S) 
{ 
    int count = 0; 
    while (S != NULL) { 
        count++; 
        S = S->next; 
    } 
    return count; 
} 

void knodeswap(lptr P,int k)
{
	int n = countnodes(P);
	cout<<n<<endl;
	int c=n-k;
	lptr S=P;
	while(c--)
	S=S->next;
	k--;
	while(k--)
	P=P->next;
	swap(P->data,S->data);
}

int main()
{
	lptr L;
	createlist(L);
	int k;cin>>k;
	knodeswap(L,k);
	printlist(L);
}
