/*
	PRIME_ERATOSTHENE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;
const int maxn = 10000010;

bitset<maxn> b;
VLL primes;
LL ssize;
void eratosthene(LL upperbound){
	ssize=upperbound+1;
	b.set(); b[0]=b[1]=0;
	for (LL i=2;i<=ssize;i++)
	if (b[i]){
		for (LL j=i*i;j<=ssize;j+=i)
			b[j]=0;
		primes.push_back(i);
	}
}
bool isPrime(LL x){
	if (x<=ssize) return b[x];
	for (int i=0;i<primes.size();i++)
	if (x%primes[i]==0) return false;
	return true;
}

int main(){
	eratosthene(10000000);
	cout<<isPrime(2147483647)<<"\n"; // 1
	cout<<isPrime(136117223861LL)<<"\n"; // 0
	return 0;
}
