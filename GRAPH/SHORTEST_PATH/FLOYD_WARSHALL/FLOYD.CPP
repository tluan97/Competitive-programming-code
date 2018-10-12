/*
	FLOYD
	http://vn.spoj.com/problems/FLOYD/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
const int oo = 1000000;

int n,m;
int d[maxn][maxn];
int p[maxn][maxn];
void initFloyd(int n){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		d[i][j]=oo;
		p[i][j]=0;
	}
	for (int i=1;i<=n;i++){
		d[i][i]=0;
		p[i][i]=i;
	}
}
void floyd(){
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (d[i][j]>d[i][k]+d[k][j]){
		d[i][j]=d[i][k]+d[k][j];
		p[i][j]=p[i][k];
	}
}
int getd(int s,int t){
	return d[s][t];
}
vector<int> getp(int s,int t){
	vector<int> r;
	do {
		r.push_back(s);
		s=p[s][t];
	} while (s!=t);
	r.push_back(s);
	return r;
}

int main()
{
	int k,u,v,w;
	cin>>n>>m>>k;
	initFloyd(n);
	for (int i=1;i<=m;i++){
		cin>>u>>v>>w;
		d[u][v]=w;p[u][v]=v;
		d[v][u]=w;p[v][u]=u;
	}
	floyd();
	for (int i=1;i<=k;i++){
		cin>>w>>u>>v;
		if (w==0){
			int t=getd(u,v);
			cout<<t<<"\n";
		} else {
			vector<int> r=getp(u,v);
			cout<<r.size();
			for (int i=0;i<r.size();i++){
				cout<<" "<<r[i];
			}	cout<<"\n";
		}
	}
	return 0;
}
