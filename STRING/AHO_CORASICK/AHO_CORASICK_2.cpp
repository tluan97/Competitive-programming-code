/*
	AHO_CORASICK
	http://www.spoj.com/problems/EMOTICON/
*/
/*
Dùng thuật toán Aho Corasick để giải bài toán sau.
Cho một số pattern và một xâu S. 
Một phép biến đổi là thay thế một kí tự 
	trong xâu S bằng một kí tự khác. 
Tìm cách biến đổi ít nhất để không có pattern nào 
	xuất hiện trong S như một xâu con liên tiếp. 
Biết rằng các pattern không chứa dấu cách 
	còn xâu S có thể có dấu cách.
khởi tạo trie: O(n) với n là tổng độ dài các pattern
duyệt trên trie: O(m) với m là độ dài của xâu S
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;

namespace trie {
    const int N = 2003;
    int a[N][128], Peak=0; //
    int Prev[N]; bool Leaf[N]; //
   
    void clear() {
        Peak=0;
        memset(a, 0, sizeof a);
        memset(Prev, 0, sizeof Prev);
        memset(Leaf, 0, sizeof Leaf);
    }
   
    void insert(char s[]) {
        int u=0;
        for (int i=0; char k=s[i]; i++) {
            if (!a[u][k]) a[u][k] = ++Peak;
            u=a[u][k];
        }
        Leaf[u]=true;
    }
   
    int next(int u, char k) {
        for (int i=u; i!=-1; i=Prev[i])
        if (a[i][k]) return a[i][k];
        return 0;
    }
   
    void bfs() {
        queue<int> qu;
        qu.push(0); Prev[0]=-1;
        while (qu.size()) {
            int u=qu.front(); qu.pop();
            for (int k=0; k<128; k++)
            if (int v=a[u][k]) {
                Prev[v] = next(Prev[u], k);
                Leaf[v] |= Leaf[Prev[v]];
                qu.push(v);
            }
        }
    }
};

int solve(char s[]) {
    using namespace trie;
    int u=0, Count=0;
    for (int i=0; s[i]; i++) {
        u = next(u, s[i]);
        if (Leaf[u]) { Count++; u=0; }
    }
    return Count;
}

void solve() {
    for (int i=1; i<=m; i++) {
        char s[123]; gets(s);
        trie :: insert(s);
    }
    trie :: bfs();
   
    int Sum = 0;
    for (int i=1; i<=n; i++) {
        char s[123]; gets(s);
        Sum += solve(s);
    }
    cout << Sum << endl;
}

void readln()
    { do {} while (getchar()!='\n'); }

main() {
    for (;;) {
        scanf("%d%d", &m, &n); readln();
        if (m==0 && n==0) return 0;
        solve();
        trie :: clear();
    }
}