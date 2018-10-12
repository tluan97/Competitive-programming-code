
void debug(int n){
	cout<<n<<"\n-----\n";
}
void debug (II ii){
	cout<<ii.X<<" "<<ii.Y<<"\n-----\n";
}
void debug(int a[maxn],int n){
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}	cout<<"\n-----\n";
}
void debug(int a[maxn][maxn],int m,int n){
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}	cout<<"\n";
	}	cout<<"\n-----\n";
}
