#include<iostream>
using namespace std;


struct s1{
	int a;
	int b;
};

int main()
{
	struct s1 *s;
	s=new(s1);
	s->a=5;
	cout<<s->a;
	struct s1 p;
	p.a=5;
	cout<<p.a
}
