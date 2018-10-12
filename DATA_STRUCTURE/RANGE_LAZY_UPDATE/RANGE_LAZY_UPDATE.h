
struct RangeLazyUpdate {
	int n,a[maxn];
	int lazy[maxn];
	
	RangeLazyUpdate(int n): n(n) {}
	
	void set(int i, int k){
		a[i]=k;
	}
	void update(int u, int v, int k){
		lazy[u]+=k;
		lazy[v+1]-=k;
	}
	void update(){
		for (int i=1;i<=n+1;i++){
			lazy[i]+=lazy[i-1];
			a[i]+=lazy[i];
			lazy[i-1]=0;
		}
	}
	int getMax(int u, int v){
		int j = u;
		for (int i=u;i<=v;i++){
			if (a[j]<a[i]) j=i;
		}
		return a[j];
	}
	void print(){
		for (int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}	cout<<"\n\n";
	}
};
