/*
	LOCAL_SEARCH
	http://vn.spoj.com/problems/POST/
*/
#include <bits/stdc++.h>
using namespace std;

const int _time = 1;
const double _start = 1000000;
const double _delta = 0.9;
const double eps = 1e-6;

double a,b,f,s;
double adapt(double l){
	return fabs(a+b-l);
}
void init(){
	s=rand();
}
void search(){
	double d=_start;
	while (d>eps){
		(adapt(s+d)<adapt(s-d))
			?s+=d:s-=d;
		d*=_delta;
	}
}
void solve(){
	if (adapt(s)<adapt(f))
		f=s;
}
int local_search(){
	srand(time(NULL));
	int t=_time;
	f=rand();
	while (t--){
		init();
		search();
		solve();
		if (adapt(f)<eps) break;
	}
	return round(f);
}

void test(){
	freopen("test.txt","r",stdin);
	int t,r,k;cin>>t;
	while (t--){
		cin>>a>>b>>r;
		k=local_search();
		if (r==k) cout<<"----\n"; 
		else cout<<adapt(k)<<"\n";
	}
}
int main()
{
	test();
	return 0;
}
