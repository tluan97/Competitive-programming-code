/*
	PRIME
	http://vn.spoj.com/problems/PAGAIN/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

ULL pow_mod(ULL a,ULL b,ULL p){
	if (b==0) return (1%p);
	if (b==1) return (a%p);
	ULL t=pow_mod(a,b>>1,p);
	t=(t*t)%p;
	if (b&1) return (t*a)%p;
	else return (t)%p;
}

bool isPrime(int x){
	if (x==2 || x==3) return true;
	if (x==1 || x%2==0 || x%3==0) return false;
	int sqrtx = (int)sqrt(x);
	for (int i=5;i<=sqrtx;i+=6)
	if (x%i==0 || x%(i+2)==0) return false;
	return true;
}
bool RabinMiller(ULL n, int k){
	if (n<=50) return isPrime(n);
	ULL d=n-1, s=0;
	while (d%2==0) {s++; d/=2;}
	for (int i=1;i<=k;i++){
		ULL a = rand()%(n-2)+2;
		ULL x = pow_mod(a,d,n);
		if (x==1 || x==n-1) continue;
		for (int j=1;j<s;j++){
			x = (ULL)(x*x)%n;
			if (x==1) return false;
			if (x==n-1) break;
		}
		if (x!=n-1) return false;
	}
	return true;
}

ULL findPrime(ULL n){
	for (ULL i=n-1;i>=2;i--)
	if (RabinMiller(i,20))
		return i;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	srand(time(NULL));
	ULL n;
	int test; cin>>test;
	while (test--){
		cin>>n;
		cout<<findPrime(n)<<"\n";
	}
}
