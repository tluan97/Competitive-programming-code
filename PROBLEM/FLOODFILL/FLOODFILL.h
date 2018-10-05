
int dr[]={0,0,1,0,-1,-1,1,1,-1};
int dc[]={0,1,0,-1,0,1,1,-1,-1};
int f[maxn][maxn],m,n;

bool check(int x,int y){
	if (x<1 || m<x || y<1 || n<y || f[x][y])
		return false; return true;
}
int floodfill_dfs(int x,int y){
	if (!check(x,y)) return 0;
	int ans=1; f[x][y]=1;
	for (int i=1;i<=4;i++){
		ans+=floodfill_dfs(x+dr[i],y+dc[i]);
	}
	return f[x][y]=ans;
}
void floodfill_bfs(int x,int y){
	II ii;int t=0;
	queue<II> q;
	f[x][y]=++t;q.push(II(x,y));
	while (q.size()){
		ii=q.front();q.pop();
		for (int i=1;i<=8;i++){
			x=ii.X+dr[i];
			y=ii.Y+dc[i];
			if (!check(x,y)) continue;
			f[x][y]=++t;
			q.push(II(x,y));
		}
	}
}
