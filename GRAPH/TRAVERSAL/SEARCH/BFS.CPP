/*
	BFS
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

vector<int> a[maxn];
int n,m,t;
int d[maxn],p[maxn];

void bfs(int s){
	int u,v,i;
	queue<int> q;
	q.push(s);d[s]=1;
	
	while (q.size()){
		u=q.front();q.pop();
		for (i=0;v=a[u][i];i++){
			if (!d[v]){
				d[v]=d[u]+1;
				p[v]=u;
				q.push(v);
			}
		}
	}
}

void test(){
	cin>>n>>m;
	int u,v;
	for (int i=1;i<=m;i++){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i=1;i<=n;i++)
		a[i].push_back(0);
	bfs(1);
	int test[]={0,1,2,2,3,3,4};
	for (int i=1;i<=n;i++){
		if (d[i]!=test[i]){
			cout<<"error\n";
		}
	}
	cout<<"-----\n";
}
int main()
{
	test();
	return 0;
}
/*
6 9
1 2
1 3
2 3
2 4
3 5
2 5
4 5
4 6
5 6
*/
