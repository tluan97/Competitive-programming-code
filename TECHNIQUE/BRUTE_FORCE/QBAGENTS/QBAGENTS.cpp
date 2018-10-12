/*
	QBAGENTS
	https://vn.spoj.com/problems/QBAGENTS/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef pair<int,II> III;
#define X first
#define Y second
const int maxn = 251;

int n,m,s,t;
int r,u,v,ans;
vector<int> a[maxn];
int d[maxn][maxn];
bool f[maxn][maxn];

void solve(){
	queue<II> qu;
	int uu,vv;
	
	memset(d,-1,sizeof(d));
	d[s][t]=0;
	qu.push(II(s,t));
	while (!qu.empty()){
		u=qu.front().X;
		v=qu.front().Y;
		qu.pop();
		if (u==v){
			ans=d[u][v];
			return;
		}
		for (int i=0;i<a[u].size();i++){
			int uu=a[u][i];
			if (f[uu][v]) continue;
			f[uu][v]=1;
			for (int j=0;j<a[v].size();j++){
				vv=a[v][j];
				if (d[uu][vv]==-1){
					d[uu][vv]=d[u][v]+1;
					qu.push(II(uu,vv));
				}
			}
		}
	}
	ans=-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>s>>t;
	for (int i=1;i<=m;i++){
		cin>>u>>v;
		a[u].push_back(v);
	}
	solve();
	cout<<ans<<"\n";
	
	return 0;
}

