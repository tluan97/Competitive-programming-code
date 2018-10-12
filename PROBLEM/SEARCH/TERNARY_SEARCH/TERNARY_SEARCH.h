
#define T double
bool find(T k){
	// init load
	// set bound
	// dfs/bfs/linear
	return false;
}
double ternarysearch(point p1,point p2){
	double rr=max(p1.X,p2.X);
    double ll=min(p1.X,p2.X);
    double ml=(ll+ll+rr)/3;
    double mr=(ll+rr+rr)/3;
	while (ll!=ml && ml!=mr && mr!=rr){
		if (find(ml)>find(mr)) ll=ml;
		else rr=mr
		ml=(ll+ll+rr)/3;
        mr=(ll+rr+rr)/3;
	}
	return (ll+rr)/2;
}
void solve(){
	point hmin=point(0,0),hmax=point(1000,1000);
	double ans=ternarysearch(hmin,hmax);
	if (ans!=oo){
		cout<<ans;
	} else {
		cout<<-1;
	}
}
