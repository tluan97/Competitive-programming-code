/*
	GRAPH_COLORING
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
#define X first
#define Y second
const int maxn = 1010;

int n,m;
int a[maxn][maxn];
int color[maxn];
vector<II> s;

void input(){
	cin>>n;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		cin>>a[i][j];
	}
}
void output(){
	for (int i=1;i<=n;i++)
		cout<<i<<" : "<<color[i]<<"\n";
	cout<<"\n";
	for (int i=1;i<=m;i++){
		cout<<"Color "<<i<<" : ";
		for (int j=1;j<=n;j++)
		if (color[j]==i)
			cout<<j<<" ";
		cout<<"\n";
	}
}
void coloring(){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		a[i][0]+=a[i][j];
	for (int i=1;i<=n;i++)
		s.push_back(II(-a[i][0],i));
	sort(s.begin(),s.end());
	for (int i=0,u;i<s.size();i++){
		u=s[i].Y;
		if (!color[u]){
			color[u]=++m;
			for (int j=i+1,v;j<s.size();j++){
				v=s[j].Y;
				if (!color[v] && !a[u][v]) 
					color[v]=m;
			}
		}
	}	
}

int main()
{
	freopen("GRAPH_COLORING.INP","r",stdin);
	freopen("GRAPH_COLORING.OUT","w",stdout);
	
	input();
	coloring();
	output();
	
	return 0;
}
