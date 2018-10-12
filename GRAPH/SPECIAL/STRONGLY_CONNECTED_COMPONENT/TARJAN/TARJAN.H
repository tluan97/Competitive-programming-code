
int n,m;
int num[maxn],low[maxn],cnt=0;
vector<int> a[maxn];
stack<int> st;
int scc=0;

void visit(int u){
	num[u]=low[u]=++cnt;
	st.push(u);
	int v;
	for (int i=0;i<a[u].size();i++){
		v=a[u][i];
		if (num[v])
			low[u]=min(low[u],num[v]);
		else {
			visit(v);
			low[u]=min(low[u],low[v]);
		}
	}
	if (num[u]==low[u]){
		scc++;
		do {
			v=st.top(); st.pop();
			num[v]=low[v]=oo; //TJAlG
//			num[v]=low[v]=-oo; //MESSAGE
		} while (v!=u);
	}
}
void input(){
	cin>>n>>m;
	int u,v;
	for (int i=1;i<=m;i++){
		cin>>u>>v;
		a[u].push_back(v); //TJAlG
//		a[v].push_back(u); //MESSAGE
	}
}
void solve(){
	for (int i=1;i<=n;i++)
		if (!num[i])
			visit(i);
}
void output(){
	cout<<scc<<"\n";
}
