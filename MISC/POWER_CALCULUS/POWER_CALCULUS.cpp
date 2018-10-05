/*
	POWER_CALCULUS
	uva 1374
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

int n,p[maxn];

bool DFSID(int dep,int step){
	if (dep>step) return false;
	if (p[dep]==n) return true;
	if (p[dep]<<(step-dep)<n) 
		return false;
	for (int i=0;i<=dep;++i){
		p[dep+1]=p[dep]+p[i];
		if (p[dep+1]<=10000 && DFSID(dep+1,step)) 
			return true;
		p[dep+1]=p[dep]-p[i];
		if (p[dep+1]>0 && DFSID(dep+1,step)) 
			return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin>>n && n){
		for (int i=0;;i++){
			p[0]=1;
			if (DFSID(0,i)){
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}
