/*
	KADANE_1D
	https://www.spoj.com/problems/MAXSUMSQ/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const int oo = 1000111000;

int n;
int a[maxn];
int s[maxn];

void kadane(){
	int mi=0,ma=-oo;
	long long cma=0,cmi=1;
	
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for (int i=1;i<=n;i++){
		if (ma<s[i]-mi){
			ma=s[i]-mi;
			cma=0;
		}
		if (ma==s[i]-mi){
			cma+=cmi;
		}
		if (mi>s[i]){
			mi=s[i];
			cmi=0;
		}
		if (mi==s[i]){
			cmi+=1;
		}
	}
	cout<<ma<<" "<<cma<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test; cin>>test;
	while (test--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		kadane();
	}
	return 0;
}
