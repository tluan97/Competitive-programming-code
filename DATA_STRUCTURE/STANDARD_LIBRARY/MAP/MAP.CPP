/*
	MAP
	tested
*/
#include <bits/stdc++.h>
using namespace std;

map<int,int> mm1;
unordered_map<int,int> mm2;
multimap<int,int> mm3;

void map_(){
	map<int,int>::iterator it1 = mm1.begin();
	map<int,int>::iterator it2 = mm1.end();
	mm1.clear();
	mm1.size();
	mm1.empty();
	mm1.count(0);
	mm1[-4]=4;
}
int main(){
	map_();
}

