/*
	MMMGAME
	https://vn.spoj.com/problems/MMMGAME/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;

int n;
int a[maxn];

void solve(){
	int sxor=0,one=0;
	for (int i=1;i<=n;i++){
		sxor^=a[i];
		if (a[i]==1) one++;
	}
	if (one==n){
		if (one%2==0) cout<<"John\n";
		else cout<<"Brother\n";
	} else {
		if (sxor) cout<<"John\n";
		else cout<<"Brother\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test; cin>>test;
	while (test--){
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		solve();
	}
	return 0;
}
