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

bool L2inL1(lptr P,lptr Q)
{
	while(P!=NULL)
	{
		if(P->data==Q->data)
		{
			lptr S=Q;
			bool check=1;
			while(S!=NULL)
			{
				if(P->data==S->data)
				{
					P=P->next;
					S=S->next;
				}
				else{
					check=0;
					break;
				}
			}
			if(check)
			return true;
		}
		P=P->next;
	}
	return false;
}

int main()
{
	lptr L1,L2;
	createlist(L1);
	createlist(L2);
	cout<<L2inL1(L1,L2)<<endl;
	
}
