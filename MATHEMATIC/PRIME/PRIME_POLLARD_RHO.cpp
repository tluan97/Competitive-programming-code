/*
	PRIME_POLLARD_RHO
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool isPrime(int x){
	if (x==2 || x==3) return true;
	if (x==1 || x%2==0 || x%3==0) return false;
	int sqrtx = (int)sqrt(x);
	for (int i=5;i<=sqrtx;i+=6)
	if (x%i==0 || x%(i+2)==0) return false;
	return true;
}
LL gcd(LL a,LL b){
	return (b==0)?a:gcd(b,a%b);
}
LL mul_mod(LL a,LL b,LL p){
	if (b==0) return 0;
	if (b==1) return (a%p);
	LL t=mul_mod(a,b>>1,p);
	t=t+t;
	if (b&1) return (t+a)%p;
	else return (t)%p;
}

LL f(LL x,LL m,LL k){
	return (mul_mod(x,x,m)+k%m)%m;
}
LL pollard_rho(LL n,LL k){
	LL a=2, b=2;
	do {
		a=f(a,n,k);
		b=f(b,n,k);
		b=f(b,n,k);
		LL p=gcd(abs(b-a),n);
		if (p>1) return p;
	} while (a!=b);
	return n;
}
LL get_factor(LL n){
	if (n==1) return n;
	if (isPrime(n)) return n;
	if (n==4) return 2;
	LL p=n,q;
	for (LL k=1;p==n;k++){
		p=pollard_rho(n,k);
		q=n/p;
	}
	return p;
}

void test_(){
	int test=1000;
	while (test--){
		LL n=rand()+1;
		if (n%get_factor(n)!=0){
			cout<<n<<"\n";
		}
	}
}
int main(){
	test_();
	return 0;
}
