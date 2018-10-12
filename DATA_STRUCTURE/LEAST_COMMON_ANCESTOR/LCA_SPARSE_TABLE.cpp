/*
	LCA_SPARSE_TABLE
	http://www.spoj.com/problems/LCA/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100010;

int n,m,u,v;
vector<int> a[maxn];
int root;
int L[maxn];
int P[21][maxn];

int level(int u){
	if (u==root) return L[u]=1;
	if (L[u]) return L[u];
	return L[u]=level(P[0][u])+1;
}
void initLCA(){
	for (int i=1;i<=n;i++)
		if (P[0][i]==0) root=i;
	for (int i=1;i<=n;i++)
		level(i);
	for (int k=1;k<=20;k++)
	for (int i=1;i<=n;i++)
		P[k][i]=P[k-1][P[k-1][i]];
}
int getLCA(int u,int v){
	for (int k=20;k>=0;k--)
	if (L[P[k][u]]>=L[v])
		u=P[k][u];
	for (int k=20;k>=0;k--)
	if (L[P[k][v]]>=L[u])
		v=P[k][v];
	for (int k=20;k>=0;k--)
	if (P[k][u]!=P[k][v])
		u=P[k][u],v=P[k][v];
	while (u!=v)
		u=P[0][u],v=P[0][v];
	return u;
}
void resetLCA(){
	memset(L,0,sizeof(L));
	for (int i=1;i<maxn;i++){
		a[i].clear();
		P[0][i]=0;
	}
}
void inputLCA(){
	cin>>n;
	for (int i=1,x,y;i<=n;i++){
		cin>>y;while (y--){
			cin>>x;
			a[i].push_back(x);
			P[0][x]=i;
		}
	}
	cin>>m;
}
void outputLCA(){
	while (m--){
		cin>>u>>v;
		cout<<getLCA(u,v)<<"\n";
	}
}

int main()
{
	int tc;cin>>tc;
	for (int z=1;z<=tc;z++){
		resetLCA();
		inputLCA();
		cout<<"Case "<<z<<":\n";
		initLCA();
		outputLCA();
	}
	return 0;
}
