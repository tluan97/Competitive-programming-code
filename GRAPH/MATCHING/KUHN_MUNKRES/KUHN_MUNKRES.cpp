#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1003
#define f1(i,n) for (int i=1; i<=n; i++)
#define f2(i,a,u) for (int i=0,u; u=a[i]; i++)
int n;
int c[N][N];
int f[N], d[N], Decision[N];
int Assigned[N], Visited[N];
vector<int> Left, Right;
queue<int> qu;

bool assignable(int &a, int b){ if (a==0) a=b; else return false; return true; }
bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }
bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

int bfs_next(){
    while (qu.size()){
        int u=qu.front(); qu.pop();
        f2(i,Right,v){
            if (c[u][v]+f[u]+f[v]==0)
            if (assignable(Visited[v], u)){
                if (!Assigned[v]) return v;
                Visited[Assigned[v]]=v;
                qu.push(Assigned[v]);
            }
            if (minimize(d[v], c[u][v]+f[u]+f[v])) Decision[v]=u;
        }
    }
    return 0;
}

int bfs_first(int Start){
    while (qu.size()) qu.pop();
    f1(i,2*n) Visited[i]=0;
    f2(i,Right,u) { d[u]=c[Start][u]+f[Start]+f[u]; Decision[u]=Start; }
    Visited[Start]=-1, qu.push(Start);
    return bfs_next();
}

bool adjust(){
    int Delta=0x11112222;
    f2(i,Right,u) if (!Visited[u]) minimize(Delta, d[u]);
    if (Delta >= 0x11112222) return false;
    assert(Delta != 0);
    f2(i,Left,u) if (Visited[u]) f[u]-=Delta;
    f2(i,Right,u) if (Visited[u]) f[u]+=Delta;
    
    f2(i,Right,u)
    if (!Visited[u]) { d[u]-=Delta; if (d[u]==0) qu.push(Decision[u]); }
    return true;
}

void enlarge(int u){
    while (u>0){
        int y=u, x=Visited[y];
        u=Assigned[x];
        Assigned[x]=y;
        Assigned[y]=x;
    }
}

map<int, int> Map[N];

int force(int Pos, int Used){
    int Answer=0x11112222;
    if (Pos==n+1) return 0;
    if (Map[Pos].count(Used)) return Map[Pos][Used];
    for (int i=1; i<=n; i++)
    if ((1<<i-1) & ~Used)
    minimize(Answer, force(Pos+1, Used|(1<<i-1))+c[Pos][i+n]);
    return Map[Pos][Used]=Answer;
}

main(){
    cin >> n;
    srand(n*1000);
    f1(i,n) f1(j,n) {
        //cin >> c[i][j+n];
        c[i][j+n]=rand()%100*10;
        cout << c[i][j+n] << (j==n?"\n":" ");
    }
    
    f1(i,n) Left.push_back(i); Left.push_back(0);
    f1(i,n) Right.push_back(i+n); Right.push_back(0);

    f2(i,Left,u) {
        int x=bfs_first(u);
        while (x==0){
            if (!adjust()) break;
            else x=bfs_next();
        }
        enlarge(x);
    }
    int Answer=0;
    f1(i,n) Answer += c[i][Assigned[i]];
    cout << Answer << endl;
    cout << force(1,0) << endl;
    cin.ignore(2);
}
