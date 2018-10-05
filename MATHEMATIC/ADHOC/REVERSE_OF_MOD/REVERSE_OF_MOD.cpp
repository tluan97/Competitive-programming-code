/*
	REVERSE_OF_MOD
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
	return (b==0)?a:gcd(b,a%b);
}
LL extgcd(LL a, LL b, LL &x, LL &y){
	LL g = a; x = 1; y = 0;
	if (b != 0){
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

LL mod_inv(LL a,LL m){
	LL x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

void test_(){
	int test=10000;
	while (test--){
		LL a=rand();
		LL m=rand();
		if (gcd(a,m)==1 && (a*mod_inv(a,m))%m!=1){
			cout<<a<<" "<<mod_inv(a,m)<<" "<<m<<"\n";
		}
	}
}
int main(){
	test_();
	return 0;
}
