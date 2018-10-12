
LL m[maxl];
void initHash(){
	m[0]=1LL;
	for (int i=1;i<maxl;i++){
		m[i]=(m[i-1]*base)%mod;
	}
}
void buildHash(string s,LL h[maxl]){
	int l=s.size();h[0]=0;
	for (int i=1;i<l;i++){
		h[i]=(h[i-1]*base+1LL*s[i])%mod;
	}
}
LL getHash(LL h[maxl],int l,int r){
	return (h[r]-h[l-1]*m[r-l+1]+1LL*mod*mod)%mod;
}
