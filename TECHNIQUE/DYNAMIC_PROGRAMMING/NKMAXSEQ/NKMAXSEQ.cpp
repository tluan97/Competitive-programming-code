/*
	NKMAXSEQ
	https://vn.spoj.com/problems/NKMAXSEQ
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;

int n,p,a[maxn];
int f[maxn];
bool d[maxn];
int ans;

void solve(){
	for (int i=1;i<=n;i++)
		f[i]=a[i]+f[i-1];
	int mi=0;
	for (int i=1;i<=n;i++)
	if (f[i]<mi){
		mi=f[i];
		d[i]=true;
	}
	ans=-1;
	int pos=n;
	for (int i=n;i>=1;i--)
	if (d[i]){
		for (int j=pos;j>=i+1;j--){
			if (f[j]-f[i]>=p){
				if (j-i>ans)
					ans=j-i;
				break;
			}
			pos=j;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>p;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	cout<<ans<<"\n";
	
	return 0;
}

