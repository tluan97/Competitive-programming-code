/*
	PRIME_FACTORS
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;
const int maxn = 10000010;

bitset<maxn> b;
vector<LL> primes;
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

VLL primeFactors(LL x){
	VLL f;
	LL i=0,n=primes[i];
	while (n*n<=x){
		while (x%n==0){
			x/=n;
			f.push_back(n);
		}
		n=primes[++i];
	}
	if (x!=1) f.push_back(x);
	return f;
}
LL sumDiv(LL x){
	LL i=0,n=primes[i],ans=1;
	while (n*n<=x){
		int c=0;
		while (x%n==0) { c++; x/=n; }
		ans*=(pow(n,c+1)-1)/(n-1);
		n=primes[++i];
	}
	if (x!=1) ans*=(pow(x,2)-1)/(x-1);
	return ans;
}
LL EulerPhi(LL x){
	assert(x!=0);
	LL i=0,n=primes[i],phi=x;
	while (n*n<=x){
		if (x%n==0) phi-=phi/n;
		while (x%n==0) x/=n;
		n=primes[++i];
	}
	if (x!=1) phi-=phi/x;
	return phi;
}
LL f[maxn],p[maxn];
void init_EulerPhi(LL n){
	bool stop=false;
	if (!stop){
		for (int i=1;i<n;i++)
			p[i]=1, f[i]=i;
		for (int i=2;i<n;i++){
			if (p[i]){
				f[i]-=f[i]/i;
				for (int j=i+i;j<n;j+=i)
					p[j]=0, f[j]-=f[j]/i;
			}
		}
		stop=true;
	}
}

int main(){
	eratosthene(1000);
	init_EulerPhi(20);
	for (int i=1;i<20;i++)
		assert(f[i]==EulerPhi(i));
}
