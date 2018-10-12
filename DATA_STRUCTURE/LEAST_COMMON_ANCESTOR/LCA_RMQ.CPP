/*
	LCA_RMQ
	http://www.spoj.com/problems/LCA/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const int maxl = 21;

int n,m,u,v;
vector<int> a[maxn];
int root;
int L[maxn]; // level
int R[maxl][maxn]; // rmax
int P[maxl][maxn]; // parent

int level(int u){
	if (u==root) return L[u]=1;
	if (L[u]) return L[u];
	return L[u]=level(P[0][u])+1;
}
void initLCA_RMQ(){
	for (int i=1;i<=n;i++)
		if (P[0][i]==0) root=i;
	for (int i=1;i<=n;i++)
		level(i);
	for (int k=1;k<=20;k++)
	for (int i=1;i<=n;i++){
		P[k][i]=P[k-1][P[k-1][i]];
		R[k][i]=min(R[k-1][P[k-1][i]],R[k-1][i]);
	}
}
int getLCA_RMQ(int u,int v){
	int res=0;
	if (L[u]<L[v]) swap(u,v);
	for (int k=20;k>=0;k--)
	if (P[k][u]!=-1 && L[P[k][u]]>=L[v]){
		res=min(res,R[k][u]);
		u=P[k][u];
	}
	if (u==v) return u; // if RMQ, return res
	for (int k=20;k>=0;k--)
	if (P[k][u]!=P[k][v]){
		res=min(res,R[k][u]);
		res=min(res,R[k][v]);
		u=P[k][u];
		v=P[k][v];
	}
	res=min(res,R[0][u]);
	res=min(res,R[0][v]);
	return P[0][u]; // if RMQ, return res
}
void resetLCA(){
	memset(L,0,sizeof(L));
	memset(R,0,sizeof(R));
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
		cout<<getLCA_RMQ(u,v)<<"\n";
	}
}

int main()
{
	int tc;cin>>tc;
	for (int z=1;z<=tc;z++){
		resetLCA();
		inputLCA();
		cout<<"Case "<<z<<":\n";
		initLCA_RMQ();
		outputLCA();
	}
	return 0;
}
