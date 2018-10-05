/*
	BELLMAN
	http://www.spoj.com/problems/EZDIJKST/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
const int oo = ~(1<<31);
typedef pair<int, int> II;
#define X first
#define Y second

int n,m;
vector<II> a[maxn];
int d[maxn];
bool inqueue[maxn];
void bellman(int s,int d[maxn]){
	queue<int> qu;
	int i,u,v,uv;
	for (i=1;i<=n;i++) d[i]=oo;
	d[s]=0;
	qu.push(s);
	inqueue[s]=1;
	while (qu.size()){
		u=qu.front();qu.pop();
		inqueue[u]=0;
		for (i=0;i<a[u].size();i++){
			v=a[u][i].Y;
			uv=a[u][i].X;
			if (d[v]>d[u]+uv){
				d[v]=d[u]+uv;
				if (!inqueue[v]){
					qu.push(v);
					inqueue[v]=1;
				}
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
		bellman(s,d);
		if (d[t]==oo) cout<<"NO\n";
		else cout<<d[t]<<"\n";
	}
	return 0;
}
