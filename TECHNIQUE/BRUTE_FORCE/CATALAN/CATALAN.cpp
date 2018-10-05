/*
	CATALAN
	https://vn.spoj.com/problems/CATALAN/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = (15<<1)+10;

int n;
int a[maxn];
int k;
int f[maxn][maxn];

void initCatalan(int n){
	f[n-1][1]=1;
	for (int i=n-1;i>=2;i--)
	for (int j=0;j<n;j++)
	if (f[i][j]){
		f[i-1][j+1]+=f[i][j];
		if (j) 
			f[i-1][j-1]+=f[i][j];
	}
}
void solve(int n,int a[maxn]){
	int ans=1;
	for (int i=1;i<n;i++)
	for (int j=0;j<a[i];j++)
	if (abs(a[i-1]-j)==1){
		ans+=f[i][j];
	}
	cout<<ans<<"\n";
}
void solve(int n,int k){
	int b[maxn]={};
	b[1]=1;
	for (int i=2;i<n;i++){
		if (b[i-1]==0){
			b[i]=1;
		} else if (f[i][b[i-1]-1]<k){
			k-=f[i][b[i-1]-1];
			b[i]=b[i-1]+1;
		} else {
			b[i]=b[i-1]-1;
		}
	}
	for (int i=0;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n; n<<=1;
	for (int i=0;i<=n;i++)
		cin>>a[i];
	cin>>k;
	initCatalan(n);
	solve(n,a);
	solve(n,k);
	
	return 0;
}
/*
4
0 1 2 3 2 1 2 1 0
12
*/
