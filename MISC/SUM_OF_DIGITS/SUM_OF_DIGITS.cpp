/*
	SUM_OF_DIGITS
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL sd[20];
void init_sumDigits(){
	sd[0]=0;
	LL ten=1;
	for (int i=1;i<20;i++){
		sd[i]=sd[i-1]*10+45*ten;
		ten*=10;
	}
}
LL sumDigits(LL n){
	if (n<10) return n*(n+1)/2;
	LL d=log10(n);
	LL p=ceil(pow(10,d));
	LL t=n/p;
	return t*sd[d]+(t*(t-1)/2)*p+
		t*(1+n%p)+sumDigits(n%p);
}

void test_(){
	init_sumDigits();
	assert(sumDigits(328)==3241);
}
int main(){
	test_();
	return 0;
}
