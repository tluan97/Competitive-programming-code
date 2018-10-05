/*
	PRIME_MODIFIED_SIEVE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int sieve[maxn];
void modifiedSieve(){
	memset(sieve,0,sizeof(sieve));
	for (int i=2;i<maxn;i++)
	if (sieve[i]==0){
		for (int j=i;j<maxn;j+=i){
			sieve[j]++;
		}
	}
}

void test_(){
	modifiedSieve();
	assert(sieve[20]==2);
}
int main(){
	test_();
	return 0;
}
