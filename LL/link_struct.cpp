#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

typedef struct node* lptr;

void addfront(lptr &P,int k) {
	lptr T;
	T=new(node);
	T->data=k;
	T->next=P;
	P=T;
}

void delfront(lptr &P) {
	P=P->next;
}

void printlist(lptr P) {
	while(P!=NULL) {
		cout<<P->data<<" ";
		P=P->next;
	}
	cout<<endl;
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

void addbefore(lptr P,int k,int x) {
	if(P==NULL)
		return;

	else if(P->next->data==k) {
		lptr T,R;
		T=new(node);
		T->data=x;
		R=P->next;
		P->next=T;
		T->next=R;
	} else
		addbefore(P->next,k,x);
}

void recprintlist(lptr P) {
	if(P==NULL)
		cout<<endl;

	else {
		cout<<P->data<<" ";
		recprintlist(P->next);
	}
}

void recrevprintlist(lptr P) {
	if(P==NULL)
		return;


	else {
		recrevprintlist(P->next);
		cout<<P->data<<" ";
	}
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

void insert(lptr P,int n) {
	while(P->next!=NULL)
		P=P->next;

	P->next=new(node);
	P->next->data=n;
	P->next->next=NULL;
}

int midterm(lptr P) {
	lptr S,F;
	S=P;
	F=P;
	int j=0 ;
	while(F->next!=NULL) {
		if(j%2==0)
			F=F->next;

		else {
			S=S->next;
			F=F->next;
		}
		j++;
	}

	return S->data;
}

void delelement(lptr P,int k)
{
	while(P->next!=NULL)
	{
		if(P->next->data==k)
		{
			lptr T;
			T=P->next->next->next;
			P->next=T;
		}
		P=P->next;
	}
}

void dellast(lptr P)
{
	while(P->next->next!=NULL)
	P=P->next;
	
	P->next=NULL;
}

int main() {
	lptr l,t,p;
	l=new(node);
	l->next=NULL;
	int n;
	cin>>n;
	l->data=n;
	cin>>n;
	while(n>0) {
		t=new(node);
		t->data=n;
		t->next=NULL;
		cin>>n;
		p=l;
		while(p->next!=NULL)
			p=p->next;

		p->next=t;
	}
	p=l;
	addafter(p,11,12);
	printlist(p);
	addbefore(p,44,990);
	printlist(p);//
	addfront(l,5);
	printlist(l);//
	insert(l,10);
	printlist(l);//
	delfront(l);
	recprintlist(l);//
	cout<<find(l,11)<<endl;//
//	recrevprintlist(l);//

	addafter(l,11,12);
	
	printlist(l);//
	delelement(l,12);
	dellast(l);
	recprintlist(l);
	cout<<midterm(p);

}
