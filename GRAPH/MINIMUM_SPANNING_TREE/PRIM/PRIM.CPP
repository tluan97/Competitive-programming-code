/*
	PRIM
	http://vn.spoj.com/problems/QBMST/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn=10010;
const int oo=~(1<<31);
typedef pair<int, int> II;
#define X first
#define Y second

int n,m;
vector<II> a[maxn];
int d[maxn];
int prim(int s){
	priority_queue<II> pq;
	int i,u,v,du,uv,res=0;
	for (i=1;i<=n;i++) d[i]=oo;
	d[s]=0;
	pq.push(II(0,s));
	while (pq.size()){
		u=pq.top().Y;
		du=-pq.top().X;
		pq.pop();
		if (du!=d[u]) continue;
		res+=d[u]; d[u]=0;
		for (i=0;i<a[u].size();i++){
			v=a[u][i].Y;
			uv=a[u][i].X;
			if (d[v]>uv){
				d[v]=uv;
				pq.push(II(-d[v],v));
			}
		}
	}
	return res;
}

int main()
{
	cin>>n>>m;
	int u,v,w;
	for (int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back(II(w,v));
		a[v].push_back(II(w,u));
	}
	cout<<prim(1)<<"\n";
	return 0;
}
