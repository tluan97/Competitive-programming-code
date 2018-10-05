
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
