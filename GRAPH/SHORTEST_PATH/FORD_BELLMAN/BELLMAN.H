
int n,m;
vector<II> a[maxn];
int d[maxn];
bool inqueue[maxn];
void bellman(int s,int d[maxn]){
	queue<int> qu;
	int i,u,v,uv;
	for (i=1;i<=n;i++) d[i]=oo;
	d[s]=0;
	qu.push(s);
	inqueue[s]=1;
	while (qu.size()){
		u=qu.front();qu.pop();
		inqueue[u]=0;
		for (i=0;i<a[u].size();i++){
			v=a[u][i].Y;
			uv=a[u][i].X;
			if (d[v]>d[u]+uv){
				d[v]=d[u]+uv;
				if (!inqueue[v]){
					qu.push(v);
					inqueue[v]=1;
				}
			}
		}
	}
}
