/*
	LCA_EULER_TOUR
	http://www.spoj.com/problems/LCA/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> II;
#define X first
#define Y second
const int maxn = 100010;
const int oo = ~(1<<31);

int n,m,u,v;
vector<II> a[maxn];
LL rootd[maxn],t;
int in[maxn],out[maxn];
int P[21][maxn];

void initLCA(int cur,int par,LL d){
	P[0][cur]=par;
	for (int i=1,k=par;P[i-1][cur];k=P[i++][cur])
		P[i][cur]=P[i-1][k];
	in[cur]=t++;
	rootd[cur]=d;
	for (int i=0;i<a[cur].size();i++)
	if (a[cur][i].Y!=par)
		initLCA(a[cur][i].Y,cur,d+a[cur][i].X);
	out[cur]=t++;
}
int getLCA(int u,int v){
	if (in[u]<=in[v] && out[v]<=out[u])
		return u;
	if (in[v]<=in[u] && out[u]<=out[v])
		return v;
	for (int i=20;i>=0;i--)
	if (in[v]<in[P[i][u]] || out[P[i][u]]<out[v])
		u=P[i][u];
	return P[0][u];
}
void resetLCA(){
	memset(rootd,0,sizeof(rootd));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for (int i=1;i<maxn;i++){
		a[i].clear();
		P[0][i]=0;
	}
	t=0;in[0]=-oo;out[0]=oo;
}
void inputLCA(){
	cin>>n;
	for (int i=1,x,y;i<=n;i++){
		cin>>y;while (y--){
			cin>>x;
			a[i].push_back(II(0,x));
			a[x].push_back(II(0,i));
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
		initLCA(1,0,0);
		outputLCA();
	}
	return 0;
}
