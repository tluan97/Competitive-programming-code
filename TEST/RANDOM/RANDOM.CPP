/*
	RANDOM
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct random {
	LL rand16(){
		return rand() & ((1LL<<16)-1);
	}
	LL rand32(){
		return rand16()<<16 | rand16();
	}
	LL rand64(){
		return rand32()<<32 | rand32();
	}
};

void test_random(){
	srand(time(NULL));
	random r;
	int test; cin>>test;
	for (int i=1;i<=test;i++){
		cout<<r.rand64()<<"\n";
	}
}
int main(){
	test_random();
	return 0;
}
