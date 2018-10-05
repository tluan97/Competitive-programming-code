
#define T int
bool find(T k){
	// init load
	// set bound
	// dfs/bfs/linear
	return false;
}
T binarysearch(T left,T right){
	T ll=left,rr=right,mm=(ll+rr)/2;
	while (ll!=mm && mm!=rr){
		if (find(mm)) rr=mm;
		else ll=mm;
		mm=(ll+rr)/2;
	}
	return rr;
}
void solve(){
	int hmin=0,hmax=1000;
	int ans=binarysearch(hmin,hmax+1);
	if (ans!=hmax+1){
		cout<<ans;
	} else {
		cout<<-1;
	}
}
