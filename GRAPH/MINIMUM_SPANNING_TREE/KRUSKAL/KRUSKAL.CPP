/*
	KRUSKAL
	http://vn.spoj.com/problems/QBMST/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
typedef pair<int,int> II;
typedef pair<int,II> III;
#define X first
#define Y second

int par[maxn];
void initDSU(){
	for (int i=1;i<maxn;i++){
		par[i]=i;
	}
}
int anc(int p){
	if (par[p]==p) return p;
	return par[p]=anc(par[p]);
}
void join(int p,int q){
	par[anc(p)]=anc(q);
}

int n,m;
vector<III> e;
int kruskal(){
	int res=0;
	initDSU();
	sort(e.begin(),e.end());
	for (int i=0;i<e.size();i++){
		if (anc(e[i].Y.X)!=anc(e[i].Y.Y)){
			join(e[i].Y.X,e[i].Y.Y);
			res+=e[i].X;
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
		e.push_back(III(w,II(u,v)));
	}
	cout<<kruskal()<<"\n";
	return 0;
}

