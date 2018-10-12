
const int _time = 100;
const int _popul = 10000;
const int _rate = 10;

int a,b;
struct bee{
	int l; // location
	int ad;
}f;
struct population{
	vector<bee> p;
	int time;
}p;

int adapt(int l){
	return abs(a+b-l);
}
void init(){
	srand(time(NULL));
	p.time=_time;
	p.p.clear();
	f.l=rand();
	f.ad=adapt(f.l);
	bee tmp;
	for (int i=0;i<_popul;i++){
		tmp.l=rand();
		tmp.ad=adapt(tmp.l);
		p.p.push_back(tmp);
	}
}
void neighboorhood_search(){
	int s=p.p.size();
	int low=f.l-rand();
	int up=f.l+rand();
	for (int i=0;i<s;i++)
	if (rand()%_rate){
		p.p[i].l=rand()%(up-low)+low;
		p.p[i].ad=adapt(p.p[i].l);
	}
}
void solve(){
	int s=p.p.size();
	for (int i=0;i<s;i++)
	if (p.p[i].ad<f.ad)
		f=p.p[i];
}
int bee_search(){
	init();
	while (--p.time){
//		cout<<"-- "<<p.time<<"\n";
//		cout<<"\t-- neighboorhood_search\n";
		neighboorhood_search();
//		cout<<"\t-- solve\n";
		solve();
		if (f.ad==0) break;
	}
	return f.l;
}
