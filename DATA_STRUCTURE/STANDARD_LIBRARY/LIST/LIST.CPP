/*
	LIST
	tested
*/
#include <bits/stdc++.h>
using namespace std;

list<int> l;

void list_(){
	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.end();
	l.clear();
	l.size();
	l.empty();
	
	l.front();
	l.back();
	l.push_front(1);
	l.push_back(2);
	l.pop_back();
	l.pop_front();
}
int main(){
	list_();
}
