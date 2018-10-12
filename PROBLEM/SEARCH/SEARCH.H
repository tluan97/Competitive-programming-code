
int search(int k){
	int ll=1,rr=n,i=(ll+rr)/2;
	while (ll!=i && i!=rr){
		(a[i]>=k)?rr=i:ll=i;
		i=(ll+rr)/2;
	}
	for (int i=ll;i<=rr;i++)
	if (a[i]>=k) return i;
	return n+1;
}
double arcsin(double x){
	double ll=0,rr=M_PI/2;
	double i=(ll+rr)/2;
	while (ll!=i && i!=rr){
		(sin(i)>=x)?rr=i:ll=i;
		i=(ll+rr)/2;
	}
	return (ll+rr)/2;
}
double search(point p1,point p2){
	double rr=max(p1.X,p2.X);
    double ll=min(p1.X,p2.X);
    double ml=(ll+ll+rr)/3;
    double mr=(ll+rr+rr)/3;
	while (ll!=ml && ml!=mr && mr!=rr){
		(f(ml)>f(mr))?ll=ml:rr=mr;
		ml=(ll+ll+rr)/3;
        mr=(ll+rr+rr)/3;
	}
	return (ll+rr)/2;
}
