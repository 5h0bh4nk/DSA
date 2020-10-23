#include<bits/stdc++.h>
using namespace std;

void perculate_up(int i,int H[])
{
	if(i<=0)
	return;
	
	if(H[(i-1)/2]<H[i])
	{
		swap(H[(i-1)/2],H[i]);
		perculate_up((i-1)/2,H);
	}
}

void perculate_down(int H[],int s,int i=0)
{
	if(i>=s-1)
	return;
	
	if(2*i+2<s)
	if(H[i]<max(H[2*i+1],H[2*i+2]))
	{
		if(H[2*i+1]<H[2*i+2])
		{
			swap(H[i],H[2*i+2]);
			perculate_down(H,s,2*i+2);
		}
		else{
			swap(H[i],H[2*i+1]);
			perculate_down(H,s,2*i+1);			
		}
	}
}

vector<int> heap_sort(int H[],int s)
{
	vector<int> v;
	while(s>0)
	{
		v.push_back(H[0]);
		H[0]=H[s-1];
		perculate_down(H,s);
		s--;
	}
	return v;
}

bool isHeap(int H[],int s,int i=0)
{
	if(i>=s-1)
	return true;
	
	if(2*i+2<s)
	if(H[i]<H[2*i+2] || H[i]<H[2*i+1])
	return false;
	
	return (isHeap(H,s,2*i+1) && isHeap(H,s,2*i+2));
}

int* createHeap(int v[],int s)
{
	static int H[50]={0};
	for(int i=0 ;i<s ;i++)
	{
		H[i]=v[i];
		perculate_up(i,H);
	}
	return H;
}

void k_largest(int H[],int s,int k)
{
	int n;
	for(int i=0 ;i<k ;i++)
	{
		n=H[0];
		H[0]=H[--s];
		perculate_down(H,s);
	}
	cout<<n<<endl;
}

int main()
{
	int s;
	cout<<"Heap :";s=9;
	
	int HP[s]={5,9,3,6,2,4,8,1,7};
	
	int* H=createHeap(HP,s);
	
	for(int i=0 ;i<s ;i++)
	cout<<H[i]<<" ";cout<<endl;
	
	cout<<isHeap(H,s)<<endl;
	

	
//	vector<int> v=heap_sort(H,s);
	
	k_largest(H,s,7);
	
//	for(int i=0 ;i<v.size() ;i++)
//	cout<<v[i]<<" ";
	
	
}

