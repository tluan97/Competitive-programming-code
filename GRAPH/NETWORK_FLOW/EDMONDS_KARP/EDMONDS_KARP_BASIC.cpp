#include <stdio.h>
#include <queue>
using namespace std;

#define long long long
void minimize(long &a, long b){ if (a>b) a=b; }

int n, m, source, target;
vector<int> a[12309];
long c[2309][2309];
long f[2309][2309];
long d[12309];
const long oo = 1000111000111000;

bool findpath(int start, int target){
    queue<int> qu;
    int i, u, v;
    for (i=1; i<=n; i++) d[i]=0;
    d[start] = oo;
    qu.push(start);

    while (qu.size()){
        u=qu.front(); qu.pop();
        //printf("u=%d\n", u);
        if (u==target) return true;
        for (i=0; v=a[u][i]; i++)
        if (d[v]==0 && c[u][v] > f[u][v]){
            d[v]=u;
            qu.push(v);
        }
    }
    return false;
}

void enlarge(){
    long u, v, delta=oo;
    for (v=target; (u=d[v])!=oo; v=u)
    minimize(delta, c[u][v] - f[u][v]);
    for (v=target; v!=source; v=u){
        u=d[v];
        f[u][v] += delta;
        f[v][u] -= delta;
    }
}

long answer(int u){
    int i, v;
    long r=0;
    for (i=0; v=a[u][i]; i++)
    r += f[u][v];
    return r;
}

main(){
    int i, p, q; long w;
    scanf("%d%d", &n, &m);
    source=1; target=n;
    for (i=1; i<=m; i++){
        scanf("%d%d%lld", &p, &q, &w);
        a[p].push_back(q);
        a[q].push_back(p);
        c[p][q]=w;
    }
    for (i=1; i<=n; i++) a[i].push_back(0);
    while (findpath(source, target)) enlarge();

    printf("%lld\n", answer(source));
}
