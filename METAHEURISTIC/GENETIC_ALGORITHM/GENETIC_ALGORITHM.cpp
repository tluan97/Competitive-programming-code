/*
	GENETIC_ALGORITHM
	http://vn.spoj.com/problems/POST/
*/
#include <bits/stdc++.h>
using namespace std;

const int _time = 100;
const int _select = 1000;
const int _popul = 10000;
const int _rate = 10;

int a,b;
struct individual{
	int gen;
	int ad;
}f;
struct population{
	vector<individual> p;
	int time;
}p;

int adapt(int gen){
	return abs(a+b-gen);
}
void init(){
	srand(time(NULL));
	p.time=_time;
	p.p.clear();
	f.gen=rand();
	f.ad=adapt(f.gen);
	individual tmp;
	for (int i=0;i<_popul;i++){
		tmp.gen=rand();
		if (rand()%2) tmp.gen*=-1;
		tmp.ad=adapt(tmp.gen);
		p.p.push_back(tmp);
	}
}
void selection(){
	for (int i=0;i<p.p.size();i++){
		if (p.p[i].ad>_select && rand()%_rate){
			p.p.erase(p.p.begin()+i);
		}
	}
}
void crossover(){
	int s=p.p.size();
	individual male,female,child;
	for (int i=0;i<s;i++)
	if (rand()%_rate){
		male=p.p[rand()%s];
		female=p.p[rand()%s];
		child.gen=(male.gen+female.gen)/2;
		child.ad=adapt(child.gen);
		p.p.push_back(child);
	}
}
void mutation(){
	int s=p.p.size();
	individual in;
	for (int i=0;i<s;i++)
	if (!rand()%_rate){
		in=p.p[rand()%s];
		in.gen^=rand();
		in.ad=adapt(in.gen);
		p.p.push_back(in);
	}
}
void solve(){
	int s=p.p.size();
	for (int i=0;i<s;i++)
	if (p.p[i].ad<f.ad)
		f=p.p[i];
}
int genetic(){
	init();
	while (--p.time){
//		cout<<"-- "<<p.time<<"\n";
//		cout<<"\t-- selection\n";
		selection();
//		cout<<"\t-- crossover\n";
		crossover();
//		cout<<"\t-- mutation\n";
		mutation();
//		cout<<"\t-- solve\n";
		solve();
		if (f.ad==0) break;
	}
	return f.gen;
}

void test(){
	freopen("test.txt","r",stdin);
	int t,r,k;cin>>t;
	while (t--){
		cin>>a>>b>>r;
		k=genetic();
		if (r==k) cout<<"----\n"; 
		else cout<<f.ad<<"\n";
	}
}
int main()
{
	test();
	return 0;
}
