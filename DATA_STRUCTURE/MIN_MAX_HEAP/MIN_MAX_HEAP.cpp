/*
	MIN_MAX_HEAP
	https://vn.spoj.com/problems/MSE07B/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
#define X first
#define Y second

const int maxn = 100010;

inline int level(int u){
	for (int i=1; u&u+1; i+=i) u|=(u>>i);
	return __builtin_popcount(u);
}
struct min_max_heap {
	II T[maxn];
	int n;
	
	bool adjacent_exchange(int u, int v){
		if (T[u]<T[v] xor level(u)&1)
			swap(T[u], T[v]);
		else return false;
		return true;	
	}
	bool discrete_exchange(int u, int v){
		if (T[u]>T[v] xor level(u)&1)
			swap(T[u], T[v]);
		else return false;
		return true;
	}
	bool exchange(int u, int v){
		if (u<1 || u>n || v<1 || v>n || T[u]==T[v])
			return false;
		int x = level(u), y = level(v);
		if (abs(x-y)>2 || x==y) {
			printf("Fatal\n");
			return false;
		}
		if (x&1 xor y&1)
			return adjacent_exchange(u, v);
		else return discrete_exchange(u, v);
	}
	int potential(int u){
		int v, r=0;
		for (v=u*4; v<=u*4+3 && v<=n; v++)
		if ((T[v]>=T[r] xor level(u)&1) || r==0)
			r=v;
		// Very important
		for (v=u*2; v<=u*2+1 && v<=n; v++) 
		if ((T[v]>=T[r] xor level(u)&1) || r==0)
			r=v;
		return r;
	}
	void push(II x){
		int u = ++n;
		T[u] = x;
		if (exchange(u, u/2)) u=u/2;
		while (exchange(u, u/4)) u=u/4;
	}
	void pop(int u){
		if (u==0 || n==0) return;
		T[u]=T[n--];
		int v = potential(u);
		while (exchange(v, u)){
			// Very important
			exchange(v, v/2);
			u=v; v=potential(u);
		}
		exchange(u*2, u);
		exchange(u*2+1, u);
	}
	int i_back(){
		int r=0;
		for (int i=1; i<=n && i<=3; i++)
		if (T[i]>T[r] || r==0) r=i;
		return r;
	}
	II front(){ return T[1]; }
	II back(){ return T[i_back()]; }
	void pop_front(){ pop(1); }
	void pop_back(){ pop(i_back()); }
	void show(){
		int i;
		for (i=1; i<=n; i++){
			for (int j=1<<5-level(i); j>=3; j--)
				printf(" ");
			if (i&i+1) printf(" %d", T[i]);
			else printf(" %d\n", T[i]);
		}
	}
};

void test_1(){
	min_max_heap s;
	int n,k,p; II t;
	while (cin>>n && n){
		if (n==1){
			cin>>k>>p;
			s.push(II(p,k));
		} else {
			if (s.n==0) cout<<"0\n";
			else {
				if (n==2){
					t=s.back();
					cout<<t.Y<<"\n";
					s.pop_back();
				} else {
					t=s.front();
					cout<<t.Y<<"\n";
					s.pop_front();
				}
			}
		}
	}
}
void test_2(){
	set<II> s;
	int n,k,p; II t;
	while (cin>>n && n){
		if (n==1){
			cin>>k>>p;
			s.insert(II(p,k));
		} else {
			if (s.empty()) cout<<"0\n";
			else {
				if (n==2) t=(*--s.end());
				else t=(*s.begin());
				cout<<t.Y<<"\n";
				s.erase(t);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	test_1(); // WA
	test_2(); // AC
	return 0;
}
