/*
	FACTORIAL_MOD
	tested
*/
#include <bits/stdc++.h>
using namespace std;

//	n!, excluding p^k of course
int factMod (int n, int p) { 
	int res = 1;
	while (n > 1) {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}

void test_FACTORIAL_MOD(){
	assert(factMod(5,16)==8);
	assert(factMod(5,13)==3);
	assert(factMod(9,37)==21);
	assert(factMod(9,2408)==1680);
	assert(factMod(8,1050)==420);
	cout<<"DONE\n";
}
int main(){
	test_FACTORIAL_MOD();
	return 0;
}
