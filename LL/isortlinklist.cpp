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

void addnode(lptr &P,lptr Q,int n)
{
	lptr S=new(node);
	S->data=n;
	P->next=S;
	S->next=Q;
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

void delnextnode(lptr P)
{
	P->next=P->next->next; 
}

void addafter(lptr P,int k,int x) {
	while(P->data!=k && P->next!=NULL) {
		P=P->next;
	}
	if(P->data==k) {
		lptr T,R;
		T=new(node);
		T->data=x;
		R=P->next;
		P->next=T;
		T->next=R;
	} else cout<<k<<" not found\n";
}

//7 4 1 2 3 5 6 -1
void isortll(lptr &P)
{
	lptr it=P->next;
	while(it)
	{
		lptr start=P;
		cout<<start->data<<" "<<it->data<<endl;
		if(start->data>it->data)
		{
			addfront(P,it->data);
	
			while(start->next!=it)
					start=start->next;
				delnextnode(start);
			cout<<"if";
			printlist(P);
		}
		else
		while(start->next!=it)
		{
			if(start->next->data>it->data)
			{
				cout<<"while if start";
				cout<<start->data<<endl;
				addnode(start,start->next,it->data);
				printlist(P);
				while(start->next!=it)
					start=start->next;
				delnextnode(start);
				printlist(P);
				break;
				
			}
			else
			start=start->next;
		}
		
		it=it->next;
		printlist(P);
	}
}
int main()
{
	lptr P;
	createlist(P);
	isortll(P);
	printlist(P);
}
