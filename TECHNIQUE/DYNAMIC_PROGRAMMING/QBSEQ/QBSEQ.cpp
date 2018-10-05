/*
	QBSEQ
	https://vn.spoj.com/problems/QBSEQ/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int maxk = 60;
const int oo = 1000111000;

int n,k;
int a[maxn];
int f[maxn][maxk];
int ans;

void solve(){
	for (int j=1;j<k;j++)
		f[0][j]=-oo;
	f[0][0]=0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<k;j++){
		f[i][j]=max(f[i-1][j],
			f[i-1][(j-a[i]+k*k*k)%k]+1);
	}
	ans=f[n][0];
//	for (int i=0;i<=n;i++){
//		for (int j=0;j<k;j++)
//			cout<<f[i][j]<<" ";
//		cout<<"\n";
//	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	cout<<ans<<"\n";
	
	return 0;
}
/*
10 3
2 3 5 7
9 6 12 7
11 15
*/
