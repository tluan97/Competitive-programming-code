/*
	C11WATER
	https://vn.spoj.com/problems/C11WATER/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1010;

int m,n;
LL a[maxn][maxn];
LL f[maxn][maxn];
LL ans;

void check(int i,int j){
//	cout<<i<<" "<<j<<"\n";
	if (i<=1 || i>=m || j<=1 || j>=n) return;
	if (a[i][j]!=f[i][j]){
		LL t=min(min(f[i-1][j],f[i+1][j]),
				 min(f[i][j-1],f[i][j+1]));
		if (f[i][j]>t){
			f[i][j]=max(t,a[i][j]);
			check(i-1,j);
			check(i+1,j);
			check(i,j-1);
			check(i,j+1);
		}
	}
}
void solve(){
	for (int i=1;i<=m;i++){
		f[i][1]=a[i][1];
		f[i][n]=a[i][n];
	}
	for (int j=1;j<=n;j++){
		f[1][j]=a[1][j];
		f[m][j]=a[m][j];
	}
	for (int i=2;i<m;i++)
	for (int j=2;j<n;j++)
	if (a[i][j]<f[i-1][j] && a[i][j]<f[i][j-1])
		f[i][j]=min(f[i-1][j],f[i][j-1]);
	else f[i][j]=a[i][j];
	for (int i=2;i<m;i++)
	for (int j=2;j<n;j++)
		check(i,j);
	for (int i=2;i<m;i++)
	for (int j=2;j<n;j++)
		ans+=(f[i][j]-a[i][j]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
		cin>>a[i][j];
	solve();
	cout<<ans<<"\n";
	return 0;
}
