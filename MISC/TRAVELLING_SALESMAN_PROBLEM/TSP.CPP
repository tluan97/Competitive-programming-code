/*
	TSP
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,int> II;
#define X first
#define Y second
const int maxn = 1010;
const int oo = ~(1<<31);

int n,t;
LL ans,m;
vector<II> a[maxn];
bool visited[maxn];

void input(){
	cin>>n;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		cin>>m;
		if (i!=j) a[i].push_back(II(m,j)); 
	}
}
void init(){
	memset(visited,0,sizeof(visited));
	m=0;
}
void visit0(int s){
	cout<<s<<" -> ";
	visited[s]=1;
	for (int i=0,v;i<a[s].size();i++){
		v=a[s][i].Y;
		if (!visited[v]){
			m+=a[s][i].X;
			t=v;
			visit0(v);
		}
	}
}
void visit1(int t,int s){
	cout<<s<<"\n";
	for (int i=0,v;i<a[t].size();i++){
		v=a[t][i].Y;
		if (v==s){
			m+=a[t][i].X;
			return;
		}
	}
}
LL TSP(){
	ans=oo;
	for (int i=1;i<=n;i++)
		sort(a[i].begin(),a[i].end());
//	for (int i=1;i<=n;i++){
//		for (int j=0;j<a[i].size();j++){
//			cout<<a[i][j].X<<" "<<a[i][j].Y<<"\n";
//		}
//	}
	for (int s=1;s<=n;s++){
		init();
		cout<<s<<" : ";
		visit0(s);
		visit1(t,s);
		cout<<"Sum = "<<m<<"\n\n";
		ans=min(ans,m);
	}
	return ans;
}

int main()
{
	freopen("TSP.INP","r",stdin);
	freopen("TSP.OUT","w",stdout);
	
	input();
	cout<<TSP()<<"\n";
	
	return 0;
}
