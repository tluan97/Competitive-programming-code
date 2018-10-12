/*
	CATALAN
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

ULL binomialCoeff(int n,int k){
	ULL res=1;
	if (k>=n-k) k=n-k;
	for (int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

const int maxn = 30;
ULL cata[maxn];
void catalan(){
	cata[0]=cata[1]=1;
	for (int i=2;i<maxn;i++){
		cata[i]=0;
		for (int j=0;j<i;j++)
			cata[i]+=cata[j]*cata[i-j-1];
	}
}
ULL catalan(int n){
	if (n<=1) return 1;
	ULL res=0;
	for (int i=0;i<n;i++)
		res+=catalan(i)*catalan(n-i-1);
	return res;
}
ULL catalan_(int n){
	ULL res=binomialCoeff(2*n,n);
	return res/(n+1);
}

void test_(){
	catalan();
	int t=1000;
	while (t--){
		int n=rand()%maxn;
		if (catalan(n)!=cata[n] ||
			catalan_(n)!=cata[n]){
			cout<<n<<" "<<cata[n]<<"\n";
		}
	}
}
int main(){
	test_();
	return 0;
}
