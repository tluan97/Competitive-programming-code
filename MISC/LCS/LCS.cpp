/*
	LCS
	https://www.spoj.com/problems/LCS/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn =  1010;

string a,b;
int n,m;
int f[maxn][maxn];

void lcs(){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
	else f[i][j]=max(f[i-1][j],f[i][j-1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	n=a.length(); a=" "+a;
	m=b.length(); b=" "+b;
	lcs();
	cout<<f[n][m]<<"\n";
	
	return 0;
}
