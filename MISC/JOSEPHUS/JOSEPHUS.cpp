/*
	JOSEPHUS
	https://vn.spoj.com/problems/ANT/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL josephus(LL n,LL k){
	LL p=n*k;
	LL nn=n+1, kk=k-1;
	while (p>n){
		p+=(p-nn)/kk-n;
	}
	return p;
}

void ANT(){
	LL n,m;
	cin>>n>>m;
	cout<<josephus(n,m);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ANT();
	return 0;
}
