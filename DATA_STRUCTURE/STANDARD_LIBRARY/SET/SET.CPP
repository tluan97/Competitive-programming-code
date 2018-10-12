/*
	SET
	tested
*/
#include <bits/stdc++.h>
using namespace std;

set<int> s1;
unordered_set<int> s2;
multiset<int> s3;
unordered_multiset<int> s4;

void set_(){
	set<int>::iterator it1 = s1.begin();
	set<int>::iterator it2 = s1.end();
	s1.clear();
	s1.size();
	s1.empty();
	s1.count(0);
	s1.insert(4);
}
int main(){
	set_();
}

