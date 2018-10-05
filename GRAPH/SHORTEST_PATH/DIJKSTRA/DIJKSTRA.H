
struct dijkstra {
	int d[maxn];		// distance
	int p[maxn];		// trace
	long long b[maxn];	// count num of path
	int dij(int s){
		priority_queue<II,vector<II>,greater<II> > pq;
		int i,u,v,du,uv;
		for (i=1;i<=n;i++){
			d[i]=oo; p[i]=0; b[i]=0;
		}
		d[s]=0; p[s]=s; b[s]=1;
		pq.push(II(d[s],s));
		while (pq.size()){
			u=pq.top().Y;
			du=pq.top().X;
			pq.pop();
			if (du!=d[u]) continue;
			for (i=0;i<a[u].size();i++){
				v=a[u][i].Y;
				uv=a[u][i].X;
				if (d[v]>du+uv){
					d[v]=du+uv;
					p[v]=u;
					b[v]=b[u];
					pq.push(II(d[v],v));
				} else if (d[v]==du+uv){
					b[v]+=b[u];
				}
			}
		}
	}
};
