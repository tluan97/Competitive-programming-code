/*
	STRING
	tested
*/
#include <bits/stdc++.h>
using namespace std;

string s;

void string_(){
	string::iterator it1=s.begin();
	string::iterator it2=s.end();
	s.clear();
	s.empty();
	s.size();
	s.length();
	s="abcde";
	s.insert(s.begin()+1,'a');
	cout<<s<<"\n";
	s.erase(s.begin()+0);
	cout<<s<<"\n";
	s.find("a",0);
	s.compare(0,s.size(),"a");
	s.replace(s.begin()+1,s.begin()+2,"a");
	cout<<s<<"\n";
}
int main(){
	string_();
}
