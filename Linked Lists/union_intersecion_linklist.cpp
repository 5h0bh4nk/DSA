//Benefit from  fit LL to set

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
	if(P==NULL)
		cout<<endl;
    else {
		cout<<P->data<<" ";
		printlist(P->next);
	}
}

lptr s_union(lptr L1,lptr L2)
{
    lptr L3=NULL;
    while(L1!=NULL && L2!=NULL)
    {
            if(L1->data>L2->data)
            {
                insert(L3,L2->data);
                L2=L2->next;
            }
            else if(L1->data<L2->data)
            {
                insert(L3,L1->data);
                L1=L1->next;
            }
            else{
                insert(L3,L1->data);
                L2=L2->next;
                L1=L1->next;
            }
    }
    while(L1)
    {
        insert(L3,L1->data);
        L1=L1->next;
    }
	while(L2)
    {
        insert(L3,L2->data);
        L2=L2->next;
    }
    return L3;
}

bool find(lptr P,int k) {
	if(P==NULL)
		return false;

	if(P->data==k)
		return true;

	else {
		find(P->next,k);
	}
}

lptr s_inter(lptr L1,lptr L2)
{
	lptr L3=NULL;
	while(L1)
	{
		if(find(L2,L1->data))
		insert(L3,L1->data);
		L1=L1->next;
	}
	return L3;
}

lptr s_diff(lptr L1,lptr L2)
{
	lptr L3=NULL;
	while(L1)
	{
		if(!find(L2,L1->data))
		insert(L3,L1->data);
		L1=L1->next;
	}
	return L3;
}

lptr u_union(lptr L1,lptr L2)
{
	lptr L3=NULL;
	while(L1)
	{
		if(!find(L3,L1->data))
		insert(L3,L1->data);
		L1=L1->next;
	}
	while(L2)
	{
		if(!find(L3,L2->data))
		insert(L3,L2->data);
		L2=L2->next;
	}
	return L3;
}

lptr u_inter(lptr L1,lptr L2)
{
	lptr L3=NULL;
	while(L1)
	{
		if(find(L2,L1->data))
		insert(L3,L1->data);
		L1=L1->next;
	}
	return L3;
}

lptr u_diff(lptr L1,lptr L2)
{
	lptr L3=NULL;
	while(L1)
	{
		if(!find(L2,L1->data))
		insert(L3,L1->data);
		L1=L1->next;
	}
	return L3;
}

int main()
{
    lptr L1,L2,L3=NULL;
    createlist(L1);
    createlist(L2);
    L3=s_union(L1,L2); 
    printlist(L3);
    L3=s_inter(L1,L2);
    printlist(L3);
    L3=s_diff(L1,L2);
    printlist(L3);
    createlist(L1);
    createlist(L2);
    L3=u_union(L1,L2);
    printlist(L3);
    L3=u_inter(L1,L2);
    printlist(L3);
    L3=u_diff(L1,L2);
    printlist(L3); 
}


