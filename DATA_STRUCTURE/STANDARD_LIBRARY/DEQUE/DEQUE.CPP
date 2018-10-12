/*
	DEQUE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

deque<int> d;

void deque_(){
	deque<int>::iterator it1 = d.begin();
	deque<int>::iterator it2 = d.end();
	d.clear();
	d.size();
	d.empty();
	
	d.front();
	d.back();
	d.push_front(1);
	d.push_back(2);
	d.pop_back();
	d.pop_front();
	d.erase(d.begin()+1);
}
int main(){
	deque_();
}
