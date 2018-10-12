/*
	FACTORIAL
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL lmod = 1000000000000000007LL;
LL mul_mod(LL a,LL b,LL p){
	if (b==0) return 0;
	if (b==1) return (a%p);
	LL t=mul_mod(a,b>>1,p);
	t=t+t;
	if (b&1) return (t+a)%p;
	else return (t)%p;
}

LL factorial(int n,LL mod){
	if (n<=1) return 1LL%mod;
	return mul_mod(n,factorial(n-1,mod),mod);
}

vector<LL> factors;
void init_factors(int maxn,LL mod){
	factors.clear();
	factors.push_back(1);
	LL temp;
	for (int i=1;i<=maxn;i++){
		temp=mul_mod(i,factors[i-1],mod);
		factors.push_back(temp);
	}
}

int main(){
	init_factors(25,lmod);
	for (int i=0;i<=25;i++){
		cout<<i<<" : "<<factors[i]<<"\n";
	}
	return 0;
}
