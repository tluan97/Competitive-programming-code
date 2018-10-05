/*
	MAX_FLOW_FASTEST
	tested
*/
#include <bits/stdc++.h>
using namespace std;

template<class Flow=int>
struct maxflow {
	struct Edge {
		int u,v;
		Flow c,f;
		int next;
	};
	int n,s,t;
	vector<Edge> e;
	vector<int> head,current,h,avail;
	vector<long long> excess;
	long long maxf;
	vector<int> id_e;
	vector<bool> id_v;
	int vertex,edge;
	
	maxflow(int n) : n(n),head(n,-1),current(n,-1),
		h(n),avail(n),excess(n){e.clear();}
	
	void addEdge(int u,int v,Flow c){
		Edge uv={u,v,c,0,head[u]};
		head[u]=e.size(); e.push_back(uv);
		Edge vu={v,u,c,0,head[v]};
		head[v]=e.size(); e.push_back(vu);
	}
	long long getMaxFlow(int _s,int _t){
		s=_s; t=_t; init();
		int now=0,cnt=0,x,p;
		bool need;
		queue<int> qu[2];
		for (int x=0;x<n;x++)
			if (x!=s && x!=t && excess[x]>0)
				qu[now].push(x);
		globalLabeling();
		while (!qu[now].empty()){
			while (!qu[1-now].empty())
				qu[1-now].pop();
			while (!qu[now].empty()){
				x=qu[now].front(); qu[now].pop();
				while (current[x]>=0){
					p=current[x];
					if (e[p].c>e[p].f && 
						h[e[p].u]>h[e[p].v]){
						need=(e[p].v!=s && 
							e[p].v!=t && 
							!excess[e[p].v]);
						push(current[x]);
						if (need) 
							qu[1-now].push(e[p].v);
						if (!excess[x]) break;
					}
					current[x]=e[current[x]].next;
				}
				if (excess[x]>0){
					lift(x);
					current[x]=head[x];
					qu[1-now].push(x);
					cnt++;
					if (cnt==n){
						globalLabeling();
						cnt=0;
					}
				}
			}
			now=1-now;
		}
		return maxf=excess[t];
	}
	void trace(){
		id_e.resize(0);
		id_v.resize(n,false);
		vertex=0; edge=0;
		for (int i=0;i<e.size();i++){
			if (e[i].f>0){
				id_e.push_back(i);
				id_v[e[i].u]=true;
				id_v[e[i].v]=true;
			}
		}
		edge=id_e.size();
		for (int i=0;i<n;i++)
			if (id_v[i])
				vertex++;
	}
	void getEdge(int i){
		cout<<e[i].u<<" "<<e[i].v
			<<" "<<e[i].f<<"\n";
	}
	
private:
	void init(){
		for (int i=0;i<n;i++)
			current[i]=head[i];
		int p=head[s];
		while (p>=0){
			e[p].f=e[p].c;
			e[p^1].f-=e[p].c;
			excess[e[p].v]+=e[p].c;
			excess[s]-=e[p].c;
			p=e[p].next;
		}
		for (int v=0;v<n;v++) h[v]=1;
		h[s]=n; h[t]=0;
	}
	void push(int i){
		long long delta=min(excess[e[i].u],
				(long long)e[i].c-e[i].f);
		e[i].f+=delta;
		e[i^1].f-=delta;
		excess[e[i].u]-=delta;
		excess[e[i].v]+=delta;
	}
	void lift(int u){
		int minH=n<<1;
		int p=head[u];
		while (p>=0){
			if (e[p].c>e[p].f)
				minH=min(minH,h[e[p].v]);
			p=e[p].next;
		}
		h[u]=minH+1;
	}
	void globalLabeling(){
		int x,p,pp;
		for (int i=0;i<n;i++)
			avail[i]=1, h[i]=0;
		h[s]=n; h[t]=0;
		queue<int> qu;
		qu.push(t); avail[t]=false;
		while (!qu.empty()){
			x=qu.front(); qu.pop();
			p=head[x];
			while (p>=0){
				pp=p^1;
				if (avail[e[pp].u] && 
					e[pp].f<e[pp].c){
					h[e[pp].u]=h[x]+1;
					avail[e[pp].u]=0;
					qu.push(e[pp].u);
				}
				p=e[p].next;
			}
			if (qu.empty() && avail[s]){
				avail[s]=false;
				qu.push(s);
			}
		}
		for (int x=0;x<n;x++)
			current[x]=head[x];
	}
};
/*
does not work with directed graph
index from 0, directed

maxflow<int> flow(n);
flow.addEdge(u,v,c);
flow.getMaxFlow(s,t);
*/

void flow_fastest(){
//	http://www.spoj.com/problems/FASTFLOW/
	freopen("MAX_FLOW_FASTEST.txt","r",stdin);
	int n,m,s,t;
	int u,v,c;
	cin>>n>>m;
	s=1; t=n;
	s--; t--;
	maxflow<int> basic(n);
	while (m--){
		cin>>u>>v>>c;
		--u; --v;
		basic.addEdge(u,v,c);
	}
	cout<<basic.getMaxFlow(s,t)<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	flow_fastest();
	
	return 0;
}
