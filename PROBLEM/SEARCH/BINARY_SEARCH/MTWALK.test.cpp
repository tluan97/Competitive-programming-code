/*
	MTWALK
	https://vn.spoj.com/problems/MTWALK/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
#define X first
#define Y second
const int maxn = 120;
const int oo = 1000111000;
int n,a[maxn][maxn],ans;
int dm[]={1,-1,0,0};
int dn[]={0,0,1,-1};
int k,d[maxn][maxn],f;
int pmi,pma,hmi,hma,ami=maxn,ama=-1;

bool check(int x,int y){
	if (1<=x && x<=n && 1<=y && y<=n && 
		!d[x][y] && pmi<=a[x][y] && a[x][y]<=pma)
		return true;
	return false;
}
bool dfs(){
	int u,v;
	stack<II> st;
	while (st.size()) st.pop();
	st.push(II(1,1));
	while (st.size()){
		II t=st.top(); st.pop();
		u=t.X; v=t.Y;
		if (!check(u,v)) continue;
		if (u==n && v==n) return true;
		d[u][v]=1;
		for (int z=0;z<4;z++){
			st.push(II(u+dm[z],v+dn[z]));
		}
	}
	return false;
}
bool find(int mm){
	for (int k=ami;k<=ama-mm;k++){
		memset(d,0,sizeof(d));
		pmi=k; pma=k+mm;
		if (dfs()) return true;
	}
	return false;
}
int binarysearch(int left, int right){
	int ll=left,rr=right,mm=(ll+rr)/2;
	while (ll!=mm && mm!=rr){
		if (find(mm)) rr=mm;
		else ll=mm;
		mm=(ll+rr)/2;
//		cout<<ll<<" "<<mm<<" "<<rr<<"--\n";
	}
	return rr;
}
void solve(){
	ans=binarysearch(hmi,hma);
//	cout<<find(0)<<"\n";
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		cin>>a[i][j];
		ami=min(ami,a[i][j]);
		ama=max(ama,a[i][j]);
	}
	hmi=-1;hma=ama-ami;
	solve();
	cout<<ans<<"\n";
	return 0;
}
/*
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1
2
*/
