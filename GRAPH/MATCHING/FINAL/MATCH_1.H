
const int maxn = 50010;
const int maxm = 150010;
struct match_1{
	int nx,ny,m,adj[maxm],next[maxm],last[maxn],
	matx[maxn],maty[maxn],que[maxn],level[maxn],run[maxn];
	
	void init(int _nx,int _ny){
		nx=_nx; ny=_ny; m=0;
		for (int i=1;i<=nx;i++)
			matx[i]=-1,last[i]=-1;
		for (int i=1;i<=ny;i++)
			maty[i]=-1;
	}
	void add(int u,int v){
		adj[m]=v; next[m]=last[u]; last[u]=m++;
	}
	bool bfs(){
		bool found=0;
		int size=0;
		for (int x=1;x<=nx;x++){
			if (matx[x]!=-1) level[x]=-1;
			else {
				level[x]=0;
				que[size++]=x;
			}
		}
		for (int i=0;i<size;i++){
			for (int x=que[i],e=last[x],y;e!=-1;e=next[e]){
				y=adj[e];
				if (maty[y]==-1) found=1;
				else if (level[maty[y]]==-1){
					level[maty[y]]=level[x]+1;
					que[size++]=maty[y];
				}
			}
		}
		return found;
	}
	int dfs(int x){
		for (int &e=run[x],y;e!=-1;e=next[e]){
			y=adj[e];
			if (maty[y]==-1 || 
				(level[maty[y]]==level[x]+1 && 
					dfs(maty[y]))){
				maty[y]=x;
				matx[x]=y;
				return 1;
			}
		}
		return 0;
	}
	int maxMatching(){
		int total=0;
		while (bfs()){
			for (int x=1;x<=nx;x++)
				run[x]=last[x];
			for (int x=1;x<=nx;x++)
				if (matx[x]==-1)
					total+=dfs(x);
		}
		return total;
	}
} match1;
void solve_match1(){
	int n,m,u,v,k;
	cin>>n>>m;
	match1.init(n,m);
	while (cin>>u>>v){
		match1.add(u,v);
	}
	cout<<match1.maxMatching()<<"\n";
	for (int x=1,y;x<=n;x++){
		y=match1.matx[x];
		if (y!=-1) 
			cout<<x<<" "<<y<<"\n";
	}
}
