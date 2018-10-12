/*
	DSU
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int par[maxn];
void initDSU(){
	for (int i=1;i<maxn;i++){
		par[i]=i;
	}
}
int anc(int p){
	if (par[p]==p) return p;
	return par[p]=anc(par[p]);
}
void join(int p,int q){
	par[anc(p)]=anc(q);
}

void test(){
	initDSU();
	join(1,4);
	join(1,2);
	if (anc(2)!=anc(4)){
		cout<<"error\n";
	}
}
int main()
{
	test();
	return 0;
}
