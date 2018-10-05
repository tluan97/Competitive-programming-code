// http://uva.onlinejudge.org/external/105/10594.html

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//#define int long long

typedef pair<int, int> ii;
#define X first
#define Y second
bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }

// Network container
int n, m;
vector<ii> a[12309]; //
int c[123][123]; //
int f[123][123]; //

ii d[12309];
bool inqueue[12309];

bool fb(int start, int target){
    queue<int> qu;
    int u, i, v;
    
    for (i=1; i<=n; i++) { inqueue[i]=false; d[i].X=1000111000; }
    qu.push(start); inqueue[start]=true; d[start].X=0;
    
    while (qu.size()){
        u=qu.front(); qu.pop(); inqueue[u]=false;
        for (i=0; v=a[u][i].Y; i++)
        if (c[u][v] > f[u][v])
        if (minimize(d[v].X, d[u].X + (f[u][v]>=0 ? a[u][i].X : -a[u][i].X) )){
            d[v].Y=u;
            if (!inqueue[v]) 
            { qu.push(v); inqueue[v]=true; } 
        }
    }
    if (d[target].X < 1000111000) return true;
    else return false;
}

int enlarge(int start, int target, int delta, int &answer){
    int i;
    for (i=target; i!=start; i=d[i].Y)
    if (f[d[i].Y][i] < 0) 
    minimize(delta, - f[d[i].Y][i]);
    else
    minimize(delta, c[d[i].Y][i] - f[d[i].Y][i]);
    for (i=target; i!=start; i=d[i].Y){
        f[d[i].Y][i] += delta;
        f[i][d[i].Y] -= delta;
    }
    answer += delta * d[target].X;
    return delta;
}

main(){
    freopen("input", "r", stdin);
    int i, j, p, q, w;
    int r=0, capacity=0;
while (scanf("%d%d", &n, &m) > 0){
    for (i=1; i<=n; i++) a[i].clear();
    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    f[i][j]=c[i][j]=0;
    for (i=1; i<=m; i++){
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
        c[p][q] += 1;
        c[q][p] += 1;
    }
    for (i=1; i<=n; i++) a[i].push_back(ii());
    scanf("%d%d", &capacity, &p);
    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    c[i][j] *= p;
    
    r=0;
    while (fb(1, n))
    if (capacity == 0) break;
    else capacity -= enlarge(1, n, capacity, r);
    if (capacity != 0) printf("Impossible.\n");
    else printf("%d\n", r);
}
}