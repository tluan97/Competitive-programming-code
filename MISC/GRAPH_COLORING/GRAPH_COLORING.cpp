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
vector<int> a[maxn];
int aa[maxn][maxn];
int color[maxn];
vector<II> d;

void input(){
	cin>>n;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		cin>>aa[i][j];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (aa[i][j]==1){
				a[i].push_back(j);
			}
		}
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
bool comp(II a,II b){
	return a.X>b.X;
}
void coloring(){

	for (int i=1;i<=n;i++){
		d.push_back(II((int)a[i].size(),i));
	}
	sort(d.begin(),d.end(),comp);
	int c=0;
	for (int i=0,u;i<(int)d.size();i++){
		u=d[i].Y;
		if (!color[u]){
			color[u]=++c;
			for (int j=i+1,v;j<(int)d.size();j++){
				v=d[j].Y;
				if (!color[v]){
					bool maybe=true;
					for (int k=0;k<(int)a[v].size();k++){
						if (c==color[a[v][k]]){
							maybe=false;
							break;
						}
					}
					if (maybe){
						color[v]=c;
						// cout<<v<<" "<<color[v]<<"--\n";
					}
				}
			}
			// cout<<u<<" "<<color[u]<<"--\n";
		}
	}
	// for (int i=1;i<=n;i++){
	// 	cout<<i<<" "<<color[i]<<"\n";
	// }
	// cout<<c<<"\n";
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
