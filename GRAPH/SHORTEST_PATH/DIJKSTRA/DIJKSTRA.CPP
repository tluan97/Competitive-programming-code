/*
	DIJKSTRA
	http://www.spoj.com/problems/EZDIJKST/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn=10010;
const int oo=~(1<<30);
typedef pair<int, int> II;
#define X first
#define Y second

int n,m;
vector<II> a[maxn];
int d[maxn];
int dijkstra(int s,int d[maxn]){
	priority_queue<II,vector<II>,greater<II> > pq;
	int i,u,v,du,uv;
	for (i=1;i<=n;i++) d[i]=oo;
	d[s]=0;
	pq.push(II(0,s));
	while (pq.size()){
		u=pq.top().Y;
		du=pq.top().X;
		pq.pop();
		if (du!=d[u]) continue;
		for (i=0;i<a[u].size();i++){
			v=a[u][i].Y;
			uv=a[u][i].X;
			if (d[v]>du+uv){
				d[v]=du+uv;
				pq.push(II(d[v],v));
			}
		}
	}
}

int main()
{
	int u,v,w,s,t;
	int tc;cin>>tc;
	while (tc--){
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			a[i].clear();
		}
		for (int i=1;i<=m;i++){
			cin>>u>>v>>w;
			a[u].push_back(II(w,v));
		}
		cin>>s>>t;
		dijkstra(s,d);
		if (d[t]==oo) cout<<"NO\n";
		else cout<<d[t]<<"\n";
	}
	return 0;
}

