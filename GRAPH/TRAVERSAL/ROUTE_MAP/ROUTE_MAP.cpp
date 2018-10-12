/*
	ROUTE_MAP
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
#define X first
#define Y second

typedef pair<bitset<maxn>,int> BI;
bitset<maxn> tmp;
int n,m;
vector<BI> a[maxn];
int visit[maxn],par[maxn];

void dfs_in(int u,int p){
	if (visit[u]) return; visit[u]=1;
	for (int i=0,v;i<a[u].size();i++){
		v=a[u][i].Y;
		if (v==p) { par[u]=i;continue; }
		dfs_in(v,u);
		for (int j=0,t;j<a[v].size();j++){
			t=a[v][j].Y;
			if (t==u) continue;
			a[u][i].X|=a[v][j].X;
		}
		a[u][i].X.set(v);
	}
}
void dfs_out(int u,int p){
	int v,ip,pp;
	for (int i=0;i<a[u].size();i++){
		v=a[u][i].Y;
		if (v==p) continue;
		ip=par[v];
		for (int j=0,t;j<a[u].size();j++){
			t=a[u][j].Y;
			if (t==v) continue;
			a[v][ip].X|=a[u][j].X;
		}
		a[v][ip].X.set(u);
		dfs_out(v,u);
	}
}
int route(int u,int v){
	for (int i=0;i<a[u].size();i++)
		if (a[u][i].X.test(v))
			return a[u][i].Y;
	return -1;
}

int main()
{
	freopen("test.txt","r",stdin);
	cin>>n>>m;
	int u,v,r;
	for (int i=1;i<=m;i++){
		cin>>u>>v;
		a[u].push_back(BI(tmp,v));
		a[v].push_back(BI(tmp,u));
	}
	for (int i=1;i<=n;i++)
	if (!visit[i]){
		dfs_in(i,0);
		dfs_out(i,0);
	}
	while (cin>>u>>v>>r && u+v!=0){
		if (route(u,v)!=r)
			cout<<"\n"<<u<<" "<<v<<" "<<route(u,v)<<"\n";
		else cout<<"*";
	}
	return 0;
}
