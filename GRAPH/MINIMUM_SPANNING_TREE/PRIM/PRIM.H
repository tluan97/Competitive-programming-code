
int n,m;
vector<II> a[maxn];
int d[maxn];
int prim(int s){
	priority_queue<II> pq;
	int i,u,v,du,uv,res=0;
	for (i=1;i<=n;i++) d[i]=oo;
	d[s]=0;
	pq.push(II(0,s));
	while (pq.size()){
		u=pq.top().Y;
		du=-pq.top().X;
		pq.pop();
		if (du!=d[u]) continue;
		res+=d[u]; d[u]=0;
		for (i=0;i<a[u].size();i++){
			v=a[u][i].Y;
			uv=a[u][i].X;
			if (d[v]>uv){
				d[v]=uv;
				pq.push(II(-d[v],v));
			}
		}
	}
	return res;
}
