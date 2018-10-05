/*
	BIT_2D
	https://www.spoj.com/problems/MATSUM/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1025;

template<class type=int>
struct fenwickTree {
	int m,n;
	type T[maxn][maxn]={};
	fenwickTree(int mm,int nn){
		m=mm; n=nn;
	}
	void init(int mm,int nn){
		m=mm; n=nn;
		memset(T,0,sizeof(T));
	}
	void update(int p,int q,type val){
		for (int i=p;i<=m;i+=i&-i)
		for (int j=q;j<=n;j+=j&-j)
			T[i][j]+=val;
	}
	type query(int p,int q){
		type r=0;
		for (int i=p;i>=1;i-=i&-i)
		for (int j=q;j>=1;j-=j&-j)
			r+=T[i][j];
		return r;
	}
	type query(int p,int q,int pp,int qq){
		return query(pp,qq)
			-query(pp,q-1)
			-query(p-1,qq)
			+query(p-1,q-1);
	}
};

void test_(){
	int m,n,c,u,v,uu,vv,w; 
	cin>>m>>n;
	fenwickTree<int> bit(m,n);
	while (cin>>c){
		if (c==0){
			cin>>u>>v>>w;
			bit.update(u,v,w);
		} else if (c==1){
			cin>>u>>v;
			cout<<bit.query(u,v)<<"\n";
		} else if (c==2){
			cin>>u>>v>>uu>>vv;
			cout<<bit.query(u,v,uu,vv)<<"\n";
		}
	}
}
fenwickTree<int> bit(0,0);
void MATSUM(){
	string s; int n,u,v,uu,vv,val,valold;
	int test; cin>>test;
	while (test--){
		cin>>n;
		bit.init(n,n);
		while (cin>>s && s!="END"){
			if (s=="SET"){
				cin>>u>>v>>val;
				u++; v++;
				valold=bit.query(u,v,u,v);
				bit.update(u,v,val-valold);
			} else if (s=="SUM"){
				cin>>u>>v>>uu>>vv;
				u++; v++; uu++; vv++;
				cout<<bit.query(u,v,uu,vv)<<"\n";
			}
			
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	test_();
	MATSUM();
	return 0;
}
