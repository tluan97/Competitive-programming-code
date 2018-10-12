
struct DSU{
	int par[maxn];
	int mem[maxn];
	void init(){
		for (int i=0;i<maxn;i++){
			par[i]=i;
			mem[i]=1;
		}
	}
	int anc(int p){
		if (par[p]==p) return p;
		return par[p]=anc(par[p]);
	}
	void join(int p,int q){
		if (anc(p)!=anc(q)){
			int p1=mem[anc(p)];
			int p2=mem[anc(q)];
			par[anc(p)]=anc(q);
			mem[anc(p)]=p1+p2;
		}
	}
	int member(int p){
		return mem[anc(p)];
	}
};
