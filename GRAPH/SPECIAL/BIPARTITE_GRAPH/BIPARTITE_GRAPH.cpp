/*
	BIPARTITE_GRAPH
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int n,m;
vector<int> a[maxn];
bool visit[maxn];
int color[maxn];
bool invalid=0;

void check_bipartite(int u){
	visit[u]=1;
	for (int i=0,v;i<a[u].size();i++){
		v=a[u][i];
		if (!visit[v]){
			color[v]=3-color[u];
			check_bipartite(v);
		}
		else {
			if (color[u]==color[v])
				invalid=1;
		}
	}
}
void input(){
	cin>>n>>m;
	for (int i=1,p,q;i<=m;i++){
		cin>>p>>q;
		a[p].push_back(q);
		a[q].push_back(p);
	}
}
void solve(){
	for (int i=1;i<=n;i++){
		if (!visit[i]){
			color[i]=1;
			check_bipartite(i);
		}
	}
}
void output(){
	if (invalid) cout<<"Invalid\n";
	else {
		for (int i=1;i<=n;i++)
			cout<<color[i]<<" ";
		cout<<"\n";
	}
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
