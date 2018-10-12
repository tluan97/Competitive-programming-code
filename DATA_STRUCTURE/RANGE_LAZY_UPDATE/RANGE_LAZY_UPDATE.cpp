/*
	RANGE_LAZY_UPDATE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;

struct RangeLazyUpdate {
	int n,a[maxn];
	int lazy[maxn];
	
	RangeLazyUpdate(int n): n(n) {}
	
	void set(int i, int k){
		a[i]=k;
	}
	void update(int u, int v, int k){
		lazy[u]+=k;
		lazy[v+1]-=k;
	}
	void update(){
		for (int i=1;i<=n+1;i++){
			lazy[i]+=lazy[i-1];
			a[i]+=lazy[i];
			lazy[i-1]=0;
		}
	}
	int getMax(int u, int v){
		int j = u;
		for (int i=u;i<=v;i++){
			if (a[j]<a[i]) j=i;
		}
		return a[j];
	}
	void print(){
		for (int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}	cout<<"\n\n";
	}
};

void testRangeLazyUpdate(){
	RangeLazyUpdate RLU(5);
	RLU.update(3,3,1);
	RLU.update(4,5,2);
	RLU.update(2,4,1);
	RLU.update(); RLU.print();
	int u,v;
	while (cin>>u>>v){
		cout<<RLU.getMax(u,v)<<"\n";
	}
}
int main(){
	testRangeLazyUpdate();
}
