
template <class type>
struct matrix {
	vector<vector<type> > f;
	int m,n;
	matrix(int m=0,int n=0) : m(m), n(n) {
		f.resize(m);
		for (int i=0;i<m;i++){
			f[i].resize(n);
			for (int j=0;j<n;j++){
				f[i][j]=0;
			}
		}
	}
	void operator = (const matrix &a);
	void print(){
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				cout<<f[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
};
template<class type>
matrix<type> identity(int n){
	matrix<type> i(n,n);
	for (int j=0;j<n;j++)
		i.f[j][j]=1;
	return i;
}
template<class type>
matrix<type> operator * (
		const matrix<type> &a, 
		const matrix<type> &b){
	matrix<type> c(a.m,b.n);
	for (int i=0;i<c.m;i++)
	for (int j=0;j<c.n;j++)
	for (int k=0;k<a.n;k++)
		c.f[i][j]=(c.f[i][j]+
			a.f[i][k]*b.f[k][j])%mod;
	return c;
}
template<class type>
matrix<type> operator ^ (
		const matrix<type> &a, int k){
	if (k==0) return identity<type>(a.n);
	if (k==1) return a;
	matrix<type> t=a^(k/2);
	t=t*t;
	if (k&1) t=t*a;
	return t;
}
template<class type> 
void matrix<type> :: operator = (
		const matrix<type> &a){
	m=a.m; n=a.n;
	for (int i=0;i<m;i++)
	for (int j=0;j<n;j++)
		f[i][j]=a.f[i][j];
}
