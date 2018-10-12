
int n,a[maxn];
void combination(int pos){
	if (pos==n+1){
		debug(a,n);
		return;
	}
	a[pos]=0;combination(pos+1);
	a[pos]=1;combination(pos+1);
}
