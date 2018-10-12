/*
	PRIME_RABIN_MILLER
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;
const int maxn = 100010;

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

LL mulMod(LL x, LL y, LL p) {
	if (y == 0) return 0;
	if (x < 1000111000111000111LL / y) return x * y % p;
	LL mid = mulMod((x+x)%p, y>>1LL, p);
	if (y & 1) return (mid + x) % p;
	else return mid;
}
LL powMod(LL x, LL k, LL m) {
	if (k == 0) return 1;
	if ((k & 1)) return mulMod(x,powMod(x, k-1, m), m);
	else return powMod(mulMod(x,x,m), k/2, m);
}
bool suspect(LL a, LL s, LL d, LL n) {
	LL x = powMod(a, d, n);
	if (x == 1) return true;
	for (int r = 0; r < s; ++r) {
		if (x == n - 1) return true;
		x = mulMod(x, x, n);
	}
	return false;
}
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^15 (at least)
bool isPrime(LL n) {
	if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
	LL test[] = {2,3,5,7,11,13,17,19,23,-1};
	LL d = n - 1, s = 0;
	while (d % 2 == 0) ++s, d /= 2;
	for (int i = 0; test[i] < n && test[i] != -1; ++i)
		if (!suspect(test[i], s, d, n)) return false;
	return true;
}
// KiLLer prime: 5555555557LL (fail when not used mulMod)

void test_PRIME_RABIN_MILLER(){
	eratosthene(100000);
	for (int i=0;i<primes.size();i++){
		if (!isPrime(primes[i])){
			cout<<primes[i]<<"  FAIL\n";
		}
	}
	cout<<"DONE\n";
}
int main(){
	test_PRIME_RABIN_MILLER();
	return 0;
}
