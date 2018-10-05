
bool comp(Point a,Point b){
	if (a.X==b.X) return a.Y>b.Y;
	return a.X>b.X;
}
double dist(Point a,Point b){
	return sqrt(
		(a.X-b.X)*(a.X-b.X)+
		(a.Y-b.Y)*(a.Y-b.Y)
	);
}
double closestPoint_(vector<Point> a,int l,int r){
	double res=oo;
	for (int i=l;i<r;i++)
	for (int j=i+1;j<=r;j++)
	if (dist(a[i],a[j])<res)
		res=dist(a[i],a[j]);
	return res;
}
double closestPoint(vector<Point> a,int l,int r){
	if (l>r) return oo;
	if (r-l<=10) return closestPoint_(a,l,r);
	int m=(l+r)/2;
	double dl=closestPoint(a,l,m);
	double dr=closestPoint(a,m+1,r);
	double res=(dl<dr)?dl:dr;
	double line=(a[m].X+a[m+1].X)/2;
	for (int i=m;line-a[i].X<res && i>=l;i--)
	for (int j=m+1;a[j].X-line<res && j<=r;j++){
		double tmp=dist(a[i],a[j]);
		if (tmp<res) res=tmp;
	}
	return res;
}
