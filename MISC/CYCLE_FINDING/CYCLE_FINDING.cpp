/*
	CYCLE_FINDING
	UVA 350
*/
#include <bits/stdc++.h>
using namespace std;

int a,b,m,x;
int ans;

int f(int x){
	return (a*x+b)%m;
}
void solve(){
	int tortoise=f(x), hare=f(f(x));
	while (tortoise!=hare){
		tortoise=f(tortoise);
		hare=f(f(hare));
	}
	int mu=0; hare=x;
	while (tortoise!=hare){
		tortoise=f(tortoise);
		hare=f(hare);
		mu++;
	}
	int lambda=1; hare=f(tortoise);
	while (tortoise!=hare){
		hare=f(hare);
		lambda++;
	}
	ans=lambda;
//	cout<<mu<<" "<<lambda<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test=1;
	while (cin>>a>>b>>m>>x && a|b|m|x){
		solve();
		cout<<"Case "<<test++<<": "<<ans<<"\n";
	}
	return 0;
}

