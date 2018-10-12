
int n,m;
vector<int> a[maxn];
bool cutnode[maxn]; // critical node
VII bridge;			// critical edge
int _cutnode,_bridge;
int num[maxn],low[maxn],cnt=0;

void visit(int u,int p){
	int num_child=0,v;
	num[u]=low[u]=++cnt;
	for (int i=0;i<a[u].size();i++){
		v=a[u][i];
		if (v!=p){
			if (num[v])
				low[u]=min(low[u],num[v]);
			else {
				visit(v,u);
				num_child++;
				low[u]=min(low[u],low[v]);
				if (low[v]>=num[v]){
					bridge.push_back(II(u,v));
				}
				if (u==p){
					if (num_child>=2)
						cutnode[u]=1;
				} else {
					if (low[v]>=num[u])
						cutnode[u]=1;
				}
			}
		}
	}
}
void input(){
	cin>>n>>m;int u,v;
	for (int i=1;i<=m;i++){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}
void solve(){
	for (int i=1;i<=n;i++)
		if (!num[i])
			visit(i,i);
}
void output(){
	for (int i=1;i<=n;i++)
		if (cutnode[i]){
//			cout<<i<<"\n";
			_cutnode++;
		}
	_bridge=bridge.size();
//	for (int i=0;i<_bridge;i++)
//		cout<<bridge[i].first<<" "
//			<<bridge[i].second<<"\n";
	cout<<_cutnode<<" "<<_bridge<<"\n";
}
