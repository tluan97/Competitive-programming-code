/*
	TSP
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 21;
const int maxs = 1100010;
const int oo = 1000111000;

int n,m,u,v,c;
int a[maxn][maxn],f[maxn][maxs];
vector<int> aa[maxn];

int tsp(int i,int s){
	if (s==((1<<n)-1)) return a[i][0];
	if (f[i][s]!=-1) return f[i][s];
	int ans=oo;
	for (int j=0;j<aa[i].size();j++){
		u=aa[i][j];
		if (s&(1<<u)) continue;
		ans=min(ans,a[i][u]+tsp(u,s|(1<<u)));
	}
	f[i][s]=ans;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i=0;i<maxn;i++){
		for (int j=0;j<maxn;j++)
			a[i][j]=oo;
		for (int j=0;j<maxs;j++)
			f[i][j]=-1;
	}
	
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>u>>v>>c;
		u--; v--;
		a[u][v]=min(a[u][v],c);
		aa[u].push_back(v);
	}
	cout<<tsp(0,1<<0);
	
	return 0;
}
