
int n,a[maxn],f[maxn];
void sumArray(int n, int a[maxn], int f[maxn]){
	for (int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
}
int getSum(int u,int v){
	return f[v]-f[u-1];
}
