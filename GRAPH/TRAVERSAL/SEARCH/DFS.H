
void dfs(int u){
	d[u]=++t;
	for (int i=0,v;v=a[u][i];i++){
		if (!d[v]){
			p[v]=u;
			dfs(v);
		}
	}
}
