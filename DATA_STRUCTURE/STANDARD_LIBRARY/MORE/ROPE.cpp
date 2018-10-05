/*
	ROPE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

#include <ext/rope> 
	// Slow (balanced BST)!!! do not abuse
using namespace __gnu_cxx;

void test_(){
	rope<int> v; //use as usual STL container
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		v.push_back(i); //initialization
	int l, r;
	for(int i = 0; i < m; ++i){
		cin >> l >> r;
		--l, --r;
		rope <int> cur = v.substr(l, r - l + 1);
		v.erase(l, r - l + 1);
		v.insert(v.mutable_begin(), cur);
	}
	for(rope <int>::iterator it = v.mutable_begin(); it != v.mutable_end(); ++it)
		cout << *it << " ";
}
int main(){
	test_();
	return 0;
}
