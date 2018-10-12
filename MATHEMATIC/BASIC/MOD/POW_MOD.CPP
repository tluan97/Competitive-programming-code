/*
	POW_MOD
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL pow_mod(LL a,LL b,LL p){
	if (b==0) return (1%p);
	if (b==1) return (a%p);
	LL t=pow_mod(a,b>>1,p);
	t=(t*t)%p;
	if (b&1) return (t*a)%p;
	else return (t)%p;
}

LL pow_mod_test(LL a,LL b,LL p){
	LL t=1;
	for (int i=1;i<=b;i++){
		t*=a;t%=p;
	}
	return t;
}
void test_random(){
	srand(time(NULL));
	LL a,b,p;
	int t=100;
	while (t--){
		a=rand()*rand();
		b=rand();
		p=rand()+1;
		if (pow_mod(a,b,p)!=pow_mod_test(a,b,p)){
			cout<<a<<" "<<b<<" "<<p<<"\n";
		}
	}
	cout<<"-----\n";
}

int main()
{
	test_random();
	return 0;
}
