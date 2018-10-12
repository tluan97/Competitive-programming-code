/*
	VECTOR
	tested
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void vector_(){
	vector<int>::iterator it1=a.begin();
	vector<int>::iterator it2=a.end();
	a.clear();
	a.resize(10,1);
	a.size();
	a.push_back(100);
	a.pop_back();
	a.empty();
	a.erase(a.begin()+5);
	a[5];
}
int main(){
	vector_();
}
