// uva ???

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define long long long
#define in -1+2*
#define out 2*

void minimize(int &a, int b){ if (a>b) a=b; }
void minimize(long &a, long b){ if (a>b) a=b; }

int n, m;
vector<int> a[12309];
char b[12309];
long c[234][234];
long f[234][234];

int d[12309];
int bfs(){
    queue<int> qu;
    int u, i, v;
    
    for (i=1; i<=n; i++) 
    if (b[i]!='S') d[i]=0;
    else { d[i]=-1; qu.push(i); }
    
    while (qu.size()){
        u=qu.front(); qu.pop();
        //printf("%d\n", u);
        if (b[u]=='T') return u;
        for (i=0; v=a[u][i]; i++)
        if (d[v]==0 && c[u][v] > f[u][v]){
            d[v]=u;
            qu.push(v);
        }
    }
    return 0;
}

long enlarge(int t){
    //printf("enlarge(%d)\n", t);
    long delta = 1000111000111000111LL;
    int i;
    for (i=t; d[i]!=-1; i=d[i]) 
    minimize(delta, c[d[i]][i] - f[d[i]][i]);
    for (i=t; d[i]!=-1; i=d[i]){
        f[d[i]][i] += delta;
        f[i][d[i]] -= delta;        
    }
    return delta;    
}

main(){
    int p, q, w, i, j; long r;
while (scanf("%d", &n) > 0){
    for (i=1; i<=n; i++) { 
        a[in i].clear(); a[out i].clear(); 
        b[in i] = b[out i] = 0;
    }
    for (i=1; i<=2*n; i++)
    for (j=1; j<=2*n; j++)
    c[i][j]=f[i][j]=0;
    
    for (i=1; i<=n; i++){
        scanf("%d", &p);
        a[in i].push_back(out i);
        a[out i].push_back(in i);
        c[in i][out i] = p;
    }
    scanf("%d", &m);
    for (i=1; i<=m; i++){
        scanf("%d%d%d", &p, &q, &w);
        a[out p].push_back(in q);
        a[in q].push_back(out p);
        c[out p][in q] += w;
    }
    int ns, nt;
    scanf("%d%d", &ns, &nt);
    for (i=1; i<=ns; i++) { scanf("%d", &p); b[in p]='S'; }
    for (i=1; i<=nt; i++) { scanf("%d", &p); b[out p]='T'; }
    n=n*2;
    for (i=1; i<=n; i++) a[i].push_back(0);
    
    r=0;
    while (i=bfs()) r += enlarge(i);    
    printf("%lld\n", r);
}
}