#include<iostream>
#include<string>
using namespace std;

int getindex(char c,string s,int current)
{
	if(s[current]==c || current==s.length())
	return current;
	
	else{
		int k=getindex(c,s,current+1);
		return k;
	}
}

//s1 is testing on s2
bool check(string s1,string s2,int current,int index)
{
	if(current>=s2.length())
	return false;
	
	else if(index==s1.length() && current<s2.length())
	return true;
	
	else{
		current=getindex(s1[index],s2,current);
		return check(s1,s2,current,index+1);
		}

}



int main()
{
	string s="table";
	cout<<check("bat",s,0,0);
}
