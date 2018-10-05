
struct DSU {
	int par[maxn];
	void init(int n){
		for (int i=0;i<=n;i++)
			par[i]=i;
	}
	int anc(int p){
		if (par[p]==p) return p;
		return par[p]=anc(par[p]);
	}
	void join(int p,int q){
		par[anc(p)]=anc(q);
	}
};
