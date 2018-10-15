/*
	SUM_OF_DIGITS
	https://open.kattis.com/problems/digitsum
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
	int test; cin>>test;
	LL u,v;
	while (test--){
		cin>>u>>v;
		cout<<sumDigits(v)-sumDigits(u-1)<<"\n";
	}
}

LL sumDigitBF(LL n){
	LL res=0;
	while (n){
		res+=n%10;
		n/=10;
	}
	return res;
}
LL sumDigit(LL n){
	if (n<=0) return 0;
	LL res;
	if (n%10==0){
		res=10LL*sumDigit(n/10)+45LL*(n/10);
	} else {
		res=sumDigit(n-1)+sumDigitBF(n-1);
	}
	return res;
}
LL u,v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test; cin>>test;
	while (test--){
		cin>>u>>v;
		cout<<sumDigit(v+1)-sumDigit(u)<<"\n";
	}
	
	return 0;
}
