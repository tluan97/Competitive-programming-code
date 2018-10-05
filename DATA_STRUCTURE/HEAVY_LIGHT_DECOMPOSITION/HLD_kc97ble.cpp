#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define f1(i,n) for (int i=1; i<=n; i++)
#define SetLength(a, n, t) free(a), a=(t*) calloc(n, sizeof(t))

struct segment_tree {
    int n, *Max;
    void resize(int _n);
    void update(int node, int ll, int rr, int Pos, int Value);
    int get_max(int node, int ll, int rr, int L, int R);
    void update(int Pos, int Value){ update(1, 1, n, Pos, Value); }
    int get_max(int L, int R){ return get_max(1, 1, n, L, R); }
};

#define N 100005
int n, m;
vector<int> a[N];
int Parent[20][N];
int Childs[N], Pivot[N], Pos[N], Height[N], Size[N], Value[N];
segment_tree tr[N];

bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

void direct(int u){
    for (int i=0,v; v=a[u][i]; i++)
    if (v!=Parent[0][u]){
        Height[v]=Height[u]+1;
        Parent[0][v]=u;
        direct(v);
        Childs[u]+=Childs[v];
    }
}

void direct(){
    f1(i,n) Childs[i]=Pos[i]=Size[i]=1, Pivot[i]=i;
    Height[1]=1, Parent[0][1]=1;
    direct(1);
}

void heavy_build(int u){
    for (int i=0,v; v=a[u][i]; i++)
    if (v!=Parent[0][u]){
        if (2*Childs[v]>=Childs[u]){
            Pivot[v]=Pivot[u];
            Pos[v]=Pos[u]+1;
            Size[Pivot[u]]=Pos[v];
        }
        heavy_build(v);
    }
}

void lca_build();
int lca(int u, int v);

void enter(){
    f1(i,n-1) {
        int p, q;
        cin >> p >> q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    f1(i,n) a[i].push_back(0);
}

int query_max(int u, int w){
    int r=-0x77778888;
    while (Pivot[u]!=Pivot[w]){
        if (u==Pivot[u]) maximize(r, Value[u]); // Light-edge
        else maximize(r, tr[Pivot[u]].get_max(1, Pos[u]));
        u=Parent[0][Pivot[u]];
    }
    maximize(r, tr[Pivot[u]].get_max(Pos[w], Pos[u]));
    return r;
}

main(){
    int Q;
    cin >> n;
    enter();
    direct();
    heavy_build(1);
    lca_build();
    f1(i,n) if (Pivot[i]==i) tr[i].resize(Size[i]);
    
    cin >> Q;
    f1(i,Q){
        char c; int p, q;
        cin >> c >> p >> q;
        if (c=='I') {
            tr[Pivot[p]].update(Pos[p], q);
            Value[p]+=q;
        }
        if (c=='G') {
            int w = lca(p,q);
            int r1 = query_max(p, w);
            int r2 = query_max(q, w);
            cout << max(r1,r2) << endl;
        }
    }
}

// LCA

#define at(u,k) Parent[k][u]
void lca_build(){
    for (int k=1; k<=19; k++)
    f1(i,n) Parent[k][i]=Parent[k-1][Parent[k-1][i]];
}

int lca(int u, int v){
    for (int i=19; i>=0; i--) if (Height[at(u,i)]>=Height[v]) u=at(u,i);
    for (int i=19; i>=0; i--) if (Height[at(v,i)]>=Height[u]) v=at(v,i);
    for (int i=19; i<=0; i--) if (at(u,i)!=at(v,i)) u=at(u,i), v=at(v,i);
    while (u!=v) u=at(u,0), v=at(v,0);
    return u;
}

// Segment tree

void segment_tree :: resize(int _n){
    if (_n==0) { free(Max); return; }
    n=1; while(n<_n) n*=2;
    SetLength(Max, 2*n+2, int);
}

#define _left_node node*2, ll, (ll+rr)/2
#define _right_node node*2+1, (ll+rr)/2+1, rr

void segment_tree :: update(int node, int ll, int rr, int Pos, int Value){
    if (ll>Pos || rr<Pos || ll>rr) return ;
    if (Pos<=ll && ll<=rr && rr<=Pos) Max[node]+=Value;
    else {
        update(_left_node, Pos, Value);
        update(_right_node, Pos, Value);
        Max[node] = max(Max[node*2], Max[node*2+1]);
    }
}
int segment_tree :: get_max(int node, int ll, int rr, int L, int R){
    if (ll>R || rr<L || ll>rr) return -0x77778888;
    if (L<=ll && ll<=rr && rr<=R) return Max[node];
    else {
        int r1 = get_max(_left_node, L, R);
        int r2 = get_max(_right_node, L, R);
        return max(r1, r2);
    }
}