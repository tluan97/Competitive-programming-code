
int n,m;
int d[maxn][maxn];
int p[maxn][maxn];
void initFloyd(int n){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		d[i][j]=oo;
		p[i][j]=0;
	}
	for (int i=1;i<=n;i++){
		d[i][i]=0;
		p[i][i]=i;
	}
}
void floyd(){
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (d[i][j]>d[i][k]+d[k][j]){
		d[i][j]=d[i][k]+d[k][j];
		p[i][j]=p[i][k];
	}
}
int getd(int s,int t){
	return d[s][t];
}
vector<int> getp(int s,int t){
	vector<int> r;
	do {
		r.push_back(s);
		s=p[s][t];
	} while (s!=t);
	r.push_back(s);
	return r;
}
