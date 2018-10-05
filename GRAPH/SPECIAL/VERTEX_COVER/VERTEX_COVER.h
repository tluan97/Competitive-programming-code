
struct vertex_cover{
	int n,m;
	vector<int> a[maxn];
	bool choosed[maxn];
	
	void init(int _n,int _m){
		n=_n; m=_m;
		for (int i=1;i<=n;i++){
			a[i].clear();
			choosed[i]=0;
		}
		match1.init(n,m);
	}
	void add(int u,int v){
		a[u].push_back(v);
		match1.add(u,v);
	}
	void konig(int u){
		choosed[u]=1;
		for (int i=0,v,x;i<a[u].size();i++){
			v=a[u][i];x=match1.maty[v];
			if (x!=-1 && x!=oo){
				match1.maty[v]=oo;
				if (!choosed[x]) konig(x);
			}
		}
	}
	void solve(){
		cout<<match1.maxMatching();
		for (int i=1;i<=n;i++)
			if (match1.matx[i]==-1)
				konig(i);
		for (int i=1;i<=n;i++)
			if (match1.matx[i]!=-1 && !choosed[i])
				cout<<" r"<<i;
		for (int j=1;j<=m;j++)
			if (match1.maty[j]==oo)
				cout<<" c"<<j;
		cout<<"\n";
	}
} cover;
