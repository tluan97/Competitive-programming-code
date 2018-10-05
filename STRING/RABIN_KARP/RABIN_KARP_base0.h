
struct HashString{
	
	LL m[maxl];
	vector<LL> h[maxn];
	vector<string> a;
	int n;
	
	void init(){
		m[0]=1LL;
		for (int i=1;i<maxl;i++){
			m[i]=(m[i-1]*base)%mod;
		}
	}
	void addString(string s){
		a.push_back(" "+s);
		n++;
	}
	void buildHash(int i){
		int l=a[i].size();
		h[i].resize(l+1,0);
		for (int j=1;j<l;j++){
			h[i][j]=(h[i][j-1]*base+1LL*a[i][j])%mod;
		}
	}
	LL getHash(int i,int l,int r){
		l++; r++;
		return (h[i][r]-h[i][l-1]*m[r-l+1]+1LL*mod*mod)%mod;
	}
	
}hash;
