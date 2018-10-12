/*
	IT_PERSISTENT
	???
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5+10;

int m, n, a[maxn], l[maxn], Root[maxn], Peak=0;
int Sum[80*maxn], Left[80*maxn], Right[80*maxn];
// (n*4)+(n log n)
int create(int n){
	if (n==1){
		++Peak;
		Sum[Peak]=0;
		return Peak;
	}
	int u = ++Peak;
	Left[u]=create(n-n/2);
	Right[u]=create(n/2);
	return u;
}
struct node {
	int ll, rr, id;
	
	node(int L, int R, int X)
		{ ll=L, rr=R, id=X; }
	node left()
		{ return node(ll, (ll+rr)/2, Left[id]); }
	node right()
		{ return node((ll+rr)/2+1, rr, Right[id]); }
	
	int update(int U, int X){
		if (ll>U || U>rr) return id;
		if (ll==rr) { Sum[++Peak]=X; return Peak; }
		int u = ++Peak;
		Left[u] = left().update(U, X);
		Right[u] = right().update(U, X);
		Sum[u]=Sum[Left[u]]+Sum[Right[u]];
		return u;
	}
	int sum_range(int L, int R){
		if (L>rr || ll>R || L>R) return 0;
		if (L<=ll && rr<=R) return Sum[id];
		int Sum1 = left().sum_range(L, R);
		int Sum2 = right().sum_range(L, R);
		return Sum1 + Sum2;
	}
};
bool as_a(int x, int y)
	{ return a[x]<a[y]; }

void test_(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		l[i]=i;
	sort(l+1, l+n+1, as_a);
	Root[0]=create(n);
	for (int i=1;i<=n;i++){
		Root[i]=node(1,n,Root[i-1]).update(l[i], 1);
//		cout<<"\n"<<Peak<<" "<<80*maxn<<"\n";
	}
	for (int i=1;i<=m;i++){
		int x,y,z; cin>>x>>y>>x;
		int ll=1,rr=n,mm=(ll+rr)/2;
		while (ll!=rr){
			if (node(1,n,Root[mm]).sum_range(x,y)>=z)
				rr=mm;
			else ll=mm+1;
			mm=(ll+rr)/2;
		}
		cout<<a[l[mm]]<<"\n";
	}
}
int main(){
	test_();
	return 0;
}
